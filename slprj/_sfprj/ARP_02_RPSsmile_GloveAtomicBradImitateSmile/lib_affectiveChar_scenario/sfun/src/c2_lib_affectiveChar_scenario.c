/* Include files */

#include <stddef.h>
#include "blas.h"
#include "lib_affectiveChar_scenario_sfun.h"
#include "c2_lib_affectiveChar_scenario.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "lib_affectiveChar_scenario_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c2_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_gameOver                 ((uint8_T)1U)
#define c2_IN_stateBradWin             ((uint8_T)2U)
#define c2_IN_stateBrowUp              ((uint8_T)3U)
#define c2_IN_stateCompare             ((uint8_T)4U)
#define c2_IN_stateGo                  ((uint8_T)5U)
#define c2_IN_stateHeadNeutral2        ((uint8_T)6U)
#define c2_IN_stateNeckBack            ((uint8_T)7U)
#define c2_IN_stateNoWin               ((uint8_T)8U)
#define c2_IN_stateNotWinBored         ((uint8_T)9U)
#define c2_IN_statePoseFingersCLose    ((uint8_T)10U)
#define c2_IN_statePosePaper           ((uint8_T)11U)
#define c2_IN_statePoseReady           ((uint8_T)12U)
#define c2_IN_statePoseReturnFinger    ((uint8_T)13U)
#define c2_IN_statePoseRock            ((uint8_T)14U)
#define c2_IN_statePoseScissors        ((uint8_T)15U)
#define c2_IN_stateRandomHand          ((uint8_T)16U)
#define c2_IN_stateReadUserHand        ((uint8_T)17U)
#define c2_IN_stateReady               ((uint8_T)18U)
#define c2_IN_stateShowHands           ((uint8_T)19U)
#define c2_IN_stateShowResult          ((uint8_T)20U)
#define c2_IN_stateStart               ((uint8_T)21U)
#define c2_IN_stateUserWin             ((uint8_T)22U)
#define c2_IN_stateWinSmile            ((uint8_T)23U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c2_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c2_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_g_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c2_h_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c2_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_m_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c2_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_y_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c2_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_db_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c2_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c2_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c2_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initialize_params_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void enable_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void disable_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void set_sim_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void finalize_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void sf_gateway_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_enter_atomic_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_enter_internal_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_exit_internal_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_initc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void initSimStructsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_enter_atomic_stateReady
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_stateReady(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_gameOver(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_enter_atomic_statePoseReady
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_statePoseReady(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateHeadNeutral2(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateGo(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateNeckBack(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateRandomHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_statePoseFingersCLose
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_statePosePaper(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_statePoseRock(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateReadUserHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_statePoseReturnFinger
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_stateCompare(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateBradWin(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_stateNoWin(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_b_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_c_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_d_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_e_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_f_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_g_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_h_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_i_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_j_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_k_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_l_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_m_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_n_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_o_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_p_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_q_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_r_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_s_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_t_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static void c2_u_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256]);
static real_T c2_rand(SFc2_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance);
static real_T c2_eml_rand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_eml_rand_mt19937ar(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_d_state[625]);
static void c2_twister_state_vector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_mt
   [625], real_T c2_seed, uint32_T c2_b_mt[625]);
static void c2_b_eml_rand_mt19937ar
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_d_state[625], uint32_T c2_e_state[625], real_T *c2_r);
static void c2_eml_error(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static real_T c2_randi(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_b_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_bmlID, const char_T *c2_identifier);
static real_T c2_c_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_d_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_w_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_x_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_y_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_db_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static void c2_activate_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_deactivate_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_increment_counters_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_reset_counters_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance);
static void c2_sendSBMc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_arg
   [256]);
static void c2_sendBMLc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_arg
   [256]);
static void c2_rockPoseTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_paperPoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_scissorsPoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_handPoseSBTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_sbmID,
   real_T c2_poseSBM[256]);
static void c2_idlePoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_initialPoseTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_successTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256]);
static void c2_sendSBM(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_b_sendSBM(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_sendBML(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static void c2_b_sendBML(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance);
static const mxArray *c2_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int8_T c2_f_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_g_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_stateStart, const char_T *c2_identifier);
static uint8_T c2_i_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_j_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_method, const char_T *c2_identifier);
static uint32_T c2_k_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint32_T c2_l_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_d_state, const char_T *c2_identifier);
static uint32_T c2_m_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_n_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier,
  uint32_T c2_y[625]);
static void c2_o_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[625]);
static void c2_p_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier,
  uint32_T c2_y[2]);
static void c2_q_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[2]);
static const mxArray *c2_r_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_s_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_updateDataWrittenToVector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_vectorIndex);
static void c2_errorIfDataNotWrittenToFcn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_vectorIndex, uint32_T c2_dataNumber);
static void c2_b_twister_state_vector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_mt
   [625], real_T c2_seed);
static real_T c2_c_eml_rand_mt19937ar
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_d_state[625]);
static real_T c2_get_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static void c2_set_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b,
   real_T c2_c);
static real_T *c2_access_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static real_T c2_get_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_b);
static real_T c2_get_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static void c2_set_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b,
   real_T c2_c);
static real_T *c2_access_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static real_T c2_get_randPoseChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static void c2_set_randPoseChance(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_randPoseChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b);
static real_T c2_get_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static real_T c2_get_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void c2_set_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b);
static void init_dsm_address_info(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_update_debugger_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_lib_affectiveChar_scenario == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_statePoseReady)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateWinSmile)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateNeckBack)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_stateNotWinBored) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_statePosePaper)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_statePoseRock)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateShowHands)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateCompare)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateUserWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateBradWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
      c2_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  uint32_T c2_h_hoistedGlobal;
  uint32_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  uint32_T c2_i_hoistedGlobal;
  uint32_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i0;
  uint32_T c2_j_u[625];
  const mxArray *c2_k_y = NULL;
  int32_T c2_i1;
  uint32_T c2_k_u[2];
  const mxArray *c2_l_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  uint8_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  uint8_T c2_k_hoistedGlobal;
  uint8_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  uint8_T c2_l_hoistedGlobal;
  uint8_T c2_n_u;
  const mxArray *c2_o_y = NULL;
  real_T *c2_bWinT;
  real_T *c2_bradHand;
  real_T *c2_gameState;
  real_T *c2_round;
  real_T *c2_uWinT;
  real_T *c2_userHand;
  real_T *c2_win;
  c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(14, 1), false);
  c2_hoistedGlobal = *c2_bWinT;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_bradHand;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_gameState;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_round;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_uWinT;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_userHand;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_win;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = chartInstance->c2_method;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = chartInstance->c2_state;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  if (!chartInstance->c2_state_not_empty) {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c2_y, 8, c2_j_y);
  for (c2_i0 = 0; c2_i0 < 625; c2_i0++) {
    c2_j_u[c2_i0] = chartInstance->c2_c_state[c2_i0];
  }

  c2_k_y = NULL;
  if (!chartInstance->c2_c_state_not_empty) {
    sf_mex_assign(&c2_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_j_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c2_y, 9, c2_k_y);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    c2_k_u[c2_i1] = chartInstance->c2_b_state[c2_i1];
  }

  c2_l_y = NULL;
  if (!chartInstance->c2_b_state_not_empty) {
    sf_mex_assign(&c2_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_k_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_j_hoistedGlobal = chartInstance->c2_is_active_c2_lib_affectiveChar_scenario;
  c2_l_u = c2_j_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_k_hoistedGlobal = chartInstance->c2_is_c2_lib_affectiveChar_scenario;
  c2_m_u = c2_k_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_l_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_n_u = c2_l_hoistedGlobal;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  uint32_T c2_uv0[625];
  int32_T c2_i2;
  uint32_T c2_uv1[2];
  int32_T c2_i3;
  real_T *c2_bWinT;
  real_T *c2_bradHand;
  real_T *c2_gameState;
  real_T *c2_round;
  real_T *c2_uWinT;
  real_T *c2_userHand;
  real_T *c2_win;
  c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_bWinT = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "bWinT");
  *c2_bradHand = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "bradHand");
  *c2_gameState = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "gameState");
  *c2_round = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "round");
  *c2_uWinT = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "uWinT");
  *c2_userHand = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "userHand");
  *c2_win = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    6)), "win");
  chartInstance->c2_method = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 7)), "method");
  chartInstance->c2_state = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 8)), "state");
  c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 9)),
                        "state", c2_uv0);
  for (c2_i2 = 0; c2_i2 < 625; c2_i2++) {
    chartInstance->c2_c_state[c2_i2] = c2_uv0[c2_i2];
  }

  c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 10)),
                        "state", c2_uv1);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    chartInstance->c2_b_state[c2_i3] = c2_uv1[c2_i3];
  }

  chartInstance->c2_is_active_c2_lib_affectiveChar_scenario =
    c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 11)),
    "is_active_c2_lib_affectiveChar_scenario");
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 12)),
     "is_c2_lib_affectiveChar_scenario");
  chartInstance->c2_temporalCounter_i1 = c2_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_lib_affectiveChar_scenario(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_gameOver) {
      chartInstance->c2_tp_gameOver = 1U;
    } else {
      chartInstance->c2_tp_gameOver = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateBradWin)
    {
      chartInstance->c2_tp_stateBradWin = 1U;
    } else {
      chartInstance->c2_tp_stateBradWin = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateBrowUp)
    {
      chartInstance->c2_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c2_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateCompare)
    {
      chartInstance->c2_tp_stateCompare = 1U;
    } else {
      chartInstance->c2_tp_stateCompare = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateGo) {
      chartInstance->c2_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateGo = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateHeadNeutral2) {
      chartInstance->c2_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateNeckBack) {
      chartInstance->c2_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateNoWin)
    {
      chartInstance->c2_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateNoWin = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateNotWinBored) {
      chartInstance->c2_tp_stateNotWinBored = 1U;
    } else {
      chartInstance->c2_tp_stateNotWinBored = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePoseFingersCLose) {
      chartInstance->c2_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c2_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePosePaper) {
      chartInstance->c2_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_statePosePaper = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePoseReady) {
      chartInstance->c2_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_statePoseReady = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePoseReturnFinger) {
      chartInstance->c2_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c2_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePoseRock) {
      chartInstance->c2_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_statePoseRock = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_statePoseScissors) {
      chartInstance->c2_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateRandomHand) {
      chartInstance->c2_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c2_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateReadUserHand) {
      chartInstance->c2_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c2_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateReady)
    {
      chartInstance->c2_tp_stateReady = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateReady = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateShowHands) {
      chartInstance->c2_tp_stateShowHands = 1U;
    } else {
      chartInstance->c2_tp_stateShowHands = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateShowResult) {
      chartInstance->c2_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateShowResult = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateStart)
    {
      chartInstance->c2_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateStart = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario == c2_IN_stateUserWin)
    {
      chartInstance->c2_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 23) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateUserWin = 0U;
    }

    if (chartInstance->c2_is_c2_lib_affectiveChar_scenario ==
        c2_IN_stateWinSmile) {
      chartInstance->c2_tp_stateWinSmile = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 24) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_stateWinSmile = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  c2_set_sim_state_side_effects_c2_lib_affectiveChar_scenario(chartInstance);
}

static void c2_enter_atomic_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_active_c2_lib_affectiveChar_scenario = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_enter_internal_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_dv0[256];
  int32_T c2_i4;
  real_T c2_arg[256];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T *c2_round;
  real_T *c2_userHand;
  real_T *c2_bradHand;
  real_T *c2_win;
  real_T *c2_gameState;
  real_T *c2_uWinT;
  real_T *c2_bWinT;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = false;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateStart = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_hb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  *c2_round = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_round, 21U);
  c2_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c2_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c2_set_randSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  *c2_userHand = 3.0;
  c2_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_userHand, 3U);
  *c2_bradHand = 3.0;
  c2_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_bradHand, 2U);
  *c2_win = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_win, 4U);
  c2_set_BOREDOM_THRESHOLD(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  *c2_gameState = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
  c2_set_randPoseChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c2_set_randAvertGazeChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  *c2_uWinT = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_uWinT, 10U);
  *c2_bWinT = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_bWinT, 9U);
  c2_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c2_set_boredom(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c2_initialPoseTablec2_lib_affectiveChar_scenario(chartInstance, 1.0, c2_dv0);
  for (c2_i4 = 0; c2_i4 < 256; c2_i4++) {
    c2_arg[c2_i4] = c2_dv0[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 256; c2_i5++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i5], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  for (c2_i6 = 0; c2_i6 < 256; c2_i6++) {
    (*c2_b_arg)[c2_i6] = c2_arg[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 256; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i7], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 0.0;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 0.0;
  real_T c2_f_nargin = 0.0;
  real_T c2_f_nargout = 1.0;
  boolean_T c2_c_out;
  real_T c2_g_nargin = 0.0;
  real_T c2_g_nargout = 1.0;
  boolean_T c2_d_out;
  real_T c2_h_nargin = 0.0;
  real_T c2_h_nargout = 1.0;
  boolean_T c2_e_out;
  real_T c2_i_nargin = 0.0;
  real_T c2_i_nargout = 0.0;
  real_T c2_j_nargin = 0.0;
  real_T c2_j_nargout = 1.0;
  boolean_T c2_f_out;
  real_T c2_k_nargin = 0.0;
  real_T c2_k_nargout = 0.0;
  real_T c2_dv1[256];
  int32_T c2_i8;
  real_T c2_arg[256];
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T *c2_gameState;
  real_T *c2_round;
  real_T *c2_inputUser;
  real_T (*c2_b_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_isStable = true;
  switch (chartInstance->c2_is_c2_lib_affectiveChar_scenario) {
   case c2_IN_gameOver:
    CV_CHART_EVAL(0, 0, 1);
    c2_gameOver(chartInstance);
    break;

   case c2_IN_stateBradWin:
    CV_CHART_EVAL(0, 0, 2);
    c2_stateBradWin(chartInstance);
    break;

   case c2_IN_stateBrowUp:
    CV_CHART_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateCompare:
    CV_CHART_EVAL(0, 0, 4);
    c2_stateCompare(chartInstance);
    break;

   case c2_IN_stateGo:
    CV_CHART_EVAL(0, 0, 5);
    c2_stateGo(chartInstance);
    break;

   case c2_IN_stateHeadNeutral2:
    CV_CHART_EVAL(0, 0, 6);
    c2_stateHeadNeutral2(chartInstance);
    break;

   case c2_IN_stateNeckBack:
    CV_CHART_EVAL(0, 0, 7);
    c2_stateNeckBack(chartInstance);
    break;

   case c2_IN_stateNoWin:
    CV_CHART_EVAL(0, 0, 8);
    c2_stateNoWin(chartInstance);
    break;

   case c2_IN_stateNotWinBored:
    CV_CHART_EVAL(0, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseFingersCLose:
    CV_CHART_EVAL(0, 0, 10);
    c2_statePoseFingersCLose(chartInstance);
    break;

   case c2_IN_statePosePaper:
    CV_CHART_EVAL(0, 0, 11);
    c2_statePosePaper(chartInstance);
    break;

   case c2_IN_statePoseReady:
    CV_CHART_EVAL(0, 0, 12);
    c2_statePoseReady(chartInstance);
    break;

   case c2_IN_statePoseReturnFinger:
    CV_CHART_EVAL(0, 0, 13);
    c2_statePoseReturnFinger(chartInstance);
    break;

   case c2_IN_statePoseRock:
    CV_CHART_EVAL(0, 0, 14);
    c2_statePoseRock(chartInstance);
    break;

   case c2_IN_statePoseScissors:
    CV_CHART_EVAL(0, 0, 15);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_xc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(23, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                    (chartInstance->c2_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(23, 0, 1, c2_get_uHand(chartInstance, 0) != 3.0)) {
        CV_EML_MCDC(23, 0, 0, true);
        CV_EML_IF(23, 0, 0, true);
        c2_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(23, 0, 0, false);
      CV_EML_IF(23, 0, 0, false);
      c2_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c2_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_statePoseScissors = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario =
        c2_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateReadUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_wb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c2_set_uHand(chartInstance, 0, *c2_inputUser);
      ssUpdateDataStoreLog(chartInstance->S, 14);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateRandomHand:
    CV_CHART_EVAL(0, 0, 16);
    c2_stateRandomHand(chartInstance);
    break;

   case c2_IN_stateReadUserHand:
    CV_CHART_EVAL(0, 0, 17);
    c2_stateReadUserHand(chartInstance);
    break;

   case c2_IN_stateReady:
    CV_CHART_EVAL(0, 0, 18);
    c2_stateReady(chartInstance);
    break;

   case c2_IN_stateShowHands:
    CV_CHART_EVAL(0, 0, 19);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateShowHands = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateCompare;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateCompare = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ac_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_set_temp(chartInstance, 0, c2_get_uHand(chartInstance, 0) - c2_get_bHand
                (chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 13);
    c2_hoistedGlobal = c2_get_temp(chartInstance, 0);
    c2_b_hoistedGlobal = c2_get_temp(chartInstance, 0);
    c2_A = c2_b_hoistedGlobal;
    c2_x = c2_A;
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    c2_y = c2_c_x / 3.0;
    c2_d_x = c2_y;
    c2_e_x = c2_d_x;
    c2_e_x = muDoubleScalarFloor(c2_e_x);
    c2_set_diff(chartInstance, 0, c2_hoistedGlobal - 3.0 * c2_e_x);
    ssUpdateDataStoreLog(chartInstance->S, 4);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateShowResult:
    CV_CHART_EVAL(0, 0, 20);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_lc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                    (chartInstance->c2_temporalCounter_i1 >= 3))) {
      if (CV_EML_COND(5, 0, 1, *c2_round == 10.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c2_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c2_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c2_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_jb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      *c2_gameState = 3.0;
      c2_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
      c2_set_boredom(chartInstance, 0, c2_get_boredom(chartInstance, 0) - 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_jc_debug_family_names,
        c2_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_c_sf_marshallOut,
        c2_c_sf_marshallIn);
      c2_c_out = CV_EML_IF(3, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs)
                           && (chartInstance->c2_temporalCounter_i1 >= 3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
        chartInstance->c2_isStable = false;
        chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_stateReady = 1U;
        c2_enter_atomic_stateReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                     chartInstance->c2_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateStart:
    CV_CHART_EVAL(0, 0, 21);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_fc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_g_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_d_out = CV_EML_IF(1, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                         (chartInstance->c2_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateReady = 1U;
      c2_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateUserWin:
    CV_CHART_EVAL(0, 0, 22);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_fd_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_h_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_e_out = CV_EML_IF(33, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                         (chartInstance->c2_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ec_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateWinSmile:
    CV_CHART_EVAL(0, 0, 23);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_pc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_j_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_j_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_f_out = CV_EML_IF(14, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                         (chartInstance->c2_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateWinSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateNeckBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateNeckBack = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ob_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_successTablec2_lib_affectiveChar_scenario(chartInstance, 2.0, c2_dv1);
      for (c2_i8 = 0; c2_i8 < 256; c2_i8++) {
        c2_arg[c2_i8] = c2_dv1[c2_i8];
      }

      for (c2_i9 = 0; c2_i9 < 256; c2_i9++) {
        _SFD_DATA_RANGE_CHECK(c2_arg[c2_i9], 25U);
      }

      _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
      for (c2_i10 = 0; c2_i10 < 256; c2_i10++) {
        (*c2_b_arg)[c2_i10] = c2_arg[c2_i10];
      }

      for (c2_i11 = 0; c2_i11 < 256; c2_i11++) {
        _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i11], 25U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(25U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_exit_internal_c2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_c2_lib_affectiveChar_scenario) {
   case c2_IN_gameOver:
    CV_CHART_EVAL(0, 0, 1);
    chartInstance->c2_tp_gameOver = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateBradWin:
    CV_CHART_EVAL(0, 0, 2);
    chartInstance->c2_tp_stateBradWin = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateBrowUp:
    CV_CHART_EVAL(0, 0, 3);
    chartInstance->c2_tp_stateBrowUp = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateCompare:
    CV_CHART_EVAL(0, 0, 4);
    chartInstance->c2_tp_stateCompare = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateGo:
    CV_CHART_EVAL(0, 0, 5);
    chartInstance->c2_tp_stateGo = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateHeadNeutral2:
    CV_CHART_EVAL(0, 0, 6);
    chartInstance->c2_tp_stateHeadNeutral2 = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateNeckBack:
    CV_CHART_EVAL(0, 0, 7);
    chartInstance->c2_tp_stateNeckBack = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateNoWin:
    CV_CHART_EVAL(0, 0, 8);
    chartInstance->c2_tp_stateNoWin = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateNotWinBored:
    CV_CHART_EVAL(0, 0, 9);
    chartInstance->c2_tp_stateNotWinBored = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseFingersCLose:
    CV_CHART_EVAL(0, 0, 10);
    chartInstance->c2_tp_statePoseFingersCLose = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePosePaper:
    CV_CHART_EVAL(0, 0, 11);
    chartInstance->c2_tp_statePosePaper = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseReady:
    CV_CHART_EVAL(0, 0, 12);
    chartInstance->c2_tp_statePoseReady = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseReturnFinger:
    CV_CHART_EVAL(0, 0, 13);
    chartInstance->c2_tp_statePoseReturnFinger = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseRock:
    CV_CHART_EVAL(0, 0, 14);
    chartInstance->c2_tp_statePoseRock = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_statePoseScissors:
    CV_CHART_EVAL(0, 0, 15);
    chartInstance->c2_tp_statePoseScissors = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateRandomHand:
    CV_CHART_EVAL(0, 0, 16);
    chartInstance->c2_tp_stateRandomHand = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateReadUserHand:
    CV_CHART_EVAL(0, 0, 17);
    chartInstance->c2_tp_stateReadUserHand = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateReady:
    CV_CHART_EVAL(0, 0, 18);
    chartInstance->c2_tp_stateReady = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateShowHands:
    CV_CHART_EVAL(0, 0, 19);
    chartInstance->c2_tp_stateShowHands = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateShowResult:
    CV_CHART_EVAL(0, 0, 20);
    chartInstance->c2_tp_stateShowResult = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateStart:
    CV_CHART_EVAL(0, 0, 21);
    chartInstance->c2_tp_stateStart = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateUserWin:
    CV_CHART_EVAL(0, 0, 22);
    chartInstance->c2_tp_stateUserWin = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_stateWinSmile:
    CV_CHART_EVAL(0, 0, 23);
    chartInstance->c2_tp_stateWinSmile = 0U;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_initc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_method_not_empty = false;
  chartInstance->c2_state_not_empty = false;
  chartInstance->c2_b_state_not_empty = false;
  chartInstance->c2_c_state_not_empty = false;
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_gameOver = 0U;
  chartInstance->c2_tp_stateBradWin = 0U;
  chartInstance->c2_tp_stateBrowUp = 0U;
  chartInstance->c2_tp_stateCompare = 0U;
  chartInstance->c2_tp_stateGo = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateHeadNeutral2 = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateNeckBack = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateNoWin = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateNotWinBored = 0U;
  chartInstance->c2_tp_statePoseFingersCLose = 0U;
  chartInstance->c2_tp_statePosePaper = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_statePoseReady = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_statePoseReturnFinger = 0U;
  chartInstance->c2_tp_statePoseRock = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_statePoseScissors = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateRandomHand = 0U;
  chartInstance->c2_tp_stateReadUserHand = 0U;
  chartInstance->c2_tp_stateReady = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateShowHands = 0U;
  chartInstance->c2_tp_stateShowResult = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateStart = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateUserWin = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateWinSmile = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_active_c2_lib_affectiveChar_scenario = 0U;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_enter_atomic_stateReady
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T *c2_round;
  real_T *c2_bradHand;
  real_T *c2_userHand;
  real_T *c2_gameState;
  real_T *c2_win;
  c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ib_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
  (*c2_round)++;
  c2_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_round, 21U);
  *c2_bradHand = 3.0;
  c2_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_bradHand, 2U);
  *c2_userHand = 3.0;
  c2_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_userHand, 3U);
  *c2_gameState = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
  *c2_win = 0.0;
  c2_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_win, 4U);
  c2_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_stateReady(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 1.0;
  boolean_T c2_c_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_hc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(6, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                  (chartInstance->c2_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(6, 0, 1, c2_get_boredom(chartInstance, 0) <
                    c2_get_BOREDOM_THRESHOLD(chartInstance, 0) - 4.0)) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c2_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(6, 0, 0, false);
    CV_EML_IF(6, 0, 0, false);
    c2_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ic_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_boredom(chartInstance, 0, c2_get_boredom(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c2_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_statePoseReady = 1U;
    c2_enter_atomic_statePoseReady(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_gc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_b_out = CV_EML_IF(2, 0, 0, c2_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateReady = 1U;
      c2_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_kc_debug_family_names,
        c2_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_c_sf_marshallOut,
        c2_c_sf_marshallIn);
      c2_c_out = CV_EML_IF(7, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs)
                           && (chartInstance->c2_temporalCounter_i1 >= 1));
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_stateReady = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
        chartInstance->c2_isStable = false;
        chartInstance->c2_is_c2_lib_affectiveChar_scenario =
          c2_IN_statePoseReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_statePoseReady = 1U;
        c2_enter_atomic_statePoseReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                     chartInstance->c2_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c2_sfEvent);
}

static void c2_gameOver(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_dv2[256];
  int32_T c2_i12;
  real_T c2_arg[256];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_gameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = false;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateHeadNeutral2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateHeadNeutral2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_lb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_initialPoseTablec2_lib_affectiveChar_scenario(chartInstance, 2.0, c2_dv2);
  for (c2_i12 = 0; c2_i12 < 256; c2_i12++) {
    c2_arg[c2_i12] = c2_dv2[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 256; c2_i13++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i13], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  for (c2_i14 = 0; c2_i14 < 256; c2_i14++) {
    (*c2_b_arg)[c2_i14] = c2_arg[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 256; c2_i15++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i15], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void c2_enter_atomic_statePoseReady
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_dv3[256];
  int32_T c2_i16;
  real_T c2_arg[256];
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  real_T c2_dv4[256];
  int32_T c2_i20;
  real_T c2_b_arg[256];
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  real_T (*c2_c_arg)[256];
  real_T (*c2_d_arg)[256];
  c2_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c2_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_kb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_initialPoseTablec2_lib_affectiveChar_scenario(chartInstance, 2.0, c2_dv3);
  for (c2_i16 = 0; c2_i16 < 256; c2_i16++) {
    c2_arg[c2_i16] = c2_dv3[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 256; c2_i17++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i17], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  for (c2_i18 = 0; c2_i18 < 256; c2_i18++) {
    (*c2_d_arg)[c2_i18] = c2_arg[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 256; c2_i19++) {
    _SFD_DATA_RANGE_CHECK((*c2_d_arg)[c2_i19], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  c2_handPoseSBTablec2_lib_affectiveChar_scenario(chartInstance, 2.0, c2_dv4);
  for (c2_i20 = 0; c2_i20 < 256; c2_i20++) {
    c2_b_arg[c2_i20] = c2_dv4[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 256; c2_i21++) {
    _SFD_DATA_RANGE_CHECK(c2_b_arg[c2_i21], 24U);
  }

  _SFD_SET_DATA_VALUE_PTR(24U, c2_b_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_b_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
  for (c2_i22 = 0; c2_i22 < 256; c2_i22++) {
    (*c2_c_arg)[c2_i22] = c2_b_arg[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 256; c2_i23++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_arg)[c2_i23], 24U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(24U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
  c2_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_statePoseReady(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T *c2_gameState;
  boolean_T guard1 = false;
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_nc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(8, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                  (chartInstance->c2_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(8, 0, 1, c2_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(8, 0, 0, true);
      CV_EML_IF(8, 0, 0, true);
      c2_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(8, 0, 0, false);
    CV_EML_IF(8, 0, 0, false);
    c2_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_stateGo = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_mb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c2_gameState = 1.0;
    c2_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c2_sfEvent);
}

static void c2_stateHeadNeutral2(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 1.0;
  boolean_T c2_b_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 0.0;
  real_T c2_dv5[256];
  int32_T c2_i24;
  real_T c2_arg[256];
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_r;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_dv6[256];
  int32_T c2_i28;
  real_T c2_b_arg[256];
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  real_T *c2_uWinT;
  real_T *c2_bWinT;
  real_T (*c2_c_arg)[256];
  c2_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_mc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(10, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                     (chartInstance->c2_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_oc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
    c2_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    c2_b_out = CV_EML_IF(12, 0, 0, *c2_uWinT < *c2_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateWinSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateWinSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_nb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_successTablec2_lib_affectiveChar_scenario(chartInstance, 1.0, c2_dv5);
      for (c2_i24 = 0; c2_i24 < 256; c2_i24++) {
        c2_arg[c2_i24] = c2_dv5[c2_i24];
      }

      for (c2_i25 = 0; c2_i25 < 256; c2_i25++) {
        _SFD_DATA_RANGE_CHECK(c2_arg[c2_i25], 25U);
      }

      _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
      for (c2_i26 = 0; c2_i26 < 256; c2_i26++) {
        (*c2_c_arg)[c2_i26] = c2_arg[c2_i26];
      }

      for (c2_i27 = 0; c2_i27 < 256; c2_i27++) {
        _SFD_DATA_RANGE_CHECK((*c2_c_arg)[c2_i27], 25U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(25U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario =
        c2_IN_stateNotWinBored;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateNotWinBored = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_sb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_r = c2_rand(chartInstance);
      c2_x = c2_r * 18.0;
      c2_b_x = c2_x;
      c2_b_x = muDoubleScalarFloor(c2_b_x);
      c2_r = 1.0 + c2_b_x;
      c2_idlePoseBradTablec2_lib_affectiveChar_scenario(chartInstance, c2_r,
        c2_dv6);
      for (c2_i28 = 0; c2_i28 < 256; c2_i28++) {
        c2_b_arg[c2_i28] = c2_dv6[c2_i28];
      }

      for (c2_i29 = 0; c2_i29 < 256; c2_i29++) {
        _SFD_DATA_RANGE_CHECK(c2_b_arg[c2_i29], 25U);
      }

      _SFD_SET_DATA_VALUE_PTR(25U, c2_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_b_arg, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
      for (c2_i30 = 0; c2_i30 < 256; c2_i30++) {
        (*c2_c_arg)[c2_i30] = c2_b_arg[c2_i30];
      }

      for (c2_i31 = 0; c2_i31 < 256; c2_i31++) {
        _SFD_DATA_RANGE_CHECK((*c2_c_arg)[c2_i31], 25U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(25U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c2_sfEvent);
}

static void c2_stateGo(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_r;
  real_T c2_x;
  real_T c2_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_qc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(13, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                     (chartInstance->c2_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateRandomHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateRandomHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_pb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_r = c2_rand(chartInstance);
    c2_x = c2_r * 3.0;
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    c2_r = c2_b_x;
    c2_set_bHand(chartInstance, 0, c2_r);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
}

static void c2_stateNeckBack(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_dv7[256];
  int32_T c2_i32;
  real_T c2_arg[256];
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_rc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(15, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                     (chartInstance->c2_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateNeckBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_qb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_successTablec2_lib_affectiveChar_scenario(chartInstance, 3.0, c2_dv7);
    for (c2_i32 = 0; c2_i32 < 256; c2_i32++) {
      c2_arg[c2_i32] = c2_dv7[c2_i32];
    }

    for (c2_i33 = 0; c2_i33 < 256; c2_i33++) {
      _SFD_DATA_RANGE_CHECK(c2_arg[c2_i33], 25U);
    }

    _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    for (c2_i34 = 0; c2_i34 < 256; c2_i34++) {
      (*c2_b_arg)[c2_i34] = c2_arg[c2_i34];
    }

    for (c2_i35 = 0; c2_i35 < 256; c2_i35++) {
      _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i35], 25U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(25U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c2_sfEvent);
}

static void c2_stateRandomHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_hoistedGlobal;
  real_T c2_dv8[256];
  int32_T c2_i36;
  real_T c2_arg[256];
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_b_hoistedGlobal;
  real_T c2_dv9[256];
  int32_T c2_i40;
  real_T c2_b_arg[256];
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 1.0;
  boolean_T c2_c_out;
  real_T c2_f_nargin = 0.0;
  real_T c2_f_nargout = 0.0;
  real_T c2_dv10[256];
  int32_T c2_i44;
  real_T c2_c_arg[256];
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  real_T (*c2_d_arg)[256];
  real_T (*c2_e_arg)[256];
  c2_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c2_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_uc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(19, 0, 0, c2_get_bHand(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_tb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_set_p(chartInstance, 0, c2_randi(chartInstance));
    ssUpdateDataStoreLog(chartInstance->S, 6);
    c2_hoistedGlobal = c2_get_p(chartInstance, 0);
    c2_paperPoseBradTablec2_lib_affectiveChar_scenario(chartInstance,
      c2_hoistedGlobal, c2_dv8);
    for (c2_i36 = 0; c2_i36 < 256; c2_i36++) {
      c2_arg[c2_i36] = c2_dv8[c2_i36];
    }

    for (c2_i37 = 0; c2_i37 < 256; c2_i37++) {
      _SFD_DATA_RANGE_CHECK(c2_arg[c2_i37], 25U);
    }

    _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
      c2_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    for (c2_i38 = 0; c2_i38 < 256; c2_i38++) {
      (*c2_e_arg)[c2_i38] = c2_arg[c2_i38];
    }

    for (c2_i39 = 0; c2_i39 < 256; c2_i39++) {
      _SFD_DATA_RANGE_CHECK((*c2_e_arg)[c2_i39], 25U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(25U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_tc_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_b_out = CV_EML_IF(18, 0, 0, c2_get_bHand(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ub_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c2_set_r(chartInstance, 0, c2_randi(chartInstance));
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c2_b_hoistedGlobal = c2_get_r(chartInstance, 0);
      c2_rockPoseTablec2_lib_affectiveChar_scenario(chartInstance,
        c2_b_hoistedGlobal, c2_dv9);
      for (c2_i40 = 0; c2_i40 < 256; c2_i40++) {
        c2_b_arg[c2_i40] = c2_dv9[c2_i40];
      }

      for (c2_i41 = 0; c2_i41 < 256; c2_i41++) {
        _SFD_DATA_RANGE_CHECK(c2_b_arg[c2_i41], 25U);
      }

      _SFD_SET_DATA_VALUE_PTR(25U, c2_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_b_arg, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
      for (c2_i42 = 0; c2_i42 < 256; c2_i42++) {
        (*c2_e_arg)[c2_i42] = c2_b_arg[c2_i42];
      }

      for (c2_i43 = 0; c2_i43 < 256; c2_i43++) {
        _SFD_DATA_RANGE_CHECK((*c2_e_arg)[c2_i43], 25U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(25U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_sc_debug_family_names,
        c2_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_c_sf_marshallOut,
        c2_c_sf_marshallIn);
      c2_c_out = CV_EML_IF(17, 0, 0, c2_get_bHand(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
        chartInstance->c2_isStable = false;
        chartInstance->c2_is_c2_lib_affectiveChar_scenario =
          c2_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_rb_debug_family_names,
          c2_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        c2_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        c2_handPoseSBTablec2_lib_affectiveChar_scenario(chartInstance, 1.0,
          c2_dv10);
        for (c2_i44 = 0; c2_i44 < 256; c2_i44++) {
          c2_c_arg[c2_i44] = c2_dv10[c2_i44];
        }

        for (c2_i45 = 0; c2_i45 < 256; c2_i45++) {
          _SFD_DATA_RANGE_CHECK(c2_c_arg[c2_i45], 24U);
        }

        _SFD_SET_DATA_VALUE_PTR(24U, c2_c_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_c_arg, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c2_sfEvent);
        for (c2_i46 = 0; c2_i46 < 256; c2_i46++) {
          (*c2_d_arg)[c2_i46] = c2_c_arg[c2_i46];
        }

        for (c2_i47 = 0; c2_i47 < 256; c2_i47++) {
          _SFD_DATA_RANGE_CHECK((*c2_d_arg)[c2_i47], 24U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(24U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                     chartInstance->c2_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c2_sfEvent);
}

static void c2_statePoseFingersCLose
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_hoistedGlobal;
  real_T c2_dv11[256];
  int32_T c2_i48;
  real_T c2_arg[256];
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = false;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_vb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c2_set_s(chartInstance, 0, c2_randi(chartInstance));
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c2_hoistedGlobal = c2_get_s(chartInstance, 0);
  c2_scissorsPoseBradTablec2_lib_affectiveChar_scenario(chartInstance,
    c2_hoistedGlobal, c2_dv11);
  for (c2_i48 = 0; c2_i48 < 256; c2_i48++) {
    c2_arg[c2_i48] = c2_dv11[c2_i48];
  }

  for (c2_i49 = 0; c2_i49 < 256; c2_i49++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i49], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  for (c2_i50 = 0; c2_i50 < 256; c2_i50++) {
    (*c2_b_arg)[c2_i50] = c2_arg[c2_i50];
  }

  for (c2_i51 = 0; c2_i51 < 256; c2_i51++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i51], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c2_sfEvent);
}

static void c2_statePosePaper(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T *c2_inputUser;
  boolean_T guard1 = false;
  c2_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_wc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(21, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                  (chartInstance->c2_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(21, 0, 1, c2_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(21, 0, 0, true);
      CV_EML_IF(21, 0, 0, true);
      c2_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(21, 0, 0, false);
    CV_EML_IF(21, 0, 0, false);
    c2_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_wb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_set_uHand(chartInstance, 0, *c2_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 14);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c2_sfEvent);
}

static void c2_statePoseRock(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T *c2_inputUser;
  boolean_T guard1 = false;
  c2_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_vc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(20, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                  (chartInstance->c2_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(20, 0, 1, c2_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(20, 0, 0, true);
      CV_EML_IF(20, 0, 0, true);
      c2_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(20, 0, 0, false);
    CV_EML_IF(20, 0, 0, false);
    c2_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_wb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_set_uHand(chartInstance, 0, *c2_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 14);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c2_sfEvent);
}

static void c2_stateReadUserHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_dv12[256];
  int32_T c2_i52;
  real_T c2_arg[256];
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 0.0;
  real_T *c2_gameState;
  real_T *c2_bradHand;
  real_T *c2_userHand;
  real_T *c2_inputUser;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_yc_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(22, 0, 0, c2_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_wb_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c2_set_uHand(chartInstance, 0, *c2_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 14);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_ad_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_b_out = CV_EML_IF(25, 0, 0, c2_get_bHand(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario =
        c2_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_yb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c2_handPoseSBTablec2_lib_affectiveChar_scenario(chartInstance, 2.0,
        c2_dv12);
      for (c2_i52 = 0; c2_i52 < 256; c2_i52++) {
        c2_arg[c2_i52] = c2_dv12[c2_i52];
      }

      for (c2_i53 = 0; c2_i53 < 256; c2_i53++) {
        _SFD_DATA_RANGE_CHECK(c2_arg[c2_i53], 24U);
      }

      _SFD_SET_DATA_VALUE_PTR(24U, c2_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c2_sfEvent);
      for (c2_i54 = 0; c2_i54 < 256; c2_i54++) {
        (*c2_b_arg)[c2_i54] = c2_arg[c2_i54];
      }

      for (c2_i55 = 0; c2_i55 < 256; c2_i55++) {
        _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i55], 24U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(24U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateShowHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateShowHands = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_xb_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c2_gameState = 2.0;
      c2_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
      *c2_bradHand = c2_get_bHand(chartInstance, 0);
      c2_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(*c2_bradHand, 2U);
      *c2_userHand = c2_get_uHand(chartInstance, 0);
      c2_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(*c2_userHand, 3U);
      _SFD_SYMBOL_SCOPE_POP();
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c2_sfEvent);
}

static void c2_statePoseReturnFinger
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T *c2_gameState;
  real_T *c2_bradHand;
  real_T *c2_userHand;
  c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_statePoseReturnFinger = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = false;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateShowHands;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_stateShowHands = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_xb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c2_gameState = 2.0;
  c2_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_gameState, 0U);
  *c2_bradHand = c2_get_bHand(chartInstance, 0);
  c2_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_bradHand, 2U);
  *c2_userHand = c2_get_uHand(chartInstance, 0);
  c2_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_userHand, 3U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c2_sfEvent);
}

static void c2_stateCompare(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_e_nargin = 0.0;
  real_T c2_e_nargout = 1.0;
  boolean_T c2_c_out;
  real_T c2_f_nargin = 0.0;
  real_T c2_f_nargout = 0.0;
  real_T *c2_win;
  real_T *c2_uWinT;
  real_T *c2_bWinT;
  boolean_T guard1 = false;
  c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_cd_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(29, 0, 0, c2_get_diff(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_cc_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c2_win = 2.0;
    c2_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c2_win, 4U);
    c2_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    (*c2_bWinT)++;
    c2_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c2_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c2_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_bd_debug_family_names,
      c2_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_c_sf_marshallOut,
      c2_c_sf_marshallIn);
    c2_b_out = CV_EML_IF(28, 0, 0, c2_get_diff(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c2_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      chartInstance->c2_isStable = false;
      chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
      chartInstance->c2_temporalCounter_i1 = 0U;
      chartInstance->c2_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_bc_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      c2_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c2_win = 1.0;
      c2_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c2_win, 4U);
      c2_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      (*c2_uWinT)++;
      c2_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c2_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_dd_debug_family_names,
        c2_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_out, 2U, c2_c_sf_marshallOut,
        c2_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(30, 0, 0, c2_get_diff(chartInstance, 0) != 1.0)) {
        if (CV_EML_COND(30, 0, 1, c2_get_diff(chartInstance, 0) != 2.0)) {
          CV_EML_MCDC(30, 0, 0, true);
          CV_EML_IF(30, 0, 0, true);
          c2_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(30, 0, 0, false);
        CV_EML_IF(30, 0, 0, false);
        c2_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c2_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
        chartInstance->c2_isStable = false;
        chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_dc_debug_family_names,
          c2_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargin, 0U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_nargout, 1U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        *c2_win = 0.0;
        c2_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c2_win, 4U);
        c2_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                     chartInstance->c2_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
}

static void c2_stateBradWin(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_stateBradWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  chartInstance->c2_isStable = false;
  chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateShowResult;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_stateShowResult = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ec_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  c2_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
}

static void c2_stateNoWin(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_out;
  uint32_T c2_b_debug_family_var_map[2];
  real_T c2_b_nargin = 0.0;
  real_T c2_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_ed_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_out = CV_EML_IF(32, 0, 0, (chartInstance->c2_sfEvent == c2_event_secs) &&
                     (chartInstance->c2_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    chartInstance->c2_isStable = false;
    chartInstance->c2_is_c2_lib_affectiveChar_scenario = c2_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_ec_debug_family_names,
      c2_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_b_sf_marshallOut,
      c2_b_sf_marshallIn);
    c2_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c2_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c2_sfEvent);
}

static void c2_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[94];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[94];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i56;
  static char_T c2_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i57;
  static real_T c2_dv13[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i56 = 0; c2_i56 < 94; c2_i56++) {
    c2_mystr[c2_i56] = c2_cv0[c2_i56];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i57 = 0; c2_i57 < 94; c2_i57++) {
    c2_arr[c2_i57] = c2_dv13[c2_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i58 = 0; c2_i58 < 256; c2_i58++) {
    c2_tt[c2_i58] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i59 = 0; c2_i59 < 94; c2_i59++) {
    c2_tt[c2_i59] = c2_arr[c2_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i60 = 0; c2_i60 < 256; c2_i60++) {
    c2_myarr256[c2_i60] = c2_tt[c2_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_b_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[88];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[88];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i61;
  static char_T c2_cv1[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c2_i62;
  static real_T c2_dv14[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i61 = 0; c2_i61 < 88; c2_i61++) {
    c2_mystr[c2_i61] = c2_cv1[c2_i61];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i62 = 0; c2_i62 < 88; c2_i62++) {
    c2_arr[c2_i62] = c2_dv14[c2_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i63 = 0; c2_i63 < 256; c2_i63++) {
    c2_tt[c2_i63] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i64 = 0; c2_i64 < 88; c2_i64++) {
    c2_tt[c2_i64] = c2_arr[c2_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i65 = 0; c2_i65 < 256; c2_i65++) {
    c2_myarr256[c2_i65] = c2_tt[c2_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_c_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[86];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[86];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i66;
  static char_T c2_cv2[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c2_i67;
  static real_T c2_dv15[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_f_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i66 = 0; c2_i66 < 86; c2_i66++) {
    c2_mystr[c2_i66] = c2_cv2[c2_i66];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i67 = 0; c2_i67 < 86; c2_i67++) {
    c2_arr[c2_i67] = c2_dv15[c2_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i68 = 0; c2_i68 < 256; c2_i68++) {
    c2_tt[c2_i68] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i69 = 0; c2_i69 < 86; c2_i69++) {
    c2_tt[c2_i69] = c2_arr[c2_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i70 = 0; c2_i70 < 256; c2_i70++) {
    c2_myarr256[c2_i70] = c2_tt[c2_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_d_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[161];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[161];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i71;
  static char_T c2_cv3[161] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p', 'i', 'n',
    'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1',
    ',', '0', ',', '0', ',', '0', '.', '5', ')', ')', ';', ' ', 'b', 'r', 'a',
    'd', '.', 'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')',
    '.', 'g', 'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e',
    '(', '\"', 'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')', '.', 's', 'e', 't',
    'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r',
    'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',', '0', '.', '5', ')',
    ')' };

  int32_T c2_i72;
  static real_T c2_dv16[161] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0, 110.0,
    107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 53.0, 41.0, 41.0, 59.0, 32.0, 98.0, 114.0, 97.0, 100.0,
    46.0, 103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0,
    110.0, 40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0,
    116.0, 66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 114.0,
    105.0, 110.0, 103.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0,
    111.0, 115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    40.0, 83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0,
    48.0, 44.0, 48.0, 46.0, 53.0, 41.0, 41.0 };

  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_i_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i71 = 0; c2_i71 < 161; c2_i71++) {
    c2_mystr[c2_i71] = c2_cv3[c2_i71];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i72 = 0; c2_i72 < 161; c2_i72++) {
    c2_arr[c2_i72] = c2_dv16[c2_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i73 = 0; c2_i73 < 256; c2_i73++) {
    c2_tt[c2_i73] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i74 = 0; c2_i74 < 161; c2_i74++) {
    c2_tt[c2_i74] = c2_arr[c2_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i75 = 0; c2_i75 < 256; c2_i75++) {
    c2_myarr256[c2_i75] = c2_tt[c2_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_e_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[157];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[157];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i76;
  static char_T c2_cv4[157] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p', 'i', 'n',
    'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1',
    ',', '0', ',', '0', ',', '0', ')', ')', ';', ' ', 'b', 'r', 'a', 'd', '.',
    'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g',
    'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"',
    'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o',
    's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u',
    'a', 't', '(', '1', ',', '0', ',', '0', ',', '0', ')', ')' };

  int32_T c2_i77;
  static real_T c2_dv17[157] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0, 110.0,
    107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0, 59.0, 32.0, 98.0, 114.0, 97.0, 100.0, 46.0, 103.0,
    101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0,
    41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0,
    121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 114.0, 105.0,
    110.0, 103.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0 };

  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_j_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i76 = 0; c2_i76 < 157; c2_i76++) {
    c2_mystr[c2_i76] = c2_cv4[c2_i76];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i77 = 0; c2_i77 < 157; c2_i77++) {
    c2_arr[c2_i77] = c2_dv17[c2_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 157.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i78 = 0; c2_i78 < 256; c2_i78++) {
    c2_tt[c2_i78] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i79 = 0; c2_i79 < 157; c2_i79++) {
    c2_tt[c2_i79] = c2_arr[c2_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i80 = 0; c2_i80 < 256; c2_i80++) {
    c2_myarr256[c2_i80] = c2_tt[c2_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_f_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[91];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[91];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i81;
  static char_T c2_cv5[91] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '0', '5', ')', ')' };

  int32_T c2_i82;
  static real_T c2_dv18[91] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 46.0, 48.0, 53.0, 41.0, 41.0 };

  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_k_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i81 = 0; c2_i81 < 91; c2_i81++) {
    c2_mystr[c2_i81] = c2_cv5[c2_i81];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i82 = 0; c2_i82 < 91; c2_i82++) {
    c2_arr[c2_i82] = c2_dv18[c2_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i83 = 0; c2_i83 < 256; c2_i83++) {
    c2_tt[c2_i83] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i84 = 0; c2_i84 < 91; c2_i84++) {
    c2_tt[c2_i84] = c2_arr[c2_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i85 = 0; c2_i85 < 256; c2_i85++) {
    c2_myarr256[c2_i85] = c2_tt[c2_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_g_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[91];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[91];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i86;
  static char_T c2_cv6[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i87;
  static real_T c2_dv19[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i90;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_n_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i86 = 0; c2_i86 < 91; c2_i86++) {
    c2_mystr[c2_i86] = c2_cv6[c2_i86];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i87 = 0; c2_i87 < 91; c2_i87++) {
    c2_arr[c2_i87] = c2_dv19[c2_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i88 = 0; c2_i88 < 256; c2_i88++) {
    c2_tt[c2_i88] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i89 = 0; c2_i89 < 91; c2_i89++) {
    c2_tt[c2_i89] = c2_arr[c2_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i90 = 0; c2_i90 < 256; c2_i90++) {
    c2_myarr256[c2_i90] = c2_tt[c2_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_h_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[87];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[87];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i91;
  static char_T c2_cv7[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c2_i92;
  static real_T c2_dv20[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_o_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i91 = 0; c2_i91 < 87; c2_i91++) {
    c2_mystr[c2_i91] = c2_cv7[c2_i91];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i92 = 0; c2_i92 < 87; c2_i92++) {
    c2_arr[c2_i92] = c2_dv20[c2_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i93 = 0; c2_i93 < 256; c2_i93++) {
    c2_tt[c2_i93] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i94 = 0; c2_i94 < 87; c2_i94++) {
    c2_tt[c2_i94] = c2_arr[c2_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i95 = 0; c2_i95 < 256; c2_i95++) {
    c2_myarr256[c2_i95] = c2_tt[c2_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_i_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[93];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[93];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i96;
  static char_T c2_cv8[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i97;
  static real_T c2_dv21[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_p_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i96 = 0; c2_i96 < 93; c2_i96++) {
    c2_mystr[c2_i96] = c2_cv8[c2_i96];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i97 = 0; c2_i97 < 93; c2_i97++) {
    c2_arr[c2_i97] = c2_dv21[c2_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i98 = 0; c2_i98 < 256; c2_i98++) {
    c2_tt[c2_i98] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i99 = 0; c2_i99 < 93; c2_i99++) {
    c2_tt[c2_i99] = c2_arr[c2_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i100 = 0; c2_i100 < 256; c2_i100++) {
    c2_myarr256[c2_i100] = c2_tt[c2_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_j_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[94];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[94];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i101;
  static char_T c2_cv9[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i102;
  static real_T c2_dv22[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_q_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i101 = 0; c2_i101 < 94; c2_i101++) {
    c2_mystr[c2_i101] = c2_cv9[c2_i101];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i102 = 0; c2_i102 < 94; c2_i102++) {
    c2_arr[c2_i102] = c2_dv22[c2_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i103 = 0; c2_i103 < 256; c2_i103++) {
    c2_tt[c2_i103] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i104 = 0; c2_i104 < 94; c2_i104++) {
    c2_tt[c2_i104] = c2_arr[c2_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i105 = 0; c2_i105 < 256; c2_i105++) {
    c2_myarr256[c2_i105] = c2_tt[c2_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_k_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[95];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[95];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i106;
  static char_T c2_cv10[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i107;
  static real_T c2_dv23[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_r_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i106 = 0; c2_i106 < 95; c2_i106++) {
    c2_mystr[c2_i106] = c2_cv10[c2_i106];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i107 = 0; c2_i107 < 95; c2_i107++) {
    c2_arr[c2_i107] = c2_dv23[c2_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i108 = 0; c2_i108 < 256; c2_i108++) {
    c2_tt[c2_i108] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i109 = 0; c2_i109 < 95; c2_i109++) {
    c2_tt[c2_i109] = c2_arr[c2_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i110 = 0; c2_i110 < 256; c2_i110++) {
    c2_myarr256[c2_i110] = c2_tt[c2_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_l_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[88];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[88];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i111;
  static char_T c2_cv11[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c2_i112;
  static real_T c2_dv24[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_s_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i111 = 0; c2_i111 < 88; c2_i111++) {
    c2_mystr[c2_i111] = c2_cv11[c2_i111];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i112 = 0; c2_i112 < 88; c2_i112++) {
    c2_arr[c2_i112] = c2_dv24[c2_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i113 = 0; c2_i113 < 256; c2_i113++) {
    c2_tt[c2_i113] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i114 = 0; c2_i114 < 88; c2_i114++) {
    c2_tt[c2_i114] = c2_arr[c2_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i115 = 0; c2_i115 < 256; c2_i115++) {
    c2_myarr256[c2_i115] = c2_tt[c2_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_m_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[93];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[93];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i116;
  static char_T c2_cv12[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i117;
  static real_T c2_dv25[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i118;
  int32_T c2_i119;
  int32_T c2_i120;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_t_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i116 = 0; c2_i116 < 93; c2_i116++) {
    c2_mystr[c2_i116] = c2_cv12[c2_i116];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i117 = 0; c2_i117 < 93; c2_i117++) {
    c2_arr[c2_i117] = c2_dv25[c2_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i118 = 0; c2_i118 < 256; c2_i118++) {
    c2_tt[c2_i118] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i119 = 0; c2_i119 < 93; c2_i119++) {
    c2_tt[c2_i119] = c2_arr[c2_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i120 = 0; c2_i120 < 256; c2_i120++) {
    c2_myarr256[c2_i120] = c2_tt[c2_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_n_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[93];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[93];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i121;
  static char_T c2_cv13[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i122;
  static real_T c2_dv26[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_u_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i121 = 0; c2_i121 < 93; c2_i121++) {
    c2_mystr[c2_i121] = c2_cv13[c2_i121];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i122 = 0; c2_i122 < 93; c2_i122++) {
    c2_arr[c2_i122] = c2_dv26[c2_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i123 = 0; c2_i123 < 256; c2_i123++) {
    c2_tt[c2_i123] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i124 = 0; c2_i124 < 93; c2_i124++) {
    c2_tt[c2_i124] = c2_arr[c2_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i125 = 0; c2_i125 < 256; c2_i125++) {
    c2_myarr256[c2_i125] = c2_tt[c2_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_o_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[97];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[97];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i126;
  static char_T c2_cv14[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i127;
  static real_T c2_dv27[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i128;
  int32_T c2_i129;
  int32_T c2_i130;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_v_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i126 = 0; c2_i126 < 97; c2_i126++) {
    c2_mystr[c2_i126] = c2_cv14[c2_i126];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i127 = 0; c2_i127 < 97; c2_i127++) {
    c2_arr[c2_i127] = c2_dv27[c2_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i128 = 0; c2_i128 < 256; c2_i128++) {
    c2_tt[c2_i128] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i129 = 0; c2_i129 < 97; c2_i129++) {
    c2_tt[c2_i129] = c2_arr[c2_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i130 = 0; c2_i130 < 256; c2_i130++) {
    c2_myarr256[c2_i130] = c2_tt[c2_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_p_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[97];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[97];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i131;
  static char_T c2_cv15[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i132;
  static real_T c2_dv28[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_w_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i131 = 0; c2_i131 < 97; c2_i131++) {
    c2_mystr[c2_i131] = c2_cv15[c2_i131];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i132 = 0; c2_i132 < 97; c2_i132++) {
    c2_arr[c2_i132] = c2_dv28[c2_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i133 = 0; c2_i133 < 256; c2_i133++) {
    c2_tt[c2_i133] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i134 = 0; c2_i134 < 97; c2_i134++) {
    c2_tt[c2_i134] = c2_arr[c2_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i135 = 0; c2_i135 < 256; c2_i135++) {
    c2_myarr256[c2_i135] = c2_tt[c2_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_q_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[92];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[92];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i136;
  static char_T c2_cv16[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i137;
  static real_T c2_dv29[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c2_i138;
  int32_T c2_i139;
  int32_T c2_i140;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_x_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i136 = 0; c2_i136 < 92; c2_i136++) {
    c2_mystr[c2_i136] = c2_cv16[c2_i136];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i137 = 0; c2_i137 < 92; c2_i137++) {
    c2_arr[c2_i137] = c2_dv29[c2_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i138 = 0; c2_i138 < 256; c2_i138++) {
    c2_tt[c2_i138] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i139 = 0; c2_i139 < 92; c2_i139++) {
    c2_tt[c2_i139] = c2_arr[c2_i139];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i140 = 0; c2_i140 < 256; c2_i140++) {
    c2_myarr256[c2_i140] = c2_tt[c2_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_r_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[68];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[68];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i141;
  static char_T c2_cv17[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i142;
  static real_T c2_dv30[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_i145;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_ab_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i141 = 0; c2_i141 < 68; c2_i141++) {
    c2_mystr[c2_i141] = c2_cv17[c2_i141];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i142 = 0; c2_i142 < 68; c2_i142++) {
    c2_arr[c2_i142] = c2_dv30[c2_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 68.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i143 = 0; c2_i143 < 256; c2_i143++) {
    c2_tt[c2_i143] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i144 = 0; c2_i144 < 68; c2_i144++) {
    c2_tt[c2_i144] = c2_arr[c2_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i145 = 0; c2_i145 < 256; c2_i145++) {
    c2_myarr256[c2_i145] = c2_tt[c2_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_s_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[87];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[87];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i146;
  static char_T c2_cv18[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c2_i147;
  static real_T c2_dv31[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i150;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_bb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i146 = 0; c2_i146 < 87; c2_i146++) {
    c2_mystr[c2_i146] = c2_cv18[c2_i146];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i147 = 0; c2_i147 < 87; c2_i147++) {
    c2_arr[c2_i147] = c2_dv31[c2_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i148 = 0; c2_i148 < 256; c2_i148++) {
    c2_tt[c2_i148] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i149 = 0; c2_i149 < 87; c2_i149++) {
    c2_tt[c2_i149] = c2_arr[c2_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i150 = 0; c2_i150 < 256; c2_i150++) {
    c2_myarr256[c2_i150] = c2_tt[c2_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_t_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[223];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[223];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i151;
  static char_T c2_cv19[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c2_i152;
  static real_T c2_dv32[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c2_i153;
  int32_T c2_i154;
  int32_T c2_i155;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_eb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i151 = 0; c2_i151 < 223; c2_i151++) {
    c2_mystr[c2_i151] = c2_cv19[c2_i151];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i152 = 0; c2_i152 < 223; c2_i152++) {
    c2_arr[c2_i152] = c2_dv32[c2_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i153 = 0; c2_i153 < 256; c2_i153++) {
    c2_tt[c2_i153] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i154 = 0; c2_i154 < 223; c2_i154++) {
    c2_tt[c2_i154] = c2_arr[c2_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i155 = 0; c2_i155 < 256; c2_i155++) {
    c2_myarr256[c2_i155] = c2_tt[c2_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_u_encStr2Arr(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, real_T c2_myarr256[256])
{
  uint32_T c2_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[142];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[142];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i156;
  static char_T c2_cv20[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i157;
  static real_T c2_dv33[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c2_i158;
  int32_T c2_i159;
  int32_T c2_i160;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_fb_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  for (c2_i156 = 0; c2_i156 < 142; c2_i156++) {
    c2_mystr[c2_i156] = c2_cv20[c2_i156];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i157 = 0; c2_i157 < 142; c2_i157++) {
    c2_arr[c2_i157] = c2_dv33[c2_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_padsize = c2_maxarrsize - c2_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i158 = 0; c2_i158 < 256; c2_i158++) {
    c2_tt[c2_i158] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i159 = 0; c2_i159 < 142; c2_i159++) {
    c2_tt[c2_i159] = c2_arr[c2_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i160 = 0; c2_i160 < 256; c2_i160++) {
    c2_myarr256[c2_i160] = c2_tt[c2_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c2_rand(SFc2_lib_affectiveChar_scenarioInstanceStruct
                      *chartInstance)
{
  return c2_eml_rand(chartInstance);
}

static real_T c2_eml_rand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  real_T c2_r;
  uint32_T c2_hoistedGlobal;
  uint32_T c2_d_state;
  uint32_T c2_e_state;
  uint32_T c2_s;
  uint32_T c2_u0;
  uint32_T c2_hi;
  uint32_T c2_lo;
  uint32_T c2_test1;
  uint32_T c2_test2;
  uint32_T c2_f_state;
  real_T c2_b_r;
  real_T c2_d0;
  int32_T c2_i161;
  uint32_T c2_icng;
  uint32_T c2_jsr;
  uint32_T c2_u1;
  uint32_T c2_u2;
  uint32_T c2_ui;
  uint32_T c2_b_ui;
  real_T c2_c_r;
  real_T c2_d1;
  uint32_T c2_uv2[625];
  int32_T c2_i162;
  real_T c2_d2;
  if (!chartInstance->c2_method_not_empty) {
    chartInstance->c2_method = 7U;
    chartInstance->c2_method_not_empty = true;
  }

  if (chartInstance->c2_method == 4U) {
    if (!chartInstance->c2_state_not_empty) {
      chartInstance->c2_state = 1144108930U;
      chartInstance->c2_state_not_empty = true;
    }

    c2_hoistedGlobal = chartInstance->c2_state;
    c2_d_state = c2_hoistedGlobal;
    c2_e_state = c2_d_state;
    c2_s = c2_e_state;
    c2_u0 = 127773U;
    if (c2_u0 == 0U) {
      c2_hi = MAX_uint32_T;
    } else {
      c2_hi = c2_s / c2_u0;
    }

    c2_lo = c2_s - c2_hi * 127773U;
    c2_test1 = 16807U * c2_lo;
    c2_test2 = 2836U * c2_hi;
    if (c2_test1 < c2_test2) {
      c2_f_state = (c2_test1 - c2_test2) + 2147483647U;
    } else {
      c2_f_state = c2_test1 - c2_test2;
    }

    c2_b_r = (real_T)c2_f_state * 4.6566128752457969E-10;
    c2_e_state = c2_f_state;
    c2_d0 = c2_b_r;
    chartInstance->c2_state = c2_e_state;
    c2_r = c2_d0;
  } else if (chartInstance->c2_method == 5U) {
    if (!chartInstance->c2_b_state_not_empty) {
      for (c2_i161 = 0; c2_i161 < 2; c2_i161++) {
        chartInstance->c2_b_state[c2_i161] = 362436069U + 158852560U * (uint32_T)
          c2_i161;
      }

      chartInstance->c2_b_state_not_empty = true;
    }

    c2_icng = chartInstance->c2_b_state[0];
    c2_jsr = chartInstance->c2_b_state[1];
    c2_u1 = c2_jsr;
    c2_u2 = c2_icng;
    c2_u2 = 69069U * c2_u2 + 1234567U;
    c2_u1 ^= c2_u1 << 13;
    c2_u1 ^= c2_u1 >> 17;
    c2_u1 ^= c2_u1 << 5;
    c2_ui = c2_u2 + c2_u1;
    chartInstance->c2_b_state[0] = c2_u2;
    chartInstance->c2_b_state[1] = c2_u1;
    c2_b_ui = c2_ui;
    c2_c_r = (real_T)c2_b_ui * 2.328306436538696E-10;
    c2_d1 = c2_c_r;
    c2_r = c2_d1;
  } else {
    if (!chartInstance->c2_c_state_not_empty) {
      c2_eml_rand_mt19937ar(chartInstance, c2_uv2);
      for (c2_i162 = 0; c2_i162 < 625; c2_i162++) {
        chartInstance->c2_c_state[c2_i162] = c2_uv2[c2_i162];
      }

      chartInstance->c2_c_state_not_empty = true;
    }

    c2_d2 = c2_c_eml_rand_mt19937ar(chartInstance, chartInstance->c2_c_state);
    c2_r = c2_d2;
  }

  return c2_r;
}

static void c2_eml_rand_mt19937ar(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_d_state[625])
{
  real_T c2_d3;
  int32_T c2_i163;
  c2_d3 = 5489.0;
  for (c2_i163 = 0; c2_i163 < 625; c2_i163++) {
    c2_d_state[c2_i163] = 0U;
  }

  c2_b_twister_state_vector(chartInstance, c2_d_state, c2_d3);
}

static void c2_twister_state_vector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_mt
   [625], real_T c2_seed, uint32_T c2_b_mt[625])
{
  int32_T c2_i164;
  for (c2_i164 = 0; c2_i164 < 625; c2_i164++) {
    c2_b_mt[c2_i164] = c2_mt[c2_i164];
  }

  c2_b_twister_state_vector(chartInstance, c2_b_mt, c2_seed);
}

static void c2_b_eml_rand_mt19937ar
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_d_state[625], uint32_T c2_e_state[625], real_T *c2_r)
{
  int32_T c2_i165;
  for (c2_i165 = 0; c2_i165 < 625; c2_i165++) {
    c2_e_state[c2_i165] = c2_d_state[c2_i165];
  }

  *c2_r = c2_c_eml_rand_mt19937ar(chartInstance, c2_e_state);
}

static void c2_eml_error(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  int32_T c2_i166;
  static char_T c2_cv21[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c2_u[37];
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  for (c2_i166 = 0; c2_i166 < 37; c2_i166++) {
    c2_u[c2_i166] = c2_cv21[c2_i166];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static real_T c2_randi(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  real_T c2_r;
  real_T c2_x;
  real_T c2_b_x;
  c2_r = c2_rand(chartInstance);
  c2_x = c2_r * 2.0;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarFloor(c2_b_x);
  return 1.0 + c2_b_x;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i167;
  real_T c2_b_inData[256];
  int32_T c2_i168;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i167 = 0; c2_i167 < 256; c2_i167++) {
    c2_b_inData[c2_i167] = (*(real_T (*)[256])c2_inData)[c2_i167];
  }

  for (c2_i168 = 0; c2_i168 < 256; c2_i168++) {
    c2_u[c2_i168] = c2_b_inData[c2_i168];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv34[256];
  int32_T c2_i169;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv34, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c2_i169 = 0; c2_i169 < 256; c2_i169++) {
    c2_y[c2_i169] = c2_dv34[c2_i169];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_poseBML;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i170;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_poseBML = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_poseBML), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_poseBML);
  for (c2_i170 = 0; c2_i170 < 256; c2_i170++) {
    (*(real_T (*)[256])c2_outData)[c2_i170] = c2_y[c2_i170];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_bmlID, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bmlID), &c2_thisId);
  sf_mex_destroy(&c2_bmlID);
  return c2_y;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d4;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_bmlID;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_bmlID = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bmlID), &c2_thisId);
  sf_mex_destroy(&c2_bmlID);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_d_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_aVarTruthTableCondition_2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_aVarTruthTableCondition_2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_aVarTruthTableCondition_2), &c2_thisId);
  sf_mex_destroy(&c2_aVarTruthTableCondition_2);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i171;
  real_T c2_b_inData[256];
  int32_T c2_i172;
  real_T c2_u[256];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i171 = 0; c2_i171 < 256; c2_i171++) {
    c2_b_inData[c2_i171] = (*(real_T (*)[256])c2_inData)[c2_i171];
  }

  for (c2_i172 = 0; c2_i172 < 256; c2_i172++) {
    c2_u[c2_i172] = c2_b_inData[c2_i172];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv35[256];
  int32_T c2_i173;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv35, 1, 0, 0U, 1, 0U, 1, 256);
  for (c2_i173 = 0; c2_i173 < 256; c2_i173++) {
    c2_y[c2_i173] = c2_dv35[c2_i173];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_myarr256;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i174;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_myarr256 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_myarr256), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_myarr256);
  for (c2_i174 = 0; c2_i174 < 256; c2_i174++) {
    (*(real_T (*)[256])c2_outData)[c2_i174] = c2_y[c2_i174];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i175;
  char_T c2_b_inData[94];
  int32_T c2_i176;
  char_T c2_u[94];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i175 = 0; c2_i175 < 94; c2_i175++) {
    c2_b_inData[c2_i175] = (*(char_T (*)[94])c2_inData)[c2_i175];
  }

  for (c2_i176 = 0; c2_i176 < 94; c2_i176++) {
    c2_u[c2_i176] = c2_b_inData[c2_i176];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i177;
  real_T c2_b_inData[94];
  int32_T c2_i178;
  real_T c2_u[94];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i177 = 0; c2_i177 < 94; c2_i177++) {
    c2_b_inData[c2_i177] = (*(real_T (*)[94])c2_inData)[c2_i177];
  }

  for (c2_i178 = 0; c2_i178 < 94; c2_i178++) {
    c2_u[c2_i178] = c2_b_inData[c2_i178];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i179;
  char_T c2_b_inData[88];
  int32_T c2_i180;
  char_T c2_u[88];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i179 = 0; c2_i179 < 88; c2_i179++) {
    c2_b_inData[c2_i179] = (*(char_T (*)[88])c2_inData)[c2_i179];
  }

  for (c2_i180 = 0; c2_i180 < 88; c2_i180++) {
    c2_u[c2_i180] = c2_b_inData[c2_i180];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i181;
  real_T c2_b_inData[88];
  int32_T c2_i182;
  real_T c2_u[88];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i181 = 0; c2_i181 < 88; c2_i181++) {
    c2_b_inData[c2_i181] = (*(real_T (*)[88])c2_inData)[c2_i181];
  }

  for (c2_i182 = 0; c2_i182 < 88; c2_i182++) {
    c2_u[c2_i182] = c2_b_inData[c2_i182];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i183;
  char_T c2_b_inData[86];
  int32_T c2_i184;
  char_T c2_u[86];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i183 = 0; c2_i183 < 86; c2_i183++) {
    c2_b_inData[c2_i183] = (*(char_T (*)[86])c2_inData)[c2_i183];
  }

  for (c2_i184 = 0; c2_i184 < 86; c2_i184++) {
    c2_u[c2_i184] = c2_b_inData[c2_i184];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i185;
  real_T c2_b_inData[86];
  int32_T c2_i186;
  real_T c2_u[86];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i185 = 0; c2_i185 < 86; c2_i185++) {
    c2_b_inData[c2_i185] = (*(real_T (*)[86])c2_inData)[c2_i185];
  }

  for (c2_i186 = 0; c2_i186 < 86; c2_i186++) {
    c2_u[c2_i186] = c2_b_inData[c2_i186];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i187;
  char_T c2_b_inData[161];
  int32_T c2_i188;
  char_T c2_u[161];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i187 = 0; c2_i187 < 161; c2_i187++) {
    c2_b_inData[c2_i187] = (*(char_T (*)[161])c2_inData)[c2_i187];
  }

  for (c2_i188 = 0; c2_i188 < 161; c2_i188++) {
    c2_u[c2_i188] = c2_b_inData[c2_i188];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i189;
  real_T c2_b_inData[161];
  int32_T c2_i190;
  real_T c2_u[161];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i189 = 0; c2_i189 < 161; c2_i189++) {
    c2_b_inData[c2_i189] = (*(real_T (*)[161])c2_inData)[c2_i189];
  }

  for (c2_i190 = 0; c2_i190 < 161; c2_i190++) {
    c2_u[c2_i190] = c2_b_inData[c2_i190];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i191;
  char_T c2_b_inData[157];
  int32_T c2_i192;
  char_T c2_u[157];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i191 = 0; c2_i191 < 157; c2_i191++) {
    c2_b_inData[c2_i191] = (*(char_T (*)[157])c2_inData)[c2_i191];
  }

  for (c2_i192 = 0; c2_i192 < 157; c2_i192++) {
    c2_u[c2_i192] = c2_b_inData[c2_i192];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i193;
  real_T c2_b_inData[157];
  int32_T c2_i194;
  real_T c2_u[157];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i193 = 0; c2_i193 < 157; c2_i193++) {
    c2_b_inData[c2_i193] = (*(real_T (*)[157])c2_inData)[c2_i193];
  }

  for (c2_i194 = 0; c2_i194 < 157; c2_i194++) {
    c2_u[c2_i194] = c2_b_inData[c2_i194];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_o_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i195;
  char_T c2_b_inData[91];
  int32_T c2_i196;
  char_T c2_u[91];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i195 = 0; c2_i195 < 91; c2_i195++) {
    c2_b_inData[c2_i195] = (*(char_T (*)[91])c2_inData)[c2_i195];
  }

  for (c2_i196 = 0; c2_i196 < 91; c2_i196++) {
    c2_u[c2_i196] = c2_b_inData[c2_i196];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_p_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i197;
  real_T c2_b_inData[91];
  int32_T c2_i198;
  real_T c2_u[91];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i197 = 0; c2_i197 < 91; c2_i197++) {
    c2_b_inData[c2_i197] = (*(real_T (*)[91])c2_inData)[c2_i197];
  }

  for (c2_i198 = 0; c2_i198 < 91; c2_i198++) {
    c2_u[c2_i198] = c2_b_inData[c2_i198];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_q_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i199;
  char_T c2_b_inData[87];
  int32_T c2_i200;
  char_T c2_u[87];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i199 = 0; c2_i199 < 87; c2_i199++) {
    c2_b_inData[c2_i199] = (*(char_T (*)[87])c2_inData)[c2_i199];
  }

  for (c2_i200 = 0; c2_i200 < 87; c2_i200++) {
    c2_u[c2_i200] = c2_b_inData[c2_i200];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_r_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i201;
  real_T c2_b_inData[87];
  int32_T c2_i202;
  real_T c2_u[87];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i201 = 0; c2_i201 < 87; c2_i201++) {
    c2_b_inData[c2_i201] = (*(real_T (*)[87])c2_inData)[c2_i201];
  }

  for (c2_i202 = 0; c2_i202 < 87; c2_i202++) {
    c2_u[c2_i202] = c2_b_inData[c2_i202];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_s_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i203;
  char_T c2_b_inData[93];
  int32_T c2_i204;
  char_T c2_u[93];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i203 = 0; c2_i203 < 93; c2_i203++) {
    c2_b_inData[c2_i203] = (*(char_T (*)[93])c2_inData)[c2_i203];
  }

  for (c2_i204 = 0; c2_i204 < 93; c2_i204++) {
    c2_u[c2_i204] = c2_b_inData[c2_i204];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_t_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i205;
  real_T c2_b_inData[93];
  int32_T c2_i206;
  real_T c2_u[93];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i205 = 0; c2_i205 < 93; c2_i205++) {
    c2_b_inData[c2_i205] = (*(real_T (*)[93])c2_inData)[c2_i205];
  }

  for (c2_i206 = 0; c2_i206 < 93; c2_i206++) {
    c2_u[c2_i206] = c2_b_inData[c2_i206];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_u_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i207;
  char_T c2_b_inData[95];
  int32_T c2_i208;
  char_T c2_u[95];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i207 = 0; c2_i207 < 95; c2_i207++) {
    c2_b_inData[c2_i207] = (*(char_T (*)[95])c2_inData)[c2_i207];
  }

  for (c2_i208 = 0; c2_i208 < 95; c2_i208++) {
    c2_u[c2_i208] = c2_b_inData[c2_i208];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_v_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i209;
  real_T c2_b_inData[95];
  int32_T c2_i210;
  real_T c2_u[95];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i209 = 0; c2_i209 < 95; c2_i209++) {
    c2_b_inData[c2_i209] = (*(real_T (*)[95])c2_inData)[c2_i209];
  }

  for (c2_i210 = 0; c2_i210 < 95; c2_i210++) {
    c2_u[c2_i210] = c2_b_inData[c2_i210];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_w_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i211;
  char_T c2_b_inData[97];
  int32_T c2_i212;
  char_T c2_u[97];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i211 = 0; c2_i211 < 97; c2_i211++) {
    c2_b_inData[c2_i211] = (*(char_T (*)[97])c2_inData)[c2_i211];
  }

  for (c2_i212 = 0; c2_i212 < 97; c2_i212++) {
    c2_u[c2_i212] = c2_b_inData[c2_i212];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_x_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i213;
  real_T c2_b_inData[97];
  int32_T c2_i214;
  real_T c2_u[97];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i213 = 0; c2_i213 < 97; c2_i213++) {
    c2_b_inData[c2_i213] = (*(real_T (*)[97])c2_inData)[c2_i213];
  }

  for (c2_i214 = 0; c2_i214 < 97; c2_i214++) {
    c2_u[c2_i214] = c2_b_inData[c2_i214];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_y_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i215;
  char_T c2_b_inData[92];
  int32_T c2_i216;
  char_T c2_u[92];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i215 = 0; c2_i215 < 92; c2_i215++) {
    c2_b_inData[c2_i215] = (*(char_T (*)[92])c2_inData)[c2_i215];
  }

  for (c2_i216 = 0; c2_i216 < 92; c2_i216++) {
    c2_u[c2_i216] = c2_b_inData[c2_i216];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i217;
  real_T c2_b_inData[92];
  int32_T c2_i218;
  real_T c2_u[92];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i217 = 0; c2_i217 < 92; c2_i217++) {
    c2_b_inData[c2_i217] = (*(real_T (*)[92])c2_inData)[c2_i217];
  }

  for (c2_i218 = 0; c2_i218 < 92; c2_i218++) {
    c2_u[c2_i218] = c2_b_inData[c2_i218];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i219;
  char_T c2_b_inData[68];
  int32_T c2_i220;
  char_T c2_u[68];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i219 = 0; c2_i219 < 68; c2_i219++) {
    c2_b_inData[c2_i219] = (*(char_T (*)[68])c2_inData)[c2_i219];
  }

  for (c2_i220 = 0; c2_i220 < 68; c2_i220++) {
    c2_u[c2_i220] = c2_b_inData[c2_i220];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i221;
  real_T c2_b_inData[68];
  int32_T c2_i222;
  real_T c2_u[68];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i221 = 0; c2_i221 < 68; c2_i221++) {
    c2_b_inData[c2_i221] = (*(real_T (*)[68])c2_inData)[c2_i221];
  }

  for (c2_i222 = 0; c2_i222 < 68; c2_i222++) {
    c2_u[c2_i222] = c2_b_inData[c2_i222];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_db_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i223;
  char_T c2_b_inData[223];
  int32_T c2_i224;
  char_T c2_u[223];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i223 = 0; c2_i223 < 223; c2_i223++) {
    c2_b_inData[c2_i223] = (*(char_T (*)[223])c2_inData)[c2_i223];
  }

  for (c2_i224 = 0; c2_i224 < 223; c2_i224++) {
    c2_u[c2_i224] = c2_b_inData[c2_i224];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i225;
  real_T c2_b_inData[223];
  int32_T c2_i226;
  real_T c2_u[223];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i225 = 0; c2_i225 < 223; c2_i225++) {
    c2_b_inData[c2_i225] = (*(real_T (*)[223])c2_inData)[c2_i225];
  }

  for (c2_i226 = 0; c2_i226 < 223; c2_i226++) {
    c2_u[c2_i226] = c2_b_inData[c2_i226];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i227;
  char_T c2_b_inData[142];
  int32_T c2_i228;
  char_T c2_u[142];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i227 = 0; c2_i227 < 142; c2_i227++) {
    c2_b_inData[c2_i227] = (*(char_T (*)[142])c2_inData)[c2_i227];
  }

  for (c2_i228 = 0; c2_i228 < 142; c2_i228++) {
    c2_u[c2_i228] = c2_b_inData[c2_i228];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i229;
  real_T c2_b_inData[142];
  int32_T c2_i230;
  real_T c2_u[142];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i229 = 0; c2_i229 < 142; c2_i229++) {
    c2_b_inData[c2_i229] = (*(real_T (*)[142])c2_inData)[c2_i229];
  }

  for (c2_i230 = 0; c2_i230 < 142; c2_i230++) {
    c2_u[c2_i230] = c2_b_inData[c2_i230];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i231;
  char_T c2_b_inData[183];
  int32_T c2_i232;
  char_T c2_u[183];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i231 = 0; c2_i231 < 183; c2_i231++) {
    c2_b_inData[c2_i231] = (*(char_T (*)[183])c2_inData)[c2_i231];
  }

  for (c2_i232 = 0; c2_i232 < 183; c2_i232++) {
    c2_u[c2_i232] = c2_b_inData[c2_i232];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i233;
  real_T c2_b_inData[183];
  int32_T c2_i234;
  real_T c2_u[183];
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i233 = 0; c2_i233 < 183; c2_i233++) {
    c2_b_inData[c2_i233] = (*(real_T (*)[183])c2_inData)[c2_i233];
  }

  for (c2_i234 = 0; c2_i234 < 183; c2_i234++) {
    c2_u[c2_i234] = c2_b_inData[c2_i234];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_lib_affectiveChar_scenario_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  const mxArray *c2_rhs32 = NULL;
  const mxArray *c2_lhs32 = NULL;
  const mxArray *c2_rhs33 = NULL;
  const mxArray *c2_lhs33 = NULL;
  const mxArray *c2_rhs34 = NULL;
  const mxArray *c2_lhs34 = NULL;
  const mxArray *c2_rhs35 = NULL;
  const mxArray *c2_lhs35 = NULL;
  const mxArray *c2_rhs36 = NULL;
  const mxArray *c2_lhs36 = NULL;
  const mxArray *c2_rhs37 = NULL;
  const mxArray *c2_lhs37 = NULL;
  const mxArray *c2_rhs38 = NULL;
  const mxArray *c2_lhs38 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c2_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c2_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c2_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c2_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c2_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c2_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c2_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
  sf_mex_destroy(&c2_rhs32);
  sf_mex_destroy(&c2_lhs32);
  sf_mex_destroy(&c2_rhs33);
  sf_mex_destroy(&c2_lhs33);
  sf_mex_destroy(&c2_rhs34);
  sf_mex_destroy(&c2_lhs34);
  sf_mex_destroy(&c2_rhs35);
  sf_mex_destroy(&c2_lhs35);
  sf_mex_destroy(&c2_rhs36);
  sf_mex_destroy(&c2_lhs36);
  sf_mex_destroy(&c2_rhs37);
  sf_mex_destroy(&c2_lhs37);
  sf_mex_destroy(&c2_rhs38);
  sf_mex_destroy(&c2_lhs38);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static void c2_activate_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = c2_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c2_event_secs,
               chartInstance->c2_sfEvent);
}

static void c2_deactivate_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c2_event_secs,
               chartInstance->c2_sfEvent);
}

static void c2_increment_counters_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  if (chartInstance->c2_temporalCounter_i1 < 7U) {
    chartInstance->c2_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c2_temporalCounter_i1 + 1);
  }
}

static void c2_reset_counters_secsc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c2_lib_affectiveChar_scenario_secs(SimStruct
  *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_activate_secsc2_lib_affectiveChar_scenario(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_increment_counters_secsc2_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c2_lib_affectiveChar_scenario_secs
  (SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_reset_counters_secsc2_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_deactivate_c2_lib_affectiveChar_scenario_secs(SimStruct
  *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_deactivate_secsc2_lib_affectiveChar_scenario(chartInstance);
}

boolean_T sf_exported_auto_isStablec2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c2_isStable;
}

void sf_exported_auto_duringc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_c2_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_enterc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c2_sendSBM(chartInstance);
  c2_sendBML(chartInstance);
  c2_enter_atomic_c2_lib_affectiveChar_scenario(chartInstance);
  c2_enter_internal_c2_lib_affectiveChar_scenario(chartInstance);
}

void sf_exported_auto_exitc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c2_exit_internal_c2_lib_affectiveChar_scenario(chartInstance);
  c2_b_sendSBM(chartInstance);
  c2_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c2_sendSBM(chartInstance);
  c2_sendBML(chartInstance);
}

void sf_exported_auto_disablec2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c2_b_sendSBM(chartInstance);
  c2_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  chartInstance->c2_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc2_lib_affectiveChar_scenario
  (SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc2_lib_affectiveChar_scenario(SimStruct *
  c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc2_lib_affectiveChar_scenario(SimStruct
  *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc2_lib_affectiveChar_scenario(SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_initc2_lib_affectiveChar_scenario(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec2_lib_affectiveChar_scenario
  (SimStruct *c2_S)
{
  const mxArray *c2_out = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_out = NULL;
  sf_mex_assign(&c2_out, sf_internal_get_sim_state_c2_lib_affectiveChar_scenario
                (c2_S), false);
  return c2_out;
}

void sf_exported_auto_setSimstatec2_lib_affectiveChar_scenario(SimStruct *c2_S,
  const mxArray *c2_in)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c2_lib_affectiveChar_scenario(c2_S, sf_mex_dup(c2_in));
  sf_mex_destroy(&c2_in);
}

void sf_exported_auto_check_state_inconsistency_c2_lib_affectiveChar_scenario
  (SimStruct *c2_S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_lib_affectiveChar_scenarioMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_sendSBMc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_arg
   [256])
{
  int32_T c2_i235;
  int32_T c2_i236;
  int32_T c2_i237;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c2_i235 = 0; c2_i235 < 256; c2_i235++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i235], 24U);
  }

  _SFD_SET_DATA_VALUE_PTR(24U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
  for (c2_i236 = 0; c2_i236 < 256; c2_i236++) {
    (*c2_b_arg)[c2_i236] = c2_arg[c2_i236];
  }

  for (c2_i237 = 0; c2_i237 < 256; c2_i237++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i237], 24U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(24U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
}

static void c2_sendBMLc2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_arg
   [256])
{
  int32_T c2_i238;
  int32_T c2_i239;
  int32_T c2_i240;
  real_T (*c2_b_arg)[256];
  c2_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c2_i238 = 0; c2_i238 < 256; c2_i238++) {
    _SFD_DATA_RANGE_CHECK(c2_arg[c2_i238], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c2_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c2_arg, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  for (c2_i239 = 0; c2_i239 < 256; c2_i239++) {
    (*c2_b_arg)[c2_i239] = c2_arg[c2_i239];
  }

  for (c2_i240 = 0; c2_i240 < 256; c2_i240++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_arg)[c2_i240], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
}

static void c2_rockPoseTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[6];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv36[256];
  int32_T c2_i241;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[94];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[94];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_myarr256[256];
  int32_T c2_i242;
  static char_T c2_cv22[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i243;
  static real_T c2_dv37[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i244;
  int32_T c2_i245;
  int32_T c2_i246;
  int32_T c2_i247;
  int32_T c2_i248;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 9);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 13);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 27);
    c2_encStr2Arr(chartInstance, c2_dv36);
    for (c2_i241 = 0; c2_i241 < 256; c2_i241++) {
      c2_poseBML[c2_i241] = c2_dv36[c2_i241];
    }

    c2_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_c_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_f_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
        c2_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_e_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U,
        c2_b_sf_marshallOut, c2_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U, c2_d_sf_marshallOut,
        c2_d_sf_marshallIn);
      for (c2_i242 = 0; c2_i242 < 94; c2_i242++) {
        c2_mystr[c2_i242] = c2_cv22[c2_i242];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
      c2_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
      for (c2_i243 = 0; c2_i243 < 94; c2_i243++) {
        c2_arr[c2_i243] = c2_dv37[c2_i243];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
      c2_ss = 94.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
      c2_padsize = c2_maxarrsize - c2_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
      for (c2_i244 = 0; c2_i244 < 256; c2_i244++) {
        c2_tt[c2_i244] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
      for (c2_i245 = 0; c2_i245 < 94; c2_i245++) {
        c2_tt[c2_i245] = c2_arr[c2_i245];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
      for (c2_i246 = 0; c2_i246 < 256; c2_i246++) {
        c2_myarr256[c2_i246] = c2_tt[c2_i246];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c2_i247 = 0; c2_i247 < 256; c2_i247++) {
        c2_poseBML[c2_i247] = c2_myarr256[c2_i247];
      }

      c2_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, 27);
      c2_encStr2Arr(chartInstance, c2_dv36);
      for (c2_i248 = 0; c2_i248 < 256; c2_i248++) {
        c2_poseBML[c2_i248] = c2_dv36[c2_i248];
      }

      c2_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c2_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_paperPoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[6];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv38[256];
  int32_T c2_i249;
  int32_T c2_i250;
  int32_T c2_i251;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_d_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 9);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 13);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 15);
  if (CV_EML_IF(4, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 16);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 27);
    c2_b_encStr2Arr(chartInstance, c2_dv38);
    for (c2_i249 = 0; c2_i249 < 256; c2_i249++) {
      c2_poseBML[c2_i249] = c2_dv38[c2_i249];
    }

    c2_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, -27);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 17);
    if (CV_EML_IF(4, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 18);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 33);
      c2_c_encStr2Arr(chartInstance, c2_dv38);
      for (c2_i250 = 0; c2_i250 < 256; c2_i250++) {
        c2_poseBML[c2_i250] = c2_dv38[c2_i250];
      }

      c2_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, -33);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 20);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, 33);
      c2_c_encStr2Arr(chartInstance, c2_dv38);
      for (c2_i251 = 0; c2_i251 < 256; c2_i251++) {
        c2_poseBML[c2_i251] = c2_dv38[c2_i251];
      }

      c2_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, -33);
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c2_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_scissorsPoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[6];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv39[256];
  int32_T c2_i252;
  int32_T c2_i253;
  int32_T c2_i254;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_g_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 9);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 13);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 15);
  if (CV_EML_IF(6, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 16);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 27);
    c2_c_encStr2Arr(chartInstance, c2_dv39);
    for (c2_i252 = 0; c2_i252 < 256; c2_i252++) {
      c2_poseBML[c2_i252] = c2_dv39[c2_i252];
    }

    c2_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, -27);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 17);
    if (CV_EML_IF(6, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 18);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 33);
      c2_b_encStr2Arr(chartInstance, c2_dv39);
      for (c2_i253 = 0; c2_i253 < 256; c2_i253++) {
        c2_poseBML[c2_i253] = c2_dv39[c2_i253];
      }

      c2_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, -33);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 20);
      CV_EML_FCN(6, 1);
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, 27);
      c2_c_encStr2Arr(chartInstance, c2_dv39);
      for (c2_i254 = 0; c2_i254 < 256; c2_i254++) {
        c2_poseBML[c2_i254] = c2_dv39[c2_i254];
      }

      c2_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c2_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_handPoseSBTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_sbmID,
   real_T c2_poseSBM[256])
{
  uint32_T c2_debug_family_var_map[8];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  boolean_T c2_aVarTruthTableCondition_3;
  boolean_T c2_aVarTruthTableCondition_4;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv40[256];
  int32_T c2_i255;
  int32_T c2_i256;
  int32_T c2_i257;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[88];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[88];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_myarr256[256];
  int32_T c2_i258;
  static char_T c2_cv23[88] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', ')', ')' };

  int32_T c2_i259;
  static real_T c2_dv41[88] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0 };

  int32_T c2_i260;
  int32_T c2_i261;
  int32_T c2_i262;
  int32_T c2_i263;
  int32_T c2_i264;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_h_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_3, 2U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_4, 3U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_sbmID, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseSBM, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 5);
  c2_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 6);
  c2_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 11);
  c2_aVarTruthTableCondition_1 = (c2_sbmID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 15);
  c2_aVarTruthTableCondition_2 = (c2_sbmID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 19);
  c2_aVarTruthTableCondition_3 = (c2_sbmID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 23);
  c2_aVarTruthTableCondition_4 = (c2_sbmID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 25);
  if (CV_EML_IF(1, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 26);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 41);
    c2_d_encStr2Arr(chartInstance, c2_dv40);
    for (c2_i255 = 0; c2_i255 < 256; c2_i255++) {
      c2_poseSBM[c2_i255] = c2_dv40[c2_i255];
    }

    c2_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -41);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 27);
    if (CV_EML_IF(1, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 28);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 47);
      c2_e_encStr2Arr(chartInstance, c2_dv40);
      for (c2_i256 = 0; c2_i256 < 256; c2_i256++) {
        c2_poseSBM[c2_i256] = c2_dv40[c2_i256];
      }

      c2_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -47);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 29);
      if (CV_EML_IF(1, 1, 2, c2_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 30);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 53);
        c2_f_encStr2Arr(chartInstance, c2_dv40);
        for (c2_i257 = 0; c2_i257 < 256; c2_i257++) {
          c2_poseSBM[c2_i257] = c2_dv40[c2_i257];
        }

        c2_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -53);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 31);
        if (CV_EML_IF(1, 1, 3, c2_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 32);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_l_debug_family_names,
            c2_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U,
            c2_b_sf_marshallOut, c2_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_h_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U,
            c2_b_sf_marshallOut, c2_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
            c2_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_g_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U,
            c2_b_sf_marshallOut, c2_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U,
            c2_b_sf_marshallOut, c2_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U,
            c2_d_sf_marshallOut, c2_d_sf_marshallIn);
          for (c2_i258 = 0; c2_i258 < 88; c2_i258++) {
            c2_mystr[c2_i258] = c2_cv23[c2_i258];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
          c2_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
          for (c2_i259 = 0; c2_i259 < 88; c2_i259++) {
            c2_arr[c2_i259] = c2_dv41[c2_i259];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
          c2_ss = 88.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
          c2_padsize = c2_maxarrsize - c2_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
          for (c2_i260 = 0; c2_i260 < 256; c2_i260++) {
            c2_tt[c2_i260] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
          for (c2_i261 = 0; c2_i261 < 88; c2_i261++) {
            c2_tt[c2_i261] = c2_arr[c2_i261];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
          for (c2_i262 = 0; c2_i262 < 256; c2_i262++) {
            c2_myarr256[c2_i262] = c2_tt[c2_i262];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c2_i263 = 0; c2_i263 < 256; c2_i263++) {
            c2_poseSBM[c2_i263] = c2_myarr256[c2_i263];
          }

          c2_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -59);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 34);
          CV_EML_FCN(1, 1);
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, 41);
          c2_d_encStr2Arr(chartInstance, c2_dv40);
          for (c2_i264 = 0; c2_i264 < 256; c2_i264++) {
            c2_poseSBM[c2_i264] = c2_dv40[c2_i264];
          }

          c2_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c2_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_idlePoseBradTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[22];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  boolean_T c2_aVarTruthTableCondition_3;
  boolean_T c2_aVarTruthTableCondition_4;
  boolean_T c2_aVarTruthTableCondition_5;
  boolean_T c2_aVarTruthTableCondition_6;
  boolean_T c2_aVarTruthTableCondition_7;
  boolean_T c2_aVarTruthTableCondition_8;
  boolean_T c2_aVarTruthTableCondition_9;
  boolean_T c2_aVarTruthTableCondition_10;
  boolean_T c2_aVarTruthTableCondition_11;
  boolean_T c2_aVarTruthTableCondition_12;
  boolean_T c2_aVarTruthTableCondition_13;
  boolean_T c2_aVarTruthTableCondition_14;
  boolean_T c2_aVarTruthTableCondition_15;
  boolean_T c2_aVarTruthTableCondition_16;
  boolean_T c2_aVarTruthTableCondition_17;
  boolean_T c2_aVarTruthTableCondition_18;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv42[256];
  int32_T c2_i265;
  int32_T c2_i266;
  int32_T c2_i267;
  int32_T c2_i268;
  int32_T c2_i269;
  int32_T c2_i270;
  int32_T c2_i271;
  int32_T c2_i272;
  int32_T c2_i273;
  int32_T c2_i274;
  int32_T c2_i275;
  int32_T c2_i276;
  int32_T c2_i277;
  int32_T c2_i278;
  int32_T c2_i279;
  int32_T c2_i280;
  int32_T c2_i281;
  int32_T c2_i282;
  int32_T c2_i283;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c2_m_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_3, 2U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_4, 3U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_5, 4U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_6, 5U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_7, 6U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_8, 7U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_9, 8U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_10, 9U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_11, 10U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_12, 11U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_13, 12U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_14, 13U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_15, 14U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_16, 15U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_17, 16U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_18, 17U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 18U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 19U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 20U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 5);
  c2_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 6);
  c2_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 7);
  c2_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 8);
  c2_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 9);
  c2_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 10);
  c2_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 11);
  c2_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 12);
  c2_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 13);
  c2_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 14);
  c2_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 15);
  c2_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 16);
  c2_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 17);
  c2_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 18);
  c2_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 19);
  c2_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 20);
  c2_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 24);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 27);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 30);
  c2_aVarTruthTableCondition_3 = (c2_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 33);
  c2_aVarTruthTableCondition_4 = (c2_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 36);
  c2_aVarTruthTableCondition_5 = (c2_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 39);
  c2_aVarTruthTableCondition_6 = (c2_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 42);
  c2_aVarTruthTableCondition_7 = (c2_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 45);
  c2_aVarTruthTableCondition_8 = (c2_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 48);
  c2_aVarTruthTableCondition_9 = (c2_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 51);
  c2_aVarTruthTableCondition_10 = (c2_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 54);
  c2_aVarTruthTableCondition_11 = (c2_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 57);
  c2_aVarTruthTableCondition_12 = (c2_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 60);
  c2_aVarTruthTableCondition_13 = (c2_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 63);
  c2_aVarTruthTableCondition_14 = (c2_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 66);
  c2_aVarTruthTableCondition_15 = (c2_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 69);
  c2_aVarTruthTableCondition_16 = (c2_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 72);
  c2_aVarTruthTableCondition_17 = (c2_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 75);
  c2_aVarTruthTableCondition_18 = (c2_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 77);
  if (CV_EML_IF(2, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 78);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 121);
    c2_g_encStr2Arr(chartInstance, c2_dv42);
    for (c2_i265 = 0; c2_i265 < 256; c2_i265++) {
      c2_poseBML[c2_i265] = c2_dv42[c2_i265];
    }

    c2_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -121);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 79);
    if (CV_EML_IF(2, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 80);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, MAX_int8_T);
      c2_h_encStr2Arr(chartInstance, c2_dv42);
      for (c2_i266 = 0; c2_i266 < 256; c2_i266++) {
        c2_poseBML[c2_i266] = c2_dv42[c2_i266];
      }

      c2_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -127);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 81);
      if (CV_EML_IF(2, 1, 2, c2_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 82);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 133U);
        c2_i_encStr2Arr(chartInstance, c2_dv42);
        for (c2_i267 = 0; c2_i267 < 256; c2_i267++) {
          c2_poseBML[c2_i267] = c2_dv42[c2_i267];
        }

        c2_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -133);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 83);
        if (CV_EML_IF(2, 1, 3, c2_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 84);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 139U);
          c2_j_encStr2Arr(chartInstance, c2_dv42);
          for (c2_i268 = 0; c2_i268 < 256; c2_i268++) {
            c2_poseBML[c2_i268] = c2_dv42[c2_i268];
          }

          c2_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -139);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 85);
          if (CV_EML_IF(2, 1, 4, c2_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 86);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 145U);
            c2_k_encStr2Arr(chartInstance, c2_dv42);
            for (c2_i269 = 0; c2_i269 < 256; c2_i269++) {
              c2_poseBML[c2_i269] = c2_dv42[c2_i269];
            }

            c2_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -145);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 87);
            if (CV_EML_IF(2, 1, 5, c2_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 88);
              CV_EML_FCN(2, 11);
              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 181U);
              c2_l_encStr2Arr(chartInstance, c2_dv42);
              for (c2_i270 = 0; c2_i270 < 256; c2_i270++) {
                c2_poseBML[c2_i270] = c2_dv42[c2_i270];
              }

              c2_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -181);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 89);
              if (CV_EML_IF(2, 1, 6, c2_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 90);
                CV_EML_FCN(2, 3);
                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 133U);
                c2_i_encStr2Arr(chartInstance, c2_dv42);
                for (c2_i271 = 0; c2_i271 < 256; c2_i271++) {
                  c2_poseBML[c2_i271] = c2_dv42[c2_i271];
                }

                c2_updateDataWrittenToVector(chartInstance, 11U);
                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -133);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 91);
                if (CV_EML_IF(2, 1, 7, c2_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 92);
                  CV_EML_FCN(2, 5);
                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 145U);
                  c2_k_encStr2Arr(chartInstance, c2_dv42);
                  for (c2_i272 = 0; c2_i272 < 256; c2_i272++) {
                    c2_poseBML[c2_i272] = c2_dv42[c2_i272];
                  }

                  c2_updateDataWrittenToVector(chartInstance, 11U);
                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 93);
                  if (CV_EML_IF(2, 1, 8, c2_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 94);
                    CV_EML_FCN(2, 3);
                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 133U);
                    c2_i_encStr2Arr(chartInstance, c2_dv42);
                    for (c2_i273 = 0; c2_i273 < 256; c2_i273++) {
                      c2_poseBML[c2_i273] = c2_dv42[c2_i273];
                    }

                    c2_updateDataWrittenToVector(chartInstance, 11U);
                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 95);
                    if (CV_EML_IF(2, 1, 9, c2_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 96);
                      CV_EML_FCN(2, 10);
                      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 175U);
                      c2_m_encStr2Arr(chartInstance, c2_dv42);
                      for (c2_i274 = 0; c2_i274 < 256; c2_i274++) {
                        c2_poseBML[c2_i274] = c2_dv42[c2_i274];
                      }

                      c2_updateDataWrittenToVector(chartInstance, 11U);
                      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 97);
                      if (CV_EML_IF(2, 1, 10, c2_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 98);
                        CV_EML_FCN(2, 11);
                        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 181U);
                        c2_l_encStr2Arr(chartInstance, c2_dv42);
                        for (c2_i275 = 0; c2_i275 < 256; c2_i275++) {
                          c2_poseBML[c2_i275] = c2_dv42[c2_i275];
                        }

                        c2_updateDataWrittenToVector(chartInstance, 11U);
                        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 99);
                        if (CV_EML_IF(2, 1, 11, c2_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 100);
                          CV_EML_FCN(2, 8);
                          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 163U);
                          c2_n_encStr2Arr(chartInstance, c2_dv42);
                          for (c2_i276 = 0; c2_i276 < 256; c2_i276++) {
                            c2_poseBML[c2_i276] = c2_dv42[c2_i276];
                          }

                          c2_updateDataWrittenToVector(chartInstance, 11U);
                          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 101);
                          if (CV_EML_IF(2, 1, 12, c2_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 102);
                            CV_EML_FCN(2, 8);
                            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 163U);
                            c2_n_encStr2Arr(chartInstance, c2_dv42);
                            for (c2_i277 = 0; c2_i277 < 256; c2_i277++) {
                              c2_poseBML[c2_i277] = c2_dv42[c2_i277];
                            }

                            c2_updateDataWrittenToVector(chartInstance, 11U);
                            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 103);
                            if (CV_EML_IF(2, 1, 13,
                                          c2_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 104);
                              CV_EML_FCN(2, 7);
                              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 157U);
                              c2_o_encStr2Arr(chartInstance, c2_dv42);
                              for (c2_i278 = 0; c2_i278 < 256; c2_i278++) {
                                c2_poseBML[c2_i278] = c2_dv42[c2_i278];
                              }

                              c2_updateDataWrittenToVector(chartInstance, 11U);
                              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 105);
                              if (CV_EML_IF(2, 1, 14,
                                            c2_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 106);
                                CV_EML_FCN(2, 6);
                                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                              151U);
                                c2_p_encStr2Arr(chartInstance, c2_dv42);
                                for (c2_i279 = 0; c2_i279 < 256; c2_i279++) {
                                  c2_poseBML[c2_i279] = c2_dv42[c2_i279];
                                }

                                c2_updateDataWrittenToVector(chartInstance, 11U);
                                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, 107);
                                if (CV_EML_IF(2, 1, 15,
                                              c2_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                108);
                                  CV_EML_FCN(2, 5);
                                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                145U);
                                  c2_k_encStr2Arr(chartInstance, c2_dv42);
                                  for (c2_i280 = 0; c2_i280 < 256; c2_i280++) {
                                    c2_poseBML[c2_i280] = c2_dv42[c2_i280];
                                  }

                                  c2_updateDataWrittenToVector(chartInstance,
                                    11U);
                                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                109);
                                  if (CV_EML_IF(2, 1, 16,
                                                c2_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                  110);
                                    CV_EML_FCN(2, 8);
                                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                  163U);
                                    c2_n_encStr2Arr(chartInstance, c2_dv42);
                                    for (c2_i281 = 0; c2_i281 < 256; c2_i281++)
                                    {
                                      c2_poseBML[c2_i281] = c2_dv42[c2_i281];
                                    }

                                    c2_updateDataWrittenToVector(chartInstance,
                                      11U);
                                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c2_sfEvent,
                                                  111);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c2_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
                                                    112);
                                      CV_EML_FCN(2, 9);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
                                                    169U);
                                      c2_q_encStr2Arr(chartInstance, c2_dv42);
                                      for (c2_i282 = 0; c2_i282 < 256; c2_i282++)
                                      {
                                        c2_poseBML[c2_i282] = c2_dv42[c2_i282];
                                      }

                                      c2_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
                                                    114);
                                      CV_EML_FCN(2, 3);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
                                                    133U);
                                      c2_i_encStr2Arr(chartInstance, c2_dv42);
                                      for (c2_i283 = 0; c2_i283 < 256; c2_i283++)
                                      {
                                        c2_poseBML[c2_i283] = c2_dv42[c2_i283];
                                      }

                                      c2_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c2_sfEvent,
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

  _SFD_EML_CALL(2U, chartInstance->c2_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_initialPoseTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[7];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  boolean_T c2_aVarTruthTableCondition_3;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv43[256];
  int32_T c2_i284;
  int32_T c2_i285;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[97];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[97];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_myarr256[256];
  int32_T c2_i286;
  static char_T c2_cv24[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c2_i287;
  static real_T c2_dv44[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c2_i288;
  int32_T c2_i289;
  int32_T c2_i290;
  int32_T c2_i291;
  int32_T c2_i292;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c2_y_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_3, 2U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 5);
  c2_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 9);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 12);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 15);
  c2_aVarTruthTableCondition_3 = (c2_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 17);
  if (CV_EML_IF(3, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 18);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 31);
    c2_r_encStr2Arr(chartInstance, c2_dv43);
    for (c2_i284 = 0; c2_i284 < 256; c2_i284++) {
      c2_poseBML[c2_i284] = c2_dv43[c2_i284];
    }

    c2_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, -31);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 19);
    if (CV_EML_IF(3, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 20);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 37);
      c2_s_encStr2Arr(chartInstance, c2_dv43);
      for (c2_i285 = 0; c2_i285 < 256; c2_i285++) {
        c2_poseBML[c2_i285] = c2_dv43[c2_i285];
      }

      c2_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, -37);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 21);
      if (CV_EML_IF(3, 1, 2, c2_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 22);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 43);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_cb_debug_family_names,
          c2_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_x_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
          c2_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_w_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U,
          c2_d_sf_marshallOut, c2_d_sf_marshallIn);
        for (c2_i286 = 0; c2_i286 < 97; c2_i286++) {
          c2_mystr[c2_i286] = c2_cv24[c2_i286];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
        c2_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
        for (c2_i287 = 0; c2_i287 < 97; c2_i287++) {
          c2_arr[c2_i287] = c2_dv44[c2_i287];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
        c2_ss = 97.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
        c2_padsize = c2_maxarrsize - c2_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
        for (c2_i288 = 0; c2_i288 < 256; c2_i288++) {
          c2_tt[c2_i288] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
        for (c2_i289 = 0; c2_i289 < 97; c2_i289++) {
          c2_tt[c2_i289] = c2_arr[c2_i289];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
        for (c2_i290 = 0; c2_i290 < 256; c2_i290++) {
          c2_myarr256[c2_i290] = c2_tt[c2_i290];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c2_i291 = 0; c2_i291 < 256; c2_i291++) {
          c2_poseBML[c2_i291] = c2_myarr256[c2_i291];
        }

        c2_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, -43);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 24);
        CV_EML_FCN(3, 1);
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, 31);
        c2_r_encStr2Arr(chartInstance, c2_dv43);
        for (c2_i292 = 0; c2_i292 < 256; c2_i292++) {
          c2_poseBML[c2_i292] = c2_dv43[c2_i292];
        }

        c2_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, -31);
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c2_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_successTablec2_lib_affectiveChar_scenario
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, real_T c2_bmlID,
   real_T c2_poseBML[256])
{
  uint32_T c2_debug_family_var_map[7];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  boolean_T c2_aVarTruthTableCondition_3;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_dv45[256];
  int32_T c2_i293;
  int32_T c2_i294;
  uint32_T c2_b_debug_family_var_map[9];
  real_T c2_maxarrsize;
  real_T c2_arr[183];
  real_T c2_ss;
  real_T c2_padsize;
  real_T c2_tt[256];
  char_T c2_mystr[183];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_myarr256[256];
  int32_T c2_i295;
  static char_T c2_cv25[183] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c2_i296;
  static real_T c2_dv46[183] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c2_i297;
  int32_T c2_i298;
  int32_T c2_i299;
  int32_T c2_i300;
  int32_T c2_i301;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c2_db_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_1, 0U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_2, 1U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aVarTruthTableCondition_3, 2U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bmlID, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_poseBML, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(31, 0);
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 3);
  c2_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 4);
  c2_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 5);
  c2_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 10);
  c2_aVarTruthTableCondition_1 = (c2_bmlID == 1.0);
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 14);
  c2_aVarTruthTableCondition_2 = (c2_bmlID == 2.0);
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 18);
  c2_aVarTruthTableCondition_3 = (c2_bmlID == 3.0);
  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 20);
  if (CV_EML_IF(31, 1, 0, c2_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 21);
    CV_EML_FCN(31, 1);
    _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 34);
    c2_t_encStr2Arr(chartInstance, c2_dv45);
    for (c2_i293 = 0; c2_i293 < 256; c2_i293++) {
      c2_poseBML[c2_i293] = c2_dv45[c2_i293];
    }

    c2_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, -34);
  } else {
    _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 22);
    if (CV_EML_IF(31, 1, 1, c2_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 23);
      CV_EML_FCN(31, 2);
      _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 40);
      c2_u_encStr2Arr(chartInstance, c2_dv45);
      for (c2_i294 = 0; c2_i294 < 256; c2_i294++) {
        c2_poseBML[c2_i294] = c2_dv45[c2_i294];
      }

      c2_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, -40);
    } else {
      _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 24);
      if (CV_EML_IF(31, 1, 2, c2_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 25);
        CV_EML_FCN(31, 3);
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_gb_debug_family_names,
          c2_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_maxarrsize, 0U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c2_arr, 1U, c2_ib_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ss, 2U, c2_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_padsize, 3U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_tt, 4U, c2_d_sf_marshallOut,
          c2_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c2_mystr, 5U, c2_hb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 6U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 7U,
          c2_b_sf_marshallOut, c2_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_myarr256, 8U,
          c2_d_sf_marshallOut, c2_d_sf_marshallIn);
        for (c2_i295 = 0; c2_i295 < 183; c2_i295++) {
          c2_mystr[c2_i295] = c2_cv25[c2_i295];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
        c2_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
        for (c2_i296 = 0; c2_i296 < 183; c2_i296++) {
          c2_arr[c2_i296] = c2_dv46[c2_i296];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 7);
        c2_ss = 183.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
        c2_padsize = c2_maxarrsize - c2_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
        for (c2_i297 = 0; c2_i297 < 256; c2_i297++) {
          c2_tt[c2_i297] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
        for (c2_i298 = 0; c2_i298 < 183; c2_i298++) {
          c2_tt[c2_i298] = c2_arr[c2_i298];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
        for (c2_i299 = 0; c2_i299 < 256; c2_i299++) {
          c2_myarr256[c2_i299] = c2_tt[c2_i299];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c2_i300 = 0; c2_i300 < 256; c2_i300++) {
          c2_poseBML[c2_i300] = c2_myarr256[c2_i300];
        }

        c2_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, -46);
      } else {
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 27);
        CV_EML_FCN(31, 1);
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, 34);
        c2_t_encStr2Arr(chartInstance, c2_dv45);
        for (c2_i301 = 0; c2_i301 < 256; c2_i301++) {
          c2_poseBML[c2_i301] = c2_dv45[c2_i301];
        }

        c2_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(31U, chartInstance->c2_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_sendSBM(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c2_b_sendSBM(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c2_sendBML(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void c2_b_sendBML(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_handPoseSBTable(SimStruct
  *c2_S, real_T c2_sbmID, real_T c2_poseSBM[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_handPoseSBTablec2_lib_affectiveChar_scenario(chartInstance, c2_sbmID,
    c2_poseSBM);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_idlePoseBradTable(SimStruct *
  c2_S, real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_idlePoseBradTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_initialPoseTable(SimStruct
  *c2_S, real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_initialPoseTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_paperPoseBradTable(SimStruct
  *c2_S, real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_paperPoseBradTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_rockPoseTable(SimStruct
  *c2_S, real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_rockPoseTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_scissorsPoseBradTable
  (SimStruct *c2_S, real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_scissorsPoseBradTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_sendBML(SimStruct *c2_S,
  real_T c2_arg[256])
{
  int32_T c2_i302;
  real_T c2_b_arg[256];
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  for (c2_i302 = 0; c2_i302 < 256; c2_i302++) {
    c2_b_arg[c2_i302] = c2_arg[c2_i302];
  }

  c2_sendBMLc2_lib_affectiveChar_scenario(chartInstance, c2_b_arg);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_sendSBM(SimStruct *c2_S,
  real_T c2_arg[256])
{
  int32_T c2_i303;
  real_T c2_b_arg[256];
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  for (c2_i303 = 0; c2_i303 < 256; c2_i303++) {
    c2_b_arg[c2_i303] = c2_arg[c2_i303];
  }

  c2_sendSBMc2_lib_affectiveChar_scenario(chartInstance, c2_b_arg);
}

void sf_exported_user_c2_lib_affectiveChar_scenario_successTable(SimStruct *c2_S,
  real_T c2_bmlID, real_T c2_poseBML[256])
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c2_S))->instanceInfo
    )->chartInstance;
  c2_successTablec2_lib_affectiveChar_scenario(chartInstance, c2_bmlID,
    c2_poseBML);
}

static const mxArray *c2_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int8_T c2_f_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int8_T c2_y;
  int8_T c2_i304;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i304, 1, 2, 0U, 0, 0U, 0);
  c2_y = c2_i304;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_secs;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_secs = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_secs), &c2_thisId);
  sf_mex_destroy(&c2_secs);
  *(int8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_g_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i305;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i305, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i305;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_stateStart, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_stateStart),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_stateStart);
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u3, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_stateStart;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
    chartInstanceVoid;
  c2_b_tp_stateStart = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_stateStart),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_stateStart);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_j_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_method, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_method),
    &c2_thisId);
  sf_mex_destroy(&c2_b_method);
  return c2_y;
}

static uint32_T c2_k_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u4;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_method_not_empty = false;
  } else {
    chartInstance->c2_method_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u4, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u4;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint32_T c2_l_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_d_state, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId);
  sf_mex_destroy(&c2_d_state);
  return c2_y;
}

static uint32_T c2_m_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u5;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_state_not_empty = false;
  } else {
    chartInstance->c2_state_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u5, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u5;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_n_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier,
  uint32_T c2_y[625])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_o_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[625])
{
  uint32_T c2_uv3[625];
  int32_T c2_i306;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_c_state_not_empty = false;
  } else {
    chartInstance->c2_c_state_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c2_i306 = 0; c2_i306 < 625; c2_i306++) {
      c2_y[c2_i306] = c2_uv3[c2_i306];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_p_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier,
  uint32_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_q_emlrt_marshallIn(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint32_T c2_y[2])
{
  uint32_T c2_uv4[2];
  int32_T c2_i307;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_b_state_not_empty = false;
  } else {
    chartInstance->c2_b_state_not_empty = true;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c2_i307 = 0; c2_i307 < 2; c2_i307++) {
      c2_y[c2_i307] = c2_uv4[c2_i307];
    }
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_r_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_s_emlrt_marshallIn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_updateDataWrittenToVector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_vectorIndex)
{
  (void)chartInstance;
  c2_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c2_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c2_errorIfDataNotWrittenToFcn
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_vectorIndex, uint32_T c2_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c2_dataNumber, c2_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c2_vectorIndex, 0, 13, 1,
    0)]);
}

static void c2_b_twister_state_vector
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_mt
   [625], real_T c2_seed)
{
  real_T c2_d5;
  uint32_T c2_u6;
  uint32_T c2_r;
  int32_T c2_mti;
  real_T c2_b_mti;
  real_T c2_d6;
  uint32_T c2_u7;
  (void)chartInstance;
  c2_d5 = c2_seed;
  if (c2_d5 < 4.294967296E+9) {
    if (c2_d5 >= 0.0) {
      c2_u6 = (uint32_T)c2_d5;
    } else {
      c2_u6 = 0U;
    }
  } else if (c2_d5 >= 4.294967296E+9) {
    c2_u6 = MAX_uint32_T;
  } else {
    c2_u6 = 0U;
  }

  c2_r = c2_u6;
  c2_mt[0] = c2_r;
  for (c2_mti = 0; c2_mti < 623; c2_mti++) {
    c2_b_mti = 2.0 + (real_T)c2_mti;
    c2_d6 = muDoubleScalarRound(c2_b_mti - 1.0);
    if (c2_d6 < 4.294967296E+9) {
      if (c2_d6 >= 0.0) {
        c2_u7 = (uint32_T)c2_d6;
      } else {
        c2_u7 = 0U;
      }
    } else if (c2_d6 >= 4.294967296E+9) {
      c2_u7 = MAX_uint32_T;
    } else {
      c2_u7 = 0U;
    }

    c2_r = (c2_r ^ c2_r >> 30U) * 1812433253U + c2_u7;
    c2_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_mti), 1, 625, 1, 0) - 1] = c2_r;
  }

  c2_mt[624] = 624U;
}

static real_T c2_c_eml_rand_mt19937ar
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T
   c2_d_state[625])
{
  int32_T c2_i308;
  uint32_T c2_u[2];
  int32_T c2_j;
  real_T c2_b_j;
  uint32_T c2_mti;
  int32_T c2_kk;
  real_T c2_b_kk;
  uint32_T c2_y;
  uint32_T c2_b_y;
  uint32_T c2_c_y;
  int32_T c2_c_kk;
  uint32_T c2_d_y;
  uint32_T c2_e_y;
  uint32_T c2_f_y;
  uint32_T c2_g_y;
  real_T c2_b_r;
  boolean_T c2_b1;
  boolean_T c2_isvalid;
  int32_T c2_k;
  int32_T c2_a;
  int32_T c2_b_a;
  real_T c2_d7;
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
    for (c2_i308 = 0; c2_i308 < 2; c2_i308++) {
      c2_u[c2_i308] = 0U;
    }

    for (c2_j = 0; c2_j < 2; c2_j++) {
      c2_b_j = 1.0 + (real_T)c2_j;
      c2_mti = c2_d_state[624] + 1U;
      if ((real_T)c2_mti >= 625.0) {
        for (c2_kk = 0; c2_kk < 227; c2_kk++) {
          c2_b_kk = 1.0 + (real_T)c2_kk;
          c2_y = (c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c2_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c2_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c2_b_y = c2_y;
          c2_c_y = c2_b_y;
          if ((real_T)(c2_c_y & 1U) == 0.0) {
            c2_c_y >>= 1U;
          } else {
            c2_c_y = c2_c_y >> 1U ^ 2567483615U;
          }

          c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c2_b_kk), 1, 625, 1, 0) - 1] =
            c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c2_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c2_c_y;
        }

        for (c2_c_kk = 0; c2_c_kk < 396; c2_c_kk++) {
          c2_b_kk = 228.0 + (real_T)c2_c_kk;
          c2_y = (c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c2_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c2_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c2_d_y = c2_y;
          c2_e_y = c2_d_y;
          if ((real_T)(c2_e_y & 1U) == 0.0) {
            c2_e_y >>= 1U;
          } else {
            c2_e_y = c2_e_y >> 1U ^ 2567483615U;
          }

          c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c2_b_kk), 1, 625, 1, 0) - 1] =
            c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c2_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c2_e_y;
        }

        c2_y = (c2_d_state[623] & 2147483648U) | (c2_d_state[0] & 2147483647U);
        c2_f_y = c2_y;
        c2_g_y = c2_f_y;
        if ((real_T)(c2_g_y & 1U) == 0.0) {
          c2_g_y >>= 1U;
        } else {
          c2_g_y = c2_g_y >> 1U ^ 2567483615U;
        }

        c2_d_state[623] = c2_d_state[396] ^ c2_g_y;
        c2_mti = 1U;
      }

      c2_y = c2_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mti), 1, 625, 1, 0)
        - 1];
      c2_d_state[624] = c2_mti;
      c2_y ^= c2_y >> 11U;
      c2_y ^= c2_y << 7U & 2636928640U;
      c2_y ^= c2_y << 15U & 4022730752U;
      c2_y ^= c2_y >> 18U;
      c2_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_j), 1, 2, 1, 0) - 1] = c2_y;
    }

    c2_u[0] >>= 5U;
    c2_u[1] >>= 6U;
    c2_b_r = 1.1102230246251565E-16 * ((real_T)c2_u[0] * 6.7108864E+7 + (real_T)
      c2_u[1]);
    if (c2_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c2_d_state[624] >= 1.0) {
        if ((real_T)c2_d_state[624] < 625.0) {
          c2_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c2_b1 = false;
      }

      c2_isvalid = c2_b1;
      if (c2_isvalid) {
        c2_isvalid = false;
        c2_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c2_k < 625)) {
          if ((real_T)c2_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c2_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c2_a = c2_k;
            c2_b_a = c2_a + 1;
            c2_k = c2_b_a;
          } else {
            c2_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c2_isvalid) {
        c2_eml_error(chartInstance);
        c2_d7 = 5489.0;
        c2_b_twister_state_vector(chartInstance, c2_d_state, c2_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_b_r;
}

static real_T c2_get_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#700) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_BOREDOM_THRESHOLD_address;
}

static void c2_set_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b,
   real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#700) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_BOREDOM_THRESHOLD_address = c2_c;
}

static real_T *c2_access_BOREDOM_THRESHOLD
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c2_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#700) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_BOREDOM_THRESHOLD_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c2_c;
}

static real_T c2_get_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c2_b);
  if (chartInstance->c2_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#709) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_avert_address;
}

static void c2_set_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c2_b);
  if (chartInstance->c2_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#709) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_avert_address = c2_c;
}

static real_T *c2_access_avert(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c2_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#709) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_avert_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c2_c;
}

static real_T c2_get_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c2_b);
  if (chartInstance->c2_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#694) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_bHand_address;
}

static void c2_set_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c2_b);
  if (chartInstance->c2_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#694) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_bHand_address = c2_c;
}

static real_T *c2_access_bHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c2_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#694) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_bHand_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c2_c;
}

static real_T c2_get_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c2_b);
  if (chartInstance->c2_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#699) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_boredom_address;
}

static void c2_set_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c2_b);
  if (chartInstance->c2_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#699) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_boredom_address = c2_c;
}

static real_T *c2_access_boredom(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c2_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#699) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_boredom_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c2_c;
}

static real_T c2_get_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c2_b);
  if (chartInstance->c2_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#692) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_diff_address;
}

static void c2_set_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c2_b);
  if (chartInstance->c2_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#692) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_diff_address = c2_c;
}

static real_T *c2_access_diff(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c2_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#692) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_diff_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c2_c;
}

static real_T c2_get_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c2_b);
  if (chartInstance->c2_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#703) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_isPosing_address;
}

static void c2_set_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c2_b);
  if (chartInstance->c2_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#703) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_isPosing_address = c2_c;
}

static real_T *c2_access_isPosing(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c2_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#703) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_isPosing_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c2_c;
}

static real_T c2_get_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c2_b);
  if (chartInstance->c2_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#705) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_p_address;
}

static void c2_set_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c2_b);
  if (chartInstance->c2_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#705) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_p_address = c2_c;
}

static real_T *c2_access_p(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c2_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#705) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_p_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c2_c;
}

static real_T c2_get_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c2_b);
  if (chartInstance->c2_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#704) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_r_address;
}

static void c2_set_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c2_b);
  if (chartInstance->c2_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#704) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_r_address = c2_c;
}

static real_T *c2_access_r(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c2_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#704) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_r_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c2_c;
}

static real_T c2_get_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c2_b);
  if (chartInstance->c2_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#701) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_randAvertGazeChance_address;
}

static void c2_set_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b,
   real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c2_b);
  if (chartInstance->c2_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#701) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_randAvertGazeChance_address = c2_c;
}

static real_T *c2_access_randAvertGazeChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c2_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#701) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_randAvertGazeChance_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c2_c;
}

static real_T c2_get_randPoseChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c2_b);
  if (chartInstance->c2_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#702) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_randPoseChance_address;
}

static void c2_set_randPoseChance(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c2_b);
  if (chartInstance->c2_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#702) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_randPoseChance_address = c2_c;
}

static real_T *c2_access_randPoseChance
  (SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c2_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#702) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_randPoseChance_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c2_c;
}

static real_T c2_get_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c2_b);
  if (chartInstance->c2_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#698) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_randSmile_address;
}

static void c2_set_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c2_b);
  if (chartInstance->c2_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#698) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_randSmile_address = c2_c;
}

static real_T *c2_access_randSmile(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c2_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#698) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_randSmile_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c2_c;
}

static real_T c2_get_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c2_b);
  if (chartInstance->c2_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#706) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_s_address;
}

static void c2_set_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
                     *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c2_b);
  if (chartInstance->c2_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#706) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_s_address = c2_c;
}

static real_T *c2_access_s(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c2_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#706) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_s_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c2_c;
}

static real_T c2_get_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c2_b);
  if (chartInstance->c2_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#697) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_smileN_address;
}

static void c2_set_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c2_b);
  if (chartInstance->c2_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#697) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_smileN_address = c2_c;
}

static real_T *c2_access_smileN(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c2_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#697) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_smileN_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c2_c;
}

static real_T c2_get_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c2_b);
  if (chartInstance->c2_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#691) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_temp_address;
}

static void c2_set_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c2_b);
  if (chartInstance->c2_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#691) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_temp_address = c2_c;
}

static real_T *c2_access_temp(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c2_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#691) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_temp_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c2_c;
}

static real_T c2_get_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c2_b);
  if (chartInstance->c2_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#693) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_uHand_address;
}

static void c2_set_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c2_b);
  if (chartInstance->c2_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#693) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_uHand_address = c2_c;
}

static real_T *c2_access_uHand(SFc2_lib_affectiveChar_scenarioInstanceStruct
  *chartInstance, uint32_T c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c2_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#693) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_uHand_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c2_c;
}

static void init_dsm_address_info(SFc2_lib_affectiveChar_scenarioInstanceStruct *
  chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c2_BOREDOM_THRESHOLD_address,
    &chartInstance->c2_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c2_avert_address, &chartInstance->c2_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c2_bHand_address, &chartInstance->c2_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c2_boredom_address, &chartInstance->c2_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c2_diff_address, &chartInstance->c2_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c2_isPosing_address, &chartInstance->c2_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c2_p_address, &chartInstance->c2_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c2_r_address, &chartInstance->c2_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c2_randAvertGazeChance_address,
    &chartInstance->c2_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c2_randPoseChance_address,
    &chartInstance->c2_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSmile", (void **)
    &chartInstance->c2_randSmile_address, &chartInstance->c2_randSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c2_s_address, &chartInstance->c2_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileN", (void **)
    &chartInstance->c2_smileN_address, &chartInstance->c2_smileN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c2_temp_address, &chartInstance->c2_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c2_uHand_address, &chartInstance->c2_uHand_index);
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

void sf_c2_lib_affectiveChar_scenario_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1343578699U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2222478760U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(77959233U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2295658496U);
}

mxArray *sf_c2_lib_affectiveChar_scenario_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("UfeDp1PGfpTyYuiUvTpCZB");
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

mxArray *sf_c2_lib_affectiveChar_scenario_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_lib_affectiveChar_scenario_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_lib_affectiveChar_scenario(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"bWinT\",},{M[1],M[86],T\"bradHand\",},{M[1],M[84],T\"gameState\",},{M[1],M[106],T\"round\",},{M[1],M[94],T\"uWinT\",},{M[1],M[87],T\"userHand\",},{M[1],M[88],T\"win\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c2_lib_affectiveChar_scenario\",},{M[9],M[0],T\"is_c2_lib_affectiveChar_scenario\",},{M[11],M[107],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x13[54 55 83 59 58 62 61 64 67 69 71 78 77],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_lib_affectiveChar_scenario_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _lib_affectiveChar_scenarioMachineNumber_,
           2,
           32,
           35,
           0,
           40,
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
          _SFD_SET_DATA_PROPS(11,11,0,0,"smileN");
          _SFD_SET_DATA_PROPS(12,11,0,0,"randSmile");
          _SFD_SET_DATA_PROPS(13,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(14,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(15,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(16,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(17,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(18,11,0,0,"r");
          _SFD_SET_DATA_PROPS(19,11,0,0,"p");
          _SFD_SET_DATA_PROPS(20,11,0,0,"s");
          _SFD_SET_DATA_PROPS(21,2,0,1,"round");
          _SFD_SET_DATA_PROPS(22,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(23,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
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
          _SFD_SET_DATA_PROPS(38,8,0,0,"");
          _SFD_SET_DATA_PROPS(39,9,0,0,"");
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
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"rockPoseTablec2_lib_affectiveChar_scenario",0,
                             -1,401);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",401,-1,563);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",563,-1,725);
        _SFD_CV_INIT_EML_IF(5,1,0,225,255,286,399);
        _SFD_CV_INIT_EML_IF(5,1,1,286,320,351,399);
        _SFD_CV_INIT_EML(4,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,
                             "paperPoseBradTablec2_lib_affectiveChar_scenario",0,
                             -1,409);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",409,-1,566);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",566,-1,721);
        _SFD_CV_INIT_EML_IF(4,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(4,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(6,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,
                             "scissorsPoseBradTablec2_lib_affectiveChar_scenario",
                             0,-1,418);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",418,-1,576);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",576,-1,736);
        _SFD_CV_INIT_EML_IF(6,1,0,242,272,303,416);
        _SFD_CV_INIT_EML_IF(6,1,1,303,337,368,416);
        _SFD_CV_INIT_EML(1,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"handPoseSBTablec2_lib_affectiveChar_scenario",
                             0,-1,759);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",759,-1,996);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",996,-1,1231);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1231,-1,1403);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1403,-1,1571);
        _SFD_CV_INIT_EML_IF(1,1,0,453,483,514,757);
        _SFD_CV_INIT_EML_IF(1,1,1,514,548,579,757);
        _SFD_CV_INIT_EML_IF(1,1,2,579,613,644,757);
        _SFD_CV_INIT_EML_IF(1,1,3,644,678,709,757);
        _SFD_CV_INIT_EML(2,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,
                             "idlePoseBradTablec2_lib_affectiveChar_scenario",0,
                             -1,2812);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",2812,-1,2984);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",2984,-1,3147);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",3147,-1,3315);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",3315,-1,3485);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",3485,-1,3655);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",3655,-1,3837);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",3837,-1,4017);
        _SFD_CV_INIT_EML_FCN(2,8,"aFcnTruthTableAction_8",4017,-1,4187);
        _SFD_CV_INIT_EML_FCN(2,9,"aFcnTruthTableAction_9",4187,-1,4355);
        _SFD_CV_INIT_EML_FCN(2,10,"aFcnTruthTableAction_10",4355,-1,4525);
        _SFD_CV_INIT_EML_FCN(2,11,"aFcnTruthTableAction_11",4525,-1,4692);
        _SFD_CV_INIT_EML_IF(2,1,0,1584,1614,1645,2810);
        _SFD_CV_INIT_EML_IF(2,1,1,1645,1679,1710,2810);
        _SFD_CV_INIT_EML_IF(2,1,2,1710,1744,1775,2810);
        _SFD_CV_INIT_EML_IF(2,1,3,1775,1809,1840,2810);
        _SFD_CV_INIT_EML_IF(2,1,4,1840,1874,1905,2810);
        _SFD_CV_INIT_EML_IF(2,1,5,1905,1939,1971,2810);
        _SFD_CV_INIT_EML_IF(2,1,6,1971,2005,2036,2810);
        _SFD_CV_INIT_EML_IF(2,1,7,2036,2070,2101,2810);
        _SFD_CV_INIT_EML_IF(2,1,8,2101,2135,2166,2810);
        _SFD_CV_INIT_EML_IF(2,1,9,2166,2201,2233,2810);
        _SFD_CV_INIT_EML_IF(2,1,10,2233,2268,2300,2810);
        _SFD_CV_INIT_EML_IF(2,1,11,2300,2335,2366,2810);
        _SFD_CV_INIT_EML_IF(2,1,12,2366,2401,2432,2810);
        _SFD_CV_INIT_EML_IF(2,1,13,2432,2467,2498,2810);
        _SFD_CV_INIT_EML_IF(2,1,14,2498,2533,2564,2810);
        _SFD_CV_INIT_EML_IF(2,1,15,2564,2599,2630,2810);
        _SFD_CV_INIT_EML_IF(2,1,16,2630,2665,2696,2810);
        _SFD_CV_INIT_EML_IF(2,1,17,2696,2731,2762,2810);
        _SFD_CV_INIT_EML(3,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"initialPoseTablec2_lib_affectiveChar_scenario",
                             0,-1,537);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",537,-1,682);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",682,-1,848);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",848,-1,1013);
        _SFD_CV_INIT_EML_IF(3,1,0,296,326,357,535);
        _SFD_CV_INIT_EML_IF(3,1,1,357,391,422,535);
        _SFD_CV_INIT_EML_IF(3,1,2,422,456,487,535);
        _SFD_CV_INIT_EML(31,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(31,0,"successTablec2_lib_affectiveChar_scenario",0,
                             -1,566);
        _SFD_CV_INIT_EML_FCN(31,1,"aFcnTruthTableAction_1",566,-1,858);
        _SFD_CV_INIT_EML_FCN(31,2,"aFcnTruthTableAction_2",858,-1,1075);
        _SFD_CV_INIT_EML_FCN(31,3,"aFcnTruthTableAction_3",1075,-1,1327);
        _SFD_CV_INIT_EML_IF(31,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(31,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(31,1,2,451,485,516,564);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,0,41,0,41);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 41 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,0,41,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,0,23,0,23);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,0,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

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
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,9,1,9);
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

        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(23,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(23,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(30,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(30,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

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
        _SFD_SET_DATA_VALUE_PTR(38,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(39,(void *)(NULL));

        {
          real_T *c2_gameState;
          real_T *c2_inputUser;
          real_T *c2_bradHand;
          real_T *c2_userHand;
          real_T *c2_win;
          real_T *c2_bWinT;
          real_T *c2_uWinT;
          real_T *c2_round;
          real_T *c2_isSmiling;
          c2_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c2_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c2_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c2_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c2_smileN_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c2_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c2_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c2_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(15U,
            chartInstance->c2_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c2_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c2_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c2_r_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c2_p_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c2_s_address);
          _SFD_SET_DATA_VALUE_PTR(21U, c2_round);
          _SFD_SET_DATA_VALUE_PTR(22U, c2_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c2_avert_address);
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
  return "PIEeC7k6R43l0w8KotvPZH";
}

static void sf_opaque_initialize_c2_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_lib_affectiveChar_scenarioInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
  initialize_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  enable_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  disable_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  sf_gateway_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_lib_affectiveChar_scenario
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_lib_affectiveChar_scenario();/* state var info */
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

extern void sf_internal_set_sim_state_c2_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_lib_affectiveChar_scenario();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_lib_affectiveChar_scenario
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c2_lib_affectiveChar_scenario(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c2_lib_affectiveChar_scenario(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_lib_affectiveChar_scenarioInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_lib_affectiveChar_scenario_optimization_info();
    }

    finalize_c2_lib_affectiveChar_scenario
      ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_lib_affectiveChar_scenario
    ((SFc2_lib_affectiveChar_scenarioInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_lib_affectiveChar_scenario(SimStruct *S)
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
    initialize_params_c2_lib_affectiveChar_scenario
      ((SFc2_lib_affectiveChar_scenarioInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_lib_affectiveChar_scenario_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,2,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3024115829U));
  ssSetChecksum1(S,(2597622014U));
  ssSetChecksum2(S,(1327227783U));
  ssSetChecksum3(S,(2287197474U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_lib_affectiveChar_scenario(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_lib_affectiveChar_scenario(SimStruct *S)
{
  SFc2_lib_affectiveChar_scenarioInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_lib_affectiveChar_scenarioInstanceStruct *)utMalloc
    (sizeof(SFc2_lib_affectiveChar_scenarioInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_lib_affectiveChar_scenarioInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_lib_affectiveChar_scenario;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_lib_affectiveChar_scenario;
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

void c2_lib_affectiveChar_scenario_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_lib_affectiveChar_scenario(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_lib_affectiveChar_scenario(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_lib_affectiveChar_scenario_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
