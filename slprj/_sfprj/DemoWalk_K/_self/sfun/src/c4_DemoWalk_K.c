/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DemoWalk_K_sfun.h"
#include "c4_DemoWalk_K.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DemoWalk_K_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c4_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_stateBoredPose           ((uint8_T)1U)
#define c4_IN_stateBoredPoseGameOver   ((uint8_T)2U)
#define c4_IN_stateInit                ((uint8_T)3U)
#define c4_IN_statePoseChance          ((uint8_T)4U)
#define c4_IN_stateRandomPose          ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[27] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "aVarTruthTableCondition_19",
  "aVarTruthTableCondition_20", "aVarTruthTableCondition_21",
  "aVarTruthTableCondition_22", "nargin", "nargout", "bmlID", "pr", "poseBML" };

static const char * c4_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_t_debug_family_names[9] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c4_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_y_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c4_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_bb_debug_family_names[4] = { "nargin", "nargout",
  "myarr256", "mystr" };

static const char * c4_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_yb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c4_dataWrittenToVector[9];

/* Function Declarations */
static void initialize_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void initialize_params_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void enable_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void disable_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *
  chartInstance);
static void set_sim_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_DemoWalk_K
  (SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void finalize_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void sf_gateway_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_enter_atomic_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_enter_internal_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void c4_exit_internal_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_initc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void initSimStructsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_enter_atomic_stateRandomPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_enter_atomic_statePoseChance(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_enter_atomic_stateBoredPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_stateBoredPose(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void c4_enter_atomic_stateBoredPoseGameOver(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_b_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_c_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_d_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_e_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_f_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_g_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_h_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_i_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_j_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_k_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_l_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_m_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_n_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_o_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_p_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_q_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_r_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_s_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_t_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_u_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256]);
static void c4_decArr2Str(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256], char_T c4_mystr_data[], int32_T c4_mystr_sizes[2]);
static real_T c4_rand(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void c4_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_d_state[625]);
static void c4_twister_state_vector(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625]);
static void c4_b_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T *c4_r);
static void c4_eml_error(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static real_T c4_randi(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static real_T c4_b_randi(SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_poseBML, const char_T *c4_identifier, real_T c4_y[256]);
static void c4_b_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[256]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_pr, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_e_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_myarr256, const char_T *c4_identifier, real_T c4_y[256]);
static void c4_g_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[256]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_k_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_l_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_m_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_n_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_o_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_p_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_q_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_r_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_s_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_t_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_u_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_v_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_w_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_x_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_y_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static creal_T c4_h_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_db_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_i_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_newBmls, const char_T *c4_identifier, real_T c4_y[1280]);
static void c4_j_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[1280]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, char_T
  c4_inData_data[], int32_T c4_inData_sizes[2]);
static void c4_k_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, char_T c4_y_data[],
  int32_T c4_y_sizes[2]);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, char_T c4_outData_data[], int32_T
  c4_outData_sizes[2]);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_activate_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_deactivate_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_increment_counters_secsc4_DemoWalk_K
  (SFc4_DemoWalk_KInstanceStruct *chartInstance);
static void c4_reset_counters_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance);
static void c4_idlePoseBradTablec4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[256]);
static void c4_walkInvadingTablec4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmlID, creal_T *c4_p, real_T c4_poseBML[256]);
static void c4_insertQueueLowc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmls[1280], real_T c4_myBML[256], real_T c4_newBmls
  [1280]);
static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int8_T c4_l_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_m_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_n_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_stateInit, const char_T *c4_identifier);
static uint8_T c4_o_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint32_T c4_p_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier);
static uint32_T c4_q_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint32_T c4_r_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier);
static uint32_T c4_s_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_t_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, uint32_T c4_y[625]);
static void c4_u_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint32_T c4_y[625]);
static void c4_v_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, uint32_T c4_y[2]);
static void c4_w_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint32_T c4_y[2]);
static const mxArray *c4_x_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_y_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_updateDataWrittenToVector(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex);
static void c4_errorIfDataNotWrittenToFcn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber);
static void c4_b_twister_state_vector(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed);
static real_T c4_c_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_d_state[625]);
static real_T c4_get_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b);
static void c4_set_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b);
static void c4_set_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b);
static void c4_set_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_P(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b);
static void c4_set_P(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T c4_b,
                     real_T c4_c);
static real_T *c4_access_P(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b);
static void c4_set_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_STATE_READY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_STATE_READY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_READY(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c);
static real_T *c4_access_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_randPoseChance(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_randPoseChance(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randPoseChance(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_randSlowPose(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_randSlowPose(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randSlowPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b);
static void init_dsm_address_info(SFc4_DemoWalk_KInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_debugger_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_DemoWalk_K == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_statePoseChance) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateBoredPoseGameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *
  chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i0;
  real_T c4_b_u[256];
  const mxArray *c4_c_y = NULL;
  int32_T c4_i1;
  real_T c4_c_u[256];
  const mxArray *c4_d_y = NULL;
  int32_T c4_i2;
  real_T c4_d_u[1280];
  const mxArray *c4_e_y = NULL;
  uint32_T c4_b_hoistedGlobal;
  uint32_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  uint32_T c4_c_hoistedGlobal;
  uint32_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  int32_T c4_i3;
  uint32_T c4_g_u[625];
  const mxArray *c4_h_y = NULL;
  int32_T c4_i4;
  uint32_T c4_h_u[2];
  const mxArray *c4_i_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  uint8_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_j_u;
  const mxArray *c4_k_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  uint8_T c4_k_u;
  const mxArray *c4_l_y = NULL;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(11, 1), false);
  c4_hoistedGlobal = *c4_gameState;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i0 = 0; c4_i0 < 256; c4_i0++) {
    c4_b_u[c4_i0] = chartInstance->c4_BMLl[c4_i0];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    c4_c_u[c4_i1] = chartInstance->c4_n[c4_i1];
  }

  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  for (c4_i2 = 0; c4_i2 < 1280; c4_i2++) {
    c4_d_u[c4_i2] = chartInstance->c4_newBmlsL[c4_i2];
  }

  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_b_hoistedGlobal = chartInstance->c4_method;
  c4_e_u = c4_b_hoistedGlobal;
  c4_f_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_c_hoistedGlobal = chartInstance->c4_state;
  c4_f_u = c4_c_hoistedGlobal;
  c4_g_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  for (c4_i3 = 0; c4_i3 < 625; c4_i3++) {
    c4_g_u[c4_i3] = chartInstance->c4_c_state[c4_i3];
  }

  c4_h_y = NULL;
  if (!chartInstance->c4_c_state_not_empty) {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_g_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c4_y, 6, c4_h_y);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_h_u[c4_i4] = chartInstance->c4_b_state[c4_i4];
  }

  c4_i_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_h_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_d_hoistedGlobal = chartInstance->c4_is_active_c4_DemoWalk_K;
  c4_i_u = c4_d_hoistedGlobal;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_c4_DemoWalk_K;
  c4_j_u = c4_e_hoistedGlobal;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 9, c4_k_y);
  c4_f_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_k_u = c4_f_hoistedGlobal;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[256];
  int32_T c4_i5;
  real_T c4_dv1[256];
  int32_T c4_i6;
  real_T c4_dv2[1280];
  int32_T c4_i7;
  uint32_T c4_uv0[625];
  int32_T c4_i8;
  uint32_T c4_uv1[2];
  int32_T c4_i9;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_gameState = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "gameState");
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "BMLl",
                      c4_dv0);
  for (c4_i5 = 0; c4_i5 < 256; c4_i5++) {
    chartInstance->c4_BMLl[c4_i5] = c4_dv0[c4_i5];
  }

  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)), "n",
                        c4_dv1);
  for (c4_i6 = 0; c4_i6 < 256; c4_i6++) {
    chartInstance->c4_n[c4_i6] = c4_dv1[c4_i6];
  }

  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
                        "newBmlsL", c4_dv2);
  for (c4_i7 = 0; c4_i7 < 1280; c4_i7++) {
    chartInstance->c4_newBmlsL[c4_i7] = c4_dv2[c4_i7];
  }

  chartInstance->c4_method = c4_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "method");
  chartInstance->c4_state = c4_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "state");
  c4_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
                        "state", c4_uv0);
  for (c4_i8 = 0; c4_i8 < 625; c4_i8++) {
    chartInstance->c4_c_state[c4_i8] = c4_uv0[c4_i8];
  }

  c4_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
                        "state", c4_uv1);
  for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
    chartInstance->c4_b_state[c4_i9] = c4_uv1[c4_i9];
  }

  chartInstance->c4_is_active_c4_DemoWalk_K = c4_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
     "is_active_c4_DemoWalk_K");
  chartInstance->c4_is_c4_DemoWalk_K = c4_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 9)), "is_c4_DemoWalk_K");
  chartInstance->c4_temporalCounter_i1 = c4_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 10)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_DemoWalk_K(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_DemoWalk_K
  (SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateBoredPose) {
      chartInstance->c4_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateBoredPoseGameOver) {
      chartInstance->c4_tp_stateBoredPoseGameOver = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateBoredPoseGameOver = 0U;
    }

    if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateInit) {
      chartInstance->c4_tp_stateInit = 1U;
    } else {
      chartInstance->c4_tp_stateInit = 0U;
    }

    if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_statePoseChance) {
      chartInstance->c4_tp_statePoseChance = 1U;
    } else {
      chartInstance->c4_tp_statePoseChance = 0U;
    }

    if (chartInstance->c4_is_c4_DemoWalk_K == c4_IN_stateRandomPose) {
      chartInstance->c4_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c4_tp_stateRandomPose = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  c4_set_sim_state_side_effects_c4_DemoWalk_K(chartInstance);
}

static void c4_enter_atomic_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_active_c4_DemoWalk_K = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void c4_enter_internal_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr;
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr;
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_cb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c4_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c4_set_STATE_READY(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c4_set_STATE_GO(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  *c4_gameState = c4_get_STATE_READY(chartInstance, 0);
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 4U);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ab_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_arr, 1U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_mystr, 5U, c4_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  c4_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 255.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i10 = 0; c4_i10 < 256; c4_i10++) {
    c4_tt[c4_i10] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i11 = 0; c4_i11 < 256; c4_i11++) {
    c4_myarr256[c4_i11] = c4_tt[c4_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
    chartInstance->c4_n[c4_i12] = c4_myarr256[c4_i12];
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  for (c4_i13 = 0; c4_i13 < 256; c4_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_n[c4_i13], 27U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 3U, 27U);
  for (c4_i14 = 0; c4_i14 < 256; c4_i14++) {
    c4_set_bmlsL(chartInstance, c4_i14, chartInstance->c4_n[c4_i14]);
  }

  for (c4_i15 = 0; c4_i15 < 256; c4_i15++) {
    c4_set_bmlsL(chartInstance, c4_i15 + 256, chartInstance->c4_n[c4_i15]);
  }

  for (c4_i16 = 0; c4_i16 < 256; c4_i16++) {
    c4_set_bmlsL(chartInstance, c4_i16 + 512, chartInstance->c4_n[c4_i16]);
  }

  for (c4_i17 = 0; c4_i17 < 256; c4_i17++) {
    c4_set_bmlsL(chartInstance, c4_i17 + 768, chartInstance->c4_n[c4_i17]);
  }

  for (c4_i18 = 0; c4_i18 < 256; c4_i18++) {
    c4_set_bmlsL(chartInstance, c4_i18 + 1024, chartInstance->c4_n[c4_i18]);
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 3U, 27U);
  for (c4_i19 = 0; c4_i19 < 256; c4_i19++) {
    chartInstance->c4_newBmlsL[c4_i19] = chartInstance->c4_n[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 256; c4_i20++) {
    chartInstance->c4_newBmlsL[c4_i20 + 256] = chartInstance->c4_n[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 256; c4_i21++) {
    chartInstance->c4_newBmlsL[c4_i21 + 512] = chartInstance->c4_n[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 256; c4_i22++) {
    chartInstance->c4_newBmlsL[c4_i22 + 768] = chartInstance->c4_n[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 256; c4_i23++) {
    chartInstance->c4_newBmlsL[c4_i23 + 1024] = chartInstance->c4_n[c4_i23];
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i24 = 0; c4_i24 < 1280; c4_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i24], 25U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_d_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 1.0;
  boolean_T c4_f_out;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_g_out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 1.0;
  boolean_T c4_h_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_i_nargin = 0.0;
  real_T c4_i_nargout = 0.0;
  real_T c4_hoistedGlobal;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T *c4_gameState;
  real_T *c4_inE;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  c4_inE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_isStable = true;
  switch (chartInstance->c4_is_c4_DemoWalk_K) {
   case c4_IN_stateBoredPose:
    CV_CHART_EVAL(2, 0, 1);
    c4_stateBoredPose(chartInstance);
    break;

   case c4_IN_stateBoredPoseGameOver:
    CV_CHART_EVAL(2, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ib_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_out = CV_EML_IF(5, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                       (chartInstance->c4_temporalCounter_i1 >= 40));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateBoredPoseGameOver = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      c4_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateInit:
    CV_CHART_EVAL(2, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hb_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
    c4_b_out = CV_EML_IF(13, 0, 0, *c4_gameState == 10.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      c4_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseChance:
    CV_CHART_EVAL(2, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kb_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_c_out = CV_EML_IF(1, 0, 0, c4_get_randPoseChance(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_statePoseChance = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      c4_enter_atomic_stateRandomPose(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ob_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard7 = false;
      guard8 = false;
      if (CV_EML_COND(6, 0, 0, c4_get_randPoseChance(chartInstance, 0) == 1.0))
      {
        if (CV_EML_COND(6, 0, 1, c4_get_changeFlag(chartInstance, 0) != 1.0)) {
          if (CV_EML_COND(6, 0, 2, *c4_gameState == c4_get_STATE_OVER
                          (chartInstance, 0))) {
            CV_EML_MCDC(6, 0, 0, true);
            CV_EML_IF(6, 0, 0, true);
            c4_d_out = true;
          } else {
            guard7 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
          guard8 = true;
        }
      } else {
        guard8 = true;
      }

      if (guard8 == true) {
        guard7 = true;
      }

      if (guard7 == true) {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c4_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      guard3 = false;
      if (c4_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_qb_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        c4_e_out = CV_EML_IF(7, 0, 0, c4_get_randSlowPose(chartInstance, 0) <
                             8.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c4_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_statePoseChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateBoredPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
          chartInstance->c4_temporalCounter_i1 = 0U;
          chartInstance->c4_tp_stateBoredPose = 1U;
          c4_enter_atomic_stateBoredPose(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_pb_debug_family_names,
            c4_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U,
            c4_c_sf_marshallOut, c4_c_sf_marshallIn);
          c4_f_out = CV_EML_IF(8, 0, 0, c4_get_randSlowPose(chartInstance, 0) >=
                               8.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c4_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
            chartInstance->c4_tp_statePoseChance = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
            chartInstance->c4_isStable = false;
            chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateBoredPoseGameOver;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
            chartInstance->c4_temporalCounter_i1 = 0U;
            chartInstance->c4_tp_stateBoredPoseGameOver = 1U;
            c4_enter_atomic_stateBoredPoseGameOver(chartInstance);
          } else {
            guard3 = true;
          }
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_nb_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        guard4 = false;
        guard5 = false;
        guard6 = false;
        if (CV_EML_COND(4, 0, 0, c4_get_randPoseChance(chartInstance, 0) == 1.0))
        {
          if (CV_EML_COND(4, 0, 1, *c4_gameState != c4_get_STATE_GO
                          (chartInstance, 0))) {
            if (CV_EML_COND(4, 0, 2, *c4_gameState != c4_get_STATE_READY
                            (chartInstance, 0))) {
              if (CV_EML_COND(4, 0, 3, *c4_gameState != c4_get_STATE_OVER
                              (chartInstance, 0))) {
                CV_EML_MCDC(4, 0, 0, true);
                CV_EML_IF(4, 0, 0, true);
                c4_g_out = true;
              } else {
                guard4 = true;
              }
            } else {
              c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
              guard5 = true;
            }
          } else {
            c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
            guard6 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
          guard6 = true;
        }

        if (guard6 == true) {
          guard5 = true;
        }

        if (guard5 == true) {
          guard4 = true;
        }

        if (guard4 == true) {
          CV_EML_MCDC(4, 0, 0, false);
          CV_EML_IF(4, 0, 0, false);
          c4_g_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c4_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_statePoseChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateBoredPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
          chartInstance->c4_temporalCounter_i1 = 0U;
          chartInstance->c4_tp_stateBoredPose = 1U;
          c4_enter_atomic_stateBoredPose(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_statePoseChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateRandomPose = 1U;
          c4_enter_atomic_stateRandomPose(chartInstance);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandomPose:
    CV_CHART_EVAL(2, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_lb_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(3, 0, 0, *c4_inE == c4_get_FRUST(chartInstance, 0))) {
      guard2 = true;
    } else if (CV_EML_COND(3, 0, 1, *c4_inE == c4_get_FEAR(chartInstance, 0))) {
      if (CV_EML_COND(3, 0, 2, c4_get_interest(chartInstance, 0) > 2.0)) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c4_h_out = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c4_h_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_h_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_mb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_hoistedGlobal = c4_get_interest(chartInstance, 0);
      c4_A = c4_hoistedGlobal;
      c4_x = c4_A;
      c4_b_x = c4_x;
      c4_c_x = c4_b_x;
      c4_set_interest(chartInstance, 0, c4_c_x / 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 19);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c4_tp_stateRandomPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_DemoWalk_K = c4_IN_statePoseChance;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_statePoseChance = 1U;
      c4_enter_atomic_statePoseChance(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_DemoWalk_K = c4_IN_statePoseChance;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_statePoseChance = 1U;
      c4_enter_atomic_statePoseChance(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(2, 0, 0);
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void c4_exit_internal_c4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c4_is_c4_DemoWalk_K) {
   case c4_IN_stateBoredPose:
    CV_CHART_EVAL(2, 0, 1);
    chartInstance->c4_tp_stateBoredPose = 0U;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateBoredPoseGameOver:
    CV_CHART_EVAL(2, 0, 2);
    chartInstance->c4_tp_stateBoredPoseGameOver = 0U;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateInit:
    CV_CHART_EVAL(2, 0, 3);
    chartInstance->c4_tp_stateInit = 0U;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseChance:
    CV_CHART_EVAL(2, 0, 4);
    chartInstance->c4_tp_statePoseChance = 0U;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandomPose:
    CV_CHART_EVAL(2, 0, 5);
    chartInstance->c4_tp_stateRandomPose = 0U;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(2, 0, 0);
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;
  }
}

static void c4_initc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_stateBoredPose = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateBoredPoseGameOver = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateInit = 0U;
  chartInstance->c4_tp_statePoseChance = 0U;
  chartInstance->c4_tp_stateRandomPose = 0U;
  chartInstance->c4_is_active_c4_DemoWalk_K = 0U;
  chartInstance->c4_is_c4_DemoWalk_K = c4_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_enter_atomic_stateRandomPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_db_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 10.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  c4_r = 1.0 + c4_b_x;
  c4_set_randSlowPose(chartInstance, 0, c4_r);
  ssUpdateDataStoreLog(chartInstance->S, 21);
  c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance, 0) -
                  c4_get_boredom(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 19);
  c4_set_interest(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_enter_atomic_statePoseChance(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_hoistedGlobal;
  real_T c4_lowhigh[2];
  real_T c4_high;
  int32_T c4_i25;
  static char_T c4_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c4_u[26];
  const mxArray *c4_y = NULL;
  real_T c4_s;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_eb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_hoistedGlobal = c4_get_interest(chartInstance, 0);
  c4_lowhigh[0] = 1.0;
  c4_lowhigh[1] = c4_hoistedGlobal;
  c4_high = c4_lowhigh[1];
  if (1.0 <= c4_high) {
  } else {
    for (c4_i25 = 0; c4_i25 < 26; c4_i25++) {
      c4_u[c4_i25] = c4_cv0[c4_i25];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c4_y));
  }

  c4_s = (c4_high - 1.0) + 1.0;
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * c4_s;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  c4_r = 1.0 + c4_b_x;
  c4_set_randPoseChance(chartInstance, 0, c4_r);
  ssUpdateDataStoreLog(chartInstance->S, 20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_enter_atomic_stateBoredPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_b_BMLl[256];
  real_T c4_P;
  int32_T c4_i26;
  real_T c4_c_BMLl[256];
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  real_T c4_dv3[1280];
  int32_T c4_i30;
  real_T c4_dv4[256];
  real_T c4_dv5[1280];
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_fb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_idlePoseBradTablec4_DemoWalk_K(chartInstance, c4_randi(chartInstance),
    &c4_P, c4_b_BMLl);
  for (c4_i26 = 0; c4_i26 < 256; c4_i26++) {
    c4_c_BMLl[c4_i26] = c4_b_BMLl[c4_i26];
  }

  c4_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  for (c4_i27 = 0; c4_i27 < 256; c4_i27++) {
    chartInstance->c4_BMLl[c4_i27] = c4_c_BMLl[c4_i27];
  }

  c4_updateDataWrittenToVector(chartInstance, 1U);
  for (c4_i28 = 0; c4_i28 < 256; c4_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_BMLl[c4_i28], 24U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 24U);
  for (c4_i29 = 0; c4_i29 < 1280; c4_i29++) {
    c4_dv3[c4_i29] = c4_get_bmlsL(chartInstance, c4_i29);
  }

  for (c4_i30 = 0; c4_i30 < 256; c4_i30++) {
    c4_dv4[c4_i30] = chartInstance->c4_BMLl[c4_i30];
  }

  c4_insertQueueLowc4_DemoWalk_K(chartInstance, c4_dv3, c4_dv4, c4_dv5);
  for (c4_i31 = 0; c4_i31 < 1280; c4_i31++) {
    chartInstance->c4_newBmlsL[c4_i31] = c4_dv5[c4_i31];
  }

  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i32 = 0; c4_i32 < 1280; c4_i32++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i32], 25U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 2U, 25U);
  for (c4_i33 = 0; c4_i33 < 1280; c4_i33++) {
    c4_set_bmlsL(chartInstance, c4_i33, chartInstance->c4_newBmlsL[c4_i33]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateBoredPose(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(2, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 40));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateBoredPose = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_DemoWalk_K = c4_IN_stateRandomPose;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomPose = 1U;
    c4_enter_atomic_stateRandomPose(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateBoredPoseGameOver(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_b_BMLl[256];
  real_T c4_P;
  int32_T c4_i34;
  real_T c4_c_BMLl[256];
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  real_T c4_dv6[1280];
  int32_T c4_i38;
  real_T c4_dv7[256];
  real_T c4_dv8[1280];
  int32_T c4_i39;
  int32_T c4_i40;
  int32_T c4_i41;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_gb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_idlePoseBradTablec4_DemoWalk_K(chartInstance, c4_b_randi(chartInstance),
    &c4_P, c4_b_BMLl);
  for (c4_i34 = 0; c4_i34 < 256; c4_i34++) {
    c4_c_BMLl[c4_i34] = c4_b_BMLl[c4_i34];
  }

  c4_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  for (c4_i35 = 0; c4_i35 < 256; c4_i35++) {
    chartInstance->c4_BMLl[c4_i35] = c4_c_BMLl[c4_i35];
  }

  c4_updateDataWrittenToVector(chartInstance, 1U);
  for (c4_i36 = 0; c4_i36 < 256; c4_i36++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_BMLl[c4_i36], 24U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 24U);
  for (c4_i37 = 0; c4_i37 < 1280; c4_i37++) {
    c4_dv6[c4_i37] = c4_get_bmlsL(chartInstance, c4_i37);
  }

  for (c4_i38 = 0; c4_i38 < 256; c4_i38++) {
    c4_dv7[c4_i38] = chartInstance->c4_BMLl[c4_i38];
  }

  c4_insertQueueLowc4_DemoWalk_K(chartInstance, c4_dv6, c4_dv7, c4_dv8);
  for (c4_i39 = 0; c4_i39 < 1280; c4_i39++) {
    chartInstance->c4_newBmlsL[c4_i39] = c4_dv8[c4_i39];
  }

  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i40 = 0; c4_i40 < 1280; c4_i40++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i40], 25U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 2U, 25U);
  for (c4_i41 = 0; c4_i41 < 1280; c4_i41++) {
    c4_set_bmlsL(chartInstance, c4_i41, chartInstance->c4_newBmlsL[c4_i41]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i42;
  static char_T c4_cv1[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's', 'p',
    'e', 'e', 'd', '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i43;
  static real_T c4_dv9[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 55.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i42 = 0; c4_i42 < 108; c4_i42++) {
    c4_mystr[c4_i42] = c4_cv1[c4_i42];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i43 = 0; c4_i43 < 108; c4_i43++) {
    c4_arr[c4_i43] = c4_dv9[c4_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i44 = 0; c4_i44 < 256; c4_i44++) {
    c4_tt[c4_i44] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i45 = 0; c4_i45 < 108; c4_i45++) {
    c4_tt[c4_i45] = c4_arr[c4_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i46 = 0; c4_i46 < 256; c4_i46++) {
    c4_myarr256[c4_i46] = c4_tt[c4_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_b_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i47;
  static char_T c4_cv2[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's', 'p',
    'e', 'e', 'd', '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i48;
  static real_T c4_dv10[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 55.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i49;
  int32_T c4_i50;
  int32_T c4_i51;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_c_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i47 = 0; c4_i47 < 108; c4_i47++) {
    c4_mystr[c4_i47] = c4_cv2[c4_i47];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i48 = 0; c4_i48 < 108; c4_i48++) {
    c4_arr[c4_i48] = c4_dv10[c4_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i49 = 0; c4_i49 < 256; c4_i49++) {
    c4_tt[c4_i49] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i50 = 0; c4_i50 < 108; c4_i50++) {
    c4_tt[c4_i50] = c4_arr[c4_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i51 = 0; c4_i51 < 256; c4_i51++) {
    c4_myarr256[c4_i51] = c4_tt[c4_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[104];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[104];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i52;
  static char_T c4_cv3[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i53;
  static real_T c4_dv11[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 55.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_d_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i52 = 0; c4_i52 < 104; c4_i52++) {
    c4_mystr[c4_i52] = c4_cv3[c4_i52];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i53 = 0; c4_i53 < 104; c4_i53++) {
    c4_arr[c4_i53] = c4_dv11[c4_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 152.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i54 = 0; c4_i54 < 256; c4_i54++) {
    c4_tt[c4_i54] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i55 = 0; c4_i55 < 104; c4_i55++) {
    c4_tt[c4_i55] = c4_arr[c4_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i56 = 0; c4_i56 < 256; c4_i56++) {
    c4_myarr256[c4_i56] = c4_tt[c4_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_d_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i57;
  static char_T c4_cv4[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i58;
  static real_T c4_dv12[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    55.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i59;
  int32_T c4_i60;
  int32_T c4_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_e_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i57 = 0; c4_i57 < 106; c4_i57++) {
    c4_mystr[c4_i57] = c4_cv4[c4_i57];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i58 = 0; c4_i58 < 106; c4_i58++) {
    c4_arr[c4_i58] = c4_dv12[c4_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 150.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i59 = 0; c4_i59 < 256; c4_i59++) {
    c4_tt[c4_i59] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i60 = 0; c4_i60 < 106; c4_i60++) {
    c4_tt[c4_i60] = c4_arr[c4_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i61 = 0; c4_i61 < 256; c4_i61++) {
    c4_myarr256[c4_i61] = c4_tt[c4_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_e_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[149];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[149];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i62;
  static char_T c4_cv5[149] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', ' ',
    'r', 'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '4', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i63;
  static real_T c4_dv13[149] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0,
    61.0, 34.0, 49.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0,
    52.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 55.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_f_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i62 = 0; c4_i62 < 149; c4_i62++) {
    c4_mystr[c4_i62] = c4_cv5[c4_i62];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i63 = 0; c4_i63 < 149; c4_i63++) {
    c4_arr[c4_i63] = c4_dv13[c4_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 149.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i64 = 0; c4_i64 < 256; c4_i64++) {
    c4_tt[c4_i64] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i65 = 0; c4_i65 < 149; c4_i65++) {
    c4_tt[c4_i65] = c4_arr[c4_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i66 = 0; c4_i66 < 256; c4_i66++) {
    c4_myarr256[c4_i66] = c4_tt[c4_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_f_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[91];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[91];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i67;
  static char_T c4_cv6[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i68;
  static real_T c4_dv14[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i69;
  int32_T c4_i70;
  int32_T c4_i71;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_g_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i67 = 0; c4_i67 < 91; c4_i67++) {
    c4_mystr[c4_i67] = c4_cv6[c4_i67];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i68 = 0; c4_i68 < 91; c4_i68++) {
    c4_arr[c4_i68] = c4_dv14[c4_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i69 = 0; c4_i69 < 256; c4_i69++) {
    c4_tt[c4_i69] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i70 = 0; c4_i70 < 91; c4_i70++) {
    c4_tt[c4_i70] = c4_arr[c4_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i71 = 0; c4_i71 < 256; c4_i71++) {
    c4_myarr256[c4_i71] = c4_tt[c4_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_g_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i72;
  static char_T c4_cv7[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i73;
  static real_T c4_dv15[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    55.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_h_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i72 = 0; c4_i72 < 105; c4_i72++) {
    c4_mystr[c4_i72] = c4_cv7[c4_i72];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i73 = 0; c4_i73 < 105; c4_i73++) {
    c4_arr[c4_i73] = c4_dv15[c4_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i74 = 0; c4_i74 < 256; c4_i74++) {
    c4_tt[c4_i74] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i75 = 0; c4_i75 < 105; c4_i75++) {
    c4_tt[c4_i75] = c4_arr[c4_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i76 = 0; c4_i76 < 256; c4_i76++) {
    c4_myarr256[c4_i76] = c4_tt[c4_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_h_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[149];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[149];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i77;
  static char_T c4_cv8[149] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', ' ',
    'r', 'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '4', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '3',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i78;
  static real_T c4_dv16[149] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0,
    61.0, 34.0, 49.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0,
    52.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 55.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i79;
  int32_T c4_i80;
  int32_T c4_i81;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_i_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i77 = 0; c4_i77 < 149; c4_i77++) {
    c4_mystr[c4_i77] = c4_cv8[c4_i77];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i78 = 0; c4_i78 < 149; c4_i78++) {
    c4_arr[c4_i78] = c4_dv16[c4_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 149.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i79 = 0; c4_i79 < 256; c4_i79++) {
    c4_tt[c4_i79] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i80 = 0; c4_i80 < 149; c4_i80++) {
    c4_tt[c4_i80] = c4_arr[c4_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i81 = 0; c4_i81 < 256; c4_i81++) {
    c4_myarr256[c4_i81] = c4_tt[c4_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_i_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[93];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[93];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i82;
  static char_T c4_cv9[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i83;
  static real_T c4_dv17[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i84;
  int32_T c4_i85;
  int32_T c4_i86;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_j_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i82 = 0; c4_i82 < 93; c4_i82++) {
    c4_mystr[c4_i82] = c4_cv9[c4_i82];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i83 = 0; c4_i83 < 93; c4_i83++) {
    c4_arr[c4_i83] = c4_dv17[c4_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 163.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i84 = 0; c4_i84 < 256; c4_i84++) {
    c4_tt[c4_i84] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i85 = 0; c4_i85 < 93; c4_i85++) {
    c4_tt[c4_i85] = c4_arr[c4_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i86 = 0; c4_i86 < 256; c4_i86++) {
    c4_myarr256[c4_i86] = c4_tt[c4_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_j_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[92];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[92];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i87;
  static char_T c4_cv10[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i88;
  static real_T c4_dv18[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i89;
  int32_T c4_i90;
  int32_T c4_i91;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_k_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i87 = 0; c4_i87 < 92; c4_i87++) {
    c4_mystr[c4_i87] = c4_cv10[c4_i87];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i88 = 0; c4_i88 < 92; c4_i88++) {
    c4_arr[c4_i88] = c4_dv18[c4_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i89 = 0; c4_i89 < 256; c4_i89++) {
    c4_tt[c4_i89] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i90 = 0; c4_i90 < 92; c4_i90++) {
    c4_tt[c4_i90] = c4_arr[c4_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i91 = 0; c4_i91 < 256; c4_i91++) {
    c4_myarr256[c4_i91] = c4_tt[c4_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_k_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[93];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[93];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i92;
  static char_T c4_cv11[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i93;
  static real_T c4_dv19[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_l_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i92 = 0; c4_i92 < 93; c4_i92++) {
    c4_mystr[c4_i92] = c4_cv11[c4_i92];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i93 = 0; c4_i93 < 93; c4_i93++) {
    c4_arr[c4_i93] = c4_dv19[c4_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 163.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i94 = 0; c4_i94 < 256; c4_i94++) {
    c4_tt[c4_i94] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i95 = 0; c4_i95 < 93; c4_i95++) {
    c4_tt[c4_i95] = c4_arr[c4_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i96 = 0; c4_i96 < 256; c4_i96++) {
    c4_myarr256[c4_i96] = c4_tt[c4_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_l_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i97;
  static char_T c4_cv12[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '0', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i98;
  static real_T c4_dv20[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i99;
  int32_T c4_i100;
  int32_T c4_i101;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_m_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i97 = 0; c4_i97 < 105; c4_i97++) {
    c4_mystr[c4_i97] = c4_cv12[c4_i97];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i98 = 0; c4_i98 < 105; c4_i98++) {
    c4_arr[c4_i98] = c4_dv20[c4_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i99 = 0; c4_i99 < 256; c4_i99++) {
    c4_tt[c4_i99] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i100 = 0; c4_i100 < 105; c4_i100++) {
    c4_tt[c4_i100] = c4_arr[c4_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i101 = 0; c4_i101 < 256; c4_i101++) {
    c4_myarr256[c4_i101] = c4_tt[c4_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_m_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i102;
  static char_T c4_cv13[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h',
    't', 'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i103;
  static real_T c4_dv21[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_n_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i102 = 0; c4_i102 < 105; c4_i102++) {
    c4_mystr[c4_i102] = c4_cv13[c4_i102];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i103 = 0; c4_i103 < 105; c4_i103++) {
    c4_arr[c4_i103] = c4_dv21[c4_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i104 = 0; c4_i104 < 256; c4_i104++) {
    c4_tt[c4_i104] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i105 = 0; c4_i105 < 105; c4_i105++) {
    c4_tt[c4_i105] = c4_arr[c4_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i106 = 0; c4_i106 < 256; c4_i106++) {
    c4_myarr256[c4_i106] = c4_tt[c4_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_n_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[109];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[109];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i107;
  static char_T c4_cv14[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i108;
  static real_T c4_dv22[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i109;
  int32_T c4_i110;
  int32_T c4_i111;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_o_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i107 = 0; c4_i107 < 109; c4_i107++) {
    c4_mystr[c4_i107] = c4_cv14[c4_i107];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i108 = 0; c4_i108 < 109; c4_i108++) {
    c4_arr[c4_i108] = c4_dv22[c4_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i109 = 0; c4_i109 < 256; c4_i109++) {
    c4_tt[c4_i109] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i110 = 0; c4_i110 < 109; c4_i110++) {
    c4_tt[c4_i110] = c4_arr[c4_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i111 = 0; c4_i111 < 256; c4_i111++) {
    c4_myarr256[c4_i111] = c4_tt[c4_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_o_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i112;
  static char_T c4_cv15[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i113;
  static real_T c4_dv23[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i114;
  int32_T c4_i115;
  int32_T c4_i116;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_p_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i112 = 0; c4_i112 < 105; c4_i112++) {
    c4_mystr[c4_i112] = c4_cv15[c4_i112];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i113 = 0; c4_i113 < 105; c4_i113++) {
    c4_arr[c4_i113] = c4_dv23[c4_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i114 = 0; c4_i114 < 256; c4_i114++) {
    c4_tt[c4_i114] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i115 = 0; c4_i115 < 105; c4_i115++) {
    c4_tt[c4_i115] = c4_arr[c4_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i116 = 0; c4_i116 < 256; c4_i116++) {
    c4_myarr256[c4_i116] = c4_tt[c4_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_p_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i117;
  static char_T c4_cv16[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i118;
  static real_T c4_dv24[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i119;
  int32_T c4_i120;
  int32_T c4_i121;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_q_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i117 = 0; c4_i117 < 105; c4_i117++) {
    c4_mystr[c4_i117] = c4_cv16[c4_i117];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i118 = 0; c4_i118 < 105; c4_i118++) {
    c4_arr[c4_i118] = c4_dv24[c4_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i119 = 0; c4_i119 < 256; c4_i119++) {
    c4_tt[c4_i119] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i120 = 0; c4_i120 < 105; c4_i120++) {
    c4_tt[c4_i120] = c4_arr[c4_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i121 = 0; c4_i121 < 256; c4_i121++) {
    c4_myarr256[c4_i121] = c4_tt[c4_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_q_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i122;
  static char_T c4_cv17[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '0', '.', '5', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i123;
  static real_T c4_dv25[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i124;
  int32_T c4_i125;
  int32_T c4_i126;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_r_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i122 = 0; c4_i122 < 108; c4_i122++) {
    c4_mystr[c4_i122] = c4_cv17[c4_i122];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i123 = 0; c4_i123 < 108; c4_i123++) {
    c4_arr[c4_i123] = c4_dv25[c4_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i124 = 0; c4_i124 < 256; c4_i124++) {
    c4_tt[c4_i124] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i125 = 0; c4_i125 < 108; c4_i125++) {
    c4_tt[c4_i125] = c4_arr[c4_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i126 = 0; c4_i126 < 256; c4_i126++) {
    c4_myarr256[c4_i126] = c4_tt[c4_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_r_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[107];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[107];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i127;
  static char_T c4_cv18[107] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e',
    'e', 'd', '=', '\"', '0', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i128;
  static real_T c4_dv26[107] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i129;
  int32_T c4_i130;
  int32_T c4_i131;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_s_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i127 = 0; c4_i127 < 107; c4_i127++) {
    c4_mystr[c4_i127] = c4_cv18[c4_i127];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i128 = 0; c4_i128 < 107; c4_i128++) {
    c4_arr[c4_i128] = c4_dv26[c4_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 149.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i129 = 0; c4_i129 < 256; c4_i129++) {
    c4_tt[c4_i129] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i130 = 0; c4_i130 < 107; c4_i130++) {
    c4_tt[c4_i130] = c4_arr[c4_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i131 = 0; c4_i131 < 256; c4_i131++) {
    c4_myarr256[c4_i131] = c4_tt[c4_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_s_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[137];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[137];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i132;
  static char_T c4_cv19[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o',
    't', 'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a',
    'l', 'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l',
    '=', '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o',
    't', 'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', '0', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i133;
  static real_T c4_dv27[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i134;
  int32_T c4_i135;
  int32_T c4_i136;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_u_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i132 = 0; c4_i132 < 137; c4_i132++) {
    c4_mystr[c4_i132] = c4_cv19[c4_i132];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i133 = 0; c4_i133 < 137; c4_i133++) {
    c4_arr[c4_i133] = c4_dv27[c4_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i134 = 0; c4_i134 < 256; c4_i134++) {
    c4_tt[c4_i134] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i135 = 0; c4_i135 < 137; c4_i135++) {
    c4_tt[c4_i135] = c4_arr[c4_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i136 = 0; c4_i136 < 256; c4_i136++) {
    c4_myarr256[c4_i136] = c4_tt[c4_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_t_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[140];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[140];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i137;
  static char_T c4_cv20[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o',
    't', 'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a',
    'l', 'k', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l', '=',
    '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o', 't',
    'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 'f', 'a', 'c', 'i',
    'n', 'g', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', '0', ' ', '-', '0', '.', '6', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i138;
  static real_T c4_dv28[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 32.0, 115.0, 98.0, 109.0, 58.0, 97.0, 99.0,
    99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0, 99.0, 99.0, 101.0,
    108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0,
    103.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 45.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i139;
  int32_T c4_i140;
  int32_T c4_i141;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_v_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i137 = 0; c4_i137 < 140; c4_i137++) {
    c4_mystr[c4_i137] = c4_cv20[c4_i137];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i138 = 0; c4_i138 < 140; c4_i138++) {
    c4_arr[c4_i138] = c4_dv28[c4_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i139 = 0; c4_i139 < 256; c4_i139++) {
    c4_tt[c4_i139] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i140 = 0; c4_i140 < 140; c4_i140++) {
    c4_tt[c4_i140] = c4_arr[c4_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i141 = 0; c4_i141 < 256; c4_i141++) {
    c4_myarr256[c4_i141] = c4_tt[c4_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_u_encStr2Arr(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[139];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[139];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i142;
  static char_T c4_cv21[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o',
    't', 'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a',
    'l', 'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l',
    '=', '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o',
    't', 'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', '0', ' ', '0', '.', '6', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i143;
  static real_T c4_dv29[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 46.0, 54.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i144;
  int32_T c4_i145;
  int32_T c4_i146;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_w_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i142 = 0; c4_i142 < 139; c4_i142++) {
    c4_mystr[c4_i142] = c4_cv21[c4_i142];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i143 = 0; c4_i143 < 139; c4_i143++) {
    c4_arr[c4_i143] = c4_dv29[c4_i143];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i144 = 0; c4_i144 < 256; c4_i144++) {
    c4_tt[c4_i144] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i145 = 0; c4_i145 < 139; c4_i145++) {
    c4_tt[c4_i145] = c4_arr[c4_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i146 = 0; c4_i146 < 256; c4_i146++) {
    c4_myarr256[c4_i146] = c4_tt[c4_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_decArr2Str(SFc4_DemoWalk_KInstanceStruct *chartInstance, real_T
  c4_myarr256[256], char_T c4_mystr_data[], int32_T c4_mystr_sizes[2])
{
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i147;
  boolean_T c4_x[256];
  int32_T c4_k;
  int32_T c4_i;
  int32_T c4_b_i;
  int32_T c4_a;
  int32_T c4_b_a;
  const mxArray *c4_y = NULL;
  int32_T c4_tmp_sizes;
  int32_T c4_loop_ub;
  int32_T c4_i148;
  int32_T c4_tmp_data[256];
  int32_T c4_y_sizes;
  int32_T c4_j;
  int32_T c4_c_i;
  int32_T c4_d_i;
  int32_T c4_y_data[256];
  int32_T c4_c_a;
  int32_T c4_d_a;
  int32_T c4_s_sizes[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i149;
  real_T c4_s_data[256];
  int32_T c4_i150;
  real_T c4_dv30[2];
  int32_T c4_b_tmp_sizes[2];
  int32_T c4_iv0[2];
  int32_T c4_i151;
  int32_T c4_i152;
  int32_T c4_c_loop_ub;
  int32_T c4_i153;
  char_T c4_b_tmp_data[256];
  int32_T c4_i154;
  int32_T c4_c_tmp_sizes;
  int32_T c4_d_loop_ub;
  int32_T c4_i155;
  char_T c4_c_tmp_data[256];
  int32_T c4_i156;
  int32_T c4_mystr[2];
  int32_T c4_e_loop_ub;
  int32_T c4_i157;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_bb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 2U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c4_mystr_data, (const int32_T *)
    c4_mystr_sizes, NULL, 0, 3, (void *)c4_kb_sf_marshallOut, (void *)
    c4_g_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, 3);
  for (c4_i147 = 0; c4_i147 < 256; c4_i147++) {
    c4_x[c4_i147] = (c4_myarr256[c4_i147] != 0.0);
  }

  c4_k = 0;
  for (c4_i = 1; c4_i < 257; c4_i++) {
    c4_b_i = c4_i - 1;
    if (c4_x[c4_b_i]) {
      c4_a = c4_k;
      c4_b_a = c4_a + 1;
      c4_k = c4_b_a;
    }
  }

  if (c4_k <= 256) {
  } else {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c4_y);
  }

  c4_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c4_k);
  c4_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c4_k) - 1;
  for (c4_i148 = 0; c4_i148 <= c4_loop_ub; c4_i148++) {
    c4_tmp_data[c4_i148] = 0;
  }

  c4_y_sizes = c4_tmp_sizes;
  c4_j = 1;
  for (c4_c_i = 1; c4_c_i < 257; c4_c_i++) {
    c4_d_i = c4_c_i;
    if (c4_x[c4_d_i - 1]) {
      c4_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c4_j, 1, c4_y_sizes, 1, 0) - 1] =
        c4_d_i;
      c4_c_a = c4_j;
      c4_d_a = c4_c_a + 1;
      c4_j = c4_d_a;
    }
  }

  c4_s_sizes[0] = 1;
  c4_s_sizes[1] = c4_y_sizes;
  c4_b_loop_ub = c4_y_sizes - 1;
  for (c4_i149 = 0; c4_i149 <= c4_b_loop_ub; c4_i149++) {
    c4_s_data[c4_s_sizes[0] * c4_i149] = c4_myarr256[c4_y_data[c4_i149] - 1];
  }

  for (c4_i150 = 0; c4_i150 < 2; c4_i150++) {
    c4_dv30[c4_i150] = (real_T)c4_s_sizes[c4_i150];
  }

  c4_b_tmp_sizes[0] = 1;
  c4_iv0[0] = 1;
  c4_iv0[1] = (int32_T)c4_dv30[1];
  c4_b_tmp_sizes[1] = c4_iv0[1];
  c4_i151 = c4_b_tmp_sizes[0];
  c4_i152 = c4_b_tmp_sizes[1];
  c4_c_loop_ub = (int32_T)c4_dv30[1] - 1;
  for (c4_i153 = 0; c4_i153 <= c4_c_loop_ub; c4_i153++) {
    c4_b_tmp_data[c4_i153] = ' ';
  }

  for (c4_i154 = 0; c4_i154 < 2; c4_i154++) {
    c4_mystr_sizes[c4_i154] = c4_b_tmp_sizes[c4_i154];
  }

  c4_c_tmp_sizes = c4_s_sizes[1];
  c4_d_loop_ub = c4_s_sizes[1] - 1;
  for (c4_i155 = 0; c4_i155 <= c4_d_loop_ub; c4_i155++) {
    c4_c_tmp_data[c4_i155] = (char_T)(int8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("char",
      (int32_T)_SFD_INTEGER_CHECK("", c4_s_data[c4_i155]), 0, 255, 0, 2);
  }

  _SFD_SIZE_EQ_CHECK_1D(c4_mystr_sizes[1], c4_c_tmp_sizes);
  for (c4_i156 = 0; c4_i156 < 2; c4_i156++) {
    c4_mystr[c4_i156] = c4_mystr_sizes[c4_i156];
  }

  c4_mystr_sizes[0] = 1;
  c4_mystr_sizes[1] = c4_mystr[1];
  c4_e_loop_ub = c4_mystr[1] - 1;
  for (c4_i157 = 0; c4_i157 <= c4_e_loop_ub; c4_i157++) {
    c4_mystr_data[c4_mystr_sizes[0] * c4_i157] = c4_c_tmp_data[c4_mystr[0] *
      c4_i157];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c4_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_rand(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  uint32_T c4_uv2[625];
  int32_T c4_i158;
  real_T c4_d0;
  if (!chartInstance->c4_method_not_empty) {
    chartInstance->c4_method = 7U;
    chartInstance->c4_method_not_empty = true;
  }

  if (!chartInstance->c4_c_state_not_empty) {
    c4_eml_rand_mt19937ar(chartInstance, c4_uv2);
    for (c4_i158 = 0; c4_i158 < 625; c4_i158++) {
      chartInstance->c4_c_state[c4_i158] = c4_uv2[c4_i158];
    }

    chartInstance->c4_c_state_not_empty = true;
  }

  c4_d0 = c4_c_eml_rand_mt19937ar(chartInstance, chartInstance->c4_c_state);
  return c4_d0;
}

static void c4_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_d_state[625])
{
  real_T c4_d1;
  int32_T c4_i159;
  c4_d1 = 5489.0;
  for (c4_i159 = 0; c4_i159 < 625; c4_i159++) {
    c4_d_state[c4_i159] = 0U;
  }

  c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d1);
}

static void c4_twister_state_vector(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625])
{
  int32_T c4_i160;
  for (c4_i160 = 0; c4_i160 < 625; c4_i160++) {
    c4_b_mt[c4_i160] = c4_mt[c4_i160];
  }

  c4_b_twister_state_vector(chartInstance, c4_b_mt, c4_seed);
}

static void c4_b_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T *c4_r)
{
  int32_T c4_i161;
  for (c4_i161 = 0; c4_i161 < 625; c4_i161++) {
    c4_e_state[c4_i161] = c4_d_state[c4_i161];
  }

  *c4_r = c4_c_eml_rand_mt19937ar(chartInstance, c4_e_state);
}

static void c4_eml_error(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  int32_T c4_i162;
  static char_T c4_cv22[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c4_u[37];
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  for (c4_i162 = 0; c4_i162 < 37; c4_i162++) {
    c4_u[c4_i162] = c4_cv22[c4_i162];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c4_y));
}

static real_T c4_randi(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 22.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  return 1.0 + c4_b_x;
}

static real_T c4_b_randi(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 9.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  return 14.0 + c4_b_x;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\18-9-2015-v2-Matlab-prior-M+M\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\18-9-2015-v2-Matlab-prior-M+M\\decArr2Str.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i163;
  real_T c4_b_inData[256];
  int32_T c4_i164;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i163 = 0; c4_i163 < 256; c4_i163++) {
    c4_b_inData[c4_i163] = (*(real_T (*)[256])c4_inData)[c4_i163];
  }

  for (c4_i164 = 0; c4_i164 < 256; c4_i164++) {
    c4_u[c4_i164] = c4_b_inData[c4_i164];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_poseBML, const char_T *c4_identifier, real_T c4_y[256])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
}

static void c4_b_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[256])
{
  real_T c4_dv31[256];
  int32_T c4_i165;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv31, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c4_i165 = 0; c4_i165 < 256; c4_i165++) {
    c4_y[c4_i165] = c4_dv31[c4_i165];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_poseBML;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i166;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_poseBML = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
  for (c4_i166 = 0; c4_i166 < 256; c4_i166++) {
    (*(real_T (*)[256])c4_outData)[c4_i166] = c4_y[c4_i166];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_pr, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_pr), &c4_thisId);
  sf_mex_destroy(&c4_pr);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_pr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_pr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_pr), &c4_thisId);
  sf_mex_destroy(&c4_pr);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_e_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_aVarTruthTableCondition_22;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_aVarTruthTableCondition_22 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_aVarTruthTableCondition_22), &c4_thisId);
  sf_mex_destroy(&c4_aVarTruthTableCondition_22);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i167;
  real_T c4_b_inData[256];
  int32_T c4_i168;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i167 = 0; c4_i167 < 256; c4_i167++) {
    c4_b_inData[c4_i167] = (*(real_T (*)[256])c4_inData)[c4_i167];
  }

  for (c4_i168 = 0; c4_i168 < 256; c4_i168++) {
    c4_u[c4_i168] = c4_b_inData[c4_i168];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_myarr256, const char_T *c4_identifier, real_T c4_y[256])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
}

static void c4_g_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[256])
{
  real_T c4_dv32[256];
  int32_T c4_i169;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv32, 1, 0, 0U, 1, 0U, 1, 256);
  for (c4_i169 = 0; c4_i169 < 256; c4_i169++) {
    c4_y[c4_i169] = c4_dv32[c4_i169];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_myarr256;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i170;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_myarr256 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
  for (c4_i170 = 0; c4_i170 < 256; c4_i170++) {
    (*(real_T (*)[256])c4_outData)[c4_i170] = c4_y[c4_i170];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i171;
  char_T c4_b_inData[108];
  int32_T c4_i172;
  char_T c4_u[108];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i171 = 0; c4_i171 < 108; c4_i171++) {
    c4_b_inData[c4_i171] = (*(char_T (*)[108])c4_inData)[c4_i171];
  }

  for (c4_i172 = 0; c4_i172 < 108; c4_i172++) {
    c4_u[c4_i172] = c4_b_inData[c4_i172];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 108),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i173;
  real_T c4_b_inData[108];
  int32_T c4_i174;
  real_T c4_u[108];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i173 = 0; c4_i173 < 108; c4_i173++) {
    c4_b_inData[c4_i173] = (*(real_T (*)[108])c4_inData)[c4_i173];
  }

  for (c4_i174 = 0; c4_i174 < 108; c4_i174++) {
    c4_u[c4_i174] = c4_b_inData[c4_i174];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 108), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i175;
  char_T c4_b_inData[104];
  int32_T c4_i176;
  char_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i175 = 0; c4_i175 < 104; c4_i175++) {
    c4_b_inData[c4_i175] = (*(char_T (*)[104])c4_inData)[c4_i175];
  }

  for (c4_i176 = 0; c4_i176 < 104; c4_i176++) {
    c4_u[c4_i176] = c4_b_inData[c4_i176];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i177;
  real_T c4_b_inData[104];
  int32_T c4_i178;
  real_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i177 = 0; c4_i177 < 104; c4_i177++) {
    c4_b_inData[c4_i177] = (*(real_T (*)[104])c4_inData)[c4_i177];
  }

  for (c4_i178 = 0; c4_i178 < 104; c4_i178++) {
    c4_u[c4_i178] = c4_b_inData[c4_i178];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i179;
  char_T c4_b_inData[106];
  int32_T c4_i180;
  char_T c4_u[106];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i179 = 0; c4_i179 < 106; c4_i179++) {
    c4_b_inData[c4_i179] = (*(char_T (*)[106])c4_inData)[c4_i179];
  }

  for (c4_i180 = 0; c4_i180 < 106; c4_i180++) {
    c4_u[c4_i180] = c4_b_inData[c4_i180];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 106),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i181;
  real_T c4_b_inData[106];
  int32_T c4_i182;
  real_T c4_u[106];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i181 = 0; c4_i181 < 106; c4_i181++) {
    c4_b_inData[c4_i181] = (*(real_T (*)[106])c4_inData)[c4_i181];
  }

  for (c4_i182 = 0; c4_i182 < 106; c4_i182++) {
    c4_u[c4_i182] = c4_b_inData[c4_i182];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 106), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_k_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i183;
  char_T c4_b_inData[149];
  int32_T c4_i184;
  char_T c4_u[149];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i183 = 0; c4_i183 < 149; c4_i183++) {
    c4_b_inData[c4_i183] = (*(char_T (*)[149])c4_inData)[c4_i183];
  }

  for (c4_i184 = 0; c4_i184 < 149; c4_i184++) {
    c4_u[c4_i184] = c4_b_inData[c4_i184];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 149),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_l_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i185;
  real_T c4_b_inData[149];
  int32_T c4_i186;
  real_T c4_u[149];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i185 = 0; c4_i185 < 149; c4_i185++) {
    c4_b_inData[c4_i185] = (*(real_T (*)[149])c4_inData)[c4_i185];
  }

  for (c4_i186 = 0; c4_i186 < 149; c4_i186++) {
    c4_u[c4_i186] = c4_b_inData[c4_i186];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 149), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_m_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i187;
  char_T c4_b_inData[91];
  int32_T c4_i188;
  char_T c4_u[91];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i187 = 0; c4_i187 < 91; c4_i187++) {
    c4_b_inData[c4_i187] = (*(char_T (*)[91])c4_inData)[c4_i187];
  }

  for (c4_i188 = 0; c4_i188 < 91; c4_i188++) {
    c4_u[c4_i188] = c4_b_inData[c4_i188];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_n_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i189;
  real_T c4_b_inData[91];
  int32_T c4_i190;
  real_T c4_u[91];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i189 = 0; c4_i189 < 91; c4_i189++) {
    c4_b_inData[c4_i189] = (*(real_T (*)[91])c4_inData)[c4_i189];
  }

  for (c4_i190 = 0; c4_i190 < 91; c4_i190++) {
    c4_u[c4_i190] = c4_b_inData[c4_i190];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_o_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i191;
  char_T c4_b_inData[105];
  int32_T c4_i192;
  char_T c4_u[105];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i191 = 0; c4_i191 < 105; c4_i191++) {
    c4_b_inData[c4_i191] = (*(char_T (*)[105])c4_inData)[c4_i191];
  }

  for (c4_i192 = 0; c4_i192 < 105; c4_i192++) {
    c4_u[c4_i192] = c4_b_inData[c4_i192];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_p_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i193;
  real_T c4_b_inData[105];
  int32_T c4_i194;
  real_T c4_u[105];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i193 = 0; c4_i193 < 105; c4_i193++) {
    c4_b_inData[c4_i193] = (*(real_T (*)[105])c4_inData)[c4_i193];
  }

  for (c4_i194 = 0; c4_i194 < 105; c4_i194++) {
    c4_u[c4_i194] = c4_b_inData[c4_i194];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_q_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i195;
  char_T c4_b_inData[93];
  int32_T c4_i196;
  char_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i195 = 0; c4_i195 < 93; c4_i195++) {
    c4_b_inData[c4_i195] = (*(char_T (*)[93])c4_inData)[c4_i195];
  }

  for (c4_i196 = 0; c4_i196 < 93; c4_i196++) {
    c4_u[c4_i196] = c4_b_inData[c4_i196];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_r_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i197;
  real_T c4_b_inData[93];
  int32_T c4_i198;
  real_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i197 = 0; c4_i197 < 93; c4_i197++) {
    c4_b_inData[c4_i197] = (*(real_T (*)[93])c4_inData)[c4_i197];
  }

  for (c4_i198 = 0; c4_i198 < 93; c4_i198++) {
    c4_u[c4_i198] = c4_b_inData[c4_i198];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_s_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i199;
  char_T c4_b_inData[92];
  int32_T c4_i200;
  char_T c4_u[92];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i199 = 0; c4_i199 < 92; c4_i199++) {
    c4_b_inData[c4_i199] = (*(char_T (*)[92])c4_inData)[c4_i199];
  }

  for (c4_i200 = 0; c4_i200 < 92; c4_i200++) {
    c4_u[c4_i200] = c4_b_inData[c4_i200];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_t_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i201;
  real_T c4_b_inData[92];
  int32_T c4_i202;
  real_T c4_u[92];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i201 = 0; c4_i201 < 92; c4_i201++) {
    c4_b_inData[c4_i201] = (*(real_T (*)[92])c4_inData)[c4_i201];
  }

  for (c4_i202 = 0; c4_i202 < 92; c4_i202++) {
    c4_u[c4_i202] = c4_b_inData[c4_i202];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_u_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i203;
  char_T c4_b_inData[109];
  int32_T c4_i204;
  char_T c4_u[109];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i203 = 0; c4_i203 < 109; c4_i203++) {
    c4_b_inData[c4_i203] = (*(char_T (*)[109])c4_inData)[c4_i203];
  }

  for (c4_i204 = 0; c4_i204 < 109; c4_i204++) {
    c4_u[c4_i204] = c4_b_inData[c4_i204];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_v_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i205;
  real_T c4_b_inData[109];
  int32_T c4_i206;
  real_T c4_u[109];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i205 = 0; c4_i205 < 109; c4_i205++) {
    c4_b_inData[c4_i205] = (*(real_T (*)[109])c4_inData)[c4_i205];
  }

  for (c4_i206 = 0; c4_i206 < 109; c4_i206++) {
    c4_u[c4_i206] = c4_b_inData[c4_i206];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_w_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i207;
  char_T c4_b_inData[107];
  int32_T c4_i208;
  char_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i207 = 0; c4_i207 < 107; c4_i207++) {
    c4_b_inData[c4_i207] = (*(char_T (*)[107])c4_inData)[c4_i207];
  }

  for (c4_i208 = 0; c4_i208 < 107; c4_i208++) {
    c4_u[c4_i208] = c4_b_inData[c4_i208];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 107),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_x_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i209;
  real_T c4_b_inData[107];
  int32_T c4_i210;
  real_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i209 = 0; c4_i209 < 107; c4_i209++) {
    c4_b_inData[c4_i209] = (*(real_T (*)[107])c4_inData)[c4_i209];
  }

  for (c4_i210 = 0; c4_i210 < 107; c4_i210++) {
    c4_u[c4_i210] = c4_b_inData[c4_i210];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 107), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_y_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  creal_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(creal_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static creal_T c4_h_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  creal_T c4_y;
  creal_T c4_dc0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_dc0, 1, 0, 1U, 0, 0U, 0);
  c4_y = c4_dc0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_p;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  creal_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_p = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_p), &c4_thisId);
  sf_mex_destroy(&c4_p);
  *(creal_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i211;
  char_T c4_b_inData[137];
  int32_T c4_i212;
  char_T c4_u[137];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i211 = 0; c4_i211 < 137; c4_i211++) {
    c4_b_inData[c4_i211] = (*(char_T (*)[137])c4_inData)[c4_i211];
  }

  for (c4_i212 = 0; c4_i212 < 137; c4_i212++) {
    c4_u[c4_i212] = c4_b_inData[c4_i212];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i213;
  real_T c4_b_inData[137];
  int32_T c4_i214;
  real_T c4_u[137];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i213 = 0; c4_i213 < 137; c4_i213++) {
    c4_b_inData[c4_i213] = (*(real_T (*)[137])c4_inData)[c4_i213];
  }

  for (c4_i214 = 0; c4_i214 < 137; c4_i214++) {
    c4_u[c4_i214] = c4_b_inData[c4_i214];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i215;
  char_T c4_b_inData[140];
  int32_T c4_i216;
  char_T c4_u[140];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i215 = 0; c4_i215 < 140; c4_i215++) {
    c4_b_inData[c4_i215] = (*(char_T (*)[140])c4_inData)[c4_i215];
  }

  for (c4_i216 = 0; c4_i216 < 140; c4_i216++) {
    c4_u[c4_i216] = c4_b_inData[c4_i216];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_db_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i217;
  real_T c4_b_inData[140];
  int32_T c4_i218;
  real_T c4_u[140];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i217 = 0; c4_i217 < 140; c4_i217++) {
    c4_b_inData[c4_i217] = (*(real_T (*)[140])c4_inData)[c4_i217];
  }

  for (c4_i218 = 0; c4_i218 < 140; c4_i218++) {
    c4_u[c4_i218] = c4_b_inData[c4_i218];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i219;
  char_T c4_b_inData[139];
  int32_T c4_i220;
  char_T c4_u[139];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i219 = 0; c4_i219 < 139; c4_i219++) {
    c4_b_inData[c4_i219] = (*(char_T (*)[139])c4_inData)[c4_i219];
  }

  for (c4_i220 = 0; c4_i220 < 139; c4_i220++) {
    c4_u[c4_i220] = c4_b_inData[c4_i220];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i221;
  real_T c4_b_inData[139];
  int32_T c4_i222;
  real_T c4_u[139];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i221 = 0; c4_i221 < 139; c4_i221++) {
    c4_b_inData[c4_i221] = (*(real_T (*)[139])c4_inData)[c4_i221];
  }

  for (c4_i222 = 0; c4_i222 < 139; c4_i222++) {
    c4_u[c4_i222] = c4_b_inData[c4_i222];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i223;
  char_T c4_b_inData[115];
  int32_T c4_i224;
  char_T c4_u[115];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i223 = 0; c4_i223 < 115; c4_i223++) {
    c4_b_inData[c4_i223] = (*(char_T (*)[115])c4_inData)[c4_i223];
  }

  for (c4_i224 = 0; c4_i224 < 115; c4_i224++) {
    c4_u[c4_i224] = c4_b_inData[c4_i224];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i225;
  real_T c4_b_inData[115];
  int32_T c4_i226;
  real_T c4_u[115];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i225 = 0; c4_i225 < 115; c4_i225++) {
    c4_b_inData[c4_i225] = (*(real_T (*)[115])c4_inData)[c4_i225];
  }

  for (c4_i226 = 0; c4_i226 < 115; c4_i226++) {
    c4_u[c4_i226] = c4_b_inData[c4_i226];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i227;
  int32_T c4_i228;
  int32_T c4_i229;
  real_T c4_b_inData[1280];
  int32_T c4_i230;
  int32_T c4_i231;
  int32_T c4_i232;
  real_T c4_u[1280];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i227 = 0;
  for (c4_i228 = 0; c4_i228 < 5; c4_i228++) {
    for (c4_i229 = 0; c4_i229 < 256; c4_i229++) {
      c4_b_inData[c4_i229 + c4_i227] = (*(real_T (*)[1280])c4_inData)[c4_i229 +
        c4_i227];
    }

    c4_i227 += 256;
  }

  c4_i230 = 0;
  for (c4_i231 = 0; c4_i231 < 5; c4_i231++) {
    for (c4_i232 = 0; c4_i232 < 256; c4_i232++) {
      c4_u[c4_i232 + c4_i230] = c4_b_inData[c4_i232 + c4_i230];
    }

    c4_i230 += 256;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 256, 5), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_i_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_newBmls, const char_T *c4_identifier, real_T c4_y[1280])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_newBmls), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_newBmls);
}

static void c4_j_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[1280])
{
  real_T c4_dv33[1280];
  int32_T c4_i233;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv33, 1, 0, 0U, 1, 0U, 2, 256,
                5);
  for (c4_i233 = 0; c4_i233 < 1280; c4_i233++) {
    c4_y[c4_i233] = c4_dv33[c4_i233];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_newBmls;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[1280];
  int32_T c4_i234;
  int32_T c4_i235;
  int32_T c4_i236;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_newBmls = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_newBmls), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_newBmls);
  c4_i234 = 0;
  for (c4_i235 = 0; c4_i235 < 5; c4_i235++) {
    for (c4_i236 = 0; c4_i236 < 256; c4_i236++) {
      (*(real_T (*)[1280])c4_outData)[c4_i236 + c4_i234] = c4_y[c4_i236 +
        c4_i234];
    }

    c4_i234 += 256;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  char_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(char_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, char_T
  c4_inData_data[], int32_T c4_inData_sizes[2])
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_b_inData_sizes[2];
  int32_T c4_loop_ub;
  int32_T c4_i237;
  char_T c4_b_inData_data[256];
  int32_T c4_u_sizes[2];
  int32_T c4_b_loop_ub;
  int32_T c4_i238;
  char_T c4_u_data[256];
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_b_inData_sizes[0] = 1;
  c4_b_inData_sizes[1] = c4_inData_sizes[1];
  c4_loop_ub = c4_inData_sizes[1] - 1;
  for (c4_i237 = 0; c4_i237 <= c4_loop_ub; c4_i237++) {
    c4_b_inData_data[c4_b_inData_sizes[0] * c4_i237] =
      c4_inData_data[c4_inData_sizes[0] * c4_i237];
  }

  c4_u_sizes[0] = 1;
  c4_u_sizes[1] = c4_b_inData_sizes[1];
  c4_b_loop_ub = c4_b_inData_sizes[1] - 1;
  for (c4_i238 = 0; c4_i238 <= c4_b_loop_ub; c4_i238++) {
    c4_u_data[c4_u_sizes[0] * c4_i238] = c4_b_inData_data[c4_b_inData_sizes[0] *
      c4_i238];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u_data, 10, 0U, 1U, 0U, 2,
    c4_u_sizes[0], c4_u_sizes[1]), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_k_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, char_T c4_y_data[],
  int32_T c4_y_sizes[2])
{
  int32_T c4_i239;
  uint32_T c4_uv3[2];
  int32_T c4_i240;
  static boolean_T c4_bv0[2] = { false, true };

  boolean_T c4_bv1[2];
  int32_T c4_tmp_sizes[2];
  char_T c4_tmp_data[256];
  int32_T c4_y;
  int32_T c4_b_y;
  int32_T c4_loop_ub;
  int32_T c4_i241;
  (void)chartInstance;
  for (c4_i239 = 0; c4_i239 < 2; c4_i239++) {
    c4_uv3[c4_i239] = 1U + 255U * (uint32_T)c4_i239;
  }

  for (c4_i240 = 0; c4_i240 < 2; c4_i240++) {
    c4_bv1[c4_i240] = c4_bv0[c4_i240];
  }

  sf_mex_import_vs(c4_parentId, sf_mex_dup(c4_u), c4_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c4_bv1, c4_uv3, c4_tmp_sizes);
  c4_y_sizes[0] = 1;
  c4_y_sizes[1] = c4_tmp_sizes[1];
  c4_y = c4_y_sizes[0];
  c4_b_y = c4_y_sizes[1];
  c4_loop_ub = c4_tmp_sizes[0] * c4_tmp_sizes[1] - 1;
  for (c4_i241 = 0; c4_i241 <= c4_loop_ub; c4_i241++) {
    c4_y_data[c4_i241] = c4_tmp_data[c4_i241];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, char_T c4_outData_data[], int32_T
  c4_outData_sizes[2])
{
  const mxArray *c4_mystr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y_sizes[2];
  char_T c4_y_data[256];
  int32_T c4_loop_ub;
  int32_T c4_i242;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mystr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_mystr), &c4_thisId,
                        c4_y_data, c4_y_sizes);
  sf_mex_destroy(&c4_mystr);
  c4_outData_sizes[0] = 1;
  c4_outData_sizes[1] = c4_y_sizes[1];
  c4_loop_ub = c4_y_sizes[1] - 1;
  for (c4_i242 = 0; c4_i242 <= c4_loop_ub; c4_i242++) {
    c4_outData_data[c4_outData_sizes[0] * c4_i242] = c4_y_data[c4_y_sizes[0] *
      c4_i242];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_DemoWalk_K_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 52, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  const mxArray *c4_rhs14 = NULL;
  const mxArray *c4_lhs14 = NULL;
  const mxArray *c4_rhs15 = NULL;
  const mxArray *c4_lhs15 = NULL;
  const mxArray *c4_rhs16 = NULL;
  const mxArray *c4_lhs16 = NULL;
  const mxArray *c4_rhs17 = NULL;
  const mxArray *c4_lhs17 = NULL;
  const mxArray *c4_rhs18 = NULL;
  const mxArray *c4_lhs18 = NULL;
  const mxArray *c4_rhs19 = NULL;
  const mxArray *c4_lhs19 = NULL;
  const mxArray *c4_rhs20 = NULL;
  const mxArray *c4_lhs20 = NULL;
  const mxArray *c4_rhs21 = NULL;
  const mxArray *c4_lhs21 = NULL;
  const mxArray *c4_rhs22 = NULL;
  const mxArray *c4_lhs22 = NULL;
  const mxArray *c4_rhs23 = NULL;
  const mxArray *c4_lhs23 = NULL;
  const mxArray *c4_rhs24 = NULL;
  const mxArray *c4_lhs24 = NULL;
  const mxArray *c4_rhs25 = NULL;
  const mxArray *c4_lhs25 = NULL;
  const mxArray *c4_rhs26 = NULL;
  const mxArray *c4_lhs26 = NULL;
  const mxArray *c4_rhs27 = NULL;
  const mxArray *c4_lhs27 = NULL;
  const mxArray *c4_rhs28 = NULL;
  const mxArray *c4_lhs28 = NULL;
  const mxArray *c4_rhs29 = NULL;
  const mxArray *c4_lhs29 = NULL;
  const mxArray *c4_rhs30 = NULL;
  const mxArray *c4_lhs30 = NULL;
  const mxArray *c4_rhs31 = NULL;
  const mxArray *c4_lhs31 = NULL;
  const mxArray *c4_rhs32 = NULL;
  const mxArray *c4_lhs32 = NULL;
  const mxArray *c4_rhs33 = NULL;
  const mxArray *c4_lhs33 = NULL;
  const mxArray *c4_rhs34 = NULL;
  const mxArray *c4_lhs34 = NULL;
  const mxArray *c4_rhs35 = NULL;
  const mxArray *c4_lhs35 = NULL;
  const mxArray *c4_rhs36 = NULL;
  const mxArray *c4_lhs36 = NULL;
  const mxArray *c4_rhs37 = NULL;
  const mxArray *c4_lhs37 = NULL;
  const mxArray *c4_rhs38 = NULL;
  const mxArray *c4_lhs38 = NULL;
  const mxArray *c4_rhs39 = NULL;
  const mxArray *c4_lhs39 = NULL;
  const mxArray *c4_rhs40 = NULL;
  const mxArray *c4_lhs40 = NULL;
  const mxArray *c4_rhs41 = NULL;
  const mxArray *c4_lhs41 = NULL;
  const mxArray *c4_rhs42 = NULL;
  const mxArray *c4_lhs42 = NULL;
  const mxArray *c4_rhs43 = NULL;
  const mxArray *c4_lhs43 = NULL;
  const mxArray *c4_rhs44 = NULL;
  const mxArray *c4_lhs44 = NULL;
  const mxArray *c4_rhs45 = NULL;
  const mxArray *c4_lhs45 = NULL;
  const mxArray *c4_rhs46 = NULL;
  const mxArray *c4_lhs46 = NULL;
  const mxArray *c4_rhs47 = NULL;
  const mxArray *c4_lhs47 = NULL;
  const mxArray *c4_rhs48 = NULL;
  const mxArray *c4_lhs48 = NULL;
  const mxArray *c4_rhs49 = NULL;
  const mxArray *c4_lhs49 = NULL;
  const mxArray *c4_rhs50 = NULL;
  const mxArray *c4_lhs50 = NULL;
  const mxArray *c4_rhs51 = NULL;
  const mxArray *c4_lhs51 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("disp"), "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("decArr2Str"), "name", "name",
                  6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1403644012U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_li_find"), "name", "name",
                  7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("intmax"), "name", "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c4_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c4_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c4_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/18-9-2015-v2-Matlab-prior-M+M/decArr2Str.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "name", "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c4_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("disp"), "name", "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("randi"), "name", "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c4_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c4_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rand"), "name", "name", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c4_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c4_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c4_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c4_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c4_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c4_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c4_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c4_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c4_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c4_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c4_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c4_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c4_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c4_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eps"), "name", "name", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c4_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_eps"), "name", "name", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c4_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c4_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isequal"), "name", "name", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c4_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c4_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c4_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c4_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c4_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c4_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c4_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c4_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c4_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c4_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c4_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c4_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c4_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c4_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs51), "lhs", "lhs",
                  51);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
  sf_mex_destroy(&c4_rhs14);
  sf_mex_destroy(&c4_lhs14);
  sf_mex_destroy(&c4_rhs15);
  sf_mex_destroy(&c4_lhs15);
  sf_mex_destroy(&c4_rhs16);
  sf_mex_destroy(&c4_lhs16);
  sf_mex_destroy(&c4_rhs17);
  sf_mex_destroy(&c4_lhs17);
  sf_mex_destroy(&c4_rhs18);
  sf_mex_destroy(&c4_lhs18);
  sf_mex_destroy(&c4_rhs19);
  sf_mex_destroy(&c4_lhs19);
  sf_mex_destroy(&c4_rhs20);
  sf_mex_destroy(&c4_lhs20);
  sf_mex_destroy(&c4_rhs21);
  sf_mex_destroy(&c4_lhs21);
  sf_mex_destroy(&c4_rhs22);
  sf_mex_destroy(&c4_lhs22);
  sf_mex_destroy(&c4_rhs23);
  sf_mex_destroy(&c4_lhs23);
  sf_mex_destroy(&c4_rhs24);
  sf_mex_destroy(&c4_lhs24);
  sf_mex_destroy(&c4_rhs25);
  sf_mex_destroy(&c4_lhs25);
  sf_mex_destroy(&c4_rhs26);
  sf_mex_destroy(&c4_lhs26);
  sf_mex_destroy(&c4_rhs27);
  sf_mex_destroy(&c4_lhs27);
  sf_mex_destroy(&c4_rhs28);
  sf_mex_destroy(&c4_lhs28);
  sf_mex_destroy(&c4_rhs29);
  sf_mex_destroy(&c4_lhs29);
  sf_mex_destroy(&c4_rhs30);
  sf_mex_destroy(&c4_lhs30);
  sf_mex_destroy(&c4_rhs31);
  sf_mex_destroy(&c4_lhs31);
  sf_mex_destroy(&c4_rhs32);
  sf_mex_destroy(&c4_lhs32);
  sf_mex_destroy(&c4_rhs33);
  sf_mex_destroy(&c4_lhs33);
  sf_mex_destroy(&c4_rhs34);
  sf_mex_destroy(&c4_lhs34);
  sf_mex_destroy(&c4_rhs35);
  sf_mex_destroy(&c4_lhs35);
  sf_mex_destroy(&c4_rhs36);
  sf_mex_destroy(&c4_lhs36);
  sf_mex_destroy(&c4_rhs37);
  sf_mex_destroy(&c4_lhs37);
  sf_mex_destroy(&c4_rhs38);
  sf_mex_destroy(&c4_lhs38);
  sf_mex_destroy(&c4_rhs39);
  sf_mex_destroy(&c4_lhs39);
  sf_mex_destroy(&c4_rhs40);
  sf_mex_destroy(&c4_lhs40);
  sf_mex_destroy(&c4_rhs41);
  sf_mex_destroy(&c4_lhs41);
  sf_mex_destroy(&c4_rhs42);
  sf_mex_destroy(&c4_lhs42);
  sf_mex_destroy(&c4_rhs43);
  sf_mex_destroy(&c4_lhs43);
  sf_mex_destroy(&c4_rhs44);
  sf_mex_destroy(&c4_lhs44);
  sf_mex_destroy(&c4_rhs45);
  sf_mex_destroy(&c4_lhs45);
  sf_mex_destroy(&c4_rhs46);
  sf_mex_destroy(&c4_lhs46);
  sf_mex_destroy(&c4_rhs47);
  sf_mex_destroy(&c4_lhs47);
  sf_mex_destroy(&c4_rhs48);
  sf_mex_destroy(&c4_lhs48);
  sf_mex_destroy(&c4_rhs49);
  sf_mex_destroy(&c4_lhs49);
  sf_mex_destroy(&c4_rhs50);
  sf_mex_destroy(&c4_lhs50);
  sf_mex_destroy(&c4_rhs51);
  sf_mex_destroy(&c4_lhs51);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static void c4_activate_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = c4_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_deactivate_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_increment_counters_secsc4_DemoWalk_K
  (SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  if (chartInstance->c4_temporalCounter_i1 < 63U) {
    chartInstance->c4_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c4_temporalCounter_i1 + 1);
  }
}

static void c4_reset_counters_secsc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c4_DemoWalk_K_secs(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_activate_secsc4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c4_DemoWalk_K_secs(SimStruct
  *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_increment_counters_secsc4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c4_DemoWalk_K_secs(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_reset_counters_secsc4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_deactivate_c4_DemoWalk_K_secs(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_deactivate_secsc4_DemoWalk_K(chartInstance);
}

boolean_T sf_exported_auto_isStablec4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  return chartInstance->c4_isStable;
}

void sf_exported_auto_duringc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_c4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_enterc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_enter_atomic_c4_DemoWalk_K(chartInstance);
  c4_enter_internal_c4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_exitc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_exit_internal_c4_DemoWalk_K(chartInstance);
}

void sf_exported_auto_gatewayc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  chartInstance->c4_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_initc4_DemoWalk_K(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec4_DemoWalk_K(SimStruct *c4_S)
{
  const mxArray *c4_out = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_out = NULL;
  sf_mex_assign(&c4_out, sf_internal_get_sim_state_c4_DemoWalk_K(c4_S), false);
  return c4_out;
}

void sf_exported_auto_setSimstatec4_DemoWalk_K(SimStruct *c4_S, const mxArray
  *c4_in)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c4_DemoWalk_K(c4_S, sf_mex_dup(c4_in));
  sf_mex_destroy(&c4_in);
}

void sf_exported_auto_check_state_inconsistency_c4_DemoWalk_K(SimStruct *c4_S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DemoWalk_KMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_idlePoseBradTablec4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[27];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  boolean_T c4_aVarTruthTableCondition_5;
  boolean_T c4_aVarTruthTableCondition_6;
  boolean_T c4_aVarTruthTableCondition_7;
  boolean_T c4_aVarTruthTableCondition_8;
  boolean_T c4_aVarTruthTableCondition_9;
  boolean_T c4_aVarTruthTableCondition_10;
  boolean_T c4_aVarTruthTableCondition_11;
  boolean_T c4_aVarTruthTableCondition_12;
  boolean_T c4_aVarTruthTableCondition_13;
  boolean_T c4_aVarTruthTableCondition_14;
  boolean_T c4_aVarTruthTableCondition_15;
  boolean_T c4_aVarTruthTableCondition_16;
  boolean_T c4_aVarTruthTableCondition_17;
  boolean_T c4_aVarTruthTableCondition_18;
  boolean_T c4_aVarTruthTableCondition_19;
  boolean_T c4_aVarTruthTableCondition_20;
  boolean_T c4_aVarTruthTableCondition_21;
  boolean_T c4_aVarTruthTableCondition_22;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_dv34[256];
  int32_T c4_i243;
  int32_T c4_i244;
  int32_T c4_i245;
  int32_T c4_i246;
  int32_T c4_i247;
  int32_T c4_i248;
  int32_T c4_i249;
  int32_T c4_i250;
  int32_T c4_i251;
  int32_T c4_i252;
  int32_T c4_i253;
  int32_T c4_i254;
  int32_T c4_i255;
  int32_T c4_i256;
  int32_T c4_i257;
  int32_T c4_i258;
  int32_T c4_i259;
  int32_T c4_i260;
  int32_T c4_i261;
  int32_T c4_i262;
  int32_T c4_i263;
  int32_T c4_i264;
  int32_T c4_i265;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_5, 4U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_6, 5U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_7, 6U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_8, 7U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_9, 8U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_10, 9U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_11, 10U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_12, 11U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_13, 12U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_14, 13U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_15, 14U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_16, 15U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_17, 16U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_18, 17U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_19, 18U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_20, 19U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_21, 20U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_22, 21U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 22U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 23U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 24U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_pr, 25U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 26U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  c4_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_aVarTruthTableCondition_20 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_aVarTruthTableCondition_21 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  c4_aVarTruthTableCondition_22 = false;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 31);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 40);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 49);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 58);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 61);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 64);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 67);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 70);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 73);
  c4_aVarTruthTableCondition_16 = (c4_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 76);
  c4_aVarTruthTableCondition_17 = (c4_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 79);
  c4_aVarTruthTableCondition_18 = (c4_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 82);
  c4_aVarTruthTableCondition_19 = (c4_bmlID == 19.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 85);
  c4_aVarTruthTableCondition_20 = (c4_bmlID == 20.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 88);
  c4_aVarTruthTableCondition_21 = (c4_bmlID == 21.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 91);
  c4_aVarTruthTableCondition_22 = (c4_bmlID == 22.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 93);
  if (CV_EML_IF(0, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 94);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 145U);
    c4_encStr2Arr(chartInstance, c4_dv34);
    for (c4_i243 = 0; c4_i243 < 256; c4_i243++) {
      c4_poseBML[c4_i243] = c4_dv34[c4_i243];
    }

    c4_updateDataWrittenToVector(chartInstance, 5U);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 145U);
    *c4_pr = 3.0;
    c4_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -145);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 95);
    if (CV_EML_IF(0, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 96);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 151U);
      c4_b_encStr2Arr(chartInstance, c4_dv34);
      for (c4_i244 = 0; c4_i244 < 256; c4_i244++) {
        c4_poseBML[c4_i244] = c4_dv34[c4_i244];
      }

      c4_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 151U);
      *c4_pr = 3.0;
      c4_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -151);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 97);
      if (CV_EML_IF(0, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 98);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 157U);
        c4_c_encStr2Arr(chartInstance, c4_dv34);
        for (c4_i245 = 0; c4_i245 < 256; c4_i245++) {
          c4_poseBML[c4_i245] = c4_dv34[c4_i245];
        }

        c4_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 157U);
        *c4_pr = 3.0;
        c4_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -157);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 99);
        if (CV_EML_IF(0, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 100);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 163U);
          c4_d_encStr2Arr(chartInstance, c4_dv34);
          for (c4_i246 = 0; c4_i246 < 256; c4_i246++) {
            c4_poseBML[c4_i246] = c4_dv34[c4_i246];
          }

          c4_updateDataWrittenToVector(chartInstance, 5U);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 163U);
          *c4_pr = 3.0;
          c4_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -163);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 101);
          if (CV_EML_IF(0, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 102);
            CV_EML_FCN(0, 4);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 163U);
            c4_d_encStr2Arr(chartInstance, c4_dv34);
            for (c4_i247 = 0; c4_i247 < 256; c4_i247++) {
              c4_poseBML[c4_i247] = c4_dv34[c4_i247];
            }

            c4_updateDataWrittenToVector(chartInstance, 5U);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 163U);
            *c4_pr = 3.0;
            c4_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -163);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 103);
            if (CV_EML_IF(0, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 104);
              CV_EML_FCN(0, 5);
              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 169U);
              c4_e_encStr2Arr(chartInstance, c4_dv34);
              for (c4_i248 = 0; c4_i248 < 256; c4_i248++) {
                c4_poseBML[c4_i248] = c4_dv34[c4_i248];
              }

              c4_updateDataWrittenToVector(chartInstance, 5U);
              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 169U);
              *c4_pr = 3.0;
              c4_updateDataWrittenToVector(chartInstance, 4U);
              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -169);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 105);
              if (CV_EML_IF(0, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 106);
                CV_EML_FCN(0, 6);
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 175U);
                c4_f_encStr2Arr(chartInstance, c4_dv34);
                for (c4_i249 = 0; c4_i249 < 256; c4_i249++) {
                  c4_poseBML[c4_i249] = c4_dv34[c4_i249];
                }

                c4_updateDataWrittenToVector(chartInstance, 5U);
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 175U);
                *c4_pr = 3.0;
                c4_updateDataWrittenToVector(chartInstance, 4U);
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -175);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 107);
                if (CV_EML_IF(0, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 108);
                  CV_EML_FCN(0, 7);
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 181U);
                  c4_g_encStr2Arr(chartInstance, c4_dv34);
                  for (c4_i250 = 0; c4_i250 < 256; c4_i250++) {
                    c4_poseBML[c4_i250] = c4_dv34[c4_i250];
                  }

                  c4_updateDataWrittenToVector(chartInstance, 5U);
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 181U);
                  *c4_pr = 3.0;
                  c4_updateDataWrittenToVector(chartInstance, 4U);
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -181);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 109);
                  if (CV_EML_IF(0, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 110);
                    CV_EML_FCN(0, 3);
                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 157U);
                    c4_c_encStr2Arr(chartInstance, c4_dv34);
                    for (c4_i251 = 0; c4_i251 < 256; c4_i251++) {
                      c4_poseBML[c4_i251] = c4_dv34[c4_i251];
                    }

                    c4_updateDataWrittenToVector(chartInstance, 5U);
                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 157U);
                    *c4_pr = 3.0;
                    c4_updateDataWrittenToVector(chartInstance, 4U);
                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -157);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 111);
                    if (CV_EML_IF(0, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 112);
                      CV_EML_FCN(0, 8);
                      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 187U);
                      c4_h_encStr2Arr(chartInstance, c4_dv34);
                      for (c4_i252 = 0; c4_i252 < 256; c4_i252++) {
                        c4_poseBML[c4_i252] = c4_dv34[c4_i252];
                      }

                      c4_updateDataWrittenToVector(chartInstance, 5U);
                      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 187U);
                      *c4_pr = 3.0;
                      c4_updateDataWrittenToVector(chartInstance, 4U);
                      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -187);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 113);
                      if (CV_EML_IF(0, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 114);
                        CV_EML_FCN(0, 9);
                        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 193U);
                        c4_i_encStr2Arr(chartInstance, c4_dv34);
                        for (c4_i253 = 0; c4_i253 < 256; c4_i253++) {
                          c4_poseBML[c4_i253] = c4_dv34[c4_i253];
                        }

                        c4_updateDataWrittenToVector(chartInstance, 5U);
                        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 193U);
                        *c4_pr = 3.0;
                        c4_updateDataWrittenToVector(chartInstance, 4U);
                        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -193);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 115);
                        if (CV_EML_IF(0, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 116);
                          CV_EML_FCN(0, 10);
                          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 199U);
                          c4_j_encStr2Arr(chartInstance, c4_dv34);
                          for (c4_i254 = 0; c4_i254 < 256; c4_i254++) {
                            c4_poseBML[c4_i254] = c4_dv34[c4_i254];
                          }

                          c4_updateDataWrittenToVector(chartInstance, 5U);
                          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 199U);
                          *c4_pr = 3.0;
                          c4_updateDataWrittenToVector(chartInstance, 4U);
                          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -199);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 117);
                          if (CV_EML_IF(0, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 118);
                            CV_EML_FCN(0, 11);
                            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 205U);
                            c4_k_encStr2Arr(chartInstance, c4_dv34);
                            for (c4_i255 = 0; c4_i255 < 256; c4_i255++) {
                              c4_poseBML[c4_i255] = c4_dv34[c4_i255];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 5U);
                            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 205U);
                            *c4_pr = 3.0;
                            c4_updateDataWrittenToVector(chartInstance, 4U);
                            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -205);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 119);
                            if (CV_EML_IF(0, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 120);
                              CV_EML_FCN(0, 12);
                              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 211U);
                              c4_l_encStr2Arr(chartInstance, c4_dv34);
                              for (c4_i256 = 0; c4_i256 < 256; c4_i256++) {
                                c4_poseBML[c4_i256] = c4_dv34[c4_i256];
                              }

                              c4_updateDataWrittenToVector(chartInstance, 5U);
                              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 211U);
                              *c4_pr = 3.0;
                              c4_updateDataWrittenToVector(chartInstance, 4U);
                              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -211);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 121);
                              if (CV_EML_IF(0, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 122);
                                CV_EML_FCN(0, 13);
                                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                              217U);
                                c4_m_encStr2Arr(chartInstance, c4_dv34);
                                for (c4_i257 = 0; c4_i257 < 256; c4_i257++) {
                                  c4_poseBML[c4_i257] = c4_dv34[c4_i257];
                                }

                                c4_updateDataWrittenToVector(chartInstance, 5U);
                                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                              217U);
                                *c4_pr = 3.0;
                                c4_updateDataWrittenToVector(chartInstance, 4U);
                                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                              -217);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 123);
                                if (CV_EML_IF(0, 1, 15,
                                              c4_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                124);
                                  CV_EML_FCN(0, 13);
                                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                217U);
                                  c4_m_encStr2Arr(chartInstance, c4_dv34);
                                  for (c4_i258 = 0; c4_i258 < 256; c4_i258++) {
                                    c4_poseBML[c4_i258] = c4_dv34[c4_i258];
                                  }

                                  c4_updateDataWrittenToVector(chartInstance, 5U);
                                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                217U);
                                  *c4_pr = 3.0;
                                  c4_updateDataWrittenToVector(chartInstance, 4U);
                                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                -217);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                125);
                                  if (CV_EML_IF(0, 1, 16,
                                                c4_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                  126);
                                    CV_EML_FCN(0, 14);
                                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                  223U);
                                    c4_n_encStr2Arr(chartInstance, c4_dv34);
                                    for (c4_i259 = 0; c4_i259 < 256; c4_i259++)
                                    {
                                      c4_poseBML[c4_i259] = c4_dv34[c4_i259];
                                    }

                                    c4_updateDataWrittenToVector(chartInstance,
                                      5U);
                                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                  223U);
                                    *c4_pr = 3.0;
                                    c4_updateDataWrittenToVector(chartInstance,
                                      4U);
                                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                  -223);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent,
                                                  MAX_int8_T);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c4_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c4_sfEvent,
                                                    128U);
                                      CV_EML_FCN(0, 15);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c4_sfEvent,
                                                    229U);
                                      c4_o_encStr2Arr(chartInstance, c4_dv34);
                                      for (c4_i260 = 0; c4_i260 < 256; c4_i260++)
                                      {
                                        c4_poseBML[c4_i260] = c4_dv34[c4_i260];
                                      }

                                      c4_updateDataWrittenToVector(chartInstance,
                                        5U);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c4_sfEvent,
                                                    229U);
                                      *c4_pr = 3.0;
                                      c4_updateDataWrittenToVector(chartInstance,
                                        4U);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c4_sfEvent,
                                                    -229);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c4_sfEvent,
                                                    129U);
                                      if (CV_EML_IF(0, 1, 18,
                                                    c4_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(0U,
                                                      chartInstance->c4_sfEvent,
                                                      130U);
                                        CV_EML_FCN(0, 16);
                                        _SFD_EML_CALL(0U,
                                                      chartInstance->c4_sfEvent,
                                                      235U);
                                        c4_p_encStr2Arr(chartInstance, c4_dv34);
                                        for (c4_i261 = 0; c4_i261 < 256; c4_i261
                                             ++) {
                                          c4_poseBML[c4_i261] = c4_dv34[c4_i261];
                                        }

                                        c4_updateDataWrittenToVector
                                          (chartInstance, 5U);
                                        _SFD_EML_CALL(0U,
                                                      chartInstance->c4_sfEvent,
                                                      235U);
                                        *c4_pr = 3.0;
                                        c4_updateDataWrittenToVector
                                          (chartInstance, 4U);
                                        _SFD_EML_CALL(0U,
                                                      chartInstance->c4_sfEvent,
                                                      -235);
                                      } else {
                                        _SFD_EML_CALL(0U,
                                                      chartInstance->c4_sfEvent,
                                                      131U);
                                        if (CV_EML_IF(0, 1, 19,
                                                      c4_aVarTruthTableCondition_20))
                                        {
                                          _SFD_EML_CALL(0U,
                                                        chartInstance->c4_sfEvent,
                                                        132U);
                                          CV_EML_FCN(0, 2);
                                          _SFD_EML_CALL(0U,
                                                        chartInstance->c4_sfEvent,
                                                        151U);
                                          c4_b_encStr2Arr(chartInstance, c4_dv34);
                                          for (c4_i262 = 0; c4_i262 < 256;
                                               c4_i262++) {
                                            c4_poseBML[c4_i262] =
                                              c4_dv34[c4_i262];
                                          }

                                          c4_updateDataWrittenToVector
                                            (chartInstance, 5U);
                                          _SFD_EML_CALL(0U,
                                                        chartInstance->c4_sfEvent,
                                                        151U);
                                          *c4_pr = 3.0;
                                          c4_updateDataWrittenToVector
                                            (chartInstance, 4U);
                                          _SFD_EML_CALL(0U,
                                                        chartInstance->c4_sfEvent,
                                                        -151);
                                        } else {
                                          _SFD_EML_CALL(0U,
                                                        chartInstance->c4_sfEvent,
                                                        133U);
                                          if (CV_EML_IF(0, 1, 20,
                                                        c4_aVarTruthTableCondition_21))
                                          {
                                            _SFD_EML_CALL(0U,
                                                          chartInstance->c4_sfEvent,
                                                          134U);
                                            CV_EML_FCN(0, 17);
                                            _SFD_EML_CALL(0U,
                                                          chartInstance->c4_sfEvent,
                                                          241U);
                                            c4_q_encStr2Arr(chartInstance,
                                                            c4_dv34);
                                            for (c4_i263 = 0; c4_i263 < 256;
                                                 c4_i263++) {
                                              c4_poseBML[c4_i263] =
                                                c4_dv34[c4_i263];
                                            }

                                            c4_updateDataWrittenToVector
                                              (chartInstance, 5U);
                                            _SFD_EML_CALL(0U,
                                                          chartInstance->c4_sfEvent,
                                                          241U);
                                            *c4_pr = 3.0;
                                            c4_updateDataWrittenToVector
                                              (chartInstance, 4U);
                                            _SFD_EML_CALL(0U,
                                                          chartInstance->c4_sfEvent,
                                                          -241);
                                          } else {
                                            _SFD_EML_CALL(0U,
                                                          chartInstance->c4_sfEvent,
                                                          135U);
                                            if (CV_EML_IF(0, 1, 21,
                                                          c4_aVarTruthTableCondition_22))
                                            {
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            136U);
                                              CV_EML_FCN(0, 18);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            247U);
                                              c4_r_encStr2Arr(chartInstance,
                                                c4_dv34);
                                              for (c4_i264 = 0; c4_i264 < 256;
                                                   c4_i264++) {
                                                c4_poseBML[c4_i264] =
                                                  c4_dv34[c4_i264];
                                              }

                                              c4_updateDataWrittenToVector
                                                (chartInstance, 5U);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            247U);
                                              *c4_pr = 3.0;
                                              c4_updateDataWrittenToVector
                                                (chartInstance, 4U);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            -247);
                                            } else {
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            138U);
                                              CV_EML_FCN(0, 9);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            193U);
                                              c4_i_encStr2Arr(chartInstance,
                                                c4_dv34);
                                              for (c4_i265 = 0; c4_i265 < 256;
                                                   c4_i265++) {
                                                c4_poseBML[c4_i265] =
                                                  c4_dv34[c4_i265];
                                              }

                                              c4_updateDataWrittenToVector
                                                (chartInstance, 5U);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            193U);
                                              *c4_pr = 3.0;
                                              c4_updateDataWrittenToVector
                                                (chartInstance, 4U);
                                              _SFD_EML_CALL(0U,
                                                            chartInstance->c4_sfEvent,
                                                            -193);
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
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -138);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_walkInvadingTablec4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmlID, creal_T *c4_p, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[9];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_dv35[256];
  int32_T c4_i266;
  static creal_T c4_dc1 = { 1.0, 0.0 };

  int32_T c4_i267;
  int32_T c4_i268;
  real_T c4_maxarrsize;
  real_T c4_arr[115];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[115];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i269;
  static char_T c4_cv23[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i270;
  static real_T c4_dv36[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c4_i271;
  int32_T c4_i272;
  int32_T c4_i273;
  int32_T c4_i274;
  int32_T c4_i275;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_t_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_p, 7U, c4_y_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 23);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 25);
  if (CV_EML_IF(7, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 26);
    CV_EML_FCN(7, 1);
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 41);
    c4_s_encStr2Arr(chartInstance, c4_dv35);
    for (c4_i266 = 0; c4_i266 < 256; c4_i266++) {
      c4_poseBML[c4_i266] = c4_dv35[c4_i266];
    }

    c4_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 41);
    *c4_p = c4_dc1;
    c4_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -41);
  } else {
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 27);
    if (CV_EML_IF(7, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 28);
      CV_EML_FCN(7, 2);
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 47);
      c4_t_encStr2Arr(chartInstance, c4_dv35);
      for (c4_i267 = 0; c4_i267 < 256; c4_i267++) {
        c4_poseBML[c4_i267] = c4_dv35[c4_i267];
      }

      c4_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 47);
      *c4_p = c4_dc1;
      c4_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -47);
    } else {
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 29);
      if (CV_EML_IF(7, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 30);
        CV_EML_FCN(7, 3);
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 53);
        c4_u_encStr2Arr(chartInstance, c4_dv35);
        for (c4_i268 = 0; c4_i268 < 256; c4_i268++) {
          c4_poseBML[c4_i268] = c4_dv35[c4_i268];
        }

        c4_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 53);
        *c4_p = c4_dc1;
        c4_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -53);
      } else {
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 31);
        if (CV_EML_IF(7, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 32);
          CV_EML_FCN(7, 4);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_x_debug_family_names,
            c4_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_hb_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
            c4_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_gb_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U,
            c4_d_sf_marshallOut, c4_d_sf_marshallIn);
          for (c4_i269 = 0; c4_i269 < 115; c4_i269++) {
            c4_mystr[c4_i269] = c4_cv23[c4_i269];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
          c4_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
          for (c4_i270 = 0; c4_i270 < 115; c4_i270++) {
            c4_arr[c4_i270] = c4_dv36[c4_i270];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
          c4_ss = 115.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
          c4_padsize = 141.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
          for (c4_i271 = 0; c4_i271 < 256; c4_i271++) {
            c4_tt[c4_i271] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
          for (c4_i272 = 0; c4_i272 < 115; c4_i272++) {
            c4_tt[c4_i272] = c4_arr[c4_i272];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
          for (c4_i273 = 0; c4_i273 < 256; c4_i273++) {
            c4_myarr256[c4_i273] = c4_tt[c4_i273];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c4_i274 = 0; c4_i274 < 256; c4_i274++) {
            c4_poseBML[c4_i274] = c4_myarr256[c4_i274];
          }

          c4_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 59);
          *c4_p = c4_dc1;
          c4_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -59);
        } else {
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 34);
          CV_EML_FCN(7, 1);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 41);
          c4_s_encStr2Arr(chartInstance, c4_dv35);
          for (c4_i275 = 0; c4_i275 < 256; c4_i275++) {
            c4_poseBML[c4_i275] = c4_dv35[c4_i275];
          }

          c4_updateDataWrittenToVector(chartInstance, 7U);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 41);
          *c4_p = c4_dc1;
          c4_updateDataWrittenToVector(chartInstance, 6U);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_insertQueueLowc4_DemoWalk_K(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, real_T c4_bmls[1280], real_T c4_myBML[256], real_T c4_newBmls
  [1280])
{
  uint32_T c4_debug_family_var_map[8];
  real_T c4_full;
  real_T c4_t[256];
  real_T c4_i;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i276;
  static real_T c4_varargin_2[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c4_i277;
  int32_T c4_i278;
  int32_T c4_i279;
  int32_T c4_i280;
  int32_T c4_i281;
  int32_T c4_b_i;
  int32_T c4_c_i;
  int32_T c4_i282;
  real_T c4_varargin_1[256];
  boolean_T c4_p;
  boolean_T c4_b_p;
  int32_T c4_k;
  real_T c4_b_k;
  real_T c4_x1;
  real_T c4_x2;
  boolean_T c4_c_p;
  int32_T c4_d_i;
  int32_T c4_i283;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  int32_T c4_i284;
  real_T c4_b_myBML[256];
  int32_T c4_tmp_sizes[2];
  char_T c4_tmp_data[256];
  int32_T c4_u_sizes[2];
  int32_T c4_b_u;
  int32_T c4_c_u;
  int32_T c4_loop_ub;
  int32_T c4_i285;
  char_T c4_u_data[256];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i286;
  static char_T c4_cv24[20] = { 'b', 'e', 'f', 'o', 'r', 'e', ' ', 'a', 'd', 'd',
    ' ', 'w', 'h', 'e', 'n', ' ', 'f', 'u', 'l', 'l' };

  char_T c4_d_u[20];
  const mxArray *c4_c_y = NULL;
  int32_T c4_i287;
  real_T c4_c_myBML[256];
  int32_T c4_b_tmp_sizes[2];
  char_T c4_b_tmp_data[256];
  int32_T c4_b_u_sizes[2];
  int32_T c4_e_u;
  int32_T c4_f_u;
  int32_T c4_b_loop_ub;
  int32_T c4_i288;
  char_T c4_b_u_data[256];
  const mxArray *c4_d_y = NULL;
  int32_T c4_i289;
  real_T c4_b_bmls[256];
  int32_T c4_i290;
  int32_T c4_i291;
  real_T c4_c_bmls[256];
  int32_T c4_i292;
  int32_T c4_i293;
  real_T c4_d_bmls[256];
  int32_T c4_i294;
  int32_T c4_i295;
  int32_T c4_i296;
  int32_T exitg1;
  boolean_T exitg2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_y_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_full, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_t, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_bmls, 5U, c4_ib_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_newBmls, 7U, c4_ib_sf_marshallOut,
    c4_f_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 2);
  c4_full = 1.0;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 3);
  for (c4_i276 = 0; c4_i276 < 256; c4_i276++) {
    c4_t[c4_i276] = c4_varargin_2[c4_i276];
  }

  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 4);
  for (c4_i277 = 0; c4_i277 < 256; c4_i277++) {
    c4_newBmls[c4_i277] = c4_t[c4_i277];
  }

  for (c4_i278 = 0; c4_i278 < 256; c4_i278++) {
    c4_newBmls[c4_i278 + 256] = c4_t[c4_i278];
  }

  for (c4_i279 = 0; c4_i279 < 256; c4_i279++) {
    c4_newBmls[c4_i279 + 512] = c4_t[c4_i279];
  }

  for (c4_i280 = 0; c4_i280 < 256; c4_i280++) {
    c4_newBmls[c4_i280 + 768] = c4_t[c4_i280];
  }

  for (c4_i281 = 0; c4_i281 < 256; c4_i281++) {
    c4_newBmls[c4_i281 + 1024] = c4_t[c4_i281];
  }

  c4_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 5);
  c4_i = 1.0;
  c4_b_i = 0;
  do {
    exitg1 = 0;
    if (c4_b_i < 5) {
      c4_i = 1.0 + (real_T)c4_b_i;
      CV_EML_FOR(1, 1, 0, 1);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 6);
      c4_c_i = (int32_T)c4_i - 1;
      for (c4_i282 = 0; c4_i282 < 256; c4_i282++) {
        c4_varargin_1[c4_i282] = c4_bmls[c4_i282 + (c4_c_i << 8)];
      }

      c4_p = false;
      c4_b_p = true;
      c4_k = 0;
      exitg2 = false;
      while ((exitg2 == false) && (c4_k < 256)) {
        c4_b_k = 1.0 + (real_T)c4_k;
        c4_x1 = c4_varargin_1[(int32_T)c4_b_k - 1];
        c4_x2 = c4_varargin_2[(int32_T)c4_b_k - 1];
        c4_c_p = (c4_x1 == c4_x2);
        if (!c4_c_p) {
          c4_b_p = false;
          exitg2 = true;
        } else {
          c4_k++;
        }
      }

      if (!c4_b_p) {
      } else {
        c4_p = true;
      }

      if (CV_EML_IF(1, 1, 0, c4_p)) {
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 8);
        c4_d_i = (int32_T)c4_i - 1;
        for (c4_i283 = 0; c4_i283 < 256; c4_i283++) {
          c4_bmls[c4_i283 + (c4_d_i << 8)] = c4_myBML[c4_i283];
        }

        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 9);
        c4_full = 0.0;
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 10);
        c4_u = c4_i;
        c4_y = NULL;
        sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 10);
        for (c4_i284 = 0; c4_i284 < 256; c4_i284++) {
          c4_b_myBML[c4_i284] = c4_myBML[c4_i284];
        }

        c4_decArr2Str(chartInstance, c4_b_myBML, c4_tmp_data, c4_tmp_sizes);
        c4_u_sizes[0] = 1;
        c4_u_sizes[1] = c4_tmp_sizes[1];
        c4_b_u = c4_u_sizes[0];
        c4_c_u = c4_u_sizes[1];
        c4_loop_ub = c4_tmp_sizes[0] * c4_tmp_sizes[1] - 1;
        for (c4_i285 = 0; c4_i285 <= c4_loop_ub; c4_i285++) {
          c4_u_data[c4_i285] = c4_tmp_data[c4_i285];
        }

        c4_b_y = NULL;
        sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u_data, 10, 0U, 1U, 0U, 2,
          c4_u_sizes[0], c4_u_sizes[1]), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_b_y);
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 11);
        exitg1 = 1;
      } else {
        c4_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(1, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 14);
  if (CV_EML_IF(1, 1, 1, c4_full != 0.0)) {
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 16);
    for (c4_i286 = 0; c4_i286 < 20; c4_i286++) {
      c4_d_u[c4_i286] = c4_cv24[c4_i286];
    }

    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_d_u, 10, 0U, 1U, 0U, 2, 1, 20),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_c_y);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 16);
    for (c4_i287 = 0; c4_i287 < 256; c4_i287++) {
      c4_c_myBML[c4_i287] = c4_myBML[c4_i287];
    }

    c4_decArr2Str(chartInstance, c4_c_myBML, c4_b_tmp_data, c4_b_tmp_sizes);
    c4_b_u_sizes[0] = 1;
    c4_b_u_sizes[1] = c4_b_tmp_sizes[1];
    c4_e_u = c4_b_u_sizes[0];
    c4_f_u = c4_b_u_sizes[1];
    c4_b_loop_ub = c4_b_tmp_sizes[0] * c4_b_tmp_sizes[1] - 1;
    for (c4_i288 = 0; c4_i288 <= c4_b_loop_ub; c4_i288++) {
      c4_b_u_data[c4_i288] = c4_b_tmp_data[c4_i288];
    }

    c4_d_y = NULL;
    sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_b_u_data, 10, 0U, 1U, 0U, 2,
      c4_b_u_sizes[0], c4_b_u_sizes[1]), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_d_y);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 17);
    for (c4_i289 = 0; c4_i289 < 256; c4_i289++) {
      c4_b_bmls[c4_i289] = c4_bmls[c4_i289 + 256];
    }

    for (c4_i290 = 0; c4_i290 < 256; c4_i290++) {
      c4_bmls[c4_i290] = c4_b_bmls[c4_i290];
    }

    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 18);
    for (c4_i291 = 0; c4_i291 < 256; c4_i291++) {
      c4_c_bmls[c4_i291] = c4_bmls[c4_i291 + 512];
    }

    for (c4_i292 = 0; c4_i292 < 256; c4_i292++) {
      c4_bmls[c4_i292 + 256] = c4_c_bmls[c4_i292];
    }

    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 19);
    for (c4_i293 = 0; c4_i293 < 256; c4_i293++) {
      c4_d_bmls[c4_i293] = c4_bmls[c4_i293 + 768];
    }

    for (c4_i294 = 0; c4_i294 < 256; c4_i294++) {
      c4_bmls[c4_i294 + 512] = c4_d_bmls[c4_i294];
    }

    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 20);
    for (c4_i295 = 0; c4_i295 < 256; c4_i295++) {
      c4_bmls[c4_i295 + 1024] = c4_myBML[c4_i295];
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 22);
  for (c4_i296 = 0; c4_i296 < 1280; c4_i296++) {
    c4_newBmls[c4_i296] = c4_bmls[c4_i296];
  }

  c4_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c4_DemoWalk_K_idlePoseBradTable(SimStruct *c4_S, real_T
  c4_bmlID, real_T *c4_pr, real_T c4_poseBML[256])
{
  real_T c4_b_pr;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_idlePoseBradTablec4_DemoWalk_K(chartInstance, c4_bmlID, &c4_b_pr,
    c4_poseBML);
  *c4_pr = c4_b_pr;
}

void sf_exported_user_c4_DemoWalk_K_insertQueueLow(SimStruct *c4_S, real_T
  c4_bmls[1280], real_T c4_myBML[256], real_T c4_newBmls[1280])
{
  int32_T c4_i297;
  real_T c4_b_bmls[1280];
  int32_T c4_i298;
  real_T c4_b_myBML[256];
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  for (c4_i297 = 0; c4_i297 < 1280; c4_i297++) {
    c4_b_bmls[c4_i297] = c4_bmls[c4_i297];
  }

  for (c4_i298 = 0; c4_i298 < 256; c4_i298++) {
    c4_b_myBML[c4_i298] = c4_myBML[c4_i298];
  }

  c4_insertQueueLowc4_DemoWalk_K(chartInstance, c4_b_bmls, c4_b_myBML,
    c4_newBmls);
}

void sf_exported_user_c4_DemoWalk_K_walkInvadingTable(SimStruct *c4_S, real_T
  c4_bmlID, creal_T *c4_p, real_T c4_poseBML[256])
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_walkInvadingTablec4_DemoWalk_K(chartInstance, c4_bmlID, c4_p, c4_poseBML);
}

static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int8_T c4_l_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int8_T c4_y;
  int8_T c4_i299;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i299, 1, 2, 0U, 0, 0U, 0);
  c4_y = c4_i299;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_secs;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int8_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_secs = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_secs), &c4_thisId);
  sf_mex_destroy(&c4_secs);
  *(int8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_m_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i300;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i300, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i300;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_n_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_stateInit, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateInit),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateInit);
  return c4_y;
}

static uint8_T c4_o_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_stateInit;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)chartInstanceVoid;
  c4_b_tp_stateInit = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateInit),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateInit);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint32_T c4_p_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_method),
    &c4_thisId);
  sf_mex_destroy(&c4_b_method);
  return c4_y;
}

static uint32_T c4_q_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_method_not_empty = false;
  } else {
    chartInstance->c4_method_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u1, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_u1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint32_T c4_r_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId);
  sf_mex_destroy(&c4_d_state);
  return c4_y;
}

static uint32_T c4_s_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u2;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_state_not_empty = false;
  } else {
    chartInstance->c4_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u2, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_u2;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_t_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_u_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint32_T c4_y[625])
{
  uint32_T c4_uv4[625];
  int32_T c4_i301;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_c_state_not_empty = false;
  } else {
    chartInstance->c4_c_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 7, 0U, 1, 0U, 1, 625);
    for (c4_i301 = 0; c4_i301 < 625; c4_i301++) {
      c4_y[c4_i301] = c4_uv4[c4_i301];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_v_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_d_state, const char_T *c4_identifier, uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_w_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint32_T c4_y[2])
{
  uint32_T c4_uv5[2];
  int32_T c4_i302;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_b_state_not_empty = false;
  } else {
    chartInstance->c4_b_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv5, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i302 = 0; c4_i302 < 2; c4_i302++) {
      c4_y[c4_i302] = c4_uv5[c4_i302];
    }
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_x_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  sf_mex_assign(&c4_y, c4_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_y_emlrt_marshallIn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_updateDataWrittenToVector(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex)
{
  (void)chartInstance;
  c4_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c4_vectorIndex, 0, 8, 1, 0)] = true;
}

static void c4_errorIfDataNotWrittenToFcn(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c4_dataNumber, c4_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c4_vectorIndex, 0, 8, 1,
    0)]);
}

static void c4_b_twister_state_vector(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed)
{
  uint32_T c4_r;
  int32_T c4_mti;
  real_T c4_b_mti;
  real_T c4_d3;
  uint32_T c4_u3;
  (void)chartInstance;
  (void)c4_seed;
  c4_r = 5489U;
  c4_mt[0] = 5489U;
  for (c4_mti = 0; c4_mti < 623; c4_mti++) {
    c4_b_mti = 2.0 + (real_T)c4_mti;
    c4_d3 = muDoubleScalarRound(c4_b_mti - 1.0);
    if (c4_d3 < 4.294967296E+9) {
      if (c4_d3 >= 0.0) {
        c4_u3 = (uint32_T)c4_d3;
      } else {
        c4_u3 = 0U;
      }
    } else if (c4_d3 >= 4.294967296E+9) {
      c4_u3 = MAX_uint32_T;
    } else {
      c4_u3 = 0U;
    }

    c4_r = (c4_r ^ c4_r >> 30U) * 1812433253U + c4_u3;
    c4_mt[(int32_T)c4_b_mti - 1] = c4_r;
  }

  c4_mt[624] = 624U;
}

static real_T c4_c_eml_rand_mt19937ar(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_d_state[625])
{
  int32_T c4_i303;
  uint32_T c4_u[2];
  int32_T c4_j;
  real_T c4_b_j;
  uint32_T c4_mti;
  int32_T c4_kk;
  real_T c4_b_kk;
  uint32_T c4_y;
  uint32_T c4_b_y;
  uint32_T c4_c_y;
  int32_T c4_c_kk;
  uint32_T c4_d_y;
  uint32_T c4_e_y;
  uint32_T c4_f_y;
  uint32_T c4_g_y;
  real_T c4_b_r;
  boolean_T c4_b1;
  boolean_T c4_isvalid;
  int32_T c4_k;
  int32_T c4_a;
  int32_T c4_b_a;
  real_T c4_d4;
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
    for (c4_i303 = 0; c4_i303 < 2; c4_i303++) {
      c4_u[c4_i303] = 0U;
    }

    for (c4_j = 0; c4_j < 2; c4_j++) {
      c4_b_j = 1.0 + (real_T)c4_j;
      c4_mti = c4_d_state[624] + 1U;
      if ((real_T)c4_mti >= 625.0) {
        for (c4_kk = 0; c4_kk < 227; c4_kk++) {
          c4_b_kk = 1.0 + (real_T)c4_kk;
          c4_y = (c4_d_state[(int32_T)c4_b_kk - 1] & 2147483648U) | (c4_d_state
            [(int32_T)(c4_b_kk + 1.0) - 1] & 2147483647U);
          c4_b_y = c4_y;
          c4_c_y = c4_b_y;
          if ((real_T)(c4_c_y & 1U) == 0.0) {
            c4_c_y >>= 1U;
          } else {
            c4_c_y = c4_c_y >> 1U ^ 2567483615U;
          }

          c4_d_state[(int32_T)c4_b_kk - 1] = c4_d_state[(int32_T)(c4_b_kk +
            397.0) - 1] ^ c4_c_y;
        }

        for (c4_c_kk = 0; c4_c_kk < 396; c4_c_kk++) {
          c4_b_kk = 228.0 + (real_T)c4_c_kk;
          c4_y = (c4_d_state[(int32_T)c4_b_kk - 1] & 2147483648U) | (c4_d_state
            [(int32_T)(c4_b_kk + 1.0) - 1] & 2147483647U);
          c4_d_y = c4_y;
          c4_e_y = c4_d_y;
          if ((real_T)(c4_e_y & 1U) == 0.0) {
            c4_e_y >>= 1U;
          } else {
            c4_e_y = c4_e_y >> 1U ^ 2567483615U;
          }

          c4_d_state[(int32_T)c4_b_kk - 1] = c4_d_state[(int32_T)((c4_b_kk + 1.0)
            - 228.0) - 1] ^ c4_e_y;
        }

        c4_y = (c4_d_state[623] & 2147483648U) | (c4_d_state[0] & 2147483647U);
        c4_f_y = c4_y;
        c4_g_y = c4_f_y;
        if ((real_T)(c4_g_y & 1U) == 0.0) {
          c4_g_y >>= 1U;
        } else {
          c4_g_y = c4_g_y >> 1U ^ 2567483615U;
        }

        c4_d_state[623] = c4_d_state[396] ^ c4_g_y;
        c4_mti = 1U;
      }

      c4_y = c4_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c4_mti, 1, 625, 1, 0) - 1];
      c4_d_state[624] = c4_mti;
      c4_y ^= c4_y >> 11U;
      c4_y ^= c4_y << 7U & 2636928640U;
      c4_y ^= c4_y << 15U & 4022730752U;
      c4_y ^= c4_y >> 18U;
      c4_u[(int32_T)c4_b_j - 1] = c4_y;
    }

    c4_u[0] >>= 5U;
    c4_u[1] >>= 6U;
    c4_b_r = 1.1102230246251565E-16 * ((real_T)c4_u[0] * 6.7108864E+7 + (real_T)
      c4_u[1]);
    if (c4_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c4_d_state[624] >= 1.0) {
        if ((real_T)c4_d_state[624] < 625.0) {
          c4_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c4_b1 = false;
      }

      c4_isvalid = c4_b1;
      if (c4_isvalid) {
        c4_isvalid = false;
        c4_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c4_k + 1 < 625)) {
          if ((real_T)c4_d_state[c4_k] == 0.0) {
            c4_a = c4_k + 1;
            c4_b_a = c4_a;
            c4_k = c4_b_a;
          } else {
            c4_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c4_isvalid) {
        c4_eml_error(chartInstance);
        c4_d4 = 5489.0;
        c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d4);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c4_b_r;
}

static real_T c4_get_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1022) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_BML_address)[c4_b];
}

static void c4_set_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1022) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_BML_address)[c4_b] = c4_c;
}

static real_T *c4_access_BML(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1022) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_BML_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c4_c;
}

static real_T c4_get_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#1017) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_BORED_address;
}

static void c4_set_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#1017) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_BORED_address = c4_c;
}

static real_T *c4_access_BORED(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#1017) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_BORED_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c4_c;
}

static real_T c4_get_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1004) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_BOREDOM_THRESHOLD_address;
}

static void c4_set_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1004) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_BOREDOM_THRESHOLD_address = c4_c;
}

static real_T *c4_access_BOREDOM_THRESHOLD(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1004) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_BOREDOM_THRESHOLD_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c4_c;
}

static real_T c4_get_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#1016) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_CONTEMPT_address;
}

static void c4_set_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#1016) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_CONTEMPT_address = c4_c;
}

static real_T *c4_access_CONTEMPT(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#1016) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_CONTEMPT_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c4_c;
}

static real_T c4_get_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#1021) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_EXCITE_address;
}

static void c4_set_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#1021) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_EXCITE_address = c4_c;
}

static real_T *c4_access_EXCITE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#1021) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_EXCITE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c4_c;
}

static real_T c4_get_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#1019) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_FEAR_address;
}

static void c4_set_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#1019) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_FEAR_address = c4_c;
}

static real_T *c4_access_FEAR(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#1019) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_FEAR_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c4_c;
}

static real_T c4_get_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#1018) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_FRUST_address;
}

static void c4_set_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#1018) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_FRUST_address = c4_c;
}

static real_T *c4_access_FRUST(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#1018) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_FRUST_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c4_c;
}

static real_T c4_get_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#1014) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_HAPPY_address;
}

static void c4_set_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#1014) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_HAPPY_address = c4_c;
}

static real_T *c4_access_HAPPY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#1014) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_HAPPY_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c4_c;
}

static real_T c4_get_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#1020) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_IDLE_address;
}

static void c4_set_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#1020) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_IDLE_address = c4_c;
}

static real_T *c4_access_IDLE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#1020) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_IDLE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c4_c;
}

static real_T c4_get_P(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1023) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_P_address;
}

static void c4_set_P(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T c4_b,
                     real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1023) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_P_address = c4_c;
}

static real_T *c4_access_P(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1023) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_P_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c4_c;
}

static real_T c4_get_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#1015) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_SAD_address;
}

static void c4_set_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#1015) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_SAD_address = c4_c;
}

static real_T *c4_access_SAD(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#1015) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_SAD_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1010) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_BEFORE_address;
}

static void c4_set_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1010) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_BEFORE_address = c4_c;
}

static real_T *c4_access_STATE_BEFORE(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1010) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_BEFORE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1025) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_GO_address;
}

static void c4_set_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1025) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_GO_address = c4_c;
}

static real_T *c4_access_STATE_GO(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1025) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_GO_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1009) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_OVER_address;
}

static void c4_set_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1009) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_OVER_address = c4_c;
}

static real_T *c4_access_STATE_OVER(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1009) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_OVER_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_READY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1011) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_READY_address;
}

static void c4_set_STATE_READY(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1011) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_READY_address = c4_c;
}

static real_T *c4_access_STATE_READY(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1011) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_READY_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c4_c;
}

static real_T c4_get_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1029) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_bmlsL_address)[c4_b];
}

static void c4_set_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1029) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_bmlsL_address)[c4_b] = c4_c;
}

static real_T *c4_access_bmlsL(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1029) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_bmlsL_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c4_c;
}

static real_T c4_get_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1003) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_boredom_address;
}

static void c4_set_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1003) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_boredom_address = c4_c;
}

static real_T *c4_access_boredom(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1003) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_boredom_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c4_c;
}

static real_T c4_get_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c4_b);
  if (chartInstance->c4_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1026) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_changeFlag_address;
}

static void c4_set_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c4_b);
  if (chartInstance->c4_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1026) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_changeFlag_address = c4_c;
}

static real_T *c4_access_changeFlag(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c4_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1026) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_changeFlag_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c4_c;
}

static real_T c4_get_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c4_b);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1024) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_fileID_address;
}

static void c4_set_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance, uint32_T
  c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c4_b);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1024) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_fileID_address = c4_c;
}

static real_T *c4_access_fileID(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1024) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_fileID_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c4_c;
}

static real_T c4_get_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c4_b);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1006) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_interest_address;
}

static void c4_set_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c4_b);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1006) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_interest_address = c4_c;
}

static real_T *c4_access_interest(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1006) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_interest_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c4_c;
}

static real_T c4_get_randPoseChance(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1008) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randPoseChance_address;
}

static void c4_set_randPoseChance(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1008) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randPoseChance_address = c4_c;
}

static real_T *c4_access_randPoseChance(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1008) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randPoseChance_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c4_c;
}

static real_T c4_get_randSlowPose(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c4_b);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#1005) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randSlowPose_address;
}

static void c4_set_randSlowPose(SFc4_DemoWalk_KInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c4_b);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#1005) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randSlowPose_address = c4_c;
}

static real_T *c4_access_randSlowPose(SFc4_DemoWalk_KInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#1005) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randSlowPose_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c4_c;
}

static void init_dsm_address_info(SFc4_DemoWalk_KInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c4_BML_address, &chartInstance->c4_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BORED", (void **)
    &chartInstance->c4_BORED_address, &chartInstance->c4_BORED_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c4_BOREDOM_THRESHOLD_address,
    &chartInstance->c4_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "CONTEMPT", (void **)
    &chartInstance->c4_CONTEMPT_address, &chartInstance->c4_CONTEMPT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "EXCITE", (void **)
    &chartInstance->c4_EXCITE_address, &chartInstance->c4_EXCITE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FEAR", (void **)
    &chartInstance->c4_FEAR_address, &chartInstance->c4_FEAR_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FRUST", (void **)
    &chartInstance->c4_FRUST_address, &chartInstance->c4_FRUST_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "HAPPY", (void **)
    &chartInstance->c4_HAPPY_address, &chartInstance->c4_HAPPY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "IDLE", (void **)
    &chartInstance->c4_IDLE_address, &chartInstance->c4_IDLE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c4_P_address, &chartInstance->c4_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "SAD", (void **)
    &chartInstance->c4_SAD_address, &chartInstance->c4_SAD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c4_STATE_BEFORE_address,
    &chartInstance->c4_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c4_STATE_GO_address, &chartInstance->c4_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c4_STATE_OVER_address, &chartInstance->c4_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c4_STATE_READY_address, &chartInstance->c4_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c4_bmlsL_address, &chartInstance->c4_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c4_boredom_address, &chartInstance->c4_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c4_changeFlag_address, &chartInstance->c4_changeFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c4_fileID_address, &chartInstance->c4_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c4_interest_address, &chartInstance->c4_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c4_randPoseChance_address,
    &chartInstance->c4_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSlowPose", (void **)
    &chartInstance->c4_randSlowPose_address,
    &chartInstance->c4_randSlowPose_index);
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

void sf_c4_DemoWalk_K_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1323728010U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1450415497U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(607630159U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1649663568U);
}

mxArray *sf_c4_DemoWalk_K_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EYo1EbEtZL71VzfzKlphIH");
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_DemoWalk_K_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_DemoWalk_K_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_DemoWalk_K(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[40],T\"gameState\",},{M[3],M[141],T\"BMLl\",},{M[3],M[144],T\"n\",},{M[3],M[142],T\"newBmlsL\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c4_DemoWalk_K\",},{M[9],M[0],T\"is_c4_DemoWalk_K\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[37 10],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_DemoWalk_K_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_DemoWalk_KInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_DemoWalk_KInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DemoWalk_KMachineNumber_,
           4,
           8,
           14,
           0,
           37,
           1,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_DemoWalk_KMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DemoWalk_KMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DemoWalk_KMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randSlowPose");
          _SFD_SET_DATA_PROPS(3,11,0,0,"interest");
          _SFD_SET_DATA_PROPS(4,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(5,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(6,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(7,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(8,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(9,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(10,1,1,0,"inE");
          _SFD_SET_DATA_PROPS(11,11,0,0,"HAPPY");
          _SFD_SET_DATA_PROPS(12,11,0,0,"SAD");
          _SFD_SET_DATA_PROPS(13,11,0,0,"CONTEMPT");
          _SFD_SET_DATA_PROPS(14,11,0,0,"BORED");
          _SFD_SET_DATA_PROPS(15,11,0,0,"FRUST");
          _SFD_SET_DATA_PROPS(16,11,0,0,"FEAR");
          _SFD_SET_DATA_PROPS(17,11,0,0,"IDLE");
          _SFD_SET_DATA_PROPS(18,11,0,0,"EXCITE");
          _SFD_SET_DATA_PROPS(19,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(20,11,0,0,"P");
          _SFD_SET_DATA_PROPS(21,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(22,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(23,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(24,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(25,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(26,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(27,0,0,0,"n");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,9,0,0,"");
          _SFD_SET_DATA_PROPS(31,9,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,9,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
          _SFD_SET_DATA_PROPS(36,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,5);
          _SFD_CH_SUBSTATE_INDEX(4,6);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

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
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,19,22,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"idlePoseBradTablec4_DemoWalk_K",0,-1,3436);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",3436,-1,3634);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",3634,-1,3831);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3831,-1,4017);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",4017,-1,4204);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",4204,-1,4437);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",4437,-1,4614);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",4614,-1,4800);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4800,-1,5030);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",5030,-1,5205);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",5205,-1,5379);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",5379,-1,5554);
        _SFD_CV_INIT_EML_FCN(0,12,"aFcnTruthTableAction_12",5554,-1,5745);
        _SFD_CV_INIT_EML_FCN(0,13,"aFcnTruthTableAction_13",5745,-1,5935);
        _SFD_CV_INIT_EML_FCN(0,14,"aFcnTruthTableAction_14",5935,-1,6131);
        _SFD_CV_INIT_EML_FCN(0,15,"aFcnTruthTableAction_15",6131,-1,6321);
        _SFD_CV_INIT_EML_FCN(0,16,"aFcnTruthTableAction_16",6321,-1,6514);
        _SFD_CV_INIT_EML_FCN(0,17,"aFcnTruthTableAction_17",6514,-1,6717);
        _SFD_CV_INIT_EML_FCN(0,18,"aFcnTruthTableAction_18",6717,-1,6908);
        _SFD_CV_INIT_EML_IF(0,1,0,1937,1967,1998,3434);
        _SFD_CV_INIT_EML_IF(0,1,1,1998,2032,2063,3434);
        _SFD_CV_INIT_EML_IF(0,1,2,2063,2097,2128,3434);
        _SFD_CV_INIT_EML_IF(0,1,3,2128,2162,2193,3434);
        _SFD_CV_INIT_EML_IF(0,1,4,2193,2227,2258,3434);
        _SFD_CV_INIT_EML_IF(0,1,5,2258,2292,2323,3434);
        _SFD_CV_INIT_EML_IF(0,1,6,2323,2357,2388,3434);
        _SFD_CV_INIT_EML_IF(0,1,7,2388,2422,2453,3434);
        _SFD_CV_INIT_EML_IF(0,1,8,2453,2487,2518,3434);
        _SFD_CV_INIT_EML_IF(0,1,9,2518,2553,2584,3434);
        _SFD_CV_INIT_EML_IF(0,1,10,2584,2619,2650,3434);
        _SFD_CV_INIT_EML_IF(0,1,11,2650,2685,2717,3434);
        _SFD_CV_INIT_EML_IF(0,1,12,2717,2752,2784,3434);
        _SFD_CV_INIT_EML_IF(0,1,13,2784,2819,2851,3434);
        _SFD_CV_INIT_EML_IF(0,1,14,2851,2886,2918,3434);
        _SFD_CV_INIT_EML_IF(0,1,15,2918,2953,2985,3434);
        _SFD_CV_INIT_EML_IF(0,1,16,2985,3020,3052,3434);
        _SFD_CV_INIT_EML_IF(0,1,17,3052,3087,3119,3434);
        _SFD_CV_INIT_EML_IF(0,1,18,3119,3154,3186,3434);
        _SFD_CV_INIT_EML_IF(0,1,19,3186,3221,3252,3434);
        _SFD_CV_INIT_EML_IF(0,1,20,3252,3287,3319,3434);
        _SFD_CV_INIT_EML_IF(0,1,21,3319,3354,3386,3434);
        _SFD_CV_INIT_EML(7,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"walkInvadingTablec4_DemoWalk_K",0,-1,708);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",708,-1,921);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",921,-1,1134);
        _SFD_CV_INIT_EML_FCN(7,3,"aFcnTruthTableAction_3",1134,-1,1349);
        _SFD_CV_INIT_EML_FCN(7,4,"aFcnTruthTableAction_4",1349,-1,1542);
        _SFD_CV_INIT_EML_IF(7,1,0,402,432,463,706);
        _SFD_CV_INIT_EML_IF(7,1,1,463,497,528,706);
        _SFD_CV_INIT_EML_IF(7,1,2,528,562,593,706);
        _SFD_CV_INIT_EML_IF(7,1,3,593,627,658,706);
        _SFD_CV_INIT_EML(1,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"insertQueueLowc4_DemoWalk_K",0,-1,691);
        _SFD_CV_INIT_EML_IF(1,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(1,1,1,344,355,-1,672);
        _SFD_CV_INIT_EML_FOR(1,1,0,109,121,339);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"decArr2Str",0,-1,97);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,38,1,38);

        {
          static int condStart[] = { 2, 15, 27 };

          static int condEnd[] = { 12, 24, 37 };

          static int pfixExpr[] = { 0, 1, 2, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,95,1,48);

        {
          static int condStart[] = { 1, 21, 45, 72 };

          static int condEnd[] = { 20, 44, 71, 95 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,95,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,60,1,48);

        {
          static int condStart[] = { 1, 21, 37 };

          static int condEnd[] = { 20, 36, 60 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,60,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,15,1,15);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_ib_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_ib_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c4_y_sf_marshallOut,(MexInFcnForType)c4_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_ib_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_ib_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(36,(void *)(NULL));

        {
          real_T *c4_gameState;
          real_T *c4_inA;
          real_T *c4_inE;
          c4_inE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(1U,
            chartInstance->c4_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_randSlowPose_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c4_interest_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_gameState);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c4_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_inA);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_inE);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c4_HAPPY_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c4_SAD_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c4_CONTEMPT_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c4_BORED_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c4_FRUST_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c4_FEAR_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c4_IDLE_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c4_EXCITE_address);
          _SFD_SET_DATA_VALUE_PTR(19U, *chartInstance->c4_BML_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c4_P_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c4_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c4_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c4_changeFlag_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c4_BMLl);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c4_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(26U, *chartInstance->c4_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c4_n);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DemoWalk_KMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "oOyoukectrX5uSO8XlLfVF";
}

static void sf_opaque_initialize_c4_DemoWalk_K(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*)
    chartInstanceVar);
  initialize_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_DemoWalk_K(void *chartInstanceVar)
{
  enable_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_DemoWalk_K(void *chartInstanceVar)
{
  disable_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_DemoWalk_K(void *chartInstanceVar)
{
  sf_gateway_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_DemoWalk_K(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_DemoWalk_K
    ((SFc4_DemoWalk_KInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_DemoWalk_K();/* state var info */
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

extern void sf_internal_set_sim_state_c4_DemoWalk_K(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_DemoWalk_K();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_DemoWalk_K(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c4_DemoWalk_K(SimStruct* S, const mxArray
  *st)
{
}

static void sf_opaque_terminate_c4_DemoWalk_K(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DemoWalk_K_optimization_info();
    }

    finalize_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_DemoWalk_K(SimStruct *S)
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
    initialize_params_c4_DemoWalk_K((SFc4_DemoWalk_KInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_DemoWalk_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DemoWalk_K_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4210001398U));
  ssSetChecksum1(S,(605932873U));
  ssSetChecksum2(S,(1635572921U));
  ssSetChecksum3(S,(3533978165U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_DemoWalk_K(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_DemoWalk_K(SimStruct *S)
{
  SFc4_DemoWalk_KInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_DemoWalk_KInstanceStruct *)utMalloc(sizeof
    (SFc4_DemoWalk_KInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_DemoWalk_KInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_DemoWalk_K;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_DemoWalk_K;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_DemoWalk_K;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_DemoWalk_K;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_DemoWalk_K;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_DemoWalk_K;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_DemoWalk_K;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_DemoWalk_K;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_DemoWalk_K;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_DemoWalk_K;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_DemoWalk_K;
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

void c4_DemoWalk_K_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_DemoWalk_K(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_DemoWalk_K(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_DemoWalk_K(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_DemoWalk_K_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
