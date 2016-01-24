/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_GazeWalk_sfun.h"
#include "c3_ARP_02_GazeWalk.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_GazeWalk_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_checkUser                ((uint8_T)1U)
#define c3_IN_stateBoredGaze           ((uint8_T)2U)
#define c3_IN_stateBoredPose           ((uint8_T)3U)
#define c3_IN_stateBoredPose1          ((uint8_T)4U)
#define c3_IN_stateCheckUser           ((uint8_T)5U)
#define c3_IN_stateCheckUser2          ((uint8_T)6U)
#define c3_IN_stateCoping              ((uint8_T)7U)
#define c3_IN_stateIdle                ((uint8_T)8U)
#define c3_IN_stateInitiate            ((uint8_T)9U)
#define c3_IN_stateIntract             ((uint8_T)10U)
#define c3_IN_stateInvaded             ((uint8_T)11U)
#define c3_IN_stateWalkAway            ((uint8_T)12U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c3_subchartSimStateInfo;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_h_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "poseBML", "nargin", "nargout", "bmlID" };

static const char * c3_i_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_r_debug_family_names[4] = { "mystr", "nargin", "nargout",
  "arrBML" };

static const char * c3_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_w_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "invadedBML", "nargin", "nargout", "bmlID" };

static const char * c3_x_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "bmlID", "invadedBML" };

static const char * c3_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_fb_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "poseBML", "nargin", "nargout", "bmlID" };

static const char * c3_gb_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c3_jb_debug_family_names[7] = { "c", "mystr", "nargin",
  "nargout", "x", "arrBML", "agentPosition" };

static const char * c3_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ob_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_tb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ub_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[15];

/* Function Declarations */
static void initialize_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initialize_params_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void enable_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void disable_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void set_sim_state_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void finalize_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void sf_gateway_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void initSimStructsc3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance);
static void c3_enter_atomic_stateBoredPose1(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateBoredPose1(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_enter_atomic_stateInitiate(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateBoredGaze(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_checkUser(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_enter_atomic_stateIdle(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateCheckUser(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_enter_atomic_stateCoping(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateCoping(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_enter_atomic_stateBoredPose(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateBoredPose(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_enter_atomic_stateWalkAway(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);
static void c3_stateCheckUser2(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static real_T c3_randi(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static real_T c3_rand(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625]);
static void c3_twister_state_vector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625]);
static void c3_b_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T
  *c3_r);
static void c3_eml_error(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance);
static void c3_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_b_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_c_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_d_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_e_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_f_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_g_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  char_T c3_mystr[185], real_T c3_myarr256[256]);
static void c3_h_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_i_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_j_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_k_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_l_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_m_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_n_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_o_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256]);
static void c3_cmdBML_walkOppositeUser(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, real_T c3_x, real_T c3_b_arrBML[256], real_T *c3_agentPosition);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static void c3_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[185]);
static void c3_b_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[185]);
static void c3_c_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_d_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_f_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_myarr256, const char_T *c3_identifier,
  real_T c3_y[256]);
static void c3_h_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_i_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_j_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[185]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_db_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_mb_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2]);
static void c3_k_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2]);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2]);
static const mxArray *c3_nb_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes);
static void c3_l_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_m_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_n_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_o_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_stateBoredPose1, const char_T
  *c3_identifier);
static uint8_T c3_p_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_q_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_r_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier);
static uint32_T c3_s_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint32_T c3_t_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier);
static uint32_T c3_u_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_v_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[625]);
static void c3_w_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[625]);
static void c3_x_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[2]);
static void c3_y_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[2]);
static uint32_T c3_ab_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier);
static uint32_T c3_bb_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_cb_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_b_subchartSimStateInfo, const char_T
  *c3_identifier);
static const mxArray *c3_db_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber);
static void c3_b_twister_state_vector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed);
static real_T c3_c_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625]);
static void init_dsm_address_info(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  sf_exported_auto_initc1_ARP_02_GazeWalk(chartInstance->c3_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c3_subchartSimStateInfo = NULL;
  chartInstance->c3_method_not_empty = false;
  chartInstance->c3_state_not_empty = false;
  chartInstance->c3_b_state_not_empty = false;
  chartInstance->c3_c_state_not_empty = false;
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_checkUser = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateBoredGaze = 0U;
  chartInstance->c3_tp_stateBoredPose = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateBoredPose1 = 0U;
  chartInstance->c3_tp_stateCheckUser = 0U;
  chartInstance->c3_tp_stateCheckUser2 = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateCoping = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateIdle = 0U;
  chartInstance->c3_tp_stateInitiate = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateIntract = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateInvaded = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateWalkAway = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_is_active_c3_ARP_02_GazeWalk = 0U;
  chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_presentTicks = 0U;
  chartInstance->c3_elapsedTicks = 0U;
  chartInstance->c3_previousTicks = 0U;
}

static void initialize_params_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ + 0.5);
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredGaze) {
    sf_exported_auto_enablec1_ARP_02_GazeWalk
      (chartInstance->c3_subchartSimstruct);
  }
}

static void disable_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 127U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 127U;
  }

  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredGaze) {
    sf_exported_auto_disablec1_ARP_02_GazeWalk
      (chartInstance->c3_subchartSimstruct);
  }
}

static void c3_update_debugger_state_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_ARP_02_GazeWalk == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateInitiate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_checkUser) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateIntract) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateIdle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCheckUser) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCoping) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateInvaded) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateWalkAway) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCheckUser2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_i0;
  real_T c3_f_u[256];
  const mxArray *c3_g_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint32_T c3_j_hoistedGlobal;
  uint32_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  uint32_T c3_k_hoistedGlobal;
  uint32_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  int32_T c3_i1;
  uint32_T c3_m_u[625];
  const mxArray *c3_n_y = NULL;
  int32_T c3_i2;
  uint32_T c3_n_u[2];
  const mxArray *c3_o_y = NULL;
  uint8_T c3_l_hoistedGlobal;
  uint8_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  uint8_T c3_m_hoistedGlobal;
  uint8_T c3_p_u;
  const mxArray *c3_q_y = NULL;
  uint8_T c3_n_hoistedGlobal;
  uint8_T c3_q_u;
  const mxArray *c3_r_y = NULL;
  uint32_T c3_o_hoistedGlobal;
  uint32_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  const mxArray *c3_s_u;
  const mxArray *c3_t_y = NULL;
  real_T *c3_agentPosition;
  c3_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  sf_mex_assign(&c3_subchartSimStateInfo,
                sf_exported_auto_getSimstatec1_ARP_02_GazeWalk
                (chartInstance->c3_subchartSimstruct), true);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(19, 1), false);
  c3_hoistedGlobal = *c3_agentPosition;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_BOREDOMT;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_COPINGT;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_INTERACTT;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_PERSONALSPACE;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i0 = 0; c3_i0 < 256; c3_i0++) {
    c3_f_u[c3_i0] = chartInstance->c3_arrBML[c3_i0];
  }

  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_f_hoistedGlobal = chartInstance->c3_bored;
  c3_g_u = c3_f_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_g_hoistedGlobal = chartInstance->c3_coping;
  c3_h_u = c3_g_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_h_hoistedGlobal = chartInstance->c3_copingT;
  c3_i_u = c3_h_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_i_hoistedGlobal = chartInstance->c3_round_count;
  c3_j_u = c3_i_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_j_hoistedGlobal = chartInstance->c3_method;
  c3_k_u = c3_j_hoistedGlobal;
  c3_l_y = NULL;
  if (!chartInstance->c3_method_not_empty) {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_k_hoistedGlobal = chartInstance->c3_state;
  c3_l_u = c3_k_hoistedGlobal;
  c3_m_y = NULL;
  if (!chartInstance->c3_state_not_empty) {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 11, c3_m_y);
  for (c3_i1 = 0; c3_i1 < 625; c3_i1++) {
    c3_m_u[c3_i1] = chartInstance->c3_c_state[c3_i1];
  }

  c3_n_y = NULL;
  if (!chartInstance->c3_c_state_not_empty) {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_m_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c3_y, 12, c3_n_y);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_n_u[c3_i2] = chartInstance->c3_b_state[c3_i2];
  }

  c3_o_y = NULL;
  if (!chartInstance->c3_b_state_not_empty) {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_o_y, sf_mex_create("y", c3_n_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_l_hoistedGlobal = chartInstance->c3_is_active_c3_ARP_02_GazeWalk;
  c3_o_u = c3_l_hoistedGlobal;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_m_hoistedGlobal = chartInstance->c3_is_c3_ARP_02_GazeWalk;
  c3_p_u = c3_m_hoistedGlobal;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_n_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_q_u = c3_n_hoistedGlobal;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_o_hoistedGlobal = chartInstance->c3_previousTicks;
  c3_r_u = c3_o_hoistedGlobal;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_s_u = sf_mex_dup(c3_subchartSimStateInfo);
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_duplicatearraysafe(&c3_s_u), false);
  sf_mex_destroy(&c3_s_u);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[256];
  int32_T c3_i3;
  uint32_T c3_uv0[625];
  int32_T c3_i4;
  uint32_T c3_uv1[2];
  int32_T c3_i5;
  real_T *c3_agentPosition;
  c3_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_agentPosition = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "agentPosition");
  chartInstance->c3_BOREDOMT = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "BOREDOMT");
  chartInstance->c3_COPINGT = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "COPINGT");
  chartInstance->c3_INTERACTT = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "INTERACTT");
  chartInstance->c3_PERSONALSPACE = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "PERSONALSPACE");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
                        "arrBML", c3_dv0);
  for (c3_i3 = 0; c3_i3 < 256; c3_i3++) {
    chartInstance->c3_arrBML[c3_i3] = c3_dv0[c3_i3];
  }

  chartInstance->c3_bored = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "bored");
  chartInstance->c3_coping = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "coping");
  chartInstance->c3_copingT = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "copingT");
  chartInstance->c3_round_count = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 9)), "round_count");
  chartInstance->c3_method = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "method");
  chartInstance->c3_state = c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "state");
  c3_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 12)),
                        "state", c3_uv0);
  for (c3_i4 = 0; c3_i4 < 625; c3_i4++) {
    chartInstance->c3_c_state[c3_i4] = c3_uv0[c3_i4];
  }

  c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 13)),
                        "state", c3_uv1);
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    chartInstance->c3_b_state[c3_i5] = c3_uv1[c3_i5];
  }

  chartInstance->c3_is_active_c3_ARP_02_GazeWalk = c3_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 14)),
     "is_active_c3_ARP_02_GazeWalk");
  chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_o_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 15)), "is_c3_ARP_02_GazeWalk");
  chartInstance->c3_temporalCounter_i1 = c3_o_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 16)), "temporalCounter_i1");
  chartInstance->c3_previousTicks = c3_ab_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 17)), "previousTicks");
  sf_mex_assign(&c3_subchartSimStateInfo, c3_cb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 18)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 19)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ARP_02_GazeWalk(chartInstance);
  sf_exported_auto_setSimstatec1_ARP_02_GazeWalk
    (chartInstance->c3_subchartSimstruct, sf_mex_dup(c3_subchartSimStateInfo));
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ARP_02_GazeWalk
  (SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_checkUser) {
      chartInstance->c3_tp_checkUser = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_checkUser = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredGaze) {
      chartInstance->c3_tp_stateBoredGaze = 1U;
    } else {
      chartInstance->c3_tp_stateBoredGaze = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredPose) {
      chartInstance->c3_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredPose1) {
      chartInstance->c3_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c3_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCheckUser) {
      chartInstance->c3_tp_stateCheckUser = 1U;
    } else {
      chartInstance->c3_tp_stateCheckUser = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCheckUser2) {
      chartInstance->c3_tp_stateCheckUser2 = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateCheckUser2 = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateCoping) {
      chartInstance->c3_tp_stateCoping = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateCoping = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateIdle) {
      chartInstance->c3_tp_stateIdle = 1U;
    } else {
      chartInstance->c3_tp_stateIdle = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateInitiate) {
      chartInstance->c3_tp_stateInitiate = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateInitiate = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateIntract) {
      chartInstance->c3_tp_stateIntract = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateIntract = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateInvaded) {
      chartInstance->c3_tp_stateInvaded = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateInvaded = 0U;
    }

    if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateWalkAway) {
      chartInstance->c3_tp_stateWalkAway = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_stateWalkAway = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&c3_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  int32_T c3_i6;
  real_T *c3_userX;
  real_T *c3_userY;
  real_T *c3_userAgentDistance;
  real_T *c3_agentPosition;
  boolean_T *c3_userStill;
  c3_userStill = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_userAgentDistance = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_userY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_userX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_ARP_02_GazeWalk(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 127U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 127U;
  }

  sf_exported_auto_gatewayc1_ARP_02_GazeWalk(chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_round_count, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_userX, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_userY, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_userAgentDistance, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_agentPosition, 4U);
  for (c3_i6 = 0; c3_i6 < 256; c3_i6++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_arrBML[c3_i6], 5U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c3_userStill, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_copingT, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_COPINGT, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_BOREDOMT, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_coping, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_PERSONALSPACE, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_INTERACTT, 13U);
  sf_exported_auto_activate_callc1_ARP_02_GazeWalk
    (chartInstance->c3_subchartSimstruct);
  chartInstance->c3_sfEvent = c3_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  c3_chartstep_c3_ARP_02_GazeWalk(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_secs,
               chartInstance->c3_sfEvent);
  sf_exported_auto_deactivate_callc1_ARP_02_GazeWalk
    (chartInstance->c3_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_GazeWalkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c3_is_c3_ARP_02_GazeWalk == c3_IN_stateBoredGaze) {
    sf_exported_auto_check_state_inconsistency_c1_ARP_02_GazeWalk
      (chartInstance->c3_subchartSimstruct);
  }
}

static void c3_chartstep_c3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[99];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[99];
  real_T c3_e_nargin = 1.0;
  real_T c3_e_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i7;
  static char_T c3_cv0[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i8;
  static real_T c3_dv1[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  real_T c3_arg[256];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 1.0;
  boolean_T c3_g_out;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_h_out;
  real_T *c3_userAgentDistance;
  boolean_T *c3_userStill;
  real_T (*c3_b_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_userStill = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_userAgentDistance = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  sf_exported_auto_stepBuffersc1_ARP_02_GazeWalk
    (chartInstance->c3_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_ARP_02_GazeWalk == 0U) {
    sf_exported_auto_initBuffersc1_ARP_02_GazeWalk
      (chartInstance->c3_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_ARP_02_GazeWalk = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateInitiate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_stateInitiate = 1U;
    c3_enter_atomic_stateInitiate(chartInstance);
  } else {
    switch (chartInstance->c3_is_c3_ARP_02_GazeWalk) {
     case c3_IN_checkUser:
      CV_CHART_EVAL(1, 0, 1);
      c3_checkUser(chartInstance);
      break;

     case c3_IN_stateBoredGaze:
      CV_CHART_EVAL(1, 0, 2);
      c3_stateBoredGaze(chartInstance);
      break;

     case c3_IN_stateBoredPose:
      CV_CHART_EVAL(1, 0, 3);
      c3_stateBoredPose(chartInstance);
      break;

     case c3_IN_stateBoredPose1:
      CV_CHART_EVAL(1, 0, 4);
      c3_stateBoredPose1(chartInstance);
      break;

     case c3_IN_stateCheckUser:
      CV_CHART_EVAL(1, 0, 5);
      c3_stateCheckUser(chartInstance);
      break;

     case c3_IN_stateCheckUser2:
      CV_CHART_EVAL(1, 0, 6);
      c3_stateCheckUser2(chartInstance);
      break;

     case c3_IN_stateCoping:
      CV_CHART_EVAL(1, 0, 7);
      c3_stateCoping(chartInstance);
      break;

     case c3_IN_stateIdle:
      CV_CHART_EVAL(1, 0, 8);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_vb_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 12U);
      c3_out = CV_EML_IF(1, 0, 0, *c3_userAgentDistance <
                         chartInstance->c3_PERSONALSPACE);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateIdle = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateInvaded;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateInvaded = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ub_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_o_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 8U, 12U);
        c3_b_out = CV_EML_IF(2, 0, 0, *c3_userAgentDistance >=
                             chartInstance->c3_PERSONALSPACE);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateIdle = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCheckUser;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateCheckUser = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateInitiate:
      CV_CHART_EVAL(1, 0, 9);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_mb_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_c_out = CV_EML_IF(16, 0, 0, (real_T)*c3_userStill != 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateInitiate = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_checkUser;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_checkUser = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_m_debug_family_names,
          c3_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_s_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_r_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 6U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 7U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U,
          c3_b_sf_marshallOut, c3_b_sf_marshallIn);
        for (c3_i7 = 0; c3_i7 < 99; c3_i7++) {
          c3_mystr[c3_i7] = c3_cv0[c3_i7];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
        c3_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
        for (c3_i8 = 0; c3_i8 < 99; c3_i8++) {
          c3_arr[c3_i8] = c3_dv1[c3_i8];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
        c3_ss = 99.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
        c3_padsize = 157.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
        for (c3_i9 = 0; c3_i9 < 256; c3_i9++) {
          c3_tt[c3_i9] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
        for (c3_i10 = 0; c3_i10 < 99; c3_i10++) {
          c3_tt[c3_i10] = c3_arr[c3_i10];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
        for (c3_i11 = 0; c3_i11 < 256; c3_i11++) {
          c3_myarr256[c3_i11] = c3_tt[c3_i11];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c3_i12 = 0; c3_i12 < 256; c3_i12++) {
          c3_arg[c3_i12] = c3_myarr256[c3_i12];
        }

        for (c3_i13 = 0; c3_i13 < 256; c3_i13++) {
          _SFD_DATA_RANGE_CHECK(c3_arg[c3_i13], 17U);
        }

        _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
          c3_k_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c3_sfEvent);
        for (c3_i14 = 0; c3_i14 < 256; c3_i14++) {
          (*c3_b_arg)[c3_i14] = c3_arg[c3_i14];
        }

        for (c3_i15 = 0; c3_i15 < 256; c3_i15++) {
          _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i15], 17U);
        }

        sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(17U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_kb_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_o_sf_marshallOut,
          c3_c_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(19, 0, 0, chartInstance->c3_temporalCounter_i1 >= 50)) {
          if (CV_EML_COND(19, 0, 1, (real_T)*c3_userStill == 1.0)) {
            CV_EML_MCDC(19, 0, 0, true);
            CV_EML_IF(19, 0, 0, true);
            c3_d_out = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(19, 0, 0, false);
          CV_EML_IF(19, 0, 0, false);
          c3_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateInitiate = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateBoredGaze;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateBoredGaze = 1U;
          sf_exported_auto_enterc1_ARP_02_GazeWalk
            (chartInstance->c3_subchartSimstruct);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateIntract:
      CV_CHART_EVAL(1, 0, 10);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ob_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_e_out = CV_EML_IF(17, 0, 0, chartInstance->c3_temporalCounter_i1 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateIntract = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateIdle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateIdle = 1U;
        c3_enter_atomic_stateIdle(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateInvaded:
      CV_CHART_EVAL(1, 0, 11);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
      c3_f_out = CV_EML_IF(13, 0, 0, chartInstance->c3_coping <
                           chartInstance->c3_COPINGT);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_dc_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
        chartInstance->c3_coping++;
        c3_updateDataWrittenToVector(chartInstance, 7U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c3_coping, 11U);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c3_tp_stateInvaded = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateWalkAway;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateWalkAway = 1U;
        c3_enter_atomic_stateWalkAway(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ac_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U, c3_o_sf_marshallOut,
          c3_c_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(15, 0, 0, chartInstance->c3_temporalCounter_i1 >= 10)) {
          if (CV_EML_COND(15, 0, 1, chartInstance->c3_coping >=
                          chartInstance->c3_COPINGT)) {
            CV_EML_MCDC(15, 0, 0, true);
            CV_EML_IF(15, 0, 0, true);
            c3_g_out = true;
          } else {
            guard1 = true;
          }
        } else {
          c3_errorIfDataNotWrittenToFcn(chartInstance, 5U, 9U);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 7U, 11U);
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(15, 0, 0, false);
          CV_EML_IF(15, 0, 0, false);
          c3_g_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateInvaded = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCoping;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
          chartInstance->c3_temporalCounter_i1 = 0U;
          chartInstance->c3_tp_stateCoping = 1U;
          c3_enter_atomic_stateCoping(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_stateWalkAway:
      CV_CHART_EVAL(1, 0, 12);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_gc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_h_out = CV_EML_IF(4, 0, 0, chartInstance->c3_temporalCounter_i1 >= 10);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateWalkAway = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCheckUser2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateCheckUser2 = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_ARP_02_GazeWalk(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance)
{
  chartInstance->c3_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "stateBoredGaze");
}

static void c3_enter_atomic_stateBoredPose1(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_bmlID;
  uint32_T c3_b_debug_family_var_map[12];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  boolean_T c3_aVarTruthTableCondition_3;
  boolean_T c3_aVarTruthTableCondition_4;
  boolean_T c3_aVarTruthTableCondition_5;
  boolean_T c3_aVarTruthTableCondition_6;
  boolean_T c3_aVarTruthTableCondition_7;
  boolean_T c3_aVarTruthTableCondition_8;
  real_T c3_poseBML[256];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_dv2[256];
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  real_T c3_dv3[256];
  int32_T c3_i18;
  int32_T c3_i19;
  real_T c3_b_u[256];
  const mxArray *c3_b_y = NULL;
  real_T c3_dv4[256];
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_c_u[256];
  const mxArray *c3_c_y = NULL;
  real_T c3_dv5[256];
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_d_u[256];
  const mxArray *c3_d_y = NULL;
  real_T c3_dv6[256];
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_e_u[256];
  const mxArray *c3_e_y = NULL;
  real_T c3_dv7[256];
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_f_u[256];
  const mxArray *c3_f_y = NULL;
  real_T c3_dv8[256];
  int32_T c3_i28;
  int32_T c3_i29;
  real_T c3_g_u[256];
  const mxArray *c3_g_y = NULL;
  real_T c3_b_bmlID;
  boolean_T c3_b_aVarTruthTableCondition_1;
  boolean_T c3_b_aVarTruthTableCondition_2;
  boolean_T c3_b_aVarTruthTableCondition_3;
  boolean_T c3_b_aVarTruthTableCondition_4;
  boolean_T c3_b_aVarTruthTableCondition_5;
  boolean_T c3_b_aVarTruthTableCondition_6;
  boolean_T c3_b_aVarTruthTableCondition_7;
  boolean_T c3_b_aVarTruthTableCondition_8;
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_b_poseBML[256];
  real_T c3_dv9[256];
  int32_T c3_i30;
  int32_T c3_i31;
  real_T c3_h_u[256];
  const mxArray *c3_h_y = NULL;
  real_T c3_dv10[256];
  int32_T c3_i32;
  int32_T c3_i33;
  real_T c3_i_u[256];
  const mxArray *c3_i_y = NULL;
  real_T c3_dv11[256];
  int32_T c3_i34;
  int32_T c3_i35;
  real_T c3_j_u[256];
  const mxArray *c3_j_y = NULL;
  real_T c3_dv12[256];
  int32_T c3_i36;
  int32_T c3_i37;
  real_T c3_k_u[256];
  const mxArray *c3_k_y = NULL;
  real_T c3_dv13[256];
  int32_T c3_i38;
  int32_T c3_i39;
  real_T c3_l_u[256];
  const mxArray *c3_l_y = NULL;
  real_T c3_dv14[256];
  int32_T c3_i40;
  int32_T c3_i41;
  real_T c3_m_u[256];
  const mxArray *c3_m_y = NULL;
  real_T c3_dv15[256];
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_n_u[256];
  const mxArray *c3_n_y = NULL;
  int32_T c3_i44;
  real_T c3_arg[256];
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  chartInstance->c3_coping = 0.0;
  c3_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_coping, 11U);
  c3_bmlID = c3_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_h_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_5, 4U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_6, 5U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_7, 6U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_8, 7U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poseBML, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 5);
  c3_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 6);
  c3_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 7);
  c3_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 8);
  c3_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 9);
  c3_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 10);
  c3_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 14);
  c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 17);
  c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 20);
  c3_aVarTruthTableCondition_3 = (c3_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 23);
  c3_aVarTruthTableCondition_4 = (c3_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 26);
  c3_aVarTruthTableCondition_5 = (c3_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 29);
  c3_aVarTruthTableCondition_6 = (c3_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 32);
  c3_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 35);
  c3_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 37);
  if (CV_EML_IF(3, 1, 0, c3_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 38);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 61);
    c3_encStr2Arr(chartInstance, c3_dv2);
    for (c3_i16 = 0; c3_i16 < 256; c3_i16++) {
      c3_poseBML[c3_i16] = c3_dv2[c3_i16];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c3_i17 = 0; c3_i17 < 256; c3_i17++) {
      c3_u[c3_i17] = c3_poseBML[c3_i17];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -61);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 39);
    if (CV_EML_IF(3, 1, 1, c3_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 40);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 67);
      c3_b_encStr2Arr(chartInstance, c3_dv3);
      for (c3_i18 = 0; c3_i18 < 256; c3_i18++) {
        c3_poseBML[c3_i18] = c3_dv3[c3_i18];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c3_i19 = 0; c3_i19 < 256; c3_i19++) {
        c3_b_u[c3_i19] = c3_poseBML[c3_i19];
      }

      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -67);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 41);
      if (CV_EML_IF(3, 1, 2, c3_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 42);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 73);
        c3_c_encStr2Arr(chartInstance, c3_dv4);
        for (c3_i20 = 0; c3_i20 < 256; c3_i20++) {
          c3_poseBML[c3_i20] = c3_dv4[c3_i20];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c3_i21 = 0; c3_i21 < 256; c3_i21++) {
          c3_c_u[c3_i21] = c3_poseBML[c3_i21];
        }

        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_c_y);
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -73);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 43);
        if (CV_EML_IF(3, 1, 3, c3_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 44);
          CV_EML_FCN(3, 4);
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 79);
          c3_d_encStr2Arr(chartInstance, c3_dv5);
          for (c3_i22 = 0; c3_i22 < 256; c3_i22++) {
            c3_poseBML[c3_i22] = c3_dv5[c3_i22];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c3_i23 = 0; c3_i23 < 256; c3_i23++) {
            c3_d_u[c3_i23] = c3_poseBML[c3_i23];
          }

          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_d_y);
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -79);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 45);
          if (CV_EML_IF(3, 1, 4, c3_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 46);
            CV_EML_FCN(3, 5);
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 85);
            c3_e_encStr2Arr(chartInstance, c3_dv6);
            for (c3_i24 = 0; c3_i24 < 256; c3_i24++) {
              c3_poseBML[c3_i24] = c3_dv6[c3_i24];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c3_i25 = 0; c3_i25 < 256; c3_i25++) {
              c3_e_u[c3_i25] = c3_poseBML[c3_i25];
            }

            c3_e_y = NULL;
            sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c3_e_y);
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -85);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 47);
            if (CV_EML_IF(3, 1, 5, c3_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 48);
              CV_EML_FCN(3, 6);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 91);
              c3_f_encStr2Arr(chartInstance, c3_dv7);
              for (c3_i26 = 0; c3_i26 < 256; c3_i26++) {
                c3_poseBML[c3_i26] = c3_dv7[c3_i26];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i27 = 0; c3_i27 < 256; c3_i27++) {
                c3_f_u[c3_i27] = c3_poseBML[c3_i27];
              }

              c3_f_y = NULL;
              sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_f_y);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -91);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 49);
              CV_EML_IF(3, 1, 6, c3_aVarTruthTableCondition_7);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 51);
              CV_EML_IF(3, 1, 7, c3_aVarTruthTableCondition_8);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 54);
              CV_EML_FCN(3, 3);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 73);
              c3_c_encStr2Arr(chartInstance, c3_dv8);
              for (c3_i28 = 0; c3_i28 < 256; c3_i28++) {
                c3_poseBML[c3_i28] = c3_dv8[c3_i28];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i29 = 0; c3_i29 < 256; c3_i29++) {
                c3_g_u[c3_i29] = c3_poseBML[c3_i29];
              }

              c3_g_y = NULL;
              sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_g_y);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -73);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  c3_b_bmlID = c3_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_i_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_5, 4U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_6, 5U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_7, 6U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_8, 7U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_bmlID, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_poseBML, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 3);
  c3_b_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 4);
  c3_b_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 5);
  c3_b_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 6);
  c3_b_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 7);
  c3_b_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 8);
  c3_b_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 9);
  c3_b_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 10);
  c3_b_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 14);
  c3_b_aVarTruthTableCondition_1 = (c3_b_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 17);
  c3_b_aVarTruthTableCondition_2 = (c3_b_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 20);
  c3_b_aVarTruthTableCondition_3 = (c3_b_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 23);
  c3_b_aVarTruthTableCondition_4 = (c3_b_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 26);
  c3_b_aVarTruthTableCondition_5 = (c3_b_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 29);
  c3_b_aVarTruthTableCondition_6 = (c3_b_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 32);
  c3_b_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 35);
  c3_b_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 37);
  if (CV_EML_IF(3, 1, 0, c3_b_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 38);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 61);
    c3_encStr2Arr(chartInstance, c3_dv9);
    for (c3_i30 = 0; c3_i30 < 256; c3_i30++) {
      c3_b_poseBML[c3_i30] = c3_dv9[c3_i30];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c3_i31 = 0; c3_i31 < 256; c3_i31++) {
      c3_h_u[c3_i31] = c3_b_poseBML[c3_i31];
    }

    c3_h_y = NULL;
    sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_h_u, 0, 0U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_h_y);
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -61);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 39);
    if (CV_EML_IF(3, 1, 1, c3_b_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 40);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 67);
      c3_b_encStr2Arr(chartInstance, c3_dv10);
      for (c3_i32 = 0; c3_i32 < 256; c3_i32++) {
        c3_b_poseBML[c3_i32] = c3_dv10[c3_i32];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c3_i33 = 0; c3_i33 < 256; c3_i33++) {
        c3_i_u[c3_i33] = c3_b_poseBML[c3_i33];
      }

      c3_i_y = NULL;
      sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_i_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_i_y);
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -67);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 41);
      if (CV_EML_IF(3, 1, 2, c3_b_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 42);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 73);
        c3_c_encStr2Arr(chartInstance, c3_dv11);
        for (c3_i34 = 0; c3_i34 < 256; c3_i34++) {
          c3_b_poseBML[c3_i34] = c3_dv11[c3_i34];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c3_i35 = 0; c3_i35 < 256; c3_i35++) {
          c3_j_u[c3_i35] = c3_b_poseBML[c3_i35];
        }

        c3_j_y = NULL;
        sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_j_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_j_y);
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -73);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 43);
        if (CV_EML_IF(3, 1, 3, c3_b_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 44);
          CV_EML_FCN(3, 4);
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 79);
          c3_d_encStr2Arr(chartInstance, c3_dv12);
          for (c3_i36 = 0; c3_i36 < 256; c3_i36++) {
            c3_b_poseBML[c3_i36] = c3_dv12[c3_i36];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c3_i37 = 0; c3_i37 < 256; c3_i37++) {
            c3_k_u[c3_i37] = c3_b_poseBML[c3_i37];
          }

          c3_k_y = NULL;
          sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_k_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_k_y);
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -79);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 45);
          if (CV_EML_IF(3, 1, 4, c3_b_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 46);
            CV_EML_FCN(3, 5);
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 85);
            c3_e_encStr2Arr(chartInstance, c3_dv13);
            for (c3_i38 = 0; c3_i38 < 256; c3_i38++) {
              c3_b_poseBML[c3_i38] = c3_dv13[c3_i38];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c3_i39 = 0; c3_i39 < 256; c3_i39++) {
              c3_l_u[c3_i39] = c3_b_poseBML[c3_i39];
            }

            c3_l_y = NULL;
            sf_mex_assign(&c3_l_y, sf_mex_create("y", c3_l_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c3_l_y);
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -85);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 47);
            if (CV_EML_IF(3, 1, 5, c3_b_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 48);
              CV_EML_FCN(3, 6);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 91);
              c3_f_encStr2Arr(chartInstance, c3_dv14);
              for (c3_i40 = 0; c3_i40 < 256; c3_i40++) {
                c3_b_poseBML[c3_i40] = c3_dv14[c3_i40];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i41 = 0; c3_i41 < 256; c3_i41++) {
                c3_m_u[c3_i41] = c3_b_poseBML[c3_i41];
              }

              c3_m_y = NULL;
              sf_mex_assign(&c3_m_y, sf_mex_create("y", c3_m_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_m_y);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -91);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 49);
              CV_EML_IF(3, 1, 6, c3_b_aVarTruthTableCondition_7);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 51);
              CV_EML_IF(3, 1, 7, c3_b_aVarTruthTableCondition_8);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 54);
              CV_EML_FCN(3, 3);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, 73);
              c3_c_encStr2Arr(chartInstance, c3_dv15);
              for (c3_i42 = 0; c3_i42 < 256; c3_i42++) {
                c3_b_poseBML[c3_i42] = c3_dv15[c3_i42];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i43 = 0; c3_i43 < 256; c3_i43++) {
                c3_n_u[c3_i43] = c3_b_poseBML[c3_i43];
              }

              c3_n_y = NULL;
              sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_n_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_n_y);
              _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -73);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c3_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i44 = 0; c3_i44 < 256; c3_i44++) {
    c3_arg[c3_i44] = c3_b_poseBML[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 256; c3_i45++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i45], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i46 = 0; c3_i46 < 256; c3_i46++) {
    (*c3_b_arg)[c3_i46] = c3_arg[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 256; c3_i47++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i47], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateBoredPose1(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_stateBoredPose1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateInitiate;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_stateInitiate = 1U;
  c3_enter_atomic_stateInitiate(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateInitiate(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[103];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[103];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i48;
  static char_T c3_cv1[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', '2', ' ', '-',
    '1', '.', '7', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c3_i49;
  static real_T c3_dv16[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 50.0, 32.0, 45.0, 49.0, 46.0, 55.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  real_T c3_arg[256];
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  real_T *c3_agentPosition;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *c3_agentPosition = 600.0;
  c3_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_agentPosition, 4U);
  chartInstance->c3_bored = 0.0;
  c3_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
  chartInstance->c3_coping = 0.0;
  c3_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_coping, 11U);
  chartInstance->c3_COPINGT = 3.0;
  c3_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_COPINGT, 9U);
  chartInstance->c3_PERSONALSPACE = 150.0;
  c3_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_PERSONALSPACE, 12U);
  chartInstance->c3_BOREDOMT = 3.0;
  c3_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_BOREDOMT, 10U);
  chartInstance->c3_INTERACTT = 10.0;
  c3_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_INTERACTT, 13U);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_k_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i48 = 0; c3_i48 < 103; c3_i48++) {
    c3_mystr[c3_i48] = c3_cv1[c3_i48];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i49 = 0; c3_i49 < 103; c3_i49++) {
    c3_arr[c3_i49] = c3_dv16[c3_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 153.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i50 = 0; c3_i50 < 256; c3_i50++) {
    c3_tt[c3_i50] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i51 = 0; c3_i51 < 103; c3_i51++) {
    c3_tt[c3_i51] = c3_arr[c3_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i52 = 0; c3_i52 < 256; c3_i52++) {
    c3_myarr256[c3_i52] = c3_tt[c3_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i53 = 0; c3_i53 < 256; c3_i53++) {
    c3_arg[c3_i53] = c3_myarr256[c3_i53];
  }

  for (c3_i54 = 0; c3_i54 < 256; c3_i54++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i54], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i55 = 0; c3_i55 < 256; c3_i55++) {
    (*c3_b_arg)[c3_i55] = c3_arg[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 256; c3_i56++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i56], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateBoredGaze(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  sf_exported_auto_exitc1_ARP_02_GazeWalk(chartInstance->c3_subchartSimstruct);
  chartInstance->c3_tp_stateBoredGaze = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateBoredPose1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_stateBoredPose1 = 1U;
  c3_enter_atomic_stateBoredPose1(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
}

static void c3_checkUser(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[100];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[100];
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_myarr256[256];
  int32_T c3_i57;
  static char_T c3_cv2[100] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', '2', ' ', '0',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i58;
  static real_T c3_dv17[100] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 50.0, 32.0, 48.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  real_T c3_arg[256];
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_nb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
    c3_c_sf_marshallIn);
  c3_out = CV_EML_IF(21, 0, 0, chartInstance->c3_temporalCounter_i1 >= 50);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_checkUser = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateIntract;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_stateIntract = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_o_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_u_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_t_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 6U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 7U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    for (c3_i57 = 0; c3_i57 < 100; c3_i57++) {
      c3_mystr[c3_i57] = c3_cv2[c3_i57];
    }

    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
    c3_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
    for (c3_i58 = 0; c3_i58 < 100; c3_i58++) {
      c3_arr[c3_i58] = c3_dv17[c3_i58];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
    c3_ss = 100.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_padsize = 156.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
    for (c3_i59 = 0; c3_i59 < 256; c3_i59++) {
      c3_tt[c3_i59] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
    for (c3_i60 = 0; c3_i60 < 100; c3_i60++) {
      c3_tt[c3_i60] = c3_arr[c3_i60];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
    for (c3_i61 = 0; c3_i61 < 256; c3_i61++) {
      c3_myarr256[c3_i61] = c3_tt[c3_i61];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
    for (c3_i62 = 0; c3_i62 < 256; c3_i62++) {
      c3_arg[c3_i62] = c3_myarr256[c3_i62];
    }

    for (c3_i63 = 0; c3_i63 < 256; c3_i63++) {
      _SFD_DATA_RANGE_CHECK(c3_arg[c3_i63], 17U);
    }

    _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
      c3_k_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    for (c3_i64 = 0; c3_i64 < 256; c3_i64++) {
      (*c3_b_arg)[c3_i64] = c3_arg[c3_i64];
    }

    for (c3_i65 = 0; c3_i65 < 256; c3_i65++) {
      _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i65], 17U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(17U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateIdle(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[4];
  char_T c3_mystr[185];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_b_arrBML[256];
  int32_T c3_i66;
  int32_T c3_i67;
  static char_T c3_cv3[211] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 't', 'y', 'p', 'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"',
    ' ', 'a', 'u', '=', '\\', '\"', '6', '\\', '\"', ' ', ' ', 's', 't', 'a',
    'r', 't', '=', '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\',
    '\"', '1', '0', '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\',
    '\"', '0', '.', '5', '\\', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's',
    'i', 'd', 'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a',
    'u', '=', '\\', '\"', '1', '2', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r',
    't', '=', '\\', '\"', '0', '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"',
    '1', '0', '\\', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\\', '\"',
    '2', '\\', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c3_u[211];
  const mxArray *c3_y = NULL;
  char_T c3_cv4[185];
  int32_T c3_i68;
  int32_T c3_i69;
  char_T c3_b_mystr[185];
  real_T c3_dv18[256];
  int32_T c3_i70;
  int32_T c3_i71;
  real_T c3_arg[256];
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_p_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_r_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, 0U, c3_v_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_arrBML, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 3);
  for (c3_i66 = 0; c3_i66 < 185; c3_i66++) {
    c3_mystr[c3_i66] = ' ';
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 4);
  for (c3_i67 = 0; c3_i67 < 211; c3_i67++) {
    c3_u[c3_i67] = c3_cv3[c3_i67];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 211),
                false);
  c3_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 1U, 14, c3_y),
                      "sprintf", c3_cv4);
  for (c3_i68 = 0; c3_i68 < 185; c3_i68++) {
    c3_mystr[c3_i68] = c3_cv4[c3_i68];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, 5);
  for (c3_i69 = 0; c3_i69 < 185; c3_i69++) {
    c3_b_mystr[c3_i69] = c3_mystr[c3_i69];
  }

  c3_g_encStr2Arr(chartInstance, c3_b_mystr, c3_dv18);
  for (c3_i70 = 0; c3_i70 < 256; c3_i70++) {
    c3_b_arrBML[c3_i70] = c3_dv18[c3_i70];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c3_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i71 = 0; c3_i71 < 256; c3_i71++) {
    c3_arg[c3_i71] = c3_b_arrBML[c3_i71];
  }

  for (c3_i72 = 0; c3_i72 < 256; c3_i72++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i72], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i73 = 0; c3_i73 < 256; c3_i73++) {
    (*c3_b_arg)[c3_i73] = c3_arg[c3_i73];
  }

  for (c3_i74 = 0; c3_i74 < 256; c3_i74++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i74], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateCheckUser(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  boolean_T *c3_userStill;
  boolean_T guard1 = false;
  c3_userStill = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
    c3_c_sf_marshallIn);
  c3_out = CV_EML_IF(7, 0, 0, (real_T)*c3_userStill != 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qb_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    chartInstance->c3_bored = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c3_tp_stateCheckUser = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateIdle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateIdle = 1U;
    c3_enter_atomic_stateIdle(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_o_sf_marshallOut,
      c3_c_sf_marshallIn);
    c3_b_out = CV_EML_IF(8, 0, 0, (real_T)*c3_userStill == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_yb_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
      chartInstance->c3_bored++;
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 10U);
      c3_c_out = CV_EML_IF(6, 0, 0, chartInstance->c3_bored >=
                           chartInstance->c3_BOREDOMT);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateCheckUser = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateBoredPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateBoredPose = 1U;
        c3_enter_atomic_stateBoredPose(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wb_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_o_sf_marshallOut,
          c3_c_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 10U);
        c3_d_out = CV_EML_IF(9, 0, 0, chartInstance->c3_bored <
                             chartInstance->c3_BOREDOMT);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateCheckUser = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCheckUser;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_stateCheckUser = 1U;
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateCoping(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_r;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_bmlID;
  uint32_T c3_b_debug_family_var_map[8];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  boolean_T c3_aVarTruthTableCondition_3;
  boolean_T c3_aVarTruthTableCondition_4;
  real_T c3_invadedBML[256];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 0.0;
  int32_T c3_i75;
  static char_T c3_cv5[185] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's', 't',
    'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '.',
    '5', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'r', 'i',
    'g', 'h', 't', '\"', ' ', 'a', 'u', '=', '\"', '4', '\"', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"',
    '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  char_T c3_cv6[185];
  real_T c3_dv19[256];
  int32_T c3_i76;
  int32_T c3_i77;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  real_T c3_dv20[256];
  int32_T c3_i78;
  int32_T c3_i79;
  real_T c3_b_u[256];
  const mxArray *c3_b_y = NULL;
  real_T c3_dv21[256];
  int32_T c3_i80;
  int32_T c3_i81;
  real_T c3_c_u[256];
  const mxArray *c3_c_y = NULL;
  real_T c3_dv22[256];
  int32_T c3_i82;
  int32_T c3_i83;
  real_T c3_d_u[256];
  const mxArray *c3_d_y = NULL;
  real_T c3_dv23[256];
  int32_T c3_i84;
  int32_T c3_i85;
  real_T c3_e_u[256];
  const mxArray *c3_e_y = NULL;
  real_T c3_b_r;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_bmlID;
  boolean_T c3_b_aVarTruthTableCondition_1;
  boolean_T c3_b_aVarTruthTableCondition_2;
  boolean_T c3_b_aVarTruthTableCondition_3;
  boolean_T c3_b_aVarTruthTableCondition_4;
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_b_invadedBML[256];
  int32_T c3_i86;
  char_T c3_cv7[185];
  real_T c3_dv24[256];
  int32_T c3_i87;
  int32_T c3_i88;
  real_T c3_f_u[256];
  const mxArray *c3_f_y = NULL;
  real_T c3_dv25[256];
  int32_T c3_i89;
  int32_T c3_i90;
  real_T c3_g_u[256];
  const mxArray *c3_g_y = NULL;
  real_T c3_dv26[256];
  int32_T c3_i91;
  int32_T c3_i92;
  real_T c3_h_u[256];
  const mxArray *c3_h_y = NULL;
  real_T c3_dv27[256];
  int32_T c3_i93;
  int32_T c3_i94;
  real_T c3_i_u[256];
  const mxArray *c3_i_y = NULL;
  real_T c3_dv28[256];
  int32_T c3_i95;
  int32_T c3_i96;
  real_T c3_j_u[256];
  const mxArray *c3_j_y = NULL;
  int32_T c3_i97;
  real_T c3_arg[256];
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i100;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_r = c3_rand(chartInstance);
  c3_x = c3_r * 8.0;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarFloor(c3_b_x);
  c3_r = 1.0 + c3_b_x;
  c3_bmlID = c3_r;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_w_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_invadedBML, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 5);
  c3_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 6);
  c3_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 10);
  c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 13);
  c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 16);
  c3_aVarTruthTableCondition_3 = (c3_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 19);
  c3_aVarTruthTableCondition_4 = (c3_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 21);
  if (CV_EML_IF(5, 1, 0, c3_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 22);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 37);
    for (c3_i75 = 0; c3_i75 < 185; c3_i75++) {
      c3_cv6[c3_i75] = c3_cv5[c3_i75];
    }

    c3_g_encStr2Arr(chartInstance, c3_cv6, c3_dv19);
    for (c3_i76 = 0; c3_i76 < 256; c3_i76++) {
      c3_invadedBML[c3_i76] = c3_dv19[c3_i76];
    }

    sf_mex_printf("%s =\\n", "invadedBML");
    for (c3_i77 = 0; c3_i77 < 256; c3_i77++) {
      c3_u[c3_i77] = c3_invadedBML[c3_i77];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -37);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 23);
    if (CV_EML_IF(5, 1, 1, c3_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 24);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 43);
      c3_h_encStr2Arr(chartInstance, c3_dv20);
      for (c3_i78 = 0; c3_i78 < 256; c3_i78++) {
        c3_invadedBML[c3_i78] = c3_dv20[c3_i78];
      }

      sf_mex_printf("%s =\\n", "invadedBML");
      for (c3_i79 = 0; c3_i79 < 256; c3_i79++) {
        c3_b_u[c3_i79] = c3_invadedBML[c3_i79];
      }

      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -43);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 25);
      if (CV_EML_IF(5, 1, 2, c3_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 26);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 49);
        c3_i_encStr2Arr(chartInstance, c3_dv21);
        for (c3_i80 = 0; c3_i80 < 256; c3_i80++) {
          c3_invadedBML[c3_i80] = c3_dv21[c3_i80];
        }

        sf_mex_printf("%s =\\n", "invadedBML");
        for (c3_i81 = 0; c3_i81 < 256; c3_i81++) {
          c3_c_u[c3_i81] = c3_invadedBML[c3_i81];
        }

        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_c_y);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -49);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 27);
        if (CV_EML_IF(5, 1, 3, c3_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 28);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 55);
          c3_j_encStr2Arr(chartInstance, c3_dv22);
          for (c3_i82 = 0; c3_i82 < 256; c3_i82++) {
            c3_invadedBML[c3_i82] = c3_dv22[c3_i82];
          }

          sf_mex_printf("%s =\\n", "invadedBML");
          for (c3_i83 = 0; c3_i83 < 256; c3_i83++) {
            c3_d_u[c3_i83] = c3_invadedBML[c3_i83];
          }

          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_d_y);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -55);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 30);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 55);
          c3_j_encStr2Arr(chartInstance, c3_dv23);
          for (c3_i84 = 0; c3_i84 < 256; c3_i84++) {
            c3_invadedBML[c3_i84] = c3_dv23[c3_i84];
          }

          sf_mex_printf("%s =\\n", "invadedBML");
          for (c3_i85 = 0; c3_i85 < 256; c3_i85++) {
            c3_e_u[c3_i85] = c3_invadedBML[c3_i85];
          }

          c3_e_y = NULL;
          sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_e_y);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -55);
        }
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  c3_b_r = c3_rand(chartInstance);
  c3_c_x = c3_b_r * 4.0;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarFloor(c3_d_x);
  c3_b_r = 1.0 + c3_d_x;
  c3_b_bmlID = c3_b_r;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_x_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_bmlID, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_invadedBML, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 3);
  c3_b_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 4);
  c3_b_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 5);
  c3_b_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 6);
  c3_b_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 10);
  c3_b_aVarTruthTableCondition_1 = (c3_b_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 13);
  c3_b_aVarTruthTableCondition_2 = (c3_b_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 16);
  c3_b_aVarTruthTableCondition_3 = (c3_b_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 19);
  c3_b_aVarTruthTableCondition_4 = (c3_b_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 21);
  if (CV_EML_IF(5, 1, 0, c3_b_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 22);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 37);
    for (c3_i86 = 0; c3_i86 < 185; c3_i86++) {
      c3_cv7[c3_i86] = c3_cv5[c3_i86];
    }

    c3_g_encStr2Arr(chartInstance, c3_cv7, c3_dv24);
    for (c3_i87 = 0; c3_i87 < 256; c3_i87++) {
      c3_b_invadedBML[c3_i87] = c3_dv24[c3_i87];
    }

    sf_mex_printf("%s =\\n", "invadedBML");
    for (c3_i88 = 0; c3_i88 < 256; c3_i88++) {
      c3_f_u[c3_i88] = c3_b_invadedBML[c3_i88];
    }

    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_f_y);
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -37);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 23);
    if (CV_EML_IF(5, 1, 1, c3_b_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 24);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 43);
      c3_h_encStr2Arr(chartInstance, c3_dv25);
      for (c3_i89 = 0; c3_i89 < 256; c3_i89++) {
        c3_b_invadedBML[c3_i89] = c3_dv25[c3_i89];
      }

      sf_mex_printf("%s =\\n", "invadedBML");
      for (c3_i90 = 0; c3_i90 < 256; c3_i90++) {
        c3_g_u[c3_i90] = c3_b_invadedBML[c3_i90];
      }

      c3_g_y = NULL;
      sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_g_y);
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -43);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 25);
      if (CV_EML_IF(5, 1, 2, c3_b_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 26);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 49);
        c3_i_encStr2Arr(chartInstance, c3_dv26);
        for (c3_i91 = 0; c3_i91 < 256; c3_i91++) {
          c3_b_invadedBML[c3_i91] = c3_dv26[c3_i91];
        }

        sf_mex_printf("%s =\\n", "invadedBML");
        for (c3_i92 = 0; c3_i92 < 256; c3_i92++) {
          c3_h_u[c3_i92] = c3_b_invadedBML[c3_i92];
        }

        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_h_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_h_y);
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -49);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 27);
        if (CV_EML_IF(5, 1, 3, c3_b_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 28);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 55);
          c3_j_encStr2Arr(chartInstance, c3_dv27);
          for (c3_i93 = 0; c3_i93 < 256; c3_i93++) {
            c3_b_invadedBML[c3_i93] = c3_dv27[c3_i93];
          }

          sf_mex_printf("%s =\\n", "invadedBML");
          for (c3_i94 = 0; c3_i94 < 256; c3_i94++) {
            c3_i_u[c3_i94] = c3_b_invadedBML[c3_i94];
          }

          c3_i_y = NULL;
          sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_i_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_i_y);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -55);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 30);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, 55);
          c3_j_encStr2Arr(chartInstance, c3_dv28);
          for (c3_i95 = 0; c3_i95 < 256; c3_i95++) {
            c3_b_invadedBML[c3_i95] = c3_dv28[c3_i95];
          }

          sf_mex_printf("%s =\\n", "invadedBML");
          for (c3_i96 = 0; c3_i96 < 256; c3_i96++) {
            c3_j_u[c3_i96] = c3_b_invadedBML[c3_i96];
          }

          c3_j_y = NULL;
          sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_j_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_j_y);
          _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -55);
        }
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c3_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i97 = 0; c3_i97 < 256; c3_i97++) {
    c3_arg[c3_i97] = c3_b_invadedBML[c3_i97];
  }

  for (c3_i98 = 0; c3_i98 < 256; c3_i98++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i98], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i99 = 0; c3_i99 < 256; c3_i99++) {
    (*c3_b_arg)[c3_i99] = c3_arg[c3_i99];
  }

  for (c3_i100 = 0; c3_i100 < 256; c3_i100++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i100], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateCoping(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ec_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
    c3_c_sf_marshallIn);
  c3_out = CV_EML_IF(14, 0, 0, chartInstance->c3_temporalCounter_i1 >= 10);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateCoping = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateWalkAway;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    chartInstance->c3_temporalCounter_i1 = 0U;
    chartInstance->c3_tp_stateWalkAway = 1U;
    c3_enter_atomic_stateWalkAway(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateBoredPose(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_bmlID;
  uint32_T c3_b_debug_family_var_map[12];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  boolean_T c3_aVarTruthTableCondition_3;
  boolean_T c3_aVarTruthTableCondition_4;
  boolean_T c3_aVarTruthTableCondition_5;
  boolean_T c3_aVarTruthTableCondition_6;
  boolean_T c3_aVarTruthTableCondition_7;
  boolean_T c3_aVarTruthTableCondition_8;
  real_T c3_poseBML[256];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_dv29[256];
  int32_T c3_i101;
  int32_T c3_i102;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  real_T c3_dv30[256];
  int32_T c3_i103;
  int32_T c3_i104;
  real_T c3_b_u[256];
  const mxArray *c3_b_y = NULL;
  real_T c3_dv31[256];
  int32_T c3_i105;
  int32_T c3_i106;
  real_T c3_c_u[256];
  const mxArray *c3_c_y = NULL;
  real_T c3_dv32[256];
  int32_T c3_i107;
  int32_T c3_i108;
  real_T c3_d_u[256];
  const mxArray *c3_d_y = NULL;
  real_T c3_dv33[256];
  int32_T c3_i109;
  int32_T c3_i110;
  real_T c3_e_u[256];
  const mxArray *c3_e_y = NULL;
  real_T c3_dv34[256];
  int32_T c3_i111;
  int32_T c3_i112;
  real_T c3_f_u[256];
  const mxArray *c3_f_y = NULL;
  real_T c3_dv35[256];
  int32_T c3_i113;
  int32_T c3_i114;
  real_T c3_g_u[256];
  const mxArray *c3_g_y = NULL;
  real_T c3_b_bmlID;
  boolean_T c3_b_aVarTruthTableCondition_1;
  boolean_T c3_b_aVarTruthTableCondition_2;
  boolean_T c3_b_aVarTruthTableCondition_3;
  boolean_T c3_b_aVarTruthTableCondition_4;
  boolean_T c3_b_aVarTruthTableCondition_5;
  boolean_T c3_b_aVarTruthTableCondition_6;
  boolean_T c3_b_aVarTruthTableCondition_7;
  boolean_T c3_b_aVarTruthTableCondition_8;
  real_T c3_c_nargin = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_b_poseBML[256];
  real_T c3_dv36[256];
  int32_T c3_i115;
  int32_T c3_i116;
  real_T c3_h_u[256];
  const mxArray *c3_h_y = NULL;
  real_T c3_dv37[256];
  int32_T c3_i117;
  int32_T c3_i118;
  real_T c3_i_u[256];
  const mxArray *c3_i_y = NULL;
  real_T c3_dv38[256];
  int32_T c3_i119;
  int32_T c3_i120;
  real_T c3_j_u[256];
  const mxArray *c3_j_y = NULL;
  real_T c3_dv39[256];
  int32_T c3_i121;
  int32_T c3_i122;
  real_T c3_k_u[256];
  const mxArray *c3_k_y = NULL;
  real_T c3_dv40[256];
  int32_T c3_i123;
  int32_T c3_i124;
  real_T c3_l_u[256];
  const mxArray *c3_l_y = NULL;
  real_T c3_dv41[256];
  int32_T c3_i125;
  int32_T c3_i126;
  real_T c3_m_u[256];
  const mxArray *c3_m_y = NULL;
  real_T c3_dv42[256];
  int32_T c3_i127;
  int32_T c3_i128;
  real_T c3_n_u[256];
  const mxArray *c3_n_y = NULL;
  int32_T c3_i129;
  real_T c3_arg[256];
  int32_T c3_i130;
  int32_T c3_i131;
  int32_T c3_i132;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_y_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  chartInstance->c3_coping = 0.0;
  c3_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_coping, 11U);
  c3_bmlID = c3_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_fb_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_5, 4U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_6, 5U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_7, 6U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_8, 7U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_poseBML, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_bmlID, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
  c3_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 6);
  c3_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 7);
  c3_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
  c3_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 9);
  c3_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 10);
  c3_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 14);
  c3_aVarTruthTableCondition_1 = (c3_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 17);
  c3_aVarTruthTableCondition_2 = (c3_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 20);
  c3_aVarTruthTableCondition_3 = (c3_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 23);
  c3_aVarTruthTableCondition_4 = (c3_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 26);
  c3_aVarTruthTableCondition_5 = (c3_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 29);
  c3_aVarTruthTableCondition_6 = (c3_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 32);
  c3_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 35);
  c3_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 37);
  if (CV_EML_IF(2, 1, 0, c3_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 38);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 61);
    c3_encStr2Arr(chartInstance, c3_dv29);
    for (c3_i101 = 0; c3_i101 < 256; c3_i101++) {
      c3_poseBML[c3_i101] = c3_dv29[c3_i101];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c3_i102 = 0; c3_i102 < 256; c3_i102++) {
      c3_u[c3_i102] = c3_poseBML[c3_i102];
    }

    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -61);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 39);
    if (CV_EML_IF(2, 1, 1, c3_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 40);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 67);
      c3_k_encStr2Arr(chartInstance, c3_dv30);
      for (c3_i103 = 0; c3_i103 < 256; c3_i103++) {
        c3_poseBML[c3_i103] = c3_dv30[c3_i103];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c3_i104 = 0; c3_i104 < 256; c3_i104++) {
        c3_b_u[c3_i104] = c3_poseBML[c3_i104];
      }

      c3_b_y = NULL;
      sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_b_y);
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -67);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 41);
      if (CV_EML_IF(2, 1, 2, c3_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 42);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 73);
        c3_l_encStr2Arr(chartInstance, c3_dv31);
        for (c3_i105 = 0; c3_i105 < 256; c3_i105++) {
          c3_poseBML[c3_i105] = c3_dv31[c3_i105];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c3_i106 = 0; c3_i106 < 256; c3_i106++) {
          c3_c_u[c3_i106] = c3_poseBML[c3_i106];
        }

        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_c_y);
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -73);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 43);
        if (CV_EML_IF(2, 1, 3, c3_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 44);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 79);
          c3_m_encStr2Arr(chartInstance, c3_dv32);
          for (c3_i107 = 0; c3_i107 < 256; c3_i107++) {
            c3_poseBML[c3_i107] = c3_dv32[c3_i107];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c3_i108 = 0; c3_i108 < 256; c3_i108++) {
            c3_d_u[c3_i108] = c3_poseBML[c3_i108];
          }

          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_d_y);
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -79);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 45);
          if (CV_EML_IF(2, 1, 4, c3_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 46);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 85);
            c3_n_encStr2Arr(chartInstance, c3_dv33);
            for (c3_i109 = 0; c3_i109 < 256; c3_i109++) {
              c3_poseBML[c3_i109] = c3_dv33[c3_i109];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c3_i110 = 0; c3_i110 < 256; c3_i110++) {
              c3_e_u[c3_i110] = c3_poseBML[c3_i110];
            }

            c3_e_y = NULL;
            sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c3_e_y);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -85);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 47);
            if (CV_EML_IF(2, 1, 5, c3_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 48);
              CV_EML_FCN(2, 6);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 91);
              c3_o_encStr2Arr(chartInstance, c3_dv34);
              for (c3_i111 = 0; c3_i111 < 256; c3_i111++) {
                c3_poseBML[c3_i111] = c3_dv34[c3_i111];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i112 = 0; c3_i112 < 256; c3_i112++) {
                c3_f_u[c3_i112] = c3_poseBML[c3_i112];
              }

              c3_f_y = NULL;
              sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_f_y);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -91);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 49);
              CV_EML_IF(2, 1, 6, c3_aVarTruthTableCondition_7);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 51);
              CV_EML_IF(2, 1, 7, c3_aVarTruthTableCondition_8);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 54);
              CV_EML_FCN(2, 3);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 73);
              c3_l_encStr2Arr(chartInstance, c3_dv35);
              for (c3_i113 = 0; c3_i113 < 256; c3_i113++) {
                c3_poseBML[c3_i113] = c3_dv35[c3_i113];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i114 = 0; c3_i114 < 256; c3_i114++) {
                c3_g_u[c3_i114] = c3_poseBML[c3_i114];
              }

              c3_g_y = NULL;
              sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_g_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_g_y);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -73);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  c3_b_bmlID = c3_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c3_gb_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_1, 0U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_2, 1U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_3, 2U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_4, 3U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_5, 4U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_6, 5U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_7, 6U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_aVarTruthTableCondition_8, 7U,
    c3_o_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_bmlID, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_poseBML, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 3);
  c3_b_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 4);
  c3_b_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 5);
  c3_b_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 6);
  c3_b_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 7);
  c3_b_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 8);
  c3_b_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 9);
  c3_b_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 10);
  c3_b_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 14);
  c3_b_aVarTruthTableCondition_1 = (c3_b_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 17);
  c3_b_aVarTruthTableCondition_2 = (c3_b_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 20);
  c3_b_aVarTruthTableCondition_3 = (c3_b_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 23);
  c3_b_aVarTruthTableCondition_4 = (c3_b_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 26);
  c3_b_aVarTruthTableCondition_5 = (c3_b_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 29);
  c3_b_aVarTruthTableCondition_6 = (c3_b_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 32);
  c3_b_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 35);
  c3_b_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 37);
  if (CV_EML_IF(2, 1, 0, c3_b_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 38);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 61);
    c3_encStr2Arr(chartInstance, c3_dv36);
    for (c3_i115 = 0; c3_i115 < 256; c3_i115++) {
      c3_b_poseBML[c3_i115] = c3_dv36[c3_i115];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c3_i116 = 0; c3_i116 < 256; c3_i116++) {
      c3_h_u[c3_i116] = c3_b_poseBML[c3_i116];
    }

    c3_h_y = NULL;
    sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_h_u, 0, 0U, 1U, 0U, 1, 256),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_h_y);
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -61);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 39);
    if (CV_EML_IF(2, 1, 1, c3_b_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 40);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 67);
      c3_k_encStr2Arr(chartInstance, c3_dv37);
      for (c3_i117 = 0; c3_i117 < 256; c3_i117++) {
        c3_b_poseBML[c3_i117] = c3_dv37[c3_i117];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c3_i118 = 0; c3_i118 < 256; c3_i118++) {
        c3_i_u[c3_i118] = c3_b_poseBML[c3_i118];
      }

      c3_i_y = NULL;
      sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_i_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_i_y);
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -67);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 41);
      if (CV_EML_IF(2, 1, 2, c3_b_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 42);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 73);
        c3_l_encStr2Arr(chartInstance, c3_dv38);
        for (c3_i119 = 0; c3_i119 < 256; c3_i119++) {
          c3_b_poseBML[c3_i119] = c3_dv38[c3_i119];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c3_i120 = 0; c3_i120 < 256; c3_i120++) {
          c3_j_u[c3_i120] = c3_b_poseBML[c3_i120];
        }

        c3_j_y = NULL;
        sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_j_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_j_y);
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -73);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 43);
        if (CV_EML_IF(2, 1, 3, c3_b_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 44);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 79);
          c3_m_encStr2Arr(chartInstance, c3_dv39);
          for (c3_i121 = 0; c3_i121 < 256; c3_i121++) {
            c3_b_poseBML[c3_i121] = c3_dv39[c3_i121];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c3_i122 = 0; c3_i122 < 256; c3_i122++) {
            c3_k_u[c3_i122] = c3_b_poseBML[c3_i122];
          }

          c3_k_y = NULL;
          sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_k_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c3_k_y);
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -79);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 45);
          if (CV_EML_IF(2, 1, 4, c3_b_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 46);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 85);
            c3_n_encStr2Arr(chartInstance, c3_dv40);
            for (c3_i123 = 0; c3_i123 < 256; c3_i123++) {
              c3_b_poseBML[c3_i123] = c3_dv40[c3_i123];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c3_i124 = 0; c3_i124 < 256; c3_i124++) {
              c3_l_u[c3_i124] = c3_b_poseBML[c3_i124];
            }

            c3_l_y = NULL;
            sf_mex_assign(&c3_l_y, sf_mex_create("y", c3_l_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c3_l_y);
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -85);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 47);
            if (CV_EML_IF(2, 1, 5, c3_b_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 48);
              CV_EML_FCN(2, 6);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 91);
              c3_o_encStr2Arr(chartInstance, c3_dv41);
              for (c3_i125 = 0; c3_i125 < 256; c3_i125++) {
                c3_b_poseBML[c3_i125] = c3_dv41[c3_i125];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i126 = 0; c3_i126 < 256; c3_i126++) {
                c3_m_u[c3_i126] = c3_b_poseBML[c3_i126];
              }

              c3_m_y = NULL;
              sf_mex_assign(&c3_m_y, sf_mex_create("y", c3_m_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_m_y);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -91);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 49);
              CV_EML_IF(2, 1, 6, c3_b_aVarTruthTableCondition_7);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 51);
              CV_EML_IF(2, 1, 7, c3_b_aVarTruthTableCondition_8);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 54);
              CV_EML_FCN(2, 3);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, 73);
              c3_l_encStr2Arr(chartInstance, c3_dv42);
              for (c3_i127 = 0; c3_i127 < 256; c3_i127++) {
                c3_b_poseBML[c3_i127] = c3_dv42[c3_i127];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c3_i128 = 0; c3_i128 < 256; c3_i128++) {
                c3_n_u[c3_i128] = c3_b_poseBML[c3_i128];
              }

              c3_n_y = NULL;
              sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_n_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c3_n_y);
              _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -73);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c3_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i129 = 0; c3_i129 < 256; c3_i129++) {
    c3_arg[c3_i129] = c3_b_poseBML[c3_i129];
  }

  for (c3_i130 = 0; c3_i130 < 256; c3_i130++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i130], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i131 = 0; c3_i131 < 256; c3_i131++) {
    (*c3_b_arg)[c3_i131] = c3_arg[c3_i131];
  }

  for (c3_i132 = 0; c3_i132 < 256; c3_i132++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i132], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateBoredPose(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_tb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
    c3_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(12, 0, 0, chartInstance->c3_temporalCounter_i1 >= 100)) {
    if (CV_EML_COND(12, 0, 1, chartInstance->c3_bored <
                    chartInstance->c3_INTERACTT)) {
      CV_EML_MCDC(12, 0, 0, true);
      CV_EML_IF(12, 0, 0, true);
      c3_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 13U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(12, 0, 0, false);
    CV_EML_IF(12, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateBoredPose = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCheckUser;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_stateCheckUser = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_lb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_o_sf_marshallOut,
      c3_c_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 9U, 13U);
    c3_b_out = CV_EML_IF(18, 0, 0, chartInstance->c3_bored >=
                         chartInstance->c3_INTERACTT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateBoredPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateInitiate;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateInitiate = 1U;
      c3_enter_atomic_stateInitiate(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_stateWalkAway(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_agentPosition;
  real_T c3_dv43[256];
  int32_T c3_i133;
  int32_T c3_i134;
  int32_T c3_i135;
  real_T c3_arg[256];
  int32_T c3_i136;
  int32_T c3_i137;
  int32_T c3_i138;
  real_T *c3_userX;
  real_T *c3_b_agentPosition;
  real_T (*c3_b_arg)[256];
  c3_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_userX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_hb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  c3_cmdBML_walkOppositeUser(chartInstance, *c3_userX, c3_dv43,
    &c3_agentPosition);
  for (c3_i133 = 0; c3_i133 < 256; c3_i133++) {
    chartInstance->c3_arrBML[c3_i133] = c3_dv43[c3_i133];
  }

  c3_updateDataWrittenToVector(chartInstance, 2U);
  for (c3_i134 = 0; c3_i134 < 256; c3_i134++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_arrBML[c3_i134], 5U);
  }

  *c3_b_agentPosition = c3_agentPosition;
  c3_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_agentPosition, 4U);
  c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U);
  for (c3_i135 = 0; c3_i135 < 256; c3_i135++) {
    c3_arg[c3_i135] = chartInstance->c3_arrBML[c3_i135];
  }

  for (c3_i136 = 0; c3_i136 < 256; c3_i136++) {
    _SFD_DATA_RANGE_CHECK(c3_arg[c3_i136], 17U);
  }

  _SFD_SET_DATA_VALUE_PTR(17U, c3_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c3_arg, c3_rb_sf_marshallOut,
    c3_k_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  for (c3_i137 = 0; c3_i137 < 256; c3_i137++) {
    (*c3_b_arg)[c3_i137] = c3_arg[c3_i137];
  }

  for (c3_i138 = 0; c3_i138 < 256; c3_i138++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_arg)[c3_i138], 17U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_stateCheckUser2(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  boolean_T *c3_userStill;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c3_userStill = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_hc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_o_sf_marshallOut,
    c3_c_sf_marshallIn);
  c3_out = CV_EML_IF(3, 0, 0, (real_T)*c3_userStill == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ic_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
    chartInstance->c3_bored++;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_fc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_o_sf_marshallOut,
      c3_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(10, 0, 0, chartInstance->c3_temporalCounter_i1 >= 50)) {
      if (CV_EML_COND(10, 0, 1, chartInstance->c3_bored >=
                      chartInstance->c3_BOREDOMT)) {
        CV_EML_MCDC(10, 0, 0, true);
        CV_EML_IF(10, 0, 0, true);
        c3_b_out = true;
      } else {
        guard2 = true;
      }
    } else {
      c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 10U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(10, 0, 0, false);
      CV_EML_IF(10, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateCheckUser2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateBoredPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_temporalCounter_i1 = 0U;
      chartInstance->c3_tp_stateBoredPose = 1U;
      c3_enter_atomic_stateBoredPose(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_jc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_o_sf_marshallOut,
        c3_c_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 3U, 7U);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 6U, 10U);
      c3_c_out = CV_EML_IF(11, 0, 0, chartInstance->c3_bored <
                           chartInstance->c3_BOREDOMT);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_stateCheckUser2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateCheckUser2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
        chartInstance->c3_temporalCounter_i1 = 0U;
        chartInstance->c3_tp_stateCheckUser2 = 1U;
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_rb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_o_sf_marshallOut,
      c3_c_sf_marshallIn);
    c3_d_out = CV_EML_IF(5, 0, 0, (real_T)*c3_userStill != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_sb_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      chartInstance->c3_bored = 0.0;
      c3_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c3_bored, 7U);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c3_tp_stateCheckUser2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_ARP_02_GazeWalk = c3_IN_stateIdle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_stateIdle = 1U;
      c3_enter_atomic_stateIdle(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c3_sfEvent);
}

static real_T c3_randi(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  real_T c3_r;
  real_T c3_x;
  real_T c3_b_x;
  c3_r = c3_rand(chartInstance);
  c3_x = c3_r * 6.0;
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarFloor(c3_b_x);
  return 1.0 + c3_b_x;
}

static real_T c3_rand(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  uint32_T c3_uv2[625];
  int32_T c3_i139;
  real_T c3_d0;
  if (!chartInstance->c3_method_not_empty) {
    chartInstance->c3_method = 7U;
    chartInstance->c3_method_not_empty = true;
  }

  if (!chartInstance->c3_c_state_not_empty) {
    c3_eml_rand_mt19937ar(chartInstance, c3_uv2);
    for (c3_i139 = 0; c3_i139 < 625; c3_i139++) {
      chartInstance->c3_c_state[c3_i139] = c3_uv2[c3_i139];
    }

    chartInstance->c3_c_state_not_empty = true;
  }

  c3_d0 = c3_c_eml_rand_mt19937ar(chartInstance, chartInstance->c3_c_state);
  return c3_d0;
}

static void c3_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625])
{
  real_T c3_d1;
  int32_T c3_i140;
  c3_d1 = 5489.0;
  for (c3_i140 = 0; c3_i140 < 625; c3_i140++) {
    c3_d_state[c3_i140] = 0U;
  }

  c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d1);
}

static void c3_twister_state_vector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed, uint32_T c3_b_mt[625])
{
  int32_T c3_i141;
  for (c3_i141 = 0; c3_i141 < 625; c3_i141++) {
    c3_b_mt[c3_i141] = c3_mt[c3_i141];
  }

  c3_b_twister_state_vector(chartInstance, c3_b_mt, c3_seed);
}

static void c3_b_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625], uint32_T c3_e_state[625], real_T
  *c3_r)
{
  int32_T c3_i142;
  for (c3_i142 = 0; c3_i142 < 625; c3_i142++) {
    c3_e_state[c3_i142] = c3_d_state[c3_i142];
  }

  *c3_r = c3_c_eml_rand_mt19937ar(chartInstance, c3_e_state);
}

static void c3_eml_error(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance)
{
  int32_T c3_i143;
  static char_T c3_cv8[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c3_u[37];
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  for (c3_i143 = 0; c3_i143 < 37; c3_i143++) {
    c3_u[c3_i143] = c3_cv8[c3_i143];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_y));
}

static void c3_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[109];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[109];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i144;
  static char_T c3_cv9[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"',
    '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i145;
  static real_T c3_dv44[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i146;
  int32_T c3_i147;
  int32_T c3_i148;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i144 = 0; c3_i144 < 109; c3_i144++) {
    c3_mystr[c3_i144] = c3_cv9[c3_i144];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i145 = 0; c3_i145 < 109; c3_i145++) {
    c3_arr[c3_i145] = c3_dv44[c3_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i146 = 0; c3_i146 < 256; c3_i146++) {
    c3_tt[c3_i146] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i147 = 0; c3_i147 < 109; c3_i147++) {
    c3_tt[c3_i147] = c3_arr[c3_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i148 = 0; c3_i148 < 256; c3_i148++) {
    c3_myarr256[c3_i148] = c3_tt[c3_i148];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_b_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[87];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[87];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i149;
  static char_T c3_cv10[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c3_i150;
  static real_T c3_dv45[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i151;
  int32_T c3_i152;
  int32_T c3_i153;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i149 = 0; c3_i149 < 87; c3_i149++) {
    c3_mystr[c3_i149] = c3_cv10[c3_i149];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i150 = 0; c3_i150 < 87; c3_i150++) {
    c3_arr[c3_i150] = c3_dv45[c3_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 169.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i151 = 0; c3_i151 < 256; c3_i151++) {
    c3_tt[c3_i151] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i152 = 0; c3_i152 < 87; c3_i152++) {
    c3_tt[c3_i152] = c3_arr[c3_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i153 = 0; c3_i153 < 256; c3_i153++) {
    c3_myarr256[c3_i153] = c3_tt[c3_i153];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_c_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[93];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[93];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i154;
  static char_T c3_cv11[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i155;
  static real_T c3_dv46[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i156;
  int32_T c3_i157;
  int32_T c3_i158;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_d_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i154 = 0; c3_i154 < 93; c3_i154++) {
    c3_mystr[c3_i154] = c3_cv11[c3_i154];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i155 = 0; c3_i155 < 93; c3_i155++) {
    c3_arr[c3_i155] = c3_dv46[c3_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 163.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i156 = 0; c3_i156 < 256; c3_i156++) {
    c3_tt[c3_i156] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i157 = 0; c3_i157 < 93; c3_i157++) {
    c3_tt[c3_i157] = c3_arr[c3_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i158 = 0; c3_i158 < 256; c3_i158++) {
    c3_myarr256[c3_i158] = c3_tt[c3_i158];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_d_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[94];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[94];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i159;
  static char_T c3_cv12[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i160;
  static real_T c3_dv47[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i161;
  int32_T c3_i162;
  int32_T c3_i163;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i159 = 0; c3_i159 < 94; c3_i159++) {
    c3_mystr[c3_i159] = c3_cv12[c3_i159];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i160 = 0; c3_i160 < 94; c3_i160++) {
    c3_arr[c3_i160] = c3_dv47[c3_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 162.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i161 = 0; c3_i161 < 256; c3_i161++) {
    c3_tt[c3_i161] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i162 = 0; c3_i162 < 94; c3_i162++) {
    c3_tt[c3_i162] = c3_arr[c3_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i163 = 0; c3_i163 < 256; c3_i163++) {
    c3_myarr256[c3_i163] = c3_tt[c3_i163];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_e_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[95];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[95];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i164;
  static char_T c3_cv13[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i165;
  static real_T c3_dv48[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i164 = 0; c3_i164 < 95; c3_i164++) {
    c3_mystr[c3_i164] = c3_cv13[c3_i164];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i165 = 0; c3_i165 < 95; c3_i165++) {
    c3_arr[c3_i165] = c3_dv48[c3_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i166 = 0; c3_i166 < 256; c3_i166++) {
    c3_tt[c3_i166] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i167 = 0; c3_i167 < 95; c3_i167++) {
    c3_tt[c3_i167] = c3_arr[c3_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i168 = 0; c3_i168 < 256; c3_i168++) {
    c3_myarr256[c3_i168] = c3_tt[c3_i168];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_f_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[97];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[97];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i169;
  static char_T c3_cv14[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i170;
  static real_T c3_dv49[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i171;
  int32_T c3_i172;
  int32_T c3_i173;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i169 = 0; c3_i169 < 97; c3_i169++) {
    c3_mystr[c3_i169] = c3_cv14[c3_i169];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i170 = 0; c3_i170 < 97; c3_i170++) {
    c3_arr[c3_i170] = c3_dv49[c3_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 159.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i171 = 0; c3_i171 < 256; c3_i171++) {
    c3_tt[c3_i171] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i172 = 0; c3_i172 < 97; c3_i172++) {
    c3_tt[c3_i172] = c3_arr[c3_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i173 = 0; c3_i173 < 256; c3_i173++) {
    c3_myarr256[c3_i173] = c3_tt[c3_i173];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_g_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  char_T c3_mystr[185], real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[185];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i174;
  int32_T c3_i175;
  int32_T c3_i176;
  int32_T c3_i177;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_q_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_arr, 1U, c3_w_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mystr, 7U, c3_v_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i174 = 0; c3_i174 < 185; c3_i174++) {
    c3_arr[c3_i174] = (real_T)c3_mystr[c3_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 185.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 71.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i175 = 0; c3_i175 < 256; c3_i175++) {
    c3_tt[c3_i175] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i176 = 0; c3_i176 < 185; c3_i176++) {
    c3_tt[c3_i176] = c3_arr[c3_i176];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i177 = 0; c3_i177 < 256; c3_i177++) {
    c3_myarr256[c3_i177] = c3_tt[c3_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_h_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[184];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[184];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i178;
  static char_T c3_cv15[184] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5',
    '\"', ' ', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '2', '\"', ' ', 'a', 'm', 'o', 'u',
    'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i179;
  static real_T c3_dv50[184] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0,
    34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0,
    53.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0,
    102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0,
    65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0,
    79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i180;
  int32_T c3_i181;
  int32_T c3_i182;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_t_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i178 = 0; c3_i178 < 184; c3_i178++) {
    c3_mystr[c3_i178] = c3_cv15[c3_i178];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i179 = 0; c3_i179 < 184; c3_i179++) {
    c3_arr[c3_i179] = c3_dv50[c3_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 184.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 72.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i180 = 0; c3_i180 < 256; c3_i180++) {
    c3_tt[c3_i180] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i181 = 0; c3_i181 < 184; c3_i181++) {
    c3_tt[c3_i181] = c3_arr[c3_i181];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i182 = 0; c3_i182 < 256; c3_i182++) {
    c3_myarr256[c3_i182] = c3_tt[c3_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_i_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[112];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[112];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i183;
  static char_T c3_cv16[112] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 's', 't', 'a',
    'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"',
    ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i184;
  static real_T c3_dv51[112] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i185;
  int32_T c3_i186;
  int32_T c3_i187;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_u_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i183 = 0; c3_i183 < 112; c3_i183++) {
    c3_mystr[c3_i183] = c3_cv16[c3_i183];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i184 = 0; c3_i184 < 112; c3_i184++) {
    c3_arr[c3_i184] = c3_dv51[c3_i184];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 112.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i185 = 0; c3_i185 < 256; c3_i185++) {
    c3_tt[c3_i185] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i186 = 0; c3_i186 < 112; c3_i186++) {
    c3_tt[c3_i186] = c3_arr[c3_i186];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i187 = 0; c3_i187 < 256; c3_i187++) {
    c3_myarr256[c3_i187] = c3_tt[c3_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_j_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[245];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[245];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i188;
  static char_T c3_cv17[245] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l',
    'e', '0', '3', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    'e', 'n', 'd', '=', '\"', '1', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ',
    't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\"', 'r', 'i', 'g', 'h', 't', '\"', ' ', 'a', 'u', '=', '\"', '2',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"',
    '5', '\"', ' ', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e',
    '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'r',
    'i', 'g', 'h', 't', '\"', ' ', 'a', 'u', '=', '\"', '4', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '5', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i189;
  static real_T c3_dv52[245] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 114.0, 105.0, 103.0, 104.0, 116.0, 34.0, 32.0, 97.0,
    117.0, 61.0, 34.0, 50.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0,
    61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0,
    32.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 114.0, 105.0, 103.0, 104.0, 116.0, 34.0, 32.0, 97.0,
    117.0, 61.0, 34.0, 52.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0,
    48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c3_i190;
  int32_T c3_i191;
  int32_T c3_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_v_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i188 = 0; c3_i188 < 245; c3_i188++) {
    c3_mystr[c3_i188] = c3_cv17[c3_i188];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i189 = 0; c3_i189 < 245; c3_i189++) {
    c3_arr[c3_i189] = c3_dv52[c3_i189];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 245.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 11.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i190 = 0; c3_i190 < 256; c3_i190++) {
    c3_tt[c3_i190] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i191 = 0; c3_i191 < 245; c3_i191++) {
    c3_tt[c3_i191] = c3_arr[c3_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i192 = 0; c3_i192 < 256; c3_i192++) {
    c3_myarr256[c3_i192] = c3_tt[c3_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_k_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[105];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[105];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i193;
  static char_T c3_cv18[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l',
    'e', '0', '3', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    'e', 'n', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i194;
  static real_T c3_dv53[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c3_i195;
  int32_T c3_i196;
  int32_T c3_i197;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_ab_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i193 = 0; c3_i193 < 105; c3_i193++) {
    c3_mystr[c3_i193] = c3_cv18[c3_i193];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i194 = 0; c3_i194 < 105; c3_i194++) {
    c3_arr[c3_i194] = c3_dv53[c3_i194];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i195 = 0; c3_i195 < 256; c3_i195++) {
    c3_tt[c3_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i196 = 0; c3_i196 < 105; c3_i196++) {
    c3_tt[c3_i196] = c3_arr[c3_i196];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i197 = 0; c3_i197 < 256; c3_i197++) {
    c3_myarr256[c3_i197] = c3_tt[c3_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_l_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[110];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[110];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i198;
  static char_T c3_cv19[110] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h',
    't', 'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't',
    '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i199;
  static real_T c3_dv54[110] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i200;
  int32_T c3_i201;
  int32_T c3_i202;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_bb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i198 = 0; c3_i198 < 110; c3_i198++) {
    c3_mystr[c3_i198] = c3_cv19[c3_i198];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i199 = 0; c3_i199 < 110; c3_i199++) {
    c3_arr[c3_i199] = c3_dv54[c3_i199];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 110.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 146.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i200 = 0; c3_i200 < 256; c3_i200++) {
    c3_tt[c3_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i201 = 0; c3_i201 < 110; c3_i201++) {
    c3_tt[c3_i201] = c3_arr[c3_i201];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i202 = 0; c3_i202 < 256; c3_i202++) {
    c3_myarr256[c3_i202] = c3_tt[c3_i202];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_m_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[111];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[111];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i203;
  static char_T c3_cv20[111] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i204;
  static real_T c3_dv55[111] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i205;
  int32_T c3_i206;
  int32_T c3_i207;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_cb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i203 = 0; c3_i203 < 111; c3_i203++) {
    c3_mystr[c3_i203] = c3_cv20[c3_i203];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i204 = 0; c3_i204 < 111; c3_i204++) {
    c3_arr[c3_i204] = c3_dv55[c3_i204];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 145.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i205 = 0; c3_i205 < 256; c3_i205++) {
    c3_tt[c3_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i206 = 0; c3_i206 < 111; c3_i206++) {
    c3_tt[c3_i206] = c3_arr[c3_i206];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i207 = 0; c3_i207 < 256; c3_i207++) {
    c3_myarr256[c3_i207] = c3_tt[c3_i207];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_n_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[112];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[112];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i208;
  static char_T c3_cv21[112] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 't', 'a',
    'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i209;
  static real_T c3_dv56[112] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c3_i210;
  int32_T c3_i211;
  int32_T c3_i212;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_db_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i208 = 0; c3_i208 < 112; c3_i208++) {
    c3_mystr[c3_i208] = c3_cv21[c3_i208];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i209 = 0; c3_i209 < 112; c3_i209++) {
    c3_arr[c3_i209] = c3_dv56[c3_i209];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 112.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i210 = 0; c3_i210 < 256; c3_i210++) {
    c3_tt[c3_i210] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i211 = 0; c3_i211 < 112; c3_i211++) {
    c3_tt[c3_i211] = c3_arr[c3_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i212 = 0; c3_i212 < 256; c3_i212++) {
    c3_myarr256[c3_i212] = c3_tt[c3_i212];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_o_encStr2Arr(SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance,
  real_T c3_myarr256[256])
{
  uint32_T c3_debug_family_var_map[9];
  real_T c3_maxarrsize;
  real_T c3_arr[114];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  char_T c3_mystr[114];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  int32_T c3_i213;
  static char_T c3_cv22[114] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c3_i214;
  static real_T c3_dv57[114] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c3_i215;
  int32_T c3_i216;
  int32_T c3_i217;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_eb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_arr, 1U, c3_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ss, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_mystr, 5U, c3_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_myarr256, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  for (c3_i213 = 0; c3_i213 < 114; c3_i213++) {
    c3_mystr[c3_i213] = c3_cv22[c3_i213];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  for (c3_i214 = 0; c3_i214 < 114; c3_i214++) {
    c3_arr[c3_i214] = c3_dv57[c3_i214];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = 114.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i215 = 0; c3_i215 < 256; c3_i215++) {
    c3_tt[c3_i215] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i216 = 0; c3_i216 < 114; c3_i216++) {
    c3_tt[c3_i216] = c3_arr[c3_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i217 = 0; c3_i217 < 256; c3_i217++) {
    c3_myarr256[c3_i217] = c3_tt[c3_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_cmdBML_walkOppositeUser(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, real_T c3_x, real_T c3_b_arrBML[256], real_T *c3_agentPosition)
{
  uint32_T c3_debug_family_var_map[7];
  real_T c3_c;
  int32_T c3_mystr_sizes[2];
  char_T c3_mystr_data[116];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 2.0;
  real_T c3_A;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_n;
  real_T c3_dv58[2];
  int32_T c3_iv0[2];
  int32_T c3_mystr;
  int32_T c3_b_mystr;
  int32_T c3_loop_ub;
  int32_T c3_i218;
  int32_T c3_i219;
  static char_T c3_cv23[113] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?',
    '>', '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c',
    'o', 'm', 'o', 't', 'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=',
    '\\', '\"', 'w', 'a', 'l', 'k', '\\', '\"', ' ', 'f', 'a', 'c', 'i', 'n',
    'g', '=', '\\', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\\', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\\', '\"', '%', '0', '.', '2', 'f', ' ', '%',
    'd', '\\', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c3_u[113];
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[116];
  int32_T c3_c_mystr;
  int32_T c3_d_mystr;
  int32_T c3_b_loop_ub;
  int32_T c3_i220;
  int32_T c3_b_mystr_sizes[2];
  int32_T c3_e_mystr;
  int32_T c3_f_mystr;
  int32_T c3_c_loop_ub;
  int32_T c3_i221;
  char_T c3_b_mystr_data[116];
  uint32_T c3_b_debug_family_var_map[9];
  real_T c3_maxarrsize;
  int32_T c3_arr_sizes;
  real_T c3_arr_data[116];
  real_T c3_ss;
  real_T c3_padsize;
  real_T c3_tt[256];
  real_T c3_b_nargin = 1.0;
  real_T c3_b_nargout = 1.0;
  int32_T c3_d_loop_ub;
  int32_T c3_i222;
  int32_T c3_i223;
  boolean_T c3_b0;
  boolean_T c3_b1;
  boolean_T c3_b2;
  int32_T c3_i224;
  int32_T c3_b_tmp_sizes;
  int32_T c3_e_loop_ub;
  int32_T c3_i225;
  int32_T c3_b_tmp_data[116];
  int32_T c3_iv1[1];
  int32_T c3_f_loop_ub;
  int32_T c3_i226;
  int32_T c3_i227;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_jb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_mystr_data, (const int32_T *)
    &c3_mystr_sizes, NULL, 0, 1, (void *)c3_mb_sf_marshallOut, (void *)
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_arrBML, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_agentPosition, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 2);
  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 8);
  c3_A = c3_x - 200.0;
  c3_b_x = c3_A;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  c3_x = c3_d_x / 200.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 11);
  if (CV_SCRIPT_IF(2, 0, c3_x > 1.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 12);
    c3_x--;
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 14);
    c3_x++;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 20);
  c3_e_x = c3_x * 200.0 + 200.0;
  *c3_agentPosition = c3_e_x;
  c3_f_x = *c3_agentPosition;
  *c3_agentPosition = c3_f_x;
  *c3_agentPosition = muDoubleScalarRound(*c3_agentPosition);
  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 23);
  if (CV_SCRIPT_IF(2, 1, c3_x < 0.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 24);
    c3_c = 116.0;
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 26);
    c3_c = 115.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 29);
  c3_n = c3_c;
  c3_dv58[0] = 1.0;
  c3_dv58[1] = c3_n;
  c3_mystr_sizes[0] = 1;
  c3_iv0[0] = 1;
  c3_iv0[1] = (int32_T)c3_dv58[1];
  c3_mystr_sizes[1] = c3_iv0[1];
  c3_mystr = c3_mystr_sizes[0];
  c3_b_mystr = c3_mystr_sizes[1];
  c3_loop_ub = (int32_T)c3_dv58[1] - 1;
  for (c3_i218 = 0; c3_i218 <= c3_loop_ub; c3_i218++) {
    c3_mystr_data[c3_i218] = ' ';
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 30);
  for (c3_i219 = 0; c3_i219 < 113; c3_i219++) {
    c3_u[c3_i219] = c3_cv23[c3_i219];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 113),
                false);
  c3_b_u = c3_x;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  c3_c_u = 0.0;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14,
    c3_y, 14, c3_b_y, 14, c3_c_y), "sprintf", c3_tmp_data, c3_tmp_sizes);
  c3_mystr_sizes[0] = 1;
  c3_mystr_sizes[1] = c3_tmp_sizes[1];
  c3_c_mystr = c3_mystr_sizes[0];
  c3_d_mystr = c3_mystr_sizes[1];
  c3_b_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i220 = 0; c3_i220 <= c3_b_loop_ub; c3_i220++) {
    c3_mystr_data[c3_i220] = c3_tmp_data[c3_i220];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, 31);
  c3_b_mystr_sizes[0] = 1;
  c3_b_mystr_sizes[1] = c3_mystr_sizes[1];
  c3_e_mystr = c3_b_mystr_sizes[0];
  c3_f_mystr = c3_b_mystr_sizes[1];
  c3_c_loop_ub = c3_mystr_sizes[0] * c3_mystr_sizes[1] - 1;
  for (c3_i221 = 0; c3_i221 <= c3_c_loop_ub; c3_i221++) {
    c3_b_mystr_data[c3_i221] = c3_mystr_data[c3_i221];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c3_ib_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_maxarrsize, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_arr_data, (const int32_T *)
    &c3_arr_sizes, NULL, 0, 1, (void *)c3_nb_sf_marshallOut, (void *)
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ss, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_padsize, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_tt, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c3_b_mystr_data, (const int32_T *)
    &c3_b_mystr_sizes, NULL, 1, 7, (void *)c3_mb_sf_marshallOut, (void *)
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_arrBML, 8U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_arr_sizes = c3_b_mystr_sizes[1];
  c3_d_loop_ub = c3_b_mystr_sizes[1] - 1;
  for (c3_i222 = 0; c3_i222 <= c3_d_loop_ub; c3_i222++) {
    c3_arr_data[c3_i222] = (real_T)c3_b_mystr_data[c3_b_mystr_sizes[0] * c3_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_ss = (real_T)c3_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_padsize = 256.0 - c3_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i223 = 0; c3_i223 < 256; c3_i223++) {
    c3_tt[c3_i223] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  c3_b0 = (1.0 > c3_ss);
  c3_b1 = c3_b0;
  c3_b2 = c3_b1;
  if (c3_b2) {
    c3_i224 = 0;
  } else {
    c3_i224 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c3_ss, 1, 256, 0, 0);
  }

  c3_b_tmp_sizes = c3_i224;
  c3_e_loop_ub = c3_i224 - 1;
  for (c3_i225 = 0; c3_i225 <= c3_e_loop_ub; c3_i225++) {
    c3_b_tmp_data[c3_i225] = c3_i225;
  }

  c3_iv1[0] = c3_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c3_iv1, 1, *(int32_T (*)[1])&c3_arr_sizes, 1);
  c3_f_loop_ub = c3_arr_sizes - 1;
  for (c3_i226 = 0; c3_i226 <= c3_f_loop_ub; c3_i226++) {
    c3_tt[c3_b_tmp_data[c3_i226]] = c3_arr_data[c3_i226];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  for (c3_i227 = 0; c3_i227 < 256; c3_i227++) {
    c3_b_arrBML[c3_i227] = c3_tt[c3_i227];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(2U, chartInstance->c3_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\cmdBML_smileS.m"));
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\cmdBML_walkOppositeUser.m"));
}

static void c3_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[185])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_b_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[185])
{
  char_T c3_cv24[185];
  int32_T c3_i228;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv24, 1, 10, 0U, 1, 0U, 2, 1,
                185);
  for (c3_i228 = 0; c3_i228 < 185; c3_i228++) {
    c3_y[c3_i228] = c3_cv24[c3_i228];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y_data[], int32_T c3_y_sizes[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_d_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i229;
  uint32_T c3_uv3[2];
  int32_T c3_i230;
  static boolean_T c3_bv0[2] = { false, true };

  boolean_T c3_bv1[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[116];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i231;
  (void)chartInstance;
  for (c3_i229 = 0; c3_i229 < 2; c3_i229++) {
    c3_uv3[c3_i229] = 1U + 115U * (uint32_T)c3_i229;
  }

  for (c3_i230 = 0; c3_i230 < 2; c3_i230++) {
    c3_bv1[c3_i230] = c3_bv0[c3_i230];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c3_bv1, c3_uv3, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i231 = 0; c3_i231 <= c3_loop_ub; c3_i231++) {
    c3_y_data[c3_i231] = c3_tmp_data[c3_i231];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_f_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
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
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i232;
  real_T c3_b_inData[256];
  int32_T c3_i233;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i232 = 0; c3_i232 < 256; c3_i232++) {
    c3_b_inData[c3_i232] = (*(real_T (*)[256])c3_inData)[c3_i232];
  }

  for (c3_i233 = 0; c3_i233 < 256; c3_i233++) {
    c3_u[c3_i233] = c3_b_inData[c3_i233];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_myarr256, const char_T *c3_identifier,
  real_T c3_y[256])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
}

static void c3_h_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv59[256];
  int32_T c3_i234;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv59, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i234 = 0; c3_i234 < 256; c3_i234++) {
    c3_y[c3_i234] = c3_dv59[c3_i234];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i235;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i235 = 0; c3_i235 < 256; c3_i235++) {
    (*(real_T (*)[256])c3_outData)[c3_i235] = c3_y[c3_i235];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i236;
  char_T c3_b_inData[109];
  int32_T c3_i237;
  char_T c3_u[109];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i236 = 0; c3_i236 < 109; c3_i236++) {
    c3_b_inData[c3_i236] = (*(char_T (*)[109])c3_inData)[c3_i236];
  }

  for (c3_i237 = 0; c3_i237 < 109; c3_i237++) {
    c3_u[c3_i237] = c3_b_inData[c3_i237];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i238;
  real_T c3_b_inData[109];
  int32_T c3_i239;
  real_T c3_u[109];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i238 = 0; c3_i238 < 109; c3_i238++) {
    c3_b_inData[c3_i238] = (*(real_T (*)[109])c3_inData)[c3_i238];
  }

  for (c3_i239 = 0; c3_i239 < 109; c3_i239++) {
    c3_u[c3_i239] = c3_b_inData[c3_i239];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i240;
  char_T c3_b_inData[87];
  int32_T c3_i241;
  char_T c3_u[87];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i240 = 0; c3_i240 < 87; c3_i240++) {
    c3_b_inData[c3_i240] = (*(char_T (*)[87])c3_inData)[c3_i240];
  }

  for (c3_i241 = 0; c3_i241 < 87; c3_i241++) {
    c3_u[c3_i241] = c3_b_inData[c3_i241];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i242;
  real_T c3_b_inData[87];
  int32_T c3_i243;
  real_T c3_u[87];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i242 = 0; c3_i242 < 87; c3_i242++) {
    c3_b_inData[c3_i242] = (*(real_T (*)[87])c3_inData)[c3_i242];
  }

  for (c3_i243 = 0; c3_i243 < 87; c3_i243++) {
    c3_u[c3_i243] = c3_b_inData[c3_i243];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i244;
  char_T c3_b_inData[93];
  int32_T c3_i245;
  char_T c3_u[93];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i244 = 0; c3_i244 < 93; c3_i244++) {
    c3_b_inData[c3_i244] = (*(char_T (*)[93])c3_inData)[c3_i244];
  }

  for (c3_i245 = 0; c3_i245 < 93; c3_i245++) {
    c3_u[c3_i245] = c3_b_inData[c3_i245];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i246;
  real_T c3_b_inData[93];
  int32_T c3_i247;
  real_T c3_u[93];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i246 = 0; c3_i246 < 93; c3_i246++) {
    c3_b_inData[c3_i246] = (*(real_T (*)[93])c3_inData)[c3_i246];
  }

  for (c3_i247 = 0; c3_i247 < 93; c3_i247++) {
    c3_u[c3_i247] = c3_b_inData[c3_i247];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i248;
  char_T c3_b_inData[94];
  int32_T c3_i249;
  char_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i248 = 0; c3_i248 < 94; c3_i248++) {
    c3_b_inData[c3_i248] = (*(char_T (*)[94])c3_inData)[c3_i248];
  }

  for (c3_i249 = 0; c3_i249 < 94; c3_i249++) {
    c3_u[c3_i249] = c3_b_inData[c3_i249];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i250;
  real_T c3_b_inData[94];
  int32_T c3_i251;
  real_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i250 = 0; c3_i250 < 94; c3_i250++) {
    c3_b_inData[c3_i250] = (*(real_T (*)[94])c3_inData)[c3_i250];
  }

  for (c3_i251 = 0; c3_i251 < 94; c3_i251++) {
    c3_u[c3_i251] = c3_b_inData[c3_i251];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i252;
  char_T c3_b_inData[95];
  int32_T c3_i253;
  char_T c3_u[95];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i252 = 0; c3_i252 < 95; c3_i252++) {
    c3_b_inData[c3_i252] = (*(char_T (*)[95])c3_inData)[c3_i252];
  }

  for (c3_i253 = 0; c3_i253 < 95; c3_i253++) {
    c3_u[c3_i253] = c3_b_inData[c3_i253];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i254;
  real_T c3_b_inData[95];
  int32_T c3_i255;
  real_T c3_u[95];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i254 = 0; c3_i254 < 95; c3_i254++) {
    c3_b_inData[c3_i254] = (*(real_T (*)[95])c3_inData)[c3_i254];
  }

  for (c3_i255 = 0; c3_i255 < 95; c3_i255++) {
    c3_u[c3_i255] = c3_b_inData[c3_i255];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i256;
  char_T c3_b_inData[97];
  int32_T c3_i257;
  char_T c3_u[97];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i256 = 0; c3_i256 < 97; c3_i256++) {
    c3_b_inData[c3_i256] = (*(char_T (*)[97])c3_inData)[c3_i256];
  }

  for (c3_i257 = 0; c3_i257 < 97; c3_i257++) {
    c3_u[c3_i257] = c3_b_inData[c3_i257];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i258;
  real_T c3_b_inData[97];
  int32_T c3_i259;
  real_T c3_u[97];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i258 = 0; c3_i258 < 97; c3_i258++) {
    c3_b_inData[c3_i258] = (*(real_T (*)[97])c3_inData)[c3_i258];
  }

  for (c3_i259 = 0; c3_i259 < 97; c3_i259++) {
    c3_u[c3_i259] = c3_b_inData[c3_i259];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_i_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b3, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_aVarTruthTableCondition_8;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_aVarTruthTableCondition_8 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_8), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_8);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i260;
  char_T c3_b_inData[103];
  int32_T c3_i261;
  char_T c3_u[103];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i260 = 0; c3_i260 < 103; c3_i260++) {
    c3_b_inData[c3_i260] = (*(char_T (*)[103])c3_inData)[c3_i260];
  }

  for (c3_i261 = 0; c3_i261 < 103; c3_i261++) {
    c3_u[c3_i261] = c3_b_inData[c3_i261];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i262;
  real_T c3_b_inData[103];
  int32_T c3_i263;
  real_T c3_u[103];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i262 = 0; c3_i262 < 103; c3_i262++) {
    c3_b_inData[c3_i262] = (*(real_T (*)[103])c3_inData)[c3_i262];
  }

  for (c3_i263 = 0; c3_i263 < 103; c3_i263++) {
    c3_u[c3_i263] = c3_b_inData[c3_i263];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i264;
  char_T c3_b_inData[99];
  int32_T c3_i265;
  char_T c3_u[99];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i264 = 0; c3_i264 < 99; c3_i264++) {
    c3_b_inData[c3_i264] = (*(char_T (*)[99])c3_inData)[c3_i264];
  }

  for (c3_i265 = 0; c3_i265 < 99; c3_i265++) {
    c3_u[c3_i265] = c3_b_inData[c3_i265];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i266;
  real_T c3_b_inData[99];
  int32_T c3_i267;
  real_T c3_u[99];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i266 = 0; c3_i266 < 99; c3_i266++) {
    c3_b_inData[c3_i266] = (*(real_T (*)[99])c3_inData)[c3_i266];
  }

  for (c3_i267 = 0; c3_i267 < 99; c3_i267++) {
    c3_u[c3_i267] = c3_b_inData[c3_i267];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i268;
  char_T c3_b_inData[100];
  int32_T c3_i269;
  char_T c3_u[100];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i268 = 0; c3_i268 < 100; c3_i268++) {
    c3_b_inData[c3_i268] = (*(char_T (*)[100])c3_inData)[c3_i268];
  }

  for (c3_i269 = 0; c3_i269 < 100; c3_i269++) {
    c3_u[c3_i269] = c3_b_inData[c3_i269];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 100),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i270;
  real_T c3_b_inData[100];
  int32_T c3_i271;
  real_T c3_u[100];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i270 = 0; c3_i270 < 100; c3_i270++) {
    c3_b_inData[c3_i270] = (*(real_T (*)[100])c3_inData)[c3_i270];
  }

  for (c3_i271 = 0; c3_i271 < 100; c3_i271++) {
    c3_u[c3_i271] = c3_b_inData[c3_i271];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 100), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i272;
  char_T c3_b_inData[185];
  int32_T c3_i273;
  char_T c3_u[185];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i272 = 0; c3_i272 < 185; c3_i272++) {
    c3_b_inData[c3_i272] = (*(char_T (*)[185])c3_inData)[c3_i272];
  }

  for (c3_i273 = 0; c3_i273 < 185; c3_i273++) {
    c3_u[c3_i273] = c3_b_inData[c3_i273];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 185),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sprintf;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[185];
  int32_T c3_i274;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_sprintf = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
  for (c3_i274 = 0; c3_i274 < 185; c3_i274++) {
    (*(char_T (*)[185])c3_outData)[c3_i274] = c3_y[c3_i274];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i275;
  real_T c3_b_inData[185];
  int32_T c3_i276;
  real_T c3_u[185];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i275 = 0; c3_i275 < 185; c3_i275++) {
    c3_b_inData[c3_i275] = (*(real_T (*)[185])c3_inData)[c3_i275];
  }

  for (c3_i276 = 0; c3_i276 < 185; c3_i276++) {
    c3_u[c3_i276] = c3_b_inData[c3_i276];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 185), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_j_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[185])
{
  real_T c3_dv60[185];
  int32_T c3_i277;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv60, 1, 0, 0U, 1, 0U, 1, 185);
  for (c3_i277 = 0; c3_i277 < 185; c3_i277++) {
    c3_y[c3_i277] = c3_dv60[c3_i277];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[185];
  int32_T c3_i278;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arr);
  for (c3_i278 = 0; c3_i278 < 185; c3_i278++) {
    (*(real_T (*)[185])c3_outData)[c3_i278] = c3_y[c3_i278];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i279;
  char_T c3_b_inData[184];
  int32_T c3_i280;
  char_T c3_u[184];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i279 = 0; c3_i279 < 184; c3_i279++) {
    c3_b_inData[c3_i279] = (*(char_T (*)[184])c3_inData)[c3_i279];
  }

  for (c3_i280 = 0; c3_i280 < 184; c3_i280++) {
    c3_u[c3_i280] = c3_b_inData[c3_i280];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 184),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i281;
  real_T c3_b_inData[184];
  int32_T c3_i282;
  real_T c3_u[184];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i281 = 0; c3_i281 < 184; c3_i281++) {
    c3_b_inData[c3_i281] = (*(real_T (*)[184])c3_inData)[c3_i281];
  }

  for (c3_i282 = 0; c3_i282 < 184; c3_i282++) {
    c3_u[c3_i282] = c3_b_inData[c3_i282];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 184), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i283;
  char_T c3_b_inData[112];
  int32_T c3_i284;
  char_T c3_u[112];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i283 = 0; c3_i283 < 112; c3_i283++) {
    c3_b_inData[c3_i283] = (*(char_T (*)[112])c3_inData)[c3_i283];
  }

  for (c3_i284 = 0; c3_i284 < 112; c3_i284++) {
    c3_u[c3_i284] = c3_b_inData[c3_i284];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 112),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i285;
  real_T c3_b_inData[112];
  int32_T c3_i286;
  real_T c3_u[112];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i285 = 0; c3_i285 < 112; c3_i285++) {
    c3_b_inData[c3_i285] = (*(real_T (*)[112])c3_inData)[c3_i285];
  }

  for (c3_i286 = 0; c3_i286 < 112; c3_i286++) {
    c3_u[c3_i286] = c3_b_inData[c3_i286];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 112), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i287;
  char_T c3_b_inData[245];
  int32_T c3_i288;
  char_T c3_u[245];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i287 = 0; c3_i287 < 245; c3_i287++) {
    c3_b_inData[c3_i287] = (*(char_T (*)[245])c3_inData)[c3_i287];
  }

  for (c3_i288 = 0; c3_i288 < 245; c3_i288++) {
    c3_u[c3_i288] = c3_b_inData[c3_i288];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 245),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_db_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i289;
  real_T c3_b_inData[245];
  int32_T c3_i290;
  real_T c3_u[245];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i289 = 0; c3_i289 < 245; c3_i289++) {
    c3_b_inData[c3_i289] = (*(real_T (*)[245])c3_inData)[c3_i289];
  }

  for (c3_i290 = 0; c3_i290 < 245; c3_i290++) {
    c3_u[c3_i290] = c3_b_inData[c3_i290];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 245), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i291;
  char_T c3_b_inData[105];
  int32_T c3_i292;
  char_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i291 = 0; c3_i291 < 105; c3_i291++) {
    c3_b_inData[c3_i291] = (*(char_T (*)[105])c3_inData)[c3_i291];
  }

  for (c3_i292 = 0; c3_i292 < 105; c3_i292++) {
    c3_u[c3_i292] = c3_b_inData[c3_i292];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i293;
  real_T c3_b_inData[105];
  int32_T c3_i294;
  real_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i293 = 0; c3_i293 < 105; c3_i293++) {
    c3_b_inData[c3_i293] = (*(real_T (*)[105])c3_inData)[c3_i293];
  }

  for (c3_i294 = 0; c3_i294 < 105; c3_i294++) {
    c3_u[c3_i294] = c3_b_inData[c3_i294];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i295;
  char_T c3_b_inData[110];
  int32_T c3_i296;
  char_T c3_u[110];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i295 = 0; c3_i295 < 110; c3_i295++) {
    c3_b_inData[c3_i295] = (*(char_T (*)[110])c3_inData)[c3_i295];
  }

  for (c3_i296 = 0; c3_i296 < 110; c3_i296++) {
    c3_u[c3_i296] = c3_b_inData[c3_i296];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 110),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i297;
  real_T c3_b_inData[110];
  int32_T c3_i298;
  real_T c3_u[110];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i297 = 0; c3_i297 < 110; c3_i297++) {
    c3_b_inData[c3_i297] = (*(real_T (*)[110])c3_inData)[c3_i297];
  }

  for (c3_i298 = 0; c3_i298 < 110; c3_i298++) {
    c3_u[c3_i298] = c3_b_inData[c3_i298];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 110), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i299;
  char_T c3_b_inData[111];
  int32_T c3_i300;
  char_T c3_u[111];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i299 = 0; c3_i299 < 111; c3_i299++) {
    c3_b_inData[c3_i299] = (*(char_T (*)[111])c3_inData)[c3_i299];
  }

  for (c3_i300 = 0; c3_i300 < 111; c3_i300++) {
    c3_u[c3_i300] = c3_b_inData[c3_i300];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i301;
  real_T c3_b_inData[111];
  int32_T c3_i302;
  real_T c3_u[111];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i301 = 0; c3_i301 < 111; c3_i301++) {
    c3_b_inData[c3_i301] = (*(real_T (*)[111])c3_inData)[c3_i301];
  }

  for (c3_i302 = 0; c3_i302 < 111; c3_i302++) {
    c3_u[c3_i302] = c3_b_inData[c3_i302];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i303;
  char_T c3_b_inData[114];
  int32_T c3_i304;
  char_T c3_u[114];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i303 = 0; c3_i303 < 114; c3_i303++) {
    c3_b_inData[c3_i303] = (*(char_T (*)[114])c3_inData)[c3_i303];
  }

  for (c3_i304 = 0; c3_i304 < 114; c3_i304++) {
    c3_u[c3_i304] = c3_b_inData[c3_i304];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 114),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i305;
  real_T c3_b_inData[114];
  int32_T c3_i306;
  real_T c3_u[114];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i305 = 0; c3_i305 < 114; c3_i305++) {
    c3_b_inData[c3_i305] = (*(real_T (*)[114])c3_inData)[c3_i305];
  }

  for (c3_i306 = 0; c3_i306 < 114; c3_i306++) {
    c3_u[c3_i306] = c3_b_inData[c3_i306];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 114), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_mb_sf_marshallOut(void *chartInstanceVoid, char_T
  c3_inData_data[], int32_T c3_inData_sizes[2])
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes[2];
  int32_T c3_loop_ub;
  int32_T c3_i307;
  char_T c3_b_inData_data[116];
  int32_T c3_u_sizes[2];
  int32_T c3_b_loop_ub;
  int32_T c3_i308;
  char_T c3_u_data[116];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes[0] = 1;
  c3_b_inData_sizes[1] = c3_inData_sizes[1];
  c3_loop_ub = c3_inData_sizes[1] - 1;
  for (c3_i307 = 0; c3_i307 <= c3_loop_ub; c3_i307++) {
    c3_b_inData_data[c3_b_inData_sizes[0] * c3_i307] =
      c3_inData_data[c3_inData_sizes[0] * c3_i307];
  }

  c3_u_sizes[0] = 1;
  c3_u_sizes[1] = c3_b_inData_sizes[1];
  c3_b_loop_ub = c3_b_inData_sizes[1] - 1;
  for (c3_i308 = 0; c3_i308 <= c3_b_loop_ub; c3_i308++) {
    c3_u_data[c3_u_sizes[0] * c3_i308] = c3_b_inData_data[c3_b_inData_sizes[0] *
      c3_i308];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 10, 0U, 1U, 0U, 2,
    c3_u_sizes[0], c3_u_sizes[1]), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_k_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y_data[], int32_T c3_y_sizes[2])
{
  int32_T c3_i309;
  uint32_T c3_uv4[2];
  int32_T c3_i310;
  static boolean_T c3_bv2[2] = { false, true };

  boolean_T c3_bv3[2];
  int32_T c3_tmp_sizes[2];
  char_T c3_tmp_data[116];
  int32_T c3_y;
  int32_T c3_b_y;
  int32_T c3_loop_ub;
  int32_T c3_i311;
  (void)chartInstance;
  for (c3_i309 = 0; c3_i309 < 2; c3_i309++) {
    c3_uv4[c3_i309] = 1U + 115U * (uint32_T)c3_i309;
  }

  for (c3_i310 = 0; c3_i310 < 2; c3_i310++) {
    c3_bv3[c3_i310] = c3_bv2[c3_i310];
  }

  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c3_bv3, c3_uv4, c3_tmp_sizes);
  c3_y_sizes[0] = 1;
  c3_y_sizes[1] = c3_tmp_sizes[1];
  c3_y = c3_y_sizes[0];
  c3_b_y = c3_y_sizes[1];
  c3_loop_ub = c3_tmp_sizes[0] * c3_tmp_sizes[1] - 1;
  for (c3_i311 = 0; c3_i311 <= c3_loop_ub; c3_i311++) {
    c3_y_data[c3_i311] = c3_tmp_data[c3_i311];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, char_T c3_outData_data[], int32_T
  c3_outData_sizes[2])
{
  const mxArray *c3_mystr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes[2];
  char_T c3_y_data[116];
  int32_T c3_loop_ub;
  int32_T c3_i312;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mystr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mystr), &c3_thisId,
                        c3_y_data, c3_y_sizes);
  sf_mex_destroy(&c3_mystr);
  c3_outData_sizes[0] = 1;
  c3_outData_sizes[1] = c3_y_sizes[1];
  c3_loop_ub = c3_y_sizes[1] - 1;
  for (c3_i312 = 0; c3_i312 <= c3_loop_ub; c3_i312++) {
    c3_outData_data[c3_outData_sizes[0] * c3_i312] = c3_y_data[c3_y_sizes[0] *
      c3_i312];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_nb_sf_marshallOut(void *chartInstanceVoid, real_T
  c3_inData_data[], int32_T *c3_inData_sizes)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_inData_sizes;
  int32_T c3_loop_ub;
  int32_T c3_i313;
  real_T c3_b_inData_data[116];
  int32_T c3_u_sizes;
  int32_T c3_b_loop_ub;
  int32_T c3_i314;
  real_T c3_u_data[116];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_inData_sizes = *c3_inData_sizes;
  c3_loop_ub = *c3_inData_sizes - 1;
  for (c3_i313 = 0; c3_i313 <= c3_loop_ub; c3_i313++) {
    c3_b_inData_data[c3_i313] = c3_inData_data[c3_i313];
  }

  c3_u_sizes = c3_b_inData_sizes;
  c3_b_loop_ub = c3_b_inData_sizes - 1;
  for (c3_i314 = 0; c3_i314 <= c3_b_loop_ub; c3_i314++) {
    c3_u_data[c3_i314] = c3_b_inData_data[c3_i314];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u_data, 0, 0U, 1U, 0U, 1,
    c3_u_sizes), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_l_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y_data[], int32_T *c3_y_sizes)
{
  static uint32_T c3_uv5[1] = { 116U };

  uint32_T c3_uv6[1];
  static boolean_T c3_bv4[1] = { true };

  boolean_T c3_bv5[1];
  int32_T c3_tmp_sizes;
  real_T c3_tmp_data[116];
  int32_T c3_loop_ub;
  int32_T c3_i315;
  (void)chartInstance;
  c3_uv6[0] = c3_uv5[0];
  c3_bv5[0] = c3_bv4[0];
  sf_mex_import_vs(c3_parentId, sf_mex_dup(c3_u), c3_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c3_bv5, c3_uv6, &c3_tmp_sizes);
  *c3_y_sizes = c3_tmp_sizes;
  c3_loop_ub = c3_tmp_sizes - 1;
  for (c3_i315 = 0; c3_i315 <= c3_loop_ub; c3_i315++) {
    c3_y_data[c3_i315] = c3_tmp_data[c3_i315];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, real_T c3_outData_data[], int32_T
  *c3_outData_sizes)
{
  const mxArray *c3_arr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y_sizes;
  real_T c3_y_data[116];
  int32_T c3_loop_ub;
  int32_T c3_i316;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_arr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arr), &c3_thisId, c3_y_data,
                        &c3_y_sizes);
  sf_mex_destroy(&c3_arr);
  *c3_outData_sizes = c3_y_sizes;
  c3_loop_ub = c3_y_sizes - 1;
  for (c3_i316 = 0; c3_i316 <= c3_loop_ub; c3_i316++) {
    c3_outData_data[c3_i316] = c3_y_data[c3_i316];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_ARP_02_GazeWalk_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 48, 1),
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
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("randi"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rand"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eps"), "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_eps"), "name", "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isequal"), "name", "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnan"), "name", "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_smileS"), "name",
                  "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_smileS.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1414606952U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_smileS.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_smileS.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cmdBML_walkOppositeUser"),
                  "name", "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_walkOppositeUser.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1414452790U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_walkOppositeUser.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_walkOppositeUser.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("round"), "name", "name", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_walkOppositeUser.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("blanks"), "name", "name", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/cmdBML_walkOppositeUser.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
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
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
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

static const mxArray *c3_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_m_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i317;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i317, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i317;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_secs;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_secs = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_secs), &c3_thisId);
  sf_mex_destroy(&c3_secs);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_n_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i318;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i318, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i318;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_o_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_stateBoredPose1, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_stateBoredPose1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_stateBoredPose1);
  return c3_y;
}

static uint8_T c3_p_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
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

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_stateBoredPose1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_b_tp_stateBoredPose1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_stateBoredPose1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_stateBoredPose1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i319;
  real_T c3_b_inData[256];
  int32_T c3_i320;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i319 = 0; c3_i319 < 256; c3_i319++) {
    c3_b_inData[c3_i319] = (*(real_T (*)[256])c3_inData)[c3_i319];
  }

  for (c3_i320 = 0; c3_i320 < 256; c3_i320++) {
    c3_u[c3_i320] = c3_b_inData[c3_i320];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_q_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv61[256];
  int32_T c3_i321;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv61, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i321 = 0; c3_i321 < 256; c3_i321++) {
    c3_y[c3_i321] = c3_dv61[c3_i321];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_arg;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i322;
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)chartInstanceVoid;
  c3_arg = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_arg), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_arg);
  for (c3_i322 = 0; c3_i322 < 256; c3_i322++) {
    (*(real_T (*)[256])c3_outData)[c3_i322] = c3_y[c3_i322];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static uint32_T c3_r_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_method, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_method),
    &c3_thisId);
  sf_mex_destroy(&c3_b_method);
  return c3_y;
}

static uint32_T c3_s_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u1;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_method_not_empty = false;
  } else {
    chartInstance->c3_method_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint32_T c3_t_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId);
  sf_mex_destroy(&c3_d_state);
  return c3_y;
}

static uint32_T c3_u_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u2;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_state_not_empty = false;
  } else {
    chartInstance->c3_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_v_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[625])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_w_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[625])
{
  uint32_T c3_uv7[625];
  int32_T c3_i323;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_c_state_not_empty = false;
  } else {
    chartInstance->c3_c_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv7, 1, 7, 0U, 1, 0U, 1, 625);
    for (c3_i323 = 0; c3_i323 < 625; c3_i323++) {
      c3_y[c3_i323] = c3_uv7[c3_i323];
    }
  }

  sf_mex_destroy(&c3_u);
}

static void c3_x_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_d_state, const char_T *c3_identifier,
  uint32_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_d_state), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_d_state);
}

static void c3_y_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint32_T c3_y[2])
{
  uint32_T c3_uv8[2];
  int32_T c3_i324;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_b_state_not_empty = false;
  } else {
    chartInstance->c3_b_state_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv8, 1, 7, 0U, 1, 0U, 1, 2);
    for (c3_i324 = 0; c3_i324 < 2; c3_i324++) {
      c3_y[c3_i324] = c3_uv8[c3_i324];
    }
  }

  sf_mex_destroy(&c3_u);
}

static uint32_T c3_ab_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_previousTicks),
    &c3_thisId);
  sf_mex_destroy(&c3_b_previousTicks);
  return c3_y;
}

static uint32_T c3_bb_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_cb_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_b_subchartSimStateInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_db_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_subchartSimStateInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_subchartSimStateInfo);
  return c3_y;
}

static const mxArray *c3_db_emlrt_marshallIn(SFc3_ARP_02_GazeWalkInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 14, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 14, 1,
    0)]);
}

static void c3_b_twister_state_vector(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_mt[625], real_T c3_seed)
{
  uint32_T c3_r;
  int32_T c3_mti;
  real_T c3_b_mti;
  real_T c3_d3;
  uint32_T c3_u4;
  (void)chartInstance;
  (void)c3_seed;
  c3_r = 5489U;
  c3_mt[0] = 5489U;
  for (c3_mti = 0; c3_mti < 623; c3_mti++) {
    c3_b_mti = 2.0 + (real_T)c3_mti;
    c3_d3 = muDoubleScalarRound(c3_b_mti - 1.0);
    if (c3_d3 < 4.294967296E+9) {
      if (c3_d3 >= 0.0) {
        c3_u4 = (uint32_T)c3_d3;
      } else {
        c3_u4 = 0U;
      }
    } else if (c3_d3 >= 4.294967296E+9) {
      c3_u4 = MAX_uint32_T;
    } else {
      c3_u4 = 0U;
    }

    c3_r = (c3_r ^ c3_r >> 30U) * 1812433253U + c3_u4;
    c3_mt[(int32_T)c3_b_mti - 1] = c3_r;
  }

  c3_mt[624] = 624U;
}

static real_T c3_c_eml_rand_mt19937ar(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance, uint32_T c3_d_state[625])
{
  int32_T c3_i325;
  uint32_T c3_u[2];
  int32_T c3_j;
  real_T c3_b_j;
  uint32_T c3_mti;
  int32_T c3_kk;
  real_T c3_b_kk;
  uint32_T c3_y;
  uint32_T c3_b_y;
  uint32_T c3_c_y;
  int32_T c3_c_kk;
  uint32_T c3_d_y;
  uint32_T c3_e_y;
  uint32_T c3_f_y;
  uint32_T c3_g_y;
  real_T c3_b_r;
  boolean_T c3_b4;
  boolean_T c3_isvalid;
  int32_T c3_k;
  int32_T c3_a;
  int32_T c3_b_a;
  real_T c3_d4;
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
    for (c3_i325 = 0; c3_i325 < 2; c3_i325++) {
      c3_u[c3_i325] = 0U;
    }

    for (c3_j = 0; c3_j < 2; c3_j++) {
      c3_b_j = 1.0 + (real_T)c3_j;
      c3_mti = c3_d_state[624] + 1U;
      if ((real_T)c3_mti >= 625.0) {
        for (c3_kk = 0; c3_kk < 227; c3_kk++) {
          c3_b_kk = 1.0 + (real_T)c3_kk;
          c3_y = (c3_d_state[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_d_state
            [(int32_T)(c3_b_kk + 1.0) - 1] & 2147483647U);
          c3_b_y = c3_y;
          c3_c_y = c3_b_y;
          if ((real_T)(c3_c_y & 1U) == 0.0) {
            c3_c_y >>= 1U;
          } else {
            c3_c_y = c3_c_y >> 1U ^ 2567483615U;
          }

          c3_d_state[(int32_T)c3_b_kk - 1] = c3_d_state[(int32_T)(c3_b_kk +
            397.0) - 1] ^ c3_c_y;
        }

        for (c3_c_kk = 0; c3_c_kk < 396; c3_c_kk++) {
          c3_b_kk = 228.0 + (real_T)c3_c_kk;
          c3_y = (c3_d_state[(int32_T)c3_b_kk - 1] & 2147483648U) | (c3_d_state
            [(int32_T)(c3_b_kk + 1.0) - 1] & 2147483647U);
          c3_d_y = c3_y;
          c3_e_y = c3_d_y;
          if ((real_T)(c3_e_y & 1U) == 0.0) {
            c3_e_y >>= 1U;
          } else {
            c3_e_y = c3_e_y >> 1U ^ 2567483615U;
          }

          c3_d_state[(int32_T)c3_b_kk - 1] = c3_d_state[(int32_T)((c3_b_kk + 1.0)
            - 228.0) - 1] ^ c3_e_y;
        }

        c3_y = (c3_d_state[623] & 2147483648U) | (c3_d_state[0] & 2147483647U);
        c3_f_y = c3_y;
        c3_g_y = c3_f_y;
        if ((real_T)(c3_g_y & 1U) == 0.0) {
          c3_g_y >>= 1U;
        } else {
          c3_g_y = c3_g_y >> 1U ^ 2567483615U;
        }

        c3_d_state[623] = c3_d_state[396] ^ c3_g_y;
        c3_mti = 1U;
      }

      c3_y = c3_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c3_mti, 1, 625, 1, 0) - 1];
      c3_d_state[624] = c3_mti;
      c3_y ^= c3_y >> 11U;
      c3_y ^= c3_y << 7U & 2636928640U;
      c3_y ^= c3_y << 15U & 4022730752U;
      c3_y ^= c3_y >> 18U;
      c3_u[(int32_T)c3_b_j - 1] = c3_y;
    }

    c3_u[0] >>= 5U;
    c3_u[1] >>= 6U;
    c3_b_r = 1.1102230246251565E-16 * ((real_T)c3_u[0] * 6.7108864E+7 + (real_T)
      c3_u[1]);
    if (c3_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c3_d_state[624] >= 1.0) {
        if ((real_T)c3_d_state[624] < 625.0) {
          c3_b4 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c3_b4 = false;
      }

      c3_isvalid = c3_b4;
      if (c3_isvalid) {
        c3_isvalid = false;
        c3_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c3_k + 1 < 625)) {
          if ((real_T)c3_d_state[c3_k] == 0.0) {
            c3_a = c3_k + 1;
            c3_b_a = c3_a;
            c3_k = c3_b_a;
          } else {
            c3_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c3_isvalid) {
        c3_eml_error(chartInstance);
        c3_d4 = 5489.0;
        c3_b_twister_state_vector(chartInstance, c3_d_state, c3_d4);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_b_r;
}

static void init_dsm_address_info(SFc3_ARP_02_GazeWalkInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
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

void sf_c3_ARP_02_GazeWalk_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1258406343U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2132404911U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(508344324U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(340911352U);
}

mxArray *sf_c3_ARP_02_GazeWalk_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5GrxC1H7PIxUsy0j8w4OEC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      pr[0] = (double)(256);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ARP_02_GazeWalk_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ARP_02_GazeWalk_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_ARP_02_GazeWalk(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[265],T\"agentPosition\",},{M[3],M[336],T\"BOREDOMT\",},{M[3],M[335],T\"COPINGT\",},{M[3],M[360],T\"INTERACTT\",},{M[3],M[338],T\"PERSONALSPACE\",},{M[3],M[266],T\"arrBML\",},{M[3],M[301],T\"bored\",},{M[3],M[337],T\"coping\",},{M[3],M[333],T\"copingT\",},{M[3],M[17],T\"round_count\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c3_ARP_02_GazeWalk\",},{M[9],M[0],T\"is_c3_ARP_02_GazeWalk\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x8[350 363 357 295 329 321 278 244],M[1]}}},{M[13],M[0],T\"previousTicks\",},{M[14],M[383],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 19, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ARP_02_GazeWalk_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_GazeWalkMachineNumber_,
           3,
           19,
           24,
           0,
           26,
           1,
           0,
           0,
           0,
           3,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_02_GazeWalkMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_02_GazeWalkMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_GazeWalkMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"round_count");
          _SFD_SET_DATA_PROPS(1,1,1,0,"userX");
          _SFD_SET_DATA_PROPS(2,1,1,0,"userY");
          _SFD_SET_DATA_PROPS(3,1,1,0,"userAgentDistance");
          _SFD_SET_DATA_PROPS(4,2,0,1,"agentPosition");
          _SFD_SET_DATA_PROPS(5,0,0,0,"arrBML");
          _SFD_SET_DATA_PROPS(6,1,1,0,"userStill");
          _SFD_SET_DATA_PROPS(7,0,0,0,"bored");
          _SFD_SET_DATA_PROPS(8,0,0,0,"copingT");
          _SFD_SET_DATA_PROPS(9,0,0,0,"COPINGT");
          _SFD_SET_DATA_PROPS(10,0,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(11,0,0,0,"coping");
          _SFD_SET_DATA_PROPS(12,0,0,0,"PERSONALSPACE");
          _SFD_SET_DATA_PROPS(13,0,0,0,"INTERACTT");
          _SFD_SET_DATA_PROPS(14,8,0,0,"");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,8,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_CH_SUBSTATE_COUNT(12);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,4);
          _SFD_CH_SUBSTATE_INDEX(1,8);
          _SFD_CH_SUBSTATE_INDEX(2,9);
          _SFD_CH_SUBSTATE_INDEX(3,10);
          _SFD_CH_SUBSTATE_INDEX(4,11);
          _SFD_CH_SUBSTATE_INDEX(5,12);
          _SFD_CH_SUBSTATE_INDEX(6,13);
          _SFD_CH_SUBSTATE_INDEX(7,14);
          _SFD_CH_SUBSTATE_INDEX(8,15);
          _SFD_CH_SUBSTATE_INDEX(9,16);
          _SFD_CH_SUBSTATE_INDEX(10,17);
          _SFD_CH_SUBSTATE_INDEX(11,18);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
        }

        _SFD_CV_INIT_CHART(12,1,0,0);

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"boredPoseS",0,-1,1276);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",1276,-1,1458);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",1458,-1,1623);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",1623,-1,1790);
        _SFD_CV_INIT_EML_FCN(3,4,"aFcnTruthTableAction_4",1790,-1,1959);
        _SFD_CV_INIT_EML_FCN(3,5,"aFcnTruthTableAction_5",1959,-1,2128);
        _SFD_CV_INIT_EML_FCN(3,6,"aFcnTruthTableAction_6",2128,-1,2302);
        _SFD_CV_INIT_EML_IF(3,1,0,710,740,771,1274);
        _SFD_CV_INIT_EML_IF(3,1,1,771,805,836,1274);
        _SFD_CV_INIT_EML_IF(3,1,2,836,870,901,1274);
        _SFD_CV_INIT_EML_IF(3,1,3,901,935,966,1274);
        _SFD_CV_INIT_EML_IF(3,1,4,966,1000,1031,1274);
        _SFD_CV_INIT_EML_IF(3,1,5,1031,1065,1096,1274);
        _SFD_CV_INIT_EML_IF(3,1,6,1096,1130,1161,1274);
        _SFD_CV_INIT_EML_IF(3,1,7,1161,1195,1226,1274);
        _SFD_CV_INIT_EML(2,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"boredPose",0,-1,1275);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",1275,-1,1457);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",1457,-1,1640);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1640,-1,1824);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1824,-1,2010);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",2010,-1,2196);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",2196,-1,2387);
        _SFD_CV_INIT_EML_IF(2,1,0,709,739,770,1273);
        _SFD_CV_INIT_EML_IF(2,1,1,770,804,835,1273);
        _SFD_CV_INIT_EML_IF(2,1,2,835,869,900,1273);
        _SFD_CV_INIT_EML_IF(2,1,3,900,934,965,1273);
        _SFD_CV_INIT_EML_IF(2,1,4,965,999,1030,1273);
        _SFD_CV_INIT_EML_IF(2,1,5,1030,1064,1095,1273);
        _SFD_CV_INIT_EML_IF(2,1,6,1095,1129,1160,1273);
        _SFD_CV_INIT_EML_IF(2,1,7,1160,1194,1225,1273);
        _SFD_CV_INIT_EML(1,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"boredGaze",0,-1,1275);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1275,-1,1454);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1454,-1,1641);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1641,-1,1830);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1830,-1,2015);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",2015,-1,2198);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2198,-1,2373);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",2373,-1,2554);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",2554,-1,2732);
        _SFD_CV_INIT_EML_IF(1,1,0,709,739,770,1273);
        _SFD_CV_INIT_EML_IF(1,1,1,770,804,835,1273);
        _SFD_CV_INIT_EML_IF(1,1,2,835,869,900,1273);
        _SFD_CV_INIT_EML_IF(1,1,3,900,934,965,1273);
        _SFD_CV_INIT_EML_IF(1,1,4,965,999,1030,1273);
        _SFD_CV_INIT_EML_IF(1,1,5,1030,1064,1095,1273);
        _SFD_CV_INIT_EML_IF(1,1,6,1095,1129,1160,1273);
        _SFD_CV_INIT_EML_IF(1,1,7,1160,1194,1225,1273);
        _SFD_CV_INIT_EML(5,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"copingInvaded",0,-1,686);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",686,-1,944);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",944,-1,1202);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",1202,-1,1387);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",1387,-1,1707);
        _SFD_CV_INIT_EML_IF(5,1,0,380,410,441,684);
        _SFD_CV_INIT_EML_IF(5,1,1,441,475,506,684);
        _SFD_CV_INIT_EML_IF(5,1,2,506,540,571,684);
        _SFD_CV_INIT_EML_IF(5,1,3,571,605,636,684);
        _SFD_CV_INIT_EML(0,1,10,9,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"EAU",0,-1,1473);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1473,-1,1539);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1539,-1,1590);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1590,-1,1649);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1649,-1,1700);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1700,-1,1752);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",1752,-1,1805);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",1805,-1,1857);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",1857,-1,1911);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",1911,-1,1972);
        _SFD_CV_INIT_EML_IF(0,1,0,842,872,903,1471);
        _SFD_CV_INIT_EML_IF(0,1,1,903,937,968,1471);
        _SFD_CV_INIT_EML_IF(0,1,2,968,1002,1033,1471);
        _SFD_CV_INIT_EML_IF(0,1,3,1033,1067,1098,1471);
        _SFD_CV_INIT_EML_IF(0,1,4,1098,1132,1163,1471);
        _SFD_CV_INIT_EML_IF(0,1,5,1163,1197,1228,1471);
        _SFD_CV_INIT_EML_IF(0,1,6,1228,1262,1293,1471);
        _SFD_CV_INIT_EML_IF(0,1,7,1293,1327,1358,1471);
        _SFD_CV_INIT_EML_IF(0,1,8,1358,1392,1423,1471);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"cmdBML_smileS",0,-1,351);
        _SFD_CV_INIT_SCRIPT(2,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"cmdBML_walkOppositeUser",0,-1,885);
        _SFD_CV_INIT_SCRIPT_IF(2,0,355,361,373,392);
        _SFD_CV_INIT_SCRIPT_IF(2,1,658,664,676,695);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(19,0,0,0,27,0,27);

        {
          static int condStart[] = { 0, 15 };

          static int condEnd[] = { 14, 27 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(19,0,0,0,27,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(12,0,0,0,31,0,31);

        {
          static int condStart[] = { 0, 16 };

          static int condEnd[] = { 15, 31 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,0,31,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,33,1,33);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,32,1,32);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(15,0,0,0,30,0,30);

        {
          static int condStart[] = { 0, 15 };

          static int condEnd[] = { 14, 30 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(15,0,0,0,30,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(10,0,0,0,30,0,30);

        {
          static int condStart[] = { 0, 15 };

          static int condEnd[] = { 14, 30 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(10,0,0,0,30,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,15,1,15);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_o_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_rb_sf_marshallOut,(MexInFcnForType)
            c3_k_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_rb_sf_marshallOut,(MexInFcnForType)
            c3_k_sf_marshallIn);
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
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));

        {
          real_T *c3_userX;
          real_T *c3_userY;
          real_T *c3_userAgentDistance;
          real_T *c3_agentPosition;
          boolean_T *c3_userStill;
          c3_userStill = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_agentPosition = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_userAgentDistance = (real_T *)ssGetInputPortSignal(chartInstance->S,
            2);
          c3_userY = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_userX = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c3_round_count);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_userX);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_userY);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_userAgentDistance);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_agentPosition);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_arrBML);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_userStill);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_bored);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c3_copingT);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_COPINGT);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_BOREDOMT);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_coping);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_PERSONALSPACE);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_INTERACTT);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_GazeWalkMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Hglo62XJWaUMnNi3QmBWW";
}

static void sf_opaque_initialize_c3_ARP_02_GazeWalk(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
  initialize_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_ARP_02_GazeWalk(void *chartInstanceVar)
{
  enable_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_ARP_02_GazeWalk(void *chartInstanceVar)
{
  disable_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_ARP_02_GazeWalk(void *chartInstanceVar)
{
  sf_gateway_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_ARP_02_GazeWalk(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ARP_02_GazeWalk
    ((SFc3_ARP_02_GazeWalkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ARP_02_GazeWalk();/* state var info */
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

extern void sf_internal_set_sim_state_c3_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_ARP_02_GazeWalk();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_ARP_02_GazeWalk(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_ARP_02_GazeWalk(S);
}

static void sf_opaque_set_sim_state_c3_ARP_02_GazeWalk(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_ARP_02_GazeWalk(S, st);
}

static void sf_opaque_terminate_c3_ARP_02_GazeWalk(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ARP_02_GazeWalkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_GazeWalk_optimization_info();
    }

    finalize_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
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
  initSimStructsc3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ARP_02_GazeWalk(SimStruct *S)
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
    initialize_params_c3_ARP_02_GazeWalk((SFc3_ARP_02_GazeWalkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ARP_02_GazeWalk(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_GazeWalk_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1861176721U));
  ssSetChecksum1(S,(3774416141U));
  ssSetChecksum2(S,(2862848762U));
  ssSetChecksum3(S,(1065798895U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ARP_02_GazeWalk(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ARP_02_GazeWalk(SimStruct *S)
{
  SFc3_ARP_02_GazeWalkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_ARP_02_GazeWalkInstanceStruct *)utMalloc(sizeof
    (SFc3_ARP_02_GazeWalkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ARP_02_GazeWalkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ARP_02_GazeWalk;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_ARP_02_GazeWalk;
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

void c3_ARP_02_GazeWalk_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ARP_02_GazeWalk(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ARP_02_GazeWalk(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ARP_02_GazeWalk_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
