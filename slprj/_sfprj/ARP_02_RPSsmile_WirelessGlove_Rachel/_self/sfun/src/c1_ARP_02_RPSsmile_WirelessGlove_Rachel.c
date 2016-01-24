/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_WirelessGlove_Rachel_sfun.h"
#include "c1_ARP_02_RPSsmile_WirelessGlove_Rachel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_WirelessGlove_Rachel_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_stateBradWin             ((uint8_T)1U)
#define c1_IN_stateCompare             ((uint8_T)2U)
#define c1_IN_stateGo                  ((uint8_T)3U)
#define c1_IN_stateNoWin               ((uint8_T)4U)
#define c1_IN_statePoseFingersCLose    ((uint8_T)5U)
#define c1_IN_statePosePaper           ((uint8_T)6U)
#define c1_IN_statePoseReady           ((uint8_T)7U)
#define c1_IN_statePoseReturnFinger    ((uint8_T)8U)
#define c1_IN_statePoseReturnWrist     ((uint8_T)9U)
#define c1_IN_statePoseRock            ((uint8_T)10U)
#define c1_IN_statePoseScissors        ((uint8_T)11U)
#define c1_IN_statePoseSmile           ((uint8_T)12U)
#define c1_IN_statePoseSmileWin        ((uint8_T)13U)
#define c1_IN_stateRandom              ((uint8_T)14U)
#define c1_IN_stateRandom1             ((uint8_T)15U)
#define c1_IN_stateRandomHand          ((uint8_T)16U)
#define c1_IN_stateReadUserHand        ((uint8_T)17U)
#define c1_IN_stateReady               ((uint8_T)18U)
#define c1_IN_stateShowHands           ((uint8_T)19U)
#define c1_IN_stateShowResult          ((uint8_T)20U)
#define c1_IN_stateStart               ((uint8_T)21U)
#define c1_IN_stateUserWin             ((uint8_T)22U)
#define c1_IN_stateWristRotate         ((uint8_T)23U)
#define c1_IN_stateAvertGaze           ((uint8_T)1U)
#define c1_IN_stateAvertHead           ((uint8_T)2U)
#define c1_IN_stateHeadNeutral         ((uint8_T)3U)
#define c1_IN_stateInitial             ((uint8_T)4U)
#define c1_IN_stateBoredPose           ((uint8_T)1U)
#define c1_IN_stateRandomPose          ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_g_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_h_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c1_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_o_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_yb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_bc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_cc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_dc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ec_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_fc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_gc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_hc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ic_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_jc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_kc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_lc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_mc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_nc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_oc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_pc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_qc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_rc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_sc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_tc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_uc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_vc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_wc_debug_family_names[37] = { "aVarTruthTableCondition_1",
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
  "aVarTruthTableCondition_22", "aVarTruthTableCondition_23",
  "aVarTruthTableCondition_24", "aVarTruthTableCondition_25",
  "aVarTruthTableCondition_26", "aVarTruthTableCondition_27",
  "aVarTruthTableCondition_28", "aVarTruthTableCondition_29",
  "aVarTruthTableCondition_30", "aVarTruthTableCondition_31",
  "aVarTruthTableCondition_32", "aVarTruthTableCondition_33", "nargin",
  "nargout", "bmlID", "gazeBML" };

static const char * c1_xc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_yc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ad_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_bd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_cd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_dd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ed_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_fd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_gd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_hd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_id_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_jd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_kd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ld_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_md_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_nd_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_sd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_se_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_te_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ue_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ve_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_we_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_xe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ye_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_af_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_bf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_cf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_df_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ef_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ff_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_gf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_hf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_if_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_jf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_kf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_lf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_mf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_nf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_of_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_pf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_rf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_sf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_tf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_uf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_vf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_wf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_xf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_yf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ag_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_bg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_cg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_dg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_eg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_fg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_gg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_hg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ig_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_jg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_kg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_lg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_mg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ng_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_og_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_pg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_rg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[37];

/* Function Declarations */
static void initialize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void initialize_params_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void enable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void disable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_WirelessGlove_R
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void finalize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void sf_gateway_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_chartstep_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void initSimStructsc1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateGame(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance);
static void c1_stateStart
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_stateReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateRandom
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_statePoseReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseSmile
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_stateWristRotate
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateWristRotate
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateRandomHand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseRock
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseFingersCLose
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateReadUserHand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseScissors
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateShowHands
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseReturnFinger
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_statePoseReturnWrist
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateUserWin
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_stateRandom1
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateRandom1
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_statePoseSmileWin
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateShowResult
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateIdleGaze
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_stateInitial
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_stateInitial
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_enter_atomic_stateBoredPose
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_b_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_c_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_d_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_e_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_f_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_g_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_h_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_i_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_j_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_k_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_l_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_m_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_n_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_o_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static real_T c1_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_lowhigh[2]);
static real_T c1_rand(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
                      *chartInstance);
static real_T c1_eml_rand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);
static void c1_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625]);
static void c1_twister_state_vector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625]);
static void c1_b_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_b_r);
static void c1_eml_error(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance);
static real_T c1_b_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance);
static real_T c1_c_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance);
static void c1_p_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_q_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_r_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_s_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_t_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_u_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_v_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_w_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_x_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_y_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_ab_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_bb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_cb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_db_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_eb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_fb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_gb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_hb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_ib_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_jb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_kb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_lb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_mb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static real_T c1_d_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance);
static void c1_nb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_ob_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_pb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_qb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_rb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_sb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_tb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_ub_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_vb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_wb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void c1_xb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_bmlID, const char_T *c1_identifier);
static real_T c1_c_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_u_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_v_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_w_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_x_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_y_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_db_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_sendBML(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_arg[256]);
static void c1_handPoseSB
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_sbmID, real_T c1_poseSBM[256]);
static void c1_idlePose(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *
  chartInstance, real_T c1_bmlID, real_T c1_poseBML[256]);
static void c1_boredGaze(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_gazeBML[256]);
static const mxArray *c1_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_stateGame, const char_T *c1_identifier);
static uint8_T c1_i_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_method, const char_T *c1_identifier);
static uint32_T c1_k_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_l_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier);
static uint32_T c1_m_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_n_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625]);
static void c1_o_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625]);
static void c1_p_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2]);
static void c1_q_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2]);
static uint32_T c1_r_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_temporalCounter_i2, const char_T *c1_identifier);
static uint32_T c1_s_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_t_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_u_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_vectorIndex, uint32_T c1_dataNumber);
static void c1_b_twister_state_vector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_mt[625], real_T c1_seed);
static real_T c1_c_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625]);
static void init_dsm_address_info
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_method_not_empty = false;
  chartInstance->c1_state_not_empty = false;
  chartInstance->c1_b_state_not_empty = false;
  chartInstance->c1_c_state_not_empty = false;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_stateGame = 0U;
  chartInstance->c1_is_stateGame = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_stateGame = 0U;
  chartInstance->c1_tp_stateBradWin = 0U;
  chartInstance->c1_tp_stateCompare = 0U;
  chartInstance->c1_tp_stateGo = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateNoWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseFingersCLose = 0U;
  chartInstance->c1_tp_statePosePaper = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseReady = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseReturnFinger = 0U;
  chartInstance->c1_tp_statePoseReturnWrist = 0U;
  chartInstance->c1_tp_statePoseRock = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseScissors = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseSmile = 0U;
  chartInstance->c1_tp_statePoseSmileWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateRandom = 0U;
  chartInstance->c1_tp_stateRandom1 = 0U;
  chartInstance->c1_tp_stateRandomHand = 0U;
  chartInstance->c1_tp_stateReadUserHand = 0U;
  chartInstance->c1_tp_stateReady = 0U;
  chartInstance->c1_tp_stateShowHands = 0U;
  chartInstance->c1_tp_stateShowResult = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateStart = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateUserWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateWristRotate = 0U;
  chartInstance->c1_is_active_stateIdleGaze = 0U;
  chartInstance->c1_is_stateIdleGaze = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_stateIdleGaze = 0U;
  chartInstance->c1_tp_stateAvertGaze = 0U;
  chartInstance->c1_temporalCounter_i2 = 0U;
  chartInstance->c1_tp_stateAvertHead = 0U;
  chartInstance->c1_temporalCounter_i2 = 0U;
  chartInstance->c1_tp_stateHeadNeutral = 0U;
  chartInstance->c1_temporalCounter_i2 = 0U;
  chartInstance->c1_tp_stateInitial = 0U;
  chartInstance->c1_is_active_stateIdlePose = 0U;
  chartInstance->c1_is_stateIdlePose = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_stateIdlePose = 0U;
  chartInstance->c1_tp_stateBoredPose = 0U;
  chartInstance->c1_temporalCounter_i3 = 0U;
  chartInstance->c1_tp_stateRandomPose = 0U;
  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel = 0U;
}

static void initialize_params_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
}

static void disable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
}

static void c1_update_debugger_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel == 1U)
  {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateGame == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateRandom) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateWristRotate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseRock) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnWrist) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateRandom1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmileWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateAvertGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateAvertHead) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateIdlePose == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdlePose == c1_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateIdlePose == c1_IN_stateBoredPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_n_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_o_hoistedGlobal;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_p_hoistedGlobal;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_q_hoistedGlobal;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_r_hoistedGlobal;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_s_hoistedGlobal;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_ab_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_bb_hoistedGlobal;
  real_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  real_T c1_cb_hoistedGlobal;
  real_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  uint32_T c1_db_hoistedGlobal;
  uint32_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  uint32_T c1_eb_hoistedGlobal;
  uint32_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  int32_T c1_i0;
  uint32_T c1_fb_u[625];
  const mxArray *c1_gb_y = NULL;
  int32_T c1_i1;
  uint32_T c1_gb_u[2];
  const mxArray *c1_hb_y = NULL;
  uint8_T c1_fb_hoistedGlobal;
  uint8_T c1_hb_u;
  const mxArray *c1_ib_y = NULL;
  uint8_T c1_gb_hoistedGlobal;
  uint8_T c1_ib_u;
  const mxArray *c1_jb_y = NULL;
  uint8_T c1_hb_hoistedGlobal;
  uint8_T c1_jb_u;
  const mxArray *c1_kb_y = NULL;
  uint8_T c1_ib_hoistedGlobal;
  uint8_T c1_kb_u;
  const mxArray *c1_lb_y = NULL;
  uint8_T c1_jb_hoistedGlobal;
  uint8_T c1_lb_u;
  const mxArray *c1_mb_y = NULL;
  uint8_T c1_kb_hoistedGlobal;
  uint8_T c1_mb_u;
  const mxArray *c1_nb_y = NULL;
  uint8_T c1_lb_hoistedGlobal;
  uint8_T c1_nb_u;
  const mxArray *c1_ob_y = NULL;
  uint8_T c1_mb_hoistedGlobal;
  uint8_T c1_ob_u;
  const mxArray *c1_pb_y = NULL;
  uint32_T c1_nb_hoistedGlobal;
  uint32_T c1_pb_u;
  const mxArray *c1_qb_y = NULL;
  uint8_T c1_ob_hoistedGlobal;
  uint8_T c1_qb_u;
  const mxArray *c1_rb_y = NULL;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(42, 1), false);
  c1_hoistedGlobal = *c1_bWinT;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_bradHand;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_gameState;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_uWinT;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_userHand;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_win;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_BOREDOMT;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_b;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_bHand;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_bored;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = chartInstance->c1_diff;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_p;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = chartInstance->c1_pose;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = chartInstance->c1_poseYN;
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = chartInstance->c1_r;
  c1_o_u = c1_o_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_p_hoistedGlobal = chartInstance->c1_randomB;
  c1_p_u = c1_p_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_q_hoistedGlobal = chartInstance->c1_randomD;
  c1_q_u = c1_q_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_r_hoistedGlobal = chartInstance->c1_randomG;
  c1_r_u = c1_r_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_s_hoistedGlobal = chartInstance->c1_randomGP;
  c1_s_u = c1_s_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_t_hoistedGlobal = chartInstance->c1_randomH;
  c1_t_u = c1_t_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_u_hoistedGlobal = chartInstance->c1_randomP;
  c1_u_u = c1_u_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_v_hoistedGlobal = chartInstance->c1_s;
  c1_v_u = c1_v_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_w_hoistedGlobal = chartInstance->c1_shoulderFW;
  c1_w_u = c1_w_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_x_hoistedGlobal = chartInstance->c1_smileN;
  c1_x_u = c1_x_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_y_hoistedGlobal = chartInstance->c1_smileYN;
  c1_y_u = c1_y_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_ab_hoistedGlobal = chartInstance->c1_temp;
  c1_ab_u = c1_ab_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_bb_hoistedGlobal = chartInstance->c1_uHand;
  c1_bb_u = c1_bb_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_cb_hoistedGlobal = chartInstance->c1_wristRotate;
  c1_cb_u = c1_cb_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_db_hoistedGlobal = chartInstance->c1_method;
  c1_db_u = c1_db_hoistedGlobal;
  c1_eb_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_eb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_eb_hoistedGlobal = chartInstance->c1_state;
  c1_eb_u = c1_eb_hoistedGlobal;
  c1_fb_y = NULL;
  if (!chartInstance->c1_state_not_empty) {
    sf_mex_assign(&c1_fb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c1_y, 29, c1_fb_y);
  for (c1_i0 = 0; c1_i0 < 625; c1_i0++) {
    c1_fb_u[c1_i0] = chartInstance->c1_c_state[c1_i0];
  }

  c1_gb_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_gb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_gb_y, sf_mex_create("y", c1_fb_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c1_y, 30, c1_gb_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_gb_u[c1_i1] = chartInstance->c1_b_state[c1_i1];
  }

  c1_hb_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_hb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_hb_y, sf_mex_create("y", c1_gb_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_fb_hoistedGlobal =
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  c1_hb_u = c1_fb_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_hb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_gb_hoistedGlobal = chartInstance->c1_is_active_stateIdlePose;
  c1_ib_u = c1_gb_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_ib_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_hb_hoistedGlobal = chartInstance->c1_is_active_stateIdleGaze;
  c1_jb_u = c1_hb_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_jb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_ib_hoistedGlobal = chartInstance->c1_is_active_stateGame;
  c1_kb_u = c1_ib_hoistedGlobal;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_kb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_jb_hoistedGlobal = chartInstance->c1_is_stateIdlePose;
  c1_lb_u = c1_jb_hoistedGlobal;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_lb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  c1_kb_hoistedGlobal = chartInstance->c1_is_stateIdleGaze;
  c1_mb_u = c1_kb_hoistedGlobal;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", &c1_mb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 37, c1_nb_y);
  c1_lb_hoistedGlobal = chartInstance->c1_is_stateGame;
  c1_nb_u = c1_lb_hoistedGlobal;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_nb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 38, c1_ob_y);
  c1_mb_hoistedGlobal = chartInstance->c1_temporalCounter_i3;
  c1_ob_u = c1_mb_hoistedGlobal;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_ob_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 39, c1_pb_y);
  c1_nb_hoistedGlobal = chartInstance->c1_temporalCounter_i2;
  c1_pb_u = c1_nb_hoistedGlobal;
  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", &c1_pb_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 40, c1_qb_y);
  c1_ob_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_qb_u = c1_ob_hoistedGlobal;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_qb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 41, c1_rb_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  uint32_T c1_uv0[625];
  int32_T c1_i2;
  uint32_T c1_uv1[2];
  int32_T c1_i3;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_bWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "bWinT");
  *c1_bradHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "bradHand");
  *c1_gameState = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "gameState");
  *c1_uWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "uWinT");
  *c1_userHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "userHand");
  *c1_win = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    5)), "win");
  chartInstance->c1_BOREDOMT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "BOREDOMT");
  chartInstance->c1_b = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 7)), "b");
  chartInstance->c1_bHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "bHand");
  chartInstance->c1_bored = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "bored");
  chartInstance->c1_diff = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "diff");
  chartInstance->c1_p = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "p");
  chartInstance->c1_pose = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "pose");
  chartInstance->c1_poseYN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "poseYN");
  chartInstance->c1_r = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 14)), "r");
  chartInstance->c1_randomB = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 15)), "randomB");
  chartInstance->c1_randomD = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 16)), "randomD");
  chartInstance->c1_randomG = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 17)), "randomG");
  chartInstance->c1_randomGP = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 18)), "randomGP");
  chartInstance->c1_randomH = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 19)), "randomH");
  chartInstance->c1_randomP = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 20)), "randomP");
  chartInstance->c1_s = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 21)), "s");
  chartInstance->c1_shoulderFW = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 22)), "shoulderFW");
  chartInstance->c1_smileN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 23)), "smileN");
  chartInstance->c1_smileYN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 24)), "smileYN");
  chartInstance->c1_temp = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 25)), "temp");
  chartInstance->c1_uHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 26)), "uHand");
  chartInstance->c1_wristRotate = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 27)), "wristRotate");
  chartInstance->c1_method = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 28)), "method");
  chartInstance->c1_state = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 29)), "state");
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 30)),
                        "state", c1_uv0);
  for (c1_i2 = 0; c1_i2 < 625; c1_i2++) {
    chartInstance->c1_c_state[c1_i2] = c1_uv0[c1_i2];
  }

  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 31)),
                        "state", c1_uv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_b_state[c1_i3] = c1_uv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel =
    c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 32)),
    "is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel");
  chartInstance->c1_is_active_stateIdlePose = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 33)),
     "is_active_stateIdlePose");
  chartInstance->c1_is_active_stateIdleGaze = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 34)),
     "is_active_stateIdleGaze");
  chartInstance->c1_is_active_stateGame = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 35)), "is_active_stateGame");
  chartInstance->c1_is_stateIdlePose = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 36)), "is_stateIdlePose");
  chartInstance->c1_is_stateIdleGaze = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 37)), "is_stateIdleGaze");
  chartInstance->c1_is_stateGame = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 38)), "is_stateGame");
  chartInstance->c1_temporalCounter_i3 = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 39)), "temporalCounter_i3");
  chartInstance->c1_temporalCounter_i2 = c1_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 40)), "temporalCounter_i2");
  chartInstance->c1_temporalCounter_i1 = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 41)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 42)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_WirelessGlove_R
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_stateGame == 1U) {
      chartInstance->c1_tp_stateGame = 1U;
    } else {
      chartInstance->c1_tp_stateGame = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateBradWin) {
      chartInstance->c1_tp_stateBradWin = 1U;
    } else {
      chartInstance->c1_tp_stateBradWin = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateCompare) {
      chartInstance->c1_tp_stateCompare = 1U;
    } else {
      chartInstance->c1_tp_stateCompare = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateGo) {
      chartInstance->c1_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateGo = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateNoWin) {
      chartInstance->c1_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateNoWin = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseFingersCLose) {
      chartInstance->c1_tp_statePoseFingersCLose = 1U;
    } else {
      chartInstance->c1_tp_statePoseFingersCLose = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePosePaper) {
      chartInstance->c1_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePosePaper = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseReady) {
      chartInstance->c1_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseReady = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnFinger) {
      chartInstance->c1_tp_statePoseReturnFinger = 1U;
    } else {
      chartInstance->c1_tp_statePoseReturnFinger = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnWrist) {
      chartInstance->c1_tp_statePoseReturnWrist = 1U;
    } else {
      chartInstance->c1_tp_statePoseReturnWrist = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseRock) {
      chartInstance->c1_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseRock = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseScissors) {
      chartInstance->c1_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmile) {
      chartInstance->c1_tp_statePoseSmile = 1U;
    } else {
      chartInstance->c1_tp_statePoseSmile = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmileWin) {
      chartInstance->c1_tp_statePoseSmileWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseSmileWin = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateRandom) {
      chartInstance->c1_tp_stateRandom = 1U;
    } else {
      chartInstance->c1_tp_stateRandom = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateRandom1) {
      chartInstance->c1_tp_stateRandom1 = 1U;
    } else {
      chartInstance->c1_tp_stateRandom1 = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateRandomHand) {
      chartInstance->c1_tp_stateRandomHand = 1U;
    } else {
      chartInstance->c1_tp_stateRandomHand = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateReadUserHand) {
      chartInstance->c1_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c1_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateReady) {
      chartInstance->c1_tp_stateReady = 1U;
    } else {
      chartInstance->c1_tp_stateReady = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateShowHands) {
      chartInstance->c1_tp_stateShowHands = 1U;
    } else {
      chartInstance->c1_tp_stateShowHands = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateShowResult) {
      chartInstance->c1_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateShowResult = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
      chartInstance->c1_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 23) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateStart = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateUserWin) {
      chartInstance->c1_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 24) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateUserWin = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateWristRotate) {
      chartInstance->c1_tp_stateWristRotate = 1U;
    } else {
      chartInstance->c1_tp_stateWristRotate = 0U;
    }

    if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
      chartInstance->c1_tp_stateIdleGaze = 1U;
    } else {
      chartInstance->c1_tp_stateIdleGaze = 0U;
    }

    if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateAvertGaze) {
      chartInstance->c1_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 27) == 0.0) {
        chartInstance->c1_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateAvertHead) {
      chartInstance->c1_tp_stateAvertHead = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 28) == 0.0) {
        chartInstance->c1_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateAvertHead = 0U;
    }

    if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateHeadNeutral) {
      chartInstance->c1_tp_stateHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 29) == 0.0) {
        chartInstance->c1_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c1_is_stateIdleGaze == c1_IN_stateInitial) {
      chartInstance->c1_tp_stateInitial = 1U;
    } else {
      chartInstance->c1_tp_stateInitial = 0U;
    }

    if (chartInstance->c1_is_active_stateIdlePose == 1U) {
      chartInstance->c1_tp_stateIdlePose = 1U;
    } else {
      chartInstance->c1_tp_stateIdlePose = 0U;
    }

    if (chartInstance->c1_is_stateIdlePose == c1_IN_stateBoredPose) {
      chartInstance->c1_tp_stateBoredPose = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 32) == 0.0) {
        chartInstance->c1_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateBoredPose = 0U;
    }

    if (chartInstance->c1_is_stateIdlePose == c1_IN_stateRandomPose) {
      chartInstance->c1_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c1_tp_stateRandomPose = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_WirelessGlove_R(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_inputUser, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_temp, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_bHand, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_bored, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_BOREDOMT, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_poseYN, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomG, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomGP, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 21U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_p, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_s, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_shoulderFW, 24U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomB, 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomD, 26U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_wristRotate, 27U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomH, 28U);
  if (chartInstance->c1_temporalCounter_i1 < 7U) {
    chartInstance->c1_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c1_temporalCounter_i1 + 1);
  }

  if (chartInstance->c1_temporalCounter_i2 < MAX_uint32_T) {
    chartInstance->c1_temporalCounter_i2++;
  }

  if (chartInstance->c1_temporalCounter_i3 < 3U) {
    chartInstance->c1_temporalCounter_i3 = (uint8_T)(int16_T)
      (chartInstance->c1_temporalCounter_i3 + 1);
  }

  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  c1_chartstep_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv0[256];
  int32_T c1_i4;
  real_T c1_arg[256];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_dv1[2];
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_dv2[2];
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_dv3[2];
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  real_T c1_m_nargin = 0.0;
  real_T c1_m_nargout = 0.0;
  real_T c1_dv4[2];
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_userHand;
  real_T *c1_bradHand;
  real_T *c1_win;
  real_T *c1_gameState;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  real_T (*c1_b_arg)[256];
  boolean_T guard1 = false;
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel == 0U)
  {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_stateGame = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateGame = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateStart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateStart = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_x_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_uHand = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    chartInstance->c1_smileYN = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    *c1_userHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    *c1_bradHand = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    *c1_win = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
    chartInstance->c1_BOREDOMT = 10.0;
    c1_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_BOREDOMT, 14U);
    *c1_gameState = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    chartInstance->c1_randomP = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
    *c1_uWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
    *c1_bWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
    chartInstance->c1_pose = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_bored = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_bored, 13U);
    chartInstance->c1_randomG = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomG, 16U);
    c1_idlePose(chartInstance, 3.0, c1_dv0);
    for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
      c1_arg[c1_i4] = c1_dv0[c1_i4];
    }

    for (c1_i5 = 0; c1_i5 < 256; c1_i5++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i5], 30U);
    }

    _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i6 = 0; c1_i6 < 256; c1_i6++) {
      (*c1_b_arg)[c1_i6] = c1_arg[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i7], 30U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(30U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_is_active_stateIdleGaze = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateIdleGaze = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateIdleGaze = c1_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateInitial = 1U;
    c1_enter_atomic_stateInitial(chartInstance);
    chartInstance->c1_is_active_stateIdlePose = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateIdlePose = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateIdlePose = c1_IN_stateRandomPose;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandomPose = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 14U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
    chartInstance->c1_b = chartInstance->c1_BOREDOMT - chartInstance->c1_bored;
    c1_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 20U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ad_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 20U);
    c1_dv1[0] = 1.0;
    c1_dv1[1] = chartInstance->c1_b;
    chartInstance->c1_randomP = c1_randi(chartInstance, c1_dv1);
    c1_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
    sf_mex_printf("%s =\\n", "randomP");
    c1_hoistedGlobal = chartInstance->c1_randomP;
    c1_u = c1_hoistedGlobal;
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    c1_stateGame(chartInstance);
    c1_stateIdleGaze(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
    switch (chartInstance->c1_is_stateIdlePose) {
     case c1_IN_stateBoredPose:
      CV_STATE_EVAL(40, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_bf_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_out = CV_EML_IF(31, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i3 >= 1));
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateBoredPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateIdlePose = c1_IN_stateRandomPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateRandomPose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yc_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 14U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
        chartInstance->c1_b = chartInstance->c1_BOREDOMT -
          chartInstance->c1_bored;
        c1_updateDataWrittenToVector(chartInstance, 19U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 20U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ad_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 20U);
        c1_dv2[0] = 1.0;
        c1_dv2[1] = chartInstance->c1_b;
        chartInstance->c1_randomP = c1_randi(chartInstance, c1_dv2);
        c1_updateDataWrittenToVector(chartInstance, 17U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
        sf_mex_printf("%s =\\n", "randomP");
        c1_b_hoistedGlobal = chartInstance->c1_randomP;
        c1_b_u = c1_b_hoistedGlobal;
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_b_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_stateRandomPose:
      CV_STATE_EVAL(40, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_df_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
      guard1 = false;
      if (CV_EML_COND(34, 0, 0, chartInstance->c1_randomP == 1.0)) {
        if (CV_EML_COND(34, 0, 1, chartInstance->c1_pose == 0.0)) {
          CV_EML_MCDC(34, 0, 0, true);
          CV_EML_IF(34, 0, 0, true);
          c1_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 19U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(34, 0, 0, false);
        CV_EML_IF(34, 0, 0, false);
        c1_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateRandomPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateIdlePose = c1_IN_stateBoredPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i3 = 0U;
        chartInstance->c1_tp_stateBoredPose = 1U;
        c1_enter_atomic_stateBoredPose(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_cf_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
        c1_c_out = CV_EML_IF(30, 0, 0, chartInstance->c1_randomP != 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateRandomPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateIdlePose = c1_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateRandomPose = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yc_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 14U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
          chartInstance->c1_b = chartInstance->c1_BOREDOMT -
            chartInstance->c1_bored;
          c1_updateDataWrittenToVector(chartInstance, 19U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 20U);
          _SFD_SYMBOL_SCOPE_POP();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ad_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 20U);
          c1_dv3[0] = 1.0;
          c1_dv3[1] = chartInstance->c1_b;
          chartInstance->c1_randomP = c1_randi(chartInstance, c1_dv3);
          c1_updateDataWrittenToVector(chartInstance, 17U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
          sf_mex_printf("%s =\\n", "randomP");
          c1_c_hoistedGlobal = chartInstance->c1_randomP;
          c1_c_u = c1_c_hoistedGlobal;
          c1_c_y = NULL;
          sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_c_y);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                       chartInstance->c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_af_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U,
            c1_c_sf_marshallOut, c1_c_sf_marshallIn);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 19U);
          c1_d_out = CV_EML_IF(35, 0, 0, chartInstance->c1_pose != 0.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c1_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_stateRandomPose = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
            chartInstance->c1_is_stateIdlePose = c1_IN_stateRandomPose;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
            chartInstance->c1_tp_stateRandomPose = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yc_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 14U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
            chartInstance->c1_b = chartInstance->c1_BOREDOMT -
              chartInstance->c1_bored;
            c1_updateDataWrittenToVector(chartInstance, 19U);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_b, 20U);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ad_debug_family_names,
              c1_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargin, 0U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_m_nargout, 1U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 20U);
            c1_dv4[0] = 1.0;
            c1_dv4[1] = chartInstance->c1_b;
            chartInstance->c1_randomP = c1_randi(chartInstance, c1_dv4);
            c1_updateDataWrittenToVector(chartInstance, 17U);
            _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomP, 18U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 18U);
            sf_mex_printf("%s =\\n", "randomP");
            c1_d_hoistedGlobal = chartInstance->c1_randomP;
            c1_d_u = c1_d_hoistedGlobal;
            c1_d_y = NULL;
            sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                          false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_d_y);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U,
                         chartInstance->c1_sfEvent);
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_STATE_EVAL(40, 0, 0);
      chartInstance->c1_is_stateIdlePose = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_stateGame(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  real_T *c1_win;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  real_T *c1_inputUser;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_stateGame) {
   case c1_IN_stateBradWin:
    CV_STATE_EVAL(11, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateBradWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 1U;
    c1_enter_atomic_stateRandom1(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateCompare:
    CV_STATE_EVAL(11, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_le_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
    c1_out = CV_EML_IF(10, 0, 0, chartInstance->c1_diff == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateBradWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateBradWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_rb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      *c1_win = 2.0;
      c1_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 8U, 9U);
      (*c1_bWinT)++;
      c1_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ke_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      c1_b_out = CV_EML_IF(1, 0, 0, chartInstance->c1_diff == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateUserWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_stateUserWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_pb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        chartInstance->c1_pose = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
        *c1_win = 1.0;
        c1_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 10U);
        (*c1_uWinT)++;
        c1_updateDataWrittenToVector(chartInstance, 9U);
        _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_me_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
        guard2 = false;
        if (CV_EML_COND(7, 0, 0, chartInstance->c1_diff != 1.0)) {
          if (CV_EML_COND(7, 0, 1, chartInstance->c1_diff != 2.0)) {
            CV_EML_MCDC(7, 0, 0, true);
            CV_EML_IF(7, 0, 0, true);
            c1_c_out = true;
          } else {
            guard2 = true;
          }
        } else {
          c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(7, 0, 0, false);
          CV_EML_IF(7, 0, 0, false);
          c1_c_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateCompare = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateGame = c1_IN_stateNoWin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i1 = 0U;
          chartInstance->c1_tp_stateNoWin = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_qb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          *c1_win = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
          chartInstance->c1_pose = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                       chartInstance->c1_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateGo:
    CV_STATE_EVAL(11, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_yd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_d_out = CV_EML_IF(3, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateGo = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateRandomHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandomHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      c1_b_r = c1_rand(chartInstance);
      c1_x = c1_b_r * 3.0;
      c1_b_x = c1_x;
      c1_b_x = muDoubleScalarFloor(c1_b_x);
      c1_b_r = c1_b_x;
      chartInstance->c1_bHand = c1_b_r;
      c1_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_bHand, 8U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateNoWin:
    CV_STATE_EVAL(11, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ne_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_e_out = CV_EML_IF(8, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateNoWin = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandom1 = 1U;
      c1_enter_atomic_stateRandom1(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_statePoseFingersCLose:
    CV_STATE_EVAL(11, 0, 5);
    c1_statePoseFingersCLose(chartInstance);
    break;

   case c1_IN_statePosePaper:
    CV_STATE_EVAL(11, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ee_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(42, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                    (chartInstance->c1_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(42, 0, 1, chartInstance->c1_uHand != 3.0)) {
        CV_EML_MCDC(42, 0, 0, true);
        CV_EML_IF(42, 0, 0, true);
        c1_f_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(42, 0, 0, false);
      CV_EML_IF(42, 0, 0, false);
      c1_f_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePosePaper = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateReadUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      chartInstance->c1_uHand = *c1_inputUser;
      c1_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_statePoseReady:
    CV_STATE_EVAL(11, 0, 7);
    c1_statePoseReady(chartInstance);
    break;

   case c1_IN_statePoseReturnFinger:
    CV_STATE_EVAL(11, 0, 8);
    c1_statePoseReturnFinger(chartInstance);
    break;

   case c1_IN_statePoseReturnWrist:
    CV_STATE_EVAL(11, 0, 9);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnWrist = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_lb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    *c1_gameState = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    *c1_bradHand = chartInstance->c1_bHand;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    *c1_userHand = chartInstance->c1_uHand;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_statePoseRock:
    CV_STATE_EVAL(11, 0, 10);
    c1_statePoseRock(chartInstance);
    break;

   case c1_IN_statePoseScissors:
    CV_STATE_EVAL(11, 0, 11);
    c1_statePoseScissors(chartInstance);
    break;

   case c1_IN_statePoseSmile:
    CV_STATE_EVAL(11, 0, 12);
    c1_statePoseSmile(chartInstance);
    break;

   case c1_IN_statePoseSmileWin:
    CV_STATE_EVAL(11, 0, 13);
    c1_statePoseSmileWin(chartInstance);
    break;

   case c1_IN_stateRandom:
    CV_STATE_EVAL(11, 0, 14);
    c1_stateRandom(chartInstance);
    break;

   case c1_IN_stateRandom1:
    CV_STATE_EVAL(11, 0, 15);
    c1_stateRandom1(chartInstance);
    break;

   case c1_IN_stateRandomHand:
    CV_STATE_EVAL(11, 0, 16);
    c1_stateRandomHand(chartInstance);
    break;

   case c1_IN_stateReadUserHand:
    CV_STATE_EVAL(11, 0, 17);
    c1_stateReadUserHand(chartInstance);
    break;

   case c1_IN_stateReady:
    CV_STATE_EVAL(11, 0, 18);
    c1_stateReady(chartInstance);
    break;

   case c1_IN_stateShowHands:
    CV_STATE_EVAL(11, 0, 19);
    c1_stateShowHands(chartInstance);
    break;

   case c1_IN_stateShowResult:
    CV_STATE_EVAL(11, 0, 20);
    c1_stateShowResult(chartInstance);
    break;

   case c1_IN_stateStart:
    CV_STATE_EVAL(11, 0, 21);
    c1_stateStart(chartInstance);
    break;

   case c1_IN_stateUserWin:
    CV_STATE_EVAL(11, 0, 22);
    c1_stateUserWin(chartInstance);
    break;

   case c1_IN_stateWristRotate:
    CV_STATE_EVAL(11, 0, 23);
    c1_stateWristRotate(chartInstance);
    break;

   default:
    CV_STATE_EVAL(11, 0, 0);
    chartInstance->c1_is_stateGame = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
}

static void c1_stateStart
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_od_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(17, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 2));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateStart = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReady = 1U;
    c1_enter_atomic_stateReady(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_gameState;
  real_T *c1_win;
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_y_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  *c1_bradHand = 3.0;
  c1_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  *c1_userHand = 3.0;
  c1_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  *c1_gameState = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  *c1_win = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 14U);
  c1_out = CV_EML_IF(4, 0, 0, chartInstance->c1_bored <
                     chartInstance->c1_BOREDOMT - 6.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_sd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
    chartInstance->c1_bored++;
    c1_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_bored, 13U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
    sf_mex_printf("%s =\\n", "bored");
    c1_hoistedGlobal = chartInstance->c1_bored;
    c1_u = c1_hoistedGlobal;
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseReady = 1U;
    c1_enter_atomic_statePoseReady(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseReady = 1U;
    c1_enter_atomic_statePoseReady(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
}

static void c1_stateRandom
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_dv5[256];
  int32_T c1_i8;
  real_T c1_arg[256];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T *c1_gameState;
  real_T (*c1_b_arg)[256];
  boolean_T guard1 = false;
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 12U);
  c1_out = CV_EML_IF(15, 0, 0, chartInstance->c1_smileYN == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_cb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_smileN = c1_b_randi(chartInstance);
    c1_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 11U);
    c1_hoistedGlobal = chartInstance->c1_smileN;
    c1_idlePose(chartInstance, c1_hoistedGlobal, c1_dv5);
    for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
      c1_arg[c1_i8] = c1_dv5[c1_i8];
    }

    for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i9], 30U);
    }

    _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i10 = 0; c1_i10 < 256; c1_i10++) {
      (*c1_b_arg)[c1_i10] = c1_arg[c1_i10];
    }

    for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i11], 30U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(30U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ud_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 12U);
    c1_b_out = CV_EML_IF(16, 0, 0, chartInstance->c1_smileYN != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
      c1_c_out = CV_EML_IF(51, 0, 0, chartInstance->c1_wristRotate == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateRandom = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateWristRotate;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateWristRotate = 1U;
        c1_enter_atomic_stateWristRotate(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wd_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
        c1_d_out = CV_EML_IF(52, 0, 0, chartInstance->c1_wristRotate != 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateRandom = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateGame = c1_IN_stateGo;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i1 = 0U;
          chartInstance->c1_tp_stateGo = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_db_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          chartInstance->c1_pose = 1.0;
          c1_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
          *c1_gameState = 1.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_statePoseReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv6[256];
  int32_T c1_i12;
  real_T c1_arg[256];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  real_T c1_dv7[256];
  int32_T c1_i16;
  real_T c1_b_arg[256];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T (*c1_c_arg)[256];
  real_T (*c1_d_arg)[256];
  c1_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_bb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_idlePose(chartInstance, 8.0, c1_dv6);
  for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
    c1_arg[c1_i12] = c1_dv6[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 256; c1_i13++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i13], 30U);
  }

  _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i14 = 0; c1_i14 < 256; c1_i14++) {
    (*c1_d_arg)[c1_i14] = c1_arg[c1_i14];
  }

  for (c1_i15 = 0; c1_i15 < 256; c1_i15++) {
    _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i15], 30U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(30U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  c1_handPoseSB(chartInstance, 2.0, c1_dv7);
  for (c1_i16 = 0; c1_i16 < 256; c1_i16++) {
    c1_b_arg[c1_i16] = c1_dv7[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
    _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i17], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c1_b_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i18 = 0; c1_i18 < 256; c1_i18++) {
    (*c1_c_arg)[c1_i18] = c1_b_arg[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 256; c1_i19++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_arg)[c1_i19], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 2.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  c1_b_r = c1_b_x;
  chartInstance->c1_wristRotate = c1_b_r;
  c1_updateDataWrittenToVector(chartInstance, 26U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_wristRotate, 27U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_statePoseReady
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv8[2];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_td_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(22, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(22, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(22, 0, 0, true);
      CV_EML_IF(22, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(22, 0, 0, false);
    CV_EML_IF(22, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ab_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 13U);
    c1_dv8[0] = 0.0;
    c1_dv8[1] = chartInstance->c1_bored;
    chartInstance->c1_smileYN = c1_randi(chartInstance, c1_dv8);
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
}

static void c1_statePoseSmile
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T *c1_gameState;
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
  c1_out = CV_EML_IF(51, 0, 0, chartInstance->c1_wristRotate == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateWristRotate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateWristRotate = 1U;
    c1_enter_atomic_stateWristRotate(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
    c1_b_out = CV_EML_IF(52, 0, 0, chartInstance->c1_wristRotate != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePoseSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateGo;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateGo = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_db_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      *c1_gameState = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateWristRotate
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv9[256];
  int32_T c1_i20;
  real_T c1_arg[256];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_eb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  c1_handPoseSB(chartInstance, 5.0, c1_dv9);
  for (c1_i20 = 0; c1_i20 < 256; c1_i20++) {
    c1_arg[c1_i20] = c1_dv9[c1_i20];
  }

  for (c1_i21 = 0; c1_i21 < 256; c1_i21++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i21], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i22 = 0; c1_i22 < 256; c1_i22++) {
    (*c1_b_arg)[c1_i22] = c1_arg[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 256; c1_i23++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i23], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateWristRotate
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_gameState;
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateWristRotate = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_stateGo;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateGo = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_db_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  *c1_gameState = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
}

static void c1_stateRandomHand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_bmlID;
  uint32_T c1_c_debug_family_var_map[6];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  real_T c1_c_nargin = 1.0;
  real_T c1_c_nargout = 1.0;
  real_T c1_poseBML[256];
  real_T c1_dv10[256];
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i30;
  real_T c1_arg[256];
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_bmlID;
  boolean_T c1_b_aVarTruthTableCondition_1;
  boolean_T c1_b_aVarTruthTableCondition_2;
  real_T c1_f_nargin = 1.0;
  real_T c1_f_nargout = 1.0;
  real_T c1_b_poseBML[256];
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  uint32_T c1_d_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_g_nargin = 1.0;
  real_T c1_g_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i36;
  static char_T c1_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i37;
  static real_T c1_dv11[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i43;
  int32_T c1_i44;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i45;
  real_T c1_b_arg[256];
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_dv12[256];
  int32_T c1_i49;
  real_T c1_c_arg[256];
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  real_T (*c1_d_arg)[256];
  real_T (*c1_e_arg)[256];
  c1_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ce_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
  c1_out = CV_EML_IF(40, 0, 0, chartInstance->c1_bHand == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ib_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_p = c1_c_randi(chartInstance);
    c1_updateDataWrittenToVector(chartInstance, 21U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_p, 22U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 22U);
    c1_hoistedGlobal = chartInstance->c1_p;
    c1_bmlID = c1_hoistedGlobal;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_d_debug_family_names,
      c1_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
      c1_c_sf_marshallOut, c1_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
      c1_c_sf_marshallOut, c1_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 3U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 4U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 5U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    CV_EML_FCN(6, 0);
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 3);
    c1_aVarTruthTableCondition_1 = false;
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 4);
    c1_aVarTruthTableCondition_2 = false;
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 9);
    c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 13);
    c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 15);
    if (CV_EML_IF(6, 1, 0, c1_aVarTruthTableCondition_1)) {
      _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 16);
      CV_EML_FCN(6, 1);
      _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 27);
      c1_b_encStr2Arr(chartInstance, c1_dv10);
      for (c1_i24 = 0; c1_i24 < 256; c1_i24++) {
        c1_poseBML[c1_i24] = c1_dv10[c1_i24];
      }

      c1_updateDataWrittenToVector(chartInstance, 29U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 29U, 34U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i25 = 0; c1_i25 < 256; c1_i25++) {
        c1_u[c1_i25] = c1_poseBML[c1_i25];
      }

      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
      _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -27);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 17);
      if (CV_EML_IF(6, 1, 1, c1_aVarTruthTableCondition_2)) {
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 18);
        CV_EML_FCN(6, 2);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 33);
        c1_c_encStr2Arr(chartInstance, c1_dv10);
        for (c1_i26 = 0; c1_i26 < 256; c1_i26++) {
          c1_poseBML[c1_i26] = c1_dv10[c1_i26];
        }

        c1_updateDataWrittenToVector(chartInstance, 29U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 29U, 34U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i27 = 0; c1_i27 < 256; c1_i27++) {
          c1_b_u[c1_i27] = c1_poseBML[c1_i27];
        }

        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_b_y);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -33);
      } else {
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 20);
        CV_EML_FCN(6, 2);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, 33);
        c1_c_encStr2Arr(chartInstance, c1_dv10);
        for (c1_i28 = 0; c1_i28 < 256; c1_i28++) {
          c1_poseBML[c1_i28] = c1_dv10[c1_i28];
        }

        c1_updateDataWrittenToVector(chartInstance, 29U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 29U, 34U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i29 = 0; c1_i29 < 256; c1_i29++) {
          c1_c_u[c1_i29] = c1_poseBML[c1_i29];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -33);
      }
    }

    _SFD_EML_CALL(6U, chartInstance->c1_sfEvent, -20);
    _SFD_SYMBOL_SCOPE_POP();
    for (c1_i30 = 0; c1_i30 < 256; c1_i30++) {
      c1_arg[c1_i30] = c1_poseBML[c1_i30];
    }

    for (c1_i31 = 0; c1_i31 < 256; c1_i31++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i31], 30U);
    }

    _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i32 = 0; c1_i32 < 256; c1_i32++) {
      (*c1_e_arg)[c1_i32] = c1_arg[c1_i32];
    }

    for (c1_i33 = 0; c1_i33 < 256; c1_i33++) {
      _SFD_DATA_RANGE_CHECK((*c1_e_arg)[c1_i33], 30U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(30U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_be_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    c1_b_out = CV_EML_IF(41, 0, 0, chartInstance->c1_bHand == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_gb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      chartInstance->c1_r = c1_c_randi(chartInstance);
      c1_updateDataWrittenToVector(chartInstance, 20U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 21U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 20U, 21U);
      c1_b_hoistedGlobal = chartInstance->c1_r;
      c1_b_bmlID = c1_b_hoistedGlobal;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_debug_family_names,
        c1_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_aVarTruthTableCondition_1, 0U,
        c1_c_sf_marshallOut, c1_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_aVarTruthTableCondition_2, 1U,
        c1_c_sf_marshallOut, c1_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 3U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_bmlID, 4U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_poseBML, 5U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      CV_EML_FCN(7, 0);
      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 3);
      c1_b_aVarTruthTableCondition_1 = false;
      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 4);
      c1_b_aVarTruthTableCondition_2 = false;
      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 9);
      c1_b_aVarTruthTableCondition_1 = (c1_b_bmlID == 1.0);
      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 13);
      c1_b_aVarTruthTableCondition_2 = (c1_b_bmlID == 2.0);
      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 15);
      if (CV_EML_IF(7, 1, 0, c1_b_aVarTruthTableCondition_1)) {
        _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 16);
        CV_EML_FCN(7, 1);
        _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 27);
        c1_encStr2Arr(chartInstance, c1_dv10);
        for (c1_i34 = 0; c1_i34 < 256; c1_i34++) {
          c1_b_poseBML[c1_i34] = c1_dv10[c1_i34];
        }

        c1_updateDataWrittenToVector(chartInstance, 28U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 28U, 32U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i35 = 0; c1_i35 < 256; c1_i35++) {
          c1_d_u[c1_i35] = c1_b_poseBML[c1_i35];
        }

        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_d_y);
        _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, -27);
      } else {
        _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 17);
        if (CV_EML_IF(7, 1, 1, c1_b_aVarTruthTableCondition_2)) {
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 18);
          CV_EML_FCN(7, 2);
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 33);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_c_debug_family_names,
            c1_d_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_f_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
            c1_d_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_e_sf_marshallOut);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 6U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 7U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
            c1_d_sf_marshallOut, c1_d_sf_marshallIn);
          for (c1_i36 = 0; c1_i36 < 94; c1_i36++) {
            c1_mystr[c1_i36] = c1_cv0[c1_i36];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
          c1_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
          for (c1_i37 = 0; c1_i37 < 94; c1_i37++) {
            c1_arr[c1_i37] = c1_dv11[c1_i37];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
          c1_ss = 94.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
          c1_padsize = c1_maxarrsize - c1_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
          for (c1_i38 = 0; c1_i38 < 256; c1_i38++) {
            c1_tt[c1_i38] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
          for (c1_i39 = 0; c1_i39 < 94; c1_i39++) {
            c1_tt[c1_i39] = c1_arr[c1_i39];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
          for (c1_i40 = 0; c1_i40 < 256; c1_i40++) {
            c1_myarr256[c1_i40] = c1_tt[c1_i40];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c1_i41 = 0; c1_i41 < 256; c1_i41++) {
            c1_b_poseBML[c1_i41] = c1_myarr256[c1_i41];
          }

          c1_updateDataWrittenToVector(chartInstance, 28U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 28U, 32U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i42 = 0; c1_i42 < 256; c1_i42++) {
            c1_e_u[c1_i42] = c1_b_poseBML[c1_i42];
          }

          c1_e_y = NULL;
          sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_e_y);
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, -33);
        } else {
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 20);
          CV_EML_FCN(7, 1);
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, 27);
          c1_encStr2Arr(chartInstance, c1_dv10);
          for (c1_i43 = 0; c1_i43 < 256; c1_i43++) {
            c1_b_poseBML[c1_i43] = c1_dv10[c1_i43];
          }

          c1_updateDataWrittenToVector(chartInstance, 28U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 28U, 32U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i44 = 0; c1_i44 < 256; c1_i44++) {
            c1_f_u[c1_i44] = c1_b_poseBML[c1_i44];
          }

          c1_f_y = NULL;
          sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_f_y);
          _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, -27);
        }
      }

      _SFD_EML_CALL(7U, chartInstance->c1_sfEvent, -20);
      _SFD_SYMBOL_SCOPE_POP();
      for (c1_i45 = 0; c1_i45 < 256; c1_i45++) {
        c1_b_arg[c1_i45] = c1_b_poseBML[c1_i45];
      }

      for (c1_i46 = 0; c1_i46 < 256; c1_i46++) {
        _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i46], 30U);
      }

      _SFD_SET_DATA_VALUE_PTR(30U, c1_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      for (c1_i47 = 0; c1_i47 < 256; c1_i47++) {
        (*c1_e_arg)[c1_i47] = c1_b_arg[c1_i47];
      }

      for (c1_i48 = 0; c1_i48 < 256; c1_i48++) {
        _SFD_DATA_RANGE_CHECK((*c1_e_arg)[c1_i48], 30U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(30U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ae_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
      c1_c_out = CV_EML_IF(11, 0, 0, chartInstance->c1_bHand == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateRandomHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_hb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        chartInstance->c1_pose = 1.0;
        c1_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
        c1_handPoseSB(chartInstance, 1.0, c1_dv12);
        for (c1_i49 = 0; c1_i49 < 256; c1_i49++) {
          c1_c_arg[c1_i49] = c1_dv12[c1_i49];
        }

        for (c1_i50 = 0; c1_i50 < 256; c1_i50++) {
          _SFD_DATA_RANGE_CHECK(c1_c_arg[c1_i50], 29U);
        }

        _SFD_SET_DATA_VALUE_PTR(29U, c1_c_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_c_arg, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c1_sfEvent);
        for (c1_i51 = 0; c1_i51 < 256; c1_i51++) {
          (*c1_d_arg)[c1_i51] = c1_c_arg[c1_i51];
        }

        for (c1_i52 = 0; c1_i52 < 256; c1_i52++) {
          _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i52], 29U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(29U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                     chartInstance->c1_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c1_sfEvent);
}

static void c1_statePoseRock
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T *c1_inputUser;
  boolean_T guard1 = false;
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_de_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(43, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(43, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(43, 0, 0, true);
      CV_EML_IF(43, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(43, 0, 0, false);
    CV_EML_IF(43, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c1_sfEvent);
}

static void c1_statePoseFingersCLose
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_bmlID;
  uint32_T c1_b_debug_family_var_map[6];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_poseBML[256];
  real_T c1_dv13[256];
  int32_T c1_i53;
  int32_T c1_i54;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i59;
  real_T c1_arg[256];
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_kb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  chartInstance->c1_s = c1_c_randi(chartInstance);
  c1_updateDataWrittenToVector(chartInstance, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_s, 23U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 23U);
  c1_hoistedGlobal = chartInstance->c1_s;
  c1_bmlID = c1_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_g_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(8, 0);
  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 13);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 15);
  if (CV_EML_IF(8, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 16);
    CV_EML_FCN(8, 1);
    _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 27);
    c1_c_encStr2Arr(chartInstance, c1_dv13);
    for (c1_i53 = 0; c1_i53 < 256; c1_i53++) {
      c1_poseBML[c1_i53] = c1_dv13[c1_i53];
    }

    c1_updateDataWrittenToVector(chartInstance, 30U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 30U, 36U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i54 = 0; c1_i54 < 256; c1_i54++) {
      c1_u[c1_i54] = c1_poseBML[c1_i54];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, -27);
  } else {
    _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 17);
    if (CV_EML_IF(8, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 18);
      CV_EML_FCN(8, 2);
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 33);
      c1_b_encStr2Arr(chartInstance, c1_dv13);
      for (c1_i55 = 0; c1_i55 < 256; c1_i55++) {
        c1_poseBML[c1_i55] = c1_dv13[c1_i55];
      }

      c1_updateDataWrittenToVector(chartInstance, 30U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 30U, 36U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i56 = 0; c1_i56 < 256; c1_i56++) {
        c1_b_u[c1_i56] = c1_poseBML[c1_i56];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, -33);
    } else {
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 20);
      CV_EML_FCN(8, 1);
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, 27);
      c1_c_encStr2Arr(chartInstance, c1_dv13);
      for (c1_i57 = 0; c1_i57 < 256; c1_i57++) {
        c1_poseBML[c1_i57] = c1_dv13[c1_i57];
      }

      c1_updateDataWrittenToVector(chartInstance, 30U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 30U, 36U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i58 = 0; c1_i58 < 256; c1_i58++) {
        c1_c_u[c1_i58] = c1_poseBML[c1_i58];
      }

      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_c_y);
      _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(8U, chartInstance->c1_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i59 = 0; c1_i59 < 256; c1_i59++) {
    c1_arg[c1_i59] = c1_poseBML[c1_i59];
  }

  for (c1_i60 = 0; c1_i60 < 256; c1_i60++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i60], 30U);
  }

  _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i61 = 0; c1_i61 < 256; c1_i61++) {
    (*c1_b_arg)[c1_i61] = c1_arg[c1_i61];
  }

  for (c1_i62 = 0; c1_i62 < 256; c1_i62++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i62], 30U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(30U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
}

static void c1_stateReadUserHand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_dv14[256];
  int32_T c1_i63;
  real_T c1_arg[256];
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_inputUser;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fe_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
  c1_out = CV_EML_IF(0, 0, 0, chartInstance->c1_uHand == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ie_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    c1_b_out = CV_EML_IF(38, 0, 0, chartInstance->c1_bHand == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_mb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      c1_handPoseSB(chartInstance, 2.0, c1_dv14);
      for (c1_i63 = 0; c1_i63 < 256; c1_i63++) {
        c1_arg[c1_i63] = c1_dv14[c1_i63];
      }

      for (c1_i64 = 0; c1_i64 < 256; c1_i64++) {
        _SFD_DATA_RANGE_CHECK(c1_arg[c1_i64], 29U);
      }

      _SFD_SET_DATA_VALUE_PTR(29U, c1_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
      for (c1_i65 = 0; c1_i65 < 256; c1_i65++) {
        (*c1_b_arg)[c1_i65] = c1_arg[c1_i65];
      }

      for (c1_i66 = 0; c1_i66 < 256; c1_i66++) {
        _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i66], 29U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(29U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_he_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
      c1_c_out = CV_EML_IF(45, 0, 0, chartInstance->c1_wristRotate == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_statePoseReturnWrist;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_statePoseReturnWrist = 1U;
        c1_enter_atomic_statePoseReturnWrist(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateShowHands = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_lb_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        chartInstance->c1_pose = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
        *c1_gameState = 2.0;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
        *c1_bradHand = chartInstance->c1_bHand;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
        *c1_userHand = chartInstance->c1_uHand;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c1_sfEvent);
}

static void c1_statePoseScissors
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T *c1_inputUser;
  boolean_T guard1 = false;
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ge_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(2, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(2, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(2, 0, 0, false);
    CV_EML_IF(2, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseScissors = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 1.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c1_sfEvent);
}

static void c1_stateShowHands
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_d_x;
  real_T c1_e_x;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateShowHands = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_nb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  chartInstance->c1_pose = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
  chartInstance->c1_temp = chartInstance->c1_uHand - chartInstance->c1_bHand;
  c1_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_temp, 5U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 4U, 5U);
  c1_hoistedGlobal = chartInstance->c1_temp;
  c1_b_hoistedGlobal = chartInstance->c1_temp;
  c1_A = c1_b_hoistedGlobal;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = c1_c_x / 3.0;
  c1_d_x = c1_y;
  c1_e_x = c1_d_x;
  c1_e_x = muDoubleScalarFloor(c1_e_x);
  chartInstance->c1_diff = c1_hoistedGlobal - 3.0 * c1_e_x;
  c1_updateDataWrittenToVector(chartInstance, 4U);
  c1_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_diff, 6U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c1_sfEvent);
}

static void c1_statePoseReturnFinger
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_je_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 26U, 27U);
  c1_out = CV_EML_IF(46, 0, 0, chartInstance->c1_wristRotate == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReturnWrist;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnWrist = 1U;
    c1_enter_atomic_statePoseReturnWrist(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_lb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    *c1_gameState = 2.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    *c1_bradHand = chartInstance->c1_bHand;
    c1_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    *c1_userHand = chartInstance->c1_uHand;
    c1_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_statePoseReturnWrist
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv15[256];
  int32_T c1_i67;
  real_T c1_arg[256];
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 7);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ob_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  chartInstance->c1_pose = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  c1_handPoseSB(chartInstance, 6.0, c1_dv15);
  for (c1_i67 = 0; c1_i67 < 256; c1_i67++) {
    c1_arg[c1_i67] = c1_dv15[c1_i67];
  }

  for (c1_i68 = 0; c1_i68 < 256; c1_i68++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i68], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i69 = 0; c1_i69 < 256; c1_i69++) {
    (*c1_b_arg)[c1_i69] = c1_arg[c1_i69];
  }

  for (c1_i70 = 0; c1_i70 < 256; c1_i70++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i70], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateUserWin
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_oe_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(9, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateUserWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 1U;
    c1_enter_atomic_stateRandom1(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateRandom1
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_sb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 4.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  c1_b_r = c1_b_x;
  chartInstance->c1_smileYN = c1_b_r;
  c1_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
  chartInstance->c1_pose = 0.0;
  c1_updateDataWrittenToVector(chartInstance, 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateRandom1
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_dv16[256];
  int32_T c1_i71;
  real_T c1_arg[256];
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_pe_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 12U);
  c1_out = CV_EML_IF(19, 0, 0, chartInstance->c1_smileYN == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseSmileWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseSmileWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_tb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_smileN = c1_b_randi(chartInstance);
    c1_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 11U);
    c1_hoistedGlobal = chartInstance->c1_smileN;
    c1_idlePose(chartInstance, c1_hoistedGlobal, c1_dv16);
    for (c1_i71 = 0; c1_i71 < 256; c1_i71++) {
      c1_arg[c1_i71] = c1_dv16[c1_i71];
    }

    for (c1_i72 = 0; c1_i72 < 256; c1_i72++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i72], 30U);
    }

    _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i73 = 0; c1_i73 < 256; c1_i73++) {
      (*c1_b_arg)[c1_i73] = c1_arg[c1_i73];
    }

    for (c1_i74 = 0; c1_i74 < 256; c1_i74++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i74], 30U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(30U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    chartInstance->c1_pose = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 11U, 12U);
    c1_b_out = CV_EML_IF(23, 0, 0, chartInstance->c1_smileYN != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandom1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ub_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_pose = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c1_sfEvent);
}

static void c1_statePoseSmileWin
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_re_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(20, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseSmileWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ub_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    chartInstance->c1_pose = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_pose, 19U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c1_sfEvent);
}

static void c1_stateShowResult
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(18, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 3));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowResult = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReady = 1U;
    c1_enter_atomic_stateReady(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
}

static void c1_stateIdleGaze
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  boolean_T c1_b_temp;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  boolean_T c1_c_temp;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_dv17[256];
  int32_T c1_i75;
  real_T c1_arg[256];
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_stateIdleGaze) {
   case c1_IN_stateAvertGaze:
    CV_STATE_EVAL(35, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ue_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 25U, 26U);
    c1_b_temp = (chartInstance->c1_sfEvent == c1_event_secs);
    if (c1_b_temp) {
      c1_b_temp = (chartInstance->c1_temporalCounter_i2 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
        chartInstance->c1_randomD, 32U, 28U));
    }

    c1_out = CV_EML_IF(28, 0, 0, c1_b_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateIdleGaze = c1_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateInitial = 1U;
      c1_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateAvertHead:
    CV_STATE_EVAL(35, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ye_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 27U, 28U);
    c1_c_temp = (chartInstance->c1_sfEvent == c1_event_secs);
    if (c1_c_temp) {
      c1_c_temp = (chartInstance->c1_temporalCounter_i2 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
        chartInstance->c1_randomH, 32U, 48U));
    }

    c1_b_out = CV_EML_IF(48, 0, 0, c1_c_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateAvertHead = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateIdleGaze = c1_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i2 = 0U;
      chartInstance->c1_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_wb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_idlePose(chartInstance, 8.0, c1_dv17);
      for (c1_i75 = 0; c1_i75 < 256; c1_i75++) {
        c1_arg[c1_i75] = c1_dv17[c1_i75];
      }

      for (c1_i76 = 0; c1_i76 < 256; c1_i76++) {
        _SFD_DATA_RANGE_CHECK(c1_arg[c1_i76], 30U);
      }

      _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      for (c1_i77 = 0; c1_i77 < 256; c1_i77++) {
        (*c1_b_arg)[c1_i77] = c1_arg[c1_i77];
      }

      for (c1_i78 = 0; c1_i78 < 256; c1_i78++) {
        _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i78], 30U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(30U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateHeadNeutral:
    CV_STATE_EVAL(35, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_se_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_c_out = CV_EML_IF(53, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i2 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateIdleGaze = c1_IN_stateInitial;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateInitial = 1U;
      c1_enter_atomic_stateInitial(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateInitial:
    CV_STATE_EVAL(35, 0, 4);
    c1_stateInitial(chartInstance);
    break;

   default:
    CV_STATE_EVAL(35, 0, 0);
    chartInstance->c1_is_stateIdleGaze = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateInitial
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_c_r;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_d_r;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_vb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 8.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  c1_b_r = 1.0 + c1_b_x;
  chartInstance->c1_randomG = c1_b_r;
  c1_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomG, 16U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 16U);
  sf_mex_printf("%s =\\n", "randomG");
  c1_hoistedGlobal = chartInstance->c1_randomG;
  c1_u = c1_hoistedGlobal;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
  c1_c_r = c1_rand(chartInstance);
  c1_c_x = c1_c_r * 4.0;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarFloor(c1_d_x);
  c1_c_r = 1.0 + c1_d_x;
  chartInstance->c1_randomD = c1_c_r;
  c1_updateDataWrittenToVector(chartInstance, 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomD, 26U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 25U, 26U);
  sf_mex_printf("%s =\\n", "randomD");
  c1_b_hoistedGlobal = chartInstance->c1_randomD;
  c1_b_u = c1_b_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
  c1_d_r = c1_rand(chartInstance);
  c1_e_x = c1_d_r * 3.0;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarFloor(c1_f_x);
  c1_d_r = 5.0 + c1_f_x;
  chartInstance->c1_randomH = c1_d_r;
  c1_updateDataWrittenToVector(chartInstance, 27U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomH, 28U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 27U, 28U);
  sf_mex_printf("%s =\\n", "randomH");
  c1_c_hoistedGlobal = chartInstance->c1_randomH;
  c1_c_u = c1_c_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_c_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateInitial
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_dv18[256];
  int32_T c1_i79;
  real_T c1_arg[256];
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 0.0;
  real_T c1_c_r;
  real_T c1_c_x;
  real_T c1_d_x;
  int32_T c1_i83;
  real_T c1_b_arg[256];
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 1.0;
  boolean_T c1_d_out;
  real_T (*c1_c_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c1_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_te_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 19U);
  c1_out = CV_EML_IF(33, 0, 0, chartInstance->c1_pose != 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateIdleGaze = c1_IN_stateInitial;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateInitial = 1U;
    c1_enter_atomic_stateInitial(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xe_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 16U);
    guard3 = false;
    if (CV_EML_COND(32, 0, 0, chartInstance->c1_randomG > 4.0)) {
      if (CV_EML_COND(32, 0, 1, chartInstance->c1_pose == 0.0)) {
        CV_EML_MCDC(32, 0, 0, true);
        CV_EML_IF(32, 0, 0, true);
        c1_b_out = true;
      } else {
        guard3 = true;
      }
    } else {
      c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 19U);
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(32, 0, 0, false);
      CV_EML_IF(32, 0, 0, false);
      c1_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateInitial = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateIdleGaze = c1_IN_stateAvertGaze;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i2 = 0U;
      chartInstance->c1_tp_stateAvertGaze = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_xb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_b_r = c1_rand(chartInstance);
      c1_x = c1_b_r * 16.0;
      c1_b_x = c1_x;
      c1_b_x = muDoubleScalarFloor(c1_b_x);
      c1_b_r = 1.0 + c1_b_x;
      c1_boredGaze(chartInstance, c1_b_r, c1_dv18);
      for (c1_i79 = 0; c1_i79 < 256; c1_i79++) {
        c1_arg[c1_i79] = c1_dv18[c1_i79];
      }

      for (c1_i80 = 0; c1_i80 < 256; c1_i80++) {
        _SFD_DATA_RANGE_CHECK(c1_arg[c1_i80], 30U);
      }

      _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      for (c1_i81 = 0; c1_i81 < 256; c1_i81++) {
        (*c1_c_arg)[c1_i81] = c1_arg[c1_i81];
      }

      for (c1_i82 = 0; c1_i82 < 256; c1_i82++) {
        _SFD_DATA_RANGE_CHECK((*c1_c_arg)[c1_i82], 30U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(30U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_we_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 16U);
      guard2 = false;
      if (CV_EML_COND(37, 0, 0, chartInstance->c1_randomG == 1.0)) {
        if (CV_EML_COND(37, 0, 1, chartInstance->c1_pose == 0.0)) {
          CV_EML_MCDC(37, 0, 0, true);
          CV_EML_IF(37, 0, 0, true);
          c1_c_out = true;
        } else {
          guard2 = true;
        }
      } else {
        c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 19U);
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(37, 0, 0, false);
        CV_EML_IF(37, 0, 0, false);
        c1_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateInitial = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateIdleGaze = c1_IN_stateAvertHead;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i2 = 0U;
        chartInstance->c1_tp_stateAvertHead = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_xc_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_c_r = c1_rand(chartInstance);
        c1_c_x = c1_c_r * 16.0;
        c1_d_x = c1_c_x;
        c1_d_x = muDoubleScalarFloor(c1_d_x);
        c1_c_r = 17.0 + c1_d_x;
        c1_boredGaze(chartInstance, c1_c_r, c1_dv18);
        for (c1_i83 = 0; c1_i83 < 256; c1_i83++) {
          c1_b_arg[c1_i83] = c1_dv18[c1_i83];
        }

        for (c1_i84 = 0; c1_i84 < 256; c1_i84++) {
          _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i84], 30U);
        }

        _SFD_SET_DATA_VALUE_PTR(30U, c1_b_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c1_sfEvent);
        for (c1_i85 = 0; c1_i85 < 256; c1_i85++) {
          (*c1_c_arg)[c1_i85] = c1_b_arg[c1_i85];
        }

        for (c1_i86 = 0; c1_i86 < 256; c1_i86++) {
          _SFD_DATA_RANGE_CHECK((*c1_c_arg)[c1_i86], 30U);
        }

        sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(30U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ve_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 16U);
        guard1 = false;
        if (CV_EML_COND(27, 0, 0, 1.0 < chartInstance->c1_randomG)) {
          if (CV_EML_COND(27, 0, 1, chartInstance->c1_randomG < 5.0)) {
            CV_EML_MCDC(27, 0, 0, true);
            CV_EML_IF(27, 0, 0, true);
            c1_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 16U);
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(27, 0, 0, false);
          CV_EML_IF(27, 0, 0, false);
          c1_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateInitial = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateIdleGaze = c1_IN_stateInitial;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateInitial = 1U;
          c1_enter_atomic_stateInitial(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U,
                       chartInstance->c1_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateBoredPose
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_bmlID;
  uint32_T c1_b_debug_family_var_map[22];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  boolean_T c1_aVarTruthTableCondition_7;
  boolean_T c1_aVarTruthTableCondition_8;
  boolean_T c1_aVarTruthTableCondition_9;
  boolean_T c1_aVarTruthTableCondition_10;
  boolean_T c1_aVarTruthTableCondition_11;
  boolean_T c1_aVarTruthTableCondition_12;
  boolean_T c1_aVarTruthTableCondition_13;
  boolean_T c1_aVarTruthTableCondition_14;
  boolean_T c1_aVarTruthTableCondition_15;
  boolean_T c1_aVarTruthTableCondition_16;
  boolean_T c1_aVarTruthTableCondition_17;
  boolean_T c1_aVarTruthTableCondition_18;
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_poseBML[256];
  real_T c1_dv19[256];
  int32_T c1_i87;
  int32_T c1_i88;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  real_T c1_dv20[256];
  int32_T c1_i89;
  int32_T c1_i90;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  real_T c1_dv21[256];
  int32_T c1_i91;
  int32_T c1_i92;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  real_T c1_dv22[256];
  int32_T c1_i93;
  int32_T c1_i94;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  real_T c1_dv23[256];
  int32_T c1_i95;
  int32_T c1_i96;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  real_T c1_dv24[256];
  int32_T c1_i97;
  int32_T c1_i98;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  real_T c1_dv25[256];
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  real_T c1_dv26[256];
  int32_T c1_i101;
  int32_T c1_i102;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  real_T c1_dv27[256];
  int32_T c1_i103;
  int32_T c1_i104;
  real_T c1_i_u[256];
  const mxArray *c1_i_y = NULL;
  real_T c1_dv28[256];
  int32_T c1_i105;
  int32_T c1_i106;
  real_T c1_j_u[256];
  const mxArray *c1_j_y = NULL;
  real_T c1_dv29[256];
  int32_T c1_i107;
  int32_T c1_i108;
  real_T c1_k_u[256];
  const mxArray *c1_k_y = NULL;
  real_T c1_dv30[256];
  int32_T c1_i109;
  int32_T c1_i110;
  real_T c1_l_u[256];
  const mxArray *c1_l_y = NULL;
  real_T c1_dv31[256];
  int32_T c1_i111;
  int32_T c1_i112;
  real_T c1_m_u[256];
  const mxArray *c1_m_y = NULL;
  real_T c1_dv32[256];
  int32_T c1_i113;
  int32_T c1_i114;
  real_T c1_n_u[256];
  const mxArray *c1_n_y = NULL;
  real_T c1_dv33[256];
  int32_T c1_i115;
  int32_T c1_i116;
  real_T c1_o_u[256];
  const mxArray *c1_o_y = NULL;
  real_T c1_dv34[256];
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_p_u[256];
  const mxArray *c1_p_y = NULL;
  real_T c1_dv35[256];
  int32_T c1_i119;
  int32_T c1_i120;
  real_T c1_q_u[256];
  const mxArray *c1_q_y = NULL;
  real_T c1_dv36[256];
  int32_T c1_i121;
  int32_T c1_i122;
  real_T c1_r_u[256];
  const mxArray *c1_r_y = NULL;
  real_T c1_dv37[256];
  int32_T c1_i123;
  int32_T c1_i124;
  real_T c1_s_u[256];
  const mxArray *c1_s_y = NULL;
  int32_T c1_i125;
  real_T c1_b_poseBML[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_bd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_bmlID = c1_d_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c1_nd_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_7, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_8, 7U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_9, 8U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_10, 9U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_11, 10U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_12, 11U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_13, 12U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_14, 13U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_15, 14U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_16, 15U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_17, 16U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_18, 17U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 19U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 20U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 21U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 11);
  c1_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 12);
  c1_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 13);
  c1_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 14);
  c1_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 16);
  c1_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 17);
  c1_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 18);
  c1_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 19);
  c1_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 20);
  c1_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 24);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 27);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 30);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 33);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 36);
  c1_aVarTruthTableCondition_5 = (c1_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 39);
  c1_aVarTruthTableCondition_6 = (c1_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 42);
  c1_aVarTruthTableCondition_7 = (c1_bmlID == 7.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 45);
  c1_aVarTruthTableCondition_8 = (c1_bmlID == 8.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 48);
  c1_aVarTruthTableCondition_9 = (c1_bmlID == 9.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 51);
  c1_aVarTruthTableCondition_10 = (c1_bmlID == 10.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 54);
  c1_aVarTruthTableCondition_11 = (c1_bmlID == 11.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 57);
  c1_aVarTruthTableCondition_12 = (c1_bmlID == 12.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 60);
  c1_aVarTruthTableCondition_13 = (c1_bmlID == 13.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 63);
  c1_aVarTruthTableCondition_14 = (c1_bmlID == 14.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 66);
  c1_aVarTruthTableCondition_15 = (c1_bmlID == 15.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 69);
  c1_aVarTruthTableCondition_16 = (c1_bmlID == 16.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 72);
  c1_aVarTruthTableCondition_17 = (c1_bmlID == 17.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 75);
  c1_aVarTruthTableCondition_18 = (c1_bmlID == 18.0);
  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 77);
  if (CV_EML_IF(3, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 78);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 121);
    c1_nb_encStr2Arr(chartInstance, c1_dv19);
    for (c1_i87 = 0; c1_i87 < 256; c1_i87++) {
      c1_poseBML[c1_i87] = c1_dv19[c1_i87];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i88 = 0; c1_i88 < 256; c1_i88++) {
      c1_u[c1_i88] = c1_poseBML[c1_i88];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -121);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 79);
    if (CV_EML_IF(3, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 80);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, MAX_int8_T);
      c1_ob_encStr2Arr(chartInstance, c1_dv20);
      for (c1_i89 = 0; c1_i89 < 256; c1_i89++) {
        c1_poseBML[c1_i89] = c1_dv20[c1_i89];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i90 = 0; c1_i90 < 256; c1_i90++) {
        c1_b_u[c1_i90] = c1_poseBML[c1_i90];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -127);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 81);
      if (CV_EML_IF(3, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 82);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
        c1_pb_encStr2Arr(chartInstance, c1_dv21);
        for (c1_i91 = 0; c1_i91 < 256; c1_i91++) {
          c1_poseBML[c1_i91] = c1_dv21[c1_i91];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i92 = 0; c1_i92 < 256; c1_i92++) {
          c1_c_u[c1_i92] = c1_poseBML[c1_i92];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 83);
        if (CV_EML_IF(3, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 84);
          CV_EML_FCN(3, 4);
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 139U);
          c1_qb_encStr2Arr(chartInstance, c1_dv22);
          for (c1_i93 = 0; c1_i93 < 256; c1_i93++) {
            c1_poseBML[c1_i93] = c1_dv22[c1_i93];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i94 = 0; c1_i94 < 256; c1_i94++) {
            c1_d_u[c1_i94] = c1_poseBML[c1_i94];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -139);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 85);
          if (CV_EML_IF(3, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 86);
            CV_EML_FCN(3, 5);
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 145U);
            c1_rb_encStr2Arr(chartInstance, c1_dv23);
            for (c1_i95 = 0; c1_i95 < 256; c1_i95++) {
              c1_poseBML[c1_i95] = c1_dv23[c1_i95];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c1_i96 = 0; c1_i96 < 256; c1_i96++) {
              c1_e_u[c1_i96] = c1_poseBML[c1_i96];
            }

            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_e_y);
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -145);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 87);
            if (CV_EML_IF(3, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 88);
              CV_EML_FCN(3, 11);
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 181U);
              c1_sb_encStr2Arr(chartInstance, c1_dv24);
              for (c1_i97 = 0; c1_i97 < 256; c1_i97++) {
                c1_poseBML[c1_i97] = c1_dv24[c1_i97];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c1_i98 = 0; c1_i98 < 256; c1_i98++) {
                c1_f_u[c1_i98] = c1_poseBML[c1_i98];
              }

              c1_f_y = NULL;
              sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_f_y);
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -181);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 89);
              if (CV_EML_IF(3, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 90);
                CV_EML_FCN(3, 3);
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
                c1_pb_encStr2Arr(chartInstance, c1_dv25);
                for (c1_i99 = 0; c1_i99 < 256; c1_i99++) {
                  c1_poseBML[c1_i99] = c1_dv25[c1_i99];
                }

                sf_mex_printf("%s =\\n", "poseBML");
                for (c1_i100 = 0; c1_i100 < 256; c1_i100++) {
                  c1_g_u[c1_i100] = c1_poseBML[c1_i100];
                }

                c1_g_y = NULL;
                sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c1_g_y);
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 91);
                if (CV_EML_IF(3, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 92);
                  CV_EML_FCN(3, 5);
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 145U);
                  c1_rb_encStr2Arr(chartInstance, c1_dv26);
                  for (c1_i101 = 0; c1_i101 < 256; c1_i101++) {
                    c1_poseBML[c1_i101] = c1_dv26[c1_i101];
                  }

                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i102 = 0; c1_i102 < 256; c1_i102++) {
                    c1_h_u[c1_i102] = c1_poseBML[c1_i102];
                  }

                  c1_h_y = NULL;
                  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c1_h_y);
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 93);
                  if (CV_EML_IF(3, 1, 8, c1_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 94);
                    CV_EML_FCN(3, 3);
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 133U);
                    c1_pb_encStr2Arr(chartInstance, c1_dv27);
                    for (c1_i103 = 0; c1_i103 < 256; c1_i103++) {
                      c1_poseBML[c1_i103] = c1_dv27[c1_i103];
                    }

                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c1_i104 = 0; c1_i104 < 256; c1_i104++) {
                      c1_i_u[c1_i104] = c1_poseBML[c1_i104];
                    }

                    c1_i_y = NULL;
                    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c1_i_y);
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 95);
                    if (CV_EML_IF(3, 1, 9, c1_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 96);
                      CV_EML_FCN(3, 10);
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 175U);
                      c1_tb_encStr2Arr(chartInstance, c1_dv28);
                      for (c1_i105 = 0; c1_i105 < 256; c1_i105++) {
                        c1_poseBML[c1_i105] = c1_dv28[c1_i105];
                      }

                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c1_i106 = 0; c1_i106 < 256; c1_i106++) {
                        c1_j_u[c1_i106] = c1_poseBML[c1_i106];
                      }

                      c1_j_y = NULL;
                      sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c1_j_y);
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 97);
                      if (CV_EML_IF(3, 1, 10, c1_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 98);
                        CV_EML_FCN(3, 11);
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 181U);
                        c1_sb_encStr2Arr(chartInstance, c1_dv29);
                        for (c1_i107 = 0; c1_i107 < 256; c1_i107++) {
                          c1_poseBML[c1_i107] = c1_dv29[c1_i107];
                        }

                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c1_i108 = 0; c1_i108 < 256; c1_i108++) {
                          c1_k_u[c1_i108] = c1_poseBML[c1_i108];
                        }

                        c1_k_y = NULL;
                        sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c1_k_y);
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 99);
                        if (CV_EML_IF(3, 1, 11, c1_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 100);
                          CV_EML_FCN(3, 8);
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 163U);
                          c1_ub_encStr2Arr(chartInstance, c1_dv30);
                          for (c1_i109 = 0; c1_i109 < 256; c1_i109++) {
                            c1_poseBML[c1_i109] = c1_dv30[c1_i109];
                          }

                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c1_i110 = 0; c1_i110 < 256; c1_i110++) {
                            c1_l_u[c1_i110] = c1_poseBML[c1_i110];
                          }

                          c1_l_y = NULL;
                          sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c1_l_y);
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 101);
                          if (CV_EML_IF(3, 1, 12, c1_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 102);
                            CV_EML_FCN(3, 8);
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 163U);
                            c1_ub_encStr2Arr(chartInstance, c1_dv31);
                            for (c1_i111 = 0; c1_i111 < 256; c1_i111++) {
                              c1_poseBML[c1_i111] = c1_dv31[c1_i111];
                            }

                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c1_i112 = 0; c1_i112 < 256; c1_i112++) {
                              c1_m_u[c1_i112] = c1_poseBML[c1_i112];
                            }

                            c1_m_y = NULL;
                            sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c1_m_y);
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 103);
                            if (CV_EML_IF(3, 1, 13,
                                          c1_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 104);
                              CV_EML_FCN(3, 7);
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 157U);
                              c1_vb_encStr2Arr(chartInstance, c1_dv32);
                              for (c1_i113 = 0; c1_i113 < 256; c1_i113++) {
                                c1_poseBML[c1_i113] = c1_dv32[c1_i113];
                              }

                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c1_i114 = 0; c1_i114 < 256; c1_i114++) {
                                c1_n_u[c1_i114] = c1_poseBML[c1_i114];
                              }

                              c1_n_y = NULL;
                              sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c1_n_y);
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 105);
                              if (CV_EML_IF(3, 1, 14,
                                            c1_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 106);
                                CV_EML_FCN(3, 6);
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                              151U);
                                c1_wb_encStr2Arr(chartInstance, c1_dv33);
                                for (c1_i115 = 0; c1_i115 < 256; c1_i115++) {
                                  c1_poseBML[c1_i115] = c1_dv33[c1_i115];
                                }

                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c1_i116 = 0; c1_i116 < 256; c1_i116++) {
                                  c1_o_u[c1_i116] = c1_poseBML[c1_i116];
                                }

                                c1_o_y = NULL;
                                sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c1_o_y);
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, 107);
                                if (CV_EML_IF(3, 1, 15,
                                              c1_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                108);
                                  CV_EML_FCN(3, 5);
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                145U);
                                  c1_rb_encStr2Arr(chartInstance, c1_dv34);
                                  for (c1_i117 = 0; c1_i117 < 256; c1_i117++) {
                                    c1_poseBML[c1_i117] = c1_dv34[c1_i117];
                                  }

                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c1_i118 = 0; c1_i118 < 256; c1_i118++) {
                                    c1_p_u[c1_i118] = c1_poseBML[c1_i118];
                                  }

                                  c1_p_y = NULL;
                                  sf_mex_assign(&c1_p_y, sf_mex_create("y",
                                    c1_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c1_p_y);
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                109);
                                  if (CV_EML_IF(3, 1, 16,
                                                c1_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  110);
                                    CV_EML_FCN(3, 8);
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  163U);
                                    c1_ub_encStr2Arr(chartInstance, c1_dv35);
                                    for (c1_i119 = 0; c1_i119 < 256; c1_i119++)
                                    {
                                      c1_poseBML[c1_i119] = c1_dv35[c1_i119];
                                    }

                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c1_i120 = 0; c1_i120 < 256; c1_i120++)
                                    {
                                      c1_q_u[c1_i120] = c1_poseBML[c1_i120];
                                    }

                                    c1_q_y = NULL;
                                    sf_mex_assign(&c1_q_y, sf_mex_create("y",
                                      c1_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c1_q_y);
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(3U, chartInstance->c1_sfEvent,
                                                  111);
                                    if (CV_EML_IF(3, 1, 17,
                                                  c1_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    112);
                                      CV_EML_FCN(3, 9);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    169U);
                                      c1_xb_encStr2Arr(chartInstance, c1_dv36);
                                      for (c1_i121 = 0; c1_i121 < 256; c1_i121++)
                                      {
                                        c1_poseBML[c1_i121] = c1_dv36[c1_i121];
                                      }

                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c1_i122 = 0; c1_i122 < 256; c1_i122++)
                                      {
                                        c1_r_u[c1_i122] = c1_poseBML[c1_i122];
                                      }

                                      c1_r_y = NULL;
                                      sf_mex_assign(&c1_r_y, sf_mex_create("y",
                                        c1_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c1_r_y);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    114);
                                      CV_EML_FCN(3, 3);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
                                                    133U);
                                      c1_pb_encStr2Arr(chartInstance, c1_dv37);
                                      for (c1_i123 = 0; c1_i123 < 256; c1_i123++)
                                      {
                                        c1_poseBML[c1_i123] = c1_dv37[c1_i123];
                                      }

                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c1_i124 = 0; c1_i124 < 256; c1_i124++)
                                      {
                                        c1_s_u[c1_i124] = c1_poseBML[c1_i124];
                                      }

                                      c1_s_y = NULL;
                                      sf_mex_assign(&c1_s_y, sf_mex_create("y",
                                        c1_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c1_s_y);
                                      _SFD_EML_CALL(3U,
                                                    chartInstance->c1_sfEvent,
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

  _SFD_EML_CALL(3U, chartInstance->c1_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i125 = 0; c1_i125 < 256; c1_i125++) {
    c1_b_poseBML[c1_i125] = c1_poseBML[c1_i125];
  }

  c1_sendBML(chartInstance, c1_b_poseBML);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i126;
  static char_T c1_cv1[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i127;
  static real_T c1_dv38[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i128;
  int32_T c1_i129;
  int32_T c1_i130;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i126 = 0; c1_i126 < 94; c1_i126++) {
    c1_mystr[c1_i126] = c1_cv1[c1_i126];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i127 = 0; c1_i127 < 94; c1_i127++) {
    c1_arr[c1_i127] = c1_dv38[c1_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i128 = 0; c1_i128 < 256; c1_i128++) {
    c1_tt[c1_i128] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i129 = 0; c1_i129 < 94; c1_i129++) {
    c1_tt[c1_i129] = c1_arr[c1_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i130 = 0; c1_i130 < 256; c1_i130++) {
    c1_myarr256[c1_i130] = c1_tt[c1_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_b_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[88];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[88];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i131;
  static char_T c1_cv2[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i132;
  static real_T c1_dv39[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i133;
  int32_T c1_i134;
  int32_T c1_i135;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i131 = 0; c1_i131 < 88; c1_i131++) {
    c1_mystr[c1_i131] = c1_cv2[c1_i131];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i132 = 0; c1_i132 < 88; c1_i132++) {
    c1_arr[c1_i132] = c1_dv39[c1_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i133 = 0; c1_i133 < 256; c1_i133++) {
    c1_tt[c1_i133] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i134 = 0; c1_i134 < 88; c1_i134++) {
    c1_tt[c1_i134] = c1_arr[c1_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i135 = 0; c1_i135 < 256; c1_i135++) {
    c1_myarr256[c1_i135] = c1_tt[c1_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_c_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[86];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[86];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i136;
  static char_T c1_cv3[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c1_i137;
  static real_T c1_dv40[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i138;
  int32_T c1_i139;
  int32_T c1_i140;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i136 = 0; c1_i136 < 86; c1_i136++) {
    c1_mystr[c1_i136] = c1_cv3[c1_i136];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i137 = 0; c1_i137 < 86; c1_i137++) {
    c1_arr[c1_i137] = c1_dv40[c1_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i138 = 0; c1_i138 < 256; c1_i138++) {
    c1_tt[c1_i138] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i139 = 0; c1_i139 < 86; c1_i139++) {
    c1_tt[c1_i139] = c1_arr[c1_i139];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i140 = 0; c1_i140 < 256; c1_i140++) {
    c1_myarr256[c1_i140] = c1_tt[c1_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_d_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[165];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[165];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i141;
  static char_T c1_cv4[165] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
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

  int32_T c1_i142;
  static real_T c1_dv41[165] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
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

  int32_T c1_i143;
  int32_T c1_i144;
  int32_T c1_i145;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_i_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i141 = 0; c1_i141 < 165; c1_i141++) {
    c1_mystr[c1_i141] = c1_cv4[c1_i141];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i142 = 0; c1_i142 < 165; c1_i142++) {
    c1_arr[c1_i142] = c1_dv41[c1_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i143 = 0; c1_i143 < 256; c1_i143++) {
    c1_tt[c1_i143] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i144 = 0; c1_i144 < 165; c1_i144++) {
    c1_tt[c1_i144] = c1_arr[c1_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i145 = 0; c1_i145 < 256; c1_i145++) {
    c1_myarr256[c1_i145] = c1_tt[c1_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_e_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[161];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[161];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i146;
  static char_T c1_cv5[161] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
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

  int32_T c1_i147;
  static real_T c1_dv42[161] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
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

  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_j_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i146 = 0; c1_i146 < 161; c1_i146++) {
    c1_mystr[c1_i146] = c1_cv5[c1_i146];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i147 = 0; c1_i147 < 161; c1_i147++) {
    c1_arr[c1_i147] = c1_dv42[c1_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i148 = 0; c1_i148 < 256; c1_i148++) {
    c1_tt[c1_i148] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i149 = 0; c1_i149 < 161; c1_i149++) {
    c1_tt[c1_i149] = c1_arr[c1_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i150 = 0; c1_i150 < 256; c1_i150++) {
    c1_myarr256[c1_i150] = c1_tt[c1_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_f_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i151;
  static char_T c1_cv6[94] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', '.', '0', '5', ')', ')', ';' };

  int32_T c1_i152;
  static real_T c1_dv43[94] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 48.0, 53.0, 41.0, 41.0, 59.0 };

  int32_T c1_i153;
  int32_T c1_i154;
  int32_T c1_i155;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_k_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i151 = 0; c1_i151 < 94; c1_i151++) {
    c1_mystr[c1_i151] = c1_cv6[c1_i151];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i152 = 0; c1_i152 < 94; c1_i152++) {
    c1_arr[c1_i152] = c1_dv43[c1_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i153 = 0; c1_i153 < 256; c1_i153++) {
    c1_tt[c1_i153] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i154 = 0; c1_i154 < 94; c1_i154++) {
    c1_tt[c1_i154] = c1_arr[c1_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i155 = 0; c1_i155 < 256; c1_i155++) {
    c1_myarr256[c1_i155] = c1_tt[c1_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_g_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[91];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[91];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i156;
  static char_T c1_cv7[91] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's',
    't', 'e', 'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r',
    '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't',
    'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',',
    '0', ',', '0', ')', ')', ';' };

  int32_T c1_i157;
  static real_T c1_dv44[91] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0,
    101.0, 114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0,
    108.0, 97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i158;
  int32_T c1_i159;
  int32_T c1_i160;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_l_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i156 = 0; c1_i156 < 91; c1_i156++) {
    c1_mystr[c1_i156] = c1_cv7[c1_i156];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i157 = 0; c1_i157 < 91; c1_i157++) {
    c1_arr[c1_i157] = c1_dv44[c1_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i158 = 0; c1_i158 < 256; c1_i158++) {
    c1_tt[c1_i158] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i159 = 0; c1_i159 < 91; c1_i159++) {
    c1_tt[c1_i159] = c1_arr[c1_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i160 = 0; c1_i160 < 256; c1_i160++) {
    c1_myarr256[c1_i160] = c1_tt[c1_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_h_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[80];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[80];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i161;
  static char_T c1_cv8[80] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w',
    'r', 'i', 's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r',
    'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(',
    '1', ',', '0', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c1_i162;
  static real_T c1_dv45[80] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0,
    105.0, 115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i163;
  int32_T c1_i164;
  int32_T c1_i165;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_n_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i161 = 0; c1_i161 < 80; c1_i161++) {
    c1_mystr[c1_i161] = c1_cv8[c1_i161];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i162 = 0; c1_i162 < 80; c1_i162++) {
    c1_arr[c1_i162] = c1_dv45[c1_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 80.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i163 = 0; c1_i163 < 256; c1_i163++) {
    c1_tt[c1_i163] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i164 = 0; c1_i164 < 80; c1_i164++) {
    c1_tt[c1_i164] = c1_arr[c1_i164];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i165 = 0; c1_i165 < 256; c1_i165++) {
    c1_myarr256[c1_i165] = c1_tt[c1_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_i_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[147];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[147];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i166;
  static char_T c1_cv9[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
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

  int32_T c1_i167;
  static real_T c1_dv46[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i168;
  int32_T c1_i169;
  int32_T c1_i170;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_p_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i166 = 0; c1_i166 < 147; c1_i166++) {
    c1_mystr[c1_i166] = c1_cv9[c1_i166];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i167 = 0; c1_i167 < 147; c1_i167++) {
    c1_arr[c1_i167] = c1_dv46[c1_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i168 = 0; c1_i168 < 256; c1_i168++) {
    c1_tt[c1_i168] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i169 = 0; c1_i169 < 147; c1_i169++) {
    c1_tt[c1_i169] = c1_arr[c1_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i170 = 0; c1_i170 < 256; c1_i170++) {
    c1_myarr256[c1_i170] = c1_tt[c1_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_j_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[164];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[164];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i171;
  static char_T c1_cv10[164] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i172;
  static real_T c1_dv47[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i173;
  int32_T c1_i174;
  int32_T c1_i175;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_q_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i171 = 0; c1_i171 < 164; c1_i171++) {
    c1_mystr[c1_i171] = c1_cv10[c1_i171];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i172 = 0; c1_i172 < 164; c1_i172++) {
    c1_arr[c1_i172] = c1_dv47[c1_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i173 = 0; c1_i173 < 256; c1_i173++) {
    c1_tt[c1_i173] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i174 = 0; c1_i174 < 164; c1_i174++) {
    c1_tt[c1_i174] = c1_arr[c1_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i175 = 0; c1_i175 < 256; c1_i175++) {
    c1_myarr256[c1_i175] = c1_tt[c1_i175];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_k_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[223];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[223];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i176;
  static char_T c1_cv11[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i177;
  static real_T c1_dv48[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i178;
  int32_T c1_i179;
  int32_T c1_i180;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_s_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i176 = 0; c1_i176 < 223; c1_i176++) {
    c1_mystr[c1_i176] = c1_cv11[c1_i176];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i177 = 0; c1_i177 < 223; c1_i177++) {
    c1_arr[c1_i177] = c1_dv48[c1_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i178 = 0; c1_i178 < 256; c1_i178++) {
    c1_tt[c1_i178] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i179 = 0; c1_i179 < 223; c1_i179++) {
    c1_tt[c1_i179] = c1_arr[c1_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i180 = 0; c1_i180 < 256; c1_i180++) {
    c1_myarr256[c1_i180] = c1_tt[c1_i180];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_l_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[223];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[223];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i181;
  static char_T c1_cv12[223] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i182;
  static real_T c1_dv49[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i183;
  int32_T c1_i184;
  int32_T c1_i185;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_t_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i181 = 0; c1_i181 < 223; c1_i181++) {
    c1_mystr[c1_i181] = c1_cv12[c1_i181];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i182 = 0; c1_i182 < 223; c1_i182++) {
    c1_arr[c1_i182] = c1_dv49[c1_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i183 = 0; c1_i183 < 256; c1_i183++) {
    c1_tt[c1_i183] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i184 = 0; c1_i184 < 223; c1_i184++) {
    c1_tt[c1_i184] = c1_arr[c1_i184];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i185 = 0; c1_i185 < 256; c1_i185++) {
    c1_myarr256[c1_i185] = c1_tt[c1_i185];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_m_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[225];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[225];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i186;
  static char_T c1_cv13[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i187;
  static real_T c1_dv50[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i188;
  int32_T c1_i189;
  int32_T c1_i190;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_u_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i186 = 0; c1_i186 < 225; c1_i186++) {
    c1_mystr[c1_i186] = c1_cv13[c1_i186];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i187 = 0; c1_i187 < 225; c1_i187++) {
    c1_arr[c1_i187] = c1_dv50[c1_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i188 = 0; c1_i188 < 256; c1_i188++) {
    c1_tt[c1_i188] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i189 = 0; c1_i189 < 225; c1_i189++) {
    c1_tt[c1_i189] = c1_arr[c1_i189];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i190 = 0; c1_i190 < 256; c1_i190++) {
    c1_myarr256[c1_i190] = c1_tt[c1_i190];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_n_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[225];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[225];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i191;
  static char_T c1_cv14[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i192;
  static real_T c1_dv51[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i193;
  int32_T c1_i194;
  int32_T c1_i195;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_v_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i191 = 0; c1_i191 < 225; c1_i191++) {
    c1_mystr[c1_i191] = c1_cv14[c1_i191];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i192 = 0; c1_i192 < 225; c1_i192++) {
    c1_arr[c1_i192] = c1_dv51[c1_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i193 = 0; c1_i193 < 256; c1_i193++) {
    c1_tt[c1_i193] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i194 = 0; c1_i194 < 225; c1_i194++) {
    c1_tt[c1_i194] = c1_arr[c1_i194];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i195 = 0; c1_i195 < 256; c1_i195++) {
    c1_myarr256[c1_i195] = c1_tt[c1_i195];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_o_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[87];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[87];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i196;
  static char_T c1_cv15[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i197;
  static real_T c1_dv52[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i198;
  int32_T c1_i199;
  int32_T c1_i200;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_w_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i196 = 0; c1_i196 < 87; c1_i196++) {
    c1_mystr[c1_i196] = c1_cv15[c1_i196];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i197 = 0; c1_i197 < 87; c1_i197++) {
    c1_arr[c1_i197] = c1_dv52[c1_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i198 = 0; c1_i198 < 256; c1_i198++) {
    c1_tt[c1_i198] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i199 = 0; c1_i199 < 87; c1_i199++) {
    c1_tt[c1_i199] = c1_arr[c1_i199];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i200 = 0; c1_i200 < 256; c1_i200++) {
    c1_myarr256[c1_i200] = c1_tt[c1_i200];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_lowhigh[2])
{
  real_T c1_b_r;
  real_T c1_low;
  real_T c1_high;
  int32_T c1_i201;
  static char_T c1_cv16[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c1_u[26];
  const mxArray *c1_y = NULL;
  real_T c1_b_s;
  real_T c1_x;
  real_T c1_b_x;
  c1_low = c1_lowhigh[0];
  c1_high = c1_lowhigh[1];
  if (c1_low <= c1_high) {
  } else {
    for (c1_i201 = 0; c1_i201 < 26; c1_i201++) {
      c1_u[c1_i201] = c1_cv16[c1_i201];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_b_s = (c1_high - c1_low) + 1.0;
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * c1_b_s;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  return c1_low + c1_b_x;
}

static real_T c1_rand(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
                      *chartInstance)
{
  return c1_eml_rand(chartInstance);
}

static real_T c1_eml_rand
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
{
  real_T c1_b_r;
  uint32_T c1_hoistedGlobal;
  uint32_T c1_d_state;
  uint32_T c1_e_state;
  uint32_T c1_b_s;
  uint32_T c1_u0;
  uint32_T c1_hi;
  uint32_T c1_lo;
  uint32_T c1_test1;
  uint32_T c1_test2;
  uint32_T c1_f_state;
  real_T c1_c_r;
  real_T c1_d0;
  int32_T c1_i202;
  uint32_T c1_icng;
  uint32_T c1_jsr;
  uint32_T c1_u1;
  uint32_T c1_u2;
  uint32_T c1_ui;
  uint32_T c1_b_ui;
  real_T c1_d_r;
  real_T c1_d1;
  uint32_T c1_uv2[625];
  int32_T c1_i203;
  real_T c1_d2;
  if (!chartInstance->c1_method_not_empty) {
    chartInstance->c1_method = 7U;
    chartInstance->c1_method_not_empty = true;
  }

  if (chartInstance->c1_method == 4U) {
    if (!chartInstance->c1_state_not_empty) {
      chartInstance->c1_state = 1144108930U;
      chartInstance->c1_state_not_empty = true;
    }

    c1_hoistedGlobal = chartInstance->c1_state;
    c1_d_state = c1_hoistedGlobal;
    c1_e_state = c1_d_state;
    c1_b_s = c1_e_state;
    c1_u0 = 127773U;
    if (c1_u0 == 0U) {
      c1_hi = MAX_uint32_T;
    } else {
      c1_hi = c1_b_s / c1_u0;
    }

    c1_lo = c1_b_s - c1_hi * 127773U;
    c1_test1 = 16807U * c1_lo;
    c1_test2 = 2836U * c1_hi;
    if (c1_test1 < c1_test2) {
      c1_f_state = (c1_test1 - c1_test2) + 2147483647U;
    } else {
      c1_f_state = c1_test1 - c1_test2;
    }

    c1_c_r = (real_T)c1_f_state * 4.6566128752457969E-10;
    c1_e_state = c1_f_state;
    c1_d0 = c1_c_r;
    chartInstance->c1_state = c1_e_state;
    c1_b_r = c1_d0;
  } else if (chartInstance->c1_method == 5U) {
    if (!chartInstance->c1_b_state_not_empty) {
      for (c1_i202 = 0; c1_i202 < 2; c1_i202++) {
        chartInstance->c1_b_state[c1_i202] = 362436069U + 158852560U * (uint32_T)
          c1_i202;
      }

      chartInstance->c1_b_state_not_empty = true;
    }

    c1_icng = chartInstance->c1_b_state[0];
    c1_jsr = chartInstance->c1_b_state[1];
    c1_u1 = c1_jsr;
    c1_u2 = c1_icng;
    c1_u2 = 69069U * c1_u2 + 1234567U;
    c1_u1 ^= c1_u1 << 13;
    c1_u1 ^= c1_u1 >> 17;
    c1_u1 ^= c1_u1 << 5;
    c1_ui = c1_u2 + c1_u1;
    chartInstance->c1_b_state[0] = c1_u2;
    chartInstance->c1_b_state[1] = c1_u1;
    c1_b_ui = c1_ui;
    c1_d_r = (real_T)c1_b_ui * 2.328306436538696E-10;
    c1_d1 = c1_d_r;
    c1_b_r = c1_d1;
  } else {
    if (!chartInstance->c1_c_state_not_empty) {
      c1_eml_rand_mt19937ar(chartInstance, c1_uv2);
      for (c1_i203 = 0; c1_i203 < 625; c1_i203++) {
        chartInstance->c1_c_state[c1_i203] = c1_uv2[c1_i203];
      }

      chartInstance->c1_c_state_not_empty = true;
    }

    c1_d2 = c1_c_eml_rand_mt19937ar(chartInstance, chartInstance->c1_c_state);
    c1_b_r = c1_d2;
  }

  return c1_b_r;
}

static void c1_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625])
{
  real_T c1_d3;
  int32_T c1_i204;
  c1_d3 = 5489.0;
  for (c1_i204 = 0; c1_i204 < 625; c1_i204++) {
    c1_d_state[c1_i204] = 0U;
  }

  c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d3);
}

static void c1_twister_state_vector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625])
{
  int32_T c1_i205;
  for (c1_i205 = 0; c1_i205 < 625; c1_i205++) {
    c1_b_mt[c1_i205] = c1_mt[c1_i205];
  }

  c1_b_twister_state_vector(chartInstance, c1_b_mt, c1_seed);
}

static void c1_b_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_b_r)
{
  int32_T c1_i206;
  for (c1_i206 = 0; c1_i206 < 625; c1_i206++) {
    c1_e_state[c1_i206] = c1_d_state[c1_i206];
  }

  *c1_b_r = c1_c_eml_rand_mt19937ar(chartInstance, c1_e_state);
}

static void c1_eml_error(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance)
{
  int32_T c1_i207;
  static char_T c1_cv17[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c1_u[37];
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  for (c1_i207 = 0; c1_i207 < 37; c1_i207++) {
    c1_u[c1_i207] = c1_cv17[c1_i207];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static real_T c1_b_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance)
{
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 4.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  return 4.0 + c1_b_x;
}

static real_T c1_c_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance)
{
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 2.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  return 1.0 + c1_b_x;
}

static void c1_p_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[118];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[118];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i208;
  static char_T c1_cv18[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i209;
  static real_T c1_dv53[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i210;
  int32_T c1_i211;
  int32_T c1_i212;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_yb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i208 = 0; c1_i208 < 118; c1_i208++) {
    c1_mystr[c1_i208] = c1_cv18[c1_i208];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i209 = 0; c1_i209 < 118; c1_i209++) {
    c1_arr[c1_i209] = c1_dv53[c1_i209];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i210 = 0; c1_i210 < 256; c1_i210++) {
    c1_tt[c1_i210] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i211 = 0; c1_i211 < 118; c1_i211++) {
    c1_tt[c1_i211] = c1_arr[c1_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i212 = 0; c1_i212 < 256; c1_i212++) {
    c1_myarr256[c1_i212] = c1_tt[c1_i212];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_q_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[119];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[119];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i213;
  static char_T c1_cv19[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c1_i214;
  static real_T c1_dv54[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i215;
  int32_T c1_i216;
  int32_T c1_i217;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ac_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i213 = 0; c1_i213 < 119; c1_i213++) {
    c1_mystr[c1_i213] = c1_cv19[c1_i213];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i214 = 0; c1_i214 < 119; c1_i214++) {
    c1_arr[c1_i214] = c1_dv54[c1_i214];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i215 = 0; c1_i215 < 256; c1_i215++) {
    c1_tt[c1_i215] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i216 = 0; c1_i216 < 119; c1_i216++) {
    c1_tt[c1_i216] = c1_arr[c1_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i217 = 0; c1_i217 < 256; c1_i217++) {
    c1_myarr256[c1_i217] = c1_tt[c1_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_r_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[116];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[116];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i218;
  static char_T c1_cv20[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i219;
  static real_T c1_dv55[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i220;
  int32_T c1_i221;
  int32_T c1_i222;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_bc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i218 = 0; c1_i218 < 116; c1_i218++) {
    c1_mystr[c1_i218] = c1_cv20[c1_i218];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i219 = 0; c1_i219 < 116; c1_i219++) {
    c1_arr[c1_i219] = c1_dv55[c1_i219];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i220 = 0; c1_i220 < 256; c1_i220++) {
    c1_tt[c1_i220] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i221 = 0; c1_i221 < 116; c1_i221++) {
    c1_tt[c1_i221] = c1_arr[c1_i221];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i222 = 0; c1_i222 < 256; c1_i222++) {
    c1_myarr256[c1_i222] = c1_tt[c1_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_s_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[118];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[118];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i223;
  static char_T c1_cv21[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i224;
  static real_T c1_dv56[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i225;
  int32_T c1_i226;
  int32_T c1_i227;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_cc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i223 = 0; c1_i223 < 118; c1_i223++) {
    c1_mystr[c1_i223] = c1_cv21[c1_i223];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i224 = 0; c1_i224 < 118; c1_i224++) {
    c1_arr[c1_i224] = c1_dv56[c1_i224];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i225 = 0; c1_i225 < 256; c1_i225++) {
    c1_tt[c1_i225] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i226 = 0; c1_i226 < 118; c1_i226++) {
    c1_tt[c1_i226] = c1_arr[c1_i226];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i227 = 0; c1_i227 < 256; c1_i227++) {
    c1_myarr256[c1_i227] = c1_tt[c1_i227];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_t_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[120];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[120];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i228;
  static char_T c1_cv22[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i229;
  static real_T c1_dv57[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i230;
  int32_T c1_i231;
  int32_T c1_i232;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_dc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i228 = 0; c1_i228 < 120; c1_i228++) {
    c1_mystr[c1_i228] = c1_cv22[c1_i228];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i229 = 0; c1_i229 < 120; c1_i229++) {
    c1_arr[c1_i229] = c1_dv57[c1_i229];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i230 = 0; c1_i230 < 256; c1_i230++) {
    c1_tt[c1_i230] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i231 = 0; c1_i231 < 120; c1_i231++) {
    c1_tt[c1_i231] = c1_arr[c1_i231];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i232 = 0; c1_i232 < 256; c1_i232++) {
    c1_myarr256[c1_i232] = c1_tt[c1_i232];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_u_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[121];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[121];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i233;
  static char_T c1_cv23[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i234;
  static real_T c1_dv58[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i235;
  int32_T c1_i236;
  int32_T c1_i237;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ec_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i233 = 0; c1_i233 < 121; c1_i233++) {
    c1_mystr[c1_i233] = c1_cv23[c1_i233];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i234 = 0; c1_i234 < 121; c1_i234++) {
    c1_arr[c1_i234] = c1_dv58[c1_i234];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i235 = 0; c1_i235 < 256; c1_i235++) {
    c1_tt[c1_i235] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i236 = 0; c1_i236 < 121; c1_i236++) {
    c1_tt[c1_i236] = c1_arr[c1_i236];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i237 = 0; c1_i237 < 256; c1_i237++) {
    c1_myarr256[c1_i237] = c1_tt[c1_i237];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_v_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[122];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[122];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i238;
  static char_T c1_cv24[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i239;
  static real_T c1_dv59[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i240;
  int32_T c1_i241;
  int32_T c1_i242;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_fc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i238 = 0; c1_i238 < 122; c1_i238++) {
    c1_mystr[c1_i238] = c1_cv24[c1_i238];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i239 = 0; c1_i239 < 122; c1_i239++) {
    c1_arr[c1_i239] = c1_dv59[c1_i239];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i240 = 0; c1_i240 < 256; c1_i240++) {
    c1_tt[c1_i240] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i241 = 0; c1_i241 < 122; c1_i241++) {
    c1_tt[c1_i241] = c1_arr[c1_i241];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i242 = 0; c1_i242 < 256; c1_i242++) {
    c1_myarr256[c1_i242] = c1_tt[c1_i242];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_w_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[123];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[123];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i243;
  static char_T c1_cv25[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i244;
  static real_T c1_dv60[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i245;
  int32_T c1_i246;
  int32_T c1_i247;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_gc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i243 = 0; c1_i243 < 123; c1_i243++) {
    c1_mystr[c1_i243] = c1_cv25[c1_i243];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i244 = 0; c1_i244 < 123; c1_i244++) {
    c1_arr[c1_i244] = c1_dv60[c1_i244];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i245 = 0; c1_i245 < 256; c1_i245++) {
    c1_tt[c1_i245] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i246 = 0; c1_i246 < 123; c1_i246++) {
    c1_tt[c1_i246] = c1_arr[c1_i246];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i247 = 0; c1_i247 < 256; c1_i247++) {
    c1_myarr256[c1_i247] = c1_tt[c1_i247];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_x_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[138];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[138];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i248;
  static char_T c1_cv26[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N',
    'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h',
    'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i249;
  static real_T c1_dv61[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i250;
  int32_T c1_i251;
  int32_T c1_i252;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_hc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i248 = 0; c1_i248 < 138; c1_i248++) {
    c1_mystr[c1_i248] = c1_cv26[c1_i248];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i249 = 0; c1_i249 < 138; c1_i249++) {
    c1_arr[c1_i249] = c1_dv61[c1_i249];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i250 = 0; c1_i250 < 256; c1_i250++) {
    c1_tt[c1_i250] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i251 = 0; c1_i251 < 138; c1_i251++) {
    c1_tt[c1_i251] = c1_arr[c1_i251];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i252 = 0; c1_i252 < 256; c1_i252++) {
    c1_myarr256[c1_i252] = c1_tt[c1_i252];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_y_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[139];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[139];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i253;
  static char_T c1_cv27[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-',
    'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i254;
  static real_T c1_dv62[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0,
    105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0,
    97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i255;
  int32_T c1_i256;
  int32_T c1_i257;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ic_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_yb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_xb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i253 = 0; c1_i253 < 139; c1_i253++) {
    c1_mystr[c1_i253] = c1_cv27[c1_i253];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i254 = 0; c1_i254 < 139; c1_i254++) {
    c1_arr[c1_i254] = c1_dv62[c1_i254];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i255 = 0; c1_i255 < 256; c1_i255++) {
    c1_tt[c1_i255] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i256 = 0; c1_i256 < 139; c1_i256++) {
    c1_tt[c1_i256] = c1_arr[c1_i256];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i257 = 0; c1_i257 < 256; c1_i257++) {
    c1_myarr256[c1_i257] = c1_tt[c1_i257];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ab_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[136];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[136];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i258;
  static char_T c1_cv28[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i259;
  static real_T c1_dv63[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0,
    61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i260;
  int32_T c1_i261;
  int32_T c1_i262;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_jc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_bc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_ac_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i258 = 0; c1_i258 < 136; c1_i258++) {
    c1_mystr[c1_i258] = c1_cv28[c1_i258];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i259 = 0; c1_i259 < 136; c1_i259++) {
    c1_arr[c1_i259] = c1_dv63[c1_i259];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i260 = 0; c1_i260 < 256; c1_i260++) {
    c1_tt[c1_i260] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i261 = 0; c1_i261 < 136; c1_i261++) {
    c1_tt[c1_i261] = c1_arr[c1_i261];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i262 = 0; c1_i262 < 256; c1_i262++) {
    c1_myarr256[c1_i262] = c1_tt[c1_i262];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_bb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[138];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[138];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i263;
  static char_T c1_cv29[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N',
    'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h',
    'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i264;
  static real_T c1_dv64[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i265;
  int32_T c1_i266;
  int32_T c1_i267;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_kc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i263 = 0; c1_i263 < 138; c1_i263++) {
    c1_mystr[c1_i263] = c1_cv29[c1_i263];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i264 = 0; c1_i264 < 138; c1_i264++) {
    c1_arr[c1_i264] = c1_dv64[c1_i264];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i265 = 0; c1_i265 < 256; c1_i265++) {
    c1_tt[c1_i265] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i266 = 0; c1_i266 < 138; c1_i266++) {
    c1_tt[c1_i266] = c1_arr[c1_i266];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i267 = 0; c1_i267 < 256; c1_i267++) {
    c1_myarr256[c1_i267] = c1_tt[c1_i267];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_cb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[140];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[140];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i268;
  static char_T c1_cv30[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e',
    '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i269;
  static real_T c1_dv65[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i270;
  int32_T c1_i271;
  int32_T c1_i272;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_lc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_dc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_cc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i268 = 0; c1_i268 < 140; c1_i268++) {
    c1_mystr[c1_i268] = c1_cv30[c1_i268];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i269 = 0; c1_i269 < 140; c1_i269++) {
    c1_arr[c1_i269] = c1_dv65[c1_i269];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i270 = 0; c1_i270 < 256; c1_i270++) {
    c1_tt[c1_i270] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i271 = 0; c1_i271 < 140; c1_i271++) {
    c1_tt[c1_i271] = c1_arr[c1_i271];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i272 = 0; c1_i272 < 256; c1_i272++) {
    c1_myarr256[c1_i272] = c1_tt[c1_i272];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_db_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[141];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[141];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i273;
  static char_T c1_cv31[141] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i274;
  static real_T c1_dv66[141] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0, 72.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0,
    75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i275;
  int32_T c1_i276;
  int32_T c1_i277;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_mc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_fc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_ec_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i273 = 0; c1_i273 < 141; c1_i273++) {
    c1_mystr[c1_i273] = c1_cv31[c1_i273];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i274 = 0; c1_i274 < 141; c1_i274++) {
    c1_arr[c1_i274] = c1_dv66[c1_i274];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 141.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i275 = 0; c1_i275 < 256; c1_i275++) {
    c1_tt[c1_i275] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i276 = 0; c1_i276 < 141; c1_i276++) {
    c1_tt[c1_i276] = c1_arr[c1_i276];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i277 = 0; c1_i277 < 256; c1_i277++) {
    c1_myarr256[c1_i277] = c1_tt[c1_i277];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_eb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[142];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[142];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i278;
  static char_T c1_cv32[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i279;
  static real_T c1_dv67[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0,
    75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i280;
  int32_T c1_i281;
  int32_T c1_i282;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_nc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_hc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_gc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i278 = 0; c1_i278 < 142; c1_i278++) {
    c1_mystr[c1_i278] = c1_cv32[c1_i278];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i279 = 0; c1_i279 < 142; c1_i279++) {
    c1_arr[c1_i279] = c1_dv67[c1_i279];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i280 = 0; c1_i280 < 256; c1_i280++) {
    c1_tt[c1_i280] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i281 = 0; c1_i281 < 142; c1_i281++) {
    c1_tt[c1_i281] = c1_arr[c1_i281];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i282 = 0; c1_i282 < 256; c1_i282++) {
    c1_myarr256[c1_i282] = c1_tt[c1_i282];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_fb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[143];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[143];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i283;
  static char_T c1_cv33[143] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i284;
  static real_T c1_dv68[143] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 78.0, 69.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i285;
  int32_T c1_i286;
  int32_T c1_i287;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_oc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_jc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_ic_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i283 = 0; c1_i283 < 143; c1_i283++) {
    c1_mystr[c1_i283] = c1_cv33[c1_i283];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i284 = 0; c1_i284 < 143; c1_i284++) {
    c1_arr[c1_i284] = c1_dv68[c1_i284];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 143.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i285 = 0; c1_i285 < 256; c1_i285++) {
    c1_tt[c1_i285] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i286 = 0; c1_i286 < 143; c1_i286++) {
    c1_tt[c1_i286] = c1_arr[c1_i286];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i287 = 0; c1_i287 < 256; c1_i287++) {
    c1_myarr256[c1_i287] = c1_tt[c1_i287];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_gb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[136];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[136];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i288;
  static char_T c1_cv34[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i289;
  static real_T c1_dv69[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i290;
  int32_T c1_i291;
  int32_T c1_i292;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_pc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_bc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_ac_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i288 = 0; c1_i288 < 136; c1_i288++) {
    c1_mystr[c1_i288] = c1_cv34[c1_i288];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i289 = 0; c1_i289 < 136; c1_i289++) {
    c1_arr[c1_i289] = c1_dv69[c1_i289];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i290 = 0; c1_i290 < 256; c1_i290++) {
    c1_tt[c1_i290] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i291 = 0; c1_i291 < 136; c1_i291++) {
    c1_tt[c1_i291] = c1_arr[c1_i291];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i292 = 0; c1_i292 < 256; c1_i292++) {
    c1_myarr256[c1_i292] = c1_tt[c1_i292];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_hb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[135];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[135];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i293;
  static char_T c1_cv35[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i294;
  static real_T c1_dv70[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i295;
  int32_T c1_i296;
  int32_T c1_i297;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_qc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_lc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_kc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i293 = 0; c1_i293 < 135; c1_i293++) {
    c1_mystr[c1_i293] = c1_cv35[c1_i293];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i294 = 0; c1_i294 < 135; c1_i294++) {
    c1_arr[c1_i294] = c1_dv70[c1_i294];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i295 = 0; c1_i295 < 256; c1_i295++) {
    c1_tt[c1_i295] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i296 = 0; c1_i296 < 135; c1_i296++) {
    c1_tt[c1_i296] = c1_arr[c1_i296];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i297 = 0; c1_i297 < 256; c1_i297++) {
    c1_myarr256[c1_i297] = c1_tt[c1_i297];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ib_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[132];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[132];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i298;
  static char_T c1_cv36[132] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i299;
  static real_T c1_dv71[132] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i300;
  int32_T c1_i301;
  int32_T c1_i302;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_rc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_nc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_mc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i298 = 0; c1_i298 < 132; c1_i298++) {
    c1_mystr[c1_i298] = c1_cv36[c1_i298];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i299 = 0; c1_i299 < 132; c1_i299++) {
    c1_arr[c1_i299] = c1_dv71[c1_i299];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 132.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i300 = 0; c1_i300 < 256; c1_i300++) {
    c1_tt[c1_i300] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i301 = 0; c1_i301 < 132; c1_i301++) {
    c1_tt[c1_i301] = c1_arr[c1_i301];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i302 = 0; c1_i302 < 256; c1_i302++) {
    c1_myarr256[c1_i302] = c1_tt[c1_i302];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_jb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[137];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[137];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i303;
  static char_T c1_cv37[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i304;
  static real_T c1_dv72[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c1_i305;
  int32_T c1_i306;
  int32_T c1_i307;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_sc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_pc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_oc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i303 = 0; c1_i303 < 137; c1_i303++) {
    c1_mystr[c1_i303] = c1_cv37[c1_i303];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i304 = 0; c1_i304 < 137; c1_i304++) {
    c1_arr[c1_i304] = c1_dv72[c1_i304];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i305 = 0; c1_i305 < 256; c1_i305++) {
    c1_tt[c1_i305] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i306 = 0; c1_i306 < 137; c1_i306++) {
    c1_tt[c1_i306] = c1_arr[c1_i306];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i307 = 0; c1_i307 < 256; c1_i307++) {
    c1_myarr256[c1_i307] = c1_tt[c1_i307];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_kb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[134];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[134];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i308;
  static char_T c1_cv38[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c1_i309;
  static real_T c1_dv73[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i310;
  int32_T c1_i311;
  int32_T c1_i312;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_tc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_rc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_qc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i308 = 0; c1_i308 < 134; c1_i308++) {
    c1_mystr[c1_i308] = c1_cv38[c1_i308];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i309 = 0; c1_i309 < 134; c1_i309++) {
    c1_arr[c1_i309] = c1_dv73[c1_i309];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i310 = 0; c1_i310 < 256; c1_i310++) {
    c1_tt[c1_i310] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i311 = 0; c1_i311 < 134; c1_i311++) {
    c1_tt[c1_i311] = c1_arr[c1_i311];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i312 = 0; c1_i312 < 256; c1_i312++) {
    c1_myarr256[c1_i312] = c1_tt[c1_i312];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_lb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[130];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[130];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i313;
  static char_T c1_cv39[130] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c1_i314;
  static real_T c1_dv74[130] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i315;
  int32_T c1_i316;
  int32_T c1_i317;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_uc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_tc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_sc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i313 = 0; c1_i313 < 130; c1_i313++) {
    c1_mystr[c1_i313] = c1_cv39[c1_i313];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i314 = 0; c1_i314 < 130; c1_i314++) {
    c1_arr[c1_i314] = c1_dv74[c1_i314];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 130.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i315 = 0; c1_i315 < 256; c1_i315++) {
    c1_tt[c1_i315] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i316 = 0; c1_i316 < 130; c1_i316++) {
    c1_tt[c1_i316] = c1_arr[c1_i316];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i317 = 0; c1_i317 < 256; c1_i317++) {
    c1_myarr256[c1_i317] = c1_tt[c1_i317];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_mb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[97];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[97];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i318;
  static char_T c1_cv40[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i319;
  static real_T c1_dv75[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i320;
  int32_T c1_i321;
  int32_T c1_i322;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_vc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_vc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_uc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i318 = 0; c1_i318 < 97; c1_i318++) {
    c1_mystr[c1_i318] = c1_cv40[c1_i318];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i319 = 0; c1_i319 < 97; c1_i319++) {
    c1_arr[c1_i319] = c1_dv75[c1_i319];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i320 = 0; c1_i320 < 256; c1_i320++) {
    c1_tt[c1_i320] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i321 = 0; c1_i321 < 97; c1_i321++) {
    c1_tt[c1_i321] = c1_arr[c1_i321];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i322 = 0; c1_i322 < 256; c1_i322++) {
    c1_myarr256[c1_i322] = c1_tt[c1_i322];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_d_randi(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance)
{
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 16.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  return 3.0 + c1_b_x;
}

static void c1_nb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[91];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[91];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i323;
  static char_T c1_cv41[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i324;
  static real_T c1_dv76[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c1_i325;
  int32_T c1_i326;
  int32_T c1_i327;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_cd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i323 = 0; c1_i323 < 91; c1_i323++) {
    c1_mystr[c1_i323] = c1_cv41[c1_i323];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i324 = 0; c1_i324 < 91; c1_i324++) {
    c1_arr[c1_i324] = c1_dv76[c1_i324];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i325 = 0; c1_i325 < 256; c1_i325++) {
    c1_tt[c1_i325] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i326 = 0; c1_i326 < 91; c1_i326++) {
    c1_tt[c1_i326] = c1_arr[c1_i326];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i327 = 0; c1_i327 < 256; c1_i327++) {
    c1_myarr256[c1_i327] = c1_tt[c1_i327];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ob_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[87];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[87];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i328;
  static char_T c1_cv42[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i329;
  static real_T c1_dv77[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i330;
  int32_T c1_i331;
  int32_T c1_i332;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_dd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i328 = 0; c1_i328 < 87; c1_i328++) {
    c1_mystr[c1_i328] = c1_cv42[c1_i328];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i329 = 0; c1_i329 < 87; c1_i329++) {
    c1_arr[c1_i329] = c1_dv77[c1_i329];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i330 = 0; c1_i330 < 256; c1_i330++) {
    c1_tt[c1_i330] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i331 = 0; c1_i331 < 87; c1_i331++) {
    c1_tt[c1_i331] = c1_arr[c1_i331];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i332 = 0; c1_i332 < 256; c1_i332++) {
    c1_myarr256[c1_i332] = c1_tt[c1_i332];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_pb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i333;
  static char_T c1_cv43[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i334;
  static real_T c1_dv78[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i335;
  int32_T c1_i336;
  int32_T c1_i337;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ed_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_xc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_wc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i333 = 0; c1_i333 < 93; c1_i333++) {
    c1_mystr[c1_i333] = c1_cv43[c1_i333];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i334 = 0; c1_i334 < 93; c1_i334++) {
    c1_arr[c1_i334] = c1_dv78[c1_i334];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i335 = 0; c1_i335 < 256; c1_i335++) {
    c1_tt[c1_i335] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i336 = 0; c1_i336 < 93; c1_i336++) {
    c1_tt[c1_i336] = c1_arr[c1_i336];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i337 = 0; c1_i337 < 256; c1_i337++) {
    c1_myarr256[c1_i337] = c1_tt[c1_i337];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_qb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[94];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[94];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i338;
  static char_T c1_cv44[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i339;
  static real_T c1_dv79[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i340;
  int32_T c1_i341;
  int32_T c1_i342;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_fd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i338 = 0; c1_i338 < 94; c1_i338++) {
    c1_mystr[c1_i338] = c1_cv44[c1_i338];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i339 = 0; c1_i339 < 94; c1_i339++) {
    c1_arr[c1_i339] = c1_dv79[c1_i339];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i340 = 0; c1_i340 < 256; c1_i340++) {
    c1_tt[c1_i340] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i341 = 0; c1_i341 < 94; c1_i341++) {
    c1_tt[c1_i341] = c1_arr[c1_i341];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i342 = 0; c1_i342 < 256; c1_i342++) {
    c1_myarr256[c1_i342] = c1_tt[c1_i342];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_rb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[95];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[95];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i343;
  static char_T c1_cv45[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i344;
  static real_T c1_dv80[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i345;
  int32_T c1_i346;
  int32_T c1_i347;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_gd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ad_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_yc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i343 = 0; c1_i343 < 95; c1_i343++) {
    c1_mystr[c1_i343] = c1_cv45[c1_i343];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i344 = 0; c1_i344 < 95; c1_i344++) {
    c1_arr[c1_i344] = c1_dv80[c1_i344];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i345 = 0; c1_i345 < 256; c1_i345++) {
    c1_tt[c1_i345] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i346 = 0; c1_i346 < 95; c1_i346++) {
    c1_tt[c1_i346] = c1_arr[c1_i346];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i347 = 0; c1_i347 < 256; c1_i347++) {
    c1_myarr256[c1_i347] = c1_tt[c1_i347];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_sb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[88];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[88];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i348;
  static char_T c1_cv46[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i349;
  static real_T c1_dv81[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i350;
  int32_T c1_i351;
  int32_T c1_i352;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_hd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i348 = 0; c1_i348 < 88; c1_i348++) {
    c1_mystr[c1_i348] = c1_cv46[c1_i348];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i349 = 0; c1_i349 < 88; c1_i349++) {
    c1_arr[c1_i349] = c1_dv81[c1_i349];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i350 = 0; c1_i350 < 256; c1_i350++) {
    c1_tt[c1_i350] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i351 = 0; c1_i351 < 88; c1_i351++) {
    c1_tt[c1_i351] = c1_arr[c1_i351];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i352 = 0; c1_i352 < 256; c1_i352++) {
    c1_myarr256[c1_i352] = c1_tt[c1_i352];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_tb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i353;
  static char_T c1_cv47[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i354;
  static real_T c1_dv82[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i355;
  int32_T c1_i356;
  int32_T c1_i357;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_id_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_xc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_wc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i353 = 0; c1_i353 < 93; c1_i353++) {
    c1_mystr[c1_i353] = c1_cv47[c1_i353];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i354 = 0; c1_i354 < 93; c1_i354++) {
    c1_arr[c1_i354] = c1_dv82[c1_i354];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i355 = 0; c1_i355 < 256; c1_i355++) {
    c1_tt[c1_i355] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i356 = 0; c1_i356 < 93; c1_i356++) {
    c1_tt[c1_i356] = c1_arr[c1_i356];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i357 = 0; c1_i357 < 256; c1_i357++) {
    c1_myarr256[c1_i357] = c1_tt[c1_i357];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ub_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[93];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[93];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i358;
  static char_T c1_cv48[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i359;
  static real_T c1_dv83[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i360;
  int32_T c1_i361;
  int32_T c1_i362;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_jd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_xc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_wc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i358 = 0; c1_i358 < 93; c1_i358++) {
    c1_mystr[c1_i358] = c1_cv48[c1_i358];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i359 = 0; c1_i359 < 93; c1_i359++) {
    c1_arr[c1_i359] = c1_dv83[c1_i359];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i360 = 0; c1_i360 < 256; c1_i360++) {
    c1_tt[c1_i360] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i361 = 0; c1_i361 < 93; c1_i361++) {
    c1_tt[c1_i361] = c1_arr[c1_i361];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i362 = 0; c1_i362 < 256; c1_i362++) {
    c1_myarr256[c1_i362] = c1_tt[c1_i362];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_vb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[97];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[97];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i363;
  static char_T c1_cv49[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i364;
  static real_T c1_dv84[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i365;
  int32_T c1_i366;
  int32_T c1_i367;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_kd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_vc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_uc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i363 = 0; c1_i363 < 97; c1_i363++) {
    c1_mystr[c1_i363] = c1_cv49[c1_i363];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i364 = 0; c1_i364 < 97; c1_i364++) {
    c1_arr[c1_i364] = c1_dv84[c1_i364];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i365 = 0; c1_i365 < 256; c1_i365++) {
    c1_tt[c1_i365] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i366 = 0; c1_i366 < 97; c1_i366++) {
    c1_tt[c1_i366] = c1_arr[c1_i366];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i367 = 0; c1_i367 < 256; c1_i367++) {
    c1_myarr256[c1_i367] = c1_tt[c1_i367];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_wb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[97];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[97];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i368;
  static char_T c1_cv50[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i369;
  static real_T c1_dv85[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i370;
  int32_T c1_i371;
  int32_T c1_i372;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ld_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_vc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_uc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i368 = 0; c1_i368 < 97; c1_i368++) {
    c1_mystr[c1_i368] = c1_cv50[c1_i368];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i369 = 0; c1_i369 < 97; c1_i369++) {
    c1_arr[c1_i369] = c1_dv85[c1_i369];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i370 = 0; c1_i370 < 256; c1_i370++) {
    c1_tt[c1_i370] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i371 = 0; c1_i371 < 97; c1_i371++) {
    c1_tt[c1_i371] = c1_arr[c1_i371];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i372 = 0; c1_i372 < 256; c1_i372++) {
    c1_myarr256[c1_i372] = c1_tt[c1_i372];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_xb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[92];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[92];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i373;
  static char_T c1_cv51[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i374;
  static real_T c1_dv86[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i375;
  int32_T c1_i376;
  int32_T c1_i377;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_md_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_cd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_bd_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i373 = 0; c1_i373 < 92; c1_i373++) {
    c1_mystr[c1_i373] = c1_cv51[c1_i373];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i374 = 0; c1_i374 < 92; c1_i374++) {
    c1_arr[c1_i374] = c1_dv86[c1_i374];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i375 = 0; c1_i375 < 256; c1_i375++) {
    c1_tt[c1_i375] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i376 = 0; c1_i376 < 92; c1_i376++) {
    c1_tt[c1_i376] = c1_arr[c1_i376];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i377 = 0; c1_i377 < 256; c1_i377++) {
    c1_myarr256[c1_i377] = c1_tt[c1_i377];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i378;
  real_T c1_b_inData[256];
  int32_T c1_i379;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i378 = 0; c1_i378 < 256; c1_i378++) {
    c1_b_inData[c1_i378] = (*(real_T (*)[256])c1_inData)[c1_i378];
  }

  for (c1_i379 = 0; c1_i379 < 256; c1_i379++) {
    c1_u[c1_i379] = c1_b_inData[c1_i379];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv87[256];
  int32_T c1_i380;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv87, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c1_i380 = 0; c1_i380 < 256; c1_i380++) {
    c1_y[c1_i380] = c1_dv87[c1_i380];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_poseBML;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i381;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_poseBML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_poseBML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_poseBML);
  for (c1_i381 = 0; c1_i381 < 256; c1_i381++) {
    (*(real_T (*)[256])c1_outData)[c1_i381] = c1_y[c1_i381];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_bmlID, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bmlID), &c1_thisId);
  sf_mex_destroy(&c1_bmlID);
  return c1_y;
}

static real_T c1_c_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d4;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d4, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d4;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_bmlID;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_bmlID = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_bmlID), &c1_thisId);
  sf_mex_destroy(&c1_bmlID);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_aVarTruthTableCondition_2;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_aVarTruthTableCondition_2 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_2), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_2);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i382;
  real_T c1_b_inData[256];
  int32_T c1_i383;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i382 = 0; c1_i382 < 256; c1_i382++) {
    c1_b_inData[c1_i382] = (*(real_T (*)[256])c1_inData)[c1_i382];
  }

  for (c1_i383 = 0; c1_i383 < 256; c1_i383++) {
    c1_u[c1_i383] = c1_b_inData[c1_i383];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv88[256];
  int32_T c1_i384;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv88, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i384 = 0; c1_i384 < 256; c1_i384++) {
    c1_y[c1_i384] = c1_dv88[c1_i384];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_myarr256;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[256];
  int32_T c1_i385;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_myarr256 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
  for (c1_i385 = 0; c1_i385 < 256; c1_i385++) {
    (*(real_T (*)[256])c1_outData)[c1_i385] = c1_y[c1_i385];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i386;
  char_T c1_b_inData[94];
  int32_T c1_i387;
  char_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i386 = 0; c1_i386 < 94; c1_i386++) {
    c1_b_inData[c1_i386] = (*(char_T (*)[94])c1_inData)[c1_i386];
  }

  for (c1_i387 = 0; c1_i387 < 94; c1_i387++) {
    c1_u[c1_i387] = c1_b_inData[c1_i387];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i388;
  real_T c1_b_inData[94];
  int32_T c1_i389;
  real_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i388 = 0; c1_i388 < 94; c1_i388++) {
    c1_b_inData[c1_i388] = (*(real_T (*)[94])c1_inData)[c1_i388];
  }

  for (c1_i389 = 0; c1_i389 < 94; c1_i389++) {
    c1_u[c1_i389] = c1_b_inData[c1_i389];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i390;
  char_T c1_b_inData[88];
  int32_T c1_i391;
  char_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i390 = 0; c1_i390 < 88; c1_i390++) {
    c1_b_inData[c1_i390] = (*(char_T (*)[88])c1_inData)[c1_i390];
  }

  for (c1_i391 = 0; c1_i391 < 88; c1_i391++) {
    c1_u[c1_i391] = c1_b_inData[c1_i391];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i392;
  real_T c1_b_inData[88];
  int32_T c1_i393;
  real_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i392 = 0; c1_i392 < 88; c1_i392++) {
    c1_b_inData[c1_i392] = (*(real_T (*)[88])c1_inData)[c1_i392];
  }

  for (c1_i393 = 0; c1_i393 < 88; c1_i393++) {
    c1_u[c1_i393] = c1_b_inData[c1_i393];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i394;
  char_T c1_b_inData[86];
  int32_T c1_i395;
  char_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i394 = 0; c1_i394 < 86; c1_i394++) {
    c1_b_inData[c1_i394] = (*(char_T (*)[86])c1_inData)[c1_i394];
  }

  for (c1_i395 = 0; c1_i395 < 86; c1_i395++) {
    c1_u[c1_i395] = c1_b_inData[c1_i395];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i396;
  real_T c1_b_inData[86];
  int32_T c1_i397;
  real_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i396 = 0; c1_i396 < 86; c1_i396++) {
    c1_b_inData[c1_i396] = (*(real_T (*)[86])c1_inData)[c1_i396];
  }

  for (c1_i397 = 0; c1_i397 < 86; c1_i397++) {
    c1_u[c1_i397] = c1_b_inData[c1_i397];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i398;
  char_T c1_b_inData[165];
  int32_T c1_i399;
  char_T c1_u[165];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i398 = 0; c1_i398 < 165; c1_i398++) {
    c1_b_inData[c1_i398] = (*(char_T (*)[165])c1_inData)[c1_i398];
  }

  for (c1_i399 = 0; c1_i399 < 165; c1_i399++) {
    c1_u[c1_i399] = c1_b_inData[c1_i399];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 165),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i400;
  real_T c1_b_inData[165];
  int32_T c1_i401;
  real_T c1_u[165];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i400 = 0; c1_i400 < 165; c1_i400++) {
    c1_b_inData[c1_i400] = (*(real_T (*)[165])c1_inData)[c1_i400];
  }

  for (c1_i401 = 0; c1_i401 < 165; c1_i401++) {
    c1_u[c1_i401] = c1_b_inData[c1_i401];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 165), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i402;
  char_T c1_b_inData[161];
  int32_T c1_i403;
  char_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i402 = 0; c1_i402 < 161; c1_i402++) {
    c1_b_inData[c1_i402] = (*(char_T (*)[161])c1_inData)[c1_i402];
  }

  for (c1_i403 = 0; c1_i403 < 161; c1_i403++) {
    c1_u[c1_i403] = c1_b_inData[c1_i403];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i404;
  real_T c1_b_inData[161];
  int32_T c1_i405;
  real_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i404 = 0; c1_i404 < 161; c1_i404++) {
    c1_b_inData[c1_i404] = (*(real_T (*)[161])c1_inData)[c1_i404];
  }

  for (c1_i405 = 0; c1_i405 < 161; c1_i405++) {
    c1_u[c1_i405] = c1_b_inData[c1_i405];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i406;
  char_T c1_b_inData[91];
  int32_T c1_i407;
  char_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i406 = 0; c1_i406 < 91; c1_i406++) {
    c1_b_inData[c1_i406] = (*(char_T (*)[91])c1_inData)[c1_i406];
  }

  for (c1_i407 = 0; c1_i407 < 91; c1_i407++) {
    c1_u[c1_i407] = c1_b_inData[c1_i407];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i408;
  real_T c1_b_inData[91];
  int32_T c1_i409;
  real_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i408 = 0; c1_i408 < 91; c1_i408++) {
    c1_b_inData[c1_i408] = (*(real_T (*)[91])c1_inData)[c1_i408];
  }

  for (c1_i409 = 0; c1_i409 < 91; c1_i409++) {
    c1_u[c1_i409] = c1_b_inData[c1_i409];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i410;
  char_T c1_b_inData[83];
  int32_T c1_i411;
  char_T c1_u[83];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i410 = 0; c1_i410 < 83; c1_i410++) {
    c1_b_inData[c1_i410] = (*(char_T (*)[83])c1_inData)[c1_i410];
  }

  for (c1_i411 = 0; c1_i411 < 83; c1_i411++) {
    c1_u[c1_i411] = c1_b_inData[c1_i411];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 83), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i412;
  real_T c1_b_inData[83];
  int32_T c1_i413;
  real_T c1_u[83];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i412 = 0; c1_i412 < 83; c1_i412++) {
    c1_b_inData[c1_i412] = (*(real_T (*)[83])c1_inData)[c1_i412];
  }

  for (c1_i413 = 0; c1_i413 < 83; c1_i413++) {
    c1_u[c1_i413] = c1_b_inData[c1_i413];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 83), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i414;
  char_T c1_b_inData[80];
  int32_T c1_i415;
  char_T c1_u[80];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i414 = 0; c1_i414 < 80; c1_i414++) {
    c1_b_inData[c1_i414] = (*(char_T (*)[80])c1_inData)[c1_i414];
  }

  for (c1_i415 = 0; c1_i415 < 80; c1_i415++) {
    c1_u[c1_i415] = c1_b_inData[c1_i415];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 80), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i416;
  real_T c1_b_inData[80];
  int32_T c1_i417;
  real_T c1_u[80];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i416 = 0; c1_i416 < 80; c1_i416++) {
    c1_b_inData[c1_i416] = (*(real_T (*)[80])c1_inData)[c1_i416];
  }

  for (c1_i417 = 0; c1_i417 < 80; c1_i417++) {
    c1_u[c1_i417] = c1_b_inData[c1_i417];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 80), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_u_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i418;
  char_T c1_b_inData[147];
  int32_T c1_i419;
  char_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i418 = 0; c1_i418 < 147; c1_i418++) {
    c1_b_inData[c1_i418] = (*(char_T (*)[147])c1_inData)[c1_i418];
  }

  for (c1_i419 = 0; c1_i419 < 147; c1_i419++) {
    c1_u[c1_i419] = c1_b_inData[c1_i419];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_v_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i420;
  real_T c1_b_inData[147];
  int32_T c1_i421;
  real_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i420 = 0; c1_i420 < 147; c1_i420++) {
    c1_b_inData[c1_i420] = (*(real_T (*)[147])c1_inData)[c1_i420];
  }

  for (c1_i421 = 0; c1_i421 < 147; c1_i421++) {
    c1_u[c1_i421] = c1_b_inData[c1_i421];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_w_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i422;
  char_T c1_b_inData[164];
  int32_T c1_i423;
  char_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i422 = 0; c1_i422 < 164; c1_i422++) {
    c1_b_inData[c1_i422] = (*(char_T (*)[164])c1_inData)[c1_i422];
  }

  for (c1_i423 = 0; c1_i423 < 164; c1_i423++) {
    c1_u[c1_i423] = c1_b_inData[c1_i423];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_x_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i424;
  real_T c1_b_inData[164];
  int32_T c1_i425;
  real_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i424 = 0; c1_i424 < 164; c1_i424++) {
    c1_b_inData[c1_i424] = (*(real_T (*)[164])c1_inData)[c1_i424];
  }

  for (c1_i425 = 0; c1_i425 < 164; c1_i425++) {
    c1_u[c1_i425] = c1_b_inData[c1_i425];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_y_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i426;
  char_T c1_b_inData[68];
  int32_T c1_i427;
  char_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i426 = 0; c1_i426 < 68; c1_i426++) {
    c1_b_inData[c1_i426] = (*(char_T (*)[68])c1_inData)[c1_i426];
  }

  for (c1_i427 = 0; c1_i427 < 68; c1_i427++) {
    c1_u[c1_i427] = c1_b_inData[c1_i427];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i428;
  real_T c1_b_inData[68];
  int32_T c1_i429;
  real_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i428 = 0; c1_i428 < 68; c1_i428++) {
    c1_b_inData[c1_i428] = (*(real_T (*)[68])c1_inData)[c1_i428];
  }

  for (c1_i429 = 0; c1_i429 < 68; c1_i429++) {
    c1_u[c1_i429] = c1_b_inData[c1_i429];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i430;
  char_T c1_b_inData[223];
  int32_T c1_i431;
  char_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i430 = 0; c1_i430 < 223; c1_i430++) {
    c1_b_inData[c1_i430] = (*(char_T (*)[223])c1_inData)[c1_i430];
  }

  for (c1_i431 = 0; c1_i431 < 223; c1_i431++) {
    c1_u[c1_i431] = c1_b_inData[c1_i431];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i432;
  real_T c1_b_inData[223];
  int32_T c1_i433;
  real_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i432 = 0; c1_i432 < 223; c1_i432++) {
    c1_b_inData[c1_i432] = (*(real_T (*)[223])c1_inData)[c1_i432];
  }

  for (c1_i433 = 0; c1_i433 < 223; c1_i433++) {
    c1_u[c1_i433] = c1_b_inData[c1_i433];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_db_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i434;
  char_T c1_b_inData[225];
  int32_T c1_i435;
  char_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i434 = 0; c1_i434 < 225; c1_i434++) {
    c1_b_inData[c1_i434] = (*(char_T (*)[225])c1_inData)[c1_i434];
  }

  for (c1_i435 = 0; c1_i435 < 225; c1_i435++) {
    c1_u[c1_i435] = c1_b_inData[c1_i435];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i436;
  real_T c1_b_inData[225];
  int32_T c1_i437;
  real_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i436 = 0; c1_i436 < 225; c1_i436++) {
    c1_b_inData[c1_i436] = (*(real_T (*)[225])c1_inData)[c1_i436];
  }

  for (c1_i437 = 0; c1_i437 < 225; c1_i437++) {
    c1_u[c1_i437] = c1_b_inData[c1_i437];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i438;
  char_T c1_b_inData[87];
  int32_T c1_i439;
  char_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i438 = 0; c1_i438 < 87; c1_i438++) {
    c1_b_inData[c1_i438] = (*(char_T (*)[87])c1_inData)[c1_i438];
  }

  for (c1_i439 = 0; c1_i439 < 87; c1_i439++) {
    c1_u[c1_i439] = c1_b_inData[c1_i439];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i440;
  real_T c1_b_inData[87];
  int32_T c1_i441;
  real_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i440 = 0; c1_i440 < 87; c1_i440++) {
    c1_b_inData[c1_i440] = (*(real_T (*)[87])c1_inData)[c1_i440];
  }

  for (c1_i441 = 0; c1_i441 < 87; c1_i441++) {
    c1_u[c1_i441] = c1_b_inData[c1_i441];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i442;
  char_T c1_b_inData[118];
  int32_T c1_i443;
  char_T c1_u[118];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i442 = 0; c1_i442 < 118; c1_i442++) {
    c1_b_inData[c1_i442] = (*(char_T (*)[118])c1_inData)[c1_i442];
  }

  for (c1_i443 = 0; c1_i443 < 118; c1_i443++) {
    c1_u[c1_i443] = c1_b_inData[c1_i443];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i444;
  real_T c1_b_inData[118];
  int32_T c1_i445;
  real_T c1_u[118];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i444 = 0; c1_i444 < 118; c1_i444++) {
    c1_b_inData[c1_i444] = (*(real_T (*)[118])c1_inData)[c1_i444];
  }

  for (c1_i445 = 0; c1_i445 < 118; c1_i445++) {
    c1_u[c1_i445] = c1_b_inData[c1_i445];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i446;
  char_T c1_b_inData[119];
  int32_T c1_i447;
  char_T c1_u[119];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i446 = 0; c1_i446 < 119; c1_i446++) {
    c1_b_inData[c1_i446] = (*(char_T (*)[119])c1_inData)[c1_i446];
  }

  for (c1_i447 = 0; c1_i447 < 119; c1_i447++) {
    c1_u[c1_i447] = c1_b_inData[c1_i447];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i448;
  real_T c1_b_inData[119];
  int32_T c1_i449;
  real_T c1_u[119];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i448 = 0; c1_i448 < 119; c1_i448++) {
    c1_b_inData[c1_i448] = (*(real_T (*)[119])c1_inData)[c1_i448];
  }

  for (c1_i449 = 0; c1_i449 < 119; c1_i449++) {
    c1_u[c1_i449] = c1_b_inData[c1_i449];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i450;
  char_T c1_b_inData[116];
  int32_T c1_i451;
  char_T c1_u[116];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i450 = 0; c1_i450 < 116; c1_i450++) {
    c1_b_inData[c1_i450] = (*(char_T (*)[116])c1_inData)[c1_i450];
  }

  for (c1_i451 = 0; c1_i451 < 116; c1_i451++) {
    c1_u[c1_i451] = c1_b_inData[c1_i451];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i452;
  real_T c1_b_inData[116];
  int32_T c1_i453;
  real_T c1_u[116];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i452 = 0; c1_i452 < 116; c1_i452++) {
    c1_b_inData[c1_i452] = (*(real_T (*)[116])c1_inData)[c1_i452];
  }

  for (c1_i453 = 0; c1_i453 < 116; c1_i453++) {
    c1_u[c1_i453] = c1_b_inData[c1_i453];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i454;
  char_T c1_b_inData[120];
  int32_T c1_i455;
  char_T c1_u[120];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i454 = 0; c1_i454 < 120; c1_i454++) {
    c1_b_inData[c1_i454] = (*(char_T (*)[120])c1_inData)[c1_i454];
  }

  for (c1_i455 = 0; c1_i455 < 120; c1_i455++) {
    c1_u[c1_i455] = c1_b_inData[c1_i455];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i456;
  real_T c1_b_inData[120];
  int32_T c1_i457;
  real_T c1_u[120];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i456 = 0; c1_i456 < 120; c1_i456++) {
    c1_b_inData[c1_i456] = (*(real_T (*)[120])c1_inData)[c1_i456];
  }

  for (c1_i457 = 0; c1_i457 < 120; c1_i457++) {
    c1_u[c1_i457] = c1_b_inData[c1_i457];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i458;
  char_T c1_b_inData[121];
  int32_T c1_i459;
  char_T c1_u[121];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i458 = 0; c1_i458 < 121; c1_i458++) {
    c1_b_inData[c1_i458] = (*(char_T (*)[121])c1_inData)[c1_i458];
  }

  for (c1_i459 = 0; c1_i459 < 121; c1_i459++) {
    c1_u[c1_i459] = c1_b_inData[c1_i459];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i460;
  real_T c1_b_inData[121];
  int32_T c1_i461;
  real_T c1_u[121];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i460 = 0; c1_i460 < 121; c1_i460++) {
    c1_b_inData[c1_i460] = (*(real_T (*)[121])c1_inData)[c1_i460];
  }

  for (c1_i461 = 0; c1_i461 < 121; c1_i461++) {
    c1_u[c1_i461] = c1_b_inData[c1_i461];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i462;
  char_T c1_b_inData[122];
  int32_T c1_i463;
  char_T c1_u[122];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i462 = 0; c1_i462 < 122; c1_i462++) {
    c1_b_inData[c1_i462] = (*(char_T (*)[122])c1_inData)[c1_i462];
  }

  for (c1_i463 = 0; c1_i463 < 122; c1_i463++) {
    c1_u[c1_i463] = c1_b_inData[c1_i463];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i464;
  real_T c1_b_inData[122];
  int32_T c1_i465;
  real_T c1_u[122];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i464 = 0; c1_i464 < 122; c1_i464++) {
    c1_b_inData[c1_i464] = (*(real_T (*)[122])c1_inData)[c1_i464];
  }

  for (c1_i465 = 0; c1_i465 < 122; c1_i465++) {
    c1_u[c1_i465] = c1_b_inData[c1_i465];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i466;
  char_T c1_b_inData[123];
  int32_T c1_i467;
  char_T c1_u[123];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i466 = 0; c1_i466 < 123; c1_i466++) {
    c1_b_inData[c1_i466] = (*(char_T (*)[123])c1_inData)[c1_i466];
  }

  for (c1_i467 = 0; c1_i467 < 123; c1_i467++) {
    c1_u[c1_i467] = c1_b_inData[c1_i467];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i468;
  real_T c1_b_inData[123];
  int32_T c1_i469;
  real_T c1_u[123];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i468 = 0; c1_i468 < 123; c1_i468++) {
    c1_b_inData[c1_i468] = (*(real_T (*)[123])c1_inData)[c1_i468];
  }

  for (c1_i469 = 0; c1_i469 < 123; c1_i469++) {
    c1_u[c1_i469] = c1_b_inData[c1_i469];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i470;
  char_T c1_b_inData[138];
  int32_T c1_i471;
  char_T c1_u[138];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i470 = 0; c1_i470 < 138; c1_i470++) {
    c1_b_inData[c1_i470] = (*(char_T (*)[138])c1_inData)[c1_i470];
  }

  for (c1_i471 = 0; c1_i471 < 138; c1_i471++) {
    c1_u[c1_i471] = c1_b_inData[c1_i471];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i472;
  real_T c1_b_inData[138];
  int32_T c1_i473;
  real_T c1_u[138];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i472 = 0; c1_i472 < 138; c1_i472++) {
    c1_b_inData[c1_i472] = (*(real_T (*)[138])c1_inData)[c1_i472];
  }

  for (c1_i473 = 0; c1_i473 < 138; c1_i473++) {
    c1_u[c1_i473] = c1_b_inData[c1_i473];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i474;
  char_T c1_b_inData[139];
  int32_T c1_i475;
  char_T c1_u[139];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i474 = 0; c1_i474 < 139; c1_i474++) {
    c1_b_inData[c1_i474] = (*(char_T (*)[139])c1_inData)[c1_i474];
  }

  for (c1_i475 = 0; c1_i475 < 139; c1_i475++) {
    c1_u[c1_i475] = c1_b_inData[c1_i475];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i476;
  real_T c1_b_inData[139];
  int32_T c1_i477;
  real_T c1_u[139];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i476 = 0; c1_i476 < 139; c1_i476++) {
    c1_b_inData[c1_i476] = (*(real_T (*)[139])c1_inData)[c1_i476];
  }

  for (c1_i477 = 0; c1_i477 < 139; c1_i477++) {
    c1_u[c1_i477] = c1_b_inData[c1_i477];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i478;
  char_T c1_b_inData[136];
  int32_T c1_i479;
  char_T c1_u[136];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i478 = 0; c1_i478 < 136; c1_i478++) {
    c1_b_inData[c1_i478] = (*(char_T (*)[136])c1_inData)[c1_i478];
  }

  for (c1_i479 = 0; c1_i479 < 136; c1_i479++) {
    c1_u[c1_i479] = c1_b_inData[c1_i479];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i480;
  real_T c1_b_inData[136];
  int32_T c1_i481;
  real_T c1_u[136];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i480 = 0; c1_i480 < 136; c1_i480++) {
    c1_b_inData[c1_i480] = (*(real_T (*)[136])c1_inData)[c1_i480];
  }

  for (c1_i481 = 0; c1_i481 < 136; c1_i481++) {
    c1_u[c1_i481] = c1_b_inData[c1_i481];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i482;
  char_T c1_b_inData[140];
  int32_T c1_i483;
  char_T c1_u[140];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i482 = 0; c1_i482 < 140; c1_i482++) {
    c1_b_inData[c1_i482] = (*(char_T (*)[140])c1_inData)[c1_i482];
  }

  for (c1_i483 = 0; c1_i483 < 140; c1_i483++) {
    c1_u[c1_i483] = c1_b_inData[c1_i483];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i484;
  real_T c1_b_inData[140];
  int32_T c1_i485;
  real_T c1_u[140];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i484 = 0; c1_i484 < 140; c1_i484++) {
    c1_b_inData[c1_i484] = (*(real_T (*)[140])c1_inData)[c1_i484];
  }

  for (c1_i485 = 0; c1_i485 < 140; c1_i485++) {
    c1_u[c1_i485] = c1_b_inData[c1_i485];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i486;
  char_T c1_b_inData[141];
  int32_T c1_i487;
  char_T c1_u[141];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i486 = 0; c1_i486 < 141; c1_i486++) {
    c1_b_inData[c1_i486] = (*(char_T (*)[141])c1_inData)[c1_i486];
  }

  for (c1_i487 = 0; c1_i487 < 141; c1_i487++) {
    c1_u[c1_i487] = c1_b_inData[c1_i487];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 141),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i488;
  real_T c1_b_inData[141];
  int32_T c1_i489;
  real_T c1_u[141];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i488 = 0; c1_i488 < 141; c1_i488++) {
    c1_b_inData[c1_i488] = (*(real_T (*)[141])c1_inData)[c1_i488];
  }

  for (c1_i489 = 0; c1_i489 < 141; c1_i489++) {
    c1_u[c1_i489] = c1_b_inData[c1_i489];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 141), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i490;
  char_T c1_b_inData[142];
  int32_T c1_i491;
  char_T c1_u[142];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i490 = 0; c1_i490 < 142; c1_i490++) {
    c1_b_inData[c1_i490] = (*(char_T (*)[142])c1_inData)[c1_i490];
  }

  for (c1_i491 = 0; c1_i491 < 142; c1_i491++) {
    c1_u[c1_i491] = c1_b_inData[c1_i491];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i492;
  real_T c1_b_inData[142];
  int32_T c1_i493;
  real_T c1_u[142];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i492 = 0; c1_i492 < 142; c1_i492++) {
    c1_b_inData[c1_i492] = (*(real_T (*)[142])c1_inData)[c1_i492];
  }

  for (c1_i493 = 0; c1_i493 < 142; c1_i493++) {
    c1_u[c1_i493] = c1_b_inData[c1_i493];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i494;
  char_T c1_b_inData[143];
  int32_T c1_i495;
  char_T c1_u[143];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i494 = 0; c1_i494 < 143; c1_i494++) {
    c1_b_inData[c1_i494] = (*(char_T (*)[143])c1_inData)[c1_i494];
  }

  for (c1_i495 = 0; c1_i495 < 143; c1_i495++) {
    c1_u[c1_i495] = c1_b_inData[c1_i495];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 143),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i496;
  real_T c1_b_inData[143];
  int32_T c1_i497;
  real_T c1_u[143];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i496 = 0; c1_i496 < 143; c1_i496++) {
    c1_b_inData[c1_i496] = (*(real_T (*)[143])c1_inData)[c1_i496];
  }

  for (c1_i497 = 0; c1_i497 < 143; c1_i497++) {
    c1_u[c1_i497] = c1_b_inData[c1_i497];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 143), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i498;
  char_T c1_b_inData[135];
  int32_T c1_i499;
  char_T c1_u[135];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i498 = 0; c1_i498 < 135; c1_i498++) {
    c1_b_inData[c1_i498] = (*(char_T (*)[135])c1_inData)[c1_i498];
  }

  for (c1_i499 = 0; c1_i499 < 135; c1_i499++) {
    c1_u[c1_i499] = c1_b_inData[c1_i499];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i500;
  real_T c1_b_inData[135];
  int32_T c1_i501;
  real_T c1_u[135];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i500 = 0; c1_i500 < 135; c1_i500++) {
    c1_b_inData[c1_i500] = (*(real_T (*)[135])c1_inData)[c1_i500];
  }

  for (c1_i501 = 0; c1_i501 < 135; c1_i501++) {
    c1_u[c1_i501] = c1_b_inData[c1_i501];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i502;
  char_T c1_b_inData[132];
  int32_T c1_i503;
  char_T c1_u[132];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i502 = 0; c1_i502 < 132; c1_i502++) {
    c1_b_inData[c1_i502] = (*(char_T (*)[132])c1_inData)[c1_i502];
  }

  for (c1_i503 = 0; c1_i503 < 132; c1_i503++) {
    c1_u[c1_i503] = c1_b_inData[c1_i503];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 132),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i504;
  real_T c1_b_inData[132];
  int32_T c1_i505;
  real_T c1_u[132];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i504 = 0; c1_i504 < 132; c1_i504++) {
    c1_b_inData[c1_i504] = (*(real_T (*)[132])c1_inData)[c1_i504];
  }

  for (c1_i505 = 0; c1_i505 < 132; c1_i505++) {
    c1_u[c1_i505] = c1_b_inData[c1_i505];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 132), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i506;
  char_T c1_b_inData[137];
  int32_T c1_i507;
  char_T c1_u[137];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i506 = 0; c1_i506 < 137; c1_i506++) {
    c1_b_inData[c1_i506] = (*(char_T (*)[137])c1_inData)[c1_i506];
  }

  for (c1_i507 = 0; c1_i507 < 137; c1_i507++) {
    c1_u[c1_i507] = c1_b_inData[c1_i507];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i508;
  real_T c1_b_inData[137];
  int32_T c1_i509;
  real_T c1_u[137];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i508 = 0; c1_i508 < 137; c1_i508++) {
    c1_b_inData[c1_i508] = (*(real_T (*)[137])c1_inData)[c1_i508];
  }

  for (c1_i509 = 0; c1_i509 < 137; c1_i509++) {
    c1_u[c1_i509] = c1_b_inData[c1_i509];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i510;
  char_T c1_b_inData[134];
  int32_T c1_i511;
  char_T c1_u[134];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i510 = 0; c1_i510 < 134; c1_i510++) {
    c1_b_inData[c1_i510] = (*(char_T (*)[134])c1_inData)[c1_i510];
  }

  for (c1_i511 = 0; c1_i511 < 134; c1_i511++) {
    c1_u[c1_i511] = c1_b_inData[c1_i511];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i512;
  real_T c1_b_inData[134];
  int32_T c1_i513;
  real_T c1_u[134];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i512 = 0; c1_i512 < 134; c1_i512++) {
    c1_b_inData[c1_i512] = (*(real_T (*)[134])c1_inData)[c1_i512];
  }

  for (c1_i513 = 0; c1_i513 < 134; c1_i513++) {
    c1_u[c1_i513] = c1_b_inData[c1_i513];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i514;
  char_T c1_b_inData[130];
  int32_T c1_i515;
  char_T c1_u[130];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i514 = 0; c1_i514 < 130; c1_i514++) {
    c1_b_inData[c1_i514] = (*(char_T (*)[130])c1_inData)[c1_i514];
  }

  for (c1_i515 = 0; c1_i515 < 130; c1_i515++) {
    c1_u[c1_i515] = c1_b_inData[c1_i515];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 130),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i516;
  real_T c1_b_inData[130];
  int32_T c1_i517;
  real_T c1_u[130];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i516 = 0; c1_i516 < 130; c1_i516++) {
    c1_b_inData[c1_i516] = (*(real_T (*)[130])c1_inData)[c1_i516];
  }

  for (c1_i517 = 0; c1_i517 < 130; c1_i517++) {
    c1_u[c1_i517] = c1_b_inData[c1_i517];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 130), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i518;
  char_T c1_b_inData[97];
  int32_T c1_i519;
  char_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i518 = 0; c1_i518 < 97; c1_i518++) {
    c1_b_inData[c1_i518] = (*(char_T (*)[97])c1_inData)[c1_i518];
  }

  for (c1_i519 = 0; c1_i519 < 97; c1_i519++) {
    c1_u[c1_i519] = c1_b_inData[c1_i519];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i520;
  real_T c1_b_inData[97];
  int32_T c1_i521;
  real_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i520 = 0; c1_i520 < 97; c1_i520++) {
    c1_b_inData[c1_i520] = (*(real_T (*)[97])c1_inData)[c1_i520];
  }

  for (c1_i521 = 0; c1_i521 < 97; c1_i521++) {
    c1_u[c1_i521] = c1_b_inData[c1_i521];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i522;
  char_T c1_b_inData[93];
  int32_T c1_i523;
  char_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i522 = 0; c1_i522 < 93; c1_i522++) {
    c1_b_inData[c1_i522] = (*(char_T (*)[93])c1_inData)[c1_i522];
  }

  for (c1_i523 = 0; c1_i523 < 93; c1_i523++) {
    c1_u[c1_i523] = c1_b_inData[c1_i523];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i524;
  real_T c1_b_inData[93];
  int32_T c1_i525;
  real_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i524 = 0; c1_i524 < 93; c1_i524++) {
    c1_b_inData[c1_i524] = (*(real_T (*)[93])c1_inData)[c1_i524];
  }

  for (c1_i525 = 0; c1_i525 < 93; c1_i525++) {
    c1_u[c1_i525] = c1_b_inData[c1_i525];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i526;
  char_T c1_b_inData[95];
  int32_T c1_i527;
  char_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i526 = 0; c1_i526 < 95; c1_i526++) {
    c1_b_inData[c1_i526] = (*(char_T (*)[95])c1_inData)[c1_i526];
  }

  for (c1_i527 = 0; c1_i527 < 95; c1_i527++) {
    c1_u[c1_i527] = c1_b_inData[c1_i527];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i528;
  real_T c1_b_inData[95];
  int32_T c1_i529;
  real_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i528 = 0; c1_i528 < 95; c1_i528++) {
    c1_b_inData[c1_i528] = (*(real_T (*)[95])c1_inData)[c1_i528];
  }

  for (c1_i529 = 0; c1_i529 < 95; c1_i529++) {
    c1_u[c1_i529] = c1_b_inData[c1_i529];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i530;
  char_T c1_b_inData[92];
  int32_T c1_i531;
  char_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i530 = 0; c1_i530 < 92; c1_i530++) {
    c1_b_inData[c1_i530] = (*(char_T (*)[92])c1_inData)[c1_i530];
  }

  for (c1_i531 = 0; c1_i531 < 92; c1_i531++) {
    c1_u[c1_i531] = c1_b_inData[c1_i531];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i532;
  real_T c1_b_inData[92];
  int32_T c1_i533;
  real_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i532 = 0; c1_i532 < 92; c1_i532++) {
    c1_b_inData[c1_i532] = (*(real_T (*)[92])c1_inData)[c1_i532];
  }

  for (c1_i533 = 0; c1_i533 < 92; c1_i533++) {
    c1_u[c1_i533] = c1_b_inData[c1_i533];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray
  *sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("randi"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rand"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eps"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_eps"), "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isequal"), "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_sendBML(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_arg[256])
{
  int32_T c1_i534;
  int32_T c1_i535;
  int32_T c1_i536;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c1_i534 = 0; c1_i534 < 256; c1_i534++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i534], 30U);
  }

  _SFD_SET_DATA_VALUE_PTR(30U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i535 = 0; c1_i535 < 256; c1_i535++) {
    (*c1_b_arg)[c1_i535] = c1_arg[c1_i535];
  }

  for (c1_i536 = 0; c1_i536 < 256; c1_i536++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i536], 30U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(30U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
}

static void c1_handPoseSB
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   real_T c1_sbmID, real_T c1_poseSBM[256])
{
  uint32_T c1_debug_family_var_map[10];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv89[256];
  int32_T c1_i537;
  int32_T c1_i538;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i539;
  int32_T c1_i540;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i541;
  int32_T c1_i542;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i543;
  int32_T c1_i544;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[83];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[83];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i545;
  static char_T c1_cv52[83] = { 'R', 'a', 'c', 'h', 'e', 'l', '.', 'g', 'e', 't',
    'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J',
    'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w',
    'r', 'i', 's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r',
    'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(',
    '-', '1', ',', '0', '.', '1', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c1_i546;
  static real_T c1_dv90[83] = { 82.0, 97.0, 99.0, 104.0, 101.0, 108.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0,
    105.0, 115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 45.0, 49.0, 44.0, 48.0, 46.0,
    49.0, 44.0, 48.0, 44.0, 48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i547;
  int32_T c1_i548;
  int32_T c1_i549;
  int32_T c1_i550;
  int32_T c1_i551;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i552;
  int32_T c1_i553;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i554;
  int32_T c1_i555;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_h_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sbmID, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseSBM, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 13);
  c1_aVarTruthTableCondition_1 = (c1_sbmID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 17);
  c1_aVarTruthTableCondition_2 = (c1_sbmID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 21);
  c1_aVarTruthTableCondition_3 = (c1_sbmID == 3.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 25);
  c1_aVarTruthTableCondition_4 = (c1_sbmID == 4.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 29);
  c1_aVarTruthTableCondition_5 = (c1_sbmID == 5.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 33);
  c1_aVarTruthTableCondition_6 = (c1_sbmID == 6.0);
  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 35);
  if (CV_EML_IF(4, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 36);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 55);
    c1_d_encStr2Arr(chartInstance, c1_dv89);
    for (c1_i537 = 0; c1_i537 < 256; c1_i537++) {
      c1_poseSBM[c1_i537] = c1_dv89[c1_i537];
    }

    c1_updateDataWrittenToVector(chartInstance, 31U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
    sf_mex_printf("%s =\\n", "poseSBM");
    for (c1_i538 = 0; c1_i538 < 256; c1_i538++) {
      c1_u[c1_i538] = c1_poseSBM[c1_i538];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -55);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 37);
    if (CV_EML_IF(4, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 38);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 61);
      c1_e_encStr2Arr(chartInstance, c1_dv89);
      for (c1_i539 = 0; c1_i539 < 256; c1_i539++) {
        c1_poseSBM[c1_i539] = c1_dv89[c1_i539];
      }

      c1_updateDataWrittenToVector(chartInstance, 31U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
      sf_mex_printf("%s =\\n", "poseSBM");
      for (c1_i540 = 0; c1_i540 < 256; c1_i540++) {
        c1_b_u[c1_i540] = c1_poseSBM[c1_i540];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -61);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 39);
      if (CV_EML_IF(4, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 40);
        CV_EML_FCN(4, 3);
        _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 67);
        c1_f_encStr2Arr(chartInstance, c1_dv89);
        for (c1_i541 = 0; c1_i541 < 256; c1_i541++) {
          c1_poseSBM[c1_i541] = c1_dv89[c1_i541];
        }

        c1_updateDataWrittenToVector(chartInstance, 31U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
        sf_mex_printf("%s =\\n", "poseSBM");
        for (c1_i542 = 0; c1_i542 < 256; c1_i542++) {
          c1_c_u[c1_i542] = c1_poseSBM[c1_i542];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -67);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 41);
        if (CV_EML_IF(4, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 42);
          CV_EML_FCN(4, 4);
          _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 73);
          c1_g_encStr2Arr(chartInstance, c1_dv89);
          for (c1_i543 = 0; c1_i543 < 256; c1_i543++) {
            c1_poseSBM[c1_i543] = c1_dv89[c1_i543];
          }

          c1_updateDataWrittenToVector(chartInstance, 31U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
          sf_mex_printf("%s =\\n", "poseSBM");
          for (c1_i544 = 0; c1_i544 < 256; c1_i544++) {
            c1_d_u[c1_i544] = c1_poseSBM[c1_i544];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -73);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 43);
          if (CV_EML_IF(4, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 44);
            CV_EML_FCN(4, 5);
            _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 79);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_m_debug_family_names,
              c1_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_r_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
              c1_d_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_q_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
              c1_d_sf_marshallOut, c1_d_sf_marshallIn);
            for (c1_i545 = 0; c1_i545 < 83; c1_i545++) {
              c1_mystr[c1_i545] = c1_cv52[c1_i545];
            }

            CV_SCRIPT_FCN(0, 0);
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
            c1_maxarrsize = 256.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
            for (c1_i546 = 0; c1_i546 < 83; c1_i546++) {
              c1_arr[c1_i546] = c1_dv90[c1_i546];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
            c1_ss = 83.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
            c1_padsize = c1_maxarrsize - c1_ss;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
            for (c1_i547 = 0; c1_i547 < 256; c1_i547++) {
              c1_tt[c1_i547] = 0.0;
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
            for (c1_i548 = 0; c1_i548 < 83; c1_i548++) {
              c1_tt[c1_i548] = c1_arr[c1_i548];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
            for (c1_i549 = 0; c1_i549 < 256; c1_i549++) {
              c1_myarr256[c1_i549] = c1_tt[c1_i549];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
            _SFD_SYMBOL_SCOPE_POP();
            for (c1_i550 = 0; c1_i550 < 256; c1_i550++) {
              c1_poseSBM[c1_i550] = c1_myarr256[c1_i550];
            }

            c1_updateDataWrittenToVector(chartInstance, 31U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
            sf_mex_printf("%s =\\n", "poseSBM");
            for (c1_i551 = 0; c1_i551 < 256; c1_i551++) {
              c1_e_u[c1_i551] = c1_poseSBM[c1_i551];
            }

            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_e_y);
            _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -79);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 45);
            if (CV_EML_IF(4, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 46);
              CV_EML_FCN(4, 6);
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 85);
              c1_h_encStr2Arr(chartInstance, c1_dv89);
              for (c1_i552 = 0; c1_i552 < 256; c1_i552++) {
                c1_poseSBM[c1_i552] = c1_dv89[c1_i552];
              }

              c1_updateDataWrittenToVector(chartInstance, 31U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c1_i553 = 0; c1_i553 < 256; c1_i553++) {
                c1_f_u[c1_i553] = c1_poseSBM[c1_i553];
              }

              c1_f_y = NULL;
              sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_f_y);
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -85);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 48);
              CV_EML_FCN(4, 6);
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, 85);
              c1_h_encStr2Arr(chartInstance, c1_dv89);
              for (c1_i554 = 0; c1_i554 < 256; c1_i554++) {
                c1_poseSBM[c1_i554] = c1_dv89[c1_i554];
              }

              c1_updateDataWrittenToVector(chartInstance, 31U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 31U, 38U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c1_i555 = 0; c1_i555 < 256; c1_i555++) {
                c1_g_u[c1_i555] = c1_poseSBM[c1_i555];
              }

              c1_g_y = NULL;
              sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_g_y);
              _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -85);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c1_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_idlePose(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *
  chartInstance, real_T c1_bmlID, real_T c1_poseBML[256])
{
  uint32_T c1_debug_family_var_map[12];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  boolean_T c1_aVarTruthTableCondition_7;
  boolean_T c1_aVarTruthTableCondition_8;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv91[256];
  int32_T c1_i556;
  int32_T c1_i557;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i558;
  int32_T c1_i559;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[68];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[68];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i560;
  static char_T c1_cv53[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i561;
  static real_T c1_dv92[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i562;
  int32_T c1_i563;
  int32_T c1_i564;
  int32_T c1_i565;
  int32_T c1_i566;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i567;
  int32_T c1_i568;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i569;
  int32_T c1_i570;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i571;
  int32_T c1_i572;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i573;
  int32_T c1_i574;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i575;
  int32_T c1_i576;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  int32_T c1_i577;
  int32_T c1_i578;
  real_T c1_i_u[256];
  const mxArray *c1_i_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c1_o_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_7, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_8, 7U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 10U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_poseBML, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 19);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 23);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 27);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 31);
  c1_aVarTruthTableCondition_5 = (c1_bmlID == 5.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 35);
  c1_aVarTruthTableCondition_6 = (c1_bmlID == 6.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 39);
  c1_aVarTruthTableCondition_7 = (c1_bmlID == 7.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 43);
  c1_aVarTruthTableCondition_8 = (c1_bmlID == 8.0);
  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 45);
  if (CV_EML_IF(5, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 46);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 69);
    c1_i_encStr2Arr(chartInstance, c1_dv91);
    for (c1_i556 = 0; c1_i556 < 256; c1_i556++) {
      c1_poseBML[c1_i556] = c1_dv91[c1_i556];
    }

    c1_updateDataWrittenToVector(chartInstance, 32U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i557 = 0; c1_i557 < 256; c1_i557++) {
      c1_u[c1_i557] = c1_poseBML[c1_i557];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -69);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 47);
    if (CV_EML_IF(5, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 48);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 75);
      c1_j_encStr2Arr(chartInstance, c1_dv91);
      for (c1_i558 = 0; c1_i558 < 256; c1_i558++) {
        c1_poseBML[c1_i558] = c1_dv91[c1_i558];
      }

      c1_updateDataWrittenToVector(chartInstance, 32U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i559 = 0; c1_i559 < 256; c1_i559++) {
        c1_b_u[c1_i559] = c1_poseBML[c1_i559];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -75);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 49);
      if (CV_EML_IF(5, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 50);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 81);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_r_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ab_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
          c1_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_y_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
          c1_d_sf_marshallOut, c1_d_sf_marshallIn);
        for (c1_i560 = 0; c1_i560 < 68; c1_i560++) {
          c1_mystr[c1_i560] = c1_cv53[c1_i560];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
        c1_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
        for (c1_i561 = 0; c1_i561 < 68; c1_i561++) {
          c1_arr[c1_i561] = c1_dv92[c1_i561];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
        c1_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
        c1_padsize = c1_maxarrsize - c1_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
        for (c1_i562 = 0; c1_i562 < 256; c1_i562++) {
          c1_tt[c1_i562] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
        for (c1_i563 = 0; c1_i563 < 68; c1_i563++) {
          c1_tt[c1_i563] = c1_arr[c1_i563];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
        for (c1_i564 = 0; c1_i564 < 256; c1_i564++) {
          c1_myarr256[c1_i564] = c1_tt[c1_i564];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c1_i565 = 0; c1_i565 < 256; c1_i565++) {
          c1_poseBML[c1_i565] = c1_myarr256[c1_i565];
        }

        c1_updateDataWrittenToVector(chartInstance, 32U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i566 = 0; c1_i566 < 256; c1_i566++) {
          c1_c_u[c1_i566] = c1_poseBML[c1_i566];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -81);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 51);
        if (CV_EML_IF(5, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 52);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 87);
          c1_k_encStr2Arr(chartInstance, c1_dv91);
          for (c1_i567 = 0; c1_i567 < 256; c1_i567++) {
            c1_poseBML[c1_i567] = c1_dv91[c1_i567];
          }

          c1_updateDataWrittenToVector(chartInstance, 32U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i568 = 0; c1_i568 < 256; c1_i568++) {
            c1_d_u[c1_i568] = c1_poseBML[c1_i568];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -87);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 53);
          if (CV_EML_IF(5, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 54);
            CV_EML_FCN(5, 5);
            _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 93);
            c1_l_encStr2Arr(chartInstance, c1_dv91);
            for (c1_i569 = 0; c1_i569 < 256; c1_i569++) {
              c1_poseBML[c1_i569] = c1_dv91[c1_i569];
            }

            c1_updateDataWrittenToVector(chartInstance, 32U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c1_i570 = 0; c1_i570 < 256; c1_i570++) {
              c1_e_u[c1_i570] = c1_poseBML[c1_i570];
            }

            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_e_y);
            _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -93);
          } else {
            _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 55);
            if (CV_EML_IF(5, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 56);
              CV_EML_FCN(5, 6);
              _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 99);
              c1_m_encStr2Arr(chartInstance, c1_dv91);
              for (c1_i571 = 0; c1_i571 < 256; c1_i571++) {
                c1_poseBML[c1_i571] = c1_dv91[c1_i571];
              }

              c1_updateDataWrittenToVector(chartInstance, 32U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c1_i572 = 0; c1_i572 < 256; c1_i572++) {
                c1_f_u[c1_i572] = c1_poseBML[c1_i572];
              }

              c1_f_y = NULL;
              sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_f_y);
              _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -99);
            } else {
              _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 57);
              if (CV_EML_IF(5, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 58);
                CV_EML_FCN(5, 7);
                _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 105);
                c1_n_encStr2Arr(chartInstance, c1_dv91);
                for (c1_i573 = 0; c1_i573 < 256; c1_i573++) {
                  c1_poseBML[c1_i573] = c1_dv91[c1_i573];
                }

                c1_updateDataWrittenToVector(chartInstance, 32U);
                c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c1_i574 = 0; c1_i574 < 256; c1_i574++) {
                  c1_g_u[c1_i574] = c1_poseBML[c1_i574];
                }

                c1_g_y = NULL;
                sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c1_g_y);
                _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -105);
              } else {
                _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 59);
                if (CV_EML_IF(5, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 60);
                  CV_EML_FCN(5, 8);
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 111);
                  c1_o_encStr2Arr(chartInstance, c1_dv91);
                  for (c1_i575 = 0; c1_i575 < 256; c1_i575++) {
                    c1_poseBML[c1_i575] = c1_dv91[c1_i575];
                  }

                  c1_updateDataWrittenToVector(chartInstance, 32U);
                  c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i576 = 0; c1_i576 < 256; c1_i576++) {
                    c1_h_u[c1_i576] = c1_poseBML[c1_i576];
                  }

                  c1_h_y = NULL;
                  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c1_h_y);
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -111);
                } else {
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 62);
                  CV_EML_FCN(5, 8);
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, 111);
                  c1_o_encStr2Arr(chartInstance, c1_dv91);
                  for (c1_i577 = 0; c1_i577 < 256; c1_i577++) {
                    c1_poseBML[c1_i577] = c1_dv91[c1_i577];
                  }

                  c1_updateDataWrittenToVector(chartInstance, 32U);
                  c1_errorIfDataNotWrittenToFcn(chartInstance, 32U, 40U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i578 = 0; c1_i578 < 256; c1_i578++) {
                    c1_i_u[c1_i578] = c1_poseBML[c1_i578];
                  }

                  c1_i_y = NULL;
                  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c1_i_y);
                  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -111);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c1_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_boredGaze(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_gazeBML[256])
{
  uint32_T c1_debug_family_var_map[37];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  boolean_T c1_aVarTruthTableCondition_4;
  boolean_T c1_aVarTruthTableCondition_5;
  boolean_T c1_aVarTruthTableCondition_6;
  boolean_T c1_aVarTruthTableCondition_7;
  boolean_T c1_aVarTruthTableCondition_8;
  boolean_T c1_aVarTruthTableCondition_9;
  boolean_T c1_aVarTruthTableCondition_10;
  boolean_T c1_aVarTruthTableCondition_11;
  boolean_T c1_aVarTruthTableCondition_12;
  boolean_T c1_aVarTruthTableCondition_13;
  boolean_T c1_aVarTruthTableCondition_14;
  boolean_T c1_aVarTruthTableCondition_15;
  boolean_T c1_aVarTruthTableCondition_16;
  boolean_T c1_aVarTruthTableCondition_17;
  boolean_T c1_aVarTruthTableCondition_18;
  boolean_T c1_aVarTruthTableCondition_19;
  boolean_T c1_aVarTruthTableCondition_20;
  boolean_T c1_aVarTruthTableCondition_21;
  boolean_T c1_aVarTruthTableCondition_22;
  boolean_T c1_aVarTruthTableCondition_23;
  boolean_T c1_aVarTruthTableCondition_24;
  boolean_T c1_aVarTruthTableCondition_25;
  boolean_T c1_aVarTruthTableCondition_26;
  boolean_T c1_aVarTruthTableCondition_27;
  boolean_T c1_aVarTruthTableCondition_28;
  boolean_T c1_aVarTruthTableCondition_29;
  boolean_T c1_aVarTruthTableCondition_30;
  boolean_T c1_aVarTruthTableCondition_31;
  boolean_T c1_aVarTruthTableCondition_32;
  boolean_T c1_aVarTruthTableCondition_33;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv93[256];
  int32_T c1_i579;
  int32_T c1_i580;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  real_T c1_dv94[256];
  int32_T c1_i581;
  int32_T c1_i582;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  real_T c1_dv95[256];
  int32_T c1_i583;
  int32_T c1_i584;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  real_T c1_dv96[256];
  int32_T c1_i585;
  int32_T c1_i586;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  real_T c1_dv97[256];
  int32_T c1_i587;
  int32_T c1_i588;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  real_T c1_dv98[256];
  int32_T c1_i589;
  int32_T c1_i590;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  real_T c1_dv99[256];
  int32_T c1_i591;
  int32_T c1_i592;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  real_T c1_dv100[256];
  int32_T c1_i593;
  int32_T c1_i594;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  real_T c1_dv101[256];
  int32_T c1_i595;
  int32_T c1_i596;
  real_T c1_i_u[256];
  const mxArray *c1_i_y = NULL;
  real_T c1_dv102[256];
  int32_T c1_i597;
  int32_T c1_i598;
  real_T c1_j_u[256];
  const mxArray *c1_j_y = NULL;
  real_T c1_dv103[256];
  int32_T c1_i599;
  int32_T c1_i600;
  real_T c1_k_u[256];
  const mxArray *c1_k_y = NULL;
  real_T c1_dv104[256];
  int32_T c1_i601;
  int32_T c1_i602;
  real_T c1_l_u[256];
  const mxArray *c1_l_y = NULL;
  real_T c1_dv105[256];
  int32_T c1_i603;
  int32_T c1_i604;
  real_T c1_m_u[256];
  const mxArray *c1_m_y = NULL;
  real_T c1_dv106[256];
  int32_T c1_i605;
  int32_T c1_i606;
  real_T c1_n_u[256];
  const mxArray *c1_n_y = NULL;
  real_T c1_dv107[256];
  int32_T c1_i607;
  int32_T c1_i608;
  real_T c1_o_u[256];
  const mxArray *c1_o_y = NULL;
  real_T c1_dv108[256];
  int32_T c1_i609;
  int32_T c1_i610;
  real_T c1_p_u[256];
  const mxArray *c1_p_y = NULL;
  real_T c1_dv109[256];
  int32_T c1_i611;
  int32_T c1_i612;
  real_T c1_q_u[256];
  const mxArray *c1_q_y = NULL;
  real_T c1_dv110[256];
  int32_T c1_i613;
  int32_T c1_i614;
  real_T c1_r_u[256];
  const mxArray *c1_r_y = NULL;
  real_T c1_dv111[256];
  int32_T c1_i615;
  int32_T c1_i616;
  real_T c1_s_u[256];
  const mxArray *c1_s_y = NULL;
  real_T c1_dv112[256];
  int32_T c1_i617;
  int32_T c1_i618;
  real_T c1_t_u[256];
  const mxArray *c1_t_y = NULL;
  real_T c1_dv113[256];
  int32_T c1_i619;
  int32_T c1_i620;
  real_T c1_u_u[256];
  const mxArray *c1_u_y = NULL;
  real_T c1_dv114[256];
  int32_T c1_i621;
  int32_T c1_i622;
  real_T c1_v_u[256];
  const mxArray *c1_v_y = NULL;
  real_T c1_dv115[256];
  int32_T c1_i623;
  int32_T c1_i624;
  real_T c1_w_u[256];
  const mxArray *c1_w_y = NULL;
  real_T c1_dv116[256];
  int32_T c1_i625;
  int32_T c1_i626;
  real_T c1_x_u[256];
  const mxArray *c1_x_y = NULL;
  real_T c1_dv117[256];
  int32_T c1_i627;
  int32_T c1_i628;
  real_T c1_y_u[256];
  const mxArray *c1_y_y = NULL;
  real_T c1_dv118[256];
  int32_T c1_i629;
  int32_T c1_i630;
  real_T c1_ab_u[256];
  const mxArray *c1_ab_y = NULL;
  real_T c1_dv119[256];
  int32_T c1_i631;
  int32_T c1_i632;
  real_T c1_bb_u[256];
  const mxArray *c1_bb_y = NULL;
  real_T c1_dv120[256];
  int32_T c1_i633;
  int32_T c1_i634;
  real_T c1_cb_u[256];
  const mxArray *c1_cb_y = NULL;
  real_T c1_dv121[256];
  int32_T c1_i635;
  int32_T c1_i636;
  real_T c1_db_u[256];
  const mxArray *c1_db_y = NULL;
  real_T c1_dv122[256];
  int32_T c1_i637;
  int32_T c1_i638;
  real_T c1_eb_u[256];
  const mxArray *c1_eb_y = NULL;
  real_T c1_dv123[256];
  int32_T c1_i639;
  int32_T c1_i640;
  real_T c1_fb_u[256];
  const mxArray *c1_fb_y = NULL;
  real_T c1_dv124[256];
  int32_T c1_i641;
  int32_T c1_i642;
  real_T c1_gb_u[256];
  const mxArray *c1_gb_y = NULL;
  real_T c1_dv125[256];
  int32_T c1_i643;
  int32_T c1_i644;
  real_T c1_hb_u[256];
  const mxArray *c1_hb_y = NULL;
  real_T c1_dv126[256];
  int32_T c1_i645;
  int32_T c1_i646;
  real_T c1_ib_u[256];
  const mxArray *c1_ib_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 37U, 37U, c1_wc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_4, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_5, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_6, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_7, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_8, 7U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_9, 8U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_10, 9U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_11, 10U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_12, 11U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_13, 12U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_14, 13U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_15, 14U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_16, 15U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_17, 16U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_18, 17U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_19, 18U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_20, 19U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_21, 20U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_22, 21U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_23, 22U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_24, 23U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_25, 24U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_26, 25U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_27, 26U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_28, 27U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_29, 28U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_30, 29U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_31, 30U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_32, 31U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_33, 32U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 33U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 34U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 35U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_gazeBML, 36U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 6);
  c1_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 7);
  c1_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 8);
  c1_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 9);
  c1_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 11);
  c1_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 12);
  c1_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 13);
  c1_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 14);
  c1_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 15);
  c1_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 16);
  c1_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 17);
  c1_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 18);
  c1_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 19);
  c1_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 20);
  c1_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 21);
  c1_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 22);
  c1_aVarTruthTableCondition_20 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 23);
  c1_aVarTruthTableCondition_21 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 24);
  c1_aVarTruthTableCondition_22 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 25);
  c1_aVarTruthTableCondition_23 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 26);
  c1_aVarTruthTableCondition_24 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 27);
  c1_aVarTruthTableCondition_25 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 28);
  c1_aVarTruthTableCondition_26 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 29);
  c1_aVarTruthTableCondition_27 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 30);
  c1_aVarTruthTableCondition_28 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 31);
  c1_aVarTruthTableCondition_29 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 32);
  c1_aVarTruthTableCondition_30 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 33);
  c1_aVarTruthTableCondition_31 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 34);
  c1_aVarTruthTableCondition_32 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 35);
  c1_aVarTruthTableCondition_33 = false;
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 39);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 42);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 45);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 48);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 51);
  c1_aVarTruthTableCondition_5 = (c1_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 54);
  c1_aVarTruthTableCondition_6 = (c1_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 57);
  c1_aVarTruthTableCondition_7 = (c1_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 60);
  c1_aVarTruthTableCondition_8 = (c1_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 63);
  c1_aVarTruthTableCondition_9 = (c1_bmlID == 9.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 66);
  c1_aVarTruthTableCondition_10 = (c1_bmlID == 10.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 69);
  c1_aVarTruthTableCondition_11 = (c1_bmlID == 11.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 72);
  c1_aVarTruthTableCondition_12 = (c1_bmlID == 12.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 75);
  c1_aVarTruthTableCondition_13 = (c1_bmlID == 13.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 78);
  c1_aVarTruthTableCondition_14 = (c1_bmlID == 14.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 81);
  c1_aVarTruthTableCondition_15 = (c1_bmlID == 15.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 84);
  c1_aVarTruthTableCondition_16 = (c1_bmlID == 16.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 87);
  c1_aVarTruthTableCondition_17 = (c1_bmlID == 17.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 90);
  c1_aVarTruthTableCondition_18 = (c1_bmlID == 18.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 93);
  c1_aVarTruthTableCondition_19 = (c1_bmlID == 19.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 96);
  c1_aVarTruthTableCondition_20 = (c1_bmlID == 20.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 99);
  c1_aVarTruthTableCondition_21 = (c1_bmlID == 21.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 102);
  c1_aVarTruthTableCondition_22 = (c1_bmlID == 22.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 105);
  c1_aVarTruthTableCondition_23 = (c1_bmlID == 23.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 108);
  c1_aVarTruthTableCondition_24 = (c1_bmlID == 24.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 111);
  c1_aVarTruthTableCondition_25 = (c1_bmlID == 25.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 114);
  c1_aVarTruthTableCondition_26 = (c1_bmlID == 26.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 117);
  c1_aVarTruthTableCondition_27 = (c1_bmlID == 27.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 120);
  c1_aVarTruthTableCondition_28 = (c1_bmlID == 28.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 123);
  c1_aVarTruthTableCondition_29 = (c1_bmlID == 29.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 126);
  c1_aVarTruthTableCondition_30 = (c1_bmlID == 30.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 129U);
  c1_aVarTruthTableCondition_31 = (c1_bmlID == 31.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 132U);
  c1_aVarTruthTableCondition_32 = (c1_bmlID == 32.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 135U);
  c1_aVarTruthTableCondition_33 = (c1_bmlID == 33.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 137U);
  if (CV_EML_IF(1, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 138U);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 211U);
    c1_p_encStr2Arr(chartInstance, c1_dv93);
    for (c1_i579 = 0; c1_i579 < 256; c1_i579++) {
      c1_gazeBML[c1_i579] = c1_dv93[c1_i579];
    }

    sf_mex_printf("%s =\\n", "gazeBML");
    for (c1_i580 = 0; c1_i580 < 256; c1_i580++) {
      c1_u[c1_i580] = c1_gazeBML[c1_i580];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -211);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 139U);
    if (CV_EML_IF(1, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 140U);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 217U);
      c1_q_encStr2Arr(chartInstance, c1_dv94);
      for (c1_i581 = 0; c1_i581 < 256; c1_i581++) {
        c1_gazeBML[c1_i581] = c1_dv94[c1_i581];
      }

      sf_mex_printf("%s =\\n", "gazeBML");
      for (c1_i582 = 0; c1_i582 < 256; c1_i582++) {
        c1_b_u[c1_i582] = c1_gazeBML[c1_i582];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -217);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 141U);
      if (CV_EML_IF(1, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 142U);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 223U);
        c1_r_encStr2Arr(chartInstance, c1_dv95);
        for (c1_i583 = 0; c1_i583 < 256; c1_i583++) {
          c1_gazeBML[c1_i583] = c1_dv95[c1_i583];
        }

        sf_mex_printf("%s =\\n", "gazeBML");
        for (c1_i584 = 0; c1_i584 < 256; c1_i584++) {
          c1_c_u[c1_i584] = c1_gazeBML[c1_i584];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -223);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 143U);
        if (CV_EML_IF(1, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 144U);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 229U);
          c1_s_encStr2Arr(chartInstance, c1_dv96);
          for (c1_i585 = 0; c1_i585 < 256; c1_i585++) {
            c1_gazeBML[c1_i585] = c1_dv96[c1_i585];
          }

          sf_mex_printf("%s =\\n", "gazeBML");
          for (c1_i586 = 0; c1_i586 < 256; c1_i586++) {
            c1_d_u[c1_i586] = c1_gazeBML[c1_i586];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -229);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 145U);
          if (CV_EML_IF(1, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 146U);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 235U);
            c1_t_encStr2Arr(chartInstance, c1_dv97);
            for (c1_i587 = 0; c1_i587 < 256; c1_i587++) {
              c1_gazeBML[c1_i587] = c1_dv97[c1_i587];
            }

            sf_mex_printf("%s =\\n", "gazeBML");
            for (c1_i588 = 0; c1_i588 < 256; c1_i588++) {
              c1_e_u[c1_i588] = c1_gazeBML[c1_i588];
            }

            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_e_y);
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -235);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 147U);
            if (CV_EML_IF(1, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 148U);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 241U);
              c1_u_encStr2Arr(chartInstance, c1_dv98);
              for (c1_i589 = 0; c1_i589 < 256; c1_i589++) {
                c1_gazeBML[c1_i589] = c1_dv98[c1_i589];
              }

              sf_mex_printf("%s =\\n", "gazeBML");
              for (c1_i590 = 0; c1_i590 < 256; c1_i590++) {
                c1_f_u[c1_i590] = c1_gazeBML[c1_i590];
              }

              c1_f_y = NULL;
              sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_f_y);
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -241);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 149U);
              if (CV_EML_IF(1, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 150U);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 247U);
                c1_v_encStr2Arr(chartInstance, c1_dv99);
                for (c1_i591 = 0; c1_i591 < 256; c1_i591++) {
                  c1_gazeBML[c1_i591] = c1_dv99[c1_i591];
                }

                sf_mex_printf("%s =\\n", "gazeBML");
                for (c1_i592 = 0; c1_i592 < 256; c1_i592++) {
                  c1_g_u[c1_i592] = c1_gazeBML[c1_i592];
                }

                c1_g_y = NULL;
                sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c1_g_y);
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -247);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 151U);
                if (CV_EML_IF(1, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 152U);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 253U);
                  c1_w_encStr2Arr(chartInstance, c1_dv100);
                  for (c1_i593 = 0; c1_i593 < 256; c1_i593++) {
                    c1_gazeBML[c1_i593] = c1_dv100[c1_i593];
                  }

                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c1_i594 = 0; c1_i594 < 256; c1_i594++) {
                    c1_h_u[c1_i594] = c1_gazeBML[c1_i594];
                  }

                  c1_h_y = NULL;
                  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c1_h_y);
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -253);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 153U);
                  if (CV_EML_IF(1, 1, 8, c1_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 154U);
                    CV_EML_FCN(1, 1);
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 211U);
                    c1_p_encStr2Arr(chartInstance, c1_dv101);
                    for (c1_i595 = 0; c1_i595 < 256; c1_i595++) {
                      c1_gazeBML[c1_i595] = c1_dv101[c1_i595];
                    }

                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c1_i596 = 0; c1_i596 < 256; c1_i596++) {
                      c1_i_u[c1_i596] = c1_gazeBML[c1_i596];
                    }

                    c1_i_y = NULL;
                    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c1_i_y);
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -211);
                  } else {
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 155U);
                    if (CV_EML_IF(1, 1, 9, c1_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 156U);
                      CV_EML_FCN(1, 2);
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 217U);
                      c1_q_encStr2Arr(chartInstance, c1_dv102);
                      for (c1_i597 = 0; c1_i597 < 256; c1_i597++) {
                        c1_gazeBML[c1_i597] = c1_dv102[c1_i597];
                      }

                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c1_i598 = 0; c1_i598 < 256; c1_i598++) {
                        c1_j_u[c1_i598] = c1_gazeBML[c1_i598];
                      }

                      c1_j_y = NULL;
                      sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c1_j_y);
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -217);
                    } else {
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 157U);
                      if (CV_EML_IF(1, 1, 10, c1_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 158U);
                        CV_EML_FCN(1, 3);
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 223U);
                        c1_r_encStr2Arr(chartInstance, c1_dv103);
                        for (c1_i599 = 0; c1_i599 < 256; c1_i599++) {
                          c1_gazeBML[c1_i599] = c1_dv103[c1_i599];
                        }

                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c1_i600 = 0; c1_i600 < 256; c1_i600++) {
                          c1_k_u[c1_i600] = c1_gazeBML[c1_i600];
                        }

                        c1_k_y = NULL;
                        sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c1_k_y);
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -223);
                      } else {
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 159U);
                        if (CV_EML_IF(1, 1, 11, c1_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 160U);
                          CV_EML_FCN(1, 4);
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 229U);
                          c1_s_encStr2Arr(chartInstance, c1_dv104);
                          for (c1_i601 = 0; c1_i601 < 256; c1_i601++) {
                            c1_gazeBML[c1_i601] = c1_dv104[c1_i601];
                          }

                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c1_i602 = 0; c1_i602 < 256; c1_i602++) {
                            c1_l_u[c1_i602] = c1_gazeBML[c1_i602];
                          }

                          c1_l_y = NULL;
                          sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c1_l_y);
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -229);
                        } else {
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 161U);
                          if (CV_EML_IF(1, 1, 12, c1_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 162U);
                            CV_EML_FCN(1, 5);
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 235U);
                            c1_t_encStr2Arr(chartInstance, c1_dv105);
                            for (c1_i603 = 0; c1_i603 < 256; c1_i603++) {
                              c1_gazeBML[c1_i603] = c1_dv105[c1_i603];
                            }

                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c1_i604 = 0; c1_i604 < 256; c1_i604++) {
                              c1_m_u[c1_i604] = c1_gazeBML[c1_i604];
                            }

                            c1_m_y = NULL;
                            sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c1_m_y);
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -235);
                          } else {
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 163U);
                            if (CV_EML_IF(1, 1, 13,
                                          c1_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 164U);
                              CV_EML_FCN(1, 6);
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 241U);
                              c1_u_encStr2Arr(chartInstance, c1_dv106);
                              for (c1_i605 = 0; c1_i605 < 256; c1_i605++) {
                                c1_gazeBML[c1_i605] = c1_dv106[c1_i605];
                              }

                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c1_i606 = 0; c1_i606 < 256; c1_i606++) {
                                c1_n_u[c1_i606] = c1_gazeBML[c1_i606];
                              }

                              c1_n_y = NULL;
                              sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c1_n_y);
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -241);
                            } else {
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 165U);
                              if (CV_EML_IF(1, 1, 14,
                                            c1_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              166U);
                                CV_EML_FCN(1, 7);
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              247U);
                                c1_v_encStr2Arr(chartInstance, c1_dv107);
                                for (c1_i607 = 0; c1_i607 < 256; c1_i607++) {
                                  c1_gazeBML[c1_i607] = c1_dv107[c1_i607];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c1_i608 = 0; c1_i608 < 256; c1_i608++) {
                                  c1_o_u[c1_i608] = c1_gazeBML[c1_i608];
                                }

                                c1_o_y = NULL;
                                sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c1_o_y);
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              -247);
                              } else {
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              167U);
                                if (CV_EML_IF(1, 1, 15,
                                              c1_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                168U);
                                  CV_EML_FCN(1, 8);
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                253U);
                                  c1_w_encStr2Arr(chartInstance, c1_dv108);
                                  for (c1_i609 = 0; c1_i609 < 256; c1_i609++) {
                                    c1_gazeBML[c1_i609] = c1_dv108[c1_i609];
                                  }

                                  sf_mex_printf("%s =\\n", "gazeBML");
                                  for (c1_i610 = 0; c1_i610 < 256; c1_i610++) {
                                    c1_p_u[c1_i610] = c1_gazeBML[c1_i610];
                                  }

                                  c1_p_y = NULL;
                                  sf_mex_assign(&c1_p_y, sf_mex_create("y",
                                    c1_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c1_p_y);
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                -253);
                                } else {
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                169U);
                                  if (CV_EML_IF(1, 1, 16,
                                                c1_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  170U);
                                    CV_EML_FCN(1, 17);
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  307);
                                    c1_x_encStr2Arr(chartInstance, c1_dv109);
                                    for (c1_i611 = 0; c1_i611 < 256; c1_i611++)
                                    {
                                      c1_gazeBML[c1_i611] = c1_dv109[c1_i611];
                                    }

                                    sf_mex_printf("%s =\\n", "gazeBML");
                                    for (c1_i612 = 0; c1_i612 < 256; c1_i612++)
                                    {
                                      c1_q_u[c1_i612] = c1_gazeBML[c1_i612];
                                    }

                                    c1_q_y = NULL;
                                    sf_mex_assign(&c1_q_y, sf_mex_create("y",
                                      c1_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c1_q_y);
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  -307);
                                  } else {
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  171U);
                                    if (CV_EML_IF(1, 1, 17,
                                                  c1_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    172U);
                                      CV_EML_FCN(1, 18);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    313);
                                      c1_y_encStr2Arr(chartInstance, c1_dv110);
                                      for (c1_i613 = 0; c1_i613 < 256; c1_i613++)
                                      {
                                        c1_gazeBML[c1_i613] = c1_dv110[c1_i613];
                                      }

                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c1_i614 = 0; c1_i614 < 256; c1_i614++)
                                      {
                                        c1_r_u[c1_i614] = c1_gazeBML[c1_i614];
                                      }

                                      c1_r_y = NULL;
                                      sf_mex_assign(&c1_r_y, sf_mex_create("y",
                                        c1_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c1_r_y);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    -313);
                                    } else {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    173U);
                                      if (CV_EML_IF(1, 1, 18,
                                                    c1_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      174U);
                                        CV_EML_FCN(1, 19);
                                        _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      319);
                                        c1_ab_encStr2Arr(chartInstance, c1_dv111);
                                        for (c1_i615 = 0; c1_i615 < 256; c1_i615
                                             ++) {
                                          c1_gazeBML[c1_i615] = c1_dv111[c1_i615];
                                        }

                                        sf_mex_printf("%s =\\n", "gazeBML");
                                        for (c1_i616 = 0; c1_i616 < 256; c1_i616
                                             ++) {
                                          c1_s_u[c1_i616] = c1_gazeBML[c1_i616];
                                        }

                                        c1_s_y = NULL;
                                        sf_mex_assign(&c1_s_y, sf_mex_create("y",
                                          c1_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                        sf_mex_call_debug
                                          (sfGlobalDebugInstanceStruct, "disp",
                                           0U, 1U, 14, c1_s_y);
                                        _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      -319);
                                      } else {
                                        _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      175U);
                                        if (CV_EML_IF(1, 1, 19,
                                                      c1_aVarTruthTableCondition_20))
                                        {
                                          _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        176U);
                                          CV_EML_FCN(1, 20);
                                          _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        325);
                                          c1_bb_encStr2Arr(chartInstance,
                                                           c1_dv112);
                                          for (c1_i617 = 0; c1_i617 < 256;
                                               c1_i617++) {
                                            c1_gazeBML[c1_i617] =
                                              c1_dv112[c1_i617];
                                          }

                                          sf_mex_printf("%s =\\n", "gazeBML");
                                          for (c1_i618 = 0; c1_i618 < 256;
                                               c1_i618++) {
                                            c1_t_u[c1_i618] = c1_gazeBML[c1_i618];
                                          }

                                          c1_t_y = NULL;
                                          sf_mex_assign(&c1_t_y, sf_mex_create(
                                            "y", c1_t_u, 0, 0U, 1U, 0U, 1, 256),
                                                        false);
                                          sf_mex_call_debug
                                            (sfGlobalDebugInstanceStruct, "disp",
                                             0U, 1U, 14, c1_t_y);
                                          _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        -325);
                                        } else {
                                          _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        177U);
                                          if (CV_EML_IF(1, 1, 20,
                                                        c1_aVarTruthTableCondition_21))
                                          {
                                            _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          178U);
                                            CV_EML_FCN(1, 21);
                                            _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          331);
                                            c1_cb_encStr2Arr(chartInstance,
                                              c1_dv113);
                                            for (c1_i619 = 0; c1_i619 < 256;
                                                 c1_i619++) {
                                              c1_gazeBML[c1_i619] =
                                                c1_dv113[c1_i619];
                                            }

                                            sf_mex_printf("%s =\\n", "gazeBML");
                                            for (c1_i620 = 0; c1_i620 < 256;
                                                 c1_i620++) {
                                              c1_u_u[c1_i620] =
                                                c1_gazeBML[c1_i620];
                                            }

                                            c1_u_y = NULL;
                                            sf_mex_assign(&c1_u_y, sf_mex_create
                                                          ("y", c1_u_u, 0, 0U,
                                                           1U, 0U, 1, 256),
                                                          false);
                                            sf_mex_call_debug
                                              (sfGlobalDebugInstanceStruct,
                                               "disp", 0U, 1U, 14, c1_u_y);
                                            _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          -331);
                                          } else {
                                            _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          179U);
                                            if (CV_EML_IF(1, 1, 21,
                                                          c1_aVarTruthTableCondition_22))
                                            {
                                              _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            180U);
                                              CV_EML_FCN(1, 22);
                                              _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            337);
                                              c1_db_encStr2Arr(chartInstance,
                                                c1_dv114);
                                              for (c1_i621 = 0; c1_i621 < 256;
                                                   c1_i621++) {
                                                c1_gazeBML[c1_i621] =
                                                  c1_dv114[c1_i621];
                                              }

                                              sf_mex_printf("%s =\\n", "gazeBML");
                                              for (c1_i622 = 0; c1_i622 < 256;
                                                   c1_i622++) {
                                                c1_v_u[c1_i622] =
                                                  c1_gazeBML[c1_i622];
                                              }

                                              c1_v_y = NULL;
                                              sf_mex_assign(&c1_v_y,
                                                            sf_mex_create("y",
                                                c1_v_u, 0, 0U, 1U, 0U, 1, 256),
                                                            false);
                                              sf_mex_call_debug
                                                (sfGlobalDebugInstanceStruct,
                                                 "disp", 0U, 1U, 14, c1_v_y);
                                              _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            -337);
                                            } else {
                                              _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            181U);
                                              if (CV_EML_IF(1, 1, 22,
                                                            c1_aVarTruthTableCondition_23))
                                              {
                                                _SFD_EML_CALL(1U,
                                                  chartInstance->c1_sfEvent,
                                                  182U);
                                                CV_EML_FCN(1, 23);
                                                _SFD_EML_CALL(1U,
                                                  chartInstance->c1_sfEvent, 343);
                                                c1_eb_encStr2Arr(chartInstance,
                                                  c1_dv115);
                                                for (c1_i623 = 0; c1_i623 < 256;
                                                     c1_i623++) {
                                                  c1_gazeBML[c1_i623] =
                                                    c1_dv115[c1_i623];
                                                }

                                                sf_mex_printf("%s =\\n",
                                                  "gazeBML");
                                                for (c1_i624 = 0; c1_i624 < 256;
                                                     c1_i624++) {
                                                  c1_w_u[c1_i624] =
                                                    c1_gazeBML[c1_i624];
                                                }

                                                c1_w_y = NULL;
                                                sf_mex_assign(&c1_w_y,
                                                  sf_mex_create("y", c1_w_u, 0,
                                                  0U, 1U, 0U, 1, 256), false);
                                                sf_mex_call_debug
                                                  (sfGlobalDebugInstanceStruct,
                                                   "disp", 0U, 1U, 14, c1_w_y);
                                                _SFD_EML_CALL(1U,
                                                  chartInstance->c1_sfEvent,
                                                  -343);
                                              } else {
                                                _SFD_EML_CALL(1U,
                                                  chartInstance->c1_sfEvent,
                                                  183U);
                                                if (CV_EML_IF(1, 1, 23,
                                                     c1_aVarTruthTableCondition_24))
                                                {
                                                  _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    184U);
                                                  CV_EML_FCN(1, 24);
                                                  _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    349);
                                                  c1_fb_encStr2Arr(chartInstance,
                                                    c1_dv116);
                                                  for (c1_i625 = 0; c1_i625 <
                                                       256; c1_i625++) {
                                                    c1_gazeBML[c1_i625] =
                                                      c1_dv116[c1_i625];
                                                  }

                                                  sf_mex_printf("%s =\\n",
                                                    "gazeBML");
                                                  for (c1_i626 = 0; c1_i626 <
                                                       256; c1_i626++) {
                                                    c1_x_u[c1_i626] =
                                                      c1_gazeBML[c1_i626];
                                                  }

                                                  c1_x_y = NULL;
                                                  sf_mex_assign(&c1_x_y,
                                                    sf_mex_create("y", c1_x_u, 0,
                                                    0U, 1U, 0U, 1, 256), false);
                                                  sf_mex_call_debug
                                                    (sfGlobalDebugInstanceStruct,
                                                     "disp", 0U, 1U, 14, c1_x_y);
                                                  _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    -349);
                                                } else {
                                                  _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    185U);
                                                  if (CV_EML_IF(1, 1, 24,
                                                       c1_aVarTruthTableCondition_25))
                                                  {
                                                    _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      186U);
                                                    CV_EML_FCN(1, 10);
                                                    _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      265);
                                                    c1_gb_encStr2Arr
                                                      (chartInstance, c1_dv117);
                                                    for (c1_i627 = 0; c1_i627 <
                                                         256; c1_i627++) {
                                                      c1_gazeBML[c1_i627] =
                                                        c1_dv117[c1_i627];
                                                    }

                                                    sf_mex_printf("%s =\\n",
                                                      "gazeBML");
                                                    for (c1_i628 = 0; c1_i628 <
                                                         256; c1_i628++) {
                                                      c1_y_u[c1_i628] =
                                                        c1_gazeBML[c1_i628];
                                                    }

                                                    c1_y_y = NULL;
                                                    sf_mex_assign(&c1_y_y,
                                                      sf_mex_create("y", c1_y_u,
                                                      0, 0U, 1U, 0U, 1, 256),
                                                      false);
                                                    sf_mex_call_debug
                                                      (sfGlobalDebugInstanceStruct,
                                                       "disp", 0U, 1U, 14,
                                                       c1_y_y);
                                                    _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      -265);
                                                  } else {
                                                    _SFD_EML_CALL(1U,
                                                      chartInstance->c1_sfEvent,
                                                      187U);
                                                    if (CV_EML_IF(1, 1, 25,
                                                         c1_aVarTruthTableCondition_26))
                                                    {
                                                      _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        188U);
                                                      CV_EML_FCN(1, 12);
                                                      _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        277);
                                                      c1_hb_encStr2Arr
                                                        (chartInstance, c1_dv118);
                                                      for (c1_i629 = 0; c1_i629 <
                                                           256; c1_i629++) {
                                                        c1_gazeBML[c1_i629] =
                                                          c1_dv118[c1_i629];
                                                      }

                                                      sf_mex_printf("%s =\\n",
                                                        "gazeBML");
                                                      for (c1_i630 = 0; c1_i630 <
                                                           256; c1_i630++) {
                                                        c1_ab_u[c1_i630] =
                                                          c1_gazeBML[c1_i630];
                                                      }

                                                      c1_ab_y = NULL;
                                                      sf_mex_assign(&c1_ab_y,
                                                        sf_mex_create("y",
                                                        c1_ab_u, 0, 0U, 1U, 0U,
                                                        1, 256), false);
                                                      sf_mex_call_debug
                                                        (sfGlobalDebugInstanceStruct,
                                                         "disp", 0U, 1U, 14,
                                                         c1_ab_y);
                                                      _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        -277);
                                                    } else {
                                                      _SFD_EML_CALL(1U,
                                                        chartInstance->c1_sfEvent,
                                                        189U);
                                                      if (CV_EML_IF(1, 1, 26,
                                                           c1_aVarTruthTableCondition_27))
                                                      {
                                                        _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          190U);
                                                        CV_EML_FCN(1, 9);
                                                        _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          259);
                                                        c1_ib_encStr2Arr
                                                          (chartInstance,
                                                           c1_dv119);
                                                        for (c1_i631 = 0;
                                                             c1_i631 < 256;
                                                             c1_i631++) {
                                                          c1_gazeBML[c1_i631] =
                                                            c1_dv119[c1_i631];
                                                        }

                                                        sf_mex_printf("%s =\\n",
                                                          "gazeBML");
                                                        for (c1_i632 = 0;
                                                             c1_i632 < 256;
                                                             c1_i632++) {
                                                          c1_bb_u[c1_i632] =
                                                            c1_gazeBML[c1_i632];
                                                        }

                                                        c1_bb_y = NULL;
                                                        sf_mex_assign(&c1_bb_y,
                                                          sf_mex_create("y",
                                                          c1_bb_u, 0, 0U, 1U, 0U,
                                                          1, 256), false);
                                                        sf_mex_call_debug
                                                          (sfGlobalDebugInstanceStruct,
                                                           "disp", 0U, 1U, 14,
                                                           c1_bb_y);
                                                        _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          -259);
                                                      } else {
                                                        _SFD_EML_CALL(1U,
                                                          chartInstance->c1_sfEvent,
                                                          191U);
                                                        if (CV_EML_IF(1, 1, 27,
                                                             c1_aVarTruthTableCondition_28))
                                                        {
                                                          _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            192U);
                                                          CV_EML_FCN(1, 10);
                                                          _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            265);
                                                          c1_gb_encStr2Arr
                                                            (chartInstance,
                                                             c1_dv120);
                                                          for (c1_i633 = 0;
                                                               c1_i633 < 256;
                                                               c1_i633++) {
                                                            c1_gazeBML[c1_i633] =
                                                              c1_dv120[c1_i633];
                                                          }

                                                          sf_mex_printf(
                                                            "%s =\\n", "gazeBML");
                                                          for (c1_i634 = 0;
                                                               c1_i634 < 256;
                                                               c1_i634++) {
                                                            c1_cb_u[c1_i634] =
                                                              c1_gazeBML[c1_i634];
                                                          }

                                                          c1_cb_y = NULL;
                                                          sf_mex_assign(&c1_cb_y,
                                                            sf_mex_create("y",
                                                            c1_cb_u, 0, 0U, 1U,
                                                            0U, 1, 256), false);
                                                          sf_mex_call_debug
                                                            (sfGlobalDebugInstanceStruct,
                                                             "disp", 0U, 1U, 14,
                                                             c1_cb_y);
                                                          _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            -265);
                                                        } else {
                                                          _SFD_EML_CALL(1U,
                                                            chartInstance->c1_sfEvent,
                                                            193U);
                                                          if (CV_EML_IF(1, 1, 28,
                                                               c1_aVarTruthTableCondition_29))
                                                          {
                                                            _SFD_EML_CALL(1U,
                                                              chartInstance->c1_sfEvent,
                                                              194U);
                                                            CV_EML_FCN(1, 11);
                                                            _SFD_EML_CALL(1U,
                                                              chartInstance->c1_sfEvent,
                                                              271);
                                                            c1_jb_encStr2Arr
                                                              (chartInstance,
                                                               c1_dv121);
                                                            for (c1_i635 = 0;
                                                                 c1_i635 < 256;
                                                                 c1_i635++) {
                                                              c1_gazeBML[c1_i635]
                                                                =
                                                                c1_dv121[c1_i635];
                                                            }

                                                            sf_mex_printf(
                                                              "%s =\\n",
                                                              "gazeBML");
                                                            for (c1_i636 = 0;
                                                                 c1_i636 < 256;
                                                                 c1_i636++) {
                                                              c1_db_u[c1_i636] =
                                                                c1_gazeBML[c1_i636];
                                                            }

                                                            c1_db_y = NULL;
                                                            sf_mex_assign
                                                              (&c1_db_y,
                                                               sf_mex_create("y",
                                                                c1_db_u, 0, 0U,
                                                                1U, 0U, 1, 256),
                                                               false);
                                                            sf_mex_call_debug
                                                              (sfGlobalDebugInstanceStruct,
                                                               "disp", 0U, 1U,
                                                               14, c1_db_y);
                                                            _SFD_EML_CALL(1U,
                                                              chartInstance->c1_sfEvent,
                                                              -271);
                                                          } else {
                                                            _SFD_EML_CALL(1U,
                                                              chartInstance->c1_sfEvent,
                                                              195U);
                                                            if (CV_EML_IF(1, 1,
                                                                 29,
                                                                 c1_aVarTruthTableCondition_30))
                                                            {
                                                              _SFD_EML_CALL(1U,
                                                                chartInstance->c1_sfEvent,
                                                                196U);
                                                              CV_EML_FCN(1, 12);
                                                              _SFD_EML_CALL(1U,
                                                                chartInstance->c1_sfEvent,
                                                                277);
                                                              c1_hb_encStr2Arr
                                                                (chartInstance,
                                                                 c1_dv122);
                                                              for (c1_i637 = 0;
                                                                   c1_i637 < 256;
                                                                   c1_i637++) {
                                                                c1_gazeBML[c1_i637]
                                                                  =
                                                                  c1_dv122[c1_i637];
                                                              }

                                                              sf_mex_printf(
                                                                "%s =\\n",
                                                                "gazeBML");
                                                              for (c1_i638 = 0;
                                                                   c1_i638 < 256;
                                                                   c1_i638++) {
                                                                c1_eb_u[c1_i638]
                                                                  =
                                                                  c1_gazeBML[c1_i638];
                                                              }

                                                              c1_eb_y = NULL;
                                                              sf_mex_assign
                                                                (&c1_eb_y,
                                                                 sf_mex_create(
                                                                  "y", c1_eb_u,
                                                                  0, 0U, 1U, 0U,
                                                                  1, 256), false);
                                                              sf_mex_call_debug
                                                                (sfGlobalDebugInstanceStruct,
                                                                 "disp", 0U, 1U,
                                                                 14, c1_eb_y);
                                                              _SFD_EML_CALL(1U,
                                                                chartInstance->c1_sfEvent,
                                                                -277);
                                                            } else {
                                                              _SFD_EML_CALL(1U,
                                                                chartInstance->c1_sfEvent,
                                                                197U);
                                                              if (CV_EML_IF(1, 1,
                                                                   30,
                                                                   c1_aVarTruthTableCondition_31))
                                                              {
                                                                _SFD_EML_CALL(1U,
                                                                  chartInstance->
                                                                  c1_sfEvent,
                                                                  198U);
                                                                CV_EML_FCN(1, 13);
                                                                _SFD_EML_CALL(1U,
                                                                  chartInstance->
                                                                  c1_sfEvent,
                                                                  283);
                                                                c1_kb_encStr2Arr
                                                                  (chartInstance,
                                                                   c1_dv123);
                                                                for (c1_i639 = 0;
                                                                     c1_i639 <
                                                                     256;
                                                                     c1_i639++)
                                                                {
                                                                  c1_gazeBML[c1_i639]
                                                                    =
                                                                    c1_dv123[c1_i639];
                                                                }

                                                                sf_mex_printf(
                                                                  "%s =\\n",
                                                                  "gazeBML");
                                                                for (c1_i640 = 0;
                                                                     c1_i640 <
                                                                     256;
                                                                     c1_i640++)
                                                                {
                                                                  c1_fb_u[c1_i640]
                                                                    =
                                                                    c1_gazeBML[c1_i640];
                                                                }

                                                                c1_fb_y = NULL;
                                                                sf_mex_assign
                                                                  (&c1_fb_y,
                                                                   sf_mex_create
                                                                  ("y", c1_fb_u,
                                                                    0, 0U, 1U,
                                                                    0U, 1, 256),
                                                                   false);
                                                                sf_mex_call_debug
                                                                  (sfGlobalDebugInstanceStruct,
                                                                   "disp", 0U,
                                                                   1U, 14,
                                                                   c1_fb_y);
                                                                _SFD_EML_CALL(1U,
                                                                  chartInstance->
                                                                  c1_sfEvent,
                                                                  -283);
                                                              } else {
                                                                _SFD_EML_CALL(1U,
                                                                  chartInstance->
                                                                  c1_sfEvent,
                                                                  199U);
                                                                if (CV_EML_IF(1,
                                                                     1, 31,
                                                                     c1_aVarTruthTableCondition_32))
                                                                {
                                                                  _SFD_EML_CALL
                                                                    (1U,
                                                                     chartInstance
                                                                     ->c1_sfEvent,
                                                                     200U);
                                                                  CV_EML_FCN(1,
                                                                      14);
                                                                  _SFD_EML_CALL
                                                                    (1U,
                                                                     chartInstance
                                                                     ->c1_sfEvent,
                                                                     289);
                                                                  c1_lb_encStr2Arr
                                                                    (chartInstance,
                                                                     c1_dv124);
                                                                  for (c1_i641 =
                                                                      0; c1_i641
                                                                      < 256;
                                                                      c1_i641++)
                                                                  {
                                                                    c1_gazeBML[c1_i641]
                                                                      =
                                                                      c1_dv124[c1_i641];
                                                                  }

                                                                  sf_mex_printf(
                                                                    "%s =\\n",
                                                                    "gazeBML");
                                                                  for (c1_i642 =
                                                                      0; c1_i642
                                                                      < 256;
                                                                      c1_i642++)
                                                                  {
                                                                    c1_gb_u[c1_i642]
                                                                      =
                                                                      c1_gazeBML[
                                                                      c1_i642];
                                                                  }

                                                                  c1_gb_y = NULL;
                                                                  sf_mex_assign(
                                                                    &c1_gb_y,
                                                                    sf_mex_create
                                                                    ("y",
                                                                    c1_gb_u, 0,
                                                                    0U, 1U, 0U,
                                                                    1, 256),
                                                                    false);
                                                                  sf_mex_call_debug
                                                                    (sfGlobalDebugInstanceStruct,
                                                                     "disp", 0U,
                                                                     1U, 14,
                                                                     c1_gb_y);
                                                                  _SFD_EML_CALL
                                                                    (1U,
                                                                     chartInstance
                                                                     ->c1_sfEvent,
                                                                     -289);
                                                                } else {
                                                                  _SFD_EML_CALL
                                                                    (1U,
                                                                     chartInstance
                                                                     ->c1_sfEvent,
                                                                     201U);
                                                                  if (CV_EML_IF
                                                                      (1, 1, 32,
                                                                      c1_aVarTruthTableCondition_33))
                                                                  {
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      202U);
                                                                    CV_EML_FCN(1,
                                                                      25);
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      355);
                                                                    c1_mb_encStr2Arr
                                                                      (chartInstance,
                                                                      c1_dv125);
                                                                    for (c1_i643
                                                                      = 0;
                                                                      c1_i643 <
                                                                      256;
                                                                      c1_i643++)
                                                                    {
                                                                      c1_gazeBML[
                                                                      c1_i643] =
                                                                      c1_dv125[c1_i643];
                                                                    }

                                                                    sf_mex_printf
                                                                      ("%s =\\n",
                                                                      "gazeBML");
                                                                    for (c1_i644
                                                                      = 0;
                                                                      c1_i644 <
                                                                      256;
                                                                      c1_i644++)
                                                                    {
                                                                      c1_hb_u[c1_i644]
                                                                      =
                                                                      c1_gazeBML[
                                                                      c1_i644];
                                                                    }

                                                                    c1_hb_y =
                                                                      NULL;
                                                                    sf_mex_assign
                                                                      (&c1_hb_y,
                                                                      sf_mex_create
                                                                      ("y",
                                                                      c1_hb_u, 0,
                                                                      0U, 1U, 0U,
                                                                      1, 256),
                                                                      false);
                                                                    sf_mex_call_debug
                                                                      (sfGlobalDebugInstanceStruct,
                                                                      "disp", 0U,
                                                                      1U, 14,
                                                                      c1_hb_y);
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      -355);
                                                                  } else {
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      204U);
                                                                    CV_EML_FCN(1,
                                                                      14);
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      289);
                                                                    c1_lb_encStr2Arr
                                                                      (chartInstance,
                                                                      c1_dv126);
                                                                    for (c1_i645
                                                                      = 0;
                                                                      c1_i645 <
                                                                      256;
                                                                      c1_i645++)
                                                                    {
                                                                      c1_gazeBML[
                                                                      c1_i645] =
                                                                      c1_dv126[c1_i645];
                                                                    }

                                                                    sf_mex_printf
                                                                      ("%s =\\n",
                                                                      "gazeBML");
                                                                    for (c1_i646
                                                                      = 0;
                                                                      c1_i646 <
                                                                      256;
                                                                      c1_i646++)
                                                                    {
                                                                      c1_ib_u[c1_i646]
                                                                      =
                                                                      c1_gazeBML[
                                                                      c1_i646];
                                                                    }

                                                                    c1_ib_y =
                                                                      NULL;
                                                                    sf_mex_assign
                                                                      (&c1_ib_y,
                                                                      sf_mex_create
                                                                      ("y",
                                                                      c1_ib_u, 0,
                                                                      0U, 1U, 0U,
                                                                      1, 256),
                                                                      false);
                                                                    sf_mex_call_debug
                                                                      (sfGlobalDebugInstanceStruct,
                                                                      "disp", 0U,
                                                                      1U, 14,
                                                                      c1_ib_y);
                                                                    _SFD_EML_CALL
                                                                      (1U,
                                                                      chartInstance
                                                                      ->c1_sfEvent,
                                                                      -289);
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

  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -204);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c1_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i647;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i647, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i647;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_secs;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_secs = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_secs), &c1_thisId);
  sf_mex_destroy(&c1_secs);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i648;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i648, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i648;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_stateGame, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_stateGame),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_stateGame);
  return c1_y;
}

static uint8_T c1_i_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u3, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_stateGame;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_stateGame = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_stateGame),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_stateGame);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_method, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_method),
    &c1_thisId);
  sf_mex_destroy(&c1_b_method);
  return c1_y;
}

static uint32_T c1_k_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_method_not_empty = false;
  } else {
    chartInstance->c1_method_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u4, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u4;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static uint32_T c1_l_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId);
  sf_mex_destroy(&c1_d_state);
  return c1_y;
}

static uint32_T c1_m_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u5;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_state_not_empty = false;
  } else {
    chartInstance->c1_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u5, 1, 7, 0U, 0, 0U, 0);
    c1_y = c1_u5;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_n_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_o_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625])
{
  uint32_T c1_uv3[625];
  int32_T c1_i649;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_c_state_not_empty = false;
  } else {
    chartInstance->c1_c_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c1_i649 = 0; c1_i649 < 625; c1_i649++) {
      c1_y[c1_i649] = c1_uv3[c1_i649];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_p_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_q_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2])
{
  uint32_T c1_uv4[2];
  int32_T c1_i650;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_state_not_empty = false;
  } else {
    chartInstance->c1_b_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i650 = 0; c1_i650 < 2; c1_i650++) {
      c1_y[c1_i650] = c1_uv4[c1_i650];
    }
  }

  sf_mex_destroy(&c1_u);
}

static uint32_T c1_r_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_temporalCounter_i2, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_temporalCounter_i2),
    &c1_thisId);
  sf_mex_destroy(&c1_b_temporalCounter_i2);
  return c1_y;
}

static uint32_T c1_s_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u6;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u6, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u6;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_t_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_u_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 36, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 36, 1,
    0)]);
}

static void c1_b_twister_state_vector
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_mt[625], real_T c1_seed)
{
  real_T c1_d5;
  uint32_T c1_u7;
  uint32_T c1_b_r;
  int32_T c1_mti;
  real_T c1_b_mti;
  real_T c1_d6;
  uint32_T c1_u8;
  (void)chartInstance;
  c1_d5 = c1_seed;
  if (c1_d5 < 4.294967296E+9) {
    if (c1_d5 >= 0.0) {
      c1_u7 = (uint32_T)c1_d5;
    } else {
      c1_u7 = 0U;
    }
  } else if (c1_d5 >= 4.294967296E+9) {
    c1_u7 = MAX_uint32_T;
  } else {
    c1_u7 = 0U;
  }

  c1_b_r = c1_u7;
  c1_mt[0] = c1_b_r;
  for (c1_mti = 0; c1_mti < 623; c1_mti++) {
    c1_b_mti = 2.0 + (real_T)c1_mti;
    c1_d6 = muDoubleScalarRound(c1_b_mti - 1.0);
    if (c1_d6 < 4.294967296E+9) {
      if (c1_d6 >= 0.0) {
        c1_u8 = (uint32_T)c1_d6;
      } else {
        c1_u8 = 0U;
      }
    } else if (c1_d6 >= 4.294967296E+9) {
      c1_u8 = MAX_uint32_T;
    } else {
      c1_u8 = 0U;
    }

    c1_b_r = (c1_b_r ^ c1_b_r >> 30U) * 1812433253U + c1_u8;
    c1_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_mti), 1, 625, 1, 0) - 1] = c1_b_r;
  }

  c1_mt[624] = 624U;
}

static real_T c1_c_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance,
   uint32_T c1_d_state[625])
{
  int32_T c1_i651;
  uint32_T c1_u[2];
  int32_T c1_j;
  real_T c1_b_j;
  uint32_T c1_mti;
  int32_T c1_kk;
  real_T c1_b_kk;
  uint32_T c1_y;
  uint32_T c1_b_y;
  uint32_T c1_c_y;
  int32_T c1_c_kk;
  uint32_T c1_d_y;
  uint32_T c1_e_y;
  uint32_T c1_f_y;
  uint32_T c1_g_y;
  real_T c1_c_r;
  boolean_T c1_b1;
  boolean_T c1_isvalid;
  int32_T c1_k;
  int32_T c1_a;
  int32_T c1_b_a;
  real_T c1_d7;
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
    for (c1_i651 = 0; c1_i651 < 2; c1_i651++) {
      c1_u[c1_i651] = 0U;
    }

    for (c1_j = 0; c1_j < 2; c1_j++) {
      c1_b_j = 1.0 + (real_T)c1_j;
      c1_mti = c1_d_state[624] + 1U;
      if ((real_T)c1_mti >= 625.0) {
        for (c1_kk = 0; c1_kk < 227; c1_kk++) {
          c1_b_kk = 1.0 + (real_T)c1_kk;
          c1_y = (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c1_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c1_b_y = c1_y;
          c1_c_y = c1_b_y;
          if ((real_T)(c1_c_y & 1U) == 0.0) {
            c1_c_y >>= 1U;
          } else {
            c1_c_y = c1_c_y >> 1U ^ 2567483615U;
          }

          c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c1_b_kk), 1, 625, 1, 0) - 1] =
            c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_b_kk + 397.0), 1, 625, 1, 0) - 1] ^ c1_c_y;
        }

        for (c1_c_kk = 0; c1_c_kk < 396; c1_c_kk++) {
          c1_b_kk = 228.0 + (real_T)c1_c_kk;
          c1_y = (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                   _SFD_INTEGER_CHECK("", c1_b_kk), 1, 625, 1, 0) - 1] &
                  2147483648U) | (c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", c1_b_kk + 1.0), 1, 625, 1, 0) - 1] &
            2147483647U);
          c1_d_y = c1_y;
          c1_e_y = c1_d_y;
          if ((real_T)(c1_e_y & 1U) == 0.0) {
            c1_e_y >>= 1U;
          } else {
            c1_e_y = c1_e_y >> 1U ^ 2567483615U;
          }

          c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", c1_b_kk), 1, 625, 1, 0) - 1] =
            c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (c1_b_kk + 1.0) - 228.0), 1, 625, 1, 0) - 1] ^
            c1_e_y;
        }

        c1_y = (c1_d_state[623] & 2147483648U) | (c1_d_state[0] & 2147483647U);
        c1_f_y = c1_y;
        c1_g_y = c1_f_y;
        if ((real_T)(c1_g_y & 1U) == 0.0) {
          c1_g_y >>= 1U;
        } else {
          c1_g_y = c1_g_y >> 1U ^ 2567483615U;
        }

        c1_d_state[623] = c1_d_state[396] ^ c1_g_y;
        c1_mti = 1U;
      }

      c1_y = c1_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)(uint32_T)_SFD_INTEGER_CHECK("", (real_T)c1_mti), 1, 625, 1, 0)
        - 1];
      c1_d_state[624] = c1_mti;
      c1_y ^= c1_y >> 11U;
      c1_y ^= c1_y << 7U & 2636928640U;
      c1_y ^= c1_y << 15U & 4022730752U;
      c1_y ^= c1_y >> 18U;
      c1_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c1_b_j), 1, 2, 1, 0) - 1] = c1_y;
    }

    c1_u[0] >>= 5U;
    c1_u[1] >>= 6U;
    c1_c_r = 1.1102230246251565E-16 * ((real_T)c1_u[0] * 6.7108864E+7 + (real_T)
      c1_u[1]);
    if (c1_c_r == 0.0) {
      guard1 = false;
      if ((real_T)c1_d_state[624] >= 1.0) {
        if ((real_T)c1_d_state[624] < 625.0) {
          c1_b1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c1_b1 = false;
      }

      c1_isvalid = c1_b1;
      if (c1_isvalid) {
        c1_isvalid = false;
        c1_k = 1;
        exitg2 = false;
        while ((exitg2 == false) && (c1_k < 625)) {
          if ((real_T)c1_d_state[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c1_k), 1, 625, 1, 0) - 1] == 0.0)
          {
            c1_a = c1_k;
            c1_b_a = c1_a + 1;
            c1_k = c1_b_a;
          } else {
            c1_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!c1_isvalid) {
        c1_eml_error(chartInstance);
        c1_d7 = 5489.0;
        c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d7);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c1_c_r;
}

static void init_dsm_address_info
  (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance)
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

void sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(33495751U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(406428716U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3444695972U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1779980411U);
}

mxArray *sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Y6nUwZ1biQ4qN7xixCC9uH");
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

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,22,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[568],T\"BOREDOMT\",},{M[3],M[641],T\"b\",},{M[3],M[468],T\"bHand\",},{M[3],M[567],T\"bored\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[462],T\"diff\",},{M[3],M[660],T\"p\",},{M[3],M[636],T\"pose\",},{M[3],M[584],T\"poseYN\",},{M[3],M[659],T\"r\",},{M[3],M[683],T\"randomB\",},{M[3],M[688],T\"randomD\",},{M[3],M[596],T\"randomG\",},{M[3],M[597],T\"randomGP\",},{M[3],M[701],T\"randomH\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[635],T\"randomP\",},{M[3],M[661],T\"s\",},{M[3],M[671],T\"shoulderFW\",},{M[3],M[482],T\"smileN\",},{M[3],M[566],T\"smileYN\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[3],M[689],T\"wristRotate\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c1_ARP_02_RPSsmile_WirelessGlove_Rachel\",},{M[8],M[613],T\"is_active_stateIdlePose\",},{M[8],M[616],T\"is_active_stateIdleGaze\",},{M[8],M[618],T\"is_active_stateGame\",},{M[9],M[613],T\"is_stateIdlePose\",},{M[9],M[616],T\"is_stateIdleGaze\",},{M[9],M[618],T\"is_stateGame\",},{M[11],M[510],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[601],M[1]}}}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[11],M[510],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M1x3[699 599 643],M[1]}}},{M[11],M[510],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x10[432 439 578 440 654 653 495 449 430 571],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 42, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ARP_02_RPSsmile_WirelessGlove_Rachel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
           1,
           43,
           54,
           0,
           49,
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
          (_ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(1,1,1,0,"inputUser");
          _SFD_SET_DATA_PROPS(2,2,0,1,"bradHand");
          _SFD_SET_DATA_PROPS(3,2,0,1,"userHand");
          _SFD_SET_DATA_PROPS(4,2,0,1,"win");
          _SFD_SET_DATA_PROPS(5,0,0,0,"temp");
          _SFD_SET_DATA_PROPS(6,0,0,0,"diff");
          _SFD_SET_DATA_PROPS(7,0,0,0,"uHand");
          _SFD_SET_DATA_PROPS(8,0,0,0,"bHand");
          _SFD_SET_DATA_PROPS(9,2,0,1,"bWinT");
          _SFD_SET_DATA_PROPS(10,2,0,1,"uWinT");
          _SFD_SET_DATA_PROPS(11,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(12,0,0,0,"smileYN");
          _SFD_SET_DATA_PROPS(13,0,0,0,"bored");
          _SFD_SET_DATA_PROPS(14,0,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(15,0,0,0,"poseYN");
          _SFD_SET_DATA_PROPS(16,0,0,0,"randomG");
          _SFD_SET_DATA_PROPS(17,0,0,0,"randomGP");
          _SFD_SET_DATA_PROPS(18,0,0,0,"randomP");
          _SFD_SET_DATA_PROPS(19,0,0,0,"pose");
          _SFD_SET_DATA_PROPS(20,0,0,0,"b");
          _SFD_SET_DATA_PROPS(21,0,0,0,"r");
          _SFD_SET_DATA_PROPS(22,0,0,0,"p");
          _SFD_SET_DATA_PROPS(23,0,0,0,"s");
          _SFD_SET_DATA_PROPS(24,0,0,0,"shoulderFW");
          _SFD_SET_DATA_PROPS(25,0,0,0,"randomB");
          _SFD_SET_DATA_PROPS(26,0,0,0,"randomD");
          _SFD_SET_DATA_PROPS(27,0,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(28,0,0,0,"randomH");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_SET_DATA_PROPS(30,8,0,0,"");
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
          _SFD_SET_DATA_PROPS(43,8,0,0,"");
          _SFD_SET_DATA_PROPS(44,9,0,0,"");
          _SFD_SET_DATA_PROPS(45,8,0,0,"");
          _SFD_SET_DATA_PROPS(46,9,0,0,"");
          _SFD_SET_DATA_PROPS(47,8,0,0,"");
          _SFD_SET_DATA_PROPS(48,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(11,0,1);
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
          _SFD_STATE_INFO(35,0,1);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,1);
          _SFD_STATE_INFO(41,0,0);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,11);
          _SFD_CH_SUBSTATE_INDEX(1,35);
          _SFD_CH_SUBSTATE_INDEX(2,40);
          _SFD_ST_SUBSTATE_COUNT(11,23);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_INDEX(11,2,14);
          _SFD_ST_SUBSTATE_INDEX(11,3,15);
          _SFD_ST_SUBSTATE_INDEX(11,4,16);
          _SFD_ST_SUBSTATE_INDEX(11,5,17);
          _SFD_ST_SUBSTATE_INDEX(11,6,18);
          _SFD_ST_SUBSTATE_INDEX(11,7,19);
          _SFD_ST_SUBSTATE_INDEX(11,8,20);
          _SFD_ST_SUBSTATE_INDEX(11,9,21);
          _SFD_ST_SUBSTATE_INDEX(11,10,22);
          _SFD_ST_SUBSTATE_INDEX(11,11,23);
          _SFD_ST_SUBSTATE_INDEX(11,12,24);
          _SFD_ST_SUBSTATE_INDEX(11,13,25);
          _SFD_ST_SUBSTATE_INDEX(11,14,26);
          _SFD_ST_SUBSTATE_INDEX(11,15,27);
          _SFD_ST_SUBSTATE_INDEX(11,16,28);
          _SFD_ST_SUBSTATE_INDEX(11,17,29);
          _SFD_ST_SUBSTATE_INDEX(11,18,30);
          _SFD_ST_SUBSTATE_INDEX(11,19,31);
          _SFD_ST_SUBSTATE_INDEX(11,20,32);
          _SFD_ST_SUBSTATE_INDEX(11,21,33);
          _SFD_ST_SUBSTATE_INDEX(11,22,34);
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
          _SFD_ST_SUBSTATE_COUNT(35,4);
          _SFD_ST_SUBSTATE_INDEX(35,0,36);
          _SFD_ST_SUBSTATE_INDEX(35,1,37);
          _SFD_ST_SUBSTATE_INDEX(35,2,38);
          _SFD_ST_SUBSTATE_INDEX(35,3,39);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(40,2);
          _SFD_ST_SUBSTATE_INDEX(40,0,41);
          _SFD_ST_SUBSTATE_INDEX(40,1,42);
          _SFD_ST_SUBSTATE_COUNT(41,0);
          _SFD_ST_SUBSTATE_COUNT(42,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(11,23,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(35,4,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(40,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"rockPose",0,-1,396);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",396,-1,557);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",557,-1,718);
        _SFD_CV_INIT_EML_IF(7,1,0,220,250,281,394);
        _SFD_CV_INIT_EML_IF(7,1,1,281,315,346,394);
        _SFD_CV_INIT_EML(6,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"paperPose",0,-1,400);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",400,-1,556);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",556,-1,710);
        _SFD_CV_INIT_EML_IF(6,1,0,224,254,285,398);
        _SFD_CV_INIT_EML_IF(6,1,1,285,319,350,398);
        _SFD_CV_INIT_EML(8,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"scissorsPose",0,-1,409);
        _SFD_CV_INIT_EML_FCN(8,1,"aFcnTruthTableAction_1",409,-1,566);
        _SFD_CV_INIT_EML_FCN(8,2,"aFcnTruthTableAction_2",566,-1,725);
        _SFD_CV_INIT_EML_IF(8,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(8,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(4,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"handPoseSB",0,-1,1083);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",1083,-1,1323);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",1323,-1,1561);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",1561,-1,1735);
        _SFD_CV_INIT_EML_FCN(4,4,"aFcnTruthTableAction_4",1735,-1,1906);
        _SFD_CV_INIT_EML_FCN(4,5,"aFcnTruthTableAction_5",1906,-1,2064);
        _SFD_CV_INIT_EML_FCN(4,6,"aFcnTruthTableAction_6",2064,-1,2219);
        _SFD_CV_INIT_EML_IF(4,1,0,647,677,708,1081);
        _SFD_CV_INIT_EML_IF(4,1,1,708,742,773,1081);
        _SFD_CV_INIT_EML_IF(4,1,2,773,807,838,1081);
        _SFD_CV_INIT_EML_IF(4,1,3,838,872,903,1081);
        _SFD_CV_INIT_EML_IF(4,1,4,903,937,968,1081);
        _SFD_CV_INIT_EML_IF(4,1,5,968,1002,1033,1081);
        _SFD_CV_INIT_EML(5,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"idlePose",0,-1,1353);
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
        _SFD_CV_INIT_EML(3,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"boredPoseS",0,-1,2805);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",2805,-1,2976);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",2976,-1,3138);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",3138,-1,3305);
        _SFD_CV_INIT_EML_FCN(3,4,"aFcnTruthTableAction_4",3305,-1,3474);
        _SFD_CV_INIT_EML_FCN(3,5,"aFcnTruthTableAction_5",3474,-1,3643);
        _SFD_CV_INIT_EML_FCN(3,6,"aFcnTruthTableAction_6",3643,-1,3824);
        _SFD_CV_INIT_EML_FCN(3,7,"aFcnTruthTableAction_7",3824,-1,4003);
        _SFD_CV_INIT_EML_FCN(3,8,"aFcnTruthTableAction_8",4003,-1,4172);
        _SFD_CV_INIT_EML_FCN(3,9,"aFcnTruthTableAction_9",4172,-1,4339);
        _SFD_CV_INIT_EML_FCN(3,10,"aFcnTruthTableAction_10",4339,-1,4508);
        _SFD_CV_INIT_EML_FCN(3,11,"aFcnTruthTableAction_11",4508,-1,4674);
        _SFD_CV_INIT_EML_IF(3,1,0,1577,1607,1638,2803);
        _SFD_CV_INIT_EML_IF(3,1,1,1638,1672,1703,2803);
        _SFD_CV_INIT_EML_IF(3,1,2,1703,1737,1768,2803);
        _SFD_CV_INIT_EML_IF(3,1,3,1768,1802,1833,2803);
        _SFD_CV_INIT_EML_IF(3,1,4,1833,1867,1898,2803);
        _SFD_CV_INIT_EML_IF(3,1,5,1898,1932,1964,2803);
        _SFD_CV_INIT_EML_IF(3,1,6,1964,1998,2029,2803);
        _SFD_CV_INIT_EML_IF(3,1,7,2029,2063,2094,2803);
        _SFD_CV_INIT_EML_IF(3,1,8,2094,2128,2159,2803);
        _SFD_CV_INIT_EML_IF(3,1,9,2159,2194,2226,2803);
        _SFD_CV_INIT_EML_IF(3,1,10,2226,2261,2293,2803);
        _SFD_CV_INIT_EML_IF(3,1,11,2293,2328,2359,2803);
        _SFD_CV_INIT_EML_IF(3,1,12,2359,2394,2425,2803);
        _SFD_CV_INIT_EML_IF(3,1,13,2425,2460,2491,2803);
        _SFD_CV_INIT_EML_IF(3,1,14,2491,2526,2557,2803);
        _SFD_CV_INIT_EML_IF(3,1,15,2557,2592,2623,2803);
        _SFD_CV_INIT_EML_IF(3,1,16,2623,2658,2689,2803);
        _SFD_CV_INIT_EML_IF(3,1,17,2689,2724,2755,2803);
        _SFD_CV_INIT_EML(1,1,26,33,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"boredGaze",0,-1,5113);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",5113,-1,5299);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",5299,-1,5487);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",5487,-1,5669);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",5669,-1,5855);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",5855,-1,6045);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",6045,-1,6237);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",6237,-1,6431);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",6431,-1,6627);
        _SFD_CV_INIT_EML_FCN(1,9,"aFcnTruthTableAction_9",6627,-1,6826);
        _SFD_CV_INIT_EML_FCN(1,10,"aFcnTruthTableAction_10",6826,-1,7034);
        _SFD_CV_INIT_EML_FCN(1,11,"aFcnTruthTableAction_11",7034,-1,7244);
        _SFD_CV_INIT_EML_FCN(1,12,"aFcnTruthTableAction_12",7244,-1,7450);
        _SFD_CV_INIT_EML_FCN(1,13,"aFcnTruthTableAction_13",7450,-1,7654);
        _SFD_CV_INIT_EML_FCN(1,14,"aFcnTruthTableAction_14",7654,-1,7850);
        _SFD_CV_INIT_EML_FCN(1,15,"aFcnTruthTableAction_15",7850,-1,8052);
        _SFD_CV_INIT_EML_FCN(1,16,"aFcnTruthTableAction_16",8052,-1,8252);
        _SFD_CV_INIT_EML_FCN(1,17,"aFcnTruthTableAction_17",8252,-1,8464);
        _SFD_CV_INIT_EML_FCN(1,18,"aFcnTruthTableAction_18",8464,-1,8678);
        _SFD_CV_INIT_EML_FCN(1,19,"aFcnTruthTableAction_19",8678,-1,8886);
        _SFD_CV_INIT_EML_FCN(1,20,"aFcnTruthTableAction_20",8886,-1,9098);
        _SFD_CV_INIT_EML_FCN(1,21,"aFcnTruthTableAction_21",9098,-1,9314);
        _SFD_CV_INIT_EML_FCN(1,22,"aFcnTruthTableAction_22",9314,-1,9532);
        _SFD_CV_INIT_EML_FCN(1,23,"aFcnTruthTableAction_23",9532,-1,9752);
        _SFD_CV_INIT_EML_FCN(1,24,"aFcnTruthTableAction_24",9752,-1,9974);
        _SFD_CV_INIT_EML_FCN(1,25,"aFcnTruthTableAction_25",9974,-1,10139);
        _SFD_CV_INIT_EML_IF(1,1,0,2881,2911,2942,5111);
        _SFD_CV_INIT_EML_IF(1,1,1,2942,2976,3007,5111);
        _SFD_CV_INIT_EML_IF(1,1,2,3007,3041,3072,5111);
        _SFD_CV_INIT_EML_IF(1,1,3,3072,3106,3137,5111);
        _SFD_CV_INIT_EML_IF(1,1,4,3137,3171,3202,5111);
        _SFD_CV_INIT_EML_IF(1,1,5,3202,3236,3267,5111);
        _SFD_CV_INIT_EML_IF(1,1,6,3267,3301,3332,5111);
        _SFD_CV_INIT_EML_IF(1,1,7,3332,3366,3397,5111);
        _SFD_CV_INIT_EML_IF(1,1,8,3397,3431,3462,5111);
        _SFD_CV_INIT_EML_IF(1,1,9,3462,3497,3528,5111);
        _SFD_CV_INIT_EML_IF(1,1,10,3528,3563,3594,5111);
        _SFD_CV_INIT_EML_IF(1,1,11,3594,3629,3660,5111);
        _SFD_CV_INIT_EML_IF(1,1,12,3660,3695,3726,5111);
        _SFD_CV_INIT_EML_IF(1,1,13,3726,3761,3792,5111);
        _SFD_CV_INIT_EML_IF(1,1,14,3792,3827,3858,5111);
        _SFD_CV_INIT_EML_IF(1,1,15,3858,3893,3924,5111);
        _SFD_CV_INIT_EML_IF(1,1,16,3924,3959,3991,5111);
        _SFD_CV_INIT_EML_IF(1,1,17,3991,4026,4058,5111);
        _SFD_CV_INIT_EML_IF(1,1,18,4058,4093,4125,5111);
        _SFD_CV_INIT_EML_IF(1,1,19,4125,4160,4192,5111);
        _SFD_CV_INIT_EML_IF(1,1,20,4192,4227,4259,5111);
        _SFD_CV_INIT_EML_IF(1,1,21,4259,4294,4326,5111);
        _SFD_CV_INIT_EML_IF(1,1,22,4326,4361,4393,5111);
        _SFD_CV_INIT_EML_IF(1,1,23,4393,4428,4460,5111);
        _SFD_CV_INIT_EML_IF(1,1,24,4460,4495,4527,5111);
        _SFD_CV_INIT_EML_IF(1,1,25,4527,4562,4594,5111);
        _SFD_CV_INIT_EML_IF(1,1,26,4594,4629,4660,5111);
        _SFD_CV_INIT_EML_IF(1,1,27,4660,4695,4727,5111);
        _SFD_CV_INIT_EML_IF(1,1,28,4727,4762,4794,5111);
        _SFD_CV_INIT_EML_IF(1,1,29,4794,4829,4861,5111);
        _SFD_CV_INIT_EML_IF(1,1,30,4861,4896,4928,5111);
        _SFD_CV_INIT_EML_IF(1,1,31,4928,4963,4995,5111);
        _SFD_CV_INIT_EML_IF(1,1,32,4995,5030,5062,5111);
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
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(37,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(42,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(41,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(22,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(22,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(52,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(52,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(51,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(51,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(40,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(43,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(43,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(43,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(42,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(42,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(42,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(45,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(46,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(46,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(53,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(53,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,0,19,0,19);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(27,0,0,1,28,1,28);

        {
          static int condStart[] = { 2, 16 };

          static int condEnd[] = { 13, 27 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(27,0,0,1,28,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(37,0,0,1,27,1,27);

        {
          static int condStart[] = { 2, 17 };

          static int condEnd[] = { 14, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(37,0,0,1,27,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(32,0,0,1,26,1,26);

        {
          static int condStart[] = { 2, 16 };

          static int condEnd[] = { 13, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(32,0,0,1,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(48,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(48,0,0,0,19,0,19);
        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(34,0,0,1,27,1,27);

        {
          static int condStart[] = { 2, 17 };

          static int condEnd[] = { 14, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(34,0,0,1,27,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(44,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(46,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(48,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

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
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(46,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(47,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(48,(void *)(NULL));

        {
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
          c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_win);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c1_temp);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_diff);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_uHand);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c1_bHand);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c1_smileN);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c1_smileYN);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c1_bored);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c1_BOREDOMT);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c1_poseYN);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c1_randomG);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c1_randomGP);
          _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c1_randomP);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c1_pose);
          _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c1_b);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c1_r);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c1_p);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c1_s);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c1_shoulderFW);
          _SFD_SET_DATA_VALUE_PTR(25U, &chartInstance->c1_randomB);
          _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance->c1_randomD);
          _SFD_SET_DATA_VALUE_PTR(27U, &chartInstance->c1_wristRotate);
          _SFD_SET_DATA_VALUE_PTR(28U, &chartInstance->c1_randomH);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_WirelessGlove_RachelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "S4pxwe8XOEkObxkpeF1riF";
}

static void sf_opaque_initialize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
  initialize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void
  *chartInstanceVar)
{
  enable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void
  *chartInstanceVar)
{
  disable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void
  *chartInstanceVar)
{
  sf_gateway_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_WirelessGlove_Rachel();/* state var info */
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

extern void sf_internal_set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
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
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_WirelessGlove_Rachel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(S);
}

static void sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(S, st);
}

static void sf_opaque_terminate_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_WirelessGlove_Rachel_optimization_info();
    }

    finalize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
      ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
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
  initSimStructsc1_ARP_02_RPSsmile_WirelessGlove_Rachel
    ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
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
    initialize_params_c1_ARP_02_RPSsmile_WirelessGlove_Rachel
      ((SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ARP_02_RPSsmile_WirelessGlove_Rachel_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,1,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,8);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1804449867U));
  ssSetChecksum1(S,(671055639U));
  ssSetChecksum2(S,(2408676698U));
  ssSetChecksum3(S,(2127703609U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(SimStruct *S)
{
  SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct *)
    utMalloc(sizeof(SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_ARP_02_RPSsmile_WirelessGlove_RachelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_WirelessGlove_Rachel;
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

void c1_ARP_02_RPSsmile_WirelessGlove_Rachel_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ARP_02_RPSsmile_WirelessGlove_Rachel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ARP_02_RPSsmile_WirelessGlove_Rachel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
