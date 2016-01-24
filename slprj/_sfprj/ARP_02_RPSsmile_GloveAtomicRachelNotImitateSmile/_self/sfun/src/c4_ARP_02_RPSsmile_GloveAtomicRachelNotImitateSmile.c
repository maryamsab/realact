/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_sfun.h"
#include "c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c4_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_gameOver                 ((uint8_T)1U)
#define c4_IN_stateBoredPose1          ((uint8_T)2U)
#define c4_IN_stateBradWin             ((uint8_T)3U)
#define c4_IN_stateBrowUp              ((uint8_T)4U)
#define c4_IN_stateCompare             ((uint8_T)5U)
#define c4_IN_stateGo                  ((uint8_T)6U)
#define c4_IN_stateHeadNeutral1        ((uint8_T)7U)
#define c4_IN_stateHeadNeutral2        ((uint8_T)8U)
#define c4_IN_stateIfSmile             ((uint8_T)9U)
#define c4_IN_stateNeckBack            ((uint8_T)10U)
#define c4_IN_stateNoWin               ((uint8_T)11U)
#define c4_IN_statePoseFingersCLose    ((uint8_T)12U)
#define c4_IN_statePosePaper           ((uint8_T)13U)
#define c4_IN_statePoseReady           ((uint8_T)14U)
#define c4_IN_statePoseReturnFinger    ((uint8_T)15U)
#define c4_IN_statePoseRock            ((uint8_T)16U)
#define c4_IN_statePoseScissors        ((uint8_T)17U)
#define c4_IN_statePoseSmile           ((uint8_T)18U)
#define c4_IN_statePoseSmileWin        ((uint8_T)19U)
#define c4_IN_stateRandom1             ((uint8_T)20U)
#define c4_IN_stateRandomHand          ((uint8_T)21U)
#define c4_IN_stateReadUserHand        ((uint8_T)22U)
#define c4_IN_stateReady               ((uint8_T)23U)
#define c4_IN_stateShowHands           ((uint8_T)24U)
#define c4_IN_stateShowResult          ((uint8_T)25U)
#define c4_IN_stateSmile               ((uint8_T)26U)
#define c4_IN_stateStart               ((uint8_T)27U)
#define c4_IN_stateUserWin             ((uint8_T)28U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[5] = { "aVarTruthTableCondition_1",
  "nargin", "nargout", "bmlID", "poseBML" };

static const char * c4_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_c_debug_family_names[5] = { "aVarTruthTableCondition_1",
  "nargin", "nargout", "bmlID", "poseBML" };

static const char * c4_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c4_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_g_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c4_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_l_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

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

static const char * c4_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_u_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c4_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_x_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c4_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c4_dataWrittenToVector[14];

/* Function Declarations */
static void initialize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void
  initialize_params_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void enable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void disable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNot
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_ARP_02_RPSsmile_GloveAtomicRach
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void finalize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void sf_gateway_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_enter_atomic_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_enter_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_exit_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateS
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_initc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void initSimStructsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_enter_atomic_stateReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_gameOver
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateHeadNeutral2
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateIfSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_enter_atomic_stateGo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateGo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateNeckBack
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateRandomHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseFingersCLose
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePosePaper
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseRock
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseScissors
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateReadUserHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_enter_atomic_stateShowHands
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateShowHands
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseReturnFinger
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateCompare
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateBradWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateNoWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateRandom1
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_stateHeadNeutral1
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_statePoseSmileWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_b_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_c_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_d_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_e_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_f_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_g_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_h_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_i_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_j_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_k_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_l_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_m_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_n_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_o_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static void c4_p_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256]);
static real_T c4_randi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_lowhigh[2]);
static real_T c4_rand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static real_T c4_eml_rand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625]);
static void c4_twister_state_vector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625]);
static void c4_b_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
   *c4_r);
static void c4_eml_error
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   real_T c4_y[256]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_b_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_bmlID, const char_T *c4_identifier);
static real_T c4_c_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_d_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   real_T c4_y[256]);
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
static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_activate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_deactivate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_increment_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_reset_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_arg[256]);
static void c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_arg[256]);
static void c4_paperPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotIm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_scissorsPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_rockPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_sbmID, real_T c4_poseSBM[256]);
static void c4_idlePoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static void c4_sendSBM
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_b_sendSBM
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_sendBML
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static void c4_b_sendBML
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);
static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int8_T c4_f_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_h_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_tp_stateStart, const char_T
   *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint32_T c4_j_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier);
static uint32_T c4_k_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint32_T c4_l_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier);
static uint32_T c4_m_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_n_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
   uint32_T c4_y[625]);
static void c4_o_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   uint32_T c4_y[625]);
static void c4_p_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
   uint32_T c4_y[2]);
static void c4_q_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   uint32_T c4_y[2]);
static const mxArray *c4_r_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T *
   c4_identifier);
static const mxArray *c4_s_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_updateDataWrittenToVector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_vectorIndex);
static void c4_errorIfDataNotWrittenToFcn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber);
static void c4_b_twister_state_vector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_mt[625], real_T c4_seed);
static real_T c4_c_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625]);
static real_T c4_get_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static real_T c4_get_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void c4_set_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b);
static void init_dsm_address_info
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void
  initialize_params_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void disable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNot
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
      == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateIfSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateNeckBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseRock) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateRandom1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateHeadNeutral1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_statePoseSmileWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile ==
      c4_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray
  *get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  uint32_T c4_h_hoistedGlobal;
  uint32_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  uint32_T c4_i_hoistedGlobal;
  uint32_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  int32_T c4_i0;
  uint32_T c4_j_u[625];
  const mxArray *c4_k_y = NULL;
  int32_T c4_i1;
  uint32_T c4_k_u[2];
  const mxArray *c4_l_y = NULL;
  uint8_T c4_j_hoistedGlobal;
  uint8_T c4_l_u;
  const mxArray *c4_m_y = NULL;
  uint8_T c4_k_hoistedGlobal;
  uint8_T c4_m_u;
  const mxArray *c4_n_y = NULL;
  uint8_T c4_l_hoistedGlobal;
  uint8_T c4_n_u;
  const mxArray *c4_o_y = NULL;
  real_T *c4_bWinT;
  real_T *c4_bradHand;
  real_T *c4_gameState;
  real_T *c4_round;
  real_T *c4_uWinT;
  real_T *c4_userHand;
  real_T *c4_win;
  c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(14, 1), false);
  c4_hoistedGlobal = *c4_bWinT;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_bradHand;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_gameState;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_round;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *c4_uWinT;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = *c4_userHand;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = *c4_win;
  c4_g_u = c4_g_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = chartInstance->c4_method;
  c4_h_u = c4_h_hoistedGlobal;
  c4_i_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_i_hoistedGlobal = chartInstance->c4_state;
  c4_i_u = c4_i_hoistedGlobal;
  c4_j_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 8, c4_j_y);
  for (c4_i0 = 0; c4_i0 < 625; c4_i0++) {
    c4_j_u[c4_i0] = chartInstance->c4_c_state[c4_i0];
  }

  c4_k_y = NULL;
  if (!chartInstance->c4_c_state_not_empty) {
    sf_mex_assign(&c4_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_j_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c4_y, 9, c4_k_y);
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_k_u[c4_i1] = chartInstance->c4_b_state[c4_i1];
  }

  c4_l_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_k_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c4_y, 10, c4_l_y);
  c4_j_hoistedGlobal =
    chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  c4_l_u = c4_j_hoistedGlobal;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 11, c4_m_y);
  c4_k_hoistedGlobal =
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  c4_m_u = c4_k_hoistedGlobal;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 12, c4_n_y);
  c4_l_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_n_u = c4_l_hoistedGlobal;
  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", &c4_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 13, c4_o_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  uint32_T c4_uv0[625];
  int32_T c4_i2;
  uint32_T c4_uv1[2];
  int32_T c4_i3;
  real_T *c4_bWinT;
  real_T *c4_bradHand;
  real_T *c4_gameState;
  real_T *c4_round;
  real_T *c4_uWinT;
  real_T *c4_userHand;
  real_T *c4_win;
  c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_bWinT = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "bWinT");
  *c4_bradHand = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 1)), "bradHand");
  *c4_gameState = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 2)), "gameState");
  *c4_round = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 3)), "round");
  *c4_uWinT = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 4)), "uWinT");
  *c4_userHand = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 5)), "userHand");
  *c4_win = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    6)), "win");
  chartInstance->c4_method = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 7)), "method");
  chartInstance->c4_state = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 8)), "state");
  c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 9)),
                        "state", c4_uv0);
  for (c4_i2 = 0; c4_i2 < 625; c4_i2++) {
    chartInstance->c4_c_state[c4_i2] = c4_uv0[c4_i2];
  }

  c4_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 10)),
                        "state", c4_uv1);
  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    chartInstance->c4_b_state[c4_i3] = c4_uv1[c4_i3];
  }

  chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 11)),
    "is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile");
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 12)),
    "is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile");
  chartInstance->c4_temporalCounter_i1 = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNot(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_ARP_02_RPSsmile_GloveAtomicRach
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_gameOver) {
      chartInstance->c4_tp_gameOver = 1U;
    } else {
      chartInstance->c4_tp_gameOver = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateBoredPose1) {
      chartInstance->c4_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c4_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateBradWin) {
      chartInstance->c4_tp_stateBradWin = 1U;
    } else {
      chartInstance->c4_tp_stateBradWin = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateBrowUp) {
      chartInstance->c4_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c4_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateCompare) {
      chartInstance->c4_tp_stateCompare = 1U;
    } else {
      chartInstance->c4_tp_stateCompare = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateGo) {
      chartInstance->c4_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateGo = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateHeadNeutral1) {
      chartInstance->c4_tp_stateHeadNeutral1 = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateHeadNeutral1 = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateHeadNeutral2) {
      chartInstance->c4_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateIfSmile) {
      chartInstance->c4_tp_stateIfSmile = 1U;
    } else {
      chartInstance->c4_tp_stateIfSmile = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateNeckBack) {
      chartInstance->c4_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateNoWin) {
      chartInstance->c4_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateNoWin = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseFingersCLose) {
      chartInstance->c4_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c4_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePosePaper) {
      chartInstance->c4_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_statePosePaper = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseReady) {
      chartInstance->c4_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_statePoseReady = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseReturnFinger) {
      chartInstance->c4_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c4_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseRock) {
      chartInstance->c4_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 17) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_statePoseRock = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseScissors) {
      chartInstance->c4_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 18) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseSmile) {
      chartInstance->c4_tp_statePoseSmile = 1U;
    } else {
      chartInstance->c4_tp_statePoseSmile = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_statePoseSmileWin) {
      chartInstance->c4_tp_statePoseSmileWin = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 20) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_statePoseSmileWin = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateRandom1) {
      chartInstance->c4_tp_stateRandom1 = 1U;
    } else {
      chartInstance->c4_tp_stateRandom1 = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateRandomHand) {
      chartInstance->c4_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c4_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateReadUserHand) {
      chartInstance->c4_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c4_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateReady) {
      chartInstance->c4_tp_stateReady = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 24) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateReady = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateShowHands) {
      chartInstance->c4_tp_stateShowHands = 1U;
    } else {
      chartInstance->c4_tp_stateShowHands = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateShowResult) {
      chartInstance->c4_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 26) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateShowResult = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateSmile) {
      chartInstance->c4_tp_stateSmile = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 27) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateSmile = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateStart) {
      chartInstance->c4_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 28) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateStart = 0U;
    }

    if (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        == c4_IN_stateUserWin) {
      chartInstance->c4_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 29) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateUserWin = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  c4_set_sim_state_side_effects_c4_ARP_02_RPSsmile_GloveAtomicRach(chartInstance);
}

static void c4_enter_atomic_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void c4_enter_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv0[256];
  int32_T c4_i4;
  real_T c4_dv1[256];
  real_T *c4_round;
  real_T *c4_bradHand;
  real_T *c4_userHand;
  real_T *c4_win;
  real_T *c4_gameState;
  real_T *c4_uWinT;
  real_T *c4_bWinT;
  c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateStart = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_cb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_BOREDOM_THRESHOLD(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  *c4_round = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_round, 21U);
  c4_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c4_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c4_set_bHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  *c4_bradHand = 3.0;
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_bradHand, 2U);
  *c4_userHand = 3.0;
  c4_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_userHand, 3U);
  *c4_win = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_win, 4U);
  *c4_gameState = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 0U);
  *c4_uWinT = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_uWinT, 10U);
  *c4_bWinT = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_bWinT, 9U);
  c4_set_isSmiling(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c4_set_smileDur(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c4_set_randSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c4_set_boredom(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c4_set_randAvertGazeChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c4_set_randPoseChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c4_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat(chartInstance,
    1.0, c4_dv0);
  for (c4_i4 = 0; c4_i4 < 256; c4_i4++) {
    c4_dv1[c4_i4] = c4_dv0[c4_i4];
  }

  c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
    c4_dv1);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_dv2[256];
  int32_T c4_i5;
  real_T c4_dv3[256];
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 1.0;
  boolean_T c4_d_out;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 0.0;
  real_T c4_dv4[2];
  real_T *c4_round;
  real_T *c4_gameState;
  boolean_T guard1 = false;
  c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_isStable = true;
  switch
    (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile) {
   case c4_IN_gameOver:
    CV_CHART_EVAL(3, 0, 1);
    c4_gameOver(chartInstance);
    break;

   case c4_IN_stateBoredPose1:
    CV_CHART_EVAL(3, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateBradWin:
    CV_CHART_EVAL(3, 0, 3);
    c4_stateBradWin(chartInstance);
    break;

   case c4_IN_stateBrowUp:
    CV_CHART_EVAL(3, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c4_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateCompare:
    CV_CHART_EVAL(3, 0, 5);
    c4_stateCompare(chartInstance);
    break;

   case c4_IN_stateGo:
    CV_CHART_EVAL(3, 0, 6);
    c4_stateGo(chartInstance);
    break;

   case c4_IN_stateHeadNeutral1:
    CV_CHART_EVAL(3, 0, 7);
    c4_stateHeadNeutral1(chartInstance);
    break;

   case c4_IN_stateHeadNeutral2:
    CV_CHART_EVAL(3, 0, 8);
    c4_stateHeadNeutral2(chartInstance);
    break;

   case c4_IN_stateIfSmile:
    CV_CHART_EVAL(3, 0, 9);
    c4_stateIfSmile(chartInstance);
    break;

   case c4_IN_stateNeckBack:
    CV_CHART_EVAL(3, 0, 10);
    c4_stateNeckBack(chartInstance);
    break;

   case c4_IN_stateNoWin:
    CV_CHART_EVAL(3, 0, 11);
    c4_stateNoWin(chartInstance);
    break;

   case c4_IN_statePoseFingersCLose:
    CV_CHART_EVAL(3, 0, 12);
    c4_statePoseFingersCLose(chartInstance);
    break;

   case c4_IN_statePosePaper:
    CV_CHART_EVAL(3, 0, 13);
    c4_statePosePaper(chartInstance);
    break;

   case c4_IN_statePoseReady:
    CV_CHART_EVAL(3, 0, 14);
    c4_statePoseReady(chartInstance);
    break;

   case c4_IN_statePoseReturnFinger:
    CV_CHART_EVAL(3, 0, 15);
    c4_statePoseReturnFinger(chartInstance);
    break;

   case c4_IN_statePoseRock:
    CV_CHART_EVAL(3, 0, 16);
    c4_statePoseRock(chartInstance);
    break;

   case c4_IN_statePoseScissors:
    CV_CHART_EVAL(3, 0, 17);
    c4_statePoseScissors(chartInstance);
    break;

   case c4_IN_statePoseSmile:
    CV_CHART_EVAL(3, 0, 18);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_stateGo = 1U;
    c4_enter_atomic_stateGo(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseSmileWin:
    CV_CHART_EVAL(3, 0, 19);
    c4_statePoseSmileWin(chartInstance);
    break;

   case c4_IN_stateRandom1:
    CV_CHART_EVAL(3, 0, 20);
    c4_stateRandom1(chartInstance);
    break;

   case c4_IN_stateRandomHand:
    CV_CHART_EVAL(3, 0, 21);
    c4_stateRandomHand(chartInstance);
    break;

   case c4_IN_stateReadUserHand:
    CV_CHART_EVAL(3, 0, 22);
    c4_stateReadUserHand(chartInstance);
    break;

   case c4_IN_stateReady:
    CV_CHART_EVAL(3, 0, 23);
    c4_stateReady(chartInstance);
    break;

   case c4_IN_stateShowHands:
    CV_CHART_EVAL(3, 0, 24);
    c4_stateShowHands(chartInstance);
    break;

   case c4_IN_stateShowResult:
    CV_CHART_EVAL(3, 0, 25);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                    (chartInstance->c4_temporalCounter_i1 >= 3))) {
      if (CV_EML_COND(5, 0, 1, *c4_round == 10.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c4_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c4_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c4_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_eb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      *c4_gameState = 3.0;
      c4_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c4_gameState, 0U);
      c4_set_boredom(chartInstance, 0, c4_get_boredom(chartInstance, 0) - 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_b_out = CV_EML_IF(3, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs)
                           && (chartInstance->c4_temporalCounter_i1 >= 3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          = c4_IN_stateReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateReady = 1U;
        c4_enter_atomic_stateReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U,
                     chartInstance->c4_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateSmile:
    CV_CHART_EVAL(3, 0, 26);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_sc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_c_out = CV_EML_IF(18, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                         (chartInstance->c4_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateNeckBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateNeckBack = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_lb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmi
        (chartInstance, 2.0, c4_dv2);
      for (c4_i5 = 0; c4_i5 < 256; c4_i5++) {
        c4_dv3[c4_i5] = c4_dv2[c4_i5];
      }

      c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        (chartInstance, c4_dv3);
      c4_set_isSmiling(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateStart:
    CV_CHART_EVAL(3, 0, 27);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_d_out = CV_EML_IF(1, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                         (chartInstance->c4_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateReady = 1U;
      c4_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateUserWin:
    CV_CHART_EVAL(3, 0, 28);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_e_out = CV_EML_IF(38, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                         (chartInstance->c4_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateRandom1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandom1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_bc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_dv4[0] = 0.0;
      c4_dv4[1] = c4_get_boredom(chartInstance, 0);
      c4_set_randSmile(chartInstance, 0, c4_randi(chartInstance, c4_dv4));
      ssUpdateDataStoreLog(chartInstance->S, 11);
      c4_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(3, 0, 0);
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void c4_exit_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateS
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  switch
    (chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile) {
   case c4_IN_gameOver:
    CV_CHART_EVAL(3, 0, 1);
    chartInstance->c4_tp_gameOver = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateBoredPose1:
    CV_CHART_EVAL(3, 0, 2);
    chartInstance->c4_tp_stateBoredPose1 = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateBradWin:
    CV_CHART_EVAL(3, 0, 3);
    chartInstance->c4_tp_stateBradWin = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateBrowUp:
    CV_CHART_EVAL(3, 0, 4);
    chartInstance->c4_tp_stateBrowUp = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateCompare:
    CV_CHART_EVAL(3, 0, 5);
    chartInstance->c4_tp_stateCompare = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateGo:
    CV_CHART_EVAL(3, 0, 6);
    chartInstance->c4_tp_stateGo = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateHeadNeutral1:
    CV_CHART_EVAL(3, 0, 7);
    chartInstance->c4_tp_stateHeadNeutral1 = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateHeadNeutral2:
    CV_CHART_EVAL(3, 0, 8);
    chartInstance->c4_tp_stateHeadNeutral2 = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateIfSmile:
    CV_CHART_EVAL(3, 0, 9);
    chartInstance->c4_tp_stateIfSmile = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateNeckBack:
    CV_CHART_EVAL(3, 0, 10);
    chartInstance->c4_tp_stateNeckBack = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateNoWin:
    CV_CHART_EVAL(3, 0, 11);
    chartInstance->c4_tp_stateNoWin = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseFingersCLose:
    CV_CHART_EVAL(3, 0, 12);
    chartInstance->c4_tp_statePoseFingersCLose = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePosePaper:
    CV_CHART_EVAL(3, 0, 13);
    chartInstance->c4_tp_statePosePaper = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseReady:
    CV_CHART_EVAL(3, 0, 14);
    chartInstance->c4_tp_statePoseReady = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseReturnFinger:
    CV_CHART_EVAL(3, 0, 15);
    chartInstance->c4_tp_statePoseReturnFinger = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseRock:
    CV_CHART_EVAL(3, 0, 16);
    chartInstance->c4_tp_statePoseRock = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseScissors:
    CV_CHART_EVAL(3, 0, 17);
    chartInstance->c4_tp_statePoseScissors = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseSmile:
    CV_CHART_EVAL(3, 0, 18);
    chartInstance->c4_tp_statePoseSmile = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_statePoseSmileWin:
    CV_CHART_EVAL(3, 0, 19);
    chartInstance->c4_tp_statePoseSmileWin = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandom1:
    CV_CHART_EVAL(3, 0, 20);
    chartInstance->c4_tp_stateRandom1 = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandomHand:
    CV_CHART_EVAL(3, 0, 21);
    chartInstance->c4_tp_stateRandomHand = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateReadUserHand:
    CV_CHART_EVAL(3, 0, 22);
    chartInstance->c4_tp_stateReadUserHand = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateReady:
    CV_CHART_EVAL(3, 0, 23);
    chartInstance->c4_tp_stateReady = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateShowHands:
    CV_CHART_EVAL(3, 0, 24);
    chartInstance->c4_tp_stateShowHands = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateShowResult:
    CV_CHART_EVAL(3, 0, 25);
    chartInstance->c4_tp_stateShowResult = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateSmile:
    CV_CHART_EVAL(3, 0, 26);
    chartInstance->c4_tp_stateSmile = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateStart:
    CV_CHART_EVAL(3, 0, 27);
    chartInstance->c4_tp_stateStart = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateUserWin:
    CV_CHART_EVAL(3, 0, 28);
    chartInstance->c4_tp_stateUserWin = 0U;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(3, 0, 0);
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    break;
  }
}

static void c4_initc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_gameOver = 0U;
  chartInstance->c4_tp_stateBoredPose1 = 0U;
  chartInstance->c4_tp_stateBradWin = 0U;
  chartInstance->c4_tp_stateBrowUp = 0U;
  chartInstance->c4_tp_stateCompare = 0U;
  chartInstance->c4_tp_stateGo = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateHeadNeutral1 = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateHeadNeutral2 = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateIfSmile = 0U;
  chartInstance->c4_tp_stateNeckBack = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateNoWin = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseFingersCLose = 0U;
  chartInstance->c4_tp_statePosePaper = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseReady = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseReturnFinger = 0U;
  chartInstance->c4_tp_statePoseRock = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseScissors = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseSmile = 0U;
  chartInstance->c4_tp_statePoseSmileWin = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateRandom1 = 0U;
  chartInstance->c4_tp_stateRandomHand = 0U;
  chartInstance->c4_tp_stateReadUserHand = 0U;
  chartInstance->c4_tp_stateReady = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateShowHands = 0U;
  chartInstance->c4_tp_stateShowResult = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateSmile = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateStart = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateUserWin = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    = 0U;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c4_enter_atomic_stateReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T *c4_round;
  real_T *c4_bradHand;
  real_T *c4_userHand;
  real_T *c4_gameState;
  real_T *c4_win;
  c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_db_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
  (*c4_round)++;
  c4_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_round, 21U);
  *c4_bradHand = 3.0;
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_bradHand, 2U);
  *c4_userHand = 3.0;
  c4_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_userHand, 3U);
  *c4_gameState = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 0U);
  *c4_win = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_win, 4U);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  real_T c4_dv5[256];
  int32_T c4_i6;
  real_T c4_dv6[256];
  int32_T c4_i7;
  real_T c4_dv7[256];
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  int32_T c4_i8;
  real_T c4_dv8[256];
  int32_T c4_i9;
  real_T c4_dv9[256];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(6, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                  (chartInstance->c4_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(6, 0, 1, c4_get_boredom(chartInstance, 0) <
                    c4_get_BOREDOM_THRESHOLD(chartInstance, 0) - 4.0)) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(6, 0, 0, false);
    CV_EML_IF(6, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_boredom(chartInstance, 0, c4_get_boredom(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c4_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_statePoseReady = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_fb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat
      (chartInstance, 2.0, c4_dv5);
    for (c4_i6 = 0; c4_i6 < 256; c4_i6++) {
      c4_dv6[c4_i6] = c4_dv5[c4_i6];
    }

    c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
      c4_dv6);
    c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
      (chartInstance, 2.0, c4_dv5);
    for (c4_i7 = 0; c4_i7 < 256; c4_i7++) {
      c4_dv7[c4_i7] = c4_dv5[c4_i7];
    }

    c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
      c4_dv7);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_gc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(2, 0, 0, c4_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateReady = 1U;
      c4_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_lc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_c_out = CV_EML_IF(7, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs)
                           && (chartInstance->c4_temporalCounter_i1 >= 1));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateReady = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          = c4_IN_statePoseReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_statePoseReady = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_fb_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat
          (chartInstance, 2.0, c4_dv5);
        for (c4_i8 = 0; c4_i8 < 256; c4_i8++) {
          c4_dv8[c4_i8] = c4_dv5[c4_i8];
        }

        c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          (chartInstance, c4_dv8);
        c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
          (chartInstance, 2.0, c4_dv5);
        for (c4_i9 = 0; c4_i9 < 256; c4_i9++) {
          c4_dv9[c4_i9] = c4_dv5[c4_i9];
        }

        c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          (chartInstance, c4_dv9);
        c4_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                     chartInstance->c4_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c4_sfEvent);
}

static void c4_gameOver
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv10[256];
  int32_T c4_i10;
  real_T c4_dv11[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_gameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_stateHeadNeutral2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateHeadNeutral2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_gb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat(chartInstance,
    2.0, c4_dv10);
  for (c4_i10 = 0; c4_i10 < 256; c4_i10++) {
    c4_dv11[c4_i10] = c4_dv10[c4_i10];
  }

  c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
    c4_dv11);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
}

static void c4_statePoseReady
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_dv12[2];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_mc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(8, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                  (chartInstance->c4_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(8, 0, 1, c4_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(8, 0, 0, true);
      CV_EML_IF(8, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(8, 0, 0, false);
    CV_EML_IF(8, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateIfSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateIfSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_hb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_dv12[0] = 0.0;
    c4_dv12[1] = c4_get_boredom(chartInstance, 0);
    c4_set_randSmile(chartInstance, 0, c4_randi(chartInstance, c4_dv12));
    ssUpdateDataStoreLog(chartInstance->S, 11);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c4_sfEvent);
}

static void c4_stateHeadNeutral2
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 0.0;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_dv13[256];
  int32_T c4_i11;
  real_T c4_dv14[256];
  real_T *c4_uWinT;
  real_T *c4_bWinT;
  c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_nc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(12, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_qc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    c4_b_out = CV_EML_IF(16, 0, 0, *c4_uWinT < *c4_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_jb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_isSmiling(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateBoredPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateBoredPose1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ob_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_r = c4_rand(chartInstance);
      c4_x = c4_r * 18.0;
      c4_b_x = c4_x;
      c4_b_x = muDoubleScalarFloor(c4_b_x);
      c4_r = 1.0 + c4_b_x;
      c4_idlePoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImi
        (chartInstance, c4_r, c4_dv13);
      for (c4_i11 = 0; c4_i11 < 256; c4_i11++) {
        c4_dv14[c4_i11] = c4_dv13[c4_i11];
      }

      c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        (chartInstance, c4_dv14);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c4_sfEvent);
}

static void c4_stateIfSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_pc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(11, 0, 0, c4_get_randSmile(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateIfSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_statePoseSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_kb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isSmiling(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_oc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(10, 0, 0, c4_get_randSmile(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateIfSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateGo;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateGo = 1U;
      c4_enter_atomic_stateGo(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateGo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ib_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c4_gameState = 1.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 0U);
  c4_set_isSmiling(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateGo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_rc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(17, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateRandomHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_mb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_r = c4_rand(chartInstance);
    c4_x = c4_r * 3.0;
    c4_b_x = c4_x;
    c4_b_x = muDoubleScalarFloor(c4_b_x);
    c4_r = c4_b_x;
    c4_set_bHand(chartInstance, 0, c4_r);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c4_sfEvent);
}

static void c4_stateNeckBack
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_dv15[256];
  int32_T c4_i12;
  real_T c4_dv16[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_tc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(19, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateNeckBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_nb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmi
      (chartInstance, 3.0, c4_dv15);
    for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
      c4_dv16[c4_i12] = c4_dv15[c4_i12];
    }

    c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
      c4_dv16);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c4_sfEvent);
}

static void c4_stateRandomHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_dv17[256];
  int32_T c4_i13;
  real_T c4_dv18[256];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  int32_T c4_i14;
  real_T c4_dv19[256];
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  int32_T c4_i15;
  real_T c4_dv20[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_vc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(23, 0, 0, c4_get_bHand(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_qb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_paperPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotIm
      (chartInstance, 1.0, c4_dv17);
    for (c4_i13 = 0; c4_i13 < 256; c4_i13++) {
      c4_dv18[c4_i13] = c4_dv17[c4_i13];
    }

    c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
      c4_dv18);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_uc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(22, 0, 0, c4_get_bHand(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_rb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c4_r = c4_rand(chartInstance);
      c4_x = c4_r * 2.0;
      c4_b_x = c4_x;
      c4_b_x = muDoubleScalarFloor(c4_b_x);
      c4_r = 1.0 + c4_b_x;
      c4_set_r(chartInstance, 0, c4_r);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      c4_rockPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
        (chartInstance, c4_get_r(chartInstance, 0), c4_dv17);
      for (c4_i14 = 0; c4_i14 < 256; c4_i14++) {
        c4_dv19[c4_i14] = c4_dv17[c4_i14];
      }

      c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        (chartInstance, c4_dv19);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_wc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_c_out = CV_EML_IF(21, 0, 0, c4_get_bHand(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          = c4_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_pb_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        c4_set_isPosing(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
          (chartInstance, 1.0, c4_dv17);
        for (c4_i15 = 0; c4_i15 < 256; c4_i15++) {
          c4_dv20[c4_i15] = c4_dv17[c4_i15];
        }

        c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          (chartInstance, c4_dv20);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                     chartInstance->c4_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c4_sfEvent);
}

static void c4_statePoseFingersCLose
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv21[256];
  int32_T c4_i16;
  real_T c4_dv22[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_sb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c4_scissorsPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNo(chartInstance,
    1.0, c4_dv21);
  for (c4_i16 = 0; c4_i16 < 256; c4_i16++) {
    c4_dv22[c4_i16] = c4_dv21[c4_i16];
  }

  c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
    c4_dv22);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c4_sfEvent);
}

static void c4_statePosePaper
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T *c4_inputUser;
  boolean_T guard1 = false;
  c4_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_yc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(25, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                  (chartInstance->c4_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(25, 0, 1, c4_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(25, 0, 0, true);
      CV_EML_IF(25, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(25, 0, 0, false);
    CV_EML_IF(25, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_tb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_set_uHand(chartInstance, 0, *c4_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c4_sfEvent);
}

static void c4_statePoseRock
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T *c4_inputUser;
  boolean_T guard1 = false;
  c4_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_xc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(24, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                  (chartInstance->c4_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(24, 0, 1, c4_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(24, 0, 0, true);
      CV_EML_IF(24, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(24, 0, 0, false);
    CV_EML_IF(24, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_tb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_set_uHand(chartInstance, 0, *c4_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c4_sfEvent);
}

static void c4_statePoseScissors
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T *c4_inputUser;
  boolean_T guard1 = false;
  c4_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ad_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(28, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                  (chartInstance->c4_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(28, 0, 1, c4_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(28, 0, 0, true);
      CV_EML_IF(28, 0, 0, true);
      c4_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(28, 0, 0, false);
    CV_EML_IF(28, 0, 0, false);
    c4_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseScissors = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_tb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_set_uHand(chartInstance, 0, *c4_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c4_sfEvent);
}

static void c4_stateReadUserHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_dv23[256];
  int32_T c4_i17;
  real_T c4_dv24[256];
  real_T *c4_inputUser;
  c4_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_bd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(27, 0, 0, c4_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_tb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_set_uHand(chartInstance, 0, *c4_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_cd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(30, 0, 0, c4_get_bHand(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_vb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_isPosing(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
        (chartInstance, 2.0, c4_dv23);
      for (c4_i17 = 0; c4_i17 < 256; c4_i17++) {
        c4_dv24[c4_i17] = c4_dv23[c4_i17];
      }

      c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
        (chartInstance, c4_dv24);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateShowHands;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateShowHands = 1U;
      c4_enter_atomic_stateShowHands(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateShowHands
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T *c4_gameState;
  real_T *c4_bradHand;
  real_T *c4_userHand;
  c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ub_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c4_gameState = 2.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 0U);
  *c4_bradHand = c4_get_bHand(chartInstance, 0);
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_bradHand, 2U);
  *c4_userHand = c4_get_uHand(chartInstance, 0);
  c4_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_userHand, 3U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateShowHands
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_y;
  real_T c4_d_x;
  real_T c4_e_x;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateShowHands = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_wb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_isPosing(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c4_set_temp(chartInstance, 0, c4_get_uHand(chartInstance, 0) - c4_get_bHand
              (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c4_hoistedGlobal = c4_get_temp(chartInstance, 0);
  c4_b_hoistedGlobal = c4_get_temp(chartInstance, 0);
  c4_A = c4_b_hoistedGlobal;
  c4_x = c4_A;
  c4_b_x = c4_x;
  c4_c_x = c4_b_x;
  c4_y = c4_c_x / 3.0;
  c4_d_x = c4_y;
  c4_e_x = c4_d_x;
  c4_e_x = muDoubleScalarFloor(c4_e_x);
  c4_set_diff(chartInstance, 0, c4_hoistedGlobal - 3.0 * c4_e_x);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c4_sfEvent);
}

static void c4_statePoseReturnFinger
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_statePoseReturnFinger = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_stateShowHands;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateShowHands = 1U;
  c4_enter_atomic_stateShowHands(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c4_sfEvent);
}

static void c4_stateCompare
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T *c4_win;
  real_T *c4_uWinT;
  real_T *c4_bWinT;
  boolean_T guard1 = false;
  c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ed_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(34, 0, 0, c4_get_diff(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_yb_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    *c4_win = 2.0;
    c4_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c4_win, 4U);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    (*c4_bWinT)++;
    c4_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c4_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_dd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(33, 0, 0, c4_get_diff(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_xb_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      *c4_win = 1.0;
      c4_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c4_win, 4U);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      (*c4_uWinT)++;
      c4_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c4_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fd_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(35, 0, 0, c4_get_diff(chartInstance, 0) != 1.0)) {
        if (CV_EML_COND(35, 0, 1, c4_get_diff(chartInstance, 0) != 2.0)) {
          CV_EML_MCDC(35, 0, 0, true);
          CV_EML_IF(35, 0, 0, true);
          c4_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(35, 0, 0, false);
        CV_EML_IF(35, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
          = c4_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ac_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        *c4_win = 0.0;
        c4_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c4_win, 4U);
        c4_set_isPosing(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 5);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c4_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c4_sfEvent);
}

static void c4_stateBradWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv25[2];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateBradWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
    c4_IN_stateRandom1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateRandom1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_bc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_dv25[0] = 0.0;
  c4_dv25[1] = c4_get_boredom(chartInstance, 0);
  c4_set_randSmile(chartInstance, 0, c4_randi(chartInstance, c4_dv25));
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c4_set_isPosing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c4_sfEvent);
}

static void c4_stateNoWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_dv26[2];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_gd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(37, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_bc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_dv26[0] = 0.0;
    c4_dv26[1] = c4_get_boredom(chartInstance, 0);
    c4_set_randSmile(chartInstance, 0, c4_randi(chartInstance, c4_dv26));
    ssUpdateDataStoreLog(chartInstance->S, 11);
    c4_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c4_sfEvent);
}

static void c4_stateRandom1
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_dv27[256];
  int32_T c4_i18;
  real_T c4_dv28[256];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_id_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(39, 0, 0, c4_get_randSmile(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandom1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateHeadNeutral1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_stateHeadNeutral1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_cc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat
      (chartInstance, 2.0, c4_dv27);
    for (c4_i18 = 0; c4_i18 < 256; c4_i18++) {
      c4_dv28[c4_i18] = c4_dv27[c4_i18];
    }

    c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
      c4_dv28);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(40, 0, 0, c4_get_randSmile(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandom1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
        c4_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ec_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_isPosing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 5);
      c4_set_isSmiling(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c4_sfEvent);
}

static void c4_stateHeadNeutral1
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(41, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateHeadNeutral1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_statePoseSmileWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_statePoseSmileWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_dc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isSmiling(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    c4_set_isPosing(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c4_sfEvent);
}

static void c4_statePoseSmileWin
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ld_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(42, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                     (chartInstance->c4_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_statePoseSmileWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile =
      c4_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ec_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_isPosing(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c4_set_isSmiling(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c4_sfEvent);
}

static void c4_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[86];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[86];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i19;
  static char_T c4_cv0[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i20;
  static real_T c4_dv29[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
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
  for (c4_i19 = 0; c4_i19 < 86; c4_i19++) {
    c4_mystr[c4_i19] = c4_cv0[c4_i19];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i20 = 0; c4_i20 < 86; c4_i20++) {
    c4_arr[c4_i20] = c4_dv29[c4_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i21 = 0; c4_i21 < 256; c4_i21++) {
    c4_tt[c4_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i22 = 0; c4_i22 < 86; c4_i22++) {
    c4_tt[c4_i22] = c4_arr[c4_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i23 = 0; c4_i23 < 256; c4_i23++) {
    c4_myarr256[c4_i23] = c4_tt[c4_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_b_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[94];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[94];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i24;
  static char_T c4_cv1[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i25;
  static real_T c4_dv30[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_e_debug_family_names,
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
  for (c4_i24 = 0; c4_i24 < 94; c4_i24++) {
    c4_mystr[c4_i24] = c4_cv1[c4_i24];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i25 = 0; c4_i25 < 94; c4_i25++) {
    c4_arr[c4_i25] = c4_dv30[c4_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i26 = 0; c4_i26 < 256; c4_i26++) {
    c4_tt[c4_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i27 = 0; c4_i27 < 94; c4_i27++) {
    c4_tt[c4_i27] = c4_arr[c4_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i28 = 0; c4_i28 < 256; c4_i28++) {
    c4_myarr256[c4_i28] = c4_tt[c4_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[165];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[165];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i29;
  static char_T c4_cv2[165] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
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

  int32_T c4_i30;
  static real_T c4_dv31[165] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
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

  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_h_debug_family_names,
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
  for (c4_i29 = 0; c4_i29 < 165; c4_i29++) {
    c4_mystr[c4_i29] = c4_cv2[c4_i29];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i30 = 0; c4_i30 < 165; c4_i30++) {
    c4_arr[c4_i30] = c4_dv31[c4_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i31 = 0; c4_i31 < 256; c4_i31++) {
    c4_tt[c4_i31] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i32 = 0; c4_i32 < 165; c4_i32++) {
    c4_tt[c4_i32] = c4_arr[c4_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i33 = 0; c4_i33 < 256; c4_i33++) {
    c4_myarr256[c4_i33] = c4_tt[c4_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_d_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[161];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[161];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i34;
  static char_T c4_cv3[161] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
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

  int32_T c4_i35;
  static real_T c4_dv32[161] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
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

  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
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
  for (c4_i34 = 0; c4_i34 < 161; c4_i34++) {
    c4_mystr[c4_i34] = c4_cv3[c4_i34];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i35 = 0; c4_i35 < 161; c4_i35++) {
    c4_arr[c4_i35] = c4_dv32[c4_i35];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i36 = 0; c4_i36 < 256; c4_i36++) {
    c4_tt[c4_i36] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i37 = 0; c4_i37 < 161; c4_i37++) {
    c4_tt[c4_i37] = c4_arr[c4_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i38 = 0; c4_i38 < 256; c4_i38++) {
    c4_myarr256[c4_i38] = c4_tt[c4_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_e_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i39;
  static char_T c4_cv4[93] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', '.', '0', '5', ')', ')' };

  int32_T c4_i40;
  static real_T c4_dv33[93] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 48.0, 53.0, 41.0, 41.0 };

  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_j_debug_family_names,
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
  for (c4_i39 = 0; c4_i39 < 93; c4_i39++) {
    c4_mystr[c4_i39] = c4_cv4[c4_i39];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i40 = 0; c4_i40 < 93; c4_i40++) {
    c4_arr[c4_i40] = c4_dv33[c4_i40];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i41 = 0; c4_i41 < 256; c4_i41++) {
    c4_tt[c4_i41] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i42 = 0; c4_i42 < 93; c4_i42++) {
    c4_tt[c4_i42] = c4_arr[c4_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i43 = 0; c4_i43 < 256; c4_i43++) {
    c4_myarr256[c4_i43] = c4_tt[c4_i43];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_f_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i44;
  static char_T c4_cv5[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i45;
  static real_T c4_dv34[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_m_debug_family_names,
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
  for (c4_i44 = 0; c4_i44 < 93; c4_i44++) {
    c4_mystr[c4_i44] = c4_cv5[c4_i44];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i45 = 0; c4_i45 < 93; c4_i45++) {
    c4_arr[c4_i45] = c4_dv34[c4_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i46 = 0; c4_i46 < 256; c4_i46++) {
    c4_tt[c4_i46] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i47 = 0; c4_i47 < 93; c4_i47++) {
    c4_tt[c4_i47] = c4_arr[c4_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i48 = 0; c4_i48 < 256; c4_i48++) {
    c4_myarr256[c4_i48] = c4_tt[c4_i48];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_g_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i49;
  static char_T c4_cv6[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'R', 'a', 'c',
    'h', 'e', 'l', '_', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l',
    'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c', 'h', 'C', 'h', 'e', 's',
    't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i50;
  static real_T c4_dv35[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 82.0, 97.0,
    99.0, 104.0, 101.0, 108.0, 95.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0,
    100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0, 114.0,
    97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0, 49.0, 34.0,
    32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_n_debug_family_names,
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
  for (c4_i49 = 0; c4_i49 < 104; c4_i49++) {
    c4_mystr[c4_i49] = c4_cv6[c4_i49];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i50 = 0; c4_i50 < 104; c4_i50++) {
    c4_arr[c4_i50] = c4_dv35[c4_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i51 = 0; c4_i51 < 256; c4_i51++) {
    c4_tt[c4_i51] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i52 = 0; c4_i52 < 104; c4_i52++) {
    c4_tt[c4_i52] = c4_arr[c4_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i53 = 0; c4_i53 < 256; c4_i53++) {
    c4_myarr256[c4_i53] = c4_tt[c4_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_h_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i54;
  static char_T c4_cv7[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i55;
  static real_T c4_dv36[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_o_debug_family_names,
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
  for (c4_i54 = 0; c4_i54 < 93; c4_i54++) {
    c4_mystr[c4_i54] = c4_cv7[c4_i54];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i55 = 0; c4_i55 < 93; c4_i55++) {
    c4_arr[c4_i55] = c4_dv36[c4_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i56 = 0; c4_i56 < 256; c4_i56++) {
    c4_tt[c4_i56] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i57 = 0; c4_i57 < 93; c4_i57++) {
    c4_tt[c4_i57] = c4_arr[c4_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i58 = 0; c4_i58 < 256; c4_i58++) {
    c4_myarr256[c4_i58] = c4_tt[c4_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_i_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[95];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[95];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i59;
  static char_T c4_cv8[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i60;
  static real_T c4_dv37[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_p_debug_family_names,
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
  for (c4_i59 = 0; c4_i59 < 95; c4_i59++) {
    c4_mystr[c4_i59] = c4_cv8[c4_i59];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i60 = 0; c4_i60 < 95; c4_i60++) {
    c4_arr[c4_i60] = c4_dv37[c4_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i61 = 0; c4_i61 < 256; c4_i61++) {
    c4_tt[c4_i61] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i62 = 0; c4_i62 < 95; c4_i62++) {
    c4_tt[c4_i62] = c4_arr[c4_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i63 = 0; c4_i63 < 256; c4_i63++) {
    c4_myarr256[c4_i63] = c4_tt[c4_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_j_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[88];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[88];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i64;
  static char_T c4_cv9[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i65;
  static real_T c4_dv38[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_q_debug_family_names,
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
  for (c4_i64 = 0; c4_i64 < 88; c4_i64++) {
    c4_mystr[c4_i64] = c4_cv9[c4_i64];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i65 = 0; c4_i65 < 88; c4_i65++) {
    c4_arr[c4_i65] = c4_dv38[c4_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i66 = 0; c4_i66 < 256; c4_i66++) {
    c4_tt[c4_i66] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i67 = 0; c4_i67 < 88; c4_i67++) {
    c4_tt[c4_i67] = c4_arr[c4_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i68 = 0; c4_i68 < 256; c4_i68++) {
    c4_myarr256[c4_i68] = c4_tt[c4_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_k_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i69;
  static char_T c4_cv10[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i70;
  static real_T c4_dv39[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_r_debug_family_names,
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
  for (c4_i69 = 0; c4_i69 < 93; c4_i69++) {
    c4_mystr[c4_i69] = c4_cv10[c4_i69];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i70 = 0; c4_i70 < 93; c4_i70++) {
    c4_arr[c4_i70] = c4_dv39[c4_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i71 = 0; c4_i71 < 256; c4_i71++) {
    c4_tt[c4_i71] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i72 = 0; c4_i72 < 93; c4_i72++) {
    c4_tt[c4_i72] = c4_arr[c4_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i73 = 0; c4_i73 < 256; c4_i73++) {
    c4_myarr256[c4_i73] = c4_tt[c4_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_l_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
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
  int32_T c4_i74;
  static char_T c4_cv11[107] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'R', 'a',
    'c', 'h', 'e', 'l', '_', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '@', 'I', 'd',
    'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c', 'h', 'T', 'e', 'm',
    'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i75;
  static real_T c4_dv40[107] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 82.0, 97.0,
    99.0, 104.0, 101.0, 108.0, 95.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0,
    100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0, 114.0,
    97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0, 76.0,
    102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
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
  for (c4_i74 = 0; c4_i74 < 107; c4_i74++) {
    c4_mystr[c4_i74] = c4_cv11[c4_i74];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i75 = 0; c4_i75 < 107; c4_i75++) {
    c4_arr[c4_i75] = c4_dv40[c4_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i76 = 0; c4_i76 < 256; c4_i76++) {
    c4_tt[c4_i76] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i77 = 0; c4_i77 < 107; c4_i77++) {
    c4_tt[c4_i77] = c4_arr[c4_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i78 = 0; c4_i78 < 256; c4_i78++) {
    c4_myarr256[c4_i78] = c4_tt[c4_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_m_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[97];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[97];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i79;
  static char_T c4_cv12[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i80;
  static real_T c4_dv41[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_t_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i79 = 0; c4_i79 < 97; c4_i79++) {
    c4_mystr[c4_i79] = c4_cv12[c4_i79];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i80 = 0; c4_i80 < 97; c4_i80++) {
    c4_arr[c4_i80] = c4_dv41[c4_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i81 = 0; c4_i81 < 256; c4_i81++) {
    c4_tt[c4_i81] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i82 = 0; c4_i82 < 97; c4_i82++) {
    c4_tt[c4_i82] = c4_arr[c4_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i83 = 0; c4_i83 < 256; c4_i83++) {
    c4_myarr256[c4_i83] = c4_tt[c4_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_n_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[68];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[68];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i84;
  static char_T c4_cv13[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i85;
  static real_T c4_dv42[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_v_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i84 = 0; c4_i84 < 68; c4_i84++) {
    c4_mystr[c4_i84] = c4_cv13[c4_i84];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i85 = 0; c4_i85 < 68; c4_i85++) {
    c4_arr[c4_i85] = c4_dv42[c4_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 68.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i86 = 0; c4_i86 < 256; c4_i86++) {
    c4_tt[c4_i86] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i87 = 0; c4_i87 < 68; c4_i87++) {
    c4_tt[c4_i87] = c4_arr[c4_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i88 = 0; c4_i88 < 256; c4_i88++) {
    c4_myarr256[c4_i88] = c4_tt[c4_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_o_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[223];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[223];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i89;
  static char_T c4_cv14[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c4_i90;
  static real_T c4_dv43[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_y_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i89 = 0; c4_i89 < 223; c4_i89++) {
    c4_mystr[c4_i89] = c4_cv14[c4_i89];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i90 = 0; c4_i90 < 223; c4_i90++) {
    c4_arr[c4_i90] = c4_dv43[c4_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i91 = 0; c4_i91 < 256; c4_i91++) {
    c4_tt[c4_i91] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i92 = 0; c4_i92 < 223; c4_i92++) {
    c4_tt[c4_i92] = c4_arr[c4_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i93 = 0; c4_i93 < 256; c4_i93++) {
    c4_myarr256[c4_i93] = c4_tt[c4_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_p_encStr2Arr
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[142];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[142];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i94;
  static char_T c4_cv15[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i95;
  static real_T c4_dv44[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ab_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i94 = 0; c4_i94 < 142; c4_i94++) {
    c4_mystr[c4_i94] = c4_cv15[c4_i94];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i95 = 0; c4_i95 < 142; c4_i95++) {
    c4_arr[c4_i95] = c4_dv44[c4_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i96 = 0; c4_i96 < 256; c4_i96++) {
    c4_tt[c4_i96] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i97 = 0; c4_i97 < 142; c4_i97++) {
    c4_tt[c4_i97] = c4_arr[c4_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i98 = 0; c4_i98 < 256; c4_i98++) {
    c4_myarr256[c4_i98] = c4_tt[c4_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_randi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_lowhigh[2])
{
  real_T c4_r;
  real_T c4_low;
  real_T c4_high;
  int32_T c4_i99;
  static char_T c4_cv16[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c4_u[26];
  const mxArray *c4_y = NULL;
  real_T c4_s;
  real_T c4_x;
  real_T c4_b_x;
  c4_low = c4_lowhigh[0];
  c4_high = c4_lowhigh[1];
  if (c4_low <= c4_high) {
  } else {
    for (c4_i99 = 0; c4_i99 < 26; c4_i99++) {
      c4_u[c4_i99] = c4_cv16[c4_i99];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c4_y));
  }

  c4_s = (c4_high - c4_low) + 1.0;
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * c4_s;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  return c4_low + c4_b_x;
}

static real_T c4_rand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  return c4_eml_rand(chartInstance);
}

static real_T c4_eml_rand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  real_T c4_r;
  uint32_T c4_hoistedGlobal;
  uint32_T c4_d_state;
  uint32_T c4_e_state;
  uint32_T c4_s;
  uint32_T c4_u0;
  uint32_T c4_hi;
  uint32_T c4_lo;
  uint32_T c4_test1;
  uint32_T c4_test2;
  uint32_T c4_f_state;
  real_T c4_b_r;
  real_T c4_d0;
  int32_T c4_i100;
  uint32_T c4_icng;
  uint32_T c4_jsr;
  uint32_T c4_u1;
  uint32_T c4_u2;
  uint32_T c4_ui;
  uint32_T c4_b_ui;
  real_T c4_c_r;
  real_T c4_d1;
  uint32_T c4_uv2[625];
  int32_T c4_i101;
  real_T c4_d2;
  if (!chartInstance->c4_method_not_empty) {
    chartInstance->c4_method = 7U;
    chartInstance->c4_method_not_empty = true;
  }

  if (chartInstance->c4_method == 4U) {
    if (!chartInstance->c4_state_not_empty) {
      chartInstance->c4_state = 1144108930U;
      chartInstance->c4_state_not_empty = true;
    }

    c4_hoistedGlobal = chartInstance->c4_state;
    c4_d_state = c4_hoistedGlobal;
    c4_e_state = c4_d_state;
    c4_s = c4_e_state;
    c4_u0 = 127773U;
    if (c4_u0 == 0U) {
      c4_hi = MAX_uint32_T;
    } else {
      c4_hi = c4_s / c4_u0;
    }

    c4_lo = c4_s - c4_hi * 127773U;
    c4_test1 = 16807U * c4_lo;
    c4_test2 = 2836U * c4_hi;
    if (c4_test1 < c4_test2) {
      c4_f_state = (c4_test1 - c4_test2) + 2147483647U;
    } else {
      c4_f_state = c4_test1 - c4_test2;
    }

    c4_b_r = (real_T)c4_f_state * 4.6566128752457969E-10;
    c4_e_state = c4_f_state;
    c4_d0 = c4_b_r;
    chartInstance->c4_state = c4_e_state;
    c4_r = c4_d0;
  } else if (chartInstance->c4_method == 5U) {
    if (!chartInstance->c4_b_state_not_empty) {
      for (c4_i100 = 0; c4_i100 < 2; c4_i100++) {
        chartInstance->c4_b_state[c4_i100] = 362436069U + 158852560U * (uint32_T)
          c4_i100;
      }

      chartInstance->c4_b_state_not_empty = true;
    }

    c4_icng = chartInstance->c4_b_state[0];
    c4_jsr = chartInstance->c4_b_state[1];
    c4_u1 = c4_jsr;
    c4_u2 = c4_icng;
    c4_u2 = 69069U * c4_u2 + 1234567U;
    c4_u1 ^= c4_u1 << 13;
    c4_u1 ^= c4_u1 >> 17;
    c4_u1 ^= c4_u1 << 5;
    c4_ui = c4_u2 + c4_u1;
    chartInstance->c4_b_state[0] = c4_u2;
    chartInstance->c4_b_state[1] = c4_u1;
    c4_b_ui = c4_ui;
    c4_c_r = (real_T)c4_b_ui * 2.328306436538696E-10;
    c4_d1 = c4_c_r;
    c4_r = c4_d1;
  } else {
    if (!chartInstance->c4_c_state_not_empty) {
      c4_eml_rand_mt19937ar(chartInstance, c4_uv2);
      for (c4_i101 = 0; c4_i101 < 625; c4_i101++) {
        chartInstance->c4_c_state[c4_i101] = c4_uv2[c4_i101];
      }

      chartInstance->c4_c_state_not_empty = true;
    }

    c4_d2 = c4_c_eml_rand_mt19937ar(chartInstance, chartInstance->c4_c_state);
    c4_r = c4_d2;
  }

  return c4_r;
}

static void c4_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625])
{
  real_T c4_d3;
  int32_T c4_i102;
  c4_d3 = 5489.0;
  for (c4_i102 = 0; c4_i102 < 625; c4_i102++) {
    c4_d_state[c4_i102] = 0U;
  }

  c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d3);
}

static void c4_twister_state_vector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625])
{
  int32_T c4_i103;
  for (c4_i103 = 0; c4_i103 < 625; c4_i103++) {
    c4_b_mt[c4_i103] = c4_mt[c4_i103];
  }

  c4_b_twister_state_vector(chartInstance, c4_b_mt, c4_seed);
}

static void c4_b_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
   *c4_r)
{
  int32_T c4_i104;
  for (c4_i104 = 0; c4_i104 < 625; c4_i104++) {
    c4_e_state[c4_i104] = c4_d_state[c4_i104];
  }

  *c4_r = c4_c_eml_rand_mt19937ar(chartInstance, c4_e_state);
}

static void c4_eml_error
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  int32_T c4_i105;
  static char_T c4_cv17[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c4_u[37];
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  for (c4_i105 = 0; c4_i105 < 37; c4_i105++) {
    c4_u[c4_i105] = c4_cv17[c4_i105];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c4_y));
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i106;
  real_T c4_b_inData[256];
  int32_T c4_i107;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i106 = 0; c4_i106 < 256; c4_i106++) {
    c4_b_inData[c4_i106] = (*(real_T (*)[256])c4_inData)[c4_i106];
  }

  for (c4_i107 = 0; c4_i107 < 256; c4_i107++) {
    c4_u[c4_i107] = c4_b_inData[c4_i107];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   real_T c4_y[256])
{
  real_T c4_dv45[256];
  int32_T c4_i108;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv45, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c4_i108 = 0; c4_i108 < 256; c4_i108++) {
    c4_y[c4_i108] = c4_dv45[c4_i108];
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
  int32_T c4_i109;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_poseBML = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
  for (c4_i109 = 0; c4_i109 < 256; c4_i109++) {
    (*(real_T (*)[256])c4_outData)[c4_i109] = c4_y[c4_i109];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_b_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_bmlID, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_bmlID), &c4_thisId);
  sf_mex_destroy(&c4_bmlID);
  return c4_y;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d4;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d4, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d4;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_bmlID;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_bmlID = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_bmlID), &c4_thisId);
  sf_mex_destroy(&c4_bmlID);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_d_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
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
  const mxArray *c4_aVarTruthTableCondition_1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_aVarTruthTableCondition_1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_aVarTruthTableCondition_1), &c4_thisId);
  sf_mex_destroy(&c4_aVarTruthTableCondition_1);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i110;
  real_T c4_b_inData[256];
  int32_T c4_i111;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i110 = 0; c4_i110 < 256; c4_i110++) {
    c4_b_inData[c4_i110] = (*(real_T (*)[256])c4_inData)[c4_i110];
  }

  for (c4_i111 = 0; c4_i111 < 256; c4_i111++) {
    c4_u[c4_i111] = c4_b_inData[c4_i111];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   real_T c4_y[256])
{
  real_T c4_dv46[256];
  int32_T c4_i112;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv46, 1, 0, 0U, 1, 0U, 1, 256);
  for (c4_i112 = 0; c4_i112 < 256; c4_i112++) {
    c4_y[c4_i112] = c4_dv46[c4_i112];
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
  int32_T c4_i113;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_myarr256 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
  for (c4_i113 = 0; c4_i113 < 256; c4_i113++) {
    (*(real_T (*)[256])c4_outData)[c4_i113] = c4_y[c4_i113];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i114;
  char_T c4_b_inData[86];
  int32_T c4_i115;
  char_T c4_u[86];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i114 = 0; c4_i114 < 86; c4_i114++) {
    c4_b_inData[c4_i114] = (*(char_T (*)[86])c4_inData)[c4_i114];
  }

  for (c4_i115 = 0; c4_i115 < 86; c4_i115++) {
    c4_u[c4_i115] = c4_b_inData[c4_i115];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i116;
  real_T c4_b_inData[86];
  int32_T c4_i117;
  real_T c4_u[86];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i116 = 0; c4_i116 < 86; c4_i116++) {
    c4_b_inData[c4_i116] = (*(real_T (*)[86])c4_inData)[c4_i116];
  }

  for (c4_i117 = 0; c4_i117 < 86; c4_i117++) {
    c4_u[c4_i117] = c4_b_inData[c4_i117];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i118;
  char_T c4_b_inData[94];
  int32_T c4_i119;
  char_T c4_u[94];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i118 = 0; c4_i118 < 94; c4_i118++) {
    c4_b_inData[c4_i118] = (*(char_T (*)[94])c4_inData)[c4_i118];
  }

  for (c4_i119 = 0; c4_i119 < 94; c4_i119++) {
    c4_u[c4_i119] = c4_b_inData[c4_i119];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i120;
  real_T c4_b_inData[94];
  int32_T c4_i121;
  real_T c4_u[94];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i120 = 0; c4_i120 < 94; c4_i120++) {
    c4_b_inData[c4_i120] = (*(real_T (*)[94])c4_inData)[c4_i120];
  }

  for (c4_i121 = 0; c4_i121 < 94; c4_i121++) {
    c4_u[c4_i121] = c4_b_inData[c4_i121];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i122;
  char_T c4_b_inData[165];
  int32_T c4_i123;
  char_T c4_u[165];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i122 = 0; c4_i122 < 165; c4_i122++) {
    c4_b_inData[c4_i122] = (*(char_T (*)[165])c4_inData)[c4_i122];
  }

  for (c4_i123 = 0; c4_i123 < 165; c4_i123++) {
    c4_u[c4_i123] = c4_b_inData[c4_i123];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 165),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i124;
  real_T c4_b_inData[165];
  int32_T c4_i125;
  real_T c4_u[165];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i124 = 0; c4_i124 < 165; c4_i124++) {
    c4_b_inData[c4_i124] = (*(real_T (*)[165])c4_inData)[c4_i124];
  }

  for (c4_i125 = 0; c4_i125 < 165; c4_i125++) {
    c4_u[c4_i125] = c4_b_inData[c4_i125];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 165), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_k_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i126;
  char_T c4_b_inData[161];
  int32_T c4_i127;
  char_T c4_u[161];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i126 = 0; c4_i126 < 161; c4_i126++) {
    c4_b_inData[c4_i126] = (*(char_T (*)[161])c4_inData)[c4_i126];
  }

  for (c4_i127 = 0; c4_i127 < 161; c4_i127++) {
    c4_u[c4_i127] = c4_b_inData[c4_i127];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_l_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i128;
  real_T c4_b_inData[161];
  int32_T c4_i129;
  real_T c4_u[161];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i128 = 0; c4_i128 < 161; c4_i128++) {
    c4_b_inData[c4_i128] = (*(real_T (*)[161])c4_inData)[c4_i128];
  }

  for (c4_i129 = 0; c4_i129 < 161; c4_i129++) {
    c4_u[c4_i129] = c4_b_inData[c4_i129];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_m_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i130;
  char_T c4_b_inData[93];
  int32_T c4_i131;
  char_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i130 = 0; c4_i130 < 93; c4_i130++) {
    c4_b_inData[c4_i130] = (*(char_T (*)[93])c4_inData)[c4_i130];
  }

  for (c4_i131 = 0; c4_i131 < 93; c4_i131++) {
    c4_u[c4_i131] = c4_b_inData[c4_i131];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_n_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i132;
  real_T c4_b_inData[93];
  int32_T c4_i133;
  real_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i132 = 0; c4_i132 < 93; c4_i132++) {
    c4_b_inData[c4_i132] = (*(real_T (*)[93])c4_inData)[c4_i132];
  }

  for (c4_i133 = 0; c4_i133 < 93; c4_i133++) {
    c4_u[c4_i133] = c4_b_inData[c4_i133];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_o_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i134;
  char_T c4_b_inData[90];
  int32_T c4_i135;
  char_T c4_u[90];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i134 = 0; c4_i134 < 90; c4_i134++) {
    c4_b_inData[c4_i134] = (*(char_T (*)[90])c4_inData)[c4_i134];
  }

  for (c4_i135 = 0; c4_i135 < 90; c4_i135++) {
    c4_u[c4_i135] = c4_b_inData[c4_i135];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 90), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_p_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i136;
  real_T c4_b_inData[90];
  int32_T c4_i137;
  real_T c4_u[90];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i136 = 0; c4_i136 < 90; c4_i136++) {
    c4_b_inData[c4_i136] = (*(real_T (*)[90])c4_inData)[c4_i136];
  }

  for (c4_i137 = 0; c4_i137 < 90; c4_i137++) {
    c4_u[c4_i137] = c4_b_inData[c4_i137];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 90), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_q_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i138;
  char_T c4_b_inData[104];
  int32_T c4_i139;
  char_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i138 = 0; c4_i138 < 104; c4_i138++) {
    c4_b_inData[c4_i138] = (*(char_T (*)[104])c4_inData)[c4_i138];
  }

  for (c4_i139 = 0; c4_i139 < 104; c4_i139++) {
    c4_u[c4_i139] = c4_b_inData[c4_i139];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_r_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i140;
  real_T c4_b_inData[104];
  int32_T c4_i141;
  real_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i140 = 0; c4_i140 < 104; c4_i140++) {
    c4_b_inData[c4_i140] = (*(real_T (*)[104])c4_inData)[c4_i140];
  }

  for (c4_i141 = 0; c4_i141 < 104; c4_i141++) {
    c4_u[c4_i141] = c4_b_inData[c4_i141];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_s_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i142;
  char_T c4_b_inData[95];
  int32_T c4_i143;
  char_T c4_u[95];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i142 = 0; c4_i142 < 95; c4_i142++) {
    c4_b_inData[c4_i142] = (*(char_T (*)[95])c4_inData)[c4_i142];
  }

  for (c4_i143 = 0; c4_i143 < 95; c4_i143++) {
    c4_u[c4_i143] = c4_b_inData[c4_i143];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_t_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i144;
  real_T c4_b_inData[95];
  int32_T c4_i145;
  real_T c4_u[95];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i144 = 0; c4_i144 < 95; c4_i144++) {
    c4_b_inData[c4_i144] = (*(real_T (*)[95])c4_inData)[c4_i144];
  }

  for (c4_i145 = 0; c4_i145 < 95; c4_i145++) {
    c4_u[c4_i145] = c4_b_inData[c4_i145];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_u_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i146;
  char_T c4_b_inData[88];
  int32_T c4_i147;
  char_T c4_u[88];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i146 = 0; c4_i146 < 88; c4_i146++) {
    c4_b_inData[c4_i146] = (*(char_T (*)[88])c4_inData)[c4_i146];
  }

  for (c4_i147 = 0; c4_i147 < 88; c4_i147++) {
    c4_u[c4_i147] = c4_b_inData[c4_i147];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_v_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i148;
  real_T c4_b_inData[88];
  int32_T c4_i149;
  real_T c4_u[88];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i148 = 0; c4_i148 < 88; c4_i148++) {
    c4_b_inData[c4_i148] = (*(real_T (*)[88])c4_inData)[c4_i148];
  }

  for (c4_i149 = 0; c4_i149 < 88; c4_i149++) {
    c4_u[c4_i149] = c4_b_inData[c4_i149];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_w_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i150;
  char_T c4_b_inData[107];
  int32_T c4_i151;
  char_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i150 = 0; c4_i150 < 107; c4_i150++) {
    c4_b_inData[c4_i150] = (*(char_T (*)[107])c4_inData)[c4_i150];
  }

  for (c4_i151 = 0; c4_i151 < 107; c4_i151++) {
    c4_u[c4_i151] = c4_b_inData[c4_i151];
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
  int32_T c4_i152;
  real_T c4_b_inData[107];
  int32_T c4_i153;
  real_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i152 = 0; c4_i152 < 107; c4_i152++) {
    c4_b_inData[c4_i152] = (*(real_T (*)[107])c4_inData)[c4_i152];
  }

  for (c4_i153 = 0; c4_i153 < 107; c4_i153++) {
    c4_u[c4_i153] = c4_b_inData[c4_i153];
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
  int32_T c4_i154;
  char_T c4_b_inData[97];
  int32_T c4_i155;
  char_T c4_u[97];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i154 = 0; c4_i154 < 97; c4_i154++) {
    c4_b_inData[c4_i154] = (*(char_T (*)[97])c4_inData)[c4_i154];
  }

  for (c4_i155 = 0; c4_i155 < 97; c4_i155++) {
    c4_u[c4_i155] = c4_b_inData[c4_i155];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i156;
  real_T c4_b_inData[97];
  int32_T c4_i157;
  real_T c4_u[97];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i156 = 0; c4_i156 < 97; c4_i156++) {
    c4_b_inData[c4_i156] = (*(real_T (*)[97])c4_inData)[c4_i156];
  }

  for (c4_i157 = 0; c4_i157 < 97; c4_i157++) {
    c4_u[c4_i157] = c4_b_inData[c4_i157];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i158;
  char_T c4_b_inData[68];
  int32_T c4_i159;
  char_T c4_u[68];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i158 = 0; c4_i158 < 68; c4_i158++) {
    c4_b_inData[c4_i158] = (*(char_T (*)[68])c4_inData)[c4_i158];
  }

  for (c4_i159 = 0; c4_i159 < 68; c4_i159++) {
    c4_u[c4_i159] = c4_b_inData[c4_i159];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i160;
  real_T c4_b_inData[68];
  int32_T c4_i161;
  real_T c4_u[68];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i160 = 0; c4_i160 < 68; c4_i160++) {
    c4_b_inData[c4_i160] = (*(real_T (*)[68])c4_inData)[c4_i160];
  }

  for (c4_i161 = 0; c4_i161 < 68; c4_i161++) {
    c4_u[c4_i161] = c4_b_inData[c4_i161];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_db_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i162;
  char_T c4_b_inData[87];
  int32_T c4_i163;
  char_T c4_u[87];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i162 = 0; c4_i162 < 87; c4_i162++) {
    c4_b_inData[c4_i162] = (*(char_T (*)[87])c4_inData)[c4_i162];
  }

  for (c4_i163 = 0; c4_i163 < 87; c4_i163++) {
    c4_u[c4_i163] = c4_b_inData[c4_i163];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i164;
  real_T c4_b_inData[87];
  int32_T c4_i165;
  real_T c4_u[87];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i164 = 0; c4_i164 < 87; c4_i164++) {
    c4_b_inData[c4_i164] = (*(real_T (*)[87])c4_inData)[c4_i164];
  }

  for (c4_i165 = 0; c4_i165 < 87; c4_i165++) {
    c4_u[c4_i165] = c4_b_inData[c4_i165];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i166;
  char_T c4_b_inData[223];
  int32_T c4_i167;
  char_T c4_u[223];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i166 = 0; c4_i166 < 223; c4_i166++) {
    c4_b_inData[c4_i166] = (*(char_T (*)[223])c4_inData)[c4_i166];
  }

  for (c4_i167 = 0; c4_i167 < 223; c4_i167++) {
    c4_u[c4_i167] = c4_b_inData[c4_i167];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i168;
  real_T c4_b_inData[223];
  int32_T c4_i169;
  real_T c4_u[223];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i168 = 0; c4_i168 < 223; c4_i168++) {
    c4_b_inData[c4_i168] = (*(real_T (*)[223])c4_inData)[c4_i168];
  }

  for (c4_i169 = 0; c4_i169 < 223; c4_i169++) {
    c4_u[c4_i169] = c4_b_inData[c4_i169];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i170;
  char_T c4_b_inData[142];
  int32_T c4_i171;
  char_T c4_u[142];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i170 = 0; c4_i170 < 142; c4_i170++) {
    c4_b_inData[c4_i170] = (*(char_T (*)[142])c4_inData)[c4_i170];
  }

  for (c4_i171 = 0; c4_i171 < 142; c4_i171++) {
    c4_u[c4_i171] = c4_b_inData[c4_i171];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i172;
  real_T c4_b_inData[142];
  int32_T c4_i173;
  real_T c4_u[142];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i172 = 0; c4_i172 < 142; c4_i172++) {
    c4_b_inData[c4_i172] = (*(real_T (*)[142])c4_inData)[c4_i172];
  }

  for (c4_i173 = 0; c4_i173 < 142; c4_i173++) {
    c4_u[c4_i173] = c4_b_inData[c4_i173];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i174;
  char_T c4_b_inData[183];
  int32_T c4_i175;
  char_T c4_u[183];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i174 = 0; c4_i174 < 183; c4_i174++) {
    c4_b_inData[c4_i174] = (*(char_T (*)[183])c4_inData)[c4_i174];
  }

  for (c4_i175 = 0; c4_i175 < 183; c4_i175++) {
    c4_u[c4_i175] = c4_b_inData[c4_i175];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i176;
  real_T c4_b_inData[183];
  int32_T c4_i177;
  real_T c4_u[183];
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i176 = 0; c4_i176 < 183; c4_i176++) {
    c4_b_inData[c4_i176] = (*(real_T (*)[183])c4_inData)[c4_i176];
  }

  for (c4_i177 = 0; c4_i177 < 183; c4_i177++) {
    c4_u[c4_i177] = c4_b_inData[c4_i177];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray
  *sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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

static void c4_activate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  chartInstance->c4_sfEvent = c4_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_deactivate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_increment_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c4_temporalCounter_i1 < 7U) {
    chartInstance->c4_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c4_temporalCounter_i1 + 1);
  }
}

static void c4_reset_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

void
  sf_exported_auto_activate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_activate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_increment_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNo(chartInstance);
}

void
  sf_exported_auto_resetTemporalCounter_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_reset_counters_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImi(chartInstance);
}

void
  sf_exported_auto_deactivate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_secs
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_deactivate_secsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate(chartInstance);
}

boolean_T
  sf_exported_auto_isStablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c4_isStable;
}

void sf_exported_auto_duringc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance);
}

void sf_exported_auto_enterc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_sendSBM(chartInstance);
  c4_sendBML(chartInstance);
  c4_enter_atomic_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm(chartInstance);
  c4_enter_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitate(chartInstance);
}

void sf_exported_auto_exitc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_exit_internal_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateS(chartInstance);
  c4_b_sendSBM(chartInstance);
  c4_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_sendSBM(chartInstance);
  c4_sendBML(chartInstance);
}

void sf_exported_auto_disablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_b_sendSBM(chartInstance);
  c4_b_sendBML(chartInstance);
}

void
  sf_exported_auto_stepBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_initBuffersc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_activate_callc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  chartInstance->c4_sfEvent = CALL_EVENT;
}

void
  sf_exported_auto_increment_call_counterc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_reset_call_counterc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_deactivate_callc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_initc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance);
}

const mxArray
  *sf_exported_auto_getSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  const mxArray *c4_out = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_out = NULL;
  sf_mex_assign(&c4_out,
                sf_internal_get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
                (c4_S), false);
  return c4_out;
}

void
  sf_exported_auto_setSimstatec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S, const mxArray *c4_in)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    (c4_S, sf_mex_dup(c4_in));
  sf_mex_destroy(&c4_in);
}

void
  sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *c4_S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_arg[256])
{
  int32_T c4_i178;
  int32_T c4_i179;
  int32_T c4_i180;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c4_i178 = 0; c4_i178 < 256; c4_i178++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i178], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i179 = 0; c4_i179 < 256; c4_i179++) {
    (*c4_b_arg)[c4_i179] = c4_arg[c4_i179];
  }

  for (c4_i180 = 0; c4_i180 < 256; c4_i180++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i180], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
}

static void c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_arg[256])
{
  int32_T c4_i181;
  int32_T c4_i182;
  int32_T c4_i183;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c4_i181 = 0; c4_i181 < 256; c4_i181++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i181], 26U);
  }

  _SFD_SET_DATA_VALUE_PTR(26U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c4_sfEvent);
  for (c4_i182 = 0; c4_i182 < 256; c4_i182++) {
    (*c4_b_arg)[c4_i182] = c4_arg[c4_i182];
  }

  for (c4_i183 = 0; c4_i183 < 256; c4_i183++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i183], 26U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(26U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c4_sfEvent);
}

static void c4_paperPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotIm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[5];
  boolean_T c4_aVarTruthTableCondition_1;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv47[256];
  int32_T c4_i184;
  int32_T c4_i185;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 10);
  if (CV_EML_IF(4, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 11);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 20);
    c4_encStr2Arr(chartInstance, c4_dv47);
    for (c4_i184 = 0; c4_i184 < 256; c4_i184++) {
      c4_poseBML[c4_i184] = c4_dv47[c4_i184];
    }

    c4_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, -20);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 13);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, 20);
    c4_encStr2Arr(chartInstance, c4_dv47);
    for (c4_i185 = 0; c4_i185 < 256; c4_i185++) {
      c4_poseBML[c4_i185] = c4_dv47[c4_i185];
    }

    c4_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, -20);
  }

  _SFD_EML_CALL(4U, chartInstance->c4_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_scissorsPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNo
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[5];
  boolean_T c4_aVarTruthTableCondition_1;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv48[256];
  int32_T c4_i186;
  int32_T c4_i187;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_c_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 10);
  if (CV_EML_IF(6, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 11);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 20);
    c4_encStr2Arr(chartInstance, c4_dv48);
    for (c4_i186 = 0; c4_i186 < 256; c4_i186++) {
      c4_poseBML[c4_i186] = c4_dv48[c4_i186];
    }

    c4_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, -20);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 13);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, 20);
    c4_encStr2Arr(chartInstance, c4_dv48);
    for (c4_i187 = 0; c4_i187 < 256; c4_i187++) {
      c4_poseBML[c4_i187] = c4_dv48[c4_i187];
    }

    c4_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, -20);
  }

  _SFD_EML_CALL(6U, chartInstance->c4_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_rockPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[6];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv49[256];
  int32_T c4_i188;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[94];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[94];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i189;
  static char_T c4_cv18[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i190;
  static real_T c4_dv50[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i191;
  int32_T c4_i192;
  int32_T c4_i193;
  int32_T c4_i194;
  int32_T c4_i195;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c4_d_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 15);
  if (CV_EML_IF(5, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 16);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 27);
    c4_b_encStr2Arr(chartInstance, c4_dv49);
    for (c4_i188 = 0; c4_i188 < 256; c4_i188++) {
      c4_poseBML[c4_i188] = c4_dv49[c4_i188];
    }

    c4_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, -27);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 17);
    if (CV_EML_IF(5, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 18);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_f_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_g_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      for (c4_i189 = 0; c4_i189 < 94; c4_i189++) {
        c4_mystr[c4_i189] = c4_cv18[c4_i189];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
      c4_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
      for (c4_i190 = 0; c4_i190 < 94; c4_i190++) {
        c4_arr[c4_i190] = c4_dv50[c4_i190];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
      c4_ss = 94.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
      c4_padsize = c4_maxarrsize - c4_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
      for (c4_i191 = 0; c4_i191 < 256; c4_i191++) {
        c4_tt[c4_i191] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
      for (c4_i192 = 0; c4_i192 < 94; c4_i192++) {
        c4_tt[c4_i192] = c4_arr[c4_i192];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
      for (c4_i193 = 0; c4_i193 < 256; c4_i193++) {
        c4_myarr256[c4_i193] = c4_tt[c4_i193];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c4_i194 = 0; c4_i194 < 256; c4_i194++) {
        c4_poseBML[c4_i194] = c4_myarr256[c4_i194];
      }

      c4_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, -33);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 20);
      CV_EML_FCN(5, 1);
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, 27);
      c4_b_encStr2Arr(chartInstance, c4_dv49);
      for (c4_i195 = 0; c4_i195 < 256; c4_i195++) {
        c4_poseBML[c4_i195] = c4_dv49[c4_i195];
      }

      c4_updateDataWrittenToVector(chartInstance, 9U);
      _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_sbmID, real_T c4_poseSBM[256])
{
  uint32_T c4_debug_family_var_map[8];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv51[256];
  int32_T c4_i196;
  int32_T c4_i197;
  int32_T c4_i198;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[90];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[90];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i199;
  static char_T c4_cv19[90] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', ')', ')' };

  int32_T c4_i200;
  static real_T c4_dv52[90] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0 };

  int32_T c4_i201;
  int32_T c4_i202;
  int32_T c4_i203;
  int32_T c4_i204;
  int32_T c4_i205;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_g_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sbmID, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseSBM, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_1 = (c4_sbmID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_2 = (c4_sbmID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_3 = (c4_sbmID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 23);
  c4_aVarTruthTableCondition_4 = (c4_sbmID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 25);
  if (CV_EML_IF(1, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 26);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 41);
    c4_c_encStr2Arr(chartInstance, c4_dv51);
    for (c4_i196 = 0; c4_i196 < 256; c4_i196++) {
      c4_poseSBM[c4_i196] = c4_dv51[c4_i196];
    }

    c4_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -41);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 27);
    if (CV_EML_IF(1, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 28);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 47);
      c4_d_encStr2Arr(chartInstance, c4_dv51);
      for (c4_i197 = 0; c4_i197 < 256; c4_i197++) {
        c4_poseSBM[c4_i197] = c4_dv51[c4_i197];
      }

      c4_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -47);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 29);
      if (CV_EML_IF(1, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 30);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 53);
        c4_e_encStr2Arr(chartInstance, c4_dv51);
        for (c4_i198 = 0; c4_i198 < 256; c4_i198++) {
          c4_poseSBM[c4_i198] = c4_dv51[c4_i198];
        }

        c4_updateDataWrittenToVector(chartInstance, 10U);
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -53);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 31);
        if (CV_EML_IF(1, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 32);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 59);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_k_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
            c4_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U,
            c4_d_sf_marshallOut, c4_d_sf_marshallIn);
          for (c4_i199 = 0; c4_i199 < 90; c4_i199++) {
            c4_mystr[c4_i199] = c4_cv19[c4_i199];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
          c4_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
          for (c4_i200 = 0; c4_i200 < 90; c4_i200++) {
            c4_arr[c4_i200] = c4_dv52[c4_i200];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
          c4_ss = 90.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
          c4_padsize = c4_maxarrsize - c4_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
          for (c4_i201 = 0; c4_i201 < 256; c4_i201++) {
            c4_tt[c4_i201] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
          for (c4_i202 = 0; c4_i202 < 90; c4_i202++) {
            c4_tt[c4_i202] = c4_arr[c4_i202];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
          for (c4_i203 = 0; c4_i203 < 256; c4_i203++) {
            c4_myarr256[c4_i203] = c4_tt[c4_i203];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c4_i204 = 0; c4_i204 < 256; c4_i204++) {
            c4_poseSBM[c4_i204] = c4_myarr256[c4_i204];
          }

          c4_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -59);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 34);
          CV_EML_FCN(1, 1);
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, 41);
          c4_c_encStr2Arr(chartInstance, c4_dv51);
          for (c4_i205 = 0; c4_i205 < 256; c4_i205++) {
            c4_poseSBM[c4_i205] = c4_dv51[c4_i205];
          }

          c4_updateDataWrittenToVector(chartInstance, 10U);
          _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c4_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_idlePoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[22];
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
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv53[256];
  int32_T c4_i206;
  int32_T c4_i207;
  int32_T c4_i208;
  int32_T c4_i209;
  int32_T c4_i210;
  int32_T c4_i211;
  int32_T c4_i212;
  int32_T c4_i213;
  int32_T c4_i214;
  int32_T c4_i215;
  int32_T c4_i216;
  int32_T c4_i217;
  int32_T c4_i218;
  int32_T c4_i219;
  int32_T c4_i220;
  int32_T c4_i221;
  int32_T c4_i222;
  int32_T c4_i223;
  int32_T c4_i224;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c4_l_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 18U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 19U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 20U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 21U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 20);
  c4_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 24);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 27);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 30);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 33);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 36);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 39);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 42);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 45);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 48);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 51);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 54);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 57);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 60);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 63);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 66);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 69);
  c4_aVarTruthTableCondition_16 = (c4_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 72);
  c4_aVarTruthTableCondition_17 = (c4_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 75);
  c4_aVarTruthTableCondition_18 = (c4_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 77);
  if (CV_EML_IF(2, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 78);
    CV_EML_FCN(2, 7);
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 157U);
    c4_f_encStr2Arr(chartInstance, c4_dv53);
    for (c4_i206 = 0; c4_i206 < 256; c4_i206++) {
      c4_poseBML[c4_i206] = c4_dv53[c4_i206];
    }

    c4_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -157);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 79);
    if (CV_EML_IF(2, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 80);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, MAX_int8_T);
      c4_g_encStr2Arr(chartInstance, c4_dv53);
      for (c4_i207 = 0; c4_i207 < 256; c4_i207++) {
        c4_poseBML[c4_i207] = c4_dv53[c4_i207];
      }

      c4_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -127);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 81);
      if (CV_EML_IF(2, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 82);
        CV_EML_FCN(2, 1);
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 121);
        c4_h_encStr2Arr(chartInstance, c4_dv53);
        for (c4_i208 = 0; c4_i208 < 256; c4_i208++) {
          c4_poseBML[c4_i208] = c4_dv53[c4_i208];
        }

        c4_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -121);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 83);
        if (CV_EML_IF(2, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 84);
          CV_EML_FCN(2, 2);
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, MAX_int8_T);
          c4_g_encStr2Arr(chartInstance, c4_dv53);
          for (c4_i209 = 0; c4_i209 < 256; c4_i209++) {
            c4_poseBML[c4_i209] = c4_dv53[c4_i209];
          }

          c4_updateDataWrittenToVector(chartInstance, 11U);
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -127);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 85);
          if (CV_EML_IF(2, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 86);
            CV_EML_FCN(2, 3);
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 133U);
            c4_i_encStr2Arr(chartInstance, c4_dv53);
            for (c4_i210 = 0; c4_i210 < 256; c4_i210++) {
              c4_poseBML[c4_i210] = c4_dv53[c4_i210];
            }

            c4_updateDataWrittenToVector(chartInstance, 11U);
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -133);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 87);
            if (CV_EML_IF(2, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 88);
              CV_EML_FCN(2, 8);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 163U);
              c4_j_encStr2Arr(chartInstance, c4_dv53);
              for (c4_i211 = 0; c4_i211 < 256; c4_i211++) {
                c4_poseBML[c4_i211] = c4_dv53[c4_i211];
              }

              c4_updateDataWrittenToVector(chartInstance, 11U);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -163);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 89);
              if (CV_EML_IF(2, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 90);
                CV_EML_FCN(2, 1);
                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 121);
                c4_h_encStr2Arr(chartInstance, c4_dv53);
                for (c4_i212 = 0; c4_i212 < 256; c4_i212++) {
                  c4_poseBML[c4_i212] = c4_dv53[c4_i212];
                }

                c4_updateDataWrittenToVector(chartInstance, 11U);
                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -121);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 91);
                if (CV_EML_IF(2, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 92);
                  CV_EML_FCN(2, 3);
                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 133U);
                  c4_i_encStr2Arr(chartInstance, c4_dv53);
                  for (c4_i213 = 0; c4_i213 < 256; c4_i213++) {
                    c4_poseBML[c4_i213] = c4_dv53[c4_i213];
                  }

                  c4_updateDataWrittenToVector(chartInstance, 11U);
                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -133);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 93);
                  if (CV_EML_IF(2, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 94);
                    CV_EML_FCN(2, 1);
                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 121);
                    c4_h_encStr2Arr(chartInstance, c4_dv53);
                    for (c4_i214 = 0; c4_i214 < 256; c4_i214++) {
                      c4_poseBML[c4_i214] = c4_dv53[c4_i214];
                    }

                    c4_updateDataWrittenToVector(chartInstance, 11U);
                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -121);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 95);
                    if (CV_EML_IF(2, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 96);
                      CV_EML_FCN(2, 7);
                      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 157U);
                      c4_f_encStr2Arr(chartInstance, c4_dv53);
                      for (c4_i215 = 0; c4_i215 < 256; c4_i215++) {
                        c4_poseBML[c4_i215] = c4_dv53[c4_i215];
                      }

                      c4_updateDataWrittenToVector(chartInstance, 11U);
                      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -157);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 97);
                      if (CV_EML_IF(2, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 98);
                        CV_EML_FCN(2, 8);
                        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 163U);
                        c4_j_encStr2Arr(chartInstance, c4_dv53);
                        for (c4_i216 = 0; c4_i216 < 256; c4_i216++) {
                          c4_poseBML[c4_i216] = c4_dv53[c4_i216];
                        }

                        c4_updateDataWrittenToVector(chartInstance, 11U);
                        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -163);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 99);
                        if (CV_EML_IF(2, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 100);
                          CV_EML_FCN(2, 6);
                          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 151U);
                          c4_k_encStr2Arr(chartInstance, c4_dv53);
                          for (c4_i217 = 0; c4_i217 < 256; c4_i217++) {
                            c4_poseBML[c4_i217] = c4_dv53[c4_i217];
                          }

                          c4_updateDataWrittenToVector(chartInstance, 11U);
                          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -151);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 101);
                          if (CV_EML_IF(2, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 102);
                            CV_EML_FCN(2, 6);
                            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 151U);
                            c4_k_encStr2Arr(chartInstance, c4_dv53);
                            for (c4_i218 = 0; c4_i218 < 256; c4_i218++) {
                              c4_poseBML[c4_i218] = c4_dv53[c4_i218];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 11U);
                            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -151);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 103);
                            if (CV_EML_IF(2, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 104);
                              CV_EML_FCN(2, 5);
                              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 145U);
                              c4_l_encStr2Arr(chartInstance, c4_dv53);
                              for (c4_i219 = 0; c4_i219 < 256; c4_i219++) {
                                c4_poseBML[c4_i219] = c4_dv53[c4_i219];
                              }

                              c4_updateDataWrittenToVector(chartInstance, 11U);
                              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -145);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 105);
                              if (CV_EML_IF(2, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 106);
                                CV_EML_FCN(2, 4);
                                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                              139U);
                                c4_m_encStr2Arr(chartInstance, c4_dv53);
                                for (c4_i220 = 0; c4_i220 < 256; c4_i220++) {
                                  c4_poseBML[c4_i220] = c4_dv53[c4_i220];
                                }

                                c4_updateDataWrittenToVector(chartInstance, 11U);
                                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                              -139);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 107);
                                if (CV_EML_IF(2, 1, 15,
                                              c4_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                108);
                                  CV_EML_FCN(2, 3);
                                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                133U);
                                  c4_i_encStr2Arr(chartInstance, c4_dv53);
                                  for (c4_i221 = 0; c4_i221 < 256; c4_i221++) {
                                    c4_poseBML[c4_i221] = c4_dv53[c4_i221];
                                  }

                                  c4_updateDataWrittenToVector(chartInstance,
                                    11U);
                                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                -133);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                109);
                                  if (CV_EML_IF(2, 1, 16,
                                                c4_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                  110);
                                    CV_EML_FCN(2, 6);
                                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                  151U);
                                    c4_k_encStr2Arr(chartInstance, c4_dv53);
                                    for (c4_i222 = 0; c4_i222 < 256; c4_i222++)
                                    {
                                      c4_poseBML[c4_i222] = c4_dv53[c4_i222];
                                    }

                                    c4_updateDataWrittenToVector(chartInstance,
                                      11U);
                                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                  -151);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent,
                                                  111);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c4_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
                                                    112);
                                      CV_EML_FCN(2, 3);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
                                                    133U);
                                      c4_i_encStr2Arr(chartInstance, c4_dv53);
                                      for (c4_i223 = 0; c4_i223 < 256; c4_i223++)
                                      {
                                        c4_poseBML[c4_i223] = c4_dv53[c4_i223];
                                      }

                                      c4_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
                                                    -133);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
                                                    114);
                                      CV_EML_FCN(2, 1);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
                                                    121);
                                      c4_h_encStr2Arr(chartInstance, c4_dv53);
                                      for (c4_i224 = 0; c4_i224 < 256; c4_i224++)
                                      {
                                        c4_poseBML[c4_i224] = c4_dv53[c4_i224];
                                      }

                                      c4_updateDataWrittenToVector(chartInstance,
                                        11U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c4_sfEvent,
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

  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[7];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv54[256];
  int32_T c4_i225;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[87];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[87];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i226;
  static char_T c4_cv20[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c4_i227;
  static real_T c4_dv55[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i228;
  int32_T c4_i229;
  int32_T c4_i230;
  int32_T c4_i231;
  int32_T c4_i232;
  int32_T c4_i233;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_u_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 17);
  if (CV_EML_IF(3, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 18);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 31);
    c4_n_encStr2Arr(chartInstance, c4_dv54);
    for (c4_i225 = 0; c4_i225 < 256; c4_i225++) {
      c4_poseBML[c4_i225] = c4_dv54[c4_i225];
    }

    c4_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -31);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 19);
    if (CV_EML_IF(3, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 20);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 37);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_w_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_eb_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_db_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
        c4_d_sf_marshallIn);
      for (c4_i226 = 0; c4_i226 < 87; c4_i226++) {
        c4_mystr[c4_i226] = c4_cv20[c4_i226];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
      c4_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
      for (c4_i227 = 0; c4_i227 < 87; c4_i227++) {
        c4_arr[c4_i227] = c4_dv55[c4_i227];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
      c4_ss = 87.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
      c4_padsize = c4_maxarrsize - c4_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
      for (c4_i228 = 0; c4_i228 < 256; c4_i228++) {
        c4_tt[c4_i228] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
      for (c4_i229 = 0; c4_i229 < 87; c4_i229++) {
        c4_tt[c4_i229] = c4_arr[c4_i229];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
      for (c4_i230 = 0; c4_i230 < 256; c4_i230++) {
        c4_myarr256[c4_i230] = c4_tt[c4_i230];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c4_i231 = 0; c4_i231 < 256; c4_i231++) {
        c4_poseBML[c4_i231] = c4_myarr256[c4_i231];
      }

      c4_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -37);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 21);
      if (CV_EML_IF(3, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 22);
        CV_EML_FCN(3, 1);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 31);
        c4_n_encStr2Arr(chartInstance, c4_dv54);
        for (c4_i232 = 0; c4_i232 < 256; c4_i232++) {
          c4_poseBML[c4_i232] = c4_dv54[c4_i232];
        }

        c4_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -31);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 24);
        CV_EML_FCN(3, 1);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 31);
        c4_n_encStr2Arr(chartInstance, c4_dv54);
        for (c4_i233 = 0; c4_i233 < 256; c4_i233++) {
          c4_poseBML[c4_i233] = c4_dv54[c4_i233];
        }

        c4_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -31);
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmi
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[7];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv56[256];
  int32_T c4_i234;
  int32_T c4_i235;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[183];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[183];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i236;
  static char_T c4_cv21[183] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c4_i237;
  static real_T c4_dv57[183] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c4_i238;
  int32_T c4_i239;
  int32_T c4_i240;
  int32_T c4_i241;
  int32_T c4_i242;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_x_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(36, 0);
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 20);
  if (CV_EML_IF(36, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 21);
    CV_EML_FCN(36, 1);
    _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 34);
    c4_o_encStr2Arr(chartInstance, c4_dv56);
    for (c4_i234 = 0; c4_i234 < 256; c4_i234++) {
      c4_poseBML[c4_i234] = c4_dv56[c4_i234];
    }

    c4_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, -34);
  } else {
    _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 22);
    if (CV_EML_IF(36, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 23);
      CV_EML_FCN(36, 2);
      _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 40);
      c4_p_encStr2Arr(chartInstance, c4_dv56);
      for (c4_i235 = 0; c4_i235 < 256; c4_i235++) {
        c4_poseBML[c4_i235] = c4_dv56[c4_i235];
      }

      c4_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, -40);
    } else {
      _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 24);
      if (CV_EML_IF(36, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 25);
        CV_EML_FCN(36, 3);
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_bb_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_kb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
          c4_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_jb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U,
          c4_d_sf_marshallOut, c4_d_sf_marshallIn);
        for (c4_i236 = 0; c4_i236 < 183; c4_i236++) {
          c4_mystr[c4_i236] = c4_cv21[c4_i236];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
        c4_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
        for (c4_i237 = 0; c4_i237 < 183; c4_i237++) {
          c4_arr[c4_i237] = c4_dv57[c4_i237];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
        c4_ss = 183.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
        c4_padsize = c4_maxarrsize - c4_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
        for (c4_i238 = 0; c4_i238 < 256; c4_i238++) {
          c4_tt[c4_i238] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
        for (c4_i239 = 0; c4_i239 < 183; c4_i239++) {
          c4_tt[c4_i239] = c4_arr[c4_i239];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
        for (c4_i240 = 0; c4_i240 < 256; c4_i240++) {
          c4_myarr256[c4_i240] = c4_tt[c4_i240];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c4_i241 = 0; c4_i241 < 256; c4_i241++) {
          c4_poseBML[c4_i241] = c4_myarr256[c4_i241];
        }

        c4_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, -46);
      } else {
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 27);
        CV_EML_FCN(36, 1);
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, 34);
        c4_o_encStr2Arr(chartInstance, c4_dv56);
        for (c4_i242 = 0; c4_i242 < 256; c4_i242++) {
          c4_poseBML[c4_i242] = c4_dv56[c4_i242];
        }

        c4_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(36U, chartInstance->c4_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_sendSBM
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c4_b_sendSBM
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c4_sendBML
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void c4_b_sendBML
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_handPoseSBRachelTable
  (SimStruct *c4_S, real_T c4_sbmID, real_T c4_poseSBM[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotI(chartInstance,
    c4_sbmID, c4_poseSBM);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_idlePoseRachelTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_idlePoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImi(chartInstance,
    c4_bmlID, c4_poseBML);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_initialPoseTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitat(chartInstance,
    c4_bmlID, c4_poseBML);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_paperPoseRachelTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_paperPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotIm(chartInstance,
    c4_bmlID, c4_poseBML);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_rockPoseTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_rockPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSm(chartInstance,
    c4_bmlID, c4_poseBML);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_scissorsPoseRachelTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_scissorsPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNo(chartInstance,
    c4_bmlID, c4_poseBML);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_sendBML
  (SimStruct *c4_S, real_T c4_arg[256])
{
  int32_T c4_i243;
  real_T c4_b_arg[256];
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  for (c4_i243 = 0; c4_i243 < 256; c4_i243++) {
    c4_b_arg[c4_i243] = c4_arg[c4_i243];
  }

  c4_sendBMLc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
    c4_b_arg);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_sendSBM
  (SimStruct *c4_S, real_T c4_arg[256])
{
  int32_T c4_i244;
  real_T c4_b_arg[256];
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  for (c4_i244 = 0; c4_i244 < 256; c4_i244++) {
    c4_b_arg[c4_i244] = c4_arg[c4_i244];
  }

  c4_sendSBMc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(chartInstance,
    c4_b_arg);
}

void
  sf_exported_user_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_successTable
  (SimStruct *c4_S, real_T c4_bmlID, real_T c4_poseBML[256])
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo
    )->chartInstance;
  c4_successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmi(chartInstance,
    c4_bmlID, c4_poseBML);
}

static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int8_T c4_f_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int8_T c4_y;
  int8_T c4_i245;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i245, 1, 2, 0U, 0, 0U, 0);
  c4_y = c4_i245;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_secs;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int8_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_secs = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_secs), &c4_thisId);
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
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i246;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i246, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i246;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
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
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_h_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_tp_stateStart, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateStart),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateStart);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u3, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_stateStart;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c4_b_tp_stateStart = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_stateStart),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_stateStart);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint32_T c4_j_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_method),
    &c4_thisId);
  sf_mex_destroy(&c4_b_method);
  return c4_y;
}

static uint32_T c4_k_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u4;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_method_not_empty = false;
  } else {
    chartInstance->c4_method_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u4, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_u4;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static uint32_T c4_l_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId);
  sf_mex_destroy(&c4_d_state);
  return c4_y;
}

static uint32_T c4_m_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u5;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_state_not_empty = false;
  } else {
    chartInstance->c4_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u5, 1, 7, 0U, 0, 0U, 0);
    c4_y = c4_u5;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_n_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
   uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_o_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   uint32_T c4_y[625])
{
  uint32_T c4_uv3[625];
  int32_T c4_i247;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_c_state_not_empty = false;
  } else {
    chartInstance->c4_c_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c4_i247 = 0; c4_i247 < 625; c4_i247++) {
      c4_y[c4_i247] = c4_uv3[c4_i247];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_p_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
   uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_q_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
   uint32_T c4_y[2])
{
  uint32_T c4_uv4[2];
  int32_T c4_i248;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_b_state_not_empty = false;
  } else {
    chartInstance->c4_b_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i248 = 0; c4_i248 < 2; c4_i248++) {
      c4_y[c4_i248] = c4_uv4[c4_i248];
    }
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_r_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T *
   c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  sf_mex_assign(&c4_y, c4_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_s_emlrt_marshallIn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
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

static void c4_updateDataWrittenToVector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_vectorIndex)
{
  (void)chartInstance;
  c4_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c4_vectorIndex, 0, 13, 1, 0)] = true;
}

static void c4_errorIfDataNotWrittenToFcn
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c4_dataNumber, c4_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c4_vectorIndex, 0, 13, 1,
    0)]);
}

static void c4_b_twister_state_vector
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_mt[625], real_T c4_seed)
{
  real_T c4_d5;
  uint32_T c4_u6;
  uint32_T c4_r;
  int32_T c4_mti;
  real_T c4_b_mti;
  real_T c4_d6;
  uint32_T c4_u7;
  (void)chartInstance;
  c4_d5 = c4_seed;
  if (c4_d5 < 4.294967296E+9) {
    if (c4_d5 >= 0.0) {
      c4_u6 = (uint32_T)c4_d5;
    } else {
      c4_u6 = 0U;
    }
  } else if (c4_d5 >= 4.294967296E+9) {
    c4_u6 = MAX_uint32_T;
  } else {
    c4_u6 = 0U;
  }

  c4_r = c4_u6;
  c4_mt[0] = c4_r;
  for (c4_mti = 0; c4_mti < 623; c4_mti++) {
    c4_b_mti = 2.0 + (real_T)c4_mti;
    c4_d6 = muDoubleScalarRound(c4_b_mti - 1.0);
    if (c4_d6 < 4.294967296E+9) {
      if (c4_d6 >= 0.0) {
        c4_u7 = (uint32_T)c4_d6;
      } else {
        c4_u7 = 0U;
      }
    } else if (c4_d6 >= 4.294967296E+9) {
      c4_u7 = MAX_uint32_T;
    } else {
      c4_u7 = 0U;
    }

    c4_r = (c4_r ^ c4_r >> 30U) * 1812433253U + c4_u7;
    c4_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_mti), 1, 625, 1, 0) - 1] = c4_r;
  }

  c4_mt[624] = 624U;
}

static real_T c4_c_eml_rand_mt19937ar
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_d_state[625])
{
  int32_T c4_i249;
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
  real_T c4_d7;
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
    for (c4_i249 = 0; c4_i249 < 2; c4_i249++) {
      c4_u[c4_i249] = 0U;
    }

    for (c4_j = 0; c4_j < 2; c4_j++) {
      c4_b_j = 1.0 + (real_T)c4_j;
      c4_mti = c4_d_state[624] + 1U;
      if ((real_T)c4_mti >= 625.0) {
        for (c4_kk = 0; c4_kk < 227; c4_kk++) {
          c4_b_kk = 1.0 + (real_T)c4_kk;
          c4_y = (c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c4_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c4_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c4_b_y = c4_y;
          c4_c_y = c4_b_y;
          if ((real_T)(c4_c_y & 1U) == 0.0) {
            c4_c_y >>= 1U;
          } else {
            c4_c_y = c4_c_y >> 1U ^ 2567483615U;
          }

          c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c4_b_kk), 1, 625, 1, 0) - 1] =
            c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c4_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c4_c_y;
        }

        for (c4_c_kk = 0; c4_c_kk < 396; c4_c_kk++) {
          c4_b_kk = 228.0 + (real_T)c4_c_kk;
          c4_y = (c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c4_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c4_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c4_d_y = c4_y;
          c4_e_y = c4_d_y;
          if ((real_T)(c4_e_y & 1U) == 0.0) {
            c4_e_y >>= 1U;
          } else {
            c4_e_y = c4_e_y >> 1U ^ 2567483615U;
          }

          c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c4_b_kk), 1, 625, 1, 0) - 1] =
            c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c4_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c4_e_y;
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
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c4_mti), 1, 625, 1, 0)
        - 1];
      c4_d_state[624] = c4_mti;
      c4_y ^= c4_y >> 11U;
      c4_y ^= c4_y << 7U & 2636928640U;
      c4_y ^= c4_y << 15U & 4022730752U;
      c4_y ^= c4_y >> 18U;
      c4_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c4_b_j), 1, 2, 1, 0) - 1] = c4_y;
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
        c4_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c4_k < 625)) {
          if ((real_T)c4_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c4_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c4_a = c4_k;
            c4_b_a = c4_a + 1;
            c4_k = c4_b_a;
          } else {
            c4_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c4_isvalid) {
        c4_eml_error(chartInstance);
        c4_d7 = 5489.0;
        c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c4_b_r;
}

static real_T c4_get_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1596) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_BOREDOM_THRESHOLD_address;
}

static void c4_set_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1596) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_BOREDOM_THRESHOLD_address = c4_c;
}

static real_T *c4_access_BOREDOM_THRESHOLD
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1596) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_BOREDOM_THRESHOLD_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c4_c;
}

static real_T c4_get_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1606) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_avert_address;
}

static void c4_set_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1606) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_avert_address = c4_c;
}

static real_T *c4_access_avert
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c4_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1606) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_avert_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c4_c;
}

static real_T c4_get_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1591) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_bHand_address;
}

static void c4_set_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1591) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_bHand_address = c4_c;
}

static real_T *c4_access_bHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c4_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#1591) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_bHand_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c4_c;
}

static real_T c4_get_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1595) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_boredom_address;
}

static void c4_set_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1595) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_boredom_address = c4_c;
}

static real_T *c4_access_boredom
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1595) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_boredom_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c4_c;
}

static real_T c4_get_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1589) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_diff_address;
}

static void c4_set_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1589) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_diff_address = c4_c;
}

static real_T *c4_access_diff
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c4_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#1589) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_diff_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c4_c;
}

static real_T c4_get_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1599) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_isPosing_address;
}

static void c4_set_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1599) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_isPosing_address = c4_c;
}

static real_T *c4_access_isPosing
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c4_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1599) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_isPosing_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c4_c;
}

static real_T c4_get_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#1605) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_isSmiling_address;
}

static void c4_set_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#1605) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_isSmiling_address = c4_c;
}

static real_T *c4_access_isSmiling
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c4_isSmiling_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isSmiling\' (#1605) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_isSmiling_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c4_c;
}

static real_T c4_get_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1601) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_p_address;
}

static void c4_set_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1601) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_p_address = c4_c;
}

static real_T *c4_access_p
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c4_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#1601) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_p_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c4_c;
}

static real_T c4_get_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1600) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_r_address;
}

static void c4_set_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1600) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_r_address = c4_c;
}

static real_T *c4_access_r
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c4_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#1600) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_r_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c4_c;
}

static real_T c4_get_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1597) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randAvertGazeChance_address;
}

static void c4_set_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1597) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randAvertGazeChance_address = c4_c;
}

static real_T *c4_access_randAvertGazeChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c4_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1597) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randAvertGazeChance_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c4_c;
}

static real_T c4_get_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1598) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randPoseChance_address;
}

static void c4_set_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1598) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randPoseChance_address = c4_c;
}

static real_T *c4_access_randPoseChance
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1598) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randPoseChance_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c4_c;
}

static real_T c4_get_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#1594) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randSmile_address;
}

static void c4_set_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#1594) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randSmile_address = c4_c;
}

static real_T *c4_access_randSmile
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c4_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#1594) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randSmile_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c4_c;
}

static real_T c4_get_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1602) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_s_address;
}

static void c4_set_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1602) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_s_address = c4_c;
}

static real_T *c4_access_s
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c4_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#1602) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_s_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c4_c;
}

static real_T c4_get_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_smileDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileDur\' (#1607) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_smileDur_address;
}

static void c4_set_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_smileDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileDur\' (#1607) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_smileDur_address = c4_c;
}

static real_T *c4_access_smileDur
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c4_smileDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileDur\' (#1607) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_smileDur_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c4_c;
}

static real_T c4_get_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1588) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_temp_address;
}

static void c4_set_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1588) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_temp_address = c4_c;
}

static real_T *c4_access_temp
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c4_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#1588) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_temp_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c4_c;
}

static real_T c4_get_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1590) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_uHand_address;
}

static void c4_set_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1590) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_uHand_address = c4_c;
}

static real_T *c4_access_uHand
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c4_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#1590) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_uHand_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c4_c;
}

static real_T c4_get_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#1603) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_wristRotate_address;
}

static void c4_set_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#1603) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_wristRotate_address = c4_c;
}

static real_T *c4_access_wristRotate
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c4_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#1603) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_wristRotate_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c4_c;
}

static void init_dsm_address_info
  (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
   *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c4_BOREDOM_THRESHOLD_address,
    &chartInstance->c4_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c4_avert_address, &chartInstance->c4_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c4_bHand_address, &chartInstance->c4_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c4_boredom_address, &chartInstance->c4_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c4_diff_address, &chartInstance->c4_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c4_isPosing_address, &chartInstance->c4_isPosing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isSmiling", (void **)
    &chartInstance->c4_isSmiling_address, &chartInstance->c4_isSmiling_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c4_p_address, &chartInstance->c4_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c4_r_address, &chartInstance->c4_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c4_randAvertGazeChance_address,
    &chartInstance->c4_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c4_randPoseChance_address,
    &chartInstance->c4_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSmile", (void **)
    &chartInstance->c4_randSmile_address, &chartInstance->c4_randSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c4_s_address, &chartInstance->c4_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileDur", (void **)
    &chartInstance->c4_smileDur_address, &chartInstance->c4_smileDur_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c4_temp_address, &chartInstance->c4_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c4_uHand_address, &chartInstance->c4_uHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "wristRotate", (void **)
    &chartInstance->c4_wristRotate_address, &chartInstance->c4_wristRotate_index);
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

void sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_check_sum
  (mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4009004827U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4040705173U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1785145635U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3933903335U);
}

mxArray
  *sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NAMAn1lLgwKwFLxwWV4wsH");
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
  *sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray
  *sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"bWinT\",},{M[1],M[86],T\"bradHand\",},{M[1],M[84],T\"gameState\",},{M[1],M[106],T\"round\",},{M[1],M[94],T\"uWinT\",},{M[1],M[87],T\"userHand\",},{M[1],M[88],T\"win\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile\",},{M[9],M[0],T\"is_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile\",},{M[11],M[107],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x15[54 55 83 58 59 61 62 64 67 69 71 78 77 81 82],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_get_check_sum
    (&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
      *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance =
      (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
           4,
           37,
           43,
           0,
           41,
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
          (_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
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
          _SFD_SET_DATA_PROPS(11,11,0,0,"randSmile");
          _SFD_SET_DATA_PROPS(12,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(13,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(14,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(15,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(16,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(17,11,0,0,"r");
          _SFD_SET_DATA_PROPS(18,11,0,0,"p");
          _SFD_SET_DATA_PROPS(19,11,0,0,"s");
          _SFD_SET_DATA_PROPS(20,11,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(21,2,0,1,"round");
          _SFD_SET_DATA_PROPS(22,11,0,0,"isSmiling");
          _SFD_SET_DATA_PROPS(23,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(24,11,0,0,"smileDur");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,9,0,0,"");
          _SFD_SET_DATA_PROPS(31,8,0,0,"");
          _SFD_SET_DATA_PROPS(32,9,0,0,"");
          _SFD_SET_DATA_PROPS(33,8,0,0,"");
          _SFD_SET_DATA_PROPS(34,9,0,0,"");
          _SFD_SET_DATA_PROPS(35,8,0,0,"");
          _SFD_SET_DATA_PROPS(36,9,0,0,"");
          _SFD_SET_DATA_PROPS(37,8,0,0,"");
          _SFD_SET_DATA_PROPS(38,9,0,0,"");
          _SFD_SET_DATA_PROPS(39,8,0,0,"");
          _SFD_SET_DATA_PROPS(40,9,0,0,"");
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
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(36,0,2);
          _SFD_CH_SUBSTATE_COUNT(28);
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
          _SFD_CH_SUBSTATE_INDEX(27,35);
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
          _SFD_ST_SUBSTATE_COUNT(35,0);
        }

        _SFD_CV_INIT_CHART(28,1,0,0);

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
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,
                             "paperPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,253);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",253,-1,407);
        _SFD_CV_INIT_EML_IF(4,1,0,142,172,203,251);
        _SFD_CV_INIT_EML(6,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,
                             "scissorsPoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,259);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",259,-1,416);
        _SFD_CV_INIT_EML_IF(6,1,0,148,178,209,257);
        _SFD_CV_INIT_EML(5,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,
                             "rockPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,401);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",401,-1,563);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",563,-1,725);
        _SFD_CV_INIT_EML_IF(5,1,0,225,255,286,399);
        _SFD_CV_INIT_EML_IF(5,1,1,286,320,351,399);
        _SFD_CV_INIT_EML(1,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,
                             "handPoseSBRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,765);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",765,-1,1006);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1006,-1,1245);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1245,-1,1419);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1419,-1,1589);
        _SFD_CV_INIT_EML_IF(1,1,0,459,489,520,763);
        _SFD_CV_INIT_EML_IF(1,1,1,520,554,585,763);
        _SFD_CV_INIT_EML_IF(1,1,2,585,619,650,763);
        _SFD_CV_INIT_EML_IF(1,1,3,650,684,715,763);
        _SFD_CV_INIT_EML(2,1,9,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,
                             "idlePoseRachelTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,2811);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",2811,-1,2979);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",2979,-1,3159);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",3159,-1,3329);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",3329,-1,3511);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",3511,-1,3701);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",3701,-1,3871);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",3871,-1,4040);
        _SFD_CV_INIT_EML_FCN(2,8,"aFcnTruthTableAction_8",4040,-1,4206);
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
        _SFD_CV_INIT_EML(3,1,3,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,
                             "initialPoseTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,537);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",537,-1,682);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",682,-1,847);
        _SFD_CV_INIT_EML_IF(3,1,0,296,326,357,535);
        _SFD_CV_INIT_EML_IF(3,1,1,357,391,422,535);
        _SFD_CV_INIT_EML_IF(3,1,2,422,456,487,535);
        _SFD_CV_INIT_EML(36,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(36,0,
                             "successTablec4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile",
                             0,-1,566);
        _SFD_CV_INIT_EML_FCN(36,1,"aFcnTruthTableAction_1",566,-1,858);
        _SFD_CV_INIT_EML_FCN(36,2,"aFcnTruthTableAction_2",858,-1,1075);
        _SFD_CV_INIT_EML_FCN(36,3,"aFcnTruthTableAction_3",1075,-1,1327);
        _SFD_CV_INIT_EML_IF(36,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(36,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(36,1,2,451,485,516,564);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
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
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,0,13,0,13);
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
        _SFD_CV_INIT_EML_IF(12,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(24,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(24,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(25,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(25,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(28,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(28,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(34,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(35,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(35,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(40,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(42,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(42,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
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
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
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
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

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

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

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
        _SFD_SET_DATA_VALUE_PTR(40,(void *)(NULL));

        {
          real_T *c4_gameState;
          real_T *c4_inputUser;
          real_T *c4_bradHand;
          real_T *c4_userHand;
          real_T *c4_win;
          real_T *c4_bWinT;
          real_T *c4_uWinT;
          real_T *c4_round;
          c4_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c4_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c4_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c4_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c4_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c4_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c4_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(13U,
            chartInstance->c4_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c4_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c4_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c4_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c4_r_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c4_p_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c4_s_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c4_wristRotate_address);
          _SFD_SET_DATA_VALUE_PTR(21U, c4_round);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c4_isSmiling_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c4_avert_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c4_smileDur_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "oedxFsJiVODqc4yhHB793C";
}

static void
  sf_opaque_initialize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
  initialize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (void *chartInstanceVar)
{
  enable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_disable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(void
  *chartInstanceVar)
{
  disable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_gateway_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(void
  *chartInstanceVar)
{
  sf_gateway_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
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
    get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile();/* state var info */
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
  sf_internal_set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
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
    sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct* S)
{
  return NULL;
}

static void
  sf_opaque_set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct* S, const mxArray *st)
{
}

static void
  sf_opaque_terminate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
       chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_optimization_info();
    }

    finalize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
      ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
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
  initSimStructsc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
    ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
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
    initialize_params_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
      ((SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_optimization_info();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,4,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,9);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4073374885U));
  ssSetChecksum1(S,(3125824139U));
  ssSetChecksum2(S,(4138061123U));
  ssSetChecksum3(S,(32417792U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile
  (SimStruct *S)
{
  SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct
    *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance =
    (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct *)
    utMalloc(sizeof
             (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile;
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

void c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ARP_02_RPSsmile_GloveAtomicRachelNotImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
