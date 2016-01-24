/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_Glove_atomicError_sfun.h"
#include "c1_ARP_02_RPSsmile_Glove_atomicError.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_Glove_atomicError_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_gameOver                 ((uint8_T)1U)
#define c1_IN_stateBoredPose1          ((uint8_T)2U)
#define c1_IN_stateBradWin             ((uint8_T)3U)
#define c1_IN_stateBrowUp              ((uint8_T)4U)
#define c1_IN_stateCompare             ((uint8_T)5U)
#define c1_IN_stateGo                  ((uint8_T)6U)
#define c1_IN_stateHeadNeutral1        ((uint8_T)7U)
#define c1_IN_stateHeadNeutral2        ((uint8_T)8U)
#define c1_IN_stateIfSmile             ((uint8_T)9U)
#define c1_IN_stateNeckBack            ((uint8_T)10U)
#define c1_IN_stateNoWin               ((uint8_T)11U)
#define c1_IN_statePoseFingersCLose    ((uint8_T)12U)
#define c1_IN_statePosePaper           ((uint8_T)13U)
#define c1_IN_statePoseReady           ((uint8_T)14U)
#define c1_IN_statePoseReturnFinger    ((uint8_T)15U)
#define c1_IN_statePoseReturnWrist     ((uint8_T)16U)
#define c1_IN_statePoseRock            ((uint8_T)17U)
#define c1_IN_statePoseScissors        ((uint8_T)18U)
#define c1_IN_statePoseSmile           ((uint8_T)19U)
#define c1_IN_statePoseSmileWin        ((uint8_T)20U)
#define c1_IN_stateRandom1             ((uint8_T)21U)
#define c1_IN_stateRandomHand          ((uint8_T)22U)
#define c1_IN_stateReadUserHand        ((uint8_T)23U)
#define c1_IN_stateReady               ((uint8_T)24U)
#define c1_IN_stateShowHands           ((uint8_T)25U)
#define c1_IN_stateShowResult          ((uint8_T)26U)
#define c1_IN_stateSmile               ((uint8_T)27U)
#define c1_IN_stateStart               ((uint8_T)28U)
#define c1_IN_stateUserWin             ((uint8_T)29U)
#define c1_IN_stateWristRotate         ((uint8_T)30U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c1_subchartSimStateInfo;
static const mxArray *c1_b_subchartSimStateInfo;
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

static const char * c1_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_sb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_tb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ub_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_vb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_wb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_xb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_yb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_bc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_cc_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c1_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_fc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_gc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_hc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_jc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_kc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_lc_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c1_wc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c1_xc_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c1_yc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ad_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_bd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_cd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_dd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_ed_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_fd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_gd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_hd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_id_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_od_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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

static boolean_T c1_dataWrittenToVector[27];

/* Function Declarations */
static void initialize_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void initialize_params_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void enable_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void disable_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_Glove_atomicErr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void finalize_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void sf_gateway_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void initSimStructsc1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateGame(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_stateStart(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_enter_atomic_stateReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateReady(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_stateIfSmile(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_enter_atomic_statePoseReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateHeadNeutral2
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseSmile
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateSmile(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_enter_atomic_stateWristRotate
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateWristRotate
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateNeckBack
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateRandomHand
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseRock
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseFingersCLose
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePosePaper
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateReadUserHand
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseScissors
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateShowHands
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_enter_atomic_stateBoredPose1
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseReturnFinger
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_enter_atomic_statePoseReturnWrist
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateUserWin(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_stateNoWin(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_stateRandom1(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_stateHeadNeutral1
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_statePoseSmileWin
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_stateShowResult
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);
static void c1_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_b_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_c_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_d_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_e_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_f_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_g_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_h_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_i_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_j_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_k_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_l_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_m_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_n_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_o_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static real_T c1_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_lowhigh[2]);
static real_T c1_rand(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
                      *chartInstance);
static real_T c1_eml_rand(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625]);
static void c1_twister_state_vector
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625]);
static void c1_b_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_b_r);
static void c1_eml_error(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static real_T c1_b_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_p_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_q_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_r_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_s_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_t_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_u_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_v_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_w_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_x_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_y_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256]);
static void c1_ab_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_bb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_cb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_db_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_eb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_fb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_gb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_hb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static real_T c1_c_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static real_T c1_d_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance);
static void c1_ib_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_jb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_kb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_lb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_mb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_nb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_ob_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_pb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_qb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_rb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void c1_sb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_bmlID, const char_T *c1_identifier);
static real_T c1_c_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_sendBML(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_arg[256]);
static void c1_handPoseSB(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_sbmID, real_T c1_poseSBM[256]);
static void c1_idlePose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_poseBML[256]);
static void c1_boredGaze(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_gazeBML[256]);
static const mxArray *c1_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_stateGame, const char_T *c1_identifier);
static uint8_T c1_i_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint32_T c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_b_method, const char_T *c1_identifier);
static uint32_T c1_k_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static uint32_T c1_l_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier);
static uint32_T c1_m_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_n_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625]);
static void c1_o_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625]);
static void c1_p_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2]);
static void c1_q_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2]);
static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_c_subchartSimStateInfo, const char_T *c1_identifier);
static const mxArray *c1_s_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber);
static void c1_b_twister_state_vector
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_mt[625], real_T c1_seed);
static real_T c1_c_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625]);
static real_T c1_get_BOREDOMT
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static void c1_set_BOREDOMT(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BOREDOMT
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static real_T c1_get_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_bored(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b);
static void c1_set_bored(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bored
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static real_T c1_get_pose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static real_T c1_get_randomD
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static void c1_set_randomD(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomD
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static real_T c1_get_randomG
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static void c1_set_randomG(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomG
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static real_T c1_get_randomP
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static void c1_set_randomP(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomP
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b);
static void init_dsm_address_info
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  sf_exported_auto_initc10_ARP_02_RPSsmile_Glove_atomicError
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_initc11_lib_affectiveChar_scenario
    (chartInstance->c1_b_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c1_subchartSimStateInfo = NULL;
  c1_b_subchartSimStateInfo = NULL;
  chartInstance->c1_method_not_empty = false;
  chartInstance->c1_state_not_empty = false;
  chartInstance->c1_b_state_not_empty = false;
  chartInstance->c1_c_state_not_empty = false;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_stateGame = 0U;
  chartInstance->c1_is_stateGame = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_stateGame = 0U;
  chartInstance->c1_tp_gameOver = 0U;
  chartInstance->c1_tp_stateBoredPose1 = 0U;
  chartInstance->c1_tp_stateBradWin = 0U;
  chartInstance->c1_tp_stateBrowUp = 0U;
  chartInstance->c1_tp_stateCompare = 0U;
  chartInstance->c1_tp_stateGo = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateHeadNeutral1 = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateHeadNeutral2 = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateIfSmile = 0U;
  chartInstance->c1_tp_stateNeckBack = 0U;
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
  chartInstance->c1_tp_stateRandom1 = 0U;
  chartInstance->c1_tp_stateRandomHand = 0U;
  chartInstance->c1_tp_stateReadUserHand = 0U;
  chartInstance->c1_tp_stateReady = 0U;
  chartInstance->c1_tp_stateShowHands = 0U;
  chartInstance->c1_tp_stateShowResult = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateSmile = 0U;
  chartInstance->c1_tp_stateStart = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateUserWin = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateWristRotate = 0U;
  chartInstance->c1_is_active_stateIdleGaze = 0U;
  chartInstance->c1_tp_stateIdleGaze = 0U;
  chartInstance->c1_is_active_stateIdlePose = 0U;
  chartInstance->c1_tp_stateIdlePose = 0U;
  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError = 0U;
  c1_set_bored(chartInstance, 0, 0.0);
  c1_set_BOREDOMT(chartInstance, 0, 0.0);
  c1_set_randomG(chartInstance, 0, 0.0);
  c1_set_randomP(chartInstance, 0, 0.0);
  c1_set_pose(chartInstance, 0, 0.0);
  c1_set_b(chartInstance, 0, 0.0);
  c1_set_randomD(chartInstance, 0, 0.0);
}

static void initialize_params_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "sendBML", 0);
  if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
    sf_exported_auto_enablec10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_stateIdlePose == 1U) {
    sf_exported_auto_enablec11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
  }
}

static void disable_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "sendBML", 0);
  if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
    sf_exported_auto_disablec10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_stateIdlePose == 1U) {
    sf_exported_auto_disablec11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
  }
}

static void c1_update_debugger_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateGame == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateIfSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateHeadNeutral2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateWristRotate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateNeckBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateRandomHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseRock) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseFingersCLose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateBoredPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnFinger) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseReturnWrist) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateRandom1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateHeadNeutral1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_statePoseSmileWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_stateGame == c1_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_stateIdlePose == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  uint32_T c1_ab_hoistedGlobal;
  uint32_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  uint32_T c1_bb_hoistedGlobal;
  uint32_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  int32_T c1_i0;
  uint32_T c1_cb_u[625];
  const mxArray *c1_db_y = NULL;
  int32_T c1_i1;
  uint32_T c1_db_u[2];
  const mxArray *c1_eb_y = NULL;
  uint8_T c1_cb_hoistedGlobal;
  uint8_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  uint8_T c1_db_hoistedGlobal;
  uint8_T c1_fb_u;
  const mxArray *c1_gb_y = NULL;
  uint8_T c1_eb_hoistedGlobal;
  uint8_T c1_gb_u;
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
  const mxArray *c1_kb_u;
  const mxArray *c1_lb_y = NULL;
  const mxArray *c1_lb_u;
  const mxArray *c1_mb_y = NULL;
  real_T *c1_bWinT;
  real_T *c1_bradHand;
  real_T *c1_gameState;
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_subchartSimStateInfo,
                sf_exported_auto_getSimstatec10_ARP_02_RPSsmile_Glove_atomicError
                (chartInstance->c1_subchartSimstruct), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo,
                sf_exported_auto_getSimstatec11_lib_affectiveChar_scenario
                (chartInstance->c1_b_subchartSimstruct), true);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(37, 1), false);
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
  c1_d_hoistedGlobal = *c1_round;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_uWinT;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_userHand;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_win;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = c1_get_BOREDOMT(chartInstance, 0);
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = c1_get_b(chartInstance, 0);
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_bHand;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = c1_get_bored(chartInstance, 0);
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_diff;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = chartInstance->c1_p;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = c1_get_pose(chartInstance, 0);
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = chartInstance->c1_r;
  c1_o_u = c1_o_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_p_hoistedGlobal = c1_get_randomD(chartInstance, 0);
  c1_p_u = c1_p_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_q_hoistedGlobal = c1_get_randomG(chartInstance, 0);
  c1_q_u = c1_q_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_r_hoistedGlobal = chartInstance->c1_randomH;
  c1_r_u = c1_r_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_s_hoistedGlobal = c1_get_randomP(chartInstance, 0);
  c1_s_u = c1_s_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  c1_t_hoistedGlobal = chartInstance->c1_s;
  c1_t_u = c1_t_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_u_hoistedGlobal = chartInstance->c1_smileN;
  c1_u_u = c1_u_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_v_hoistedGlobal = chartInstance->c1_smileYN;
  c1_v_u = c1_v_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_w_hoistedGlobal = chartInstance->c1_temp;
  c1_w_u = c1_w_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_x_hoistedGlobal = chartInstance->c1_uHand;
  c1_x_u = c1_x_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_y_hoistedGlobal = chartInstance->c1_wristRotate;
  c1_y_u = c1_y_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_ab_hoistedGlobal = chartInstance->c1_method;
  c1_ab_u = c1_ab_hoistedGlobal;
  c1_bb_y = NULL;
  if (!chartInstance->c1_method_not_empty) {
    sf_mex_assign(&c1_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_bb_hoistedGlobal = chartInstance->c1_state;
  c1_bb_u = c1_bb_hoistedGlobal;
  c1_cb_y = NULL;
  if (!chartInstance->c1_state_not_empty) {
    sf_mex_assign(&c1_cb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 7, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c1_y, 26, c1_cb_y);
  for (c1_i0 = 0; c1_i0 < 625; c1_i0++) {
    c1_cb_u[c1_i0] = chartInstance->c1_c_state[c1_i0];
  }

  c1_db_y = NULL;
  if (!chartInstance->c1_c_state_not_empty) {
    sf_mex_assign(&c1_db_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_db_y, sf_mex_create("y", c1_cb_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c1_y, 27, c1_db_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_db_u[c1_i1] = chartInstance->c1_b_state[c1_i1];
  }

  c1_eb_y = NULL;
  if (!chartInstance->c1_b_state_not_empty) {
    sf_mex_assign(&c1_eb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c1_eb_y, sf_mex_create("y", c1_db_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_cb_hoistedGlobal =
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError;
  c1_eb_u = c1_cb_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_db_hoistedGlobal = chartInstance->c1_is_active_stateGame;
  c1_fb_u = c1_db_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_fb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_eb_hoistedGlobal = chartInstance->c1_is_active_stateIdleGaze;
  c1_gb_u = c1_eb_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_gb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_fb_hoistedGlobal = chartInstance->c1_is_active_stateIdlePose;
  c1_hb_u = c1_fb_hoistedGlobal;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_hb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_gb_hoistedGlobal = chartInstance->c1_is_stateGame;
  c1_ib_u = c1_gb_hoistedGlobal;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_ib_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_hb_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_jb_u = c1_hb_hoistedGlobal;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_jb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_kb_u = sf_mex_dup(c1_subchartSimStateInfo);
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_duplicatearraysafe(&c1_kb_u), false);
  sf_mex_destroy(&c1_kb_u);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  c1_lb_u = sf_mex_dup(c1_b_subchartSimStateInfo);
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_duplicatearraysafe(&c1_lb_u), false);
  sf_mex_destroy(&c1_lb_u);
  sf_mex_setcell(c1_y, 36, c1_mb_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  real_T *c1_round;
  real_T *c1_uWinT;
  real_T *c1_userHand;
  real_T *c1_win;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
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
  *c1_round = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "round");
  *c1_uWinT = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "uWinT");
  *c1_userHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "userHand");
  *c1_win = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    6)), "win");
  c1_set_BOREDOMT(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 7)), "BOREDOMT"));
  c1_set_b(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 8)), "b"));
  chartInstance->c1_bHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "bHand");
  c1_set_bored(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
                (sf_mex_getcell(c1_u, 10)), "bored"));
  chartInstance->c1_diff = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "diff");
  chartInstance->c1_p = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "p");
  c1_set_pose(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 13)), "pose"));
  chartInstance->c1_r = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 14)), "r");
  c1_set_randomD(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 15)), "randomD"));
  c1_set_randomG(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 16)), "randomG"));
  chartInstance->c1_randomH = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 17)), "randomH");
  c1_set_randomP(chartInstance, 0, c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 18)), "randomP"));
  chartInstance->c1_s = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 19)), "s");
  chartInstance->c1_smileN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 20)), "smileN");
  chartInstance->c1_smileYN = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 21)), "smileYN");
  chartInstance->c1_temp = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 22)), "temp");
  chartInstance->c1_uHand = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 23)), "uHand");
  chartInstance->c1_wristRotate = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 24)), "wristRotate");
  chartInstance->c1_method = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 25)), "method");
  chartInstance->c1_state = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 26)), "state");
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 27)),
                        "state", c1_uv0);
  for (c1_i2 = 0; c1_i2 < 625; c1_i2++) {
    chartInstance->c1_c_state[c1_i2] = c1_uv0[c1_i2];
  }

  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 28)),
                        "state", c1_uv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_b_state[c1_i3] = c1_uv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError =
    c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 29)),
    "is_active_c1_ARP_02_RPSsmile_Glove_atomicError");
  chartInstance->c1_is_active_stateGame = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 30)), "is_active_stateGame");
  chartInstance->c1_is_active_stateIdleGaze = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 31)),
     "is_active_stateIdleGaze");
  chartInstance->c1_is_active_stateIdlePose = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 32)),
     "is_active_stateIdlePose");
  chartInstance->c1_is_stateGame = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "is_stateGame");
  chartInstance->c1_temporalCounter_i1 = c1_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 34)), "temporalCounter_i1");
  sf_mex_assign(&c1_subchartSimStateInfo, c1_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 35)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo, c1_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 36)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 37)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_ARP_02_RPSsmile_Glove_atomicError(chartInstance);
  sf_exported_auto_setSimstatec10_ARP_02_RPSsmile_Glove_atomicError
    (chartInstance->c1_subchartSimstruct, sf_mex_dup(c1_subchartSimStateInfo));
  sf_exported_auto_setSimstatec11_lib_affectiveChar_scenario
    (chartInstance->c1_b_subchartSimstruct, sf_mex_dup(c1_b_subchartSimStateInfo));
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_Glove_atomicErr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_stateGame == 1U) {
      chartInstance->c1_tp_stateGame = 1U;
    } else {
      chartInstance->c1_tp_stateGame = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_gameOver) {
      chartInstance->c1_tp_gameOver = 1U;
    } else {
      chartInstance->c1_tp_gameOver = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateBoredPose1) {
      chartInstance->c1_tp_stateBoredPose1 = 1U;
    } else {
      chartInstance->c1_tp_stateBoredPose1 = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateBradWin) {
      chartInstance->c1_tp_stateBradWin = 1U;
    } else {
      chartInstance->c1_tp_stateBradWin = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateBrowUp) {
      chartInstance->c1_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c1_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateCompare) {
      chartInstance->c1_tp_stateCompare = 1U;
    } else {
      chartInstance->c1_tp_stateCompare = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateGo) {
      chartInstance->c1_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateGo = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateHeadNeutral1) {
      chartInstance->c1_tp_stateHeadNeutral1 = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateHeadNeutral1 = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateHeadNeutral2) {
      chartInstance->c1_tp_stateHeadNeutral2 = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateHeadNeutral2 = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateIfSmile) {
      chartInstance->c1_tp_stateIfSmile = 1U;
    } else {
      chartInstance->c1_tp_stateIfSmile = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateNeckBack) {
      chartInstance->c1_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateNoWin) {
      chartInstance->c1_tp_stateNoWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
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
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePosePaper = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseReady) {
      chartInstance->c1_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
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
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseRock = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_statePoseScissors) {
      chartInstance->c1_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 20) == 0.0) {
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
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_statePoseSmileWin = 0U;
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
                     "setSimStateSideEffectsInfo", 1, 28) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateShowResult = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateSmile) {
      chartInstance->c1_tp_stateSmile = 1U;
    } else {
      chartInstance->c1_tp_stateSmile = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateStart) {
      chartInstance->c1_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 30) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_stateStart = 0U;
    }

    if (chartInstance->c1_is_stateGame == c1_IN_stateUserWin) {
      chartInstance->c1_tp_stateUserWin = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 31) == 0.0) {
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

    if (chartInstance->c1_is_active_stateIdlePose == 1U) {
      chartInstance->c1_tp_stateIdlePose = 1U;
    } else {
      chartInstance->c1_tp_stateIdlePose = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c1_subchartSimStateInfo);
  sf_mex_destroy(&c1_b_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T *c1_gameState;
  real_T *c1_inputUser;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_win;
  real_T *c1_bWinT;
  real_T *c1_uWinT;
  real_T *c1_round;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_Glove_atomicErr(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc10_ARP_02_RPSsmile_Glove_atomicError
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_gatewayc11_lib_affectiveChar_scenario
    (chartInstance->c1_b_subchartSimstruct);
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
  _SFD_DATA_RANGE_CHECK(c1_get_bored(chartInstance, 0), 13U);
  _SFD_DATA_RANGE_CHECK(c1_get_BOREDOMT(chartInstance, 0), 14U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomG(chartInstance, 0), 15U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomP(chartInstance, 0), 16U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  _SFD_DATA_RANGE_CHECK(c1_get_b(chartInstance, 0), 18U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_p, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_s, 21U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomD(chartInstance, 0), 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_wristRotate, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomH, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 25U);
  sf_exported_auto_activate_c10_ARP_02_RPSsmile_Glove_atomicError_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_activate_c11_lib_affectiveChar_scenario_secs
    (chartInstance->c1_b_subchartSimstruct);
  if (chartInstance->c1_temporalCounter_i1 < 7U) {
    chartInstance->c1_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c1_temporalCounter_i1 + 1);
  }

  sf_exported_auto_incrementTemporalCounter_c10_ARP_02_RPSsmile_Glove_atomicError_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c11_lib_affectiveChar_scenario_secs
    (chartInstance->c1_b_subchartSimstruct);
  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_stepBuffersc10_ARP_02_RPSsmile_Glove_atomicError
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_stepBuffersc11_lib_affectiveChar_scenario
    (chartInstance->c1_b_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError == 0U) {
    sf_exported_auto_initBuffersc10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
    sf_exported_auto_initBuffersc11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_Glove_atomicError = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_stateGame = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateGame = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateStart;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateStart = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_x_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    *c1_round = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_DATA_RANGE_CHECK(*c1_round, 25U);
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
    c1_set_BOREDOMT(chartInstance, 0, 10.0);
    _SFD_DATA_RANGE_CHECK(c1_get_BOREDOMT(chartInstance, 0), 14U);
    *c1_gameState = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    c1_set_randomP(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_randomP(chartInstance, 0), 16U);
    *c1_uWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 9U);
    _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
    *c1_bWinT = 0.0;
    c1_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
    c1_set_pose(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    c1_set_bored(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_bored(chartInstance, 0), 13U);
    c1_set_randomG(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_randomG(chartInstance, 0), 15U);
    c1_idlePose(chartInstance, 3.0, c1_dv0);
    for (c1_i4 = 0; c1_i4 < 256; c1_i4++) {
      c1_arg[c1_i4] = c1_dv0[c1_i4];
    }

    for (c1_i5 = 0; c1_i5 < 256; c1_i5++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i5], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i6 = 0; c1_i6 < 256; c1_i6++) {
      (*c1_b_arg)[c1_i6] = c1_arg[c1_i6];
    }

    for (c1_i7 = 0; c1_i7 < 256; c1_i7++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i7], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_is_active_stateIdleGaze = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateIdleGaze = 1U;
    sf_exported_auto_enterc10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
    chartInstance->c1_is_active_stateIdlePose = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateIdlePose = 1U;
    sf_exported_auto_enterc11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
  } else {
    c1_stateGame(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_resetTemporalCounter_c10_ARP_02_RPSsmile_Glove_atomicError_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c11_lib_affectiveChar_scenario_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_deactivate_c10_ARP_02_RPSsmile_Glove_atomicError_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_deactivate_c11_lib_affectiveChar_scenario_secs
    (chartInstance->c1_b_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c1_is_active_stateIdleGaze == 1U) {
    sf_exported_auto_check_state_inconsistency_c10_ARP_02_RPSsmile_Glove_atomicError
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_stateIdlePose == 1U) {
    sf_exported_auto_check_state_inconsistency_c11_lib_affectiveChar_scenario
      (chartInstance->c1_b_subchartSimstruct);
  }
}

static void initSimStructsc1_ARP_02_RPSsmile_Glove_atomicError
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  chartInstance->c1_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "stateIdleGaze");
  chartInstance->c1_b_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "stateIdlePose");
}

static void c1_stateGame(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv1[256];
  int32_T c1_i8;
  real_T c1_arg[256];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv2[2];
  uint32_T c1_b_debug_family_var_map[3];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 0.0;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 0.0;
  real_T *c1_win;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  real_T *c1_gameState;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T (*c1_b_arg)[256];
  boolean_T guard1 = false;
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_stateGame) {
   case c1_IN_gameOver:
    CV_STATE_EVAL(11, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_gameOver = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateHeadNeutral2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateHeadNeutral2 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_db_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_idlePose(chartInstance, 8.0, c1_dv1);
    for (c1_i8 = 0; c1_i8 < 256; c1_i8++) {
      c1_arg[c1_i8] = c1_dv1[c1_i8];
    }

    for (c1_i9 = 0; c1_i9 < 256; c1_i9++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i9], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i10 = 0; c1_i10 < 256; c1_i10++) {
      (*c1_b_arg)[c1_i10] = c1_arg[c1_i10];
    }

    for (c1_i11 = 0; c1_i11 < 256; c1_i11++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i11], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateBoredPose1:
    CV_STATE_EVAL(11, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateBradWin:
    CV_STATE_EVAL(11, 0, 3);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateBradWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fd_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_dv2[0] = 0.0;
    c1_dv2[1] = c1_get_bored(chartInstance, 0);
    chartInstance->c1_smileYN = c1_randi(chartInstance, c1_dv2);
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    c1_set_pose(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateBrowUp:
    CV_STATE_EVAL(11, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateCompare:
    CV_STATE_EVAL(11, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ke_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
    c1_out = CV_EML_IF(10, 0, 0, chartInstance->c1_diff == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateBradWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateBradWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ed_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 0.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_je_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
      c1_b_out = CV_EML_IF(1, 0, 0, chartInstance->c1_diff == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateUserWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_stateUserWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_cd_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_set_pose(chartInstance, 0, 0.0);
        _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_le_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
        guard1 = false;
        if (CV_EML_COND(7, 0, 0, chartInstance->c1_diff != 1.0)) {
          if (CV_EML_COND(7, 0, 1, chartInstance->c1_diff != 2.0)) {
            CV_EML_MCDC(7, 0, 0, true);
            CV_EML_IF(7, 0, 0, true);
            c1_c_out = true;
          } else {
            guard1 = true;
          }
        } else {
          c1_errorIfDataNotWrittenToFcn(chartInstance, 5U, 6U);
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(7, 0, 0, false);
          CV_EML_IF(7, 0, 0, false);
          c1_c_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateCompare = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateGame = c1_IN_stateNoWin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i1 = 0U;
          chartInstance->c1_tp_stateNoWin = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_dd_debug_family_names,
            c1_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          *c1_win = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
          c1_set_pose(chartInstance, 0, 0.0);
          _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                       chartInstance->c1_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateGo:
    CV_STATE_EVAL(11, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_wd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_d_out = CV_EML_IF(3, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i1 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateGo = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateRandomHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandomHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_dc_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 1.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_stateHeadNeutral1:
    CV_STATE_EVAL(11, 0, 7);
    c1_stateHeadNeutral1(chartInstance);
    break;

   case c1_IN_stateHeadNeutral2:
    CV_STATE_EVAL(11, 0, 8);
    c1_stateHeadNeutral2(chartInstance);
    break;

   case c1_IN_stateIfSmile:
    CV_STATE_EVAL(11, 0, 9);
    c1_stateIfSmile(chartInstance);
    break;

   case c1_IN_stateNeckBack:
    CV_STATE_EVAL(11, 0, 10);
    c1_stateNeckBack(chartInstance);
    break;

   case c1_IN_stateNoWin:
    CV_STATE_EVAL(11, 0, 11);
    c1_stateNoWin(chartInstance);
    break;

   case c1_IN_statePoseFingersCLose:
    CV_STATE_EVAL(11, 0, 12);
    c1_statePoseFingersCLose(chartInstance);
    break;

   case c1_IN_statePosePaper:
    CV_STATE_EVAL(11, 0, 13);
    c1_statePosePaper(chartInstance);
    break;

   case c1_IN_statePoseReady:
    CV_STATE_EVAL(11, 0, 14);
    c1_statePoseReady(chartInstance);
    break;

   case c1_IN_statePoseReturnFinger:
    CV_STATE_EVAL(11, 0, 15);
    c1_statePoseReturnFinger(chartInstance);
    break;

   case c1_IN_statePoseReturnWrist:
    CV_STATE_EVAL(11, 0, 16);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnWrist = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_kc_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_statePoseRock:
    CV_STATE_EVAL(11, 0, 17);
    c1_statePoseRock(chartInstance);
    break;

   case c1_IN_statePoseScissors:
    CV_STATE_EVAL(11, 0, 18);
    c1_statePoseScissors(chartInstance);
    break;

   case c1_IN_statePoseSmile:
    CV_STATE_EVAL(11, 0, 19);
    c1_statePoseSmile(chartInstance);
    break;

   case c1_IN_statePoseSmileWin:
    CV_STATE_EVAL(11, 0, 20);
    c1_statePoseSmileWin(chartInstance);
    break;

   case c1_IN_stateRandom1:
    CV_STATE_EVAL(11, 0, 21);
    c1_stateRandom1(chartInstance);
    break;

   case c1_IN_stateRandomHand:
    CV_STATE_EVAL(11, 0, 22);
    c1_stateRandomHand(chartInstance);
    break;

   case c1_IN_stateReadUserHand:
    CV_STATE_EVAL(11, 0, 23);
    c1_stateReadUserHand(chartInstance);
    break;

   case c1_IN_stateReady:
    CV_STATE_EVAL(11, 0, 24);
    c1_stateReady(chartInstance);
    break;

   case c1_IN_stateShowHands:
    CV_STATE_EVAL(11, 0, 25);
    c1_stateShowHands(chartInstance);
    break;

   case c1_IN_stateShowResult:
    CV_STATE_EVAL(11, 0, 26);
    c1_stateShowResult(chartInstance);
    break;

   case c1_IN_stateSmile:
    CV_STATE_EVAL(11, 0, 27);
    c1_stateSmile(chartInstance);
    break;

   case c1_IN_stateStart:
    CV_STATE_EVAL(11, 0, 28);
    c1_stateStart(chartInstance);
    break;

   case c1_IN_stateUserWin:
    CV_STATE_EVAL(11, 0, 29);
    c1_stateUserWin(chartInstance);
    break;

   case c1_IN_stateWristRotate:
    CV_STATE_EVAL(11, 0, 30);
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

static void c1_stateStart(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_jd_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReady = 1U;
    c1_enter_atomic_stateReady(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_round;
  real_T *c1_bradHand;
  real_T *c1_userHand;
  real_T *c1_gameState;
  real_T *c1_win;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
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
  c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 25U);
  (*c1_round)++;
  c1_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_DATA_RANGE_CHECK(*c1_round, 25U);
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
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateReady(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
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
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_nd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(4, 0, 0, c1_get_bored(chartInstance, 0) < c1_get_BOREDOMT
                     (chartInstance, 0) - 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_od_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_bored(chartInstance, 0, c1_get_bored(chartInstance, 0) + 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_bored(chartInstance, 0), 13U);
    sf_mex_printf("%s =\\n", "bored");
    c1_hoistedGlobal = c1_get_bored(chartInstance, 0);
    c1_u = c1_hoistedGlobal;
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c1_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseReady = 1U;
    c1_enter_atomic_statePoseReady(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseReady = 1U;
    c1_enter_atomic_statePoseReady(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c1_sfEvent);
}

static void c1_stateIfSmile(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_dv3[256];
  int32_T c1_i12;
  real_T c1_arg[256];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
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
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_rd_debug_family_names,
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
    chartInstance->c1_tp_stateIfSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_eb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_smileN = c1_b_randi(chartInstance);
    c1_updateDataWrittenToVector(chartInstance, 10U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 11U);
    c1_hoistedGlobal = chartInstance->c1_smileN;
    c1_idlePose(chartInstance, c1_hoistedGlobal, c1_dv3);
    for (c1_i12 = 0; c1_i12 < 256; c1_i12++) {
      c1_arg[c1_i12] = c1_dv3[c1_i12];
    }

    for (c1_i13 = 0; c1_i13 < 256; c1_i13++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i13], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i14 = 0; c1_i14 < 256; c1_i14++) {
      (*c1_b_arg)[c1_i14] = c1_arg[c1_i14];
    }

    for (c1_i15 = 0; c1_i15 < 256; c1_i15++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i15], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qd_debug_family_names,
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
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vd_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
      c1_c_out = CV_EML_IF(37, 0, 0, chartInstance->c1_wristRotate == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateIfSmile = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateWristRotate;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateWristRotate = 1U;
        c1_enter_atomic_stateWristRotate(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                     chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_td_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_c_sf_marshallOut,
          c1_c_sf_marshallIn);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
        c1_d_out = CV_EML_IF(38, 0, 0, chartInstance->c1_wristRotate != 1.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_stateIfSmile = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_stateGame = c1_IN_stateGo;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
          chartInstance->c1_temporalCounter_i1 = 0U;
          chartInstance->c1_tp_stateGo = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fb_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          c1_set_pose(chartInstance, 0, 1.0);
          _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_statePoseReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv4[256];
  int32_T c1_i16;
  real_T c1_arg[256];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_dv5[256];
  int32_T c1_i20;
  real_T c1_b_arg[256];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_b_r;
  real_T c1_x;
  real_T c1_b_x;
  real_T (*c1_c_arg)[256];
  real_T (*c1_d_arg)[256];
  c1_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_cb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_idlePose(chartInstance, 8.0, c1_dv4);
  for (c1_i16 = 0; c1_i16 < 256; c1_i16++) {
    c1_arg[c1_i16] = c1_dv4[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 256; c1_i17++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i17], 27U);
  }

  _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i18 = 0; c1_i18 < 256; c1_i18++) {
    (*c1_d_arg)[c1_i18] = c1_arg[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 256; c1_i19++) {
    _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i19], 27U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(27U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  c1_handPoseSB(chartInstance, 2.0, c1_dv5);
  for (c1_i20 = 0; c1_i20 < 256; c1_i20++) {
    c1_b_arg[c1_i20] = c1_dv5[c1_i20];
  }

  for (c1_i21 = 0; c1_i21 < 256; c1_i21++) {
    _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i21], 26U);
  }

  _SFD_SET_DATA_VALUE_PTR(26U, c1_b_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i22 = 0; c1_i22 < 256; c1_i22++) {
    (*c1_c_arg)[c1_i22] = c1_b_arg[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 256; c1_i23++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_arg)[c1_i23], 26U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(26U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  c1_b_r = c1_rand(chartInstance);
  c1_x = c1_b_r * 2.0;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarFloor(c1_b_x);
  c1_b_r = c1_b_x;
  chartInstance->c1_wristRotate = c1_b_r;
  c1_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_wristRotate, 23U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_statePoseReady
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv6[2];
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_pd_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateIfSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateIfSmile = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_bb_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_dv6[0] = 0.0;
    c1_dv6[1] = c1_get_bored(chartInstance, 0);
    chartInstance->c1_smileYN = c1_randi(chartInstance, c1_dv6);
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c1_sfEvent);
}

static void c1_stateHeadNeutral2
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T c1_hoistedGlobal;
  real_T c1_dv7[256];
  int32_T c1_i24;
  real_T c1_arg[256];
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T *c1_uWinT;
  real_T *c1_bWinT;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_sd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(45, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ud_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 9U, 10U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 8U, 9U);
    c1_b_out = CV_EML_IF(42, 0, 0, *c1_uWinT < *c1_bWinT);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_gb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      chartInstance->c1_smileN = c1_b_randi(chartInstance);
      c1_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileN, 11U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 10U, 11U);
      c1_hoistedGlobal = chartInstance->c1_smileN;
      c1_idlePose(chartInstance, c1_hoistedGlobal, c1_dv7);
      for (c1_i24 = 0; c1_i24 < 256; c1_i24++) {
        c1_arg[c1_i24] = c1_dv7[c1_i24];
      }

      for (c1_i25 = 0; c1_i25 < 256; c1_i25++) {
        _SFD_DATA_RANGE_CHECK(c1_arg[c1_i25], 27U);
      }

      _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      for (c1_i26 = 0; c1_i26 < 256; c1_i26++) {
        (*c1_b_arg)[c1_i26] = c1_arg[c1_i26];
      }

      for (c1_i27 = 0; c1_i27 < 256; c1_i27++) {
        _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i27], 27U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(27U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateHeadNeutral2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateBoredPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateBoredPose1 = 1U;
      c1_enter_atomic_stateBoredPose1(chartInstance);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c1_sfEvent);
}

static void c1_statePoseSmile
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_vd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
  c1_out = CV_EML_IF(37, 0, 0, chartInstance->c1_wristRotate == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseSmile = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateWristRotate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateWristRotate = 1U;
    c1_enter_atomic_stateWristRotate(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_td_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
    c1_b_out = CV_EML_IF(38, 0, 0, chartInstance->c1_wristRotate != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePoseSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateGo;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateGo = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fb_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 1.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
      *c1_gameState = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c1_sfEvent);
}

static void c1_stateSmile(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv8[256];
  int32_T c1_i28;
  real_T c1_arg[256];
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateSmile = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_stateNeckBack;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateNeckBack = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ib_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_boredGaze(chartInstance, 17.0, c1_dv8);
  for (c1_i28 = 0; c1_i28 < 256; c1_i28++) {
    c1_arg[c1_i28] = c1_dv8[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 256; c1_i29++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i29], 27U);
  }

  _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i30 = 0; c1_i30 < 256; c1_i30++) {
    (*c1_b_arg)[c1_i30] = c1_arg[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 256; c1_i31++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i31], 27U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(27U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateWristRotate
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv9[256];
  int32_T c1_i32;
  real_T c1_arg[256];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_hb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  c1_handPoseSB(chartInstance, 5.0, c1_dv9);
  for (c1_i32 = 0; c1_i32 < 256; c1_i32++) {
    c1_arg[c1_i32] = c1_dv9[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 256; c1_i33++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i33], 26U);
  }

  _SFD_SET_DATA_VALUE_PTR(26U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i34 = 0; c1_i34 < 256; c1_i34++) {
    (*c1_b_arg)[c1_i34] = c1_arg[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 256; c1_i35++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i35], 26U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(26U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateWristRotate
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T *c1_gameState;
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateWristRotate = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_stateGo;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_stateGo = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fb_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  *c1_gameState = 1.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, chartInstance->c1_sfEvent);
}

static void c1_stateNeckBack
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv10[256];
  int32_T c1_i36;
  real_T c1_arg[256];
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_xd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(43, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateNeckBack = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateBrowUp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateBrowUp = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ec_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_boredGaze(chartInstance, 18.0, c1_dv10);
    for (c1_i36 = 0; c1_i36 < 256; c1_i36++) {
      c1_arg[c1_i36] = c1_dv10[c1_i36];
    }

    for (c1_i37 = 0; c1_i37 < 256; c1_i37++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i37], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i38 = 0; c1_i38 < 256; c1_i38++) {
      (*c1_b_arg)[c1_i38] = c1_arg[c1_i38];
    }

    for (c1_i39 = 0; c1_i39 < 256; c1_i39++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i39], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c1_sfEvent);
}

static void c1_stateRandomHand
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T c1_dv11[256];
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i44;
  int32_T c1_i45;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i46;
  real_T c1_arg[256];
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
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
  int32_T c1_i50;
  int32_T c1_i51;
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
  int32_T c1_i52;
  static char_T c1_cv0[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i53;
  static real_T c1_dv12[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i59;
  int32_T c1_i60;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i61;
  real_T c1_b_arg[256];
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_dv13[256];
  int32_T c1_i65;
  real_T c1_c_arg[256];
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  real_T (*c1_d_arg)[256];
  real_T (*c1_e_arg)[256];
  c1_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  c1_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_be_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
  c1_out = CV_EML_IF(27, 0, 0, chartInstance->c1_bHand == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandomHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePosePaper;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePosePaper = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_hc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_p = c1_c_randi(chartInstance);
    c1_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_p, 20U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 13U, 20U);
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
      c1_b_encStr2Arr(chartInstance, c1_dv11);
      for (c1_i40 = 0; c1_i40 < 256; c1_i40++) {
        c1_poseBML[c1_i40] = c1_dv11[c1_i40];
      }

      c1_updateDataWrittenToVector(chartInstance, 19U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 31U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i41 = 0; c1_i41 < 256; c1_i41++) {
        c1_u[c1_i41] = c1_poseBML[c1_i41];
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
        c1_c_encStr2Arr(chartInstance, c1_dv11);
        for (c1_i42 = 0; c1_i42 < 256; c1_i42++) {
          c1_poseBML[c1_i42] = c1_dv11[c1_i42];
        }

        c1_updateDataWrittenToVector(chartInstance, 19U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 31U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i43 = 0; c1_i43 < 256; c1_i43++) {
          c1_b_u[c1_i43] = c1_poseBML[c1_i43];
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
        c1_c_encStr2Arr(chartInstance, c1_dv11);
        for (c1_i44 = 0; c1_i44 < 256; c1_i44++) {
          c1_poseBML[c1_i44] = c1_dv11[c1_i44];
        }

        c1_updateDataWrittenToVector(chartInstance, 19U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 19U, 31U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i45 = 0; c1_i45 < 256; c1_i45++) {
          c1_c_u[c1_i45] = c1_poseBML[c1_i45];
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
    for (c1_i46 = 0; c1_i46 < 256; c1_i46++) {
      c1_arg[c1_i46] = c1_poseBML[c1_i46];
    }

    for (c1_i47 = 0; c1_i47 < 256; c1_i47++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i47], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i48 = 0; c1_i48 < 256; c1_i48++) {
      (*c1_e_arg)[c1_i48] = c1_arg[c1_i48];
    }

    for (c1_i49 = 0; c1_i49 < 256; c1_i49++) {
      _SFD_DATA_RANGE_CHECK((*c1_e_arg)[c1_i49], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ae_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    c1_b_out = CV_EML_IF(28, 0, 0, chartInstance->c1_bHand == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateRandomHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_statePoseRock;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_statePoseRock = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fc_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 1.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
      chartInstance->c1_r = c1_c_randi(chartInstance);
      c1_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_r, 19U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 12U, 19U);
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
        c1_encStr2Arr(chartInstance, c1_dv11);
        for (c1_i50 = 0; c1_i50 < 256; c1_i50++) {
          c1_b_poseBML[c1_i50] = c1_dv11[c1_i50];
        }

        c1_updateDataWrittenToVector(chartInstance, 18U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 29U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i51 = 0; c1_i51 < 256; c1_i51++) {
          c1_d_u[c1_i51] = c1_b_poseBML[c1_i51];
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
          for (c1_i52 = 0; c1_i52 < 94; c1_i52++) {
            c1_mystr[c1_i52] = c1_cv0[c1_i52];
          }

          CV_SCRIPT_FCN(0, 0);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
          c1_maxarrsize = 256.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
          for (c1_i53 = 0; c1_i53 < 94; c1_i53++) {
            c1_arr[c1_i53] = c1_dv12[c1_i53];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
          c1_ss = 94.0;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
          c1_padsize = c1_maxarrsize - c1_ss;
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
          for (c1_i54 = 0; c1_i54 < 256; c1_i54++) {
            c1_tt[c1_i54] = 0.0;
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
          for (c1_i55 = 0; c1_i55 < 94; c1_i55++) {
            c1_tt[c1_i55] = c1_arr[c1_i55];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
          for (c1_i56 = 0; c1_i56 < 256; c1_i56++) {
            c1_myarr256[c1_i56] = c1_tt[c1_i56];
          }

          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
          _SFD_SYMBOL_SCOPE_POP();
          for (c1_i57 = 0; c1_i57 < 256; c1_i57++) {
            c1_b_poseBML[c1_i57] = c1_myarr256[c1_i57];
          }

          c1_updateDataWrittenToVector(chartInstance, 18U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 29U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i58 = 0; c1_i58 < 256; c1_i58++) {
            c1_e_u[c1_i58] = c1_b_poseBML[c1_i58];
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
          c1_encStr2Arr(chartInstance, c1_dv11);
          for (c1_i59 = 0; c1_i59 < 256; c1_i59++) {
            c1_b_poseBML[c1_i59] = c1_dv11[c1_i59];
          }

          c1_updateDataWrittenToVector(chartInstance, 18U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 18U, 29U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i60 = 0; c1_i60 < 256; c1_i60++) {
            c1_f_u[c1_i60] = c1_b_poseBML[c1_i60];
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
      for (c1_i61 = 0; c1_i61 < 256; c1_i61++) {
        c1_b_arg[c1_i61] = c1_b_poseBML[c1_i61];
      }

      for (c1_i62 = 0; c1_i62 < 256; c1_i62++) {
        _SFD_DATA_RANGE_CHECK(c1_b_arg[c1_i62], 27U);
      }

      _SFD_SET_DATA_VALUE_PTR(27U, c1_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_b_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
      for (c1_i63 = 0; c1_i63 < 256; c1_i63++) {
        (*c1_e_arg)[c1_i63] = c1_b_arg[c1_i63];
      }

      for (c1_i64 = 0; c1_i64 < 256; c1_i64++) {
        _SFD_DATA_RANGE_CHECK((*c1_e_arg)[c1_i64], 27U);
      }

      sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(27U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_yd_debug_family_names,
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
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_statePoseFingersCLose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_statePoseFingersCLose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_gc_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_set_pose(chartInstance, 0, 1.0);
        _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
        c1_handPoseSB(chartInstance, 1.0, c1_dv13);
        for (c1_i65 = 0; c1_i65 < 256; c1_i65++) {
          c1_c_arg[c1_i65] = c1_dv13[c1_i65];
        }

        for (c1_i66 = 0; c1_i66 < 256; c1_i66++) {
          _SFD_DATA_RANGE_CHECK(c1_c_arg[c1_i66], 26U);
        }

        _SFD_SET_DATA_VALUE_PTR(26U, c1_c_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_c_arg, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c1_sfEvent);
        for (c1_i67 = 0; c1_i67 < 256; c1_i67++) {
          (*c1_d_arg)[c1_i67] = c1_c_arg[c1_i67];
        }

        for (c1_i68 = 0; c1_i68 < 256; c1_i68++) {
          _SFD_DATA_RANGE_CHECK((*c1_d_arg)[c1_i68], 26U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(26U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U,
                     chartInstance->c1_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c1_sfEvent);
}

static void c1_statePoseRock
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ce_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(30, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(30, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(30, 0, 0, true);
      CV_EML_IF(30, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(30, 0, 0, false);
    CV_EML_IF(30, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseRock = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ic_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c1_sfEvent);
}

static void c1_statePoseFingersCLose
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T c1_dv14[256];
  int32_T c1_i69;
  int32_T c1_i70;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i71;
  int32_T c1_i72;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i73;
  int32_T c1_i74;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i75;
  real_T c1_arg[256];
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_statePoseFingersCLose = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_statePoseScissors;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_statePoseScissors = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_jc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  chartInstance->c1_s = c1_c_randi(chartInstance);
  c1_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_s, 21U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 14U, 21U);
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
    c1_c_encStr2Arr(chartInstance, c1_dv14);
    for (c1_i69 = 0; c1_i69 < 256; c1_i69++) {
      c1_poseBML[c1_i69] = c1_dv14[c1_i69];
    }

    c1_updateDataWrittenToVector(chartInstance, 20U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 20U, 33U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i70 = 0; c1_i70 < 256; c1_i70++) {
      c1_u[c1_i70] = c1_poseBML[c1_i70];
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
      c1_b_encStr2Arr(chartInstance, c1_dv14);
      for (c1_i71 = 0; c1_i71 < 256; c1_i71++) {
        c1_poseBML[c1_i71] = c1_dv14[c1_i71];
      }

      c1_updateDataWrittenToVector(chartInstance, 20U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 20U, 33U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i72 = 0; c1_i72 < 256; c1_i72++) {
        c1_b_u[c1_i72] = c1_poseBML[c1_i72];
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
      c1_c_encStr2Arr(chartInstance, c1_dv14);
      for (c1_i73 = 0; c1_i73 < 256; c1_i73++) {
        c1_poseBML[c1_i73] = c1_dv14[c1_i73];
      }

      c1_updateDataWrittenToVector(chartInstance, 20U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 20U, 33U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i74 = 0; c1_i74 < 256; c1_i74++) {
        c1_c_u[c1_i74] = c1_poseBML[c1_i74];
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
  for (c1_i75 = 0; c1_i75 < 256; c1_i75++) {
    c1_arg[c1_i75] = c1_poseBML[c1_i75];
  }

  for (c1_i76 = 0; c1_i76 < 256; c1_i76++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i76], 27U);
  }

  _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i77 = 0; c1_i77 < 256; c1_i77++) {
    (*c1_b_arg)[c1_i77] = c1_arg[c1_i77];
  }

  for (c1_i78 = 0; c1_i78 < 256; c1_i78++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i78], 27U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(27U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c1_sfEvent);
}

static void c1_statePosePaper
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_de_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(29, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(29, 0, 1, chartInstance->c1_uHand != 3.0)) {
      CV_EML_MCDC(29, 0, 0, true);
      CV_EML_IF(29, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 6U, 7U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(29, 0, 0, false);
    CV_EML_IF(29, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePosePaper = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ic_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c1_sfEvent);
}

static void c1_stateReadUserHand
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T c1_dv15[256];
  int32_T c1_i79;
  real_T c1_arg[256];
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
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
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  c1_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ee_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ic_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_he_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 7U, 8U);
    c1_b_out = CV_EML_IF(25, 0, 0, chartInstance->c1_bHand == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateReadUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_statePoseReturnFinger;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_statePoseReturnFinger = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_yc_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 1.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
      c1_handPoseSB(chartInstance, 2.0, c1_dv15);
      for (c1_i79 = 0; c1_i79 < 256; c1_i79++) {
        c1_arg[c1_i79] = c1_dv15[c1_i79];
      }

      for (c1_i80 = 0; c1_i80 < 256; c1_i80++) {
        _SFD_DATA_RANGE_CHECK(c1_arg[c1_i80], 26U);
      }

      _SFD_SET_DATA_VALUE_PTR(26U, c1_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c1_sfEvent);
      for (c1_i81 = 0; c1_i81 < 256; c1_i81++) {
        (*c1_b_arg)[c1_i81] = c1_arg[c1_i81];
      }

      for (c1_i82 = 0; c1_i82 < 256; c1_i82++) {
        _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i82], 26U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(26U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ge_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_c_sf_marshallOut,
        c1_c_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
      c1_c_out = CV_EML_IF(32, 0, 0, chartInstance->c1_wristRotate == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_statePoseReturnWrist;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_statePoseReturnWrist = 1U;
        c1_enter_atomic_statePoseReturnWrist(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateReadUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_stateShowHands = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_kc_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        c1_set_pose(chartInstance, 0, 1.0);
        _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c1_sfEvent);
}

static void c1_statePoseScissors
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_fe_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ic_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    chartInstance->c1_uHand = *c1_inputUser;
    c1_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_uHand, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c1_sfEvent);
}

static void c1_stateShowHands
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_stateGame = c1_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ad_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_stateBoredPose1
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T c1_dv16[256];
  int32_T c1_i83;
  int32_T c1_i84;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  real_T c1_dv17[256];
  int32_T c1_i85;
  int32_T c1_i86;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  real_T c1_dv18[256];
  int32_T c1_i87;
  int32_T c1_i88;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  real_T c1_dv19[256];
  int32_T c1_i89;
  int32_T c1_i90;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  real_T c1_dv20[256];
  int32_T c1_i91;
  int32_T c1_i92;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  real_T c1_dv21[256];
  int32_T c1_i93;
  int32_T c1_i94;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  real_T c1_dv22[256];
  int32_T c1_i95;
  int32_T c1_i96;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  real_T c1_dv23[256];
  int32_T c1_i97;
  int32_T c1_i98;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  real_T c1_dv24[256];
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_i_u[256];
  const mxArray *c1_i_y = NULL;
  real_T c1_dv25[256];
  int32_T c1_i101;
  int32_T c1_i102;
  real_T c1_j_u[256];
  const mxArray *c1_j_y = NULL;
  real_T c1_dv26[256];
  int32_T c1_i103;
  int32_T c1_i104;
  real_T c1_k_u[256];
  const mxArray *c1_k_y = NULL;
  real_T c1_dv27[256];
  int32_T c1_i105;
  int32_T c1_i106;
  real_T c1_l_u[256];
  const mxArray *c1_l_y = NULL;
  real_T c1_dv28[256];
  int32_T c1_i107;
  int32_T c1_i108;
  real_T c1_m_u[256];
  const mxArray *c1_m_y = NULL;
  real_T c1_dv29[256];
  int32_T c1_i109;
  int32_T c1_i110;
  real_T c1_n_u[256];
  const mxArray *c1_n_y = NULL;
  real_T c1_dv30[256];
  int32_T c1_i111;
  int32_T c1_i112;
  real_T c1_o_u[256];
  const mxArray *c1_o_y = NULL;
  real_T c1_dv31[256];
  int32_T c1_i113;
  int32_T c1_i114;
  real_T c1_p_u[256];
  const mxArray *c1_p_y = NULL;
  real_T c1_dv32[256];
  int32_T c1_i115;
  int32_T c1_i116;
  real_T c1_q_u[256];
  const mxArray *c1_q_y = NULL;
  real_T c1_dv33[256];
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_r_u[256];
  const mxArray *c1_r_y = NULL;
  real_T c1_dv34[256];
  int32_T c1_i119;
  int32_T c1_i120;
  real_T c1_s_u[256];
  const mxArray *c1_s_y = NULL;
  int32_T c1_i121;
  real_T c1_b_poseBML[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_lc_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_bmlID = c1_d_randi(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c1_xc_debug_family_names,
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
    c1_ib_encStr2Arr(chartInstance, c1_dv16);
    for (c1_i83 = 0; c1_i83 < 256; c1_i83++) {
      c1_poseBML[c1_i83] = c1_dv16[c1_i83];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i84 = 0; c1_i84 < 256; c1_i84++) {
      c1_u[c1_i84] = c1_poseBML[c1_i84];
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
      c1_jb_encStr2Arr(chartInstance, c1_dv17);
      for (c1_i85 = 0; c1_i85 < 256; c1_i85++) {
        c1_poseBML[c1_i85] = c1_dv17[c1_i85];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i86 = 0; c1_i86 < 256; c1_i86++) {
        c1_b_u[c1_i86] = c1_poseBML[c1_i86];
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
        c1_kb_encStr2Arr(chartInstance, c1_dv18);
        for (c1_i87 = 0; c1_i87 < 256; c1_i87++) {
          c1_poseBML[c1_i87] = c1_dv18[c1_i87];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i88 = 0; c1_i88 < 256; c1_i88++) {
          c1_c_u[c1_i88] = c1_poseBML[c1_i88];
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
          c1_lb_encStr2Arr(chartInstance, c1_dv19);
          for (c1_i89 = 0; c1_i89 < 256; c1_i89++) {
            c1_poseBML[c1_i89] = c1_dv19[c1_i89];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i90 = 0; c1_i90 < 256; c1_i90++) {
            c1_d_u[c1_i90] = c1_poseBML[c1_i90];
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
            c1_mb_encStr2Arr(chartInstance, c1_dv20);
            for (c1_i91 = 0; c1_i91 < 256; c1_i91++) {
              c1_poseBML[c1_i91] = c1_dv20[c1_i91];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c1_i92 = 0; c1_i92 < 256; c1_i92++) {
              c1_e_u[c1_i92] = c1_poseBML[c1_i92];
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
              c1_nb_encStr2Arr(chartInstance, c1_dv21);
              for (c1_i93 = 0; c1_i93 < 256; c1_i93++) {
                c1_poseBML[c1_i93] = c1_dv21[c1_i93];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c1_i94 = 0; c1_i94 < 256; c1_i94++) {
                c1_f_u[c1_i94] = c1_poseBML[c1_i94];
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
                c1_kb_encStr2Arr(chartInstance, c1_dv22);
                for (c1_i95 = 0; c1_i95 < 256; c1_i95++) {
                  c1_poseBML[c1_i95] = c1_dv22[c1_i95];
                }

                sf_mex_printf("%s =\\n", "poseBML");
                for (c1_i96 = 0; c1_i96 < 256; c1_i96++) {
                  c1_g_u[c1_i96] = c1_poseBML[c1_i96];
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
                  c1_mb_encStr2Arr(chartInstance, c1_dv23);
                  for (c1_i97 = 0; c1_i97 < 256; c1_i97++) {
                    c1_poseBML[c1_i97] = c1_dv23[c1_i97];
                  }

                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i98 = 0; c1_i98 < 256; c1_i98++) {
                    c1_h_u[c1_i98] = c1_poseBML[c1_i98];
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
                    c1_kb_encStr2Arr(chartInstance, c1_dv24);
                    for (c1_i99 = 0; c1_i99 < 256; c1_i99++) {
                      c1_poseBML[c1_i99] = c1_dv24[c1_i99];
                    }

                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c1_i100 = 0; c1_i100 < 256; c1_i100++) {
                      c1_i_u[c1_i100] = c1_poseBML[c1_i100];
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
                      c1_ob_encStr2Arr(chartInstance, c1_dv25);
                      for (c1_i101 = 0; c1_i101 < 256; c1_i101++) {
                        c1_poseBML[c1_i101] = c1_dv25[c1_i101];
                      }

                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c1_i102 = 0; c1_i102 < 256; c1_i102++) {
                        c1_j_u[c1_i102] = c1_poseBML[c1_i102];
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
                        c1_nb_encStr2Arr(chartInstance, c1_dv26);
                        for (c1_i103 = 0; c1_i103 < 256; c1_i103++) {
                          c1_poseBML[c1_i103] = c1_dv26[c1_i103];
                        }

                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c1_i104 = 0; c1_i104 < 256; c1_i104++) {
                          c1_k_u[c1_i104] = c1_poseBML[c1_i104];
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
                          c1_pb_encStr2Arr(chartInstance, c1_dv27);
                          for (c1_i105 = 0; c1_i105 < 256; c1_i105++) {
                            c1_poseBML[c1_i105] = c1_dv27[c1_i105];
                          }

                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c1_i106 = 0; c1_i106 < 256; c1_i106++) {
                            c1_l_u[c1_i106] = c1_poseBML[c1_i106];
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
                            c1_pb_encStr2Arr(chartInstance, c1_dv28);
                            for (c1_i107 = 0; c1_i107 < 256; c1_i107++) {
                              c1_poseBML[c1_i107] = c1_dv28[c1_i107];
                            }

                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c1_i108 = 0; c1_i108 < 256; c1_i108++) {
                              c1_m_u[c1_i108] = c1_poseBML[c1_i108];
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
                              c1_qb_encStr2Arr(chartInstance, c1_dv29);
                              for (c1_i109 = 0; c1_i109 < 256; c1_i109++) {
                                c1_poseBML[c1_i109] = c1_dv29[c1_i109];
                              }

                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c1_i110 = 0; c1_i110 < 256; c1_i110++) {
                                c1_n_u[c1_i110] = c1_poseBML[c1_i110];
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
                                c1_rb_encStr2Arr(chartInstance, c1_dv30);
                                for (c1_i111 = 0; c1_i111 < 256; c1_i111++) {
                                  c1_poseBML[c1_i111] = c1_dv30[c1_i111];
                                }

                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c1_i112 = 0; c1_i112 < 256; c1_i112++) {
                                  c1_o_u[c1_i112] = c1_poseBML[c1_i112];
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
                                  c1_mb_encStr2Arr(chartInstance, c1_dv31);
                                  for (c1_i113 = 0; c1_i113 < 256; c1_i113++) {
                                    c1_poseBML[c1_i113] = c1_dv31[c1_i113];
                                  }

                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c1_i114 = 0; c1_i114 < 256; c1_i114++) {
                                    c1_p_u[c1_i114] = c1_poseBML[c1_i114];
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
                                    c1_pb_encStr2Arr(chartInstance, c1_dv32);
                                    for (c1_i115 = 0; c1_i115 < 256; c1_i115++)
                                    {
                                      c1_poseBML[c1_i115] = c1_dv32[c1_i115];
                                    }

                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c1_i116 = 0; c1_i116 < 256; c1_i116++)
                                    {
                                      c1_q_u[c1_i116] = c1_poseBML[c1_i116];
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
                                      c1_sb_encStr2Arr(chartInstance, c1_dv33);
                                      for (c1_i117 = 0; c1_i117 < 256; c1_i117++)
                                      {
                                        c1_poseBML[c1_i117] = c1_dv33[c1_i117];
                                      }

                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c1_i118 = 0; c1_i118 < 256; c1_i118++)
                                      {
                                        c1_r_u[c1_i118] = c1_poseBML[c1_i118];
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
                                      c1_kb_encStr2Arr(chartInstance, c1_dv34);
                                      for (c1_i119 = 0; c1_i119 < 256; c1_i119++)
                                      {
                                        c1_poseBML[c1_i119] = c1_dv34[c1_i119];
                                      }

                                      sf_mex_printf("%s =\\n", "poseBML");
                                      for (c1_i120 = 0; c1_i120 < 256; c1_i120++)
                                      {
                                        c1_s_u[c1_i120] = c1_poseBML[c1_i120];
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
  for (c1_i121 = 0; c1_i121 < 256; c1_i121++) {
    c1_b_poseBML[c1_i121] = c1_poseBML[c1_i121];
  }

  c1_sendBML(chartInstance, c1_b_poseBML);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_statePoseReturnFinger
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ie_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 15U, 23U);
  c1_out = CV_EML_IF(33, 0, 0, chartInstance->c1_wristRotate == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseReturnWrist;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnWrist = 1U;
    c1_enter_atomic_statePoseReturnWrist(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_statePoseReturnFinger = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_kc_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
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

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c1_sfEvent);
}

static void c1_enter_atomic_statePoseReturnWrist
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_dv35[256];
  int32_T c1_i122;
  real_T c1_arg[256];
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_bd_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  c1_set_pose(chartInstance, 0, 1.0);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
  c1_handPoseSB(chartInstance, 6.0, c1_dv35);
  for (c1_i122 = 0; c1_i122 < 256; c1_i122++) {
    c1_arg[c1_i122] = c1_dv35[c1_i122];
  }

  for (c1_i123 = 0; c1_i123 < 256; c1_i123++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i123], 26U);
  }

  _SFD_SET_DATA_VALUE_PTR(26U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  for (c1_i124 = 0; c1_i124 < 256; c1_i124++) {
    (*c1_b_arg)[c1_i124] = c1_arg[c1_i124];
  }

  for (c1_i125 = 0; c1_i125 < 256; c1_i125++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i125], 26U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(26U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_stateUserWin(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv36[2];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ne_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_dv36[0] = 0.0;
    c1_dv36[1] = c1_get_bored(chartInstance, 0);
    chartInstance->c1_smileYN = c1_randi(chartInstance, c1_dv36);
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    c1_set_pose(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c1_sfEvent);
}

static void c1_stateNoWin(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv37[2];
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_me_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(8, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 5));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateNoWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateRandom1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateRandom1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_fd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_dv37[0] = 0.0;
    c1_dv37[1] = c1_get_bored(chartInstance, 0);
    chartInstance->c1_smileYN = c1_randi(chartInstance, c1_dv37);
    c1_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_smileYN, 12U);
    c1_set_pose(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c1_sfEvent);
}

static void c1_stateRandom1(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_dv38[256];
  int32_T c1_i126;
  real_T c1_arg[256];
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i129;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_oe_debug_family_names,
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateHeadNeutral1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateHeadNeutral1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_gd_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_idlePose(chartInstance, 8.0, c1_dv38);
    for (c1_i126 = 0; c1_i126 < 256; c1_i126++) {
      c1_arg[c1_i126] = c1_dv38[c1_i126];
    }

    for (c1_i127 = 0; c1_i127 < 256; c1_i127++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i127], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i128 = 0; c1_i128 < 256; c1_i128++) {
      (*c1_b_arg)[c1_i128] = c1_arg[c1_i128];
    }

    for (c1_i129 = 0; c1_i129 < 256; c1_i129++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i129], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_pe_debug_family_names,
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
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateShowResult;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_stateShowResult = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_id_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U,
        c1_b_sf_marshallOut, c1_b_sf_marshallIn);
      c1_set_pose(chartInstance, 0, 0.0);
      _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c1_sfEvent);
}

static void c1_stateHeadNeutral1
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_dv39[256];
  int32_T c1_i130;
  real_T c1_arg[256];
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_qe_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  c1_out = CV_EML_IF(41, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                     (chartInstance->c1_temporalCounter_i1 >= 1));
  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateHeadNeutral1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_statePoseSmileWin;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_statePoseSmileWin = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_hd_debug_family_names,
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
    c1_idlePose(chartInstance, c1_hoistedGlobal, c1_dv39);
    for (c1_i130 = 0; c1_i130 < 256; c1_i130++) {
      c1_arg[c1_i130] = c1_dv39[c1_i130];
    }

    for (c1_i131 = 0; c1_i131 < 256; c1_i131++) {
      _SFD_DATA_RANGE_CHECK(c1_arg[c1_i131], 27U);
    }

    _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    for (c1_i132 = 0; c1_i132 < 256; c1_i132++) {
      (*c1_b_arg)[c1_i132] = c1_arg[c1_i132];
    }

    for (c1_i133 = 0; c1_i133 < 256; c1_i133++) {
      _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i133], 27U);
    }

    sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(27U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    c1_set_pose(chartInstance, 0, 1.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c1_sfEvent);
}

static void c1_statePoseSmileWin
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
    chartInstance->c1_temporalCounter_i1 = 0U;
    chartInstance->c1_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_id_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_set_pose(chartInstance, 0, 0.0);
    _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 17U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c1_sfEvent);
}

static void c1_stateShowResult
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
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
  real_T *c1_round;
  real_T *c1_gameState;
  boolean_T guard1 = false;
  c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_md_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(40, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                  (chartInstance->c1_temporalCounter_i1 >= 3))) {
    if (CV_EML_COND(40, 0, 1, *c1_round == 3.0)) {
      CV_EML_MCDC(40, 0, 0, true);
      CV_EML_IF(40, 0, 0, true);
      c1_out = true;
    } else {
      guard1 = true;
    }
  } else {
    c1_errorIfDataNotWrittenToFcn(chartInstance, 17U, 25U);
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(40, 0, 0, false);
    CV_EML_IF(40, 0, 0, false);
    c1_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_stateShowResult = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_stateGame = c1_IN_gameOver;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_gameOver = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_ab_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    *c1_gameState = 3.0;
    c1_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
    c1_set_bored(chartInstance, 0, c1_get_bored(chartInstance, 0) - 2.0);
    _SFD_DATA_RANGE_CHECK(c1_get_bored(chartInstance, 0), 13U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_ld_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_c_sf_marshallOut,
      c1_c_sf_marshallIn);
    c1_b_out = CV_EML_IF(39, 0, 0, (chartInstance->c1_sfEvent == c1_event_secs) &&
                         (chartInstance->c1_temporalCounter_i1 >= 3));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateShowResult = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_stateGame = c1_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_stateReady = 1U;
      c1_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                   chartInstance->c1_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c1_sfEvent);
}

static void c1_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i134;
  static char_T c1_cv1[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i135;
  static real_T c1_dv40[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i136;
  int32_T c1_i137;
  int32_T c1_i138;
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
  for (c1_i134 = 0; c1_i134 < 94; c1_i134++) {
    c1_mystr[c1_i134] = c1_cv1[c1_i134];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i135 = 0; c1_i135 < 94; c1_i135++) {
    c1_arr[c1_i135] = c1_dv40[c1_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i136 = 0; c1_i136 < 256; c1_i136++) {
    c1_tt[c1_i136] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i137 = 0; c1_i137 < 94; c1_i137++) {
    c1_tt[c1_i137] = c1_arr[c1_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i138 = 0; c1_i138 < 256; c1_i138++) {
    c1_myarr256[c1_i138] = c1_tt[c1_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_b_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i139;
  static char_T c1_cv2[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i140;
  static real_T c1_dv41[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i141;
  int32_T c1_i142;
  int32_T c1_i143;
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
  for (c1_i139 = 0; c1_i139 < 88; c1_i139++) {
    c1_mystr[c1_i139] = c1_cv2[c1_i139];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i140 = 0; c1_i140 < 88; c1_i140++) {
    c1_arr[c1_i140] = c1_dv41[c1_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i141 = 0; c1_i141 < 256; c1_i141++) {
    c1_tt[c1_i141] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i142 = 0; c1_i142 < 88; c1_i142++) {
    c1_tt[c1_i142] = c1_arr[c1_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i143 = 0; c1_i143 < 256; c1_i143++) {
    c1_myarr256[c1_i143] = c1_tt[c1_i143];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_c_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i144;
  static char_T c1_cv3[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c1_i145;
  static real_T c1_dv42[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i146;
  int32_T c1_i147;
  int32_T c1_i148;
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
  for (c1_i144 = 0; c1_i144 < 86; c1_i144++) {
    c1_mystr[c1_i144] = c1_cv3[c1_i144];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i145 = 0; c1_i145 < 86; c1_i145++) {
    c1_arr[c1_i145] = c1_dv42[c1_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i146 = 0; c1_i146 < 256; c1_i146++) {
    c1_tt[c1_i146] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i147 = 0; c1_i147 < 86; c1_i147++) {
    c1_tt[c1_i147] = c1_arr[c1_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i148 = 0; c1_i148 < 256; c1_i148++) {
    c1_myarr256[c1_i148] = c1_tt[c1_i148];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_d_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i149;
  static char_T c1_cv4[161] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c1_i150;
  static real_T c1_dv43[161] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c1_i151;
  int32_T c1_i152;
  int32_T c1_i153;
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
  for (c1_i149 = 0; c1_i149 < 161; c1_i149++) {
    c1_mystr[c1_i149] = c1_cv4[c1_i149];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i150 = 0; c1_i150 < 161; c1_i150++) {
    c1_arr[c1_i150] = c1_dv43[c1_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 161.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i151 = 0; c1_i151 < 256; c1_i151++) {
    c1_tt[c1_i151] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i152 = 0; c1_i152 < 161; c1_i152++) {
    c1_tt[c1_i152] = c1_arr[c1_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i153 = 0; c1_i153 < 256; c1_i153++) {
    c1_myarr256[c1_i153] = c1_tt[c1_i153];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_e_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[157];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[157];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i154;
  static char_T c1_cv5[157] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
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

  int32_T c1_i155;
  static real_T c1_dv44[157] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
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

  int32_T c1_i156;
  int32_T c1_i157;
  int32_T c1_i158;
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
  for (c1_i154 = 0; c1_i154 < 157; c1_i154++) {
    c1_mystr[c1_i154] = c1_cv5[c1_i154];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i155 = 0; c1_i155 < 157; c1_i155++) {
    c1_arr[c1_i155] = c1_dv44[c1_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 157.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i156 = 0; c1_i156 < 256; c1_i156++) {
    c1_tt[c1_i156] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i157 = 0; c1_i157 < 157; c1_i157++) {
    c1_tt[c1_i157] = c1_arr[c1_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i158 = 0; c1_i158 < 256; c1_i158++) {
    c1_myarr256[c1_i158] = c1_tt[c1_i158];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_f_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i159;
  static char_T c1_cv6[92] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '0', '5', ')', ')', ';' };

  int32_T c1_i160;
  static real_T c1_dv45[92] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 46.0, 48.0, 53.0, 41.0, 41.0, 59.0 };

  int32_T c1_i161;
  int32_T c1_i162;
  int32_T c1_i163;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_k_debug_family_names,
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
  for (c1_i159 = 0; c1_i159 < 92; c1_i159++) {
    c1_mystr[c1_i159] = c1_cv6[c1_i159];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i160 = 0; c1_i160 < 92; c1_i160++) {
    c1_arr[c1_i160] = c1_dv45[c1_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i161 = 0; c1_i161 < 256; c1_i161++) {
    c1_tt[c1_i161] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i162 = 0; c1_i162 < 92; c1_i162++) {
    c1_tt[c1_i162] = c1_arr[c1_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i163 = 0; c1_i163 < 256; c1_i163++) {
    c1_myarr256[c1_i163] = c1_tt[c1_i163];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_g_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[89];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[89];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i164;
  static char_T c1_cv7[89] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', ')', ')', ';' };

  int32_T c1_i165;
  static real_T c1_dv46[89] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i166;
  int32_T c1_i167;
  int32_T c1_i168;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_l_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i164 = 0; c1_i164 < 89; c1_i164++) {
    c1_mystr[c1_i164] = c1_cv7[c1_i164];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i165 = 0; c1_i165 < 89; c1_i165++) {
    c1_arr[c1_i165] = c1_dv46[c1_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 89.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i166 = 0; c1_i166 < 256; c1_i166++) {
    c1_tt[c1_i166] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i167 = 0; c1_i167 < 89; c1_i167++) {
    c1_tt[c1_i167] = c1_arr[c1_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i168 = 0; c1_i168 < 256; c1_i168++) {
    c1_myarr256[c1_i168] = c1_tt[c1_i168];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_h_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[78];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[78];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i169;
  static char_T c1_cv8[78] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w', 'r', 'i',
    's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't',
    'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',',
    '0', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c1_i170;
  static real_T c1_dv47[78] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0, 105.0,
    115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i171;
  int32_T c1_i172;
  int32_T c1_i173;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_n_debug_family_names,
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
  for (c1_i169 = 0; c1_i169 < 78; c1_i169++) {
    c1_mystr[c1_i169] = c1_cv8[c1_i169];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i170 = 0; c1_i170 < 78; c1_i170++) {
    c1_arr[c1_i170] = c1_dv47[c1_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 78.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i171 = 0; c1_i171 < 256; c1_i171++) {
    c1_tt[c1_i171] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i172 = 0; c1_i172 < 78; c1_i172++) {
    c1_tt[c1_i172] = c1_arr[c1_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i173 = 0; c1_i173 < 256; c1_i173++) {
    c1_myarr256[c1_i173] = c1_tt[c1_i173];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_i_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i174;
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

  int32_T c1_i175;
  static real_T c1_dv48[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i176;
  int32_T c1_i177;
  int32_T c1_i178;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_p_debug_family_names,
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
  for (c1_i174 = 0; c1_i174 < 147; c1_i174++) {
    c1_mystr[c1_i174] = c1_cv9[c1_i174];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i175 = 0; c1_i175 < 147; c1_i175++) {
    c1_arr[c1_i175] = c1_dv48[c1_i175];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i176 = 0; c1_i176 < 256; c1_i176++) {
    c1_tt[c1_i176] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i177 = 0; c1_i177 < 147; c1_i177++) {
    c1_tt[c1_i177] = c1_arr[c1_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i178 = 0; c1_i178 < 256; c1_i178++) {
    c1_myarr256[c1_i178] = c1_tt[c1_i178];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_j_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i179;
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

  int32_T c1_i180;
  static real_T c1_dv49[164] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i181;
  int32_T c1_i182;
  int32_T c1_i183;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_q_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_maxarrsize, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  for (c1_i179 = 0; c1_i179 < 164; c1_i179++) {
    c1_mystr[c1_i179] = c1_cv10[c1_i179];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i180 = 0; c1_i180 < 164; c1_i180++) {
    c1_arr[c1_i180] = c1_dv49[c1_i180];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 164.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i181 = 0; c1_i181 < 256; c1_i181++) {
    c1_tt[c1_i181] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i182 = 0; c1_i182 < 164; c1_i182++) {
    c1_tt[c1_i182] = c1_arr[c1_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i183 = 0; c1_i183 < 256; c1_i183++) {
    c1_myarr256[c1_i183] = c1_tt[c1_i183];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_k_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i184;
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

  int32_T c1_i185;
  static real_T c1_dv50[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i186;
  int32_T c1_i187;
  int32_T c1_i188;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_s_debug_family_names,
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
  for (c1_i184 = 0; c1_i184 < 223; c1_i184++) {
    c1_mystr[c1_i184] = c1_cv11[c1_i184];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i185 = 0; c1_i185 < 223; c1_i185++) {
    c1_arr[c1_i185] = c1_dv50[c1_i185];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i186 = 0; c1_i186 < 256; c1_i186++) {
    c1_tt[c1_i186] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i187 = 0; c1_i187 < 223; c1_i187++) {
    c1_tt[c1_i187] = c1_arr[c1_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i188 = 0; c1_i188 < 256; c1_i188++) {
    c1_myarr256[c1_i188] = c1_tt[c1_i188];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_l_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i189;
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

  int32_T c1_i190;
  static real_T c1_dv51[223] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i191;
  int32_T c1_i192;
  int32_T c1_i193;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_t_debug_family_names,
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
  for (c1_i189 = 0; c1_i189 < 223; c1_i189++) {
    c1_mystr[c1_i189] = c1_cv12[c1_i189];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i190 = 0; c1_i190 < 223; c1_i190++) {
    c1_arr[c1_i190] = c1_dv51[c1_i190];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 223.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i191 = 0; c1_i191 < 256; c1_i191++) {
    c1_tt[c1_i191] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i192 = 0; c1_i192 < 223; c1_i192++) {
    c1_tt[c1_i192] = c1_arr[c1_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i193 = 0; c1_i193 < 256; c1_i193++) {
    c1_myarr256[c1_i193] = c1_tt[c1_i193];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_m_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i194;
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

  int32_T c1_i195;
  static real_T c1_dv52[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i196;
  int32_T c1_i197;
  int32_T c1_i198;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_u_debug_family_names,
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
  for (c1_i194 = 0; c1_i194 < 225; c1_i194++) {
    c1_mystr[c1_i194] = c1_cv13[c1_i194];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i195 = 0; c1_i195 < 225; c1_i195++) {
    c1_arr[c1_i195] = c1_dv52[c1_i195];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i196 = 0; c1_i196 < 256; c1_i196++) {
    c1_tt[c1_i196] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i197 = 0; c1_i197 < 225; c1_i197++) {
    c1_tt[c1_i197] = c1_arr[c1_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i198 = 0; c1_i198 < 256; c1_i198++) {
    c1_myarr256[c1_i198] = c1_tt[c1_i198];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_n_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i199;
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

  int32_T c1_i200;
  static real_T c1_dv53[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i201;
  int32_T c1_i202;
  int32_T c1_i203;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_v_debug_family_names,
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
  for (c1_i199 = 0; c1_i199 < 225; c1_i199++) {
    c1_mystr[c1_i199] = c1_cv14[c1_i199];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i200 = 0; c1_i200 < 225; c1_i200++) {
    c1_arr[c1_i200] = c1_dv53[c1_i200];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i201 = 0; c1_i201 < 256; c1_i201++) {
    c1_tt[c1_i201] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i202 = 0; c1_i202 < 225; c1_i202++) {
    c1_tt[c1_i202] = c1_arr[c1_i202];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i203 = 0; c1_i203 < 256; c1_i203++) {
    c1_myarr256[c1_i203] = c1_tt[c1_i203];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_o_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i204;
  static char_T c1_cv15[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i205;
  static real_T c1_dv54[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i206;
  int32_T c1_i207;
  int32_T c1_i208;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_w_debug_family_names,
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
  for (c1_i204 = 0; c1_i204 < 87; c1_i204++) {
    c1_mystr[c1_i204] = c1_cv15[c1_i204];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i205 = 0; c1_i205 < 87; c1_i205++) {
    c1_arr[c1_i205] = c1_dv54[c1_i205];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i206 = 0; c1_i206 < 256; c1_i206++) {
    c1_tt[c1_i206] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i207 = 0; c1_i207 < 87; c1_i207++) {
    c1_tt[c1_i207] = c1_arr[c1_i207];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i208 = 0; c1_i208 < 256; c1_i208++) {
    c1_myarr256[c1_i208] = c1_tt[c1_i208];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_lowhigh[2])
{
  real_T c1_b_r;
  real_T c1_low;
  real_T c1_high;
  int32_T c1_i209;
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
    for (c1_i209 = 0; c1_i209 < 26; c1_i209++) {
      c1_u[c1_i209] = c1_cv16[c1_i209];
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

static real_T c1_rand(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
                      *chartInstance)
{
  return c1_eml_rand(chartInstance);
}

static real_T c1_eml_rand(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
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
  int32_T c1_i210;
  uint32_T c1_icng;
  uint32_T c1_jsr;
  uint32_T c1_u1;
  uint32_T c1_u2;
  uint32_T c1_ui;
  uint32_T c1_b_ui;
  real_T c1_d_r;
  real_T c1_d1;
  uint32_T c1_uv2[625];
  int32_T c1_i211;
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
      for (c1_i210 = 0; c1_i210 < 2; c1_i210++) {
        chartInstance->c1_b_state[c1_i210] = 362436069U + 158852560U * (uint32_T)
          c1_i210;
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
      for (c1_i211 = 0; c1_i211 < 625; c1_i211++) {
        chartInstance->c1_c_state[c1_i211] = c1_uv2[c1_i211];
      }

      chartInstance->c1_c_state_not_empty = true;
    }

    c1_d2 = c1_c_eml_rand_mt19937ar(chartInstance, chartInstance->c1_c_state);
    c1_b_r = c1_d2;
  }

  return c1_b_r;
}

static void c1_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625])
{
  real_T c1_d3;
  int32_T c1_i212;
  c1_d3 = 5489.0;
  for (c1_i212 = 0; c1_i212 < 625; c1_i212++) {
    c1_d_state[c1_i212] = 0U;
  }

  c1_b_twister_state_vector(chartInstance, c1_d_state, c1_d3);
}

static void c1_twister_state_vector
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_mt[625], real_T c1_seed, uint32_T c1_b_mt[625])
{
  int32_T c1_i213;
  for (c1_i213 = 0; c1_i213 < 625; c1_i213++) {
    c1_b_mt[c1_i213] = c1_mt[c1_i213];
  }

  c1_b_twister_state_vector(chartInstance, c1_b_mt, c1_seed);
}

static void c1_b_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625], uint32_T c1_e_state[625], real_T *c1_b_r)
{
  int32_T c1_i214;
  for (c1_i214 = 0; c1_i214 < 625; c1_i214++) {
    c1_e_state[c1_i214] = c1_d_state[c1_i214];
  }

  *c1_b_r = c1_c_eml_rand_mt19937ar(chartInstance, c1_e_state);
}

static void c1_eml_error(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance)
{
  int32_T c1_i215;
  static char_T c1_cv17[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c1_u[37];
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  for (c1_i215 = 0; c1_i215 < 37; c1_i215++) {
    c1_u[c1_i215] = c1_cv17[c1_i215];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static real_T c1_b_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
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

static void c1_p_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i216;
  static char_T c1_cv18[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i217;
  static real_T c1_dv55[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i218;
  int32_T c1_i219;
  int32_T c1_i220;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_jb_debug_family_names,
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
  for (c1_i216 = 0; c1_i216 < 118; c1_i216++) {
    c1_mystr[c1_i216] = c1_cv18[c1_i216];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i217 = 0; c1_i217 < 118; c1_i217++) {
    c1_arr[c1_i217] = c1_dv55[c1_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i218 = 0; c1_i218 < 256; c1_i218++) {
    c1_tt[c1_i218] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i219 = 0; c1_i219 < 118; c1_i219++) {
    c1_tt[c1_i219] = c1_arr[c1_i219];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i220 = 0; c1_i220 < 256; c1_i220++) {
    c1_myarr256[c1_i220] = c1_tt[c1_i220];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_q_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i221;
  static char_T c1_cv19[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c1_i222;
  static real_T c1_dv56[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i223;
  int32_T c1_i224;
  int32_T c1_i225;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_kb_debug_family_names,
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
  for (c1_i221 = 0; c1_i221 < 119; c1_i221++) {
    c1_mystr[c1_i221] = c1_cv19[c1_i221];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i222 = 0; c1_i222 < 119; c1_i222++) {
    c1_arr[c1_i222] = c1_dv56[c1_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i223 = 0; c1_i223 < 256; c1_i223++) {
    c1_tt[c1_i223] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i224 = 0; c1_i224 < 119; c1_i224++) {
    c1_tt[c1_i224] = c1_arr[c1_i224];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i225 = 0; c1_i225 < 256; c1_i225++) {
    c1_myarr256[c1_i225] = c1_tt[c1_i225];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_r_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i226;
  static char_T c1_cv20[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i227;
  static real_T c1_dv57[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i228;
  int32_T c1_i229;
  int32_T c1_i230;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_lb_debug_family_names,
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
  for (c1_i226 = 0; c1_i226 < 116; c1_i226++) {
    c1_mystr[c1_i226] = c1_cv20[c1_i226];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i227 = 0; c1_i227 < 116; c1_i227++) {
    c1_arr[c1_i227] = c1_dv57[c1_i227];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i228 = 0; c1_i228 < 256; c1_i228++) {
    c1_tt[c1_i228] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i229 = 0; c1_i229 < 116; c1_i229++) {
    c1_tt[c1_i229] = c1_arr[c1_i229];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i230 = 0; c1_i230 < 256; c1_i230++) {
    c1_myarr256[c1_i230] = c1_tt[c1_i230];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_s_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i231;
  static char_T c1_cv21[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i232;
  static real_T c1_dv58[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i233;
  int32_T c1_i234;
  int32_T c1_i235;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_mb_debug_family_names,
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
  for (c1_i231 = 0; c1_i231 < 118; c1_i231++) {
    c1_mystr[c1_i231] = c1_cv21[c1_i231];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i232 = 0; c1_i232 < 118; c1_i232++) {
    c1_arr[c1_i232] = c1_dv58[c1_i232];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i233 = 0; c1_i233 < 256; c1_i233++) {
    c1_tt[c1_i233] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i234 = 0; c1_i234 < 118; c1_i234++) {
    c1_tt[c1_i234] = c1_arr[c1_i234];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i235 = 0; c1_i235 < 256; c1_i235++) {
    c1_myarr256[c1_i235] = c1_tt[c1_i235];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_t_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i236;
  static char_T c1_cv22[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i237;
  static real_T c1_dv59[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i238;
  int32_T c1_i239;
  int32_T c1_i240;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_nb_debug_family_names,
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
  for (c1_i236 = 0; c1_i236 < 120; c1_i236++) {
    c1_mystr[c1_i236] = c1_cv22[c1_i236];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i237 = 0; c1_i237 < 120; c1_i237++) {
    c1_arr[c1_i237] = c1_dv59[c1_i237];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i238 = 0; c1_i238 < 256; c1_i238++) {
    c1_tt[c1_i238] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i239 = 0; c1_i239 < 120; c1_i239++) {
    c1_tt[c1_i239] = c1_arr[c1_i239];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i240 = 0; c1_i240 < 256; c1_i240++) {
    c1_myarr256[c1_i240] = c1_tt[c1_i240];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_u_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i241;
  static char_T c1_cv23[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i242;
  static real_T c1_dv60[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i243;
  int32_T c1_i244;
  int32_T c1_i245;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ob_debug_family_names,
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
  for (c1_i241 = 0; c1_i241 < 121; c1_i241++) {
    c1_mystr[c1_i241] = c1_cv23[c1_i241];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i242 = 0; c1_i242 < 121; c1_i242++) {
    c1_arr[c1_i242] = c1_dv60[c1_i242];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i243 = 0; c1_i243 < 256; c1_i243++) {
    c1_tt[c1_i243] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i244 = 0; c1_i244 < 121; c1_i244++) {
    c1_tt[c1_i244] = c1_arr[c1_i244];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i245 = 0; c1_i245 < 256; c1_i245++) {
    c1_myarr256[c1_i245] = c1_tt[c1_i245];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_v_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i246;
  static char_T c1_cv24[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i247;
  static real_T c1_dv61[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i248;
  int32_T c1_i249;
  int32_T c1_i250;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_pb_debug_family_names,
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
  for (c1_i246 = 0; c1_i246 < 122; c1_i246++) {
    c1_mystr[c1_i246] = c1_cv24[c1_i246];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i247 = 0; c1_i247 < 122; c1_i247++) {
    c1_arr[c1_i247] = c1_dv61[c1_i247];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i248 = 0; c1_i248 < 256; c1_i248++) {
    c1_tt[c1_i248] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i249 = 0; c1_i249 < 122; c1_i249++) {
    c1_tt[c1_i249] = c1_arr[c1_i249];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i250 = 0; c1_i250 < 256; c1_i250++) {
    c1_myarr256[c1_i250] = c1_tt[c1_i250];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_w_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i251;
  static char_T c1_cv25[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i252;
  static real_T c1_dv62[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i253;
  int32_T c1_i254;
  int32_T c1_i255;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_qb_debug_family_names,
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
  for (c1_i251 = 0; c1_i251 < 123; c1_i251++) {
    c1_mystr[c1_i251] = c1_cv25[c1_i251];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i252 = 0; c1_i252 < 123; c1_i252++) {
    c1_arr[c1_i252] = c1_dv62[c1_i252];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i253 = 0; c1_i253 < 256; c1_i253++) {
    c1_tt[c1_i253] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i254 = 0; c1_i254 < 123; c1_i254++) {
    c1_tt[c1_i254] = c1_arr[c1_i254];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i255 = 0; c1_i255 < 256; c1_i255++) {
    c1_myarr256[c1_i255] = c1_tt[c1_i255];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_x_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[133];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[133];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i256;
  static char_T c1_cv26[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i257;
  static real_T c1_dv63[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i258;
  int32_T c1_i259;
  int32_T c1_i260;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_rb_debug_family_names,
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
  for (c1_i256 = 0; c1_i256 < 133; c1_i256++) {
    c1_mystr[c1_i256] = c1_cv26[c1_i256];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i257 = 0; c1_i257 < 133; c1_i257++) {
    c1_arr[c1_i257] = c1_dv63[c1_i257];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i258 = 0; c1_i258 < 256; c1_i258++) {
    c1_tt[c1_i258] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i259 = 0; c1_i259 < 133; c1_i259++) {
    c1_tt[c1_i259] = c1_arr[c1_i259];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i260 = 0; c1_i260 < 256; c1_i260++) {
    c1_myarr256[c1_i260] = c1_tt[c1_i260];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_y_encStr2Arr(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_myarr256[256])
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
  int32_T c1_i261;
  static char_T c1_cv27[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i262;
  static real_T c1_dv64[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i263;
  int32_T c1_i264;
  int32_T c1_i265;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_sb_debug_family_names,
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
  for (c1_i261 = 0; c1_i261 < 137; c1_i261++) {
    c1_mystr[c1_i261] = c1_cv27[c1_i261];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i262 = 0; c1_i262 < 137; c1_i262++) {
    c1_arr[c1_i262] = c1_dv64[c1_i262];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i263 = 0; c1_i263 < 256; c1_i263++) {
    c1_tt[c1_i263] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i264 = 0; c1_i264 < 137; c1_i264++) {
    c1_tt[c1_i264] = c1_arr[c1_i264];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i265 = 0; c1_i265 < 256; c1_i265++) {
    c1_myarr256[c1_i265] = c1_tt[c1_i265];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ab_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i266;
  static char_T c1_cv28[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i267;
  static real_T c1_dv65[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i268;
  int32_T c1_i269;
  int32_T c1_i270;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_tb_debug_family_names,
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
  for (c1_i266 = 0; c1_i266 < 138; c1_i266++) {
    c1_mystr[c1_i266] = c1_cv28[c1_i266];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i267 = 0; c1_i267 < 138; c1_i267++) {
    c1_arr[c1_i267] = c1_dv65[c1_i267];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i268 = 0; c1_i268 < 256; c1_i268++) {
    c1_tt[c1_i268] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i269 = 0; c1_i269 < 138; c1_i269++) {
    c1_tt[c1_i269] = c1_arr[c1_i269];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i270 = 0; c1_i270 < 256; c1_i270++) {
    c1_myarr256[c1_i270] = c1_tt[c1_i270];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_bb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i271;
  static char_T c1_cv29[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i272;
  static real_T c1_dv66[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i273;
  int32_T c1_i274;
  int32_T c1_i275;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ub_debug_family_names,
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
  for (c1_i271 = 0; c1_i271 < 136; c1_i271++) {
    c1_mystr[c1_i271] = c1_cv29[c1_i271];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i272 = 0; c1_i272 < 136; c1_i272++) {
    c1_arr[c1_i272] = c1_dv66[c1_i272];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i273 = 0; c1_i273 < 256; c1_i273++) {
    c1_tt[c1_i273] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i274 = 0; c1_i274 < 136; c1_i274++) {
    c1_tt[c1_i274] = c1_arr[c1_i274];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i275 = 0; c1_i275 < 256; c1_i275++) {
    c1_myarr256[c1_i275] = c1_tt[c1_i275];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_cb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i276;
  static char_T c1_cv30[135] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i277;
  static real_T c1_dv67[135] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i278;
  int32_T c1_i279;
  int32_T c1_i280;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_vb_debug_family_names,
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
  for (c1_i276 = 0; c1_i276 < 135; c1_i276++) {
    c1_mystr[c1_i276] = c1_cv30[c1_i276];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i277 = 0; c1_i277 < 135; c1_i277++) {
    c1_arr[c1_i277] = c1_dv67[c1_i277];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i278 = 0; c1_i278 < 256; c1_i278++) {
    c1_tt[c1_i278] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i279 = 0; c1_i279 < 135; c1_i279++) {
    c1_tt[c1_i279] = c1_arr[c1_i279];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i280 = 0; c1_i280 < 256; c1_i280++) {
    c1_myarr256[c1_i280] = c1_tt[c1_i280];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_db_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[131];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[131];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i281;
  static char_T c1_cv31[131] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '1',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i282;
  static real_T c1_dv68[131] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i283;
  int32_T c1_i284;
  int32_T c1_i285;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_wb_debug_family_names,
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
  for (c1_i281 = 0; c1_i281 < 131; c1_i281++) {
    c1_mystr[c1_i281] = c1_cv31[c1_i281];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i282 = 0; c1_i282 < 131; c1_i282++) {
    c1_arr[c1_i282] = c1_dv68[c1_i282];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i283 = 0; c1_i283 < 256; c1_i283++) {
    c1_tt[c1_i283] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i284 = 0; c1_i284 < 131; c1_i284++) {
    c1_tt[c1_i284] = c1_arr[c1_i284];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i285 = 0; c1_i285 < 256; c1_i285++) {
    c1_myarr256[c1_i285] = c1_tt[c1_i285];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_eb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i286;
  static char_T c1_cv32[134] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c1_i287;
  static real_T c1_dv69[134] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i288;
  int32_T c1_i289;
  int32_T c1_i290;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_xb_debug_family_names,
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
  for (c1_i286 = 0; c1_i286 < 134; c1_i286++) {
    c1_mystr[c1_i286] = c1_cv32[c1_i286];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i287 = 0; c1_i287 < 134; c1_i287++) {
    c1_arr[c1_i287] = c1_dv69[c1_i287];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i288 = 0; c1_i288 < 256; c1_i288++) {
    c1_tt[c1_i288] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i289 = 0; c1_i289 < 134; c1_i289++) {
    c1_tt[c1_i289] = c1_arr[c1_i289];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i290 = 0; c1_i290 < 256; c1_i290++) {
    c1_myarr256[c1_i290] = c1_tt[c1_i290];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_fb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[133];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[133];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i291;
  static char_T c1_cv33[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '1', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c1_i292;
  static real_T c1_dv70[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i293;
  int32_T c1_i294;
  int32_T c1_i295;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_yb_debug_family_names,
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
  for (c1_i291 = 0; c1_i291 < 133; c1_i291++) {
    c1_mystr[c1_i291] = c1_cv33[c1_i291];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i292 = 0; c1_i292 < 133; c1_i292++) {
    c1_arr[c1_i292] = c1_dv70[c1_i292];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i293 = 0; c1_i293 < 256; c1_i293++) {
    c1_tt[c1_i293] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i294 = 0; c1_i294 < 133; c1_i294++) {
    c1_tt[c1_i294] = c1_arr[c1_i294];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i295 = 0; c1_i295 < 256; c1_i295++) {
    c1_myarr256[c1_i295] = c1_tt[c1_i295];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_gb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i296;
  static char_T c1_cv34[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i297;
  static real_T c1_dv71[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i298;
  int32_T c1_i299;
  int32_T c1_i300;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_ac_debug_family_names,
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
  for (c1_i296 = 0; c1_i296 < 142; c1_i296++) {
    c1_mystr[c1_i296] = c1_cv34[c1_i296];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i297 = 0; c1_i297 < 142; c1_i297++) {
    c1_arr[c1_i297] = c1_dv71[c1_i297];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i298 = 0; c1_i298 < 256; c1_i298++) {
    c1_tt[c1_i298] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i299 = 0; c1_i299 < 142; c1_i299++) {
    c1_tt[c1_i299] = c1_arr[c1_i299];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i300 = 0; c1_i300 < 256; c1_i300++) {
    c1_myarr256[c1_i300] = c1_tt[c1_i300];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_hb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i301;
  static char_T c1_cv35[225] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c1_i302;
  static real_T c1_dv72[225] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c1_i303;
  int32_T c1_i304;
  int32_T c1_i305;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_bc_debug_family_names,
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
  for (c1_i301 = 0; c1_i301 < 225; c1_i301++) {
    c1_mystr[c1_i301] = c1_cv35[c1_i301];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i302 = 0; c1_i302 < 225; c1_i302++) {
    c1_arr[c1_i302] = c1_dv72[c1_i302];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 225.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i303 = 0; c1_i303 < 256; c1_i303++) {
    c1_tt[c1_i303] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i304 = 0; c1_i304 < 225; c1_i304++) {
    c1_tt[c1_i304] = c1_arr[c1_i304];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i305 = 0; c1_i305 < 256; c1_i305++) {
    c1_myarr256[c1_i305] = c1_tt[c1_i305];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_c_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
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

static real_T c1_d_randi(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
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

static void c1_ib_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i306;
  static char_T c1_cv36[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i307;
  static real_T c1_dv73[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c1_i308;
  int32_T c1_i309;
  int32_T c1_i310;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_mc_debug_family_names,
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
  for (c1_i306 = 0; c1_i306 < 91; c1_i306++) {
    c1_mystr[c1_i306] = c1_cv36[c1_i306];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i307 = 0; c1_i307 < 91; c1_i307++) {
    c1_arr[c1_i307] = c1_dv73[c1_i307];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i308 = 0; c1_i308 < 256; c1_i308++) {
    c1_tt[c1_i308] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i309 = 0; c1_i309 < 91; c1_i309++) {
    c1_tt[c1_i309] = c1_arr[c1_i309];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i310 = 0; c1_i310 < 256; c1_i310++) {
    c1_myarr256[c1_i310] = c1_tt[c1_i310];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_jb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i311;
  static char_T c1_cv37[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c1_i312;
  static real_T c1_dv74[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i313;
  int32_T c1_i314;
  int32_T c1_i315;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_nc_debug_family_names,
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
  for (c1_i311 = 0; c1_i311 < 87; c1_i311++) {
    c1_mystr[c1_i311] = c1_cv37[c1_i311];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i312 = 0; c1_i312 < 87; c1_i312++) {
    c1_arr[c1_i312] = c1_dv74[c1_i312];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i313 = 0; c1_i313 < 256; c1_i313++) {
    c1_tt[c1_i313] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i314 = 0; c1_i314 < 87; c1_i314++) {
    c1_tt[c1_i314] = c1_arr[c1_i314];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i315 = 0; c1_i315 < 256; c1_i315++) {
    c1_myarr256[c1_i315] = c1_tt[c1_i315];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_kb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i316;
  static char_T c1_cv38[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i317;
  static real_T c1_dv75[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i318;
  int32_T c1_i319;
  int32_T c1_i320;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_oc_debug_family_names,
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
  for (c1_i316 = 0; c1_i316 < 93; c1_i316++) {
    c1_mystr[c1_i316] = c1_cv38[c1_i316];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i317 = 0; c1_i317 < 93; c1_i317++) {
    c1_arr[c1_i317] = c1_dv75[c1_i317];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i318 = 0; c1_i318 < 256; c1_i318++) {
    c1_tt[c1_i318] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i319 = 0; c1_i319 < 93; c1_i319++) {
    c1_tt[c1_i319] = c1_arr[c1_i319];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i320 = 0; c1_i320 < 256; c1_i320++) {
    c1_myarr256[c1_i320] = c1_tt[c1_i320];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_lb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i321;
  static char_T c1_cv39[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i322;
  static real_T c1_dv76[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i323;
  int32_T c1_i324;
  int32_T c1_i325;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_pc_debug_family_names,
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
  for (c1_i321 = 0; c1_i321 < 94; c1_i321++) {
    c1_mystr[c1_i321] = c1_cv39[c1_i321];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i322 = 0; c1_i322 < 94; c1_i322++) {
    c1_arr[c1_i322] = c1_dv76[c1_i322];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i323 = 0; c1_i323 < 256; c1_i323++) {
    c1_tt[c1_i323] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i324 = 0; c1_i324 < 94; c1_i324++) {
    c1_tt[c1_i324] = c1_arr[c1_i324];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i325 = 0; c1_i325 < 256; c1_i325++) {
    c1_myarr256[c1_i325] = c1_tt[c1_i325];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_mb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i326;
  static char_T c1_cv40[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i327;
  static real_T c1_dv77[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i328;
  int32_T c1_i329;
  int32_T c1_i330;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_qc_debug_family_names,
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
  for (c1_i326 = 0; c1_i326 < 95; c1_i326++) {
    c1_mystr[c1_i326] = c1_cv40[c1_i326];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i327 = 0; c1_i327 < 95; c1_i327++) {
    c1_arr[c1_i327] = c1_dv77[c1_i327];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i328 = 0; c1_i328 < 256; c1_i328++) {
    c1_tt[c1_i328] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i329 = 0; c1_i329 < 95; c1_i329++) {
    c1_tt[c1_i329] = c1_arr[c1_i329];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i330 = 0; c1_i330 < 256; c1_i330++) {
    c1_myarr256[c1_i330] = c1_tt[c1_i330];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_nb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i331;
  static char_T c1_cv41[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c1_i332;
  static real_T c1_dv78[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i333;
  int32_T c1_i334;
  int32_T c1_i335;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_rc_debug_family_names,
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
  for (c1_i331 = 0; c1_i331 < 88; c1_i331++) {
    c1_mystr[c1_i331] = c1_cv41[c1_i331];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i332 = 0; c1_i332 < 88; c1_i332++) {
    c1_arr[c1_i332] = c1_dv78[c1_i332];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i333 = 0; c1_i333 < 256; c1_i333++) {
    c1_tt[c1_i333] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i334 = 0; c1_i334 < 88; c1_i334++) {
    c1_tt[c1_i334] = c1_arr[c1_i334];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i335 = 0; c1_i335 < 256; c1_i335++) {
    c1_myarr256[c1_i335] = c1_tt[c1_i335];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ob_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i336;
  static char_T c1_cv42[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i337;
  static real_T c1_dv79[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i338;
  int32_T c1_i339;
  int32_T c1_i340;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_sc_debug_family_names,
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
  for (c1_i336 = 0; c1_i336 < 93; c1_i336++) {
    c1_mystr[c1_i336] = c1_cv42[c1_i336];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i337 = 0; c1_i337 < 93; c1_i337++) {
    c1_arr[c1_i337] = c1_dv79[c1_i337];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i338 = 0; c1_i338 < 256; c1_i338++) {
    c1_tt[c1_i338] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i339 = 0; c1_i339 < 93; c1_i339++) {
    c1_tt[c1_i339] = c1_arr[c1_i339];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i340 = 0; c1_i340 < 256; c1_i340++) {
    c1_myarr256[c1_i340] = c1_tt[c1_i340];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_pb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i341;
  static char_T c1_cv43[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i342;
  static real_T c1_dv80[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i343;
  int32_T c1_i344;
  int32_T c1_i345;
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
  for (c1_i341 = 0; c1_i341 < 93; c1_i341++) {
    c1_mystr[c1_i341] = c1_cv43[c1_i341];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i342 = 0; c1_i342 < 93; c1_i342++) {
    c1_arr[c1_i342] = c1_dv80[c1_i342];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i343 = 0; c1_i343 < 256; c1_i343++) {
    c1_tt[c1_i343] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i344 = 0; c1_i344 < 93; c1_i344++) {
    c1_tt[c1_i344] = c1_arr[c1_i344];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i345 = 0; c1_i345 < 256; c1_i345++) {
    c1_myarr256[c1_i345] = c1_tt[c1_i345];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_qb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i346;
  static char_T c1_cv44[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i347;
  static real_T c1_dv81[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i348;
  int32_T c1_i349;
  int32_T c1_i350;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_uc_debug_family_names,
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
  for (c1_i346 = 0; c1_i346 < 97; c1_i346++) {
    c1_mystr[c1_i346] = c1_cv44[c1_i346];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i347 = 0; c1_i347 < 97; c1_i347++) {
    c1_arr[c1_i347] = c1_dv81[c1_i347];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i348 = 0; c1_i348 < 256; c1_i348++) {
    c1_tt[c1_i348] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i349 = 0; c1_i349 < 97; c1_i349++) {
    c1_tt[c1_i349] = c1_arr[c1_i349];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i350 = 0; c1_i350 < 256; c1_i350++) {
    c1_myarr256[c1_i350] = c1_tt[c1_i350];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_rb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i351;
  static char_T c1_cv45[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i352;
  static real_T c1_dv82[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c1_i353;
  int32_T c1_i354;
  int32_T c1_i355;
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
  for (c1_i351 = 0; c1_i351 < 97; c1_i351++) {
    c1_mystr[c1_i351] = c1_cv45[c1_i351];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i352 = 0; c1_i352 < 97; c1_i352++) {
    c1_arr[c1_i352] = c1_dv82[c1_i352];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i353 = 0; c1_i353 < 256; c1_i353++) {
    c1_tt[c1_i353] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i354 = 0; c1_i354 < 97; c1_i354++) {
    c1_tt[c1_i354] = c1_arr[c1_i354];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i355 = 0; c1_i355 < 256; c1_i355++) {
    c1_myarr256[c1_i355] = c1_tt[c1_i355];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_sb_encStr2Arr
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, real_T
   c1_myarr256[256])
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
  int32_T c1_i356;
  static char_T c1_cv46[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i357;
  static real_T c1_dv83[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i358;
  int32_T c1_i359;
  int32_T c1_i360;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_wc_debug_family_names,
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
  for (c1_i356 = 0; c1_i356 < 92; c1_i356++) {
    c1_mystr[c1_i356] = c1_cv46[c1_i356];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  for (c1_i357 = 0; c1_i357 < 92; c1_i357++) {
    c1_arr[c1_i357] = c1_dv83[c1_i357];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_padsize = c1_maxarrsize - c1_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  for (c1_i358 = 0; c1_i358 < 256; c1_i358++) {
    c1_tt[c1_i358] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  for (c1_i359 = 0; c1_i359 < 92; c1_i359++) {
    c1_tt[c1_i359] = c1_arr[c1_i359];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
  for (c1_i360 = 0; c1_i360 < 256; c1_i360++) {
    c1_myarr256[c1_i360] = c1_tt[c1_i360];
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
  int32_T c1_i361;
  real_T c1_b_inData[256];
  int32_T c1_i362;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i361 = 0; c1_i361 < 256; c1_i361++) {
    c1_b_inData[c1_i361] = (*(real_T (*)[256])c1_inData)[c1_i361];
  }

  for (c1_i362 = 0; c1_i362 < 256; c1_i362++) {
    c1_u[c1_i362] = c1_b_inData[c1_i362];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv84[256];
  int32_T c1_i363;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv84, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c1_i363 = 0; c1_i363 < 256; c1_i363++) {
    c1_y[c1_i363] = c1_dv84[c1_i363];
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
  int32_T c1_i364;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_poseBML = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_poseBML), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_poseBML);
  for (c1_i364 = 0; c1_i364 < 256; c1_i364++) {
    (*(real_T (*)[256])c1_outData)[c1_i364] = c1_y[c1_i364];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
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
  int32_T c1_i365;
  real_T c1_b_inData[256];
  int32_T c1_i366;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i365 = 0; c1_i365 < 256; c1_i365++) {
    c1_b_inData[c1_i365] = (*(real_T (*)[256])c1_inData)[c1_i365];
  }

  for (c1_i366 = 0; c1_i366 < 256; c1_i366++) {
    c1_u[c1_i366] = c1_b_inData[c1_i366];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[256])
{
  real_T c1_dv85[256];
  int32_T c1_i367;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv85, 1, 0, 0U, 1, 0U, 1, 256);
  for (c1_i367 = 0; c1_i367 < 256; c1_i367++) {
    c1_y[c1_i367] = c1_dv85[c1_i367];
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
  int32_T c1_i368;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_myarr256 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_myarr256), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_myarr256);
  for (c1_i368 = 0; c1_i368 < 256; c1_i368++) {
    (*(real_T (*)[256])c1_outData)[c1_i368] = c1_y[c1_i368];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i369;
  char_T c1_b_inData[94];
  int32_T c1_i370;
  char_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i369 = 0; c1_i369 < 94; c1_i369++) {
    c1_b_inData[c1_i369] = (*(char_T (*)[94])c1_inData)[c1_i369];
  }

  for (c1_i370 = 0; c1_i370 < 94; c1_i370++) {
    c1_u[c1_i370] = c1_b_inData[c1_i370];
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
  int32_T c1_i371;
  real_T c1_b_inData[94];
  int32_T c1_i372;
  real_T c1_u[94];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i371 = 0; c1_i371 < 94; c1_i371++) {
    c1_b_inData[c1_i371] = (*(real_T (*)[94])c1_inData)[c1_i371];
  }

  for (c1_i372 = 0; c1_i372 < 94; c1_i372++) {
    c1_u[c1_i372] = c1_b_inData[c1_i372];
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
  int32_T c1_i373;
  char_T c1_b_inData[88];
  int32_T c1_i374;
  char_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i373 = 0; c1_i373 < 88; c1_i373++) {
    c1_b_inData[c1_i373] = (*(char_T (*)[88])c1_inData)[c1_i373];
  }

  for (c1_i374 = 0; c1_i374 < 88; c1_i374++) {
    c1_u[c1_i374] = c1_b_inData[c1_i374];
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
  int32_T c1_i375;
  real_T c1_b_inData[88];
  int32_T c1_i376;
  real_T c1_u[88];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i375 = 0; c1_i375 < 88; c1_i375++) {
    c1_b_inData[c1_i375] = (*(real_T (*)[88])c1_inData)[c1_i375];
  }

  for (c1_i376 = 0; c1_i376 < 88; c1_i376++) {
    c1_u[c1_i376] = c1_b_inData[c1_i376];
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
  int32_T c1_i377;
  char_T c1_b_inData[86];
  int32_T c1_i378;
  char_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i377 = 0; c1_i377 < 86; c1_i377++) {
    c1_b_inData[c1_i377] = (*(char_T (*)[86])c1_inData)[c1_i377];
  }

  for (c1_i378 = 0; c1_i378 < 86; c1_i378++) {
    c1_u[c1_i378] = c1_b_inData[c1_i378];
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
  int32_T c1_i379;
  real_T c1_b_inData[86];
  int32_T c1_i380;
  real_T c1_u[86];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i379 = 0; c1_i379 < 86; c1_i379++) {
    c1_b_inData[c1_i379] = (*(real_T (*)[86])c1_inData)[c1_i379];
  }

  for (c1_i380 = 0; c1_i380 < 86; c1_i380++) {
    c1_u[c1_i380] = c1_b_inData[c1_i380];
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
  int32_T c1_i381;
  char_T c1_b_inData[161];
  int32_T c1_i382;
  char_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i381 = 0; c1_i381 < 161; c1_i381++) {
    c1_b_inData[c1_i381] = (*(char_T (*)[161])c1_inData)[c1_i381];
  }

  for (c1_i382 = 0; c1_i382 < 161; c1_i382++) {
    c1_u[c1_i382] = c1_b_inData[c1_i382];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i383;
  real_T c1_b_inData[161];
  int32_T c1_i384;
  real_T c1_u[161];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i383 = 0; c1_i383 < 161; c1_i383++) {
    c1_b_inData[c1_i383] = (*(real_T (*)[161])c1_inData)[c1_i383];
  }

  for (c1_i384 = 0; c1_i384 < 161; c1_i384++) {
    c1_u[c1_i384] = c1_b_inData[c1_i384];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i385;
  char_T c1_b_inData[157];
  int32_T c1_i386;
  char_T c1_u[157];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i385 = 0; c1_i385 < 157; c1_i385++) {
    c1_b_inData[c1_i385] = (*(char_T (*)[157])c1_inData)[c1_i385];
  }

  for (c1_i386 = 0; c1_i386 < 157; c1_i386++) {
    c1_u[c1_i386] = c1_b_inData[c1_i386];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i387;
  real_T c1_b_inData[157];
  int32_T c1_i388;
  real_T c1_u[157];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i387 = 0; c1_i387 < 157; c1_i387++) {
    c1_b_inData[c1_i387] = (*(real_T (*)[157])c1_inData)[c1_i387];
  }

  for (c1_i388 = 0; c1_i388 < 157; c1_i388++) {
    c1_u[c1_i388] = c1_b_inData[c1_i388];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_o_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i389;
  char_T c1_b_inData[92];
  int32_T c1_i390;
  char_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i389 = 0; c1_i389 < 92; c1_i389++) {
    c1_b_inData[c1_i389] = (*(char_T (*)[92])c1_inData)[c1_i389];
  }

  for (c1_i390 = 0; c1_i390 < 92; c1_i390++) {
    c1_u[c1_i390] = c1_b_inData[c1_i390];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_p_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i391;
  real_T c1_b_inData[92];
  int32_T c1_i392;
  real_T c1_u[92];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i391 = 0; c1_i391 < 92; c1_i391++) {
    c1_b_inData[c1_i391] = (*(real_T (*)[92])c1_inData)[c1_i391];
  }

  for (c1_i392 = 0; c1_i392 < 92; c1_i392++) {
    c1_u[c1_i392] = c1_b_inData[c1_i392];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_q_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i393;
  char_T c1_b_inData[89];
  int32_T c1_i394;
  char_T c1_u[89];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i393 = 0; c1_i393 < 89; c1_i393++) {
    c1_b_inData[c1_i393] = (*(char_T (*)[89])c1_inData)[c1_i393];
  }

  for (c1_i394 = 0; c1_i394 < 89; c1_i394++) {
    c1_u[c1_i394] = c1_b_inData[c1_i394];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 89), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_r_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i395;
  real_T c1_b_inData[89];
  int32_T c1_i396;
  real_T c1_u[89];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i395 = 0; c1_i395 < 89; c1_i395++) {
    c1_b_inData[c1_i395] = (*(real_T (*)[89])c1_inData)[c1_i395];
  }

  for (c1_i396 = 0; c1_i396 < 89; c1_i396++) {
    c1_u[c1_i396] = c1_b_inData[c1_i396];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 89), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_s_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i397;
  char_T c1_b_inData[81];
  int32_T c1_i398;
  char_T c1_u[81];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i397 = 0; c1_i397 < 81; c1_i397++) {
    c1_b_inData[c1_i397] = (*(char_T (*)[81])c1_inData)[c1_i397];
  }

  for (c1_i398 = 0; c1_i398 < 81; c1_i398++) {
    c1_u[c1_i398] = c1_b_inData[c1_i398];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 81), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_t_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i399;
  real_T c1_b_inData[81];
  int32_T c1_i400;
  real_T c1_u[81];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i399 = 0; c1_i399 < 81; c1_i399++) {
    c1_b_inData[c1_i399] = (*(real_T (*)[81])c1_inData)[c1_i399];
  }

  for (c1_i400 = 0; c1_i400 < 81; c1_i400++) {
    c1_u[c1_i400] = c1_b_inData[c1_i400];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 81), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_u_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i401;
  char_T c1_b_inData[78];
  int32_T c1_i402;
  char_T c1_u[78];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i401 = 0; c1_i401 < 78; c1_i401++) {
    c1_b_inData[c1_i401] = (*(char_T (*)[78])c1_inData)[c1_i401];
  }

  for (c1_i402 = 0; c1_i402 < 78; c1_i402++) {
    c1_u[c1_i402] = c1_b_inData[c1_i402];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 78), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_v_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i403;
  real_T c1_b_inData[78];
  int32_T c1_i404;
  real_T c1_u[78];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i403 = 0; c1_i403 < 78; c1_i403++) {
    c1_b_inData[c1_i403] = (*(real_T (*)[78])c1_inData)[c1_i403];
  }

  for (c1_i404 = 0; c1_i404 < 78; c1_i404++) {
    c1_u[c1_i404] = c1_b_inData[c1_i404];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 78), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_w_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i405;
  char_T c1_b_inData[147];
  int32_T c1_i406;
  char_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i405 = 0; c1_i405 < 147; c1_i405++) {
    c1_b_inData[c1_i405] = (*(char_T (*)[147])c1_inData)[c1_i405];
  }

  for (c1_i406 = 0; c1_i406 < 147; c1_i406++) {
    c1_u[c1_i406] = c1_b_inData[c1_i406];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_x_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i407;
  real_T c1_b_inData[147];
  int32_T c1_i408;
  real_T c1_u[147];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i407 = 0; c1_i407 < 147; c1_i407++) {
    c1_b_inData[c1_i407] = (*(real_T (*)[147])c1_inData)[c1_i407];
  }

  for (c1_i408 = 0; c1_i408 < 147; c1_i408++) {
    c1_u[c1_i408] = c1_b_inData[c1_i408];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_y_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i409;
  char_T c1_b_inData[164];
  int32_T c1_i410;
  char_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i409 = 0; c1_i409 < 164; c1_i409++) {
    c1_b_inData[c1_i409] = (*(char_T (*)[164])c1_inData)[c1_i409];
  }

  for (c1_i410 = 0; c1_i410 < 164; c1_i410++) {
    c1_u[c1_i410] = c1_b_inData[c1_i410];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i411;
  real_T c1_b_inData[164];
  int32_T c1_i412;
  real_T c1_u[164];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i411 = 0; c1_i411 < 164; c1_i411++) {
    c1_b_inData[c1_i411] = (*(real_T (*)[164])c1_inData)[c1_i411];
  }

  for (c1_i412 = 0; c1_i412 < 164; c1_i412++) {
    c1_u[c1_i412] = c1_b_inData[c1_i412];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i413;
  char_T c1_b_inData[68];
  int32_T c1_i414;
  char_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i413 = 0; c1_i413 < 68; c1_i413++) {
    c1_b_inData[c1_i413] = (*(char_T (*)[68])c1_inData)[c1_i413];
  }

  for (c1_i414 = 0; c1_i414 < 68; c1_i414++) {
    c1_u[c1_i414] = c1_b_inData[c1_i414];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i415;
  real_T c1_b_inData[68];
  int32_T c1_i416;
  real_T c1_u[68];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i415 = 0; c1_i415 < 68; c1_i415++) {
    c1_b_inData[c1_i415] = (*(real_T (*)[68])c1_inData)[c1_i415];
  }

  for (c1_i416 = 0; c1_i416 < 68; c1_i416++) {
    c1_u[c1_i416] = c1_b_inData[c1_i416];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_db_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i417;
  char_T c1_b_inData[223];
  int32_T c1_i418;
  char_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i417 = 0; c1_i417 < 223; c1_i417++) {
    c1_b_inData[c1_i417] = (*(char_T (*)[223])c1_inData)[c1_i417];
  }

  for (c1_i418 = 0; c1_i418 < 223; c1_i418++) {
    c1_u[c1_i418] = c1_b_inData[c1_i418];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i419;
  real_T c1_b_inData[223];
  int32_T c1_i420;
  real_T c1_u[223];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i419 = 0; c1_i419 < 223; c1_i419++) {
    c1_b_inData[c1_i419] = (*(real_T (*)[223])c1_inData)[c1_i419];
  }

  for (c1_i420 = 0; c1_i420 < 223; c1_i420++) {
    c1_u[c1_i420] = c1_b_inData[c1_i420];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i421;
  char_T c1_b_inData[225];
  int32_T c1_i422;
  char_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i421 = 0; c1_i421 < 225; c1_i421++) {
    c1_b_inData[c1_i421] = (*(char_T (*)[225])c1_inData)[c1_i421];
  }

  for (c1_i422 = 0; c1_i422 < 225; c1_i422++) {
    c1_u[c1_i422] = c1_b_inData[c1_i422];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i423;
  real_T c1_b_inData[225];
  int32_T c1_i424;
  real_T c1_u[225];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i423 = 0; c1_i423 < 225; c1_i423++) {
    c1_b_inData[c1_i423] = (*(real_T (*)[225])c1_inData)[c1_i423];
  }

  for (c1_i424 = 0; c1_i424 < 225; c1_i424++) {
    c1_u[c1_i424] = c1_b_inData[c1_i424];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i425;
  char_T c1_b_inData[87];
  int32_T c1_i426;
  char_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i425 = 0; c1_i425 < 87; c1_i425++) {
    c1_b_inData[c1_i425] = (*(char_T (*)[87])c1_inData)[c1_i425];
  }

  for (c1_i426 = 0; c1_i426 < 87; c1_i426++) {
    c1_u[c1_i426] = c1_b_inData[c1_i426];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i427;
  real_T c1_b_inData[87];
  int32_T c1_i428;
  real_T c1_u[87];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i427 = 0; c1_i427 < 87; c1_i427++) {
    c1_b_inData[c1_i427] = (*(real_T (*)[87])c1_inData)[c1_i427];
  }

  for (c1_i428 = 0; c1_i428 < 87; c1_i428++) {
    c1_u[c1_i428] = c1_b_inData[c1_i428];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i429;
  char_T c1_b_inData[118];
  int32_T c1_i430;
  char_T c1_u[118];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i429 = 0; c1_i429 < 118; c1_i429++) {
    c1_b_inData[c1_i429] = (*(char_T (*)[118])c1_inData)[c1_i429];
  }

  for (c1_i430 = 0; c1_i430 < 118; c1_i430++) {
    c1_u[c1_i430] = c1_b_inData[c1_i430];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i431;
  real_T c1_b_inData[118];
  int32_T c1_i432;
  real_T c1_u[118];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i431 = 0; c1_i431 < 118; c1_i431++) {
    c1_b_inData[c1_i431] = (*(real_T (*)[118])c1_inData)[c1_i431];
  }

  for (c1_i432 = 0; c1_i432 < 118; c1_i432++) {
    c1_u[c1_i432] = c1_b_inData[c1_i432];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i433;
  char_T c1_b_inData[119];
  int32_T c1_i434;
  char_T c1_u[119];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i433 = 0; c1_i433 < 119; c1_i433++) {
    c1_b_inData[c1_i433] = (*(char_T (*)[119])c1_inData)[c1_i433];
  }

  for (c1_i434 = 0; c1_i434 < 119; c1_i434++) {
    c1_u[c1_i434] = c1_b_inData[c1_i434];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i435;
  real_T c1_b_inData[119];
  int32_T c1_i436;
  real_T c1_u[119];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i435 = 0; c1_i435 < 119; c1_i435++) {
    c1_b_inData[c1_i435] = (*(real_T (*)[119])c1_inData)[c1_i435];
  }

  for (c1_i436 = 0; c1_i436 < 119; c1_i436++) {
    c1_u[c1_i436] = c1_b_inData[c1_i436];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i437;
  char_T c1_b_inData[116];
  int32_T c1_i438;
  char_T c1_u[116];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i437 = 0; c1_i437 < 116; c1_i437++) {
    c1_b_inData[c1_i437] = (*(char_T (*)[116])c1_inData)[c1_i437];
  }

  for (c1_i438 = 0; c1_i438 < 116; c1_i438++) {
    c1_u[c1_i438] = c1_b_inData[c1_i438];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i439;
  real_T c1_b_inData[116];
  int32_T c1_i440;
  real_T c1_u[116];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i439 = 0; c1_i439 < 116; c1_i439++) {
    c1_b_inData[c1_i439] = (*(real_T (*)[116])c1_inData)[c1_i439];
  }

  for (c1_i440 = 0; c1_i440 < 116; c1_i440++) {
    c1_u[c1_i440] = c1_b_inData[c1_i440];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i441;
  char_T c1_b_inData[120];
  int32_T c1_i442;
  char_T c1_u[120];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i441 = 0; c1_i441 < 120; c1_i441++) {
    c1_b_inData[c1_i441] = (*(char_T (*)[120])c1_inData)[c1_i441];
  }

  for (c1_i442 = 0; c1_i442 < 120; c1_i442++) {
    c1_u[c1_i442] = c1_b_inData[c1_i442];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i443;
  real_T c1_b_inData[120];
  int32_T c1_i444;
  real_T c1_u[120];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i443 = 0; c1_i443 < 120; c1_i443++) {
    c1_b_inData[c1_i443] = (*(real_T (*)[120])c1_inData)[c1_i443];
  }

  for (c1_i444 = 0; c1_i444 < 120; c1_i444++) {
    c1_u[c1_i444] = c1_b_inData[c1_i444];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i445;
  char_T c1_b_inData[121];
  int32_T c1_i446;
  char_T c1_u[121];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i445 = 0; c1_i445 < 121; c1_i445++) {
    c1_b_inData[c1_i445] = (*(char_T (*)[121])c1_inData)[c1_i445];
  }

  for (c1_i446 = 0; c1_i446 < 121; c1_i446++) {
    c1_u[c1_i446] = c1_b_inData[c1_i446];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i447;
  real_T c1_b_inData[121];
  int32_T c1_i448;
  real_T c1_u[121];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i447 = 0; c1_i447 < 121; c1_i447++) {
    c1_b_inData[c1_i447] = (*(real_T (*)[121])c1_inData)[c1_i447];
  }

  for (c1_i448 = 0; c1_i448 < 121; c1_i448++) {
    c1_u[c1_i448] = c1_b_inData[c1_i448];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i449;
  char_T c1_b_inData[122];
  int32_T c1_i450;
  char_T c1_u[122];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i449 = 0; c1_i449 < 122; c1_i449++) {
    c1_b_inData[c1_i449] = (*(char_T (*)[122])c1_inData)[c1_i449];
  }

  for (c1_i450 = 0; c1_i450 < 122; c1_i450++) {
    c1_u[c1_i450] = c1_b_inData[c1_i450];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i451;
  real_T c1_b_inData[122];
  int32_T c1_i452;
  real_T c1_u[122];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i451 = 0; c1_i451 < 122; c1_i451++) {
    c1_b_inData[c1_i451] = (*(real_T (*)[122])c1_inData)[c1_i451];
  }

  for (c1_i452 = 0; c1_i452 < 122; c1_i452++) {
    c1_u[c1_i452] = c1_b_inData[c1_i452];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i453;
  char_T c1_b_inData[123];
  int32_T c1_i454;
  char_T c1_u[123];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i453 = 0; c1_i453 < 123; c1_i453++) {
    c1_b_inData[c1_i453] = (*(char_T (*)[123])c1_inData)[c1_i453];
  }

  for (c1_i454 = 0; c1_i454 < 123; c1_i454++) {
    c1_u[c1_i454] = c1_b_inData[c1_i454];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i455;
  real_T c1_b_inData[123];
  int32_T c1_i456;
  real_T c1_u[123];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i455 = 0; c1_i455 < 123; c1_i455++) {
    c1_b_inData[c1_i455] = (*(real_T (*)[123])c1_inData)[c1_i455];
  }

  for (c1_i456 = 0; c1_i456 < 123; c1_i456++) {
    c1_u[c1_i456] = c1_b_inData[c1_i456];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i457;
  char_T c1_b_inData[133];
  int32_T c1_i458;
  char_T c1_u[133];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i457 = 0; c1_i457 < 133; c1_i457++) {
    c1_b_inData[c1_i457] = (*(char_T (*)[133])c1_inData)[c1_i457];
  }

  for (c1_i458 = 0; c1_i458 < 133; c1_i458++) {
    c1_u[c1_i458] = c1_b_inData[c1_i458];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i459;
  real_T c1_b_inData[133];
  int32_T c1_i460;
  real_T c1_u[133];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i459 = 0; c1_i459 < 133; c1_i459++) {
    c1_b_inData[c1_i459] = (*(real_T (*)[133])c1_inData)[c1_i459];
  }

  for (c1_i460 = 0; c1_i460 < 133; c1_i460++) {
    c1_u[c1_i460] = c1_b_inData[c1_i460];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i461;
  char_T c1_b_inData[137];
  int32_T c1_i462;
  char_T c1_u[137];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i461 = 0; c1_i461 < 137; c1_i461++) {
    c1_b_inData[c1_i461] = (*(char_T (*)[137])c1_inData)[c1_i461];
  }

  for (c1_i462 = 0; c1_i462 < 137; c1_i462++) {
    c1_u[c1_i462] = c1_b_inData[c1_i462];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i463;
  real_T c1_b_inData[137];
  int32_T c1_i464;
  real_T c1_u[137];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i463 = 0; c1_i463 < 137; c1_i463++) {
    c1_b_inData[c1_i463] = (*(real_T (*)[137])c1_inData)[c1_i463];
  }

  for (c1_i464 = 0; c1_i464 < 137; c1_i464++) {
    c1_u[c1_i464] = c1_b_inData[c1_i464];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i465;
  char_T c1_b_inData[138];
  int32_T c1_i466;
  char_T c1_u[138];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i465 = 0; c1_i465 < 138; c1_i465++) {
    c1_b_inData[c1_i465] = (*(char_T (*)[138])c1_inData)[c1_i465];
  }

  for (c1_i466 = 0; c1_i466 < 138; c1_i466++) {
    c1_u[c1_i466] = c1_b_inData[c1_i466];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i467;
  real_T c1_b_inData[138];
  int32_T c1_i468;
  real_T c1_u[138];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i467 = 0; c1_i467 < 138; c1_i467++) {
    c1_b_inData[c1_i467] = (*(real_T (*)[138])c1_inData)[c1_i467];
  }

  for (c1_i468 = 0; c1_i468 < 138; c1_i468++) {
    c1_u[c1_i468] = c1_b_inData[c1_i468];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i469;
  char_T c1_b_inData[136];
  int32_T c1_i470;
  char_T c1_u[136];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i469 = 0; c1_i469 < 136; c1_i469++) {
    c1_b_inData[c1_i469] = (*(char_T (*)[136])c1_inData)[c1_i469];
  }

  for (c1_i470 = 0; c1_i470 < 136; c1_i470++) {
    c1_u[c1_i470] = c1_b_inData[c1_i470];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i471;
  real_T c1_b_inData[136];
  int32_T c1_i472;
  real_T c1_u[136];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i471 = 0; c1_i471 < 136; c1_i471++) {
    c1_b_inData[c1_i471] = (*(real_T (*)[136])c1_inData)[c1_i471];
  }

  for (c1_i472 = 0; c1_i472 < 136; c1_i472++) {
    c1_u[c1_i472] = c1_b_inData[c1_i472];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i473;
  char_T c1_b_inData[135];
  int32_T c1_i474;
  char_T c1_u[135];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i473 = 0; c1_i473 < 135; c1_i473++) {
    c1_b_inData[c1_i473] = (*(char_T (*)[135])c1_inData)[c1_i473];
  }

  for (c1_i474 = 0; c1_i474 < 135; c1_i474++) {
    c1_u[c1_i474] = c1_b_inData[c1_i474];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i475;
  real_T c1_b_inData[135];
  int32_T c1_i476;
  real_T c1_u[135];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i475 = 0; c1_i475 < 135; c1_i475++) {
    c1_b_inData[c1_i475] = (*(real_T (*)[135])c1_inData)[c1_i475];
  }

  for (c1_i476 = 0; c1_i476 < 135; c1_i476++) {
    c1_u[c1_i476] = c1_b_inData[c1_i476];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i477;
  char_T c1_b_inData[131];
  int32_T c1_i478;
  char_T c1_u[131];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i477 = 0; c1_i477 < 131; c1_i477++) {
    c1_b_inData[c1_i477] = (*(char_T (*)[131])c1_inData)[c1_i477];
  }

  for (c1_i478 = 0; c1_i478 < 131; c1_i478++) {
    c1_u[c1_i478] = c1_b_inData[c1_i478];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i479;
  real_T c1_b_inData[131];
  int32_T c1_i480;
  real_T c1_u[131];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i479 = 0; c1_i479 < 131; c1_i479++) {
    c1_b_inData[c1_i479] = (*(real_T (*)[131])c1_inData)[c1_i479];
  }

  for (c1_i480 = 0; c1_i480 < 131; c1_i480++) {
    c1_u[c1_i480] = c1_b_inData[c1_i480];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i481;
  char_T c1_b_inData[134];
  int32_T c1_i482;
  char_T c1_u[134];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i481 = 0; c1_i481 < 134; c1_i481++) {
    c1_b_inData[c1_i481] = (*(char_T (*)[134])c1_inData)[c1_i481];
  }

  for (c1_i482 = 0; c1_i482 < 134; c1_i482++) {
    c1_u[c1_i482] = c1_b_inData[c1_i482];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i483;
  real_T c1_b_inData[134];
  int32_T c1_i484;
  real_T c1_u[134];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i483 = 0; c1_i483 < 134; c1_i483++) {
    c1_b_inData[c1_i483] = (*(real_T (*)[134])c1_inData)[c1_i483];
  }

  for (c1_i484 = 0; c1_i484 < 134; c1_i484++) {
    c1_u[c1_i484] = c1_b_inData[c1_i484];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i485;
  char_T c1_b_inData[142];
  int32_T c1_i486;
  char_T c1_u[142];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i485 = 0; c1_i485 < 142; c1_i485++) {
    c1_b_inData[c1_i485] = (*(char_T (*)[142])c1_inData)[c1_i485];
  }

  for (c1_i486 = 0; c1_i486 < 142; c1_i486++) {
    c1_u[c1_i486] = c1_b_inData[c1_i486];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i487;
  real_T c1_b_inData[142];
  int32_T c1_i488;
  real_T c1_u[142];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i487 = 0; c1_i487 < 142; c1_i487++) {
    c1_b_inData[c1_i487] = (*(real_T (*)[142])c1_inData)[c1_i487];
  }

  for (c1_i488 = 0; c1_i488 < 142; c1_i488++) {
    c1_u[c1_i488] = c1_b_inData[c1_i488];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i489;
  char_T c1_b_inData[91];
  int32_T c1_i490;
  char_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i489 = 0; c1_i489 < 91; c1_i489++) {
    c1_b_inData[c1_i489] = (*(char_T (*)[91])c1_inData)[c1_i489];
  }

  for (c1_i490 = 0; c1_i490 < 91; c1_i490++) {
    c1_u[c1_i490] = c1_b_inData[c1_i490];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i491;
  real_T c1_b_inData[91];
  int32_T c1_i492;
  real_T c1_u[91];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i491 = 0; c1_i491 < 91; c1_i491++) {
    c1_b_inData[c1_i491] = (*(real_T (*)[91])c1_inData)[c1_i491];
  }

  for (c1_i492 = 0; c1_i492 < 91; c1_i492++) {
    c1_u[c1_i492] = c1_b_inData[c1_i492];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i493;
  char_T c1_b_inData[93];
  int32_T c1_i494;
  char_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i493 = 0; c1_i493 < 93; c1_i493++) {
    c1_b_inData[c1_i493] = (*(char_T (*)[93])c1_inData)[c1_i493];
  }

  for (c1_i494 = 0; c1_i494 < 93; c1_i494++) {
    c1_u[c1_i494] = c1_b_inData[c1_i494];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i495;
  real_T c1_b_inData[93];
  int32_T c1_i496;
  real_T c1_u[93];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i495 = 0; c1_i495 < 93; c1_i495++) {
    c1_b_inData[c1_i495] = (*(real_T (*)[93])c1_inData)[c1_i495];
  }

  for (c1_i496 = 0; c1_i496 < 93; c1_i496++) {
    c1_u[c1_i496] = c1_b_inData[c1_i496];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i497;
  char_T c1_b_inData[95];
  int32_T c1_i498;
  char_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i497 = 0; c1_i497 < 95; c1_i497++) {
    c1_b_inData[c1_i497] = (*(char_T (*)[95])c1_inData)[c1_i497];
  }

  for (c1_i498 = 0; c1_i498 < 95; c1_i498++) {
    c1_u[c1_i498] = c1_b_inData[c1_i498];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i499;
  real_T c1_b_inData[95];
  int32_T c1_i500;
  real_T c1_u[95];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i499 = 0; c1_i499 < 95; c1_i499++) {
    c1_b_inData[c1_i499] = (*(real_T (*)[95])c1_inData)[c1_i499];
  }

  for (c1_i500 = 0; c1_i500 < 95; c1_i500++) {
    c1_u[c1_i500] = c1_b_inData[c1_i500];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i501;
  char_T c1_b_inData[97];
  int32_T c1_i502;
  char_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i501 = 0; c1_i501 < 97; c1_i501++) {
    c1_b_inData[c1_i501] = (*(char_T (*)[97])c1_inData)[c1_i501];
  }

  for (c1_i502 = 0; c1_i502 < 97; c1_i502++) {
    c1_u[c1_i502] = c1_b_inData[c1_i502];
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
  int32_T c1_i503;
  real_T c1_b_inData[97];
  int32_T c1_i504;
  real_T c1_u[97];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i503 = 0; c1_i503 < 97; c1_i503++) {
    c1_b_inData[c1_i503] = (*(real_T (*)[97])c1_inData)[c1_i503];
  }

  for (c1_i504 = 0; c1_i504 < 97; c1_i504++) {
    c1_u[c1_i504] = c1_b_inData[c1_i504];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray
  *sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_eml_resolved_functions_info(void)
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

static void c1_sendBML(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_arg[256])
{
  int32_T c1_i505;
  int32_T c1_i506;
  int32_T c1_i507;
  real_T (*c1_b_arg)[256];
  c1_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 9);
  for (c1_i505 = 0; c1_i505 < 256; c1_i505++) {
    _SFD_DATA_RANGE_CHECK(c1_arg[c1_i505], 27U);
  }

  _SFD_SET_DATA_VALUE_PTR(27U, c1_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c1_arg, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
  for (c1_i506 = 0; c1_i506 < 256; c1_i506++) {
    (*c1_b_arg)[c1_i506] = c1_arg[c1_i506];
  }

  for (c1_i507 = 0; c1_i507 < 256; c1_i507++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_arg)[c1_i507], 27U);
  }

  sf_call_output_fcn_call(chartInstance->S, 1, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(27U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
}

static void c1_handPoseSB(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_sbmID, real_T c1_poseSBM[256])
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
  real_T c1_dv86[256];
  int32_T c1_i508;
  int32_T c1_i509;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i510;
  int32_T c1_i511;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i512;
  int32_T c1_i513;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i514;
  int32_T c1_i515;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  uint32_T c1_b_debug_family_var_map[9];
  real_T c1_maxarrsize;
  real_T c1_arr[81];
  real_T c1_ss;
  real_T c1_padsize;
  real_T c1_tt[256];
  char_T c1_mystr[81];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_myarr256[256];
  int32_T c1_i516;
  static char_T c1_cv47[81] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'w', 'r', 'i',
    's', 't', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't',
    'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '-', '1',
    ',', '0', '.', '1', ',', '0', ',', '0', ')', ')', ';' };

  int32_T c1_i517;
  static real_T c1_dv87[81] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 119.0, 114.0, 105.0,
    115.0, 116.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 45.0, 49.0, 44.0, 48.0, 46.0, 49.0,
    44.0, 48.0, 44.0, 48.0, 41.0, 41.0, 59.0 };

  int32_T c1_i518;
  int32_T c1_i519;
  int32_T c1_i520;
  int32_T c1_i521;
  int32_T c1_i522;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i523;
  int32_T c1_i524;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i525;
  int32_T c1_i526;
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
    c1_d_encStr2Arr(chartInstance, c1_dv86);
    for (c1_i508 = 0; c1_i508 < 256; c1_i508++) {
      c1_poseSBM[c1_i508] = c1_dv86[c1_i508];
    }

    c1_updateDataWrittenToVector(chartInstance, 21U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
    sf_mex_printf("%s =\\n", "poseSBM");
    for (c1_i509 = 0; c1_i509 < 256; c1_i509++) {
      c1_u[c1_i509] = c1_poseSBM[c1_i509];
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
      c1_e_encStr2Arr(chartInstance, c1_dv86);
      for (c1_i510 = 0; c1_i510 < 256; c1_i510++) {
        c1_poseSBM[c1_i510] = c1_dv86[c1_i510];
      }

      c1_updateDataWrittenToVector(chartInstance, 21U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
      sf_mex_printf("%s =\\n", "poseSBM");
      for (c1_i511 = 0; c1_i511 < 256; c1_i511++) {
        c1_b_u[c1_i511] = c1_poseSBM[c1_i511];
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
        c1_f_encStr2Arr(chartInstance, c1_dv86);
        for (c1_i512 = 0; c1_i512 < 256; c1_i512++) {
          c1_poseSBM[c1_i512] = c1_dv86[c1_i512];
        }

        c1_updateDataWrittenToVector(chartInstance, 21U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
        sf_mex_printf("%s =\\n", "poseSBM");
        for (c1_i513 = 0; c1_i513 < 256; c1_i513++) {
          c1_c_u[c1_i513] = c1_poseSBM[c1_i513];
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
          c1_g_encStr2Arr(chartInstance, c1_dv86);
          for (c1_i514 = 0; c1_i514 < 256; c1_i514++) {
            c1_poseSBM[c1_i514] = c1_dv86[c1_i514];
          }

          c1_updateDataWrittenToVector(chartInstance, 21U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
          sf_mex_printf("%s =\\n", "poseSBM");
          for (c1_i515 = 0; c1_i515 < 256; c1_i515++) {
            c1_d_u[c1_i515] = c1_poseSBM[c1_i515];
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
            _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_t_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
              c1_d_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_s_sf_marshallOut);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U,
              c1_b_sf_marshallOut, c1_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
              c1_d_sf_marshallOut, c1_d_sf_marshallIn);
            for (c1_i516 = 0; c1_i516 < 81; c1_i516++) {
              c1_mystr[c1_i516] = c1_cv47[c1_i516];
            }

            CV_SCRIPT_FCN(0, 0);
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
            c1_maxarrsize = 256.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
            for (c1_i517 = 0; c1_i517 < 81; c1_i517++) {
              c1_arr[c1_i517] = c1_dv87[c1_i517];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
            c1_ss = 81.0;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
            c1_padsize = c1_maxarrsize - c1_ss;
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
            for (c1_i518 = 0; c1_i518 < 256; c1_i518++) {
              c1_tt[c1_i518] = 0.0;
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
            for (c1_i519 = 0; c1_i519 < 81; c1_i519++) {
              c1_tt[c1_i519] = c1_arr[c1_i519];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
            for (c1_i520 = 0; c1_i520 < 256; c1_i520++) {
              c1_myarr256[c1_i520] = c1_tt[c1_i520];
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
            _SFD_SYMBOL_SCOPE_POP();
            for (c1_i521 = 0; c1_i521 < 256; c1_i521++) {
              c1_poseSBM[c1_i521] = c1_myarr256[c1_i521];
            }

            c1_updateDataWrittenToVector(chartInstance, 21U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
            sf_mex_printf("%s =\\n", "poseSBM");
            for (c1_i522 = 0; c1_i522 < 256; c1_i522++) {
              c1_e_u[c1_i522] = c1_poseSBM[c1_i522];
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
              c1_h_encStr2Arr(chartInstance, c1_dv86);
              for (c1_i523 = 0; c1_i523 < 256; c1_i523++) {
                c1_poseSBM[c1_i523] = c1_dv86[c1_i523];
              }

              c1_updateDataWrittenToVector(chartInstance, 21U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c1_i524 = 0; c1_i524 < 256; c1_i524++) {
                c1_f_u[c1_i524] = c1_poseSBM[c1_i524];
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
              c1_h_encStr2Arr(chartInstance, c1_dv86);
              for (c1_i525 = 0; c1_i525 < 256; c1_i525++) {
                c1_poseSBM[c1_i525] = c1_dv86[c1_i525];
              }

              c1_updateDataWrittenToVector(chartInstance, 21U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 21U, 35U);
              sf_mex_printf("%s =\\n", "poseSBM");
              for (c1_i526 = 0; c1_i526 < 256; c1_i526++) {
                c1_g_u[c1_i526] = c1_poseSBM[c1_i526];
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

static void c1_idlePose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_poseBML[256])
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
  real_T c1_dv88[256];
  int32_T c1_i527;
  int32_T c1_i528;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  int32_T c1_i529;
  int32_T c1_i530;
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
  int32_T c1_i531;
  static char_T c1_cv48[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c1_i532;
  static real_T c1_dv89[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c1_i533;
  int32_T c1_i534;
  int32_T c1_i535;
  int32_T c1_i536;
  int32_T c1_i537;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i538;
  int32_T c1_i539;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i540;
  int32_T c1_i541;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  int32_T c1_i542;
  int32_T c1_i543;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i544;
  int32_T c1_i545;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  int32_T c1_i546;
  int32_T c1_i547;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  int32_T c1_i548;
  int32_T c1_i549;
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
    c1_i_encStr2Arr(chartInstance, c1_dv88);
    for (c1_i527 = 0; c1_i527 < 256; c1_i527++) {
      c1_poseBML[c1_i527] = c1_dv88[c1_i527];
    }

    c1_updateDataWrittenToVector(chartInstance, 22U);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
    sf_mex_printf("%s =\\n", "poseBML");
    for (c1_i528 = 0; c1_i528 < 256; c1_i528++) {
      c1_u[c1_i528] = c1_poseBML[c1_i528];
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
      c1_j_encStr2Arr(chartInstance, c1_dv88);
      for (c1_i529 = 0; c1_i529 < 256; c1_i529++) {
        c1_poseBML[c1_i529] = c1_dv88[c1_i529];
      }

      c1_updateDataWrittenToVector(chartInstance, 22U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
      sf_mex_printf("%s =\\n", "poseBML");
      for (c1_i530 = 0; c1_i530 < 256; c1_i530++) {
        c1_b_u[c1_i530] = c1_poseBML[c1_i530];
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
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_arr, 1U, c1_cb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ss, 2U, c1_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_padsize, 3U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_tt, 4U, c1_d_sf_marshallOut,
          c1_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c1_mystr, 5U, c1_bb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 6U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 7U,
          c1_b_sf_marshallOut, c1_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_myarr256, 8U,
          c1_d_sf_marshallOut, c1_d_sf_marshallIn);
        for (c1_i531 = 0; c1_i531 < 68; c1_i531++) {
          c1_mystr[c1_i531] = c1_cv48[c1_i531];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
        c1_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
        for (c1_i532 = 0; c1_i532 < 68; c1_i532++) {
          c1_arr[c1_i532] = c1_dv89[c1_i532];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
        c1_ss = 68.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
        c1_padsize = c1_maxarrsize - c1_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
        for (c1_i533 = 0; c1_i533 < 256; c1_i533++) {
          c1_tt[c1_i533] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
        for (c1_i534 = 0; c1_i534 < 68; c1_i534++) {
          c1_tt[c1_i534] = c1_arr[c1_i534];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 11);
        for (c1_i535 = 0; c1_i535 < 256; c1_i535++) {
          c1_myarr256[c1_i535] = c1_tt[c1_i535];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c1_i536 = 0; c1_i536 < 256; c1_i536++) {
          c1_poseBML[c1_i536] = c1_myarr256[c1_i536];
        }

        c1_updateDataWrittenToVector(chartInstance, 22U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
        sf_mex_printf("%s =\\n", "poseBML");
        for (c1_i537 = 0; c1_i537 < 256; c1_i537++) {
          c1_c_u[c1_i537] = c1_poseBML[c1_i537];
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
          c1_k_encStr2Arr(chartInstance, c1_dv88);
          for (c1_i538 = 0; c1_i538 < 256; c1_i538++) {
            c1_poseBML[c1_i538] = c1_dv88[c1_i538];
          }

          c1_updateDataWrittenToVector(chartInstance, 22U);
          c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
          sf_mex_printf("%s =\\n", "poseBML");
          for (c1_i539 = 0; c1_i539 < 256; c1_i539++) {
            c1_d_u[c1_i539] = c1_poseBML[c1_i539];
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
            c1_l_encStr2Arr(chartInstance, c1_dv88);
            for (c1_i540 = 0; c1_i540 < 256; c1_i540++) {
              c1_poseBML[c1_i540] = c1_dv88[c1_i540];
            }

            c1_updateDataWrittenToVector(chartInstance, 22U);
            c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
            sf_mex_printf("%s =\\n", "poseBML");
            for (c1_i541 = 0; c1_i541 < 256; c1_i541++) {
              c1_e_u[c1_i541] = c1_poseBML[c1_i541];
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
              c1_m_encStr2Arr(chartInstance, c1_dv88);
              for (c1_i542 = 0; c1_i542 < 256; c1_i542++) {
                c1_poseBML[c1_i542] = c1_dv88[c1_i542];
              }

              c1_updateDataWrittenToVector(chartInstance, 22U);
              c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
              sf_mex_printf("%s =\\n", "poseBML");
              for (c1_i543 = 0; c1_i543 < 256; c1_i543++) {
                c1_f_u[c1_i543] = c1_poseBML[c1_i543];
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
                c1_n_encStr2Arr(chartInstance, c1_dv88);
                for (c1_i544 = 0; c1_i544 < 256; c1_i544++) {
                  c1_poseBML[c1_i544] = c1_dv88[c1_i544];
                }

                c1_updateDataWrittenToVector(chartInstance, 22U);
                c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
                sf_mex_printf("%s =\\n", "poseBML");
                for (c1_i545 = 0; c1_i545 < 256; c1_i545++) {
                  c1_g_u[c1_i545] = c1_poseBML[c1_i545];
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
                  c1_o_encStr2Arr(chartInstance, c1_dv88);
                  for (c1_i546 = 0; c1_i546 < 256; c1_i546++) {
                    c1_poseBML[c1_i546] = c1_dv88[c1_i546];
                  }

                  c1_updateDataWrittenToVector(chartInstance, 22U);
                  c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i547 = 0; c1_i547 < 256; c1_i547++) {
                    c1_h_u[c1_i547] = c1_poseBML[c1_i547];
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
                  c1_o_encStr2Arr(chartInstance, c1_dv88);
                  for (c1_i548 = 0; c1_i548 < 256; c1_i548++) {
                    c1_poseBML[c1_i548] = c1_dv88[c1_i548];
                  }

                  c1_updateDataWrittenToVector(chartInstance, 22U);
                  c1_errorIfDataNotWrittenToFcn(chartInstance, 22U, 37U);
                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c1_i549 = 0; c1_i549 < 256; c1_i549++) {
                    c1_i_u[c1_i549] = c1_poseBML[c1_i549];
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

static void c1_boredGaze(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, real_T c1_bmlID, real_T c1_gazeBML[256])
{
  uint32_T c1_debug_family_var_map[22];
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
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_dv90[256];
  int32_T c1_i550;
  int32_T c1_i551;
  real_T c1_u[256];
  const mxArray *c1_y = NULL;
  real_T c1_dv91[256];
  int32_T c1_i552;
  int32_T c1_i553;
  real_T c1_b_u[256];
  const mxArray *c1_b_y = NULL;
  real_T c1_dv92[256];
  int32_T c1_i554;
  int32_T c1_i555;
  real_T c1_c_u[256];
  const mxArray *c1_c_y = NULL;
  real_T c1_dv93[256];
  int32_T c1_i556;
  int32_T c1_i557;
  real_T c1_d_u[256];
  const mxArray *c1_d_y = NULL;
  real_T c1_dv94[256];
  int32_T c1_i558;
  int32_T c1_i559;
  real_T c1_e_u[256];
  const mxArray *c1_e_y = NULL;
  real_T c1_dv95[256];
  int32_T c1_i560;
  int32_T c1_i561;
  real_T c1_f_u[256];
  const mxArray *c1_f_y = NULL;
  real_T c1_dv96[256];
  int32_T c1_i562;
  int32_T c1_i563;
  real_T c1_g_u[256];
  const mxArray *c1_g_y = NULL;
  real_T c1_dv97[256];
  int32_T c1_i564;
  int32_T c1_i565;
  real_T c1_h_u[256];
  const mxArray *c1_h_y = NULL;
  real_T c1_dv98[256];
  int32_T c1_i566;
  int32_T c1_i567;
  real_T c1_i_u[256];
  const mxArray *c1_i_y = NULL;
  real_T c1_dv99[256];
  int32_T c1_i568;
  int32_T c1_i569;
  real_T c1_j_u[256];
  const mxArray *c1_j_y = NULL;
  real_T c1_dv100[256];
  int32_T c1_i570;
  int32_T c1_i571;
  real_T c1_k_u[256];
  const mxArray *c1_k_y = NULL;
  real_T c1_dv101[256];
  int32_T c1_i572;
  int32_T c1_i573;
  real_T c1_l_u[256];
  const mxArray *c1_l_y = NULL;
  real_T c1_dv102[256];
  int32_T c1_i574;
  int32_T c1_i575;
  real_T c1_m_u[256];
  const mxArray *c1_m_y = NULL;
  real_T c1_dv103[256];
  int32_T c1_i576;
  int32_T c1_i577;
  real_T c1_n_u[256];
  const mxArray *c1_n_y = NULL;
  real_T c1_dv104[256];
  int32_T c1_i578;
  int32_T c1_i579;
  real_T c1_o_u[256];
  const mxArray *c1_o_y = NULL;
  real_T c1_dv105[256];
  int32_T c1_i580;
  int32_T c1_i581;
  real_T c1_p_u[256];
  const mxArray *c1_p_y = NULL;
  real_T c1_dv106[256];
  int32_T c1_i582;
  int32_T c1_i583;
  real_T c1_q_u[256];
  const mxArray *c1_q_y = NULL;
  real_T c1_dv107[256];
  int32_T c1_i584;
  int32_T c1_i585;
  real_T c1_r_u[256];
  const mxArray *c1_r_y = NULL;
  real_T c1_dv108[256];
  int32_T c1_i586;
  int32_T c1_i587;
  real_T c1_s_u[256];
  const mxArray *c1_s_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c1_cc_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 19U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bmlID, 20U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_gazeBML, 21U, c1_d_sf_marshallOut,
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
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 24);
  c1_aVarTruthTableCondition_1 = (c1_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 27);
  c1_aVarTruthTableCondition_2 = (c1_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 30);
  c1_aVarTruthTableCondition_3 = (c1_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 33);
  c1_aVarTruthTableCondition_4 = (c1_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 36);
  c1_aVarTruthTableCondition_5 = (c1_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 39);
  c1_aVarTruthTableCondition_6 = (c1_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 42);
  c1_aVarTruthTableCondition_7 = (c1_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 45);
  c1_aVarTruthTableCondition_8 = (c1_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 48);
  c1_aVarTruthTableCondition_9 = (c1_bmlID == 9.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 51);
  c1_aVarTruthTableCondition_10 = (c1_bmlID == 10.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 54);
  c1_aVarTruthTableCondition_11 = (c1_bmlID == 11.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 57);
  c1_aVarTruthTableCondition_12 = (c1_bmlID == 12.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 60);
  c1_aVarTruthTableCondition_13 = (c1_bmlID == 13.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 63);
  c1_aVarTruthTableCondition_14 = (c1_bmlID == 14.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 66);
  c1_aVarTruthTableCondition_15 = (c1_bmlID == 15.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 69);
  c1_aVarTruthTableCondition_16 = (c1_bmlID == 16.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 72);
  c1_aVarTruthTableCondition_17 = (c1_bmlID == 17.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 75);
  c1_aVarTruthTableCondition_18 = (c1_bmlID == 18.0);
  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 77);
  if (CV_EML_IF(1, 1, 0, c1_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 78);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 121);
    c1_p_encStr2Arr(chartInstance, c1_dv90);
    for (c1_i550 = 0; c1_i550 < 256; c1_i550++) {
      c1_gazeBML[c1_i550] = c1_dv90[c1_i550];
    }

    sf_mex_printf("%s =\\n", "gazeBML");
    for (c1_i551 = 0; c1_i551 < 256; c1_i551++) {
      c1_u[c1_i551] = c1_gazeBML[c1_i551];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -121);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 79);
    if (CV_EML_IF(1, 1, 1, c1_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 80);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, MAX_int8_T);
      c1_q_encStr2Arr(chartInstance, c1_dv91);
      for (c1_i552 = 0; c1_i552 < 256; c1_i552++) {
        c1_gazeBML[c1_i552] = c1_dv91[c1_i552];
      }

      sf_mex_printf("%s =\\n", "gazeBML");
      for (c1_i553 = 0; c1_i553 < 256; c1_i553++) {
        c1_b_u[c1_i553] = c1_gazeBML[c1_i553];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -127);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 81);
      if (CV_EML_IF(1, 1, 2, c1_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 82);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 133U);
        c1_r_encStr2Arr(chartInstance, c1_dv92);
        for (c1_i554 = 0; c1_i554 < 256; c1_i554++) {
          c1_gazeBML[c1_i554] = c1_dv92[c1_i554];
        }

        sf_mex_printf("%s =\\n", "gazeBML");
        for (c1_i555 = 0; c1_i555 < 256; c1_i555++) {
          c1_c_u[c1_i555] = c1_gazeBML[c1_i555];
        }

        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -133);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 83);
        if (CV_EML_IF(1, 1, 3, c1_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 84);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 139U);
          c1_s_encStr2Arr(chartInstance, c1_dv93);
          for (c1_i556 = 0; c1_i556 < 256; c1_i556++) {
            c1_gazeBML[c1_i556] = c1_dv93[c1_i556];
          }

          sf_mex_printf("%s =\\n", "gazeBML");
          for (c1_i557 = 0; c1_i557 < 256; c1_i557++) {
            c1_d_u[c1_i557] = c1_gazeBML[c1_i557];
          }

          c1_d_y = NULL;
          sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c1_d_y);
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -139);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 85);
          if (CV_EML_IF(1, 1, 4, c1_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 86);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 145U);
            c1_t_encStr2Arr(chartInstance, c1_dv94);
            for (c1_i558 = 0; c1_i558 < 256; c1_i558++) {
              c1_gazeBML[c1_i558] = c1_dv94[c1_i558];
            }

            sf_mex_printf("%s =\\n", "gazeBML");
            for (c1_i559 = 0; c1_i559 < 256; c1_i559++) {
              c1_e_u[c1_i559] = c1_gazeBML[c1_i559];
            }

            c1_e_y = NULL;
            sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c1_e_y);
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -145);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 87);
            if (CV_EML_IF(1, 1, 5, c1_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 88);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 151U);
              c1_u_encStr2Arr(chartInstance, c1_dv95);
              for (c1_i560 = 0; c1_i560 < 256; c1_i560++) {
                c1_gazeBML[c1_i560] = c1_dv95[c1_i560];
              }

              sf_mex_printf("%s =\\n", "gazeBML");
              for (c1_i561 = 0; c1_i561 < 256; c1_i561++) {
                c1_f_u[c1_i561] = c1_gazeBML[c1_i561];
              }

              c1_f_y = NULL;
              sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c1_f_y);
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -151);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 89);
              if (CV_EML_IF(1, 1, 6, c1_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 90);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 157U);
                c1_v_encStr2Arr(chartInstance, c1_dv96);
                for (c1_i562 = 0; c1_i562 < 256; c1_i562++) {
                  c1_gazeBML[c1_i562] = c1_dv96[c1_i562];
                }

                sf_mex_printf("%s =\\n", "gazeBML");
                for (c1_i563 = 0; c1_i563 < 256; c1_i563++) {
                  c1_g_u[c1_i563] = c1_gazeBML[c1_i563];
                }

                c1_g_y = NULL;
                sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c1_g_y);
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -157);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 91);
                if (CV_EML_IF(1, 1, 7, c1_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 92);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 163U);
                  c1_w_encStr2Arr(chartInstance, c1_dv97);
                  for (c1_i564 = 0; c1_i564 < 256; c1_i564++) {
                    c1_gazeBML[c1_i564] = c1_dv97[c1_i564];
                  }

                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c1_i565 = 0; c1_i565 < 256; c1_i565++) {
                    c1_h_u[c1_i565] = c1_gazeBML[c1_i565];
                  }

                  c1_h_y = NULL;
                  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c1_h_y);
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -163);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 93);
                  if (CV_EML_IF(1, 1, 8, c1_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 94);
                    CV_EML_FCN(1, 9);
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 169U);
                    c1_x_encStr2Arr(chartInstance, c1_dv98);
                    for (c1_i566 = 0; c1_i566 < 256; c1_i566++) {
                      c1_gazeBML[c1_i566] = c1_dv98[c1_i566];
                    }

                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c1_i567 = 0; c1_i567 < 256; c1_i567++) {
                      c1_i_u[c1_i567] = c1_gazeBML[c1_i567];
                    }

                    c1_i_y = NULL;
                    sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c1_i_y);
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -169);
                  } else {
                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 95);
                    if (CV_EML_IF(1, 1, 9, c1_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 96);
                      CV_EML_FCN(1, 10);
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 175U);
                      c1_y_encStr2Arr(chartInstance, c1_dv99);
                      for (c1_i568 = 0; c1_i568 < 256; c1_i568++) {
                        c1_gazeBML[c1_i568] = c1_dv99[c1_i568];
                      }

                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c1_i569 = 0; c1_i569 < 256; c1_i569++) {
                        c1_j_u[c1_i569] = c1_gazeBML[c1_i569];
                      }

                      c1_j_y = NULL;
                      sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c1_j_y);
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 97);
                      if (CV_EML_IF(1, 1, 10, c1_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 98);
                        CV_EML_FCN(1, 11);
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 181U);
                        c1_ab_encStr2Arr(chartInstance, c1_dv100);
                        for (c1_i570 = 0; c1_i570 < 256; c1_i570++) {
                          c1_gazeBML[c1_i570] = c1_dv100[c1_i570];
                        }

                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c1_i571 = 0; c1_i571 < 256; c1_i571++) {
                          c1_k_u[c1_i571] = c1_gazeBML[c1_i571];
                        }

                        c1_k_y = NULL;
                        sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c1_k_y);
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 99);
                        if (CV_EML_IF(1, 1, 11, c1_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 100);
                          CV_EML_FCN(1, 12);
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 187U);
                          c1_bb_encStr2Arr(chartInstance, c1_dv101);
                          for (c1_i572 = 0; c1_i572 < 256; c1_i572++) {
                            c1_gazeBML[c1_i572] = c1_dv101[c1_i572];
                          }

                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c1_i573 = 0; c1_i573 < 256; c1_i573++) {
                            c1_l_u[c1_i573] = c1_gazeBML[c1_i573];
                          }

                          c1_l_y = NULL;
                          sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c1_l_y);
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -187);
                        } else {
                          _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 101);
                          if (CV_EML_IF(1, 1, 12, c1_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 102);
                            CV_EML_FCN(1, 13);
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 193U);
                            c1_cb_encStr2Arr(chartInstance, c1_dv102);
                            for (c1_i574 = 0; c1_i574 < 256; c1_i574++) {
                              c1_gazeBML[c1_i574] = c1_dv102[c1_i574];
                            }

                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c1_i575 = 0; c1_i575 < 256; c1_i575++) {
                              c1_m_u[c1_i575] = c1_gazeBML[c1_i575];
                            }

                            c1_m_y = NULL;
                            sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c1_m_y);
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -193);
                          } else {
                            _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 103);
                            if (CV_EML_IF(1, 1, 13,
                                          c1_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 104);
                              CV_EML_FCN(1, 14);
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 199U);
                              c1_db_encStr2Arr(chartInstance, c1_dv103);
                              for (c1_i576 = 0; c1_i576 < 256; c1_i576++) {
                                c1_gazeBML[c1_i576] = c1_dv103[c1_i576];
                              }

                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c1_i577 = 0; c1_i577 < 256; c1_i577++) {
                                c1_n_u[c1_i577] = c1_gazeBML[c1_i577];
                              }

                              c1_n_y = NULL;
                              sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c1_n_y);
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -199);
                            } else {
                              _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 105);
                              if (CV_EML_IF(1, 1, 14,
                                            c1_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 106);
                                CV_EML_FCN(1, 15);
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              205U);
                                c1_eb_encStr2Arr(chartInstance, c1_dv104);
                                for (c1_i578 = 0; c1_i578 < 256; c1_i578++) {
                                  c1_gazeBML[c1_i578] = c1_dv104[c1_i578];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c1_i579 = 0; c1_i579 < 256; c1_i579++) {
                                  c1_o_u[c1_i579] = c1_gazeBML[c1_i579];
                                }

                                c1_o_y = NULL;
                                sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c1_o_y);
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                              -205);
                              } else {
                                _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, 107);
                                if (CV_EML_IF(1, 1, 15,
                                              c1_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                108);
                                  CV_EML_FCN(1, 16);
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                211U);
                                  c1_fb_encStr2Arr(chartInstance, c1_dv105);
                                  for (c1_i580 = 0; c1_i580 < 256; c1_i580++) {
                                    c1_gazeBML[c1_i580] = c1_dv105[c1_i580];
                                  }

                                  sf_mex_printf("%s =\\n", "gazeBML");
                                  for (c1_i581 = 0; c1_i581 < 256; c1_i581++) {
                                    c1_p_u[c1_i581] = c1_gazeBML[c1_i581];
                                  }

                                  c1_p_y = NULL;
                                  sf_mex_assign(&c1_p_y, sf_mex_create("y",
                                    c1_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c1_p_y);
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                -211);
                                } else {
                                  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                109);
                                  if (CV_EML_IF(1, 1, 16,
                                                c1_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  110);
                                    CV_EML_FCN(1, 19);
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  229U);
                                    c1_gb_encStr2Arr(chartInstance, c1_dv106);
                                    for (c1_i582 = 0; c1_i582 < 256; c1_i582++)
                                    {
                                      c1_gazeBML[c1_i582] = c1_dv106[c1_i582];
                                    }

                                    sf_mex_printf("%s =\\n", "gazeBML");
                                    for (c1_i583 = 0; c1_i583 < 256; c1_i583++)
                                    {
                                      c1_q_u[c1_i583] = c1_gazeBML[c1_i583];
                                    }

                                    c1_q_y = NULL;
                                    sf_mex_assign(&c1_q_y, sf_mex_create("y",
                                      c1_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c1_q_y);
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  -229);
                                  } else {
                                    _SFD_EML_CALL(1U, chartInstance->c1_sfEvent,
                                                  111);
                                    if (CV_EML_IF(1, 1, 17,
                                                  c1_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    112);
                                      CV_EML_FCN(1, 26);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    271);
                                      c1_hb_encStr2Arr(chartInstance, c1_dv107);
                                      for (c1_i584 = 0; c1_i584 < 256; c1_i584++)
                                      {
                                        c1_gazeBML[c1_i584] = c1_dv107[c1_i584];
                                      }

                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c1_i585 = 0; c1_i585 < 256; c1_i585++)
                                      {
                                        c1_r_u[c1_i585] = c1_gazeBML[c1_i585];
                                      }

                                      c1_r_y = NULL;
                                      sf_mex_assign(&c1_r_y, sf_mex_create("y",
                                        c1_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c1_r_y);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    -271);
                                    } else {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    114);
                                      CV_EML_FCN(1, 1);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
                                                    121);
                                      c1_p_encStr2Arr(chartInstance, c1_dv108);
                                      for (c1_i586 = 0; c1_i586 < 256; c1_i586++)
                                      {
                                        c1_gazeBML[c1_i586] = c1_dv108[c1_i586];
                                      }

                                      sf_mex_printf("%s =\\n", "gazeBML");
                                      for (c1_i587 = 0; c1_i587 < 256; c1_i587++)
                                      {
                                        c1_s_u[c1_i587] = c1_gazeBML[c1_i587];
                                      }

                                      c1_s_y = NULL;
                                      sf_mex_assign(&c1_s_y, sf_mex_create("y",
                                        c1_s_u, 0, 0U, 1U, 0U, 1, 256), false);
                                      sf_mex_call_debug
                                        (sfGlobalDebugInstanceStruct, "disp", 0U,
                                         1U, 14, c1_s_y);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c1_sfEvent,
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

  _SFD_EML_CALL(1U, chartInstance->c1_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c1_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i588;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i588, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i588;
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
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

static const mxArray *c1_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i589;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i589, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i589;
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
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

static const mxArray *c1_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[625])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_o_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[625])
{
  uint32_T c1_uv3[625];
  int32_T c1_i590;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_c_state_not_empty = false;
  } else {
    chartInstance->c1_c_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c1_i590 = 0; c1_i590 < 625; c1_i590++) {
      c1_y[c1_i590] = c1_uv3[c1_i590];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_p_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_d_state, const char_T *c1_identifier, uint32_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d_state), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d_state);
}

static void c1_q_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, uint32_T c1_y[2])
{
  uint32_T c1_uv4[2];
  int32_T c1_i591;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_b_state_not_empty = false;
  } else {
    chartInstance->c1_b_state_not_empty = true;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c1_i591 = 0; c1_i591 < 2; c1_i591++) {
      c1_y[c1_i591] = c1_uv4[c1_i591];
    }
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
   mxArray *c1_c_subchartSimStateInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_c_subchartSimStateInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_c_subchartSimStateInfo);
  return c1_y;
}

static const mxArray *c1_s_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, const
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
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 26, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 26, 1,
    0)]);
}

static void c1_b_twister_state_vector
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_mt[625], real_T c1_seed)
{
  real_T c1_d5;
  uint32_T c1_u6;
  uint32_T c1_b_r;
  int32_T c1_mti;
  real_T c1_b_mti;
  real_T c1_d6;
  uint32_T c1_u7;
  (void)chartInstance;
  c1_d5 = c1_seed;
  if (c1_d5 < 4.294967296E+9) {
    if (c1_d5 >= 0.0) {
      c1_u6 = (uint32_T)c1_d5;
    } else {
      c1_u6 = 0U;
    }
  } else if (c1_d5 >= 4.294967296E+9) {
    c1_u6 = MAX_uint32_T;
  } else {
    c1_u6 = 0U;
  }

  c1_b_r = c1_u6;
  c1_mt[0] = c1_b_r;
  for (c1_mti = 0; c1_mti < 623; c1_mti++) {
    c1_b_mti = 2.0 + (real_T)c1_mti;
    c1_d6 = muDoubleScalarRound(c1_b_mti - 1.0);
    if (c1_d6 < 4.294967296E+9) {
      if (c1_d6 >= 0.0) {
        c1_u7 = (uint32_T)c1_d6;
      } else {
        c1_u7 = 0U;
      }
    } else if (c1_d6 >= 4.294967296E+9) {
      c1_u7 = MAX_uint32_T;
    } else {
      c1_u7 = 0U;
    }

    c1_b_r = (c1_b_r ^ c1_b_r >> 30U) * 1812433253U + c1_u7;
    c1_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_mti), 1, 625, 1, 0) - 1] = c1_b_r;
  }

  c1_mt[624] = 624U;
}

static real_T c1_c_eml_rand_mt19937ar
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_d_state[625])
{
  int32_T c1_i592;
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
    for (c1_i592 = 0; c1_i592 < 2; c1_i592++) {
      c1_u[c1_i592] = 0U;
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

static real_T c1_get_BOREDOMT
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#1013) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BOREDOMT_address;
}

static void c1_set_BOREDOMT(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#1013) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BOREDOMT_address = c1_c;
}

static real_T *c1_access_BOREDOMT
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#1013) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BOREDOMT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static real_T c1_get_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#1017) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_b_address;
}

static void c1_set_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#1017) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_b_address = c1_c;
}

static real_T *c1_access_b(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#1017) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_b_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static real_T c1_get_bored(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#1012) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bored_address;
}

static void c1_set_bored(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#1012) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bored_address = c1_c;
}

static real_T *c1_access_bored
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#1012) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bored_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#1016) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_address;
}

static void c1_set_pose(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#1016) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_address = c1_c;
}

static real_T *c1_access_pose
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#1016) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomD
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#1021) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomD_address;
}

static void c1_set_randomD(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#1021) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomD_address = c1_c;
}

static real_T *c1_access_randomD
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#1021) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomG
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#1014) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomG_address;
}

static void c1_set_randomG(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#1014) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomG_address = c1_c;
}

static real_T *c1_access_randomG
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#1014) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomG_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomP
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#1015) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomP_address;
}

static void c1_set_randomP(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *
  chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#1015) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomP_address = c1_c;
}

static real_T *c1_access_randomP
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance, uint32_T
   c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#1015) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomP_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info
  (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c1_BOREDOMT_address, &chartInstance->c1_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c1_b_address, &chartInstance->c1_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c1_bored_address, &chartInstance->c1_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c1_pose_address, &chartInstance->c1_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomD", (void **)
    &chartInstance->c1_randomD_address, &chartInstance->c1_randomD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomG", (void **)
    &chartInstance->c1_randomG_address, &chartInstance->c1_randomG_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c1_randomP_address, &chartInstance->c1_randomP_index);
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

void sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1147249860U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2986993749U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3471843603U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(817110280U);
}

mxArray *sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NOTDFrQyPk5YMSc0AA1omB");
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,18,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ARP_02_RPSsmile_Glove_atomicError_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ARP_02_RPSsmile_Glove_atomicError_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_ARP_02_RPSsmile_Glove_atomicError
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[713],T\"round\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[568],T\"BOREDOMT\",},{M[3],M[641],T\"b\",},{M[3],M[468],T\"bHand\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[567],T\"bored\",},{M[3],M[462],T\"diff\",},{M[3],M[660],T\"p\",},{M[3],M[636],T\"pose\",},{M[3],M[659],T\"r\",},{M[3],M[688],T\"randomD\",},{M[3],M[596],T\"randomG\",},{M[3],M[701],T\"randomH\",},{M[3],M[635],T\"randomP\",},{M[3],M[661],T\"s\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[482],T\"smileN\",},{M[3],M[566],T\"smileYN\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[3],M[689],T\"wristRotate\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c1_ARP_02_RPSsmile_Glove_atomicError\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[8],M[618],T\"is_active_stateGame\",},{M[8],M[730],T\"is_active_stateIdleGaze\",},{M[8],M[731],T\"is_active_stateIdlePose\",},{M[9],M[618],T\"is_stateGame\",},{M[11],M[510],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x13[432 439 578 722 440 716 654 653 495 449 430 714 571],M[1]}}},{M[14],M[730],T\"subchartSimStateInfo\",},{M[14],M[731],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 37, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ARP_02_RPSsmile_Glove_atomicError_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
           1,
           44,
           48,
           0,
           46,
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
          (_ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
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
          _SFD_SET_DATA_PROPS(15,0,0,0,"randomG");
          _SFD_SET_DATA_PROPS(16,0,0,0,"randomP");
          _SFD_SET_DATA_PROPS(17,0,0,0,"pose");
          _SFD_SET_DATA_PROPS(18,0,0,0,"b");
          _SFD_SET_DATA_PROPS(19,0,0,0,"r");
          _SFD_SET_DATA_PROPS(20,0,0,0,"p");
          _SFD_SET_DATA_PROPS(21,0,0,0,"s");
          _SFD_SET_DATA_PROPS(22,0,0,0,"randomD");
          _SFD_SET_DATA_PROPS(23,0,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(24,0,0,0,"randomH");
          _SFD_SET_DATA_PROPS(25,2,0,1,"round");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
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
          _SFD_SET_DATA_PROPS(40,8,0,0,"");
          _SFD_SET_DATA_PROPS(41,9,0,0,"");
          _SFD_SET_DATA_PROPS(42,8,0,0,"");
          _SFD_SET_DATA_PROPS(43,9,0,0,"");
          _SFD_SET_DATA_PROPS(44,8,0,0,"");
          _SFD_SET_DATA_PROPS(45,9,0,0,"");
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
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,0);
          _SFD_STATE_INFO(42,0,1);
          _SFD_STATE_INFO(43,0,1);
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
          _SFD_CH_SUBSTATE_INDEX(1,42);
          _SFD_CH_SUBSTATE_INDEX(2,43);
          _SFD_ST_SUBSTATE_COUNT(11,30);
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
          _SFD_ST_SUBSTATE_INDEX(11,23,35);
          _SFD_ST_SUBSTATE_INDEX(11,24,36);
          _SFD_ST_SUBSTATE_INDEX(11,25,37);
          _SFD_ST_SUBSTATE_INDEX(11,26,38);
          _SFD_ST_SUBSTATE_INDEX(11,27,39);
          _SFD_ST_SUBSTATE_INDEX(11,28,40);
          _SFD_ST_SUBSTATE_INDEX(11,29,41);
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
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(41,0);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(11,30,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
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
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);

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
        _SFD_CV_INIT_EML(1,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"boredGaze",0,-1,2810);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",2810,-1,2996);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",2996,-1,3184);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",3184,-1,3366);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",3366,-1,3552);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",3552,-1,3742);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",3742,-1,3934);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",3934,-1,4128);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",4128,-1,4324);
        _SFD_CV_INIT_EML_FCN(1,9,"aFcnTruthTableAction_9",4324,-1,4524);
        _SFD_CV_INIT_EML_FCN(1,10,"aFcnTruthTableAction_10",4524,-1,4733);
        _SFD_CV_INIT_EML_FCN(1,11,"aFcnTruthTableAction_11",4733,-1,4944);
        _SFD_CV_INIT_EML_FCN(1,12,"aFcnTruthTableAction_12",4944,-1,5151);
        _SFD_CV_INIT_EML_FCN(1,13,"aFcnTruthTableAction_13",5151,-1,5356);
        _SFD_CV_INIT_EML_FCN(1,14,"aFcnTruthTableAction_14",5356,-1,5553);
        _SFD_CV_INIT_EML_FCN(1,15,"aFcnTruthTableAction_15",5553,-1,5756);
        _SFD_CV_INIT_EML_FCN(1,16,"aFcnTruthTableAction_16",5756,-1,5957);
        _SFD_CV_INIT_EML_FCN(1,17,"aFcnTruthTableAction_17",5957,-1,6170);
        _SFD_CV_INIT_EML_FCN(1,18,"aFcnTruthTableAction_18",6170,-1,6385);
        _SFD_CV_INIT_EML_FCN(1,19,"aFcnTruthTableAction_19",6385,-1,6599);
        _SFD_CV_INIT_EML_FCN(1,20,"aFcnTruthTableAction_20",6599,-1,6812);
        _SFD_CV_INIT_EML_FCN(1,21,"aFcnTruthTableAction_21",6812,-1,7029);
        _SFD_CV_INIT_EML_FCN(1,22,"aFcnTruthTableAction_22",7029,-1,7248);
        _SFD_CV_INIT_EML_FCN(1,23,"aFcnTruthTableAction_23",7248,-1,7469);
        _SFD_CV_INIT_EML_FCN(1,24,"aFcnTruthTableAction_24",7469,-1,7692);
        _SFD_CV_INIT_EML_FCN(1,25,"aFcnTruthTableAction_25",7692,-1,7858);
        _SFD_CV_INIT_EML_FCN(1,26,"aFcnTruthTableAction_26",7858,-1,8155);
        _SFD_CV_INIT_EML_IF(1,1,0,1576,1606,1637,2808);
        _SFD_CV_INIT_EML_IF(1,1,1,1637,1671,1702,2808);
        _SFD_CV_INIT_EML_IF(1,1,2,1702,1736,1767,2808);
        _SFD_CV_INIT_EML_IF(1,1,3,1767,1801,1832,2808);
        _SFD_CV_INIT_EML_IF(1,1,4,1832,1866,1897,2808);
        _SFD_CV_INIT_EML_IF(1,1,5,1897,1931,1962,2808);
        _SFD_CV_INIT_EML_IF(1,1,6,1962,1996,2027,2808);
        _SFD_CV_INIT_EML_IF(1,1,7,2027,2061,2092,2808);
        _SFD_CV_INIT_EML_IF(1,1,8,2092,2126,2157,2808);
        _SFD_CV_INIT_EML_IF(1,1,9,2157,2192,2224,2808);
        _SFD_CV_INIT_EML_IF(1,1,10,2224,2259,2291,2808);
        _SFD_CV_INIT_EML_IF(1,1,11,2291,2326,2358,2808);
        _SFD_CV_INIT_EML_IF(1,1,12,2358,2393,2425,2808);
        _SFD_CV_INIT_EML_IF(1,1,13,2425,2460,2492,2808);
        _SFD_CV_INIT_EML_IF(1,1,14,2492,2527,2559,2808);
        _SFD_CV_INIT_EML_IF(1,1,15,2559,2594,2626,2808);
        _SFD_CV_INIT_EML_IF(1,1,16,2626,2661,2693,2808);
        _SFD_CV_INIT_EML_IF(1,1,17,2693,2728,2760,2808);
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
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(41,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(40,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(37,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(40,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(40,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

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
        _SFD_CV_INIT_EML(45,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(42,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(42,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(43,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(43,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(30,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(30,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(29,0,0,0,22,0,22);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(29,0,0,0,22,2,0,&(condStart[0]),&(condEnd[0]),3,
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

        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,1,15,1,15);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,15,1,15);
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
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,0,13,0,13);
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

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

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

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(43,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

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
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));

        {
          real_T *c1_gameState;
          real_T *c1_inputUser;
          real_T *c1_bradHand;
          real_T *c1_userHand;
          real_T *c1_win;
          real_T *c1_bWinT;
          real_T *c1_uWinT;
          real_T *c1_round;
          c1_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
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
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c1_bored_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c1_BOREDOMT_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c1_randomG_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c1_randomP_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c1_pose_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c1_b_address);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c1_r);
          _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c1_p);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c1_s);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c1_randomD_address);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c1_wristRotate);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c1_randomH);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_round);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_Glove_atomicErrorMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tFqMVFJB0pnRoSSXJBEClB";
}

static void sf_opaque_initialize_c1_ARP_02_RPSsmile_Glove_atomicError(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
  initialize_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ARP_02_RPSsmile_Glove_atomicError(void
  *chartInstanceVar)
{
  enable_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ARP_02_RPSsmile_Glove_atomicError(void
  *chartInstanceVar)
{
  disable_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ARP_02_RPSsmile_Glove_atomicError(void
  *chartInstanceVar)
{
  sf_gateway_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_Glove_atomicError();/* state var info */
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

extern void sf_internal_set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
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
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_Glove_atomicError();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError(S);
}

static void sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError(S, st);
}

static void sf_opaque_terminate_c1_ARP_02_RPSsmile_Glove_atomicError(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_Glove_atomicError_optimization_info();
    }

    finalize_c1_ARP_02_RPSsmile_Glove_atomicError
      ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ARP_02_RPSsmile_Glove_atomicError
    ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct *
  S)
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
    initialize_params_c1_ARP_02_RPSsmile_Glove_atomicError
      ((SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ARP_02_RPSsmile_Glove_atomicError_optimization_info();
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
        infoStruct,1,9);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2721507125U));
  ssSetChecksum1(S,(3748336747U));
  ssSetChecksum2(S,(3325928634U));
  ssSetChecksum3(S,(1275920972U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_ARP_02_RPSsmile_Glove_atomicError(SimStruct *S)
{
  SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct *)
    utMalloc(sizeof(SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_ARP_02_RPSsmile_Glove_atomicErrorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_ARP_02_RPSsmile_Glove_atomicError;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_Glove_atomicError;
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

void c1_ARP_02_RPSsmile_Glove_atomicError_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ARP_02_RPSsmile_Glove_atomicError(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_Glove_atomicError(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ARP_02_RPSsmile_Glove_atomicError(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ARP_02_RPSsmile_Glove_atomicError_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
