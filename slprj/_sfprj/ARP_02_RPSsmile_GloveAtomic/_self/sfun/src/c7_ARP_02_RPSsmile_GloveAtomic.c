/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveAtomic_sfun.h"
#include "c7_ARP_02_RPSsmile_GloveAtomic.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveAtomic_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c7_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_gameOver                 ((uint8_T)1U)
#define c7_IN_stateBoredPose1          ((uint8_T)2U)
#define c7_IN_stateBradWin             ((uint8_T)3U)
#define c7_IN_stateBrowUp              ((uint8_T)4U)
#define c7_IN_stateCompare             ((uint8_T)5U)
#define c7_IN_stateGo                  ((uint8_T)6U)
#define c7_IN_stateHeadNeutral1        ((uint8_T)7U)
#define c7_IN_stateHeadNeutral2        ((uint8_T)8U)
#define c7_IN_stateIfSmile             ((uint8_T)9U)
#define c7_IN_stateNeckBack            ((uint8_T)10U)
#define c7_IN_stateNoWin               ((uint8_T)11U)
#define c7_IN_statePoseFingersCLose    ((uint8_T)12U)
#define c7_IN_statePosePaper           ((uint8_T)13U)
#define c7_IN_statePoseReady           ((uint8_T)14U)
#define c7_IN_statePoseReturnFinger    ((uint8_T)15U)
#define c7_IN_statePoseReturnWrist     ((uint8_T)16U)
#define c7_IN_statePoseRock            ((uint8_T)17U)
#define c7_IN_statePoseScissors        ((uint8_T)18U)
#define c7_IN_statePoseSmile           ((uint8_T)19U)
#define c7_IN_statePoseSmileWin        ((uint8_T)20U)
#define c7_IN_stateRandom1             ((uint8_T)21U)
#define c7_IN_stateRandomHand          ((uint8_T)22U)
#define c7_IN_stateReadUserHand        ((uint8_T)23U)
#define c7_IN_stateReady               ((uint8_T)24U)
#define c7_IN_stateShowHands           ((uint8_T)25U)
#define c7_IN_stateShowResult          ((uint8_T)26U)
#define c7_IN_stateSmile               ((uint8_T)27U)
#define c7_IN_stateStart               ((uint8_T)28U)
#define c7_IN_stateUserWin             ((uint8_T)29U)
#define c7_IN_stateWristRotate         ((uint8_T)30U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c7_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_g_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_h_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c7_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_o_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_x_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_kb_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c7_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_sb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_tb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ub_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_vb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_wb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_xb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_yb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_bc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_cc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_dc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ec_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c7_fc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_gc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_hc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_ic_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_jc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_kc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c7_lc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_mc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_nc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_oc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_qc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_rc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_sc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_tc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_uc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_vc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_wc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_xc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_yc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_ad_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_bd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_cd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_dd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_ed_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_fd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_gd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_hd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_id_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_jd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_kd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_ld_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_md_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_nd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_od_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_pd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_vd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_se_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_te_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ue_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ve_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_we_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_xe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ye_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_af_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_bf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_cf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_df_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ef_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ff_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_gf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_hf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_if_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_jf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_kf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_lf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_mf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_nf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_of_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_pf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_qf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_rf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_sf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_tf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_uf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_vf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_wf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_xf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_yf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ag_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_bg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_cg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_dg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_eg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_fg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_gg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_hg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c7_dataWrittenToVector[15];

/* Function Declarations */
static void initialize_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initialize_params_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void enable_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void disable_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_st);
static void c7_set_sim_state_side_effects_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void finalize_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void sf_gateway_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_enter_atomic_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_enter_internal_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_exit_internal_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_initc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initSimStructsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_enter_atomic_stateReady
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_stateReady(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_gameOver(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateHeadNeutral2(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance);
static void c7_enter_atomic_statePoseReady
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_statePoseReady(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateIfSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_enter_atomic_stateGo
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_stateGo(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_statePoseSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateNeckBack(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateRandomHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_statePoseFingersCLose
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_statePosePaper(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_statePoseRock(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_statePoseScissors(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance);
static void c7_stateReadUserHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance);
static void c7_enter_atomic_stateShowHands
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_stateShowHands(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_statePoseReturnFinger
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_stateCompare(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateBradWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateNoWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateRandom1(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_stateHeadNeutral1(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance);
static void c7_statePoseSmileWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance);
static void c7_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_b_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_c_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_d_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_e_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_f_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_g_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_h_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_i_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_j_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_k_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_l_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_m_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_n_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_o_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_p_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_q_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_r_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_s_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_t_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_u_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_v_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_w_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_x_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_y_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_ab_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_bb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_cb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_db_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_eb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_fb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_gb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_hb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_ib_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_jb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_kb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_lb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_mb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_nb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_ob_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_pb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_qb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_rb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_sb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_tb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_ub_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_vb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_wb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static void c7_xb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256]);
static real_T c7_rand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                      *chartInstance);
static real_T c7_eml_rand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_eml_rand_mt19937ar(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_d_state[625]);
static void c7_twister_state_vector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_mt[625], real_T c7_seed, uint32_T c7_b_mt[625]);
static void c7_b_eml_rand_mt19937ar
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_d_state[625], uint32_T c7_e_state[625], real_T *c7_r);
static void c7_eml_error(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static real_T c7_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_lowhigh[2]);
static real_T c7_b_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static real_T c7_c_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[256]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_b_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_bmlID, const char_T *c7_identifier);
static real_T c7_c_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static boolean_T c7_d_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_e_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[256]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_i_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_j_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_k_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_l_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_m_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_n_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_o_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_p_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_q_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_r_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_s_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_t_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_u_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_v_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_w_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_x_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_y_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_db_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_gd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_hd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_id_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_info_helper(const mxArray **c7_info);
static const mxArray *c7_emlrt_marshallOut(const char * c7_u);
static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u);
static void c7_activate_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_deactivate_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_increment_counters_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_reset_counters_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c7_arg
   [256]);
static void c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c7_arg
   [256]);
static void c7_rockPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_paperPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_scissorsPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_sbmID, real_T c7_poseSBM[256]);
static void c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_boredPoseSc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_boredGazec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_gazeBML[256]);
static void c7_boredPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256]);
static void c7_sendSBM(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_b_sendSBM(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_sendBML(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static void c7_b_sendBML(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);
static const mxArray *c7_jd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int8_T c7_f_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_kd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_g_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_ld_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_h_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_tp_stateStart, const char_T *c7_identifier);
static uint8_T c7_i_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint32_T c7_j_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_method, const char_T *c7_identifier);
static uint32_T c7_k_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static uint32_T c7_l_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_d_state, const char_T *c7_identifier);
static uint32_T c7_m_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_n_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_d_state, const char_T *c7_identifier,
  uint32_T c7_y[625]);
static void c7_o_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint32_T c7_y[625]);
static void c7_p_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_d_state, const char_T *c7_identifier,
  uint32_T c7_y[2]);
static void c7_q_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint32_T c7_y[2]);
static const mxArray *c7_r_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier);
static const mxArray *c7_s_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_updateDataWrittenToVector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_vectorIndex);
static void c7_errorIfDataNotWrittenToFcn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_vectorIndex, uint32_T c7_dataNumber);
static void c7_b_twister_state_vector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_mt[625], real_T c7_seed);
static real_T c7_c_eml_rand_mt19937ar
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_d_state[625]);
static real_T c7_get_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b);
static real_T c7_get_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b);
static real_T c7_get_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b);
static real_T c7_get_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static void c7_set_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b);
static real_T c7_get_wristRotate(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b);
static void c7_set_wristRotate(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c);
static real_T *c7_access_wristRotate
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T c7_b);
static void init_dsm_address_info(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void disable_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_update_debugger_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c7_is_active_c7_ARP_02_RPSsmile_GloveAtomic == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateIfSmile)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateNeckBack)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateWristRotate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateBrowUp)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_statePoseRock)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateCompare)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseReturnWrist) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateUserWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateBradWin)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateRandom1)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateHeadNeutral1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_statePoseSmileWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
      c7_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
  }

  _SFD_SET_ANIMATION(c7_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  real_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_d_hoistedGlobal;
  real_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  real_T c7_e_hoistedGlobal;
  real_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  real_T c7_f_hoistedGlobal;
  real_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  real_T c7_g_hoistedGlobal;
  real_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  uint32_T c7_h_hoistedGlobal;
  uint32_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  uint32_T c7_i_hoistedGlobal;
  uint32_T c7_i_u;
  const mxArray *c7_j_y = NULL;
  int32_T c7_i0;
  uint32_T c7_j_u[625];
  const mxArray *c7_k_y = NULL;
  int32_T c7_i1;
  uint32_T c7_k_u[2];
  const mxArray *c7_l_y = NULL;
  uint8_T c7_j_hoistedGlobal;
  uint8_T c7_l_u;
  const mxArray *c7_m_y = NULL;
  uint8_T c7_k_hoistedGlobal;
  uint8_T c7_m_u;
  const mxArray *c7_n_y = NULL;
  uint8_T c7_l_hoistedGlobal;
  uint8_T c7_n_u;
  const mxArray *c7_o_y = NULL;
  real_T *c7_bWinT;
  real_T *c7_bradHand;
  real_T *c7_gameState;
  real_T *c7_round;
  real_T *c7_uWinT;
  real_T *c7_userHand;
  real_T *c7_win;
  c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(14, 1), false);
  c7_hoistedGlobal = *c7_bWinT;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_bradHand;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = *c7_gameState;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = *c7_round;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = *c7_uWinT;
  c7_e_u = c7_e_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = *c7_userHand;
  c7_f_u = c7_f_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = *c7_win;
  c7_g_u = c7_g_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_h_hoistedGlobal = chartInstance->c7_method;
  c7_h_u = c7_h_hoistedGlobal;
  c7_i_y = NULL;
  if (!chartInstance->c7_method_not_empty) {
    sf_mex_assign(&c7_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_i_hoistedGlobal = chartInstance->c7_state;
  c7_i_u = c7_i_hoistedGlobal;
  c7_j_y = NULL;
  if (!chartInstance->c7_state_not_empty) {
    sf_mex_assign(&c7_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c7_y, 8, c7_j_y);
  for (c7_i0 = 0; c7_i0 < 625; c7_i0++) {
    c7_j_u[c7_i0] = chartInstance->c7_c_state[c7_i0];
  }

  c7_k_y = NULL;
  if (!chartInstance->c7_c_state_not_empty) {
    sf_mex_assign(&c7_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_k_y, sf_mex_create("y", c7_j_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c7_y, 9, c7_k_y);
  for (c7_i1 = 0; c7_i1 < 2; c7_i1++) {
    c7_k_u[c7_i1] = chartInstance->c7_b_state[c7_i1];
  }

  c7_l_y = NULL;
  if (!chartInstance->c7_b_state_not_empty) {
    sf_mex_assign(&c7_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_l_y, sf_mex_create("y", c7_k_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c7_y, 10, c7_l_y);
  c7_j_hoistedGlobal =
    chartInstance->c7_is_active_c7_ARP_02_RPSsmile_GloveAtomic;
  c7_l_u = c7_j_hoistedGlobal;
  c7_m_y = NULL;
  sf_mex_assign(&c7_m_y, sf_mex_create("y", &c7_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 11, c7_m_y);
  c7_k_hoistedGlobal = chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic;
  c7_m_u = c7_k_hoistedGlobal;
  c7_n_y = NULL;
  sf_mex_assign(&c7_n_y, sf_mex_create("y", &c7_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 12, c7_n_y);
  c7_l_hoistedGlobal = chartInstance->c7_temporalCounter_i1;
  c7_n_u = c7_l_hoistedGlobal;
  c7_o_y = NULL;
  sf_mex_assign(&c7_o_y, sf_mex_create("y", &c7_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 13, c7_o_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_st)
{
  const mxArray *c7_u;
  uint32_T c7_uv0[625];
  int32_T c7_i2;
  uint32_T c7_uv1[2];
  int32_T c7_i3;
  real_T *c7_bWinT;
  real_T *c7_bradHand;
  real_T *c7_gameState;
  real_T *c7_round;
  real_T *c7_uWinT;
  real_T *c7_userHand;
  real_T *c7_win;
  c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_u = sf_mex_dup(c7_st);
  *c7_bWinT = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 0)), "bWinT");
  *c7_bradHand = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 1)), "bradHand");
  *c7_gameState = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 2)), "gameState");
  *c7_round = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 3)), "round");
  *c7_uWinT = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 4)), "uWinT");
  *c7_userHand = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 5)), "userHand");
  *c7_win = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u,
    6)), "win");
  chartInstance->c7_method = c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 7)), "method");
  chartInstance->c7_state = c7_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 8)), "state");
  c7_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 9)),
                        "state", c7_uv0);
  for (c7_i2 = 0; c7_i2 < 625; c7_i2++) {
    chartInstance->c7_c_state[c7_i2] = c7_uv0[c7_i2];
  }

  c7_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 10)),
                        "state", c7_uv1);
  for (c7_i3 = 0; c7_i3 < 2; c7_i3++) {
    chartInstance->c7_b_state[c7_i3] = c7_uv1[c7_i3];
  }

  chartInstance->c7_is_active_c7_ARP_02_RPSsmile_GloveAtomic =
    c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 11)),
    "is_active_c7_ARP_02_RPSsmile_GloveAtomic");
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 12)),
     "is_c7_ARP_02_RPSsmile_GloveAtomic");
  chartInstance->c7_temporalCounter_i1 = c7_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 13)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 14)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_gameOver) {
      chartInstance->c7_tp_gameOver = 1U;
    } else {
      chartInstance->c7_tp_gameOver = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateBoredPose1) {
      chartInstance->c7_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c7_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateBradWin) {
      chartInstance->c7_tp_stateBradWin = 1U;
    } else {
      chartInstance->c7_tp_stateBradWin = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateBrowUp)
    {
      chartInstance->c7_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c7_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateCompare) {
      chartInstance->c7_tp_stateCompare = 1U;
    } else {
      chartInstance->c7_tp_stateCompare = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateGo) {
      chartInstance->c7_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateGo = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateHeadNeutral1) {
      chartInstance->c7_tp_stateHeadNeutral1 = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateHeadNeutral1 = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateHeadNeutral2) {
      chartInstance->c7_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateIfSmile) {
      chartInstance->c7_tp_stateIfSmile = 1U;
    } else {
      chartInstance->c7_tp_stateIfSmile = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateNeckBack) {
      chartInstance->c7_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateNoWin)
    {
      chartInstance->c7_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateNoWin = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseFingersCLose) {
      chartInstance->c7_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c7_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePosePaper) {
      chartInstance->c7_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_statePosePaper = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseReady) {
      chartInstance->c7_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_statePoseReady = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseReturnFinger) {
      chartInstance->c7_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c7_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseReturnWrist) {
      chartInstance->c7_tp_statePoseReturnWrist = 1U;
    } else {
      chartInstance->c7_tp_statePoseReturnWrist = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseRock) {
      chartInstance->c7_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 18) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_statePoseRock = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseScissors) {
      chartInstance->c7_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseSmile) {
      chartInstance->c7_tp_statePoseSmile = 1U;
    } else {
      chartInstance->c7_tp_statePoseSmile = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_statePoseSmileWin) {
      chartInstance->c7_tp_statePoseSmileWin = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_statePoseSmileWin = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateRandom1) {
      chartInstance->c7_tp_stateRandom1 = 1U;
    } else {
      chartInstance->c7_tp_stateRandom1 = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateRandomHand) {
      chartInstance->c7_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c7_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateReadUserHand) {
      chartInstance->c7_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c7_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateReady)
    {
      chartInstance->c7_tp_stateReady = 1U;
    } else {
      chartInstance->c7_tp_stateReady = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateShowHands) {
      chartInstance->c7_tp_stateShowHands = 1U;
    } else {
      chartInstance->c7_tp_stateShowHands = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateShowResult) {
      chartInstance->c7_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 27) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateShowResult = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateSmile)
    {
      chartInstance->c7_tp_stateSmile = 1U;
    } else {
      chartInstance->c7_tp_stateSmile = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic == c7_IN_stateStart)
    {
      chartInstance->c7_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 29) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateStart = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateUserWin) {
      chartInstance->c7_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 30) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_stateUserWin = 0U;
    }

    if (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic ==
        c7_IN_stateWristRotate) {
      chartInstance->c7_tp_stateWristRotate = 1U;
    } else {
      chartInstance->c7_tp_stateWristRotate = 0U;
    }

    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_gateway_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  c7_set_sim_state_side_effects_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

static void c7_enter_atomic_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_active_c7_ARP_02_RPSsmile_GloveAtomic = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void c7_enter_internal_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_dv0[256];
  int32_T c7_i4;
  real_T c7_dv1[256];
  real_T *c7_round;
  real_T *c7_userHand;
  real_T *c7_bradHand;
  real_T *c7_win;
  real_T *c7_gameState;
  real_T *c7_uWinT;
  real_T *c7_bWinT;
  c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  chartInstance->c7_isStable = false;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateStart = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_lc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  *c7_round = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c7_round, 22U);
  c7_set_pSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c7_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c7_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c7_set_smileYN(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  *c7_userHand = 3.0;
  c7_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_userHand, 3U);
  *c7_bradHand = 3.0;
  c7_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_bradHand, 2U);
  *c7_win = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_win, 4U);
  c7_set_BOREDOMT(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  *c7_gameState = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_gameState, 0U);
  c7_set_randomP(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  *c7_uWinT = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c7_uWinT, 10U);
  *c7_bWinT = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c7_bWinT, 9U);
  c7_set_pose(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c7_set_bored(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c7_set_randomG(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 3.0, c7_dv0);
  for (c7_i4 = 0; c7_i4 < 256; c7_i4++) {
    c7_dv1[c7_i4] = c7_dv0[c7_i4];
  }

  c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv1);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_dv2[256];
  int32_T c7_i5;
  real_T c7_dv3[256];
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 1.0;
  boolean_T c7_d_out;
  real_T c7_g_nargin = 0.0;
  real_T c7_g_nargout = 0.0;
  real_T c7_dv4[2];
  real_T *c7_round;
  real_T *c7_gameState;
  boolean_T guard1 = false;
  c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_isStable = true;
  switch (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic) {
   case c7_IN_gameOver:
    CV_CHART_EVAL(6, 0, 1);
    c7_gameOver(chartInstance);
    break;

   case c7_IN_stateBoredPose1:
    CV_CHART_EVAL(6, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c7_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateBradWin:
    CV_CHART_EVAL(6, 0, 3);
    c7_stateBradWin(chartInstance);
    break;

   case c7_IN_stateBrowUp:
    CV_CHART_EVAL(6, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c7_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateCompare:
    CV_CHART_EVAL(6, 0, 5);
    c7_stateCompare(chartInstance);
    break;

   case c7_IN_stateGo:
    CV_CHART_EVAL(6, 0, 6);
    c7_stateGo(chartInstance);
    break;

   case c7_IN_stateHeadNeutral1:
    CV_CHART_EVAL(6, 0, 7);
    c7_stateHeadNeutral1(chartInstance);
    break;

   case c7_IN_stateHeadNeutral2:
    CV_CHART_EVAL(6, 0, 8);
    c7_stateHeadNeutral2(chartInstance);
    break;

   case c7_IN_stateIfSmile:
    CV_CHART_EVAL(6, 0, 9);
    c7_stateIfSmile(chartInstance);
    break;

   case c7_IN_stateNeckBack:
    CV_CHART_EVAL(6, 0, 10);
    c7_stateNeckBack(chartInstance);
    break;

   case c7_IN_stateNoWin:
    CV_CHART_EVAL(6, 0, 11);
    c7_stateNoWin(chartInstance);
    break;

   case c7_IN_statePoseFingersCLose:
    CV_CHART_EVAL(6, 0, 12);
    c7_statePoseFingersCLose(chartInstance);
    break;

   case c7_IN_statePosePaper:
    CV_CHART_EVAL(6, 0, 13);
    c7_statePosePaper(chartInstance);
    break;

   case c7_IN_statePoseReady:
    CV_CHART_EVAL(6, 0, 14);
    c7_statePoseReady(chartInstance);
    break;

   case c7_IN_statePoseReturnFinger:
    CV_CHART_EVAL(6, 0, 15);
    c7_statePoseReturnFinger(chartInstance);
    break;

   case c7_IN_statePoseReturnWrist:
    CV_CHART_EVAL(6, 0, 16);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseReturnWrist = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateShowHands = 1U;
    c7_enter_atomic_stateShowHands(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseRock:
    CV_CHART_EVAL(6, 0, 17);
    c7_statePoseRock(chartInstance);
    break;

   case c7_IN_statePoseScissors:
    CV_CHART_EVAL(6, 0, 18);
    c7_statePoseScissors(chartInstance);
    break;

   case c7_IN_statePoseSmile:
    CV_CHART_EVAL(6, 0, 19);
    c7_statePoseSmile(chartInstance);
    break;

   case c7_IN_statePoseSmileWin:
    CV_CHART_EVAL(6, 0, 20);
    c7_statePoseSmileWin(chartInstance);
    break;

   case c7_IN_stateRandom1:
    CV_CHART_EVAL(6, 0, 21);
    c7_stateRandom1(chartInstance);
    break;

   case c7_IN_stateRandomHand:
    CV_CHART_EVAL(6, 0, 22);
    c7_stateRandomHand(chartInstance);
    break;

   case c7_IN_stateReadUserHand:
    CV_CHART_EVAL(6, 0, 23);
    c7_stateReadUserHand(chartInstance);
    break;

   case c7_IN_stateReady:
    CV_CHART_EVAL(6, 0, 24);
    c7_stateReady(chartInstance);
    break;

   case c7_IN_stateShowHands:
    CV_CHART_EVAL(6, 0, 25);
    c7_stateShowHands(chartInstance);
    break;

   case c7_IN_stateShowResult:
    CV_CHART_EVAL(6, 0, 26);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_sd_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                    (chartInstance->c7_temporalCounter_i1 >= 3))) {
      if (CV_EML_COND(5, 0, 1, *c7_round == 10.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c7_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c7_errorIfDataNotWrittenToFcn(chartInstance, 6U, 22U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c7_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c7_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_nc_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      *c7_gameState = 3.0;
      c7_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c7_gameState, 0U);
      c7_set_bored(chartInstance, 0, c7_get_bored(chartInstance, 0) - 2.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_td_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
        c7_c_sf_marshallIn);
      c7_b_out = CV_EML_IF(3, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs)
                           && (chartInstance->c7_temporalCounter_i1 >= 3));
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateShowResult = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateReady;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateReady = 1U;
        c7_enter_atomic_stateReady(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                     chartInstance->c7_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateSmile:
    CV_CHART_EVAL(6, 0, 27);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateNeckBack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_stateNeckBack = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_uc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_boredGazec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 17.0, c7_dv2);
    for (c7_i5 = 0; c7_i5 < 256; c7_i5++) {
      c7_dv3[c7_i5] = c7_dv2[c7_i5];
    }

    c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv3);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateStart:
    CV_CHART_EVAL(6, 0, 28);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_qd_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_c_out = CV_EML_IF(1, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                         (chartInstance->c7_temporalCounter_i1 >= 2));
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateStart = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateReady = 1U;
      c7_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateUserWin:
    CV_CHART_EVAL(6, 0, 29);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ue_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_d_out = CV_EML_IF(43, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                         (chartInstance->c7_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateUserWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateRandom1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateRandom1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_md_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_dv4[0] = 0.0;
      c7_dv4[1] = c7_get_bored(chartInstance, 0);
      c7_set_smileYN(chartInstance, 0, c7_randi(chartInstance, c7_dv4));
      ssUpdateDataStoreLog(chartInstance->S, 13);
      c7_set_pose(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateWristRotate:
    CV_CHART_EVAL(6, 0, 30);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateWristRotate = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_stateGo = 1U;
    c7_enter_atomic_stateGo(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c7_sfEvent);
    break;

   default:
    CV_CHART_EVAL(6, 0, 0);
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void c7_exit_internal_c7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  switch (chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic) {
   case c7_IN_gameOver:
    CV_CHART_EVAL(6, 0, 1);
    chartInstance->c7_tp_gameOver = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateBoredPose1:
    CV_CHART_EVAL(6, 0, 2);
    chartInstance->c7_tp_stateBoredPose1 = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateBradWin:
    CV_CHART_EVAL(6, 0, 3);
    chartInstance->c7_tp_stateBradWin = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateBrowUp:
    CV_CHART_EVAL(6, 0, 4);
    chartInstance->c7_tp_stateBrowUp = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateCompare:
    CV_CHART_EVAL(6, 0, 5);
    chartInstance->c7_tp_stateCompare = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateGo:
    CV_CHART_EVAL(6, 0, 6);
    chartInstance->c7_tp_stateGo = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateHeadNeutral1:
    CV_CHART_EVAL(6, 0, 7);
    chartInstance->c7_tp_stateHeadNeutral1 = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateHeadNeutral2:
    CV_CHART_EVAL(6, 0, 8);
    chartInstance->c7_tp_stateHeadNeutral2 = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateIfSmile:
    CV_CHART_EVAL(6, 0, 9);
    chartInstance->c7_tp_stateIfSmile = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateNeckBack:
    CV_CHART_EVAL(6, 0, 10);
    chartInstance->c7_tp_stateNeckBack = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateNoWin:
    CV_CHART_EVAL(6, 0, 11);
    chartInstance->c7_tp_stateNoWin = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseFingersCLose:
    CV_CHART_EVAL(6, 0, 12);
    chartInstance->c7_tp_statePoseFingersCLose = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePosePaper:
    CV_CHART_EVAL(6, 0, 13);
    chartInstance->c7_tp_statePosePaper = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseReady:
    CV_CHART_EVAL(6, 0, 14);
    chartInstance->c7_tp_statePoseReady = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseReturnFinger:
    CV_CHART_EVAL(6, 0, 15);
    chartInstance->c7_tp_statePoseReturnFinger = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseReturnWrist:
    CV_CHART_EVAL(6, 0, 16);
    chartInstance->c7_tp_statePoseReturnWrist = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseRock:
    CV_CHART_EVAL(6, 0, 17);
    chartInstance->c7_tp_statePoseRock = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseScissors:
    CV_CHART_EVAL(6, 0, 18);
    chartInstance->c7_tp_statePoseScissors = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseSmile:
    CV_CHART_EVAL(6, 0, 19);
    chartInstance->c7_tp_statePoseSmile = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_statePoseSmileWin:
    CV_CHART_EVAL(6, 0, 20);
    chartInstance->c7_tp_statePoseSmileWin = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateRandom1:
    CV_CHART_EVAL(6, 0, 21);
    chartInstance->c7_tp_stateRandom1 = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateRandomHand:
    CV_CHART_EVAL(6, 0, 22);
    chartInstance->c7_tp_stateRandomHand = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateReadUserHand:
    CV_CHART_EVAL(6, 0, 23);
    chartInstance->c7_tp_stateReadUserHand = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateReady:
    CV_CHART_EVAL(6, 0, 24);
    chartInstance->c7_tp_stateReady = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateShowHands:
    CV_CHART_EVAL(6, 0, 25);
    chartInstance->c7_tp_stateShowHands = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateShowResult:
    CV_CHART_EVAL(6, 0, 26);
    chartInstance->c7_tp_stateShowResult = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateSmile:
    CV_CHART_EVAL(6, 0, 27);
    chartInstance->c7_tp_stateSmile = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateStart:
    CV_CHART_EVAL(6, 0, 28);
    chartInstance->c7_tp_stateStart = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateUserWin:
    CV_CHART_EVAL(6, 0, 29);
    chartInstance->c7_tp_stateUserWin = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_stateWristRotate:
    CV_CHART_EVAL(6, 0, 30);
    chartInstance->c7_tp_stateWristRotate = 0U;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
    break;

   default:
    CV_CHART_EVAL(6, 0, 0);
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
    break;
  }
}

static void c7_initc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_method_not_empty = false;
  chartInstance->c7_state_not_empty = false;
  chartInstance->c7_b_state_not_empty = false;
  chartInstance->c7_c_state_not_empty = false;
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  chartInstance->c7_tp_gameOver = 0U;
  chartInstance->c7_tp_stateBoredPose1 = 0U;
  chartInstance->c7_tp_stateBradWin = 0U;
  chartInstance->c7_tp_stateBrowUp = 0U;
  chartInstance->c7_tp_stateCompare = 0U;
  chartInstance->c7_tp_stateGo = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateHeadNeutral1 = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateHeadNeutral2 = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateIfSmile = 0U;
  chartInstance->c7_tp_stateNeckBack = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateNoWin = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseFingersCLose = 0U;
  chartInstance->c7_tp_statePosePaper = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseReady = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseReturnFinger = 0U;
  chartInstance->c7_tp_statePoseReturnWrist = 0U;
  chartInstance->c7_tp_statePoseRock = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseScissors = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseSmile = 0U;
  chartInstance->c7_tp_statePoseSmileWin = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateRandom1 = 0U;
  chartInstance->c7_tp_stateRandomHand = 0U;
  chartInstance->c7_tp_stateReadUserHand = 0U;
  chartInstance->c7_tp_stateReady = 0U;
  chartInstance->c7_tp_stateShowHands = 0U;
  chartInstance->c7_tp_stateShowResult = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateSmile = 0U;
  chartInstance->c7_tp_stateStart = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateUserWin = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateWristRotate = 0U;
  chartInstance->c7_is_active_c7_ARP_02_RPSsmile_GloveAtomic = 0U;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_enter_atomic_stateReady
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T *c7_round;
  real_T *c7_bradHand;
  real_T *c7_userHand;
  real_T *c7_gameState;
  real_T *c7_win;
  c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_mc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_errorIfDataNotWrittenToFcn(chartInstance, 6U, 22U);
  (*c7_round)++;
  c7_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c7_round, 22U);
  *c7_bradHand = 3.0;
  c7_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_bradHand, 2U);
  *c7_userHand = 3.0;
  c7_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_userHand, 3U);
  *c7_gameState = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_gameState, 0U);
  *c7_win = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_win, 4U);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_stateReady(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ud_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(7, 0, 0, c7_get_bored(chartInstance, 0) < c7_get_BOREDOMT
                     (chartInstance, 0) - 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_vd_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_bored(chartInstance, 0, c7_get_bored(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    sf_mex_printf("%s =\\n", "bored");
    c7_hoistedGlobal = c7_get_bored(chartInstance, 0);
    c7_u = c7_hoistedGlobal;
    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c7_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_statePoseReady = 1U;
    c7_enter_atomic_statePoseReady(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_rd_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(2, 0, 0, c7_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateReady = 1U;
      c7_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePoseReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_statePoseReady = 1U;
      c7_enter_atomic_statePoseReady(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c7_sfEvent);
}

static void c7_gameOver(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_dv5[256];
  int32_T c7_i6;
  real_T c7_dv6[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_gameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  chartInstance->c7_isStable = false;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateHeadNeutral2;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_stateHeadNeutral2 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_oc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 8.0, c7_dv5);
  for (c7_i6 = 0; c7_i6 < 256; c7_i6++) {
    c7_dv6[c7_i6] = c7_dv5[c7_i6];
  }

  c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv6);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
}

static void c7_stateHeadNeutral2(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 1.0;
  boolean_T c7_b_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 0.0;
  real_T c7_dv7[256];
  int32_T c7_i7;
  real_T c7_dv8[256];
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_r;
  real_T c7_x;
  real_T c7_b_x;
  int32_T c7_i8;
  real_T c7_dv9[256];
  real_T *c7_uWinT;
  real_T *c7_bWinT;
  c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_xd_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(12, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_be_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    c7_b_out = CV_EML_IF(16, 0, 0, *c7_uWinT < *c7_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_sc_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_set_smileN(chartInstance, 0, c7_b_randi(chartInstance));
      ssUpdateDataStoreLog(chartInstance->S, 12);
      c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_get_smileN
        (chartInstance, 0), c7_dv7);
      for (c7_i7 = 0; c7_i7 < 256; c7_i7++) {
        c7_dv8[c7_i7] = c7_dv7[c7_i7];
      }

      c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv8);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
        c7_IN_stateBoredPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateBoredPose1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_yc_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_r = c7_rand(chartInstance);
      c7_x = c7_r * 16.0;
      c7_b_x = c7_x;
      c7_b_x = muDoubleScalarFloor(c7_b_x);
      c7_r = 3.0 + c7_b_x;
      c7_boredPoseSc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_r, c7_dv7);
      for (c7_i8 = 0; c7_i8 < 256; c7_i8++) {
        c7_dv9[c7_i8] = c7_dv7[c7_i8];
      }

      c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv9);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c7_sfEvent);
}

static void c7_enter_atomic_statePoseReady
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_dv10[256];
  int32_T c7_i9;
  real_T c7_dv11[256];
  int32_T c7_i10;
  real_T c7_dv12[256];
  real_T c7_r;
  real_T c7_x;
  real_T c7_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_pc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 8.0, c7_dv10);
  for (c7_i9 = 0; c7_i9 < 256; c7_i9++) {
    c7_dv11[c7_i9] = c7_dv10[c7_i9];
  }

  c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv11);
  c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 2.0, c7_dv10);
  for (c7_i10 = 0; c7_i10 < 256; c7_i10++) {
    c7_dv12[c7_i10] = c7_dv10[c7_i10];
  }

  c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv12);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c7_r = c7_rand(chartInstance);
  c7_x = c7_r * 2.0;
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarFloor(c7_b_x);
  c7_r = c7_b_x;
  c7_set_wristRotate(chartInstance, 0, c7_r);
  ssUpdateDataStoreLog(chartInstance->S, 16);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_statePoseReady(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv13[2];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_wd_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(8, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                  (chartInstance->c7_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(8, 0, 1, c7_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(8, 0, 0, true);
      CV_EML_IF(8, 0, 0, true);
      c7_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(8, 0, 0, false);
    CV_EML_IF(8, 0, 0, false);
    c7_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateIfSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateIfSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_qc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_dv13[0] = 0.0;
    c7_dv13[1] = c7_get_bored(chartInstance, 0);
    c7_set_smileYN(chartInstance, 0, c7_randi(chartInstance, c7_dv13));
    ssUpdateDataStoreLog(chartInstance->S, 13);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c7_sfEvent);
}

static void c7_stateIfSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 0.0;
  real_T c7_dv14[256];
  int32_T c7_i11;
  real_T c7_dv15[256];
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 1.0;
  boolean_T c7_d_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ae_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(11, 0, 0, c7_get_smileYN(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateIfSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePoseSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_tc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pSmile(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 6);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_yd_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(10, 0, 0, c7_get_smileYN(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_de_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_c_sf_marshallOut,
        c7_c_sf_marshallIn);
      c7_c_out = CV_EML_IF(17, 0, 0, c7_get_wristRotate(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateIfSmile = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
          c7_IN_stateWristRotate;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateWristRotate = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_vc_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        c7_set_pose(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 7);
        c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 5.0, c7_dv14);
        for (c7_i11 = 0; c7_i11 < 256; c7_i11++) {
          c7_dv15[c7_i11] = c7_dv14[c7_i11];
        }

        c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv15);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                     chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ce_debug_family_names,
          c7_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_out, 2U, c7_c_sf_marshallOut,
          c7_c_sf_marshallIn);
        c7_d_out = CV_EML_IF(14, 0, 0, c7_get_wristRotate(chartInstance, 0) !=
                             1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c7_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
          chartInstance->c7_tp_stateIfSmile = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
          chartInstance->c7_isStable = false;
          chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateGo;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
          chartInstance->c7_temporalCounter_i1 = 0U;
          chartInstance->c7_tp_stateGo = 1U;
          c7_enter_atomic_stateGo(chartInstance);
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c7_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c7_sfEvent);
}

static void c7_enter_atomic_stateGo
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T *c7_gameState;
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_rc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  *c7_gameState = 1.0;
  c7_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_gameState, 0U);
  c7_set_pSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_stateGo(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_r;
  real_T c7_x;
  real_T c7_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ee_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(19, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateRandomHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateRandomHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_wc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_r = c7_rand(chartInstance);
    c7_x = c7_r * 3.0;
    c7_b_x = c7_x;
    c7_b_x = muDoubleScalarFloor(c7_b_x);
    c7_r = c7_b_x;
    c7_set_bHand(chartInstance, 0, c7_r);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c7_sfEvent);
}

static void c7_statePoseSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv16[256];
  int32_T c7_i12;
  real_T c7_dv17[256];
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_de_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(17, 0, 0, c7_get_wristRotate(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateWristRotate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateWristRotate = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_vc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 5.0, c7_dv16);
    for (c7_i12 = 0; c7_i12 < 256; c7_i12++) {
      c7_dv17[c7_i12] = c7_dv16[c7_i12];
    }

    c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv17);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ce_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(14, 0, 0, c7_get_wristRotate(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_statePoseSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateGo;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_stateGo = 1U;
      c7_enter_atomic_stateGo(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c7_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c7_sfEvent);
}

static void c7_stateNeckBack(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv18[256];
  int32_T c7_i13;
  real_T c7_dv19[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_fe_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(21, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateNeckBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_xc_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_boredGazec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 18.0, c7_dv18);
    for (c7_i13 = 0; c7_i13 < 256; c7_i13++) {
      c7_dv19[c7_i13] = c7_dv18[c7_i13];
    }

    c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv19);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c7_sfEvent);
}

static void c7_stateRandomHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv20[256];
  int32_T c7_i14;
  real_T c7_dv21[256];
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  int32_T c7_i15;
  real_T c7_dv22[256];
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 0.0;
  int32_T c7_i16;
  real_T c7_dv23[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ie_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(25, 0, 0, c7_get_bHand(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_bd_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_set_p(chartInstance, 0, c7_c_randi(chartInstance));
    ssUpdateDataStoreLog(chartInstance->S, 5);
    c7_paperPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_get_p
      (chartInstance, 0), c7_dv20);
    for (c7_i14 = 0; c7_i14 < 256; c7_i14++) {
      c7_dv21[c7_i14] = c7_dv20[c7_i14];
    }

    c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv21);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ge_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(24, 0, 0, c7_get_bHand(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_cd_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_set_pose(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c7_set_r(chartInstance, 0, c7_c_randi(chartInstance));
      ssUpdateDataStoreLog(chartInstance->S, 8);
      c7_rockPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_get_r
        (chartInstance, 0), c7_dv20);
      for (c7_i15 = 0; c7_i15 < 256; c7_i15++) {
        c7_dv22[c7_i15] = c7_dv20[c7_i15];
      }

      c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv22);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_he_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_c_sf_marshallOut,
        c7_c_sf_marshallIn);
      c7_c_out = CV_EML_IF(23, 0, 0, c7_get_bHand(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
          c7_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ad_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        c7_set_pose(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 7);
        c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 1.0, c7_dv20);
        for (c7_i16 = 0; c7_i16 < 256; c7_i16++) {
          c7_dv23[c7_i16] = c7_dv20[c7_i16];
        }

        c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv23);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                     chartInstance->c7_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c7_sfEvent);
}

static void c7_statePoseFingersCLose
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_dv24[256];
  int32_T c7_i17;
  real_T c7_dv25[256];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c7_sfEvent);
  chartInstance->c7_isStable = false;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_dd_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c7_set_s(chartInstance, 0, c7_c_randi(chartInstance));
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c7_scissorsPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_get_s
    (chartInstance, 0), c7_dv24);
  for (c7_i17 = 0; c7_i17 < 256; c7_i17++) {
    c7_dv25[c7_i17] = c7_dv24[c7_i17];
  }

  c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv25);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c7_sfEvent);
}

static void c7_statePosePaper(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T *c7_inputUser;
  boolean_T guard1 = false;
  c7_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ke_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(27, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                  (chartInstance->c7_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(27, 0, 1, c7_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(27, 0, 0, true);
      CV_EML_IF(27, 0, 0, true);
      c7_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(27, 0, 0, false);
    CV_EML_IF(27, 0, 0, false);
    c7_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ed_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_set_uHand(chartInstance, 0, *c7_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c7_sfEvent);
}

static void c7_statePoseRock(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T *c7_inputUser;
  boolean_T guard1 = false;
  c7_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_je_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(26, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                  (chartInstance->c7_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(26, 0, 1, c7_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(26, 0, 0, true);
      CV_EML_IF(26, 0, 0, true);
      c7_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(26, 0, 0, false);
    CV_EML_IF(26, 0, 0, false);
    c7_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ed_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_set_uHand(chartInstance, 0, *c7_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c7_sfEvent);
}

static void c7_statePoseScissors(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T *c7_inputUser;
  boolean_T guard1 = false;
  c7_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_le_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(30, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                  (chartInstance->c7_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(30, 0, 1, c7_get_uHand(chartInstance, 0) != 3.0)) {
      CV_EML_MCDC(30, 0, 0, true);
      CV_EML_IF(30, 0, 0, true);
      c7_out = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(30, 0, 0, false);
    CV_EML_IF(30, 0, 0, false);
    c7_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseScissors = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ed_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_set_uHand(chartInstance, 0, *c7_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c7_sfEvent);
}

static void c7_stateReadUserHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_dv26[256];
  int32_T c7_i18;
  real_T c7_dv27[256];
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 0.0;
  int32_T c7_i19;
  real_T c7_dv28[256];
  real_T *c7_inputUser;
  c7_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_me_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(29, 0, 0, c7_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ed_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_set_uHand(chartInstance, 0, *c7_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 15);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ne_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(33, 0, 0, c7_get_bHand(chartInstance, 0) == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
        c7_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_gd_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_set_pose(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 2.0, c7_dv26);
      for (c7_i18 = 0; c7_i18 < 256; c7_i18++) {
        c7_dv27[c7_i18] = c7_dv26[c7_i18];
      }

      c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv27);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_oe_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_c_sf_marshallOut,
        c7_c_sf_marshallIn);
      c7_c_out = CV_EML_IF(32, 0, 0, c7_get_wristRotate(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
          c7_IN_statePoseReturnWrist;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_statePoseReturnWrist = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_id_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        c7_set_pose(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 7);
        c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 6.0, c7_dv26);
        for (c7_i19 = 0; c7_i19 < 256; c7_i19++) {
          c7_dv28[c7_i19] = c7_dv26[c7_i19];
        }

        c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv28);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
          c7_IN_stateShowHands;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateShowHands = 1U;
        c7_enter_atomic_stateShowHands(chartInstance);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c7_sfEvent);
}

static void c7_enter_atomic_stateShowHands
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T *c7_gameState;
  real_T *c7_bradHand;
  real_T *c7_userHand;
  c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_fd_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  *c7_gameState = 2.0;
  c7_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_gameState, 0U);
  *c7_bradHand = c7_get_bHand(chartInstance, 0);
  c7_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_bradHand, 2U);
  *c7_userHand = c7_get_uHand(chartInstance, 0);
  c7_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_userHand, 3U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_stateShowHands(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_A;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_y;
  real_T c7_d_x;
  real_T c7_e_x;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_stateShowHands = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
  chartInstance->c7_isStable = false;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_hd_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_set_pose(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c7_set_temp(chartInstance, 0, c7_get_uHand(chartInstance, 0) - c7_get_bHand
              (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c7_hoistedGlobal = c7_get_temp(chartInstance, 0);
  c7_b_hoistedGlobal = c7_get_temp(chartInstance, 0);
  c7_A = c7_b_hoistedGlobal;
  c7_x = c7_A;
  c7_b_x = c7_x;
  c7_c_x = c7_b_x;
  c7_y = c7_c_x / 3.0;
  c7_d_x = c7_y;
  c7_e_x = c7_d_x;
  c7_e_x = muDoubleScalarFloor(c7_e_x);
  c7_set_diff(chartInstance, 0, c7_hoistedGlobal - 3.0 * c7_e_x);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c7_sfEvent);
}

static void c7_statePoseReturnFinger
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv29[256];
  int32_T c7_i20;
  real_T c7_dv30[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_pe_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(37, 0, 0, c7_get_wristRotate(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_statePoseReturnWrist;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseReturnWrist = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_id_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 6.0, c7_dv29);
    for (c7_i20 = 0; c7_i20 < 256; c7_i20++) {
      c7_dv30[c7_i20] = c7_dv29[c7_i20];
    }

    c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv30);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateShowHands = 1U;
    c7_enter_atomic_stateShowHands(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c7_sfEvent);
}

static void c7_stateCompare(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 0.0;
  real_T *c7_win;
  real_T *c7_uWinT;
  real_T *c7_bWinT;
  boolean_T guard1 = false;
  c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_re_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(39, 0, 0, c7_get_diff(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateCompare = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateBradWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateBradWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_kd_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    *c7_win = 2.0;
    c7_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c7_win, 4U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
    (*c7_bWinT)++;
    c7_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c7_bWinT, 9U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_qe_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(38, 0, 0, c7_get_diff(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateUserWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_stateUserWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_jd_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_set_pose(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      *c7_win = 1.0;
      c7_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c7_win, 4U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      (*c7_uWinT)++;
      c7_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_DATA_RANGE_CHECK(*c7_uWinT, 10U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_se_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_c_sf_marshallOut,
        c7_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(40, 0, 0, c7_get_diff(chartInstance, 0) != 1.0)) {
        if (CV_EML_COND(40, 0, 1, c7_get_diff(chartInstance, 0) != 2.0)) {
          CV_EML_MCDC(40, 0, 0, true);
          CV_EML_IF(40, 0, 0, true);
          c7_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(40, 0, 0, false);
        CV_EML_IF(40, 0, 0, false);
        c7_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c7_sfEvent);
        chartInstance->c7_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
        chartInstance->c7_isStable = false;
        chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateNoWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_tp_stateNoWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_ld_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        *c7_win = 0.0;
        c7_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c7_win, 4U);
        c7_set_pose(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 7);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c7_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c7_sfEvent);
}

static void c7_stateBradWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T c7_dv31[2];
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_stateBradWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  chartInstance->c7_isStable = false;
  chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateRandom1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_stateRandom1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_md_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  c7_dv31[0] = 0.0;
  c7_dv31[1] = c7_get_bored(chartInstance, 0);
  c7_set_smileYN(chartInstance, 0, c7_randi(chartInstance, c7_dv31));
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c7_set_pose(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c7_sfEvent);
}

static void c7_stateNoWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv32[2];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_te_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(42, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_md_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_dv32[0] = 0.0;
    c7_dv32[1] = c7_get_bored(chartInstance, 0);
    c7_set_smileYN(chartInstance, 0, c7_randi(chartInstance, c7_dv32));
    ssUpdateDataStoreLog(chartInstance->S, 13);
    c7_set_pose(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c7_sfEvent);
}

static void c7_stateRandom1(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv33[256];
  int32_T c7_i21;
  real_T c7_dv34[256];
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 44U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ve_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(44, 0, 0, c7_get_smileYN(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateRandom1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_stateHeadNeutral1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_stateHeadNeutral1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_nd_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, 8.0, c7_dv33);
    for (c7_i21 = 0; c7_i21 < 256; c7_i21++) {
      c7_dv34[c7_i21] = c7_dv33[c7_i21];
    }

    c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv34);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_we_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_c_sf_marshallOut,
      c7_c_sf_marshallIn);
    c7_b_out = CV_EML_IF(45, 0, 0, c7_get_smileYN(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_stateRandom1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c7_sfEvent);
      chartInstance->c7_isStable = false;
      chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
        c7_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_pd_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      c7_set_pose(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 7);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c7_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c7_sfEvent);
}

static void c7_stateHeadNeutral1(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_dv35[256];
  int32_T c7_i22;
  real_T c7_dv36[256];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_xe_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(46, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_stateHeadNeutral1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic =
      c7_IN_statePoseSmileWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_statePoseSmileWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_od_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_smileN(chartInstance, 0, c7_b_randi(chartInstance));
    ssUpdateDataStoreLog(chartInstance->S, 12);
    c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_get_smileN
      (chartInstance, 0), c7_dv35);
    for (c7_i22 = 0; c7_i22 < 256; c7_i22++) {
      c7_dv36[c7_i22] = c7_dv35[c7_i22];
    }

    c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_dv36);
    c7_set_pose(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c7_sfEvent);
}

static void c7_statePoseSmileWin(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_ye_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  c7_out = CV_EML_IF(47, 0, 0, (chartInstance->c7_sfEvent == c7_event_secs) &&
                     (chartInstance->c7_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c7_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c7_sfEvent);
    chartInstance->c7_tp_statePoseSmileWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c7_sfEvent);
    chartInstance->c7_isStable = false;
    chartInstance->c7_is_c7_ARP_02_RPSsmile_GloveAtomic = c7_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c7_sfEvent);
    chartInstance->c7_temporalCounter_i1 = 0U;
    chartInstance->c7_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_pd_debug_family_names,
      c7_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_set_pose(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c7_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c7_sfEvent);
}

static void c7_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[94];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[94];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i23;
  static char_T c7_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i24;
  static real_T c7_dv37[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_b_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i23 = 0; c7_i23 < 94; c7_i23++) {
    c7_mystr[c7_i23] = c7_cv0[c7_i23];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i24 = 0; c7_i24 < 94; c7_i24++) {
    c7_arr[c7_i24] = c7_dv37[c7_i24];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i25 = 0; c7_i25 < 256; c7_i25++) {
    c7_tt[c7_i25] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i26 = 0; c7_i26 < 94; c7_i26++) {
    c7_tt[c7_i26] = c7_arr[c7_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i27 = 0; c7_i27 < 256; c7_i27++) {
    c7_myarr256[c7_i27] = c7_tt[c7_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_b_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[88];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[88];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i28;
  static char_T c7_cv1[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c7_i29;
  static real_T c7_dv38[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_e_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i28 = 0; c7_i28 < 88; c7_i28++) {
    c7_mystr[c7_i28] = c7_cv1[c7_i28];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i29 = 0; c7_i29 < 88; c7_i29++) {
    c7_arr[c7_i29] = c7_dv38[c7_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i30 = 0; c7_i30 < 256; c7_i30++) {
    c7_tt[c7_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i31 = 0; c7_i31 < 88; c7_i31++) {
    c7_tt[c7_i31] = c7_arr[c7_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i32 = 0; c7_i32 < 256; c7_i32++) {
    c7_myarr256[c7_i32] = c7_tt[c7_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_c_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[86];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[86];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i33;
  static char_T c7_cv2[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c7_i34;
  static real_T c7_dv39[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_f_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i33 = 0; c7_i33 < 86; c7_i33++) {
    c7_mystr[c7_i33] = c7_cv2[c7_i33];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i34 = 0; c7_i34 < 86; c7_i34++) {
    c7_arr[c7_i34] = c7_dv39[c7_i34];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i35 = 0; c7_i35 < 256; c7_i35++) {
    c7_tt[c7_i35] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i36 = 0; c7_i36 < 86; c7_i36++) {
    c7_tt[c7_i36] = c7_arr[c7_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i37 = 0; c7_i37 < 256; c7_i37++) {
    c7_myarr256[c7_i37] = c7_tt[c7_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_d_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[161];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[161];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i38;
  static char_T c7_cv3[161] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c7_i39;
  static real_T c7_dv40[161] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_i_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i38 = 0; c7_i38 < 161; c7_i38++) {
    c7_mystr[c7_i38] = c7_cv3[c7_i38];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i39 = 0; c7_i39 < 161; c7_i39++) {
    c7_arr[c7_i39] = c7_dv40[c7_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i40 = 0; c7_i40 < 256; c7_i40++) {
    c7_tt[c7_i40] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i41 = 0; c7_i41 < 161; c7_i41++) {
    c7_tt[c7_i41] = c7_arr[c7_i41];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i42 = 0; c7_i42 < 256; c7_i42++) {
    c7_myarr256[c7_i42] = c7_tt[c7_i42];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_e_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[157];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[157];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i43;
  static char_T c7_cv4[157] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c7_i44;
  static real_T c7_dv41[157] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c7_i45;
  int32_T c7_i46;
  int32_T c7_i47;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_j_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i43 = 0; c7_i43 < 157; c7_i43++) {
    c7_mystr[c7_i43] = c7_cv4[c7_i43];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i44 = 0; c7_i44 < 157; c7_i44++) {
    c7_arr[c7_i44] = c7_dv41[c7_i44];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 157.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i45 = 0; c7_i45 < 256; c7_i45++) {
    c7_tt[c7_i45] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i46 = 0; c7_i46 < 157; c7_i46++) {
    c7_tt[c7_i46] = c7_arr[c7_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i47 = 0; c7_i47 < 256; c7_i47++) {
    c7_myarr256[c7_i47] = c7_tt[c7_i47];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_f_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[92];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[92];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i48;
  static char_T c7_cv5[92] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '0', '5', ')', ')', ';' };

  int32_T c7_i49;
  static real_T c7_dv42[92] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 46.0, 48.0, 53.0, 41.0, 41.0, 59.0 };

  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_k_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i48 = 0; c7_i48 < 92; c7_i48++) {
    c7_mystr[c7_i48] = c7_cv5[c7_i48];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i49 = 0; c7_i49 < 92; c7_i49++) {
    c7_arr[c7_i49] = c7_dv42[c7_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i50 = 0; c7_i50 < 256; c7_i50++) {
    c7_tt[c7_i50] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i51 = 0; c7_i51 < 92; c7_i51++) {
    c7_tt[c7_i51] = c7_arr[c7_i51];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i52 = 0; c7_i52 < 256; c7_i52++) {
    c7_myarr256[c7_i52] = c7_tt[c7_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_g_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[89];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[89];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i53;
  static char_T c7_cv6[89] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', ')', ')', ';' };

  int32_T c7_i54;
  static real_T c7_dv43[89] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0, 59.0 };

  int32_T c7_i55;
  int32_T c7_i56;
  int32_T c7_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_l_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i53 = 0; c7_i53 < 89; c7_i53++) {
    c7_mystr[c7_i53] = c7_cv6[c7_i53];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i54 = 0; c7_i54 < 89; c7_i54++) {
    c7_arr[c7_i54] = c7_dv43[c7_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 89.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i55 = 0; c7_i55 < 256; c7_i55++) {
    c7_tt[c7_i55] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i56 = 0; c7_i56 < 89; c7_i56++) {
    c7_tt[c7_i56] = c7_arr[c7_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i57 = 0; c7_i57 < 256; c7_i57++) {
    c7_myarr256[c7_i57] = c7_tt[c7_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_h_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[78];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[78];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i58;
  static char_T c7_cv7[78] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w', 'r', 'i',
    's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't',
    'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',',
    '0', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c7_i59;
  static real_T c7_dv44[78] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0, 105.0,
    115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0, 59.0 };

  int32_T c7_i60;
  int32_T c7_i61;
  int32_T c7_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_n_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i58 = 0; c7_i58 < 78; c7_i58++) {
    c7_mystr[c7_i58] = c7_cv7[c7_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i59 = 0; c7_i59 < 78; c7_i59++) {
    c7_arr[c7_i59] = c7_dv44[c7_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 78.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i60 = 0; c7_i60 < 256; c7_i60++) {
    c7_tt[c7_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i61 = 0; c7_i61 < 78; c7_i61++) {
    c7_tt[c7_i61] = c7_arr[c7_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i62 = 0; c7_i62 < 256; c7_i62++) {
    c7_myarr256[c7_i62] = c7_tt[c7_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_i_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[147];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[147];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i63;
  static char_T c7_cv8[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
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

  int32_T c7_i64;
  static real_T c7_dv45[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i65;
  int32_T c7_i66;
  int32_T c7_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_p_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i63 = 0; c7_i63 < 147; c7_i63++) {
    c7_mystr[c7_i63] = c7_cv8[c7_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i64 = 0; c7_i64 < 147; c7_i64++) {
    c7_arr[c7_i64] = c7_dv45[c7_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i65 = 0; c7_i65 < 256; c7_i65++) {
    c7_tt[c7_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i66 = 0; c7_i66 < 147; c7_i66++) {
    c7_tt[c7_i66] = c7_arr[c7_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i67 = 0; c7_i67 < 256; c7_i67++) {
    c7_myarr256[c7_i67] = c7_tt[c7_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_j_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[164];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[164];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i68;
  static char_T c7_cv9[164] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
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

  int32_T c7_i69;
  static real_T c7_dv46[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i70;
  int32_T c7_i71;
  int32_T c7_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_q_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i68 = 0; c7_i68 < 164; c7_i68++) {
    c7_mystr[c7_i68] = c7_cv9[c7_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i69 = 0; c7_i69 < 164; c7_i69++) {
    c7_arr[c7_i69] = c7_dv46[c7_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i70 = 0; c7_i70 < 256; c7_i70++) {
    c7_tt[c7_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i71 = 0; c7_i71 < 164; c7_i71++) {
    c7_tt[c7_i71] = c7_arr[c7_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i72 = 0; c7_i72 < 256; c7_i72++) {
    c7_myarr256[c7_i72] = c7_tt[c7_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_k_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[223];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[223];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i73;
  static char_T c7_cv10[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c7_i74;
  static real_T c7_dv47[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i75;
  int32_T c7_i76;
  int32_T c7_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_s_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i73 = 0; c7_i73 < 223; c7_i73++) {
    c7_mystr[c7_i73] = c7_cv10[c7_i73];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i74 = 0; c7_i74 < 223; c7_i74++) {
    c7_arr[c7_i74] = c7_dv47[c7_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i75 = 0; c7_i75 < 256; c7_i75++) {
    c7_tt[c7_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i76 = 0; c7_i76 < 223; c7_i76++) {
    c7_tt[c7_i76] = c7_arr[c7_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i77 = 0; c7_i77 < 256; c7_i77++) {
    c7_myarr256[c7_i77] = c7_tt[c7_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_l_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[223];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[223];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i78;
  static char_T c7_cv11[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c7_i79;
  static real_T c7_dv48[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i80;
  int32_T c7_i81;
  int32_T c7_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_t_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i78 = 0; c7_i78 < 223; c7_i78++) {
    c7_mystr[c7_i78] = c7_cv11[c7_i78];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i79 = 0; c7_i79 < 223; c7_i79++) {
    c7_arr[c7_i79] = c7_dv48[c7_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i80 = 0; c7_i80 < 256; c7_i80++) {
    c7_tt[c7_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i81 = 0; c7_i81 < 223; c7_i81++) {
    c7_tt[c7_i81] = c7_arr[c7_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i82 = 0; c7_i82 < 256; c7_i82++) {
    c7_myarr256[c7_i82] = c7_tt[c7_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_m_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[225];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[225];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i83;
  static char_T c7_cv12[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c7_i84;
  static real_T c7_dv49[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i85;
  int32_T c7_i86;
  int32_T c7_i87;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_u_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i83 = 0; c7_i83 < 225; c7_i83++) {
    c7_mystr[c7_i83] = c7_cv12[c7_i83];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i84 = 0; c7_i84 < 225; c7_i84++) {
    c7_arr[c7_i84] = c7_dv49[c7_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i85 = 0; c7_i85 < 256; c7_i85++) {
    c7_tt[c7_i85] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i86 = 0; c7_i86 < 225; c7_i86++) {
    c7_tt[c7_i86] = c7_arr[c7_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i87 = 0; c7_i87 < 256; c7_i87++) {
    c7_myarr256[c7_i87] = c7_tt[c7_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_n_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[225];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[225];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i88;
  static char_T c7_cv13[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c7_i89;
  static real_T c7_dv50[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i90;
  int32_T c7_i91;
  int32_T c7_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_v_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i88 = 0; c7_i88 < 225; c7_i88++) {
    c7_mystr[c7_i88] = c7_cv13[c7_i88];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i89 = 0; c7_i89 < 225; c7_i89++) {
    c7_arr[c7_i89] = c7_dv50[c7_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i90 = 0; c7_i90 < 256; c7_i90++) {
    c7_tt[c7_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i91 = 0; c7_i91 < 225; c7_i91++) {
    c7_tt[c7_i91] = c7_arr[c7_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i92 = 0; c7_i92 < 256; c7_i92++) {
    c7_myarr256[c7_i92] = c7_tt[c7_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_o_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[87];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[87];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i93;
  static char_T c7_cv14[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c7_i94;
  static real_T c7_dv51[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i95;
  int32_T c7_i96;
  int32_T c7_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_w_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i93 = 0; c7_i93 < 87; c7_i93++) {
    c7_mystr[c7_i93] = c7_cv14[c7_i93];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i94 = 0; c7_i94 < 87; c7_i94++) {
    c7_arr[c7_i94] = c7_dv51[c7_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i95 = 0; c7_i95 < 256; c7_i95++) {
    c7_tt[c7_i95] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i96 = 0; c7_i96 < 87; c7_i96++) {
    c7_tt[c7_i96] = c7_arr[c7_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i97 = 0; c7_i97 < 256; c7_i97++) {
    c7_myarr256[c7_i97] = c7_tt[c7_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_p_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[91];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[91];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i98;
  static char_T c7_cv15[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i99;
  static real_T c7_dv52[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c7_i100;
  int32_T c7_i101;
  int32_T c7_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_y_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i98 = 0; c7_i98 < 91; c7_i98++) {
    c7_mystr[c7_i98] = c7_cv15[c7_i98];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i99 = 0; c7_i99 < 91; c7_i99++) {
    c7_arr[c7_i99] = c7_dv52[c7_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i100 = 0; c7_i100 < 256; c7_i100++) {
    c7_tt[c7_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i101 = 0; c7_i101 < 91; c7_i101++) {
    c7_tt[c7_i101] = c7_arr[c7_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i102 = 0; c7_i102 < 256; c7_i102++) {
    c7_myarr256[c7_i102] = c7_tt[c7_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_q_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[87];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[87];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i103;
  static char_T c7_cv16[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c7_i104;
  static real_T c7_dv53[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i105;
  int32_T c7_i106;
  int32_T c7_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ab_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i103 = 0; c7_i103 < 87; c7_i103++) {
    c7_mystr[c7_i103] = c7_cv16[c7_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i104 = 0; c7_i104 < 87; c7_i104++) {
    c7_arr[c7_i104] = c7_dv53[c7_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i105 = 0; c7_i105 < 256; c7_i105++) {
    c7_tt[c7_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i106 = 0; c7_i106 < 87; c7_i106++) {
    c7_tt[c7_i106] = c7_arr[c7_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i107 = 0; c7_i107 < 256; c7_i107++) {
    c7_myarr256[c7_i107] = c7_tt[c7_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_r_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[93];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[93];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i108;
  static char_T c7_cv17[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i109;
  static real_T c7_dv54[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i110;
  int32_T c7_i111;
  int32_T c7_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_bb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i108 = 0; c7_i108 < 93; c7_i108++) {
    c7_mystr[c7_i108] = c7_cv17[c7_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i109 = 0; c7_i109 < 93; c7_i109++) {
    c7_arr[c7_i109] = c7_dv54[c7_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i110 = 0; c7_i110 < 256; c7_i110++) {
    c7_tt[c7_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i111 = 0; c7_i111 < 93; c7_i111++) {
    c7_tt[c7_i111] = c7_arr[c7_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i112 = 0; c7_i112 < 256; c7_i112++) {
    c7_myarr256[c7_i112] = c7_tt[c7_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_s_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[94];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[94];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i113;
  static char_T c7_cv18[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i114;
  static real_T c7_dv55[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i115;
  int32_T c7_i116;
  int32_T c7_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_cb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i113 = 0; c7_i113 < 94; c7_i113++) {
    c7_mystr[c7_i113] = c7_cv18[c7_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i114 = 0; c7_i114 < 94; c7_i114++) {
    c7_arr[c7_i114] = c7_dv55[c7_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i115 = 0; c7_i115 < 256; c7_i115++) {
    c7_tt[c7_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i116 = 0; c7_i116 < 94; c7_i116++) {
    c7_tt[c7_i116] = c7_arr[c7_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i117 = 0; c7_i117 < 256; c7_i117++) {
    c7_myarr256[c7_i117] = c7_tt[c7_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_t_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[95];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[95];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i118;
  static char_T c7_cv19[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i119;
  static real_T c7_dv56[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i120;
  int32_T c7_i121;
  int32_T c7_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_db_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i118 = 0; c7_i118 < 95; c7_i118++) {
    c7_mystr[c7_i118] = c7_cv19[c7_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i119 = 0; c7_i119 < 95; c7_i119++) {
    c7_arr[c7_i119] = c7_dv56[c7_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i120 = 0; c7_i120 < 256; c7_i120++) {
    c7_tt[c7_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i121 = 0; c7_i121 < 95; c7_i121++) {
    c7_tt[c7_i121] = c7_arr[c7_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i122 = 0; c7_i122 < 256; c7_i122++) {
    c7_myarr256[c7_i122] = c7_tt[c7_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_u_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[88];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[88];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i123;
  static char_T c7_cv20[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c7_i124;
  static real_T c7_dv57[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i125;
  int32_T c7_i126;
  int32_T c7_i127;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_eb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i123 = 0; c7_i123 < 88; c7_i123++) {
    c7_mystr[c7_i123] = c7_cv20[c7_i123];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i124 = 0; c7_i124 < 88; c7_i124++) {
    c7_arr[c7_i124] = c7_dv57[c7_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i125 = 0; c7_i125 < 256; c7_i125++) {
    c7_tt[c7_i125] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i126 = 0; c7_i126 < 88; c7_i126++) {
    c7_tt[c7_i126] = c7_arr[c7_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i127 = 0; c7_i127 < 256; c7_i127++) {
    c7_myarr256[c7_i127] = c7_tt[c7_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_v_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[93];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[93];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i128;
  static char_T c7_cv21[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i129;
  static real_T c7_dv58[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i130;
  int32_T c7_i131;
  int32_T c7_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_fb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i128 = 0; c7_i128 < 93; c7_i128++) {
    c7_mystr[c7_i128] = c7_cv21[c7_i128];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i129 = 0; c7_i129 < 93; c7_i129++) {
    c7_arr[c7_i129] = c7_dv58[c7_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i130 = 0; c7_i130 < 256; c7_i130++) {
    c7_tt[c7_i130] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i131 = 0; c7_i131 < 93; c7_i131++) {
    c7_tt[c7_i131] = c7_arr[c7_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i132 = 0; c7_i132 < 256; c7_i132++) {
    c7_myarr256[c7_i132] = c7_tt[c7_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_w_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[93];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[93];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i133;
  static char_T c7_cv22[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i134;
  static real_T c7_dv59[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i135;
  int32_T c7_i136;
  int32_T c7_i137;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_gb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i133 = 0; c7_i133 < 93; c7_i133++) {
    c7_mystr[c7_i133] = c7_cv22[c7_i133];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i134 = 0; c7_i134 < 93; c7_i134++) {
    c7_arr[c7_i134] = c7_dv59[c7_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i135 = 0; c7_i135 < 256; c7_i135++) {
    c7_tt[c7_i135] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i136 = 0; c7_i136 < 93; c7_i136++) {
    c7_tt[c7_i136] = c7_arr[c7_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i137 = 0; c7_i137 < 256; c7_i137++) {
    c7_myarr256[c7_i137] = c7_tt[c7_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_x_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[97];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[97];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i138;
  static char_T c7_cv23[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i139;
  static real_T c7_dv60[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i140;
  int32_T c7_i141;
  int32_T c7_i142;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_hb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i138 = 0; c7_i138 < 97; c7_i138++) {
    c7_mystr[c7_i138] = c7_cv23[c7_i138];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i139 = 0; c7_i139 < 97; c7_i139++) {
    c7_arr[c7_i139] = c7_dv60[c7_i139];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i140 = 0; c7_i140 < 256; c7_i140++) {
    c7_tt[c7_i140] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i141 = 0; c7_i141 < 97; c7_i141++) {
    c7_tt[c7_i141] = c7_arr[c7_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i142 = 0; c7_i142 < 256; c7_i142++) {
    c7_myarr256[c7_i142] = c7_tt[c7_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_y_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[97];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[97];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i143;
  static char_T c7_cv24[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i144;
  static real_T c7_dv61[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i145;
  int32_T c7_i146;
  int32_T c7_i147;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ib_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i143 = 0; c7_i143 < 97; c7_i143++) {
    c7_mystr[c7_i143] = c7_cv24[c7_i143];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i144 = 0; c7_i144 < 97; c7_i144++) {
    c7_arr[c7_i144] = c7_dv61[c7_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i145 = 0; c7_i145 < 256; c7_i145++) {
    c7_tt[c7_i145] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i146 = 0; c7_i146 < 97; c7_i146++) {
    c7_tt[c7_i146] = c7_arr[c7_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i147 = 0; c7_i147 < 256; c7_i147++) {
    c7_myarr256[c7_i147] = c7_tt[c7_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_ab_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[92];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[92];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i148;
  static char_T c7_cv25[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i149;
  static real_T c7_dv62[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c7_i150;
  int32_T c7_i151;
  int32_T c7_i152;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_jb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i148 = 0; c7_i148 < 92; c7_i148++) {
    c7_mystr[c7_i148] = c7_cv25[c7_i148];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i149 = 0; c7_i149 < 92; c7_i149++) {
    c7_arr[c7_i149] = c7_dv62[c7_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i150 = 0; c7_i150 < 256; c7_i150++) {
    c7_tt[c7_i150] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i151 = 0; c7_i151 < 92; c7_i151++) {
    c7_tt[c7_i151] = c7_arr[c7_i151];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i152 = 0; c7_i152 < 256; c7_i152++) {
    c7_myarr256[c7_i152] = c7_tt[c7_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_bb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[118];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[118];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i153;
  static char_T c7_cv26[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c7_i154;
  static real_T c7_dv63[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i155;
  int32_T c7_i156;
  int32_T c7_i157;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_lb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i153 = 0; c7_i153 < 118; c7_i153++) {
    c7_mystr[c7_i153] = c7_cv26[c7_i153];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i154 = 0; c7_i154 < 118; c7_i154++) {
    c7_arr[c7_i154] = c7_dv63[c7_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i155 = 0; c7_i155 < 256; c7_i155++) {
    c7_tt[c7_i155] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i156 = 0; c7_i156 < 118; c7_i156++) {
    c7_tt[c7_i156] = c7_arr[c7_i156];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i157 = 0; c7_i157 < 256; c7_i157++) {
    c7_myarr256[c7_i157] = c7_tt[c7_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_cb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[119];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[119];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i158;
  static char_T c7_cv27[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c7_i159;
  static real_T c7_dv64[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i160;
  int32_T c7_i161;
  int32_T c7_i162;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_mb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i158 = 0; c7_i158 < 119; c7_i158++) {
    c7_mystr[c7_i158] = c7_cv27[c7_i158];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i159 = 0; c7_i159 < 119; c7_i159++) {
    c7_arr[c7_i159] = c7_dv64[c7_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i160 = 0; c7_i160 < 256; c7_i160++) {
    c7_tt[c7_i160] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i161 = 0; c7_i161 < 119; c7_i161++) {
    c7_tt[c7_i161] = c7_arr[c7_i161];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i162 = 0; c7_i162 < 256; c7_i162++) {
    c7_myarr256[c7_i162] = c7_tt[c7_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_db_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[116];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[116];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i163;
  static char_T c7_cv28[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c7_i164;
  static real_T c7_dv65[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i165;
  int32_T c7_i166;
  int32_T c7_i167;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_nb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i163 = 0; c7_i163 < 116; c7_i163++) {
    c7_mystr[c7_i163] = c7_cv28[c7_i163];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i164 = 0; c7_i164 < 116; c7_i164++) {
    c7_arr[c7_i164] = c7_dv65[c7_i164];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i165 = 0; c7_i165 < 256; c7_i165++) {
    c7_tt[c7_i165] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i166 = 0; c7_i166 < 116; c7_i166++) {
    c7_tt[c7_i166] = c7_arr[c7_i166];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i167 = 0; c7_i167 < 256; c7_i167++) {
    c7_myarr256[c7_i167] = c7_tt[c7_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_eb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[118];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[118];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i168;
  static char_T c7_cv29[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c7_i169;
  static real_T c7_dv66[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i170;
  int32_T c7_i171;
  int32_T c7_i172;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ob_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i168 = 0; c7_i168 < 118; c7_i168++) {
    c7_mystr[c7_i168] = c7_cv29[c7_i168];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i169 = 0; c7_i169 < 118; c7_i169++) {
    c7_arr[c7_i169] = c7_dv66[c7_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i170 = 0; c7_i170 < 256; c7_i170++) {
    c7_tt[c7_i170] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i171 = 0; c7_i171 < 118; c7_i171++) {
    c7_tt[c7_i171] = c7_arr[c7_i171];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i172 = 0; c7_i172 < 256; c7_i172++) {
    c7_myarr256[c7_i172] = c7_tt[c7_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_fb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[120];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[120];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i173;
  static char_T c7_cv30[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i174;
  static real_T c7_dv67[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i175;
  int32_T c7_i176;
  int32_T c7_i177;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_pb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_yb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_xb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i173 = 0; c7_i173 < 120; c7_i173++) {
    c7_mystr[c7_i173] = c7_cv30[c7_i173];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i174 = 0; c7_i174 < 120; c7_i174++) {
    c7_arr[c7_i174] = c7_dv67[c7_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i175 = 0; c7_i175 < 256; c7_i175++) {
    c7_tt[c7_i175] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i176 = 0; c7_i176 < 120; c7_i176++) {
    c7_tt[c7_i176] = c7_arr[c7_i176];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i177 = 0; c7_i177 < 256; c7_i177++) {
    c7_myarr256[c7_i177] = c7_tt[c7_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_gb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[121];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[121];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i178;
  static char_T c7_cv31[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i179;
  static real_T c7_dv68[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i180;
  int32_T c7_i181;
  int32_T c7_i182;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_qb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_bc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_ac_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i178 = 0; c7_i178 < 121; c7_i178++) {
    c7_mystr[c7_i178] = c7_cv31[c7_i178];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i179 = 0; c7_i179 < 121; c7_i179++) {
    c7_arr[c7_i179] = c7_dv68[c7_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i180 = 0; c7_i180 < 256; c7_i180++) {
    c7_tt[c7_i180] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i181 = 0; c7_i181 < 121; c7_i181++) {
    c7_tt[c7_i181] = c7_arr[c7_i181];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i182 = 0; c7_i182 < 256; c7_i182++) {
    c7_myarr256[c7_i182] = c7_tt[c7_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_hb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[122];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[122];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i183;
  static char_T c7_cv32[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i184;
  static real_T c7_dv69[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i185;
  int32_T c7_i186;
  int32_T c7_i187;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_rb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_dc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_cc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i183 = 0; c7_i183 < 122; c7_i183++) {
    c7_mystr[c7_i183] = c7_cv32[c7_i183];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i184 = 0; c7_i184 < 122; c7_i184++) {
    c7_arr[c7_i184] = c7_dv69[c7_i184];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i185 = 0; c7_i185 < 256; c7_i185++) {
    c7_tt[c7_i185] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i186 = 0; c7_i186 < 122; c7_i186++) {
    c7_tt[c7_i186] = c7_arr[c7_i186];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i187 = 0; c7_i187 < 256; c7_i187++) {
    c7_myarr256[c7_i187] = c7_tt[c7_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_ib_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[123];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[123];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i188;
  static char_T c7_cv33[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i189;
  static real_T c7_dv70[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i190;
  int32_T c7_i191;
  int32_T c7_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_sb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_fc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_ec_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i188 = 0; c7_i188 < 123; c7_i188++) {
    c7_mystr[c7_i188] = c7_cv33[c7_i188];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i189 = 0; c7_i189 < 123; c7_i189++) {
    c7_arr[c7_i189] = c7_dv70[c7_i189];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i190 = 0; c7_i190 < 256; c7_i190++) {
    c7_tt[c7_i190] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i191 = 0; c7_i191 < 123; c7_i191++) {
    c7_tt[c7_i191] = c7_arr[c7_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i192 = 0; c7_i192 < 256; c7_i192++) {
    c7_myarr256[c7_i192] = c7_tt[c7_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_jb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[133];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[133];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i193;
  static char_T c7_cv34[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c7_i194;
  static real_T c7_dv71[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i195;
  int32_T c7_i196;
  int32_T c7_i197;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_tb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_hc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_gc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i193 = 0; c7_i193 < 133; c7_i193++) {
    c7_mystr[c7_i193] = c7_cv34[c7_i193];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i194 = 0; c7_i194 < 133; c7_i194++) {
    c7_arr[c7_i194] = c7_dv71[c7_i194];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i195 = 0; c7_i195 < 256; c7_i195++) {
    c7_tt[c7_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i196 = 0; c7_i196 < 133; c7_i196++) {
    c7_tt[c7_i196] = c7_arr[c7_i196];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i197 = 0; c7_i197 < 256; c7_i197++) {
    c7_myarr256[c7_i197] = c7_tt[c7_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_kb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[137];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[137];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i198;
  static char_T c7_cv35[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i199;
  static real_T c7_dv72[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i200;
  int32_T c7_i201;
  int32_T c7_i202;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ub_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_jc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_ic_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i198 = 0; c7_i198 < 137; c7_i198++) {
    c7_mystr[c7_i198] = c7_cv35[c7_i198];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i199 = 0; c7_i199 < 137; c7_i199++) {
    c7_arr[c7_i199] = c7_dv72[c7_i199];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i200 = 0; c7_i200 < 256; c7_i200++) {
    c7_tt[c7_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i201 = 0; c7_i201 < 137; c7_i201++) {
    c7_tt[c7_i201] = c7_arr[c7_i201];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i202 = 0; c7_i202 < 256; c7_i202++) {
    c7_myarr256[c7_i202] = c7_tt[c7_i202];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_lb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[138];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[138];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i203;
  static char_T c7_cv36[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i204;
  static real_T c7_dv73[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i205;
  int32_T c7_i206;
  int32_T c7_i207;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_vb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_lc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_kc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i203 = 0; c7_i203 < 138; c7_i203++) {
    c7_mystr[c7_i203] = c7_cv36[c7_i203];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i204 = 0; c7_i204 < 138; c7_i204++) {
    c7_arr[c7_i204] = c7_dv73[c7_i204];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i205 = 0; c7_i205 < 256; c7_i205++) {
    c7_tt[c7_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i206 = 0; c7_i206 < 138; c7_i206++) {
    c7_tt[c7_i206] = c7_arr[c7_i206];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i207 = 0; c7_i207 < 256; c7_i207++) {
    c7_myarr256[c7_i207] = c7_tt[c7_i207];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_mb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[136];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[136];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i208;
  static char_T c7_cv37[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i209;
  static real_T c7_dv74[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i210;
  int32_T c7_i211;
  int32_T c7_i212;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_wb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_nc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_mc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i208 = 0; c7_i208 < 136; c7_i208++) {
    c7_mystr[c7_i208] = c7_cv37[c7_i208];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i209 = 0; c7_i209 < 136; c7_i209++) {
    c7_arr[c7_i209] = c7_dv74[c7_i209];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i210 = 0; c7_i210 < 256; c7_i210++) {
    c7_tt[c7_i210] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i211 = 0; c7_i211 < 136; c7_i211++) {
    c7_tt[c7_i211] = c7_arr[c7_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i212 = 0; c7_i212 < 256; c7_i212++) {
    c7_myarr256[c7_i212] = c7_tt[c7_i212];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_nb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[135];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[135];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i213;
  static char_T c7_cv38[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i214;
  static real_T c7_dv75[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i215;
  int32_T c7_i216;
  int32_T c7_i217;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_xb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_pc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_oc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i213 = 0; c7_i213 < 135; c7_i213++) {
    c7_mystr[c7_i213] = c7_cv38[c7_i213];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i214 = 0; c7_i214 < 135; c7_i214++) {
    c7_arr[c7_i214] = c7_dv75[c7_i214];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i215 = 0; c7_i215 < 256; c7_i215++) {
    c7_tt[c7_i215] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i216 = 0; c7_i216 < 135; c7_i216++) {
    c7_tt[c7_i216] = c7_arr[c7_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i217 = 0; c7_i217 < 256; c7_i217++) {
    c7_myarr256[c7_i217] = c7_tt[c7_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_ob_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[131];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[131];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i218;
  static char_T c7_cv39[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '1',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c7_i219;
  static real_T c7_dv76[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i220;
  int32_T c7_i221;
  int32_T c7_i222;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_yb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_rc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_qc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i218 = 0; c7_i218 < 131; c7_i218++) {
    c7_mystr[c7_i218] = c7_cv39[c7_i218];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i219 = 0; c7_i219 < 131; c7_i219++) {
    c7_arr[c7_i219] = c7_dv76[c7_i219];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i220 = 0; c7_i220 < 256; c7_i220++) {
    c7_tt[c7_i220] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i221 = 0; c7_i221 < 131; c7_i221++) {
    c7_tt[c7_i221] = c7_arr[c7_i221];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i222 = 0; c7_i222 < 256; c7_i222++) {
    c7_myarr256[c7_i222] = c7_tt[c7_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_pb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[134];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[134];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i223;
  static char_T c7_cv40[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c7_i224;
  static real_T c7_dv77[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i225;
  int32_T c7_i226;
  int32_T c7_i227;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ac_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_tc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_sc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i223 = 0; c7_i223 < 134; c7_i223++) {
    c7_mystr[c7_i223] = c7_cv40[c7_i223];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i224 = 0; c7_i224 < 134; c7_i224++) {
    c7_arr[c7_i224] = c7_dv77[c7_i224];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i225 = 0; c7_i225 < 256; c7_i225++) {
    c7_tt[c7_i225] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i226 = 0; c7_i226 < 134; c7_i226++) {
    c7_tt[c7_i226] = c7_arr[c7_i226];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i227 = 0; c7_i227 < 256; c7_i227++) {
    c7_myarr256[c7_i227] = c7_tt[c7_i227];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_qb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[133];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[133];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i228;
  static char_T c7_cv41[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c7_i229;
  static real_T c7_dv78[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i230;
  int32_T c7_i231;
  int32_T c7_i232;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_bc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_hc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_gc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i228 = 0; c7_i228 < 133; c7_i228++) {
    c7_mystr[c7_i228] = c7_cv41[c7_i228];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i229 = 0; c7_i229 < 133; c7_i229++) {
    c7_arr[c7_i229] = c7_dv78[c7_i229];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i230 = 0; c7_i230 < 256; c7_i230++) {
    c7_tt[c7_i230] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i231 = 0; c7_i231 < 133; c7_i231++) {
    c7_tt[c7_i231] = c7_arr[c7_i231];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i232 = 0; c7_i232 < 256; c7_i232++) {
    c7_myarr256[c7_i232] = c7_tt[c7_i232];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_rb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[142];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[142];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i233;
  static char_T c7_cv42[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i234;
  static real_T c7_dv79[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i235;
  int32_T c7_i236;
  int32_T c7_i237;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_cc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_vc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_uc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i233 = 0; c7_i233 < 142; c7_i233++) {
    c7_mystr[c7_i233] = c7_cv42[c7_i233];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i234 = 0; c7_i234 < 142; c7_i234++) {
    c7_arr[c7_i234] = c7_dv79[c7_i234];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i235 = 0; c7_i235 < 256; c7_i235++) {
    c7_tt[c7_i235] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i236 = 0; c7_i236 < 142; c7_i236++) {
    c7_tt[c7_i236] = c7_arr[c7_i236];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i237 = 0; c7_i237 < 256; c7_i237++) {
    c7_myarr256[c7_i237] = c7_tt[c7_i237];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_sb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[225];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[225];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i238;
  static char_T c7_cv43[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c7_i239;
  static real_T c7_dv80[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i240;
  int32_T c7_i241;
  int32_T c7_i242;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_dc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i238 = 0; c7_i238 < 225; c7_i238++) {
    c7_mystr[c7_i238] = c7_cv43[c7_i238];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i239 = 0; c7_i239 < 225; c7_i239++) {
    c7_arr[c7_i239] = c7_dv80[c7_i239];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i240 = 0; c7_i240 < 256; c7_i240++) {
    c7_tt[c7_i240] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i241 = 0; c7_i241 < 225; c7_i241++) {
    c7_tt[c7_i241] = c7_arr[c7_i241];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i242 = 0; c7_i242 < 256; c7_i242++) {
    c7_myarr256[c7_i242] = c7_tt[c7_i242];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_tb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[109];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[109];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i243;
  static char_T c7_cv44[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't',
    'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i244;
  static real_T c7_dv81[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i245;
  int32_T c7_i246;
  int32_T c7_i247;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_fc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_xc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_wc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i243 = 0; c7_i243 < 109; c7_i243++) {
    c7_mystr[c7_i243] = c7_cv44[c7_i243];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i244 = 0; c7_i244 < 109; c7_i244++) {
    c7_arr[c7_i244] = c7_dv81[c7_i244];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i245 = 0; c7_i245 < 256; c7_i245++) {
    c7_tt[c7_i245] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i246 = 0; c7_i246 < 109; c7_i246++) {
    c7_tt[c7_i246] = c7_arr[c7_i246];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i247 = 0; c7_i247 < 256; c7_i247++) {
    c7_myarr256[c7_i247] = c7_tt[c7_i247];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_ub_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[105];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[105];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i248;
  static char_T c7_cv45[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l',
    'e', '0', '3', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    'e', 'n', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i249;
  static real_T c7_dv82[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c7_i250;
  int32_T c7_i251;
  int32_T c7_i252;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_gc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ad_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_yc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i248 = 0; c7_i248 < 105; c7_i248++) {
    c7_mystr[c7_i248] = c7_cv45[c7_i248];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i249 = 0; c7_i249 < 105; c7_i249++) {
    c7_arr[c7_i249] = c7_dv82[c7_i249];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i250 = 0; c7_i250 < 256; c7_i250++) {
    c7_tt[c7_i250] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i251 = 0; c7_i251 < 105; c7_i251++) {
    c7_tt[c7_i251] = c7_arr[c7_i251];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i252 = 0; c7_i252 < 256; c7_i252++) {
    c7_myarr256[c7_i252] = c7_tt[c7_i252];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_vb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[110];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[110];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i253;
  static char_T c7_cv46[110] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h',
    't', 'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't',
    '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i254;
  static real_T c7_dv83[110] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i255;
  int32_T c7_i256;
  int32_T c7_i257;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_hc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_cd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_bd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i253 = 0; c7_i253 < 110; c7_i253++) {
    c7_mystr[c7_i253] = c7_cv46[c7_i253];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i254 = 0; c7_i254 < 110; c7_i254++) {
    c7_arr[c7_i254] = c7_dv83[c7_i254];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 110.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i255 = 0; c7_i255 < 256; c7_i255++) {
    c7_tt[c7_i255] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i256 = 0; c7_i256 < 110; c7_i256++) {
    c7_tt[c7_i256] = c7_arr[c7_i256];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i257 = 0; c7_i257 < 256; c7_i257++) {
    c7_myarr256[c7_i257] = c7_tt[c7_i257];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_wb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[111];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[111];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i258;
  static char_T c7_cv47[111] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i259;
  static real_T c7_dv84[111] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i260;
  int32_T c7_i261;
  int32_T c7_i262;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_ic_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_ed_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_dd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i258 = 0; c7_i258 < 111; c7_i258++) {
    c7_mystr[c7_i258] = c7_cv47[c7_i258];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i259 = 0; c7_i259 < 111; c7_i259++) {
    c7_arr[c7_i259] = c7_dv84[c7_i259];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i260 = 0; c7_i260 < 256; c7_i260++) {
    c7_tt[c7_i260] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i261 = 0; c7_i261 < 111; c7_i261++) {
    c7_tt[c7_i261] = c7_arr[c7_i261];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i262 = 0; c7_i262 < 256; c7_i262++) {
    c7_myarr256[c7_i262] = c7_tt[c7_i262];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_xb_encStr2Arr(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_myarr256[256])
{
  uint32_T c7_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[112];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[112];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  int32_T c7_i263;
  static char_T c7_cv48[112] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 't', 'a',
    'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i264;
  static real_T c7_dv85[112] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i265;
  int32_T c7_i266;
  int32_T c7_i267;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_jc_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_gd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_fd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
    c7_d_sf_marshallIn);
  for (c7_i263 = 0; c7_i263 < 112; c7_i263++) {
    c7_mystr[c7_i263] = c7_cv48[c7_i263];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
  for (c7_i264 = 0; c7_i264 < 112; c7_i264++) {
    c7_arr[c7_i264] = c7_dv85[c7_i264];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_ss = 112.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_padsize = c7_maxarrsize - c7_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
  for (c7_i265 = 0; c7_i265 < 256; c7_i265++) {
    c7_tt[c7_i265] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
  for (c7_i266 = 0; c7_i266 < 112; c7_i266++) {
    c7_tt[c7_i266] = c7_arr[c7_i266];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
  for (c7_i267 = 0; c7_i267 < 256; c7_i267++) {
    c7_myarr256[c7_i267] = c7_tt[c7_i267];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c7_rand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                      *chartInstance)
{
  return c7_eml_rand(chartInstance);
}

static real_T c7_eml_rand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  real_T c7_r;
  uint32_T c7_hoistedGlobal;
  uint32_T c7_d_state;
  uint32_T c7_e_state;
  uint32_T c7_s;
  uint32_T c7_u0;
  uint32_T c7_hi;
  uint32_T c7_lo;
  uint32_T c7_test1;
  uint32_T c7_test2;
  uint32_T c7_f_state;
  real_T c7_b_r;
  real_T c7_d0;
  int32_T c7_i268;
  uint32_T c7_icng;
  uint32_T c7_jsr;
  uint32_T c7_u1;
  uint32_T c7_u2;
  uint32_T c7_ui;
  uint32_T c7_b_ui;
  real_T c7_c_r;
  real_T c7_d1;
  uint32_T c7_uv2[625];
  int32_T c7_i269;
  real_T c7_d2;
  if (!chartInstance->c7_method_not_empty) {
    chartInstance->c7_method = 7U;
    chartInstance->c7_method_not_empty = true;
  }

  if (chartInstance->c7_method == 4U) {
    if (!chartInstance->c7_state_not_empty) {
      chartInstance->c7_state = 1144108930U;
      chartInstance->c7_state_not_empty = true;
    }

    c7_hoistedGlobal = chartInstance->c7_state;
    c7_d_state = c7_hoistedGlobal;
    c7_e_state = c7_d_state;
    c7_s = c7_e_state;
    c7_u0 = 127773U;
    if (c7_u0 == 0U) {
      c7_hi = MAX_uint32_T;
    } else {
      c7_hi = c7_s / c7_u0;
    }

    c7_lo = c7_s - c7_hi * 127773U;
    c7_test1 = 16807U * c7_lo;
    c7_test2 = 2836U * c7_hi;
    if (c7_test1 < c7_test2) {
      c7_f_state = (c7_test1 - c7_test2) + 2147483647U;
    } else {
      c7_f_state = c7_test1 - c7_test2;
    }

    c7_b_r = (real_T)c7_f_state * 4.6566128752457969E-10;
    c7_e_state = c7_f_state;
    c7_d0 = c7_b_r;
    chartInstance->c7_state = c7_e_state;
    c7_r = c7_d0;
  } else if (chartInstance->c7_method == 5U) {
    if (!chartInstance->c7_b_state_not_empty) {
      for (c7_i268 = 0; c7_i268 < 2; c7_i268++) {
        chartInstance->c7_b_state[c7_i268] = 362436069U + 158852560U * (uint32_T)
          c7_i268;
      }

      chartInstance->c7_b_state_not_empty = true;
    }

    c7_icng = chartInstance->c7_b_state[0];
    c7_jsr = chartInstance->c7_b_state[1];
    c7_u1 = c7_jsr;
    c7_u2 = c7_icng;
    c7_u2 = 69069U * c7_u2 + 1234567U;
    c7_u1 ^= c7_u1 << 13;
    c7_u1 ^= c7_u1 >> 17;
    c7_u1 ^= c7_u1 << 5;
    c7_ui = c7_u2 + c7_u1;
    chartInstance->c7_b_state[0] = c7_u2;
    chartInstance->c7_b_state[1] = c7_u1;
    c7_b_ui = c7_ui;
    c7_c_r = (real_T)c7_b_ui * 2.328306436538696E-10;
    c7_d1 = c7_c_r;
    c7_r = c7_d1;
  } else {
    if (!chartInstance->c7_c_state_not_empty) {
      c7_eml_rand_mt19937ar(chartInstance, c7_uv2);
      for (c7_i269 = 0; c7_i269 < 625; c7_i269++) {
        chartInstance->c7_c_state[c7_i269] = c7_uv2[c7_i269];
      }

      chartInstance->c7_c_state_not_empty = true;
    }

    c7_d2 = c7_c_eml_rand_mt19937ar(chartInstance, chartInstance->c7_c_state);
    c7_r = c7_d2;
  }

  return c7_r;
}

static void c7_eml_rand_mt19937ar(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_d_state[625])
{
  real_T c7_d3;
  int32_T c7_i270;
  c7_d3 = 5489.0;
  for (c7_i270 = 0; c7_i270 < 625; c7_i270++) {
    c7_d_state[c7_i270] = 0U;
  }

  c7_b_twister_state_vector(chartInstance, c7_d_state, c7_d3);
}

static void c7_twister_state_vector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_mt[625], real_T c7_seed, uint32_T c7_b_mt[625])
{
  int32_T c7_i271;
  for (c7_i271 = 0; c7_i271 < 625; c7_i271++) {
    c7_b_mt[c7_i271] = c7_mt[c7_i271];
  }

  c7_b_twister_state_vector(chartInstance, c7_b_mt, c7_seed);
}

static void c7_b_eml_rand_mt19937ar
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_d_state[625], uint32_T c7_e_state[625], real_T *c7_r)
{
  int32_T c7_i272;
  for (c7_i272 = 0; c7_i272 < 625; c7_i272++) {
    c7_e_state[c7_i272] = c7_d_state[c7_i272];
  }

  *c7_r = c7_c_eml_rand_mt19937ar(chartInstance, c7_e_state);
}

static void c7_eml_error(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  int32_T c7_i273;
  static char_T c7_cv49[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c7_u[37];
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  for (c7_i273 = 0; c7_i273 < 37; c7_i273++) {
    c7_u[c7_i273] = c7_cv49[c7_i273];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c7_y));
}

static real_T c7_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, real_T c7_lowhigh[2])
{
  real_T c7_r;
  real_T c7_low;
  real_T c7_high;
  int32_T c7_i274;
  static char_T c7_cv50[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c7_u[26];
  const mxArray *c7_y = NULL;
  real_T c7_s;
  real_T c7_x;
  real_T c7_b_x;
  c7_low = c7_lowhigh[0];
  c7_high = c7_lowhigh[1];
  if (c7_low <= c7_high) {
  } else {
    for (c7_i274 = 0; c7_i274 < 26; c7_i274++) {
      c7_u[c7_i274] = c7_cv50[c7_i274];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c7_y));
  }

  c7_s = (c7_high - c7_low) + 1.0;
  c7_r = c7_rand(chartInstance);
  c7_x = c7_r * c7_s;
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarFloor(c7_b_x);
  return c7_low + c7_b_x;
}

static real_T c7_b_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  real_T c7_r;
  real_T c7_x;
  real_T c7_b_x;
  c7_r = c7_rand(chartInstance);
  c7_x = c7_r * 4.0;
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarFloor(c7_b_x);
  return 4.0 + c7_b_x;
}

static real_T c7_c_randi(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  real_T c7_r;
  real_T c7_x;
  real_T c7_b_x;
  c7_r = c7_rand(chartInstance);
  c7_x = c7_r * 2.0;
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarFloor(c7_b_x);
  return 1.0 + c7_b_x;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c7_chartNumber, c7_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i275;
  real_T c7_b_inData[256];
  int32_T c7_i276;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i275 = 0; c7_i275 < 256; c7_i275++) {
    c7_b_inData[c7_i275] = (*(real_T (*)[256])c7_inData)[c7_i275];
  }

  for (c7_i276 = 0; c7_i276 < 256; c7_i276++) {
    c7_u[c7_i276] = c7_b_inData[c7_i276];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[256])
{
  real_T c7_dv86[256];
  int32_T c7_i277;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv86, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c7_i277 = 0; c7_i277 < 256; c7_i277++) {
    c7_y[c7_i277] = c7_dv86[c7_i277];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_poseBML;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[256];
  int32_T c7_i278;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_poseBML = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_poseBML), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_poseBML);
  for (c7_i278 = 0; c7_i278 < 256; c7_i278++) {
    (*(real_T (*)[256])c7_outData)[c7_i278] = c7_y[c7_i278];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_b_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_bmlID, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_bmlID), &c7_thisId);
  sf_mex_destroy(&c7_bmlID);
  return c7_y;
}

static real_T c7_c_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d4;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d4, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d4;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_bmlID;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_bmlID = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_bmlID), &c7_thisId);
  sf_mex_destroy(&c7_bmlID);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  boolean_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(boolean_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static boolean_T c7_d_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  boolean_T c7_y;
  boolean_T c7_b0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_b0, 1, 11, 0U, 0, 0U, 0);
  c7_y = c7_b0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_aVarTruthTableCondition_2;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  boolean_T c7_y;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_aVarTruthTableCondition_2 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_aVarTruthTableCondition_2), &c7_thisId);
  sf_mex_destroy(&c7_aVarTruthTableCondition_2);
  *(boolean_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i279;
  real_T c7_b_inData[256];
  int32_T c7_i280;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i279 = 0; c7_i279 < 256; c7_i279++) {
    c7_b_inData[c7_i279] = (*(real_T (*)[256])c7_inData)[c7_i279];
  }

  for (c7_i280 = 0; c7_i280 < 256; c7_i280++) {
    c7_u[c7_i280] = c7_b_inData[c7_i280];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_e_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[256])
{
  real_T c7_dv87[256];
  int32_T c7_i281;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv87, 1, 0, 0U, 1, 0U, 1, 256);
  for (c7_i281 = 0; c7_i281 < 256; c7_i281++) {
    c7_y[c7_i281] = c7_dv87[c7_i281];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_myarr256;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[256];
  int32_T c7_i282;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_myarr256 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_myarr256), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_myarr256);
  for (c7_i282 = 0; c7_i282 < 256; c7_i282++) {
    (*(real_T (*)[256])c7_outData)[c7_i282] = c7_y[c7_i282];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i283;
  char_T c7_b_inData[94];
  int32_T c7_i284;
  char_T c7_u[94];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i283 = 0; c7_i283 < 94; c7_i283++) {
    c7_b_inData[c7_i283] = (*(char_T (*)[94])c7_inData)[c7_i283];
  }

  for (c7_i284 = 0; c7_i284 < 94; c7_i284++) {
    c7_u[c7_i284] = c7_b_inData[c7_i284];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i285;
  real_T c7_b_inData[94];
  int32_T c7_i286;
  real_T c7_u[94];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i285 = 0; c7_i285 < 94; c7_i285++) {
    c7_b_inData[c7_i285] = (*(real_T (*)[94])c7_inData)[c7_i285];
  }

  for (c7_i286 = 0; c7_i286 < 94; c7_i286++) {
    c7_u[c7_i286] = c7_b_inData[c7_i286];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i287;
  char_T c7_b_inData[88];
  int32_T c7_i288;
  char_T c7_u[88];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i287 = 0; c7_i287 < 88; c7_i287++) {
    c7_b_inData[c7_i287] = (*(char_T (*)[88])c7_inData)[c7_i287];
  }

  for (c7_i288 = 0; c7_i288 < 88; c7_i288++) {
    c7_u[c7_i288] = c7_b_inData[c7_i288];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i289;
  real_T c7_b_inData[88];
  int32_T c7_i290;
  real_T c7_u[88];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i289 = 0; c7_i289 < 88; c7_i289++) {
    c7_b_inData[c7_i289] = (*(real_T (*)[88])c7_inData)[c7_i289];
  }

  for (c7_i290 = 0; c7_i290 < 88; c7_i290++) {
    c7_u[c7_i290] = c7_b_inData[c7_i290];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_i_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i291;
  char_T c7_b_inData[86];
  int32_T c7_i292;
  char_T c7_u[86];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i291 = 0; c7_i291 < 86; c7_i291++) {
    c7_b_inData[c7_i291] = (*(char_T (*)[86])c7_inData)[c7_i291];
  }

  for (c7_i292 = 0; c7_i292 < 86; c7_i292++) {
    c7_u[c7_i292] = c7_b_inData[c7_i292];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_j_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i293;
  real_T c7_b_inData[86];
  int32_T c7_i294;
  real_T c7_u[86];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i293 = 0; c7_i293 < 86; c7_i293++) {
    c7_b_inData[c7_i293] = (*(real_T (*)[86])c7_inData)[c7_i293];
  }

  for (c7_i294 = 0; c7_i294 < 86; c7_i294++) {
    c7_u[c7_i294] = c7_b_inData[c7_i294];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_k_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i295;
  char_T c7_b_inData[161];
  int32_T c7_i296;
  char_T c7_u[161];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i295 = 0; c7_i295 < 161; c7_i295++) {
    c7_b_inData[c7_i295] = (*(char_T (*)[161])c7_inData)[c7_i295];
  }

  for (c7_i296 = 0; c7_i296 < 161; c7_i296++) {
    c7_u[c7_i296] = c7_b_inData[c7_i296];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_l_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i297;
  real_T c7_b_inData[161];
  int32_T c7_i298;
  real_T c7_u[161];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i297 = 0; c7_i297 < 161; c7_i297++) {
    c7_b_inData[c7_i297] = (*(real_T (*)[161])c7_inData)[c7_i297];
  }

  for (c7_i298 = 0; c7_i298 < 161; c7_i298++) {
    c7_u[c7_i298] = c7_b_inData[c7_i298];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_m_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i299;
  char_T c7_b_inData[157];
  int32_T c7_i300;
  char_T c7_u[157];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i299 = 0; c7_i299 < 157; c7_i299++) {
    c7_b_inData[c7_i299] = (*(char_T (*)[157])c7_inData)[c7_i299];
  }

  for (c7_i300 = 0; c7_i300 < 157; c7_i300++) {
    c7_u[c7_i300] = c7_b_inData[c7_i300];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_n_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i301;
  real_T c7_b_inData[157];
  int32_T c7_i302;
  real_T c7_u[157];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i301 = 0; c7_i301 < 157; c7_i301++) {
    c7_b_inData[c7_i301] = (*(real_T (*)[157])c7_inData)[c7_i301];
  }

  for (c7_i302 = 0; c7_i302 < 157; c7_i302++) {
    c7_u[c7_i302] = c7_b_inData[c7_i302];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_o_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i303;
  char_T c7_b_inData[92];
  int32_T c7_i304;
  char_T c7_u[92];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i303 = 0; c7_i303 < 92; c7_i303++) {
    c7_b_inData[c7_i303] = (*(char_T (*)[92])c7_inData)[c7_i303];
  }

  for (c7_i304 = 0; c7_i304 < 92; c7_i304++) {
    c7_u[c7_i304] = c7_b_inData[c7_i304];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_p_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i305;
  real_T c7_b_inData[92];
  int32_T c7_i306;
  real_T c7_u[92];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i305 = 0; c7_i305 < 92; c7_i305++) {
    c7_b_inData[c7_i305] = (*(real_T (*)[92])c7_inData)[c7_i305];
  }

  for (c7_i306 = 0; c7_i306 < 92; c7_i306++) {
    c7_u[c7_i306] = c7_b_inData[c7_i306];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_q_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i307;
  char_T c7_b_inData[89];
  int32_T c7_i308;
  char_T c7_u[89];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i307 = 0; c7_i307 < 89; c7_i307++) {
    c7_b_inData[c7_i307] = (*(char_T (*)[89])c7_inData)[c7_i307];
  }

  for (c7_i308 = 0; c7_i308 < 89; c7_i308++) {
    c7_u[c7_i308] = c7_b_inData[c7_i308];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 89), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_r_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i309;
  real_T c7_b_inData[89];
  int32_T c7_i310;
  real_T c7_u[89];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i309 = 0; c7_i309 < 89; c7_i309++) {
    c7_b_inData[c7_i309] = (*(real_T (*)[89])c7_inData)[c7_i309];
  }

  for (c7_i310 = 0; c7_i310 < 89; c7_i310++) {
    c7_u[c7_i310] = c7_b_inData[c7_i310];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 89), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_s_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i311;
  char_T c7_b_inData[81];
  int32_T c7_i312;
  char_T c7_u[81];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i311 = 0; c7_i311 < 81; c7_i311++) {
    c7_b_inData[c7_i311] = (*(char_T (*)[81])c7_inData)[c7_i311];
  }

  for (c7_i312 = 0; c7_i312 < 81; c7_i312++) {
    c7_u[c7_i312] = c7_b_inData[c7_i312];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 81), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_t_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i313;
  real_T c7_b_inData[81];
  int32_T c7_i314;
  real_T c7_u[81];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i313 = 0; c7_i313 < 81; c7_i313++) {
    c7_b_inData[c7_i313] = (*(real_T (*)[81])c7_inData)[c7_i313];
  }

  for (c7_i314 = 0; c7_i314 < 81; c7_i314++) {
    c7_u[c7_i314] = c7_b_inData[c7_i314];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 81), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_u_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i315;
  char_T c7_b_inData[78];
  int32_T c7_i316;
  char_T c7_u[78];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i315 = 0; c7_i315 < 78; c7_i315++) {
    c7_b_inData[c7_i315] = (*(char_T (*)[78])c7_inData)[c7_i315];
  }

  for (c7_i316 = 0; c7_i316 < 78; c7_i316++) {
    c7_u[c7_i316] = c7_b_inData[c7_i316];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 78), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_v_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i317;
  real_T c7_b_inData[78];
  int32_T c7_i318;
  real_T c7_u[78];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i317 = 0; c7_i317 < 78; c7_i317++) {
    c7_b_inData[c7_i317] = (*(real_T (*)[78])c7_inData)[c7_i317];
  }

  for (c7_i318 = 0; c7_i318 < 78; c7_i318++) {
    c7_u[c7_i318] = c7_b_inData[c7_i318];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 78), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_w_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i319;
  char_T c7_b_inData[147];
  int32_T c7_i320;
  char_T c7_u[147];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i319 = 0; c7_i319 < 147; c7_i319++) {
    c7_b_inData[c7_i319] = (*(char_T (*)[147])c7_inData)[c7_i319];
  }

  for (c7_i320 = 0; c7_i320 < 147; c7_i320++) {
    c7_u[c7_i320] = c7_b_inData[c7_i320];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_x_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i321;
  real_T c7_b_inData[147];
  int32_T c7_i322;
  real_T c7_u[147];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i321 = 0; c7_i321 < 147; c7_i321++) {
    c7_b_inData[c7_i321] = (*(real_T (*)[147])c7_inData)[c7_i321];
  }

  for (c7_i322 = 0; c7_i322 < 147; c7_i322++) {
    c7_u[c7_i322] = c7_b_inData[c7_i322];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_y_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i323;
  char_T c7_b_inData[164];
  int32_T c7_i324;
  char_T c7_u[164];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i323 = 0; c7_i323 < 164; c7_i323++) {
    c7_b_inData[c7_i323] = (*(char_T (*)[164])c7_inData)[c7_i323];
  }

  for (c7_i324 = 0; c7_i324 < 164; c7_i324++) {
    c7_u[c7_i324] = c7_b_inData[c7_i324];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i325;
  real_T c7_b_inData[164];
  int32_T c7_i326;
  real_T c7_u[164];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i325 = 0; c7_i325 < 164; c7_i325++) {
    c7_b_inData[c7_i325] = (*(real_T (*)[164])c7_inData)[c7_i325];
  }

  for (c7_i326 = 0; c7_i326 < 164; c7_i326++) {
    c7_u[c7_i326] = c7_b_inData[c7_i326];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i327;
  char_T c7_b_inData[68];
  int32_T c7_i328;
  char_T c7_u[68];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i327 = 0; c7_i327 < 68; c7_i327++) {
    c7_b_inData[c7_i327] = (*(char_T (*)[68])c7_inData)[c7_i327];
  }

  for (c7_i328 = 0; c7_i328 < 68; c7_i328++) {
    c7_u[c7_i328] = c7_b_inData[c7_i328];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i329;
  real_T c7_b_inData[68];
  int32_T c7_i330;
  real_T c7_u[68];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i329 = 0; c7_i329 < 68; c7_i329++) {
    c7_b_inData[c7_i329] = (*(real_T (*)[68])c7_inData)[c7_i329];
  }

  for (c7_i330 = 0; c7_i330 < 68; c7_i330++) {
    c7_u[c7_i330] = c7_b_inData[c7_i330];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_db_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i331;
  char_T c7_b_inData[223];
  int32_T c7_i332;
  char_T c7_u[223];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i331 = 0; c7_i331 < 223; c7_i331++) {
    c7_b_inData[c7_i331] = (*(char_T (*)[223])c7_inData)[c7_i331];
  }

  for (c7_i332 = 0; c7_i332 < 223; c7_i332++) {
    c7_u[c7_i332] = c7_b_inData[c7_i332];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i333;
  real_T c7_b_inData[223];
  int32_T c7_i334;
  real_T c7_u[223];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i333 = 0; c7_i333 < 223; c7_i333++) {
    c7_b_inData[c7_i333] = (*(real_T (*)[223])c7_inData)[c7_i333];
  }

  for (c7_i334 = 0; c7_i334 < 223; c7_i334++) {
    c7_u[c7_i334] = c7_b_inData[c7_i334];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i335;
  char_T c7_b_inData[225];
  int32_T c7_i336;
  char_T c7_u[225];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i335 = 0; c7_i335 < 225; c7_i335++) {
    c7_b_inData[c7_i335] = (*(char_T (*)[225])c7_inData)[c7_i335];
  }

  for (c7_i336 = 0; c7_i336 < 225; c7_i336++) {
    c7_u[c7_i336] = c7_b_inData[c7_i336];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i337;
  real_T c7_b_inData[225];
  int32_T c7_i338;
  real_T c7_u[225];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i337 = 0; c7_i337 < 225; c7_i337++) {
    c7_b_inData[c7_i337] = (*(real_T (*)[225])c7_inData)[c7_i337];
  }

  for (c7_i338 = 0; c7_i338 < 225; c7_i338++) {
    c7_u[c7_i338] = c7_b_inData[c7_i338];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i339;
  char_T c7_b_inData[87];
  int32_T c7_i340;
  char_T c7_u[87];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i339 = 0; c7_i339 < 87; c7_i339++) {
    c7_b_inData[c7_i339] = (*(char_T (*)[87])c7_inData)[c7_i339];
  }

  for (c7_i340 = 0; c7_i340 < 87; c7_i340++) {
    c7_u[c7_i340] = c7_b_inData[c7_i340];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i341;
  real_T c7_b_inData[87];
  int32_T c7_i342;
  real_T c7_u[87];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i341 = 0; c7_i341 < 87; c7_i341++) {
    c7_b_inData[c7_i341] = (*(real_T (*)[87])c7_inData)[c7_i341];
  }

  for (c7_i342 = 0; c7_i342 < 87; c7_i342++) {
    c7_u[c7_i342] = c7_b_inData[c7_i342];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i343;
  char_T c7_b_inData[91];
  int32_T c7_i344;
  char_T c7_u[91];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i343 = 0; c7_i343 < 91; c7_i343++) {
    c7_b_inData[c7_i343] = (*(char_T (*)[91])c7_inData)[c7_i343];
  }

  for (c7_i344 = 0; c7_i344 < 91; c7_i344++) {
    c7_u[c7_i344] = c7_b_inData[c7_i344];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i345;
  real_T c7_b_inData[91];
  int32_T c7_i346;
  real_T c7_u[91];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i345 = 0; c7_i345 < 91; c7_i345++) {
    c7_b_inData[c7_i345] = (*(real_T (*)[91])c7_inData)[c7_i345];
  }

  for (c7_i346 = 0; c7_i346 < 91; c7_i346++) {
    c7_u[c7_i346] = c7_b_inData[c7_i346];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i347;
  char_T c7_b_inData[93];
  int32_T c7_i348;
  char_T c7_u[93];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i347 = 0; c7_i347 < 93; c7_i347++) {
    c7_b_inData[c7_i347] = (*(char_T (*)[93])c7_inData)[c7_i347];
  }

  for (c7_i348 = 0; c7_i348 < 93; c7_i348++) {
    c7_u[c7_i348] = c7_b_inData[c7_i348];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i349;
  real_T c7_b_inData[93];
  int32_T c7_i350;
  real_T c7_u[93];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i349 = 0; c7_i349 < 93; c7_i349++) {
    c7_b_inData[c7_i349] = (*(real_T (*)[93])c7_inData)[c7_i349];
  }

  for (c7_i350 = 0; c7_i350 < 93; c7_i350++) {
    c7_u[c7_i350] = c7_b_inData[c7_i350];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i351;
  char_T c7_b_inData[95];
  int32_T c7_i352;
  char_T c7_u[95];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i351 = 0; c7_i351 < 95; c7_i351++) {
    c7_b_inData[c7_i351] = (*(char_T (*)[95])c7_inData)[c7_i351];
  }

  for (c7_i352 = 0; c7_i352 < 95; c7_i352++) {
    c7_u[c7_i352] = c7_b_inData[c7_i352];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i353;
  real_T c7_b_inData[95];
  int32_T c7_i354;
  real_T c7_u[95];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i353 = 0; c7_i353 < 95; c7_i353++) {
    c7_b_inData[c7_i353] = (*(real_T (*)[95])c7_inData)[c7_i353];
  }

  for (c7_i354 = 0; c7_i354 < 95; c7_i354++) {
    c7_u[c7_i354] = c7_b_inData[c7_i354];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i355;
  char_T c7_b_inData[97];
  int32_T c7_i356;
  char_T c7_u[97];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i355 = 0; c7_i355 < 97; c7_i355++) {
    c7_b_inData[c7_i355] = (*(char_T (*)[97])c7_inData)[c7_i355];
  }

  for (c7_i356 = 0; c7_i356 < 97; c7_i356++) {
    c7_u[c7_i356] = c7_b_inData[c7_i356];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i357;
  real_T c7_b_inData[97];
  int32_T c7_i358;
  real_T c7_u[97];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i357 = 0; c7_i357 < 97; c7_i357++) {
    c7_b_inData[c7_i357] = (*(real_T (*)[97])c7_inData)[c7_i357];
  }

  for (c7_i358 = 0; c7_i358 < 97; c7_i358++) {
    c7_u[c7_i358] = c7_b_inData[c7_i358];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i359;
  char_T c7_b_inData[118];
  int32_T c7_i360;
  char_T c7_u[118];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i359 = 0; c7_i359 < 118; c7_i359++) {
    c7_b_inData[c7_i359] = (*(char_T (*)[118])c7_inData)[c7_i359];
  }

  for (c7_i360 = 0; c7_i360 < 118; c7_i360++) {
    c7_u[c7_i360] = c7_b_inData[c7_i360];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i361;
  real_T c7_b_inData[118];
  int32_T c7_i362;
  real_T c7_u[118];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i361 = 0; c7_i361 < 118; c7_i361++) {
    c7_b_inData[c7_i361] = (*(real_T (*)[118])c7_inData)[c7_i361];
  }

  for (c7_i362 = 0; c7_i362 < 118; c7_i362++) {
    c7_u[c7_i362] = c7_b_inData[c7_i362];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i363;
  char_T c7_b_inData[119];
  int32_T c7_i364;
  char_T c7_u[119];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i363 = 0; c7_i363 < 119; c7_i363++) {
    c7_b_inData[c7_i363] = (*(char_T (*)[119])c7_inData)[c7_i363];
  }

  for (c7_i364 = 0; c7_i364 < 119; c7_i364++) {
    c7_u[c7_i364] = c7_b_inData[c7_i364];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i365;
  real_T c7_b_inData[119];
  int32_T c7_i366;
  real_T c7_u[119];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i365 = 0; c7_i365 < 119; c7_i365++) {
    c7_b_inData[c7_i365] = (*(real_T (*)[119])c7_inData)[c7_i365];
  }

  for (c7_i366 = 0; c7_i366 < 119; c7_i366++) {
    c7_u[c7_i366] = c7_b_inData[c7_i366];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i367;
  char_T c7_b_inData[116];
  int32_T c7_i368;
  char_T c7_u[116];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i367 = 0; c7_i367 < 116; c7_i367++) {
    c7_b_inData[c7_i367] = (*(char_T (*)[116])c7_inData)[c7_i367];
  }

  for (c7_i368 = 0; c7_i368 < 116; c7_i368++) {
    c7_u[c7_i368] = c7_b_inData[c7_i368];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i369;
  real_T c7_b_inData[116];
  int32_T c7_i370;
  real_T c7_u[116];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i369 = 0; c7_i369 < 116; c7_i369++) {
    c7_b_inData[c7_i369] = (*(real_T (*)[116])c7_inData)[c7_i369];
  }

  for (c7_i370 = 0; c7_i370 < 116; c7_i370++) {
    c7_u[c7_i370] = c7_b_inData[c7_i370];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i371;
  char_T c7_b_inData[120];
  int32_T c7_i372;
  char_T c7_u[120];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i371 = 0; c7_i371 < 120; c7_i371++) {
    c7_b_inData[c7_i371] = (*(char_T (*)[120])c7_inData)[c7_i371];
  }

  for (c7_i372 = 0; c7_i372 < 120; c7_i372++) {
    c7_u[c7_i372] = c7_b_inData[c7_i372];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i373;
  real_T c7_b_inData[120];
  int32_T c7_i374;
  real_T c7_u[120];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i373 = 0; c7_i373 < 120; c7_i373++) {
    c7_b_inData[c7_i373] = (*(real_T (*)[120])c7_inData)[c7_i373];
  }

  for (c7_i374 = 0; c7_i374 < 120; c7_i374++) {
    c7_u[c7_i374] = c7_b_inData[c7_i374];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i375;
  char_T c7_b_inData[121];
  int32_T c7_i376;
  char_T c7_u[121];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i375 = 0; c7_i375 < 121; c7_i375++) {
    c7_b_inData[c7_i375] = (*(char_T (*)[121])c7_inData)[c7_i375];
  }

  for (c7_i376 = 0; c7_i376 < 121; c7_i376++) {
    c7_u[c7_i376] = c7_b_inData[c7_i376];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i377;
  real_T c7_b_inData[121];
  int32_T c7_i378;
  real_T c7_u[121];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i377 = 0; c7_i377 < 121; c7_i377++) {
    c7_b_inData[c7_i377] = (*(real_T (*)[121])c7_inData)[c7_i377];
  }

  for (c7_i378 = 0; c7_i378 < 121; c7_i378++) {
    c7_u[c7_i378] = c7_b_inData[c7_i378];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i379;
  char_T c7_b_inData[122];
  int32_T c7_i380;
  char_T c7_u[122];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i379 = 0; c7_i379 < 122; c7_i379++) {
    c7_b_inData[c7_i379] = (*(char_T (*)[122])c7_inData)[c7_i379];
  }

  for (c7_i380 = 0; c7_i380 < 122; c7_i380++) {
    c7_u[c7_i380] = c7_b_inData[c7_i380];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i381;
  real_T c7_b_inData[122];
  int32_T c7_i382;
  real_T c7_u[122];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i381 = 0; c7_i381 < 122; c7_i381++) {
    c7_b_inData[c7_i381] = (*(real_T (*)[122])c7_inData)[c7_i381];
  }

  for (c7_i382 = 0; c7_i382 < 122; c7_i382++) {
    c7_u[c7_i382] = c7_b_inData[c7_i382];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i383;
  char_T c7_b_inData[123];
  int32_T c7_i384;
  char_T c7_u[123];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i383 = 0; c7_i383 < 123; c7_i383++) {
    c7_b_inData[c7_i383] = (*(char_T (*)[123])c7_inData)[c7_i383];
  }

  for (c7_i384 = 0; c7_i384 < 123; c7_i384++) {
    c7_u[c7_i384] = c7_b_inData[c7_i384];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i385;
  real_T c7_b_inData[123];
  int32_T c7_i386;
  real_T c7_u[123];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i385 = 0; c7_i385 < 123; c7_i385++) {
    c7_b_inData[c7_i385] = (*(real_T (*)[123])c7_inData)[c7_i385];
  }

  for (c7_i386 = 0; c7_i386 < 123; c7_i386++) {
    c7_u[c7_i386] = c7_b_inData[c7_i386];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i387;
  char_T c7_b_inData[133];
  int32_T c7_i388;
  char_T c7_u[133];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i387 = 0; c7_i387 < 133; c7_i387++) {
    c7_b_inData[c7_i387] = (*(char_T (*)[133])c7_inData)[c7_i387];
  }

  for (c7_i388 = 0; c7_i388 < 133; c7_i388++) {
    c7_u[c7_i388] = c7_b_inData[c7_i388];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i389;
  real_T c7_b_inData[133];
  int32_T c7_i390;
  real_T c7_u[133];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i389 = 0; c7_i389 < 133; c7_i389++) {
    c7_b_inData[c7_i389] = (*(real_T (*)[133])c7_inData)[c7_i389];
  }

  for (c7_i390 = 0; c7_i390 < 133; c7_i390++) {
    c7_u[c7_i390] = c7_b_inData[c7_i390];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i391;
  char_T c7_b_inData[137];
  int32_T c7_i392;
  char_T c7_u[137];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i391 = 0; c7_i391 < 137; c7_i391++) {
    c7_b_inData[c7_i391] = (*(char_T (*)[137])c7_inData)[c7_i391];
  }

  for (c7_i392 = 0; c7_i392 < 137; c7_i392++) {
    c7_u[c7_i392] = c7_b_inData[c7_i392];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i393;
  real_T c7_b_inData[137];
  int32_T c7_i394;
  real_T c7_u[137];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i393 = 0; c7_i393 < 137; c7_i393++) {
    c7_b_inData[c7_i393] = (*(real_T (*)[137])c7_inData)[c7_i393];
  }

  for (c7_i394 = 0; c7_i394 < 137; c7_i394++) {
    c7_u[c7_i394] = c7_b_inData[c7_i394];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i395;
  char_T c7_b_inData[138];
  int32_T c7_i396;
  char_T c7_u[138];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i395 = 0; c7_i395 < 138; c7_i395++) {
    c7_b_inData[c7_i395] = (*(char_T (*)[138])c7_inData)[c7_i395];
  }

  for (c7_i396 = 0; c7_i396 < 138; c7_i396++) {
    c7_u[c7_i396] = c7_b_inData[c7_i396];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i397;
  real_T c7_b_inData[138];
  int32_T c7_i398;
  real_T c7_u[138];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i397 = 0; c7_i397 < 138; c7_i397++) {
    c7_b_inData[c7_i397] = (*(real_T (*)[138])c7_inData)[c7_i397];
  }

  for (c7_i398 = 0; c7_i398 < 138; c7_i398++) {
    c7_u[c7_i398] = c7_b_inData[c7_i398];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i399;
  char_T c7_b_inData[136];
  int32_T c7_i400;
  char_T c7_u[136];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i399 = 0; c7_i399 < 136; c7_i399++) {
    c7_b_inData[c7_i399] = (*(char_T (*)[136])c7_inData)[c7_i399];
  }

  for (c7_i400 = 0; c7_i400 < 136; c7_i400++) {
    c7_u[c7_i400] = c7_b_inData[c7_i400];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i401;
  real_T c7_b_inData[136];
  int32_T c7_i402;
  real_T c7_u[136];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i401 = 0; c7_i401 < 136; c7_i401++) {
    c7_b_inData[c7_i401] = (*(real_T (*)[136])c7_inData)[c7_i401];
  }

  for (c7_i402 = 0; c7_i402 < 136; c7_i402++) {
    c7_u[c7_i402] = c7_b_inData[c7_i402];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i403;
  char_T c7_b_inData[135];
  int32_T c7_i404;
  char_T c7_u[135];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i403 = 0; c7_i403 < 135; c7_i403++) {
    c7_b_inData[c7_i403] = (*(char_T (*)[135])c7_inData)[c7_i403];
  }

  for (c7_i404 = 0; c7_i404 < 135; c7_i404++) {
    c7_u[c7_i404] = c7_b_inData[c7_i404];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i405;
  real_T c7_b_inData[135];
  int32_T c7_i406;
  real_T c7_u[135];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i405 = 0; c7_i405 < 135; c7_i405++) {
    c7_b_inData[c7_i405] = (*(real_T (*)[135])c7_inData)[c7_i405];
  }

  for (c7_i406 = 0; c7_i406 < 135; c7_i406++) {
    c7_u[c7_i406] = c7_b_inData[c7_i406];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i407;
  char_T c7_b_inData[131];
  int32_T c7_i408;
  char_T c7_u[131];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i407 = 0; c7_i407 < 131; c7_i407++) {
    c7_b_inData[c7_i407] = (*(char_T (*)[131])c7_inData)[c7_i407];
  }

  for (c7_i408 = 0; c7_i408 < 131; c7_i408++) {
    c7_u[c7_i408] = c7_b_inData[c7_i408];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i409;
  real_T c7_b_inData[131];
  int32_T c7_i410;
  real_T c7_u[131];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i409 = 0; c7_i409 < 131; c7_i409++) {
    c7_b_inData[c7_i409] = (*(real_T (*)[131])c7_inData)[c7_i409];
  }

  for (c7_i410 = 0; c7_i410 < 131; c7_i410++) {
    c7_u[c7_i410] = c7_b_inData[c7_i410];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i411;
  char_T c7_b_inData[134];
  int32_T c7_i412;
  char_T c7_u[134];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i411 = 0; c7_i411 < 134; c7_i411++) {
    c7_b_inData[c7_i411] = (*(char_T (*)[134])c7_inData)[c7_i411];
  }

  for (c7_i412 = 0; c7_i412 < 134; c7_i412++) {
    c7_u[c7_i412] = c7_b_inData[c7_i412];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i413;
  real_T c7_b_inData[134];
  int32_T c7_i414;
  real_T c7_u[134];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i413 = 0; c7_i413 < 134; c7_i413++) {
    c7_b_inData[c7_i413] = (*(real_T (*)[134])c7_inData)[c7_i413];
  }

  for (c7_i414 = 0; c7_i414 < 134; c7_i414++) {
    c7_u[c7_i414] = c7_b_inData[c7_i414];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i415;
  char_T c7_b_inData[142];
  int32_T c7_i416;
  char_T c7_u[142];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i415 = 0; c7_i415 < 142; c7_i415++) {
    c7_b_inData[c7_i415] = (*(char_T (*)[142])c7_inData)[c7_i415];
  }

  for (c7_i416 = 0; c7_i416 < 142; c7_i416++) {
    c7_u[c7_i416] = c7_b_inData[c7_i416];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i417;
  real_T c7_b_inData[142];
  int32_T c7_i418;
  real_T c7_u[142];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i417 = 0; c7_i417 < 142; c7_i417++) {
    c7_b_inData[c7_i417] = (*(real_T (*)[142])c7_inData)[c7_i417];
  }

  for (c7_i418 = 0; c7_i418 < 142; c7_i418++) {
    c7_u[c7_i418] = c7_b_inData[c7_i418];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i419;
  char_T c7_b_inData[109];
  int32_T c7_i420;
  char_T c7_u[109];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i419 = 0; c7_i419 < 109; c7_i419++) {
    c7_b_inData[c7_i419] = (*(char_T (*)[109])c7_inData)[c7_i419];
  }

  for (c7_i420 = 0; c7_i420 < 109; c7_i420++) {
    c7_u[c7_i420] = c7_b_inData[c7_i420];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i421;
  real_T c7_b_inData[109];
  int32_T c7_i422;
  real_T c7_u[109];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i421 = 0; c7_i421 < 109; c7_i421++) {
    c7_b_inData[c7_i421] = (*(real_T (*)[109])c7_inData)[c7_i421];
  }

  for (c7_i422 = 0; c7_i422 < 109; c7_i422++) {
    c7_u[c7_i422] = c7_b_inData[c7_i422];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i423;
  char_T c7_b_inData[105];
  int32_T c7_i424;
  char_T c7_u[105];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i423 = 0; c7_i423 < 105; c7_i423++) {
    c7_b_inData[c7_i423] = (*(char_T (*)[105])c7_inData)[c7_i423];
  }

  for (c7_i424 = 0; c7_i424 < 105; c7_i424++) {
    c7_u[c7_i424] = c7_b_inData[c7_i424];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i425;
  real_T c7_b_inData[105];
  int32_T c7_i426;
  real_T c7_u[105];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i425 = 0; c7_i425 < 105; c7_i425++) {
    c7_b_inData[c7_i425] = (*(real_T (*)[105])c7_inData)[c7_i425];
  }

  for (c7_i426 = 0; c7_i426 < 105; c7_i426++) {
    c7_u[c7_i426] = c7_b_inData[c7_i426];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i427;
  char_T c7_b_inData[110];
  int32_T c7_i428;
  char_T c7_u[110];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i427 = 0; c7_i427 < 110; c7_i427++) {
    c7_b_inData[c7_i427] = (*(char_T (*)[110])c7_inData)[c7_i427];
  }

  for (c7_i428 = 0; c7_i428 < 110; c7_i428++) {
    c7_u[c7_i428] = c7_b_inData[c7_i428];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 110),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i429;
  real_T c7_b_inData[110];
  int32_T c7_i430;
  real_T c7_u[110];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i429 = 0; c7_i429 < 110; c7_i429++) {
    c7_b_inData[c7_i429] = (*(real_T (*)[110])c7_inData)[c7_i429];
  }

  for (c7_i430 = 0; c7_i430 < 110; c7_i430++) {
    c7_u[c7_i430] = c7_b_inData[c7_i430];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 110), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i431;
  char_T c7_b_inData[111];
  int32_T c7_i432;
  char_T c7_u[111];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i431 = 0; c7_i431 < 111; c7_i431++) {
    c7_b_inData[c7_i431] = (*(char_T (*)[111])c7_inData)[c7_i431];
  }

  for (c7_i432 = 0; c7_i432 < 111; c7_i432++) {
    c7_u[c7_i432] = c7_b_inData[c7_i432];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i433;
  real_T c7_b_inData[111];
  int32_T c7_i434;
  real_T c7_u[111];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i433 = 0; c7_i433 < 111; c7_i433++) {
    c7_b_inData[c7_i433] = (*(real_T (*)[111])c7_inData)[c7_i433];
  }

  for (c7_i434 = 0; c7_i434 < 111; c7_i434++) {
    c7_u[c7_i434] = c7_b_inData[c7_i434];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i435;
  char_T c7_b_inData[112];
  int32_T c7_i436;
  char_T c7_u[112];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i435 = 0; c7_i435 < 112; c7_i435++) {
    c7_b_inData[c7_i435] = (*(char_T (*)[112])c7_inData)[c7_i435];
  }

  for (c7_i436 = 0; c7_i436 < 112; c7_i436++) {
    c7_u[c7_i436] = c7_b_inData[c7_i436];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 112),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_gd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i437;
  real_T c7_b_inData[112];
  int32_T c7_i438;
  real_T c7_u[112];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i437 = 0; c7_i437 < 112; c7_i437++) {
    c7_b_inData[c7_i437] = (*(real_T (*)[112])c7_inData)[c7_i437];
  }

  for (c7_i438 = 0; c7_i438 < 112; c7_i438++) {
    c7_u[c7_i438] = c7_b_inData[c7_i438];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 112), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_hd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i439;
  char_T c7_b_inData[114];
  int32_T c7_i440;
  char_T c7_u[114];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i439 = 0; c7_i439 < 114; c7_i439++) {
    c7_b_inData[c7_i439] = (*(char_T (*)[114])c7_inData)[c7_i439];
  }

  for (c7_i440 = 0; c7_i440 < 114; c7_i440++) {
    c7_u[c7_i440] = c7_b_inData[c7_i440];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 114),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_id_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i441;
  real_T c7_b_inData[114];
  int32_T c7_i442;
  real_T c7_u[114];
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i441 = 0; c7_i441 < 114; c7_i441++) {
    c7_b_inData[c7_i441] = (*(real_T (*)[114])c7_inData)[c7_i441];
  }

  for (c7_i442 = 0; c7_i442 < 114; c7_i442++) {
    c7_u[c7_i442] = c7_b_inData[c7_i442];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 114), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

const mxArray *sf_c7_ARP_02_RPSsmile_GloveAtomic_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c7_info_helper(&c7_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(const mxArray **c7_info)
{
  const mxArray *c7_rhs0 = NULL;
  const mxArray *c7_lhs0 = NULL;
  const mxArray *c7_rhs1 = NULL;
  const mxArray *c7_lhs1 = NULL;
  const mxArray *c7_rhs2 = NULL;
  const mxArray *c7_lhs2 = NULL;
  const mxArray *c7_rhs3 = NULL;
  const mxArray *c7_lhs3 = NULL;
  const mxArray *c7_rhs4 = NULL;
  const mxArray *c7_lhs4 = NULL;
  const mxArray *c7_rhs5 = NULL;
  const mxArray *c7_lhs5 = NULL;
  const mxArray *c7_rhs6 = NULL;
  const mxArray *c7_lhs6 = NULL;
  const mxArray *c7_rhs7 = NULL;
  const mxArray *c7_lhs7 = NULL;
  const mxArray *c7_rhs8 = NULL;
  const mxArray *c7_lhs8 = NULL;
  const mxArray *c7_rhs9 = NULL;
  const mxArray *c7_lhs9 = NULL;
  const mxArray *c7_rhs10 = NULL;
  const mxArray *c7_lhs10 = NULL;
  const mxArray *c7_rhs11 = NULL;
  const mxArray *c7_lhs11 = NULL;
  const mxArray *c7_rhs12 = NULL;
  const mxArray *c7_lhs12 = NULL;
  const mxArray *c7_rhs13 = NULL;
  const mxArray *c7_lhs13 = NULL;
  const mxArray *c7_rhs14 = NULL;
  const mxArray *c7_lhs14 = NULL;
  const mxArray *c7_rhs15 = NULL;
  const mxArray *c7_lhs15 = NULL;
  const mxArray *c7_rhs16 = NULL;
  const mxArray *c7_lhs16 = NULL;
  const mxArray *c7_rhs17 = NULL;
  const mxArray *c7_lhs17 = NULL;
  const mxArray *c7_rhs18 = NULL;
  const mxArray *c7_lhs18 = NULL;
  const mxArray *c7_rhs19 = NULL;
  const mxArray *c7_lhs19 = NULL;
  const mxArray *c7_rhs20 = NULL;
  const mxArray *c7_lhs20 = NULL;
  const mxArray *c7_rhs21 = NULL;
  const mxArray *c7_lhs21 = NULL;
  const mxArray *c7_rhs22 = NULL;
  const mxArray *c7_lhs22 = NULL;
  const mxArray *c7_rhs23 = NULL;
  const mxArray *c7_lhs23 = NULL;
  const mxArray *c7_rhs24 = NULL;
  const mxArray *c7_lhs24 = NULL;
  const mxArray *c7_rhs25 = NULL;
  const mxArray *c7_lhs25 = NULL;
  const mxArray *c7_rhs26 = NULL;
  const mxArray *c7_lhs26 = NULL;
  const mxArray *c7_rhs27 = NULL;
  const mxArray *c7_lhs27 = NULL;
  const mxArray *c7_rhs28 = NULL;
  const mxArray *c7_lhs28 = NULL;
  const mxArray *c7_rhs29 = NULL;
  const mxArray *c7_lhs29 = NULL;
  const mxArray *c7_rhs30 = NULL;
  const mxArray *c7_lhs30 = NULL;
  const mxArray *c7_rhs31 = NULL;
  const mxArray *c7_lhs31 = NULL;
  const mxArray *c7_rhs32 = NULL;
  const mxArray *c7_lhs32 = NULL;
  const mxArray *c7_rhs33 = NULL;
  const mxArray *c7_lhs33 = NULL;
  const mxArray *c7_rhs34 = NULL;
  const mxArray *c7_lhs34 = NULL;
  const mxArray *c7_rhs35 = NULL;
  const mxArray *c7_lhs35 = NULL;
  const mxArray *c7_rhs36 = NULL;
  const mxArray *c7_lhs36 = NULL;
  const mxArray *c7_rhs37 = NULL;
  const mxArray *c7_lhs37 = NULL;
  const mxArray *c7_rhs38 = NULL;
  const mxArray *c7_lhs38 = NULL;
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c7_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c7_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c7_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c7_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c7_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c7_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c7_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c7_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c7_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c7_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c7_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c7_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c7_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c7_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c7_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c7_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c7_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c7_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c7_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c7_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c7_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c7_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c7_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c7_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c7_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c7_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c7_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c7_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c7_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c7_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c7_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c7_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c7_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c7_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c7_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c7_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c7_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c7_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c7_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c7_rhs0);
  sf_mex_destroy(&c7_lhs0);
  sf_mex_destroy(&c7_rhs1);
  sf_mex_destroy(&c7_lhs1);
  sf_mex_destroy(&c7_rhs2);
  sf_mex_destroy(&c7_lhs2);
  sf_mex_destroy(&c7_rhs3);
  sf_mex_destroy(&c7_lhs3);
  sf_mex_destroy(&c7_rhs4);
  sf_mex_destroy(&c7_lhs4);
  sf_mex_destroy(&c7_rhs5);
  sf_mex_destroy(&c7_lhs5);
  sf_mex_destroy(&c7_rhs6);
  sf_mex_destroy(&c7_lhs6);
  sf_mex_destroy(&c7_rhs7);
  sf_mex_destroy(&c7_lhs7);
  sf_mex_destroy(&c7_rhs8);
  sf_mex_destroy(&c7_lhs8);
  sf_mex_destroy(&c7_rhs9);
  sf_mex_destroy(&c7_lhs9);
  sf_mex_destroy(&c7_rhs10);
  sf_mex_destroy(&c7_lhs10);
  sf_mex_destroy(&c7_rhs11);
  sf_mex_destroy(&c7_lhs11);
  sf_mex_destroy(&c7_rhs12);
  sf_mex_destroy(&c7_lhs12);
  sf_mex_destroy(&c7_rhs13);
  sf_mex_destroy(&c7_lhs13);
  sf_mex_destroy(&c7_rhs14);
  sf_mex_destroy(&c7_lhs14);
  sf_mex_destroy(&c7_rhs15);
  sf_mex_destroy(&c7_lhs15);
  sf_mex_destroy(&c7_rhs16);
  sf_mex_destroy(&c7_lhs16);
  sf_mex_destroy(&c7_rhs17);
  sf_mex_destroy(&c7_lhs17);
  sf_mex_destroy(&c7_rhs18);
  sf_mex_destroy(&c7_lhs18);
  sf_mex_destroy(&c7_rhs19);
  sf_mex_destroy(&c7_lhs19);
  sf_mex_destroy(&c7_rhs20);
  sf_mex_destroy(&c7_lhs20);
  sf_mex_destroy(&c7_rhs21);
  sf_mex_destroy(&c7_lhs21);
  sf_mex_destroy(&c7_rhs22);
  sf_mex_destroy(&c7_lhs22);
  sf_mex_destroy(&c7_rhs23);
  sf_mex_destroy(&c7_lhs23);
  sf_mex_destroy(&c7_rhs24);
  sf_mex_destroy(&c7_lhs24);
  sf_mex_destroy(&c7_rhs25);
  sf_mex_destroy(&c7_lhs25);
  sf_mex_destroy(&c7_rhs26);
  sf_mex_destroy(&c7_lhs26);
  sf_mex_destroy(&c7_rhs27);
  sf_mex_destroy(&c7_lhs27);
  sf_mex_destroy(&c7_rhs28);
  sf_mex_destroy(&c7_lhs28);
  sf_mex_destroy(&c7_rhs29);
  sf_mex_destroy(&c7_lhs29);
  sf_mex_destroy(&c7_rhs30);
  sf_mex_destroy(&c7_lhs30);
  sf_mex_destroy(&c7_rhs31);
  sf_mex_destroy(&c7_lhs31);
  sf_mex_destroy(&c7_rhs32);
  sf_mex_destroy(&c7_lhs32);
  sf_mex_destroy(&c7_rhs33);
  sf_mex_destroy(&c7_lhs33);
  sf_mex_destroy(&c7_rhs34);
  sf_mex_destroy(&c7_lhs34);
  sf_mex_destroy(&c7_rhs35);
  sf_mex_destroy(&c7_lhs35);
  sf_mex_destroy(&c7_rhs36);
  sf_mex_destroy(&c7_lhs36);
  sf_mex_destroy(&c7_rhs37);
  sf_mex_destroy(&c7_lhs37);
  sf_mex_destroy(&c7_rhs38);
  sf_mex_destroy(&c7_lhs38);
}

static const mxArray *c7_emlrt_marshallOut(const char * c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c7_u)), false);
  return c7_y;
}

static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  return c7_y;
}

static void c7_activate_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = c7_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c7_event_secs,
               chartInstance->c7_sfEvent);
}

static void c7_deactivate_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c7_event_secs,
               chartInstance->c7_sfEvent);
}

static void c7_increment_counters_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  if (chartInstance->c7_temporalCounter_i1 < 7U) {
    chartInstance->c7_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c7_temporalCounter_i1 + 1);
  }
}

static void c7_reset_counters_secsc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c7_ARP_02_RPSsmile_GloveAtomic_secs(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_activate_secsc7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c7_ARP_02_RPSsmile_GloveAtomic_secs
  (SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_increment_counters_secsc7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c7_ARP_02_RPSsmile_GloveAtomic_secs
  (SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_reset_counters_secsc7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_deactivate_c7_ARP_02_RPSsmile_GloveAtomic_secs(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_deactivate_secsc7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

boolean_T sf_exported_auto_isStablec7_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c7_isStable;
}

void sf_exported_auto_duringc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_enterc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c7_sendSBM(chartInstance);
  c7_sendBML(chartInstance);
  c7_enter_atomic_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  c7_enter_internal_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

void sf_exported_auto_exitc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c7_exit_internal_c7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  c7_b_sendSBM(chartInstance);
  c7_b_sendBML(chartInstance);
}

void sf_exported_auto_gatewayc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c7_sendSBM(chartInstance);
  c7_sendBML(chartInstance);
}

void sf_exported_auto_disablec7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c7_b_sendSBM(chartInstance);
  c7_b_sendBML(chartInstance);
}

void sf_exported_auto_stepBuffersc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initBuffersc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_activate_callc7_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  chartInstance->c7_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc7_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_reset_call_counterc7_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_deactivate_callc7_ARP_02_RPSsmile_GloveAtomic(SimStruct
  *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
}

void sf_exported_auto_initc7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_initc7_ARP_02_RPSsmile_GloveAtomic(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec7_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c7_S)
{
  const mxArray *c7_out = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_out = NULL;
  sf_mex_assign(&c7_out,
                sf_internal_get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic(c7_S),
                false);
  return c7_out;
}

void sf_exported_auto_setSimstatec7_ARP_02_RPSsmile_GloveAtomic(SimStruct *c7_S,
  const mxArray *c7_in)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic(c7_S, sf_mex_dup
    (c7_in));
  sf_mex_destroy(&c7_in);
}

void sf_exported_auto_check_state_inconsistency_c7_ARP_02_RPSsmile_GloveAtomic
  (SimStruct *c7_S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSsmile_GloveAtomicMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c7_arg
   [256])
{
  int32_T c7_i443;
  int32_T c7_i444;
  int32_T c7_i445;
  real_T (*c7_b_arg)[256];
  c7_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c7_i443 = 0; c7_i443 < 256; c7_i443++) {
    _SFD_DATA_RANGE_CHECK(c7_arg[c7_i443], 25U);
  }

  _SFD_SET_DATA_VALUE_PTR(25U, c7_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c7_arg, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c7_sfEvent);
  for (c7_i444 = 0; c7_i444 < 256; c7_i444++) {
    (*c7_b_arg)[c7_i444] = c7_arg[c7_i444];
  }

  for (c7_i445 = 0; c7_i445 < 256; c7_i445++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_arg)[c7_i445], 25U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c7_sfEvent);
}

static void c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T c7_arg
   [256])
{
  int32_T c7_i446;
  int32_T c7_i447;
  int32_T c7_i448;
  real_T (*c7_b_arg)[256];
  c7_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c7_i446 = 0; c7_i446 < 256; c7_i446++) {
    _SFD_DATA_RANGE_CHECK(c7_arg[c7_i446], 26U);
  }

  _SFD_SET_DATA_VALUE_PTR(26U, c7_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c7_arg, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c7_sfEvent);
  for (c7_i447 = 0; c7_i447 < 256; c7_i447++) {
    (*c7_b_arg)[c7_i447] = c7_arg[c7_i447];
  }

  for (c7_i448 = 0; c7_i448 < 256; c7_i448++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_arg)[c7_i448], 26U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(26U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c7_sfEvent);
}

static void c7_rockPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[6];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv88[256];
  int32_T c7_i449;
  int32_T c7_i450;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  uint32_T c7_b_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[94];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[94];
  real_T c7_b_nargin = 1.0;
  real_T c7_b_nargout = 1.0;
  real_T c7_myarr256[256];
  int32_T c7_i451;
  static char_T c7_cv51[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i452;
  static real_T c7_dv89[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c7_i453;
  int32_T c7_i454;
  int32_T c7_i455;
  int32_T c7_i456;
  int32_T c7_i457;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i458;
  int32_T c7_i459;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 15);
  if (CV_EML_IF(7, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 16);
    CV_EML_FCN(7, 1);
    _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 27);
    c7_encStr2Arr(chartInstance, c7_dv88);
    for (c7_i449 = 0; c7_i449 < 256; c7_i449++) {
      c7_poseBML[c7_i449] = c7_dv88[c7_i449];
    }

    c7_updateDataWrittenToVector(chartInstance, 7U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 7U, 28U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i450 = 0; c7_i450 < 256; c7_i450++) {
      c7_u[c7_i450] = c7_poseBML[c7_i450];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, -27);
  } else {
    _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 17);
    if (CV_EML_IF(7, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 18);
      CV_EML_FCN(7, 2);
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_c_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_f_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
        c7_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_e_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 6U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 7U,
        c7_b_sf_marshallOut, c7_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U, c7_d_sf_marshallOut,
        c7_d_sf_marshallIn);
      for (c7_i451 = 0; c7_i451 < 94; c7_i451++) {
        c7_mystr[c7_i451] = c7_cv51[c7_i451];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
      c7_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
      for (c7_i452 = 0; c7_i452 < 94; c7_i452++) {
        c7_arr[c7_i452] = c7_dv89[c7_i452];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
      c7_ss = 94.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
      c7_padsize = c7_maxarrsize - c7_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
      for (c7_i453 = 0; c7_i453 < 256; c7_i453++) {
        c7_tt[c7_i453] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
      for (c7_i454 = 0; c7_i454 < 94; c7_i454++) {
        c7_tt[c7_i454] = c7_arr[c7_i454];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
      for (c7_i455 = 0; c7_i455 < 256; c7_i455++) {
        c7_myarr256[c7_i455] = c7_tt[c7_i455];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c7_i456 = 0; c7_i456 < 256; c7_i456++) {
        c7_poseBML[c7_i456] = c7_myarr256[c7_i456];
      }

      c7_updateDataWrittenToVector(chartInstance, 7U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 7U, 28U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i457 = 0; c7_i457 < 256; c7_i457++) {
        c7_b_u[c7_i457] = c7_poseBML[c7_i457];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, -33);
    } else {
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 20);
      CV_EML_FCN(7, 1);
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, 27);
      c7_encStr2Arr(chartInstance, c7_dv88);
      for (c7_i458 = 0; c7_i458 < 256; c7_i458++) {
        c7_poseBML[c7_i458] = c7_dv88[c7_i458];
      }

      c7_updateDataWrittenToVector(chartInstance, 7U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 7U, 28U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i459 = 0; c7_i459 < 256; c7_i459++) {
        c7_c_u[c7_i459] = c7_poseBML[c7_i459];
      }

      c7_c_y = NULL;
      sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_c_y);
      _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c7_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_paperPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[6];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv90[256];
  int32_T c7_i460;
  int32_T c7_i461;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i462;
  int32_T c7_i463;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i464;
  int32_T c7_i465;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c7_d_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 15);
  if (CV_EML_IF(6, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 16);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 27);
    c7_b_encStr2Arr(chartInstance, c7_dv90);
    for (c7_i460 = 0; c7_i460 < 256; c7_i460++) {
      c7_poseBML[c7_i460] = c7_dv90[c7_i460];
    }

    c7_updateDataWrittenToVector(chartInstance, 8U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 8U, 30U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i461 = 0; c7_i461 < 256; c7_i461++) {
      c7_u[c7_i461] = c7_poseBML[c7_i461];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, -27);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 17);
    if (CV_EML_IF(6, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 18);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 33);
      c7_c_encStr2Arr(chartInstance, c7_dv90);
      for (c7_i462 = 0; c7_i462 < 256; c7_i462++) {
        c7_poseBML[c7_i462] = c7_dv90[c7_i462];
      }

      c7_updateDataWrittenToVector(chartInstance, 8U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 8U, 30U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i463 = 0; c7_i463 < 256; c7_i463++) {
        c7_b_u[c7_i463] = c7_poseBML[c7_i463];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, -33);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 20);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, 33);
      c7_c_encStr2Arr(chartInstance, c7_dv90);
      for (c7_i464 = 0; c7_i464 < 256; c7_i464++) {
        c7_poseBML[c7_i464] = c7_dv90[c7_i464];
      }

      c7_updateDataWrittenToVector(chartInstance, 8U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 8U, 30U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i465 = 0; c7_i465 < 256; c7_i465++) {
        c7_c_u[c7_i465] = c7_poseBML[c7_i465];
      }

      c7_c_y = NULL;
      sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_c_y);
      _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, -33);
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c7_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_scissorsPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[6];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv91[256];
  int32_T c7_i466;
  int32_T c7_i467;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i468;
  int32_T c7_i469;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i470;
  int32_T c7_i471;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c7_g_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(8, 0);
  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 15);
  if (CV_EML_IF(8, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 16);
    CV_EML_FCN(8, 1);
    _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 27);
    c7_c_encStr2Arr(chartInstance, c7_dv91);
    for (c7_i466 = 0; c7_i466 < 256; c7_i466++) {
      c7_poseBML[c7_i466] = c7_dv91[c7_i466];
    }

    c7_updateDataWrittenToVector(chartInstance, 9U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 9U, 32U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i467 = 0; c7_i467 < 256; c7_i467++) {
      c7_u[c7_i467] = c7_poseBML[c7_i467];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, -27);
  } else {
    _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 17);
    if (CV_EML_IF(8, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 18);
      CV_EML_FCN(8, 2);
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 33);
      c7_b_encStr2Arr(chartInstance, c7_dv91);
      for (c7_i468 = 0; c7_i468 < 256; c7_i468++) {
        c7_poseBML[c7_i468] = c7_dv91[c7_i468];
      }

      c7_updateDataWrittenToVector(chartInstance, 9U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 9U, 32U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i469 = 0; c7_i469 < 256; c7_i469++) {
        c7_b_u[c7_i469] = c7_poseBML[c7_i469];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, -33);
    } else {
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 20);
      CV_EML_FCN(8, 1);
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, 27);
      c7_c_encStr2Arr(chartInstance, c7_dv91);
      for (c7_i470 = 0; c7_i470 < 256; c7_i470++) {
        c7_poseBML[c7_i470] = c7_dv91[c7_i470];
      }

      c7_updateDataWrittenToVector(chartInstance, 9U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 9U, 32U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i471 = 0; c7_i471 < 256; c7_i471++) {
        c7_c_u[c7_i471] = c7_poseBML[c7_i471];
      }

      c7_c_y = NULL;
      sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_c_y);
      _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(8U, chartInstance->c7_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_sbmID, real_T c7_poseSBM[256])
{
  uint32_T c7_debug_family_var_map[10];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  boolean_T c7_aVarTruthTableCondition_3;
  boolean_T c7_aVarTruthTableCondition_4;
  boolean_T c7_aVarTruthTableCondition_5;
  boolean_T c7_aVarTruthTableCondition_6;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv92[256];
  int32_T c7_i472;
  int32_T c7_i473;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i474;
  int32_T c7_i475;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i476;
  int32_T c7_i477;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  int32_T c7_i478;
  int32_T c7_i479;
  real_T c7_d_u[256];
  const mxArray *c7_d_y = NULL;
  uint32_T c7_b_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[81];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[81];
  real_T c7_b_nargin = 1.0;
  real_T c7_b_nargout = 1.0;
  real_T c7_myarr256[256];
  int32_T c7_i480;
  static char_T c7_cv52[81] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w', 'r', 'i',
    's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't',
    'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '-', '1',
    ',', '0', '.', '1', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c7_i481;
  static real_T c7_dv93[81] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0, 105.0,
    115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 45.0, 49.0, 44.0, 48.0, 46.0, 49.0,
    44.0, 48.0, 44.0, 48.0, 41.0, 41.0, 59.0 };

  int32_T c7_i482;
  int32_T c7_i483;
  int32_T c7_i484;
  int32_T c7_i485;
  int32_T c7_i486;
  real_T c7_e_u[256];
  const mxArray *c7_e_y = NULL;
  int32_T c7_i487;
  int32_T c7_i488;
  real_T c7_f_u[256];
  const mxArray *c7_f_y = NULL;
  int32_T c7_i489;
  int32_T c7_i490;
  real_T c7_g_u[256];
  const mxArray *c7_g_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c7_h_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_3, 2U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_4, 3U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_5, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_6, 5U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_sbmID, 8U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseSBM, 9U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 5);
  c7_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 6);
  c7_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 7);
  c7_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 8);
  c7_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_1 = (c7_sbmID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 17);
  c7_aVarTruthTableCondition_2 = (c7_sbmID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 21);
  c7_aVarTruthTableCondition_3 = (c7_sbmID == 3.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 25);
  c7_aVarTruthTableCondition_4 = (c7_sbmID == 4.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 29);
  c7_aVarTruthTableCondition_5 = (c7_sbmID == 5.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 33);
  c7_aVarTruthTableCondition_6 = (c7_sbmID == 6.0);
  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 35);
  if (CV_EML_IF(4, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 36);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 55);
    c7_d_encStr2Arr(chartInstance, c7_dv92);
    for (c7_i472 = 0; c7_i472 < 256; c7_i472++) {
      c7_poseSBM[c7_i472] = c7_dv92[c7_i472];
    }

    c7_updateDataWrittenToVector(chartInstance, 10U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
    sf_mex_printf("%s =\\n", "poseSBM");
    for (c7_i473 = 0; c7_i473 < 256; c7_i473++) {
      c7_u[c7_i473] = c7_poseSBM[c7_i473];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -55);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 37);
    if (CV_EML_IF(4, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 38);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 61);
      c7_e_encStr2Arr(chartInstance, c7_dv92);
      for (c7_i474 = 0; c7_i474 < 256; c7_i474++) {
        c7_poseSBM[c7_i474] = c7_dv92[c7_i474];
      }

      c7_updateDataWrittenToVector(chartInstance, 10U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
      sf_mex_printf("%s =\\n", "poseSBM");
      for (c7_i475 = 0; c7_i475 < 256; c7_i475++) {
        c7_b_u[c7_i475] = c7_poseSBM[c7_i475];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -61);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 39);
      if (CV_EML_IF(4, 1, 2, c7_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 40);
        CV_EML_FCN(4, 3);
        _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 67);
        c7_f_encStr2Arr(chartInstance, c7_dv92);
        for (c7_i476 = 0; c7_i476 < 256; c7_i476++) {
          c7_poseSBM[c7_i476] = c7_dv92[c7_i476];
        }

        c7_updateDataWrittenToVector(chartInstance, 10U);
        c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
        sf_mex_printf("%s =\\n", "poseSBM");
        for (c7_i477 = 0; c7_i477 < 256; c7_i477++) {
          c7_c_u[c7_i477] = c7_poseSBM[c7_i477];
        }

        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -67);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 41);
        if (CV_EML_IF(4, 1, 3, c7_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 42);
          CV_EML_FCN(4, 4);
          _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 73);
          c7_g_encStr2Arr(chartInstance, c7_dv92);
          for (c7_i478 = 0; c7_i478 < 256; c7_i478++) {
            c7_poseSBM[c7_i478] = c7_dv92[c7_i478];
          }

          c7_updateDataWrittenToVector(chartInstance, 10U);
          c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
          sf_mex_printf("%s =\\n", "poseSBM");
          for (c7_i479 = 0; c7_i479 < 256; c7_i479++) {
            c7_d_u[c7_i479] = c7_poseSBM[c7_i479];
          }

          c7_d_y = NULL;
          sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c7_d_y);
          _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -73);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 43);
          if (CV_EML_IF(4, 1, 4, c7_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 44);
            CV_EML_FCN(4, 5);
            _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 79);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_m_debug_family_names,
              c7_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U,
              c7_b_sf_marshallOut, c7_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_t_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U,
              c7_b_sf_marshallOut, c7_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
              c7_d_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_s_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 6U,
              c7_b_sf_marshallOut, c7_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 7U,
              c7_b_sf_marshallOut, c7_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U,
              c7_d_sf_marshallOut, c7_d_sf_marshallIn);
            for (c7_i480 = 0; c7_i480 < 81; c7_i480++) {
              c7_mystr[c7_i480] = c7_cv52[c7_i480];
            }

            CV_SCRIPT_FCN(0, 0);
            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
            c7_maxarrsize = 256.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
            for (c7_i481 = 0; c7_i481 < 81; c7_i481++) {
              c7_arr[c7_i481] = c7_dv93[c7_i481];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
            c7_ss = 81.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
            c7_padsize = c7_maxarrsize - c7_ss;
            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
            for (c7_i482 = 0; c7_i482 < 256; c7_i482++) {
              c7_tt[c7_i482] = 0.0;
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
            for (c7_i483 = 0; c7_i483 < 81; c7_i483++) {
              c7_tt[c7_i483] = c7_arr[c7_i483];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
            for (c7_i484 = 0; c7_i484 < 256; c7_i484++) {
              c7_myarr256[c7_i484] = c7_tt[c7_i484];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
            _SFD_SYMBOL_SCOPE_POP();
            for (c7_i485 = 0; c7_i485 < 256; c7_i485++) {
              c7_poseSBM[c7_i485] = c7_myarr256[c7_i485];
            }

            c7_updateDataWrittenToVector(chartInstance, 10U);
            c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
            sf_mex_printf("%s =\\n", "poseSBM");
            for (c7_i486 = 0; c7_i486 < 256; c7_i486++) {
              c7_e_u[c7_i486] = c7_poseSBM[c7_i486];
            }

            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c7_e_y);
            _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -79);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 45);
            if (CV_EML_IF(4, 1, 5, c7_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 46);
              CV_EML_FCN(4, 6);
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 85);
              c7_h_encStr2Arr(chartInstance, c7_dv92);
              for (c7_i487 = 0; c7_i487 < 256; c7_i487++) {
                c7_poseSBM[c7_i487] = c7_dv92[c7_i487];
              }

              c7_updateDataWrittenToVector(chartInstance, 10U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c7_i488 = 0; c7_i488 < 256; c7_i488++) {
                c7_f_u[c7_i488] = c7_poseSBM[c7_i488];
              }

              c7_f_y = NULL;
              sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_f_y);
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -85);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 48);
              CV_EML_FCN(4, 6);
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, 85);
              c7_h_encStr2Arr(chartInstance, c7_dv92);
              for (c7_i489 = 0; c7_i489 < 256; c7_i489++) {
                c7_poseSBM[c7_i489] = c7_dv92[c7_i489];
              }

              c7_updateDataWrittenToVector(chartInstance, 10U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 10U, 34U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c7_i490 = 0; c7_i490 < 256; c7_i490++) {
                c7_g_u[c7_i490] = c7_poseSBM[c7_i490];
              }

              c7_g_y = NULL;
              sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_g_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_g_y);
              _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -85);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c7_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[12];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  boolean_T c7_aVarTruthTableCondition_3;
  boolean_T c7_aVarTruthTableCondition_4;
  boolean_T c7_aVarTruthTableCondition_5;
  boolean_T c7_aVarTruthTableCondition_6;
  boolean_T c7_aVarTruthTableCondition_7;
  boolean_T c7_aVarTruthTableCondition_8;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv94[256];
  int32_T c7_i491;
  int32_T c7_i492;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i493;
  int32_T c7_i494;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  uint32_T c7_b_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[68];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[68];
  real_T c7_b_nargin = 1.0;
  real_T c7_b_nargout = 1.0;
  real_T c7_myarr256[256];
  int32_T c7_i495;
  static char_T c7_cv53[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i496;
  static real_T c7_dv95[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c7_i497;
  int32_T c7_i498;
  int32_T c7_i499;
  int32_T c7_i500;
  int32_T c7_i501;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  int32_T c7_i502;
  int32_T c7_i503;
  real_T c7_d_u[256];
  const mxArray *c7_d_y = NULL;
  int32_T c7_i504;
  int32_T c7_i505;
  real_T c7_e_u[256];
  const mxArray *c7_e_y = NULL;
  int32_T c7_i506;
  int32_T c7_i507;
  real_T c7_f_u[256];
  const mxArray *c7_f_y = NULL;
  int32_T c7_i508;
  int32_T c7_i509;
  real_T c7_g_u[256];
  const mxArray *c7_g_y = NULL;
  int32_T c7_i510;
  int32_T c7_i511;
  real_T c7_h_u[256];
  const mxArray *c7_h_y = NULL;
  int32_T c7_i512;
  int32_T c7_i513;
  real_T c7_i_u[256];
  const mxArray *c7_i_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c7_o_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_3, 2U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_4, 3U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_5, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_6, 5U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_7, 6U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_8, 7U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 8U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 9U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 10U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 11U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 5);
  c7_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 6);
  c7_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 7);
  c7_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 8);
  c7_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 10);
  c7_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 15);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 19);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 23);
  c7_aVarTruthTableCondition_3 = (c7_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 27);
  c7_aVarTruthTableCondition_4 = (c7_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 31);
  c7_aVarTruthTableCondition_5 = (c7_bmlID == 5.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 35);
  c7_aVarTruthTableCondition_6 = (c7_bmlID == 6.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 39);
  c7_aVarTruthTableCondition_7 = (c7_bmlID == 7.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 43);
  c7_aVarTruthTableCondition_8 = (c7_bmlID == 8.0);
  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 45);
  if (CV_EML_IF(5, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 46);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 69);
    c7_i_encStr2Arr(chartInstance, c7_dv94);
    for (c7_i491 = 0; c7_i491 < 256; c7_i491++) {
      c7_poseBML[c7_i491] = c7_dv94[c7_i491];
    }

    c7_updateDataWrittenToVector(chartInstance, 11U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i492 = 0; c7_i492 < 256; c7_i492++) {
      c7_u[c7_i492] = c7_poseBML[c7_i492];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -69);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 47);
    if (CV_EML_IF(5, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 48);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 75);
      c7_j_encStr2Arr(chartInstance, c7_dv94);
      for (c7_i493 = 0; c7_i493 < 256; c7_i493++) {
        c7_poseBML[c7_i493] = c7_dv94[c7_i493];
      }

      c7_updateDataWrittenToVector(chartInstance, 11U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i494 = 0; c7_i494 < 256; c7_i494++) {
        c7_b_u[c7_i494] = c7_poseBML[c7_i494];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -75);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 49);
      if (CV_EML_IF(5, 1, 2, c7_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 50);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 81);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_r_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_cb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U, c7_d_sf_marshallOut,
          c7_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_bb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 6U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 7U,
          c7_b_sf_marshallOut, c7_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U,
          c7_d_sf_marshallOut, c7_d_sf_marshallIn);
        for (c7_i495 = 0; c7_i495 < 68; c7_i495++) {
          c7_mystr[c7_i495] = c7_cv53[c7_i495];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
        c7_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
        for (c7_i496 = 0; c7_i496 < 68; c7_i496++) {
          c7_arr[c7_i496] = c7_dv95[c7_i496];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
        c7_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
        c7_padsize = c7_maxarrsize - c7_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
        for (c7_i497 = 0; c7_i497 < 256; c7_i497++) {
          c7_tt[c7_i497] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
        for (c7_i498 = 0; c7_i498 < 68; c7_i498++) {
          c7_tt[c7_i498] = c7_arr[c7_i498];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
        for (c7_i499 = 0; c7_i499 < 256; c7_i499++) {
          c7_myarr256[c7_i499] = c7_tt[c7_i499];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c7_i500 = 0; c7_i500 < 256; c7_i500++) {
          c7_poseBML[c7_i500] = c7_myarr256[c7_i500];
        }

        c7_updateDataWrittenToVector(chartInstance, 11U);
        c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c7_i501 = 0; c7_i501 < 256; c7_i501++) {
          c7_c_u[c7_i501] = c7_poseBML[c7_i501];
        }

        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -81);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 51);
        if (CV_EML_IF(5, 1, 3, c7_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 52);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 87);
          c7_k_encStr2Arr(chartInstance, c7_dv94);
          for (c7_i502 = 0; c7_i502 < 256; c7_i502++) {
            c7_poseBML[c7_i502] = c7_dv94[c7_i502];
          }

          c7_updateDataWrittenToVector(chartInstance, 11U);
          c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c7_i503 = 0; c7_i503 < 256; c7_i503++) {
            c7_d_u[c7_i503] = c7_poseBML[c7_i503];
          }

          c7_d_y = NULL;
          sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c7_d_y);
          _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -87);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 53);
          if (CV_EML_IF(5, 1, 4, c7_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 54);
            CV_EML_FCN(5, 5);
            _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 93);
            c7_l_encStr2Arr(chartInstance, c7_dv94);
            for (c7_i504 = 0; c7_i504 < 256; c7_i504++) {
              c7_poseBML[c7_i504] = c7_dv94[c7_i504];
            }

            c7_updateDataWrittenToVector(chartInstance, 11U);
            c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c7_i505 = 0; c7_i505 < 256; c7_i505++) {
              c7_e_u[c7_i505] = c7_poseBML[c7_i505];
            }

            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c7_e_y);
            _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -93);
          } else {
            _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 55);
            if (CV_EML_IF(5, 1, 5, c7_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 56);
              CV_EML_FCN(5, 6);
              _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 99);
              c7_m_encStr2Arr(chartInstance, c7_dv94);
              for (c7_i506 = 0; c7_i506 < 256; c7_i506++) {
                c7_poseBML[c7_i506] = c7_dv94[c7_i506];
              }

              c7_updateDataWrittenToVector(chartInstance, 11U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c7_i507 = 0; c7_i507 < 256; c7_i507++) {
                c7_f_u[c7_i507] = c7_poseBML[c7_i507];
              }

              c7_f_y = NULL;
              sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_f_y);
              _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -99);
            } else {
              _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 57);
              if (CV_EML_IF(5, 1, 6, c7_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 58);
                CV_EML_FCN(5, 7);
                _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 105);
                c7_n_encStr2Arr(chartInstance, c7_dv94);
                for (c7_i508 = 0; c7_i508 < 256; c7_i508++) {
                  c7_poseBML[c7_i508] = c7_dv94[c7_i508];
                }

                c7_updateDataWrittenToVector(chartInstance, 11U);
                c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c7_i509 = 0; c7_i509 < 256; c7_i509++) {
                  c7_g_u[c7_i509] = c7_poseBML[c7_i509];
                }

                c7_g_y = NULL;
                sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c7_g_y);
                _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -105);
              } else {
                _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 59);
                if (CV_EML_IF(5, 1, 7, c7_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 60);
                  CV_EML_FCN(5, 8);
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 111);
                  c7_o_encStr2Arr(chartInstance, c7_dv94);
                  for (c7_i510 = 0; c7_i510 < 256; c7_i510++) {
                    c7_poseBML[c7_i510] = c7_dv94[c7_i510];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 11U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c7_i511 = 0; c7_i511 < 256; c7_i511++) {
                    c7_h_u[c7_i511] = c7_poseBML[c7_i511];
                  }

                  c7_h_y = NULL;
                  sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_h_y);
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 62);
                  CV_EML_FCN(5, 8);
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, 111);
                  c7_o_encStr2Arr(chartInstance, c7_dv94);
                  for (c7_i512 = 0; c7_i512 < 256; c7_i512++) {
                    c7_poseBML[c7_i512] = c7_dv94[c7_i512];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 11U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 11U, 36U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c7_i513 = 0; c7_i513 < 256; c7_i513++) {
                    c7_i_u[c7_i513] = c7_poseBML[c7_i513];
                  }

                  c7_i_y = NULL;
                  sf_mex_assign(&c7_i_y, sf_mex_create("y", c7_i_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_i_y);
                  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -111);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c7_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_boredPoseSc7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[22];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  boolean_T c7_aVarTruthTableCondition_3;
  boolean_T c7_aVarTruthTableCondition_4;
  boolean_T c7_aVarTruthTableCondition_5;
  boolean_T c7_aVarTruthTableCondition_6;
  boolean_T c7_aVarTruthTableCondition_7;
  boolean_T c7_aVarTruthTableCondition_8;
  boolean_T c7_aVarTruthTableCondition_9;
  boolean_T c7_aVarTruthTableCondition_10;
  boolean_T c7_aVarTruthTableCondition_11;
  boolean_T c7_aVarTruthTableCondition_12;
  boolean_T c7_aVarTruthTableCondition_13;
  boolean_T c7_aVarTruthTableCondition_14;
  boolean_T c7_aVarTruthTableCondition_15;
  boolean_T c7_aVarTruthTableCondition_16;
  boolean_T c7_aVarTruthTableCondition_17;
  boolean_T c7_aVarTruthTableCondition_18;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv96[256];
  int32_T c7_i514;
  int32_T c7_i515;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i516;
  int32_T c7_i517;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i518;
  int32_T c7_i519;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  int32_T c7_i520;
  int32_T c7_i521;
  real_T c7_d_u[256];
  const mxArray *c7_d_y = NULL;
  int32_T c7_i522;
  int32_T c7_i523;
  real_T c7_e_u[256];
  const mxArray *c7_e_y = NULL;
  int32_T c7_i524;
  int32_T c7_i525;
  real_T c7_f_u[256];
  const mxArray *c7_f_y = NULL;
  int32_T c7_i526;
  int32_T c7_i527;
  real_T c7_g_u[256];
  const mxArray *c7_g_y = NULL;
  int32_T c7_i528;
  int32_T c7_i529;
  real_T c7_h_u[256];
  const mxArray *c7_h_y = NULL;
  int32_T c7_i530;
  int32_T c7_i531;
  real_T c7_i_u[256];
  const mxArray *c7_i_y = NULL;
  int32_T c7_i532;
  int32_T c7_i533;
  real_T c7_j_u[256];
  const mxArray *c7_j_y = NULL;
  int32_T c7_i534;
  int32_T c7_i535;
  real_T c7_k_u[256];
  const mxArray *c7_k_y = NULL;
  int32_T c7_i536;
  int32_T c7_i537;
  real_T c7_l_u[256];
  const mxArray *c7_l_y = NULL;
  int32_T c7_i538;
  int32_T c7_i539;
  real_T c7_m_u[256];
  const mxArray *c7_m_y = NULL;
  int32_T c7_i540;
  int32_T c7_i541;
  real_T c7_n_u[256];
  const mxArray *c7_n_y = NULL;
  int32_T c7_i542;
  int32_T c7_i543;
  real_T c7_o_u[256];
  const mxArray *c7_o_y = NULL;
  int32_T c7_i544;
  int32_T c7_i545;
  real_T c7_p_u[256];
  const mxArray *c7_p_y = NULL;
  int32_T c7_i546;
  int32_T c7_i547;
  real_T c7_q_u[256];
  const mxArray *c7_q_y = NULL;
  int32_T c7_i548;
  int32_T c7_i549;
  real_T c7_r_u[256];
  const mxArray *c7_r_y = NULL;
  int32_T c7_i550;
  int32_T c7_i551;
  real_T c7_s_u[256];
  const mxArray *c7_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c7_x_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_3, 2U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_4, 3U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_5, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_6, 5U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_7, 6U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_8, 7U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_9, 8U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_10, 9U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_11, 10U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_12, 11U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_13, 12U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_14, 13U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_15, 14U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_16, 15U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_17, 16U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_18, 17U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 18U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 19U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 20U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 21U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 5);
  c7_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 6);
  c7_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 7);
  c7_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 8);
  c7_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 10);
  c7_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 11);
  c7_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 12);
  c7_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 14);
  c7_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 15);
  c7_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 16);
  c7_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 17);
  c7_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 18);
  c7_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 19);
  c7_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 20);
  c7_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 24);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 27);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 30);
  c7_aVarTruthTableCondition_3 = (c7_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 33);
  c7_aVarTruthTableCondition_4 = (c7_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 36);
  c7_aVarTruthTableCondition_5 = (c7_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 39);
  c7_aVarTruthTableCondition_6 = (c7_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 42);
  c7_aVarTruthTableCondition_7 = (c7_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 45);
  c7_aVarTruthTableCondition_8 = (c7_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 48);
  c7_aVarTruthTableCondition_9 = (c7_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 51);
  c7_aVarTruthTableCondition_10 = (c7_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 54);
  c7_aVarTruthTableCondition_11 = (c7_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 57);
  c7_aVarTruthTableCondition_12 = (c7_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 60);
  c7_aVarTruthTableCondition_13 = (c7_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 63);
  c7_aVarTruthTableCondition_14 = (c7_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 66);
  c7_aVarTruthTableCondition_15 = (c7_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 69);
  c7_aVarTruthTableCondition_16 = (c7_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 72);
  c7_aVarTruthTableCondition_17 = (c7_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 75);
  c7_aVarTruthTableCondition_18 = (c7_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 77);
  if (CV_EML_IF(2, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 78);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 121);
    c7_p_encStr2Arr(chartInstance, c7_dv96);
    for (c7_i514 = 0; c7_i514 < 256; c7_i514++) {
      c7_poseBML[c7_i514] = c7_dv96[c7_i514];
    }

    c7_updateDataWrittenToVector(chartInstance, 12U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i515 = 0; c7_i515 < 256; c7_i515++) {
      c7_u[c7_i515] = c7_poseBML[c7_i515];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -121);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 79);
    if (CV_EML_IF(2, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 80);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, MAX_int8_T);
      c7_q_encStr2Arr(chartInstance, c7_dv96);
      for (c7_i516 = 0; c7_i516 < 256; c7_i516++) {
        c7_poseBML[c7_i516] = c7_dv96[c7_i516];
      }

      c7_updateDataWrittenToVector(chartInstance, 12U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i517 = 0; c7_i517 < 256; c7_i517++) {
        c7_b_u[c7_i517] = c7_poseBML[c7_i517];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -127);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 81);
      if (CV_EML_IF(2, 1, 2, c7_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 82);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 133U);
        c7_r_encStr2Arr(chartInstance, c7_dv96);
        for (c7_i518 = 0; c7_i518 < 256; c7_i518++) {
          c7_poseBML[c7_i518] = c7_dv96[c7_i518];
        }

        c7_updateDataWrittenToVector(chartInstance, 12U);
        c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c7_i519 = 0; c7_i519 < 256; c7_i519++) {
          c7_c_u[c7_i519] = c7_poseBML[c7_i519];
        }

        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -133);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 83);
        if (CV_EML_IF(2, 1, 3, c7_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 84);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 139U);
          c7_s_encStr2Arr(chartInstance, c7_dv96);
          for (c7_i520 = 0; c7_i520 < 256; c7_i520++) {
            c7_poseBML[c7_i520] = c7_dv96[c7_i520];
          }

          c7_updateDataWrittenToVector(chartInstance, 12U);
          c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c7_i521 = 0; c7_i521 < 256; c7_i521++) {
            c7_d_u[c7_i521] = c7_poseBML[c7_i521];
          }

          c7_d_y = NULL;
          sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c7_d_y);
          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -139);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 85);
          if (CV_EML_IF(2, 1, 4, c7_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 86);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 145U);
            c7_t_encStr2Arr(chartInstance, c7_dv96);
            for (c7_i522 = 0; c7_i522 < 256; c7_i522++) {
              c7_poseBML[c7_i522] = c7_dv96[c7_i522];
            }

            c7_updateDataWrittenToVector(chartInstance, 12U);
            c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c7_i523 = 0; c7_i523 < 256; c7_i523++) {
              c7_e_u[c7_i523] = c7_poseBML[c7_i523];
            }

            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c7_e_y);
            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -145);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 87);
            if (CV_EML_IF(2, 1, 5, c7_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 88);
              CV_EML_FCN(2, 11);
              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 181U);
              c7_u_encStr2Arr(chartInstance, c7_dv96);
              for (c7_i524 = 0; c7_i524 < 256; c7_i524++) {
                c7_poseBML[c7_i524] = c7_dv96[c7_i524];
              }

              c7_updateDataWrittenToVector(chartInstance, 12U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c7_i525 = 0; c7_i525 < 256; c7_i525++) {
                c7_f_u[c7_i525] = c7_poseBML[c7_i525];
              }

              c7_f_y = NULL;
              sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_f_y);
              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -181);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 89);
              if (CV_EML_IF(2, 1, 6, c7_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 90);
                CV_EML_FCN(2, 3);
                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 133U);
                c7_r_encStr2Arr(chartInstance, c7_dv96);
                for (c7_i526 = 0; c7_i526 < 256; c7_i526++) {
                  c7_poseBML[c7_i526] = c7_dv96[c7_i526];
                }

                c7_updateDataWrittenToVector(chartInstance, 12U);
                c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c7_i527 = 0; c7_i527 < 256; c7_i527++) {
                  c7_g_u[c7_i527] = c7_poseBML[c7_i527];
                }

                c7_g_y = NULL;
                sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c7_g_y);
                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -133);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 91);
                if (CV_EML_IF(2, 1, 7, c7_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 92);
                  CV_EML_FCN(2, 5);
                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 145U);
                  c7_t_encStr2Arr(chartInstance, c7_dv96);
                  for (c7_i528 = 0; c7_i528 < 256; c7_i528++) {
                    c7_poseBML[c7_i528] = c7_dv96[c7_i528];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 12U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c7_i529 = 0; c7_i529 < 256; c7_i529++) {
                    c7_h_u[c7_i529] = c7_poseBML[c7_i529];
                  }

                  c7_h_y = NULL;
                  sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_h_y);
                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 93);
                  if (CV_EML_IF(2, 1, 8, c7_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 94);
                    CV_EML_FCN(2, 3);
                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 133U);
                    c7_r_encStr2Arr(chartInstance, c7_dv96);
                    for (c7_i530 = 0; c7_i530 < 256; c7_i530++) {
                      c7_poseBML[c7_i530] = c7_dv96[c7_i530];
                    }

                    c7_updateDataWrittenToVector(chartInstance, 12U);
                    c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c7_i531 = 0; c7_i531 < 256; c7_i531++) {
                      c7_i_u[c7_i531] = c7_poseBML[c7_i531];
                    }

                    c7_i_y = NULL;
                    sf_mex_assign(&c7_i_y, sf_mex_create("y", c7_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c7_i_y);
                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 95);
                    if (CV_EML_IF(2, 1, 9, c7_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 96);
                      CV_EML_FCN(2, 10);
                      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 175U);
                      c7_v_encStr2Arr(chartInstance, c7_dv96);
                      for (c7_i532 = 0; c7_i532 < 256; c7_i532++) {
                        c7_poseBML[c7_i532] = c7_dv96[c7_i532];
                      }

                      c7_updateDataWrittenToVector(chartInstance, 12U);
                      c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c7_i533 = 0; c7_i533 < 256; c7_i533++) {
                        c7_j_u[c7_i533] = c7_poseBML[c7_i533];
                      }

                      c7_j_y = NULL;
                      sf_mex_assign(&c7_j_y, sf_mex_create("y", c7_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c7_j_y);
                      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 97);
                      if (CV_EML_IF(2, 1, 10, c7_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 98);
                        CV_EML_FCN(2, 11);
                        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 181U);
                        c7_u_encStr2Arr(chartInstance, c7_dv96);
                        for (c7_i534 = 0; c7_i534 < 256; c7_i534++) {
                          c7_poseBML[c7_i534] = c7_dv96[c7_i534];
                        }

                        c7_updateDataWrittenToVector(chartInstance, 12U);
                        c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c7_i535 = 0; c7_i535 < 256; c7_i535++) {
                          c7_k_u[c7_i535] = c7_poseBML[c7_i535];
                        }

                        c7_k_y = NULL;
                        sf_mex_assign(&c7_k_y, sf_mex_create("y", c7_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c7_k_y);
                        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 99);
                        if (CV_EML_IF(2, 1, 11, c7_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 100);
                          CV_EML_FCN(2, 8);
                          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 163U);
                          c7_w_encStr2Arr(chartInstance, c7_dv96);
                          for (c7_i536 = 0; c7_i536 < 256; c7_i536++) {
                            c7_poseBML[c7_i536] = c7_dv96[c7_i536];
                          }

                          c7_updateDataWrittenToVector(chartInstance, 12U);
                          c7_errorIfDataNotWrittenToFcn(chartInstance, 12U, 38U);
                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c7_i537 = 0; c7_i537 < 256; c7_i537++) {
                            c7_l_u[c7_i537] = c7_poseBML[c7_i537];
                          }

                          c7_l_y = NULL;
                          sf_mex_assign(&c7_l_y, sf_mex_create("y", c7_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c7_l_y);
                          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 101);
                          if (CV_EML_IF(2, 1, 12, c7_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 102);
                            CV_EML_FCN(2, 8);
                            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 163U);
                            c7_w_encStr2Arr(chartInstance, c7_dv96);
                            for (c7_i538 = 0; c7_i538 < 256; c7_i538++) {
                              c7_poseBML[c7_i538] = c7_dv96[c7_i538];
                            }

                            c7_updateDataWrittenToVector(chartInstance, 12U);
                            c7_errorIfDataNotWrittenToFcn(chartInstance, 12U,
                              38U);
                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c7_i539 = 0; c7_i539 < 256; c7_i539++) {
                              c7_m_u[c7_i539] = c7_poseBML[c7_i539];
                            }

                            c7_m_y = NULL;
                            sf_mex_assign(&c7_m_y, sf_mex_create("y", c7_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c7_m_y);
                            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 103);
                            if (CV_EML_IF(2, 1, 13,
                                          c7_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 104);
                              CV_EML_FCN(2, 7);
                              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 157U);
                              c7_x_encStr2Arr(chartInstance, c7_dv96);
                              for (c7_i540 = 0; c7_i540 < 256; c7_i540++) {
                                c7_poseBML[c7_i540] = c7_dv96[c7_i540];
                              }

                              c7_updateDataWrittenToVector(chartInstance, 12U);
                              c7_errorIfDataNotWrittenToFcn(chartInstance, 12U,
                                38U);
                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c7_i541 = 0; c7_i541 < 256; c7_i541++) {
                                c7_n_u[c7_i541] = c7_poseBML[c7_i541];
                              }

                              c7_n_y = NULL;
                              sf_mex_assign(&c7_n_y, sf_mex_create("y", c7_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c7_n_y);
                              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 105);
                              if (CV_EML_IF(2, 1, 14,
                                            c7_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 106);
                                CV_EML_FCN(2, 6);
                                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                              151U);
                                c7_y_encStr2Arr(chartInstance, c7_dv96);
                                for (c7_i542 = 0; c7_i542 < 256; c7_i542++) {
                                  c7_poseBML[c7_i542] = c7_dv96[c7_i542];
                                }

                                c7_updateDataWrittenToVector(chartInstance, 12U);
                                c7_errorIfDataNotWrittenToFcn(chartInstance, 12U,
                                  38U);
                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c7_i543 = 0; c7_i543 < 256; c7_i543++) {
                                  c7_o_u[c7_i543] = c7_poseBML[c7_i543];
                                }

                                c7_o_y = NULL;
                                sf_mex_assign(&c7_o_y, sf_mex_create("y", c7_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c7_o_y);
                                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, 107);
                                if (CV_EML_IF(2, 1, 15,
                                              c7_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                108);
                                  CV_EML_FCN(2, 5);
                                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                145U);
                                  c7_t_encStr2Arr(chartInstance, c7_dv96);
                                  for (c7_i544 = 0; c7_i544 < 256; c7_i544++) {
                                    c7_poseBML[c7_i544] = c7_dv96[c7_i544];
                                  }

                                  c7_updateDataWrittenToVector(chartInstance,
                                    12U);
                                  c7_errorIfDataNotWrittenToFcn(chartInstance,
                                    12U, 38U);
                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c7_i545 = 0; c7_i545 < 256; c7_i545++) {
                                    c7_p_u[c7_i545] = c7_poseBML[c7_i545];
                                  }

                                  c7_p_y = NULL;
                                  sf_mex_assign(&c7_p_y, sf_mex_create("y",
                                    c7_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c7_p_y);
                                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                109);
                                  if (CV_EML_IF(2, 1, 16,
                                                c7_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                  110);
                                    CV_EML_FCN(2, 8);
                                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                  163U);
                                    c7_w_encStr2Arr(chartInstance, c7_dv96);
                                    for (c7_i546 = 0; c7_i546 < 256; c7_i546++)
                                    {
                                      c7_poseBML[c7_i546] = c7_dv96[c7_i546];
                                    }

                                    c7_updateDataWrittenToVector(chartInstance,
                                      12U);
                                    c7_errorIfDataNotWrittenToFcn(chartInstance,
                                      12U, 38U);
                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c7_i547 = 0; c7_i547 < 256; c7_i547++)
                                    {
                                      c7_q_u[c7_i547] = c7_poseBML[c7_i547];
                                    }

                                    c7_q_y = NULL;
                                    sf_mex_assign(&c7_q_y, sf_mex_create("y",
                                      c7_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c7_q_y);
                                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c7_sfEvent,
                                                  111);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c7_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
                                                    112);
                                      CV_EML_FCN(2, 9);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
                                                    169U);
                                      c7_ab_encStr2Arr(chartInstance, c7_dv96);
                                      for (c7_i548 = 0; c7_i548 < 256; c7_i548++)
                                      {
                                        c7_poseBML[c7_i548] = c7_dv96[c7_i548];
                                      }

                                      c7_updateDataWrittenToVector(chartInstance,
                                        12U);
                                      c7_errorIfDataNotWrittenToFcn
                                        (chartInstance, 12U, 38U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c7_i549 = 0; c7_i549 < 256; c7_i549++)
                                      {
                                        c7_r_u[c7_i549] = c7_poseBML[c7_i549];
                                      }

                                      c7_r_y = NULL;
                                      sf_mex_assign(&c7_r_y, sf_mex_create("y",
                                        c7_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c7_r_y);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
                                                    114);
                                      CV_EML_FCN(2, 3);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
                                                    133U);
                                      c7_r_encStr2Arr(chartInstance, c7_dv96);
                                      for (c7_i550 = 0; c7_i550 < 256; c7_i550++)
                                      {
                                        c7_poseBML[c7_i550] = c7_dv96[c7_i550];
                                      }

                                      c7_updateDataWrittenToVector(chartInstance,
                                        12U);
                                      c7_errorIfDataNotWrittenToFcn
                                        (chartInstance, 12U, 38U);
                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c7_i551 = 0; c7_i551 < 256; c7_i551++)
                                      {
                                        c7_s_u[c7_i551] = c7_poseBML[c7_i551];
                                      }

                                      c7_s_y = NULL;
                                      sf_mex_assign(&c7_s_y, sf_mex_create("y",
                                        c7_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c7_s_y);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c7_sfEvent,
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

  _SFD_EML_CALL(2U, chartInstance->c7_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_boredGazec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_gazeBML[256])
{
  uint32_T c7_debug_family_var_map[22];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  boolean_T c7_aVarTruthTableCondition_3;
  boolean_T c7_aVarTruthTableCondition_4;
  boolean_T c7_aVarTruthTableCondition_5;
  boolean_T c7_aVarTruthTableCondition_6;
  boolean_T c7_aVarTruthTableCondition_7;
  boolean_T c7_aVarTruthTableCondition_8;
  boolean_T c7_aVarTruthTableCondition_9;
  boolean_T c7_aVarTruthTableCondition_10;
  boolean_T c7_aVarTruthTableCondition_11;
  boolean_T c7_aVarTruthTableCondition_12;
  boolean_T c7_aVarTruthTableCondition_13;
  boolean_T c7_aVarTruthTableCondition_14;
  boolean_T c7_aVarTruthTableCondition_15;
  boolean_T c7_aVarTruthTableCondition_16;
  boolean_T c7_aVarTruthTableCondition_17;
  boolean_T c7_aVarTruthTableCondition_18;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv97[256];
  int32_T c7_i552;
  int32_T c7_i553;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i554;
  int32_T c7_i555;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i556;
  int32_T c7_i557;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  int32_T c7_i558;
  int32_T c7_i559;
  real_T c7_d_u[256];
  const mxArray *c7_d_y = NULL;
  int32_T c7_i560;
  int32_T c7_i561;
  real_T c7_e_u[256];
  const mxArray *c7_e_y = NULL;
  int32_T c7_i562;
  int32_T c7_i563;
  real_T c7_f_u[256];
  const mxArray *c7_f_y = NULL;
  int32_T c7_i564;
  int32_T c7_i565;
  real_T c7_g_u[256];
  const mxArray *c7_g_y = NULL;
  int32_T c7_i566;
  int32_T c7_i567;
  real_T c7_h_u[256];
  const mxArray *c7_h_y = NULL;
  int32_T c7_i568;
  int32_T c7_i569;
  real_T c7_i_u[256];
  const mxArray *c7_i_y = NULL;
  int32_T c7_i570;
  int32_T c7_i571;
  real_T c7_j_u[256];
  const mxArray *c7_j_y = NULL;
  int32_T c7_i572;
  int32_T c7_i573;
  real_T c7_k_u[256];
  const mxArray *c7_k_y = NULL;
  int32_T c7_i574;
  int32_T c7_i575;
  real_T c7_l_u[256];
  const mxArray *c7_l_y = NULL;
  int32_T c7_i576;
  int32_T c7_i577;
  real_T c7_m_u[256];
  const mxArray *c7_m_y = NULL;
  int32_T c7_i578;
  int32_T c7_i579;
  real_T c7_n_u[256];
  const mxArray *c7_n_y = NULL;
  int32_T c7_i580;
  int32_T c7_i581;
  real_T c7_o_u[256];
  const mxArray *c7_o_y = NULL;
  int32_T c7_i582;
  int32_T c7_i583;
  real_T c7_p_u[256];
  const mxArray *c7_p_y = NULL;
  int32_T c7_i584;
  int32_T c7_i585;
  real_T c7_q_u[256];
  const mxArray *c7_q_y = NULL;
  int32_T c7_i586;
  int32_T c7_i587;
  real_T c7_r_u[256];
  const mxArray *c7_r_y = NULL;
  int32_T c7_i588;
  int32_T c7_i589;
  real_T c7_s_u[256];
  const mxArray *c7_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c7_kb_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_3, 2U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_4, 3U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_5, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_6, 5U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_7, 6U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_8, 7U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_9, 8U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_10, 9U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_11, 10U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_12, 11U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_13, 12U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_14, 13U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_15, 14U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_16, 15U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_17, 16U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_18, 17U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 18U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 19U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 20U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_gazeBML, 21U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  c7_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  c7_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  c7_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  c7_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  c7_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  c7_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
  c7_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
  c7_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
  c7_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
  c7_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 30);
  c7_aVarTruthTableCondition_3 = (c7_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 33);
  c7_aVarTruthTableCondition_4 = (c7_bmlID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 36);
  c7_aVarTruthTableCondition_5 = (c7_bmlID == 5.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 39);
  c7_aVarTruthTableCondition_6 = (c7_bmlID == 6.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 42);
  c7_aVarTruthTableCondition_7 = (c7_bmlID == 7.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 45);
  c7_aVarTruthTableCondition_8 = (c7_bmlID == 8.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 48);
  c7_aVarTruthTableCondition_9 = (c7_bmlID == 9.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 51);
  c7_aVarTruthTableCondition_10 = (c7_bmlID == 10.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 54);
  c7_aVarTruthTableCondition_11 = (c7_bmlID == 11.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 57);
  c7_aVarTruthTableCondition_12 = (c7_bmlID == 12.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 60);
  c7_aVarTruthTableCondition_13 = (c7_bmlID == 13.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 63);
  c7_aVarTruthTableCondition_14 = (c7_bmlID == 14.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 66);
  c7_aVarTruthTableCondition_15 = (c7_bmlID == 15.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 69);
  c7_aVarTruthTableCondition_16 = (c7_bmlID == 16.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 72);
  c7_aVarTruthTableCondition_17 = (c7_bmlID == 17.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 75);
  c7_aVarTruthTableCondition_18 = (c7_bmlID == 18.0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 77);
  if (CV_EML_IF(0, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 78);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 121);
    c7_bb_encStr2Arr(chartInstance, c7_dv97);
    for (c7_i552 = 0; c7_i552 < 256; c7_i552++) {
      c7_gazeBML[c7_i552] = c7_dv97[c7_i552];
    }

    c7_updateDataWrittenToVector(chartInstance, 13U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
    sf_mex_printf("%s =\\n", "gazeBML");
    for (c7_i553 = 0; c7_i553 < 256; c7_i553++) {
      c7_u[c7_i553] = c7_gazeBML[c7_i553];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -121);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 79);
    if (CV_EML_IF(0, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 80);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, MAX_int8_T);
      c7_cb_encStr2Arr(chartInstance, c7_dv97);
      for (c7_i554 = 0; c7_i554 < 256; c7_i554++) {
        c7_gazeBML[c7_i554] = c7_dv97[c7_i554];
      }

      c7_updateDataWrittenToVector(chartInstance, 13U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
      sf_mex_printf("%s =\\n", "gazeBML");
      for (c7_i555 = 0; c7_i555 < 256; c7_i555++) {
        c7_b_u[c7_i555] = c7_gazeBML[c7_i555];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -127);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 81);
      if (CV_EML_IF(0, 1, 2, c7_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 82);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 133U);
        c7_db_encStr2Arr(chartInstance, c7_dv97);
        for (c7_i556 = 0; c7_i556 < 256; c7_i556++) {
          c7_gazeBML[c7_i556] = c7_dv97[c7_i556];
        }

        c7_updateDataWrittenToVector(chartInstance, 13U);
        c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
        sf_mex_printf("%s =\\n", "gazeBML");
        for (c7_i557 = 0; c7_i557 < 256; c7_i557++) {
          c7_c_u[c7_i557] = c7_gazeBML[c7_i557];
        }

        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -133);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 83);
        if (CV_EML_IF(0, 1, 3, c7_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 84);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 139U);
          c7_eb_encStr2Arr(chartInstance, c7_dv97);
          for (c7_i558 = 0; c7_i558 < 256; c7_i558++) {
            c7_gazeBML[c7_i558] = c7_dv97[c7_i558];
          }

          c7_updateDataWrittenToVector(chartInstance, 13U);
          c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
          sf_mex_printf("%s =\\n", "gazeBML");
          for (c7_i559 = 0; c7_i559 < 256; c7_i559++) {
            c7_d_u[c7_i559] = c7_gazeBML[c7_i559];
          }

          c7_d_y = NULL;
          sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c7_d_y);
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -139);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 85);
          if (CV_EML_IF(0, 1, 4, c7_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 86);
            CV_EML_FCN(0, 5);
            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 145U);
            c7_fb_encStr2Arr(chartInstance, c7_dv97);
            for (c7_i560 = 0; c7_i560 < 256; c7_i560++) {
              c7_gazeBML[c7_i560] = c7_dv97[c7_i560];
            }

            c7_updateDataWrittenToVector(chartInstance, 13U);
            c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
            sf_mex_printf("%s =\\n", "gazeBML");
            for (c7_i561 = 0; c7_i561 < 256; c7_i561++) {
              c7_e_u[c7_i561] = c7_gazeBML[c7_i561];
            }

            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c7_e_y);
            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -145);
          } else {
            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 87);
            if (CV_EML_IF(0, 1, 5, c7_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 88);
              CV_EML_FCN(0, 6);
              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 151U);
              c7_gb_encStr2Arr(chartInstance, c7_dv97);
              for (c7_i562 = 0; c7_i562 < 256; c7_i562++) {
                c7_gazeBML[c7_i562] = c7_dv97[c7_i562];
              }

              c7_updateDataWrittenToVector(chartInstance, 13U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
              sf_mex_printf("%s =\\n", "gazeBML");
              for (c7_i563 = 0; c7_i563 < 256; c7_i563++) {
                c7_f_u[c7_i563] = c7_gazeBML[c7_i563];
              }

              c7_f_y = NULL;
              sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_f_y);
              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -151);
            } else {
              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 89);
              if (CV_EML_IF(0, 1, 6, c7_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 90);
                CV_EML_FCN(0, 7);
                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 157U);
                c7_hb_encStr2Arr(chartInstance, c7_dv97);
                for (c7_i564 = 0; c7_i564 < 256; c7_i564++) {
                  c7_gazeBML[c7_i564] = c7_dv97[c7_i564];
                }

                c7_updateDataWrittenToVector(chartInstance, 13U);
                c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                sf_mex_printf("%s =\\n", "gazeBML");
                for (c7_i565 = 0; c7_i565 < 256; c7_i565++) {
                  c7_g_u[c7_i565] = c7_gazeBML[c7_i565];
                }

                c7_g_y = NULL;
                sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c7_g_y);
                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -157);
              } else {
                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 91);
                if (CV_EML_IF(0, 1, 7, c7_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 92);
                  CV_EML_FCN(0, 8);
                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 163U);
                  c7_ib_encStr2Arr(chartInstance, c7_dv97);
                  for (c7_i566 = 0; c7_i566 < 256; c7_i566++) {
                    c7_gazeBML[c7_i566] = c7_dv97[c7_i566];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 13U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c7_i567 = 0; c7_i567 < 256; c7_i567++) {
                    c7_h_u[c7_i567] = c7_gazeBML[c7_i567];
                  }

                  c7_h_y = NULL;
                  sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_h_y);
                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -163);
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 93);
                  if (CV_EML_IF(0, 1, 8, c7_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 94);
                    CV_EML_FCN(0, 9);
                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 169U);
                    c7_jb_encStr2Arr(chartInstance, c7_dv97);
                    for (c7_i568 = 0; c7_i568 < 256; c7_i568++) {
                      c7_gazeBML[c7_i568] = c7_dv97[c7_i568];
                    }

                    c7_updateDataWrittenToVector(chartInstance, 13U);
                    c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c7_i569 = 0; c7_i569 < 256; c7_i569++) {
                      c7_i_u[c7_i569] = c7_gazeBML[c7_i569];
                    }

                    c7_i_y = NULL;
                    sf_mex_assign(&c7_i_y, sf_mex_create("y", c7_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c7_i_y);
                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -169);
                  } else {
                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 95);
                    if (CV_EML_IF(0, 1, 9, c7_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 96);
                      CV_EML_FCN(0, 10);
                      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 175U);
                      c7_kb_encStr2Arr(chartInstance, c7_dv97);
                      for (c7_i570 = 0; c7_i570 < 256; c7_i570++) {
                        c7_gazeBML[c7_i570] = c7_dv97[c7_i570];
                      }

                      c7_updateDataWrittenToVector(chartInstance, 13U);
                      c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c7_i571 = 0; c7_i571 < 256; c7_i571++) {
                        c7_j_u[c7_i571] = c7_gazeBML[c7_i571];
                      }

                      c7_j_y = NULL;
                      sf_mex_assign(&c7_j_y, sf_mex_create("y", c7_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c7_j_y);
                      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 97);
                      if (CV_EML_IF(0, 1, 10, c7_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 98);
                        CV_EML_FCN(0, 11);
                        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 181U);
                        c7_lb_encStr2Arr(chartInstance, c7_dv97);
                        for (c7_i572 = 0; c7_i572 < 256; c7_i572++) {
                          c7_gazeBML[c7_i572] = c7_dv97[c7_i572];
                        }

                        c7_updateDataWrittenToVector(chartInstance, 13U);
                        c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c7_i573 = 0; c7_i573 < 256; c7_i573++) {
                          c7_k_u[c7_i573] = c7_gazeBML[c7_i573];
                        }

                        c7_k_y = NULL;
                        sf_mex_assign(&c7_k_y, sf_mex_create("y", c7_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c7_k_y);
                        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 99);
                        if (CV_EML_IF(0, 1, 11, c7_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 100);
                          CV_EML_FCN(0, 12);
                          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 187U);
                          c7_mb_encStr2Arr(chartInstance, c7_dv97);
                          for (c7_i574 = 0; c7_i574 < 256; c7_i574++) {
                            c7_gazeBML[c7_i574] = c7_dv97[c7_i574];
                          }

                          c7_updateDataWrittenToVector(chartInstance, 13U);
                          c7_errorIfDataNotWrittenToFcn(chartInstance, 13U, 40U);
                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c7_i575 = 0; c7_i575 < 256; c7_i575++) {
                            c7_l_u[c7_i575] = c7_gazeBML[c7_i575];
                          }

                          c7_l_y = NULL;
                          sf_mex_assign(&c7_l_y, sf_mex_create("y", c7_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c7_l_y);
                          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -187);
                        } else {
                          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 101);
                          if (CV_EML_IF(0, 1, 12, c7_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 102);
                            CV_EML_FCN(0, 13);
                            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 193U);
                            c7_nb_encStr2Arr(chartInstance, c7_dv97);
                            for (c7_i576 = 0; c7_i576 < 256; c7_i576++) {
                              c7_gazeBML[c7_i576] = c7_dv97[c7_i576];
                            }

                            c7_updateDataWrittenToVector(chartInstance, 13U);
                            c7_errorIfDataNotWrittenToFcn(chartInstance, 13U,
                              40U);
                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c7_i577 = 0; c7_i577 < 256; c7_i577++) {
                              c7_m_u[c7_i577] = c7_gazeBML[c7_i577];
                            }

                            c7_m_y = NULL;
                            sf_mex_assign(&c7_m_y, sf_mex_create("y", c7_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c7_m_y);
                            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -193);
                          } else {
                            _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 103);
                            if (CV_EML_IF(0, 1, 13,
                                          c7_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 104);
                              CV_EML_FCN(0, 14);
                              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 199U);
                              c7_ob_encStr2Arr(chartInstance, c7_dv97);
                              for (c7_i578 = 0; c7_i578 < 256; c7_i578++) {
                                c7_gazeBML[c7_i578] = c7_dv97[c7_i578];
                              }

                              c7_updateDataWrittenToVector(chartInstance, 13U);
                              c7_errorIfDataNotWrittenToFcn(chartInstance, 13U,
                                40U);
                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c7_i579 = 0; c7_i579 < 256; c7_i579++) {
                                c7_n_u[c7_i579] = c7_gazeBML[c7_i579];
                              }

                              c7_n_y = NULL;
                              sf_mex_assign(&c7_n_y, sf_mex_create("y", c7_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c7_n_y);
                              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -199);
                            } else {
                              _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 105);
                              if (CV_EML_IF(0, 1, 14,
                                            c7_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 106);
                                CV_EML_FCN(0, 15);
                                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                              205U);
                                c7_pb_encStr2Arr(chartInstance, c7_dv97);
                                for (c7_i580 = 0; c7_i580 < 256; c7_i580++) {
                                  c7_gazeBML[c7_i580] = c7_dv97[c7_i580];
                                }

                                c7_updateDataWrittenToVector(chartInstance, 13U);
                                c7_errorIfDataNotWrittenToFcn(chartInstance, 13U,
                                  40U);
                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c7_i581 = 0; c7_i581 < 256; c7_i581++) {
                                  c7_o_u[c7_i581] = c7_gazeBML[c7_i581];
                                }

                                c7_o_y = NULL;
                                sf_mex_assign(&c7_o_y, sf_mex_create("y", c7_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c7_o_y);
                                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                              -205);
                              } else {
                                _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 107);
                                if (CV_EML_IF(0, 1, 15,
                                              c7_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                108);
                                  CV_EML_FCN(0, 16);
                                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                211U);
                                  c7_qb_encStr2Arr(chartInstance, c7_dv97);
                                  for (c7_i582 = 0; c7_i582 < 256; c7_i582++) {
                                    c7_gazeBML[c7_i582] = c7_dv97[c7_i582];
                                  }

                                  c7_updateDataWrittenToVector(chartInstance,
                                    13U);
                                  c7_errorIfDataNotWrittenToFcn(chartInstance,
                                    13U, 40U);
                                  sf_mex_printf("%s =\\n", "gazeBML");
                                  for (c7_i583 = 0; c7_i583 < 256; c7_i583++) {
                                    c7_p_u[c7_i583] = c7_gazeBML[c7_i583];
                                  }

                                  c7_p_y = NULL;
                                  sf_mex_assign(&c7_p_y, sf_mex_create("y",
                                    c7_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c7_p_y);
                                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                -211);
                                } else {
                                  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                109);
                                  if (CV_EML_IF(0, 1, 16,
                                                c7_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                  110);
                                    CV_EML_FCN(0, 19);
                                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                  229U);
                                    c7_rb_encStr2Arr(chartInstance, c7_dv97);
                                    for (c7_i584 = 0; c7_i584 < 256; c7_i584++)
                                    {
                                      c7_gazeBML[c7_i584] = c7_dv97[c7_i584];
                                    }

                                    c7_updateDataWrittenToVector(chartInstance,
                                      13U);
                                    c7_errorIfDataNotWrittenToFcn(chartInstance,
                                      13U, 40U);
                                    sf_mex_printf("%s =\\n", "gazeBML");
                                    for (c7_i585 = 0; c7_i585 < 256; c7_i585++)
                                    {
                                      c7_q_u[c7_i585] = c7_gazeBML[c7_i585];
                                    }

                                    c7_q_y = NULL;
                                    sf_mex_assign(&c7_q_y, sf_mex_create("y",
                                      c7_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c7_q_y);
                                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                  -229);
                                  } else {
                                    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent,
                                                  111);
                                    if (CV_EML_IF(0, 1, 17,
                                                  c7_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
                                                    112);
                                      CV_EML_FCN(0, 26);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
                                                    271);
                                      c7_sb_encStr2Arr(chartInstance, c7_dv97);
                                      for (c7_i586 = 0; c7_i586 < 256; c7_i586++)
                                      {
                                        c7_gazeBML[c7_i586] = c7_dv97[c7_i586];
                                      }

                                      c7_updateDataWrittenToVector(chartInstance,
                                        13U);
                                      c7_errorIfDataNotWrittenToFcn
                                        (chartInstance, 13U, 40U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c7_i587 = 0; c7_i587 < 256; c7_i587++)
                                      {
                                        c7_r_u[c7_i587] = c7_gazeBML[c7_i587];
                                      }

                                      c7_r_y = NULL;
                                      sf_mex_assign(&c7_r_y, sf_mex_create("y",
                                        c7_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c7_r_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
                                                    -271);
                                    } else {
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
                                                    114);
                                      CV_EML_FCN(0, 1);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
                                                    121);
                                      c7_bb_encStr2Arr(chartInstance, c7_dv97);
                                      for (c7_i588 = 0; c7_i588 < 256; c7_i588++)
                                      {
                                        c7_gazeBML[c7_i588] = c7_dv97[c7_i588];
                                      }

                                      c7_updateDataWrittenToVector(chartInstance,
                                        13U);
                                      c7_errorIfDataNotWrittenToFcn
                                        (chartInstance, 13U, 40U);
                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c7_i589 = 0; c7_i589 < 256; c7_i589++)
                                      {
                                        c7_s_u[c7_i589] = c7_gazeBML[c7_i589];
                                      }

                                      c7_s_y = NULL;
                                      sf_mex_assign(&c7_s_y, sf_mex_create("y",
                                        c7_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c7_s_y);
                                      _SFD_EML_CALL(0U,
                                                    chartInstance->c7_sfEvent,
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

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_boredPosec7_ARP_02_RPSsmile_GloveAtomic
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, real_T
   c7_bmlID, real_T c7_poseBML[256])
{
  uint32_T c7_debug_family_var_map[12];
  boolean_T c7_aVarTruthTableCondition_1;
  boolean_T c7_aVarTruthTableCondition_2;
  boolean_T c7_aVarTruthTableCondition_3;
  boolean_T c7_aVarTruthTableCondition_4;
  boolean_T c7_aVarTruthTableCondition_5;
  boolean_T c7_aVarTruthTableCondition_6;
  boolean_T c7_aVarTruthTableCondition_7;
  boolean_T c7_aVarTruthTableCondition_8;
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_dv98[256];
  int32_T c7_i590;
  int32_T c7_i591;
  real_T c7_u[256];
  const mxArray *c7_y = NULL;
  int32_T c7_i592;
  int32_T c7_i593;
  real_T c7_b_u[256];
  const mxArray *c7_b_y = NULL;
  int32_T c7_i594;
  int32_T c7_i595;
  real_T c7_c_u[256];
  const mxArray *c7_c_y = NULL;
  int32_T c7_i596;
  int32_T c7_i597;
  real_T c7_d_u[256];
  const mxArray *c7_d_y = NULL;
  int32_T c7_i598;
  int32_T c7_i599;
  real_T c7_e_u[256];
  const mxArray *c7_e_y = NULL;
  uint32_T c7_b_debug_family_var_map[9];
  real_T c7_maxarrsize;
  real_T c7_arr[114];
  real_T c7_ss;
  real_T c7_padsize;
  real_T c7_tt[256];
  char_T c7_mystr[114];
  real_T c7_b_nargin = 1.0;
  real_T c7_b_nargout = 1.0;
  real_T c7_myarr256[256];
  int32_T c7_i600;
  static char_T c7_cv54[114] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c7_i601;
  static real_T c7_dv99[114] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c7_i602;
  int32_T c7_i603;
  int32_T c7_i604;
  int32_T c7_i605;
  int32_T c7_i606;
  real_T c7_f_u[256];
  const mxArray *c7_f_y = NULL;
  int32_T c7_i607;
  int32_T c7_i608;
  real_T c7_g_u[256];
  const mxArray *c7_g_y = NULL;
  int32_T c7_i609;
  int32_T c7_i610;
  real_T c7_h_u[256];
  const mxArray *c7_h_y = NULL;
  int32_T c7_i611;
  int32_T c7_i612;
  real_T c7_i_u[256];
  const mxArray *c7_i_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c7_ec_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_1, 0U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_2, 1U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_3, 2U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_4, 3U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_5, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_6, 5U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_7, 6U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_aVarTruthTableCondition_8, 7U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 8U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 9U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_bmlID, 10U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_poseBML, 11U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 3);
  c7_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 4);
  c7_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 5);
  c7_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 6);
  c7_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 7);
  c7_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 8);
  c7_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 9);
  c7_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 10);
  c7_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 14);
  c7_aVarTruthTableCondition_1 = (c7_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 17);
  c7_aVarTruthTableCondition_2 = (c7_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 20);
  c7_aVarTruthTableCondition_3 = (c7_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 23);
  c7_aVarTruthTableCondition_4 = (c7_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 26);
  c7_aVarTruthTableCondition_5 = (c7_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 29);
  c7_aVarTruthTableCondition_6 = (c7_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 32);
  c7_aVarTruthTableCondition_7 = (c7_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 35);
  c7_aVarTruthTableCondition_8 = (c7_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 37);
  if (CV_EML_IF(1, 1, 0, c7_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 38);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 61);
    c7_tb_encStr2Arr(chartInstance, c7_dv98);
    for (c7_i590 = 0; c7_i590 < 256; c7_i590++) {
      c7_poseBML[c7_i590] = c7_dv98[c7_i590];
    }

    c7_updateDataWrittenToVector(chartInstance, 14U);
    c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c7_i591 = 0; c7_i591 < 256; c7_i591++) {
      c7_u[c7_i591] = c7_poseBML[c7_i591];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_y);
    _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -61);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 39);
    if (CV_EML_IF(1, 1, 1, c7_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 40);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 67);
      c7_ub_encStr2Arr(chartInstance, c7_dv98);
      for (c7_i592 = 0; c7_i592 < 256; c7_i592++) {
        c7_poseBML[c7_i592] = c7_dv98[c7_i592];
      }

      c7_updateDataWrittenToVector(chartInstance, 14U);
      c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c7_i593 = 0; c7_i593 < 256; c7_i593++) {
        c7_b_u[c7_i593] = c7_poseBML[c7_i593];
      }

      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c7_b_y);
      _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -67);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 41);
      if (CV_EML_IF(1, 1, 2, c7_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 42);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 73);
        c7_vb_encStr2Arr(chartInstance, c7_dv98);
        for (c7_i594 = 0; c7_i594 < 256; c7_i594++) {
          c7_poseBML[c7_i594] = c7_dv98[c7_i594];
        }

        c7_updateDataWrittenToVector(chartInstance, 14U);
        c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c7_i595 = 0; c7_i595 < 256; c7_i595++) {
          c7_c_u[c7_i595] = c7_poseBML[c7_i595];
        }

        c7_c_y = NULL;
        sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c7_c_y);
        _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -73);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 43);
        if (CV_EML_IF(1, 1, 3, c7_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 44);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 79);
          c7_wb_encStr2Arr(chartInstance, c7_dv98);
          for (c7_i596 = 0; c7_i596 < 256; c7_i596++) {
            c7_poseBML[c7_i596] = c7_dv98[c7_i596];
          }

          c7_updateDataWrittenToVector(chartInstance, 14U);
          c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c7_i597 = 0; c7_i597 < 256; c7_i597++) {
            c7_d_u[c7_i597] = c7_poseBML[c7_i597];
          }

          c7_d_y = NULL;
          sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c7_d_y);
          _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -79);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 45);
          if (CV_EML_IF(1, 1, 4, c7_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 46);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 85);
            c7_xb_encStr2Arr(chartInstance, c7_dv98);
            for (c7_i598 = 0; c7_i598 < 256; c7_i598++) {
              c7_poseBML[c7_i598] = c7_dv98[c7_i598];
            }

            c7_updateDataWrittenToVector(chartInstance, 14U);
            c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c7_i599 = 0; c7_i599 < 256; c7_i599++) {
              c7_e_u[c7_i599] = c7_poseBML[c7_i599];
            }

            c7_e_y = NULL;
            sf_mex_assign(&c7_e_y, sf_mex_create("y", c7_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c7_e_y);
            _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -85);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 47);
            if (CV_EML_IF(1, 1, 5, c7_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 48);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 91);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_kc_debug_family_names,
                c7_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_maxarrsize, 0U,
                c7_b_sf_marshallOut, c7_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c7_arr, 1U, c7_id_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML(&c7_ss, 2U, c7_b_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_padsize, 3U,
                c7_b_sf_marshallOut, c7_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_tt, 4U,
                c7_d_sf_marshallOut, c7_d_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML(c7_mystr, 5U, c7_hd_sf_marshallOut);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 6U,
                c7_b_sf_marshallOut, c7_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 7U,
                c7_b_sf_marshallOut, c7_b_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_myarr256, 8U,
                c7_d_sf_marshallOut, c7_d_sf_marshallIn);
              for (c7_i600 = 0; c7_i600 < 114; c7_i600++) {
                c7_mystr[c7_i600] = c7_cv54[c7_i600];
              }

              CV_SCRIPT_FCN(0, 0);
              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 3);
              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 4);
              c7_maxarrsize = 256.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 6);
              for (c7_i601 = 0; c7_i601 < 114; c7_i601++) {
                c7_arr[c7_i601] = c7_dv99[c7_i601];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 7);
              c7_ss = 114.0;
              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 8);
              c7_padsize = c7_maxarrsize - c7_ss;
              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 9);
              for (c7_i602 = 0; c7_i602 < 256; c7_i602++) {
                c7_tt[c7_i602] = 0.0;
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 10);
              for (c7_i603 = 0; c7_i603 < 114; c7_i603++) {
                c7_tt[c7_i603] = c7_arr[c7_i603];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, 11);
              for (c7_i604 = 0; c7_i604 < 256; c7_i604++) {
                c7_myarr256[c7_i604] = c7_tt[c7_i604];
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c7_sfEvent, -11);
              _SFD_SYMBOL_SCOPE_POP();
              for (c7_i605 = 0; c7_i605 < 256; c7_i605++) {
                c7_poseBML[c7_i605] = c7_myarr256[c7_i605];
              }

              c7_updateDataWrittenToVector(chartInstance, 14U);
              c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c7_i606 = 0; c7_i606 < 256; c7_i606++) {
                c7_f_u[c7_i606] = c7_poseBML[c7_i606];
              }

              c7_f_y = NULL;
              sf_mex_assign(&c7_f_y, sf_mex_create("y", c7_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c7_f_y);
              _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -91);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 49);
              if (CV_EML_IF(1, 1, 6, c7_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 50);
                CV_EML_FCN(1, 3);
                _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 73);
                c7_vb_encStr2Arr(chartInstance, c7_dv98);
                for (c7_i607 = 0; c7_i607 < 256; c7_i607++) {
                  c7_poseBML[c7_i607] = c7_dv98[c7_i607];
                }

                c7_updateDataWrittenToVector(chartInstance, 14U);
                c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c7_i608 = 0; c7_i608 < 256; c7_i608++) {
                  c7_g_u[c7_i608] = c7_poseBML[c7_i608];
                }

                c7_g_y = NULL;
                sf_mex_assign(&c7_g_y, sf_mex_create("y", c7_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c7_g_y);
                _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -73);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 51);
                if (CV_EML_IF(1, 1, 7, c7_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 52);
                  CV_EML_FCN(1, 5);
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 85);
                  c7_xb_encStr2Arr(chartInstance, c7_dv98);
                  for (c7_i609 = 0; c7_i609 < 256; c7_i609++) {
                    c7_poseBML[c7_i609] = c7_dv98[c7_i609];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 14U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c7_i610 = 0; c7_i610 < 256; c7_i610++) {
                    c7_h_u[c7_i610] = c7_poseBML[c7_i610];
                  }

                  c7_h_y = NULL;
                  sf_mex_assign(&c7_h_y, sf_mex_create("y", c7_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_h_y);
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -85);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 54);
                  CV_EML_FCN(1, 3);
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, 73);
                  c7_vb_encStr2Arr(chartInstance, c7_dv98);
                  for (c7_i611 = 0; c7_i611 < 256; c7_i611++) {
                    c7_poseBML[c7_i611] = c7_dv98[c7_i611];
                  }

                  c7_updateDataWrittenToVector(chartInstance, 14U);
                  c7_errorIfDataNotWrittenToFcn(chartInstance, 14U, 42U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c7_i612 = 0; c7_i612 < 256; c7_i612++) {
                    c7_i_u[c7_i612] = c7_poseBML[c7_i612];
                  }

                  c7_i_y = NULL;
                  sf_mex_assign(&c7_i_y, sf_mex_create("y", c7_i_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c7_i_y);
                  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -73);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c7_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_sendSBM(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c7_b_sendSBM(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static void c7_sendBML(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void c7_b_sendBML(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_boredGaze(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_gazeBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_boredGazec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID, c7_gazeBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_boredPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_boredPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID, c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_boredPoseS(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_boredPoseSc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID,
    c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_handPoseSB(SimStruct *c7_S,
  real_T c7_sbmID, real_T c7_poseSBM[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_handPoseSBc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_sbmID,
    c7_poseSBM);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_idlePose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_idlePosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID, c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_paperPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_paperPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID, c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_rockPose(SimStruct *c7_S,
  real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_rockPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID, c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_scissorsPose(SimStruct
  *c7_S, real_T c7_bmlID, real_T c7_poseBML[256])
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  c7_scissorsPosec7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_bmlID,
    c7_poseBML);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_sendBML(SimStruct *c7_S,
  real_T c7_arg[256])
{
  int32_T c7_i613;
  real_T c7_b_arg[256];
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  for (c7_i613 = 0; c7_i613 < 256; c7_i613++) {
    c7_b_arg[c7_i613] = c7_arg[c7_i613];
  }

  c7_sendBMLc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_b_arg);
}

void sf_exported_user_c7_ARP_02_RPSsmile_GloveAtomic_sendSBM(SimStruct *c7_S,
  real_T c7_arg[256])
{
  int32_T c7_i614;
  real_T c7_b_arg[256];
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c7_S))->instanceInfo
    )->chartInstance;
  for (c7_i614 = 0; c7_i614 < 256; c7_i614++) {
    c7_b_arg[c7_i614] = c7_arg[c7_i614];
  }

  c7_sendSBMc7_ARP_02_RPSsmile_GloveAtomic(chartInstance, c7_b_arg);
}

static const mxArray *c7_jd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int8_T c7_f_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int8_T c7_y;
  int8_T c7_i615;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i615, 1, 2, 0U, 0, 0U, 0);
  c7_y = c7_i615;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_secs;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int8_T c7_y;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_secs = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_secs), &c7_thisId);
  sf_mex_destroy(&c7_secs);
  *(int8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_kd_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_g_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i616;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i616, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i616;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_ld_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static uint8_T c7_h_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_tp_stateStart, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_stateStart),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_stateStart);
  return c7_y;
}

static uint8_T c7_i_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u3;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u3, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u3;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_tp_stateStart;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c7_b_tp_stateStart = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_stateStart),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_stateStart);
  *(uint8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint32_T c7_j_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_method, const char_T *c7_identifier)
{
  uint32_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_method),
    &c7_thisId);
  sf_mex_destroy(&c7_b_method);
  return c7_y;
}

static uint32_T c7_k_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint32_T c7_y;
  uint32_T c7_u4;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_method_not_empty = false;
  } else {
    chartInstance->c7_method_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u4, 1, 7, 0U, 0, 0U, 0);
    c7_y = c7_u4;
  }

  sf_mex_destroy(&c7_u);
  return c7_y;
}

static uint32_T c7_l_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_d_state, const char_T *c7_identifier)
{
  uint32_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_d_state), &c7_thisId);
  sf_mex_destroy(&c7_d_state);
  return c7_y;
}

static uint32_T c7_m_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint32_T c7_y;
  uint32_T c7_u5;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_state_not_empty = false;
  } else {
    chartInstance->c7_state_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u5, 1, 7, 0U, 0, 0U, 0);
    c7_y = c7_u5;
  }

  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_n_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_d_state, const char_T *c7_identifier,
  uint32_T c7_y[625])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_d_state), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_d_state);
}

static void c7_o_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint32_T c7_y[625])
{
  uint32_T c7_uv3[625];
  int32_T c7_i617;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_c_state_not_empty = false;
  } else {
    chartInstance->c7_c_state_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c7_i617 = 0; c7_i617 < 625; c7_i617++) {
      c7_y[c7_i617] = c7_uv3[c7_i617];
    }
  }

  sf_mex_destroy(&c7_u);
}

static void c7_p_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_d_state, const char_T *c7_identifier,
  uint32_T c7_y[2])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_d_state), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_d_state);
}

static void c7_q_emlrt_marshallIn(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  uint32_T c7_y[2])
{
  uint32_T c7_uv4[2];
  int32_T c7_i618;
  if (mxIsEmpty(c7_u)) {
    chartInstance->c7_b_state_not_empty = false;
  } else {
    chartInstance->c7_b_state_not_empty = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c7_i618 = 0; c7_i618 < 2; c7_i618++) {
      c7_y[c7_i618] = c7_uv4[c7_i618];
    }
  }

  sf_mex_destroy(&c7_u);
}

static const mxArray *c7_r_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_b_setSimStateSideEffectsInfo, const char_T *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  sf_mex_assign(&c7_y, c7_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), false);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_s_emlrt_marshallIn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  (void)c7_parentId;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), false);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_updateDataWrittenToVector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_vectorIndex)
{
  (void)chartInstance;
  c7_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c7_vectorIndex, 0, 14, 1, 0)] = true;
}

static void c7_errorIfDataNotWrittenToFcn
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_vectorIndex, uint32_T c7_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c7_dataNumber, c7_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c7_vectorIndex, 0, 14, 1,
    0)]);
}

static void c7_b_twister_state_vector
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_mt[625], real_T c7_seed)
{
  real_T c7_d5;
  uint32_T c7_u6;
  uint32_T c7_r;
  int32_T c7_mti;
  real_T c7_b_mti;
  real_T c7_d6;
  uint32_T c7_u7;
  (void)chartInstance;
  c7_d5 = c7_seed;
  if (c7_d5 < 4.294967296E+9) {
    if (c7_d5 >= 0.0) {
      c7_u6 = (uint32_T)c7_d5;
    } else {
      c7_u6 = 0U;
    }
  } else if (c7_d5 >= 4.294967296E+9) {
    c7_u6 = MAX_uint32_T;
  } else {
    c7_u6 = 0U;
  }

  c7_r = c7_u6;
  c7_mt[0] = c7_r;
  for (c7_mti = 0; c7_mti < 623; c7_mti++) {
    c7_b_mti = 2.0 + (real_T)c7_mti;
    c7_d6 = muDoubleScalarRound(c7_b_mti - 1.0);
    if (c7_d6 < 4.294967296E+9) {
      if (c7_d6 >= 0.0) {
        c7_u7 = (uint32_T)c7_d6;
      } else {
        c7_u7 = 0U;
      }
    } else if (c7_d6 >= 4.294967296E+9) {
      c7_u7 = MAX_uint32_T;
    } else {
      c7_u7 = 0U;
    }

    c7_r = (c7_r ^ c7_r >> 30U) * 1812433253U + c7_u7;
    c7_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c7_b_mti), 1, 625, 1, 0) - 1] = c7_r;
  }

  c7_mt[624] = 624U;
}

static real_T c7_c_eml_rand_mt19937ar
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T
   c7_d_state[625])
{
  int32_T c7_i619;
  uint32_T c7_u[2];
  int32_T c7_j;
  real_T c7_b_j;
  uint32_T c7_mti;
  int32_T c7_kk;
  real_T c7_b_kk;
  uint32_T c7_y;
  uint32_T c7_b_y;
  uint32_T c7_c_y;
  int32_T c7_c_kk;
  uint32_T c7_d_y;
  uint32_T c7_e_y;
  uint32_T c7_f_y;
  uint32_T c7_g_y;
  real_T c7_b_r;
  boolean_T c7_b1;
  boolean_T c7_isvalid;
  int32_T c7_k;
  int32_T c7_a;
  int32_T c7_b_a;
  real_T c7_d7;
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
    for (c7_i619 = 0; c7_i619 < 2; c7_i619++) {
      c7_u[c7_i619] = 0U;
    }

    for (c7_j = 0; c7_j < 2; c7_j++) {
      c7_b_j = 1.0 + (real_T)c7_j;
      c7_mti = c7_d_state[624] + 1U;
      if ((real_T)c7_mti >= 625.0) {
        for (c7_kk = 0; c7_kk < 227; c7_kk++) {
          c7_b_kk = 1.0 + (real_T)c7_kk;
          c7_y = (c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c7_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c7_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c7_b_y = c7_y;
          c7_c_y = c7_b_y;
          if ((real_T)(c7_c_y & 1U) == 0.0) {
            c7_c_y >>= 1U;
          } else {
            c7_c_y = c7_c_y >> 1U ^ 2567483615U;
          }

          c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c7_b_kk), 1, 625, 1, 0) - 1] =
            c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c7_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c7_c_y;
        }

        for (c7_c_kk = 0; c7_c_kk < 396; c7_c_kk++) {
          c7_b_kk = 228.0 + (real_T)c7_c_kk;
          c7_y = (c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c7_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c7_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c7_d_y = c7_y;
          c7_e_y = c7_d_y;
          if ((real_T)(c7_e_y & 1U) == 0.0) {
            c7_e_y >>= 1U;
          } else {
            c7_e_y = c7_e_y >> 1U ^ 2567483615U;
          }

          c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c7_b_kk), 1, 625, 1, 0) - 1] =
            c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c7_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c7_e_y;
        }

        c7_y = (c7_d_state[623] & 2147483648U) | (c7_d_state[0] & 2147483647U);
        c7_f_y = c7_y;
        c7_g_y = c7_f_y;
        if ((real_T)(c7_g_y & 1U) == 0.0) {
          c7_g_y >>= 1U;
        } else {
          c7_g_y = c7_g_y >> 1U ^ 2567483615U;
        }

        c7_d_state[623] = c7_d_state[396] ^ c7_g_y;
        c7_mti = 1U;
      }

      c7_y = c7_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c7_mti), 1, 625, 1, 0)
        - 1];
      c7_d_state[624] = c7_mti;
      c7_y ^= c7_y >> 11U;
      c7_y ^= c7_y << 7U & 2636928640U;
      c7_y ^= c7_y << 15U & 4022730752U;
      c7_y ^= c7_y >> 18U;
      c7_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c7_b_j), 1, 2, 1, 0) - 1] = c7_y;
    }

    c7_u[0] >>= 5U;
    c7_u[1] >>= 6U;
    c7_b_r = 1.1102230246251565E-16 * ((real_T)c7_u[0] * 6.7108864E+7 + (real_T)
      c7_u[1]);
    if (c7_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c7_d_state[624] >= 1.0) {
        if ((real_T)c7_d_state[624] < 625.0) {
          c7_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c7_b1 = false;
      }

      c7_isvalid = c7_b1;
      if (c7_isvalid) {
        c7_isvalid = false;
        c7_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c7_k < 625)) {
          if ((real_T)c7_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c7_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c7_a = c7_k;
            c7_b_a = c7_a + 1;
            c7_k = c7_b_a;
          } else {
            c7_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c7_isvalid) {
        c7_eml_error(chartInstance);
        c7_d7 = 5489.0;
        c7_b_twister_state_vector(chartInstance, c7_d_state, c7_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c7_b_r;
}

static real_T c7_get_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c7_b);
  if (chartInstance->c7_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#472) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_BOREDOMT_address;
}

static void c7_set_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c7_b);
  if (chartInstance->c7_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#472) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_BOREDOMT_address = c7_c;
}

static real_T *c7_access_BOREDOMT(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c7_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#472) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_BOREDOMT_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c7_c;
}

static real_T c7_get_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c7_b);
  if (chartInstance->c7_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#482) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_avert_address;
}

static void c7_set_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c7_b);
  if (chartInstance->c7_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#482) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_avert_address = c7_c;
}

static real_T *c7_access_avert(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c7_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#482) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_avert_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c7_c;
}

static real_T c7_get_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c7_b);
  if (chartInstance->c7_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#466) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_bHand_address;
}

static void c7_set_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c7_b);
  if (chartInstance->c7_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#466) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_bHand_address = c7_c;
}

static real_T *c7_access_bHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c7_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#466) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_bHand_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c7_c;
}

static real_T c7_get_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c7_b);
  if (chartInstance->c7_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#471) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_bored_address;
}

static void c7_set_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c7_b);
  if (chartInstance->c7_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#471) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_bored_address = c7_c;
}

static real_T *c7_access_bored(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c7_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#471) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_bored_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c7_c;
}

static real_T c7_get_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c7_b);
  if (chartInstance->c7_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#464) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_diff_address;
}

static void c7_set_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c7_b);
  if (chartInstance->c7_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#464) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_diff_address = c7_c;
}

static real_T *c7_access_diff(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c7_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#464) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_diff_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c7_c;
}

static real_T c7_get_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c7_b);
  if (chartInstance->c7_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#477) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_p_address;
}

static void c7_set_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c7_b);
  if (chartInstance->c7_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#477) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_p_address = c7_c;
}

static real_T *c7_access_p(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c7_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#477) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_p_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c7_c;
}

static real_T c7_get_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c7_b);
  if (chartInstance->c7_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#481) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_pSmile_address;
}

static void c7_set_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c7_b);
  if (chartInstance->c7_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#481) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_pSmile_address = c7_c;
}

static real_T *c7_access_pSmile(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c7_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#481) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_pSmile_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c7_c;
}

static real_T c7_get_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c7_b);
  if (chartInstance->c7_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#475) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_pose_address;
}

static void c7_set_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c7_b);
  if (chartInstance->c7_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#475) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_pose_address = c7_c;
}

static real_T *c7_access_pose(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c7_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#475) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_pose_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c7_c;
}

static real_T c7_get_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c7_b);
  if (chartInstance->c7_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#476) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_r_address;
}

static void c7_set_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c7_b);
  if (chartInstance->c7_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#476) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_r_address = c7_c;
}

static real_T *c7_access_r(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c7_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#476) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_r_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c7_c;
}

static real_T c7_get_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c7_b);
  if (chartInstance->c7_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#473) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_randomG_address;
}

static void c7_set_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c7_b);
  if (chartInstance->c7_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#473) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_randomG_address = c7_c;
}

static real_T *c7_access_randomG(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c7_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#473) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_randomG_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c7_c;
}

static real_T c7_get_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c7_b);
  if (chartInstance->c7_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#474) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_randomP_address;
}

static void c7_set_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c7_b);
  if (chartInstance->c7_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#474) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_randomP_address = c7_c;
}

static real_T *c7_access_randomP(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c7_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#474) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_randomP_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c7_c;
}

static real_T c7_get_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c7_b);
  if (chartInstance->c7_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#478) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_s_address;
}

static void c7_set_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c7_b);
  if (chartInstance->c7_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#478) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_s_address = c7_c;
}

static real_T *c7_access_s(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c7_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#478) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_s_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c7_c;
}

static real_T c7_get_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c7_b);
  if (chartInstance->c7_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#469) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_smileN_address;
}

static void c7_set_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c7_b);
  if (chartInstance->c7_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#469) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_smileN_address = c7_c;
}

static real_T *c7_access_smileN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c7_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#469) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_smileN_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c7_c;
}

static real_T c7_get_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c7_b);
  if (chartInstance->c7_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#470) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_smileYN_address;
}

static void c7_set_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c7_b);
  if (chartInstance->c7_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#470) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_smileYN_address = c7_c;
}

static real_T *c7_access_smileYN(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c7_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#470) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_smileYN_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c7_c;
}

static real_T c7_get_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c7_b);
  if (chartInstance->c7_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#463) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_temp_address;
}

static void c7_set_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c7_b);
  if (chartInstance->c7_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#463) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_temp_address = c7_c;
}

static real_T *c7_access_temp(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c7_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#463) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_temp_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c7_c;
}

static real_T c7_get_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c7_b);
  if (chartInstance->c7_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#465) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_uHand_address;
}

static void c7_set_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c7_b);
  if (chartInstance->c7_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#465) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_uHand_address = c7_c;
}

static real_T *c7_access_uHand(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c7_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#465) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_uHand_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c7_c;
}

static real_T c7_get_wristRotate(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c7_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c7_b);
  if (chartInstance->c7_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#479) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c7_wristRotate_address;
}

static void c7_set_wristRotate(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c7_b, real_T c7_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c7_b);
  if (chartInstance->c7_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#479) in the initialization routine of the chart.\n");
  }

  *chartInstance->c7_wristRotate_address = c7_c;
}

static real_T *c7_access_wristRotate
  (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T c7_b)
{
  real_T *c7_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c7_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#479) in the initialization routine of the chart.\n");
  }

  c7_c = chartInstance->c7_wristRotate_address;
  if (c7_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c7_c;
}

static void init_dsm_address_info(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c7_BOREDOMT_address, &chartInstance->c7_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c7_avert_address, &chartInstance->c7_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c7_bHand_address, &chartInstance->c7_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c7_bored_address, &chartInstance->c7_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c7_diff_address, &chartInstance->c7_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c7_p_address, &chartInstance->c7_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pSmile", (void **)
    &chartInstance->c7_pSmile_address, &chartInstance->c7_pSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c7_pose_address, &chartInstance->c7_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c7_r_address, &chartInstance->c7_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomG", (void **)
    &chartInstance->c7_randomG_address, &chartInstance->c7_randomG_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c7_randomP_address, &chartInstance->c7_randomP_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c7_s_address, &chartInstance->c7_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileN", (void **)
    &chartInstance->c7_smileN_address, &chartInstance->c7_smileN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileYN", (void **)
    &chartInstance->c7_smileYN_address, &chartInstance->c7_smileYN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c7_temp_address, &chartInstance->c7_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c7_uHand_address, &chartInstance->c7_uHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "wristRotate", (void **)
    &chartInstance->c7_wristRotate_address, &chartInstance->c7_wristRotate_index);
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

void sf_c7_ARP_02_RPSsmile_GloveAtomic_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1909528298U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2723325977U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4172425838U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3265672878U);
}

mxArray *sf_c7_ARP_02_RPSsmile_GloveAtomic_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rJG0SKeodNuz8Qlrlf6qtF");
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

mxArray *sf_c7_ARP_02_RPSsmile_GloveAtomic_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_ARP_02_RPSsmile_GloveAtomic_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_ARP_02_RPSsmile_GloveAtomic(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[93],T\"bWinT\",},{M[1],M[86],T\"bradHand\",},{M[1],M[84],T\"gameState\",},{M[1],M[106],T\"round\",},{M[1],M[94],T\"uWinT\",},{M[1],M[87],T\"userHand\",},{M[1],M[88],T\"win\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c7_ARP_02_RPSsmile_GloveAtomic\",},{M[9],M[0],T\"is_c7_ARP_02_RPSsmile_GloveAtomic\",},{M[11],M[107],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x13[54 83 58 59 61 64 67 69 71 78 77 81 82],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_ARP_02_RPSsmile_GloveAtomic_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
           7,
           40,
           48,
           0,
           43,
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
          _SFD_SET_DATA_PROPS(12,11,0,0,"smileYN");
          _SFD_SET_DATA_PROPS(13,11,0,0,"bored");
          _SFD_SET_DATA_PROPS(14,11,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(15,11,0,0,"randomG");
          _SFD_SET_DATA_PROPS(16,11,0,0,"randomP");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pose");
          _SFD_SET_DATA_PROPS(18,11,0,0,"r");
          _SFD_SET_DATA_PROPS(19,11,0,0,"p");
          _SFD_SET_DATA_PROPS(20,11,0,0,"s");
          _SFD_SET_DATA_PROPS(21,11,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(22,2,0,1,"round");
          _SFD_SET_DATA_PROPS(23,11,0,0,"pSmile");
          _SFD_SET_DATA_PROPS(24,11,0,0,"avert");
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
          _SFD_SET_DATA_PROPS(41,8,0,0,"");
          _SFD_SET_DATA_PROPS(42,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(3,0,0);
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
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_CH_SUBSTATE_COUNT(30);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,3);
          _SFD_CH_SUBSTATE_INDEX(1,11);
          _SFD_CH_SUBSTATE_INDEX(2,12);
          _SFD_CH_SUBSTATE_INDEX(3,13);
          _SFD_CH_SUBSTATE_INDEX(4,14);
          _SFD_CH_SUBSTATE_INDEX(5,15);
          _SFD_CH_SUBSTATE_INDEX(6,16);
          _SFD_CH_SUBSTATE_INDEX(7,17);
          _SFD_CH_SUBSTATE_INDEX(8,18);
          _SFD_CH_SUBSTATE_INDEX(9,19);
          _SFD_CH_SUBSTATE_INDEX(10,20);
          _SFD_CH_SUBSTATE_INDEX(11,21);
          _SFD_CH_SUBSTATE_INDEX(12,22);
          _SFD_CH_SUBSTATE_INDEX(13,23);
          _SFD_CH_SUBSTATE_INDEX(14,24);
          _SFD_CH_SUBSTATE_INDEX(15,25);
          _SFD_CH_SUBSTATE_INDEX(16,26);
          _SFD_CH_SUBSTATE_INDEX(17,27);
          _SFD_CH_SUBSTATE_INDEX(18,28);
          _SFD_CH_SUBSTATE_INDEX(19,29);
          _SFD_CH_SUBSTATE_INDEX(20,30);
          _SFD_CH_SUBSTATE_INDEX(21,31);
          _SFD_CH_SUBSTATE_INDEX(22,32);
          _SFD_CH_SUBSTATE_INDEX(23,33);
          _SFD_CH_SUBSTATE_INDEX(24,34);
          _SFD_CH_SUBSTATE_INDEX(25,35);
          _SFD_CH_SUBSTATE_INDEX(26,36);
          _SFD_CH_SUBSTATE_INDEX(27,37);
          _SFD_CH_SUBSTATE_INDEX(28,38);
          _SFD_CH_SUBSTATE_INDEX(29,39);
          _SFD_ST_SUBSTATE_COUNT(3,0);
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
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
        }

        _SFD_CV_INIT_CHART(30,1,0,0);

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(37,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
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
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"rockPosec7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             396);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",396,-1,557);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",557,-1,718);
        _SFD_CV_INIT_EML_IF(7,1,0,220,250,281,394);
        _SFD_CV_INIT_EML_IF(7,1,1,281,315,346,394);
        _SFD_CV_INIT_EML(6,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"paperPosec7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             400);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",400,-1,556);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",556,-1,710);
        _SFD_CV_INIT_EML_IF(6,1,0,224,254,285,398);
        _SFD_CV_INIT_EML_IF(6,1,1,285,319,350,398);
        _SFD_CV_INIT_EML(8,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"scissorsPosec7_ARP_02_RPSsmile_GloveAtomic",0,
                             -1,409);
        _SFD_CV_INIT_EML_FCN(8,1,"aFcnTruthTableAction_1",409,-1,566);
        _SFD_CV_INIT_EML_FCN(8,2,"aFcnTruthTableAction_2",566,-1,725);
        _SFD_CV_INIT_EML_IF(8,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(8,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(4,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"handPoseSBc7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             1083);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",1083,-1,1319);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",1319,-1,1553);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",1553,-1,1725);
        _SFD_CV_INIT_EML_FCN(4,4,"aFcnTruthTableAction_4",1725,-1,1894);
        _SFD_CV_INIT_EML_FCN(4,5,"aFcnTruthTableAction_5",1894,-1,2050);
        _SFD_CV_INIT_EML_FCN(4,6,"aFcnTruthTableAction_6",2050,-1,2203);
        _SFD_CV_INIT_EML_IF(4,1,0,647,677,708,1081);
        _SFD_CV_INIT_EML_IF(4,1,1,708,742,773,1081);
        _SFD_CV_INIT_EML_IF(4,1,2,773,807,838,1081);
        _SFD_CV_INIT_EML_IF(4,1,3,838,872,903,1081);
        _SFD_CV_INIT_EML_IF(4,1,4,903,937,968,1081);
        _SFD_CV_INIT_EML_IF(4,1,5,968,1002,1033,1081);
        _SFD_CV_INIT_EML(5,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"idlePosec7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             1353);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",1353,-1,1569);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",1569,-1,1800);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",1800,-1,1935);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",1935,-1,2226);
        _SFD_CV_INIT_EML_FCN(5,5,"aFcnTruthTableAction_5",2226,-1,2518);
        _SFD_CV_INIT_EML_FCN(5,6,"aFcnTruthTableAction_6",2518,-1,2812);
        _SFD_CV_INIT_EML_FCN(5,7,"aFcnTruthTableAction_7",2812,-1,3107);
        _SFD_CV_INIT_EML_FCN(5,8,"aFcnTruthTableAction_8",3107,-1,3271);
        _SFD_CV_INIT_EML_IF(5,1,0,787,817,848,1351);
        _SFD_CV_INIT_EML_IF(5,1,1,848,882,913,1351);
        _SFD_CV_INIT_EML_IF(5,1,2,913,947,978,1351);
        _SFD_CV_INIT_EML_IF(5,1,3,978,1012,1043,1351);
        _SFD_CV_INIT_EML_IF(5,1,4,1043,1077,1108,1351);
        _SFD_CV_INIT_EML_IF(5,1,5,1108,1142,1173,1351);
        _SFD_CV_INIT_EML_IF(5,1,6,1173,1207,1238,1351);
        _SFD_CV_INIT_EML_IF(5,1,7,1238,1272,1303,1351);
        _SFD_CV_INIT_EML(2,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"boredPoseSc7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             2805);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",2805,-1,2976);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",2976,-1,3138);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",3138,-1,3305);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",3305,-1,3474);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",3474,-1,3643);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",3643,-1,3824);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",3824,-1,4003);
        _SFD_CV_INIT_EML_FCN(2,8,"aFcnTruthTableAction_8",4003,-1,4172);
        _SFD_CV_INIT_EML_FCN(2,9,"aFcnTruthTableAction_9",4172,-1,4339);
        _SFD_CV_INIT_EML_FCN(2,10,"aFcnTruthTableAction_10",4339,-1,4508);
        _SFD_CV_INIT_EML_FCN(2,11,"aFcnTruthTableAction_11",4508,-1,4674);
        _SFD_CV_INIT_EML_IF(2,1,0,1577,1607,1638,2803);
        _SFD_CV_INIT_EML_IF(2,1,1,1638,1672,1703,2803);
        _SFD_CV_INIT_EML_IF(2,1,2,1703,1737,1768,2803);
        _SFD_CV_INIT_EML_IF(2,1,3,1768,1802,1833,2803);
        _SFD_CV_INIT_EML_IF(2,1,4,1833,1867,1898,2803);
        _SFD_CV_INIT_EML_IF(2,1,5,1898,1932,1964,2803);
        _SFD_CV_INIT_EML_IF(2,1,6,1964,1998,2029,2803);
        _SFD_CV_INIT_EML_IF(2,1,7,2029,2063,2094,2803);
        _SFD_CV_INIT_EML_IF(2,1,8,2094,2128,2159,2803);
        _SFD_CV_INIT_EML_IF(2,1,9,2159,2194,2226,2803);
        _SFD_CV_INIT_EML_IF(2,1,10,2226,2261,2293,2803);
        _SFD_CV_INIT_EML_IF(2,1,11,2293,2328,2359,2803);
        _SFD_CV_INIT_EML_IF(2,1,12,2359,2394,2425,2803);
        _SFD_CV_INIT_EML_IF(2,1,13,2425,2460,2491,2803);
        _SFD_CV_INIT_EML_IF(2,1,14,2491,2526,2557,2803);
        _SFD_CV_INIT_EML_IF(2,1,15,2557,2592,2623,2803);
        _SFD_CV_INIT_EML_IF(2,1,16,2623,2658,2689,2803);
        _SFD_CV_INIT_EML_IF(2,1,17,2689,2724,2755,2803);
        _SFD_CV_INIT_EML(0,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredGazec7_ARP_02_RPSsmile_GloveAtomic",0,-1,
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
        _SFD_CV_INIT_EML(1,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"boredPosec7_ARP_02_RPSsmile_GloveAtomic",0,-1,
                             1275);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1275,-1,1457);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1457,-1,1640);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1640,-1,1824);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1824,-1,2010);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",2010,-1,2196);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2196,-1,2387);
        _SFD_CV_INIT_EML_IF(1,1,0,709,739,770,1273);
        _SFD_CV_INIT_EML_IF(1,1,1,770,804,835,1273);
        _SFD_CV_INIT_EML_IF(1,1,2,835,869,900,1273);
        _SFD_CV_INIT_EML_IF(1,1,3,900,934,965,1273);
        _SFD_CV_INIT_EML_IF(1,1,4,965,999,1030,1273);
        _SFD_CV_INIT_EML_IF(1,1,5,1030,1064,1095,1273);
        _SFD_CV_INIT_EML_IF(1,1,6,1095,1129,1160,1273);
        _SFD_CV_INIT_EML_IF(1,1,7,1160,1194,1225,1273);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(37,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0);
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
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,17,1,17);
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
        _SFD_CV_INIT_EML_IF(10,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,9,1,9);
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

        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(27,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(27,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(30,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(30,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(40,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(40,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(42,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(42,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(43,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(43,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(44,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(44,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(45,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(46,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(46,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(47,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(47,0,0,0,13,0,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
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
        _SFD_SET_DATA_VALUE_PTR(41,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(42,(void *)(NULL));

        {
          real_T *c7_gameState;
          real_T *c7_inputUser;
          real_T *c7_bradHand;
          real_T *c7_userHand;
          real_T *c7_win;
          real_T *c7_bWinT;
          real_T *c7_uWinT;
          real_T *c7_round;
          c7_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c7_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c7_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c7_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c7_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c7_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c7_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c7_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c7_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c7_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c7_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c7_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c7_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c7_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c7_smileN_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c7_smileYN_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c7_bored_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c7_BOREDOMT_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c7_randomG_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c7_randomP_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c7_pose_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c7_r_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c7_p_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c7_s_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c7_wristRotate_address);
          _SFD_SET_DATA_VALUE_PTR(22U, c7_round);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c7_pSmile_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c7_avert_address);
        }
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
  return "y7PydtqKdhmRsc6kMOPvqB";
}

static void sf_opaque_initialize_c7_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
  initialize_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  enable_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  disable_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  sf_gateway_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_ARP_02_RPSsmile_GloveAtomic();/* state var info */
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

extern void sf_internal_set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c7_ARP_02_RPSsmile_GloveAtomic();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct* S,
  const mxArray *st)
{
}

static void sf_opaque_terminate_c7_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveAtomic_optimization_info();
    }

    finalize_c7_ARP_02_RPSsmile_GloveAtomic
      ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_ARP_02_RPSsmile_GloveAtomic
    ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
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
    initialize_params_c7_ARP_02_RPSsmile_GloveAtomic
      ((SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSsmile_GloveAtomic_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,7,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,9);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3177029697U));
  ssSetChecksum1(S,(2865773658U));
  ssSetChecksum2(S,(2569310027U));
  ssSetChecksum3(S,(2372824137U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)utMalloc
    (sizeof(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_ARP_02_RPSsmile_GloveAtomic;
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

void c7_ARP_02_RPSsmile_GloveAtomic_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_ARP_02_RPSsmile_GloveAtomic_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
