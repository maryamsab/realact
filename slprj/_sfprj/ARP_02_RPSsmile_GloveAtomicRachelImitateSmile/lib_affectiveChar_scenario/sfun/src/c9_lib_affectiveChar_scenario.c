/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_scenario_sfun.h"
#include "c9_lib_affectiveChar_scenario.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_scenario_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c9_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_gameOver                 ((uint8_T)1U)
#define c9_IN_stateBoredPose1          ((uint8_T)2U)
#define c9_IN_stateBradWin             ((uint8_T)3U)
#define c9_IN_stateBrowUp              ((uint8_T)4U)
#define c9_IN_stateCompare             ((uint8_T)5U)
#define c9_IN_stateGo                  ((uint8_T)6U)
#define c9_IN_stateHeadNeutral2        ((uint8_T)7U)
#define c9_IN_stateNeckBack            ((uint8_T)8U)
#define c9_IN_stateNoWin               ((uint8_T)9U)
#define c9_IN_statePoseFingersCLose    ((uint8_T)10U)
#define c9_IN_statePosePaper           ((uint8_T)11U)
#define c9_IN_statePoseReady           ((uint8_T)12U)
#define c9_IN_statePoseReturnFinger    ((uint8_T)13U)
#define c9_IN_statePoseRock            ((uint8_T)14U)
#define c9_IN_statePoseScissors        ((uint8_T)15U)
#define c9_IN_stateRandomHand          ((uint8_T)16U)
#define c9_IN_stateReadUserHand        ((uint8_T)17U)
#define c9_IN_stateReady               ((uint8_T)18U)
#define c9_IN_stateShowHands           ((uint8_T)19U)
#define c9_IN_stateShowResult          ((uint8_T)20U)
#define c9_IN_stateSmile               ((uint8_T)21U)
#define c9_IN_stateStart               ((uint8_T)22U)
#define c9_IN_stateUserWin             ((uint8_T)23U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c9_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_d_debug_family_names[5] = { "aVarTruthTableCondition_1",
  "nargin", "nargout", "bmlID", "poseBML" };

static const char * c9_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_f_debug_family_names[5] = { "aVarTruthTableCondition_1",
  "nargin", "nargout", "bmlID", "poseBML" };

static const char * c9_g_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c9_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_l_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

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

static const char * c9_t_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c9_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_x_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

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

static const char * c9_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_fc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initialize_params_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void enable_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void disable_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void set_sim_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void c9_set_sim_state_side_effects_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void finalize_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void sf_gateway_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_enter_atomic_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_enter_internal_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_exit_internal_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_initc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initSimStructsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_enter_atomic_stateReady
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_stateReady(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_gameOver(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_enter_atomic_statePoseReady
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_statePoseReady(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateHeadNeutral2(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateGo(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateNeckBack(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateRandomHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_statePoseFingersCLose
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_statePosePaper(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_statePoseRock(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateReadUserHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_statePoseReturnFinger
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_stateCompare(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateBradWin(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_stateNoWin(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_b_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_c_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_d_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_e_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_f_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_g_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_h_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_i_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_j_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_k_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_l_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_m_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_n_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_o_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static void c9_p_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256]);
static real_T c9_rand(SFc9_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance);
static real_T c9_eml_rand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_eml_rand_mt19937ar(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_d_state[625]);
static void c9_twister_state_vector
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed, uint32_T c9_b_mt[625]);
static void c9_b_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_d_state[625], uint32_T c9_e_state[625], real_T *c9_r);
static void c9_eml_error(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_b_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_bmlID, const char_T *c9_identifier);
static real_T c9_c_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_d_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
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
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_activate_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_deactivate_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_increment_counters_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_reset_counters_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c9_sendSBMc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_arg
   [256]);
static void c9_sendBMLc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_arg
   [256]);
static void c9_rockPoseTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_paperPoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_scissorsPoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_sbmID,
   real_T c9_poseSBM[256]);
static void c9_idlePoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_initialPoseTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_successTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256]);
static void c9_sendSBM(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_b_sendSBM(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_sendBML(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c9_b_sendBML(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int8_T c9_f_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_g_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_tp_stateStart, const char_T *c9_identifier);
static uint8_T c9_i_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint32_T c9_j_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_method, const char_T *c9_identifier);
static uint32_T c9_k_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static uint32_T c9_l_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_d_state, const char_T *c9_identifier);
static uint32_T c9_m_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_n_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625]);
static void c9_o_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625]);
static void c9_p_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2]);
static void c9_q_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2]);
static const mxArray *c9_r_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier);
static const mxArray *c9_s_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex, uint32_T c9_dataNumber);
static void c9_b_twister_state_vector
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed);
static real_T c9_c_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_d_state[625]);
static real_T c9_get_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c);
static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_b);
static real_T c9_get_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c);
static real_T *c9_access_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_randPoseChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static void c9_set_randPoseChance(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randPoseChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b);
static real_T c9_get_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b);
static void init_dsm_address_info(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_debugger_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_lib_affectiveChar_scenario == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_statePoseReady)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateNeckBack)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_statePosePaper)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_statePoseRock)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateShowHands)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateCompare)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateUserWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateBradWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
      c9_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_f_hoistedGlobal;
  real_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  real_T c9_g_hoistedGlobal;
  real_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  uint32_T c9_h_hoistedGlobal;
  uint32_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  uint32_T c9_i_hoistedGlobal;
  uint32_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  int32_T c9_i0;
  uint32_T c9_j_u[625];
  const mxArray *c9_k_y = NULL;
  int32_T c9_i1;
  uint32_T c9_k_u[2];
  const mxArray *c9_l_y = NULL;
  uint8_T c9_j_hoistedGlobal;
  uint8_T c9_l_u;
  const mxArray *c9_m_y = NULL;
  uint8_T c9_k_hoistedGlobal;
  uint8_T c9_m_u;
  const mxArray *c9_n_y = NULL;
  uint8_T c9_l_hoistedGlobal;
  uint8_T c9_n_u;
  const mxArray *c9_o_y = NULL;
  real_T *c9_bWinT;
  real_T *c9_bradHand;
  real_T *c9_gameState;
  real_T *c9_round;
  real_T *c9_uWinT;
  real_T *c9_userHand;
  real_T *c9_win;
  c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(14, 1), false);
  c9_hoistedGlobal = *c9_bWinT;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_bradHand;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_gameState;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_round;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = *c9_uWinT;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_f_hoistedGlobal = *c9_userHand;
  c9_f_u = c9_f_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_g_hoistedGlobal = *c9_win;
  c9_g_u = c9_g_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_h_hoistedGlobal = chartInstance->c9_method;
  c9_h_u = c9_h_hoistedGlobal;
  c9_i_y = NULL;
  if (!chartInstance->c9_method_not_empty) {
    sf_mex_assign(&c9_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_i_hoistedGlobal = chartInstance->c9_state;
  c9_i_u = c9_i_hoistedGlobal;
  c9_j_y = NULL;
  if (!chartInstance->c9_state_not_empty) {
    sf_mex_assign(&c9_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 8, c9_j_y);
  for (c9_i0 = 0; c9_i0 < 625; c9_i0++) {
    c9_j_u[c9_i0] = chartInstance->c9_c_state[c9_i0];
  }

  c9_k_y = NULL;
  if (!chartInstance->c9_c_state_not_empty) {
    sf_mex_assign(&c9_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_j_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c9_y, 9, c9_k_y);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_k_u[c9_i1] = chartInstance->c9_b_state[c9_i1];
  }

  c9_l_y = NULL;
  if (!chartInstance->c9_b_state_not_empty) {
    sf_mex_assign(&c9_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_k_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c9_y, 10, c9_l_y);
  c9_j_hoistedGlobal = chartInstance->c9_is_active_c9_lib_affectiveChar_scenario;
  c9_l_u = c9_j_hoistedGlobal;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 11, c9_m_y);
  c9_k_hoistedGlobal = chartInstance->c9_is_c9_lib_affectiveChar_scenario;
  c9_m_u = c9_k_hoistedGlobal;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 12, c9_n_y);
  c9_l_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_n_u = c9_l_hoistedGlobal;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 13, c9_o_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  uint32_T c9_uv0[625];
  int32_T c9_i2;
  uint32_T c9_uv1[2];
  int32_T c9_i3;
  real_T *c9_bWinT;
  real_T *c9_bradHand;
  real_T *c9_gameState;
  real_T *c9_round;
  real_T *c9_uWinT;
  real_T *c9_userHand;
  real_T *c9_win;
  c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_bWinT = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "bWinT");
  *c9_bradHand = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 1)), "bradHand");
  *c9_gameState = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 2)), "gameState");
  *c9_round = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 3)), "round");
  *c9_uWinT = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 4)), "uWinT");
  *c9_userHand = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 5)), "userHand");
  *c9_win = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    6)), "win");
  chartInstance->c9_method = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 7)), "method");
  chartInstance->c9_state = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 8)), "state");
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 9)),
                        "state", c9_uv0);
  for (c9_i2 = 0; c9_i2 < 625; c9_i2++) {
    chartInstance->c9_c_state[c9_i2] = c9_uv0[c9_i2];
  }

  c9_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 10)),
                        "state", c9_uv1);
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    chartInstance->c9_b_state[c9_i3] = c9_uv1[c9_i3];
  }

  chartInstance->c9_is_active_c9_lib_affectiveChar_scenario =
    c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 11)),
    "is_active_c9_lib_affectiveChar_scenario");
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 12)),
     "is_c9_lib_affectiveChar_scenario");
  chartInstance->c9_temporalCounter_i1 = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_lib_affectiveChar_scenario(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_gameOver) {
      chartInstance->c9_tp_gameOver = 1U;
    } else {
      chartInstance->c9_tp_gameOver = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateBoredPose1) {
      chartInstance->c9_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c9_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateBradWin)
    {
      chartInstance->c9_tp_stateBradWin = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateBradWin = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateBrowUp)
    {
      chartInstance->c9_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c9_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateCompare)
    {
      chartInstance->c9_tp_stateCompare = 1U;
    } else {
      chartInstance->c9_tp_stateCompare = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateGo) {
      chartInstance->c9_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGo = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateHeadNeutral2) {
      chartInstance->c9_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateNeckBack) {
      chartInstance->c9_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateNoWin)
    {
      chartInstance->c9_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateNoWin = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePoseFingersCLose) {
      chartInstance->c9_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c9_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePosePaper) {
      chartInstance->c9_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_statePosePaper = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePoseReady) {
      chartInstance->c9_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_statePoseReady = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePoseReturnFinger) {
      chartInstance->c9_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c9_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePoseRock) {
      chartInstance->c9_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_statePoseRock = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_statePoseScissors) {
      chartInstance->c9_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateRandomHand) {
      chartInstance->c9_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c9_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateReadUserHand) {
      chartInstance->c9_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c9_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateReady)
    {
      chartInstance->c9_tp_stateReady = 1U;
    } else {
      chartInstance->c9_tp_stateReady = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateShowHands) {
      chartInstance->c9_tp_stateShowHands = 1U;
    } else {
      chartInstance->c9_tp_stateShowHands = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario ==
        c9_IN_stateShowResult) {
      chartInstance->c9_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateShowResult = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateSmile)
    {
      chartInstance->c9_tp_stateSmile = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateSmile = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateStart)
    {
      chartInstance->c9_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 23) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateStart = 0U;
    }

    if (chartInstance->c9_is_c9_lib_affectiveChar_scenario == c9_IN_stateUserWin)
    {
      chartInstance->c9_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 24) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateUserWin = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  c9_set_sim_state_side_effects_c9_lib_affectiveChar_scenario(chartInstance);
}

static void c9_enter_atomic_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
  chartInstance->c9_is_active_c9_lib_affectiveChar_scenario = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
}

static void c9_enter_internal_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv0[256];
  int32_T c9_i4;
  real_T c9_arg[256];
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  real_T *c9_round;
  real_T *c9_bradHand;
  real_T *c9_userHand;
  real_T *c9_win;
  real_T *c9_gameState;
  real_T *c9_uWinT;
  real_T *c9_bWinT;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateStart = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_cb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_set_BOREDOM_THRESHOLD(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  *c9_round = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c9_round, 20U);
  c9_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c9_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c9_set_bHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  *c9_bradHand = 3.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_bradHand, 2U);
  *c9_userHand = 3.0;
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_userHand, 3U);
  *c9_win = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_win, 4U);
  *c9_gameState = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
  *c9_uWinT = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_uWinT, 10U);
  *c9_bWinT = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_bWinT, 9U);
  c9_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c9_set_boredom(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c9_set_randAvertGazeChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c9_set_randPoseChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c9_initialPoseTablec9_lib_affectiveChar_scenario(chartInstance, 1.0, c9_dv0);
  for (c9_i4 = 0; c9_i4 < 256; c9_i4++) {
    c9_arg[c9_i4] = c9_dv0[c9_i4];
  }

  for (c9_i5 = 0; c9_i5 < 256; c9_i5++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i5], 23U);
  }

  _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i6 = 0; c9_i6 < 256; c9_i6++) {
    (*c9_b_arg)[c9_i6] = c9_arg[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 256; c9_i7++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i7], 23U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_A;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_y;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 0.0;
  real_T c9_dv1[256];
  int32_T c9_i8;
  real_T c9_arg[256];
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 1.0;
  boolean_T c9_e_out;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 1.0;
  boolean_T c9_f_out;
  real_T c9_k_nargin = 0.0;
  real_T c9_k_nargout = 0.0;
  real_T *c9_gameState;
  real_T *c9_round;
  real_T *c9_inputUser;
  real_T (*c9_b_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_isStable = true;
  switch (chartInstance->c9_is_c9_lib_affectiveChar_scenario) {
   case c9_IN_gameOver:
    CV_CHART_EVAL(0, 0, 1);
    c9_gameOver(chartInstance);
    break;

   case c9_IN_stateBoredPose1:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateBradWin:
    CV_CHART_EVAL(0, 0, 3);
    c9_stateBradWin(chartInstance);
    break;

   case c9_IN_stateBrowUp:
    CV_CHART_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCompare:
    CV_CHART_EVAL(0, 0, 5);
    c9_stateCompare(chartInstance);
    break;

   case c9_IN_stateGo:
    CV_CHART_EVAL(0, 0, 6);
    c9_stateGo(chartInstance);
    break;

   case c9_IN_stateHeadNeutral2:
    CV_CHART_EVAL(0, 0, 7);
    c9_stateHeadNeutral2(chartInstance);
    break;

   case c9_IN_stateNeckBack:
    CV_CHART_EVAL(0, 0, 8);
    c9_stateNeckBack(chartInstance);
    break;

   case c9_IN_stateNoWin:
    CV_CHART_EVAL(0, 0, 9);
    c9_stateNoWin(chartInstance);
    break;

   case c9_IN_statePoseFingersCLose:
    CV_CHART_EVAL(0, 0, 10);
    c9_statePoseFingersCLose(chartInstance);
    break;

   case c9_IN_statePosePaper:
    CV_CHART_EVAL(0, 0, 11);
    c9_statePosePaper(chartInstance);
    break;

   case c9_IN_statePoseReady:
    CV_CHART_EVAL(0, 0, 12);
    c9_statePoseReady(chartInstance);
    break;

   case c9_IN_statePoseReturnFinger:
    CV_CHART_EVAL(0, 0, 13);
    c9_statePoseReturnFinger(chartInstance);
    break;

   case c9_IN_statePoseRock:
    CV_CHART_EVAL(0, 0, 14);
    c9_statePoseRock(chartInstance);
    break;

   case c9_IN_statePoseScissors:
    CV_CHART_EVAL(0, 0, 15);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_rc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(24, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                    (chartInstance->c9_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(24, 0, 1, c9_get_uHand(chartInstance, 0) != 3.0)) {
        CV_EML_MCDC(24, 0, 0, true);
        CV_EML_IF(24, 0, 0, true);
        c9_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(24, 0, 0, false);
      CV_EML_IF(24, 0, 0, false);
      c9_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_statePoseScissors = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario =
        c9_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReadUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c9_set_uHand(chartInstance, 0, *c9_inputUser);
      ssUpdateDataStoreLog(chartInstance->S, 12);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateRandomHand:
    CV_CHART_EVAL(0, 0, 16);
    c9_stateRandomHand(chartInstance);
    break;

   case c9_IN_stateReadUserHand:
    CV_CHART_EVAL(0, 0, 17);
    c9_stateReadUserHand(chartInstance);
    break;

   case c9_IN_stateReady:
    CV_CHART_EVAL(0, 0, 18);
    c9_stateReady(chartInstance);
    break;

   case c9_IN_stateShowHands:
    CV_CHART_EVAL(0, 0, 19);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateShowHands = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateCompare;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateCompare = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ub_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_set_temp(chartInstance, 0, c9_get_uHand(chartInstance, 0) - c9_get_bHand
                (chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 11);
    c9_hoistedGlobal = c9_get_temp(chartInstance, 0);
    c9_b_hoistedGlobal = c9_get_temp(chartInstance, 0);
    c9_A = c9_b_hoistedGlobal;
    c9_x = c9_A;
    c9_b_x = c9_x;
    c9_c_x = c9_b_x;
    c9_y = c9_c_x / 3.0;
    c9_d_x = c9_y;
    c9_e_x = c9_d_x;
    c9_e_x = muDoubleScalarFloor(c9_e_x);
    c9_set_diff(chartInstance, 0, c9_hoistedGlobal - 3.0 * c9_e_x);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateShowResult:
    CV_CHART_EVAL(0, 0, 20);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_cc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                    (chartInstance->c9_temporalCounter_i1 >= 3))) {
      if (CV_EML_COND(5, 0, 1, *c9_round == 10.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c9_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 6U, 20U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c9_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_eb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      *c9_gameState = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
      c9_set_boredom(chartInstance, 0, c9_get_boredom(chartInstance, 0) - 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_dc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_c_out = CV_EML_IF(3, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs)
                           && (chartInstance->c9_temporalCounter_i1 >= 3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateReady = 1U;
        c9_enter_atomic_stateReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                     chartInstance->c9_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateSmile:
    CV_CHART_EVAL(0, 0, 21);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_jc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_d_out = CV_EML_IF(14, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateNeckBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateNeckBack = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_jb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_successTablec9_lib_affectiveChar_scenario(chartInstance, 2.0, c9_dv1);
      for (c9_i8 = 0; c9_i8 < 256; c9_i8++) {
        c9_arg[c9_i8] = c9_dv1[c9_i8];
      }

      for (c9_i9 = 0; c9_i9 < 256; c9_i9++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i9], 23U);
      }

      _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c9_sfEvent);
      for (c9_i10 = 0; c9_i10 < 256; c9_i10++) {
        (*c9_b_arg)[c9_i10] = c9_arg[c9_i10];
      }

      for (c9_i11 = 0; c9_i11 < 256; c9_i11++) {
        _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i11], 23U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(23U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateStart:
    CV_CHART_EVAL(0, 0, 22);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ac_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_e_out = CV_EML_IF(1, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReady = 1U;
      c9_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateUserWin:
    CV_CHART_EVAL(0, 0, 23);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ad_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_f_out = CV_EML_IF(34, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_yb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
}

static void c9_exit_internal_c9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  switch (chartInstance->c9_is_c9_lib_affectiveChar_scenario) {
   case c9_IN_gameOver:
    CV_CHART_EVAL(0, 0, 1);
    chartInstance->c9_tp_gameOver = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateBoredPose1:
    CV_CHART_EVAL(0, 0, 2);
    chartInstance->c9_tp_stateBoredPose1 = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateBradWin:
    CV_CHART_EVAL(0, 0, 3);
    chartInstance->c9_tp_stateBradWin = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateBrowUp:
    CV_CHART_EVAL(0, 0, 4);
    chartInstance->c9_tp_stateBrowUp = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCompare:
    CV_CHART_EVAL(0, 0, 5);
    chartInstance->c9_tp_stateCompare = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGo:
    CV_CHART_EVAL(0, 0, 6);
    chartInstance->c9_tp_stateGo = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateHeadNeutral2:
    CV_CHART_EVAL(0, 0, 7);
    chartInstance->c9_tp_stateHeadNeutral2 = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNeckBack:
    CV_CHART_EVAL(0, 0, 8);
    chartInstance->c9_tp_stateNeckBack = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNoWin:
    CV_CHART_EVAL(0, 0, 9);
    chartInstance->c9_tp_stateNoWin = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePoseFingersCLose:
    CV_CHART_EVAL(0, 0, 10);
    chartInstance->c9_tp_statePoseFingersCLose = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePosePaper:
    CV_CHART_EVAL(0, 0, 11);
    chartInstance->c9_tp_statePosePaper = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePoseReady:
    CV_CHART_EVAL(0, 0, 12);
    chartInstance->c9_tp_statePoseReady = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePoseReturnFinger:
    CV_CHART_EVAL(0, 0, 13);
    chartInstance->c9_tp_statePoseReturnFinger = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePoseRock:
    CV_CHART_EVAL(0, 0, 14);
    chartInstance->c9_tp_statePoseRock = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_statePoseScissors:
    CV_CHART_EVAL(0, 0, 15);
    chartInstance->c9_tp_statePoseScissors = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateRandomHand:
    CV_CHART_EVAL(0, 0, 16);
    chartInstance->c9_tp_stateRandomHand = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateReadUserHand:
    CV_CHART_EVAL(0, 0, 17);
    chartInstance->c9_tp_stateReadUserHand = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateReady:
    CV_CHART_EVAL(0, 0, 18);
    chartInstance->c9_tp_stateReady = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateShowHands:
    CV_CHART_EVAL(0, 0, 19);
    chartInstance->c9_tp_stateShowHands = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateShowResult:
    CV_CHART_EVAL(0, 0, 20);
    chartInstance->c9_tp_stateShowResult = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateSmile:
    CV_CHART_EVAL(0, 0, 21);
    chartInstance->c9_tp_stateSmile = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateStart:
    CV_CHART_EVAL(0, 0, 22);
    chartInstance->c9_tp_stateStart = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateUserWin:
    CV_CHART_EVAL(0, 0, 23);
    chartInstance->c9_tp_stateUserWin = 0U;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    break;
  }
}

static void c9_initc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_method_not_empty = false;
  chartInstance->c9_state_not_empty = false;
  chartInstance->c9_b_state_not_empty = false;
  chartInstance->c9_c_state_not_empty = false;
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_tp_gameOver = 0U;
  chartInstance->c9_tp_stateBoredPose1 = 0U;
  chartInstance->c9_tp_stateBradWin = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateBrowUp = 0U;
  chartInstance->c9_tp_stateCompare = 0U;
  chartInstance->c9_tp_stateGo = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateHeadNeutral2 = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateNeckBack = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateNoWin = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_statePoseFingersCLose = 0U;
  chartInstance->c9_tp_statePosePaper = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_statePoseReady = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_statePoseReturnFinger = 0U;
  chartInstance->c9_tp_statePoseRock = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_statePoseScissors = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateRandomHand = 0U;
  chartInstance->c9_tp_stateReadUserHand = 0U;
  chartInstance->c9_tp_stateReady = 0U;
  chartInstance->c9_tp_stateShowHands = 0U;
  chartInstance->c9_tp_stateShowResult = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateSmile = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateStart = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateUserWin = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_is_active_c9_lib_affectiveChar_scenario = 0U;
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_enter_atomic_stateReady
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T *c9_round;
  real_T *c9_bradHand;
  real_T *c9_userHand;
  real_T *c9_gameState;
  real_T *c9_win;
  c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_db_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 6U, 20U);
  (*c9_round)++;
  c9_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c9_round, 20U);
  *c9_bradHand = 3.0;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_bradHand, 2U);
  *c9_userHand = 3.0;
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_userHand, 3U);
  *c9_gameState = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
  *c9_win = 0.0;
  c9_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_win, 4U);
  c9_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateReady(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ec_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(6, 0, 0, c9_get_boredom(chartInstance, 0) <
                     c9_get_BOREDOM_THRESHOLD(chartInstance, 0) - 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_fc_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_boredom(chartInstance, 0, c9_get_boredom(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c9_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_statePoseReady = 1U;
    c9_enter_atomic_statePoseReady(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_bc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(2, 0, 0, c9_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReady = 1U;
      c9_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_statePoseReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_statePoseReady = 1U;
      c9_enter_atomic_statePoseReady(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c9_sfEvent);
}

static void c9_gameOver(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv2[256];
  int32_T c9_i12;
  real_T c9_arg[256];
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_gameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateHeadNeutral2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateHeadNeutral2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_gb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_initialPoseTablec9_lib_affectiveChar_scenario(chartInstance, 2.0, c9_dv2);
  for (c9_i12 = 0; c9_i12 < 256; c9_i12++) {
    c9_arg[c9_i12] = c9_dv2[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 256; c9_i13++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i13], 23U);
  }

  _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i14 = 0; c9_i14 < 256; c9_i14++) {
    (*c9_b_arg)[c9_i14] = c9_arg[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 256; c9_i15++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i15], 23U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_statePoseReady
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv3[256];
  int32_T c9_i16;
  real_T c9_arg[256];
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  real_T c9_dv4[256];
  int32_T c9_i20;
  real_T c9_b_arg[256];
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  real_T (*c9_c_arg)[256];
  real_T (*c9_d_arg)[256];
  c9_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c9_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_fb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_initialPoseTablec9_lib_affectiveChar_scenario(chartInstance, 2.0, c9_dv3);
  for (c9_i16 = 0; c9_i16 < 256; c9_i16++) {
    c9_arg[c9_i16] = c9_dv3[c9_i16];
  }

  for (c9_i17 = 0; c9_i17 < 256; c9_i17++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i17], 23U);
  }

  _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i18 = 0; c9_i18 < 256; c9_i18++) {
    (*c9_d_arg)[c9_i18] = c9_arg[c9_i18];
  }

  for (c9_i19 = 0; c9_i19 < 256; c9_i19++) {
    _SFD_DATA_RANGE_CHECK((*c9_d_arg)[c9_i19], 23U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario(chartInstance, 2.0,
    c9_dv4);
  for (c9_i20 = 0; c9_i20 < 256; c9_i20++) {
    c9_b_arg[c9_i20] = c9_dv4[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 256; c9_i21++) {
    _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i21], 22U);
  }

  _SFD_SET_DATA_VALUE_PTR(22U, c9_b_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i22 = 0; c9_i22 < 256; c9_i22++) {
    (*c9_c_arg)[c9_i22] = c9_b_arg[c9_i22];
  }

  for (c9_i23 = 0; c9_i23 < 256; c9_i23++) {
    _SFD_DATA_RANGE_CHECK((*c9_c_arg)[c9_i23], 22U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(22U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_statePoseReady(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T *c9_gameState;
  boolean_T guard1 = false;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_hc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(8, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                  (chartInstance->c9_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(8, 0, 1, c9_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(8, 0, 0, true);
      CV_EML_IF(8, 0, 0, true);
      c9_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(8, 0, 0, false);
    CV_EML_IF(8, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateGo = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_hb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c9_gameState = 1.0;
    c9_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
}

static void c9_stateHeadNeutral2(SFc9_lib_affectiveChar_scenarioInstanceStruct
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
  real_T c9_dv5[256];
  int32_T c9_i24;
  real_T c9_arg[256];
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_dv6[256];
  int32_T c9_i28;
  real_T c9_b_arg[256];
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  real_T *c9_uWinT;
  real_T *c9_bWinT;
  real_T (*c9_c_arg)[256];
  c9_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_gc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(10, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ic_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    c9_b_out = CV_EML_IF(12, 0, 0, *c9_uWinT < *c9_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ib_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_successTablec9_lib_affectiveChar_scenario(chartInstance, 1.0, c9_dv5);
      for (c9_i24 = 0; c9_i24 < 256; c9_i24++) {
        c9_arg[c9_i24] = c9_dv5[c9_i24];
      }

      for (c9_i25 = 0; c9_i25 < 256; c9_i25++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i25], 23U);
      }

      _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c9_sfEvent);
      for (c9_i26 = 0; c9_i26 < 256; c9_i26++) {
        (*c9_c_arg)[c9_i26] = c9_arg[c9_i26];
      }

      for (c9_i27 = 0; c9_i27 < 256; c9_i27++) {
        _SFD_DATA_RANGE_CHECK((*c9_c_arg)[c9_i27], 23U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(23U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateBoredPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateBoredPose1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_mb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_r = c9_rand(chartInstance);
      c9_x = c9_r * 18.0;
      c9_b_x = c9_x;
      c9_b_x = muDoubleScalarFloor(c9_b_x);
      c9_r = 1.0 + c9_b_x;
      c9_idlePoseRachelTablec9_lib_affectiveChar_scenario(chartInstance, c9_r,
        c9_dv6);
      for (c9_i28 = 0; c9_i28 < 256; c9_i28++) {
        c9_b_arg[c9_i28] = c9_dv6[c9_i28];
      }

      for (c9_i29 = 0; c9_i29 < 256; c9_i29++) {
        _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i29], 23U);
      }

      _SFD_SET_DATA_VALUE_PTR(23U, c9_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c9_sfEvent);
      for (c9_i30 = 0; c9_i30 < 256; c9_i30++) {
        (*c9_c_arg)[c9_i30] = c9_b_arg[c9_i30];
      }

      for (c9_i31 = 0; c9_i31 < 256; c9_i31++) {
        _SFD_DATA_RANGE_CHECK((*c9_c_arg)[c9_i31], 23U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(23U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
}

static void c9_stateGo(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_kc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(13, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateRandomHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateRandomHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_kb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_r = c9_rand(chartInstance);
    c9_x = c9_r * 3.0;
    c9_b_x = c9_x;
    c9_b_x = muDoubleScalarFloor(c9_b_x);
    c9_r = c9_b_x;
    c9_set_bHand(chartInstance, 0, c9_r);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
}

static void c9_stateNeckBack(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_dv7[256];
  int32_T c9_i32;
  real_T c9_arg[256];
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_lc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(15, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateNeckBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_lb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_successTablec9_lib_affectiveChar_scenario(chartInstance, 3.0, c9_dv7);
    for (c9_i32 = 0; c9_i32 < 256; c9_i32++) {
      c9_arg[c9_i32] = c9_dv7[c9_i32];
    }

    for (c9_i33 = 0; c9_i33 < 256; c9_i33++) {
      _SFD_DATA_RANGE_CHECK(c9_arg[c9_i33], 23U);
    }

    _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    for (c9_i34 = 0; c9_i34 < 256; c9_i34++) {
      (*c9_b_arg)[c9_i34] = c9_arg[c9_i34];
    }

    for (c9_i35 = 0; c9_i35 < 256; c9_i35++) {
      _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i35], 23U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(23U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
}

static void c9_stateRandomHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_dv8[256];
  int32_T c9_i36;
  real_T c9_arg[256];
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_hoistedGlobal;
  real_T c9_dv9[256];
  int32_T c9_i40;
  real_T c9_b_arg[256];
  int32_T c9_i41;
  int32_T c9_i42;
  int32_T c9_i43;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 0.0;
  real_T c9_dv10[256];
  int32_T c9_i44;
  real_T c9_c_arg[256];
  int32_T c9_i45;
  int32_T c9_i46;
  int32_T c9_i47;
  real_T (*c9_d_arg)[256];
  real_T (*c9_e_arg)[256];
  c9_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c9_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_oc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(19, 0, 0, c9_get_bHand(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ob_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_paperPoseRachelTablec9_lib_affectiveChar_scenario(chartInstance, 1.0,
      c9_dv8);
    for (c9_i36 = 0; c9_i36 < 256; c9_i36++) {
      c9_arg[c9_i36] = c9_dv8[c9_i36];
    }

    for (c9_i37 = 0; c9_i37 < 256; c9_i37++) {
      _SFD_DATA_RANGE_CHECK(c9_arg[c9_i37], 23U);
    }

    _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    for (c9_i38 = 0; c9_i38 < 256; c9_i38++) {
      (*c9_e_arg)[c9_i38] = c9_arg[c9_i38];
    }

    for (c9_i39 = 0; c9_i39 < 256; c9_i39++) {
      _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i39], 23U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(23U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_mc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(18, 0, 0, c9_get_bHand(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_pb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c9_r = c9_rand(chartInstance);
      c9_x = c9_r * 2.0;
      c9_b_x = c9_x;
      c9_b_x = muDoubleScalarFloor(c9_b_x);
      c9_r = 1.0 + c9_b_x;
      c9_set_r(chartInstance, 0, c9_r);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c9_hoistedGlobal = c9_get_r(chartInstance, 0);
      c9_rockPoseTablec9_lib_affectiveChar_scenario(chartInstance,
        c9_hoistedGlobal, c9_dv9);
      for (c9_i40 = 0; c9_i40 < 256; c9_i40++) {
        c9_b_arg[c9_i40] = c9_dv9[c9_i40];
      }

      for (c9_i41 = 0; c9_i41 < 256; c9_i41++) {
        _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i41], 23U);
      }

      _SFD_SET_DATA_VALUE_PTR(23U, c9_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c9_sfEvent);
      for (c9_i42 = 0; c9_i42 < 256; c9_i42++) {
        (*c9_e_arg)[c9_i42] = c9_b_arg[c9_i42];
      }

      for (c9_i43 = 0; c9_i43 < 256; c9_i43++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i43], 23U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(23U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_nc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_c_out = CV_EML_IF(17, 0, 0, c9_get_bHand(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_c9_lib_affectiveChar_scenario =
          c9_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_nb_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        c9_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario(chartInstance, 1.0,
          c9_dv10);
        for (c9_i44 = 0; c9_i44 < 256; c9_i44++) {
          c9_c_arg[c9_i44] = c9_dv10[c9_i44];
        }

        for (c9_i45 = 0; c9_i45 < 256; c9_i45++) {
          _SFD_DATA_RANGE_CHECK(c9_c_arg[c9_i45], 22U);
        }

        _SFD_SET_DATA_VALUE_PTR(22U, c9_c_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_c_arg, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c9_sfEvent);
        for (c9_i46 = 0; c9_i46 < 256; c9_i46++) {
          (*c9_d_arg)[c9_i46] = c9_c_arg[c9_i46];
        }

        for (c9_i47 = 0; c9_i47 < 256; c9_i47++) {
          _SFD_DATA_RANGE_CHECK((*c9_d_arg)[c9_i47], 22U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(22U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                     chartInstance->c9_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c9_sfEvent);
}

static void c9_statePoseFingersCLose
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_dv11[256];
  int32_T c9_i48;
  real_T c9_arg[256];
  int32_T c9_i49;
  int32_T c9_i50;
  int32_T c9_i51;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_qb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c9_scissorsPoseRachelTablec9_lib_affectiveChar_scenario(chartInstance, 1.0,
    c9_dv11);
  for (c9_i48 = 0; c9_i48 < 256; c9_i48++) {
    c9_arg[c9_i48] = c9_dv11[c9_i48];
  }

  for (c9_i49 = 0; c9_i49 < 256; c9_i49++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i49], 23U);
  }

  _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i50 = 0; c9_i50 < 256; c9_i50++) {
    (*c9_b_arg)[c9_i50] = c9_arg[c9_i50];
  }

  for (c9_i51 = 0; c9_i51 < 256; c9_i51++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i51], 23U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c9_sfEvent);
}

static void c9_statePosePaper(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T *c9_inputUser;
  boolean_T guard1 = false;
  c9_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_qc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(21, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                  (chartInstance->c9_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(21, 0, 1, c9_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(21, 0, 0, true);
      CV_EML_IF(21, 0, 0, true);
      c9_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(21, 0, 0, false);
    CV_EML_IF(21, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_set_uHand(chartInstance, 0, *c9_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 12);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
}

static void c9_statePoseRock(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T *c9_inputUser;
  boolean_T guard1 = false;
  c9_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_pc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(20, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                  (chartInstance->c9_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(20, 0, 1, c9_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(20, 0, 0, true);
      CV_EML_IF(20, 0, 0, true);
      c9_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(20, 0, 0, false);
    CV_EML_IF(20, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_set_uHand(chartInstance, 0, *c9_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 12);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c9_sfEvent);
}

static void c9_stateReadUserHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_dv12[256];
  int32_T c9_i52;
  real_T c9_arg[256];
  int32_T c9_i53;
  int32_T c9_i54;
  int32_T c9_i55;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  real_T *c9_gameState;
  real_T *c9_bradHand;
  real_T *c9_userHand;
  real_T *c9_inputUser;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_sc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(23, 0, 0, c9_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c9_set_uHand(chartInstance, 0, *c9_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 12);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_tc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(26, 0, 0, c9_get_bHand(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario =
        c9_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_tb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario(chartInstance, 2.0,
        c9_dv12);
      for (c9_i52 = 0; c9_i52 < 256; c9_i52++) {
        c9_arg[c9_i52] = c9_dv12[c9_i52];
      }

      for (c9_i53 = 0; c9_i53 < 256; c9_i53++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i53], 22U);
      }

      _SFD_SET_DATA_VALUE_PTR(22U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c9_sfEvent);
      for (c9_i54 = 0; c9_i54 < 256; c9_i54++) {
        (*c9_b_arg)[c9_i54] = c9_arg[c9_i54];
      }

      for (c9_i55 = 0; c9_i55 < 256; c9_i55++) {
        _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i55], 22U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(22U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateShowHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateShowHands = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c9_gameState = 2.0;
      c9_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
      *c9_bradHand = c9_get_bHand(chartInstance, 0);
      c9_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(*c9_bradHand, 2U);
      *c9_userHand = c9_get_uHand(chartInstance, 0);
      c9_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(*c9_userHand, 3U);
      _SFD_SYMBOL_SCOPE_POP();
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c9_sfEvent);
}

static void c9_statePoseReturnFinger
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T *c9_gameState;
  real_T *c9_bradHand;
  real_T *c9_userHand;
  c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_statePoseReturnFinger = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateShowHands;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateShowHands = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c9_gameState = 2.0;
  c9_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 0U);
  *c9_bradHand = c9_get_bHand(chartInstance, 0);
  c9_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_bradHand, 2U);
  *c9_userHand = c9_get_uHand(chartInstance, 0);
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_userHand, 3U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c9_sfEvent);
}

static void c9_stateCompare(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 0.0;
  real_T *c9_win;
  real_T *c9_uWinT;
  real_T *c9_bWinT;
  boolean_T guard1 = false;
  c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_vc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(30, 0, 0, c9_get_diff(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_wb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c9_win = 2.0;
    c9_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c9_win, 4U);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    (*c9_bWinT)++;
    c9_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c9_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_uc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(29, 0, 0, c9_get_diff(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_vb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c9_win = 1.0;
      c9_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c9_win, 4U);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      (*c9_uWinT)++;
      c9_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c9_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_wc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(31, 0, 0, c9_get_diff(chartInstance, 0) != 1.0)) {
        if (CV_EML_COND(31, 0, 1, c9_get_diff(chartInstance, 0) != 2.0)) {
          CV_EML_MCDC(31, 0, 0, true);
          CV_EML_IF(31, 0, 0, true);
          c9_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(31, 0, 0, false);
        CV_EML_IF(31, 0, 0, false);
        c9_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_xb_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        *c9_win = 0.0;
        c9_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c9_win, 4U);
        c9_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c9_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
}

static void c9_stateBradWin(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_xc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(32, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateBradWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_yb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
}

static void c9_stateNoWin(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_yc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(33, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_c9_lib_affectiveChar_scenario = c9_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_yb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
}

static void c9_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[94];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[94];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i56;
  static char_T c9_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i57;
  static real_T c9_dv13[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i58;
  int32_T c9_i59;
  int32_T c9_i60;
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
  for (c9_i56 = 0; c9_i56 < 94; c9_i56++) {
    c9_mystr[c9_i56] = c9_cv0[c9_i56];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i57 = 0; c9_i57 < 94; c9_i57++) {
    c9_arr[c9_i57] = c9_dv13[c9_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i58 = 0; c9_i58 < 256; c9_i58++) {
    c9_tt[c9_i58] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i59 = 0; c9_i59 < 94; c9_i59++) {
    c9_tt[c9_i59] = c9_arr[c9_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i60 = 0; c9_i60 < 256; c9_i60++) {
    c9_myarr256[c9_i60] = c9_tt[c9_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_b_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[86];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[86];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i61;
  static char_T c9_cv1[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i62;
  static real_T c9_dv14[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i63;
  int32_T c9_i64;
  int32_T c9_i65;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_e_debug_family_names,
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
  for (c9_i61 = 0; c9_i61 < 86; c9_i61++) {
    c9_mystr[c9_i61] = c9_cv1[c9_i61];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i62 = 0; c9_i62 < 86; c9_i62++) {
    c9_arr[c9_i62] = c9_dv14[c9_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i63 = 0; c9_i63 < 256; c9_i63++) {
    c9_tt[c9_i63] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i64 = 0; c9_i64 < 86; c9_i64++) {
    c9_tt[c9_i64] = c9_arr[c9_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i65 = 0; c9_i65 < 256; c9_i65++) {
    c9_myarr256[c9_i65] = c9_tt[c9_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[165];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[165];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i66;
  static char_T c9_cv2[165] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p',
    'i', 'n', 'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't',
    'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't',
    '(', '1', ',', '0', ',', '0', ',', '0', '.', '5', ')', ')', ';', ' ', 'R',
    'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't',
    'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y',
    'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '5', ')', ')' };

  int32_T c9_i67;
  static real_T c9_dv15[165] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0,
    110.0, 107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0,
    111.0, 115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    40.0, 83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0,
    48.0, 44.0, 48.0, 46.0, 53.0, 41.0, 41.0, 59.0, 32.0, 82.0, 97.0, 99.0,
    104.0, 101.0, 108.0, 46.0, 103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0,
    101.0, 116.0, 111.0, 110.0, 40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0,
    111.0, 105.0, 110.0, 116.0, 66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0,
    34.0, 108.0, 95.0, 114.0, 105.0, 110.0, 103.0, 49.0, 34.0, 41.0, 46.0, 115.0,
    101.0, 116.0, 80.0, 111.0, 115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0,
    105.0, 111.0, 110.0, 40.0, 83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0,
    44.0, 48.0, 44.0, 48.0, 44.0, 48.0, 46.0, 53.0, 41.0, 41.0 };

  int32_T c9_i68;
  int32_T c9_i69;
  int32_T c9_i70;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_h_debug_family_names,
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
  for (c9_i66 = 0; c9_i66 < 165; c9_i66++) {
    c9_mystr[c9_i66] = c9_cv2[c9_i66];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i67 = 0; c9_i67 < 165; c9_i67++) {
    c9_arr[c9_i67] = c9_dv15[c9_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i68 = 0; c9_i68 < 256; c9_i68++) {
    c9_tt[c9_i68] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i69 = 0; c9_i69 < 165; c9_i69++) {
    c9_tt[c9_i69] = c9_arr[c9_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i70 = 0; c9_i70 < 256; c9_i70++) {
    c9_myarr256[c9_i70] = c9_tt[c9_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_d_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[161];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[161];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i71;
  static char_T c9_cv3[161] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p',
    'i', 'n', 'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't',
    'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't',
    '(', '1', ',', '0', ',', '0', ',', '0', ')', ')', ';', ' ', 'R', 'a', 'c',
    'h', 'e', 'l', '.', 'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n',
    '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y', 'N', 'a',
    'm', 'e', '(', '\"', 'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')', '.', 's',
    'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(',
    'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',', '0', ')',
    ')' };

  int32_T c9_i72;
  static real_T c9_dv16[161] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0,
    110.0, 107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0,
    111.0, 115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    40.0, 83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0,
    48.0, 44.0, 48.0, 41.0, 41.0, 59.0, 32.0, 82.0, 97.0, 99.0, 104.0, 101.0,
    108.0, 46.0, 103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0,
    111.0, 110.0, 40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0,
    110.0, 116.0, 66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0,
    114.0, 105.0, 110.0, 103.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0,
    80.0, 111.0, 115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0,
    110.0, 40.0, 83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0,
    44.0, 48.0, 44.0, 48.0, 41.0, 41.0 };

  int32_T c9_i73;
  int32_T c9_i74;
  int32_T c9_i75;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_i_debug_family_names,
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
  for (c9_i71 = 0; c9_i71 < 161; c9_i71++) {
    c9_mystr[c9_i71] = c9_cv3[c9_i71];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i72 = 0; c9_i72 < 161; c9_i72++) {
    c9_arr[c9_i72] = c9_dv16[c9_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i73 = 0; c9_i73 < 256; c9_i73++) {
    c9_tt[c9_i73] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i74 = 0; c9_i74 < 161; c9_i74++) {
    c9_tt[c9_i74] = c9_arr[c9_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i75 = 0; c9_i75 < 256; c9_i75++) {
    c9_myarr256[c9_i75] = c9_tt[c9_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_e_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[93];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[93];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i76;
  static char_T c9_cv4[93] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', '.', '0', '5', ')', ')' };

  int32_T c9_i77;
  static real_T c9_dv17[93] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 48.0, 53.0, 41.0, 41.0 };

  int32_T c9_i78;
  int32_T c9_i79;
  int32_T c9_i80;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_j_debug_family_names,
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
  for (c9_i76 = 0; c9_i76 < 93; c9_i76++) {
    c9_mystr[c9_i76] = c9_cv4[c9_i76];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i77 = 0; c9_i77 < 93; c9_i77++) {
    c9_arr[c9_i77] = c9_dv17[c9_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i78 = 0; c9_i78 < 256; c9_i78++) {
    c9_tt[c9_i78] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i79 = 0; c9_i79 < 93; c9_i79++) {
    c9_tt[c9_i79] = c9_arr[c9_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i80 = 0; c9_i80 < 256; c9_i80++) {
    c9_myarr256[c9_i80] = c9_tt[c9_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_f_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[93];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[93];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i81;
  static char_T c9_cv5[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i82;
  static real_T c9_dv18[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i83;
  int32_T c9_i84;
  int32_T c9_i85;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_m_debug_family_names,
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
  for (c9_i81 = 0; c9_i81 < 93; c9_i81++) {
    c9_mystr[c9_i81] = c9_cv5[c9_i81];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i82 = 0; c9_i82 < 93; c9_i82++) {
    c9_arr[c9_i82] = c9_dv18[c9_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i83 = 0; c9_i83 < 256; c9_i83++) {
    c9_tt[c9_i83] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i84 = 0; c9_i84 < 93; c9_i84++) {
    c9_tt[c9_i84] = c9_arr[c9_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i85 = 0; c9_i85 < 256; c9_i85++) {
    c9_myarr256[c9_i85] = c9_tt[c9_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_g_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[104];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[104];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i86;
  static char_T c9_cv6[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'R', 'a', 'c',
    'h', 'e', 'l', '_', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l',
    'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c', 'h', 'C', 'h', 'e', 's',
    't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i87;
  static real_T c9_dv19[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 82.0, 97.0,
    99.0, 104.0, 101.0, 108.0, 95.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0,
    100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0, 114.0,
    97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0, 49.0, 34.0,
    32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c9_i88;
  int32_T c9_i89;
  int32_T c9_i90;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_n_debug_family_names,
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
  for (c9_i86 = 0; c9_i86 < 104; c9_i86++) {
    c9_mystr[c9_i86] = c9_cv6[c9_i86];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i87 = 0; c9_i87 < 104; c9_i87++) {
    c9_arr[c9_i87] = c9_dv19[c9_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i88 = 0; c9_i88 < 256; c9_i88++) {
    c9_tt[c9_i88] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i89 = 0; c9_i89 < 104; c9_i89++) {
    c9_tt[c9_i89] = c9_arr[c9_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i90 = 0; c9_i90 < 256; c9_i90++) {
    c9_myarr256[c9_i90] = c9_tt[c9_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_h_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[93];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[93];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i91;
  static char_T c9_cv7[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i92;
  static real_T c9_dv20[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i93;
  int32_T c9_i94;
  int32_T c9_i95;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_o_debug_family_names,
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
  for (c9_i91 = 0; c9_i91 < 93; c9_i91++) {
    c9_mystr[c9_i91] = c9_cv7[c9_i91];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i92 = 0; c9_i92 < 93; c9_i92++) {
    c9_arr[c9_i92] = c9_dv20[c9_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i93 = 0; c9_i93 < 256; c9_i93++) {
    c9_tt[c9_i93] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i94 = 0; c9_i94 < 93; c9_i94++) {
    c9_tt[c9_i94] = c9_arr[c9_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i95 = 0; c9_i95 < 256; c9_i95++) {
    c9_myarr256[c9_i95] = c9_tt[c9_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_i_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[95];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[95];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i96;
  static char_T c9_cv8[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i97;
  static real_T c9_dv21[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i98;
  int32_T c9_i99;
  int32_T c9_i100;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_p_debug_family_names,
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
  for (c9_i96 = 0; c9_i96 < 95; c9_i96++) {
    c9_mystr[c9_i96] = c9_cv8[c9_i96];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i97 = 0; c9_i97 < 95; c9_i97++) {
    c9_arr[c9_i97] = c9_dv21[c9_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i98 = 0; c9_i98 < 256; c9_i98++) {
    c9_tt[c9_i98] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i99 = 0; c9_i99 < 95; c9_i99++) {
    c9_tt[c9_i99] = c9_arr[c9_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i100 = 0; c9_i100 < 256; c9_i100++) {
    c9_myarr256[c9_i100] = c9_tt[c9_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_j_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[88];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[88];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i101;
  static char_T c9_cv9[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i102;
  static real_T c9_dv22[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i103;
  int32_T c9_i104;
  int32_T c9_i105;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_q_debug_family_names,
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
  for (c9_i101 = 0; c9_i101 < 88; c9_i101++) {
    c9_mystr[c9_i101] = c9_cv9[c9_i101];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i102 = 0; c9_i102 < 88; c9_i102++) {
    c9_arr[c9_i102] = c9_dv22[c9_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i103 = 0; c9_i103 < 256; c9_i103++) {
    c9_tt[c9_i103] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i104 = 0; c9_i104 < 88; c9_i104++) {
    c9_tt[c9_i104] = c9_arr[c9_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i105 = 0; c9_i105 < 256; c9_i105++) {
    c9_myarr256[c9_i105] = c9_tt[c9_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_k_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[93];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[93];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i106;
  static char_T c9_cv10[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i107;
  static real_T c9_dv23[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i108;
  int32_T c9_i109;
  int32_T c9_i110;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_r_debug_family_names,
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
  for (c9_i106 = 0; c9_i106 < 93; c9_i106++) {
    c9_mystr[c9_i106] = c9_cv10[c9_i106];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i107 = 0; c9_i107 < 93; c9_i107++) {
    c9_arr[c9_i107] = c9_dv23[c9_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i108 = 0; c9_i108 < 256; c9_i108++) {
    c9_tt[c9_i108] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i109 = 0; c9_i109 < 93; c9_i109++) {
    c9_tt[c9_i109] = c9_arr[c9_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i110 = 0; c9_i110 < 256; c9_i110++) {
    c9_myarr256[c9_i110] = c9_tt[c9_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_l_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[97];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[97];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i111;
  static char_T c9_cv11[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i112;
  static real_T c9_dv24[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i113;
  int32_T c9_i114;
  int32_T c9_i115;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_s_debug_family_names,
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
  for (c9_i111 = 0; c9_i111 < 97; c9_i111++) {
    c9_mystr[c9_i111] = c9_cv11[c9_i111];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i112 = 0; c9_i112 < 97; c9_i112++) {
    c9_arr[c9_i112] = c9_dv24[c9_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i113 = 0; c9_i113 < 256; c9_i113++) {
    c9_tt[c9_i113] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i114 = 0; c9_i114 < 97; c9_i114++) {
    c9_tt[c9_i114] = c9_arr[c9_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i115 = 0; c9_i115 < 256; c9_i115++) {
    c9_myarr256[c9_i115] = c9_tt[c9_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_m_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[68];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[68];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i116;
  static char_T c9_cv12[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i117;
  static real_T c9_dv25[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i118;
  int32_T c9_i119;
  int32_T c9_i120;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_u_debug_family_names,
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
  for (c9_i116 = 0; c9_i116 < 68; c9_i116++) {
    c9_mystr[c9_i116] = c9_cv12[c9_i116];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i117 = 0; c9_i117 < 68; c9_i117++) {
    c9_arr[c9_i117] = c9_dv25[c9_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 68.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i118 = 0; c9_i118 < 256; c9_i118++) {
    c9_tt[c9_i118] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i119 = 0; c9_i119 < 68; c9_i119++) {
    c9_tt[c9_i119] = c9_arr[c9_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i120 = 0; c9_i120 < 256; c9_i120++) {
    c9_myarr256[c9_i120] = c9_tt[c9_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_n_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
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
  int32_T c9_i121;
  static char_T c9_cv13[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i122;
  static real_T c9_dv26[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i123;
  int32_T c9_i124;
  int32_T c9_i125;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_v_debug_family_names,
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
  for (c9_i121 = 0; c9_i121 < 87; c9_i121++) {
    c9_mystr[c9_i121] = c9_cv13[c9_i121];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i122 = 0; c9_i122 < 87; c9_i122++) {
    c9_arr[c9_i122] = c9_dv26[c9_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i123 = 0; c9_i123 < 256; c9_i123++) {
    c9_tt[c9_i123] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i124 = 0; c9_i124 < 87; c9_i124++) {
    c9_tt[c9_i124] = c9_arr[c9_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i125 = 0; c9_i125 < 256; c9_i125++) {
    c9_myarr256[c9_i125] = c9_tt[c9_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_o_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[223];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[223];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i126;
  static char_T c9_cv14[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c9_i127;
  static real_T c9_dv27[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i128;
  int32_T c9_i129;
  int32_T c9_i130;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_y_debug_family_names,
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
  for (c9_i126 = 0; c9_i126 < 223; c9_i126++) {
    c9_mystr[c9_i126] = c9_cv14[c9_i126];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i127 = 0; c9_i127 < 223; c9_i127++) {
    c9_arr[c9_i127] = c9_dv27[c9_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i128 = 0; c9_i128 < 256; c9_i128++) {
    c9_tt[c9_i128] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i129 = 0; c9_i129 < 223; c9_i129++) {
    c9_tt[c9_i129] = c9_arr[c9_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i130 = 0; c9_i130 < 256; c9_i130++) {
    c9_myarr256[c9_i130] = c9_tt[c9_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_p_encStr2Arr(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[142];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[142];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i131;
  static char_T c9_cv15[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i132;
  static real_T c9_dv28[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i133;
  int32_T c9_i134;
  int32_T c9_i135;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ab_debug_family_names,
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
  for (c9_i131 = 0; c9_i131 < 142; c9_i131++) {
    c9_mystr[c9_i131] = c9_cv15[c9_i131];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i132 = 0; c9_i132 < 142; c9_i132++) {
    c9_arr[c9_i132] = c9_dv28[c9_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i133 = 0; c9_i133 < 256; c9_i133++) {
    c9_tt[c9_i133] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i134 = 0; c9_i134 < 142; c9_i134++) {
    c9_tt[c9_i134] = c9_arr[c9_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i135 = 0; c9_i135 < 256; c9_i135++) {
    c9_myarr256[c9_i135] = c9_tt[c9_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c9_rand(SFc9_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance)
{
  return c9_eml_rand(chartInstance);
}

static real_T c9_eml_rand(SFc9_lib_affectiveChar_scenarioInstanceStruct
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
  int32_T c9_i136;
  uint32_T c9_icng;
  uint32_T c9_jsr;
  uint32_T c9_u1;
  uint32_T c9_u2;
  uint32_T c9_ui;
  uint32_T c9_b_ui;
  real_T c9_c_r;
  real_T c9_d1;
  uint32_T c9_uv2[625];
  int32_T c9_i137;
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
      for (c9_i136 = 0; c9_i136 < 2; c9_i136++) {
        chartInstance->c9_b_state[c9_i136] = 362436069U + 158852560U * (uint32_T)
          c9_i136;
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
      for (c9_i137 = 0; c9_i137 < 625; c9_i137++) {
        chartInstance->c9_c_state[c9_i137] = c9_uv2[c9_i137];
      }

      chartInstance->c9_c_state_not_empty = true;
    }

    c9_d2 = c9_c_eml_rand_mt19937ar(chartInstance, chartInstance->c9_c_state);
    c9_r = c9_d2;
  }

  return c9_r;
}

static void c9_eml_rand_mt19937ar(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_d_state[625])
{
  real_T c9_d3;
  int32_T c9_i138;
  c9_d3 = 5489.0;
  for (c9_i138 = 0; c9_i138 < 625; c9_i138++) {
    c9_d_state[c9_i138] = 0U;
  }

  c9_b_twister_state_vector(chartInstance, c9_d_state, c9_d3);
}

static void c9_twister_state_vector
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed, uint32_T c9_b_mt[625])
{
  int32_T c9_i139;
  for (c9_i139 = 0; c9_i139 < 625; c9_i139++) {
    c9_b_mt[c9_i139] = c9_mt[c9_i139];
  }

  c9_b_twister_state_vector(chartInstance, c9_b_mt, c9_seed);
}

static void c9_b_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_d_state[625], uint32_T c9_e_state[625], real_T *c9_r)
{
  int32_T c9_i140;
  for (c9_i140 = 0; c9_i140 < 625; c9_i140++) {
    c9_e_state[c9_i140] = c9_d_state[c9_i140];
  }

  *c9_r = c9_c_eml_rand_mt19937ar(chartInstance, c9_e_state);
}

static void c9_eml_error(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  int32_T c9_i141;
  static char_T c9_cv16[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c9_u[37];
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  for (c9_i141 = 0; c9_i141 < 37; c9_i141++) {
    c9_u[c9_i141] = c9_cv16[c9_i141];
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
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i142;
  real_T c9_b_inData[256];
  int32_T c9_i143;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i142 = 0; c9_i142 < 256; c9_i142++) {
    c9_b_inData[c9_i142] = (*(real_T (*)[256])c9_inData)[c9_i142];
  }

  for (c9_i143 = 0; c9_i143 < 256; c9_i143++) {
    c9_u[c9_i143] = c9_b_inData[c9_i143];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv29[256];
  int32_T c9_i144;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv29, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c9_i144 = 0; c9_i144 < 256; c9_i144++) {
    c9_y[c9_i144] = c9_dv29[c9_i144];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_poseBML;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[256];
  int32_T c9_i145;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_poseBML = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_poseBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_poseBML);
  for (c9_i145 = 0; c9_i145 < 256; c9_i145++) {
    (*(real_T (*)[256])c9_outData)[c9_i145] = c9_y[c9_i145];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_bmlID, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_bmlID), &c9_thisId);
  sf_mex_destroy(&c9_bmlID);
  return c9_y;
}

static real_T c9_c_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_bmlID = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_bmlID), &c9_thisId);
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
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_d_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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
  const mxArray *c9_aVarTruthTableCondition_2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_aVarTruthTableCondition_2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_aVarTruthTableCondition_2), &c9_thisId);
  sf_mex_destroy(&c9_aVarTruthTableCondition_2);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i146;
  real_T c9_b_inData[256];
  int32_T c9_i147;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i146 = 0; c9_i146 < 256; c9_i146++) {
    c9_b_inData[c9_i146] = (*(real_T (*)[256])c9_inData)[c9_i146];
  }

  for (c9_i147 = 0; c9_i147 < 256; c9_i147++) {
    c9_u[c9_i147] = c9_b_inData[c9_i147];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv30[256];
  int32_T c9_i148;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv30, 1, 0, 0U, 1, 0U, 1, 256);
  for (c9_i148 = 0; c9_i148 < 256; c9_i148++) {
    c9_y[c9_i148] = c9_dv30[c9_i148];
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
  int32_T c9_i149;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_myarr256 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
  for (c9_i149 = 0; c9_i149 < 256; c9_i149++) {
    (*(real_T (*)[256])c9_outData)[c9_i149] = c9_y[c9_i149];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i150;
  char_T c9_b_inData[94];
  int32_T c9_i151;
  char_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i150 = 0; c9_i150 < 94; c9_i150++) {
    c9_b_inData[c9_i150] = (*(char_T (*)[94])c9_inData)[c9_i150];
  }

  for (c9_i151 = 0; c9_i151 < 94; c9_i151++) {
    c9_u[c9_i151] = c9_b_inData[c9_i151];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i152;
  real_T c9_b_inData[94];
  int32_T c9_i153;
  real_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i152 = 0; c9_i152 < 94; c9_i152++) {
    c9_b_inData[c9_i152] = (*(real_T (*)[94])c9_inData)[c9_i152];
  }

  for (c9_i153 = 0; c9_i153 < 94; c9_i153++) {
    c9_u[c9_i153] = c9_b_inData[c9_i153];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i154;
  char_T c9_b_inData[86];
  int32_T c9_i155;
  char_T c9_u[86];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i154 = 0; c9_i154 < 86; c9_i154++) {
    c9_b_inData[c9_i154] = (*(char_T (*)[86])c9_inData)[c9_i154];
  }

  for (c9_i155 = 0; c9_i155 < 86; c9_i155++) {
    c9_u[c9_i155] = c9_b_inData[c9_i155];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i156;
  real_T c9_b_inData[86];
  int32_T c9_i157;
  real_T c9_u[86];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i156 = 0; c9_i156 < 86; c9_i156++) {
    c9_b_inData[c9_i156] = (*(real_T (*)[86])c9_inData)[c9_i156];
  }

  for (c9_i157 = 0; c9_i157 < 86; c9_i157++) {
    c9_u[c9_i157] = c9_b_inData[c9_i157];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i158;
  char_T c9_b_inData[165];
  int32_T c9_i159;
  char_T c9_u[165];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i158 = 0; c9_i158 < 165; c9_i158++) {
    c9_b_inData[c9_i158] = (*(char_T (*)[165])c9_inData)[c9_i158];
  }

  for (c9_i159 = 0; c9_i159 < 165; c9_i159++) {
    c9_u[c9_i159] = c9_b_inData[c9_i159];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 165),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i160;
  real_T c9_b_inData[165];
  int32_T c9_i161;
  real_T c9_u[165];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i160 = 0; c9_i160 < 165; c9_i160++) {
    c9_b_inData[c9_i160] = (*(real_T (*)[165])c9_inData)[c9_i160];
  }

  for (c9_i161 = 0; c9_i161 < 165; c9_i161++) {
    c9_u[c9_i161] = c9_b_inData[c9_i161];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 165), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i162;
  char_T c9_b_inData[161];
  int32_T c9_i163;
  char_T c9_u[161];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i162 = 0; c9_i162 < 161; c9_i162++) {
    c9_b_inData[c9_i162] = (*(char_T (*)[161])c9_inData)[c9_i162];
  }

  for (c9_i163 = 0; c9_i163 < 161; c9_i163++) {
    c9_u[c9_i163] = c9_b_inData[c9_i163];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i164;
  real_T c9_b_inData[161];
  int32_T c9_i165;
  real_T c9_u[161];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i164 = 0; c9_i164 < 161; c9_i164++) {
    c9_b_inData[c9_i164] = (*(real_T (*)[161])c9_inData)[c9_i164];
  }

  for (c9_i165 = 0; c9_i165 < 161; c9_i165++) {
    c9_u[c9_i165] = c9_b_inData[c9_i165];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i166;
  char_T c9_b_inData[93];
  int32_T c9_i167;
  char_T c9_u[93];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i166 = 0; c9_i166 < 93; c9_i166++) {
    c9_b_inData[c9_i166] = (*(char_T (*)[93])c9_inData)[c9_i166];
  }

  for (c9_i167 = 0; c9_i167 < 93; c9_i167++) {
    c9_u[c9_i167] = c9_b_inData[c9_i167];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i168;
  real_T c9_b_inData[93];
  int32_T c9_i169;
  real_T c9_u[93];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i168 = 0; c9_i168 < 93; c9_i168++) {
    c9_b_inData[c9_i168] = (*(real_T (*)[93])c9_inData)[c9_i168];
  }

  for (c9_i169 = 0; c9_i169 < 93; c9_i169++) {
    c9_u[c9_i169] = c9_b_inData[c9_i169];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i170;
  char_T c9_b_inData[90];
  int32_T c9_i171;
  char_T c9_u[90];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i170 = 0; c9_i170 < 90; c9_i170++) {
    c9_b_inData[c9_i170] = (*(char_T (*)[90])c9_inData)[c9_i170];
  }

  for (c9_i171 = 0; c9_i171 < 90; c9_i171++) {
    c9_u[c9_i171] = c9_b_inData[c9_i171];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 90), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i172;
  real_T c9_b_inData[90];
  int32_T c9_i173;
  real_T c9_u[90];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i172 = 0; c9_i172 < 90; c9_i172++) {
    c9_b_inData[c9_i172] = (*(real_T (*)[90])c9_inData)[c9_i172];
  }

  for (c9_i173 = 0; c9_i173 < 90; c9_i173++) {
    c9_u[c9_i173] = c9_b_inData[c9_i173];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 90), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i174;
  char_T c9_b_inData[104];
  int32_T c9_i175;
  char_T c9_u[104];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i174 = 0; c9_i174 < 104; c9_i174++) {
    c9_b_inData[c9_i174] = (*(char_T (*)[104])c9_inData)[c9_i174];
  }

  for (c9_i175 = 0; c9_i175 < 104; c9_i175++) {
    c9_u[c9_i175] = c9_b_inData[c9_i175];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i176;
  real_T c9_b_inData[104];
  int32_T c9_i177;
  real_T c9_u[104];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i176 = 0; c9_i176 < 104; c9_i176++) {
    c9_b_inData[c9_i176] = (*(real_T (*)[104])c9_inData)[c9_i176];
  }

  for (c9_i177 = 0; c9_i177 < 104; c9_i177++) {
    c9_u[c9_i177] = c9_b_inData[c9_i177];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i178;
  char_T c9_b_inData[95];
  int32_T c9_i179;
  char_T c9_u[95];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i178 = 0; c9_i178 < 95; c9_i178++) {
    c9_b_inData[c9_i178] = (*(char_T (*)[95])c9_inData)[c9_i178];
  }

  for (c9_i179 = 0; c9_i179 < 95; c9_i179++) {
    c9_u[c9_i179] = c9_b_inData[c9_i179];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i180;
  real_T c9_b_inData[95];
  int32_T c9_i181;
  real_T c9_u[95];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i180 = 0; c9_i180 < 95; c9_i180++) {
    c9_b_inData[c9_i180] = (*(real_T (*)[95])c9_inData)[c9_i180];
  }

  for (c9_i181 = 0; c9_i181 < 95; c9_i181++) {
    c9_u[c9_i181] = c9_b_inData[c9_i181];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i182;
  char_T c9_b_inData[88];
  int32_T c9_i183;
  char_T c9_u[88];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i182 = 0; c9_i182 < 88; c9_i182++) {
    c9_b_inData[c9_i182] = (*(char_T (*)[88])c9_inData)[c9_i182];
  }

  for (c9_i183 = 0; c9_i183 < 88; c9_i183++) {
    c9_u[c9_i183] = c9_b_inData[c9_i183];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i184;
  real_T c9_b_inData[88];
  int32_T c9_i185;
  real_T c9_u[88];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i184 = 0; c9_i184 < 88; c9_i184++) {
    c9_b_inData[c9_i184] = (*(real_T (*)[88])c9_inData)[c9_i184];
  }

  for (c9_i185 = 0; c9_i185 < 88; c9_i185++) {
    c9_u[c9_i185] = c9_b_inData[c9_i185];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i186;
  char_T c9_b_inData[97];
  int32_T c9_i187;
  char_T c9_u[97];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i186 = 0; c9_i186 < 97; c9_i186++) {
    c9_b_inData[c9_i186] = (*(char_T (*)[97])c9_inData)[c9_i186];
  }

  for (c9_i187 = 0; c9_i187 < 97; c9_i187++) {
    c9_u[c9_i187] = c9_b_inData[c9_i187];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i188;
  real_T c9_b_inData[97];
  int32_T c9_i189;
  real_T c9_u[97];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i188 = 0; c9_i188 < 97; c9_i188++) {
    c9_b_inData[c9_i188] = (*(real_T (*)[97])c9_inData)[c9_i188];
  }

  for (c9_i189 = 0; c9_i189 < 97; c9_i189++) {
    c9_u[c9_i189] = c9_b_inData[c9_i189];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i190;
  char_T c9_b_inData[68];
  int32_T c9_i191;
  char_T c9_u[68];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i190 = 0; c9_i190 < 68; c9_i190++) {
    c9_b_inData[c9_i190] = (*(char_T (*)[68])c9_inData)[c9_i190];
  }

  for (c9_i191 = 0; c9_i191 < 68; c9_i191++) {
    c9_u[c9_i191] = c9_b_inData[c9_i191];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i192;
  real_T c9_b_inData[68];
  int32_T c9_i193;
  real_T c9_u[68];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i192 = 0; c9_i192 < 68; c9_i192++) {
    c9_b_inData[c9_i192] = (*(real_T (*)[68])c9_inData)[c9_i192];
  }

  for (c9_i193 = 0; c9_i193 < 68; c9_i193++) {
    c9_u[c9_i193] = c9_b_inData[c9_i193];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i194;
  char_T c9_b_inData[87];
  int32_T c9_i195;
  char_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i194 = 0; c9_i194 < 87; c9_i194++) {
    c9_b_inData[c9_i194] = (*(char_T (*)[87])c9_inData)[c9_i194];
  }

  for (c9_i195 = 0; c9_i195 < 87; c9_i195++) {
    c9_u[c9_i195] = c9_b_inData[c9_i195];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i196;
  real_T c9_b_inData[87];
  int32_T c9_i197;
  real_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i196 = 0; c9_i196 < 87; c9_i196++) {
    c9_b_inData[c9_i196] = (*(real_T (*)[87])c9_inData)[c9_i196];
  }

  for (c9_i197 = 0; c9_i197 < 87; c9_i197++) {
    c9_u[c9_i197] = c9_b_inData[c9_i197];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i198;
  char_T c9_b_inData[223];
  int32_T c9_i199;
  char_T c9_u[223];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i198 = 0; c9_i198 < 223; c9_i198++) {
    c9_b_inData[c9_i198] = (*(char_T (*)[223])c9_inData)[c9_i198];
  }

  for (c9_i199 = 0; c9_i199 < 223; c9_i199++) {
    c9_u[c9_i199] = c9_b_inData[c9_i199];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i200;
  real_T c9_b_inData[223];
  int32_T c9_i201;
  real_T c9_u[223];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i200 = 0; c9_i200 < 223; c9_i200++) {
    c9_b_inData[c9_i200] = (*(real_T (*)[223])c9_inData)[c9_i200];
  }

  for (c9_i201 = 0; c9_i201 < 223; c9_i201++) {
    c9_u[c9_i201] = c9_b_inData[c9_i201];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i202;
  char_T c9_b_inData[142];
  int32_T c9_i203;
  char_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i202 = 0; c9_i202 < 142; c9_i202++) {
    c9_b_inData[c9_i202] = (*(char_T (*)[142])c9_inData)[c9_i202];
  }

  for (c9_i203 = 0; c9_i203 < 142; c9_i203++) {
    c9_u[c9_i203] = c9_b_inData[c9_i203];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i204;
  real_T c9_b_inData[142];
  int32_T c9_i205;
  real_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i204 = 0; c9_i204 < 142; c9_i204++) {
    c9_b_inData[c9_i204] = (*(real_T (*)[142])c9_inData)[c9_i204];
  }

  for (c9_i205 = 0; c9_i205 < 142; c9_i205++) {
    c9_u[c9_i205] = c9_b_inData[c9_i205];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i206;
  char_T c9_b_inData[183];
  int32_T c9_i207;
  char_T c9_u[183];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i206 = 0; c9_i206 < 183; c9_i206++) {
    c9_b_inData[c9_i206] = (*(char_T (*)[183])c9_inData)[c9_i206];
  }

  for (c9_i207 = 0; c9_i207 < 183; c9_i207++) {
    c9_u[c9_i207] = c9_b_inData[c9_i207];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i208;
  real_T c9_b_inData[183];
  int32_T c9_i209;
  real_T c9_u[183];
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i208 = 0; c9_i208 < 183; c9_i208++) {
    c9_b_inData[c9_i208] = (*(real_T (*)[183])c9_inData)[c9_i208];
  }

  for (c9_i209 = 0; c9_i209 < 183; c9_i209++) {
    c9_u[c9_i209] = c9_b_inData[c9_i209];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_lib_affectiveChar_scenario_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
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
  const mxArray *c9_rhs31 = NULL;
  const mxArray *c9_lhs31 = NULL;
  const mxArray *c9_rhs32 = NULL;
  const mxArray *c9_lhs32 = NULL;
  const mxArray *c9_rhs33 = NULL;
  const mxArray *c9_lhs33 = NULL;
  const mxArray *c9_rhs34 = NULL;
  const mxArray *c9_lhs34 = NULL;
  const mxArray *c9_rhs35 = NULL;
  const mxArray *c9_lhs35 = NULL;
  const mxArray *c9_rhs36 = NULL;
  const mxArray *c9_lhs36 = NULL;
  const mxArray *c9_rhs37 = NULL;
  const mxArray *c9_lhs37 = NULL;
  const mxArray *c9_rhs38 = NULL;
  const mxArray *c9_lhs38 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c9_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c9_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c9_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c9_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c9_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c9_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c9_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c9_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs38), "lhs", "lhs",
                  38);
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
  sf_mex_destroy(&c9_rhs31);
  sf_mex_destroy(&c9_lhs31);
  sf_mex_destroy(&c9_rhs32);
  sf_mex_destroy(&c9_lhs32);
  sf_mex_destroy(&c9_rhs33);
  sf_mex_destroy(&c9_lhs33);
  sf_mex_destroy(&c9_rhs34);
  sf_mex_destroy(&c9_lhs34);
  sf_mex_destroy(&c9_rhs35);
  sf_mex_destroy(&c9_lhs35);
  sf_mex_destroy(&c9_rhs36);
  sf_mex_destroy(&c9_lhs36);
  sf_mex_destroy(&c9_rhs37);
  sf_mex_destroy(&c9_lhs37);
  sf_mex_destroy(&c9_rhs38);
  sf_mex_destroy(&c9_lhs38);
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

static void c9_activate_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = c9_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_deactivate_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_increment_counters_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c9_temporalCounter_i1 < 7U) {
    chartInstance->c9_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i1 + 1);
  }
}

static void c9_reset_counters_secsc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c9_lib_affectiveChar_scenario_secs(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_activate_secsc9_lib_affectiveChar_scenario(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_increment_counters_secsc9_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c9_lib_affectiveChar_scenario_secs
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_reset_counters_secsc9_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_deactivate_c9_lib_affectiveChar_scenario_secs(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_deactivate_secsc9_lib_affectiveChar_scenario(chartInstance);
}

boolean_T sf_exported_auto_isStablec9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c9_isStable;
}

void sf_exported_auto_duringc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_c9_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_enterc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendSBM(chartInstance);
  c9_sendBML(chartInstance);
  c9_enter_atomic_c9_lib_affectiveChar_scenario(chartInstance);
  c9_enter_internal_c9_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_exitc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_exit_internal_c9_lib_affectiveChar_scenario(chartInstance);
  c9_b_sendSBM(chartInstance);
  c9_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendSBM(chartInstance);
  c9_sendBML(chartInstance);
}

void sf_exported_auto_disablec9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_b_sendSBM(chartInstance);
  c9_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  chartInstance->c9_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc9_lib_affectiveChar_scenario
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc9_lib_affectiveChar_scenario(SimStruct *
  c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc9_lib_affectiveChar_scenario(SimStruct
  *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc9_lib_affectiveChar_scenario(SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_initc9_lib_affectiveChar_scenario(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec9_lib_affectiveChar_scenario
  (SimStruct *c9_S)
{
  const mxArray *c9_out = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_out = NULL;
  sf_mex_assign(&c9_out, sf_internal_get_sim_state_c9_lib_affectiveChar_scenario
                (c9_S), false);
  return c9_out;
}

void sf_exported_auto_setSimstatec9_lib_affectiveChar_scenario(SimStruct *c9_S,
  const mxArray *c9_in)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c9_lib_affectiveChar_scenario(c9_S, sf_mex_dup(c9_in));
  sf_mex_destroy(&c9_in);
}

void sf_exported_auto_check_state_inconsistency_c9_lib_affectiveChar_scenario
  (SimStruct *c9_S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_scenarioMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_sendSBMc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_arg
   [256])
{
  int32_T c9_i210;
  int32_T c9_i211;
  int32_T c9_i212;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c9_i210 = 0; c9_i210 < 256; c9_i210++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i210], 22U);
  }

  _SFD_SET_DATA_VALUE_PTR(22U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i211 = 0; c9_i211 < 256; c9_i211++) {
    (*c9_b_arg)[c9_i211] = c9_arg[c9_i211];
  }

  for (c9_i212 = 0; c9_i212 < 256; c9_i212++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i212], 22U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(22U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
}

static void c9_sendBMLc9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_arg
   [256])
{
  int32_T c9_i213;
  int32_T c9_i214;
  int32_T c9_i215;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c9_i213 = 0; c9_i213 < 256; c9_i213++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i213], 23U);
  }

  _SFD_SET_DATA_VALUE_PTR(23U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i214 = 0; c9_i214 < 256; c9_i214++) {
    (*c9_b_arg)[c9_i214] = c9_arg[c9_i214];
  }

  for (c9_i215 = 0; c9_i215 < 256; c9_i215++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i215], 23U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
}

static void c9_rockPoseTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[6];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv31[256];
  int32_T c9_i216;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[94];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[94];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i217;
  static char_T c9_cv17[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i218;
  static real_T c9_dv32[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i219;
  int32_T c9_i220;
  int32_T c9_i221;
  int32_T c9_i222;
  int32_T c9_i223;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
    c9_encStr2Arr(chartInstance, c9_dv31);
    for (c9_i216 = 0; c9_i216 < 256; c9_i216++) {
      c9_poseBML[c9_i216] = c9_dv31[c9_i216];
    }

    c9_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_c_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      for (c9_i217 = 0; c9_i217 < 94; c9_i217++) {
        c9_mystr[c9_i217] = c9_cv17[c9_i217];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
      c9_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
      for (c9_i218 = 0; c9_i218 < 94; c9_i218++) {
        c9_arr[c9_i218] = c9_dv32[c9_i218];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
      c9_ss = 94.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
      c9_padsize = c9_maxarrsize - c9_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
      for (c9_i219 = 0; c9_i219 < 256; c9_i219++) {
        c9_tt[c9_i219] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
      for (c9_i220 = 0; c9_i220 < 94; c9_i220++) {
        c9_tt[c9_i220] = c9_arr[c9_i220];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
      for (c9_i221 = 0; c9_i221 < 256; c9_i221++) {
        c9_myarr256[c9_i221] = c9_tt[c9_i221];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c9_i222 = 0; c9_i222 < 256; c9_i222++) {
        c9_poseBML[c9_i222] = c9_myarr256[c9_i222];
      }

      c9_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
      c9_encStr2Arr(chartInstance, c9_dv31);
      for (c9_i223 = 0; c9_i223 < 256; c9_i223++) {
        c9_poseBML[c9_i223] = c9_dv31[c9_i223];
      }

      c9_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_paperPoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[5];
  boolean_T c9_aVarTruthTableCondition_1;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv33[256];
  int32_T c9_i224;
  int32_T c9_i225;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c9_d_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 10);
  if (CV_EML_IF(4, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 11);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 20);
    c9_b_encStr2Arr(chartInstance, c9_dv33);
    for (c9_i224 = 0; c9_i224 < 256; c9_i224++) {
      c9_poseBML[c9_i224] = c9_dv33[c9_i224];
    }

    c9_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -20);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 13);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 20);
    c9_b_encStr2Arr(chartInstance, c9_dv33);
    for (c9_i225 = 0; c9_i225 < 256; c9_i225++) {
      c9_poseBML[c9_i225] = c9_dv33[c9_i225];
    }

    c9_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -20);
  }

  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_scissorsPoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[5];
  boolean_T c9_aVarTruthTableCondition_1;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv34[256];
  int32_T c9_i226;
  int32_T c9_i227;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c9_f_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 10);
  if (CV_EML_IF(6, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 11);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 20);
    c9_b_encStr2Arr(chartInstance, c9_dv34);
    for (c9_i226 = 0; c9_i226 < 256; c9_i226++) {
      c9_poseBML[c9_i226] = c9_dv34[c9_i226];
    }

    c9_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -20);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 13);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 20);
    c9_b_encStr2Arr(chartInstance, c9_dv34);
    for (c9_i227 = 0; c9_i227 < 256; c9_i227++) {
      c9_poseBML[c9_i227] = c9_dv34[c9_i227];
    }

    c9_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -20);
  }

  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_sbmID,
   real_T c9_poseSBM[256])
{
  uint32_T c9_debug_family_var_map[8];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv35[256];
  int32_T c9_i228;
  int32_T c9_i229;
  int32_T c9_i230;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[90];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[90];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i231;
  static char_T c9_cv18[90] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', ')', ')' };

  int32_T c9_i232;
  static real_T c9_dv36[90] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0 };

  int32_T c9_i233;
  int32_T c9_i234;
  int32_T c9_i235;
  int32_T c9_i236;
  int32_T c9_i237;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_g_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_4, 3U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_sbmID, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseSBM, 7U, c9_sf_marshallOut,
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
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_1 = (c9_sbmID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_2 = (c9_sbmID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_3 = (c9_sbmID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 23);
  c9_aVarTruthTableCondition_4 = (c9_sbmID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 25);
  if (CV_EML_IF(1, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 26);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 41);
    c9_c_encStr2Arr(chartInstance, c9_dv35);
    for (c9_i228 = 0; c9_i228 < 256; c9_i228++) {
      c9_poseSBM[c9_i228] = c9_dv35[c9_i228];
    }

    c9_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -41);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 27);
    if (CV_EML_IF(1, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 28);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 47);
      c9_d_encStr2Arr(chartInstance, c9_dv35);
      for (c9_i229 = 0; c9_i229 < 256; c9_i229++) {
        c9_poseSBM[c9_i229] = c9_dv35[c9_i229];
      }

      c9_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -47);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 29);
      if (CV_EML_IF(1, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 30);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 53);
        c9_e_encStr2Arr(chartInstance, c9_dv35);
        for (c9_i230 = 0; c9_i230 < 256; c9_i230++) {
          c9_poseSBM[c9_i230] = c9_dv35[c9_i230];
        }

        c9_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -53);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 31);
        if (CV_EML_IF(1, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 32);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_k_debug_family_names,
            c9_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
            c9_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
            c9_d_sf_marshallOut, c9_d_sf_marshallIn);
          for (c9_i231 = 0; c9_i231 < 90; c9_i231++) {
            c9_mystr[c9_i231] = c9_cv18[c9_i231];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
          c9_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
          for (c9_i232 = 0; c9_i232 < 90; c9_i232++) {
            c9_arr[c9_i232] = c9_dv36[c9_i232];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
          c9_ss = 90.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
          c9_padsize = c9_maxarrsize - c9_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
          for (c9_i233 = 0; c9_i233 < 256; c9_i233++) {
            c9_tt[c9_i233] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
          for (c9_i234 = 0; c9_i234 < 90; c9_i234++) {
            c9_tt[c9_i234] = c9_arr[c9_i234];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
          for (c9_i235 = 0; c9_i235 < 256; c9_i235++) {
            c9_myarr256[c9_i235] = c9_tt[c9_i235];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c9_i236 = 0; c9_i236 < 256; c9_i236++) {
            c9_poseSBM[c9_i236] = c9_myarr256[c9_i236];
          }

          c9_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -59);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 34);
          CV_EML_FCN(1, 1);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 41);
          c9_c_encStr2Arr(chartInstance, c9_dv35);
          for (c9_i237 = 0; c9_i237 < 256; c9_i237++) {
            c9_poseSBM[c9_i237] = c9_dv35[c9_i237];
          }

          c9_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idlePoseRachelTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
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
  real_T c9_dv37[256];
  int32_T c9_i238;
  int32_T c9_i239;
  int32_T c9_i240;
  int32_T c9_i241;
  int32_T c9_i242;
  int32_T c9_i243;
  int32_T c9_i244;
  int32_T c9_i245;
  int32_T c9_i246;
  int32_T c9_i247;
  int32_T c9_i248;
  int32_T c9_i249;
  int32_T c9_i250;
  int32_T c9_i251;
  int32_T c9_i252;
  int32_T c9_i253;
  int32_T c9_i254;
  int32_T c9_i255;
  int32_T c9_i256;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c9_l_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 21U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 16);
  c9_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 17);
  c9_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 27);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 30);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 33);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 36);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 39);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 42);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 45);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 48);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 51);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 54);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 57);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 60);
  c9_aVarTruthTableCondition_13 = (c9_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 63);
  c9_aVarTruthTableCondition_14 = (c9_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 66);
  c9_aVarTruthTableCondition_15 = (c9_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 69);
  c9_aVarTruthTableCondition_16 = (c9_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 72);
  c9_aVarTruthTableCondition_17 = (c9_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 75);
  c9_aVarTruthTableCondition_18 = (c9_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 77);
  if (CV_EML_IF(2, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 78);
    CV_EML_FCN(2, 6);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 151U);
    c9_f_encStr2Arr(chartInstance, c9_dv37);
    for (c9_i238 = 0; c9_i238 < 256; c9_i238++) {
      c9_poseBML[c9_i238] = c9_dv37[c9_i238];
    }

    c9_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -151);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 79);
    if (CV_EML_IF(2, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 80);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, MAX_int8_T);
      c9_g_encStr2Arr(chartInstance, c9_dv37);
      for (c9_i239 = 0; c9_i239 < 256; c9_i239++) {
        c9_poseBML[c9_i239] = c9_dv37[c9_i239];
      }

      c9_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -127);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 81);
      if (CV_EML_IF(2, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 82);
        CV_EML_FCN(2, 1);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 121);
        c9_h_encStr2Arr(chartInstance, c9_dv37);
        for (c9_i240 = 0; c9_i240 < 256; c9_i240++) {
          c9_poseBML[c9_i240] = c9_dv37[c9_i240];
        }

        c9_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -121);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 83);
        if (CV_EML_IF(2, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 84);
          CV_EML_FCN(2, 2);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, MAX_int8_T);
          c9_g_encStr2Arr(chartInstance, c9_dv37);
          for (c9_i241 = 0; c9_i241 < 256; c9_i241++) {
            c9_poseBML[c9_i241] = c9_dv37[c9_i241];
          }

          c9_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -127);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 85);
          if (CV_EML_IF(2, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 86);
            CV_EML_FCN(2, 3);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 133U);
            c9_i_encStr2Arr(chartInstance, c9_dv37);
            for (c9_i242 = 0; c9_i242 < 256; c9_i242++) {
              c9_poseBML[c9_i242] = c9_dv37[c9_i242];
            }

            c9_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -133);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 87);
            if (CV_EML_IF(2, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 88);
              CV_EML_FCN(2, 7);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 157U);
              c9_j_encStr2Arr(chartInstance, c9_dv37);
              for (c9_i243 = 0; c9_i243 < 256; c9_i243++) {
                c9_poseBML[c9_i243] = c9_dv37[c9_i243];
              }

              c9_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -157);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 89);
              if (CV_EML_IF(2, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 90);
                CV_EML_FCN(2, 1);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 121);
                c9_h_encStr2Arr(chartInstance, c9_dv37);
                for (c9_i244 = 0; c9_i244 < 256; c9_i244++) {
                  c9_poseBML[c9_i244] = c9_dv37[c9_i244];
                }

                c9_updateDataWrittenToVector(chartInstance, 11U);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -121);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 91);
                if (CV_EML_IF(2, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 92);
                  CV_EML_FCN(2, 3);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 133U);
                  c9_i_encStr2Arr(chartInstance, c9_dv37);
                  for (c9_i245 = 0; c9_i245 < 256; c9_i245++) {
                    c9_poseBML[c9_i245] = c9_dv37[c9_i245];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 11U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -133);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 93);
                  if (CV_EML_IF(2, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 94);
                    CV_EML_FCN(2, 1);
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 121);
                    c9_h_encStr2Arr(chartInstance, c9_dv37);
                    for (c9_i246 = 0; c9_i246 < 256; c9_i246++) {
                      c9_poseBML[c9_i246] = c9_dv37[c9_i246];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 11U);
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -121);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 95);
                    if (CV_EML_IF(2, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 96);
                      CV_EML_FCN(2, 6);
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 151U);
                      c9_f_encStr2Arr(chartInstance, c9_dv37);
                      for (c9_i247 = 0; c9_i247 < 256; c9_i247++) {
                        c9_poseBML[c9_i247] = c9_dv37[c9_i247];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 11U);
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -151);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 97);
                      if (CV_EML_IF(2, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 98);
                        CV_EML_FCN(2, 7);
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 157U);
                        c9_j_encStr2Arr(chartInstance, c9_dv37);
                        for (c9_i248 = 0; c9_i248 < 256; c9_i248++) {
                          c9_poseBML[c9_i248] = c9_dv37[c9_i248];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 11U);
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -157);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 99);
                        if (CV_EML_IF(2, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 100);
                          CV_EML_FCN(2, 5);
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 145U);
                          c9_k_encStr2Arr(chartInstance, c9_dv37);
                          for (c9_i249 = 0; c9_i249 < 256; c9_i249++) {
                            c9_poseBML[c9_i249] = c9_dv37[c9_i249];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 11U);
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -145);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 101);
                          if (CV_EML_IF(2, 1, 12, c9_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 102);
                            CV_EML_FCN(2, 5);
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 145U);
                            c9_k_encStr2Arr(chartInstance, c9_dv37);
                            for (c9_i250 = 0; c9_i250 < 256; c9_i250++) {
                              c9_poseBML[c9_i250] = c9_dv37[c9_i250];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 11U);
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -145);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 103);
                            if (CV_EML_IF(2, 1, 13,
                                          c9_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 104);
                              CV_EML_FCN(2, 5);
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 145U);
                              c9_k_encStr2Arr(chartInstance, c9_dv37);
                              for (c9_i251 = 0; c9_i251 < 256; c9_i251++) {
                                c9_poseBML[c9_i251] = c9_dv37[c9_i251];
                              }

                              c9_updateDataWrittenToVector(chartInstance, 11U);
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -145);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 105);
                              if (CV_EML_IF(2, 1, 14,
                                            c9_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 106);
                                CV_EML_FCN(2, 4);
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              139U);
                                c9_l_encStr2Arr(chartInstance, c9_dv37);
                                for (c9_i252 = 0; c9_i252 < 256; c9_i252++) {
                                  c9_poseBML[c9_i252] = c9_dv37[c9_i252];
                                }

                                c9_updateDataWrittenToVector(chartInstance, 11U);
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              -139);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 107);
                                if (CV_EML_IF(2, 1, 15,
                                              c9_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                108);
                                  CV_EML_FCN(2, 3);
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                133U);
                                  c9_i_encStr2Arr(chartInstance, c9_dv37);
                                  for (c9_i253 = 0; c9_i253 < 256; c9_i253++) {
                                    c9_poseBML[c9_i253] = c9_dv37[c9_i253];
                                  }

                                  c9_updateDataWrittenToVector(chartInstance,
                                    11U);
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                -133);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                109);
                                  if (CV_EML_IF(2, 1, 16,
                                                c9_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  110);
                                    CV_EML_FCN(2, 5);
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  145U);
                                    c9_k_encStr2Arr(chartInstance, c9_dv37);
                                    for (c9_i254 = 0; c9_i254 < 256; c9_i254++)
                                    {
                                      c9_poseBML[c9_i254] = c9_dv37[c9_i254];
                                    }

                                    c9_updateDataWrittenToVector(chartInstance,
                                      11U);
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  -145);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  111);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c9_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    112);
                                      CV_EML_FCN(2, 3);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    133U);
                                      c9_i_encStr2Arr(chartInstance, c9_dv37);
                                      for (c9_i255 = 0; c9_i255 < 256; c9_i255++)
                                      {
                                        c9_poseBML[c9_i255] = c9_dv37[c9_i255];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    -133);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    114);
                                      CV_EML_FCN(2, 1);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    121);
                                      c9_h_encStr2Arr(chartInstance, c9_dv37);
                                      for (c9_i256 = 0; c9_i256 < 256; c9_i256++)
                                      {
                                        c9_poseBML[c9_i256] = c9_dv37[c9_i256];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
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

  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_initialPoseTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv38[256];
  int32_T c9_i257;
  int32_T c9_i258;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[97];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[97];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i259;
  static char_T c9_cv19[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i260;
  static real_T c9_dv39[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i261;
  int32_T c9_i262;
  int32_T c9_i263;
  int32_T c9_i264;
  int32_T c9_i265;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_t_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 17);
  if (CV_EML_IF(3, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 18);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 31);
    c9_m_encStr2Arr(chartInstance, c9_dv38);
    for (c9_i257 = 0; c9_i257 < 256; c9_i257++) {
      c9_poseBML[c9_i257] = c9_dv38[c9_i257];
    }

    c9_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -31);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 19);
    if (CV_EML_IF(3, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 20);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 37);
      c9_n_encStr2Arr(chartInstance, c9_dv38);
      for (c9_i258 = 0; c9_i258 < 256; c9_i258++) {
        c9_poseBML[c9_i258] = c9_dv38[c9_i258];
      }

      c9_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -37);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 21);
      if (CV_EML_IF(3, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 22);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 43);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_w_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_x_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
          c9_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_w_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
          c9_d_sf_marshallOut, c9_d_sf_marshallIn);
        for (c9_i259 = 0; c9_i259 < 97; c9_i259++) {
          c9_mystr[c9_i259] = c9_cv19[c9_i259];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
        c9_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
        for (c9_i260 = 0; c9_i260 < 97; c9_i260++) {
          c9_arr[c9_i260] = c9_dv39[c9_i260];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
        c9_ss = 97.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
        c9_padsize = c9_maxarrsize - c9_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
        for (c9_i261 = 0; c9_i261 < 256; c9_i261++) {
          c9_tt[c9_i261] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
        for (c9_i262 = 0; c9_i262 < 97; c9_i262++) {
          c9_tt[c9_i262] = c9_arr[c9_i262];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
        for (c9_i263 = 0; c9_i263 < 256; c9_i263++) {
          c9_myarr256[c9_i263] = c9_tt[c9_i263];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c9_i264 = 0; c9_i264 < 256; c9_i264++) {
          c9_poseBML[c9_i264] = c9_myarr256[c9_i264];
        }

        c9_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -43);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 24);
        CV_EML_FCN(3, 1);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 31);
        c9_m_encStr2Arr(chartInstance, c9_dv38);
        for (c9_i265 = 0; c9_i265 < 256; c9_i265++) {
          c9_poseBML[c9_i265] = c9_dv38[c9_i265];
        }

        c9_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -31);
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_successTablec9_lib_affectiveChar_scenario
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c9_bmlID,
   real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv40[256];
  int32_T c9_i266;
  int32_T c9_i267;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[183];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[183];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i268;
  static char_T c9_cv20[183] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 's', 'i',
    'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't',
    '=', '\"', '0', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's',
    '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o', 'u', 'n', 't',
    '=', '\"', '0', '.', '8', '\"', ' ', ' ', 'a', 'u', '=', '\"', '2', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"',
    'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"',
    ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i269;
  static real_T c9_dv41[183] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 56.0, 34.0, 32.0, 32.0, 97.0, 117.0, 61.0, 34.0, 50.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i270;
  int32_T c9_i271;
  int32_T c9_i272;
  int32_T c9_i273;
  int32_T c9_i274;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_x_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(31, 0);
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 20);
  if (CV_EML_IF(31, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 21);
    CV_EML_FCN(31, 1);
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 34);
    c9_o_encStr2Arr(chartInstance, c9_dv40);
    for (c9_i266 = 0; c9_i266 < 256; c9_i266++) {
      c9_poseBML[c9_i266] = c9_dv40[c9_i266];
    }

    c9_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -34);
  } else {
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 22);
    if (CV_EML_IF(31, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 23);
      CV_EML_FCN(31, 2);
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 40);
      c9_p_encStr2Arr(chartInstance, c9_dv40);
      for (c9_i267 = 0; c9_i267 < 256; c9_i267++) {
        c9_poseBML[c9_i267] = c9_dv40[c9_i267];
      }

      c9_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -40);
    } else {
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 24);
      if (CV_EML_IF(31, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 25);
        CV_EML_FCN(31, 3);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_bb_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ib_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
          c9_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_hb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
          c9_d_sf_marshallOut, c9_d_sf_marshallIn);
        for (c9_i268 = 0; c9_i268 < 183; c9_i268++) {
          c9_mystr[c9_i268] = c9_cv20[c9_i268];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
        c9_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
        for (c9_i269 = 0; c9_i269 < 183; c9_i269++) {
          c9_arr[c9_i269] = c9_dv41[c9_i269];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
        c9_ss = 183.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
        c9_padsize = c9_maxarrsize - c9_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
        for (c9_i270 = 0; c9_i270 < 256; c9_i270++) {
          c9_tt[c9_i270] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
        for (c9_i271 = 0; c9_i271 < 183; c9_i271++) {
          c9_tt[c9_i271] = c9_arr[c9_i271];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
        for (c9_i272 = 0; c9_i272 < 256; c9_i272++) {
          c9_myarr256[c9_i272] = c9_tt[c9_i272];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c9_i273 = 0; c9_i273 < 256; c9_i273++) {
          c9_poseBML[c9_i273] = c9_myarr256[c9_i273];
        }

        c9_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -46);
      } else {
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 27);
        CV_EML_FCN(31, 1);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 34);
        c9_o_encStr2Arr(chartInstance, c9_dv40);
        for (c9_i274 = 0; c9_i274 < 256; c9_i274++) {
          c9_poseBML[c9_i274] = c9_dv40[c9_i274];
        }

        c9_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_sendSBM(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c9_b_sendSBM(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c9_sendBML(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void c9_b_sendBML(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_handPoseSBRachelTable
  (SimStruct *c9_S, real_T c9_sbmID, real_T c9_poseSBM[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_handPoseSBRachelTablec9_lib_affectiveChar_scenario(chartInstance, c9_sbmID,
    c9_poseSBM);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_idlePoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_idlePoseRachelTablec9_lib_affectiveChar_scenario(chartInstance, c9_bmlID,
    c9_poseBML);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_initialPoseTable(SimStruct
  *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_initialPoseTablec9_lib_affectiveChar_scenario(chartInstance, c9_bmlID,
    c9_poseBML);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_paperPoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_paperPoseRachelTablec9_lib_affectiveChar_scenario(chartInstance, c9_bmlID,
    c9_poseBML);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_rockPoseTable(SimStruct
  *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_rockPoseTablec9_lib_affectiveChar_scenario(chartInstance, c9_bmlID,
    c9_poseBML);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_scissorsPoseRachelTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_scissorsPoseRachelTablec9_lib_affectiveChar_scenario(chartInstance,
    c9_bmlID, c9_poseBML);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_sendBML(SimStruct *c9_S,
  real_T c9_arg[256])
{
  int32_T c9_i275;
  real_T c9_b_arg[256];
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  for (c9_i275 = 0; c9_i275 < 256; c9_i275++) {
    c9_b_arg[c9_i275] = c9_arg[c9_i275];
  }

  c9_sendBMLc9_lib_affectiveChar_scenario(chartInstance, c9_b_arg);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_sendSBM(SimStruct *c9_S,
  real_T c9_arg[256])
{
  int32_T c9_i276;
  real_T c9_b_arg[256];
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  for (c9_i276 = 0; c9_i276 < 256; c9_i276++) {
    c9_b_arg[c9_i276] = c9_arg[c9_i276];
  }

  c9_sendSBMc9_lib_affectiveChar_scenario(chartInstance, c9_b_arg);
}

void sf_exported_user_c9_lib_affectiveChar_scenario_successTable(SimStruct *c9_S,
  real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_successTablec9_lib_affectiveChar_scenario(chartInstance, c9_bmlID,
    c9_poseBML);
}

static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int8_T c9_f_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int8_T c9_y;
  int8_T c9_i277;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i277, 1, 2, 0U, 0, 0U, 0);
  c9_y = c9_i277;
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
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_secs = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_secs), &c9_thisId);
  sf_mex_destroy(&c9_secs);
  *(int8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_g_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i278;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i278, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i278;
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
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_tp_stateStart, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateStart),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateStart);
  return c9_y;
}

static uint8_T c9_i_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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
  const mxArray *c9_b_tp_stateStart;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c9_b_tp_stateStart = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateStart),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateStart);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint32_T c9_j_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_method, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_method),
    &c9_thisId);
  sf_mex_destroy(&c9_b_method);
  return c9_y;
}

static uint32_T c9_k_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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

static uint32_T c9_l_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_d_state, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId);
  sf_mex_destroy(&c9_d_state);
  return c9_y;
}

static uint32_T c9_m_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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

static void c9_n_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_o_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625])
{
  uint32_T c9_uv3[625];
  int32_T c9_i279;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_c_state_not_empty = false;
  } else {
    chartInstance->c9_c_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c9_i279 = 0; c9_i279 < 625; c9_i279++) {
      c9_y[c9_i279] = c9_uv3[c9_i279];
    }
  }

  sf_mex_destroy(&c9_u);
}

static void c9_p_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_q_emlrt_marshallIn(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2])
{
  uint32_T c9_uv4[2];
  int32_T c9_i280;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_b_state_not_empty = false;
  } else {
    chartInstance->c9_b_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c9_i280 = 0; c9_i280 < 2; c9_i280++) {
      c9_y[c9_i280] = c9_uv4[c9_i280];
    }
  }

  sf_mex_destroy(&c9_u);
}

static const mxArray *c9_r_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_s_emlrt_marshallIn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
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
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c9_errorIfDataNotWrittenToFcn
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_vectorIndex, uint32_T c9_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 13, 1,
    0)]);
}

static void c9_b_twister_state_vector
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_mt
   [625], real_T c9_seed)
{
  real_T c9_d5;
  uint32_T c9_u6;
  uint32_T c9_r;
  int32_T c9_mti;
  real_T c9_b_mti;
  real_T c9_d6;
  uint32_T c9_u7;
  (void)chartInstance;
  c9_d5 = c9_seed;
  if (c9_d5 < 4.294967296E+9) {
    if (c9_d5 >= 0.0) {
      c9_u6 = (uint32_T)c9_d5;
    } else {
      c9_u6 = 0U;
    }
  } else if (c9_d5 >= 4.294967296E+9) {
    c9_u6 = MAX_uint32_T;
  } else {
    c9_u6 = 0U;
  }

  c9_r = c9_u6;
  c9_mt[0] = c9_r;
  for (c9_mti = 0; c9_mti < 623; c9_mti++) {
    c9_b_mti = 2.0 + (real_T)c9_mti;
    c9_d6 = muDoubleScalarRound(c9_b_mti - 1.0);
    if (c9_d6 < 4.294967296E+9) {
      if (c9_d6 >= 0.0) {
        c9_u7 = (uint32_T)c9_d6;
      } else {
        c9_u7 = 0U;
      }
    } else if (c9_d6 >= 4.294967296E+9) {
      c9_u7 = MAX_uint32_T;
    } else {
      c9_u7 = 0U;
    }

    c9_r = (c9_r ^ c9_r >> 30U) * 1812433253U + c9_u7;
    c9_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c9_b_mti), 1, 625, 1, 0) - 1] = c9_r;
  }

  c9_mt[624] = 624U;
}

static real_T c9_c_eml_rand_mt19937ar
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c9_d_state[625])
{
  int32_T c9_i281;
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
    for (c9_i281 = 0; c9_i281 < 2; c9_i281++) {
      c9_u[c9_i281] = 0U;
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
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1867) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_BOREDOM_THRESHOLD_address;
}

static void c9_set_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1867) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_BOREDOM_THRESHOLD_address = c9_c;
}

static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1867) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_BOREDOM_THRESHOLD_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static real_T c9_get_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1875) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_avert_address;
}

static void c9_set_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1875) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_avert_address = c9_c;
}

static real_T *c9_access_avert(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1875) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_avert_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c9_c;
}

static real_T c9_get_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1862) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_bHand_address;
}

static void c9_set_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1862) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_bHand_address = c9_c;
}

static real_T *c9_access_bHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c9_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1862) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_bHand_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c9_c;
}

static real_T c9_get_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1866) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_boredom_address;
}

static void c9_set_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1866) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_boredom_address = c9_c;
}

static real_T *c9_access_boredom(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1866) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_boredom_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c9_c;
}

static real_T c9_get_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1860) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_diff_address;
}

static void c9_set_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1860) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_diff_address = c9_c;
}

static real_T *c9_access_diff(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c9_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1860) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_diff_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c9_c;
}

static real_T c9_get_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1870) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_isPosing_address;
}

static void c9_set_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1870) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_isPosing_address = c9_c;
}

static real_T *c9_access_isPosing(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1870) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_isPosing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c9_c;
}

static real_T c9_get_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1872) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_p_address;
}

static void c9_set_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1872) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_p_address = c9_c;
}

static real_T *c9_access_p(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c9_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1872) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_p_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c9_c;
}

static real_T c9_get_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1871) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_r_address;
}

static void c9_set_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1871) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_r_address = c9_c;
}

static real_T *c9_access_r(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c9_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1871) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_r_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c9_c;
}

static real_T c9_get_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1868) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randAvertGazeChance_address;
}

static void c9_set_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b,
   real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1868) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randAvertGazeChance_address = c9_c;
}

static real_T *c9_access_randAvertGazeChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1868) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randAvertGazeChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c9_c;
}

static real_T c9_get_randPoseChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1869) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randPoseChance_address;
}

static void c9_set_randPoseChance(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1869) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randPoseChance_address = c9_c;
}

static real_T *c9_access_randPoseChance
  (SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1869) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randPoseChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c9_c;
}

static real_T c9_get_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1873) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_s_address;
}

static void c9_set_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1873) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_s_address = c9_c;
}

static real_T *c9_access_s(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c9_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1873) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_s_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c9_c;
}

static real_T c9_get_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1859) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_temp_address;
}

static void c9_set_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1859) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_temp_address = c9_c;
}

static real_T *c9_access_temp(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c9_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1859) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_temp_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c9_c;
}

static real_T c9_get_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1861) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_uHand_address;
}

static void c9_set_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1861) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_uHand_address = c9_c;
}

static real_T *c9_access_uHand(SFc9_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c9_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1861) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_uHand_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info(SFc9_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c9_BOREDOM_THRESHOLD_address,
    &chartInstance->c9_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c9_avert_address, &chartInstance->c9_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c9_bHand_address, &chartInstance->c9_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c9_boredom_address, &chartInstance->c9_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c9_diff_address, &chartInstance->c9_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c9_isPosing_address, &chartInstance->c9_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c9_p_address, &chartInstance->c9_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c9_r_address, &chartInstance->c9_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c9_randAvertGazeChance_address,
    &chartInstance->c9_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c9_randPoseChance_address,
    &chartInstance->c9_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c9_s_address, &chartInstance->c9_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c9_temp_address, &chartInstance->c9_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c9_uHand_address, &chartInstance->c9_uHand_index);
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

void sf_c9_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2230192264U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(790382334U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3499124798U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1802053130U);
}

mxArray *sf_c9_lib_affectiveChar_scenario_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("soG6u6qcmttOzedb6z6Y9");
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

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_lib_affectiveChar_scenario_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_lib_affectiveChar_scenario_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_lib_affectiveChar_scenario(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"bWinT\",},{M[1],M[86],T\"bradHand\",},{M[1],M[84],T\"gameState\",},{M[1],M[106],T\"round\",},{M[1],M[94],T\"uWinT\",},{M[1],M[87],T\"userHand\",},{M[1],M[88],T\"win\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c9_lib_affectiveChar_scenario\",},{M[9],M[0],T\"is_c9_lib_affectiveChar_scenario\",},{M[11],M[107],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x13[54 83 59 58 62 61 64 67 69 71 79 78 77],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_lib_affectiveChar_scenario_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_scenarioMachineNumber_,
           9,
           32,
           35,
           0,
           38,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(2,2,0,1,"bradHand");
          _SFD_SET_DATA_PROPS(3,2,0,1,"userHand");
          _SFD_SET_DATA_PROPS(4,2,0,1,"win");
          _SFD_SET_DATA_PROPS(5,11,0,0,"temp");
          _SFD_SET_DATA_PROPS(6,11,0,0,"diff");
          _SFD_SET_DATA_PROPS(7,11,0,0,"uHand");
          _SFD_SET_DATA_PROPS(8,11,0,0,"bHand");
          _SFD_SET_DATA_PROPS(9,2,0,1,"bWinT");
          _SFD_SET_DATA_PROPS(10,2,0,1,"uWinT");
          _SFD_SET_DATA_PROPS(11,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(12,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(13,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(14,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(15,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(16,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(17,11,0,0,"r");
          _SFD_SET_DATA_PROPS(18,11,0,0,"p");
          _SFD_SET_DATA_PROPS(19,11,0,0,"s");
          _SFD_SET_DATA_PROPS(20,2,0,1,"round");
          _SFD_SET_DATA_PROPS(21,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,9,0,0,"");
          _SFD_SET_DATA_PROPS(28,8,0,0,"");
          _SFD_SET_DATA_PROPS(29,9,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
          _SFD_SET_DATA_PROPS(31,9,0,0,"");
          _SFD_SET_DATA_PROPS(32,8,0,0,"");
          _SFD_SET_DATA_PROPS(33,9,0,0,"");
          _SFD_SET_DATA_PROPS(34,8,0,0,"");
          _SFD_SET_DATA_PROPS(35,9,0,0,"");
          _SFD_SET_DATA_PROPS(36,8,0,0,"");
          _SFD_SET_DATA_PROPS(37,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
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
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(31,0,2);
          _SFD_CH_SUBSTATE_COUNT(23);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,9);
          _SFD_CH_SUBSTATE_INDEX(2,10);
          _SFD_CH_SUBSTATE_INDEX(3,11);
          _SFD_CH_SUBSTATE_INDEX(4,12);
          _SFD_CH_SUBSTATE_INDEX(5,13);
          _SFD_CH_SUBSTATE_INDEX(6,14);
          _SFD_CH_SUBSTATE_INDEX(7,15);
          _SFD_CH_SUBSTATE_INDEX(8,16);
          _SFD_CH_SUBSTATE_INDEX(9,17);
          _SFD_CH_SUBSTATE_INDEX(10,18);
          _SFD_CH_SUBSTATE_INDEX(11,19);
          _SFD_CH_SUBSTATE_INDEX(12,20);
          _SFD_CH_SUBSTATE_INDEX(13,21);
          _SFD_CH_SUBSTATE_INDEX(14,22);
          _SFD_CH_SUBSTATE_INDEX(15,23);
          _SFD_CH_SUBSTATE_INDEX(16,24);
          _SFD_CH_SUBSTATE_INDEX(17,25);
          _SFD_CH_SUBSTATE_INDEX(18,26);
          _SFD_CH_SUBSTATE_INDEX(19,27);
          _SFD_CH_SUBSTATE_INDEX(20,28);
          _SFD_CH_SUBSTATE_INDEX(21,29);
          _SFD_CH_SUBSTATE_INDEX(22,30);
          _SFD_ST_SUBSTATE_COUNT(0,0);
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
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(26,0);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
        }

        _SFD_CV_INIT_CHART(23,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"rockPoseTablec9_lib_affectiveChar_scenario",0,
                             -1,401);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",401,-1,563);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",563,-1,725);
        _SFD_CV_INIT_EML_IF(5,1,0,225,255,286,399);
        _SFD_CV_INIT_EML_IF(5,1,1,286,320,351,399);
        _SFD_CV_INIT_EML(4,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,
                             "paperPoseRachelTablec9_lib_affectiveChar_scenario",
                             0,-1,253);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",253,-1,407);
        _SFD_CV_INIT_EML_IF(4,1,0,142,172,203,251);
        _SFD_CV_INIT_EML(6,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,
                             "scissorsPoseRachelTablec9_lib_affectiveChar_scenario",
                             0,-1,259);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",259,-1,416);
        _SFD_CV_INIT_EML_IF(6,1,0,148,178,209,257);
        _SFD_CV_INIT_EML(1,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,
                             "handPoseSBRachelTablec9_lib_affectiveChar_scenario",
                             0,-1,765);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",765,-1,1006);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1006,-1,1245);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1245,-1,1419);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1419,-1,1589);
        _SFD_CV_INIT_EML_IF(1,1,0,459,489,520,763);
        _SFD_CV_INIT_EML_IF(1,1,1,520,554,585,763);
        _SFD_CV_INIT_EML_IF(1,1,2,585,619,650,763);
        _SFD_CV_INIT_EML_IF(1,1,3,650,684,715,763);
        _SFD_CV_INIT_EML(2,1,8,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,
                             "idlePoseRachelTablec9_lib_affectiveChar_scenario",
                             0,-1,2811);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",2811,-1,2979);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",2979,-1,3159);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",3159,-1,3329);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",3329,-1,3511);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",3511,-1,3681);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",3681,-1,3850);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",3850,-1,4016);
        _SFD_CV_INIT_EML_IF(2,1,0,1586,1616,1647,2809);
        _SFD_CV_INIT_EML_IF(2,1,1,1647,1681,1712,2809);
        _SFD_CV_INIT_EML_IF(2,1,2,1712,1746,1777,2809);
        _SFD_CV_INIT_EML_IF(2,1,3,1777,1811,1842,2809);
        _SFD_CV_INIT_EML_IF(2,1,4,1842,1876,1907,2809);
        _SFD_CV_INIT_EML_IF(2,1,5,1907,1941,1972,2809);
        _SFD_CV_INIT_EML_IF(2,1,6,1972,2006,2037,2809);
        _SFD_CV_INIT_EML_IF(2,1,7,2037,2071,2102,2809);
        _SFD_CV_INIT_EML_IF(2,1,8,2102,2136,2167,2809);
        _SFD_CV_INIT_EML_IF(2,1,9,2167,2202,2233,2809);
        _SFD_CV_INIT_EML_IF(2,1,10,2233,2268,2299,2809);
        _SFD_CV_INIT_EML_IF(2,1,11,2299,2334,2365,2809);
        _SFD_CV_INIT_EML_IF(2,1,12,2365,2400,2431,2809);
        _SFD_CV_INIT_EML_IF(2,1,13,2431,2466,2497,2809);
        _SFD_CV_INIT_EML_IF(2,1,14,2497,2532,2563,2809);
        _SFD_CV_INIT_EML_IF(2,1,15,2563,2598,2629,2809);
        _SFD_CV_INIT_EML_IF(2,1,16,2629,2664,2695,2809);
        _SFD_CV_INIT_EML_IF(2,1,17,2695,2730,2761,2809);
        _SFD_CV_INIT_EML(3,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"initialPoseTablec9_lib_affectiveChar_scenario",
                             0,-1,537);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",537,-1,682);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",682,-1,848);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",848,-1,1013);
        _SFD_CV_INIT_EML_IF(3,1,0,296,326,357,535);
        _SFD_CV_INIT_EML_IF(3,1,1,357,391,422,535);
        _SFD_CV_INIT_EML_IF(3,1,2,422,456,487,535);
        _SFD_CV_INIT_EML(31,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(31,0,"successTablec9_lib_affectiveChar_scenario",0,
                             -1,566);
        _SFD_CV_INIT_EML_FCN(31,1,"aFcnTruthTableAction_1",566,-1,858);
        _SFD_CV_INIT_EML_FCN(31,2,"aFcnTruthTableAction_2",858,-1,1075);
        _SFD_CV_INIT_EML_FCN(31,3,"aFcnTruthTableAction_3",1075,-1,1327);
        _SFD_CV_INIT_EML_IF(31,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(31,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(31,1,2,451,485,516,564);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,0,23,0,23);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,0,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(20,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(20,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(21,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(21,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(24,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(24,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(31,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(31,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(34,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
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
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(36,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(37,(void *)(NULL));

        {
          real_T *c9_gameState;
          real_T *c9_inputUser;
          real_T *c9_bradHand;
          real_T *c9_userHand;
          real_T *c9_win;
          real_T *c9_bWinT;
          real_T *c9_uWinT;
          real_T *c9_isSmiling;
          real_T *c9_round;
          c9_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c9_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c9_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c9_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c9_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c9_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c9_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c9_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, c9_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c9_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(13U,
            chartInstance->c9_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c9_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c9_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c9_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c9_r_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c9_p_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c9_s_address);
          _SFD_SET_DATA_VALUE_PTR(20U, c9_round);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c9_avert_address);
        }
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
  return "cfoxFIYl3uuPxK9GdSQ4dD";
}

static void sf_opaque_initialize_c9_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_lib_affectiveChar_scenarioInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
  initialize_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  enable_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  disable_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  sf_gateway_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_lib_affectiveChar_scenario
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_lib_affectiveChar_scenario();/* state var info */
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

extern void sf_internal_set_sim_state_c9_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_lib_affectiveChar_scenario();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_lib_affectiveChar_scenario
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c9_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c9_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_lib_affectiveChar_scenarioInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_scenario_optimization_info();
    }

    finalize_c9_lib_affectiveChar_scenario
      ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_lib_affectiveChar_scenario
    ((SFc9_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_lib_affectiveChar_scenario(SimStruct *S)
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
    initialize_params_c9_lib_affectiveChar_scenario
      ((SFc9_lib_affectiveChar_scenarioInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_scenario_optimization_info();
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
      (),infoStruct,9,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,9);
    }

    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=9; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3756315933U));
  ssSetChecksum1(S,(2807036266U));
  ssSetChecksum2(S,(1378951087U));
  ssSetChecksum3(S,(517834339U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_lib_affectiveChar_scenario(SimStruct *S)
{
  SFc9_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_lib_affectiveChar_scenarioInstanceStruct *)utMalloc
    (sizeof(SFc9_lib_affectiveChar_scenarioInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_lib_affectiveChar_scenarioInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_lib_affectiveChar_scenario;
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

void c9_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_lib_affectiveChar_scenario(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_lib_affectiveChar_scenario_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
