/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sfun.h"
#include "c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c8_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c8_IN_gameOver                 ((uint8_T)1U)
#define c8_IN_stateBoredPose1          ((uint8_T)2U)
#define c8_IN_stateBradWin             ((uint8_T)3U)
#define c8_IN_stateBrowUp              ((uint8_T)4U)
#define c8_IN_stateCompare             ((uint8_T)5U)
#define c8_IN_stateGo                  ((uint8_T)6U)
#define c8_IN_stateHeadNeutral2        ((uint8_T)7U)
#define c8_IN_stateIfSmile             ((uint8_T)8U)
#define c8_IN_stateLeanBack            ((uint8_T)9U)
#define c8_IN_stateNoWin               ((uint8_T)10U)
#define c8_IN_statePoseFingersCLose    ((uint8_T)11U)
#define c8_IN_statePosePaper           ((uint8_T)12U)
#define c8_IN_statePoseReady           ((uint8_T)13U)
#define c8_IN_statePoseReturnFinger    ((uint8_T)14U)
#define c8_IN_statePoseRock            ((uint8_T)15U)
#define c8_IN_statePoseScissors        ((uint8_T)16U)
#define c8_IN_statePoseSmile           ((uint8_T)17U)
#define c8_IN_statePoseSmileWin        ((uint8_T)18U)
#define c8_IN_stateRandom1             ((uint8_T)19U)
#define c8_IN_stateRandomHand          ((uint8_T)20U)
#define c8_IN_stateReadUserHand        ((uint8_T)21U)
#define c8_IN_stateReady               ((uint8_T)22U)
#define c8_IN_stateShowHands           ((uint8_T)23U)
#define c8_IN_stateShowResult          ((uint8_T)24U)
#define c8_IN_stateSmile               ((uint8_T)25U)
#define c8_IN_stateStart               ((uint8_T)26U)
#define c8_IN_stateUserWin             ((uint8_T)27U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c8_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c8_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_g_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c8_h_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c8_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_m_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c8_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_y_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c8_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_db_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c8_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c8_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_fc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_gc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_hc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_oc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c8_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c8_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c8_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void initialize_params_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void enable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void disable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_update_debugger_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotIm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_st);
static void c8_set_sim_state_side_effects_c8_ARP_02_RPSsmile_GloveAtomicBrad
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void finalize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void sf_gateway_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_enter_atomic_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_enter_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_exit_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_initc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void initSimStructsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_enter_atomic_stateReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_gameOver
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateHeadNeutral2
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateIfSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_enter_atomic_stateGo
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateGo
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateLeanBack
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateRandomHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseFingersCLose
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePosePaper
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseRock
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseScissors
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateReadUserHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_enter_atomic_stateShowHands
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateShowHands
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseReturnFinger
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateCompare
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateBradWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateNoWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_stateRandom1
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_statePoseSmileWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_b_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_c_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_d_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_e_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_f_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_g_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_h_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_i_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_j_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_k_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_l_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_m_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_n_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_o_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_p_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_q_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_r_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_s_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_t_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static void c8_u_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256]);
static real_T c8_randi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_lowhigh[2]);
static real_T c8_rand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static real_T c8_eml_rand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625]);
static void c8_twister_state_vector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_mt[625], real_T c8_seed, uint32_T c8_b_mt[625]);
static void c8_b_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625], uint32_T c8_e_state[625], real_T
   *c8_r);
static void c8_eml_error
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static real_T c8_b_randi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   real_T c8_y[256]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_b_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_bmlID, const char_T *c8_identifier);
static real_T c8_c_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   real_T c8_y[256]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_p_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_q_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_r_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_v_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_w_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_x_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_y_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_db_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_activate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_deactivate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_increment_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotI
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_reset_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImita
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_arg[256]);
static void c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_arg[256]);
static void c8_rockPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_paperPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitat
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_scissorsPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_sbmID, real_T c8_poseSBM[256]);
static void c8_idlePoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitate
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256]);
static void c8_sendSBM
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_b_sendSBM
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_sendBML
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static void c8_b_sendBML
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);
static const mxArray *c8_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int8_T c8_f_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_g_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_h_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_tp_stateStart, const char_T
   *c8_identifier);
static uint8_T c8_i_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint32_T c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_method, const char_T *c8_identifier);
static uint32_T c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static uint32_T c8_l_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier);
static uint32_T c8_m_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_n_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier,
   uint32_T c8_y[625]);
static void c8_o_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   uint32_T c8_y[625]);
static void c8_p_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier,
   uint32_T c8_y[2]);
static void c8_q_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   uint32_T c8_y[2]);
static const mxArray *c8_r_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T *
   c8_identifier);
static const mxArray *c8_s_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_vectorIndex);
static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_vectorIndex, uint32_T c8_dataNumber);
static void c8_b_twister_state_vector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_mt[625], real_T c8_seed);
static real_T c8_c_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625]);
static real_T c8_get_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static real_T c8_get_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void c8_set_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c);
static real_T *c8_access_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b);
static void init_dsm_address_info
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void disable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_update_debugger_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotIm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c8_is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
      == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateIfSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateLeanBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseRock) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateRandom1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_statePoseSmileWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
      c8_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
  }

  _SFD_SET_ANIMATION(c8_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray
  *get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  real_T c8_b_hoistedGlobal;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_hoistedGlobal;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_d_hoistedGlobal;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_e_hoistedGlobal;
  real_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_f_hoistedGlobal;
  real_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  real_T c8_g_hoistedGlobal;
  real_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  uint32_T c8_h_hoistedGlobal;
  uint32_T c8_h_u;
  const mxArray *c8_i_y = NULL;
  uint32_T c8_i_hoistedGlobal;
  uint32_T c8_i_u;
  const mxArray *c8_j_y = NULL;
  int32_T c8_i0;
  uint32_T c8_j_u[625];
  const mxArray *c8_k_y = NULL;
  int32_T c8_i1;
  uint32_T c8_k_u[2];
  const mxArray *c8_l_y = NULL;
  uint8_T c8_j_hoistedGlobal;
  uint8_T c8_l_u;
  const mxArray *c8_m_y = NULL;
  uint8_T c8_k_hoistedGlobal;
  uint8_T c8_m_u;
  const mxArray *c8_n_y = NULL;
  uint8_T c8_l_hoistedGlobal;
  uint8_T c8_n_u;
  const mxArray *c8_o_y = NULL;
  real_T *c8_bWinT;
  real_T *c8_bradHand;
  real_T *c8_gameState;
  real_T *c8_round;
  real_T *c8_uWinT;
  real_T *c8_userHand;
  real_T *c8_win;
  c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(14, 1), false);
  c8_hoistedGlobal = *c8_bWinT;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_bradHand;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_gameState;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_round;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal = *c8_uWinT;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_hoistedGlobal = *c8_userHand;
  c8_f_u = c8_f_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_g_hoistedGlobal = *c8_win;
  c8_g_u = c8_g_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  c8_h_hoistedGlobal = chartInstance->c8_method;
  c8_h_u = c8_h_hoistedGlobal;
  c8_i_y = NULL;
  if (!chartInstance->c8_method_not_empty) {
    sf_mex_assign(&c8_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_h_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c8_y, 7, c8_i_y);
  c8_i_hoistedGlobal = chartInstance->c8_state;
  c8_i_u = c8_i_hoistedGlobal;
  c8_j_y = NULL;
  if (!chartInstance->c8_state_not_empty) {
    sf_mex_assign(&c8_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c8_j_y, sf_mex_create("y", &c8_i_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c8_y, 8, c8_j_y);
  for (c8_i0 = 0; c8_i0 < 625; c8_i0++) {
    c8_j_u[c8_i0] = chartInstance->c8_c_state[c8_i0];
  }

  c8_k_y = NULL;
  if (!chartInstance->c8_c_state_not_empty) {
    sf_mex_assign(&c8_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c8_k_y, sf_mex_create("y", c8_j_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c8_y, 9, c8_k_y);
  for (c8_i1 = 0; c8_i1 < 2; c8_i1++) {
    c8_k_u[c8_i1] = chartInstance->c8_b_state[c8_i1];
  }

  c8_l_y = NULL;
  if (!chartInstance->c8_b_state_not_empty) {
    sf_mex_assign(&c8_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c8_l_y, sf_mex_create("y", c8_k_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c8_y, 10, c8_l_y);
  c8_j_hoistedGlobal =
    chartInstance->c8_is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  c8_l_u = c8_j_hoistedGlobal;
  c8_m_y = NULL;
  sf_mex_assign(&c8_m_y, sf_mex_create("y", &c8_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 11, c8_m_y);
  c8_k_hoistedGlobal =
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  c8_m_u = c8_k_hoistedGlobal;
  c8_n_y = NULL;
  sf_mex_assign(&c8_n_y, sf_mex_create("y", &c8_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 12, c8_n_y);
  c8_l_hoistedGlobal = chartInstance->c8_temporalCounter_i1;
  c8_n_u = c8_l_hoistedGlobal;
  c8_o_y = NULL;
  sf_mex_assign(&c8_o_y, sf_mex_create("y", &c8_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 13, c8_o_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  uint32_T c8_uv0[625];
  int32_T c8_i2;
  uint32_T c8_uv1[2];
  int32_T c8_i3;
  real_T *c8_bWinT;
  real_T *c8_bradHand;
  real_T *c8_gameState;
  real_T *c8_round;
  real_T *c8_uWinT;
  real_T *c8_userHand;
  real_T *c8_win;
  c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  *c8_bWinT = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 0)), "bWinT");
  *c8_bradHand = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 1)), "bradHand");
  *c8_gameState = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 2)), "gameState");
  *c8_round = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 3)), "round");
  *c8_uWinT = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 4)), "uWinT");
  *c8_userHand = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 5)), "userHand");
  *c8_win = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    6)), "win");
  chartInstance->c8_method = c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 7)), "method");
  chartInstance->c8_state = c8_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 8)), "state");
  c8_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 9)),
                        "state", c8_uv0);
  for (c8_i2 = 0; c8_i2 < 625; c8_i2++) {
    chartInstance->c8_c_state[c8_i2] = c8_uv0[c8_i2];
  }

  c8_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 10)),
                        "state", c8_uv1);
  for (c8_i3 = 0; c8_i3 < 2; c8_i3++) {
    chartInstance->c8_b_state[c8_i3] = c8_uv1[c8_i3];
  }

  chartInstance->c8_is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 11)),
    "is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile");
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 12)),
    "is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile");
  chartInstance->c8_temporalCounter_i1 = c8_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotIm(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_ARP_02_RPSsmile_GloveAtomicBrad
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_gameOver) {
      chartInstance->c8_tp_gameOver = 1U;
    } else {
      chartInstance->c8_tp_gameOver = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateBoredPose1) {
      chartInstance->c8_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c8_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateBradWin) {
      chartInstance->c8_tp_stateBradWin = 1U;
    } else {
      chartInstance->c8_tp_stateBradWin = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateBrowUp) {
      chartInstance->c8_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c8_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateCompare) {
      chartInstance->c8_tp_stateCompare = 1U;
    } else {
      chartInstance->c8_tp_stateCompare = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateGo) {
      chartInstance->c8_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateGo = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateHeadNeutral2) {
      chartInstance->c8_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateIfSmile) {
      chartInstance->c8_tp_stateIfSmile = 1U;
    } else {
      chartInstance->c8_tp_stateIfSmile = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateLeanBack) {
      chartInstance->c8_tp_stateLeanBack = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateLeanBack = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateNoWin) {
      chartInstance->c8_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateNoWin = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseFingersCLose) {
      chartInstance->c8_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c8_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePosePaper) {
      chartInstance->c8_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_statePosePaper = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseReady) {
      chartInstance->c8_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_statePoseReady = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseReturnFinger) {
      chartInstance->c8_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c8_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseRock) {
      chartInstance->c8_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_statePoseRock = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseScissors) {
      chartInstance->c8_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 17) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseSmile) {
      chartInstance->c8_tp_statePoseSmile = 1U;
    } else {
      chartInstance->c8_tp_statePoseSmile = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_statePoseSmileWin) {
      chartInstance->c8_tp_statePoseSmileWin = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_statePoseSmileWin = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateRandom1) {
      chartInstance->c8_tp_stateRandom1 = 1U;
    } else {
      chartInstance->c8_tp_stateRandom1 = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateRandomHand) {
      chartInstance->c8_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c8_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateReadUserHand) {
      chartInstance->c8_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c8_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateReady) {
      chartInstance->c8_tp_stateReady = 1U;
    } else {
      chartInstance->c8_tp_stateReady = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateShowHands) {
      chartInstance->c8_tp_stateShowHands = 1U;
    } else {
      chartInstance->c8_tp_stateShowHands = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateShowResult) {
      chartInstance->c8_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 25) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateShowResult = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateSmile) {
      chartInstance->c8_tp_stateSmile = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 26) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateSmile = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateStart) {
      chartInstance->c8_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 27) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateStart = 0U;
    }

    if (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile ==
        c8_IN_stateUserWin) {
      chartInstance->c8_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 28) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_stateUserWin = 0U;
    }

    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  c8_set_sim_state_side_effects_c8_ARP_02_RPSsmile_GloveAtomicBrad(chartInstance);
}

static void c8_enter_atomic_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  chartInstance->c8_is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
}

static void c8_enter_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_dv0[256];
  int32_T c8_i4;
  real_T c8_dv1[256];
  real_T *c8_round;
  real_T *c8_userHand;
  real_T *c8_bradHand;
  real_T *c8_win;
  real_T *c8_gameState;
  real_T *c8_uWinT;
  real_T *c8_bWinT;
  c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateStart = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_hb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  *c8_round = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_round, 21U);
  c8_set_isSmiling(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c8_set_randSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c8_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c8_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  *c8_userHand = 3.0;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_userHand, 3U);
  *c8_bradHand = 3.0;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_bradHand, 2U);
  *c8_win = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_win, 4U);
  *c8_gameState = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  c8_set_randPoseChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  *c8_uWinT = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c8_uWinT, 10U);
  *c8_bWinT = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_bWinT, 9U);
  c8_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c8_set_boredom(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c8_set_randAvertGazeChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c8_set_BOREDOM_THRESHOLD(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS(chartInstance,
    1.0, c8_dv0);
  for (c8_i4 = 0; c8_i4 < 256; c8_i4++) {
    c8_dv1[c8_i4] = c8_dv0[c8_i4];
  }

  c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_dv1);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 0.0;
  real_T c8_dv2[256];
  int32_T c8_i5;
  real_T c8_dv3[256];
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 1.0;
  boolean_T c8_d_out;
  real_T c8_g_nargin = 0.0;
  real_T c8_g_nargout = 1.0;
  boolean_T c8_e_out;
  real_T c8_h_nargin = 0.0;
  real_T c8_h_nargout = 0.0;
  real_T c8_dv4[2];
  real_T *c8_round;
  real_T *c8_gameState;
  boolean_T guard1 = false;
  c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_isStable = true;
  switch (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile)
  {
   case c8_IN_gameOver:
    CV_CHART_EVAL(4, 0, 1);
    c8_gameOver(chartInstance);
    break;

   case c8_IN_stateBoredPose1:
    CV_CHART_EVAL(4, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c8_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateBradWin:
    CV_CHART_EVAL(4, 0, 3);
    c8_stateBradWin(chartInstance);
    break;

   case c8_IN_stateBrowUp:
    CV_CHART_EVAL(4, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c8_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateCompare:
    CV_CHART_EVAL(4, 0, 5);
    c8_stateCompare(chartInstance);
    break;

   case c8_IN_stateGo:
    CV_CHART_EVAL(4, 0, 6);
    c8_stateGo(chartInstance);
    break;

   case c8_IN_stateHeadNeutral2:
    CV_CHART_EVAL(4, 0, 7);
    c8_stateHeadNeutral2(chartInstance);
    break;

   case c8_IN_stateIfSmile:
    CV_CHART_EVAL(4, 0, 8);
    c8_stateIfSmile(chartInstance);
    break;

   case c8_IN_stateLeanBack:
    CV_CHART_EVAL(4, 0, 9);
    c8_stateLeanBack(chartInstance);
    break;

   case c8_IN_stateNoWin:
    CV_CHART_EVAL(4, 0, 10);
    c8_stateNoWin(chartInstance);
    break;

   case c8_IN_statePoseFingersCLose:
    CV_CHART_EVAL(4, 0, 11);
    c8_statePoseFingersCLose(chartInstance);
    break;

   case c8_IN_statePosePaper:
    CV_CHART_EVAL(4, 0, 12);
    c8_statePosePaper(chartInstance);
    break;

   case c8_IN_statePoseReady:
    CV_CHART_EVAL(4, 0, 13);
    c8_statePoseReady(chartInstance);
    break;

   case c8_IN_statePoseReturnFinger:
    CV_CHART_EVAL(4, 0, 14);
    c8_statePoseReturnFinger(chartInstance);
    break;

   case c8_IN_statePoseRock:
    CV_CHART_EVAL(4, 0, 15);
    c8_statePoseRock(chartInstance);
    break;

   case c8_IN_statePoseScissors:
    CV_CHART_EVAL(4, 0, 16);
    c8_statePoseScissors(chartInstance);
    break;

   case c8_IN_statePoseSmile:
    CV_CHART_EVAL(4, 0, 17);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_stateGo = 1U;
    c8_enter_atomic_stateGo(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseSmileWin:
    CV_CHART_EVAL(4, 0, 18);
    c8_statePoseSmileWin(chartInstance);
    break;

   case c8_IN_stateRandom1:
    CV_CHART_EVAL(4, 0, 19);
    c8_stateRandom1(chartInstance);
    break;

   case c8_IN_stateRandomHand:
    CV_CHART_EVAL(4, 0, 20);
    c8_stateRandomHand(chartInstance);
    break;

   case c8_IN_stateReadUserHand:
    CV_CHART_EVAL(4, 0, 21);
    c8_stateReadUserHand(chartInstance);
    break;

   case c8_IN_stateReady:
    CV_CHART_EVAL(4, 0, 22);
    c8_stateReady(chartInstance);
    break;

   case c8_IN_stateShowHands:
    CV_CHART_EVAL(4, 0, 23);
    c8_stateShowHands(chartInstance);
    break;

   case c8_IN_stateShowResult:
    CV_CHART_EVAL(4, 0, 24);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_lc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                    (chartInstance->c8_temporalCounter_i1 >= 3))) {
      if (CV_EML_COND(5, 0, 1, *c8_round == 10.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c8_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c8_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c8_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_jb_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      *c8_gameState = 3.0;
      c8_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
      c8_set_boredom(chartInstance, 0, c8_get_boredom(chartInstance, 0) - 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_mc_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_b_out = CV_EML_IF(3, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs)
                           && (chartInstance->c8_temporalCounter_i1 >= 3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
          c8_IN_stateReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateReady = 1U;
        c8_enter_atomic_stateReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                     chartInstance->c8_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateSmile:
    CV_CHART_EVAL(4, 0, 25);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_uc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_c_out = CV_EML_IF(16, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateLeanBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_stateLeanBack = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_qb_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
        (chartInstance, 1.0, c8_dv2);
      for (c8_i5 = 0; c8_i5 < 256; c8_i5++) {
        c8_dv3[c8_i5] = c8_dv2[c8_i5];
      }

      c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv3);
      c8_set_isSmiling(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateStart:
    CV_CHART_EVAL(4, 0, 26);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_jc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_d_out = CV_EML_IF(1, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReady = 1U;
      c8_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateUserWin:
    CV_CHART_EVAL(4, 0, 27);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_kd_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_g_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_e_out = CV_EML_IF(36, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                         (chartInstance->c8_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateRandom1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateRandom1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_gc_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_h_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_dv4[0] = 0.0;
      c8_dv4[1] = c8_get_boredom(chartInstance, 0);
      c8_set_randSmile(chartInstance, 0, c8_randi(chartInstance, c8_dv4));
      ssUpdateDataStoreLog(chartInstance->S, 11);
      c8_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U,
                   chartInstance->c8_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c8_sfEvent);
}

static void c8_exit_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  switch (chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile)
  {
   case c8_IN_gameOver:
    CV_CHART_EVAL(4, 0, 1);
    chartInstance->c8_tp_gameOver = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateBoredPose1:
    CV_CHART_EVAL(4, 0, 2);
    chartInstance->c8_tp_stateBoredPose1 = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateBradWin:
    CV_CHART_EVAL(4, 0, 3);
    chartInstance->c8_tp_stateBradWin = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateBrowUp:
    CV_CHART_EVAL(4, 0, 4);
    chartInstance->c8_tp_stateBrowUp = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateCompare:
    CV_CHART_EVAL(4, 0, 5);
    chartInstance->c8_tp_stateCompare = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateGo:
    CV_CHART_EVAL(4, 0, 6);
    chartInstance->c8_tp_stateGo = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateHeadNeutral2:
    CV_CHART_EVAL(4, 0, 7);
    chartInstance->c8_tp_stateHeadNeutral2 = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateIfSmile:
    CV_CHART_EVAL(4, 0, 8);
    chartInstance->c8_tp_stateIfSmile = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateLeanBack:
    CV_CHART_EVAL(4, 0, 9);
    chartInstance->c8_tp_stateLeanBack = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateNoWin:
    CV_CHART_EVAL(4, 0, 10);
    chartInstance->c8_tp_stateNoWin = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseFingersCLose:
    CV_CHART_EVAL(4, 0, 11);
    chartInstance->c8_tp_statePoseFingersCLose = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePosePaper:
    CV_CHART_EVAL(4, 0, 12);
    chartInstance->c8_tp_statePosePaper = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseReady:
    CV_CHART_EVAL(4, 0, 13);
    chartInstance->c8_tp_statePoseReady = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseReturnFinger:
    CV_CHART_EVAL(4, 0, 14);
    chartInstance->c8_tp_statePoseReturnFinger = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseRock:
    CV_CHART_EVAL(4, 0, 15);
    chartInstance->c8_tp_statePoseRock = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseScissors:
    CV_CHART_EVAL(4, 0, 16);
    chartInstance->c8_tp_statePoseScissors = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseSmile:
    CV_CHART_EVAL(4, 0, 17);
    chartInstance->c8_tp_statePoseSmile = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_statePoseSmileWin:
    CV_CHART_EVAL(4, 0, 18);
    chartInstance->c8_tp_statePoseSmileWin = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateRandom1:
    CV_CHART_EVAL(4, 0, 19);
    chartInstance->c8_tp_stateRandom1 = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateRandomHand:
    CV_CHART_EVAL(4, 0, 20);
    chartInstance->c8_tp_stateRandomHand = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateReadUserHand:
    CV_CHART_EVAL(4, 0, 21);
    chartInstance->c8_tp_stateReadUserHand = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateReady:
    CV_CHART_EVAL(4, 0, 22);
    chartInstance->c8_tp_stateReady = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateShowHands:
    CV_CHART_EVAL(4, 0, 23);
    chartInstance->c8_tp_stateShowHands = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateShowResult:
    CV_CHART_EVAL(4, 0, 24);
    chartInstance->c8_tp_stateShowResult = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateSmile:
    CV_CHART_EVAL(4, 0, 25);
    chartInstance->c8_tp_stateSmile = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateStart:
    CV_CHART_EVAL(4, 0, 26);
    chartInstance->c8_tp_stateStart = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_stateUserWin:
    CV_CHART_EVAL(4, 0, 27);
    chartInstance->c8_tp_stateUserWin = 0U;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_CHART_EVAL(4, 0, 0);
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    break;
  }
}

static void c8_initc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_method_not_empty = false;
  chartInstance->c8_state_not_empty = false;
  chartInstance->c8_b_state_not_empty = false;
  chartInstance->c8_c_state_not_empty = false;
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_tp_gameOver = 0U;
  chartInstance->c8_tp_stateBoredPose1 = 0U;
  chartInstance->c8_tp_stateBradWin = 0U;
  chartInstance->c8_tp_stateBrowUp = 0U;
  chartInstance->c8_tp_stateCompare = 0U;
  chartInstance->c8_tp_stateGo = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateHeadNeutral2 = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateIfSmile = 0U;
  chartInstance->c8_tp_stateLeanBack = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateNoWin = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseFingersCLose = 0U;
  chartInstance->c8_tp_statePosePaper = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseReady = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseReturnFinger = 0U;
  chartInstance->c8_tp_statePoseRock = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseScissors = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseSmile = 0U;
  chartInstance->c8_tp_statePoseSmileWin = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateRandom1 = 0U;
  chartInstance->c8_tp_stateRandomHand = 0U;
  chartInstance->c8_tp_stateReadUserHand = 0U;
  chartInstance->c8_tp_stateReady = 0U;
  chartInstance->c8_tp_stateShowHands = 0U;
  chartInstance->c8_tp_stateShowResult = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateSmile = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateStart = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateUserWin = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    0U;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_enter_atomic_stateReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T *c8_round;
  real_T *c8_bradHand;
  real_T *c8_userHand;
  real_T *c8_gameState;
  real_T *c8_win;
  c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ib_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
  (*c8_round)++;
  c8_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_round, 21U);
  *c8_bradHand = 3.0;
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_bradHand, 2U);
  *c8_userHand = 3.0;
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_userHand, 3U);
  *c8_gameState = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  *c8_win = 0.0;
  c8_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_win, 4U);
  c8_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_stateReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 0.0;
  real_T c8_dv5[256];
  int32_T c8_i6;
  real_T c8_dv6[256];
  int32_T c8_i7;
  real_T c8_dv7[256];
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 0.0;
  int32_T c8_i8;
  real_T c8_dv8[256];
  int32_T c8_i9;
  real_T c8_dv9[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_nc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(40, 0, 0, c8_get_boredom(chartInstance, 0) <
                     c8_get_BOREDOM_THRESHOLD(chartInstance, 0) - 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_oc_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_boredom(chartInstance, 0, c8_get_boredom(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c8_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_statePoseReady = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_kb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS
      (chartInstance, 2.0, c8_dv5);
    for (c8_i6 = 0; c8_i6 < 256; c8_i6++) {
      c8_dv6[c8_i6] = c8_dv5[c8_i6];
    }

    c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
      c8_dv6);
    c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
      (chartInstance, 2.0, c8_dv5);
    for (c8_i7 = 0; c8_i7 < 256; c8_i7++) {
      c8_dv7[c8_i7] = c8_dv5[c8_i7];
    }

    c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
      c8_dv7);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_kc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(2, 0, 0, c8_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReady = 1U;
      c8_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_statePoseReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_statePoseReady = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_kb_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS
        (chartInstance, 2.0, c8_dv5);
      for (c8_i8 = 0; c8_i8 < 256; c8_i8++) {
        c8_dv8[c8_i8] = c8_dv5[c8_i8];
      }

      c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv8);
      c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
        (chartInstance, 2.0, c8_dv5);
      for (c8_i9 = 0; c8_i9 < 256; c8_i9++) {
        c8_dv9[c8_i9] = c8_dv5[c8_i9];
      }

      c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv9);
      c8_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c8_sfEvent);
}

static void c8_gameOver
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_dv10[256];
  int32_T c8_i10;
  real_T c8_dv11[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_gameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_stateHeadNeutral2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_stateHeadNeutral2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_lb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS(chartInstance,
    2.0, c8_dv10);
  for (c8_i10 = 0; c8_i10 < 256; c8_i10++) {
    c8_dv11[c8_i10] = c8_dv10[c8_i10];
  }

  c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_dv11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
}

static void c8_statePoseReady
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_dv12[2];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_pc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(6, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                  (chartInstance->c8_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(6, 0, 1, c8_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c8_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(6, 0, 0, false);
    CV_EML_IF(6, 0, 0, false);
    c8_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateIfSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateIfSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_mb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_dv12[0] = 0.0;
    c8_dv12[1] = c8_get_boredom(chartInstance, 0);
    c8_set_randSmile(chartInstance, 0, c8_randi(chartInstance, c8_dv12));
    ssUpdateDataStoreLog(chartInstance->S, 11);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c8_sfEvent);
}

static void c8_stateHeadNeutral2
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 1.0;
  boolean_T c8_b_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 0.0;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_r;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_dv13[256];
  int32_T c8_i11;
  real_T c8_dv14[256];
  real_T *c8_uWinT;
  real_T *c8_bWinT;
  c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_qc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(10, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_tc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    c8_b_out = CV_EML_IF(14, 0, 0, *c8_uWinT < *c8_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ob_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_isSmiling(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateBoredPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateBoredPose1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_tb_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_r = c8_rand(chartInstance);
      c8_x = c8_r * 18.0;
      c8_b_x = c8_x;
      c8_b_x = muDoubleScalarFloor(c8_b_x);
      c8_r = 1.0 + c8_b_x;
      c8_idlePoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitate
        (chartInstance, c8_r, c8_dv13);
      for (c8_i11 = 0; c8_i11 < 256; c8_i11++) {
        c8_dv14[c8_i11] = c8_dv13[c8_i11];
      }

      c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv14);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c8_sfEvent);
}

static void c8_stateIfSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_sc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(9, 0, 0, c8_get_randSmile(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateIfSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_statePoseSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_pb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isSmiling(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_rc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(8, 0, 0, c8_get_randSmile(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateIfSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateGo;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_stateGo = 1U;
      c8_enter_atomic_stateGo(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c8_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_stateGo
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T *c8_gameState;
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_nb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c8_gameState = 1.0;
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  c8_set_isSmiling(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_stateGo
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_r;
  real_T c8_x;
  real_T c8_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_vc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(15, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateRandomHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateRandomHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_rb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_r = c8_rand(chartInstance);
    c8_x = c8_r * 3.0;
    c8_b_x = c8_x;
    c8_b_x = muDoubleScalarFloor(c8_b_x);
    c8_r = c8_b_x;
    c8_set_bHand(chartInstance, 0, c8_r);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c8_sfEvent);
}

static void c8_stateLeanBack
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_dv15[256];
  int32_T c8_i12;
  real_T c8_dv16[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_wc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(17, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateLeanBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_sb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
      (chartInstance, 2.0, c8_dv15);
    for (c8_i12 = 0; c8_i12 < 256; c8_i12++) {
      c8_dv16[c8_i12] = c8_dv15[c8_i12];
    }

    c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
      c8_dv16);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c8_sfEvent);
}

static void c8_stateRandomHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_dv17[256];
  int32_T c8_i13;
  real_T c8_dv18[256];
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  int32_T c8_i14;
  real_T c8_dv19[256];
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 0.0;
  int32_T c8_i15;
  real_T c8_dv20[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ad_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(21, 0, 0, c8_get_bHand(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_vb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_p(chartInstance, 0, c8_b_randi(chartInstance));
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c8_paperPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitat
      (chartInstance, c8_get_p(chartInstance, 0), c8_dv17);
    for (c8_i13 = 0; c8_i13 < 256; c8_i13++) {
      c8_dv18[c8_i13] = c8_dv17[c8_i13];
    }

    c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
      c8_dv18);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_xc_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(20, 0, 0, c8_get_bHand(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_wb_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c8_set_r(chartInstance, 0, c8_b_randi(chartInstance));
      ssUpdateDataStoreLog(chartInstance->S, 8);
      c8_rockPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
        (chartInstance, c8_get_r(chartInstance, 0), c8_dv17);
      for (c8_i14 = 0; c8_i14 < 256; c8_i14++) {
        c8_dv19[c8_i14] = c8_dv17[c8_i14];
      }

      c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv19);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_yc_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      c8_c_out = CV_EML_IF(19, 0, 0, c8_get_bHand(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
          c8_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ub_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        c8_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
          (chartInstance, 1.0, c8_dv17);
        for (c8_i15 = 0; c8_i15 < 256; c8_i15++) {
          c8_dv20[c8_i15] = c8_dv17[c8_i15];
        }

        c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
          (chartInstance, c8_dv20);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                     chartInstance->c8_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c8_sfEvent);
}

static void c8_statePoseFingersCLose
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_dv21[256];
  int32_T c8_i16;
  real_T c8_dv22[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_xb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c8_set_s(chartInstance, 0, c8_b_randi(chartInstance));
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c8_scissorsPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImi(chartInstance,
    c8_get_s(chartInstance, 0), c8_dv21);
  for (c8_i16 = 0; c8_i16 < 256; c8_i16++) {
    c8_dv22[c8_i16] = c8_dv21[c8_i16];
  }

  c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_dv22);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c8_sfEvent);
}

static void c8_statePosePaper
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T *c8_inputUser;
  boolean_T guard1 = false;
  c8_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_cd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(23, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                  (chartInstance->c8_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(23, 0, 1, c8_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(23, 0, 0, true);
      CV_EML_IF(23, 0, 0, true);
      c8_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(23, 0, 0, false);
    CV_EML_IF(23, 0, 0, false);
    c8_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_yb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_uHand(chartInstance, 0, *c8_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c8_sfEvent);
}

static void c8_statePoseRock
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T *c8_inputUser;
  boolean_T guard1 = false;
  c8_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_bd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(22, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                  (chartInstance->c8_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(22, 0, 1, c8_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(22, 0, 0, true);
      CV_EML_IF(22, 0, 0, true);
      c8_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(22, 0, 0, false);
    CV_EML_IF(22, 0, 0, false);
    c8_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_yb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_uHand(chartInstance, 0, *c8_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c8_sfEvent);
}

static void c8_statePoseScissors
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T *c8_inputUser;
  boolean_T guard1 = false;
  c8_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ed_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(26, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                  (chartInstance->c8_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(26, 0, 1, c8_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(26, 0, 0, true);
      CV_EML_IF(26, 0, 0, true);
      c8_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(26, 0, 0, false);
    CV_EML_IF(26, 0, 0, false);
    c8_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseScissors = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_yb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_uHand(chartInstance, 0, *c8_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c8_sfEvent);
}

static void c8_stateReadUserHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_dv23[256];
  int32_T c8_i17;
  real_T c8_dv24[256];
  real_T *c8_inputUser;
  c8_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_dd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(25, 0, 0, c8_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_yb_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_uHand(chartInstance, 0, *c8_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_fd_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(28, 0, 0, c8_get_bHand(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_bc_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
        (chartInstance, 2.0, c8_dv23);
      for (c8_i17 = 0; c8_i17 < 256; c8_i17++) {
        c8_dv24[c8_i17] = c8_dv23[c8_i17];
      }

      c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
        c8_dv24);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateShowHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateShowHands = 1U;
      c8_enter_atomic_stateShowHands(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c8_sfEvent);
}

static void c8_enter_atomic_stateShowHands
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T *c8_gameState;
  real_T *c8_bradHand;
  real_T *c8_userHand;
  c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ac_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c8_gameState = 2.0;
  c8_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c8_gameState, 0U);
  *c8_bradHand = c8_get_bHand(chartInstance, 0);
  c8_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_bradHand, 2U);
  *c8_userHand = c8_get_uHand(chartInstance, 0);
  c8_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_userHand, 3U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_stateShowHands
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_A;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_d_x;
  real_T c8_e_x;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateShowHands = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_cc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c8_set_temp(chartInstance, 0, c8_get_uHand(chartInstance, 0) - c8_get_bHand
              (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c8_hoistedGlobal = c8_get_temp(chartInstance, 0);
  c8_b_hoistedGlobal = c8_get_temp(chartInstance, 0);
  c8_A = c8_b_hoistedGlobal;
  c8_x = c8_A;
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_y = c8_c_x / 3.0;
  c8_d_x = c8_y;
  c8_e_x = c8_d_x;
  c8_e_x = muDoubleScalarFloor(c8_e_x);
  c8_set_diff(chartInstance, 0, c8_hoistedGlobal - 3.0 * c8_e_x);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c8_sfEvent);
}

static void c8_statePoseReturnFinger
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_statePoseReturnFinger = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_stateShowHands;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateShowHands = 1U;
  c8_enter_atomic_stateShowHands(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c8_sfEvent);
}

static void c8_stateCompare
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  real_T c8_e_nargin = 0.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_c_out;
  real_T c8_f_nargin = 0.0;
  real_T c8_f_nargout = 0.0;
  real_T *c8_win;
  real_T *c8_uWinT;
  real_T *c8_bWinT;
  boolean_T guard1 = false;
  c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_hd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(32, 0, 0, c8_get_diff(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ec_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c8_win = 2.0;
    c8_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c8_win, 4U);
    c8_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    (*c8_bWinT)++;
    c8_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c8_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_gd_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(31, 0, 0, c8_get_diff(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_dc_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c8_win = 1.0;
      c8_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c8_win, 4U);
      c8_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      (*c8_uWinT)++;
      c8_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c8_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                   chartInstance->c8_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_id_debug_family_names,
        c8_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_out, 2U, c8_c_sf_marshallOut,
        c8_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(33, 0, 0, c8_get_diff(chartInstance, 0) != 1.0)) {
        if (CV_EML_COND(33, 0, 1, c8_get_diff(chartInstance, 0) != 2.0)) {
          CV_EML_MCDC(33, 0, 0, true);
          CV_EML_IF(33, 0, 0, true);
          c8_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(33, 0, 0, false);
        CV_EML_IF(33, 0, 0, false);
        c8_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c8_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c8_sfEvent);
        chartInstance->c8_isStable = false;
        chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
          c8_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
        chartInstance->c8_temporalCounter_i1 = 0U;
        chartInstance->c8_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_fc_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargin, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_nargout, 1U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        *c8_win = 0.0;
        c8_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c8_win, 4U);
        c8_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c8_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c8_sfEvent);
}

static void c8_stateBradWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[2];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 0.0;
  real_T c8_dv25[2];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateBradWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c8_sfEvent);
  chartInstance->c8_isStable = false;
  chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
    c8_IN_stateRandom1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
  chartInstance->c8_tp_stateRandom1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_gc_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  c8_dv25[0] = 0.0;
  c8_dv25[1] = c8_get_boredom(chartInstance, 0);
  c8_set_randSmile(chartInstance, 0, c8_randi(chartInstance, c8_dv25));
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c8_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c8_sfEvent);
}

static void c8_stateNoWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_dv26[2];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_jd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(35, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_gc_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_dv26[0] = 0.0;
    c8_dv26[1] = c8_get_boredom(chartInstance, 0);
    c8_set_randSmile(chartInstance, 0, c8_randi(chartInstance, c8_dv26));
    ssUpdateDataStoreLog(chartInstance->S, 11);
    c8_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c8_sfEvent);
}

static void c8_stateRandom1
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  real_T c8_c_nargin = 0.0;
  real_T c8_c_nargout = 1.0;
  boolean_T c8_b_out;
  real_T c8_d_nargin = 0.0;
  real_T c8_d_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_ld_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(37, 0, 0, c8_get_randSmile(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_stateRandom1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_statePoseSmileWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_statePoseSmileWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_hc_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isSmiling(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    c8_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c8_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_md_debug_family_names,
      c8_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_out, 2U, c8_c_sf_marshallOut,
      c8_c_sf_marshallIn);
    c8_b_out = CV_EML_IF(38, 0, 0, c8_get_randSmile(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c8_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c8_sfEvent);
      chartInstance->c8_tp_stateRandom1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c8_sfEvent);
      chartInstance->c8_isStable = false;
      chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
        c8_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
      chartInstance->c8_temporalCounter_i1 = 0U;
      chartInstance->c8_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ic_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      c8_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c8_set_isSmiling(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U,
                   chartInstance->c8_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c8_sfEvent);
}

static void c8_statePoseSmileWin
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c8_debug_family_var_map[3];
  real_T c8_nargin = 0.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_out;
  uint32_T c8_b_debug_family_var_map[2];
  real_T c8_b_nargin = 0.0;
  real_T c8_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c8_nd_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_out, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  c8_out = CV_EML_IF(39, 0, 0, (chartInstance->c8_sfEvent == c8_event_secs) &&
                     (chartInstance->c8_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c8_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c8_sfEvent);
    chartInstance->c8_tp_statePoseSmileWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c8_sfEvent);
    chartInstance->c8_isStable = false;
    chartInstance->c8_is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile =
      c8_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c8_ic_debug_family_names,
      c8_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
      c8_b_sf_marshallIn);
    c8_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c8_set_isSmiling(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c8_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c8_sfEvent);
}

static void c8_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[94];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[94];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i18;
  static char_T c8_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i19;
  static real_T c8_dv27[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i18 = 0; c8_i18 < 94; c8_i18++) {
    c8_mystr[c8_i18] = c8_cv0[c8_i18];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i19 = 0; c8_i19 < 94; c8_i19++) {
    c8_arr[c8_i19] = c8_dv27[c8_i19];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i20 = 0; c8_i20 < 256; c8_i20++) {
    c8_tt[c8_i20] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i21 = 0; c8_i21 < 94; c8_i21++) {
    c8_tt[c8_i21] = c8_arr[c8_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i22 = 0; c8_i22 < 256; c8_i22++) {
    c8_myarr256[c8_i22] = c8_tt[c8_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_b_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[88];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[88];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i23;
  static char_T c8_cv1[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c8_i24;
  static real_T c8_dv28[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_e_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i23 = 0; c8_i23 < 88; c8_i23++) {
    c8_mystr[c8_i23] = c8_cv1[c8_i23];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i24 = 0; c8_i24 < 88; c8_i24++) {
    c8_arr[c8_i24] = c8_dv28[c8_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i25 = 0; c8_i25 < 256; c8_i25++) {
    c8_tt[c8_i25] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i26 = 0; c8_i26 < 88; c8_i26++) {
    c8_tt[c8_i26] = c8_arr[c8_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i27 = 0; c8_i27 < 256; c8_i27++) {
    c8_myarr256[c8_i27] = c8_tt[c8_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_c_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[86];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[86];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i28;
  static char_T c8_cv2[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c8_i29;
  static real_T c8_dv29[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i30;
  int32_T c8_i31;
  int32_T c8_i32;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_f_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i28 = 0; c8_i28 < 86; c8_i28++) {
    c8_mystr[c8_i28] = c8_cv2[c8_i28];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i29 = 0; c8_i29 < 86; c8_i29++) {
    c8_arr[c8_i29] = c8_dv29[c8_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i30 = 0; c8_i30 < 256; c8_i30++) {
    c8_tt[c8_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i31 = 0; c8_i31 < 86; c8_i31++) {
    c8_tt[c8_i31] = c8_arr[c8_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i32 = 0; c8_i32 < 256; c8_i32++) {
    c8_myarr256[c8_i32] = c8_tt[c8_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_d_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[161];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[161];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i33;
  static char_T c8_cv3[161] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c8_i34;
  static real_T c8_dv30[161] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c8_i35;
  int32_T c8_i36;
  int32_T c8_i37;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_i_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i33 = 0; c8_i33 < 161; c8_i33++) {
    c8_mystr[c8_i33] = c8_cv3[c8_i33];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i34 = 0; c8_i34 < 161; c8_i34++) {
    c8_arr[c8_i34] = c8_dv30[c8_i34];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i35 = 0; c8_i35 < 256; c8_i35++) {
    c8_tt[c8_i35] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i36 = 0; c8_i36 < 161; c8_i36++) {
    c8_tt[c8_i36] = c8_arr[c8_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i37 = 0; c8_i37 < 256; c8_i37++) {
    c8_myarr256[c8_i37] = c8_tt[c8_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_e_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[157];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[157];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i38;
  static char_T c8_cv4[157] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c8_i39;
  static real_T c8_dv31[157] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c8_i40;
  int32_T c8_i41;
  int32_T c8_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_j_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i38 = 0; c8_i38 < 157; c8_i38++) {
    c8_mystr[c8_i38] = c8_cv4[c8_i38];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i39 = 0; c8_i39 < 157; c8_i39++) {
    c8_arr[c8_i39] = c8_dv31[c8_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 157.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i40 = 0; c8_i40 < 256; c8_i40++) {
    c8_tt[c8_i40] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i41 = 0; c8_i41 < 157; c8_i41++) {
    c8_tt[c8_i41] = c8_arr[c8_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i42 = 0; c8_i42 < 256; c8_i42++) {
    c8_myarr256[c8_i42] = c8_tt[c8_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_f_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[91];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[91];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i43;
  static char_T c8_cv5[91] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '0', '5', ')', ')' };

  int32_T c8_i44;
  static real_T c8_dv32[91] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 46.0, 48.0, 53.0, 41.0, 41.0 };

  int32_T c8_i45;
  int32_T c8_i46;
  int32_T c8_i47;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_k_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i43 = 0; c8_i43 < 91; c8_i43++) {
    c8_mystr[c8_i43] = c8_cv5[c8_i43];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i44 = 0; c8_i44 < 91; c8_i44++) {
    c8_arr[c8_i44] = c8_dv32[c8_i44];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i45 = 0; c8_i45 < 256; c8_i45++) {
    c8_tt[c8_i45] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i46 = 0; c8_i46 < 91; c8_i46++) {
    c8_tt[c8_i46] = c8_arr[c8_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i47 = 0; c8_i47 < 256; c8_i47++) {
    c8_myarr256[c8_i47] = c8_tt[c8_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_g_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[91];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[91];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i48;
  static char_T c8_cv6[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i49;
  static real_T c8_dv33[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c8_i50;
  int32_T c8_i51;
  int32_T c8_i52;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_n_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i48 = 0; c8_i48 < 91; c8_i48++) {
    c8_mystr[c8_i48] = c8_cv6[c8_i48];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i49 = 0; c8_i49 < 91; c8_i49++) {
    c8_arr[c8_i49] = c8_dv33[c8_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i50 = 0; c8_i50 < 256; c8_i50++) {
    c8_tt[c8_i50] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i51 = 0; c8_i51 < 91; c8_i51++) {
    c8_tt[c8_i51] = c8_arr[c8_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i52 = 0; c8_i52 < 256; c8_i52++) {
    c8_myarr256[c8_i52] = c8_tt[c8_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_h_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[87];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[87];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i53;
  static char_T c8_cv7[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c8_i54;
  static real_T c8_dv34[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i55;
  int32_T c8_i56;
  int32_T c8_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_o_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i53 = 0; c8_i53 < 87; c8_i53++) {
    c8_mystr[c8_i53] = c8_cv7[c8_i53];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i54 = 0; c8_i54 < 87; c8_i54++) {
    c8_arr[c8_i54] = c8_dv34[c8_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i55 = 0; c8_i55 < 256; c8_i55++) {
    c8_tt[c8_i55] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i56 = 0; c8_i56 < 87; c8_i56++) {
    c8_tt[c8_i56] = c8_arr[c8_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i57 = 0; c8_i57 < 256; c8_i57++) {
    c8_myarr256[c8_i57] = c8_tt[c8_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_i_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[93];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[93];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i58;
  static char_T c8_cv8[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i59;
  static real_T c8_dv35[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i60;
  int32_T c8_i61;
  int32_T c8_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_p_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i58 = 0; c8_i58 < 93; c8_i58++) {
    c8_mystr[c8_i58] = c8_cv8[c8_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i59 = 0; c8_i59 < 93; c8_i59++) {
    c8_arr[c8_i59] = c8_dv35[c8_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i60 = 0; c8_i60 < 256; c8_i60++) {
    c8_tt[c8_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i61 = 0; c8_i61 < 93; c8_i61++) {
    c8_tt[c8_i61] = c8_arr[c8_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i62 = 0; c8_i62 < 256; c8_i62++) {
    c8_myarr256[c8_i62] = c8_tt[c8_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_j_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[94];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[94];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i63;
  static char_T c8_cv9[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i64;
  static real_T c8_dv36[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i65;
  int32_T c8_i66;
  int32_T c8_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_q_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i63 = 0; c8_i63 < 94; c8_i63++) {
    c8_mystr[c8_i63] = c8_cv9[c8_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i64 = 0; c8_i64 < 94; c8_i64++) {
    c8_arr[c8_i64] = c8_dv36[c8_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i65 = 0; c8_i65 < 256; c8_i65++) {
    c8_tt[c8_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i66 = 0; c8_i66 < 94; c8_i66++) {
    c8_tt[c8_i66] = c8_arr[c8_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i67 = 0; c8_i67 < 256; c8_i67++) {
    c8_myarr256[c8_i67] = c8_tt[c8_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_k_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[95];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[95];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i68;
  static char_T c8_cv10[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i69;
  static real_T c8_dv37[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i70;
  int32_T c8_i71;
  int32_T c8_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_r_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i68 = 0; c8_i68 < 95; c8_i68++) {
    c8_mystr[c8_i68] = c8_cv10[c8_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i69 = 0; c8_i69 < 95; c8_i69++) {
    c8_arr[c8_i69] = c8_dv37[c8_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i70 = 0; c8_i70 < 256; c8_i70++) {
    c8_tt[c8_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i71 = 0; c8_i71 < 95; c8_i71++) {
    c8_tt[c8_i71] = c8_arr[c8_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i72 = 0; c8_i72 < 256; c8_i72++) {
    c8_myarr256[c8_i72] = c8_tt[c8_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_l_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[88];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[88];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i73;
  static char_T c8_cv11[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c8_i74;
  static real_T c8_dv38[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i75;
  int32_T c8_i76;
  int32_T c8_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_s_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i73 = 0; c8_i73 < 88; c8_i73++) {
    c8_mystr[c8_i73] = c8_cv11[c8_i73];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i74 = 0; c8_i74 < 88; c8_i74++) {
    c8_arr[c8_i74] = c8_dv38[c8_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i75 = 0; c8_i75 < 256; c8_i75++) {
    c8_tt[c8_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i76 = 0; c8_i76 < 88; c8_i76++) {
    c8_tt[c8_i76] = c8_arr[c8_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i77 = 0; c8_i77 < 256; c8_i77++) {
    c8_myarr256[c8_i77] = c8_tt[c8_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_m_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[93];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[93];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i78;
  static char_T c8_cv12[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i79;
  static real_T c8_dv39[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i80;
  int32_T c8_i81;
  int32_T c8_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_t_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i78 = 0; c8_i78 < 93; c8_i78++) {
    c8_mystr[c8_i78] = c8_cv12[c8_i78];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i79 = 0; c8_i79 < 93; c8_i79++) {
    c8_arr[c8_i79] = c8_dv39[c8_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i80 = 0; c8_i80 < 256; c8_i80++) {
    c8_tt[c8_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i81 = 0; c8_i81 < 93; c8_i81++) {
    c8_tt[c8_i81] = c8_arr[c8_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i82 = 0; c8_i82 < 256; c8_i82++) {
    c8_myarr256[c8_i82] = c8_tt[c8_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_n_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[93];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[93];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i83;
  static char_T c8_cv13[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i84;
  static real_T c8_dv40[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i85;
  int32_T c8_i86;
  int32_T c8_i87;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_u_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i83 = 0; c8_i83 < 93; c8_i83++) {
    c8_mystr[c8_i83] = c8_cv13[c8_i83];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i84 = 0; c8_i84 < 93; c8_i84++) {
    c8_arr[c8_i84] = c8_dv40[c8_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i85 = 0; c8_i85 < 256; c8_i85++) {
    c8_tt[c8_i85] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i86 = 0; c8_i86 < 93; c8_i86++) {
    c8_tt[c8_i86] = c8_arr[c8_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i87 = 0; c8_i87 < 256; c8_i87++) {
    c8_myarr256[c8_i87] = c8_tt[c8_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_o_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[97];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[97];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i88;
  static char_T c8_cv14[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i89;
  static real_T c8_dv41[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i90;
  int32_T c8_i91;
  int32_T c8_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_v_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i88 = 0; c8_i88 < 97; c8_i88++) {
    c8_mystr[c8_i88] = c8_cv14[c8_i88];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i89 = 0; c8_i89 < 97; c8_i89++) {
    c8_arr[c8_i89] = c8_dv41[c8_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i90 = 0; c8_i90 < 256; c8_i90++) {
    c8_tt[c8_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i91 = 0; c8_i91 < 97; c8_i91++) {
    c8_tt[c8_i91] = c8_arr[c8_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i92 = 0; c8_i92 < 256; c8_i92++) {
    c8_myarr256[c8_i92] = c8_tt[c8_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_p_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[97];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[97];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i93;
  static char_T c8_cv15[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i94;
  static real_T c8_dv42[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i95;
  int32_T c8_i96;
  int32_T c8_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_w_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i93 = 0; c8_i93 < 97; c8_i93++) {
    c8_mystr[c8_i93] = c8_cv15[c8_i93];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i94 = 0; c8_i94 < 97; c8_i94++) {
    c8_arr[c8_i94] = c8_dv42[c8_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i95 = 0; c8_i95 < 256; c8_i95++) {
    c8_tt[c8_i95] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i96 = 0; c8_i96 < 97; c8_i96++) {
    c8_tt[c8_i96] = c8_arr[c8_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i97 = 0; c8_i97 < 256; c8_i97++) {
    c8_myarr256[c8_i97] = c8_tt[c8_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_q_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[92];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[92];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i98;
  static char_T c8_cv16[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i99;
  static real_T c8_dv43[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i100;
  int32_T c8_i101;
  int32_T c8_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_x_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i98 = 0; c8_i98 < 92; c8_i98++) {
    c8_mystr[c8_i98] = c8_cv16[c8_i98];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i99 = 0; c8_i99 < 92; c8_i99++) {
    c8_arr[c8_i99] = c8_dv43[c8_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i100 = 0; c8_i100 < 256; c8_i100++) {
    c8_tt[c8_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i101 = 0; c8_i101 < 92; c8_i101++) {
    c8_tt[c8_i101] = c8_arr[c8_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i102 = 0; c8_i102 < 256; c8_i102++) {
    c8_myarr256[c8_i102] = c8_tt[c8_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_r_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[68];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[68];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i103;
  static char_T c8_cv17[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i104;
  static real_T c8_dv44[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c8_i105;
  int32_T c8_i106;
  int32_T c8_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_ab_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i103 = 0; c8_i103 < 68; c8_i103++) {
    c8_mystr[c8_i103] = c8_cv17[c8_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i104 = 0; c8_i104 < 68; c8_i104++) {
    c8_arr[c8_i104] = c8_dv44[c8_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 68.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i105 = 0; c8_i105 < 256; c8_i105++) {
    c8_tt[c8_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i106 = 0; c8_i106 < 68; c8_i106++) {
    c8_tt[c8_i106] = c8_arr[c8_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i107 = 0; c8_i107 < 256; c8_i107++) {
    c8_myarr256[c8_i107] = c8_tt[c8_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_s_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[87];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[87];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i108;
  static char_T c8_cv18[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c8_i109;
  static real_T c8_dv45[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i110;
  int32_T c8_i111;
  int32_T c8_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_bb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i108 = 0; c8_i108 < 87; c8_i108++) {
    c8_mystr[c8_i108] = c8_cv18[c8_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i109 = 0; c8_i109 < 87; c8_i109++) {
    c8_arr[c8_i109] = c8_dv45[c8_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i110 = 0; c8_i110 < 256; c8_i110++) {
    c8_tt[c8_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i111 = 0; c8_i111 < 87; c8_i111++) {
    c8_tt[c8_i111] = c8_arr[c8_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i112 = 0; c8_i112 < 256; c8_i112++) {
    c8_myarr256[c8_i112] = c8_tt[c8_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_t_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[223];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[223];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i113;
  static char_T c8_cv19[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c8_i114;
  static real_T c8_dv46[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i115;
  int32_T c8_i116;
  int32_T c8_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_eb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i113 = 0; c8_i113 < 223; c8_i113++) {
    c8_mystr[c8_i113] = c8_cv19[c8_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i114 = 0; c8_i114 < 223; c8_i114++) {
    c8_arr[c8_i114] = c8_dv46[c8_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i115 = 0; c8_i115 < 256; c8_i115++) {
    c8_tt[c8_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i116 = 0; c8_i116 < 223; c8_i116++) {
    c8_tt[c8_i116] = c8_arr[c8_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i117 = 0; c8_i117 < 256; c8_i117++) {
    c8_myarr256[c8_i117] = c8_tt[c8_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_u_encStr2Arr
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_myarr256[256])
{
  uint32_T c8_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[142];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[142];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i118;
  static char_T c8_cv20[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i119;
  static real_T c8_dv47[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i120;
  int32_T c8_i121;
  int32_T c8_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_fb_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  for (c8_i118 = 0; c8_i118 < 142; c8_i118++) {
    c8_mystr[c8_i118] = c8_cv20[c8_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
  for (c8_i119 = 0; c8_i119 < 142; c8_i119++) {
    c8_arr[c8_i119] = c8_dv47[c8_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
  c8_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_padsize = c8_maxarrsize - c8_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  for (c8_i120 = 0; c8_i120 < 256; c8_i120++) {
    c8_tt[c8_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
  for (c8_i121 = 0; c8_i121 < 142; c8_i121++) {
    c8_tt[c8_i121] = c8_arr[c8_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i122 = 0; c8_i122 < 256; c8_i122++) {
    c8_myarr256[c8_i122] = c8_tt[c8_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c8_randi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_lowhigh[2])
{
  real_T c8_r;
  real_T c8_low;
  real_T c8_high;
  int32_T c8_i123;
  static char_T c8_cv21[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c8_u[26];
  const mxArray *c8_y = NULL;
  real_T c8_s;
  real_T c8_x;
  real_T c8_b_x;
  c8_low = c8_lowhigh[0];
  c8_high = c8_lowhigh[1];
  if (c8_low <= c8_high) {
  } else {
    for (c8_i123 = 0; c8_i123 < 26; c8_i123++) {
      c8_u[c8_i123] = c8_cv21[c8_i123];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c8_y));
  }

  c8_s = (c8_high - c8_low) + 1.0;
  c8_r = c8_rand(chartInstance);
  c8_x = c8_r * c8_s;
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarFloor(c8_b_x);
  return c8_low + c8_b_x;
}

static real_T c8_rand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  return c8_eml_rand(chartInstance);
}

static real_T c8_eml_rand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  real_T c8_r;
  uint32_T c8_hoistedGlobal;
  uint32_T c8_d_state;
  uint32_T c8_e_state;
  uint32_T c8_s;
  uint32_T c8_u0;
  uint32_T c8_hi;
  uint32_T c8_lo;
  uint32_T c8_test1;
  uint32_T c8_test2;
  uint32_T c8_f_state;
  real_T c8_b_r;
  real_T c8_d0;
  int32_T c8_i124;
  uint32_T c8_icng;
  uint32_T c8_jsr;
  uint32_T c8_u1;
  uint32_T c8_u2;
  uint32_T c8_ui;
  uint32_T c8_b_ui;
  real_T c8_c_r;
  real_T c8_d1;
  uint32_T c8_uv2[625];
  int32_T c8_i125;
  real_T c8_d2;
  if (!chartInstance->c8_method_not_empty) {
    chartInstance->c8_method = 7U;
    chartInstance->c8_method_not_empty = true;
  }

  if (chartInstance->c8_method == 4U) {
    if (!chartInstance->c8_state_not_empty) {
      chartInstance->c8_state = 1144108930U;
      chartInstance->c8_state_not_empty = true;
    }

    c8_hoistedGlobal = chartInstance->c8_state;
    c8_d_state = c8_hoistedGlobal;
    c8_e_state = c8_d_state;
    c8_s = c8_e_state;
    c8_u0 = 127773U;
    if (c8_u0 == 0U) {
      c8_hi = MAX_uint32_T;
    } else {
      c8_hi = c8_s / c8_u0;
    }

    c8_lo = c8_s - c8_hi * 127773U;
    c8_test1 = 16807U * c8_lo;
    c8_test2 = 2836U * c8_hi;
    if (c8_test1 < c8_test2) {
      c8_f_state = (c8_test1 - c8_test2) + 2147483647U;
    } else {
      c8_f_state = c8_test1 - c8_test2;
    }

    c8_b_r = (real_T)c8_f_state * 4.6566128752457969E-10;
    c8_e_state = c8_f_state;
    c8_d0 = c8_b_r;
    chartInstance->c8_state = c8_e_state;
    c8_r = c8_d0;
  } else if (chartInstance->c8_method == 5U) {
    if (!chartInstance->c8_b_state_not_empty) {
      for (c8_i124 = 0; c8_i124 < 2; c8_i124++) {
        chartInstance->c8_b_state[c8_i124] = 362436069U + 158852560U * (uint32_T)
          c8_i124;
      }

      chartInstance->c8_b_state_not_empty = true;
    }

    c8_icng = chartInstance->c8_b_state[0];
    c8_jsr = chartInstance->c8_b_state[1];
    c8_u1 = c8_jsr;
    c8_u2 = c8_icng;
    c8_u2 = 69069U * c8_u2 + 1234567U;
    c8_u1 ^= c8_u1 << 13;
    c8_u1 ^= c8_u1 >> 17;
    c8_u1 ^= c8_u1 << 5;
    c8_ui = c8_u2 + c8_u1;
    chartInstance->c8_b_state[0] = c8_u2;
    chartInstance->c8_b_state[1] = c8_u1;
    c8_b_ui = c8_ui;
    c8_c_r = (real_T)c8_b_ui * 2.328306436538696E-10;
    c8_d1 = c8_c_r;
    c8_r = c8_d1;
  } else {
    if (!chartInstance->c8_c_state_not_empty) {
      c8_eml_rand_mt19937ar(chartInstance, c8_uv2);
      for (c8_i125 = 0; c8_i125 < 625; c8_i125++) {
        chartInstance->c8_c_state[c8_i125] = c8_uv2[c8_i125];
      }

      chartInstance->c8_c_state_not_empty = true;
    }

    c8_d2 = c8_c_eml_rand_mt19937ar(chartInstance, chartInstance->c8_c_state);
    c8_r = c8_d2;
  }

  return c8_r;
}

static void c8_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625])
{
  real_T c8_d3;
  int32_T c8_i126;
  c8_d3 = 5489.0;
  for (c8_i126 = 0; c8_i126 < 625; c8_i126++) {
    c8_d_state[c8_i126] = 0U;
  }

  c8_b_twister_state_vector(chartInstance, c8_d_state, c8_d3);
}

static void c8_twister_state_vector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_mt[625], real_T c8_seed, uint32_T c8_b_mt[625])
{
  int32_T c8_i127;
  for (c8_i127 = 0; c8_i127 < 625; c8_i127++) {
    c8_b_mt[c8_i127] = c8_mt[c8_i127];
  }

  c8_b_twister_state_vector(chartInstance, c8_b_mt, c8_seed);
}

static void c8_b_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625], uint32_T c8_e_state[625], real_T
   *c8_r)
{
  int32_T c8_i128;
  for (c8_i128 = 0; c8_i128 < 625; c8_i128++) {
    c8_e_state[c8_i128] = c8_d_state[c8_i128];
  }

  *c8_r = c8_c_eml_rand_mt19937ar(chartInstance, c8_e_state);
}

static void c8_eml_error
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  int32_T c8_i129;
  static char_T c8_cv22[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c8_u[37];
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  for (c8_i129 = 0; c8_i129 < 37; c8_i129++) {
    c8_u[c8_i129] = c8_cv22[c8_i129];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c8_y));
}

static real_T c8_b_randi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  real_T c8_r;
  real_T c8_x;
  real_T c8_b_x;
  c8_r = c8_rand(chartInstance);
  c8_x = c8_r * 2.0;
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarFloor(c8_b_x);
  return 1.0 + c8_b_x;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i130;
  real_T c8_b_inData[256];
  int32_T c8_i131;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i130 = 0; c8_i130 < 256; c8_i130++) {
    c8_b_inData[c8_i130] = (*(real_T (*)[256])c8_inData)[c8_i130];
  }

  for (c8_i131 = 0; c8_i131 < 256; c8_i131++) {
    c8_u[c8_i131] = c8_b_inData[c8_i131];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   real_T c8_y[256])
{
  real_T c8_dv48[256];
  int32_T c8_i132;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv48, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c8_i132 = 0; c8_i132 < 256; c8_i132++) {
    c8_y[c8_i132] = c8_dv48[c8_i132];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_poseBML;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i133;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_poseBML = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_poseBML), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_poseBML);
  for (c8_i133 = 0; c8_i133 < 256; c8_i133++) {
    (*(real_T (*)[256])c8_outData)[c8_i133] = c8_y[c8_i133];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_b_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_bmlID, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_bmlID), &c8_thisId);
  sf_mex_destroy(&c8_bmlID);
  return c8_y;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d4;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d4, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d4;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_bmlID;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_bmlID = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_bmlID), &c8_thisId);
  sf_mex_destroy(&c8_bmlID);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static boolean_T c8_d_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_aVarTruthTableCondition_2;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_aVarTruthTableCondition_2 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_aVarTruthTableCondition_2), &c8_thisId);
  sf_mex_destroy(&c8_aVarTruthTableCondition_2);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i134;
  real_T c8_b_inData[256];
  int32_T c8_i135;
  real_T c8_u[256];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i134 = 0; c8_i134 < 256; c8_i134++) {
    c8_b_inData[c8_i134] = (*(real_T (*)[256])c8_inData)[c8_i134];
  }

  for (c8_i135 = 0; c8_i135 < 256; c8_i135++) {
    c8_u[c8_i135] = c8_b_inData[c8_i135];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   real_T c8_y[256])
{
  real_T c8_dv49[256];
  int32_T c8_i136;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv49, 1, 0, 0U, 1, 0U, 1, 256);
  for (c8_i136 = 0; c8_i136 < 256; c8_i136++) {
    c8_y[c8_i136] = c8_dv49[c8_i136];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_myarr256;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[256];
  int32_T c8_i137;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_myarr256 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_myarr256), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_myarr256);
  for (c8_i137 = 0; c8_i137 < 256; c8_i137++) {
    (*(real_T (*)[256])c8_outData)[c8_i137] = c8_y[c8_i137];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i138;
  char_T c8_b_inData[94];
  int32_T c8_i139;
  char_T c8_u[94];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i138 = 0; c8_i138 < 94; c8_i138++) {
    c8_b_inData[c8_i138] = (*(char_T (*)[94])c8_inData)[c8_i138];
  }

  for (c8_i139 = 0; c8_i139 < 94; c8_i139++) {
    c8_u[c8_i139] = c8_b_inData[c8_i139];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i140;
  real_T c8_b_inData[94];
  int32_T c8_i141;
  real_T c8_u[94];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i140 = 0; c8_i140 < 94; c8_i140++) {
    c8_b_inData[c8_i140] = (*(real_T (*)[94])c8_inData)[c8_i140];
  }

  for (c8_i141 = 0; c8_i141 < 94; c8_i141++) {
    c8_u[c8_i141] = c8_b_inData[c8_i141];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i142;
  char_T c8_b_inData[88];
  int32_T c8_i143;
  char_T c8_u[88];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i142 = 0; c8_i142 < 88; c8_i142++) {
    c8_b_inData[c8_i142] = (*(char_T (*)[88])c8_inData)[c8_i142];
  }

  for (c8_i143 = 0; c8_i143 < 88; c8_i143++) {
    c8_u[c8_i143] = c8_b_inData[c8_i143];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i144;
  real_T c8_b_inData[88];
  int32_T c8_i145;
  real_T c8_u[88];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i144 = 0; c8_i144 < 88; c8_i144++) {
    c8_b_inData[c8_i144] = (*(real_T (*)[88])c8_inData)[c8_i144];
  }

  for (c8_i145 = 0; c8_i145 < 88; c8_i145++) {
    c8_u[c8_i145] = c8_b_inData[c8_i145];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_i_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i146;
  char_T c8_b_inData[86];
  int32_T c8_i147;
  char_T c8_u[86];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i146 = 0; c8_i146 < 86; c8_i146++) {
    c8_b_inData[c8_i146] = (*(char_T (*)[86])c8_inData)[c8_i146];
  }

  for (c8_i147 = 0; c8_i147 < 86; c8_i147++) {
    c8_u[c8_i147] = c8_b_inData[c8_i147];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_j_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i148;
  real_T c8_b_inData[86];
  int32_T c8_i149;
  real_T c8_u[86];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i148 = 0; c8_i148 < 86; c8_i148++) {
    c8_b_inData[c8_i148] = (*(real_T (*)[86])c8_inData)[c8_i148];
  }

  for (c8_i149 = 0; c8_i149 < 86; c8_i149++) {
    c8_u[c8_i149] = c8_b_inData[c8_i149];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_k_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i150;
  char_T c8_b_inData[161];
  int32_T c8_i151;
  char_T c8_u[161];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i150 = 0; c8_i150 < 161; c8_i150++) {
    c8_b_inData[c8_i150] = (*(char_T (*)[161])c8_inData)[c8_i150];
  }

  for (c8_i151 = 0; c8_i151 < 161; c8_i151++) {
    c8_u[c8_i151] = c8_b_inData[c8_i151];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_l_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i152;
  real_T c8_b_inData[161];
  int32_T c8_i153;
  real_T c8_u[161];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i152 = 0; c8_i152 < 161; c8_i152++) {
    c8_b_inData[c8_i152] = (*(real_T (*)[161])c8_inData)[c8_i152];
  }

  for (c8_i153 = 0; c8_i153 < 161; c8_i153++) {
    c8_u[c8_i153] = c8_b_inData[c8_i153];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_m_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i154;
  char_T c8_b_inData[157];
  int32_T c8_i155;
  char_T c8_u[157];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i154 = 0; c8_i154 < 157; c8_i154++) {
    c8_b_inData[c8_i154] = (*(char_T (*)[157])c8_inData)[c8_i154];
  }

  for (c8_i155 = 0; c8_i155 < 157; c8_i155++) {
    c8_u[c8_i155] = c8_b_inData[c8_i155];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_n_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i156;
  real_T c8_b_inData[157];
  int32_T c8_i157;
  real_T c8_u[157];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i156 = 0; c8_i156 < 157; c8_i156++) {
    c8_b_inData[c8_i156] = (*(real_T (*)[157])c8_inData)[c8_i156];
  }

  for (c8_i157 = 0; c8_i157 < 157; c8_i157++) {
    c8_u[c8_i157] = c8_b_inData[c8_i157];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_o_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i158;
  char_T c8_b_inData[91];
  int32_T c8_i159;
  char_T c8_u[91];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i158 = 0; c8_i158 < 91; c8_i158++) {
    c8_b_inData[c8_i158] = (*(char_T (*)[91])c8_inData)[c8_i158];
  }

  for (c8_i159 = 0; c8_i159 < 91; c8_i159++) {
    c8_u[c8_i159] = c8_b_inData[c8_i159];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_p_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i160;
  real_T c8_b_inData[91];
  int32_T c8_i161;
  real_T c8_u[91];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i160 = 0; c8_i160 < 91; c8_i160++) {
    c8_b_inData[c8_i160] = (*(real_T (*)[91])c8_inData)[c8_i160];
  }

  for (c8_i161 = 0; c8_i161 < 91; c8_i161++) {
    c8_u[c8_i161] = c8_b_inData[c8_i161];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_q_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i162;
  char_T c8_b_inData[87];
  int32_T c8_i163;
  char_T c8_u[87];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i162 = 0; c8_i162 < 87; c8_i162++) {
    c8_b_inData[c8_i162] = (*(char_T (*)[87])c8_inData)[c8_i162];
  }

  for (c8_i163 = 0; c8_i163 < 87; c8_i163++) {
    c8_u[c8_i163] = c8_b_inData[c8_i163];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_r_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i164;
  real_T c8_b_inData[87];
  int32_T c8_i165;
  real_T c8_u[87];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i164 = 0; c8_i164 < 87; c8_i164++) {
    c8_b_inData[c8_i164] = (*(real_T (*)[87])c8_inData)[c8_i164];
  }

  for (c8_i165 = 0; c8_i165 < 87; c8_i165++) {
    c8_u[c8_i165] = c8_b_inData[c8_i165];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_s_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i166;
  char_T c8_b_inData[93];
  int32_T c8_i167;
  char_T c8_u[93];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i166 = 0; c8_i166 < 93; c8_i166++) {
    c8_b_inData[c8_i166] = (*(char_T (*)[93])c8_inData)[c8_i166];
  }

  for (c8_i167 = 0; c8_i167 < 93; c8_i167++) {
    c8_u[c8_i167] = c8_b_inData[c8_i167];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_t_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i168;
  real_T c8_b_inData[93];
  int32_T c8_i169;
  real_T c8_u[93];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i168 = 0; c8_i168 < 93; c8_i168++) {
    c8_b_inData[c8_i168] = (*(real_T (*)[93])c8_inData)[c8_i168];
  }

  for (c8_i169 = 0; c8_i169 < 93; c8_i169++) {
    c8_u[c8_i169] = c8_b_inData[c8_i169];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_u_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i170;
  char_T c8_b_inData[95];
  int32_T c8_i171;
  char_T c8_u[95];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i170 = 0; c8_i170 < 95; c8_i170++) {
    c8_b_inData[c8_i170] = (*(char_T (*)[95])c8_inData)[c8_i170];
  }

  for (c8_i171 = 0; c8_i171 < 95; c8_i171++) {
    c8_u[c8_i171] = c8_b_inData[c8_i171];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_v_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i172;
  real_T c8_b_inData[95];
  int32_T c8_i173;
  real_T c8_u[95];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i172 = 0; c8_i172 < 95; c8_i172++) {
    c8_b_inData[c8_i172] = (*(real_T (*)[95])c8_inData)[c8_i172];
  }

  for (c8_i173 = 0; c8_i173 < 95; c8_i173++) {
    c8_u[c8_i173] = c8_b_inData[c8_i173];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_w_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i174;
  char_T c8_b_inData[97];
  int32_T c8_i175;
  char_T c8_u[97];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i174 = 0; c8_i174 < 97; c8_i174++) {
    c8_b_inData[c8_i174] = (*(char_T (*)[97])c8_inData)[c8_i174];
  }

  for (c8_i175 = 0; c8_i175 < 97; c8_i175++) {
    c8_u[c8_i175] = c8_b_inData[c8_i175];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_x_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i176;
  real_T c8_b_inData[97];
  int32_T c8_i177;
  real_T c8_u[97];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i176 = 0; c8_i176 < 97; c8_i176++) {
    c8_b_inData[c8_i176] = (*(real_T (*)[97])c8_inData)[c8_i176];
  }

  for (c8_i177 = 0; c8_i177 < 97; c8_i177++) {
    c8_u[c8_i177] = c8_b_inData[c8_i177];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_y_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i178;
  char_T c8_b_inData[92];
  int32_T c8_i179;
  char_T c8_u[92];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i178 = 0; c8_i178 < 92; c8_i178++) {
    c8_b_inData[c8_i178] = (*(char_T (*)[92])c8_inData)[c8_i178];
  }

  for (c8_i179 = 0; c8_i179 < 92; c8_i179++) {
    c8_u[c8_i179] = c8_b_inData[c8_i179];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i180;
  real_T c8_b_inData[92];
  int32_T c8_i181;
  real_T c8_u[92];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i180 = 0; c8_i180 < 92; c8_i180++) {
    c8_b_inData[c8_i180] = (*(real_T (*)[92])c8_inData)[c8_i180];
  }

  for (c8_i181 = 0; c8_i181 < 92; c8_i181++) {
    c8_u[c8_i181] = c8_b_inData[c8_i181];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i182;
  char_T c8_b_inData[68];
  int32_T c8_i183;
  char_T c8_u[68];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i182 = 0; c8_i182 < 68; c8_i182++) {
    c8_b_inData[c8_i182] = (*(char_T (*)[68])c8_inData)[c8_i182];
  }

  for (c8_i183 = 0; c8_i183 < 68; c8_i183++) {
    c8_u[c8_i183] = c8_b_inData[c8_i183];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i184;
  real_T c8_b_inData[68];
  int32_T c8_i185;
  real_T c8_u[68];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i184 = 0; c8_i184 < 68; c8_i184++) {
    c8_b_inData[c8_i184] = (*(real_T (*)[68])c8_inData)[c8_i184];
  }

  for (c8_i185 = 0; c8_i185 < 68; c8_i185++) {
    c8_u[c8_i185] = c8_b_inData[c8_i185];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_db_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i186;
  char_T c8_b_inData[223];
  int32_T c8_i187;
  char_T c8_u[223];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i186 = 0; c8_i186 < 223; c8_i186++) {
    c8_b_inData[c8_i186] = (*(char_T (*)[223])c8_inData)[c8_i186];
  }

  for (c8_i187 = 0; c8_i187 < 223; c8_i187++) {
    c8_u[c8_i187] = c8_b_inData[c8_i187];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i188;
  real_T c8_b_inData[223];
  int32_T c8_i189;
  real_T c8_u[223];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i188 = 0; c8_i188 < 223; c8_i188++) {
    c8_b_inData[c8_i188] = (*(real_T (*)[223])c8_inData)[c8_i188];
  }

  for (c8_i189 = 0; c8_i189 < 223; c8_i189++) {
    c8_u[c8_i189] = c8_b_inData[c8_i189];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i190;
  char_T c8_b_inData[142];
  int32_T c8_i191;
  char_T c8_u[142];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i190 = 0; c8_i190 < 142; c8_i190++) {
    c8_b_inData[c8_i190] = (*(char_T (*)[142])c8_inData)[c8_i190];
  }

  for (c8_i191 = 0; c8_i191 < 142; c8_i191++) {
    c8_u[c8_i191] = c8_b_inData[c8_i191];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i192;
  real_T c8_b_inData[142];
  int32_T c8_i193;
  real_T c8_u[142];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i192 = 0; c8_i192 < 142; c8_i192++) {
    c8_b_inData[c8_i192] = (*(real_T (*)[142])c8_inData)[c8_i192];
  }

  for (c8_i193 = 0; c8_i193 < 142; c8_i193++) {
    c8_u[c8_i193] = c8_b_inData[c8_i193];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i194;
  char_T c8_b_inData[183];
  int32_T c8_i195;
  char_T c8_u[183];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i194 = 0; c8_i194 < 183; c8_i194++) {
    c8_b_inData[c8_i194] = (*(char_T (*)[183])c8_inData)[c8_i194];
  }

  for (c8_i195 = 0; c8_i195 < 183; c8_i195++) {
    c8_u[c8_i195] = c8_b_inData[c8_i195];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i196;
  real_T c8_b_inData[183];
  int32_T c8_i197;
  real_T c8_u[183];
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i196 = 0; c8_i196 < 183; c8_i196++) {
    c8_b_inData[c8_i196] = (*(real_T (*)[183])c8_inData)[c8_i196];
  }

  for (c8_i197 = 0; c8_i197 < 183; c8_i197++) {
    c8_u[c8_i197] = c8_b_inData[c8_i197];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

const mxArray
  *sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  const mxArray *c8_rhs10 = NULL;
  const mxArray *c8_lhs10 = NULL;
  const mxArray *c8_rhs11 = NULL;
  const mxArray *c8_lhs11 = NULL;
  const mxArray *c8_rhs12 = NULL;
  const mxArray *c8_lhs12 = NULL;
  const mxArray *c8_rhs13 = NULL;
  const mxArray *c8_lhs13 = NULL;
  const mxArray *c8_rhs14 = NULL;
  const mxArray *c8_lhs14 = NULL;
  const mxArray *c8_rhs15 = NULL;
  const mxArray *c8_lhs15 = NULL;
  const mxArray *c8_rhs16 = NULL;
  const mxArray *c8_lhs16 = NULL;
  const mxArray *c8_rhs17 = NULL;
  const mxArray *c8_lhs17 = NULL;
  const mxArray *c8_rhs18 = NULL;
  const mxArray *c8_lhs18 = NULL;
  const mxArray *c8_rhs19 = NULL;
  const mxArray *c8_lhs19 = NULL;
  const mxArray *c8_rhs20 = NULL;
  const mxArray *c8_lhs20 = NULL;
  const mxArray *c8_rhs21 = NULL;
  const mxArray *c8_lhs21 = NULL;
  const mxArray *c8_rhs22 = NULL;
  const mxArray *c8_lhs22 = NULL;
  const mxArray *c8_rhs23 = NULL;
  const mxArray *c8_lhs23 = NULL;
  const mxArray *c8_rhs24 = NULL;
  const mxArray *c8_lhs24 = NULL;
  const mxArray *c8_rhs25 = NULL;
  const mxArray *c8_lhs25 = NULL;
  const mxArray *c8_rhs26 = NULL;
  const mxArray *c8_lhs26 = NULL;
  const mxArray *c8_rhs27 = NULL;
  const mxArray *c8_lhs27 = NULL;
  const mxArray *c8_rhs28 = NULL;
  const mxArray *c8_lhs28 = NULL;
  const mxArray *c8_rhs29 = NULL;
  const mxArray *c8_lhs29 = NULL;
  const mxArray *c8_rhs30 = NULL;
  const mxArray *c8_lhs30 = NULL;
  const mxArray *c8_rhs31 = NULL;
  const mxArray *c8_lhs31 = NULL;
  const mxArray *c8_rhs32 = NULL;
  const mxArray *c8_lhs32 = NULL;
  const mxArray *c8_rhs33 = NULL;
  const mxArray *c8_lhs33 = NULL;
  const mxArray *c8_rhs34 = NULL;
  const mxArray *c8_lhs34 = NULL;
  const mxArray *c8_rhs35 = NULL;
  const mxArray *c8_lhs35 = NULL;
  const mxArray *c8_rhs36 = NULL;
  const mxArray *c8_lhs36 = NULL;
  const mxArray *c8_rhs37 = NULL;
  const mxArray *c8_lhs37 = NULL;
  const mxArray *c8_rhs38 = NULL;
  const mxArray *c8_lhs38 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c8_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c8_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c8_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c8_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c8_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c8_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c8_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c8_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c8_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c8_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c8_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c8_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c8_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c8_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c8_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c8_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c8_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c8_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c8_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c8_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c8_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c8_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c8_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c8_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c8_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c8_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c8_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c8_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c8_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
  sf_mex_destroy(&c8_rhs10);
  sf_mex_destroy(&c8_lhs10);
  sf_mex_destroy(&c8_rhs11);
  sf_mex_destroy(&c8_lhs11);
  sf_mex_destroy(&c8_rhs12);
  sf_mex_destroy(&c8_lhs12);
  sf_mex_destroy(&c8_rhs13);
  sf_mex_destroy(&c8_lhs13);
  sf_mex_destroy(&c8_rhs14);
  sf_mex_destroy(&c8_lhs14);
  sf_mex_destroy(&c8_rhs15);
  sf_mex_destroy(&c8_lhs15);
  sf_mex_destroy(&c8_rhs16);
  sf_mex_destroy(&c8_lhs16);
  sf_mex_destroy(&c8_rhs17);
  sf_mex_destroy(&c8_lhs17);
  sf_mex_destroy(&c8_rhs18);
  sf_mex_destroy(&c8_lhs18);
  sf_mex_destroy(&c8_rhs19);
  sf_mex_destroy(&c8_lhs19);
  sf_mex_destroy(&c8_rhs20);
  sf_mex_destroy(&c8_lhs20);
  sf_mex_destroy(&c8_rhs21);
  sf_mex_destroy(&c8_lhs21);
  sf_mex_destroy(&c8_rhs22);
  sf_mex_destroy(&c8_lhs22);
  sf_mex_destroy(&c8_rhs23);
  sf_mex_destroy(&c8_lhs23);
  sf_mex_destroy(&c8_rhs24);
  sf_mex_destroy(&c8_lhs24);
  sf_mex_destroy(&c8_rhs25);
  sf_mex_destroy(&c8_lhs25);
  sf_mex_destroy(&c8_rhs26);
  sf_mex_destroy(&c8_lhs26);
  sf_mex_destroy(&c8_rhs27);
  sf_mex_destroy(&c8_lhs27);
  sf_mex_destroy(&c8_rhs28);
  sf_mex_destroy(&c8_lhs28);
  sf_mex_destroy(&c8_rhs29);
  sf_mex_destroy(&c8_lhs29);
  sf_mex_destroy(&c8_rhs30);
  sf_mex_destroy(&c8_lhs30);
  sf_mex_destroy(&c8_rhs31);
  sf_mex_destroy(&c8_lhs31);
  sf_mex_destroy(&c8_rhs32);
  sf_mex_destroy(&c8_lhs32);
  sf_mex_destroy(&c8_rhs33);
  sf_mex_destroy(&c8_lhs33);
  sf_mex_destroy(&c8_rhs34);
  sf_mex_destroy(&c8_lhs34);
  sf_mex_destroy(&c8_rhs35);
  sf_mex_destroy(&c8_lhs35);
  sf_mex_destroy(&c8_rhs36);
  sf_mex_destroy(&c8_lhs36);
  sf_mex_destroy(&c8_rhs37);
  sf_mex_destroy(&c8_lhs37);
  sf_mex_destroy(&c8_rhs38);
  sf_mex_destroy(&c8_lhs38);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), false);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), false);
  return c8_y;
}

static void c8_activate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  chartInstance->c8_sfEvent = c8_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_deactivate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c8_event_secs,
               chartInstance->c8_sfEvent);
}

static void c8_increment_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotI
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c8_temporalCounter_i1 < 7U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c8_temporalCounter_i1 + 1);
  }
}

static void c8_reset_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImita
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

void
  sf_exported_auto_activate_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_activate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_increment_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotI(chartInstance);
}

void
  sf_exported_auto_resetTemporalCounter_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_reset_counters_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImita(chartInstance);
}

void
  sf_exported_auto_deactivate_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_secs
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_deactivate_secsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm(chartInstance);
}

boolean_T
  sf_exported_auto_isStablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c8_isStable;
}

void sf_exported_auto_duringc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance);
}

void sf_exported_auto_enterc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_sendSBM(chartInstance);
  c8_sendBML(chartInstance);
  c8_enter_atomic_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil(chartInstance);
  c8_enter_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm(chartInstance);
}

void sf_exported_auto_exitc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_exit_internal_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmi(chartInstance);
  c8_b_sendSBM(chartInstance);
  c8_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_sendSBM(chartInstance);
  c8_sendBML(chartInstance);
}

void sf_exported_auto_disablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c8_b_sendSBM(chartInstance);
  c8_b_sendBML(chartInstance);
}

void
  sf_exported_auto_stepBuffersc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_initBuffersc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_activate_callc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  chartInstance->c8_sfEvent = CALL_EVENT;
}

void
  sf_exported_auto_increment_call_counterc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_reset_call_counterc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_deactivate_callc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_initc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance);
}

const mxArray
  *sf_exported_auto_getSimstatec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  const mxArray *c8_out = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_out = NULL;
  sf_mex_assign(&c8_out,
                sf_internal_get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
                (c8_S), false);
  return c8_out;
}

void
  sf_exported_auto_setSimstatec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S, const mxArray *c8_in)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    (c8_S, sf_mex_dup(c8_in));
  sf_mex_destroy(&c8_in);
}

void
  sf_exported_auto_check_state_inconsistency_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *c8_S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_arg[256])
{
  int32_T c8_i198;
  int32_T c8_i199;
  int32_T c8_i200;
  real_T (*c8_b_arg)[256];
  c8_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c8_i198 = 0; c8_i198 < 256; c8_i198++) {
    _SFD_DATA_RANGE_CHECK(c8_arg[c8_i198], 24U);
  }

  _SFD_SET_DATA_VALUE_PTR(24U, c8_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c8_arg, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c8_sfEvent);
  for (c8_i199 = 0; c8_i199 < 256; c8_i199++) {
    (*c8_b_arg)[c8_i199] = c8_arg[c8_i199];
  }

  for (c8_i200 = 0; c8_i200 < 256; c8_i200++) {
    _SFD_DATA_RANGE_CHECK((*c8_b_arg)[c8_i200], 24U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c8_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(24U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c8_sfEvent);
}

static void c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_arg[256])
{
  int32_T c8_i201;
  int32_T c8_i202;
  int32_T c8_i203;
  real_T (*c8_b_arg)[256];
  c8_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c8_i201 = 0; c8_i201 < 256; c8_i201++) {
    _SFD_DATA_RANGE_CHECK(c8_arg[c8_i201], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c8_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c8_arg, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i202 = 0; c8_i202 < 256; c8_i202++) {
    (*c8_b_arg)[c8_i202] = c8_arg[c8_i202];
  }

  for (c8_i203 = 0; c8_i203 < 256; c8_i203++) {
    _SFD_DATA_RANGE_CHECK((*c8_b_arg)[c8_i203], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void c8_rockPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[6];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv50[256];
  int32_T c8_i204;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[94];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[94];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i205;
  static char_T c8_cv23[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i206;
  static real_T c8_dv51[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i207;
  int32_T c8_i208;
  int32_T c8_i209;
  int32_T c8_i210;
  int32_T c8_i211;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 13);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 27);
    c8_encStr2Arr(chartInstance, c8_dv50);
    for (c8_i204 = 0; c8_i204 < 256; c8_i204++) {
      c8_poseBML[c8_i204] = c8_dv50[c8_i204];
    }

    c8_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_c_debug_family_names,
        c8_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_f_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
        c8_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_e_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U, c8_b_sf_marshallOut,
        c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
        c8_b_sf_marshallOut, c8_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U, c8_d_sf_marshallOut,
        c8_d_sf_marshallIn);
      for (c8_i205 = 0; c8_i205 < 94; c8_i205++) {
        c8_mystr[c8_i205] = c8_cv23[c8_i205];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
      c8_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
      for (c8_i206 = 0; c8_i206 < 94; c8_i206++) {
        c8_arr[c8_i206] = c8_dv51[c8_i206];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
      c8_ss = 94.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
      c8_padsize = c8_maxarrsize - c8_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
      for (c8_i207 = 0; c8_i207 < 256; c8_i207++) {
        c8_tt[c8_i207] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
      for (c8_i208 = 0; c8_i208 < 94; c8_i208++) {
        c8_tt[c8_i208] = c8_arr[c8_i208];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
      for (c8_i209 = 0; c8_i209 < 256; c8_i209++) {
        c8_myarr256[c8_i209] = c8_tt[c8_i209];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c8_i210 = 0; c8_i210 < 256; c8_i210++) {
        c8_poseBML[c8_i210] = c8_myarr256[c8_i210];
      }

      c8_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, 27);
      c8_encStr2Arr(chartInstance, c8_dv50);
      for (c8_i211 = 0; c8_i211 < 256; c8_i211++) {
        c8_poseBML[c8_i211] = c8_dv50[c8_i211];
      }

      c8_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c8_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_paperPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitat
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[6];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv52[256];
  int32_T c8_i212;
  int32_T c8_i213;
  int32_T c8_i214;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c8_d_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 13);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 15);
  if (CV_EML_IF(4, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 16);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 27);
    c8_b_encStr2Arr(chartInstance, c8_dv52);
    for (c8_i212 = 0; c8_i212 < 256; c8_i212++) {
      c8_poseBML[c8_i212] = c8_dv52[c8_i212];
    }

    c8_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, -27);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 17);
    if (CV_EML_IF(4, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 18);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 33);
      c8_c_encStr2Arr(chartInstance, c8_dv52);
      for (c8_i213 = 0; c8_i213 < 256; c8_i213++) {
        c8_poseBML[c8_i213] = c8_dv52[c8_i213];
      }

      c8_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, -33);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 20);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, 33);
      c8_c_encStr2Arr(chartInstance, c8_dv52);
      for (c8_i214 = 0; c8_i214 < 256; c8_i214++) {
        c8_poseBML[c8_i214] = c8_dv52[c8_i214];
      }

      c8_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, -33);
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c8_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_scissorsPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImi
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[6];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv53[256];
  int32_T c8_i215;
  int32_T c8_i216;
  int32_T c8_i217;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c8_g_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 13);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 15);
  if (CV_EML_IF(6, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 16);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 27);
    c8_c_encStr2Arr(chartInstance, c8_dv53);
    for (c8_i215 = 0; c8_i215 < 256; c8_i215++) {
      c8_poseBML[c8_i215] = c8_dv53[c8_i215];
    }

    c8_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, -27);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 17);
    if (CV_EML_IF(6, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 18);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 33);
      c8_b_encStr2Arr(chartInstance, c8_dv53);
      for (c8_i216 = 0; c8_i216 < 256; c8_i216++) {
        c8_poseBML[c8_i216] = c8_dv53[c8_i216];
      }

      c8_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, -33);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 20);
      CV_EML_FCN(6, 1);
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, 27);
      c8_c_encStr2Arr(chartInstance, c8_dv53);
      for (c8_i217 = 0; c8_i217 < 256; c8_i217++) {
        c8_poseBML[c8_i217] = c8_dv53[c8_i217];
      }

      c8_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c8_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_sbmID, real_T c8_poseSBM[256])
{
  uint32_T c8_debug_family_var_map[8];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  boolean_T c8_aVarTruthTableCondition_4;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv54[256];
  int32_T c8_i218;
  int32_T c8_i219;
  int32_T c8_i220;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[88];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[88];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i221;
  static char_T c8_cv24[88] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', ')', ')' };

  int32_T c8_i222;
  static real_T c8_dv55[88] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0 };

  int32_T c8_i223;
  int32_T c8_i224;
  int32_T c8_i225;
  int32_T c8_i226;
  int32_T c8_i227;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c8_h_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_4, 3U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sbmID, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseSBM, 7U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 6);
  c8_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 11);
  c8_aVarTruthTableCondition_1 = (c8_sbmID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_2 = (c8_sbmID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 19);
  c8_aVarTruthTableCondition_3 = (c8_sbmID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 23);
  c8_aVarTruthTableCondition_4 = (c8_sbmID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 25);
  if (CV_EML_IF(1, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 26);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 41);
    c8_d_encStr2Arr(chartInstance, c8_dv54);
    for (c8_i218 = 0; c8_i218 < 256; c8_i218++) {
      c8_poseSBM[c8_i218] = c8_dv54[c8_i218];
    }

    c8_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -41);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 27);
    if (CV_EML_IF(1, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 28);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 47);
      c8_e_encStr2Arr(chartInstance, c8_dv54);
      for (c8_i219 = 0; c8_i219 < 256; c8_i219++) {
        c8_poseSBM[c8_i219] = c8_dv54[c8_i219];
      }

      c8_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -47);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 29);
      if (CV_EML_IF(1, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 30);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 53);
        c8_f_encStr2Arr(chartInstance, c8_dv54);
        for (c8_i220 = 0; c8_i220 < 256; c8_i220++) {
          c8_poseSBM[c8_i220] = c8_dv54[c8_i220];
        }

        c8_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -53);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 31);
        if (CV_EML_IF(1, 1, 3, c8_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 32);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_l_debug_family_names,
            c8_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_h_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
            c8_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_g_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
            c8_b_sf_marshallOut, c8_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
            c8_d_sf_marshallOut, c8_d_sf_marshallIn);
          for (c8_i221 = 0; c8_i221 < 88; c8_i221++) {
            c8_mystr[c8_i221] = c8_cv24[c8_i221];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
          c8_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
          for (c8_i222 = 0; c8_i222 < 88; c8_i222++) {
            c8_arr[c8_i222] = c8_dv55[c8_i222];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
          c8_ss = 88.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
          c8_padsize = c8_maxarrsize - c8_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
          for (c8_i223 = 0; c8_i223 < 256; c8_i223++) {
            c8_tt[c8_i223] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
          for (c8_i224 = 0; c8_i224 < 88; c8_i224++) {
            c8_tt[c8_i224] = c8_arr[c8_i224];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
          for (c8_i225 = 0; c8_i225 < 256; c8_i225++) {
            c8_myarr256[c8_i225] = c8_tt[c8_i225];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c8_i226 = 0; c8_i226 < 256; c8_i226++) {
            c8_poseSBM[c8_i226] = c8_myarr256[c8_i226];
          }

          c8_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -59);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 34);
          CV_EML_FCN(1, 1);
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, 41);
          c8_d_encStr2Arr(chartInstance, c8_dv54);
          for (c8_i227 = 0; c8_i227 < 256; c8_i227++) {
            c8_poseSBM[c8_i227] = c8_dv54[c8_i227];
          }

          c8_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c8_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_idlePoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitate
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[22];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  boolean_T c8_aVarTruthTableCondition_4;
  boolean_T c8_aVarTruthTableCondition_5;
  boolean_T c8_aVarTruthTableCondition_6;
  boolean_T c8_aVarTruthTableCondition_7;
  boolean_T c8_aVarTruthTableCondition_8;
  boolean_T c8_aVarTruthTableCondition_9;
  boolean_T c8_aVarTruthTableCondition_10;
  boolean_T c8_aVarTruthTableCondition_11;
  boolean_T c8_aVarTruthTableCondition_12;
  boolean_T c8_aVarTruthTableCondition_13;
  boolean_T c8_aVarTruthTableCondition_14;
  boolean_T c8_aVarTruthTableCondition_15;
  boolean_T c8_aVarTruthTableCondition_16;
  boolean_T c8_aVarTruthTableCondition_17;
  boolean_T c8_aVarTruthTableCondition_18;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv56[256];
  int32_T c8_i228;
  int32_T c8_i229;
  int32_T c8_i230;
  int32_T c8_i231;
  int32_T c8_i232;
  int32_T c8_i233;
  int32_T c8_i234;
  int32_T c8_i235;
  int32_T c8_i236;
  int32_T c8_i237;
  int32_T c8_i238;
  int32_T c8_i239;
  int32_T c8_i240;
  int32_T c8_i241;
  int32_T c8_i242;
  int32_T c8_i243;
  int32_T c8_i244;
  int32_T c8_i245;
  int32_T c8_i246;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c8_m_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_4, 3U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_5, 4U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_6, 5U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_7, 6U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_8, 7U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_9, 8U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_10, 9U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_11, 10U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_12, 11U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_13, 12U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_14, 13U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_15, 14U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_16, 15U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_17, 16U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_18, 17U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 18U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 19U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 20U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 21U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 6);
  c8_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 7);
  c8_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 8);
  c8_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 10);
  c8_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 11);
  c8_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 12);
  c8_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 13);
  c8_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 14);
  c8_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 16);
  c8_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 17);
  c8_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 18);
  c8_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 19);
  c8_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 20);
  c8_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 24);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 27);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 30);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 33);
  c8_aVarTruthTableCondition_4 = (c8_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 36);
  c8_aVarTruthTableCondition_5 = (c8_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 39);
  c8_aVarTruthTableCondition_6 = (c8_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 42);
  c8_aVarTruthTableCondition_7 = (c8_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 45);
  c8_aVarTruthTableCondition_8 = (c8_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 48);
  c8_aVarTruthTableCondition_9 = (c8_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 51);
  c8_aVarTruthTableCondition_10 = (c8_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 54);
  c8_aVarTruthTableCondition_11 = (c8_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 57);
  c8_aVarTruthTableCondition_12 = (c8_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 60);
  c8_aVarTruthTableCondition_13 = (c8_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 63);
  c8_aVarTruthTableCondition_14 = (c8_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 66);
  c8_aVarTruthTableCondition_15 = (c8_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 69);
  c8_aVarTruthTableCondition_16 = (c8_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 72);
  c8_aVarTruthTableCondition_17 = (c8_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 75);
  c8_aVarTruthTableCondition_18 = (c8_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 77);
  if (CV_EML_IF(2, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 78);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 121);
    c8_g_encStr2Arr(chartInstance, c8_dv56);
    for (c8_i228 = 0; c8_i228 < 256; c8_i228++) {
      c8_poseBML[c8_i228] = c8_dv56[c8_i228];
    }

    c8_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -121);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 79);
    if (CV_EML_IF(2, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 80);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, MAX_int8_T);
      c8_h_encStr2Arr(chartInstance, c8_dv56);
      for (c8_i229 = 0; c8_i229 < 256; c8_i229++) {
        c8_poseBML[c8_i229] = c8_dv56[c8_i229];
      }

      c8_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -127);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 81);
      if (CV_EML_IF(2, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 82);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 133U);
        c8_i_encStr2Arr(chartInstance, c8_dv56);
        for (c8_i230 = 0; c8_i230 < 256; c8_i230++) {
          c8_poseBML[c8_i230] = c8_dv56[c8_i230];
        }

        c8_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -133);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 83);
        if (CV_EML_IF(2, 1, 3, c8_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 84);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 139U);
          c8_j_encStr2Arr(chartInstance, c8_dv56);
          for (c8_i231 = 0; c8_i231 < 256; c8_i231++) {
            c8_poseBML[c8_i231] = c8_dv56[c8_i231];
          }

          c8_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -139);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 85);
          if (CV_EML_IF(2, 1, 4, c8_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 86);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 145U);
            c8_k_encStr2Arr(chartInstance, c8_dv56);
            for (c8_i232 = 0; c8_i232 < 256; c8_i232++) {
              c8_poseBML[c8_i232] = c8_dv56[c8_i232];
            }

            c8_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -145);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 87);
            if (CV_EML_IF(2, 1, 5, c8_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 88);
              CV_EML_FCN(2, 11);
              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 181U);
              c8_l_encStr2Arr(chartInstance, c8_dv56);
              for (c8_i233 = 0; c8_i233 < 256; c8_i233++) {
                c8_poseBML[c8_i233] = c8_dv56[c8_i233];
              }

              c8_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -181);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 89);
              if (CV_EML_IF(2, 1, 6, c8_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 90);
                CV_EML_FCN(2, 3);
                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 133U);
                c8_i_encStr2Arr(chartInstance, c8_dv56);
                for (c8_i234 = 0; c8_i234 < 256; c8_i234++) {
                  c8_poseBML[c8_i234] = c8_dv56[c8_i234];
                }

                c8_updateDataWrittenToVector(chartInstance, 11U);
                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -133);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 91);
                if (CV_EML_IF(2, 1, 7, c8_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 92);
                  CV_EML_FCN(2, 5);
                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 145U);
                  c8_k_encStr2Arr(chartInstance, c8_dv56);
                  for (c8_i235 = 0; c8_i235 < 256; c8_i235++) {
                    c8_poseBML[c8_i235] = c8_dv56[c8_i235];
                  }

                  c8_updateDataWrittenToVector(chartInstance, 11U);
                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 93);
                  if (CV_EML_IF(2, 1, 8, c8_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 94);
                    CV_EML_FCN(2, 3);
                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 133U);
                    c8_i_encStr2Arr(chartInstance, c8_dv56);
                    for (c8_i236 = 0; c8_i236 < 256; c8_i236++) {
                      c8_poseBML[c8_i236] = c8_dv56[c8_i236];
                    }

                    c8_updateDataWrittenToVector(chartInstance, 11U);
                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 95);
                    if (CV_EML_IF(2, 1, 9, c8_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 96);
                      CV_EML_FCN(2, 10);
                      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 175U);
                      c8_m_encStr2Arr(chartInstance, c8_dv56);
                      for (c8_i237 = 0; c8_i237 < 256; c8_i237++) {
                        c8_poseBML[c8_i237] = c8_dv56[c8_i237];
                      }

                      c8_updateDataWrittenToVector(chartInstance, 11U);
                      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 97);
                      if (CV_EML_IF(2, 1, 10, c8_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 98);
                        CV_EML_FCN(2, 11);
                        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 181U);
                        c8_l_encStr2Arr(chartInstance, c8_dv56);
                        for (c8_i238 = 0; c8_i238 < 256; c8_i238++) {
                          c8_poseBML[c8_i238] = c8_dv56[c8_i238];
                        }

                        c8_updateDataWrittenToVector(chartInstance, 11U);
                        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 99);
                        if (CV_EML_IF(2, 1, 11, c8_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 100);
                          CV_EML_FCN(2, 8);
                          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 163U);
                          c8_n_encStr2Arr(chartInstance, c8_dv56);
                          for (c8_i239 = 0; c8_i239 < 256; c8_i239++) {
                            c8_poseBML[c8_i239] = c8_dv56[c8_i239];
                          }

                          c8_updateDataWrittenToVector(chartInstance, 11U);
                          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 101);
                          if (CV_EML_IF(2, 1, 12, c8_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 102);
                            CV_EML_FCN(2, 8);
                            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 163U);
                            c8_n_encStr2Arr(chartInstance, c8_dv56);
                            for (c8_i240 = 0; c8_i240 < 256; c8_i240++) {
                              c8_poseBML[c8_i240] = c8_dv56[c8_i240];
                            }

                            c8_updateDataWrittenToVector(chartInstance, 11U);
                            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 103);
                            if (CV_EML_IF(2, 1, 13,
                                          c8_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 104);
                              CV_EML_FCN(2, 7);
                              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 157U);
                              c8_o_encStr2Arr(chartInstance, c8_dv56);
                              for (c8_i241 = 0; c8_i241 < 256; c8_i241++) {
                                c8_poseBML[c8_i241] = c8_dv56[c8_i241];
                              }

                              c8_updateDataWrittenToVector(chartInstance, 11U);
                              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 105);
                              if (CV_EML_IF(2, 1, 14,
                                            c8_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 106);
                                CV_EML_FCN(2, 6);
                                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                              151U);
                                c8_p_encStr2Arr(chartInstance, c8_dv56);
                                for (c8_i242 = 0; c8_i242 < 256; c8_i242++) {
                                  c8_poseBML[c8_i242] = c8_dv56[c8_i242];
                                }

                                c8_updateDataWrittenToVector(chartInstance, 11U);
                                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, 107);
                                if (CV_EML_IF(2, 1, 15,
                                              c8_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                108);
                                  CV_EML_FCN(2, 5);
                                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                145U);
                                  c8_k_encStr2Arr(chartInstance, c8_dv56);
                                  for (c8_i243 = 0; c8_i243 < 256; c8_i243++) {
                                    c8_poseBML[c8_i243] = c8_dv56[c8_i243];
                                  }

                                  c8_updateDataWrittenToVector(chartInstance,
                                    11U);
                                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                109);
                                  if (CV_EML_IF(2, 1, 16,
                                                c8_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                  110);
                                    CV_EML_FCN(2, 8);
                                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                  163U);
                                    c8_n_encStr2Arr(chartInstance, c8_dv56);
                                    for (c8_i244 = 0; c8_i244 < 256; c8_i244++)
                                    {
                                      c8_poseBML[c8_i244] = c8_dv56[c8_i244];
                                    }

                                    c8_updateDataWrittenToVector(chartInstance,
                                      11U);
                                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c8_sfEvent,
                                                  111);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c8_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
                                                    112);
                                      CV_EML_FCN(2, 9);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
                                                    169U);
                                      c8_q_encStr2Arr(chartInstance, c8_dv56);
                                      for (c8_i245 = 0; c8_i245 < 256; c8_i245++)
                                      {
                                        c8_poseBML[c8_i245] = c8_dv56[c8_i245];
                                      }

                                      c8_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
                                                    114);
                                      CV_EML_FCN(2, 3);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
                                                    133U);
                                      c8_i_encStr2Arr(chartInstance, c8_dv56);
                                      for (c8_i246 = 0; c8_i246 < 256; c8_i246++)
                                      {
                                        c8_poseBML[c8_i246] = c8_dv56[c8_i246];
                                      }

                                      c8_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c8_sfEvent,
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

  _SFD_EML_CALL(2U, chartInstance->c8_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[7];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv57[256];
  int32_T c8_i247;
  int32_T c8_i248;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[97];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[97];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i249;
  static char_T c8_cv25[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c8_i250;
  static real_T c8_dv58[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c8_i251;
  int32_T c8_i252;
  int32_T c8_i253;
  int32_T c8_i254;
  int32_T c8_i255;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c8_y_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 6U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 9);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 12);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 15);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 17);
  if (CV_EML_IF(3, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 18);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 31);
    c8_r_encStr2Arr(chartInstance, c8_dv57);
    for (c8_i247 = 0; c8_i247 < 256; c8_i247++) {
      c8_poseBML[c8_i247] = c8_dv57[c8_i247];
    }

    c8_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, -31);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 19);
    if (CV_EML_IF(3, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 20);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 37);
      c8_s_encStr2Arr(chartInstance, c8_dv57);
      for (c8_i248 = 0; c8_i248 < 256; c8_i248++) {
        c8_poseBML[c8_i248] = c8_dv57[c8_i248];
      }

      c8_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, -37);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 21);
      if (CV_EML_IF(3, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 22);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 43);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_cb_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_x_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
          c8_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_w_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
          c8_d_sf_marshallOut, c8_d_sf_marshallIn);
        for (c8_i249 = 0; c8_i249 < 97; c8_i249++) {
          c8_mystr[c8_i249] = c8_cv25[c8_i249];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
        c8_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
        for (c8_i250 = 0; c8_i250 < 97; c8_i250++) {
          c8_arr[c8_i250] = c8_dv58[c8_i250];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
        c8_ss = 97.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
        c8_padsize = c8_maxarrsize - c8_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
        for (c8_i251 = 0; c8_i251 < 256; c8_i251++) {
          c8_tt[c8_i251] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
        for (c8_i252 = 0; c8_i252 < 97; c8_i252++) {
          c8_tt[c8_i252] = c8_arr[c8_i252];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
        for (c8_i253 = 0; c8_i253 < 256; c8_i253++) {
          c8_myarr256[c8_i253] = c8_tt[c8_i253];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c8_i254 = 0; c8_i254 < 256; c8_i254++) {
          c8_poseBML[c8_i254] = c8_myarr256[c8_i254];
        }

        c8_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, -43);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 24);
        CV_EML_FCN(3, 1);
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, 31);
        c8_r_encStr2Arr(chartInstance, c8_dv57);
        for (c8_i255 = 0; c8_i255 < 256; c8_i255++) {
          c8_poseBML[c8_i255] = c8_dv57[c8_i255];
        }

        c8_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, -31);
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c8_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, real_T c8_bmlID, real_T c8_poseBML[256])
{
  uint32_T c8_debug_family_var_map[7];
  boolean_T c8_aVarTruthTableCondition_1;
  boolean_T c8_aVarTruthTableCondition_2;
  boolean_T c8_aVarTruthTableCondition_3;
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_dv59[256];
  int32_T c8_i256;
  int32_T c8_i257;
  uint32_T c8_b_debug_family_var_map[9];
  real_T c8_maxarrsize;
  real_T c8_arr[183];
  real_T c8_ss;
  real_T c8_padsize;
  real_T c8_tt[256];
  char_T c8_mystr[183];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_myarr256[256];
  int32_T c8_i258;
  static char_T c8_cv26[183] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c8_i259;
  static real_T c8_dv60[183] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c8_i260;
  int32_T c8_i261;
  int32_T c8_i262;
  int32_T c8_i263;
  int32_T c8_i264;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c8_db_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_1, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_2, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_aVarTruthTableCondition_3, 2U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 4U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_bmlID, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_poseBML, 6U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(35, 0);
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 3);
  c8_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 4);
  c8_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 5);
  c8_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 10);
  c8_aVarTruthTableCondition_1 = (c8_bmlID == 1.0);
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 14);
  c8_aVarTruthTableCondition_2 = (c8_bmlID == 2.0);
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 18);
  c8_aVarTruthTableCondition_3 = (c8_bmlID == 3.0);
  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 20);
  if (CV_EML_IF(35, 1, 0, c8_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 21);
    CV_EML_FCN(35, 1);
    _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 34);
    c8_t_encStr2Arr(chartInstance, c8_dv59);
    for (c8_i256 = 0; c8_i256 < 256; c8_i256++) {
      c8_poseBML[c8_i256] = c8_dv59[c8_i256];
    }

    c8_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, -34);
  } else {
    _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 22);
    if (CV_EML_IF(35, 1, 1, c8_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 23);
      CV_EML_FCN(35, 2);
      _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 40);
      c8_u_encStr2Arr(chartInstance, c8_dv59);
      for (c8_i257 = 0; c8_i257 < 256; c8_i257++) {
        c8_poseBML[c8_i257] = c8_dv59[c8_i257];
      }

      c8_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, -40);
    } else {
      _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 24);
      if (CV_EML_IF(35, 1, 2, c8_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 25);
        CV_EML_FCN(35, 3);
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c8_gb_debug_family_names,
          c8_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_maxarrsize, 0U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c8_arr, 1U, c8_ib_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c8_ss, 2U, c8_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_padsize, 3U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_tt, 4U, c8_d_sf_marshallOut,
          c8_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c8_mystr, 5U, c8_hb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 6U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 7U,
          c8_b_sf_marshallOut, c8_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_myarr256, 8U,
          c8_d_sf_marshallOut, c8_d_sf_marshallIn);
        for (c8_i258 = 0; c8_i258 < 183; c8_i258++) {
          c8_mystr[c8_i258] = c8_cv26[c8_i258];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
        c8_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 6);
        for (c8_i259 = 0; c8_i259 < 183; c8_i259++) {
          c8_arr[c8_i259] = c8_dv60[c8_i259];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 7);
        c8_ss = 183.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
        c8_padsize = c8_maxarrsize - c8_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
        for (c8_i260 = 0; c8_i260 < 256; c8_i260++) {
          c8_tt[c8_i260] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 10);
        for (c8_i261 = 0; c8_i261 < 183; c8_i261++) {
          c8_tt[c8_i261] = c8_arr[c8_i261];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 11);
        for (c8_i262 = 0; c8_i262 < 256; c8_i262++) {
          c8_myarr256[c8_i262] = c8_tt[c8_i262];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c8_i263 = 0; c8_i263 < 256; c8_i263++) {
          c8_poseBML[c8_i263] = c8_myarr256[c8_i263];
        }

        c8_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, -46);
      } else {
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 27);
        CV_EML_FCN(35, 1);
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, 34);
        c8_t_encStr2Arr(chartInstance, c8_dv59);
        for (c8_i264 = 0; c8_i264 < 256; c8_i264++) {
          c8_poseBML[c8_i264] = c8_dv59[c8_i264];
        }

        c8_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(35U, chartInstance->c8_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c8_sendSBM
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c8_b_sendSBM
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c8_sendBML
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void c8_b_sendBML
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_handPoseSBTable
  (SimStruct *c8_S, real_T c8_sbmID, real_T c8_poseSBM[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSm(chartInstance,
    c8_sbmID, c8_poseSBM);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_idlePoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_idlePoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitate(chartInstance,
    c8_bmlID, c8_poseBML);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_initialPoseTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateS(chartInstance,
    c8_bmlID, c8_poseBML);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_paperPoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_paperPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitat(chartInstance,
    c8_bmlID, c8_poseBML);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_rockPoseTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_rockPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmil(chartInstance,
    c8_bmlID, c8_poseBML);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_scissorsPoseBradTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_scissorsPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImi(chartInstance,
    c8_bmlID, c8_poseBML);
}

void sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sendBML
  (SimStruct *c8_S, real_T c8_arg[256])
{
  int32_T c8_i265;
  real_T c8_b_arg[256];
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  for (c8_i265 = 0; c8_i265 < 256; c8_i265++) {
    c8_b_arg[c8_i265] = c8_arg[c8_i265];
  }

  c8_sendBMLc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_b_arg);
}

void sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_sendSBM
  (SimStruct *c8_S, real_T c8_arg[256])
{
  int32_T c8_i266;
  real_T c8_b_arg[256];
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  for (c8_i266 = 0; c8_i266 < 256; c8_i266++) {
    c8_b_arg[c8_i266] = c8_arg[c8_i266];
  }

  c8_sendSBMc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_b_arg);
}

void
  sf_exported_user_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_successTable
  (SimStruct *c8_S, real_T c8_bmlID, real_T c8_poseBML[256])
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c8_S))->instanceInfo
    )->chartInstance;
  c8_successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(chartInstance,
    c8_bmlID, c8_poseBML);
}

static const mxArray *c8_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int8_T c8_f_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int8_T c8_y;
  int8_T c8_i267;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i267, 1, 2, 0U, 0, 0U, 0);
  c8_y = c8_i267;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_secs;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int8_T c8_y;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_secs = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_secs), &c8_thisId);
  sf_mex_destroy(&c8_secs);
  *(int8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_g_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i268;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i268, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i268;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_h_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_tp_stateStart, const char_T
   *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateStart),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateStart);
  return c8_y;
}

static uint8_T c8_i_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u3;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u3, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u3;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_tp_stateStart;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c8_b_tp_stateStart = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_stateStart),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_stateStart);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint32_T c8_j_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_method, const char_T *c8_identifier)
{
  uint32_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_method),
    &c8_thisId);
  sf_mex_destroy(&c8_b_method);
  return c8_y;
}

static uint32_T c8_k_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint32_T c8_y;
  uint32_T c8_u4;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_method_not_empty = false;
  } else {
    chartInstance->c8_method_not_empty = true;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u4, 1, 7, 0U, 0, 0U, 0);
    c8_y = c8_u4;
  }

  sf_mex_destroy(&c8_u);
  return c8_y;
}

static uint32_T c8_l_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier)
{
  uint32_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_d_state), &c8_thisId);
  sf_mex_destroy(&c8_d_state);
  return c8_y;
}

static uint32_T c8_m_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint32_T c8_y;
  uint32_T c8_u5;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_state_not_empty = false;
  } else {
    chartInstance->c8_state_not_empty = true;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u5, 1, 7, 0U, 0, 0U, 0);
    c8_y = c8_u5;
  }

  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_n_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier,
   uint32_T c8_y[625])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_d_state), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_d_state);
}

static void c8_o_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   uint32_T c8_y[625])
{
  uint32_T c8_uv3[625];
  int32_T c8_i269;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_c_state_not_empty = false;
  } else {
    chartInstance->c8_c_state_not_empty = true;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c8_i269 = 0; c8_i269 < 625; c8_i269++) {
      c8_y[c8_i269] = c8_uv3[c8_i269];
    }
  }

  sf_mex_destroy(&c8_u);
}

static void c8_p_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_d_state, const char_T *c8_identifier,
   uint32_T c8_y[2])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_d_state), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_d_state);
}

static void c8_q_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
   uint32_T c8_y[2])
{
  uint32_T c8_uv4[2];
  int32_T c8_i270;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_b_state_not_empty = false;
  } else {
    chartInstance->c8_b_state_not_empty = true;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c8_i270 = 0; c8_i270 < 2; c8_i270++) {
      c8_y[c8_i270] = c8_uv4[c8_i270];
    }
  }

  sf_mex_destroy(&c8_u);
}

static const mxArray *c8_r_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T *
   c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  sf_mex_assign(&c8_y, c8_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_s_emlrt_marshallIn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_updateDataWrittenToVector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_vectorIndex)
{
  (void)chartInstance;
  c8_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c8_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c8_errorIfDataNotWrittenToFcn
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_vectorIndex, uint32_T c8_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c8_dataNumber, c8_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c8_vectorIndex, 0, 13, 1,
    0)]);
}

static void c8_b_twister_state_vector
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_mt[625], real_T c8_seed)
{
  real_T c8_d5;
  uint32_T c8_u6;
  uint32_T c8_r;
  int32_T c8_mti;
  real_T c8_b_mti;
  real_T c8_d6;
  uint32_T c8_u7;
  (void)chartInstance;
  c8_d5 = c8_seed;
  if (c8_d5 < 4.294967296E+9) {
    if (c8_d5 >= 0.0) {
      c8_u6 = (uint32_T)c8_d5;
    } else {
      c8_u6 = 0U;
    }
  } else if (c8_d5 >= 4.294967296E+9) {
    c8_u6 = MAX_uint32_T;
  } else {
    c8_u6 = 0U;
  }

  c8_r = c8_u6;
  c8_mt[0] = c8_r;
  for (c8_mti = 0; c8_mti < 623; c8_mti++) {
    c8_b_mti = 2.0 + (real_T)c8_mti;
    c8_d6 = muDoubleScalarRound(c8_b_mti - 1.0);
    if (c8_d6 < 4.294967296E+9) {
      if (c8_d6 >= 0.0) {
        c8_u7 = (uint32_T)c8_d6;
      } else {
        c8_u7 = 0U;
      }
    } else if (c8_d6 >= 4.294967296E+9) {
      c8_u7 = MAX_uint32_T;
    } else {
      c8_u7 = 0U;
    }

    c8_r = (c8_r ^ c8_r >> 30U) * 1812433253U + c8_u7;
    c8_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c8_b_mti), 1, 625, 1, 0) - 1] = c8_r;
  }

  c8_mt[624] = 624U;
}

static real_T c8_c_eml_rand_mt19937ar
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_d_state[625])
{
  int32_T c8_i271;
  uint32_T c8_u[2];
  int32_T c8_j;
  real_T c8_b_j;
  uint32_T c8_mti;
  int32_T c8_kk;
  real_T c8_b_kk;
  uint32_T c8_y;
  uint32_T c8_b_y;
  uint32_T c8_c_y;
  int32_T c8_c_kk;
  uint32_T c8_d_y;
  uint32_T c8_e_y;
  uint32_T c8_f_y;
  uint32_T c8_g_y;
  real_T c8_b_r;
  boolean_T c8_b1;
  boolean_T c8_isvalid;
  int32_T c8_k;
  int32_T c8_a;
  int32_T c8_b_a;
  real_T c8_d7;
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
    for (c8_i271 = 0; c8_i271 < 2; c8_i271++) {
      c8_u[c8_i271] = 0U;
    }

    for (c8_j = 0; c8_j < 2; c8_j++) {
      c8_b_j = 1.0 + (real_T)c8_j;
      c8_mti = c8_d_state[624] + 1U;
      if ((real_T)c8_mti >= 625.0) {
        for (c8_kk = 0; c8_kk < 227; c8_kk++) {
          c8_b_kk = 1.0 + (real_T)c8_kk;
          c8_y = (c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c8_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c8_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c8_b_y = c8_y;
          c8_c_y = c8_b_y;
          if ((real_T)(c8_c_y & 1U) == 0.0) {
            c8_c_y >>= 1U;
          } else {
            c8_c_y = c8_c_y >> 1U ^ 2567483615U;
          }

          c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c8_b_kk), 1, 625, 1, 0) - 1] =
            c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c8_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c8_c_y;
        }

        for (c8_c_kk = 0; c8_c_kk < 396; c8_c_kk++) {
          c8_b_kk = 228.0 + (real_T)c8_c_kk;
          c8_y = (c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c8_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c8_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c8_d_y = c8_y;
          c8_e_y = c8_d_y;
          if ((real_T)(c8_e_y & 1U) == 0.0) {
            c8_e_y >>= 1U;
          } else {
            c8_e_y = c8_e_y >> 1U ^ 2567483615U;
          }

          c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c8_b_kk), 1, 625, 1, 0) - 1] =
            c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c8_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c8_e_y;
        }

        c8_y = (c8_d_state[623] & 2147483648U) | (c8_d_state[0] & 2147483647U);
        c8_f_y = c8_y;
        c8_g_y = c8_f_y;
        if ((real_T)(c8_g_y & 1U) == 0.0) {
          c8_g_y >>= 1U;
        } else {
          c8_g_y = c8_g_y >> 1U ^ 2567483615U;
        }

        c8_d_state[623] = c8_d_state[396] ^ c8_g_y;
        c8_mti = 1U;
      }

      c8_y = c8_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mti), 1, 625, 1, 0)
        - 1];
      c8_d_state[624] = c8_mti;
      c8_y ^= c8_y >> 11U;
      c8_y ^= c8_y << 7U & 2636928640U;
      c8_y ^= c8_y << 15U & 4022730752U;
      c8_y ^= c8_y >> 18U;
      c8_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c8_b_j), 1, 2, 1, 0) - 1] = c8_y;
    }

    c8_u[0] >>= 5U;
    c8_u[1] >>= 6U;
    c8_b_r = 1.1102230246251565E-16 * ((real_T)c8_u[0] * 6.7108864E+7 + (real_T)
      c8_u[1]);
    if (c8_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c8_d_state[624] >= 1.0) {
        if ((real_T)c8_d_state[624] < 625.0) {
          c8_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c8_b1 = false;
      }

      c8_isvalid = c8_b1;
      if (c8_isvalid) {
        c8_isvalid = false;
        c8_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c8_k < 625)) {
          if ((real_T)c8_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c8_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c8_a = c8_k;
            c8_b_a = c8_a + 1;
            c8_k = c8_b_a;
          } else {
            c8_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c8_isvalid) {
        c8_eml_error(chartInstance);
        c8_d7 = 5489.0;
        c8_b_twister_state_vector(chartInstance, c8_d_state, c8_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c8_b_r;
}

static real_T c8_get_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#548) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_BOREDOM_THRESHOLD_address;
}

static void c8_set_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c8_b);
  if (chartInstance->c8_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#548) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_BOREDOM_THRESHOLD_address = c8_c;
}

static real_T *c8_access_BOREDOM_THRESHOLD
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c8_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#548) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_BOREDOM_THRESHOLD_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c8_c;
}

static real_T c8_get_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#557) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_avert_address;
}

static void c8_set_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c8_b);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#557) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_avert_address = c8_c;
}

static real_T *c8_access_avert
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c8_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#557) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_avert_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c8_c;
}

static real_T c8_get_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#542) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_bHand_address;
}

static void c8_set_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c8_b);
  if (chartInstance->c8_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#542) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_bHand_address = c8_c;
}

static real_T *c8_access_bHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c8_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#542) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_bHand_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c8_c;
}

static real_T c8_get_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#547) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_boredom_address;
}

static void c8_set_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c8_b);
  if (chartInstance->c8_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#547) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_boredom_address = c8_c;
}

static real_T *c8_access_boredom
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c8_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#547) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_boredom_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c8_c;
}

static real_T c8_get_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#540) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_diff_address;
}

static void c8_set_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c8_b);
  if (chartInstance->c8_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#540) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_diff_address = c8_c;
}

static real_T *c8_access_diff
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c8_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#540) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_diff_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c8_c;
}

static real_T c8_get_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#551) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_isPosing_address;
}

static void c8_set_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c8_b);
  if (chartInstance->c8_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#551) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_isPosing_address = c8_c;
}

static real_T *c8_access_isPosing
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c8_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#551) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_isPosing_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c8_c;
}

static real_T c8_get_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#556) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_isSmiling_address;
}

static void c8_set_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c8_b);
  if (chartInstance->c8_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#556) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_isSmiling_address = c8_c;
}

static real_T *c8_access_isSmiling
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c8_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#556) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_isSmiling_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c8_c;
}

static real_T c8_get_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#553) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_p_address;
}

static void c8_set_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c8_b);
  if (chartInstance->c8_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#553) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_p_address = c8_c;
}

static real_T *c8_access_p
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c8_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#553) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_p_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c8_c;
}

static real_T c8_get_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c8_b);
  if (chartInstance->c8_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#552) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_r_address;
}

static void c8_set_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c8_b);
  if (chartInstance->c8_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#552) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_r_address = c8_c;
}

static real_T *c8_access_r
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c8_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#552) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_r_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c8_c;
}

static real_T c8_get_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c8_b);
  if (chartInstance->c8_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#549) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_randAvertGazeChance_address;
}

static void c8_set_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c8_b);
  if (chartInstance->c8_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#549) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_randAvertGazeChance_address = c8_c;
}

static real_T *c8_access_randAvertGazeChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c8_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#549) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_randAvertGazeChance_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c8_c;
}

static real_T c8_get_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c8_b);
  if (chartInstance->c8_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#550) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_randPoseChance_address;
}

static void c8_set_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c8_b);
  if (chartInstance->c8_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#550) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_randPoseChance_address = c8_c;
}

static real_T *c8_access_randPoseChance
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c8_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#550) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_randPoseChance_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c8_c;
}

static real_T c8_get_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c8_b);
  if (chartInstance->c8_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#546) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_randSmile_address;
}

static void c8_set_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c8_b);
  if (chartInstance->c8_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#546) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_randSmile_address = c8_c;
}

static real_T *c8_access_randSmile
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c8_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#546) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_randSmile_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c8_c;
}

static real_T c8_get_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c8_b);
  if (chartInstance->c8_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#554) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_s_address;
}

static void c8_set_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c8_b);
  if (chartInstance->c8_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#554) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_s_address = c8_c;
}

static real_T *c8_access_s
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c8_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#554) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_s_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c8_c;
}

static real_T c8_get_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c8_b);
  if (chartInstance->c8_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#545) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_smileN_address;
}

static void c8_set_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c8_b);
  if (chartInstance->c8_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#545) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_smileN_address = c8_c;
}

static real_T *c8_access_smileN
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c8_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#545) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_smileN_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c8_c;
}

static real_T c8_get_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c8_b);
  if (chartInstance->c8_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#539) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_temp_address;
}

static void c8_set_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c8_b);
  if (chartInstance->c8_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#539) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_temp_address = c8_c;
}

static real_T *c8_access_temp
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c8_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#539) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_temp_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c8_c;
}

static real_T c8_get_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c8_b);
  if (chartInstance->c8_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#541) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c8_uHand_address;
}

static void c8_set_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b, real_T c8_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c8_b);
  if (chartInstance->c8_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#541) in the initialization routine of the chart.\n");
  }

  *chartInstance->c8_uHand_address = c8_c;
}

static real_T *c8_access_uHand
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c8_b)
{
  real_T *c8_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c8_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#541) in the initialization routine of the chart.\n");
  }

  c8_c = chartInstance->c8_uHand_address;
  if (c8_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c8_c;
}

static void init_dsm_address_info
  (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
   *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c8_BOREDOM_THRESHOLD_address,
    &chartInstance->c8_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c8_avert_address, &chartInstance->c8_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c8_bHand_address, &chartInstance->c8_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c8_boredom_address, &chartInstance->c8_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c8_diff_address, &chartInstance->c8_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c8_isPosing_address, &chartInstance->c8_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isSmiling", (void **)
    &chartInstance->c8_isSmiling_address, &chartInstance->c8_isSmiling_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c8_p_address, &chartInstance->c8_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c8_r_address, &chartInstance->c8_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c8_randAvertGazeChance_address,
    &chartInstance->c8_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c8_randPoseChance_address,
    &chartInstance->c8_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSmile", (void **)
    &chartInstance->c8_randSmile_address, &chartInstance->c8_randSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c8_s_address, &chartInstance->c8_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileN", (void **)
    &chartInstance->c8_smileN_address, &chartInstance->c8_smileN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c8_temp_address, &chartInstance->c8_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c8_uHand_address, &chartInstance->c8_uHand_index);
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

void sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_check_sum(mxArray *
  plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3369379557U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2057310555U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(550128900U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2232270412U);
}

mxArray
  *sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ze8uFFS2WxXPaAahSvvsxC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray
  *sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray
  *sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"bWinT\",},{M[1],M[86],T\"bradHand\",},{M[1],M[84],T\"gameState\",},{M[1],M[106],T\"round\",},{M[1],M[94],T\"uWinT\",},{M[1],M[87],T\"userHand\",},{M[1],M[88],T\"win\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile\",},{M[9],M[0],T\"is_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile\",},{M[11],M[107],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x13[54 83 58 59 62 61 64 67 69 71 78 77 82],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
      *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance =
      (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
           8,
           36,
           42,
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
        init_script_number_translation
          (_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
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
          _SFD_SET_DATA_PROPS(22,11,0,0,"isSmiling");
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
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(35,0,2);
          _SFD_CH_SUBSTATE_COUNT(27);
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
          _SFD_CH_SUBSTATE_INDEX(23,31);
          _SFD_CH_SUBSTATE_INDEX(24,32);
          _SFD_CH_SUBSTATE_INDEX(25,33);
          _SFD_CH_SUBSTATE_INDEX(26,34);
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
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(32,0);
          _SFD_ST_SUBSTATE_COUNT(33,0);
          _SFD_ST_SUBSTATE_COUNT(34,0);
        }

        _SFD_CV_INIT_CHART(27,1,0,0);

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
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,
                             "rockPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,401);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",401,-1,563);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",563,-1,725);
        _SFD_CV_INIT_EML_IF(5,1,0,225,255,286,399);
        _SFD_CV_INIT_EML_IF(5,1,1,286,320,351,399);
        _SFD_CV_INIT_EML(4,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,
                             "paperPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,409);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",409,-1,566);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",566,-1,721);
        _SFD_CV_INIT_EML_IF(4,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(4,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(6,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,
                             "scissorsPoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,418);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",418,-1,576);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",576,-1,736);
        _SFD_CV_INIT_EML_IF(6,1,0,242,272,303,416);
        _SFD_CV_INIT_EML_IF(6,1,1,303,337,368,416);
        _SFD_CV_INIT_EML(1,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,
                             "handPoseSBTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
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
                             "idlePoseBradTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,2812);
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
        _SFD_CV_INIT_EML_FCN(3,0,
                             "initialPoseTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,537);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",537,-1,682);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",682,-1,848);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",848,-1,1013);
        _SFD_CV_INIT_EML_IF(3,1,0,296,326,357,535);
        _SFD_CV_INIT_EML_IF(3,1,1,357,391,422,535);
        _SFD_CV_INIT_EML_IF(3,1,2,422,456,487,535);
        _SFD_CV_INIT_EML(35,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(35,0,
                             "successTablec8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile",
                             0,-1,566);
        _SFD_CV_INIT_EML_FCN(35,1,"aFcnTruthTableAction_1",566,-1,858);
        _SFD_CV_INIT_EML_FCN(35,2,"aFcnTruthTableAction_2",858,-1,1075);
        _SFD_CV_INIT_EML_FCN(35,3,"aFcnTruthTableAction_3",1075,-1,1327);
        _SFD_CV_INIT_EML_IF(35,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(35,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(35,1,2,451,485,516,564);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
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
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(40,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(22,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(22,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
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

        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(26,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(26,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(33,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(33,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(36,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(36,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
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
          real_T *c8_gameState;
          real_T *c8_inputUser;
          real_T *c8_bradHand;
          real_T *c8_userHand;
          real_T *c8_win;
          real_T *c8_bWinT;
          real_T *c8_uWinT;
          real_T *c8_round;
          c8_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c8_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c8_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c8_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c8_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c8_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c8_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c8_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c8_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c8_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c8_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c8_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c8_smileN_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c8_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c8_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c8_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(15U,
            chartInstance->c8_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c8_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c8_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c8_r_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c8_p_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c8_s_address);
          _SFD_SET_DATA_VALUE_PTR(21U, c8_round);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c8_isSmiling_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c8_avert_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "lXLXtx6Wt7UO9Jb4zsXgz";
}

static void
  sf_opaque_initialize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
  initialize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (void *chartInstanceVar)
{
  enable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (void *chartInstanceVar)
{
  disable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (void *chartInstanceVar)
{
  sf_gateway_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*)
    get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile();/* state var info */
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

extern void
  sf_internal_set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*)
    sf_get_sim_state_info_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct* S)
{
  return NULL;
}

static void
  sf_opaque_set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct* S, const mxArray *st)
{
}

static void
  sf_opaque_terminate_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
       chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_optimization_info();
    }

    finalize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
      ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
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
  initSimStructsc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
    ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *S)
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
    initialize_params_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
      ((SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,8,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,9);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=9; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4035285515U));
  ssSetChecksum1(S,(4247880672U));
  ssSetChecksum2(S,(21776634U));
  ssSetChecksum3(S,(3487189107U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(SimStruct
  *S)
{
  SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct
    *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance =
    (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct *)
    utMalloc(sizeof
             (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile;
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

void c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_ARP_02_RPSsmile_GloveAtomicBradNotImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
