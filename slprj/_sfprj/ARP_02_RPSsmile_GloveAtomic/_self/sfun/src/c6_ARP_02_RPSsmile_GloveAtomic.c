/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveAtomic_sfun.h"
#include "c6_ARP_02_RPSsmile_GloveAtomic.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveAtomic_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c6_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_stateAvertGaze           ((uint8_T)1U)
#define c6_IN_stateAvertHead           ((uint8_T)2U)
#define c6_IN_stateHeadNeutral         ((uint8_T)3U)
#define c6_IN_stateInitial             ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c6_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_j_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c6_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c6_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_qb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_sb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c6_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initialize_params_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void enable_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void disable_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_st);
static void c6_set_sim_state_side_effects_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void finalize_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void sf_gateway_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_enter_atomic_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_enter_internal_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_exit_internal_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_initc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initSimStructsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_enter_atomic_stateInitial
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_stateInitial(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c6_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_b_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_c_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_d_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_e_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_f_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_g_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_h_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_i_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_j_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_k_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_l_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_m_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_n_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_o_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_p_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_q_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_r_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_s_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_t_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_u_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_v_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_w_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_x_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static void c6_y_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256]);
static real_T c6_rand(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                      *chartInstance);
static real_T c6_eml_rand(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c6_eml_rand_mt19937ar(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_d_state[625]);
static void c6_twister_state_vector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_mt[625], real_T c6_seed, uint32_T c6_b_mt[625]);
static void c6_b_eml_rand_mt19937ar
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_d_state[625], uint32_T c6_e_state[625], real_T *c6_r);
static void c6_eml_error(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[256]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_b_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_c_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[256]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_m_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_n_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_o_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_p_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_q_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_r_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_s_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_t_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_u_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_v_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_w_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_x_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_y_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_db_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static void c6_activate_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_deactivate_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_increment_counters_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_reset_counters_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c6_arg
   [256]);
static void c6_idlePosec6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c6_bmlID, real_T c6_poseBML[256]);
static void c6_boredGazec6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c6_bmlID, real_T c6_gazeBML[256]);
static void c6_sendBML(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c6_b_sendBML(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static const mxArray *c6_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int8_T c6_e_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_f_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint8_T c6_g_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_tp_stateInitial, const char_T *c6_identifier);
static uint8_T c6_h_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint32_T c6_i_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_method, const char_T *c6_identifier);
static uint32_T c6_j_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static uint32_T c6_k_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_d_state, const char_T *c6_identifier);
static uint32_T c6_l_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_m_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_d_state, const char_T *c6_identifier,
  uint32_T c6_y[625]);
static void c6_n_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  uint32_T c6_y[625]);
static void c6_o_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_d_state, const char_T *c6_identifier,
  uint32_T c6_y[2]);
static void c6_p_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  uint32_T c6_y[2]);
static uint32_T c6_q_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_temporalCounter_i1, const char_T *c6_identifier);
static uint32_T c6_r_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static const mxArray *c6_s_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier);
static const mxArray *c6_t_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_updateDataWrittenToVector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_vectorIndex);
static void c6_errorIfDataNotWrittenToFcn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_vectorIndex, uint32_T c6_dataNumber);
static void c6_b_twister_state_vector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_mt[625], real_T c6_seed);
static real_T c6_c_eml_rand_mt19937ar
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_d_state[625]);
static real_T c6_get_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static real_T c6_get_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static real_T c6_get_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static real_T c6_get_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static real_T c6_get_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b);
static real_T c6_get_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b);
static real_T c6_get_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b);
static void c6_set_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c);
static real_T *c6_access_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b);
static void init_dsm_address_info(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_update_debugger_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c6_is_active_c6_ARP_02_RPSsmile_GloveAtomic == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic == c6_IN_stateInitial)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
      c6_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
      c6_IN_stateAvertGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
      c6_IN_stateAvertHead) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  }

  _SFD_SET_ANIMATION(c6_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  uint32_T c6_hoistedGlobal;
  uint32_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint32_T c6_b_hoistedGlobal;
  uint32_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  int32_T c6_i0;
  uint32_T c6_c_u[625];
  const mxArray *c6_d_y = NULL;
  int32_T c6_i1;
  uint32_T c6_d_u[2];
  const mxArray *c6_e_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  uint8_T c6_f_u;
  const mxArray *c6_g_y = NULL;
  uint32_T c6_e_hoistedGlobal;
  uint32_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(7, 1), false);
  c6_hoistedGlobal = chartInstance->c6_method;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  if (!chartInstance->c6_method_not_empty) {
    sf_mex_assign(&c6_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_state;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  if (!chartInstance->c6_state_not_empty) {
    sf_mex_assign(&c6_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 1, c6_c_y);
  for (c6_i0 = 0; c6_i0 < 625; c6_i0++) {
    c6_c_u[c6_i0] = chartInstance->c6_c_state[c6_i0];
  }

  c6_d_y = NULL;
  if (!chartInstance->c6_c_state_not_empty) {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_c_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c6_y, 2, c6_d_y);
  for (c6_i1 = 0; c6_i1 < 2; c6_i1++) {
    c6_d_u[c6_i1] = chartInstance->c6_b_state[c6_i1];
  }

  c6_e_y = NULL;
  if (!chartInstance->c6_b_state_not_empty) {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_d_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_c_hoistedGlobal =
    chartInstance->c6_is_active_c6_ARP_02_RPSsmile_GloveAtomic;
  c6_e_u = c6_c_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic;
  c6_f_u = c6_d_hoistedGlobal;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_e_hoistedGlobal = chartInstance->c6_temporalCounter_i1;
  c6_g_u = c6_e_hoistedGlobal;
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_st)
{
  const mxArray *c6_u;
  uint32_T c6_uv0[625];
  int32_T c6_i2;
  uint32_T c6_uv1[2];
  int32_T c6_i3;
  c6_u = sf_mex_dup(c6_st);
  chartInstance->c6_method = c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "method");
  chartInstance->c6_state = c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "state");
  c6_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
                        "state", c6_uv0);
  for (c6_i2 = 0; c6_i2 < 625; c6_i2++) {
    chartInstance->c6_c_state[c6_i2] = c6_uv0[c6_i2];
  }

  c6_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
                        "state", c6_uv1);
  for (c6_i3 = 0; c6_i3 < 2; c6_i3++) {
    chartInstance->c6_b_state[c6_i3] = c6_uv1[c6_i3];
  }

  chartInstance->c6_is_active_c6_ARP_02_RPSsmile_GloveAtomic =
    c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
    "is_active_c6_ARP_02_RPSsmile_GloveAtomic");
  chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 5)),
     "is_c6_ARP_02_RPSsmile_GloveAtomic");
  chartInstance->c6_temporalCounter_i1 = c6_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_debugger_state_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
        c6_IN_stateAvertGaze) {
      chartInstance->c6_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
        c6_IN_stateAvertHead) {
      chartInstance->c6_tp_stateAvertHead = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_stateAvertHead = 0U;
    }

    if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
        c6_IN_stateHeadNeutral) {
      chartInstance->c6_tp_stateHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic ==
        c6_IN_stateInitial) {
      chartInstance->c6_tp_stateInitial = 1U;
    } else {
      chartInstance->c6_tp_stateInitial = 0U;
    }

    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
}

static void sf_gateway_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  c6_set_sim_state_side_effects_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

static void c6_enter_atomic_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  chartInstance->c6_is_active_c6_ARP_02_RPSsmile_GloveAtomic = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void c6_enter_internal_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  chartInstance->c6_isStable = false;
  chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
  chartInstance->c6_tp_stateInitial = 1U;
  c6_enter_atomic_stateInitial(chartInstance);
}

static void c6_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  boolean_T c6_temp;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 1.0;
  boolean_T c6_b_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 0.0;
  real_T c6_dv0[256];
  int32_T c6_i4;
  real_T c6_dv1[256];
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_c_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_isStable = true;
  switch (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic) {
   case c6_IN_stateAvertGaze:
    CV_CHART_EVAL(5, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_jb_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_c_sf_marshallOut,
      c6_c_sf_marshallIn);
    c6_temp = (chartInstance->c6_sfEvent == c6_event_secs);
    if (c6_temp) {
      c6_temp = (chartInstance->c6_temporalCounter_i1 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c6_get_randomD
                  (chartInstance, 0), 32U, 2U));
    }

    c6_out = CV_EML_IF(2, 0, 0, c6_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_isStable = false;
      chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateInitial = 1U;
      c6_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c6_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateAvertHead:
    CV_CHART_EVAL(5, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_ob_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_c_sf_marshallOut,
      c6_c_sf_marshallIn);
    c6_b_out = CV_EML_IF(8, 0, 0, (chartInstance->c6_sfEvent == c6_event_secs) &&
                         (chartInstance->c6_temporalCounter_i1 >= 3U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateAvertHead = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
      chartInstance->c6_isStable = false;
      chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic =
        c6_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_fb_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U,
        c6_b_sf_marshallOut, c6_b_sf_marshallIn);
      c6_idlePosec6_ARP_02_RPSsmile_GloveAtomic(chartInstance, 8.0, c6_dv0);
      for (c6_i4 = 0; c6_i4 < 256; c6_i4++) {
        c6_dv1[c6_i4] = c6_dv0[c6_i4];
      }

      c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_dv1);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c6_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateHeadNeutral:
    CV_CHART_EVAL(5, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_ib_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_c_sf_marshallOut,
      c6_c_sf_marshallIn);
    c6_c_out = CV_EML_IF(1, 0, 0, (chartInstance->c6_sfEvent == c6_event_secs) &&
                         (chartInstance->c6_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
      chartInstance->c6_isStable = false;
      chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateInitial = 1U;
      c6_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c6_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateInitial:
    CV_CHART_EVAL(5, 0, 4);
    c6_stateInitial(chartInstance);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void c6_exit_internal_c6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  switch (chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic) {
   case c6_IN_stateAvertGaze:
    CV_CHART_EVAL(5, 0, 1);
    chartInstance->c6_tp_stateAvertGaze = 0U;
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateAvertHead:
    CV_CHART_EVAL(5, 0, 2);
    chartInstance->c6_tp_stateAvertHead = 0U;
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateHeadNeutral:
    CV_CHART_EVAL(5, 0, 3);
    chartInstance->c6_tp_stateHeadNeutral = 0U;
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_stateInitial:
    CV_CHART_EVAL(5, 0, 4);
    chartInstance->c6_tp_stateInitial = 0U;
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
    break;

   default:
    CV_CHART_EVAL(5, 0, 0);
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    break;
  }
}

static void c6_initc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_method_not_empty = false;
  chartInstance->c6_state_not_empty = false;
  chartInstance->c6_b_state_not_empty = false;
  chartInstance->c6_c_state_not_empty = false;
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_tp_stateAvertGaze = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_stateAvertHead = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_stateHeadNeutral = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_stateInitial = 0U;
  chartInstance->c6_is_active_c6_ARP_02_RPSsmile_GloveAtomic = 0U;
  chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_enter_atomic_stateInitial
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[2];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 0.0;
  real_T c6_r;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  real_T c6_b_r;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 0.0;
  real_T c6_c_hoistedGlobal;
  real_T c6_lowhigh[2];
  real_T c6_low;
  real_T c6_high;
  int32_T c6_i5;
  static char_T c6_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c6_c_u[26];
  const mxArray *c6_c_y = NULL;
  real_T c6_s;
  real_T c6_c_r;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_d_hoistedGlobal;
  real_T c6_d_u;
  const mxArray *c6_d_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_db_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  c6_r = c6_rand(chartInstance);
  c6_x = c6_r * 10.0;
  c6_b_x = c6_x;
  c6_b_x = muDoubleScalarFloor(c6_b_x);
  c6_r = 1.0 + c6_b_x;
  c6_set_randomG(chartInstance, 0, c6_r);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  sf_mex_printf("%s =\\n", "randomG");
  c6_hoistedGlobal = c6_get_randomG(chartInstance, 0);
  c6_u = c6_hoistedGlobal;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_y);
  c6_b_r = c6_rand(chartInstance);
  c6_c_x = c6_b_r * 4.0;
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarFloor(c6_d_x);
  c6_b_r = 1.0 + c6_d_x;
  c6_set_randomD(chartInstance, 0, c6_b_r);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  sf_mex_printf("%s =\\n", "randomD");
  c6_b_hoistedGlobal = c6_get_randomD(chartInstance, 0);
  c6_b_u = c6_b_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_b_y);
  c6_set_b(chartInstance, 0, c6_get_BOREDOMT(chartInstance, 0) - c6_get_bored
           (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_eb_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  c6_c_hoistedGlobal = c6_get_b(chartInstance, 0);
  c6_lowhigh[0] = 1.0;
  c6_lowhigh[1] = c6_c_hoistedGlobal;
  c6_low = c6_lowhigh[0];
  c6_high = c6_lowhigh[1];
  if (c6_low <= c6_high) {
  } else {
    for (c6_i5 = 0; c6_i5 < 26; c6_i5++) {
      c6_c_u[c6_i5] = c6_cv0[c6_i5];
    }

    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_c_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c6_c_y));
  }

  c6_s = (c6_high - c6_low) + 1.0;
  c6_c_r = c6_rand(chartInstance);
  c6_e_x = c6_c_r * c6_s;
  c6_f_x = c6_e_x;
  c6_f_x = muDoubleScalarFloor(c6_f_x);
  c6_c_r = c6_low + c6_f_x;
  c6_set_randomP(chartInstance, 0, c6_c_r);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  sf_mex_printf("%s =\\n", "randomP");
  c6_d_hoistedGlobal = c6_get_randomP(chartInstance, 0);
  c6_d_u = c6_d_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_d_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_stateInitial(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 1.0;
  boolean_T c6_b_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 0.0;
  real_T c6_r;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_dv2[256];
  int32_T c6_i6;
  real_T c6_dv3[256];
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 0.0;
  real_T c6_b_r;
  real_T c6_c_x;
  real_T c6_d_x;
  int32_T c6_i7;
  real_T c6_dv4[256];
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 1.0;
  boolean_T c6_d_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_kb_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  c6_out = CV_EML_IF(4, 0, 0, c6_get_pose(chartInstance, 0) != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c6_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
    chartInstance->c6_isStable = false;
    chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_stateInitial = 1U;
    c6_enter_atomic_stateInitial(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_nb_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_c_sf_marshallOut,
      c6_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(7, 0, 0, c6_get_randomG(chartInstance, 0) > 3.0)) {
      if (CV_EML_COND(7, 0, 1, c6_get_pose(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c6_b_out = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c6_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
      chartInstance->c6_isStable = false;
      chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic = c6_IN_stateAvertGaze;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_stateAvertGaze = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_gb_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U,
        c6_b_sf_marshallOut, c6_b_sf_marshallIn);
      c6_r = c6_rand(chartInstance);
      c6_x = c6_r * 8.0;
      c6_b_x = c6_x;
      c6_b_x = muDoubleScalarFloor(c6_b_x);
      c6_r = 1.0 + c6_b_x;
      c6_boredGazec6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_r, c6_dv2);
      for (c6_i6 = 0; c6_i6 < 256; c6_i6++) {
        c6_dv3[c6_i6] = c6_dv2[c6_i6];
      }

      c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_dv3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_mb_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U,
        c6_b_sf_marshallOut, c6_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_c_sf_marshallOut,
        c6_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(6, 0, 0, c6_get_randomP(chartInstance, 0) == 1.0)) {
        if (CV_EML_COND(6, 0, 1, c6_get_pose(chartInstance, 0) == 0.0)) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c6_c_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(6, 0, 0, false);
        CV_EML_IF(6, 0, 0, false);
        c6_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_stateInitial = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_isStable = false;
        chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic =
          c6_IN_stateAvertHead;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_stateAvertHead = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_hb_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        c6_b_r = c6_rand(chartInstance);
        c6_c_x = c6_b_r * 8.0;
        c6_d_x = c6_c_x;
        c6_d_x = muDoubleScalarFloor(c6_d_x);
        c6_b_r = 9.0 + c6_d_x;
        c6_boredGazec6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_b_r, c6_dv2);
        for (c6_i7 = 0; c6_i7 < 256; c6_i7++) {
          c6_dv4[c6_i7] = c6_dv2[c6_i7];
        }

        c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_dv4);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_lb_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_c_sf_marshallOut,
          c6_c_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(5, 0, 0, 0.0 < c6_get_randomG(chartInstance, 0))) {
          if (CV_EML_COND(5, 0, 1, c6_get_randomG(chartInstance, 0) < 4.0)) {
            CV_EML_MCDC(5, 0, 0, true);
            CV_EML_IF(5, 0, 0, true);
            c6_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(5, 0, 0, false);
          CV_EML_IF(5, 0, 0, false);
          c6_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_stateInitial = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
          chartInstance->c6_isStable = false;
          chartInstance->c6_is_c6_ARP_02_RPSsmile_GloveAtomic =
            c6_IN_stateInitial;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_stateInitial = 1U;
          c6_enter_atomic_stateInitial(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c6_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c6_sfEvent);
}

static void c6_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[147];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[147];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i8;
  static char_T c6_cv1[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', 'g',
    'a', 'z', 'e', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ', 'B', 'A', 'C',
    'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c6_i9;
  static real_T c6_dv5[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i8 = 0; c6_i8 < 147; c6_i8++) {
    c6_mystr[c6_i8] = c6_cv1[c6_i8];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i9 = 0; c6_i9 < 147; c6_i9++) {
    c6_arr[c6_i9] = c6_dv5[c6_i9];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i10 = 0; c6_i10 < 256; c6_i10++) {
    c6_tt[c6_i10] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i11 = 0; c6_i11 < 147; c6_i11++) {
    c6_tt[c6_i11] = c6_arr[c6_i11];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i12 = 0; c6_i12 < 256; c6_i12++) {
    c6_myarr256[c6_i12] = c6_tt[c6_i12];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_b_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[164];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[164];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i13;
  static char_T c6_cv2[164] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', 'g',
    'a', 'z', 'e', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'C', 'H', 'E', 'S', 'T', ' ', 'B',
    'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c6_i14;
  static real_T c6_dv6[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_c_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i13 = 0; c6_i13 < 164; c6_i13++) {
    c6_mystr[c6_i13] = c6_cv2[c6_i13];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i14 = 0; c6_i14 < 164; c6_i14++) {
    c6_arr[c6_i14] = c6_dv6[c6_i14];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i15 = 0; c6_i15 < 256; c6_i15++) {
    c6_tt[c6_i15] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i16 = 0; c6_i16 < 164; c6_i16++) {
    c6_tt[c6_i16] = c6_arr[c6_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i17 = 0; c6_i17 < 256; c6_i17++) {
    c6_myarr256[c6_i17] = c6_tt[c6_i17];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_c_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[223];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[223];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i18;
  static char_T c6_cv3[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"', '6',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '8', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c6_i19;
  static real_T c6_dv7[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_e_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i18 = 0; c6_i18 < 223; c6_i18++) {
    c6_mystr[c6_i18] = c6_cv3[c6_i18];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i19 = 0; c6_i19 < 223; c6_i19++) {
    c6_arr[c6_i19] = c6_dv7[c6_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i20 = 0; c6_i20 < 256; c6_i20++) {
    c6_tt[c6_i20] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i21 = 0; c6_i21 < 223; c6_i21++) {
    c6_tt[c6_i21] = c6_arr[c6_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i22 = 0; c6_i22 < 256; c6_i22++) {
    c6_myarr256[c6_i22] = c6_tt[c6_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_d_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[223];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[223];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i23;
  static char_T c6_cv4[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '9', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '7', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"', '6',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '9', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '7', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r',
    'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f',
    'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c6_i24;
  static real_T c6_dv8[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_f_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i23 = 0; c6_i23 < 223; c6_i23++) {
    c6_mystr[c6_i23] = c6_cv4[c6_i23];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i24 = 0; c6_i24 < 223; c6_i24++) {
    c6_arr[c6_i24] = c6_dv8[c6_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i25 = 0; c6_i25 < 256; c6_i25++) {
    c6_tt[c6_i25] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i26 = 0; c6_i26 < 223; c6_i26++) {
    c6_tt[c6_i26] = c6_arr[c6_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i27 = 0; c6_i27 < 256; c6_i27++) {
    c6_myarr256[c6_i27] = c6_tt[c6_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_e_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[225];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[225];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i28;
  static char_T c6_cv5[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '8', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '8', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c6_i29;
  static real_T c6_dv9[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_g_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i28 = 0; c6_i28 < 225; c6_i28++) {
    c6_mystr[c6_i28] = c6_cv5[c6_i28];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i29 = 0; c6_i29 < 225; c6_i29++) {
    c6_arr[c6_i29] = c6_dv9[c6_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i30 = 0; c6_i30 < 256; c6_i30++) {
    c6_tt[c6_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i31 = 0; c6_i31 < 225; c6_i31++) {
    c6_tt[c6_i31] = c6_arr[c6_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i32 = 0; c6_i32 < 256; c6_i32++) {
    c6_myarr256[c6_i32] = c6_tt[c6_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_f_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[225];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[225];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i33;
  static char_T c6_cv6[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '1', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '9', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '1', '\"', ' ', 'r', 'e', 'l',
    'a', 'x', '=', '\"', '9', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's',
    't', 'r', 'o', 'k', 'e', '=', '\"', '3', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c6_i34;
  static real_T c6_dv10[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_h_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i33 = 0; c6_i33 < 225; c6_i33++) {
    c6_mystr[c6_i33] = c6_cv6[c6_i33];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i34 = 0; c6_i34 < 225; c6_i34++) {
    c6_arr[c6_i34] = c6_dv10[c6_i34];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i35 = 0; c6_i35 < 256; c6_i35++) {
    c6_tt[c6_i35] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i36 = 0; c6_i36 < 225; c6_i36++) {
    c6_tt[c6_i36] = c6_arr[c6_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i37 = 0; c6_i37 < 256; c6_i37++) {
    c6_myarr256[c6_i37] = c6_tt[c6_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_g_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[87];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[87];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i38;
  static char_T c6_cv7[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c6_i39;
  static real_T c6_dv11[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_i_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i38 = 0; c6_i38 < 87; c6_i38++) {
    c6_mystr[c6_i38] = c6_cv7[c6_i38];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i39 = 0; c6_i39 < 87; c6_i39++) {
    c6_arr[c6_i39] = c6_dv11[c6_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i40 = 0; c6_i40 < 256; c6_i40++) {
    c6_tt[c6_i40] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i41 = 0; c6_i41 < 87; c6_i41++) {
    c6_tt[c6_i41] = c6_arr[c6_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i42 = 0; c6_i42 < 256; c6_i42++) {
    c6_myarr256[c6_i42] = c6_tt[c6_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_h_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[118];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[118];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i43;
  static char_T c6_cv8[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c6_i44;
  static real_T c6_dv12[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_k_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i43 = 0; c6_i43 < 118; c6_i43++) {
    c6_mystr[c6_i43] = c6_cv8[c6_i43];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i44 = 0; c6_i44 < 118; c6_i44++) {
    c6_arr[c6_i44] = c6_dv12[c6_i44];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i45 = 0; c6_i45 < 256; c6_i45++) {
    c6_tt[c6_i45] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i46 = 0; c6_i46 < 118; c6_i46++) {
    c6_tt[c6_i46] = c6_arr[c6_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i47 = 0; c6_i47 < 256; c6_i47++) {
    c6_myarr256[c6_i47] = c6_tt[c6_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_i_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[119];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[119];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i48;
  static char_T c6_cv9[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c6_i49;
  static real_T c6_dv13[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_l_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i48 = 0; c6_i48 < 119; c6_i48++) {
    c6_mystr[c6_i48] = c6_cv9[c6_i48];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i49 = 0; c6_i49 < 119; c6_i49++) {
    c6_arr[c6_i49] = c6_dv13[c6_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i50 = 0; c6_i50 < 256; c6_i50++) {
    c6_tt[c6_i50] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i51 = 0; c6_i51 < 119; c6_i51++) {
    c6_tt[c6_i51] = c6_arr[c6_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i52 = 0; c6_i52 < 256; c6_i52++) {
    c6_myarr256[c6_i52] = c6_tt[c6_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_j_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[116];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[116];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i53;
  static char_T c6_cv10[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c6_i54;
  static real_T c6_dv14[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_m_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i53 = 0; c6_i53 < 116; c6_i53++) {
    c6_mystr[c6_i53] = c6_cv10[c6_i53];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i54 = 0; c6_i54 < 116; c6_i54++) {
    c6_arr[c6_i54] = c6_dv14[c6_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i55 = 0; c6_i55 < 256; c6_i55++) {
    c6_tt[c6_i55] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i56 = 0; c6_i56 < 116; c6_i56++) {
    c6_tt[c6_i56] = c6_arr[c6_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i57 = 0; c6_i57 < 256; c6_i57++) {
    c6_myarr256[c6_i57] = c6_tt[c6_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_k_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[118];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[118];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i58;
  static char_T c6_cv11[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c6_i59;
  static real_T c6_dv15[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_n_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i58 = 0; c6_i58 < 118; c6_i58++) {
    c6_mystr[c6_i58] = c6_cv11[c6_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i59 = 0; c6_i59 < 118; c6_i59++) {
    c6_arr[c6_i59] = c6_dv15[c6_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i60 = 0; c6_i60 < 256; c6_i60++) {
    c6_tt[c6_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i61 = 0; c6_i61 < 118; c6_i61++) {
    c6_tt[c6_i61] = c6_arr[c6_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i62 = 0; c6_i62 < 256; c6_i62++) {
    c6_myarr256[c6_i62] = c6_tt[c6_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_l_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[120];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[120];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i63;
  static char_T c6_cv12[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i64;
  static real_T c6_dv16[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_o_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i63 = 0; c6_i63 < 120; c6_i63++) {
    c6_mystr[c6_i63] = c6_cv12[c6_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i64 = 0; c6_i64 < 120; c6_i64++) {
    c6_arr[c6_i64] = c6_dv16[c6_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i65 = 0; c6_i65 < 256; c6_i65++) {
    c6_tt[c6_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i66 = 0; c6_i66 < 120; c6_i66++) {
    c6_tt[c6_i66] = c6_arr[c6_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i67 = 0; c6_i67 < 256; c6_i67++) {
    c6_myarr256[c6_i67] = c6_tt[c6_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_m_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[121];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[121];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i68;
  static char_T c6_cv13[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i69;
  static real_T c6_dv17[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_p_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i68 = 0; c6_i68 < 121; c6_i68++) {
    c6_mystr[c6_i68] = c6_cv13[c6_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i69 = 0; c6_i69 < 121; c6_i69++) {
    c6_arr[c6_i69] = c6_dv17[c6_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i70 = 0; c6_i70 < 256; c6_i70++) {
    c6_tt[c6_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i71 = 0; c6_i71 < 121; c6_i71++) {
    c6_tt[c6_i71] = c6_arr[c6_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i72 = 0; c6_i72 < 256; c6_i72++) {
    c6_myarr256[c6_i72] = c6_tt[c6_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_n_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[122];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[122];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i73;
  static char_T c6_cv14[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i74;
  static real_T c6_dv18[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i75;
  int32_T c6_i76;
  int32_T c6_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_q_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i73 = 0; c6_i73 < 122; c6_i73++) {
    c6_mystr[c6_i73] = c6_cv14[c6_i73];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i74 = 0; c6_i74 < 122; c6_i74++) {
    c6_arr[c6_i74] = c6_dv18[c6_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i75 = 0; c6_i75 < 256; c6_i75++) {
    c6_tt[c6_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i76 = 0; c6_i76 < 122; c6_i76++) {
    c6_tt[c6_i76] = c6_arr[c6_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i77 = 0; c6_i77 < 256; c6_i77++) {
    c6_myarr256[c6_i77] = c6_tt[c6_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_o_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[123];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[123];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i78;
  static char_T c6_cv15[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i79;
  static real_T c6_dv19[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i80;
  int32_T c6_i81;
  int32_T c6_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_r_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i78 = 0; c6_i78 < 123; c6_i78++) {
    c6_mystr[c6_i78] = c6_cv15[c6_i78];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i79 = 0; c6_i79 < 123; c6_i79++) {
    c6_arr[c6_i79] = c6_dv19[c6_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i80 = 0; c6_i80 < 256; c6_i80++) {
    c6_tt[c6_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i81 = 0; c6_i81 < 123; c6_i81++) {
    c6_tt[c6_i81] = c6_arr[c6_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i82 = 0; c6_i82 < 256; c6_i82++) {
    c6_myarr256[c6_i82] = c6_tt[c6_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_p_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[133];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[133];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i83;
  static char_T c6_cv16[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c6_i84;
  static real_T c6_dv20[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i85;
  int32_T c6_i86;
  int32_T c6_i87;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_s_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i83 = 0; c6_i83 < 133; c6_i83++) {
    c6_mystr[c6_i83] = c6_cv16[c6_i83];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i84 = 0; c6_i84 < 133; c6_i84++) {
    c6_arr[c6_i84] = c6_dv20[c6_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i85 = 0; c6_i85 < 256; c6_i85++) {
    c6_tt[c6_i85] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i86 = 0; c6_i86 < 133; c6_i86++) {
    c6_tt[c6_i86] = c6_arr[c6_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i87 = 0; c6_i87 < 256; c6_i87++) {
    c6_myarr256[c6_i87] = c6_tt[c6_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_q_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[137];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[137];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i88;
  static char_T c6_cv17[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i89;
  static real_T c6_dv21[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i90;
  int32_T c6_i91;
  int32_T c6_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_t_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i88 = 0; c6_i88 < 137; c6_i88++) {
    c6_mystr[c6_i88] = c6_cv17[c6_i88];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i89 = 0; c6_i89 < 137; c6_i89++) {
    c6_arr[c6_i89] = c6_dv21[c6_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i90 = 0; c6_i90 < 256; c6_i90++) {
    c6_tt[c6_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i91 = 0; c6_i91 < 137; c6_i91++) {
    c6_tt[c6_i91] = c6_arr[c6_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i92 = 0; c6_i92 < 256; c6_i92++) {
    c6_myarr256[c6_i92] = c6_tt[c6_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_r_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[138];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[138];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i93;
  static char_T c6_cv18[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i94;
  static real_T c6_dv22[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i95;
  int32_T c6_i96;
  int32_T c6_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_u_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i93 = 0; c6_i93 < 138; c6_i93++) {
    c6_mystr[c6_i93] = c6_cv18[c6_i93];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i94 = 0; c6_i94 < 138; c6_i94++) {
    c6_arr[c6_i94] = c6_dv22[c6_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i95 = 0; c6_i95 < 256; c6_i95++) {
    c6_tt[c6_i95] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i96 = 0; c6_i96 < 138; c6_i96++) {
    c6_tt[c6_i96] = c6_arr[c6_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i97 = 0; c6_i97 < 256; c6_i97++) {
    c6_myarr256[c6_i97] = c6_tt[c6_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_s_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[136];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[136];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i98;
  static char_T c6_cv19[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i99;
  static real_T c6_dv23[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i100;
  int32_T c6_i101;
  int32_T c6_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_v_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i98 = 0; c6_i98 < 136; c6_i98++) {
    c6_mystr[c6_i98] = c6_cv19[c6_i98];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i99 = 0; c6_i99 < 136; c6_i99++) {
    c6_arr[c6_i99] = c6_dv23[c6_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i100 = 0; c6_i100 < 256; c6_i100++) {
    c6_tt[c6_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i101 = 0; c6_i101 < 136; c6_i101++) {
    c6_tt[c6_i101] = c6_arr[c6_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i102 = 0; c6_i102 < 256; c6_i102++) {
    c6_myarr256[c6_i102] = c6_tt[c6_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_t_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[135];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[135];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i103;
  static char_T c6_cv20[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i104;
  static real_T c6_dv24[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i105;
  int32_T c6_i106;
  int32_T c6_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_w_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i103 = 0; c6_i103 < 135; c6_i103++) {
    c6_mystr[c6_i103] = c6_cv20[c6_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i104 = 0; c6_i104 < 135; c6_i104++) {
    c6_arr[c6_i104] = c6_dv24[c6_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i105 = 0; c6_i105 < 256; c6_i105++) {
    c6_tt[c6_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i106 = 0; c6_i106 < 135; c6_i106++) {
    c6_tt[c6_i106] = c6_arr[c6_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i107 = 0; c6_i107 < 256; c6_i107++) {
    c6_myarr256[c6_i107] = c6_tt[c6_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_u_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[131];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[131];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i108;
  static char_T c6_cv21[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '1',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c6_i109;
  static real_T c6_dv25[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i110;
  int32_T c6_i111;
  int32_T c6_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_x_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i108 = 0; c6_i108 < 131; c6_i108++) {
    c6_mystr[c6_i108] = c6_cv21[c6_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i109 = 0; c6_i109 < 131; c6_i109++) {
    c6_arr[c6_i109] = c6_dv25[c6_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i110 = 0; c6_i110 < 256; c6_i110++) {
    c6_tt[c6_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i111 = 0; c6_i111 < 131; c6_i111++) {
    c6_tt[c6_i111] = c6_arr[c6_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i112 = 0; c6_i112 < 256; c6_i112++) {
    c6_myarr256[c6_i112] = c6_tt[c6_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_v_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[134];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[134];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i113;
  static char_T c6_cv22[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c6_i114;
  static real_T c6_dv26[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i115;
  int32_T c6_i116;
  int32_T c6_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_y_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i113 = 0; c6_i113 < 134; c6_i113++) {
    c6_mystr[c6_i113] = c6_cv22[c6_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i114 = 0; c6_i114 < 134; c6_i114++) {
    c6_arr[c6_i114] = c6_dv26[c6_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i115 = 0; c6_i115 < 256; c6_i115++) {
    c6_tt[c6_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i116 = 0; c6_i116 < 134; c6_i116++) {
    c6_tt[c6_i116] = c6_arr[c6_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i117 = 0; c6_i117 < 256; c6_i117++) {
    c6_myarr256[c6_i117] = c6_tt[c6_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_w_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[133];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[133];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i118;
  static char_T c6_cv23[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c6_i119;
  static real_T c6_dv27[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i120;
  int32_T c6_i121;
  int32_T c6_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_ab_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i118 = 0; c6_i118 < 133; c6_i118++) {
    c6_mystr[c6_i118] = c6_cv23[c6_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i119 = 0; c6_i119 < 133; c6_i119++) {
    c6_arr[c6_i119] = c6_dv27[c6_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i120 = 0; c6_i120 < 256; c6_i120++) {
    c6_tt[c6_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i121 = 0; c6_i121 < 133; c6_i121++) {
    c6_tt[c6_i121] = c6_arr[c6_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i122 = 0; c6_i122 < 256; c6_i122++) {
    c6_myarr256[c6_i122] = c6_tt[c6_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_x_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[142];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[142];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i123;
  static char_T c6_cv24[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i124;
  static real_T c6_dv28[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i125;
  int32_T c6_i126;
  int32_T c6_i127;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_bb_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i123 = 0; c6_i123 < 142; c6_i123++) {
    c6_mystr[c6_i123] = c6_cv24[c6_i123];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i124 = 0; c6_i124 < 142; c6_i124++) {
    c6_arr[c6_i124] = c6_dv28[c6_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i125 = 0; c6_i125 < 256; c6_i125++) {
    c6_tt[c6_i125] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i126 = 0; c6_i126 < 142; c6_i126++) {
    c6_tt[c6_i126] = c6_arr[c6_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i127 = 0; c6_i127 < 256; c6_i127++) {
    c6_myarr256[c6_i127] = c6_tt[c6_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_y_encStr2Arr(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c6_myarr256[256])
{
  uint32_T c6_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[225];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[225];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i128;
  static char_T c6_cv25[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c6_i129;
  static real_T c6_dv29[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c6_i130;
  int32_T c6_i131;
  int32_T c6_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_cb_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 6U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 7U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  for (c6_i128 = 0; c6_i128 < 225; c6_i128++) {
    c6_mystr[c6_i128] = c6_cv25[c6_i128];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i129 = 0; c6_i129 < 225; c6_i129++) {
    c6_arr[c6_i129] = c6_dv29[c6_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_padsize = c6_maxarrsize - c6_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
  for (c6_i130 = 0; c6_i130 < 256; c6_i130++) {
    c6_tt[c6_i130] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i131 = 0; c6_i131 < 225; c6_i131++) {
    c6_tt[c6_i131] = c6_arr[c6_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
  for (c6_i132 = 0; c6_i132 < 256; c6_i132++) {
    c6_myarr256[c6_i132] = c6_tt[c6_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c6_rand(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                      *chartInstance)
{
  return c6_eml_rand(chartInstance);
}

static real_T c6_eml_rand(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  real_T c6_r;
  uint32_T c6_hoistedGlobal;
  uint32_T c6_d_state;
  uint32_T c6_e_state;
  uint32_T c6_s;
  uint32_T c6_u0;
  uint32_T c6_hi;
  uint32_T c6_lo;
  uint32_T c6_test1;
  uint32_T c6_test2;
  uint32_T c6_f_state;
  real_T c6_b_r;
  real_T c6_d0;
  int32_T c6_i133;
  uint32_T c6_icng;
  uint32_T c6_jsr;
  uint32_T c6_u1;
  uint32_T c6_u2;
  uint32_T c6_ui;
  uint32_T c6_b_ui;
  real_T c6_c_r;
  real_T c6_d1;
  uint32_T c6_uv2[625];
  int32_T c6_i134;
  real_T c6_d2;
  if (!chartInstance->c6_method_not_empty) {
    chartInstance->c6_method = 7U;
    chartInstance->c6_method_not_empty = true;
  }

  if (chartInstance->c6_method == 4U) {
    if (!chartInstance->c6_state_not_empty) {
      chartInstance->c6_state = 1144108930U;
      chartInstance->c6_state_not_empty = true;
    }

    c6_hoistedGlobal = chartInstance->c6_state;
    c6_d_state = c6_hoistedGlobal;
    c6_e_state = c6_d_state;
    c6_s = c6_e_state;
    c6_u0 = 127773U;
    if (c6_u0 == 0U) {
      c6_hi = MAX_uint32_T;
    } else {
      c6_hi = c6_s / c6_u0;
    }

    c6_lo = c6_s - c6_hi * 127773U;
    c6_test1 = 16807U * c6_lo;
    c6_test2 = 2836U * c6_hi;
    if (c6_test1 < c6_test2) {
      c6_f_state = (c6_test1 - c6_test2) + 2147483647U;
    } else {
      c6_f_state = c6_test1 - c6_test2;
    }

    c6_b_r = (real_T)c6_f_state * 4.6566128752457969E-10;
    c6_e_state = c6_f_state;
    c6_d0 = c6_b_r;
    chartInstance->c6_state = c6_e_state;
    c6_r = c6_d0;
  } else if (chartInstance->c6_method == 5U) {
    if (!chartInstance->c6_b_state_not_empty) {
      for (c6_i133 = 0; c6_i133 < 2; c6_i133++) {
        chartInstance->c6_b_state[c6_i133] = 362436069U + 158852560U * (uint32_T)
          c6_i133;
      }

      chartInstance->c6_b_state_not_empty = true;
    }

    c6_icng = chartInstance->c6_b_state[0];
    c6_jsr = chartInstance->c6_b_state[1];
    c6_u1 = c6_jsr;
    c6_u2 = c6_icng;
    c6_u2 = 69069U * c6_u2 + 1234567U;
    c6_u1 ^= c6_u1 << 13;
    c6_u1 ^= c6_u1 >> 17;
    c6_u1 ^= c6_u1 << 5;
    c6_ui = c6_u2 + c6_u1;
    chartInstance->c6_b_state[0] = c6_u2;
    chartInstance->c6_b_state[1] = c6_u1;
    c6_b_ui = c6_ui;
    c6_c_r = (real_T)c6_b_ui * 2.328306436538696E-10;
    c6_d1 = c6_c_r;
    c6_r = c6_d1;
  } else {
    if (!chartInstance->c6_c_state_not_empty) {
      c6_eml_rand_mt19937ar(chartInstance, c6_uv2);
      for (c6_i134 = 0; c6_i134 < 625; c6_i134++) {
        chartInstance->c6_c_state[c6_i134] = c6_uv2[c6_i134];
      }

      chartInstance->c6_c_state_not_empty = true;
    }

    c6_d2 = c6_c_eml_rand_mt19937ar(chartInstance, chartInstance->c6_c_state);
    c6_r = c6_d2;
  }

  return c6_r;
}

static void c6_eml_rand_mt19937ar(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_d_state[625])
{
  real_T c6_d3;
  int32_T c6_i135;
  c6_d3 = 5489.0;
  for (c6_i135 = 0; c6_i135 < 625; c6_i135++) {
    c6_d_state[c6_i135] = 0U;
  }

  c6_b_twister_state_vector(chartInstance, c6_d_state, c6_d3);
}

static void c6_twister_state_vector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_mt[625], real_T c6_seed, uint32_T c6_b_mt[625])
{
  int32_T c6_i136;
  for (c6_i136 = 0; c6_i136 < 625; c6_i136++) {
    c6_b_mt[c6_i136] = c6_mt[c6_i136];
  }

  c6_b_twister_state_vector(chartInstance, c6_b_mt, c6_seed);
}

static void c6_b_eml_rand_mt19937ar
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_d_state[625], uint32_T c6_e_state[625], real_T *c6_r)
{
  int32_T c6_i137;
  for (c6_i137 = 0; c6_i137 < 625; c6_i137++) {
    c6_e_state[c6_i137] = c6_d_state[c6_i137];
  }

  *c6_r = c6_c_eml_rand_mt19937ar(chartInstance, c6_e_state);
}

static void c6_eml_error(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  int32_T c6_i138;
  static char_T c6_cv26[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c6_u[37];
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  for (c6_i138 = 0; c6_i138 < 37; c6_i138++) {
    c6_u[c6_i138] = c6_cv26[c6_i138];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c6_y));
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, c6_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i139;
  real_T c6_b_inData[256];
  int32_T c6_i140;
  real_T c6_u[256];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i139 = 0; c6_i139 < 256; c6_i139++) {
    c6_b_inData[c6_i139] = (*(real_T (*)[256])c6_inData)[c6_i139];
  }

  for (c6_i140 = 0; c6_i140 < 256; c6_i140++) {
    c6_u[c6_i140] = c6_b_inData[c6_i140];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[256])
{
  real_T c6_dv30[256];
  int32_T c6_i141;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv30, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c6_i141 = 0; c6_i141 < 256; c6_i141++) {
    c6_y[c6_i141] = c6_dv30[c6_i141];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_poseBML;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[256];
  int32_T c6_i142;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_poseBML = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_poseBML), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_poseBML);
  for (c6_i142 = 0; c6_i142 < 256; c6_i142++) {
    (*(real_T (*)[256])c6_outData)[c6_i142] = c6_y[c6_i142];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_b_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d4;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d4, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d4;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_bmlID;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_bmlID = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_bmlID), &c6_thisId);
  sf_mex_destroy(&c6_bmlID);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_c_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  boolean_T c6_y;
  boolean_T c6_b0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b0, 1, 11, 0U, 0, 0U, 0);
  c6_y = c6_b0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_aVarTruthTableCondition_8;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_aVarTruthTableCondition_8 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_aVarTruthTableCondition_8), &c6_thisId);
  sf_mex_destroy(&c6_aVarTruthTableCondition_8);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i143;
  real_T c6_b_inData[256];
  int32_T c6_i144;
  real_T c6_u[256];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i143 = 0; c6_i143 < 256; c6_i143++) {
    c6_b_inData[c6_i143] = (*(real_T (*)[256])c6_inData)[c6_i143];
  }

  for (c6_i144 = 0; c6_i144 < 256; c6_i144++) {
    c6_u[c6_i144] = c6_b_inData[c6_i144];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[256])
{
  real_T c6_dv31[256];
  int32_T c6_i145;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv31, 1, 0, 0U, 1, 0U, 1, 256);
  for (c6_i145 = 0; c6_i145 < 256; c6_i145++) {
    c6_y[c6_i145] = c6_dv31[c6_i145];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_myarr256;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[256];
  int32_T c6_i146;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_myarr256 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_myarr256), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_myarr256);
  for (c6_i146 = 0; c6_i146 < 256; c6_i146++) {
    (*(real_T (*)[256])c6_outData)[c6_i146] = c6_y[c6_i146];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i147;
  char_T c6_b_inData[147];
  int32_T c6_i148;
  char_T c6_u[147];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i147 = 0; c6_i147 < 147; c6_i147++) {
    c6_b_inData[c6_i147] = (*(char_T (*)[147])c6_inData)[c6_i147];
  }

  for (c6_i148 = 0; c6_i148 < 147; c6_i148++) {
    c6_u[c6_i148] = c6_b_inData[c6_i148];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i149;
  real_T c6_b_inData[147];
  int32_T c6_i150;
  real_T c6_u[147];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i149 = 0; c6_i149 < 147; c6_i149++) {
    c6_b_inData[c6_i149] = (*(real_T (*)[147])c6_inData)[c6_i149];
  }

  for (c6_i150 = 0; c6_i150 < 147; c6_i150++) {
    c6_u[c6_i150] = c6_b_inData[c6_i150];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i151;
  char_T c6_b_inData[164];
  int32_T c6_i152;
  char_T c6_u[164];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i151 = 0; c6_i151 < 164; c6_i151++) {
    c6_b_inData[c6_i151] = (*(char_T (*)[164])c6_inData)[c6_i151];
  }

  for (c6_i152 = 0; c6_i152 < 164; c6_i152++) {
    c6_u[c6_i152] = c6_b_inData[c6_i152];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i153;
  real_T c6_b_inData[164];
  int32_T c6_i154;
  real_T c6_u[164];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i153 = 0; c6_i153 < 164; c6_i153++) {
    c6_b_inData[c6_i153] = (*(real_T (*)[164])c6_inData)[c6_i153];
  }

  for (c6_i154 = 0; c6_i154 < 164; c6_i154++) {
    c6_u[c6_i154] = c6_b_inData[c6_i154];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i155;
  char_T c6_b_inData[68];
  int32_T c6_i156;
  char_T c6_u[68];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i155 = 0; c6_i155 < 68; c6_i155++) {
    c6_b_inData[c6_i155] = (*(char_T (*)[68])c6_inData)[c6_i155];
  }

  for (c6_i156 = 0; c6_i156 < 68; c6_i156++) {
    c6_u[c6_i156] = c6_b_inData[c6_i156];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i157;
  real_T c6_b_inData[68];
  int32_T c6_i158;
  real_T c6_u[68];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i157 = 0; c6_i157 < 68; c6_i157++) {
    c6_b_inData[c6_i157] = (*(real_T (*)[68])c6_inData)[c6_i157];
  }

  for (c6_i158 = 0; c6_i158 < 68; c6_i158++) {
    c6_u[c6_i158] = c6_b_inData[c6_i158];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i159;
  char_T c6_b_inData[223];
  int32_T c6_i160;
  char_T c6_u[223];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i159 = 0; c6_i159 < 223; c6_i159++) {
    c6_b_inData[c6_i159] = (*(char_T (*)[223])c6_inData)[c6_i159];
  }

  for (c6_i160 = 0; c6_i160 < 223; c6_i160++) {
    c6_u[c6_i160] = c6_b_inData[c6_i160];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i161;
  real_T c6_b_inData[223];
  int32_T c6_i162;
  real_T c6_u[223];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i161 = 0; c6_i161 < 223; c6_i161++) {
    c6_b_inData[c6_i161] = (*(real_T (*)[223])c6_inData)[c6_i161];
  }

  for (c6_i162 = 0; c6_i162 < 223; c6_i162++) {
    c6_u[c6_i162] = c6_b_inData[c6_i162];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_m_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i163;
  char_T c6_b_inData[225];
  int32_T c6_i164;
  char_T c6_u[225];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i163 = 0; c6_i163 < 225; c6_i163++) {
    c6_b_inData[c6_i163] = (*(char_T (*)[225])c6_inData)[c6_i163];
  }

  for (c6_i164 = 0; c6_i164 < 225; c6_i164++) {
    c6_u[c6_i164] = c6_b_inData[c6_i164];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_n_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i165;
  real_T c6_b_inData[225];
  int32_T c6_i166;
  real_T c6_u[225];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i165 = 0; c6_i165 < 225; c6_i165++) {
    c6_b_inData[c6_i165] = (*(real_T (*)[225])c6_inData)[c6_i165];
  }

  for (c6_i166 = 0; c6_i166 < 225; c6_i166++) {
    c6_u[c6_i166] = c6_b_inData[c6_i166];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_o_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i167;
  char_T c6_b_inData[87];
  int32_T c6_i168;
  char_T c6_u[87];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i167 = 0; c6_i167 < 87; c6_i167++) {
    c6_b_inData[c6_i167] = (*(char_T (*)[87])c6_inData)[c6_i167];
  }

  for (c6_i168 = 0; c6_i168 < 87; c6_i168++) {
    c6_u[c6_i168] = c6_b_inData[c6_i168];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_p_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i169;
  real_T c6_b_inData[87];
  int32_T c6_i170;
  real_T c6_u[87];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i169 = 0; c6_i169 < 87; c6_i169++) {
    c6_b_inData[c6_i169] = (*(real_T (*)[87])c6_inData)[c6_i169];
  }

  for (c6_i170 = 0; c6_i170 < 87; c6_i170++) {
    c6_u[c6_i170] = c6_b_inData[c6_i170];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_q_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i171;
  char_T c6_b_inData[118];
  int32_T c6_i172;
  char_T c6_u[118];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i171 = 0; c6_i171 < 118; c6_i171++) {
    c6_b_inData[c6_i171] = (*(char_T (*)[118])c6_inData)[c6_i171];
  }

  for (c6_i172 = 0; c6_i172 < 118; c6_i172++) {
    c6_u[c6_i172] = c6_b_inData[c6_i172];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_r_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i173;
  real_T c6_b_inData[118];
  int32_T c6_i174;
  real_T c6_u[118];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i173 = 0; c6_i173 < 118; c6_i173++) {
    c6_b_inData[c6_i173] = (*(real_T (*)[118])c6_inData)[c6_i173];
  }

  for (c6_i174 = 0; c6_i174 < 118; c6_i174++) {
    c6_u[c6_i174] = c6_b_inData[c6_i174];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_s_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i175;
  char_T c6_b_inData[119];
  int32_T c6_i176;
  char_T c6_u[119];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i175 = 0; c6_i175 < 119; c6_i175++) {
    c6_b_inData[c6_i175] = (*(char_T (*)[119])c6_inData)[c6_i175];
  }

  for (c6_i176 = 0; c6_i176 < 119; c6_i176++) {
    c6_u[c6_i176] = c6_b_inData[c6_i176];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_t_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i177;
  real_T c6_b_inData[119];
  int32_T c6_i178;
  real_T c6_u[119];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i177 = 0; c6_i177 < 119; c6_i177++) {
    c6_b_inData[c6_i177] = (*(real_T (*)[119])c6_inData)[c6_i177];
  }

  for (c6_i178 = 0; c6_i178 < 119; c6_i178++) {
    c6_u[c6_i178] = c6_b_inData[c6_i178];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_u_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i179;
  char_T c6_b_inData[116];
  int32_T c6_i180;
  char_T c6_u[116];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i179 = 0; c6_i179 < 116; c6_i179++) {
    c6_b_inData[c6_i179] = (*(char_T (*)[116])c6_inData)[c6_i179];
  }

  for (c6_i180 = 0; c6_i180 < 116; c6_i180++) {
    c6_u[c6_i180] = c6_b_inData[c6_i180];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_v_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i181;
  real_T c6_b_inData[116];
  int32_T c6_i182;
  real_T c6_u[116];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i181 = 0; c6_i181 < 116; c6_i181++) {
    c6_b_inData[c6_i181] = (*(real_T (*)[116])c6_inData)[c6_i181];
  }

  for (c6_i182 = 0; c6_i182 < 116; c6_i182++) {
    c6_u[c6_i182] = c6_b_inData[c6_i182];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_w_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i183;
  char_T c6_b_inData[120];
  int32_T c6_i184;
  char_T c6_u[120];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i183 = 0; c6_i183 < 120; c6_i183++) {
    c6_b_inData[c6_i183] = (*(char_T (*)[120])c6_inData)[c6_i183];
  }

  for (c6_i184 = 0; c6_i184 < 120; c6_i184++) {
    c6_u[c6_i184] = c6_b_inData[c6_i184];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_x_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i185;
  real_T c6_b_inData[120];
  int32_T c6_i186;
  real_T c6_u[120];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i185 = 0; c6_i185 < 120; c6_i185++) {
    c6_b_inData[c6_i185] = (*(real_T (*)[120])c6_inData)[c6_i185];
  }

  for (c6_i186 = 0; c6_i186 < 120; c6_i186++) {
    c6_u[c6_i186] = c6_b_inData[c6_i186];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_y_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i187;
  char_T c6_b_inData[121];
  int32_T c6_i188;
  char_T c6_u[121];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i187 = 0; c6_i187 < 121; c6_i187++) {
    c6_b_inData[c6_i187] = (*(char_T (*)[121])c6_inData)[c6_i187];
  }

  for (c6_i188 = 0; c6_i188 < 121; c6_i188++) {
    c6_u[c6_i188] = c6_b_inData[c6_i188];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i189;
  real_T c6_b_inData[121];
  int32_T c6_i190;
  real_T c6_u[121];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i189 = 0; c6_i189 < 121; c6_i189++) {
    c6_b_inData[c6_i189] = (*(real_T (*)[121])c6_inData)[c6_i189];
  }

  for (c6_i190 = 0; c6_i190 < 121; c6_i190++) {
    c6_u[c6_i190] = c6_b_inData[c6_i190];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i191;
  char_T c6_b_inData[122];
  int32_T c6_i192;
  char_T c6_u[122];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i191 = 0; c6_i191 < 122; c6_i191++) {
    c6_b_inData[c6_i191] = (*(char_T (*)[122])c6_inData)[c6_i191];
  }

  for (c6_i192 = 0; c6_i192 < 122; c6_i192++) {
    c6_u[c6_i192] = c6_b_inData[c6_i192];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i193;
  real_T c6_b_inData[122];
  int32_T c6_i194;
  real_T c6_u[122];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i193 = 0; c6_i193 < 122; c6_i193++) {
    c6_b_inData[c6_i193] = (*(real_T (*)[122])c6_inData)[c6_i193];
  }

  for (c6_i194 = 0; c6_i194 < 122; c6_i194++) {
    c6_u[c6_i194] = c6_b_inData[c6_i194];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_db_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i195;
  char_T c6_b_inData[123];
  int32_T c6_i196;
  char_T c6_u[123];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i195 = 0; c6_i195 < 123; c6_i195++) {
    c6_b_inData[c6_i195] = (*(char_T (*)[123])c6_inData)[c6_i195];
  }

  for (c6_i196 = 0; c6_i196 < 123; c6_i196++) {
    c6_u[c6_i196] = c6_b_inData[c6_i196];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i197;
  real_T c6_b_inData[123];
  int32_T c6_i198;
  real_T c6_u[123];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i197 = 0; c6_i197 < 123; c6_i197++) {
    c6_b_inData[c6_i197] = (*(real_T (*)[123])c6_inData)[c6_i197];
  }

  for (c6_i198 = 0; c6_i198 < 123; c6_i198++) {
    c6_u[c6_i198] = c6_b_inData[c6_i198];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i199;
  char_T c6_b_inData[133];
  int32_T c6_i200;
  char_T c6_u[133];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i199 = 0; c6_i199 < 133; c6_i199++) {
    c6_b_inData[c6_i199] = (*(char_T (*)[133])c6_inData)[c6_i199];
  }

  for (c6_i200 = 0; c6_i200 < 133; c6_i200++) {
    c6_u[c6_i200] = c6_b_inData[c6_i200];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i201;
  real_T c6_b_inData[133];
  int32_T c6_i202;
  real_T c6_u[133];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i201 = 0; c6_i201 < 133; c6_i201++) {
    c6_b_inData[c6_i201] = (*(real_T (*)[133])c6_inData)[c6_i201];
  }

  for (c6_i202 = 0; c6_i202 < 133; c6_i202++) {
    c6_u[c6_i202] = c6_b_inData[c6_i202];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i203;
  char_T c6_b_inData[137];
  int32_T c6_i204;
  char_T c6_u[137];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i203 = 0; c6_i203 < 137; c6_i203++) {
    c6_b_inData[c6_i203] = (*(char_T (*)[137])c6_inData)[c6_i203];
  }

  for (c6_i204 = 0; c6_i204 < 137; c6_i204++) {
    c6_u[c6_i204] = c6_b_inData[c6_i204];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i205;
  real_T c6_b_inData[137];
  int32_T c6_i206;
  real_T c6_u[137];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i205 = 0; c6_i205 < 137; c6_i205++) {
    c6_b_inData[c6_i205] = (*(real_T (*)[137])c6_inData)[c6_i205];
  }

  for (c6_i206 = 0; c6_i206 < 137; c6_i206++) {
    c6_u[c6_i206] = c6_b_inData[c6_i206];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i207;
  char_T c6_b_inData[138];
  int32_T c6_i208;
  char_T c6_u[138];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i207 = 0; c6_i207 < 138; c6_i207++) {
    c6_b_inData[c6_i207] = (*(char_T (*)[138])c6_inData)[c6_i207];
  }

  for (c6_i208 = 0; c6_i208 < 138; c6_i208++) {
    c6_u[c6_i208] = c6_b_inData[c6_i208];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i209;
  real_T c6_b_inData[138];
  int32_T c6_i210;
  real_T c6_u[138];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i209 = 0; c6_i209 < 138; c6_i209++) {
    c6_b_inData[c6_i209] = (*(real_T (*)[138])c6_inData)[c6_i209];
  }

  for (c6_i210 = 0; c6_i210 < 138; c6_i210++) {
    c6_u[c6_i210] = c6_b_inData[c6_i210];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i211;
  char_T c6_b_inData[136];
  int32_T c6_i212;
  char_T c6_u[136];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i211 = 0; c6_i211 < 136; c6_i211++) {
    c6_b_inData[c6_i211] = (*(char_T (*)[136])c6_inData)[c6_i211];
  }

  for (c6_i212 = 0; c6_i212 < 136; c6_i212++) {
    c6_u[c6_i212] = c6_b_inData[c6_i212];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i213;
  real_T c6_b_inData[136];
  int32_T c6_i214;
  real_T c6_u[136];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i213 = 0; c6_i213 < 136; c6_i213++) {
    c6_b_inData[c6_i213] = (*(real_T (*)[136])c6_inData)[c6_i213];
  }

  for (c6_i214 = 0; c6_i214 < 136; c6_i214++) {
    c6_u[c6_i214] = c6_b_inData[c6_i214];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i215;
  char_T c6_b_inData[135];
  int32_T c6_i216;
  char_T c6_u[135];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i215 = 0; c6_i215 < 135; c6_i215++) {
    c6_b_inData[c6_i215] = (*(char_T (*)[135])c6_inData)[c6_i215];
  }

  for (c6_i216 = 0; c6_i216 < 135; c6_i216++) {
    c6_u[c6_i216] = c6_b_inData[c6_i216];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i217;
  real_T c6_b_inData[135];
  int32_T c6_i218;
  real_T c6_u[135];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i217 = 0; c6_i217 < 135; c6_i217++) {
    c6_b_inData[c6_i217] = (*(real_T (*)[135])c6_inData)[c6_i217];
  }

  for (c6_i218 = 0; c6_i218 < 135; c6_i218++) {
    c6_u[c6_i218] = c6_b_inData[c6_i218];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i219;
  char_T c6_b_inData[131];
  int32_T c6_i220;
  char_T c6_u[131];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i219 = 0; c6_i219 < 131; c6_i219++) {
    c6_b_inData[c6_i219] = (*(char_T (*)[131])c6_inData)[c6_i219];
  }

  for (c6_i220 = 0; c6_i220 < 131; c6_i220++) {
    c6_u[c6_i220] = c6_b_inData[c6_i220];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i221;
  real_T c6_b_inData[131];
  int32_T c6_i222;
  real_T c6_u[131];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i221 = 0; c6_i221 < 131; c6_i221++) {
    c6_b_inData[c6_i221] = (*(real_T (*)[131])c6_inData)[c6_i221];
  }

  for (c6_i222 = 0; c6_i222 < 131; c6_i222++) {
    c6_u[c6_i222] = c6_b_inData[c6_i222];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i223;
  char_T c6_b_inData[134];
  int32_T c6_i224;
  char_T c6_u[134];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i223 = 0; c6_i223 < 134; c6_i223++) {
    c6_b_inData[c6_i223] = (*(char_T (*)[134])c6_inData)[c6_i223];
  }

  for (c6_i224 = 0; c6_i224 < 134; c6_i224++) {
    c6_u[c6_i224] = c6_b_inData[c6_i224];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i225;
  real_T c6_b_inData[134];
  int32_T c6_i226;
  real_T c6_u[134];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i225 = 0; c6_i225 < 134; c6_i225++) {
    c6_b_inData[c6_i225] = (*(real_T (*)[134])c6_inData)[c6_i225];
  }

  for (c6_i226 = 0; c6_i226 < 134; c6_i226++) {
    c6_u[c6_i226] = c6_b_inData[c6_i226];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i227;
  char_T c6_b_inData[142];
  int32_T c6_i228;
  char_T c6_u[142];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i227 = 0; c6_i227 < 142; c6_i227++) {
    c6_b_inData[c6_i227] = (*(char_T (*)[142])c6_inData)[c6_i227];
  }

  for (c6_i228 = 0; c6_i228 < 142; c6_i228++) {
    c6_u[c6_i228] = c6_b_inData[c6_i228];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i229;
  real_T c6_b_inData[142];
  int32_T c6_i230;
  real_T c6_u[142];
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i229 = 0; c6_i229 < 142; c6_i229++) {
    c6_b_inData[c6_i229] = (*(real_T (*)[142])c6_inData)[c6_i229];
  }

  for (c6_i230 = 0; c6_i230 < 142; c6_i230++) {
    c6_u[c6_i230] = c6_b_inData[c6_i230];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

const mxArray *sf_c6_ARP_02_RPSsmile_GloveAtomic_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  const mxArray *c6_rhs4 = NULL;
  const mxArray *c6_lhs4 = NULL;
  const mxArray *c6_rhs5 = NULL;
  const mxArray *c6_lhs5 = NULL;
  const mxArray *c6_rhs6 = NULL;
  const mxArray *c6_lhs6 = NULL;
  const mxArray *c6_rhs7 = NULL;
  const mxArray *c6_lhs7 = NULL;
  const mxArray *c6_rhs8 = NULL;
  const mxArray *c6_lhs8 = NULL;
  const mxArray *c6_rhs9 = NULL;
  const mxArray *c6_lhs9 = NULL;
  const mxArray *c6_rhs10 = NULL;
  const mxArray *c6_lhs10 = NULL;
  const mxArray *c6_rhs11 = NULL;
  const mxArray *c6_lhs11 = NULL;
  const mxArray *c6_rhs12 = NULL;
  const mxArray *c6_lhs12 = NULL;
  const mxArray *c6_rhs13 = NULL;
  const mxArray *c6_lhs13 = NULL;
  const mxArray *c6_rhs14 = NULL;
  const mxArray *c6_lhs14 = NULL;
  const mxArray *c6_rhs15 = NULL;
  const mxArray *c6_lhs15 = NULL;
  const mxArray *c6_rhs16 = NULL;
  const mxArray *c6_lhs16 = NULL;
  const mxArray *c6_rhs17 = NULL;
  const mxArray *c6_lhs17 = NULL;
  const mxArray *c6_rhs18 = NULL;
  const mxArray *c6_lhs18 = NULL;
  const mxArray *c6_rhs19 = NULL;
  const mxArray *c6_lhs19 = NULL;
  const mxArray *c6_rhs20 = NULL;
  const mxArray *c6_lhs20 = NULL;
  const mxArray *c6_rhs21 = NULL;
  const mxArray *c6_lhs21 = NULL;
  const mxArray *c6_rhs22 = NULL;
  const mxArray *c6_lhs22 = NULL;
  const mxArray *c6_rhs23 = NULL;
  const mxArray *c6_lhs23 = NULL;
  const mxArray *c6_rhs24 = NULL;
  const mxArray *c6_lhs24 = NULL;
  const mxArray *c6_rhs25 = NULL;
  const mxArray *c6_lhs25 = NULL;
  const mxArray *c6_rhs26 = NULL;
  const mxArray *c6_lhs26 = NULL;
  const mxArray *c6_rhs27 = NULL;
  const mxArray *c6_lhs27 = NULL;
  const mxArray *c6_rhs28 = NULL;
  const mxArray *c6_lhs28 = NULL;
  const mxArray *c6_rhs29 = NULL;
  const mxArray *c6_lhs29 = NULL;
  const mxArray *c6_rhs30 = NULL;
  const mxArray *c6_lhs30 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c6_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c6_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c6_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c6_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c6_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c6_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c6_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c6_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c6_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c6_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c6_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c6_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c6_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c6_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c6_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c6_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c6_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c6_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c6_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c6_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c6_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c6_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c6_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c6_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c6_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c6_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c6_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs30), "lhs", "lhs",
                  30);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
  sf_mex_destroy(&c6_rhs4);
  sf_mex_destroy(&c6_lhs4);
  sf_mex_destroy(&c6_rhs5);
  sf_mex_destroy(&c6_lhs5);
  sf_mex_destroy(&c6_rhs6);
  sf_mex_destroy(&c6_lhs6);
  sf_mex_destroy(&c6_rhs7);
  sf_mex_destroy(&c6_lhs7);
  sf_mex_destroy(&c6_rhs8);
  sf_mex_destroy(&c6_lhs8);
  sf_mex_destroy(&c6_rhs9);
  sf_mex_destroy(&c6_lhs9);
  sf_mex_destroy(&c6_rhs10);
  sf_mex_destroy(&c6_lhs10);
  sf_mex_destroy(&c6_rhs11);
  sf_mex_destroy(&c6_lhs11);
  sf_mex_destroy(&c6_rhs12);
  sf_mex_destroy(&c6_lhs12);
  sf_mex_destroy(&c6_rhs13);
  sf_mex_destroy(&c6_lhs13);
  sf_mex_destroy(&c6_rhs14);
  sf_mex_destroy(&c6_lhs14);
  sf_mex_destroy(&c6_rhs15);
  sf_mex_destroy(&c6_lhs15);
  sf_mex_destroy(&c6_rhs16);
  sf_mex_destroy(&c6_lhs16);
  sf_mex_destroy(&c6_rhs17);
  sf_mex_destroy(&c6_lhs17);
  sf_mex_destroy(&c6_rhs18);
  sf_mex_destroy(&c6_lhs18);
  sf_mex_destroy(&c6_rhs19);
  sf_mex_destroy(&c6_lhs19);
  sf_mex_destroy(&c6_rhs20);
  sf_mex_destroy(&c6_lhs20);
  sf_mex_destroy(&c6_rhs21);
  sf_mex_destroy(&c6_lhs21);
  sf_mex_destroy(&c6_rhs22);
  sf_mex_destroy(&c6_lhs22);
  sf_mex_destroy(&c6_rhs23);
  sf_mex_destroy(&c6_lhs23);
  sf_mex_destroy(&c6_rhs24);
  sf_mex_destroy(&c6_lhs24);
  sf_mex_destroy(&c6_rhs25);
  sf_mex_destroy(&c6_lhs25);
  sf_mex_destroy(&c6_rhs26);
  sf_mex_destroy(&c6_lhs26);
  sf_mex_destroy(&c6_rhs27);
  sf_mex_destroy(&c6_lhs27);
  sf_mex_destroy(&c6_rhs28);
  sf_mex_destroy(&c6_lhs28);
  sf_mex_destroy(&c6_rhs29);
  sf_mex_destroy(&c6_lhs29);
  sf_mex_destroy(&c6_rhs30);
  sf_mex_destroy(&c6_lhs30);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static void c6_activate_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = c6_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c6_event_secs,
               chartInstance->c6_sfEvent);
}

static void c6_deactivate_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c6_event_secs,
               chartInstance->c6_sfEvent);
}

static void c6_increment_counters_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  if (chartInstance->c6_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c6_temporalCounter_i1++;
  }
}

static void c6_reset_counters_secsc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c6_ARP_02_RPSsmile_GloveAtomic_secs(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_activate_secsc6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c6_ARP_02_RPSsmile_GloveAtomic_secs
  (SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_increment_counters_secsc6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c6_ARP_02_RPSsmile_GloveAtomic_secs
  (SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_reset_counters_secsc6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_deactivate_c6_ARP_02_RPSsmile_GloveAtomic_secs(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_deactivate_secsc6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

boolean_T sf_exported_auto_isStablec6_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c6_isStable;
}

void sf_exported_auto_duringc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_enterc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c6_sendBML(chartInstance);
  c6_enter_atomic_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  c6_enter_internal_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_exitc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c6_exit_internal_c6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  c6_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c6_sendBML(chartInstance);
}

void sf_exported_auto_disablec6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c6_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc6_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  chartInstance->c6_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc6_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc6_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc6_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_initc6_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec6_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c6_S)
{
  const mxArray *c6_out = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_out = NULL;
  sf_mex_assign(&c6_out,
                sf_internal_get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic(c6_S),
                false);
  return c6_out;
}

void sf_exported_auto_setSimstatec6_ARP_02_RPSsmile_GloveAtomic(SimStruct *c6_S,
  const mxArray *c6_in)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic(c6_S, sf_mex_dup
    (c6_in));
  sf_mex_destroy(&c6_in);
}

void sf_exported_auto_check_state_inconsistency_c6_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c6_S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSsmile_GloveAtomicMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c6_arg
   [256])
{
  int32_T c6_i231;
  int32_T c6_i232;
  int32_T c6_i233;
  real_T (*c6_b_arg)[256];
  c6_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c6_i231 = 0; c6_i231 < 256; c6_i231++) {
    _SFD_DATA_RANGE_CHECK(c6_arg[c6_i231], 7U);
  }

  _SFD_SET_DATA_VALUE_PTR(7U, c6_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c6_arg, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
  for (c6_i232 = 0; c6_i232 < 256; c6_i232++) {
    (*c6_b_arg)[c6_i232] = c6_arg[c6_i232];
  }

  for (c6_i233 = 0; c6_i233 < 256; c6_i233++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_arg)[c6_i233], 7U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(7U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
}

static void c6_idlePosec6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c6_bmlID, real_T c6_poseBML[256])
{
  uint32_T c6_debug_family_var_map[12];
  boolean_T c6_aVarTruthTableCondition_1;
  boolean_T c6_aVarTruthTableCondition_2;
  boolean_T c6_aVarTruthTableCondition_3;
  boolean_T c6_aVarTruthTableCondition_4;
  boolean_T c6_aVarTruthTableCondition_5;
  boolean_T c6_aVarTruthTableCondition_6;
  boolean_T c6_aVarTruthTableCondition_7;
  boolean_T c6_aVarTruthTableCondition_8;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_dv32[256];
  int32_T c6_i234;
  int32_T c6_i235;
  real_T c6_u[256];
  const mxArray *c6_y = NULL;
  int32_T c6_i236;
  int32_T c6_i237;
  real_T c6_b_u[256];
  const mxArray *c6_b_y = NULL;
  uint32_T c6_b_debug_family_var_map[9];
  real_T c6_maxarrsize;
  real_T c6_arr[68];
  real_T c6_ss;
  real_T c6_padsize;
  real_T c6_tt[256];
  char_T c6_mystr[68];
  real_T c6_b_nargin = 1.0;
  real_T c6_b_nargout = 1.0;
  real_T c6_myarr256[256];
  int32_T c6_i238;
  static char_T c6_cv27[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c6_i239;
  static real_T c6_dv33[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c6_i240;
  int32_T c6_i241;
  int32_T c6_i242;
  int32_T c6_i243;
  int32_T c6_i244;
  real_T c6_c_u[256];
  const mxArray *c6_c_y = NULL;
  int32_T c6_i245;
  int32_T c6_i246;
  real_T c6_d_u[256];
  const mxArray *c6_d_y = NULL;
  int32_T c6_i247;
  int32_T c6_i248;
  real_T c6_e_u[256];
  const mxArray *c6_e_y = NULL;
  int32_T c6_i249;
  int32_T c6_i250;
  real_T c6_f_u[256];
  const mxArray *c6_f_y = NULL;
  int32_T c6_i251;
  int32_T c6_i252;
  real_T c6_g_u[256];
  const mxArray *c6_g_y = NULL;
  int32_T c6_i253;
  int32_T c6_i254;
  real_T c6_h_u[256];
  const mxArray *c6_h_y = NULL;
  int32_T c6_i255;
  int32_T c6_i256;
  real_T c6_i_u[256];
  const mxArray *c6_i_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_1, 0U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_2, 1U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_3, 2U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_4, 3U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_5, 4U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_6, 5U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_7, 6U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_8, 7U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 8U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 9U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_bmlID, 10U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_poseBML, 11U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 3);
  c6_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 4);
  c6_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 5);
  c6_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 6);
  c6_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 7);
  c6_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 8);
  c6_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 9);
  c6_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 10);
  c6_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 15);
  c6_aVarTruthTableCondition_1 = (c6_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 19);
  c6_aVarTruthTableCondition_2 = (c6_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 23);
  c6_aVarTruthTableCondition_3 = (c6_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 27);
  c6_aVarTruthTableCondition_4 = (c6_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 31);
  c6_aVarTruthTableCondition_5 = (c6_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 35);
  c6_aVarTruthTableCondition_6 = (c6_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 39);
  c6_aVarTruthTableCondition_7 = (c6_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 43);
  c6_aVarTruthTableCondition_8 = (c6_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 45);
  if (CV_EML_IF(1, 1, 0, c6_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 46);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 69);
    c6_encStr2Arr(chartInstance, c6_dv32);
    for (c6_i234 = 0; c6_i234 < 256; c6_i234++) {
      c6_poseBML[c6_i234] = c6_dv32[c6_i234];
    }

    c6_updateDataWrittenToVector(chartInstance, 0U);
    c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c6_i235 = 0; c6_i235 < 256; c6_i235++) {
      c6_u[c6_i235] = c6_poseBML[c6_i235];
    }

    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_y);
    _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -69);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 47);
    if (CV_EML_IF(1, 1, 1, c6_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 48);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 75);
      c6_b_encStr2Arr(chartInstance, c6_dv32);
      for (c6_i236 = 0; c6_i236 < 256; c6_i236++) {
        c6_poseBML[c6_i236] = c6_dv32[c6_i236];
      }

      c6_updateDataWrittenToVector(chartInstance, 0U);
      c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c6_i237 = 0; c6_i237 < 256; c6_i237++) {
        c6_b_u[c6_i237] = c6_poseBML[c6_i237];
      }

      c6_b_y = NULL;
      sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_b_y);
      _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -75);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 49);
      if (CV_EML_IF(1, 1, 2, c6_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 50);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 81);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c6_d_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_maxarrsize, 0U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c6_arr, 1U, c6_j_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c6_ss, 2U, c6_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_padsize, 3U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_tt, 4U, c6_d_sf_marshallOut,
          c6_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c6_mystr, 5U, c6_i_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 6U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 7U,
          c6_b_sf_marshallOut, c6_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_myarr256, 8U,
          c6_d_sf_marshallOut, c6_d_sf_marshallIn);
        for (c6_i238 = 0; c6_i238 < 68; c6_i238++) {
          c6_mystr[c6_i238] = c6_cv27[c6_i238];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 4);
        c6_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 6);
        for (c6_i239 = 0; c6_i239 < 68; c6_i239++) {
          c6_arr[c6_i239] = c6_dv33[c6_i239];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 7);
        c6_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 8);
        c6_padsize = c6_maxarrsize - c6_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 9);
        for (c6_i240 = 0; c6_i240 < 256; c6_i240++) {
          c6_tt[c6_i240] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 10);
        for (c6_i241 = 0; c6_i241 < 68; c6_i241++) {
          c6_tt[c6_i241] = c6_arr[c6_i241];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, 11);
        for (c6_i242 = 0; c6_i242 < 256; c6_i242++) {
          c6_myarr256[c6_i242] = c6_tt[c6_i242];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c6_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c6_i243 = 0; c6_i243 < 256; c6_i243++) {
          c6_poseBML[c6_i243] = c6_myarr256[c6_i243];
        }

        c6_updateDataWrittenToVector(chartInstance, 0U);
        c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c6_i244 = 0; c6_i244 < 256; c6_i244++) {
          c6_c_u[c6_i244] = c6_poseBML[c6_i244];
        }

        c6_c_y = NULL;
        sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c6_c_y);
        _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -81);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 51);
        if (CV_EML_IF(1, 1, 3, c6_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 52);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 87);
          c6_c_encStr2Arr(chartInstance, c6_dv32);
          for (c6_i245 = 0; c6_i245 < 256; c6_i245++) {
            c6_poseBML[c6_i245] = c6_dv32[c6_i245];
          }

          c6_updateDataWrittenToVector(chartInstance, 0U);
          c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c6_i246 = 0; c6_i246 < 256; c6_i246++) {
            c6_d_u[c6_i246] = c6_poseBML[c6_i246];
          }

          c6_d_y = NULL;
          sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c6_d_y);
          _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -87);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 53);
          if (CV_EML_IF(1, 1, 4, c6_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 54);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 93);
            c6_d_encStr2Arr(chartInstance, c6_dv32);
            for (c6_i247 = 0; c6_i247 < 256; c6_i247++) {
              c6_poseBML[c6_i247] = c6_dv32[c6_i247];
            }

            c6_updateDataWrittenToVector(chartInstance, 0U);
            c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c6_i248 = 0; c6_i248 < 256; c6_i248++) {
              c6_e_u[c6_i248] = c6_poseBML[c6_i248];
            }

            c6_e_y = NULL;
            sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c6_e_y);
            _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -93);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 55);
            if (CV_EML_IF(1, 1, 5, c6_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 56);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 99);
              c6_e_encStr2Arr(chartInstance, c6_dv32);
              for (c6_i249 = 0; c6_i249 < 256; c6_i249++) {
                c6_poseBML[c6_i249] = c6_dv32[c6_i249];
              }

              c6_updateDataWrittenToVector(chartInstance, 0U);
              c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c6_i250 = 0; c6_i250 < 256; c6_i250++) {
                c6_f_u[c6_i250] = c6_poseBML[c6_i250];
              }

              c6_f_y = NULL;
              sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c6_f_y);
              _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -99);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 57);
              if (CV_EML_IF(1, 1, 6, c6_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 58);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 105);
                c6_f_encStr2Arr(chartInstance, c6_dv32);
                for (c6_i251 = 0; c6_i251 < 256; c6_i251++) {
                  c6_poseBML[c6_i251] = c6_dv32[c6_i251];
                }

                c6_updateDataWrittenToVector(chartInstance, 0U);
                c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c6_i252 = 0; c6_i252 < 256; c6_i252++) {
                  c6_g_u[c6_i252] = c6_poseBML[c6_i252];
                }

                c6_g_y = NULL;
                sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c6_g_y);
                _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -105);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 59);
                if (CV_EML_IF(1, 1, 7, c6_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 60);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 111);
                  c6_g_encStr2Arr(chartInstance, c6_dv32);
                  for (c6_i253 = 0; c6_i253 < 256; c6_i253++) {
                    c6_poseBML[c6_i253] = c6_dv32[c6_i253];
                  }

                  c6_updateDataWrittenToVector(chartInstance, 0U);
                  c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c6_i254 = 0; c6_i254 < 256; c6_i254++) {
                    c6_h_u[c6_i254] = c6_poseBML[c6_i254];
                  }

                  c6_h_y = NULL;
                  sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c6_h_y);
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 62);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, 111);
                  c6_g_encStr2Arr(chartInstance, c6_dv32);
                  for (c6_i255 = 0; c6_i255 < 256; c6_i255++) {
                    c6_poseBML[c6_i255] = c6_dv32[c6_i255];
                  }

                  c6_updateDataWrittenToVector(chartInstance, 0U);
                  c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 9U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c6_i256 = 0; c6_i256 < 256; c6_i256++) {
                    c6_i_u[c6_i256] = c6_poseBML[c6_i256];
                  }

                  c6_i_y = NULL;
                  sf_mex_assign(&c6_i_y, sf_mex_create("y", c6_i_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c6_i_y);
                  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -111);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c6_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_boredGazec6_ARP_02_RPSsmile_GloveAtomic
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c6_bmlID, real_T c6_gazeBML[256])
{
  uint32_T c6_debug_family_var_map[22];
  boolean_T c6_aVarTruthTableCondition_1;
  boolean_T c6_aVarTruthTableCondition_2;
  boolean_T c6_aVarTruthTableCondition_3;
  boolean_T c6_aVarTruthTableCondition_4;
  boolean_T c6_aVarTruthTableCondition_5;
  boolean_T c6_aVarTruthTableCondition_6;
  boolean_T c6_aVarTruthTableCondition_7;
  boolean_T c6_aVarTruthTableCondition_8;
  boolean_T c6_aVarTruthTableCondition_9;
  boolean_T c6_aVarTruthTableCondition_10;
  boolean_T c6_aVarTruthTableCondition_11;
  boolean_T c6_aVarTruthTableCondition_12;
  boolean_T c6_aVarTruthTableCondition_13;
  boolean_T c6_aVarTruthTableCondition_14;
  boolean_T c6_aVarTruthTableCondition_15;
  boolean_T c6_aVarTruthTableCondition_16;
  boolean_T c6_aVarTruthTableCondition_17;
  boolean_T c6_aVarTruthTableCondition_18;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_dv34[256];
  int32_T c6_i257;
  int32_T c6_i258;
  real_T c6_u[256];
  const mxArray *c6_y = NULL;
  int32_T c6_i259;
  int32_T c6_i260;
  real_T c6_b_u[256];
  const mxArray *c6_b_y = NULL;
  int32_T c6_i261;
  int32_T c6_i262;
  real_T c6_c_u[256];
  const mxArray *c6_c_y = NULL;
  int32_T c6_i263;
  int32_T c6_i264;
  real_T c6_d_u[256];
  const mxArray *c6_d_y = NULL;
  int32_T c6_i265;
  int32_T c6_i266;
  real_T c6_e_u[256];
  const mxArray *c6_e_y = NULL;
  int32_T c6_i267;
  int32_T c6_i268;
  real_T c6_f_u[256];
  const mxArray *c6_f_y = NULL;
  int32_T c6_i269;
  int32_T c6_i270;
  real_T c6_g_u[256];
  const mxArray *c6_g_y = NULL;
  int32_T c6_i271;
  int32_T c6_i272;
  real_T c6_h_u[256];
  const mxArray *c6_h_y = NULL;
  int32_T c6_i273;
  int32_T c6_i274;
  real_T c6_i_u[256];
  const mxArray *c6_i_y = NULL;
  int32_T c6_i275;
  int32_T c6_i276;
  real_T c6_j_u[256];
  const mxArray *c6_j_y = NULL;
  int32_T c6_i277;
  int32_T c6_i278;
  real_T c6_k_u[256];
  const mxArray *c6_k_y = NULL;
  int32_T c6_i279;
  int32_T c6_i280;
  real_T c6_l_u[256];
  const mxArray *c6_l_y = NULL;
  int32_T c6_i281;
  int32_T c6_i282;
  real_T c6_m_u[256];
  const mxArray *c6_m_y = NULL;
  int32_T c6_i283;
  int32_T c6_i284;
  real_T c6_n_u[256];
  const mxArray *c6_n_y = NULL;
  int32_T c6_i285;
  int32_T c6_i286;
  real_T c6_o_u[256];
  const mxArray *c6_o_y = NULL;
  int32_T c6_i287;
  int32_T c6_i288;
  real_T c6_p_u[256];
  const mxArray *c6_p_y = NULL;
  int32_T c6_i289;
  int32_T c6_i290;
  real_T c6_q_u[256];
  const mxArray *c6_q_y = NULL;
  int32_T c6_i291;
  int32_T c6_i292;
  real_T c6_r_u[256];
  const mxArray *c6_r_y = NULL;
  int32_T c6_i293;
  int32_T c6_i294;
  real_T c6_s_u[256];
  const mxArray *c6_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c6_j_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_1, 0U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_2, 1U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_3, 2U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_4, 3U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_5, 4U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_6, 5U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_7, 6U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_8, 7U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_9, 8U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_10, 9U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_11, 10U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_12, 11U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_13, 12U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_14, 13U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_15, 14U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_16, 15U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_17, 16U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_aVarTruthTableCondition_18, 17U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 18U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 19U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_bmlID, 20U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_gazeBML, 21U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 11);
  c6_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  c6_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 15);
  c6_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  c6_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  c6_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 18);
  c6_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 19);
  c6_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 20);
  c6_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  c6_aVarTruthTableCondition_1 = (c6_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  c6_aVarTruthTableCondition_2 = (c6_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 30);
  c6_aVarTruthTableCondition_3 = (c6_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 33);
  c6_aVarTruthTableCondition_4 = (c6_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 36);
  c6_aVarTruthTableCondition_5 = (c6_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 39);
  c6_aVarTruthTableCondition_6 = (c6_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 42);
  c6_aVarTruthTableCondition_7 = (c6_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 45);
  c6_aVarTruthTableCondition_8 = (c6_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 48);
  c6_aVarTruthTableCondition_9 = (c6_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 51);
  c6_aVarTruthTableCondition_10 = (c6_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 54);
  c6_aVarTruthTableCondition_11 = (c6_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 57);
  c6_aVarTruthTableCondition_12 = (c6_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 60);
  c6_aVarTruthTableCondition_13 = (c6_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 63);
  c6_aVarTruthTableCondition_14 = (c6_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 66);
  c6_aVarTruthTableCondition_15 = (c6_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 69);
  c6_aVarTruthTableCondition_16 = (c6_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 72);
  c6_aVarTruthTableCondition_17 = (c6_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 75);
  c6_aVarTruthTableCondition_18 = (c6_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c6_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 78);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 121);
    c6_h_encStr2Arr(chartInstance, c6_dv34);
    for (c6_i257 = 0; c6_i257 < 256; c6_i257++) {
      c6_gazeBML[c6_i257] = c6_dv34[c6_i257];
    }

    c6_updateDataWrittenToVector(chartInstance, 1U);
    c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
    sf_mex_printf("%s =\\n", "gazeBML");
    for (c6_i258 = 0; c6_i258 < 256; c6_i258++) {
      c6_u[c6_i258] = c6_gazeBML[c6_i258];
    }

    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_y);
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -121);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c6_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, MAX_int8_T);
      c6_i_encStr2Arr(chartInstance, c6_dv34);
      for (c6_i259 = 0; c6_i259 < 256; c6_i259++) {
        c6_gazeBML[c6_i259] = c6_dv34[c6_i259];
      }

      c6_updateDataWrittenToVector(chartInstance, 1U);
      c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
      sf_mex_printf("%s =\\n", "gazeBML");
      for (c6_i260 = 0; c6_i260 < 256; c6_i260++) {
        c6_b_u[c6_i260] = c6_gazeBML[c6_i260];
      }

      c6_b_y = NULL;
      sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_b_y);
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c6_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 82);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 133U);
        c6_j_encStr2Arr(chartInstance, c6_dv34);
        for (c6_i261 = 0; c6_i261 < 256; c6_i261++) {
          c6_gazeBML[c6_i261] = c6_dv34[c6_i261];
        }

        c6_updateDataWrittenToVector(chartInstance, 1U);
        c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
        sf_mex_printf("%s =\\n", "gazeBML");
        for (c6_i262 = 0; c6_i262 < 256; c6_i262++) {
          c6_c_u[c6_i262] = c6_gazeBML[c6_i262];
        }

        c6_c_y = NULL;
        sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c6_c_y);
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -133);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c6_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 84);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 139U);
          c6_k_encStr2Arr(chartInstance, c6_dv34);
          for (c6_i263 = 0; c6_i263 < 256; c6_i263++) {
            c6_gazeBML[c6_i263] = c6_dv34[c6_i263];
          }

          c6_updateDataWrittenToVector(chartInstance, 1U);
          c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
          sf_mex_printf("%s =\\n", "gazeBML");
          for (c6_i264 = 0; c6_i264 < 256; c6_i264++) {
            c6_d_u[c6_i264] = c6_gazeBML[c6_i264];
          }

          c6_d_y = NULL;
          sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c6_d_y);
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -139);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c6_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 86);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 145U);
            c6_l_encStr2Arr(chartInstance, c6_dv34);
            for (c6_i265 = 0; c6_i265 < 256; c6_i265++) {
              c6_gazeBML[c6_i265] = c6_dv34[c6_i265];
            }

            c6_updateDataWrittenToVector(chartInstance, 1U);
            c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
            sf_mex_printf("%s =\\n", "gazeBML");
            for (c6_i266 = 0; c6_i266 < 256; c6_i266++) {
              c6_e_u[c6_i266] = c6_gazeBML[c6_i266];
            }

            c6_e_y = NULL;
            sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c6_e_y);
            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -145);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c6_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 88);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 151U);
              c6_m_encStr2Arr(chartInstance, c6_dv34);
              for (c6_i267 = 0; c6_i267 < 256; c6_i267++) {
                c6_gazeBML[c6_i267] = c6_dv34[c6_i267];
              }

              c6_updateDataWrittenToVector(chartInstance, 1U);
              c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
              sf_mex_printf("%s =\\n", "gazeBML");
              for (c6_i268 = 0; c6_i268 < 256; c6_i268++) {
                c6_f_u[c6_i268] = c6_gazeBML[c6_i268];
              }

              c6_f_y = NULL;
              sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c6_f_y);
              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -151);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c6_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 90);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 157U);
                c6_n_encStr2Arr(chartInstance, c6_dv34);
                for (c6_i269 = 0; c6_i269 < 256; c6_i269++) {
                  c6_gazeBML[c6_i269] = c6_dv34[c6_i269];
                }

                c6_updateDataWrittenToVector(chartInstance, 1U);
                c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                sf_mex_printf("%s =\\n", "gazeBML");
                for (c6_i270 = 0; c6_i270 < 256; c6_i270++) {
                  c6_g_u[c6_i270] = c6_gazeBML[c6_i270];
                }

                c6_g_y = NULL;
                sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c6_g_y);
                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -157);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c6_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 92);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 163U);
                  c6_o_encStr2Arr(chartInstance, c6_dv34);
                  for (c6_i271 = 0; c6_i271 < 256; c6_i271++) {
                    c6_gazeBML[c6_i271] = c6_dv34[c6_i271];
                  }

                  c6_updateDataWrittenToVector(chartInstance, 1U);
                  c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c6_i272 = 0; c6_i272 < 256; c6_i272++) {
                    c6_h_u[c6_i272] = c6_gazeBML[c6_i272];
                  }

                  c6_h_y = NULL;
                  sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c6_h_y);
                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -163);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c6_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 94);
                    CV_EML_FCN(0, 9);
                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 169U);
                    c6_p_encStr2Arr(chartInstance, c6_dv34);
                    for (c6_i273 = 0; c6_i273 < 256; c6_i273++) {
                      c6_gazeBML[c6_i273] = c6_dv34[c6_i273];
                    }

                    c6_updateDataWrittenToVector(chartInstance, 1U);
                    c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c6_i274 = 0; c6_i274 < 256; c6_i274++) {
                      c6_i_u[c6_i274] = c6_gazeBML[c6_i274];
                    }

                    c6_i_y = NULL;
                    sf_mex_assign(&c6_i_y, sf_mex_create("y", c6_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c6_i_y);
                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -169);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c6_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 96);
                      CV_EML_FCN(0, 10);
                      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 175U);
                      c6_q_encStr2Arr(chartInstance, c6_dv34);
                      for (c6_i275 = 0; c6_i275 < 256; c6_i275++) {
                        c6_gazeBML[c6_i275] = c6_dv34[c6_i275];
                      }

                      c6_updateDataWrittenToVector(chartInstance, 1U);
                      c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c6_i276 = 0; c6_i276 < 256; c6_i276++) {
                        c6_j_u[c6_i276] = c6_gazeBML[c6_i276];
                      }

                      c6_j_y = NULL;
                      sf_mex_assign(&c6_j_y, sf_mex_create("y", c6_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c6_j_y);
                      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c6_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 98);
                        CV_EML_FCN(0, 11);
                        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 181U);
                        c6_r_encStr2Arr(chartInstance, c6_dv34);
                        for (c6_i277 = 0; c6_i277 < 256; c6_i277++) {
                          c6_gazeBML[c6_i277] = c6_dv34[c6_i277];
                        }

                        c6_updateDataWrittenToVector(chartInstance, 1U);
                        c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c6_i278 = 0; c6_i278 < 256; c6_i278++) {
                          c6_k_u[c6_i278] = c6_gazeBML[c6_i278];
                        }

                        c6_k_y = NULL;
                        sf_mex_assign(&c6_k_y, sf_mex_create("y", c6_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c6_k_y);
                        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c6_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 100);
                          CV_EML_FCN(0, 12);
                          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 187U);
                          c6_s_encStr2Arr(chartInstance, c6_dv34);
                          for (c6_i279 = 0; c6_i279 < 256; c6_i279++) {
                            c6_gazeBML[c6_i279] = c6_dv34[c6_i279];
                          }

                          c6_updateDataWrittenToVector(chartInstance, 1U);
                          c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c6_i280 = 0; c6_i280 < 256; c6_i280++) {
                            c6_l_u[c6_i280] = c6_gazeBML[c6_i280];
                          }

                          c6_l_y = NULL;
                          sf_mex_assign(&c6_l_y, sf_mex_create("y", c6_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c6_l_y);
                          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -187);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c6_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 102);
                            CV_EML_FCN(0, 13);
                            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 193U);
                            c6_t_encStr2Arr(chartInstance, c6_dv34);
                            for (c6_i281 = 0; c6_i281 < 256; c6_i281++) {
                              c6_gazeBML[c6_i281] = c6_dv34[c6_i281];
                            }

                            c6_updateDataWrittenToVector(chartInstance, 1U);
                            c6_errorIfDataNotWrittenToFcn(chartInstance, 1U, 11U);
                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c6_i282 = 0; c6_i282 < 256; c6_i282++) {
                              c6_m_u[c6_i282] = c6_gazeBML[c6_i282];
                            }

                            c6_m_y = NULL;
                            sf_mex_assign(&c6_m_y, sf_mex_create("y", c6_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c6_m_y);
                            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -193);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c6_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 104);
                              CV_EML_FCN(0, 14);
                              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 199U);
                              c6_u_encStr2Arr(chartInstance, c6_dv34);
                              for (c6_i283 = 0; c6_i283 < 256; c6_i283++) {
                                c6_gazeBML[c6_i283] = c6_dv34[c6_i283];
                              }

                              c6_updateDataWrittenToVector(chartInstance, 1U);
                              c6_errorIfDataNotWrittenToFcn(chartInstance, 1U,
                                11U);
                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c6_i284 = 0; c6_i284 < 256; c6_i284++) {
                                c6_n_u[c6_i284] = c6_gazeBML[c6_i284];
                              }

                              c6_n_y = NULL;
                              sf_mex_assign(&c6_n_y, sf_mex_create("y", c6_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c6_n_y);
                              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -199);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c6_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 106);
                                CV_EML_FCN(0, 15);
                                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                              205U);
                                c6_v_encStr2Arr(chartInstance, c6_dv34);
                                for (c6_i285 = 0; c6_i285 < 256; c6_i285++) {
                                  c6_gazeBML[c6_i285] = c6_dv34[c6_i285];
                                }

                                c6_updateDataWrittenToVector(chartInstance, 1U);
                                c6_errorIfDataNotWrittenToFcn(chartInstance, 1U,
                                  11U);
                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c6_i286 = 0; c6_i286 < 256; c6_i286++) {
                                  c6_o_u[c6_i286] = c6_gazeBML[c6_i286];
                                }

                                c6_o_y = NULL;
                                sf_mex_assign(&c6_o_y, sf_mex_create("y", c6_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c6_o_y);
                                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                              -205);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 107);
                                if (CV_EML_IF(0, 1, 15,
                                              c6_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 16);
                                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                211U);
                                  c6_w_encStr2Arr(chartInstance, c6_dv34);
                                  for (c6_i287 = 0; c6_i287 < 256; c6_i287++) {
                                    c6_gazeBML[c6_i287] = c6_dv34[c6_i287];
                                  }

                                  c6_updateDataWrittenToVector(chartInstance, 1U);
                                  c6_errorIfDataNotWrittenToFcn(chartInstance,
                                    1U, 11U);
                                  sf_mex_printf("%s =\\n", "gazeBML");
                                  for (c6_i288 = 0; c6_i288 < 256; c6_i288++) {
                                    c6_p_u[c6_i288] = c6_gazeBML[c6_i288];
                                  }

                                  c6_p_y = NULL;
                                  sf_mex_assign(&c6_p_y, sf_mex_create("y",
                                    c6_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c6_p_y);
                                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                -211);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c6_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 19);
                                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                  229U);
                                    c6_x_encStr2Arr(chartInstance, c6_dv34);
                                    for (c6_i289 = 0; c6_i289 < 256; c6_i289++)
                                    {
                                      c6_gazeBML[c6_i289] = c6_dv34[c6_i289];
                                    }

                                    c6_updateDataWrittenToVector(chartInstance,
                                      1U);
                                    c6_errorIfDataNotWrittenToFcn(chartInstance,
                                      1U, 11U);
                                    sf_mex_printf("%s =\\n", "gazeBML");
                                    for (c6_i290 = 0; c6_i290 < 256; c6_i290++)
                                    {
                                      c6_q_u[c6_i290] = c6_gazeBML[c6_i290];
                                    }

                                    c6_q_y = NULL;
                                    sf_mex_assign(&c6_q_y, sf_mex_create("y",
                                      c6_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c6_q_y);
                                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                  -229);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c6_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 26);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
                                                    271);
                                      c6_y_encStr2Arr(chartInstance, c6_dv34);
                                      for (c6_i291 = 0; c6_i291 < 256; c6_i291++)
                                      {
                                        c6_gazeBML[c6_i291] = c6_dv34[c6_i291];
                                      }

                                      c6_updateDataWrittenToVector(chartInstance,
                                        1U);
                                      c6_errorIfDataNotWrittenToFcn
                                        (chartInstance, 1U, 11U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c6_i292 = 0; c6_i292 < 256; c6_i292++)
                                      {
                                        c6_r_u[c6_i292] = c6_gazeBML[c6_i292];
                                      }

                                      c6_r_y = NULL;
                                      sf_mex_assign(&c6_r_y, sf_mex_create("y",
                                        c6_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c6_r_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
                                                    -271);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 1);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
                                                    121);
                                      c6_h_encStr2Arr(chartInstance, c6_dv34);
                                      for (c6_i293 = 0; c6_i293 < 256; c6_i293++)
                                      {
                                        c6_gazeBML[c6_i293] = c6_dv34[c6_i293];
                                      }

                                      c6_updateDataWrittenToVector(chartInstance,
                                        1U);
                                      c6_errorIfDataNotWrittenToFcn
                                        (chartInstance, 1U, 11U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c6_i294 = 0; c6_i294 < 256; c6_i294++)
                                      {
                                        c6_s_u[c6_i294] = c6_gazeBML[c6_i294];
                                      }

                                      c6_s_y = NULL;
                                      sf_mex_assign(&c6_s_y, sf_mex_create("y",
                                        c6_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c6_s_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c6_sfEvent,
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

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c6_sendBML(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c6_b_sendBML(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void sf_exported_user_c6_ARP_02_RPSsmile_GloveAtomic_boredGaze(SimStruct *c6_S,
  real_T c6_bmlID, real_T c6_gazeBML[256])
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_boredGazec6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_bmlID, c6_gazeBML);
}

void sf_exported_user_c6_ARP_02_RPSsmile_GloveAtomic_idlePose(SimStruct *c6_S,
  real_T c6_bmlID, real_T c6_poseBML[256])
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  c6_idlePosec6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_bmlID, c6_poseBML);
}

void sf_exported_user_c6_ARP_02_RPSsmile_GloveAtomic_sendBML(SimStruct *c6_S,
  real_T c6_arg[256])
{
  int32_T c6_i295;
  real_T c6_b_arg[256];
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c6_S))->instanceInfo
    )->chartInstance;
  for (c6_i295 = 0; c6_i295 < 256; c6_i295++) {
    c6_b_arg[c6_i295] = c6_arg[c6_i295];
  }

  c6_sendBMLc6_ARP_02_RPSsmile_GloveAtomic(chartInstance, c6_b_arg);
}

static const mxArray *c6_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int8_T c6_e_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int8_T c6_y;
  int8_T c6_i296;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i296, 1, 2, 0U, 0, 0U, 0);
  c6_y = c6_i296;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_secs;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int8_T c6_y;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_secs = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_secs), &c6_thisId);
  sf_mex_destroy(&c6_secs);
  *(int8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_f_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i297;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i297, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i297;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  uint8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint8_T c6_g_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_tp_stateInitial, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_stateInitial),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_stateInitial);
  return c6_y;
}

static uint8_T c6_h_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u3;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u3, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u3;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_tp_stateInitial;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c6_b_tp_stateInitial = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_stateInitial),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_stateInitial);
  *(uint8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint32_T c6_i_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_method, const char_T *c6_identifier)
{
  uint32_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_method),
    &c6_thisId);
  sf_mex_destroy(&c6_b_method);
  return c6_y;
}

static uint32_T c6_j_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_y;
  uint32_T c6_u4;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_method_not_empty = false;
  } else {
    chartInstance->c6_method_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u4, 1, 7, 0U, 0, 0U, 0);
    c6_y = c6_u4;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static uint32_T c6_k_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_d_state, const char_T *c6_identifier)
{
  uint32_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_state), &c6_thisId);
  sf_mex_destroy(&c6_d_state);
  return c6_y;
}

static uint32_T c6_l_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_y;
  uint32_T c6_u5;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_state_not_empty = false;
  } else {
    chartInstance->c6_state_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u5, 1, 7, 0U, 0, 0U, 0);
    c6_y = c6_u5;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_m_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_d_state, const char_T *c6_identifier,
  uint32_T c6_y[625])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_state), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_d_state);
}

static void c6_n_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  uint32_T c6_y[625])
{
  uint32_T c6_uv3[625];
  int32_T c6_i298;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_c_state_not_empty = false;
  } else {
    chartInstance->c6_c_state_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c6_i298 = 0; c6_i298 < 625; c6_i298++) {
      c6_y[c6_i298] = c6_uv3[c6_i298];
    }
  }

  sf_mex_destroy(&c6_u);
}

static void c6_o_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_d_state, const char_T *c6_identifier,
  uint32_T c6_y[2])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_state), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_d_state);
}

static void c6_p_emlrt_marshallIn(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  uint32_T c6_y[2])
{
  uint32_T c6_uv4[2];
  int32_T c6_i299;
  if (mxIsEmpty(c6_u)) {
    chartInstance->c6_b_state_not_empty = false;
  } else {
    chartInstance->c6_b_state_not_empty = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c6_i299 = 0; c6_i299 < 2; c6_i299++) {
      c6_y[c6_i299] = c6_uv4[c6_i299];
    }
  }

  sf_mex_destroy(&c6_u);
}

static uint32_T c6_q_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_temporalCounter_i1, const char_T *c6_identifier)
{
  uint32_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_temporalCounter_i1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_temporalCounter_i1);
  return c6_y;
}

static uint32_T c6_r_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_y;
  uint32_T c6_u6;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u6, 1, 7, 0U, 0, 0U, 0);
  c6_y = c6_u6;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static const mxArray *c6_s_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier)
{
  const mxArray *c6_y = NULL;
  emlrtMsgIdentifier c6_thisId;
  c6_y = NULL;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  sf_mex_assign(&c6_y, c6_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), false);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_t_emlrt_marshallIn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), false);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_updateDataWrittenToVector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_vectorIndex)
{
  (void)chartInstance;
  c6_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c6_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c6_errorIfDataNotWrittenToFcn
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_vectorIndex, uint32_T c6_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c6_dataNumber, c6_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c6_vectorIndex, 0, 1, 1,
    0)]);
}

static void c6_b_twister_state_vector
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_mt[625], real_T c6_seed)
{
  real_T c6_d5;
  uint32_T c6_u7;
  uint32_T c6_r;
  int32_T c6_mti;
  real_T c6_b_mti;
  real_T c6_d6;
  uint32_T c6_u8;
  (void)chartInstance;
  c6_d5 = c6_seed;
  if (c6_d5 < 4.294967296E+9) {
    if (c6_d5 >= 0.0) {
      c6_u7 = (uint32_T)c6_d5;
    } else {
      c6_u7 = 0U;
    }
  } else if (c6_d5 >= 4.294967296E+9) {
    c6_u7 = MAX_uint32_T;
  } else {
    c6_u7 = 0U;
  }

  c6_r = c6_u7;
  c6_mt[0] = c6_r;
  for (c6_mti = 0; c6_mti < 623; c6_mti++) {
    c6_b_mti = 2.0 + (real_T)c6_mti;
    c6_d6 = muDoubleScalarRound(c6_b_mti - 1.0);
    if (c6_d6 < 4.294967296E+9) {
      if (c6_d6 >= 0.0) {
        c6_u8 = (uint32_T)c6_d6;
      } else {
        c6_u8 = 0U;
      }
    } else if (c6_d6 >= 4.294967296E+9) {
      c6_u8 = MAX_uint32_T;
    } else {
      c6_u8 = 0U;
    }

    c6_r = (c6_r ^ c6_r >> 30U) * 1812433253U + c6_u8;
    c6_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c6_b_mti), 1, 625, 1, 0) - 1] = c6_r;
  }

  c6_mt[624] = 624U;
}

static real_T c6_c_eml_rand_mt19937ar
  (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c6_d_state[625])
{
  int32_T c6_i300;
  uint32_T c6_u[2];
  int32_T c6_j;
  real_T c6_b_j;
  uint32_T c6_mti;
  int32_T c6_kk;
  real_T c6_b_kk;
  uint32_T c6_y;
  uint32_T c6_b_y;
  uint32_T c6_c_y;
  int32_T c6_c_kk;
  uint32_T c6_d_y;
  uint32_T c6_e_y;
  uint32_T c6_f_y;
  uint32_T c6_g_y;
  real_T c6_b_r;
  boolean_T c6_b1;
  boolean_T c6_isvalid;
  int32_T c6_k;
  int32_T c6_a;
  int32_T c6_b_a;
  real_T c6_d7;
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
    for (c6_i300 = 0; c6_i300 < 2; c6_i300++) {
      c6_u[c6_i300] = 0U;
    }

    for (c6_j = 0; c6_j < 2; c6_j++) {
      c6_b_j = 1.0 + (real_T)c6_j;
      c6_mti = c6_d_state[624] + 1U;
      if ((real_T)c6_mti >= 625.0) {
        for (c6_kk = 0; c6_kk < 227; c6_kk++) {
          c6_b_kk = 1.0 + (real_T)c6_kk;
          c6_y = (c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c6_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c6_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c6_b_y = c6_y;
          c6_c_y = c6_b_y;
          if ((real_T)(c6_c_y & 1U) == 0.0) {
            c6_c_y >>= 1U;
          } else {
            c6_c_y = c6_c_y >> 1U ^ 2567483615U;
          }

          c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c6_b_kk), 1, 625, 1, 0) - 1] =
            c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c6_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c6_c_y;
        }

        for (c6_c_kk = 0; c6_c_kk < 396; c6_c_kk++) {
          c6_b_kk = 228.0 + (real_T)c6_c_kk;
          c6_y = (c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c6_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c6_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c6_d_y = c6_y;
          c6_e_y = c6_d_y;
          if ((real_T)(c6_e_y & 1U) == 0.0) {
            c6_e_y >>= 1U;
          } else {
            c6_e_y = c6_e_y >> 1U ^ 2567483615U;
          }

          c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c6_b_kk), 1, 625, 1, 0) - 1] =
            c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c6_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c6_e_y;
        }

        c6_y = (c6_d_state[623] & 2147483648U) | (c6_d_state[0] & 2147483647U);
        c6_f_y = c6_y;
        c6_g_y = c6_f_y;
        if ((real_T)(c6_g_y & 1U) == 0.0) {
          c6_g_y >>= 1U;
        } else {
          c6_g_y = c6_g_y >> 1U ^ 2567483615U;
        }

        c6_d_state[623] = c6_d_state[396] ^ c6_g_y;
        c6_mti = 1U;
      }

      c6_y = c6_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mti), 1, 625, 1, 0)
        - 1];
      c6_d_state[624] = c6_mti;
      c6_y ^= c6_y >> 11U;
      c6_y ^= c6_y << 7U & 2636928640U;
      c6_y ^= c6_y << 15U & 4022730752U;
      c6_y ^= c6_y >> 18U;
      c6_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c6_b_j), 1, 2, 1, 0) - 1] = c6_y;
    }

    c6_u[0] >>= 5U;
    c6_u[1] >>= 6U;
    c6_b_r = 1.1102230246251565E-16 * ((real_T)c6_u[0] * 6.7108864E+7 + (real_T)
      c6_u[1]);
    if (c6_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c6_d_state[624] >= 1.0) {
        if ((real_T)c6_d_state[624] < 625.0) {
          c6_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c6_b1 = false;
      }

      c6_isvalid = c6_b1;
      if (c6_isvalid) {
        c6_isvalid = false;
        c6_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c6_k < 625)) {
          if ((real_T)c6_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c6_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c6_a = c6_k;
            c6_b_a = c6_a + 1;
            c6_k = c6_b_a;
          } else {
            c6_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c6_isvalid) {
        c6_eml_error(chartInstance);
        c6_d7 = 5489.0;
        c6_b_twister_state_vector(chartInstance, c6_d_state, c6_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c6_b_r;
}

static real_T c6_get_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c6_b);
  if (chartInstance->c6_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#378) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_BOREDOMT_address;
}

static void c6_set_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c6_b);
  if (chartInstance->c6_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#378) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_BOREDOMT_address = c6_c;
}

static real_T *c6_access_BOREDOMT(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c6_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#378) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_BOREDOMT_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c6_c;
}

static real_T c6_get_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c6_b);
  if (chartInstance->c6_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#382) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_b_address;
}

static void c6_set_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c6_b);
  if (chartInstance->c6_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#382) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_b_address = c6_c;
}

static real_T *c6_access_b(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c6_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#382) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_b_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c6_c;
}

static real_T c6_get_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c6_b);
  if (chartInstance->c6_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#377) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_bored_address;
}

static void c6_set_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c6_b);
  if (chartInstance->c6_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#377) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_bored_address = c6_c;
}

static real_T *c6_access_bored(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c6_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#377) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_bored_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c6_c;
}

static real_T c6_get_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c6_b);
  if (chartInstance->c6_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#381) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_pose_address;
}

static void c6_set_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c6_b);
  if (chartInstance->c6_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#381) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_pose_address = c6_c;
}

static real_T *c6_access_pose(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c6_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#381) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_pose_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c6_c;
}

static real_T c6_get_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c6_b);
  if (chartInstance->c6_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#383) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_randomD_address;
}

static void c6_set_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c6_b);
  if (chartInstance->c6_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#383) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_randomD_address = c6_c;
}

static real_T *c6_access_randomD(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c6_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#383) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_randomD_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c6_c;
}

static real_T c6_get_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c6_b);
  if (chartInstance->c6_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#379) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_randomG_address;
}

static void c6_set_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c6_b);
  if (chartInstance->c6_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#379) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_randomG_address = c6_c;
}

static real_T *c6_access_randomG(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c6_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#379) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_randomG_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c6_c;
}

static real_T c6_get_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c6_b);
  if (chartInstance->c6_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#380) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c6_randomP_address;
}

static void c6_set_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c6_b, real_T c6_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c6_b);
  if (chartInstance->c6_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#380) in the initialization routine of the chart.\n");
  }

  *chartInstance->c6_randomP_address = c6_c;
}

static real_T *c6_access_randomP(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c6_b)
{
  real_T *c6_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c6_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#380) in the initialization routine of the chart.\n");
  }

  c6_c = chartInstance->c6_randomP_address;
  if (c6_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c6_c;
}

static void init_dsm_address_info(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c6_BOREDOMT_address, &chartInstance->c6_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c6_b_address, &chartInstance->c6_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c6_bored_address, &chartInstance->c6_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c6_pose_address, &chartInstance->c6_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomD", (void **)
    &chartInstance->c6_randomD_address, &chartInstance->c6_randomD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomG", (void **)
    &chartInstance->c6_randomG_address, &chartInstance->c6_randomG_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c6_randomP_address, &chartInstance->c6_randomP_index);
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

void sf_c6_ARP_02_RPSsmile_GloveAtomic_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2295804573U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2473788983U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2783068531U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2057204107U);
}

mxArray *sf_c6_ARP_02_RPSsmile_GloveAtomic_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xCCPxXQromW1WGgUJ4DUWE");
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

mxArray *sf_c6_ARP_02_RPSsmile_GloveAtomic_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_ARP_02_RPSsmile_GloveAtomic_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_ARP_02_RPSsmile_GloveAtomic(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c6_ARP_02_RPSsmile_GloveAtomic\",},{M[9],M[0],T\"is_c6_ARP_02_RPSsmile_GloveAtomic\",},{M[11],M[23],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[13 14 15],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_ARP_02_RPSsmile_GloveAtomic_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
           6,
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
        init_script_number_translation
          (_ARP_02_RPSsmile_GloveAtomicMachineNumber_,chartInstance->chartNumber,
           chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
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

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"idlePosec6_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             1353);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1353,-1,1569);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1569,-1,1800);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1800,-1,1935);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1935,-1,2226);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",2226,-1,2518);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2518,-1,2812);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",2812,-1,3107);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",3107,-1,3271);
        _SFD_CV_INIT_EML_IF(1,1,0,787,817,848,1351);
        _SFD_CV_INIT_EML_IF(1,1,1,848,882,913,1351);
        _SFD_CV_INIT_EML_IF(1,1,2,913,947,978,1351);
        _SFD_CV_INIT_EML_IF(1,1,3,978,1012,1043,1351);
        _SFD_CV_INIT_EML_IF(1,1,4,1043,1077,1108,1351);
        _SFD_CV_INIT_EML_IF(1,1,5,1108,1142,1173,1351);
        _SFD_CV_INIT_EML_IF(1,1,6,1173,1207,1238,1351);
        _SFD_CV_INIT_EML_IF(1,1,7,1238,1272,1303,1351);
        _SFD_CV_INIT_EML(0,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredGazec6_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             2810);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2810,-1,2996);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",2996,-1,3184);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3184,-1,3366);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3366,-1,3552);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3552,-1,3742);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3742,-1,3934);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",3934,-1,4128);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4128,-1,4324);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",4324,-1,4524);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",4524,-1,4733);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",4733,-1,4944);
        _SFD_CV_INIT_EML_FCN(0,12,"aFcnTruthTableAction_12",4944,-1,5151);
        _SFD_CV_INIT_EML_FCN(0,13,"aFcnTruthTableAction_13",5151,-1,5356);
        _SFD_CV_INIT_EML_FCN(0,14,"aFcnTruthTableAction_14",5356,-1,5553);
        _SFD_CV_INIT_EML_FCN(0,15,"aFcnTruthTableAction_15",5553,-1,5756);
        _SFD_CV_INIT_EML_FCN(0,16,"aFcnTruthTableAction_16",5756,-1,5957);
        _SFD_CV_INIT_EML_FCN(0,17,"aFcnTruthTableAction_17",5957,-1,6170);
        _SFD_CV_INIT_EML_FCN(0,18,"aFcnTruthTableAction_18",6170,-1,6385);
        _SFD_CV_INIT_EML_FCN(0,19,"aFcnTruthTableAction_19",6385,-1,6599);
        _SFD_CV_INIT_EML_FCN(0,20,"aFcnTruthTableAction_20",6599,-1,6812);
        _SFD_CV_INIT_EML_FCN(0,21,"aFcnTruthTableAction_21",6812,-1,7029);
        _SFD_CV_INIT_EML_FCN(0,22,"aFcnTruthTableAction_22",7029,-1,7248);
        _SFD_CV_INIT_EML_FCN(0,23,"aFcnTruthTableAction_23",7248,-1,7469);
        _SFD_CV_INIT_EML_FCN(0,24,"aFcnTruthTableAction_24",7469,-1,7692);
        _SFD_CV_INIT_EML_FCN(0,25,"aFcnTruthTableAction_25",7692,-1,7858);
        _SFD_CV_INIT_EML_FCN(0,26,"aFcnTruthTableAction_26",7858,-1,8155);
        _SFD_CV_INIT_EML_IF(0,1,0,1576,1606,1637,2808);
        _SFD_CV_INIT_EML_IF(0,1,1,1637,1671,1702,2808);
        _SFD_CV_INIT_EML_IF(0,1,2,1702,1736,1767,2808);
        _SFD_CV_INIT_EML_IF(0,1,3,1767,1801,1832,2808);
        _SFD_CV_INIT_EML_IF(0,1,4,1832,1866,1897,2808);
        _SFD_CV_INIT_EML_IF(0,1,5,1897,1931,1962,2808);
        _SFD_CV_INIT_EML_IF(0,1,6,1962,1996,2027,2808);
        _SFD_CV_INIT_EML_IF(0,1,7,2027,2061,2092,2808);
        _SFD_CV_INIT_EML_IF(0,1,8,2092,2126,2157,2808);
        _SFD_CV_INIT_EML_IF(0,1,9,2157,2192,2224,2808);
        _SFD_CV_INIT_EML_IF(0,1,10,2224,2259,2291,2808);
        _SFD_CV_INIT_EML_IF(0,1,11,2291,2326,2358,2808);
        _SFD_CV_INIT_EML_IF(0,1,12,2358,2393,2425,2808);
        _SFD_CV_INIT_EML_IF(0,1,13,2425,2460,2492,2808);
        _SFD_CV_INIT_EML_IF(0,1,14,2492,2527,2559,2808);
        _SFD_CV_INIT_EML_IF(0,1,15,2559,2594,2626,2808);
        _SFD_CV_INIT_EML_IF(0,1,16,2626,2661,2693,2808);
        _SFD_CV_INIT_EML_IF(0,1,17,2693,2728,2760,2808);
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
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c6_bored_address);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c6_BOREDOMT_address);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_randomG_address);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c6_randomP_address);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c6_pose_address);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c6_b_address);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c6_randomD_address);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GloveAtomicMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "2CsMdF7dS3NFKU2u8eaGgD";
}

static void sf_opaque_initialize_c6_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
  initialize_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  enable_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  disable_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  sf_gateway_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_ARP_02_RPSsmile_GloveAtomic();/* state var info */
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

extern void sf_internal_set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_ARP_02_RPSsmile_GloveAtomic();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c6_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveAtomic_optimization_info();
    }

    finalize_c6_ARP_02_RPSsmile_GloveAtomic
      ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_ARP_02_RPSsmile_GloveAtomic
    ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
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
    initialize_params_c6_ARP_02_RPSsmile_GloveAtomic
      ((SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSsmile_GloveAtomic_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,6,1);
    if (chartIsInlinable) {
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2888501276U));
  ssSetChecksum1(S,(1989733347U));
  ssSetChecksum2(S,(877787440U));
  ssSetChecksum3(S,(3961977178U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)utMalloc
    (sizeof(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_ARP_02_RPSsmile_GloveAtomic;
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

void c6_ARP_02_RPSsmile_GloveAtomic_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_ARP_02_RPSsmile_GloveAtomic_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
