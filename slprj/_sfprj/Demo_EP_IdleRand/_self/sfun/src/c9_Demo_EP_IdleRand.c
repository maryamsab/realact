/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_EP_IdleRand_sfun.h"
#include "c9_Demo_EP_IdleRand.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_EP_IdleRand_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c9_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_eHeadNeutral             ((uint8_T)1U)
#define c9_IN_iHeadNeutral             ((uint8_T)2U)
#define c9_IN_mut                      ((uint8_T)3U)
#define c9_IN_stateAvertGaze           ((uint8_T)4U)
#define c9_IN_stateAvertHeadExtrovert  ((uint8_T)5U)
#define c9_IN_stateAvertHeadIntrovert  ((uint8_T)6U)
#define c9_IN_stateCheckAvertCont      ((uint8_T)7U)
#define c9_IN_stateCheckMutCont        ((uint8_T)8U)
#define c9_IN_stateGazingGUI           ((uint8_T)9U)
#define c9_IN_stateGazingUserHand      ((uint8_T)10U)
#define c9_IN_stateInit                ((uint8_T)11U)
#define c9_IN_stateMutualGazeE         ((uint8_T)12U)
#define c9_IN_stateRandGen             ((uint8_T)13U)
#define c9_IN_stateBrowUp              ((uint8_T)1U)
#define c9_b_IN_stateInit              ((uint8_T)2U)
#define c9_IN_stateNeckBack            ((uint8_T)3U)
#define c9_IN_stateWinSmile            ((uint8_T)4U)
#define c9_IN_stateGazeSoftEye         ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[6] = { "nargin", "nargout", "p", "m",
  "a", "h" };

static const char * c9_b_debug_family_names[28] = { "aVarTruthTableCondition_1",
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
  "aVarTruthTableCondition_22", "aVarTruthTableCondition_23", "nargin",
  "nargout", "bmlID", "p", "gazeBML" };

static const char * c9_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

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

static const char * c9_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ab_debug_family_names[17] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "nargin", "nargout", "bmlID", "p", "gazeBML" };

static const char * c9_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ib_debug_family_names[18] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13", "nargin",
  "nargout", "bmlID", "p", "gazeBML" };

static const char * c9_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_pb_debug_family_names[13] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "p", "gazeBML" };

static const char * c9_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_sb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_tb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ub_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_vb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_wb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_xb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_yb_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "p", "poseBML" };

static const char * c9_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_bc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_cc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_dc_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "p", "gazeBML" };

static const char * c9_ec_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_fc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_gc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_hc_debug_family_names[10] = { "dirG", "cDir", "c",
  "mystr", "nargin", "nargout", "dir", "mag", "p", "arrBML" };

static const char * c9_ic_debug_family_names[4] = { "nargin", "nargout", "x",
  "num" };

static const char * c9_jc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c9_kc_debug_family_names[9] = { "dirG", "cDir", "c", "mystr",
  "nargin", "nargout", "dir", "mag", "arrBML" };

static const char * c9_lc_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c9_mc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_nc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_oc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_qc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_rc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_sc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_tc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_uc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_vc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_wc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_xc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_yc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ad_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_bd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_cd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_dd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ed_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c9_td_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c9_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_se_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_te_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ue_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ve_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_we_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_xe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ye_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_af_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_bf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_cf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_df_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ef_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ff_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_gf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_hf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_if_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_kf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_lf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_mf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_nf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_of_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_pf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_qf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_rf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_sf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_tf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_uf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_vf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[41];

/* Function Declarations */
static void initialize_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void initialize_params_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void enable_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void disable_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void set_sim_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void finalize_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void sf_gateway_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_internal_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_exit_internal_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_initc9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void initSimStructsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_stateGazeIde(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_atomic_stateRandGen(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_stateRandGen(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_atomic_stateCheckMutCont
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_stateCheckMutCont(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateAvertGaze(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_stateCheckAvertCont(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateMutualGazeE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_stateMutualGazeE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateAvertHeadExtrovert
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_atomic_eHeadNeutral(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateAvertHeadIntrovert
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_atomic_iHeadNeutral(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateGazingGUI(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_stateGazingGUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_enter_atomic_stateGazingUserHand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_stateGazingUserHand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateWinSmile(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateNeckBack(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateBrowUp(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_enter_atomic_stateGazeSoftEye(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);
static void c9_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_b_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_c_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_d_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_e_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_f_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_g_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_h_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_i_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_j_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_k_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_l_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_m_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_n_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_o_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_p_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_q_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_r_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_s_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_t_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_u_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_v_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_w_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_x_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_y_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_ab_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_bb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_cb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_db_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_eb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_fb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_gb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_hb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_ib_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_jb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_kb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_lb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_mb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_nb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_ob_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_pb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_qb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_rb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_sb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static void c9_tb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256]);
static real_T c9_countDigits(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_x);
static void c9_ub_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  char_T c9_mystr_data[], int32_T c9_mystr_sizes[2], real_T c9_myarr256[256]);
static real_T c9_rand(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625]);
static void c9_twister_state_vector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_mt[625], real_T c9_seed, uint32_T c9_b_mt[625]);
static void c9_b_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625], uint32_T c9_e_state[625], real_T
  *c9_r);
static void c9_eml_error(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static real_T c9_log(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T
                     c9_x);
static void c9_b_eml_error(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static void c9_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_sprintf, const char_T *c9_identifier, char_T
  c9_y_data[], int32_T c9_y_sizes[2]);
static void c9_b_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2]);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_h, const char_T *c9_identifier);
static real_T c9_d_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_gazeBML, const char_T *c9_identifier, real_T
  c9_y[256]);
static void c9_f_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_g_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_h_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_myarr256, const char_T *c9_identifier,
  real_T c9_y[256]);
static void c9_i_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
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
static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_sc_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2]);
static void c9_j_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2]);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2]);
static const mxArray *c9_tc_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2]);
static void c9_k_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2]);
static const mxArray *c9_uc_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T *c9_inData_sizes);
static void c9_l_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y_data[], int32_T *c9_y_sizes);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  *c9_outData_sizes);
static const mxArray *c9_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_m_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_newBmls, const char_T *c9_identifier, real_T
  c9_y[1280]);
static void c9_n_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[1280]);
static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_activate_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_deactivate_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_increment_counters_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_reset_counters_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance);
static void c9_setPersonalityFactorc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_p, real_T *c9_m,
   real_T *c9_a, real_T *c9_h);
static void c9_idleGazeTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256]);
static void c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256]);
static void c9_idleGazeTableIntrovertc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256]);
static void c9_idleGazeInterestedTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256]);
static void c9_successTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_poseBML[256]);
static void c9_gazeFollowUserMovec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256]);
static void c9_idleGazeFunctionc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_dir, real_T
   c9_mag, real_T c9_p, real_T c9_arrBML[256]);
static void c9_idleGazeOrigFunctionc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_dir, real_T
   c9_mag, real_T c9_arrBML[256]);
static void c9_insertQueueLowc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmls[1280],
   real_T c9_myBML[256], real_T c9_newBmls[1280]);
static void c9_blanks(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T
                      c9_b_n, char_T c9_b_data[], int32_T c9_b_sizes[2]);
static const mxArray *c9_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int8_T c9_o_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_p_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_q_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_stateGazeIde, const char_T
  *c9_identifier);
static uint8_T c9_r_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_s_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_mutContF, const char_T *c9_identifier,
  real_T c9_y[3]);
static void c9_t_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3]);
static void c9_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_u_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_avertContF, const char_T *c9_identifier,
  real_T c9_y[4]);
static void c9_v_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4]);
static void c9_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint32_T c9_w_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_method, const char_T *c9_identifier);
static uint32_T c9_x_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static uint32_T c9_y_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier);
static uint32_T c9_ab_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_bb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625]);
static void c9_cb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625]);
static void c9_db_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2]);
static void c9_eb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2]);
static uint32_T c9_fb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier);
static uint32_T c9_gb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_hb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier);
static const mxArray *c9_ib_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber);
static void c9_b_twister_state_vector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_mt[625], real_T c9_seed);
static real_T c9_c_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625]);
static void c9_b_log(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T *
                     c9_x);
static real_T c9_get_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
                     uint32_T c9_b, real_T c9_c);
static real_T *c9_access_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_avert(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_avert(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_avert(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_avertH(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_avertH(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_avertH(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_boredom(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_boredom(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_boredom(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_fileID(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_fileID(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_fileID(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_gazing(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_gazing(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_gazing(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_interest(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_interest(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c);
static real_T *c9_access_interest(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static void c9_set_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
                      uint32_T c9_b, real_T c9_c);
static real_T *c9_access_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b);
static real_T c9_get_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static real_T c9_get_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void c9_set_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b);
static void init_dsm_address_info(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_debugger_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_Demo_EP_IdleRand == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeIde == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateRandGen) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateCheckMutCont) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_mut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateCheckAvertCont) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateMutualGazeE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHeadExtrovert) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_eHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHeadIntrovert) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_iHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingGUI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeWin == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_b_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateWinSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateNeckBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeSoft == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeSoft == c9_b_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeSoft == c9_IN_stateGazeSoftEye) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i0;
  real_T c9_b_u[256];
  const mxArray *c9_c_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  int32_T c9_i1;
  real_T c9_g_u[4];
  const mxArray *c9_h_y = NULL;
  real_T c9_f_hoistedGlobal;
  real_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  real_T c9_g_hoistedGlobal;
  real_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  real_T c9_h_hoistedGlobal;
  real_T c9_j_u;
  const mxArray *c9_k_y = NULL;
  real_T c9_i_hoistedGlobal;
  real_T c9_k_u;
  const mxArray *c9_l_y = NULL;
  real_T c9_j_hoistedGlobal;
  real_T c9_l_u;
  const mxArray *c9_m_y = NULL;
  real_T c9_k_hoistedGlobal;
  real_T c9_m_u;
  const mxArray *c9_n_y = NULL;
  real_T c9_l_hoistedGlobal;
  real_T c9_n_u;
  const mxArray *c9_o_y = NULL;
  real_T c9_m_hoistedGlobal;
  real_T c9_o_u;
  const mxArray *c9_p_y = NULL;
  real_T c9_n_hoistedGlobal;
  real_T c9_p_u;
  const mxArray *c9_q_y = NULL;
  int32_T c9_i2;
  real_T c9_q_u[3];
  const mxArray *c9_r_y = NULL;
  real_T c9_o_hoistedGlobal;
  real_T c9_r_u;
  const mxArray *c9_s_y = NULL;
  int32_T c9_i3;
  real_T c9_s_u[256];
  const mxArray *c9_t_y = NULL;
  int32_T c9_i4;
  real_T c9_t_u[1280];
  const mxArray *c9_u_y = NULL;
  real_T c9_p_hoistedGlobal;
  real_T c9_u_u;
  const mxArray *c9_v_y = NULL;
  real_T c9_q_hoistedGlobal;
  real_T c9_v_u;
  const mxArray *c9_w_y = NULL;
  real_T c9_r_hoistedGlobal;
  real_T c9_w_u;
  const mxArray *c9_x_y = NULL;
  uint32_T c9_s_hoistedGlobal;
  uint32_T c9_x_u;
  const mxArray *c9_y_y = NULL;
  uint32_T c9_t_hoistedGlobal;
  uint32_T c9_y_u;
  const mxArray *c9_ab_y = NULL;
  int32_T c9_i5;
  uint32_T c9_ab_u[625];
  const mxArray *c9_bb_y = NULL;
  int32_T c9_i6;
  uint32_T c9_bb_u[2];
  const mxArray *c9_cb_y = NULL;
  uint8_T c9_u_hoistedGlobal;
  uint8_T c9_cb_u;
  const mxArray *c9_db_y = NULL;
  uint8_T c9_v_hoistedGlobal;
  uint8_T c9_db_u;
  const mxArray *c9_eb_y = NULL;
  uint8_T c9_w_hoistedGlobal;
  uint8_T c9_eb_u;
  const mxArray *c9_fb_y = NULL;
  uint8_T c9_x_hoistedGlobal;
  uint8_T c9_fb_u;
  const mxArray *c9_gb_y = NULL;
  uint8_T c9_y_hoistedGlobal;
  uint8_T c9_gb_u;
  const mxArray *c9_hb_y = NULL;
  uint8_T c9_ab_hoistedGlobal;
  uint8_T c9_hb_u;
  const mxArray *c9_ib_y = NULL;
  uint8_T c9_bb_hoistedGlobal;
  uint8_T c9_ib_u;
  const mxArray *c9_jb_y = NULL;
  uint8_T c9_cb_hoistedGlobal;
  uint8_T c9_jb_u;
  const mxArray *c9_kb_y = NULL;
  uint8_T c9_db_hoistedGlobal;
  uint8_T c9_kb_u;
  const mxArray *c9_lb_y = NULL;
  uint32_T c9_eb_hoistedGlobal;
  uint32_T c9_lb_u;
  const mxArray *c9_mb_y = NULL;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(37, 1), false);
  c9_hoistedGlobal = *c9_gameState;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i0 = 0; c9_i0 < 256; c9_i0++) {
    c9_b_u[c9_i0] = chartInstance->c9_BMLl[c9_i0];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_b_hoistedGlobal = chartInstance->c9_CHANCEA;
  c9_c_u = c9_b_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_c_hoistedGlobal = chartInstance->c9_CHANCEM;
  c9_d_u = c9_c_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_d_hoistedGlobal = chartInstance->c9_aF;
  c9_e_u = c9_d_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_e_hoistedGlobal = chartInstance->c9_avertContChance;
  c9_f_u = c9_e_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  for (c9_i1 = 0; c9_i1 < 4; c9_i1++) {
    c9_g_u[c9_i1] = chartInstance->c9_avertContF[c9_i1];
  }

  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_g_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_f_hoistedGlobal = chartInstance->c9_avertDur;
  c9_h_u = c9_f_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_g_hoistedGlobal = chartInstance->c9_chanceO;
  c9_i_u = c9_g_hoistedGlobal;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  c9_h_hoistedGlobal = chartInstance->c9_gazeDir;
  c9_j_u = c9_h_hoistedGlobal;
  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", &c9_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 9, c9_k_y);
  c9_i_hoistedGlobal = chartInstance->c9_gazeGUIChance;
  c9_k_u = c9_i_hoistedGlobal;
  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", &c9_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 10, c9_l_y);
  c9_j_hoistedGlobal = chartInstance->c9_gazeUserHandChance;
  c9_l_u = c9_j_hoistedGlobal;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 11, c9_m_y);
  c9_k_hoistedGlobal = chartInstance->c9_hF;
  c9_m_u = c9_k_hoistedGlobal;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 12, c9_n_y);
  c9_l_hoistedGlobal = chartInstance->c9_mF;
  c9_n_u = c9_l_hoistedGlobal;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 13, c9_o_y);
  c9_m_hoistedGlobal = chartInstance->c9_magnitude;
  c9_o_u = c9_m_hoistedGlobal;
  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_create("y", &c9_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 14, c9_p_y);
  c9_n_hoistedGlobal = chartInstance->c9_mutContChance;
  c9_p_u = c9_n_hoistedGlobal;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 15, c9_q_y);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    c9_q_u[c9_i2] = chartInstance->c9_mutContF[c9_i2];
  }

  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", c9_q_u, 0, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_setcell(c9_y, 16, c9_r_y);
  c9_o_hoistedGlobal = chartInstance->c9_mutDur;
  c9_r_u = c9_o_hoistedGlobal;
  c9_s_y = NULL;
  sf_mex_assign(&c9_s_y, sf_mex_create("y", &c9_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 17, c9_s_y);
  for (c9_i3 = 0; c9_i3 < 256; c9_i3++) {
    c9_s_u[c9_i3] = chartInstance->c9_n[c9_i3];
  }

  c9_t_y = NULL;
  sf_mex_assign(&c9_t_y, sf_mex_create("y", c9_s_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c9_y, 18, c9_t_y);
  for (c9_i4 = 0; c9_i4 < 1280; c9_i4++) {
    c9_t_u[c9_i4] = chartInstance->c9_newBmlsL[c9_i4];
  }

  c9_u_y = NULL;
  sf_mex_assign(&c9_u_y, sf_mex_create("y", c9_t_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c9_y, 19, c9_u_y);
  c9_p_hoistedGlobal = chartInstance->c9_randHeadChance;
  c9_u_u = c9_p_hoistedGlobal;
  c9_v_y = NULL;
  sf_mex_assign(&c9_v_y, sf_mex_create("y", &c9_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 20, c9_v_y);
  c9_q_hoistedGlobal = chartInstance->c9_randHeadDur;
  c9_v_u = c9_q_hoistedGlobal;
  c9_w_y = NULL;
  sf_mex_assign(&c9_w_y, sf_mex_create("y", &c9_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 21, c9_w_y);
  c9_r_hoistedGlobal = chartInstance->c9_randHeadDurOver;
  c9_w_u = c9_r_hoistedGlobal;
  c9_x_y = NULL;
  sf_mex_assign(&c9_x_y, sf_mex_create("y", &c9_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 22, c9_x_y);
  c9_s_hoistedGlobal = chartInstance->c9_method;
  c9_x_u = c9_s_hoistedGlobal;
  c9_y_y = NULL;
  if (!chartInstance->c9_method_not_empty) {
    sf_mex_assign(&c9_y_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_x_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 23, c9_y_y);
  c9_t_hoistedGlobal = chartInstance->c9_state;
  c9_y_u = c9_t_hoistedGlobal;
  c9_ab_y = NULL;
  if (!chartInstance->c9_state_not_empty) {
    sf_mex_assign(&c9_ab_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_ab_y, sf_mex_create("y", &c9_y_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 24, c9_ab_y);
  for (c9_i5 = 0; c9_i5 < 625; c9_i5++) {
    c9_ab_u[c9_i5] = chartInstance->c9_c_state[c9_i5];
  }

  c9_bb_y = NULL;
  if (!chartInstance->c9_c_state_not_empty) {
    sf_mex_assign(&c9_bb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_bb_y, sf_mex_create("y", c9_ab_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c9_y, 25, c9_bb_y);
  for (c9_i6 = 0; c9_i6 < 2; c9_i6++) {
    c9_bb_u[c9_i6] = chartInstance->c9_b_state[c9_i6];
  }

  c9_cb_y = NULL;
  if (!chartInstance->c9_b_state_not_empty) {
    sf_mex_assign(&c9_cb_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_cb_y, sf_mex_create("y", c9_bb_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c9_y, 26, c9_cb_y);
  c9_u_hoistedGlobal = chartInstance->c9_is_active_c9_Demo_EP_IdleRand;
  c9_cb_u = c9_u_hoistedGlobal;
  c9_db_y = NULL;
  sf_mex_assign(&c9_db_y, sf_mex_create("y", &c9_cb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 27, c9_db_y);
  c9_v_hoistedGlobal = chartInstance->c9_is_active_stateGazeIde;
  c9_db_u = c9_v_hoistedGlobal;
  c9_eb_y = NULL;
  sf_mex_assign(&c9_eb_y, sf_mex_create("y", &c9_db_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 28, c9_eb_y);
  c9_w_hoistedGlobal = chartInstance->c9_is_active_stateGazeWin;
  c9_eb_u = c9_w_hoistedGlobal;
  c9_fb_y = NULL;
  sf_mex_assign(&c9_fb_y, sf_mex_create("y", &c9_eb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 29, c9_fb_y);
  c9_x_hoistedGlobal = chartInstance->c9_is_active_stateGazeSoft;
  c9_fb_u = c9_x_hoistedGlobal;
  c9_gb_y = NULL;
  sf_mex_assign(&c9_gb_y, sf_mex_create("y", &c9_fb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 30, c9_gb_y);
  c9_y_hoistedGlobal = chartInstance->c9_is_stateGazeIde;
  c9_gb_u = c9_y_hoistedGlobal;
  c9_hb_y = NULL;
  sf_mex_assign(&c9_hb_y, sf_mex_create("y", &c9_gb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 31, c9_hb_y);
  c9_ab_hoistedGlobal = chartInstance->c9_is_stateGazeWin;
  c9_hb_u = c9_ab_hoistedGlobal;
  c9_ib_y = NULL;
  sf_mex_assign(&c9_ib_y, sf_mex_create("y", &c9_hb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 32, c9_ib_y);
  c9_bb_hoistedGlobal = chartInstance->c9_is_stateGazeSoft;
  c9_ib_u = c9_bb_hoistedGlobal;
  c9_jb_y = NULL;
  sf_mex_assign(&c9_jb_y, sf_mex_create("y", &c9_ib_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 33, c9_jb_y);
  c9_cb_hoistedGlobal = chartInstance->c9_temporalCounter_i3;
  c9_jb_u = c9_cb_hoistedGlobal;
  c9_kb_y = NULL;
  sf_mex_assign(&c9_kb_y, sf_mex_create("y", &c9_jb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 34, c9_kb_y);
  c9_db_hoistedGlobal = chartInstance->c9_temporalCounter_i2;
  c9_kb_u = c9_db_hoistedGlobal;
  c9_lb_y = NULL;
  sf_mex_assign(&c9_lb_y, sf_mex_create("y", &c9_kb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 35, c9_lb_y);
  c9_eb_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_lb_u = c9_eb_hoistedGlobal;
  c9_mb_y = NULL;
  sf_mex_assign(&c9_mb_y, sf_mex_create("y", &c9_lb_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 36, c9_mb_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[256];
  int32_T c9_i7;
  real_T c9_dv1[4];
  int32_T c9_i8;
  real_T c9_dv2[3];
  int32_T c9_i9;
  real_T c9_dv3[256];
  int32_T c9_i10;
  real_T c9_dv4[1280];
  int32_T c9_i11;
  uint32_T c9_uv0[625];
  int32_T c9_i12;
  uint32_T c9_uv1[2];
  int32_T c9_i13;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_gameState = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "gameState");
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                        "BMLl", c9_dv0);
  for (c9_i7 = 0; c9_i7 < 256; c9_i7++) {
    chartInstance->c9_BMLl[c9_i7] = c9_dv0[c9_i7];
  }

  chartInstance->c9_CHANCEA = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 2)), "CHANCEA");
  chartInstance->c9_CHANCEM = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 3)), "CHANCEM");
  chartInstance->c9_aF = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 4)), "aF");
  chartInstance->c9_avertContChance = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 5)), "avertContChance");
  c9_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 6)),
                        "avertContF", c9_dv1);
  for (c9_i8 = 0; c9_i8 < 4; c9_i8++) {
    chartInstance->c9_avertContF[c9_i8] = c9_dv1[c9_i8];
  }

  chartInstance->c9_avertDur = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 7)), "avertDur");
  chartInstance->c9_chanceO = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 8)), "chanceO");
  chartInstance->c9_gazeDir = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 9)), "gazeDir");
  chartInstance->c9_gazeGUIChance = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 10)), "gazeGUIChance");
  chartInstance->c9_gazeUserHandChance = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 11)), "gazeUserHandChance");
  chartInstance->c9_hF = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 12)), "hF");
  chartInstance->c9_mF = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 13)), "mF");
  chartInstance->c9_magnitude = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 14)), "magnitude");
  chartInstance->c9_mutContChance = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 15)), "mutContChance");
  c9_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 16)),
                        "mutContF", c9_dv2);
  for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
    chartInstance->c9_mutContF[c9_i9] = c9_dv2[c9_i9];
  }

  chartInstance->c9_mutDur = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 17)), "mutDur");
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 18)), "n",
                        c9_dv3);
  for (c9_i10 = 0; c9_i10 < 256; c9_i10++) {
    chartInstance->c9_n[c9_i10] = c9_dv3[c9_i10];
  }

  c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 19)),
                        "newBmlsL", c9_dv4);
  for (c9_i11 = 0; c9_i11 < 1280; c9_i11++) {
    chartInstance->c9_newBmlsL[c9_i11] = c9_dv4[c9_i11];
  }

  chartInstance->c9_randHeadChance = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 20)), "randHeadChance");
  chartInstance->c9_randHeadDur = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 21)), "randHeadDur");
  chartInstance->c9_randHeadDurOver = c9_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 22)), "randHeadDurOver");
  chartInstance->c9_method = c9_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 23)), "method");
  chartInstance->c9_state = c9_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 24)), "state");
  c9_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 25)),
    "state", c9_uv0);
  for (c9_i12 = 0; c9_i12 < 625; c9_i12++) {
    chartInstance->c9_c_state[c9_i12] = c9_uv0[c9_i12];
  }

  c9_db_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 26)),
    "state", c9_uv1);
  for (c9_i13 = 0; c9_i13 < 2; c9_i13++) {
    chartInstance->c9_b_state[c9_i13] = c9_uv1[c9_i13];
  }

  chartInstance->c9_is_active_c9_Demo_EP_IdleRand = c9_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 27)),
     "is_active_c9_Demo_EP_IdleRand");
  chartInstance->c9_is_active_stateGazeIde = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 28)), "is_active_stateGazeIde");
  chartInstance->c9_is_active_stateGazeWin = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 29)), "is_active_stateGazeWin");
  chartInstance->c9_is_active_stateGazeSoft = c9_q_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 30)),
     "is_active_stateGazeSoft");
  chartInstance->c9_is_stateGazeIde = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 31)), "is_stateGazeIde");
  chartInstance->c9_is_stateGazeWin = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 32)), "is_stateGazeWin");
  chartInstance->c9_is_stateGazeSoft = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 33)), "is_stateGazeSoft");
  chartInstance->c9_temporalCounter_i3 = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 34)), "temporalCounter_i3");
  chartInstance->c9_temporalCounter_i2 = c9_q_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 35)), "temporalCounter_i2");
  chartInstance->c9_temporalCounter_i1 = c9_fb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 36)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 37)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_Demo_EP_IdleRand(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_active_stateGazeIde == 1U) {
      chartInstance->c9_tp_stateGazeIde = 1U;
    } else {
      chartInstance->c9_tp_stateGazeIde = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_eHeadNeutral) {
      chartInstance->c9_tp_eHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_eHeadNeutral = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_iHeadNeutral) {
      chartInstance->c9_tp_iHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_iHeadNeutral = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_mut) {
      chartInstance->c9_tp_mut = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_mut = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertGaze) {
      chartInstance->c9_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHeadExtrovert) {
      chartInstance->c9_tp_stateAvertHeadExtrovert = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertHeadExtrovert = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHeadIntrovert) {
      chartInstance->c9_tp_stateAvertHeadIntrovert = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertHeadIntrovert = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateCheckAvertCont) {
      chartInstance->c9_tp_stateCheckAvertCont = 1U;
    } else {
      chartInstance->c9_tp_stateCheckAvertCont = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateCheckMutCont) {
      chartInstance->c9_tp_stateCheckMutCont = 1U;
    } else {
      chartInstance->c9_tp_stateCheckMutCont = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingGUI) {
      chartInstance->c9_tp_stateGazingGUI = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGazingGUI = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingUserHand) {
      chartInstance->c9_tp_stateGazingUserHand = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGazingUserHand = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateInit) {
      chartInstance->c9_tp_stateInit = 1U;
    } else {
      chartInstance->c9_tp_stateInit = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateMutualGazeE) {
      chartInstance->c9_tp_stateMutualGazeE = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateMutualGazeE = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateRandGen) {
      chartInstance->c9_tp_stateRandGen = 1U;
    } else {
      chartInstance->c9_tp_stateRandGen = 0U;
    }

    if (chartInstance->c9_is_active_stateGazeWin == 1U) {
      chartInstance->c9_tp_stateGazeWin = 1U;
    } else {
      chartInstance->c9_tp_stateGazeWin = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_IN_stateBrowUp) {
      chartInstance->c9_tp_stateBrowUp = 1U;
    } else {
      chartInstance->c9_tp_stateBrowUp = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_b_IN_stateInit) {
      chartInstance->c9_b_tp_stateInit = 1U;
    } else {
      chartInstance->c9_b_tp_stateInit = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_IN_stateNeckBack) {
      chartInstance->c9_tp_stateNeckBack = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c9_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_IN_stateWinSmile) {
      chartInstance->c9_tp_stateWinSmile = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 20) == 0.0) {
        chartInstance->c9_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateWinSmile = 0U;
    }

    if (chartInstance->c9_is_active_stateGazeSoft == 1U) {
      chartInstance->c9_tp_stateGazeSoft = 1U;
    } else {
      chartInstance->c9_tp_stateGazeSoft = 0U;
    }

    if (chartInstance->c9_is_stateGazeSoft == c9_IN_stateGazeSoftEye) {
      chartInstance->c9_tp_stateGazeSoftEye = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c9_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGazeSoftEye = 0U;
    }

    if (chartInstance->c9_is_stateGazeSoft == c9_b_IN_stateInit) {
      chartInstance->c9_c_tp_stateInit = 1U;
    } else {
      chartInstance->c9_c_tp_stateInit = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  c9_set_sim_state_side_effects_c9_Demo_EP_IdleRand(chartInstance);
}

static void c9_enter_atomic_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_is_active_c9_Demo_EP_IdleRand = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_enter_internal_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr;
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr;
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  real_T c9_b_hF;
  real_T c9_b_aF;
  real_T c9_b_mF;
  real_T *c9_gameState;
  real_T *c9_personality;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeIde = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeIde = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeIde = c9_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_nc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c9_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c9_set_STATE_READY(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c9_set_STATE_GO(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  *c9_gameState = c9_get_STATE_READY(chartInstance, 0);
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 13U);
  c9_set_GAZE_GUI(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c9_set_GAZE_SOFTEYE(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c9_set_GAZE_USER_HAND(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c9_set_GAZE_WIN(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c9_set_interest(chartInstance, 0, c9_get_BOREDOM_THRESHOLD(chartInstance, 0) -
                  c9_get_boredom(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 18);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_mc_debug_family_names,
    c9_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_arr, 1U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_mystr, 5U, c9_wc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  c9_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 255.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i14 = 0; c9_i14 < 256; c9_i14++) {
    c9_tt[c9_i14] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_tt[0] = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i15 = 0; c9_i15 < 256; c9_i15++) {
    c9_myarr256[c9_i15] = c9_tt[c9_i15];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i16 = 0; c9_i16 < 256; c9_i16++) {
    chartInstance->c9_n[c9_i16] = c9_myarr256[c9_i16];
  }

  c9_updateDataWrittenToVector(chartInstance, 18U);
  for (c9_i17 = 0; c9_i17 < 256; c9_i17++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_n[c9_i17], 40U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 18U, 40U);
  for (c9_i18 = 0; c9_i18 < 256; c9_i18++) {
    c9_set_bmlsL(chartInstance, c9_i18, chartInstance->c9_n[c9_i18]);
  }

  for (c9_i19 = 0; c9_i19 < 256; c9_i19++) {
    c9_set_bmlsL(chartInstance, c9_i19 + 256, chartInstance->c9_n[c9_i19]);
  }

  for (c9_i20 = 0; c9_i20 < 256; c9_i20++) {
    c9_set_bmlsL(chartInstance, c9_i20 + 512, chartInstance->c9_n[c9_i20]);
  }

  for (c9_i21 = 0; c9_i21 < 256; c9_i21++) {
    c9_set_bmlsL(chartInstance, c9_i21 + 768, chartInstance->c9_n[c9_i21]);
  }

  for (c9_i22 = 0; c9_i22 < 256; c9_i22++) {
    c9_set_bmlsL(chartInstance, c9_i22 + 1024, chartInstance->c9_n[c9_i22]);
  }

  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 18U, 40U);
  for (c9_i23 = 0; c9_i23 < 256; c9_i23++) {
    chartInstance->c9_newBmlsL[c9_i23] = chartInstance->c9_n[c9_i23];
  }

  for (c9_i24 = 0; c9_i24 < 256; c9_i24++) {
    chartInstance->c9_newBmlsL[c9_i24 + 256] = chartInstance->c9_n[c9_i24];
  }

  for (c9_i25 = 0; c9_i25 < 256; c9_i25++) {
    chartInstance->c9_newBmlsL[c9_i25 + 512] = chartInstance->c9_n[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 256; c9_i26++) {
    chartInstance->c9_newBmlsL[c9_i26 + 768] = chartInstance->c9_n[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 256; c9_i27++) {
    chartInstance->c9_newBmlsL[c9_i27 + 1024] = chartInstance->c9_n[c9_i27];
  }

  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 18U);
  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i28 = 0; c9_i28 < 1280; c9_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i28], 39U);
  }

  c9_set_interest(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 18);
  c9_setPersonalityFactorc9_Demo_EP_IdleRand(chartInstance, *c9_personality,
    &c9_b_mF, &c9_b_aF, &c9_b_hF);
  chartInstance->c9_mF = c9_b_mF;
  c9_updateDataWrittenToVector(chartInstance, 20U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_mF, 44U);
  chartInstance->c9_aF = c9_b_aF;
  c9_updateDataWrittenToVector(chartInstance, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_aF, 46U);
  chartInstance->c9_hF = c9_b_hF;
  c9_updateDataWrittenToVector(chartInstance, 21U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_hF, 45U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeWin = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeWin = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeWin = c9_b_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
  chartInstance->c9_b_tp_stateInit = 1U;
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeSoft = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeSoft = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeSoft = c9_b_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  chartInstance->c9_c_tp_stateInit = 1U;
}

static void c9_c9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_e_out;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_isStable = true;
  c9_stateGazeIde(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeWin) {
   case c9_IN_stateBrowUp:
    CV_STATE_EVAL(26, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c9_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(26, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_je_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_out = CV_EML_IF(10, 0, 0, c9_get_gazing(chartInstance, 0) ==
                       c9_get_GAZE_WIN(chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      chartInstance->c9_b_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateWinSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_stateWinSmile = 1U;
      c9_enter_atomic_stateWinSmile(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNeckBack:
    CV_STATE_EVAL(26, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_le_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(7, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i2 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateNeckBack = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateBrowUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateBrowUp = 1U;
      c9_enter_atomic_stateBrowUp(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateWinSmile:
    CV_STATE_EVAL(26, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ke_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_c_out = CV_EML_IF(8, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i2 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateWinSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateNeckBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_stateNeckBack = 1U;
      c9_enter_atomic_stateNeckBack(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(26, 0, 0);
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c9_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeSoft) {
   case c9_IN_stateGazeSoftEye:
    CV_STATE_EVAL(23, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_me_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_d_out = CV_EML_IF(6, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i3 >= 50));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateGazeSoftEye = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeSoft = c9_b_IN_stateInit;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_c_tp_stateInit = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(23, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ne_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(5, 0, 0, c9_get_gazing(chartInstance, 0) ==
                    c9_get_GAZE_SOFTEYE(chartInstance, 0))) {
      if (CV_EML_COND(5, 0, 1, c9_get_changeFlag(chartInstance, 0) != 1.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c9_e_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c9_e_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_c_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeSoft = c9_IN_stateGazeSoftEye;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i3 = 0U;
      chartInstance->c9_tp_stateGazeSoftEye = 1U;
      c9_enter_atomic_stateGazeSoftEye(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(23, 0, 0);
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c9_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_exit_internal_c9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  switch (chartInstance->c9_is_stateGazeSoft) {
   case c9_IN_stateGazeSoftEye:
    CV_STATE_EVAL(23, 1, 1);
    chartInstance->c9_tp_stateGazeSoftEye = 0U;
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(23, 1, 2);
    chartInstance->c9_c_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(23, 1, 0);
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeSoft = 0U;
  chartInstance->c9_is_active_stateGazeSoft = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeWin) {
   case c9_IN_stateBrowUp:
    CV_STATE_EVAL(26, 1, 1);
    chartInstance->c9_tp_stateBrowUp = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(26, 1, 2);
    chartInstance->c9_b_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNeckBack:
    CV_STATE_EVAL(26, 1, 3);
    chartInstance->c9_tp_stateNeckBack = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateWinSmile:
    CV_STATE_EVAL(26, 1, 4);
    chartInstance->c9_tp_stateWinSmile = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(26, 1, 0);
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeWin = 0U;
  chartInstance->c9_is_active_stateGazeWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeIde) {
   case c9_IN_eHeadNeutral:
    CV_STATE_EVAL(9, 1, 1);
    chartInstance->c9_tp_eHeadNeutral = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_iHeadNeutral:
    CV_STATE_EVAL(9, 1, 2);
    chartInstance->c9_tp_iHeadNeutral = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_mut:
    CV_STATE_EVAL(9, 1, 3);
    chartInstance->c9_tp_mut = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertGaze:
    CV_STATE_EVAL(9, 1, 4);
    chartInstance->c9_tp_stateAvertGaze = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHeadExtrovert:
    CV_STATE_EVAL(9, 1, 5);
    chartInstance->c9_tp_stateAvertHeadExtrovert = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHeadIntrovert:
    CV_STATE_EVAL(9, 1, 6);
    chartInstance->c9_tp_stateAvertHeadIntrovert = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCheckAvertCont:
    CV_STATE_EVAL(9, 1, 7);
    chartInstance->c9_tp_stateCheckAvertCont = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCheckMutCont:
    CV_STATE_EVAL(9, 1, 8);
    chartInstance->c9_tp_stateCheckMutCont = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingGUI:
    CV_STATE_EVAL(9, 1, 9);
    chartInstance->c9_tp_stateGazingGUI = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingUserHand:
    CV_STATE_EVAL(9, 1, 10);
    chartInstance->c9_tp_stateGazingUserHand = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInit:
    CV_STATE_EVAL(9, 1, 11);
    chartInstance->c9_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateMutualGazeE:
    CV_STATE_EVAL(9, 1, 12);
    chartInstance->c9_tp_stateMutualGazeE = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateRandGen:
    CV_STATE_EVAL(9, 1, 13);
    chartInstance->c9_tp_stateRandGen = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 1, 0);
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeIde = 0U;
  chartInstance->c9_is_active_stateGazeIde = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
}

static void c9_initc9_Demo_EP_IdleRand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_method_not_empty = false;
  chartInstance->c9_state_not_empty = false;
  chartInstance->c9_b_state_not_empty = false;
  chartInstance->c9_c_state_not_empty = false;
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_is_active_stateGazeIde = 0U;
  chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_stateGazeIde = 0U;
  chartInstance->c9_tp_eHeadNeutral = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_iHeadNeutral = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_mut = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateAvertGaze = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateAvertHeadExtrovert = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateAvertHeadIntrovert = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateCheckAvertCont = 0U;
  chartInstance->c9_tp_stateCheckMutCont = 0U;
  chartInstance->c9_tp_stateGazingGUI = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateGazingUserHand = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateInit = 0U;
  chartInstance->c9_tp_stateMutualGazeE = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateRandGen = 0U;
  chartInstance->c9_is_active_stateGazeSoft = 0U;
  chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_stateGazeSoft = 0U;
  chartInstance->c9_tp_stateGazeSoftEye = 0U;
  chartInstance->c9_temporalCounter_i3 = 0U;
  chartInstance->c9_c_tp_stateInit = 0U;
  chartInstance->c9_is_active_stateGazeWin = 0U;
  chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_stateGazeWin = 0U;
  chartInstance->c9_tp_stateBrowUp = 0U;
  chartInstance->c9_b_tp_stateInit = 0U;
  chartInstance->c9_tp_stateNeckBack = 0U;
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_tp_stateWinSmile = 0U;
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_is_active_c9_Demo_EP_IdleRand = 0U;
}

static void initSimStructsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_stateGazeIde(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  boolean_T c9_temp;
  uint32_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_d_out;
  boolean_T c9_b_temp;
  uint32_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_c_x;
  real_T c9_d_x;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  int32_T c9_i29;
  static real_T c9_dv5[4] = { -0.0034, 0.23, -6.7, 79.0 };

  int32_T c9_i30;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_x;
  int32_T c9_k;
  real_T c9_b_k;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_e_out;
  boolean_T c9_c_temp;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 1.0;
  boolean_T c9_f_out;
  boolean_T c9_d_temp;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 1.0;
  boolean_T c9_g_out;
  real_T *c9_gameState;
  real_T (*c9_randArray)[25];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeIde) {
   case c9_IN_eHeadNeutral:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_vd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_out = CV_EML_IF(30, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                       (chartInstance->c9_temporalCounter_i1 >= 2U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_eHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateMutualGazeE;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateMutualGazeE = 1U;
      c9_enter_atomic_stateMutualGazeE(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_iHeadNeutral:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_wd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(31, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 2U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_iHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateMutualGazeE;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateMutualGazeE = 1U;
      c9_enter_atomic_stateMutualGazeE(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_mut:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ld_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 19U, 42U);
    c9_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_temp) {
      c9_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
      c9_b_hoistedGlobal = chartInstance->c9_mutDur;
      c9_x = c9_b_hoistedGlobal;
      c9_b_x = c9_x;
      c9_b_x = muDoubleScalarFloor(c9_b_x);
      c9_temp = (c9_hoistedGlobal >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
                  c9_b_x, 32U, 23U));
    }

    c9_c_out = CV_EML_IF(23, 0, 0, c9_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_mut = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateCheckMutCont;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckMutCont = 1U;
      c9_enter_atomic_stateCheckMutCont(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertGaze:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_pd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 8U, 23U);
    c9_b_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_b_temp) {
      c9_c_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
      c9_d_hoistedGlobal = chartInstance->c9_avertDur;
      c9_c_x = c9_d_hoistedGlobal;
      c9_d_x = c9_c_x;
      c9_d_x = muDoubleScalarFloor(c9_d_x);
      c9_b_temp = (c9_c_hoistedGlobal >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
        c9_d_x, 32U, 15U));
    }

    c9_d_out = CV_EML_IF(15, 0, 0, c9_b_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateCheckAvertCont;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckAvertCont = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      for (c9_i29 = 0; c9_i29 < 4; c9_i29++) {
        chartInstance->c9_avertContF[c9_i29] = c9_dv5[c9_i29];
      }

      c9_updateDataWrittenToVector(chartInstance, 13U);
      for (c9_i30 = 0; c9_i30 < 4; c9_i30++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_avertContF[c9_i30], 28U);
      }

      c9_errorIfDataNotWrittenToFcn(chartInstance, 13U, 28U);
      c9_e_hoistedGlobal = c9_get_boredom(chartInstance, 0);
      c9_e_x = c9_e_hoistedGlobal * 6.0;
      chartInstance->c9_avertContChance = chartInstance->c9_avertContF[0];
      for (c9_k = 0; c9_k < 3; c9_k++) {
        c9_b_k = 2.0 + (real_T)c9_k;
        chartInstance->c9_avertContChance = c9_e_x *
          chartInstance->c9_avertContChance + chartInstance->c9_avertContF
          [(int32_T)c9_b_k - 1];
      }

      c9_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_avertContChance, 18U);
      chartInstance->c9_CHANCEA = (*c9_randArray)[8];
      c9_updateDataWrittenToVector(chartInstance, 10U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c9_CHANCEA, 25U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHeadExtrovert:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_de_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 0U, 11U);
    c9_c_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_c_temp) {
      c9_c_temp = (chartInstance->c9_temporalCounter_i1 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
        (chartInstance->c9_randHeadDur * 2.0), 32U, 26U));
    }

    c9_e_out = CV_EML_IF(26, 0, 0, c9_c_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateAvertHeadExtrovert = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_eHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_eHeadNeutral = 1U;
      c9_enter_atomic_eHeadNeutral(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHeadIntrovert:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_fe_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 12U);
    c9_d_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_d_temp) {
      c9_d_temp = (chartInstance->c9_temporalCounter_i1 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
        (chartInstance->c9_randHeadDurOver * 2.0), 32U, 29U));
    }

    c9_f_out = CV_EML_IF(29, 0, 0, c9_d_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateAvertHeadIntrovert = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_iHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_iHeadNeutral = 1U;
      c9_enter_atomic_iHeadNeutral(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateCheckAvertCont:
    CV_STATE_EVAL(9, 0, 7);
    c9_stateCheckAvertCont(chartInstance);
    break;

   case c9_IN_stateCheckMutCont:
    CV_STATE_EVAL(9, 0, 8);
    c9_stateCheckMutCont(chartInstance);
    break;

   case c9_IN_stateGazingGUI:
    CV_STATE_EVAL(9, 0, 9);
    c9_stateGazingGUI(chartInstance);
    break;

   case c9_IN_stateGazingUserHand:
    CV_STATE_EVAL(9, 0, 10);
    c9_stateGazingUserHand(chartInstance);
    break;

   case c9_IN_stateInit:
    CV_STATE_EVAL(9, 0, 11);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_fd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(13, 0, 0, c9_get_changeFlag(chartInstance, 0) != 1.0)) {
      if (CV_EML_COND(13, 0, 1, *c9_gameState != c9_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(13, 0, 2, *c9_gameState != c9_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(13, 0, 0, true);
          CV_EML_IF(13, 0, 0, true);
          c9_g_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard2 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(13, 0, 0, false);
      CV_EML_IF(13, 0, 0, false);
      c9_g_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGen;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandGen = 1U;
      c9_enter_atomic_stateRandGen(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateMutualGazeE:
    CV_STATE_EVAL(9, 0, 12);
    c9_stateMutualGazeE(chartInstance);
    break;

   case c9_IN_stateRandGen:
    CV_STATE_EVAL(9, 0, 13);
    c9_stateRandGen(chartInstance);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateRandGen(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_lowhigh[2];
  real_T c9_high;
  int32_T c9_i31;
  static char_T c9_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c9_u[26];
  const mxArray *c9_y = NULL;
  real_T c9_s;
  real_T c9_r;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T (*c9_randArray)[25];
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_oc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  chartInstance->c9_randHeadDur = (*c9_randArray)[0];
  c9_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_randHeadDur, 11U);
  chartInstance->c9_randHeadDurOver = (*c9_randArray)[1];
  c9_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_randHeadDurOver, 12U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 21U, 45U);
  c9_hoistedGlobal = chartInstance->c9_hF;
  c9_b_hoistedGlobal = c9_get_interest(chartInstance, 0);
  c9_x = c9_hoistedGlobal * c9_b_hoistedGlobal * (*c9_randArray)[2];
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarFloor(c9_b_x);
  c9_lowhigh[0] = 1.0;
  c9_lowhigh[1] = c9_b_x;
  c9_high = c9_lowhigh[1];
  if (1.0 <= c9_high) {
  } else {
    for (c9_i31 = 0; c9_i31 < 26; c9_i31++) {
      c9_u[c9_i31] = c9_cv0[c9_i31];
    }

    c9_y = NULL;
    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c9_y));
  }

  c9_s = (c9_high - 1.0) + 1.0;
  c9_r = c9_rand(chartInstance);
  c9_c_x = c9_r * c9_s;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarFloor(c9_d_x);
  c9_r = 1.0 + c9_d_x;
  chartInstance->c9_randHeadChance = c9_r;
  c9_updateDataWrittenToVector(chartInstance, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_randHeadChance, 27U);
  chartInstance->c9_gazeUserHandChance = (*c9_randArray)[3];
  c9_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_gazeUserHandChance, 29U);
  chartInstance->c9_gazeGUIChance = (*c9_randArray)[4];
  c9_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_gazeGUIChance, 19U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateRandGen(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_e_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_f_out;
  real_T *c9_gameState;
  real_T *c9_personality;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_gd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  guard8 = false;
  guard9 = false;
  guard10 = false;
  if (CV_EML_COND(0, 0, 0, c9_get_avert(chartInstance, 0) == 0.0)) {
    if (CV_EML_COND(0, 0, 1, chartInstance->c9_randHeadChance == 1.0)) {
      if (CV_EML_COND(0, 0, 2, *c9_gameState != c9_get_STATE_GO(chartInstance, 0)))
      {
        if (CV_EML_COND(0, 0, 3, *c9_gameState != c9_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(0, 0, 0, true);
          CV_EML_IF(0, 0, 0, true);
          c9_out = true;
        } else {
          guard8 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard9 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
      guard10 = true;
    }
  } else {
    c9_errorIfDataNotWrittenToFcn(chartInstance, 12U, 27U);
    guard10 = true;
  }

  if (guard10 == true) {
    guard9 = true;
  }

  if (guard9 == true) {
    guard8 = true;
  }

  if (guard8 == true) {
    CV_EML_MCDC(0, 0, 0, false);
    CV_EML_IF(0, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_yd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(25, 0, 0, *c9_personality == 2.0)) {
      guard3 = true;
    } else if (CV_EML_COND(25, 0, 1, *c9_personality == 4.0)) {
      guard3 = true;
    } else {
      CV_EML_MCDC(25, 0, 0, false);
      CV_EML_IF(25, 0, 0, false);
      c9_b_out = false;
    }

    if (guard3 == true) {
      CV_EML_MCDC(25, 0, 0, true);
      CV_EML_IF(25, 0, 0, true);
      c9_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandGen = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertHeadIntrovert;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateAvertHeadIntrovert = 1U;
      c9_enter_atomic_stateAvertHeadIntrovert(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ae_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(24, 0, 0, *c9_personality == 1.0)) {
        guard2 = true;
      } else if (CV_EML_COND(24, 0, 1, *c9_personality == 3.0)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(24, 0, 0, false);
        CV_EML_IF(24, 0, 0, false);
        c9_c_out = false;
      }

      if (guard2 == true) {
        CV_EML_MCDC(24, 0, 0, true);
        CV_EML_IF(24, 0, 0, true);
        c9_c_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateRandGen = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertHeadExtrovert;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateAvertHeadExtrovert = 1U;
        c9_enter_atomic_stateAvertHeadExtrovert(chartInstance);
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_hd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 14U, 29U);
    guard7 = false;
    if (CV_EML_COND(3, 0, 0, chartInstance->c9_gazeUserHandChance == 1.0)) {
      if (CV_EML_COND(3, 0, 1, c9_get_gazing(chartInstance, 0) ==
                      c9_get_GAZE_USER_HAND(chartInstance, 0))) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c9_d_out = true;
      } else {
        guard7 = true;
      }
    } else {
      guard7 = true;
    }

    if (guard7 == true) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c9_d_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandGen = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateGazingUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateGazingUserHand = 1U;
      c9_enter_atomic_stateGazingUserHand(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_id_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 4U, 19U);
      guard6 = false;
      if (CV_EML_COND(2, 0, 0, chartInstance->c9_gazeGUIChance == 1.0)) {
        if (CV_EML_COND(2, 0, 1, c9_get_gazing(chartInstance, 0) ==
                        c9_get_GAZE_GUI(chartInstance, 0))) {
          CV_EML_MCDC(2, 0, 0, true);
          CV_EML_IF(2, 0, 0, true);
          c9_e_out = true;
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }

      if (guard6 == true) {
        CV_EML_MCDC(2, 0, 0, false);
        CV_EML_IF(2, 0, 0, false);
        c9_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateRandGen = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_stateGazingGUI;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateGazingGUI = 1U;
        c9_enter_atomic_stateGazingGUI(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_jd_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        guard4 = false;
        guard5 = false;
        if (CV_EML_COND(16, 0, 0, c9_get_changeFlag(chartInstance, 0) != 1.0)) {
          if (CV_EML_COND(16, 0, 1, *c9_gameState != c9_get_STATE_GO
                          (chartInstance, 0))) {
            if (CV_EML_COND(16, 0, 2, *c9_gameState != c9_get_STATE_READY
                            (chartInstance, 0))) {
              CV_EML_MCDC(16, 0, 0, true);
              CV_EML_IF(16, 0, 0, true);
              c9_f_out = true;
            } else {
              guard4 = true;
            }
          } else {
            c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
            guard5 = true;
          }
        } else {
          c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
          guard5 = true;
        }

        if (guard5 == true) {
          guard4 = true;
        }

        if (guard4 == true) {
          CV_EML_MCDC(16, 0, 0, false);
          CV_EML_IF(16, 0, 0, false);
          c9_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateRandGen = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
          chartInstance->c9_isStable = false;
          chartInstance->c9_is_stateGazeIde = c9_IN_stateCheckMutCont;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateCheckMutCont = 1U;
          c9_enter_atomic_stateCheckMutCont(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                       chartInstance->c9_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateCheckMutCont
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  int32_T c9_i32;
  static real_T c9_dv6[3] = { 0.0003, -0.18, 32.0 };

  int32_T c9_i33;
  real_T c9_hoistedGlobal;
  real_T c9_x;
  int32_T c9_k;
  real_T c9_b_k;
  real_T (*c9_randArray)[25];
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_pc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  for (c9_i32 = 0; c9_i32 < 3; c9_i32++) {
    chartInstance->c9_mutContF[c9_i32] = c9_dv6[c9_i32];
  }

  c9_updateDataWrittenToVector(chartInstance, 6U);
  for (c9_i33 = 0; c9_i33 < 3; c9_i33++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_mutContF[c9_i33], 21U);
  }

  chartInstance->c9_CHANCEM = (*c9_randArray)[5];
  c9_updateDataWrittenToVector(chartInstance, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_CHANCEM, 22U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 6U, 21U);
  c9_hoistedGlobal = c9_get_boredom(chartInstance, 0);
  c9_x = c9_hoistedGlobal * 40.0;
  chartInstance->c9_mutContChance = chartInstance->c9_mutContF[0];
  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_b_k = 2.0 + (real_T)c9_k;
    chartInstance->c9_mutContChance = c9_x * chartInstance->c9_mutContChance +
      chartInstance->c9_mutContF[(int32_T)c9_b_k - 1];
  }

  c9_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_mutContChance, 20U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateCheckMutCont(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_e_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_f_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_A;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_y;
  real_T c9_d0;
  real_T *c9_gameState;
  real_T *c9_personality;
  real_T (*c9_randArray)[25];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_od_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 7U, 22U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 20U);
  guard8 = false;
  guard9 = false;
  guard10 = false;
  if (CV_EML_COND(14, 0, 0, chartInstance->c9_CHANCEM >
                  chartInstance->c9_mutContChance)) {
    if (CV_EML_COND(14, 0, 1, c9_get_changeFlag(chartInstance, 0) != 1.0)) {
      if (CV_EML_COND(14, 0, 2, *c9_gameState != c9_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(14, 0, 3, *c9_gameState != c9_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(14, 0, 0, true);
          CV_EML_IF(14, 0, 0, true);
          c9_out = true;
        } else {
          guard8 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard9 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 == true) {
    guard9 = true;
  }

  if (guard9 == true) {
    guard8 = true;
  }

  if (guard8 == true) {
    CV_EML_MCDC(14, 0, 0, false);
    CV_EML_IF(14, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateCheckMutCont = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertGaze;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateAvertGaze = 1U;
    c9_enter_atomic_stateAvertGaze(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_nd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    if (CV_EML_COND(20, 0, 0, c9_get_avert(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(20, 0, 1, chartInstance->c9_CHANCEM <=
                      chartInstance->c9_mutContChance)) {
        if (CV_EML_COND(20, 0, 2, c9_get_changeFlag(chartInstance, 0) != 1.0)) {
          if (CV_EML_COND(20, 0, 3, *c9_gameState != c9_get_STATE_GO
                          (chartInstance, 0))) {
            if (CV_EML_COND(20, 0, 4, *c9_gameState != c9_get_STATE_READY
                            (chartInstance, 0))) {
              CV_EML_MCDC(20, 0, 0, true);
              CV_EML_IF(20, 0, 0, true);
              c9_b_out = true;
            } else {
              guard4 = true;
            }
          } else {
            c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
            guard5 = true;
          }
        } else {
          c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
          guard6 = true;
        }
      } else {
        guard7 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 5U, 20U);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 7U, 22U);
      guard7 = true;
    }

    if (guard7 == true) {
      guard6 = true;
    }

    if (guard6 == true) {
      guard5 = true;
    }

    if (guard5 == true) {
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(20, 0, 0, false);
      CV_EML_IF(20, 0, 0, false);
      c9_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_xd_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_c_out = CV_EML_IF(35, 0, 0, c9_get_avertH(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      guard1 = false;
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ce_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        guard3 = false;
        if (CV_EML_COND(34, 0, 0, *c9_personality == 2.0)) {
          guard3 = true;
        } else if (CV_EML_COND(34, 0, 1, *c9_personality == 4.0)) {
          guard3 = true;
        } else {
          CV_EML_MCDC(34, 0, 0, false);
          CV_EML_IF(34, 0, 0, false);
          c9_d_out = false;
        }

        if (guard3 == true) {
          CV_EML_MCDC(34, 0, 0, true);
          CV_EML_IF(34, 0, 0, true);
          c9_d_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateCheckMutCont = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
          chartInstance->c9_isStable = false;
          chartInstance->c9_is_stateGazeIde = c9_IN_iHeadNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
          chartInstance->c9_temporalCounter_i1 = 0U;
          chartInstance->c9_tp_iHeadNeutral = 1U;
          c9_enter_atomic_iHeadNeutral(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                       chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_be_debug_family_names,
            c9_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U,
            c9_c_sf_marshallOut, c9_c_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(28, 0, 0, *c9_personality == 1.0)) {
            guard2 = true;
          } else if (CV_EML_COND(28, 0, 1, *c9_personality == 3.0)) {
            guard2 = true;
          } else {
            CV_EML_MCDC(28, 0, 0, false);
            CV_EML_IF(28, 0, 0, false);
            c9_e_out = false;
          }

          if (guard2 == true) {
            CV_EML_MCDC(28, 0, 0, true);
            CV_EML_IF(28, 0, 0, true);
            c9_e_out = true;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c9_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_stateCheckMutCont = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
            chartInstance->c9_isStable = false;
            chartInstance->c9_is_stateGazeIde = c9_IN_eHeadNeutral;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
            chartInstance->c9_temporalCounter_i1 = 0U;
            chartInstance->c9_tp_eHeadNeutral = 1U;
            c9_enter_atomic_eHeadNeutral(chartInstance);
          } else {
            guard1 = true;
          }
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCheckMutCont = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_stateMutualGazeE;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateMutualGazeE = 1U;
        c9_enter_atomic_stateMutualGazeE(chartInstance);
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_md_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_f_out = CV_EML_IF(22, 0, 0, c9_get_avert(chartInstance, 0) == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCheckMutCont = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_mut;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_mut = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_qc_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        chartInstance->c9_chanceO = (*c9_randArray)[16];
        c9_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_chanceO, 33U);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 15U, 33U);
        c9_hoistedGlobal = chartInstance->c9_chanceO;
        c9_A = c9_hoistedGlobal;
        c9_x = c9_A;
        c9_b_x = c9_x;
        c9_c_x = c9_b_x;
        c9_y = c9_c_x / 15.7;
        c9_d0 = c9_y;
        c9_b_log(chartInstance, &c9_d0);
        chartInstance->c9_magnitude = -6.9 * c9_d0;
        c9_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_magnitude, 26U);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 20U, 44U);
        chartInstance->c9_mutDur = (25.0 + 2.5 * chartInstance->c9_magnitude) *
          chartInstance->c9_mF;
        c9_updateDataWrittenToVector(chartInstance, 19U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c9_mutDur, 42U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                     chartInstance->c9_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateAvertGaze(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_A;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_y;
  real_T c9_d1;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_dv7[256];
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  real_T c9_dv8[1280];
  int32_T c9_i37;
  real_T c9_dv9[256];
  real_T c9_dv10[1280];
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  real_T *c9_personality;
  real_T (*c9_randArray)[25];
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  chartInstance->c9_chanceO = (*c9_randArray)[6];
  c9_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_chanceO, 33U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 15U, 33U);
  c9_hoistedGlobal = chartInstance->c9_chanceO;
  c9_A = c9_hoistedGlobal;
  c9_x = c9_A;
  c9_b_x = c9_x;
  c9_c_x = c9_b_x;
  c9_y = c9_c_x / 15.7;
  c9_d1 = c9_y;
  c9_b_log(chartInstance, &c9_d1);
  chartInstance->c9_magnitude = -6.9 * c9_d1;
  c9_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_magnitude, 26U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 22U, 46U);
  chartInstance->c9_avertDur = (25.0 + 2.5 * chartInstance->c9_magnitude) *
    chartInstance->c9_aF;
  c9_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_avertDur, 23U);
  chartInstance->c9_gazeDir = (*c9_randArray)[7];
  c9_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_gazeDir, 24U);
  c9_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 9U, 24U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
  c9_b_hoistedGlobal = chartInstance->c9_gazeDir;
  c9_c_hoistedGlobal = chartInstance->c9_magnitude;
  c9_d_x = c9_c_hoistedGlobal;
  c9_e_x = c9_d_x;
  c9_e_x = muDoubleScalarRound(c9_e_x);
  c9_idleGazeFunctionc9_Demo_EP_IdleRand(chartInstance, c9_b_hoistedGlobal,
    c9_e_x, *c9_personality, c9_dv7);
  for (c9_i34 = 0; c9_i34 < 256; c9_i34++) {
    chartInstance->c9_BMLl[c9_i34] = c9_dv7[c9_i34];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i35 = 0; c9_i35 < 256; c9_i35++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i35], 37U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i36 = 0; c9_i36 < 1280; c9_i36++) {
    c9_dv8[c9_i36] = c9_get_bmlsL(chartInstance, c9_i36);
  }

  for (c9_i37 = 0; c9_i37 < 256; c9_i37++) {
    c9_dv9[c9_i37] = chartInstance->c9_BMLl[c9_i37];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv8, c9_dv9, c9_dv10);
  for (c9_i38 = 0; c9_i38 < 1280; c9_i38++) {
    chartInstance->c9_newBmlsL[c9_i38] = c9_dv10[c9_i38];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i39 = 0; c9_i39 < 1280; c9_i39++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i39], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i40 = 0; c9_i40 < 1280; c9_i40++) {
    c9_set_bmlsL(chartInstance, c9_i40, chartInstance->c9_newBmlsL[c9_i40]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateCheckAvertCont(SFc9_Demo_EP_IdleRandInstanceStruct
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
  real_T c9_d_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_e_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 1.0;
  boolean_T c9_f_out;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 1.0;
  boolean_T c9_g_out;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 1.0;
  boolean_T c9_h_out;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 1.0;
  boolean_T c9_i_out;
  real_T *c9_gameState;
  real_T *c9_personality;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_sd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
  c9_out = CV_EML_IF(18, 0, 0, chartInstance->c9_avertContChance <= 0.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_td_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    chartInstance->c9_avertContChance = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_avertContChance, 18U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_qd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
    guard7 = false;
    guard8 = false;
    if (CV_EML_COND(17, 0, 0, chartInstance->c9_CHANCEA <=
                    chartInstance->c9_avertContChance)) {
      if (CV_EML_COND(17, 0, 1, *c9_gameState != c9_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(17, 0, 2, *c9_gameState != c9_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(17, 0, 0, true);
          CV_EML_IF(17, 0, 0, true);
          c9_b_out = true;
        } else {
          guard7 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard8 = true;
      }
    } else {
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
      guard8 = true;
    }

    if (guard8 == true) {
      guard7 = true;
    }

    if (guard7 == true) {
      CV_EML_MCDC(17, 0, 0, false);
      CV_EML_IF(17, 0, 0, false);
      c9_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateCheckAvertCont = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertGaze;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateAvertGaze = 1U;
      c9_enter_atomic_stateAvertGaze(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ud_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
      guard5 = false;
      guard6 = false;
      if (CV_EML_COND(19, 0, 0, chartInstance->c9_CHANCEA >
                      chartInstance->c9_avertContChance)) {
        if (CV_EML_COND(19, 0, 1, *c9_gameState != c9_get_STATE_GO(chartInstance,
              0))) {
          if (CV_EML_COND(19, 0, 2, *c9_gameState != c9_get_STATE_READY
                          (chartInstance, 0))) {
            CV_EML_MCDC(19, 0, 0, true);
            CV_EML_IF(19, 0, 0, true);
            c9_c_out = true;
          } else {
            guard5 = true;
          }
        } else {
          c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
          guard6 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard6 = true;
      }

      if (guard6 == true) {
        guard5 = true;
      }

      if (guard5 == true) {
        CV_EML_MCDC(19, 0, 0, false);
        CV_EML_IF(19, 0, 0, false);
        c9_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
        guard3 = true;
      } else {
        guard4 = true;
      }
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_rd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
    c9_d_out = CV_EML_IF(21, 0, 0, chartInstance->c9_avertContChance > 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_qd_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
      guard13 = false;
      guard14 = false;
      if (CV_EML_COND(17, 0, 0, chartInstance->c9_CHANCEA <=
                      chartInstance->c9_avertContChance)) {
        if (CV_EML_COND(17, 0, 1, *c9_gameState != c9_get_STATE_GO(chartInstance,
              0))) {
          if (CV_EML_COND(17, 0, 2, *c9_gameState != c9_get_STATE_READY
                          (chartInstance, 0))) {
            CV_EML_MCDC(17, 0, 0, true);
            CV_EML_IF(17, 0, 0, true);
            c9_e_out = true;
          } else {
            guard13 = true;
          }
        } else {
          c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
          guard14 = true;
        }
      } else {
        c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
        guard14 = true;
      }

      if (guard14 == true) {
        guard13 = true;
      }

      if (guard13 == true) {
        CV_EML_MCDC(17, 0, 0, false);
        CV_EML_IF(17, 0, 0, false);
        c9_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCheckAvertCont = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertGaze;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_stateAvertGaze = 1U;
        c9_enter_atomic_stateAvertGaze(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ud_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 10U, 25U);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 3U, 18U);
        guard11 = false;
        guard12 = false;
        if (CV_EML_COND(19, 0, 0, chartInstance->c9_CHANCEA >
                        chartInstance->c9_avertContChance)) {
          if (CV_EML_COND(19, 0, 1, *c9_gameState != c9_get_STATE_GO
                          (chartInstance, 0))) {
            if (CV_EML_COND(19, 0, 2, *c9_gameState != c9_get_STATE_READY
                            (chartInstance, 0))) {
              CV_EML_MCDC(19, 0, 0, true);
              CV_EML_IF(19, 0, 0, true);
              c9_f_out = true;
            } else {
              guard11 = true;
            }
          } else {
            c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
            guard12 = true;
          }
        } else {
          c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 13U);
          guard12 = true;
        }

        if (guard12 == true) {
          guard11 = true;
        }

        if (guard11 == true) {
          CV_EML_MCDC(19, 0, 0, false);
          CV_EML_IF(19, 0, 0, false);
          c9_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
          guard3 = true;
        } else {
          guard2 = true;
        }
      }
    } else {
      guard2 = true;
    }
  }

  if (guard3 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_xd_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_g_out = CV_EML_IF(35, 0, 0, c9_get_avertH(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ce_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard10 = false;
      if (CV_EML_COND(34, 0, 0, *c9_personality == 2.0)) {
        guard10 = true;
      } else if (CV_EML_COND(34, 0, 1, *c9_personality == 4.0)) {
        guard10 = true;
      } else {
        CV_EML_MCDC(34, 0, 0, false);
        CV_EML_IF(34, 0, 0, false);
        c9_h_out = false;
      }

      if (guard10 == true) {
        CV_EML_MCDC(34, 0, 0, true);
        CV_EML_IF(34, 0, 0, true);
        c9_h_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateCheckAvertCont = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_iHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_iHeadNeutral = 1U;
        c9_enter_atomic_iHeadNeutral(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_be_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        guard9 = false;
        if (CV_EML_COND(28, 0, 0, *c9_personality == 1.0)) {
          guard9 = true;
        } else if (CV_EML_COND(28, 0, 1, *c9_personality == 3.0)) {
          guard9 = true;
        } else {
          CV_EML_MCDC(28, 0, 0, false);
          CV_EML_IF(28, 0, 0, false);
          c9_i_out = false;
        }

        if (guard9 == true) {
          CV_EML_MCDC(28, 0, 0, true);
          CV_EML_IF(28, 0, 0, true);
          c9_i_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateCheckAvertCont = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
          chartInstance->c9_isStable = false;
          chartInstance->c9_is_stateGazeIde = c9_IN_eHeadNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
          chartInstance->c9_temporalCounter_i1 = 0U;
          chartInstance->c9_tp_eHeadNeutral = 1U;
          c9_enter_atomic_eHeadNeutral(chartInstance);
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateCheckAvertCont = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_stateGazeIde = c9_IN_stateMutualGazeE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateMutualGazeE = 1U;
    c9_enter_atomic_stateMutualGazeE(chartInstance);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateMutualGazeE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_hoistedGlobal;
  real_T c9_A;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_y;
  real_T c9_d2;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i41;
  real_T c9_c_BMLl[256];
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  real_T c9_dv11[1280];
  int32_T c9_i45;
  real_T c9_dv12[256];
  real_T c9_dv13[1280];
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  real_T (*c9_randArray)[25];
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_tc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  chartInstance->c9_chanceO = (*c9_randArray)[16];
  c9_updateDataWrittenToVector(chartInstance, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_chanceO, 33U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 15U, 33U);
  c9_hoistedGlobal = chartInstance->c9_chanceO;
  c9_A = c9_hoistedGlobal;
  c9_x = c9_A;
  c9_b_x = c9_x;
  c9_c_x = c9_b_x;
  c9_y = c9_c_x / 15.7;
  c9_d2 = c9_y;
  c9_b_log(chartInstance, &c9_d2);
  chartInstance->c9_magnitude = -6.9 * c9_d2;
  c9_updateDataWrittenToVector(chartInstance, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_magnitude, 26U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 11U, 26U);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 20U, 44U);
  chartInstance->c9_mutDur = (25.0 + 2.5 * chartInstance->c9_magnitude) *
    chartInstance->c9_mF;
  c9_updateDataWrittenToVector(chartInstance, 19U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_mutDur, 42U);
  c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand(chartInstance, 11.0, &c9_P,
    c9_b_BMLl);
  for (c9_i41 = 0; c9_i41 < 256; c9_i41++) {
    c9_c_BMLl[c9_i41] = c9_b_BMLl[c9_i41];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i42 = 0; c9_i42 < 256; c9_i42++) {
    chartInstance->c9_BMLl[c9_i42] = c9_c_BMLl[c9_i42];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i43 = 0; c9_i43 < 256; c9_i43++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i43], 37U);
  }

  c9_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i44 = 0; c9_i44 < 1280; c9_i44++) {
    c9_dv11[c9_i44] = c9_get_bmlsL(chartInstance, c9_i44);
  }

  for (c9_i45 = 0; c9_i45 < 256; c9_i45++) {
    c9_dv12[c9_i45] = chartInstance->c9_BMLl[c9_i45];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv11, c9_dv12, c9_dv13);
  for (c9_i46 = 0; c9_i46 < 1280; c9_i46++) {
    chartInstance->c9_newBmlsL[c9_i46] = c9_dv13[c9_i46];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i47 = 0; c9_i47 < 1280; c9_i47++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i47], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i48 = 0; c9_i48 < 1280; c9_i48++) {
    c9_set_bmlsL(chartInstance, c9_i48, chartInstance->c9_newBmlsL[c9_i48]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateMutualGazeE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  boolean_T c9_temp;
  uint32_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_x;
  real_T c9_b_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_kd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 19U, 42U);
  c9_temp = (chartInstance->c9_sfEvent == c9_event_secs);
  if (c9_temp) {
    c9_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
    c9_b_hoistedGlobal = chartInstance->c9_mutDur;
    c9_x = c9_b_hoistedGlobal;
    c9_b_x = c9_x;
    c9_b_x = muDoubleScalarFloor(c9_b_x);
    c9_temp = (c9_hoistedGlobal >= _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
                c9_b_x, 32U, 27U));
  }

  c9_out = CV_EML_IF(27, 0, 0, c9_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateMutualGazeE = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGen;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateRandGen = 1U;
    c9_enter_atomic_stateRandGen(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateAvertHeadExtrovert
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i49;
  real_T c9_c_BMLl[256];
  int32_T c9_i50;
  int32_T c9_i51;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  int32_T c9_i52;
  real_T c9_b_u[256];
  const mxArray *c9_b_y = NULL;
  int32_T c9_i53;
  real_T c9_dv14[1280];
  int32_T c9_i54;
  real_T c9_dv15[256];
  real_T c9_dv16[1280];
  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
  real_T (*c9_randArray)[25];
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_uc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_set_avertH(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c9_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand(chartInstance, (*c9_randArray)[17],
    &c9_P, c9_b_BMLl);
  for (c9_i49 = 0; c9_i49 < 256; c9_i49++) {
    c9_c_BMLl[c9_i49] = c9_b_BMLl[c9_i49];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i50 = 0; c9_i50 < 256; c9_i50++) {
    chartInstance->c9_BMLl[c9_i50] = c9_c_BMLl[c9_i50];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i51 = 0; c9_i51 < 256; c9_i51++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i51], 37U);
  }

  sf_mex_printf("%s =\\n", "P");
  c9_hoistedGlobal = c9_get_P(chartInstance, 0);
  c9_u = c9_hoistedGlobal;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c9_y);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  sf_mex_printf("%s =\\n", "BMLl");
  for (c9_i52 = 0; c9_i52 < 256; c9_i52++) {
    c9_b_u[c9_i52] = chartInstance->c9_BMLl[c9_i52];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c9_b_y);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i53 = 0; c9_i53 < 1280; c9_i53++) {
    c9_dv14[c9_i53] = c9_get_bmlsL(chartInstance, c9_i53);
  }

  for (c9_i54 = 0; c9_i54 < 256; c9_i54++) {
    c9_dv15[c9_i54] = chartInstance->c9_BMLl[c9_i54];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv14, c9_dv15, c9_dv16);
  for (c9_i55 = 0; c9_i55 < 1280; c9_i55++) {
    chartInstance->c9_newBmlsL[c9_i55] = c9_dv16[c9_i55];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i56 = 0; c9_i56 < 1280; c9_i56++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i56], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i57 = 0; c9_i57 < 1280; c9_i57++) {
    c9_set_bmlsL(chartInstance, c9_i57, chartInstance->c9_newBmlsL[c9_i57]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_eHeadNeutral(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i58;
  real_T c9_c_BMLl[256];
  int32_T c9_i59;
  int32_T c9_i60;
  int32_T c9_i61;
  real_T c9_dv17[1280];
  int32_T c9_i62;
  real_T c9_dv18[256];
  real_T c9_dv19[1280];
  int32_T c9_i63;
  int32_T c9_i64;
  int32_T c9_i65;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_vc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand(chartInstance, 12.0, &c9_P,
    c9_b_BMLl);
  for (c9_i58 = 0; c9_i58 < 256; c9_i58++) {
    c9_c_BMLl[c9_i58] = c9_b_BMLl[c9_i58];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i59 = 0; c9_i59 < 256; c9_i59++) {
    chartInstance->c9_BMLl[c9_i59] = c9_c_BMLl[c9_i59];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i60 = 0; c9_i60 < 256; c9_i60++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i60], 37U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i61 = 0; c9_i61 < 1280; c9_i61++) {
    c9_dv17[c9_i61] = c9_get_bmlsL(chartInstance, c9_i61);
  }

  for (c9_i62 = 0; c9_i62 < 256; c9_i62++) {
    c9_dv18[c9_i62] = chartInstance->c9_BMLl[c9_i62];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv17, c9_dv18, c9_dv19);
  for (c9_i63 = 0; c9_i63 < 1280; c9_i63++) {
    chartInstance->c9_newBmlsL[c9_i63] = c9_dv19[c9_i63];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i64 = 0; c9_i64 < 1280; c9_i64++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i64], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i65 = 0; c9_i65 < 1280; c9_i65++) {
    c9_set_bmlsL(chartInstance, c9_i65, chartInstance->c9_newBmlsL[c9_i65]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  c9_set_avertH(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_stateAvertHeadIntrovert
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i66;
  real_T c9_c_BMLl[256];
  int32_T c9_i67;
  int32_T c9_i68;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  int32_T c9_i69;
  real_T c9_b_u[256];
  const mxArray *c9_b_y = NULL;
  int32_T c9_i70;
  real_T c9_dv20[1280];
  int32_T c9_i71;
  real_T c9_dv21[256];
  real_T c9_dv22[1280];
  int32_T c9_i72;
  int32_T c9_i73;
  int32_T c9_i74;
  real_T (*c9_randArray)[25];
  c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_wc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_set_avertH(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c9_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c9_idleGazeTableIntrovertc9_Demo_EP_IdleRand(chartInstance, (*c9_randArray)[18],
    &c9_P, c9_b_BMLl);
  for (c9_i66 = 0; c9_i66 < 256; c9_i66++) {
    c9_c_BMLl[c9_i66] = c9_b_BMLl[c9_i66];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i67 = 0; c9_i67 < 256; c9_i67++) {
    chartInstance->c9_BMLl[c9_i67] = c9_c_BMLl[c9_i67];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i68 = 0; c9_i68 < 256; c9_i68++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i68], 37U);
  }

  sf_mex_printf("%s =\\n", "P");
  c9_hoistedGlobal = c9_get_P(chartInstance, 0);
  c9_u = c9_hoistedGlobal;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c9_y);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  sf_mex_printf("%s =\\n", "BMLl");
  for (c9_i69 = 0; c9_i69 < 256; c9_i69++) {
    c9_b_u[c9_i69] = chartInstance->c9_BMLl[c9_i69];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c9_b_y);
  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i70 = 0; c9_i70 < 1280; c9_i70++) {
    c9_dv20[c9_i70] = c9_get_bmlsL(chartInstance, c9_i70);
  }

  for (c9_i71 = 0; c9_i71 < 256; c9_i71++) {
    c9_dv21[c9_i71] = chartInstance->c9_BMLl[c9_i71];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv20, c9_dv21, c9_dv22);
  for (c9_i72 = 0; c9_i72 < 1280; c9_i72++) {
    chartInstance->c9_newBmlsL[c9_i72] = c9_dv22[c9_i72];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i73 = 0; c9_i73 < 1280; c9_i73++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i73], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i74 = 0; c9_i74 < 1280; c9_i74++) {
    c9_set_bmlsL(chartInstance, c9_i74, chartInstance->c9_newBmlsL[c9_i74]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_iHeadNeutral(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i75;
  real_T c9_c_BMLl[256];
  int32_T c9_i76;
  int32_T c9_i77;
  int32_T c9_i78;
  real_T c9_dv23[1280];
  int32_T c9_i79;
  real_T c9_dv24[256];
  real_T c9_dv25[1280];
  int32_T c9_i80;
  int32_T c9_i81;
  int32_T c9_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_xc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_idleGazeTableIntrovertc9_Demo_EP_IdleRand(chartInstance, 13.0, &c9_P,
    c9_b_BMLl);
  for (c9_i75 = 0; c9_i75 < 256; c9_i75++) {
    c9_c_BMLl[c9_i75] = c9_b_BMLl[c9_i75];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i76 = 0; c9_i76 < 256; c9_i76++) {
    chartInstance->c9_BMLl[c9_i76] = c9_c_BMLl[c9_i76];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i77 = 0; c9_i77 < 256; c9_i77++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i77], 37U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i78 = 0; c9_i78 < 1280; c9_i78++) {
    c9_dv23[c9_i78] = c9_get_bmlsL(chartInstance, c9_i78);
  }

  for (c9_i79 = 0; c9_i79 < 256; c9_i79++) {
    c9_dv24[c9_i79] = chartInstance->c9_BMLl[c9_i79];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv23, c9_dv24, c9_dv25);
  for (c9_i80 = 0; c9_i80 < 1280; c9_i80++) {
    chartInstance->c9_newBmlsL[c9_i80] = c9_dv25[c9_i80];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i81 = 0; c9_i81 < 1280; c9_i81++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i81], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i82 = 0; c9_i82 < 1280; c9_i82++) {
    c9_set_bmlsL(chartInstance, c9_i82, chartInstance->c9_newBmlsL[c9_i82]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  c9_set_avertH(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_stateGazingGUI(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i83;
  real_T c9_c_BMLl[256];
  int32_T c9_i84;
  int32_T c9_i85;
  int32_T c9_i86;
  real_T c9_dv26[1280];
  int32_T c9_i87;
  real_T c9_dv27[256];
  real_T c9_dv28[1280];
  int32_T c9_i88;
  int32_T c9_i89;
  int32_T c9_i90;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_yc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_idleGazeTablec9_Demo_EP_IdleRand(chartInstance, 22.0, &c9_P, c9_b_BMLl);
  for (c9_i83 = 0; c9_i83 < 256; c9_i83++) {
    c9_c_BMLl[c9_i83] = c9_b_BMLl[c9_i83];
  }

  c9_set_P(chartInstance, 0, c9_P);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i84 = 0; c9_i84 < 256; c9_i84++) {
    chartInstance->c9_BMLl[c9_i84] = c9_c_BMLl[c9_i84];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i85 = 0; c9_i85 < 256; c9_i85++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i85], 37U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i86 = 0; c9_i86 < 1280; c9_i86++) {
    c9_dv26[c9_i86] = c9_get_bmlsL(chartInstance, c9_i86);
  }

  for (c9_i87 = 0; c9_i87 < 256; c9_i87++) {
    c9_dv27[c9_i87] = chartInstance->c9_BMLl[c9_i87];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv26, c9_dv27, c9_dv28);
  for (c9_i88 = 0; c9_i88 < 1280; c9_i88++) {
    chartInstance->c9_newBmlsL[c9_i88] = c9_dv28[c9_i88];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i89 = 0; c9_i89 < 1280; c9_i89++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i89], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i90 = 0; c9_i90 < 1280; c9_i90++) {
    c9_set_bmlsL(chartInstance, c9_i90, chartInstance->c9_newBmlsL[c9_i90]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateGazingGUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T *c9_personality;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_he_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(1, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 10U));
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ge_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(32, 0, 0, *c9_personality == 2.0)) {
      guard3 = true;
    } else if (CV_EML_COND(32, 0, 1, *c9_personality == 4.0)) {
      guard3 = true;
    } else {
      CV_EML_MCDC(32, 0, 0, false);
      CV_EML_IF(32, 0, 0, false);
      c9_b_out = false;
    }

    if (guard3 == true) {
      CV_EML_MCDC(32, 0, 0, true);
      CV_EML_IF(32, 0, 0, true);
      c9_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateGazingGUI = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_iHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_iHeadNeutral = 1U;
      c9_enter_atomic_iHeadNeutral(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ee_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(33, 0, 0, *c9_personality == 1.0)) {
        guard2 = true;
      } else if (CV_EML_COND(33, 0, 1, *c9_personality == 3.0)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(33, 0, 0, false);
        CV_EML_IF(33, 0, 0, false);
        c9_c_out = false;
      }

      if (guard2 == true) {
        CV_EML_MCDC(33, 0, 0, true);
        CV_EML_IF(33, 0, 0, true);
        c9_c_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateGazingGUI = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_eHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_eHeadNeutral = 1U;
        c9_enter_atomic_eHeadNeutral(chartInstance);
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateGazingUserHand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_b_BMLl[256];
  real_T c9_P;
  int32_T c9_i91;
  real_T c9_c_BMLl[256];
  int32_T c9_i92;
  int32_T c9_i93;
  int32_T c9_i94;
  real_T c9_dv29[1280];
  int32_T c9_i95;
  real_T c9_dv30[256];
  real_T c9_dv31[1280];
  int32_T c9_i96;
  int32_T c9_i97;
  int32_T c9_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ad_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_idleGazeTablec9_Demo_EP_IdleRand(chartInstance, 23.0, &c9_P, c9_b_BMLl);
  for (c9_i91 = 0; c9_i91 < 256; c9_i91++) {
    c9_c_BMLl[c9_i91] = c9_b_BMLl[c9_i91];
  }

  c9_set_P(chartInstance, 0, c9_P);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i92 = 0; c9_i92 < 256; c9_i92++) {
    chartInstance->c9_BMLl[c9_i92] = c9_c_BMLl[c9_i92];
  }

  c9_updateDataWrittenToVector(chartInstance, 16U);
  for (c9_i93 = 0; c9_i93 < 256; c9_i93++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_BMLl[c9_i93], 37U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 16U, 37U);
  for (c9_i94 = 0; c9_i94 < 1280; c9_i94++) {
    c9_dv29[c9_i94] = c9_get_bmlsL(chartInstance, c9_i94);
  }

  for (c9_i95 = 0; c9_i95 < 256; c9_i95++) {
    c9_dv30[c9_i95] = chartInstance->c9_BMLl[c9_i95];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_dv29, c9_dv30, c9_dv31);
  for (c9_i96 = 0; c9_i96 < 1280; c9_i96++) {
    chartInstance->c9_newBmlsL[c9_i96] = c9_dv31[c9_i96];
  }

  c9_updateDataWrittenToVector(chartInstance, 17U);
  for (c9_i97 = 0; c9_i97 < 1280; c9_i97++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_newBmlsL[c9_i97], 39U);
  }

  c9_errorIfDataNotWrittenToFcn(chartInstance, 17U, 39U);
  for (c9_i98 = 0; c9_i98 < 1280; c9_i98++) {
    c9_set_bmlsL(chartInstance, c9_i98, chartInstance->c9_newBmlsL[c9_i98]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 13);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateGazingUserHand(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_c_out;
  real_T *c9_personality;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ie_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  c9_out = CV_EML_IF(4, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                     (chartInstance->c9_temporalCounter_i1 >= 10U));
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ge_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(32, 0, 0, *c9_personality == 2.0)) {
      guard3 = true;
    } else if (CV_EML_COND(32, 0, 1, *c9_personality == 4.0)) {
      guard3 = true;
    } else {
      CV_EML_MCDC(32, 0, 0, false);
      CV_EML_IF(32, 0, 0, false);
      c9_b_out = false;
    }

    if (guard3 == true) {
      CV_EML_MCDC(32, 0, 0, true);
      CV_EML_IF(32, 0, 0, true);
      c9_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateGazingUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_iHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_iHeadNeutral = 1U;
      c9_enter_atomic_iHeadNeutral(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ee_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(33, 0, 0, *c9_personality == 1.0)) {
        guard2 = true;
      } else if (CV_EML_COND(33, 0, 1, *c9_personality == 3.0)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(33, 0, 0, false);
        CV_EML_IF(33, 0, 0, false);
        c9_c_out = false;
      }

      if (guard2 == true) {
        CV_EML_MCDC(33, 0, 0, true);
        CV_EML_IF(33, 0, 0, true);
        c9_c_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateGazingUserHand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_eHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
        chartInstance->c9_temporalCounter_i1 = 0U;
        chartInstance->c9_tp_eHeadNeutral = 1U;
        c9_enter_atomic_eHeadNeutral(chartInstance);
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateWinSmile(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_BML[256];
  real_T c9_P;
  int32_T c9_i99;
  real_T c9_b_BML[256];
  int32_T c9_i100;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_bd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_successTablec9_Demo_EP_IdleRand(chartInstance, 1.0, &c9_P, c9_BML);
  for (c9_i99 = 0; c9_i99 < 256; c9_i99++) {
    c9_b_BML[c9_i99] = c9_BML[c9_i99];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i100 = 0; c9_i100 < 256; c9_i100++) {
    c9_set_BML(chartInstance, c9_i100, c9_b_BML[c9_i100]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_stateNeckBack(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_BML[256];
  real_T c9_P;
  int32_T c9_i101;
  real_T c9_b_BML[256];
  int32_T c9_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_cd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_successTablec9_Demo_EP_IdleRand(chartInstance, 2.0, &c9_P, c9_BML);
  for (c9_i101 = 0; c9_i101 < 256; c9_i101++) {
    c9_b_BML[c9_i101] = c9_BML[c9_i101];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i102 = 0; c9_i102 < 256; c9_i102++) {
    c9_set_BML(chartInstance, c9_i102, c9_b_BML[c9_i102]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_stateBrowUp(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_BML[256];
  real_T c9_P;
  int32_T c9_i103;
  real_T c9_b_BML[256];
  int32_T c9_i104;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_dd_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_successTablec9_Demo_EP_IdleRand(chartInstance, 3.0, &c9_P, c9_BML);
  for (c9_i103 = 0; c9_i103 < 256; c9_i103++) {
    c9_b_BML[c9_i103] = c9_BML[c9_i103];
  }

  c9_set_P(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i104 = 0; c9_i104 < 256; c9_i104++) {
    c9_set_BML(chartInstance, c9_i104, c9_b_BML[c9_i104]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  c9_set_gazing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 17);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_enter_atomic_stateGazeSoftEye(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_BML[256];
  real_T c9_P;
  int32_T c9_i105;
  real_T c9_b_BML[256];
  int32_T c9_i106;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ed_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_idleGazeTablec9_Demo_EP_IdleRand(chartInstance, 19.0, &c9_P, c9_BML);
  for (c9_i105 = 0; c9_i105 < 256; c9_i105++) {
    c9_b_BML[c9_i105] = c9_BML[c9_i105];
  }

  c9_set_P(chartInstance, 0, c9_P);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  for (c9_i106 = 0; c9_i106 < 256; c9_i106++) {
    c9_set_BML(chartInstance, c9_i106, c9_b_BML[c9_i106]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[122];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[122];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i107;
  static char_T c9_cv1[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z',
    'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i108;
  static real_T c9_dv32[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i109;
  int32_T c9_i110;
  int32_T c9_i111;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_c_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i107 = 0; c9_i107 < 122; c9_i107++) {
    c9_mystr[c9_i107] = c9_cv1[c9_i107];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i108 = 0; c9_i108 < 122; c9_i108++) {
    c9_arr[c9_i108] = c9_dv32[c9_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i109 = 0; c9_i109 < 256; c9_i109++) {
    c9_tt[c9_i109] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i110 = 0; c9_i110 < 122; c9_i110++) {
    c9_tt[c9_i110] = c9_arr[c9_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i111 = 0; c9_i111 < 256; c9_i111++) {
    c9_myarr256[c9_i111] = c9_tt[c9_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_b_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[123];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[123];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i112;
  static char_T c9_cv2[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a',
    'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i113;
  static real_T c9_dv33[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i114;
  int32_T c9_i115;
  int32_T c9_i116;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_d_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i112 = 0; c9_i112 < 123; c9_i112++) {
    c9_mystr[c9_i112] = c9_cv2[c9_i112];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i113 = 0; c9_i113 < 123; c9_i113++) {
    c9_arr[c9_i113] = c9_dv33[c9_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i114 = 0; c9_i114 < 256; c9_i114++) {
    c9_tt[c9_i114] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i115 = 0; c9_i115 < 123; c9_i115++) {
    c9_tt[c9_i115] = c9_arr[c9_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i116 = 0; c9_i116 < 256; c9_i116++) {
    c9_myarr256[c9_i116] = c9_tt[c9_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[120];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[120];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i117;
  static char_T c9_cv3[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T',
    'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i118;
  static real_T c9_dv34[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i119;
  int32_T c9_i120;
  int32_T c9_i121;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_e_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i117 = 0; c9_i117 < 120; c9_i117++) {
    c9_mystr[c9_i117] = c9_cv3[c9_i117];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i118 = 0; c9_i118 < 120; c9_i118++) {
    c9_arr[c9_i118] = c9_dv34[c9_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i119 = 0; c9_i119 < 256; c9_i119++) {
    c9_tt[c9_i119] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i120 = 0; c9_i120 < 120; c9_i120++) {
    c9_tt[c9_i120] = c9_arr[c9_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i121 = 0; c9_i121 < 256; c9_i121++) {
    c9_myarr256[c9_i121] = c9_tt[c9_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_d_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[122];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[122];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i122;
  static char_T c9_cv4[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z',
    'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i123;
  static real_T c9_dv35[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i124;
  int32_T c9_i125;
  int32_T c9_i126;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_f_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i122 = 0; c9_i122 < 122; c9_i122++) {
    c9_mystr[c9_i122] = c9_cv4[c9_i122];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i123 = 0; c9_i123 < 122; c9_i123++) {
    c9_arr[c9_i123] = c9_dv35[c9_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i124 = 0; c9_i124 < 256; c9_i124++) {
    c9_tt[c9_i124] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i125 = 0; c9_i125 < 122; c9_i125++) {
    c9_tt[c9_i125] = c9_arr[c9_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i126 = 0; c9_i126 < 256; c9_i126++) {
    c9_myarr256[c9_i126] = c9_tt[c9_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_e_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[124];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[124];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i127;
  static char_T c9_cv5[124] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g',
    'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i128;
  static real_T c9_dv36[124] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i129;
  int32_T c9_i130;
  int32_T c9_i131;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_g_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i127 = 0; c9_i127 < 124; c9_i127++) {
    c9_mystr[c9_i127] = c9_cv5[c9_i127];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i128 = 0; c9_i128 < 124; c9_i128++) {
    c9_arr[c9_i128] = c9_dv36[c9_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 124.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 132.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i129 = 0; c9_i129 < 256; c9_i129++) {
    c9_tt[c9_i129] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i130 = 0; c9_i130 < 124; c9_i130++) {
    c9_tt[c9_i130] = c9_arr[c9_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i131 = 0; c9_i131 < 256; c9_i131++) {
    c9_myarr256[c9_i131] = c9_tt[c9_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_f_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[125];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[125];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i132;
  static char_T c9_cv6[125] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i133;
  static real_T c9_dv37[125] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0, 72.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i134;
  int32_T c9_i135;
  int32_T c9_i136;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_h_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i132 = 0; c9_i132 < 125; c9_i132++) {
    c9_mystr[c9_i132] = c9_cv6[c9_i132];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i133 = 0; c9_i133 < 125; c9_i133++) {
    c9_arr[c9_i133] = c9_dv37[c9_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 125.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 131.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i134 = 0; c9_i134 < 256; c9_i134++) {
    c9_tt[c9_i134] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i135 = 0; c9_i135 < 125; c9_i135++) {
    c9_tt[c9_i135] = c9_arr[c9_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i136 = 0; c9_i136 < 256; c9_i136++) {
    c9_myarr256[c9_i136] = c9_tt[c9_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_g_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[126];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[126];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i137;
  static char_T c9_cv7[126] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i138;
  static real_T c9_dv38[126] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i139;
  int32_T c9_i140;
  int32_T c9_i141;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_i_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i137 = 0; c9_i137 < 126; c9_i137++) {
    c9_mystr[c9_i137] = c9_cv7[c9_i137];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i138 = 0; c9_i138 < 126; c9_i138++) {
    c9_arr[c9_i138] = c9_dv38[c9_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 126.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 130.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i139 = 0; c9_i139 < 256; c9_i139++) {
    c9_tt[c9_i139] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i140 = 0; c9_i140 < 126; c9_i140++) {
    c9_tt[c9_i140] = c9_arr[c9_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i141 = 0; c9_i141 < 256; c9_i141++) {
    c9_myarr256[c9_i141] = c9_tt[c9_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_h_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[127];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[127];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i142;
  static char_T c9_cv8[127] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i143;
  static real_T c9_dv39[127] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i144;
  int32_T c9_i145;
  int32_T c9_i146;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_j_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i142 = 0; c9_i142 < 127; c9_i142++) {
    c9_mystr[c9_i142] = c9_cv8[c9_i142];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i143 = 0; c9_i143 < 127; c9_i143++) {
    c9_arr[c9_i143] = c9_dv39[c9_i143];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 127.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 129.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i144 = 0; c9_i144 < 256; c9_i144++) {
    c9_tt[c9_i144] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i145 = 0; c9_i145 < 127; c9_i145++) {
    c9_tt[c9_i145] = c9_arr[c9_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i146 = 0; c9_i146 < 256; c9_i146++) {
    c9_myarr256[c9_i146] = c9_tt[c9_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_i_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[149];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[149];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i147;
  static char_T c9_cv9[149] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd', 'i',
    'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E',
    'F', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a',
    'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i148;
  static real_T c9_dv40[149] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0,
    49.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i149;
  int32_T c9_i150;
  int32_T c9_i151;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_k_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i147 = 0; c9_i147 < 149; c9_i147++) {
    c9_mystr[c9_i147] = c9_cv9[c9_i147];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i148 = 0; c9_i148 < 149; c9_i148++) {
    c9_arr[c9_i148] = c9_dv40[c9_i148];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 149.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i149 = 0; c9_i149 < 256; c9_i149++) {
    c9_tt[c9_i149] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i150 = 0; c9_i150 < 149; c9_i150++) {
    c9_tt[c9_i150] = c9_arr[c9_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i151 = 0; c9_i151 < 256; c9_i151++) {
    c9_myarr256[c9_i151] = c9_tt[c9_i151];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_j_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[150];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[150];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i152;
  static char_T c9_cv10[150] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '1', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i153;
  static real_T c9_dv41[150] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0,
    34.0, 49.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i154;
  int32_T c9_i155;
  int32_T c9_i156;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_l_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i152 = 0; c9_i152 < 150; c9_i152++) {
    c9_mystr[c9_i152] = c9_cv10[c9_i152];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i153 = 0; c9_i153 < 150; c9_i153++) {
    c9_arr[c9_i153] = c9_dv41[c9_i153];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 150.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i154 = 0; c9_i154 < 256; c9_i154++) {
    c9_tt[c9_i154] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i155 = 0; c9_i155 < 150; c9_i155++) {
    c9_tt[c9_i155] = c9_arr[c9_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i156 = 0; c9_i156 < 256; c9_i156++) {
    c9_myarr256[c9_i156] = c9_tt[c9_i156];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_k_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[145];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[145];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i157;
  static char_T c9_cv11[145] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i158;
  static real_T c9_dv42[145] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0,
    84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i159;
  int32_T c9_i160;
  int32_T c9_i161;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_m_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i157 = 0; c9_i157 < 145; c9_i157++) {
    c9_mystr[c9_i157] = c9_cv11[c9_i157];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i158 = 0; c9_i158 < 145; c9_i158++) {
    c9_arr[c9_i158] = c9_dv42[c9_i158];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 145.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i159 = 0; c9_i159 < 256; c9_i159++) {
    c9_tt[c9_i159] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i160 = 0; c9_i160 < 145; c9_i160++) {
    c9_tt[c9_i160] = c9_arr[c9_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i161 = 0; c9_i161 < 256; c9_i161++) {
    c9_myarr256[c9_i161] = c9_tt[c9_i161];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_l_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[148];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[148];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i162;
  static char_T c9_cv12[148] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a',
    'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i163;
  static real_T c9_dv43[148] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0,
    53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i164;
  int32_T c9_i165;
  int32_T c9_i166;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_n_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i162 = 0; c9_i162 < 148; c9_i162++) {
    c9_mystr[c9_i162] = c9_cv12[c9_i162];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i163 = 0; c9_i163 < 148; c9_i163++) {
    c9_arr[c9_i163] = c9_dv43[c9_i163];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i164 = 0; c9_i164 < 256; c9_i164++) {
    c9_tt[c9_i164] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i165 = 0; c9_i165 < 148; c9_i165++) {
    c9_tt[c9_i165] = c9_arr[c9_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i166 = 0; c9_i166 < 256; c9_i166++) {
    c9_myarr256[c9_i166] = c9_tt[c9_i166];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_m_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i167;
  static char_T c9_cv13[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i168;
  static real_T c9_dv44[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i169;
  int32_T c9_i170;
  int32_T c9_i171;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_o_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i167 = 0; c9_i167 < 147; c9_i167++) {
    c9_mystr[c9_i167] = c9_cv13[c9_i167];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i168 = 0; c9_i168 < 147; c9_i168++) {
    c9_arr[c9_i168] = c9_dv44[c9_i168];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i169 = 0; c9_i169 < 256; c9_i169++) {
    c9_tt[c9_i169] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i170 = 0; c9_i170 < 147; c9_i170++) {
    c9_tt[c9_i170] = c9_arr[c9_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i171 = 0; c9_i171 < 256; c9_i171++) {
    c9_myarr256[c9_i171] = c9_tt[c9_i171];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_n_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[215];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[215];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i172;
  static char_T c9_cv14[215] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"',
    '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i173;
  static real_T c9_dv45[215] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 97.0,
    110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0,
    75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0,
    101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0,
    32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0,
    34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i174;
  int32_T c9_i175;
  int32_T c9_i176;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_p_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i172 = 0; c9_i172 < 215; c9_i172++) {
    c9_mystr[c9_i172] = c9_cv14[c9_i172];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i173 = 0; c9_i173 < 215; c9_i173++) {
    c9_arr[c9_i173] = c9_dv45[c9_i173];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 215.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 41.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i174 = 0; c9_i174 < 256; c9_i174++) {
    c9_tt[c9_i174] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i175 = 0; c9_i175 < 215; c9_i175++) {
    c9_tt[c9_i175] = c9_arr[c9_i175];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i176 = 0; c9_i176 < 256; c9_i176++) {
    c9_myarr256[c9_i176] = c9_tt[c9_i176];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_o_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[146];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[146];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i177;
  static char_T c9_cv15[146] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i178;
  static real_T c9_dv46[146] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i179;
  int32_T c9_i180;
  int32_T c9_i181;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_q_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i177 = 0; c9_i177 < 146; c9_i177++) {
    c9_mystr[c9_i177] = c9_cv15[c9_i177];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i178 = 0; c9_i178 < 146; c9_i178++) {
    c9_arr[c9_i178] = c9_dv46[c9_i178];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 146.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 110.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i179 = 0; c9_i179 < 256; c9_i179++) {
    c9_tt[c9_i179] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i180 = 0; c9_i180 < 146; c9_i180++) {
    c9_tt[c9_i180] = c9_arr[c9_i180];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i181 = 0; c9_i181 < 256; c9_i181++) {
    c9_myarr256[c9_i181] = c9_tt[c9_i181];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_p_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[145];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[145];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i182;
  static char_T c9_cv16[145] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i183;
  static real_T c9_dv47[145] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0,
    84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i184;
  int32_T c9_i185;
  int32_T c9_i186;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_r_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i182 = 0; c9_i182 < 145; c9_i182++) {
    c9_mystr[c9_i182] = c9_cv16[c9_i182];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i183 = 0; c9_i183 < 145; c9_i183++) {
    c9_arr[c9_i183] = c9_dv47[c9_i183];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 145.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i184 = 0; c9_i184 < 256; c9_i184++) {
    c9_tt[c9_i184] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i185 = 0; c9_i185 < 145; c9_i185++) {
    c9_tt[c9_i185] = c9_arr[c9_i185];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i186 = 0; c9_i186 < 256; c9_i186++) {
    c9_myarr256[c9_i186] = c9_tt[c9_i186];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_q_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[117];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[117];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i187;
  static char_T c9_cv17[117] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i188;
  static real_T c9_dv48[117] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i189;
  int32_T c9_i190;
  int32_T c9_i191;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_s_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i187 = 0; c9_i187 < 117; c9_i187++) {
    c9_mystr[c9_i187] = c9_cv17[c9_i187];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i188 = 0; c9_i188 < 117; c9_i188++) {
    c9_arr[c9_i188] = c9_dv48[c9_i188];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i189 = 0; c9_i189 < 256; c9_i189++) {
    c9_tt[c9_i189] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i190 = 0; c9_i190 < 117; c9_i190++) {
    c9_tt[c9_i190] = c9_arr[c9_i190];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i191 = 0; c9_i191 < 256; c9_i191++) {
    c9_myarr256[c9_i191] = c9_tt[c9_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_r_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[242];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[242];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i192;
  static char_T c9_cv18[242] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g',
    'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i193;
  static real_T c9_dv49[242] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 103.0,
    97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 50.0,
    48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0,
    110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0,
    61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i194;
  int32_T c9_i195;
  int32_T c9_i196;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_t_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i192 = 0; c9_i192 < 242; c9_i192++) {
    c9_mystr[c9_i192] = c9_cv18[c9_i192];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i193 = 0; c9_i193 < 242; c9_i193++) {
    c9_arr[c9_i193] = c9_dv49[c9_i193];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 242.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 14.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i194 = 0; c9_i194 < 256; c9_i194++) {
    c9_tt[c9_i194] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i195 = 0; c9_i195 < 242; c9_i195++) {
    c9_tt[c9_i195] = c9_arr[c9_i195];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i196 = 0; c9_i196 < 256; c9_i196++) {
    c9_myarr256[c9_i196] = c9_tt[c9_i196];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_s_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[151];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[151];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i197;
  static char_T c9_cv19[151] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '1', '\"', ' ', 'a', 'u', '=',
    '\"', '4', '5', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', ' ', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y',
    '=', '\"', '5', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '1', '0',
    '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '1', '5', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '0', '\"', ' ', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i198;
  static real_T c9_dv50[151] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    52.0, 53.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0,
    84.0, 72.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0,
    99.0, 115.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0,
    48.0, 34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 53.0, 34.0,
    32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0,
    32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 32.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i199;
  int32_T c9_i200;
  int32_T c9_i201;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_u_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i197 = 0; c9_i197 < 151; c9_i197++) {
    c9_mystr[c9_i197] = c9_cv19[c9_i197];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i198 = 0; c9_i198 < 151; c9_i198++) {
    c9_arr[c9_i198] = c9_dv50[c9_i198];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i199 = 0; c9_i199 < 256; c9_i199++) {
    c9_tt[c9_i199] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i200 = 0; c9_i200 < 151; c9_i200++) {
    c9_tt[c9_i200] = c9_arr[c9_i200];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i201 = 0; c9_i201 < 256; c9_i201++) {
    c9_myarr256[c9_i201] = c9_tt[c9_i201];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_t_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[251];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[251];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i202;
  static char_T c9_cv20[251] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=',
    '\"', '5', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '1', '0',
    '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '1', '5', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '0', '\"', ' ', '/', '>', '<', 'f', 'a', 'c', 'e', ' ',
    'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a', 'u',
    '=', '\"', '2', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=',
    '\"', '5', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '1', '0',
    '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '1', '5', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i203;
  static real_T c9_dv51[251] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0,
    115.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0,
    116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0,
    101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 47.0, 62.0, 60.0, 102.0, 97.0,
    99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 50.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 116.0,
    121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 114.0, 101.0, 97.0,
    100.0, 121.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0,
    120.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0,
    50.0, 48.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i204;
  int32_T c9_i205;
  int32_T c9_i206;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_v_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i202 = 0; c9_i202 < 251; c9_i202++) {
    c9_mystr[c9_i202] = c9_cv20[c9_i202];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i203 = 0; c9_i203 < 251; c9_i203++) {
    c9_arr[c9_i203] = c9_dv51[c9_i203];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 251.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 5.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i204 = 0; c9_i204 < 256; c9_i204++) {
    c9_tt[c9_i204] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i205 = 0; c9_i205 < 251; c9_i205++) {
    c9_tt[c9_i205] = c9_arr[c9_i205];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i206 = 0; c9_i206 < 256; c9_i206++) {
    c9_myarr256[c9_i206] = c9_tt[c9_i206];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_u_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[140];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[140];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i207;
  static char_T c9_cv21[140] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '-', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'P', 'O', 'L', 'A', 'R', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-',
    'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '9', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i208;
  static real_T c9_dv52[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 45.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 80.0, 79.0, 76.0, 65.0, 82.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0,
    105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 57.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i209;
  int32_T c9_i210;
  int32_T c9_i211;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_w_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i207 = 0; c9_i207 < 140; c9_i207++) {
    c9_mystr[c9_i207] = c9_cv21[c9_i207];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i208 = 0; c9_i208 < 140; c9_i208++) {
    c9_arr[c9_i208] = c9_dv52[c9_i208];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i209 = 0; c9_i209 < 256; c9_i209++) {
    c9_tt[c9_i209] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i210 = 0; c9_i210 < 140; c9_i210++) {
    c9_tt[c9_i210] = c9_arr[c9_i210];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i211 = 0; c9_i211 < 256; c9_i211++) {
    c9_myarr256[c9_i211] = c9_tt[c9_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_v_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[242];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[242];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i212;
  static char_T c9_cv22[242] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g',
    'l', 'e', '=', '\"', '1', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i213;
  static real_T c9_dv53[242] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 103.0,
    97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0,
    53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0,
    110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0,
    61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i214;
  int32_T c9_i215;
  int32_T c9_i216;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_x_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i212 = 0; c9_i212 < 242; c9_i212++) {
    c9_mystr[c9_i212] = c9_cv22[c9_i212];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i213 = 0; c9_i213 < 242; c9_i213++) {
    c9_arr[c9_i213] = c9_dv53[c9_i213];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 242.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 14.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i214 = 0; c9_i214 < 256; c9_i214++) {
    c9_tt[c9_i214] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i215 = 0; c9_i215 < 242; c9_i215++) {
    c9_tt[c9_i215] = c9_arr[c9_i215];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i216 = 0; c9_i216 < 256; c9_i216++) {
    c9_myarr256[c9_i216] = c9_tt[c9_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_w_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
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
  int32_T c9_i217;
  static char_T c9_cv23[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h',
    'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i218;
  static real_T c9_dv54[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i219;
  int32_T c9_i220;
  int32_T c9_i221;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_y_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i217 = 0; c9_i217 < 142; c9_i217++) {
    c9_mystr[c9_i217] = c9_cv23[c9_i217];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i218 = 0; c9_i218 < 142; c9_i218++) {
    c9_arr[c9_i218] = c9_dv54[c9_i218];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 114.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i219 = 0; c9_i219 < 256; c9_i219++) {
    c9_tt[c9_i219] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i220 = 0; c9_i220 < 142; c9_i220++) {
    c9_tt[c9_i220] = c9_arr[c9_i220];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i221 = 0; c9_i221 < 256; c9_i221++) {
    c9_myarr256[c9_i221] = c9_tt[c9_i221];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_x_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[150];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[150];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i222;
  static char_T c9_cv24[150] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.',
    '7', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i223;
  static real_T c9_dv55[150] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0,
    53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 55.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0,
    34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c9_i224;
  int32_T c9_i225;
  int32_T c9_i226;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_bb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i222 = 0; c9_i222 < 150; c9_i222++) {
    c9_mystr[c9_i222] = c9_cv24[c9_i222];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i223 = 0; c9_i223 < 150; c9_i223++) {
    c9_arr[c9_i223] = c9_dv55[c9_i223];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 150.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i224 = 0; c9_i224 < 256; c9_i224++) {
    c9_tt[c9_i224] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i225 = 0; c9_i225 < 150; c9_i225++) {
    c9_tt[c9_i225] = c9_arr[c9_i225];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i226 = 0; c9_i226 < 256; c9_i226++) {
    c9_myarr256[c9_i226] = c9_tt[c9_i226];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_y_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[149];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[149];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i227;
  static char_T c9_cv25[149] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T',
    'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i228;
  static real_T c9_dv56[149] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 55.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i229;
  int32_T c9_i230;
  int32_T c9_i231;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_cb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i227 = 0; c9_i227 < 149; c9_i227++) {
    c9_mystr[c9_i227] = c9_cv25[c9_i227];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i228 = 0; c9_i228 < 149; c9_i228++) {
    c9_arr[c9_i228] = c9_dv56[c9_i228];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 149.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i229 = 0; c9_i229 < 256; c9_i229++) {
    c9_tt[c9_i229] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i230 = 0; c9_i230 < 149; c9_i230++) {
    c9_tt[c9_i230] = c9_arr[c9_i230];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i231 = 0; c9_i231 < 256; c9_i231++) {
    c9_myarr256[c9_i231] = c9_tt[c9_i231];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ab_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[217];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[217];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i232;
  static char_T c9_cv26[217] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e',
    '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n',
    '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i233;
  static real_T c9_dv57[217] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 97.0,
    110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0,
    75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 55.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0,
    84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0,
    122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 48.0,
    34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0,
    61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i234;
  int32_T c9_i235;
  int32_T c9_i236;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_db_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i232 = 0; c9_i232 < 217; c9_i232++) {
    c9_mystr[c9_i232] = c9_cv26[c9_i232];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i233 = 0; c9_i233 < 217; c9_i233++) {
    c9_arr[c9_i233] = c9_dv57[c9_i233];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 217.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 39.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i234 = 0; c9_i234 < 256; c9_i234++) {
    c9_tt[c9_i234] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i235 = 0; c9_i235 < 217; c9_i235++) {
    c9_tt[c9_i235] = c9_arr[c9_i235];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i236 = 0; c9_i236 < 256; c9_i236++) {
    c9_myarr256[c9_i236] = c9_tt[c9_i236];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_bb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[148];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[148];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i237;
  static char_T c9_cv27[148] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a',
    'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i238;
  static real_T c9_dv58[148] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 55.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i239;
  int32_T c9_i240;
  int32_T c9_i241;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_eb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i237 = 0; c9_i237 < 148; c9_i237++) {
    c9_mystr[c9_i237] = c9_cv27[c9_i237];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i238 = 0; c9_i238 < 148; c9_i238++) {
    c9_arr[c9_i238] = c9_dv58[c9_i238];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i239 = 0; c9_i239 < 256; c9_i239++) {
    c9_tt[c9_i239] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i240 = 0; c9_i240 < 148; c9_i240++) {
    c9_tt[c9_i240] = c9_arr[c9_i240];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i241 = 0; c9_i241 < 256; c9_i241++) {
    c9_myarr256[c9_i241] = c9_tt[c9_i241];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_cb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i242;
  static char_T c9_cv28[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '7', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i243;
  static real_T c9_dv59[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 55.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i244;
  int32_T c9_i245;
  int32_T c9_i246;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_fb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i242 = 0; c9_i242 < 147; c9_i242++) {
    c9_mystr[c9_i242] = c9_cv28[c9_i242];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i243 = 0; c9_i243 < 147; c9_i243++) {
    c9_arr[c9_i243] = c9_dv59[c9_i243];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i244 = 0; c9_i244 < 256; c9_i244++) {
    c9_tt[c9_i244] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i245 = 0; c9_i245 < 147; c9_i245++) {
    c9_tt[c9_i245] = c9_arr[c9_i245];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i246 = 0; c9_i246 < 256; c9_i246++) {
    c9_myarr256[c9_i246] = c9_tt[c9_i246];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_db_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
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
  int32_T c9_i247;
  static char_T c9_cv29[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g',
    'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i248;
  static real_T c9_dv60[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i249;
  int32_T c9_i250;
  int32_T c9_i251;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_gb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i247 = 0; c9_i247 < 94; c9_i247++) {
    c9_mystr[c9_i247] = c9_cv29[c9_i247];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i248 = 0; c9_i248 < 94; c9_i248++) {
    c9_arr[c9_i248] = c9_dv60[c9_i248];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 162.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i249 = 0; c9_i249 < 256; c9_i249++) {
    c9_tt[c9_i249] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i250 = 0; c9_i250 < 94; c9_i250++) {
    c9_tt[c9_i250] = c9_arr[c9_i250];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i251 = 0; c9_i251 < 256; c9_i251++) {
    c9_myarr256[c9_i251] = c9_tt[c9_i251];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_eb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[151];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[151];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i252;
  static char_T c9_cv30[151] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1',
    '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z',
    'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i253;
  static real_T c9_dv61[151] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0,
    49.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0,
    34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c9_i254;
  int32_T c9_i255;
  int32_T c9_i256;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_jb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i252 = 0; c9_i252 < 151; c9_i252++) {
    c9_mystr[c9_i252] = c9_cv30[c9_i252];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i253 = 0; c9_i253 < 151; c9_i253++) {
    c9_arr[c9_i253] = c9_dv61[c9_i253];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i254 = 0; c9_i254 < 256; c9_i254++) {
    c9_tt[c9_i254] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i255 = 0; c9_i255 < 151; c9_i255++) {
    c9_tt[c9_i255] = c9_arr[c9_i255];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i256 = 0; c9_i256 < 256; c9_i256++) {
    c9_myarr256[c9_i256] = c9_tt[c9_i256];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_fb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[152];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[152];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i257;
  static char_T c9_cv31[152] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '1', '.', '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a',
    'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i258;
  static real_T c9_dv62[152] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0,
    34.0, 49.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 46.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i259;
  int32_T c9_i260;
  int32_T c9_i261;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_kb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_bc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_ac_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i257 = 0; c9_i257 < 152; c9_i257++) {
    c9_mystr[c9_i257] = c9_cv31[c9_i257];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i258 = 0; c9_i258 < 152; c9_i258++) {
    c9_arr[c9_i258] = c9_dv62[c9_i258];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 152.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i259 = 0; c9_i259 < 256; c9_i259++) {
    c9_tt[c9_i259] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i260 = 0; c9_i260 < 152; c9_i260++) {
    c9_tt[c9_i260] = c9_arr[c9_i260];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i261 = 0; c9_i261 < 256; c9_i261++) {
    c9_myarr256[c9_i261] = c9_tt[c9_i261];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_gb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i262;
  static char_T c9_cv32[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '2', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i263;
  static real_T c9_dv63[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 50.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i264;
  int32_T c9_i265;
  int32_T c9_i266;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_lb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i262 = 0; c9_i262 < 147; c9_i262++) {
    c9_mystr[c9_i262] = c9_cv32[c9_i262];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i263 = 0; c9_i263 < 147; c9_i263++) {
    c9_arr[c9_i263] = c9_dv63[c9_i263];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i264 = 0; c9_i264 < 256; c9_i264++) {
    c9_tt[c9_i264] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i265 = 0; c9_i265 < 147; c9_i265++) {
    c9_tt[c9_i265] = c9_arr[c9_i265];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i266 = 0; c9_i266 < 256; c9_i266++) {
    c9_myarr256[c9_i266] = c9_tt[c9_i266];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_hb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[148];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[148];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i267;
  static char_T c9_cv33[148] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '2', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a',
    'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i268;
  static real_T c9_dv64[148] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 50.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i269;
  int32_T c9_i270;
  int32_T c9_i271;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_mb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i267 = 0; c9_i267 < 148; c9_i267++) {
    c9_mystr[c9_i267] = c9_cv33[c9_i267];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i268 = 0; c9_i268 < 148; c9_i268++) {
    c9_arr[c9_i268] = c9_dv64[c9_i268];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 148.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i269 = 0; c9_i269 < 256; c9_i269++) {
    c9_tt[c9_i269] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i270 = 0; c9_i270 < 148; c9_i270++) {
    c9_tt[c9_i270] = c9_arr[c9_i270];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i271 = 0; c9_i271 < 256; c9_i271++) {
    c9_myarr256[c9_i271] = c9_tt[c9_i271];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ib_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i272;
  static char_T c9_cv34[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"', '1', '5', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '2', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i273;
  static real_T c9_dv65[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 50.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i274;
  int32_T c9_i275;
  int32_T c9_i276;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_nb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i272 = 0; c9_i272 < 147; c9_i272++) {
    c9_mystr[c9_i272] = c9_cv34[c9_i272];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i273 = 0; c9_i273 < 147; c9_i273++) {
    c9_arr[c9_i273] = c9_dv65[c9_i273];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i274 = 0; c9_i274 < 256; c9_i274++) {
    c9_tt[c9_i274] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i275 = 0; c9_i275 < 147; c9_i275++) {
    c9_tt[c9_i275] = c9_arr[c9_i275];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i276 = 0; c9_i276 < 256; c9_i276++) {
    c9_myarr256[c9_i276] = c9_tt[c9_i276];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_jb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[115];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[115];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i277;
  static char_T c9_cv35[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i278;
  static real_T c9_dv66[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0,
    101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i279;
  int32_T c9_i280;
  int32_T c9_i281;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_qb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_dc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_cc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i277 = 0; c9_i277 < 115; c9_i277++) {
    c9_mystr[c9_i277] = c9_cv35[c9_i277];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i278 = 0; c9_i278 < 115; c9_i278++) {
    c9_arr[c9_i278] = c9_dv66[c9_i278];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 141.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i279 = 0; c9_i279 < 256; c9_i279++) {
    c9_tt[c9_i279] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i280 = 0; c9_i280 < 115; c9_i280++) {
    c9_tt[c9_i280] = c9_arr[c9_i280];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i281 = 0; c9_i281 < 256; c9_i281++) {
    c9_myarr256[c9_i281] = c9_tt[c9_i281];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_kb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[117];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[117];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i282;
  static char_T c9_cv36[117] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i283;
  static real_T c9_dv67[117] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i284;
  int32_T c9_i285;
  int32_T c9_i286;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_rb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i282 = 0; c9_i282 < 117; c9_i282++) {
    c9_mystr[c9_i282] = c9_cv36[c9_i282];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i283 = 0; c9_i283 < 117; c9_i283++) {
    c9_arr[c9_i283] = c9_dv67[c9_i283];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 139.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i284 = 0; c9_i284 < 256; c9_i284++) {
    c9_tt[c9_i284] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i285 = 0; c9_i285 < 117; c9_i285++) {
    c9_tt[c9_i285] = c9_arr[c9_i285];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i286 = 0; c9_i286 < 256; c9_i286++) {
    c9_myarr256[c9_i286] = c9_tt[c9_i286];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_lb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[118];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[118];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i287;
  static char_T c9_cv37[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i288;
  static real_T c9_dv68[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i289;
  int32_T c9_i290;
  int32_T c9_i291;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_sb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_fc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_ec_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i287 = 0; c9_i287 < 118; c9_i287++) {
    c9_mystr[c9_i287] = c9_cv37[c9_i287];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i288 = 0; c9_i288 < 118; c9_i288++) {
    c9_arr[c9_i288] = c9_dv68[c9_i288];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i289 = 0; c9_i289 < 256; c9_i289++) {
    c9_tt[c9_i289] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i290 = 0; c9_i290 < 118; c9_i290++) {
    c9_tt[c9_i290] = c9_arr[c9_i290];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i291 = 0; c9_i291 < 256; c9_i291++) {
    c9_myarr256[c9_i291] = c9_tt[c9_i291];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_mb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[119];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[119];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i292;
  static char_T c9_cv38[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i293;
  static real_T c9_dv69[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i294;
  int32_T c9_i295;
  int32_T c9_i296;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_tb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_hc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_gc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i292 = 0; c9_i292 < 119; c9_i292++) {
    c9_mystr[c9_i292] = c9_cv38[c9_i292];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i293 = 0; c9_i293 < 119; c9_i293++) {
    c9_arr[c9_i293] = c9_dv69[c9_i293];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i294 = 0; c9_i294 < 256; c9_i294++) {
    c9_tt[c9_i294] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i295 = 0; c9_i295 < 119; c9_i295++) {
    c9_tt[c9_i295] = c9_arr[c9_i295];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i296 = 0; c9_i296 < 256; c9_i296++) {
    c9_myarr256[c9_i296] = c9_tt[c9_i296];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_nb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[120];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[120];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i297;
  static char_T c9_cv39[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i298;
  static real_T c9_dv70[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i299;
  int32_T c9_i300;
  int32_T c9_i301;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ub_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i297 = 0; c9_i297 < 120; c9_i297++) {
    c9_mystr[c9_i297] = c9_cv39[c9_i297];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i298 = 0; c9_i298 < 120; c9_i298++) {
    c9_arr[c9_i298] = c9_dv70[c9_i298];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i299 = 0; c9_i299 < 256; c9_i299++) {
    c9_tt[c9_i299] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i300 = 0; c9_i300 < 120; c9_i300++) {
    c9_tt[c9_i300] = c9_arr[c9_i300];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i301 = 0; c9_i301 < 256; c9_i301++) {
    c9_myarr256[c9_i301] = c9_tt[c9_i301];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ob_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[121];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[121];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i302;
  static char_T c9_cv40[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i303;
  static real_T c9_dv71[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i304;
  int32_T c9_i305;
  int32_T c9_i306;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_vb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_jc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_ic_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i302 = 0; c9_i302 < 121; c9_i302++) {
    c9_mystr[c9_i302] = c9_cv40[c9_i302];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i303 = 0; c9_i303 < 121; c9_i303++) {
    c9_arr[c9_i303] = c9_dv71[c9_i303];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 135.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i304 = 0; c9_i304 < 256; c9_i304++) {
    c9_tt[c9_i304] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i305 = 0; c9_i305 < 121; c9_i305++) {
    c9_tt[c9_i305] = c9_arr[c9_i305];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i306 = 0; c9_i306 < 256; c9_i306++) {
    c9_myarr256[c9_i306] = c9_tt[c9_i306];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_pb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[122];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[122];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i307;
  static char_T c9_cv41[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i308;
  static real_T c9_dv72[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i309;
  int32_T c9_i310;
  int32_T c9_i311;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_wb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i307 = 0; c9_i307 < 122; c9_i307++) {
    c9_mystr[c9_i307] = c9_cv41[c9_i307];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i308 = 0; c9_i308 < 122; c9_i308++) {
    c9_arr[c9_i308] = c9_dv72[c9_i308];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 134.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i309 = 0; c9_i309 < 256; c9_i309++) {
    c9_tt[c9_i309] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i310 = 0; c9_i310 < 122; c9_i310++) {
    c9_tt[c9_i310] = c9_arr[c9_i310];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i311 = 0; c9_i311 < 256; c9_i311++) {
    c9_myarr256[c9_i311] = c9_tt[c9_i311];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_qb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[237];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[237];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i312;
  static char_T c9_cv42[237] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2', '\"',
    ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o',
    'k', 'e', '=', '\"', '4', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '8',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '\"', ' ', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 'a',
    'u', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '4', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '3', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '8', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '1', '5', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i313;
  static real_T c9_dv73[237] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0,
    66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 52.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 56.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 32.0, 116.0, 121.0, 112.0, 101.0,
    61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0,
    99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0,
    111.0, 107.0, 101.0, 61.0, 34.0, 52.0, 34.0, 32.0, 115.0, 116.0, 114.0,
    111.0, 107.0, 101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0,
    120.0, 61.0, 34.0, 56.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0,
    53.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0,
    115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i314;
  int32_T c9_i315;
  int32_T c9_i316;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ac_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_nc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_mc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i312 = 0; c9_i312 < 237; c9_i312++) {
    c9_mystr[c9_i312] = c9_cv42[c9_i312];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i313 = 0; c9_i313 < 237; c9_i313++) {
    c9_arr[c9_i313] = c9_dv73[c9_i313];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 237.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 19.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i314 = 0; c9_i314 < 256; c9_i314++) {
    c9_tt[c9_i314] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i315 = 0; c9_i315 < 237; c9_i315++) {
    c9_tt[c9_i315] = c9_arr[c9_i315];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i316 = 0; c9_i316 < 256; c9_i316++) {
    c9_myarr256[c9_i316] = c9_tt[c9_i316];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_rb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
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
  int32_T c9_i317;
  static char_T c9_cv43[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i318;
  static real_T c9_dv74[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0,
    103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 67.0, 72.0, 69.0,
    83.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i319;
  int32_T c9_i320;
  int32_T c9_i321;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_bc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i317 = 0; c9_i317 < 142; c9_i317++) {
    c9_mystr[c9_i317] = c9_cv43[c9_i317];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i318 = 0; c9_i318 < 142; c9_i318++) {
    c9_arr[c9_i318] = c9_dv74[c9_i318];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 114.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i319 = 0; c9_i319 < 256; c9_i319++) {
    c9_tt[c9_i319] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i320 = 0; c9_i320 < 142; c9_i320++) {
    c9_tt[c9_i320] = c9_arr[c9_i320];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i321 = 0; c9_i321 < 256; c9_i321++) {
    c9_myarr256[c9_i321] = c9_tt[c9_i321];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_sb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i322;
  static char_T c9_cv44[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '7', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H',
    'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i323;
  static real_T c9_dv75[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 55.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0,
    65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i324;
  int32_T c9_i325;
  int32_T c9_i326;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ec_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i322 = 0; c9_i322 < 147; c9_i322++) {
    c9_mystr[c9_i322] = c9_cv44[c9_i322];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i323 = 0; c9_i323 < 147; c9_i323++) {
    c9_arr[c9_i323] = c9_dv75[c9_i323];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 147.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i324 = 0; c9_i324 < 256; c9_i324++) {
    c9_tt[c9_i324] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i325 = 0; c9_i325 < 147; c9_i325++) {
    c9_tt[c9_i325] = c9_arr[c9_i325];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i326 = 0; c9_i326 < 256; c9_i326++) {
    c9_myarr256[c9_i326] = c9_tt[c9_i326];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_tb_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[91];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[91];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i327;
  static char_T c9_cv45[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i328;
  static real_T c9_dv76[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i329;
  int32_T c9_i330;
  int32_T c9_i331;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_gc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_rc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_qc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i327 = 0; c9_i327 < 91; c9_i327++) {
    c9_mystr[c9_i327] = c9_cv45[c9_i327];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i328 = 0; c9_i328 < 91; c9_i328++) {
    c9_arr[c9_i328] = c9_dv76[c9_i328];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i329 = 0; c9_i329 < 256; c9_i329++) {
    c9_tt[c9_i329] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i330 = 0; c9_i330 < 91; c9_i330++) {
    c9_tt[c9_i330] = c9_arr[c9_i330];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i331 = 0; c9_i331 < 256; c9_i331++) {
    c9_myarr256[c9_i331] = c9_tt[c9_i331];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c9_countDigits(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  real_T c9_x)
{
  real_T c9_num;
  uint32_T c9_debug_family_var_map[4];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_b_x;
  real_T c9_c_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c9_ic_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_x, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_num, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 2);
  c9_num = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 3);
  if (CV_SCRIPT_IF(1, 0, c9_x < 0.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 4);
    c9_num = 1.0;
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 5);
    c9_b_x = c9_x;
    c9_c_x = c9_b_x;
    c9_x = muDoubleScalarAbs(c9_c_x);
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 7);
  guard1 = false;
  if (CV_SCRIPT_COND(1, 0, c9_x > 0.0)) {
    if (CV_SCRIPT_COND(1, 1, c9_x < 9.0)) {
      CV_SCRIPT_MCDC(1, 0, true);
      CV_SCRIPT_IF(1, 1, true);
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 8);
      c9_num++;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(1, 0, false);
    CV_SCRIPT_IF(1, 1, false);
    _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 9);
    guard2 = false;
    if (CV_SCRIPT_COND(1, 2, c9_x > 10.0)) {
      if (CV_SCRIPT_COND(1, 3, c9_x < 99.0)) {
        CV_SCRIPT_MCDC(1, 1, true);
        CV_SCRIPT_IF(1, 2, true);
        _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 10);
        c9_num += 2.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_SCRIPT_MCDC(1, 1, false);
      CV_SCRIPT_IF(1, 2, false);
      _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 11);
      guard3 = false;
      if (CV_SCRIPT_COND(1, 4, c9_x > 100.0)) {
        if (CV_SCRIPT_COND(1, 5, c9_x < 999.0)) {
          CV_SCRIPT_MCDC(1, 2, true);
          CV_SCRIPT_IF(1, 3, true);
          _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 12);
          c9_num += 3.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_SCRIPT_MCDC(1, 2, false);
        CV_SCRIPT_IF(1, 3, false);
      }
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  return c9_num;
}

static void c9_ub_encStr2Arr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  char_T c9_mystr_data[], int32_T c9_mystr_sizes[2], real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  int32_T c9_arr_sizes;
  real_T c9_arr_data[138];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_loop_ub;
  int32_T c9_i332;
  int32_T c9_i333;
  boolean_T c9_b0;
  boolean_T c9_b1;
  boolean_T c9_b2;
  int32_T c9_i334;
  int32_T c9_tmp_sizes;
  int32_T c9_b_loop_ub;
  int32_T c9_i335;
  int32_T c9_tmp_data[138];
  int32_T c9_iv0[1];
  int32_T c9_c_loop_ub;
  int32_T c9_i336;
  int32_T c9_i337;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_jc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_arr_data, (const int32_T *)
    &c9_arr_sizes, NULL, 0, 1, (void *)c9_uc_sf_marshallOut, (void *)
    c9_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_ss, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_mystr_data, (const int32_T *)
    c9_mystr_sizes, NULL, 1, 7, (void *)c9_sc_sf_marshallOut, (void *)
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_arr_sizes = c9_mystr_sizes[1];
  c9_loop_ub = c9_mystr_sizes[1] - 1;
  for (c9_i332 = 0; c9_i332 <= c9_loop_ub; c9_i332++) {
    c9_arr_data[c9_i332] = (real_T)c9_mystr_data[c9_mystr_sizes[0] * c9_i332];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = (real_T)c9_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = 256.0 - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i333 = 0; c9_i333 < 256; c9_i333++) {
    c9_tt[c9_i333] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_b0 = (1.0 > c9_ss);
  c9_b1 = c9_b0;
  c9_b2 = c9_b1;
  if (c9_b2) {
    c9_i334 = 0;
  } else {
    c9_i334 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c9_ss, 1, 256, 0, 0);
  }

  c9_tmp_sizes = c9_i334;
  c9_b_loop_ub = c9_i334 - 1;
  for (c9_i335 = 0; c9_i335 <= c9_b_loop_ub; c9_i335++) {
    c9_tmp_data[c9_i335] = c9_i335;
  }

  c9_iv0[0] = c9_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c9_iv0, 1, *(int32_T (*)[1])&c9_arr_sizes, 1);
  c9_c_loop_ub = c9_arr_sizes - 1;
  for (c9_i336 = 0; c9_i336 <= c9_c_loop_ub; c9_i336++) {
    c9_tt[c9_tmp_data[c9_i336]] = c9_arr_data[c9_i336];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i337 = 0; c9_i337 < 256; c9_i337++) {
    c9_myarr256[c9_i337] = c9_tt[c9_i337];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c9_rand(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c9_uv2[625];
  int32_T c9_i338;
  real_T c9_d3;
  if (!chartInstance->c9_method_not_empty) {
    chartInstance->c9_method = 7U;
    chartInstance->c9_method_not_empty = true;
  }

  if (!chartInstance->c9_c_state_not_empty) {
    c9_eml_rand_mt19937ar(chartInstance, c9_uv2);
    for (c9_i338 = 0; c9_i338 < 625; c9_i338++) {
      chartInstance->c9_c_state[c9_i338] = c9_uv2[c9_i338];
    }

    chartInstance->c9_c_state_not_empty = true;
  }

  c9_d3 = c9_c_eml_rand_mt19937ar(chartInstance, chartInstance->c9_c_state);
  return c9_d3;
}

static void c9_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625])
{
  real_T c9_d4;
  int32_T c9_i339;
  c9_d4 = 5489.0;
  for (c9_i339 = 0; c9_i339 < 625; c9_i339++) {
    c9_d_state[c9_i339] = 0U;
  }

  c9_b_twister_state_vector(chartInstance, c9_d_state, c9_d4);
}

static void c9_twister_state_vector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_mt[625], real_T c9_seed, uint32_T c9_b_mt[625])
{
  int32_T c9_i340;
  for (c9_i340 = 0; c9_i340 < 625; c9_i340++) {
    c9_b_mt[c9_i340] = c9_mt[c9_i340];
  }

  c9_b_twister_state_vector(chartInstance, c9_b_mt, c9_seed);
}

static void c9_b_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625], uint32_T c9_e_state[625], real_T
  *c9_r)
{
  int32_T c9_i341;
  for (c9_i341 = 0; c9_i341 < 625; c9_i341++) {
    c9_e_state[c9_i341] = c9_d_state[c9_i341];
  }

  *c9_r = c9_c_eml_rand_mt19937ar(chartInstance, c9_e_state);
}

static void c9_eml_error(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  int32_T c9_i342;
  static char_T c9_cv46[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c9_u[37];
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  for (c9_i342 = 0; c9_i342 < 37; c9_i342++) {
    c9_u[c9_i342] = c9_cv46[c9_i342];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c9_y));
}

static real_T c9_log(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T
                     c9_x)
{
  real_T c9_b_x;
  c9_b_x = c9_x;
  c9_b_log(chartInstance, &c9_b_x);
  return c9_b_x;
}

static void c9_b_eml_error(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  int32_T c9_i343;
  static char_T c9_cv47[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c9_u[30];
  const mxArray *c9_y = NULL;
  int32_T c9_i344;
  static char_T c9_cv48[3] = { 'l', 'o', 'g' };

  char_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  (void)chartInstance;
  for (c9_i343 = 0; c9_i343 < 30; c9_i343++) {
    c9_u[c9_i343] = c9_cv47[c9_i343];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c9_i344 = 0; c9_i344 < 3; c9_i344++) {
    c9_b_u[c9_i344] = c9_cv48[c9_i344];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c9_y, 14, c9_b_y));
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\countDigits.m"));
}

static void c9_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_sprintf, const char_T *c9_identifier, char_T
  c9_y_data[], int32_T c9_y_sizes[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_sprintf), &c9_thisId,
                        c9_y_data, c9_y_sizes);
  sf_mex_destroy(&c9_sprintf);
}

static void c9_b_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2])
{
  int32_T c9_i345;
  uint32_T c9_uv3[2];
  int32_T c9_i346;
  static boolean_T c9_bv0[2] = { false, true };

  boolean_T c9_bv1[2];
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[138];
  int32_T c9_y;
  int32_T c9_b_y;
  int32_T c9_loop_ub;
  int32_T c9_i347;
  (void)chartInstance;
  for (c9_i345 = 0; c9_i345 < 2; c9_i345++) {
    c9_uv3[c9_i345] = 1U + 137U * (uint32_T)c9_i345;
  }

  for (c9_i346 = 0; c9_i346 < 2; c9_i346++) {
    c9_bv1[c9_i346] = c9_bv0[c9_i346];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 0, 10, 0U, 1, 0U,
                   2, c9_bv1, c9_uv3, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = c9_tmp_sizes[1];
  c9_y = c9_y_sizes[0];
  c9_b_y = c9_y_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i347 = 0; c9_i347 <= c9_loop_ub; c9_i347++) {
    c9_y_data[c9_i347] = c9_tmp_data[c9_i347];
  }

  sf_mex_destroy(&c9_u);
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_h, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_h), &c9_thisId);
  sf_mex_destroy(&c9_h);
  return c9_y;
}

static real_T c9_d_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d5;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d5, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d5;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_h;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_h = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_h), &c9_thisId);
  sf_mex_destroy(&c9_h);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i348;
  real_T c9_b_inData[256];
  int32_T c9_i349;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i348 = 0; c9_i348 < 256; c9_i348++) {
    c9_b_inData[c9_i348] = (*(real_T (*)[256])c9_inData)[c9_i348];
  }

  for (c9_i349 = 0; c9_i349 < 256; c9_i349++) {
    c9_u[c9_i349] = c9_b_inData[c9_i349];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_gazeBML, const char_T *c9_identifier, real_T
  c9_y[256])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_gazeBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_gazeBML);
}

static void c9_f_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv77[256];
  int32_T c9_i350;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv77, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c9_i350 = 0; c9_i350 < 256; c9_i350++) {
    c9_y[c9_i350] = c9_dv77[c9_i350];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_gazeBML;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[256];
  int32_T c9_i351;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_gazeBML = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_gazeBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_gazeBML);
  for (c9_i351 = 0; c9_i351 < 256; c9_i351++) {
    (*(real_T (*)[256])c9_outData)[c9_i351] = c9_y[c9_i351];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_g_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b3;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b3, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b3;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_aVarTruthTableCondition_23;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_aVarTruthTableCondition_23 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_aVarTruthTableCondition_23), &c9_thisId);
  sf_mex_destroy(&c9_aVarTruthTableCondition_23);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i352;
  real_T c9_b_inData[256];
  int32_T c9_i353;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i352 = 0; c9_i352 < 256; c9_i352++) {
    c9_b_inData[c9_i352] = (*(real_T (*)[256])c9_inData)[c9_i352];
  }

  for (c9_i353 = 0; c9_i353 < 256; c9_i353++) {
    c9_u[c9_i353] = c9_b_inData[c9_i353];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_h_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_myarr256, const char_T *c9_identifier,
  real_T c9_y[256])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
}

static void c9_i_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[256])
{
  real_T c9_dv78[256];
  int32_T c9_i354;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv78, 1, 0, 0U, 1, 0U, 1, 256);
  for (c9_i354 = 0; c9_i354 < 256; c9_i354++) {
    c9_y[c9_i354] = c9_dv78[c9_i354];
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
  int32_T c9_i355;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_myarr256 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
  for (c9_i355 = 0; c9_i355 < 256; c9_i355++) {
    (*(real_T (*)[256])c9_outData)[c9_i355] = c9_y[c9_i355];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i356;
  char_T c9_b_inData[122];
  int32_T c9_i357;
  char_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i356 = 0; c9_i356 < 122; c9_i356++) {
    c9_b_inData[c9_i356] = (*(char_T (*)[122])c9_inData)[c9_i356];
  }

  for (c9_i357 = 0; c9_i357 < 122; c9_i357++) {
    c9_u[c9_i357] = c9_b_inData[c9_i357];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i358;
  real_T c9_b_inData[122];
  int32_T c9_i359;
  real_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i358 = 0; c9_i358 < 122; c9_i358++) {
    c9_b_inData[c9_i358] = (*(real_T (*)[122])c9_inData)[c9_i358];
  }

  for (c9_i359 = 0; c9_i359 < 122; c9_i359++) {
    c9_u[c9_i359] = c9_b_inData[c9_i359];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i360;
  char_T c9_b_inData[123];
  int32_T c9_i361;
  char_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i360 = 0; c9_i360 < 123; c9_i360++) {
    c9_b_inData[c9_i360] = (*(char_T (*)[123])c9_inData)[c9_i360];
  }

  for (c9_i361 = 0; c9_i361 < 123; c9_i361++) {
    c9_u[c9_i361] = c9_b_inData[c9_i361];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i362;
  real_T c9_b_inData[123];
  int32_T c9_i363;
  real_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i362 = 0; c9_i362 < 123; c9_i362++) {
    c9_b_inData[c9_i362] = (*(real_T (*)[123])c9_inData)[c9_i362];
  }

  for (c9_i363 = 0; c9_i363 < 123; c9_i363++) {
    c9_u[c9_i363] = c9_b_inData[c9_i363];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i364;
  char_T c9_b_inData[120];
  int32_T c9_i365;
  char_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i364 = 0; c9_i364 < 120; c9_i364++) {
    c9_b_inData[c9_i364] = (*(char_T (*)[120])c9_inData)[c9_i364];
  }

  for (c9_i365 = 0; c9_i365 < 120; c9_i365++) {
    c9_u[c9_i365] = c9_b_inData[c9_i365];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i366;
  real_T c9_b_inData[120];
  int32_T c9_i367;
  real_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i366 = 0; c9_i366 < 120; c9_i366++) {
    c9_b_inData[c9_i366] = (*(real_T (*)[120])c9_inData)[c9_i366];
  }

  for (c9_i367 = 0; c9_i367 < 120; c9_i367++) {
    c9_u[c9_i367] = c9_b_inData[c9_i367];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i368;
  char_T c9_b_inData[124];
  int32_T c9_i369;
  char_T c9_u[124];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i368 = 0; c9_i368 < 124; c9_i368++) {
    c9_b_inData[c9_i368] = (*(char_T (*)[124])c9_inData)[c9_i368];
  }

  for (c9_i369 = 0; c9_i369 < 124; c9_i369++) {
    c9_u[c9_i369] = c9_b_inData[c9_i369];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 124),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i370;
  real_T c9_b_inData[124];
  int32_T c9_i371;
  real_T c9_u[124];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i370 = 0; c9_i370 < 124; c9_i370++) {
    c9_b_inData[c9_i370] = (*(real_T (*)[124])c9_inData)[c9_i370];
  }

  for (c9_i371 = 0; c9_i371 < 124; c9_i371++) {
    c9_u[c9_i371] = c9_b_inData[c9_i371];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 124), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i372;
  char_T c9_b_inData[125];
  int32_T c9_i373;
  char_T c9_u[125];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i372 = 0; c9_i372 < 125; c9_i372++) {
    c9_b_inData[c9_i372] = (*(char_T (*)[125])c9_inData)[c9_i372];
  }

  for (c9_i373 = 0; c9_i373 < 125; c9_i373++) {
    c9_u[c9_i373] = c9_b_inData[c9_i373];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 125),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i374;
  real_T c9_b_inData[125];
  int32_T c9_i375;
  real_T c9_u[125];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i374 = 0; c9_i374 < 125; c9_i374++) {
    c9_b_inData[c9_i374] = (*(real_T (*)[125])c9_inData)[c9_i374];
  }

  for (c9_i375 = 0; c9_i375 < 125; c9_i375++) {
    c9_u[c9_i375] = c9_b_inData[c9_i375];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 125), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i376;
  char_T c9_b_inData[126];
  int32_T c9_i377;
  char_T c9_u[126];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i376 = 0; c9_i376 < 126; c9_i376++) {
    c9_b_inData[c9_i376] = (*(char_T (*)[126])c9_inData)[c9_i376];
  }

  for (c9_i377 = 0; c9_i377 < 126; c9_i377++) {
    c9_u[c9_i377] = c9_b_inData[c9_i377];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 126),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i378;
  real_T c9_b_inData[126];
  int32_T c9_i379;
  real_T c9_u[126];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i378 = 0; c9_i378 < 126; c9_i378++) {
    c9_b_inData[c9_i378] = (*(real_T (*)[126])c9_inData)[c9_i378];
  }

  for (c9_i379 = 0; c9_i379 < 126; c9_i379++) {
    c9_u[c9_i379] = c9_b_inData[c9_i379];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 126), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i380;
  char_T c9_b_inData[127];
  int32_T c9_i381;
  char_T c9_u[127];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i380 = 0; c9_i380 < 127; c9_i380++) {
    c9_b_inData[c9_i380] = (*(char_T (*)[127])c9_inData)[c9_i380];
  }

  for (c9_i381 = 0; c9_i381 < 127; c9_i381++) {
    c9_u[c9_i381] = c9_b_inData[c9_i381];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 127),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i382;
  real_T c9_b_inData[127];
  int32_T c9_i383;
  real_T c9_u[127];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i382 = 0; c9_i382 < 127; c9_i382++) {
    c9_b_inData[c9_i382] = (*(real_T (*)[127])c9_inData)[c9_i382];
  }

  for (c9_i383 = 0; c9_i383 < 127; c9_i383++) {
    c9_u[c9_i383] = c9_b_inData[c9_i383];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 127), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i384;
  char_T c9_b_inData[149];
  int32_T c9_i385;
  char_T c9_u[149];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i384 = 0; c9_i384 < 149; c9_i384++) {
    c9_b_inData[c9_i384] = (*(char_T (*)[149])c9_inData)[c9_i384];
  }

  for (c9_i385 = 0; c9_i385 < 149; c9_i385++) {
    c9_u[c9_i385] = c9_b_inData[c9_i385];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 149),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i386;
  real_T c9_b_inData[149];
  int32_T c9_i387;
  real_T c9_u[149];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i386 = 0; c9_i386 < 149; c9_i386++) {
    c9_b_inData[c9_i386] = (*(real_T (*)[149])c9_inData)[c9_i386];
  }

  for (c9_i387 = 0; c9_i387 < 149; c9_i387++) {
    c9_u[c9_i387] = c9_b_inData[c9_i387];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 149), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i388;
  char_T c9_b_inData[150];
  int32_T c9_i389;
  char_T c9_u[150];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i388 = 0; c9_i388 < 150; c9_i388++) {
    c9_b_inData[c9_i388] = (*(char_T (*)[150])c9_inData)[c9_i388];
  }

  for (c9_i389 = 0; c9_i389 < 150; c9_i389++) {
    c9_u[c9_i389] = c9_b_inData[c9_i389];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 150),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i390;
  real_T c9_b_inData[150];
  int32_T c9_i391;
  real_T c9_u[150];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i390 = 0; c9_i390 < 150; c9_i390++) {
    c9_b_inData[c9_i390] = (*(real_T (*)[150])c9_inData)[c9_i390];
  }

  for (c9_i391 = 0; c9_i391 < 150; c9_i391++) {
    c9_u[c9_i391] = c9_b_inData[c9_i391];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 150), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i392;
  char_T c9_b_inData[145];
  int32_T c9_i393;
  char_T c9_u[145];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i392 = 0; c9_i392 < 145; c9_i392++) {
    c9_b_inData[c9_i392] = (*(char_T (*)[145])c9_inData)[c9_i392];
  }

  for (c9_i393 = 0; c9_i393 < 145; c9_i393++) {
    c9_u[c9_i393] = c9_b_inData[c9_i393];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 145),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i394;
  real_T c9_b_inData[145];
  int32_T c9_i395;
  real_T c9_u[145];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i394 = 0; c9_i394 < 145; c9_i394++) {
    c9_b_inData[c9_i394] = (*(real_T (*)[145])c9_inData)[c9_i394];
  }

  for (c9_i395 = 0; c9_i395 < 145; c9_i395++) {
    c9_u[c9_i395] = c9_b_inData[c9_i395];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 145), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i396;
  char_T c9_b_inData[148];
  int32_T c9_i397;
  char_T c9_u[148];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i396 = 0; c9_i396 < 148; c9_i396++) {
    c9_b_inData[c9_i396] = (*(char_T (*)[148])c9_inData)[c9_i396];
  }

  for (c9_i397 = 0; c9_i397 < 148; c9_i397++) {
    c9_u[c9_i397] = c9_b_inData[c9_i397];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 148),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i398;
  real_T c9_b_inData[148];
  int32_T c9_i399;
  real_T c9_u[148];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i398 = 0; c9_i398 < 148; c9_i398++) {
    c9_b_inData[c9_i398] = (*(real_T (*)[148])c9_inData)[c9_i398];
  }

  for (c9_i399 = 0; c9_i399 < 148; c9_i399++) {
    c9_u[c9_i399] = c9_b_inData[c9_i399];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 148), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i400;
  char_T c9_b_inData[147];
  int32_T c9_i401;
  char_T c9_u[147];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i400 = 0; c9_i400 < 147; c9_i400++) {
    c9_b_inData[c9_i400] = (*(char_T (*)[147])c9_inData)[c9_i400];
  }

  for (c9_i401 = 0; c9_i401 < 147; c9_i401++) {
    c9_u[c9_i401] = c9_b_inData[c9_i401];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i402;
  real_T c9_b_inData[147];
  int32_T c9_i403;
  real_T c9_u[147];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i402 = 0; c9_i402 < 147; c9_i402++) {
    c9_b_inData[c9_i402] = (*(real_T (*)[147])c9_inData)[c9_i402];
  }

  for (c9_i403 = 0; c9_i403 < 147; c9_i403++) {
    c9_u[c9_i403] = c9_b_inData[c9_i403];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i404;
  char_T c9_b_inData[215];
  int32_T c9_i405;
  char_T c9_u[215];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i404 = 0; c9_i404 < 215; c9_i404++) {
    c9_b_inData[c9_i404] = (*(char_T (*)[215])c9_inData)[c9_i404];
  }

  for (c9_i405 = 0; c9_i405 < 215; c9_i405++) {
    c9_u[c9_i405] = c9_b_inData[c9_i405];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 215),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i406;
  real_T c9_b_inData[215];
  int32_T c9_i407;
  real_T c9_u[215];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i406 = 0; c9_i406 < 215; c9_i406++) {
    c9_b_inData[c9_i406] = (*(real_T (*)[215])c9_inData)[c9_i406];
  }

  for (c9_i407 = 0; c9_i407 < 215; c9_i407++) {
    c9_u[c9_i407] = c9_b_inData[c9_i407];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 215), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i408;
  char_T c9_b_inData[146];
  int32_T c9_i409;
  char_T c9_u[146];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i408 = 0; c9_i408 < 146; c9_i408++) {
    c9_b_inData[c9_i408] = (*(char_T (*)[146])c9_inData)[c9_i408];
  }

  for (c9_i409 = 0; c9_i409 < 146; c9_i409++) {
    c9_u[c9_i409] = c9_b_inData[c9_i409];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 146),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i410;
  real_T c9_b_inData[146];
  int32_T c9_i411;
  real_T c9_u[146];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i410 = 0; c9_i410 < 146; c9_i410++) {
    c9_b_inData[c9_i410] = (*(real_T (*)[146])c9_inData)[c9_i410];
  }

  for (c9_i411 = 0; c9_i411 < 146; c9_i411++) {
    c9_u[c9_i411] = c9_b_inData[c9_i411];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 146), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i412;
  char_T c9_b_inData[117];
  int32_T c9_i413;
  char_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i412 = 0; c9_i412 < 117; c9_i412++) {
    c9_b_inData[c9_i412] = (*(char_T (*)[117])c9_inData)[c9_i412];
  }

  for (c9_i413 = 0; c9_i413 < 117; c9_i413++) {
    c9_u[c9_i413] = c9_b_inData[c9_i413];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 117),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i414;
  real_T c9_b_inData[117];
  int32_T c9_i415;
  real_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i414 = 0; c9_i414 < 117; c9_i414++) {
    c9_b_inData[c9_i414] = (*(real_T (*)[117])c9_inData)[c9_i414];
  }

  for (c9_i415 = 0; c9_i415 < 117; c9_i415++) {
    c9_u[c9_i415] = c9_b_inData[c9_i415];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 117), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i416;
  char_T c9_b_inData[242];
  int32_T c9_i417;
  char_T c9_u[242];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i416 = 0; c9_i416 < 242; c9_i416++) {
    c9_b_inData[c9_i416] = (*(char_T (*)[242])c9_inData)[c9_i416];
  }

  for (c9_i417 = 0; c9_i417 < 242; c9_i417++) {
    c9_u[c9_i417] = c9_b_inData[c9_i417];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 242),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i418;
  real_T c9_b_inData[242];
  int32_T c9_i419;
  real_T c9_u[242];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i418 = 0; c9_i418 < 242; c9_i418++) {
    c9_b_inData[c9_i418] = (*(real_T (*)[242])c9_inData)[c9_i418];
  }

  for (c9_i419 = 0; c9_i419 < 242; c9_i419++) {
    c9_u[c9_i419] = c9_b_inData[c9_i419];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 242), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i420;
  char_T c9_b_inData[151];
  int32_T c9_i421;
  char_T c9_u[151];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i420 = 0; c9_i420 < 151; c9_i420++) {
    c9_b_inData[c9_i420] = (*(char_T (*)[151])c9_inData)[c9_i420];
  }

  for (c9_i421 = 0; c9_i421 < 151; c9_i421++) {
    c9_u[c9_i421] = c9_b_inData[c9_i421];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 151),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i422;
  real_T c9_b_inData[151];
  int32_T c9_i423;
  real_T c9_u[151];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i422 = 0; c9_i422 < 151; c9_i422++) {
    c9_b_inData[c9_i422] = (*(real_T (*)[151])c9_inData)[c9_i422];
  }

  for (c9_i423 = 0; c9_i423 < 151; c9_i423++) {
    c9_u[c9_i423] = c9_b_inData[c9_i423];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 151), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i424;
  char_T c9_b_inData[251];
  int32_T c9_i425;
  char_T c9_u[251];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i424 = 0; c9_i424 < 251; c9_i424++) {
    c9_b_inData[c9_i424] = (*(char_T (*)[251])c9_inData)[c9_i424];
  }

  for (c9_i425 = 0; c9_i425 < 251; c9_i425++) {
    c9_u[c9_i425] = c9_b_inData[c9_i425];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 251),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i426;
  real_T c9_b_inData[251];
  int32_T c9_i427;
  real_T c9_u[251];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i426 = 0; c9_i426 < 251; c9_i426++) {
    c9_b_inData[c9_i426] = (*(real_T (*)[251])c9_inData)[c9_i426];
  }

  for (c9_i427 = 0; c9_i427 < 251; c9_i427++) {
    c9_u[c9_i427] = c9_b_inData[c9_i427];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 251), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i428;
  char_T c9_b_inData[140];
  int32_T c9_i429;
  char_T c9_u[140];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i428 = 0; c9_i428 < 140; c9_i428++) {
    c9_b_inData[c9_i428] = (*(char_T (*)[140])c9_inData)[c9_i428];
  }

  for (c9_i429 = 0; c9_i429 < 140; c9_i429++) {
    c9_u[c9_i429] = c9_b_inData[c9_i429];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i430;
  real_T c9_b_inData[140];
  int32_T c9_i431;
  real_T c9_u[140];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i430 = 0; c9_i430 < 140; c9_i430++) {
    c9_b_inData[c9_i430] = (*(real_T (*)[140])c9_inData)[c9_i430];
  }

  for (c9_i431 = 0; c9_i431 < 140; c9_i431++) {
    c9_u[c9_i431] = c9_b_inData[c9_i431];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i432;
  char_T c9_b_inData[142];
  int32_T c9_i433;
  char_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i432 = 0; c9_i432 < 142; c9_i432++) {
    c9_b_inData[c9_i432] = (*(char_T (*)[142])c9_inData)[c9_i432];
  }

  for (c9_i433 = 0; c9_i433 < 142; c9_i433++) {
    c9_u[c9_i433] = c9_b_inData[c9_i433];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i434;
  real_T c9_b_inData[142];
  int32_T c9_i435;
  real_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i434 = 0; c9_i434 < 142; c9_i434++) {
    c9_b_inData[c9_i434] = (*(real_T (*)[142])c9_inData)[c9_i434];
  }

  for (c9_i435 = 0; c9_i435 < 142; c9_i435++) {
    c9_u[c9_i435] = c9_b_inData[c9_i435];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i436;
  char_T c9_b_inData[217];
  int32_T c9_i437;
  char_T c9_u[217];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i436 = 0; c9_i436 < 217; c9_i436++) {
    c9_b_inData[c9_i436] = (*(char_T (*)[217])c9_inData)[c9_i436];
  }

  for (c9_i437 = 0; c9_i437 < 217; c9_i437++) {
    c9_u[c9_i437] = c9_b_inData[c9_i437];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 217),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i438;
  real_T c9_b_inData[217];
  int32_T c9_i439;
  real_T c9_u[217];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i438 = 0; c9_i438 < 217; c9_i438++) {
    c9_b_inData[c9_i438] = (*(real_T (*)[217])c9_inData)[c9_i438];
  }

  for (c9_i439 = 0; c9_i439 < 217; c9_i439++) {
    c9_u[c9_i439] = c9_b_inData[c9_i439];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 217), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i440;
  char_T c9_b_inData[94];
  int32_T c9_i441;
  char_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i440 = 0; c9_i440 < 94; c9_i440++) {
    c9_b_inData[c9_i440] = (*(char_T (*)[94])c9_inData)[c9_i440];
  }

  for (c9_i441 = 0; c9_i441 < 94; c9_i441++) {
    c9_u[c9_i441] = c9_b_inData[c9_i441];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i442;
  real_T c9_b_inData[94];
  int32_T c9_i443;
  real_T c9_u[94];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i442 = 0; c9_i442 < 94; c9_i442++) {
    c9_b_inData[c9_i442] = (*(real_T (*)[94])c9_inData)[c9_i442];
  }

  for (c9_i443 = 0; c9_i443 < 94; c9_i443++) {
    c9_u[c9_i443] = c9_b_inData[c9_i443];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i444;
  char_T c9_b_inData[144];
  int32_T c9_i445;
  char_T c9_u[144];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i444 = 0; c9_i444 < 144; c9_i444++) {
    c9_b_inData[c9_i444] = (*(char_T (*)[144])c9_inData)[c9_i444];
  }

  for (c9_i445 = 0; c9_i445 < 144; c9_i445++) {
    c9_u[c9_i445] = c9_b_inData[c9_i445];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 144),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i446;
  real_T c9_b_inData[144];
  int32_T c9_i447;
  real_T c9_u[144];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i446 = 0; c9_i446 < 144; c9_i446++) {
    c9_b_inData[c9_i446] = (*(real_T (*)[144])c9_inData)[c9_i446];
  }

  for (c9_i447 = 0; c9_i447 < 144; c9_i447++) {
    c9_u[c9_i447] = c9_b_inData[c9_i447];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 144), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i448;
  char_T c9_b_inData[152];
  int32_T c9_i449;
  char_T c9_u[152];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i448 = 0; c9_i448 < 152; c9_i448++) {
    c9_b_inData[c9_i448] = (*(char_T (*)[152])c9_inData)[c9_i448];
  }

  for (c9_i449 = 0; c9_i449 < 152; c9_i449++) {
    c9_u[c9_i449] = c9_b_inData[c9_i449];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 152),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i450;
  real_T c9_b_inData[152];
  int32_T c9_i451;
  real_T c9_u[152];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i450 = 0; c9_i450 < 152; c9_i450++) {
    c9_b_inData[c9_i450] = (*(real_T (*)[152])c9_inData)[c9_i450];
  }

  for (c9_i451 = 0; c9_i451 < 152; c9_i451++) {
    c9_u[c9_i451] = c9_b_inData[c9_i451];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 152), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i452;
  char_T c9_b_inData[115];
  int32_T c9_i453;
  char_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i452 = 0; c9_i452 < 115; c9_i452++) {
    c9_b_inData[c9_i452] = (*(char_T (*)[115])c9_inData)[c9_i452];
  }

  for (c9_i453 = 0; c9_i453 < 115; c9_i453++) {
    c9_u[c9_i453] = c9_b_inData[c9_i453];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i454;
  real_T c9_b_inData[115];
  int32_T c9_i455;
  real_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i454 = 0; c9_i454 < 115; c9_i454++) {
    c9_b_inData[c9_i454] = (*(real_T (*)[115])c9_inData)[c9_i454];
  }

  for (c9_i455 = 0; c9_i455 < 115; c9_i455++) {
    c9_u[c9_i455] = c9_b_inData[c9_i455];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i456;
  char_T c9_b_inData[118];
  int32_T c9_i457;
  char_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i456 = 0; c9_i456 < 118; c9_i456++) {
    c9_b_inData[c9_i456] = (*(char_T (*)[118])c9_inData)[c9_i456];
  }

  for (c9_i457 = 0; c9_i457 < 118; c9_i457++) {
    c9_u[c9_i457] = c9_b_inData[c9_i457];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i458;
  real_T c9_b_inData[118];
  int32_T c9_i459;
  real_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i458 = 0; c9_i458 < 118; c9_i458++) {
    c9_b_inData[c9_i458] = (*(real_T (*)[118])c9_inData)[c9_i458];
  }

  for (c9_i459 = 0; c9_i459 < 118; c9_i459++) {
    c9_u[c9_i459] = c9_b_inData[c9_i459];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i460;
  char_T c9_b_inData[119];
  int32_T c9_i461;
  char_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i460 = 0; c9_i460 < 119; c9_i460++) {
    c9_b_inData[c9_i460] = (*(char_T (*)[119])c9_inData)[c9_i460];
  }

  for (c9_i461 = 0; c9_i461 < 119; c9_i461++) {
    c9_u[c9_i461] = c9_b_inData[c9_i461];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i462;
  real_T c9_b_inData[119];
  int32_T c9_i463;
  real_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i462 = 0; c9_i462 < 119; c9_i462++) {
    c9_b_inData[c9_i462] = (*(real_T (*)[119])c9_inData)[c9_i462];
  }

  for (c9_i463 = 0; c9_i463 < 119; c9_i463++) {
    c9_u[c9_i463] = c9_b_inData[c9_i463];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i464;
  char_T c9_b_inData[121];
  int32_T c9_i465;
  char_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i464 = 0; c9_i464 < 121; c9_i464++) {
    c9_b_inData[c9_i464] = (*(char_T (*)[121])c9_inData)[c9_i464];
  }

  for (c9_i465 = 0; c9_i465 < 121; c9_i465++) {
    c9_u[c9_i465] = c9_b_inData[c9_i465];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i466;
  real_T c9_b_inData[121];
  int32_T c9_i467;
  real_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i466 = 0; c9_i466 < 121; c9_i466++) {
    c9_b_inData[c9_i466] = (*(real_T (*)[121])c9_inData)[c9_i466];
  }

  for (c9_i467 = 0; c9_i467 < 121; c9_i467++) {
    c9_u[c9_i467] = c9_b_inData[c9_i467];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i468;
  char_T c9_b_inData[139];
  int32_T c9_i469;
  char_T c9_u[139];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i468 = 0; c9_i468 < 139; c9_i468++) {
    c9_b_inData[c9_i468] = (*(char_T (*)[139])c9_inData)[c9_i468];
  }

  for (c9_i469 = 0; c9_i469 < 139; c9_i469++) {
    c9_u[c9_i469] = c9_b_inData[c9_i469];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i470;
  real_T c9_b_inData[139];
  int32_T c9_i471;
  real_T c9_u[139];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i470 = 0; c9_i470 < 139; c9_i470++) {
    c9_b_inData[c9_i470] = (*(real_T (*)[139])c9_inData)[c9_i470];
  }

  for (c9_i471 = 0; c9_i471 < 139; c9_i471++) {
    c9_u[c9_i471] = c9_b_inData[c9_i471];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i472;
  char_T c9_b_inData[237];
  int32_T c9_i473;
  char_T c9_u[237];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i472 = 0; c9_i472 < 237; c9_i472++) {
    c9_b_inData[c9_i472] = (*(char_T (*)[237])c9_inData)[c9_i472];
  }

  for (c9_i473 = 0; c9_i473 < 237; c9_i473++) {
    c9_u[c9_i473] = c9_b_inData[c9_i473];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 237),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i474;
  real_T c9_b_inData[237];
  int32_T c9_i475;
  real_T c9_u[237];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i474 = 0; c9_i474 < 237; c9_i474++) {
    c9_b_inData[c9_i474] = (*(real_T (*)[237])c9_inData)[c9_i474];
  }

  for (c9_i475 = 0; c9_i475 < 237; c9_i475++) {
    c9_u[c9_i475] = c9_b_inData[c9_i475];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 237), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i476;
  char_T c9_b_inData[185];
  int32_T c9_i477;
  char_T c9_u[185];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i476 = 0; c9_i476 < 185; c9_i476++) {
    c9_b_inData[c9_i476] = (*(char_T (*)[185])c9_inData)[c9_i476];
  }

  for (c9_i477 = 0; c9_i477 < 185; c9_i477++) {
    c9_u[c9_i477] = c9_b_inData[c9_i477];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 185),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i478;
  real_T c9_b_inData[185];
  int32_T c9_i479;
  real_T c9_u[185];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i478 = 0; c9_i478 < 185; c9_i478++) {
    c9_b_inData[c9_i478] = (*(real_T (*)[185])c9_inData)[c9_i478];
  }

  for (c9_i479 = 0; c9_i479 < 185; c9_i479++) {
    c9_u[c9_i479] = c9_b_inData[c9_i479];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 185), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i480;
  char_T c9_b_inData[91];
  int32_T c9_i481;
  char_T c9_u[91];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i480 = 0; c9_i480 < 91; c9_i480++) {
    c9_b_inData[c9_i480] = (*(char_T (*)[91])c9_inData)[c9_i480];
  }

  for (c9_i481 = 0; c9_i481 < 91; c9_i481++) {
    c9_u[c9_i481] = c9_b_inData[c9_i481];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i482;
  real_T c9_b_inData[91];
  int32_T c9_i483;
  real_T c9_u[91];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i482 = 0; c9_i482 < 91; c9_i482++) {
    c9_b_inData[c9_i482] = (*(real_T (*)[91])c9_inData)[c9_i482];
  }

  for (c9_i483 = 0; c9_i483 < 91; c9_i483++) {
    c9_u[c9_i483] = c9_b_inData[c9_i483];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_sc_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2])
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_inData_sizes[2];
  int32_T c9_loop_ub;
  int32_T c9_i484;
  char_T c9_b_inData_data[138];
  int32_T c9_u_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_i485;
  char_T c9_u_data[138];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_inData_sizes[0] = 1;
  c9_b_inData_sizes[1] = c9_inData_sizes[1];
  c9_loop_ub = c9_inData_sizes[1] - 1;
  for (c9_i484 = 0; c9_i484 <= c9_loop_ub; c9_i484++) {
    c9_b_inData_data[c9_b_inData_sizes[0] * c9_i484] =
      c9_inData_data[c9_inData_sizes[0] * c9_i484];
  }

  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = c9_b_inData_sizes[1];
  c9_b_loop_ub = c9_b_inData_sizes[1] - 1;
  for (c9_i485 = 0; c9_i485 <= c9_b_loop_ub; c9_i485++) {
    c9_u_data[c9_u_sizes[0] * c9_i485] = c9_b_inData_data[c9_b_inData_sizes[0] *
      c9_i485];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u_data, 10, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_j_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2])
{
  int32_T c9_i486;
  uint32_T c9_uv4[2];
  int32_T c9_i487;
  static boolean_T c9_bv2[2] = { false, true };

  boolean_T c9_bv3[2];
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[138];
  int32_T c9_y;
  int32_T c9_b_y;
  int32_T c9_loop_ub;
  int32_T c9_i488;
  (void)chartInstance;
  for (c9_i486 = 0; c9_i486 < 2; c9_i486++) {
    c9_uv4[c9_i486] = 1U + 137U * (uint32_T)c9_i486;
  }

  for (c9_i487 = 0; c9_i487 < 2; c9_i487++) {
    c9_bv3[c9_i487] = c9_bv2[c9_i487];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c9_bv3, c9_uv4, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = c9_tmp_sizes[1];
  c9_y = c9_y_sizes[0];
  c9_b_y = c9_y_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i488 = 0; c9_i488 <= c9_loop_ub; c9_i488++) {
    c9_y_data[c9_i488] = c9_tmp_data[c9_i488];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2])
{
  const mxArray *c9_mystr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y_sizes[2];
  char_T c9_y_data[138];
  int32_T c9_loop_ub;
  int32_T c9_i489;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mystr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_mystr), &c9_thisId,
                        c9_y_data, c9_y_sizes);
  sf_mex_destroy(&c9_mystr);
  c9_outData_sizes[0] = 1;
  c9_outData_sizes[1] = c9_y_sizes[1];
  c9_loop_ub = c9_y_sizes[1] - 1;
  for (c9_i489 = 0; c9_i489 <= c9_loop_ub; c9_i489++) {
    c9_outData_data[c9_outData_sizes[0] * c9_i489] = c9_y_data[c9_y_sizes[0] *
      c9_i489];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_tc_sf_marshallOut(void *chartInstanceVoid, char_T
  c9_inData_data[], int32_T c9_inData_sizes[2])
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_inData_sizes[2];
  int32_T c9_loop_ub;
  int32_T c9_i490;
  char_T c9_b_inData_data[9];
  int32_T c9_u_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_i491;
  char_T c9_u_data[9];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_inData_sizes[0] = 1;
  c9_b_inData_sizes[1] = c9_inData_sizes[1];
  c9_loop_ub = c9_inData_sizes[1] - 1;
  for (c9_i490 = 0; c9_i490 <= c9_loop_ub; c9_i490++) {
    c9_b_inData_data[c9_b_inData_sizes[0] * c9_i490] =
      c9_inData_data[c9_inData_sizes[0] * c9_i490];
  }

  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = c9_b_inData_sizes[1];
  c9_b_loop_ub = c9_b_inData_sizes[1] - 1;
  for (c9_i491 = 0; c9_i491 <= c9_b_loop_ub; c9_i491++) {
    c9_u_data[c9_u_sizes[0] * c9_i491] = c9_b_inData_data[c9_b_inData_sizes[0] *
      c9_i491];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u_data, 10, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_k_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y_data[], int32_T c9_y_sizes[2])
{
  int32_T c9_i492;
  uint32_T c9_uv5[2];
  int32_T c9_i493;
  static boolean_T c9_bv4[2] = { false, true };

  boolean_T c9_bv5[2];
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[9];
  int32_T c9_y;
  int32_T c9_b_y;
  int32_T c9_loop_ub;
  int32_T c9_i494;
  (void)chartInstance;
  for (c9_i492 = 0; c9_i492 < 2; c9_i492++) {
    c9_uv5[c9_i492] = 1U + ((uint32_T)c9_i492 << 3);
  }

  for (c9_i493 = 0; c9_i493 < 2; c9_i493++) {
    c9_bv5[c9_i493] = c9_bv4[c9_i493];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 10, 0U, 1, 0U,
                   2, c9_bv5, c9_uv5, c9_tmp_sizes);
  c9_y_sizes[0] = 1;
  c9_y_sizes[1] = c9_tmp_sizes[1];
  c9_y = c9_y_sizes[0];
  c9_b_y = c9_y_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i494 = 0; c9_i494 <= c9_loop_ub; c9_i494++) {
    c9_y_data[c9_i494] = c9_tmp_data[c9_i494];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, char_T c9_outData_data[], int32_T
  c9_outData_sizes[2])
{
  const mxArray *c9_dirG;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y_sizes[2];
  char_T c9_y_data[9];
  int32_T c9_loop_ub;
  int32_T c9_i495;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_dirG = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_dirG), &c9_thisId,
                        c9_y_data, c9_y_sizes);
  sf_mex_destroy(&c9_dirG);
  c9_outData_sizes[0] = 1;
  c9_outData_sizes[1] = c9_y_sizes[1];
  c9_loop_ub = c9_y_sizes[1] - 1;
  for (c9_i495 = 0; c9_i495 <= c9_loop_ub; c9_i495++) {
    c9_outData_data[c9_outData_sizes[0] * c9_i495] = c9_y_data[c9_y_sizes[0] *
      c9_i495];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_uc_sf_marshallOut(void *chartInstanceVoid, real_T
  c9_inData_data[], int32_T *c9_inData_sizes)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_b_inData_sizes;
  int32_T c9_loop_ub;
  int32_T c9_i496;
  real_T c9_b_inData_data[138];
  int32_T c9_u_sizes;
  int32_T c9_b_loop_ub;
  int32_T c9_i497;
  real_T c9_u_data[138];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_b_inData_sizes = *c9_inData_sizes;
  c9_loop_ub = *c9_inData_sizes - 1;
  for (c9_i496 = 0; c9_i496 <= c9_loop_ub; c9_i496++) {
    c9_b_inData_data[c9_i496] = c9_inData_data[c9_i496];
  }

  c9_u_sizes = c9_b_inData_sizes;
  c9_b_loop_ub = c9_b_inData_sizes - 1;
  for (c9_i497 = 0; c9_i497 <= c9_b_loop_ub; c9_i497++) {
    c9_u_data[c9_i497] = c9_b_inData_data[c9_i497];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u_data, 0, 0U, 1U, 0U, 1,
    c9_u_sizes), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_l_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y_data[], int32_T *c9_y_sizes)
{
  static uint32_T c9_uv6[1] = { 138U };

  uint32_T c9_uv7[1];
  static boolean_T c9_bv6[1] = { true };

  boolean_T c9_bv7[1];
  int32_T c9_tmp_sizes;
  real_T c9_tmp_data[138];
  int32_T c9_loop_ub;
  int32_T c9_i498;
  (void)chartInstance;
  c9_uv7[0] = c9_uv6[0];
  c9_bv7[0] = c9_bv6[0];
  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_u), c9_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c9_bv7, c9_uv7, &c9_tmp_sizes);
  *c9_y_sizes = c9_tmp_sizes;
  c9_loop_ub = c9_tmp_sizes - 1;
  for (c9_i498 = 0; c9_i498 <= c9_loop_ub; c9_i498++) {
    c9_y_data[c9_i498] = c9_tmp_data[c9_i498];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, real_T c9_outData_data[], int32_T
  *c9_outData_sizes)
{
  const mxArray *c9_arr;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y_sizes;
  real_T c9_y_data[138];
  int32_T c9_loop_ub;
  int32_T c9_i499;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_arr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_arr), &c9_thisId, c9_y_data,
                        &c9_y_sizes);
  sf_mex_destroy(&c9_arr);
  *c9_outData_sizes = c9_y_sizes;
  c9_loop_ub = c9_y_sizes - 1;
  for (c9_i499 = 0; c9_i499 <= c9_loop_ub; c9_i499++) {
    c9_outData_data[c9_i499] = c9_y_data[c9_i499];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i500;
  int32_T c9_i501;
  int32_T c9_i502;
  real_T c9_b_inData[1280];
  int32_T c9_i503;
  int32_T c9_i504;
  int32_T c9_i505;
  real_T c9_u[1280];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i500 = 0;
  for (c9_i501 = 0; c9_i501 < 5; c9_i501++) {
    for (c9_i502 = 0; c9_i502 < 256; c9_i502++) {
      c9_b_inData[c9_i502 + c9_i500] = (*(real_T (*)[1280])c9_inData)[c9_i502 +
        c9_i500];
    }

    c9_i500 += 256;
  }

  c9_i503 = 0;
  for (c9_i504 = 0; c9_i504 < 5; c9_i504++) {
    for (c9_i505 = 0; c9_i505 < 256; c9_i505++) {
      c9_u[c9_i505 + c9_i503] = c9_b_inData[c9_i505 + c9_i503];
    }

    c9_i503 += 256;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 256, 5), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_m_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_newBmls, const char_T *c9_identifier, real_T
  c9_y[1280])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_newBmls), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_newBmls);
}

static void c9_n_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[1280])
{
  real_T c9_dv79[1280];
  int32_T c9_i506;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv79, 1, 0, 0U, 1, 0U, 2, 256,
                5);
  for (c9_i506 = 0; c9_i506 < 1280; c9_i506++) {
    c9_y[c9_i506] = c9_dv79[c9_i506];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_newBmls;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[1280];
  int32_T c9_i507;
  int32_T c9_i508;
  int32_T c9_i509;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_newBmls = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_newBmls), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_newBmls);
  c9_i507 = 0;
  for (c9_i508 = 0; c9_i508 < 5; c9_i508++) {
    for (c9_i509 = 0; c9_i509 < 256; c9_i509++) {
      (*(real_T (*)[1280])c9_outData)[c9_i509 + c9_i507] = c9_y[c9_i509 +
        c9_i507];
    }

    c9_i507 += 256;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  char_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(char_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_Demo_EP_IdleRand_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 60, 1),
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
  const mxArray *c9_rhs39 = NULL;
  const mxArray *c9_lhs39 = NULL;
  const mxArray *c9_rhs40 = NULL;
  const mxArray *c9_lhs40 = NULL;
  const mxArray *c9_rhs41 = NULL;
  const mxArray *c9_lhs41 = NULL;
  const mxArray *c9_rhs42 = NULL;
  const mxArray *c9_lhs42 = NULL;
  const mxArray *c9_rhs43 = NULL;
  const mxArray *c9_lhs43 = NULL;
  const mxArray *c9_rhs44 = NULL;
  const mxArray *c9_lhs44 = NULL;
  const mxArray *c9_rhs45 = NULL;
  const mxArray *c9_lhs45 = NULL;
  const mxArray *c9_rhs46 = NULL;
  const mxArray *c9_lhs46 = NULL;
  const mxArray *c9_rhs47 = NULL;
  const mxArray *c9_lhs47 = NULL;
  const mxArray *c9_rhs48 = NULL;
  const mxArray *c9_lhs48 = NULL;
  const mxArray *c9_rhs49 = NULL;
  const mxArray *c9_lhs49 = NULL;
  const mxArray *c9_rhs50 = NULL;
  const mxArray *c9_lhs50 = NULL;
  const mxArray *c9_rhs51 = NULL;
  const mxArray *c9_lhs51 = NULL;
  const mxArray *c9_rhs52 = NULL;
  const mxArray *c9_lhs52 = NULL;
  const mxArray *c9_rhs53 = NULL;
  const mxArray *c9_lhs53 = NULL;
  const mxArray *c9_rhs54 = NULL;
  const mxArray *c9_lhs54 = NULL;
  const mxArray *c9_rhs55 = NULL;
  const mxArray *c9_lhs55 = NULL;
  const mxArray *c9_rhs56 = NULL;
  const mxArray *c9_lhs56 = NULL;
  const mxArray *c9_rhs57 = NULL;
  const mxArray *c9_lhs57 = NULL;
  const mxArray *c9_rhs58 = NULL;
  const mxArray *c9_lhs58 = NULL;
  const mxArray *c9_rhs59 = NULL;
  const mxArray *c9_lhs59 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("disp"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("countDigits"), "name", "name",
                  2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/countDigits.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1408487908U), "fileTimeLo",
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
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/countDigits.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("blanks"), "name", "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isequal"), "name", "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isnan"), "name", "name", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("floor"), "name", "name", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("randi"), "name", "name", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rand"), "name", "name", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand"), "name", "name", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eps"), "name", "name", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_eps"), "name", "name", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("isequal"), "name", "name", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_error"), "name", "name",
                  38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("floor"), "name", "name", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c9_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("polyval"), "name", "name", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1305350402U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c9_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c9_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c9_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c9_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c9_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("rdivide"), "name", "name", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c9_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c9_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c9_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_div"), "name", "name", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c9_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c9_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("log"), "name", "name", 50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862780U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c9_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_error"), "name", "name",
                  51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c9_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_log"), "name",
                  "name", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c9_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("realmax"), "name", "name", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c9_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_realmax"), "name", "name",
                  54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c9_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c9_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("mrdivide"), "name", "name", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c9_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("round"), "name", "name", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c9_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c9_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c9_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs59), "lhs", "lhs",
                  59);
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
  sf_mex_destroy(&c9_rhs39);
  sf_mex_destroy(&c9_lhs39);
  sf_mex_destroy(&c9_rhs40);
  sf_mex_destroy(&c9_lhs40);
  sf_mex_destroy(&c9_rhs41);
  sf_mex_destroy(&c9_lhs41);
  sf_mex_destroy(&c9_rhs42);
  sf_mex_destroy(&c9_lhs42);
  sf_mex_destroy(&c9_rhs43);
  sf_mex_destroy(&c9_lhs43);
  sf_mex_destroy(&c9_rhs44);
  sf_mex_destroy(&c9_lhs44);
  sf_mex_destroy(&c9_rhs45);
  sf_mex_destroy(&c9_lhs45);
  sf_mex_destroy(&c9_rhs46);
  sf_mex_destroy(&c9_lhs46);
  sf_mex_destroy(&c9_rhs47);
  sf_mex_destroy(&c9_lhs47);
  sf_mex_destroy(&c9_rhs48);
  sf_mex_destroy(&c9_lhs48);
  sf_mex_destroy(&c9_rhs49);
  sf_mex_destroy(&c9_lhs49);
  sf_mex_destroy(&c9_rhs50);
  sf_mex_destroy(&c9_lhs50);
  sf_mex_destroy(&c9_rhs51);
  sf_mex_destroy(&c9_lhs51);
  sf_mex_destroy(&c9_rhs52);
  sf_mex_destroy(&c9_lhs52);
  sf_mex_destroy(&c9_rhs53);
  sf_mex_destroy(&c9_lhs53);
  sf_mex_destroy(&c9_rhs54);
  sf_mex_destroy(&c9_lhs54);
  sf_mex_destroy(&c9_rhs55);
  sf_mex_destroy(&c9_lhs55);
  sf_mex_destroy(&c9_rhs56);
  sf_mex_destroy(&c9_lhs56);
  sf_mex_destroy(&c9_rhs57);
  sf_mex_destroy(&c9_lhs57);
  sf_mex_destroy(&c9_rhs58);
  sf_mex_destroy(&c9_lhs58);
  sf_mex_destroy(&c9_rhs59);
  sf_mex_destroy(&c9_lhs59);
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

static void c9_activate_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = c9_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_deactivate_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_increment_counters_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  if (chartInstance->c9_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c9_temporalCounter_i1++;
  }

  if (chartInstance->c9_temporalCounter_i2 < 3U) {
    chartInstance->c9_temporalCounter_i2 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i2 + 1);
  }

  if (chartInstance->c9_temporalCounter_i3 < 63U) {
    chartInstance->c9_temporalCounter_i3 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i3 + 1);
  }
}

static void c9_reset_counters_secsc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c9_Demo_EP_IdleRand_secs(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_activate_secsc9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c9_Demo_EP_IdleRand_secs
  (SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_increment_counters_secsc9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c9_Demo_EP_IdleRand_secs(SimStruct
  *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_reset_counters_secsc9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_deactivate_c9_Demo_EP_IdleRand_secs(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_deactivate_secsc9_Demo_EP_IdleRand(chartInstance);
}

boolean_T sf_exported_auto_isStablec9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  return chartInstance->c9_isStable;
}

void sf_exported_auto_duringc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_c9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_enterc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_enter_atomic_c9_Demo_EP_IdleRand(chartInstance);
  c9_enter_internal_c9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_exitc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_exit_internal_c9_Demo_EP_IdleRand(chartInstance);
}

void sf_exported_auto_gatewayc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  chartInstance->c9_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_initc9_Demo_EP_IdleRand(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec9_Demo_EP_IdleRand(SimStruct *c9_S)
{
  const mxArray *c9_out = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_out = NULL;
  sf_mex_assign(&c9_out, sf_internal_get_sim_state_c9_Demo_EP_IdleRand(c9_S),
                false);
  return c9_out;
}

void sf_exported_auto_setSimstatec9_Demo_EP_IdleRand(SimStruct *c9_S, const
  mxArray *c9_in)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c9_Demo_EP_IdleRand(c9_S, sf_mex_dup(c9_in));
  sf_mex_destroy(&c9_in);
}

void sf_exported_auto_check_state_inconsistency_c9_Demo_EP_IdleRand(SimStruct
  *c9_S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_EP_IdleRandMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_setPersonalityFactorc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_p, real_T *c9_m,
   real_T *c9_a, real_T *c9_h)
{
  uint32_T c9_debug_family_var_map[6];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 3.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_m, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_a, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_h, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(8, 0);
  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 9);
  if (CV_EML_IF(8, 1, 0, c9_p == 1.0)) {
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 10);
    *c9_m = 0.125;
    c9_updateDataWrittenToVector(chartInstance, 23U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 11);
    *c9_a = 0.05;
    c9_updateDataWrittenToVector(chartInstance, 24U);
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 12);
    *c9_h = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 25U);
  } else {
    _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 13);
    if (CV_EML_IF(8, 1, 1, c9_p == 2.0)) {
      _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 14);
      *c9_m = 0.05;
      c9_updateDataWrittenToVector(chartInstance, 23U);
      _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 15);
      *c9_a = 0.125;
      c9_updateDataWrittenToVector(chartInstance, 24U);
      _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 16);
      *c9_h = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 25U);
    } else {
      _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 17);
      if (CV_EML_IF(8, 1, 2, c9_p == 3.0)) {
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 18);
        *c9_m = 0.25;
        c9_updateDataWrittenToVector(chartInstance, 23U);
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 19);
        *c9_a = 0.125;
        c9_updateDataWrittenToVector(chartInstance, 24U);
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 20);
        *c9_h = 4.0;
        c9_updateDataWrittenToVector(chartInstance, 25U);
      } else {
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 22);
        *c9_m = 0.125;
        c9_updateDataWrittenToVector(chartInstance, 23U);
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 23);
        *c9_a = 0.25;
        c9_updateDataWrittenToVector(chartInstance, 24U);
        _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, 24);
        *c9_h = 4.0;
        c9_updateDataWrittenToVector(chartInstance, 25U);
      }
    }
  }

  _SFD_EML_CALL(8U, chartInstance->c9_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[28];
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
  boolean_T c9_aVarTruthTableCondition_19;
  boolean_T c9_aVarTruthTableCondition_20;
  boolean_T c9_aVarTruthTableCondition_21;
  boolean_T c9_aVarTruthTableCondition_22;
  boolean_T c9_aVarTruthTableCondition_23;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv80[256];
  int32_T c9_i510;
  int32_T c9_i511;
  int32_T c9_i512;
  int32_T c9_i513;
  int32_T c9_i514;
  int32_T c9_i515;
  int32_T c9_i516;
  int32_T c9_i517;
  int32_T c9_i518;
  int32_T c9_i519;
  int32_T c9_i520;
  int32_T c9_i521;
  int32_T c9_i522;
  int32_T c9_i523;
  int32_T c9_i524;
  int32_T c9_i525;
  int32_T c9_i526;
  int32_T c9_i527;
  int32_T c9_i528;
  int32_T c9_i529;
  int32_T c9_i530;
  int32_T c9_i531;
  int32_T c9_i532;
  int32_T c9_i533;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 28U, c9_b_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_19, 18U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_20, 19U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_21, 20U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_22, 21U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_23, 22U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 23U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 24U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 25U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 26U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 27U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 16);
  c9_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 17);
  c9_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 21);
  c9_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 22);
  c9_aVarTruthTableCondition_20 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 23);
  c9_aVarTruthTableCondition_21 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_22 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 25);
  c9_aVarTruthTableCondition_23 = false;
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 29);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 32);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 35);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 38);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 41);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 44);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 47);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 50);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 53);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 56);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 59);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 62);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 65);
  c9_aVarTruthTableCondition_13 = (c9_bmlID == 13.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 68);
  c9_aVarTruthTableCondition_14 = (c9_bmlID == 14.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 71);
  c9_aVarTruthTableCondition_15 = (c9_bmlID == 15.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 74);
  c9_aVarTruthTableCondition_16 = (c9_bmlID == 16.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 78);
  c9_aVarTruthTableCondition_17 = (c9_bmlID == 17.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 82);
  c9_aVarTruthTableCondition_18 = (c9_bmlID == 18.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 86);
  c9_aVarTruthTableCondition_19 = (c9_bmlID == 19.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 90);
  c9_aVarTruthTableCondition_20 = (c9_bmlID == 20.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 94);
  c9_aVarTruthTableCondition_21 = (c9_bmlID == 21.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 98);
  c9_aVarTruthTableCondition_22 = (c9_bmlID == 22.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 102);
  c9_aVarTruthTableCondition_23 = (c9_bmlID == 23.0);
  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 104);
  if (CV_EML_IF(4, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 105);
    CV_EML_FCN(4, 1);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 158U);
    c9_encStr2Arr(chartInstance, c9_dv80);
    for (c9_i510 = 0; c9_i510 < 256; c9_i510++) {
      c9_gazeBML[c9_i510] = c9_dv80[c9_i510];
    }

    c9_updateDataWrittenToVector(chartInstance, 27U);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 158U);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 26U);
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -158);
  } else {
    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 106);
    if (CV_EML_IF(4, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 107);
      CV_EML_FCN(4, 2);
      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 164U);
      c9_b_encStr2Arr(chartInstance, c9_dv80);
      for (c9_i511 = 0; c9_i511 < 256; c9_i511++) {
        c9_gazeBML[c9_i511] = c9_dv80[c9_i511];
      }

      c9_updateDataWrittenToVector(chartInstance, 27U);
      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 164U);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 26U);
      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -164);
    } else {
      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 108);
      if (CV_EML_IF(4, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 109);
        CV_EML_FCN(4, 3);
        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 170U);
        c9_c_encStr2Arr(chartInstance, c9_dv80);
        for (c9_i512 = 0; c9_i512 < 256; c9_i512++) {
          c9_gazeBML[c9_i512] = c9_dv80[c9_i512];
        }

        c9_updateDataWrittenToVector(chartInstance, 27U);
        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 170U);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 26U);
        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -170);
      } else {
        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 110);
        if (CV_EML_IF(4, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 111);
          CV_EML_FCN(4, 4);
          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 176U);
          c9_d_encStr2Arr(chartInstance, c9_dv80);
          for (c9_i513 = 0; c9_i513 < 256; c9_i513++) {
            c9_gazeBML[c9_i513] = c9_dv80[c9_i513];
          }

          c9_updateDataWrittenToVector(chartInstance, 27U);
          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 176U);
          *c9_p = 3.0;
          c9_updateDataWrittenToVector(chartInstance, 26U);
          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -176);
        } else {
          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 112);
          if (CV_EML_IF(4, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 113);
            CV_EML_FCN(4, 5);
            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 182U);
            c9_e_encStr2Arr(chartInstance, c9_dv80);
            for (c9_i514 = 0; c9_i514 < 256; c9_i514++) {
              c9_gazeBML[c9_i514] = c9_dv80[c9_i514];
            }

            c9_updateDataWrittenToVector(chartInstance, 27U);
            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 182U);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 26U);
            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -182);
          } else {
            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 114);
            if (CV_EML_IF(4, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 115);
              CV_EML_FCN(4, 6);
              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 188U);
              c9_f_encStr2Arr(chartInstance, c9_dv80);
              for (c9_i515 = 0; c9_i515 < 256; c9_i515++) {
                c9_gazeBML[c9_i515] = c9_dv80[c9_i515];
              }

              c9_updateDataWrittenToVector(chartInstance, 27U);
              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 188U);
              *c9_p = 3.0;
              c9_updateDataWrittenToVector(chartInstance, 26U);
              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -188);
            } else {
              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 116);
              if (CV_EML_IF(4, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 117);
                CV_EML_FCN(4, 7);
                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 194U);
                c9_g_encStr2Arr(chartInstance, c9_dv80);
                for (c9_i516 = 0; c9_i516 < 256; c9_i516++) {
                  c9_gazeBML[c9_i516] = c9_dv80[c9_i516];
                }

                c9_updateDataWrittenToVector(chartInstance, 27U);
                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 194U);
                *c9_p = 3.0;
                c9_updateDataWrittenToVector(chartInstance, 26U);
                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -194);
              } else {
                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 118);
                if (CV_EML_IF(4, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 119);
                  CV_EML_FCN(4, 8);
                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 200U);
                  c9_h_encStr2Arr(chartInstance, c9_dv80);
                  for (c9_i517 = 0; c9_i517 < 256; c9_i517++) {
                    c9_gazeBML[c9_i517] = c9_dv80[c9_i517];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 27U);
                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 200U);
                  *c9_p = 3.0;
                  c9_updateDataWrittenToVector(chartInstance, 26U);
                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -200);
                } else {
                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 120);
                  if (CV_EML_IF(4, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 121);
                    CV_EML_FCN(4, 9);
                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 206U);
                    c9_i_encStr2Arr(chartInstance, c9_dv80);
                    for (c9_i518 = 0; c9_i518 < 256; c9_i518++) {
                      c9_gazeBML[c9_i518] = c9_dv80[c9_i518];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 27U);
                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 206U);
                    *c9_p = 3.0;
                    c9_updateDataWrittenToVector(chartInstance, 26U);
                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -206);
                  } else {
                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 122);
                    if (CV_EML_IF(4, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 123);
                      CV_EML_FCN(4, 10);
                      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 212U);
                      c9_j_encStr2Arr(chartInstance, c9_dv80);
                      for (c9_i519 = 0; c9_i519 < 256; c9_i519++) {
                        c9_gazeBML[c9_i519] = c9_dv80[c9_i519];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 27U);
                      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 212U);
                      *c9_p = 3.0;
                      c9_updateDataWrittenToVector(chartInstance, 26U);
                      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -212);
                    } else {
                      _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 124);
                      if (CV_EML_IF(4, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 125);
                        CV_EML_FCN(4, 11);
                        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 218U);
                        c9_k_encStr2Arr(chartInstance, c9_dv80);
                        for (c9_i520 = 0; c9_i520 < 256; c9_i520++) {
                          c9_gazeBML[c9_i520] = c9_dv80[c9_i520];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 27U);
                        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 218U);
                        *c9_p = 3.0;
                        c9_updateDataWrittenToVector(chartInstance, 26U);
                        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -218);
                      } else {
                        _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 126);
                        if (CV_EML_IF(4, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                        MAX_int8_T);
                          CV_EML_FCN(4, 12);
                          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 224U);
                          c9_l_encStr2Arr(chartInstance, c9_dv80);
                          for (c9_i521 = 0; c9_i521 < 256; c9_i521++) {
                            c9_gazeBML[c9_i521] = c9_dv80[c9_i521];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 27U);
                          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 224U);
                          *c9_p = 3.0;
                          c9_updateDataWrittenToVector(chartInstance, 26U);
                          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -224);
                        } else {
                          _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 128U);
                          if (CV_EML_IF(4, 1, 12, c9_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 129U);
                            CV_EML_FCN(4, 13);
                            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 230U);
                            c9_m_encStr2Arr(chartInstance, c9_dv80);
                            for (c9_i522 = 0; c9_i522 < 256; c9_i522++) {
                              c9_gazeBML[c9_i522] = c9_dv80[c9_i522];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 27U);
                            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 230U);
                            *c9_p = 3.0;
                            c9_updateDataWrittenToVector(chartInstance, 26U);
                            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -230);
                          } else {
                            _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 130U);
                            if (CV_EML_IF(4, 1, 13,
                                          c9_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 131U);
                              CV_EML_FCN(4, 14);
                              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 236U);
                              c9_n_encStr2Arr(chartInstance, c9_dv80);
                              for (c9_i523 = 0; c9_i523 < 256; c9_i523++) {
                                c9_gazeBML[c9_i523] = c9_dv80[c9_i523];
                              }

                              c9_updateDataWrittenToVector(chartInstance, 27U);
                              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 236U);
                              *c9_p = 3.0;
                              c9_updateDataWrittenToVector(chartInstance, 26U);
                              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -236);
                            } else {
                              _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, 132U);
                              if (CV_EML_IF(4, 1, 14,
                                            c9_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                              133U);
                                CV_EML_FCN(4, 15);
                                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                              242U);
                                c9_o_encStr2Arr(chartInstance, c9_dv80);
                                for (c9_i524 = 0; c9_i524 < 256; c9_i524++) {
                                  c9_gazeBML[c9_i524] = c9_dv80[c9_i524];
                                }

                                c9_updateDataWrittenToVector(chartInstance, 27U);
                                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                              242U);
                                *c9_p = 3.0;
                                c9_updateDataWrittenToVector(chartInstance, 26U);
                                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                              -242);
                              } else {
                                _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                              134U);
                                if (CV_EML_IF(4, 1, 15,
                                              c9_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                135U);
                                  CV_EML_FCN(4, 16);
                                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                248U);
                                  c9_p_encStr2Arr(chartInstance, c9_dv80);
                                  for (c9_i525 = 0; c9_i525 < 256; c9_i525++) {
                                    c9_gazeBML[c9_i525] = c9_dv80[c9_i525];
                                  }

                                  c9_updateDataWrittenToVector(chartInstance,
                                    27U);
                                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                248U);
                                  *c9_p = 3.0;
                                  c9_updateDataWrittenToVector(chartInstance,
                                    26U);
                                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                -248);
                                } else {
                                  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                136U);
                                  if (CV_EML_IF(4, 1, 16,
                                                c9_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                  137U);
                                    CV_EML_FCN(4, 17);
                                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                  254U);
                                    c9_q_encStr2Arr(chartInstance, c9_dv80);
                                    for (c9_i526 = 0; c9_i526 < 256; c9_i526++)
                                    {
                                      c9_gazeBML[c9_i526] = c9_dv80[c9_i526];
                                    }

                                    c9_updateDataWrittenToVector(chartInstance,
                                      27U);
                                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                  254U);
                                    *c9_p = 3.0;
                                    c9_updateDataWrittenToVector(chartInstance,
                                      26U);
                                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                  -254);
                                  } else {
                                    _SFD_EML_CALL(4U, chartInstance->c9_sfEvent,
                                                  138U);
                                    if (CV_EML_IF(4, 1, 17,
                                                  c9_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(4U,
                                                    chartInstance->c9_sfEvent,
                                                    139U);
                                      CV_EML_FCN(4, 18);
                                      _SFD_EML_CALL(4U,
                                                    chartInstance->c9_sfEvent,
                                                    260);
                                      c9_r_encStr2Arr(chartInstance, c9_dv80);
                                      for (c9_i527 = 0; c9_i527 < 256; c9_i527++)
                                      {
                                        c9_gazeBML[c9_i527] = c9_dv80[c9_i527];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        27U);
                                      _SFD_EML_CALL(4U,
                                                    chartInstance->c9_sfEvent,
                                                    260);
                                      *c9_p = 3.0;
                                      c9_updateDataWrittenToVector(chartInstance,
                                        26U);
                                      _SFD_EML_CALL(4U,
                                                    chartInstance->c9_sfEvent,
                                                    -260);
                                    } else {
                                      _SFD_EML_CALL(4U,
                                                    chartInstance->c9_sfEvent,
                                                    140U);
                                      if (CV_EML_IF(4, 1, 18,
                                                    c9_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(4U,
                                                      chartInstance->c9_sfEvent,
                                                      141U);
                                        CV_EML_FCN(4, 19);
                                        _SFD_EML_CALL(4U,
                                                      chartInstance->c9_sfEvent,
                                                      266);
                                        c9_s_encStr2Arr(chartInstance, c9_dv80);
                                        for (c9_i528 = 0; c9_i528 < 256; c9_i528
                                             ++) {
                                          c9_gazeBML[c9_i528] = c9_dv80[c9_i528];
                                        }

                                        c9_updateDataWrittenToVector
                                          (chartInstance, 27U);
                                        _SFD_EML_CALL(4U,
                                                      chartInstance->c9_sfEvent,
                                                      266);
                                        *c9_p = 3.0;
                                        c9_updateDataWrittenToVector
                                          (chartInstance, 26U);
                                        _SFD_EML_CALL(4U,
                                                      chartInstance->c9_sfEvent,
                                                      -266);
                                      } else {
                                        _SFD_EML_CALL(4U,
                                                      chartInstance->c9_sfEvent,
                                                      142U);
                                        if (CV_EML_IF(4, 1, 19,
                                                      c9_aVarTruthTableCondition_20))
                                        {
                                          _SFD_EML_CALL(4U,
                                                        chartInstance->c9_sfEvent,
                                                        143U);
                                          CV_EML_FCN(4, 20);
                                          _SFD_EML_CALL(4U,
                                                        chartInstance->c9_sfEvent,
                                                        272);
                                          c9_t_encStr2Arr(chartInstance, c9_dv80);
                                          for (c9_i529 = 0; c9_i529 < 256;
                                               c9_i529++) {
                                            c9_gazeBML[c9_i529] =
                                              c9_dv80[c9_i529];
                                          }

                                          c9_updateDataWrittenToVector
                                            (chartInstance, 27U);
                                          _SFD_EML_CALL(4U,
                                                        chartInstance->c9_sfEvent,
                                                        272);
                                          *c9_p = 3.0;
                                          c9_updateDataWrittenToVector
                                            (chartInstance, 26U);
                                          _SFD_EML_CALL(4U,
                                                        chartInstance->c9_sfEvent,
                                                        -272);
                                        } else {
                                          _SFD_EML_CALL(4U,
                                                        chartInstance->c9_sfEvent,
                                                        144U);
                                          if (CV_EML_IF(4, 1, 20,
                                                        c9_aVarTruthTableCondition_21))
                                          {
                                            _SFD_EML_CALL(4U,
                                                          chartInstance->c9_sfEvent,
                                                          145U);
                                            CV_EML_FCN(4, 21);
                                            _SFD_EML_CALL(4U,
                                                          chartInstance->c9_sfEvent,
                                                          278);
                                            c9_u_encStr2Arr(chartInstance,
                                                            c9_dv80);
                                            for (c9_i530 = 0; c9_i530 < 256;
                                                 c9_i530++) {
                                              c9_gazeBML[c9_i530] =
                                                c9_dv80[c9_i530];
                                            }

                                            c9_updateDataWrittenToVector
                                              (chartInstance, 27U);
                                            _SFD_EML_CALL(4U,
                                                          chartInstance->c9_sfEvent,
                                                          278);
                                            *c9_p = 3.0;
                                            c9_updateDataWrittenToVector
                                              (chartInstance, 26U);
                                            _SFD_EML_CALL(4U,
                                                          chartInstance->c9_sfEvent,
                                                          -278);
                                          } else {
                                            _SFD_EML_CALL(4U,
                                                          chartInstance->c9_sfEvent,
                                                          146U);
                                            if (CV_EML_IF(4, 1, 21,
                                                          c9_aVarTruthTableCondition_22))
                                            {
                                              _SFD_EML_CALL(4U,
                                                            chartInstance->c9_sfEvent,
                                                            147U);
                                              CV_EML_FCN(4, 22);
                                              _SFD_EML_CALL(4U,
                                                            chartInstance->c9_sfEvent,
                                                            284);
                                              c9_v_encStr2Arr(chartInstance,
                                                c9_dv80);
                                              for (c9_i531 = 0; c9_i531 < 256;
                                                   c9_i531++) {
                                                c9_gazeBML[c9_i531] =
                                                  c9_dv80[c9_i531];
                                              }

                                              c9_updateDataWrittenToVector
                                                (chartInstance, 27U);
                                              _SFD_EML_CALL(4U,
                                                            chartInstance->c9_sfEvent,
                                                            284);
                                              *c9_p = 2.0;
                                              c9_updateDataWrittenToVector
                                                (chartInstance, 26U);
                                              _SFD_EML_CALL(4U,
                                                            chartInstance->c9_sfEvent,
                                                            -284);
                                            } else {
                                              _SFD_EML_CALL(4U,
                                                            chartInstance->c9_sfEvent,
                                                            148U);
                                              if (CV_EML_IF(4, 1, 22,
                                                            c9_aVarTruthTableCondition_23))
                                              {
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  149U);
                                                CV_EML_FCN(4, 23);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent, 290);
                                                c9_w_encStr2Arr(chartInstance,
                                                  c9_dv80);
                                                for (c9_i532 = 0; c9_i532 < 256;
                                                     c9_i532++) {
                                                  c9_gazeBML[c9_i532] =
                                                    c9_dv80[c9_i532];
                                                }

                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 27U);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent, 290);
                                                *c9_p = 2.0;
                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 26U);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  -290);
                                              } else {
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  151U);
                                                CV_EML_FCN(4, 1);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  158U);
                                                c9_encStr2Arr(chartInstance,
                                                  c9_dv80);
                                                for (c9_i533 = 0; c9_i533 < 256;
                                                     c9_i533++) {
                                                  c9_gazeBML[c9_i533] =
                                                    c9_dv80[c9_i533];
                                                }

                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 27U);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  158U);
                                                *c9_p = 3.0;
                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 26U);
                                                _SFD_EML_CALL(4U,
                                                  chartInstance->c9_sfEvent,
                                                  -158);
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

  _SFD_EML_CALL(4U, chartInstance->c9_sfEvent, -151);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[17];
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
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv81[256];
  int32_T c9_i534;
  int32_T c9_i535;
  int32_T c9_i536;
  int32_T c9_i537;
  int32_T c9_i538;
  int32_T c9_i539;
  int32_T c9_i540;
  int32_T c9_i541;
  int32_T c9_i542;
  int32_T c9_i543;
  int32_T c9_i544;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[144];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[144];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i545;
  static char_T c9_cv49[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e',
    '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i546;
  static real_T c9_dv82[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0,
    101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 53.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0,
    84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i547;
  int32_T c9_i548;
  int32_T c9_i549;
  int32_T c9_i550;
  int32_T c9_i551;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c9_ab_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 12U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 13U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 14U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 15U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 16U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 21);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 27);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 30);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 33);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 36);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 39);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 42);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 45);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 48);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 51);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 53);
  if (CV_EML_IF(5, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 54);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 85);
    c9_encStr2Arr(chartInstance, c9_dv81);
    for (c9_i534 = 0; c9_i534 < 256; c9_i534++) {
      c9_gazeBML[c9_i534] = c9_dv81[c9_i534];
    }

    c9_updateDataWrittenToVector(chartInstance, 29U);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 85);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 28U);
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -85);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 55);
    if (CV_EML_IF(5, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 56);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 91);
      c9_b_encStr2Arr(chartInstance, c9_dv81);
      for (c9_i535 = 0; c9_i535 < 256; c9_i535++) {
        c9_gazeBML[c9_i535] = c9_dv81[c9_i535];
      }

      c9_updateDataWrittenToVector(chartInstance, 29U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 91);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 28U);
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -91);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 57);
      if (CV_EML_IF(5, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 58);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 97);
        c9_c_encStr2Arr(chartInstance, c9_dv81);
        for (c9_i536 = 0; c9_i536 < 256; c9_i536++) {
          c9_gazeBML[c9_i536] = c9_dv81[c9_i536];
        }

        c9_updateDataWrittenToVector(chartInstance, 29U);
        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 97);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 28U);
        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -97);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 59);
        if (CV_EML_IF(5, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 60);
          CV_EML_FCN(5, 4);
          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 103);
          c9_e_encStr2Arr(chartInstance, c9_dv81);
          for (c9_i537 = 0; c9_i537 < 256; c9_i537++) {
            c9_gazeBML[c9_i537] = c9_dv81[c9_i537];
          }

          c9_updateDataWrittenToVector(chartInstance, 29U);
          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 103);
          *c9_p = 3.0;
          c9_updateDataWrittenToVector(chartInstance, 28U);
          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -103);
        } else {
          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 61);
          if (CV_EML_IF(5, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 62);
            CV_EML_FCN(5, 5);
            _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 109);
            c9_f_encStr2Arr(chartInstance, c9_dv81);
            for (c9_i538 = 0; c9_i538 < 256; c9_i538++) {
              c9_gazeBML[c9_i538] = c9_dv81[c9_i538];
            }

            c9_updateDataWrittenToVector(chartInstance, 29U);
            _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 109);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 28U);
            _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -109);
          } else {
            _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 63);
            if (CV_EML_IF(5, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 64);
              CV_EML_FCN(5, 6);
              _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 115);
              c9_x_encStr2Arr(chartInstance, c9_dv81);
              for (c9_i539 = 0; c9_i539 < 256; c9_i539++) {
                c9_gazeBML[c9_i539] = c9_dv81[c9_i539];
              }

              c9_updateDataWrittenToVector(chartInstance, 29U);
              _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 115);
              *c9_p = 3.0;
              c9_updateDataWrittenToVector(chartInstance, 28U);
              _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -115);
            } else {
              _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 65);
              if (CV_EML_IF(5, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 66);
                CV_EML_FCN(5, 7);
                _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 121);
                c9_y_encStr2Arr(chartInstance, c9_dv81);
                for (c9_i540 = 0; c9_i540 < 256; c9_i540++) {
                  c9_gazeBML[c9_i540] = c9_dv81[c9_i540];
                }

                c9_updateDataWrittenToVector(chartInstance, 29U);
                _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 121);
                *c9_p = 3.0;
                c9_updateDataWrittenToVector(chartInstance, 28U);
                _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -121);
              } else {
                _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 67);
                if (CV_EML_IF(5, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 68);
                  CV_EML_FCN(5, 8);
                  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, MAX_int8_T);
                  c9_ab_encStr2Arr(chartInstance, c9_dv81);
                  for (c9_i541 = 0; c9_i541 < 256; c9_i541++) {
                    c9_gazeBML[c9_i541] = c9_dv81[c9_i541];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 29U);
                  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, MAX_int8_T);
                  *c9_p = 3.0;
                  c9_updateDataWrittenToVector(chartInstance, 28U);
                  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -127);
                } else {
                  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 69);
                  if (CV_EML_IF(5, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 70);
                    CV_EML_FCN(5, 9);
                    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 133U);
                    c9_bb_encStr2Arr(chartInstance, c9_dv81);
                    for (c9_i542 = 0; c9_i542 < 256; c9_i542++) {
                      c9_gazeBML[c9_i542] = c9_dv81[c9_i542];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 29U);
                    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 133U);
                    *c9_p = 3.0;
                    c9_updateDataWrittenToVector(chartInstance, 28U);
                    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 71);
                    if (CV_EML_IF(5, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 72);
                      CV_EML_FCN(5, 10);
                      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 139U);
                      c9_cb_encStr2Arr(chartInstance, c9_dv81);
                      for (c9_i543 = 0; c9_i543 < 256; c9_i543++) {
                        c9_gazeBML[c9_i543] = c9_dv81[c9_i543];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 29U);
                      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 139U);
                      *c9_p = 3.0;
                      c9_updateDataWrittenToVector(chartInstance, 28U);
                      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -139);
                    } else {
                      _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 73);
                      if (CV_EML_IF(5, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 74);
                        CV_EML_FCN(5, 11);
                        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 145U);
                        c9_db_encStr2Arr(chartInstance, c9_dv81);
                        for (c9_i544 = 0; c9_i544 < 256; c9_i544++) {
                          c9_gazeBML[c9_i544] = c9_dv81[c9_i544];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 29U);
                        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 145U);
                        *c9_p = 3.0;
                        c9_updateDataWrittenToVector(chartInstance, 28U);
                        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -145);
                      } else {
                        _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 75);
                        if (CV_EML_IF(5, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 76);
                          CV_EML_FCN(5, 12);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 151U);
                          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U,
                            c9_hb_debug_family_names, c9_b_debug_family_var_map);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize,
                            0U, c9_sf_marshallOut, c9_sf_marshallIn);
                          _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U,
                            c9_yb_sf_marshallOut);
                          _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U,
                            c9_sf_marshallOut);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
                            c9_sf_marshallOut, c9_sf_marshallIn);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U,
                            c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                          _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U,
                            c9_xb_sf_marshallOut);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
                            c9_sf_marshallOut, c9_sf_marshallIn);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
                            c9_sf_marshallOut, c9_sf_marshallIn);
                          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
                            c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                          for (c9_i545 = 0; c9_i545 < 144; c9_i545++) {
                            c9_mystr[c9_i545] = c9_cv49[c9_i545];
                          }

                          CV_SCRIPT_FCN(0, 0);
                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
                          c9_maxarrsize = 256.0;
                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
                          for (c9_i546 = 0; c9_i546 < 144; c9_i546++) {
                            c9_arr[c9_i546] = c9_dv82[c9_i546];
                          }

                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
                          c9_ss = 144.0;
                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
                          c9_padsize = 112.0;
                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
                          for (c9_i547 = 0; c9_i547 < 256; c9_i547++) {
                            c9_tt[c9_i547] = 0.0;
                          }

                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
                          for (c9_i548 = 0; c9_i548 < 144; c9_i548++) {
                            c9_tt[c9_i548] = c9_arr[c9_i548];
                          }

                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
                          for (c9_i549 = 0; c9_i549 < 256; c9_i549++) {
                            c9_myarr256[c9_i549] = c9_tt[c9_i549];
                          }

                          _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
                          _SFD_SYMBOL_SCOPE_POP();
                          for (c9_i550 = 0; c9_i550 < 256; c9_i550++) {
                            c9_gazeBML[c9_i550] = c9_myarr256[c9_i550];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 29U);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 151U);
                          *c9_p = 3.0;
                          c9_updateDataWrittenToVector(chartInstance, 28U);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -151);
                        } else {
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 78);
                          CV_EML_FCN(5, 1);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 85);
                          c9_encStr2Arr(chartInstance, c9_dv81);
                          for (c9_i551 = 0; c9_i551 < 256; c9_i551++) {
                            c9_gazeBML[c9_i551] = c9_dv81[c9_i551];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 29U);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, 85);
                          *c9_p = 3.0;
                          c9_updateDataWrittenToVector(chartInstance, 28U);
                          _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -85);
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

  _SFD_EML_CALL(5U, chartInstance->c9_sfEvent, -78);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeTableIntrovertc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[18];
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
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv83[256];
  int32_T c9_i552;
  int32_T c9_i553;
  int32_T c9_i554;
  int32_T c9_i555;
  int32_T c9_i556;
  int32_T c9_i557;
  int32_T c9_i558;
  int32_T c9_i559;
  int32_T c9_i560;
  int32_T c9_i561;
  int32_T c9_i562;
  int32_T c9_i563;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[144];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[144];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i564;
  static char_T c9_cv50[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't',
    '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i565;
  static real_T c9_dv84[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i566;
  int32_T c9_i567;
  int32_T c9_i568;
  int32_T c9_i569;
  int32_T c9_i570;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c9_ib_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 13U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 14U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 15U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 16U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 17U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 6);
  c9_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 11);
  c9_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 12);
  c9_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 13);
  c9_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 15);
  c9_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 19);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 22);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 25);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 28);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 31);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 34);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 37);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 40);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 43);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 46);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 49);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 52);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 55);
  c9_aVarTruthTableCondition_13 = (c9_bmlID == 13.0);
  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 57);
  if (CV_EML_IF(6, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 58);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 91);
    c9_encStr2Arr(chartInstance, c9_dv83);
    for (c9_i552 = 0; c9_i552 < 256; c9_i552++) {
      c9_gazeBML[c9_i552] = c9_dv83[c9_i552];
    }

    c9_updateDataWrittenToVector(chartInstance, 31U);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 91);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 30U);
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -91);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 59);
    if (CV_EML_IF(6, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 60);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 97);
      c9_b_encStr2Arr(chartInstance, c9_dv83);
      for (c9_i553 = 0; c9_i553 < 256; c9_i553++) {
        c9_gazeBML[c9_i553] = c9_dv83[c9_i553];
      }

      c9_updateDataWrittenToVector(chartInstance, 31U);
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 97);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 30U);
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -97);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 61);
      if (CV_EML_IF(6, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 62);
        CV_EML_FCN(6, 3);
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 103);
        c9_d_encStr2Arr(chartInstance, c9_dv83);
        for (c9_i554 = 0; c9_i554 < 256; c9_i554++) {
          c9_gazeBML[c9_i554] = c9_dv83[c9_i554];
        }

        c9_updateDataWrittenToVector(chartInstance, 31U);
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 103);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 30U);
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -103);
      } else {
        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 63);
        if (CV_EML_IF(6, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 64);
          CV_EML_FCN(6, 4);
          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 109);
          c9_e_encStr2Arr(chartInstance, c9_dv83);
          for (c9_i555 = 0; c9_i555 < 256; c9_i555++) {
            c9_gazeBML[c9_i555] = c9_dv83[c9_i555];
          }

          c9_updateDataWrittenToVector(chartInstance, 31U);
          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 109);
          *c9_p = 3.0;
          c9_updateDataWrittenToVector(chartInstance, 30U);
          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -109);
        } else {
          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 65);
          if (CV_EML_IF(6, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 66);
            CV_EML_FCN(6, 5);
            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 115);
            c9_f_encStr2Arr(chartInstance, c9_dv83);
            for (c9_i556 = 0; c9_i556 < 256; c9_i556++) {
              c9_gazeBML[c9_i556] = c9_dv83[c9_i556];
            }

            c9_updateDataWrittenToVector(chartInstance, 31U);
            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 115);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 30U);
            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -115);
          } else {
            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 67);
            if (CV_EML_IF(6, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 68);
              CV_EML_FCN(6, 6);
              _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 121);
              c9_g_encStr2Arr(chartInstance, c9_dv83);
              for (c9_i557 = 0; c9_i557 < 256; c9_i557++) {
                c9_gazeBML[c9_i557] = c9_dv83[c9_i557];
              }

              c9_updateDataWrittenToVector(chartInstance, 31U);
              _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 121);
              *c9_p = 3.0;
              c9_updateDataWrittenToVector(chartInstance, 30U);
              _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -121);
            } else {
              _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 69);
              if (CV_EML_IF(6, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 70);
                CV_EML_FCN(6, 7);
                _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, MAX_int8_T);
                c9_h_encStr2Arr(chartInstance, c9_dv83);
                for (c9_i558 = 0; c9_i558 < 256; c9_i558++) {
                  c9_gazeBML[c9_i558] = c9_dv83[c9_i558];
                }

                c9_updateDataWrittenToVector(chartInstance, 31U);
                _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, MAX_int8_T);
                *c9_p = 3.0;
                c9_updateDataWrittenToVector(chartInstance, 30U);
                _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -127);
              } else {
                _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 71);
                if (CV_EML_IF(6, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 72);
                  CV_EML_FCN(6, 8);
                  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 133U);
                  c9_eb_encStr2Arr(chartInstance, c9_dv83);
                  for (c9_i559 = 0; c9_i559 < 256; c9_i559++) {
                    c9_gazeBML[c9_i559] = c9_dv83[c9_i559];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 31U);
                  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 133U);
                  *c9_p = 3.0;
                  c9_updateDataWrittenToVector(chartInstance, 30U);
                  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -133);
                } else {
                  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 73);
                  if (CV_EML_IF(6, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 74);
                    CV_EML_FCN(6, 9);
                    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 139U);
                    c9_fb_encStr2Arr(chartInstance, c9_dv83);
                    for (c9_i560 = 0; c9_i560 < 256; c9_i560++) {
                      c9_gazeBML[c9_i560] = c9_dv83[c9_i560];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 31U);
                    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 139U);
                    *c9_p = 3.0;
                    c9_updateDataWrittenToVector(chartInstance, 30U);
                    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -139);
                  } else {
                    _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 75);
                    if (CV_EML_IF(6, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 76);
                      CV_EML_FCN(6, 10);
                      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 145U);
                      c9_gb_encStr2Arr(chartInstance, c9_dv83);
                      for (c9_i561 = 0; c9_i561 < 256; c9_i561++) {
                        c9_gazeBML[c9_i561] = c9_dv83[c9_i561];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 31U);
                      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 145U);
                      *c9_p = 3.0;
                      c9_updateDataWrittenToVector(chartInstance, 30U);
                      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -145);
                    } else {
                      _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 77);
                      if (CV_EML_IF(6, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 78);
                        CV_EML_FCN(6, 11);
                        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 151U);
                        c9_hb_encStr2Arr(chartInstance, c9_dv83);
                        for (c9_i562 = 0; c9_i562 < 256; c9_i562++) {
                          c9_gazeBML[c9_i562] = c9_dv83[c9_i562];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 31U);
                        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 151U);
                        *c9_p = 3.0;
                        c9_updateDataWrittenToVector(chartInstance, 30U);
                        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -151);
                      } else {
                        _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 79);
                        if (CV_EML_IF(6, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 80);
                          CV_EML_FCN(6, 12);
                          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 157U);
                          c9_ib_encStr2Arr(chartInstance, c9_dv83);
                          for (c9_i563 = 0; c9_i563 < 256; c9_i563++) {
                            c9_gazeBML[c9_i563] = c9_dv83[c9_i563];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 31U);
                          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 157U);
                          *c9_p = 3.0;
                          c9_updateDataWrittenToVector(chartInstance, 30U);
                          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -157);
                        } else {
                          _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 81);
                          if (CV_EML_IF(6, 1, 12, c9_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 82);
                            CV_EML_FCN(6, 13);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 163U);
                            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U,
                              c9_ob_debug_family_names,
                              c9_b_debug_family_var_map);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize,
                              0U, c9_sf_marshallOut, c9_sf_marshallIn);
                            _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U,
                              c9_yb_sf_marshallOut);
                            _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U,
                              c9_sf_marshallOut);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
                              c9_sf_marshallOut, c9_sf_marshallIn);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U,
                              c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                            _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U,
                              c9_xb_sf_marshallOut);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin,
                              6U, c9_sf_marshallOut, c9_sf_marshallIn);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout,
                              7U, c9_sf_marshallOut, c9_sf_marshallIn);
                            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
                              c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                            for (c9_i564 = 0; c9_i564 < 144; c9_i564++) {
                              c9_mystr[c9_i564] = c9_cv50[c9_i564];
                            }

                            CV_SCRIPT_FCN(0, 0);
                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
                            c9_maxarrsize = 256.0;
                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
                            for (c9_i565 = 0; c9_i565 < 144; c9_i565++) {
                              c9_arr[c9_i565] = c9_dv84[c9_i565];
                            }

                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
                            c9_ss = 144.0;
                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
                            c9_padsize = 112.0;
                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
                            for (c9_i566 = 0; c9_i566 < 256; c9_i566++) {
                              c9_tt[c9_i566] = 0.0;
                            }

                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
                            for (c9_i567 = 0; c9_i567 < 144; c9_i567++) {
                              c9_tt[c9_i567] = c9_arr[c9_i567];
                            }

                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
                            for (c9_i568 = 0; c9_i568 < 256; c9_i568++) {
                              c9_myarr256[c9_i568] = c9_tt[c9_i568];
                            }

                            _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
                            _SFD_SYMBOL_SCOPE_POP();
                            for (c9_i569 = 0; c9_i569 < 256; c9_i569++) {
                              c9_gazeBML[c9_i569] = c9_myarr256[c9_i569];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 31U);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 163U);
                            *c9_p = 3.0;
                            c9_updateDataWrittenToVector(chartInstance, 30U);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 84);
                            CV_EML_FCN(6, 1);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 91);
                            c9_encStr2Arr(chartInstance, c9_dv83);
                            for (c9_i570 = 0; c9_i570 < 256; c9_i570++) {
                              c9_gazeBML[c9_i570] = c9_dv83[c9_i570];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 31U);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, 91);
                            *c9_p = 3.0;
                            c9_updateDataWrittenToVector(chartInstance, 30U);
                            _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -91);
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

  _SFD_EML_CALL(6U, chartInstance->c9_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeInterestedTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[13];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  boolean_T c9_aVarTruthTableCondition_5;
  boolean_T c9_aVarTruthTableCondition_6;
  boolean_T c9_aVarTruthTableCondition_7;
  boolean_T c9_aVarTruthTableCondition_8;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv85[256];
  int32_T c9_i571;
  int32_T c9_i572;
  int32_T c9_i573;
  int32_T c9_i574;
  int32_T c9_i575;
  int32_T c9_i576;
  int32_T c9_i577;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[139];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[139];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i578;
  static char_T c9_cv51[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'P', 'O', 'L', 'A', 'R', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-',
    'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i579;
  static real_T c9_dv86[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 80.0, 79.0, 76.0, 65.0, 82.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0,
    105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0,
    97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i580;
  int32_T c9_i581;
  int32_T c9_i582;
  int32_T c9_i583;
  int32_T c9_i584;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c9_pb_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 10U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 12U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
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
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 17);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 23);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 26);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 29);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 32);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 35);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 37);
  if (CV_EML_IF(2, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 38);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 61);
    c9_jb_encStr2Arr(chartInstance, c9_dv85);
    for (c9_i571 = 0; c9_i571 < 256; c9_i571++) {
      c9_gazeBML[c9_i571] = c9_dv85[c9_i571];
    }

    c9_updateDataWrittenToVector(chartInstance, 33U);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 61);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 32U);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -61);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 39);
    if (CV_EML_IF(2, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 40);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 67);
      c9_kb_encStr2Arr(chartInstance, c9_dv85);
      for (c9_i572 = 0; c9_i572 < 256; c9_i572++) {
        c9_gazeBML[c9_i572] = c9_dv85[c9_i572];
      }

      c9_updateDataWrittenToVector(chartInstance, 33U);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 67);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 32U);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -67);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 41);
      if (CV_EML_IF(2, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 42);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 73);
        c9_lb_encStr2Arr(chartInstance, c9_dv85);
        for (c9_i573 = 0; c9_i573 < 256; c9_i573++) {
          c9_gazeBML[c9_i573] = c9_dv85[c9_i573];
        }

        c9_updateDataWrittenToVector(chartInstance, 33U);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 73);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 32U);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -73);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 43);
        if (CV_EML_IF(2, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 44);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 79);
          c9_mb_encStr2Arr(chartInstance, c9_dv85);
          for (c9_i574 = 0; c9_i574 < 256; c9_i574++) {
            c9_gazeBML[c9_i574] = c9_dv85[c9_i574];
          }

          c9_updateDataWrittenToVector(chartInstance, 33U);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 79);
          *c9_p = 3.0;
          c9_updateDataWrittenToVector(chartInstance, 32U);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -79);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 45);
          if (CV_EML_IF(2, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 46);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 85);
            c9_nb_encStr2Arr(chartInstance, c9_dv85);
            for (c9_i575 = 0; c9_i575 < 256; c9_i575++) {
              c9_gazeBML[c9_i575] = c9_dv85[c9_i575];
            }

            c9_updateDataWrittenToVector(chartInstance, 33U);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 85);
            *c9_p = 3.0;
            c9_updateDataWrittenToVector(chartInstance, 32U);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -85);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 47);
            if (CV_EML_IF(2, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 48);
              CV_EML_FCN(2, 6);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 91);
              c9_ob_encStr2Arr(chartInstance, c9_dv85);
              for (c9_i576 = 0; c9_i576 < 256; c9_i576++) {
                c9_gazeBML[c9_i576] = c9_dv85[c9_i576];
              }

              c9_updateDataWrittenToVector(chartInstance, 33U);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 91);
              *c9_p = 3.0;
              c9_updateDataWrittenToVector(chartInstance, 32U);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -91);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 49);
              if (CV_EML_IF(2, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 50);
                CV_EML_FCN(2, 7);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 97);
                c9_pb_encStr2Arr(chartInstance, c9_dv85);
                for (c9_i577 = 0; c9_i577 < 256; c9_i577++) {
                  c9_gazeBML[c9_i577] = c9_dv85[c9_i577];
                }

                c9_updateDataWrittenToVector(chartInstance, 33U);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 97);
                *c9_p = 3.0;
                c9_updateDataWrittenToVector(chartInstance, 32U);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -97);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 51);
                if (CV_EML_IF(2, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 52);
                  CV_EML_FCN(2, 8);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 103);
                  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U,
                    c9_xb_debug_family_names, c9_b_debug_family_var_map);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
                    c9_sf_marshallOut, c9_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_lc_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
                    c9_sf_marshallOut, c9_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U,
                    c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_kc_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
                    c9_sf_marshallOut, c9_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
                    c9_sf_marshallOut, c9_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
                    c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                  for (c9_i578 = 0; c9_i578 < 139; c9_i578++) {
                    c9_mystr[c9_i578] = c9_cv51[c9_i578];
                  }

                  CV_SCRIPT_FCN(0, 0);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
                  c9_maxarrsize = 256.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
                  for (c9_i579 = 0; c9_i579 < 139; c9_i579++) {
                    c9_arr[c9_i579] = c9_dv86[c9_i579];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
                  c9_ss = 139.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
                  c9_padsize = 117.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
                  for (c9_i580 = 0; c9_i580 < 256; c9_i580++) {
                    c9_tt[c9_i580] = 0.0;
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
                  for (c9_i581 = 0; c9_i581 < 139; c9_i581++) {
                    c9_tt[c9_i581] = c9_arr[c9_i581];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
                  for (c9_i582 = 0; c9_i582 < 256; c9_i582++) {
                    c9_myarr256[c9_i582] = c9_tt[c9_i582];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
                  _SFD_SYMBOL_SCOPE_POP();
                  for (c9_i583 = 0; c9_i583 < 256; c9_i583++) {
                    c9_gazeBML[c9_i583] = c9_myarr256[c9_i583];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 33U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 103);
                  *c9_p = 3.0;
                  c9_updateDataWrittenToVector(chartInstance, 32U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -103);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 54);
                  CV_EML_FCN(2, 1);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 61);
                  c9_jb_encStr2Arr(chartInstance, c9_dv85);
                  for (c9_i584 = 0; c9_i584 < 256; c9_i584++) {
                    c9_gazeBML[c9_i584] = c9_dv85[c9_i584];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 33U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 61);
                  *c9_p = 3.0;
                  c9_updateDataWrittenToVector(chartInstance, 32U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -61);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_successTablec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[8];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv87[256];
  int32_T c9_i585;
  int32_T c9_i586;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[185];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[185];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i587;
  static char_T c9_cv52[185] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=',
    '\"', '1', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H',
    '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd',
    '=', '\"', '1', '5', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c',
    's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm', 'o', 'u', 'n',
    't', '=', '\"', '0', '.', '3', '\"', ' ', ' ', 'a', 'u', '=', '\"', '2',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '5', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"',
    '0', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i588;
  static real_T c9_dv88[185] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 116.0, 121.0,
    112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0,
    102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 32.0, 32.0, 97.0, 117.0, 61.0, 34.0,
    50.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0,
    115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 116.0, 121.0,
    112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i589;
  int32_T c9_i590;
  int32_T c9_i591;
  int32_T c9_i592;
  int32_T c9_i593;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_yb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_poseBML, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
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
    c9_qb_encStr2Arr(chartInstance, c9_dv87);
    for (c9_i585 = 0; c9_i585 < 256; c9_i585++) {
      c9_poseBML[c9_i585] = c9_dv87[c9_i585];
    }

    c9_updateDataWrittenToVector(chartInstance, 35U);
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 34);
    *c9_p = 3.0;
    c9_updateDataWrittenToVector(chartInstance, 34U);
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -34);
  } else {
    _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 22);
    if (CV_EML_IF(31, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 23);
      CV_EML_FCN(31, 2);
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 40);
      c9_rb_encStr2Arr(chartInstance, c9_dv87);
      for (c9_i586 = 0; c9_i586 < 256; c9_i586++) {
        c9_poseBML[c9_i586] = c9_dv87[c9_i586];
      }

      c9_updateDataWrittenToVector(chartInstance, 35U);
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 40);
      *c9_p = 3.0;
      c9_updateDataWrittenToVector(chartInstance, 34U);
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -40);
    } else {
      _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 24);
      if (CV_EML_IF(31, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 25);
        CV_EML_FCN(31, 3);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_cc_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_pc_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
          c9_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_oc_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
          c9_d_sf_marshallOut, c9_d_sf_marshallIn);
        for (c9_i587 = 0; c9_i587 < 185; c9_i587++) {
          c9_mystr[c9_i587] = c9_cv52[c9_i587];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
        c9_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
        for (c9_i588 = 0; c9_i588 < 185; c9_i588++) {
          c9_arr[c9_i588] = c9_dv88[c9_i588];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
        c9_ss = 185.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
        c9_padsize = 71.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
        for (c9_i589 = 0; c9_i589 < 256; c9_i589++) {
          c9_tt[c9_i589] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
        for (c9_i590 = 0; c9_i590 < 185; c9_i590++) {
          c9_tt[c9_i590] = c9_arr[c9_i590];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
        for (c9_i591 = 0; c9_i591 < 256; c9_i591++) {
          c9_myarr256[c9_i591] = c9_tt[c9_i591];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c9_i592 = 0; c9_i592 < 256; c9_i592++) {
          c9_poseBML[c9_i592] = c9_myarr256[c9_i592];
        }

        c9_updateDataWrittenToVector(chartInstance, 35U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 46);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 34U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -46);
      } else {
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 27);
        CV_EML_FCN(31, 1);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 34);
        c9_qb_encStr2Arr(chartInstance, c9_dv87);
        for (c9_i593 = 0; c9_i593 < 256; c9_i593++) {
          c9_poseBML[c9_i593] = c9_dv87[c9_i593];
        }

        c9_updateDataWrittenToVector(chartInstance, 35U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, 34);
        *c9_p = 3.0;
        c9_updateDataWrittenToVector(chartInstance, 34U);
        _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(31U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_gazeFollowUserMovec9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmlID, real_T
   *c9_p, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[8];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_dv89[256];
  int32_T c9_i594;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[147];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[147];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i595;
  static char_T c9_cv53[147] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H',
    'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r',
    'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i596;
  static real_T c9_dv90[147] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0,
    65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0,
    122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i597;
  int32_T c9_i598;
  int32_T c9_i599;
  int32_T c9_i600;
  int32_T c9_i601;
  int32_T c9_i602;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_dc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_1, 0U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_2, 1U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_aVarTruthTableCondition_3, 2U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
  if (CV_EML_IF(0, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
    c9_sb_encStr2Arr(chartInstance, c9_dv89);
    for (c9_i594 = 0; c9_i594 < 256; c9_i594++) {
      c9_gazeBML[c9_i594] = c9_dv89[c9_i594];
    }

    c9_updateDataWrittenToVector(chartInstance, 37U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 34);
    *c9_p = 1.0;
    c9_updateDataWrittenToVector(chartInstance, 36U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -34);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
    if (CV_EML_IF(0, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_fc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_cb_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_bb_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      for (c9_i595 = 0; c9_i595 < 147; c9_i595++) {
        c9_mystr[c9_i595] = c9_cv53[c9_i595];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
      c9_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
      for (c9_i596 = 0; c9_i596 < 147; c9_i596++) {
        c9_arr[c9_i596] = c9_dv90[c9_i596];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
      c9_ss = 147.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
      c9_padsize = 109.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
      for (c9_i597 = 0; c9_i597 < 256; c9_i597++) {
        c9_tt[c9_i597] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
      for (c9_i598 = 0; c9_i598 < 147; c9_i598++) {
        c9_tt[c9_i598] = c9_arr[c9_i598];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
      for (c9_i599 = 0; c9_i599 < 256; c9_i599++) {
        c9_myarr256[c9_i599] = c9_tt[c9_i599];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c9_i600 = 0; c9_i600 < 256; c9_i600++) {
        c9_gazeBML[c9_i600] = c9_myarr256[c9_i600];
      }

      c9_updateDataWrittenToVector(chartInstance, 37U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
      *c9_p = 1.0;
      c9_updateDataWrittenToVector(chartInstance, 36U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -40);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
      if (CV_EML_IF(0, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        c9_tb_encStr2Arr(chartInstance, c9_dv89);
        for (c9_i601 = 0; c9_i601 < 256; c9_i601++) {
          c9_gazeBML[c9_i601] = c9_dv89[c9_i601];
        }

        c9_updateDataWrittenToVector(chartInstance, 37U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        *c9_p = 1.0;
        c9_updateDataWrittenToVector(chartInstance, 36U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -46);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        c9_tb_encStr2Arr(chartInstance, c9_dv89);
        for (c9_i602 = 0; c9_i602 < 256; c9_i602++) {
          c9_gazeBML[c9_i602] = c9_dv89[c9_i602];
        }

        c9_updateDataWrittenToVector(chartInstance, 37U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        *c9_p = 1.0;
        c9_updateDataWrittenToVector(chartInstance, 36U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -46);
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeFunctionc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_dir, real_T
   c9_mag, real_T c9_p, real_T c9_arrBML[256])
{
  uint32_T c9_debug_family_var_map[10];
  int32_T c9_dirG_sizes[2];
  char_T c9_dirG_data[9];
  real_T c9_cDir;
  real_T c9_c;
  int32_T c9_mystr_sizes[2];
  char_T c9_mystr_data[138];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 1.0;
  int32_T c9_dirG;
  int32_T c9_b_dirG;
  int32_T c9_i603;
  static char_T c9_cv54[7] = { 'U', 'P', 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_c_dirG;
  int32_T c9_d_dirG;
  int32_T c9_i604;
  static char_T c9_cv55[4] = { 'D', 'O', 'W', 'N' };

  int32_T c9_e_dirG;
  int32_T c9_f_dirG;
  int32_T c9_i605;
  static char_T c9_cv56[5] = { 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_g_dirG;
  int32_T c9_h_dirG;
  int32_T c9_i606;
  static char_T c9_cv57[4] = { 'L', 'E', 'F', 'T' };

  int32_T c9_i_dirG;
  int32_T c9_j_dirG;
  int32_T c9_i607;
  static char_T c9_cv58[2] = { 'U', 'P' };

  int32_T c9_k_dirG;
  int32_T c9_l_dirG;
  int32_T c9_i608;
  static char_T c9_cv59[6] = { 'U', 'P', 'L', 'E', 'F', 'T' };

  int32_T c9_m_dirG;
  int32_T c9_n_dirG;
  int32_T c9_i609;
  static char_T c9_cv60[9] = { 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_o_dirG;
  int32_T c9_p_dirG;
  int32_T c9_i610;
  static char_T c9_cv61[8] = { 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T' };

  int32_T c9_q_dirG;
  int32_T c9_r_dirG;
  int32_T c9_i611;
  int32_T c9_s_dirG;
  int32_T c9_t_dirG;
  int32_T c9_i612;
  int32_T c9_u_dirG;
  int32_T c9_v_dirG;
  int32_T c9_i613;
  int32_T c9_w_dirG;
  int32_T c9_x_dirG;
  int32_T c9_i614;
  int32_T c9_y_dirG;
  int32_T c9_ab_dirG;
  int32_T c9_i615;
  int32_T c9_bb_dirG;
  int32_T c9_cb_dirG;
  int32_T c9_i616;
  int32_T c9_db_dirG;
  int32_T c9_eb_dirG;
  int32_T c9_i617;
  int32_T c9_fb_dirG;
  int32_T c9_gb_dirG;
  int32_T c9_i618;
  int32_T c9_hb_dirG;
  int32_T c9_ib_dirG;
  int32_T c9_i619;
  int32_T c9_i620;
  static char_T c9_cv62[9] = { 'g', 'a', 'z', 'e', ' ', 'e', 'l', 's', 'e' };

  char_T c9_u[9];
  const mxArray *c9_y = NULL;
  int32_T c9_jb_dirG;
  int32_T c9_kb_dirG;
  int32_T c9_i621;
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[138];
  int32_T c9_mystr;
  int32_T c9_b_mystr;
  int32_T c9_loop_ub;
  int32_T c9_i622;
  int32_T c9_i623;
  static char_T c9_cv63[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '%', 'd', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', '%', 's', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  char_T c9_b_u[120];
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_c_y = NULL;
  int32_T c9_u_sizes[2];
  int32_T c9_d_u;
  int32_T c9_e_u;
  int32_T c9_b_loop_ub;
  int32_T c9_i624;
  char_T c9_u_data[9];
  const mxArray *c9_d_y = NULL;
  int32_T c9_b_tmp_sizes[2];
  char_T c9_b_tmp_data[138];
  int32_T c9_c_mystr;
  int32_T c9_d_mystr;
  int32_T c9_c_loop_ub;
  int32_T c9_i625;
  int32_T c9_b_mystr_sizes[2];
  int32_T c9_e_mystr;
  int32_T c9_f_mystr;
  int32_T c9_d_loop_ub;
  int32_T c9_i626;
  char_T c9_b_mystr_data[138];
  real_T c9_dv91[256];
  int32_T c9_i627;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  boolean_T guard16 = false;
  boolean_T guard17 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c9_hc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_dirG_data, (const int32_T *)
    &c9_dirG_sizes, NULL, 0, 0, (void *)c9_tc_sf_marshallOut, (void *)
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cDir, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_mystr_data, (const int32_T *)
    &c9_mystr_sizes, NULL, 0, 3, (void *)c9_sc_sf_marshallOut, (void *)
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_dir, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_mag, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_arrBML, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 2);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 14);
  guard1 = false;
  if (CV_EML_COND(1, 1, 0, c9_p == 1.0)) {
    guard1 = true;
  } else if (CV_EML_COND(1, 1, 1, c9_p == 3.0)) {
    guard1 = true;
  } else {
    CV_EML_MCDC(1, 1, 0, false);
    CV_EML_IF(1, 1, 0, false);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 46);
    guard10 = false;
    if (CV_EML_COND(1, 1, 18, 0.0 < c9_dir)) {
      if (CV_EML_COND(1, 1, 19, c9_dir <= 64.0)) {
        CV_EML_MCDC(1, 1, 9, true);
        CV_EML_IF(1, 1, 9, true);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 47);
        c9_dirG_sizes[0] = 1;
        c9_dirG_sizes[1] = 4;
        c9_s_dirG = c9_dirG_sizes[0];
        c9_t_dirG = c9_dirG_sizes[1];
        for (c9_i612 = 0; c9_i612 < 4; c9_i612++) {
          c9_dirG_data[c9_i612] = c9_cv55[c9_i612];
        }

        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 48);
        c9_cDir = 4.0;
      } else {
        guard10 = true;
      }
    } else {
      guard10 = true;
    }

    if (guard10 == true) {
      CV_EML_MCDC(1, 1, 9, false);
      CV_EML_IF(1, 1, 9, false);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 49);
      guard11 = false;
      if (CV_EML_COND(1, 1, 20, 64.0 < c9_dir)) {
        if (CV_EML_COND(1, 1, 21, c9_dir <= 70.0)) {
          CV_EML_MCDC(1, 1, 10, true);
          CV_EML_IF(1, 1, 10, true);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 50);
          c9_dirG_sizes[0] = 1;
          c9_dirG_sizes[1] = 2;
          c9_u_dirG = c9_dirG_sizes[0];
          c9_v_dirG = c9_dirG_sizes[1];
          for (c9_i613 = 0; c9_i613 < 2; c9_i613++) {
            c9_dirG_data[c9_i613] = c9_cv58[c9_i613];
          }

          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 51);
          c9_mag -= 2.0;
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 52);
          c9_cDir = 2.0;
        } else {
          guard11 = true;
        }
      } else {
        guard11 = true;
      }

      if (guard11 == true) {
        CV_EML_MCDC(1, 1, 10, false);
        CV_EML_IF(1, 1, 10, false);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 53);
        guard12 = false;
        if (CV_EML_COND(1, 1, 22, 70.0 < c9_dir)) {
          if (CV_EML_COND(1, 1, 23, c9_dir <= 85.0)) {
            CV_EML_MCDC(1, 1, 11, true);
            CV_EML_IF(1, 1, 11, true);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 54);
            c9_dirG_sizes[0] = 1;
            c9_dirG_sizes[1] = 5;
            c9_w_dirG = c9_dirG_sizes[0];
            c9_x_dirG = c9_dirG_sizes[1];
            for (c9_i614 = 0; c9_i614 < 5; c9_i614++) {
              c9_dirG_data[c9_i614] = c9_cv56[c9_i614];
            }

            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 55);
            c9_cDir = 5.0;
          } else {
            guard12 = true;
          }
        } else {
          guard12 = true;
        }

        if (guard12 == true) {
          CV_EML_MCDC(1, 1, 11, false);
          CV_EML_IF(1, 1, 11, false);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 56);
          guard13 = false;
          if (CV_EML_COND(1, 1, 24, 85.0 < c9_dir)) {
            if (CV_EML_COND(1, 1, 25, c9_dir <= 100.0)) {
              CV_EML_MCDC(1, 1, 12, true);
              CV_EML_IF(1, 1, 12, true);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 57);
              c9_dirG_sizes[0] = 1;
              c9_dirG_sizes[1] = 4;
              c9_y_dirG = c9_dirG_sizes[0];
              c9_ab_dirG = c9_dirG_sizes[1];
              for (c9_i615 = 0; c9_i615 < 4; c9_i615++) {
                c9_dirG_data[c9_i615] = c9_cv57[c9_i615];
              }

              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 58);
              c9_cDir = 4.0;
            } else {
              guard13 = true;
            }
          } else {
            guard13 = true;
          }

          if (guard13 == true) {
            CV_EML_MCDC(1, 1, 12, false);
            CV_EML_IF(1, 1, 12, false);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 60);
            guard14 = false;
            if (CV_EML_COND(1, 1, 26, 100.0 < c9_dir)) {
              if (CV_EML_COND(1, 1, 27, c9_dir <= 102.0)) {
                CV_EML_MCDC(1, 1, 13, true);
                CV_EML_IF(1, 1, 13, true);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 61);
                c9_dirG_sizes[0] = 1;
                c9_dirG_sizes[1] = 7;
                c9_bb_dirG = c9_dirG_sizes[0];
                c9_cb_dirG = c9_dirG_sizes[1];
                for (c9_i616 = 0; c9_i616 < 7; c9_i616++) {
                  c9_dirG_data[c9_i616] = c9_cv54[c9_i616];
                }

                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 62);
                c9_cDir = 7.0;
              } else {
                guard14 = true;
              }
            } else {
              guard14 = true;
            }

            if (guard14 == true) {
              CV_EML_MCDC(1, 1, 13, false);
              CV_EML_IF(1, 1, 13, false);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 63);
              guard15 = false;
              if (CV_EML_COND(1, 1, 28, 102.0 < c9_dir)) {
                if (CV_EML_COND(1, 1, 29, c9_dir <= 104.0)) {
                  CV_EML_MCDC(1, 1, 14, true);
                  CV_EML_IF(1, 1, 14, true);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 64);
                  c9_dirG_sizes[0] = 1;
                  c9_dirG_sizes[1] = 6;
                  c9_db_dirG = c9_dirG_sizes[0];
                  c9_eb_dirG = c9_dirG_sizes[1];
                  for (c9_i617 = 0; c9_i617 < 6; c9_i617++) {
                    c9_dirG_data[c9_i617] = c9_cv59[c9_i617];
                  }

                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 65);
                  c9_cDir = 6.0;
                } else {
                  guard15 = true;
                }
              } else {
                guard15 = true;
              }

              if (guard15 == true) {
                CV_EML_MCDC(1, 1, 14, false);
                CV_EML_IF(1, 1, 14, false);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 66);
                guard16 = false;
                if (CV_EML_COND(1, 1, 30, 104.0 < c9_dir)) {
                  if (CV_EML_COND(1, 1, 31, c9_dir <= 118.0)) {
                    CV_EML_MCDC(1, 1, 15, true);
                    CV_EML_IF(1, 1, 15, true);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 67);
                    c9_dirG_sizes[0] = 1;
                    c9_dirG_sizes[1] = 9;
                    c9_fb_dirG = c9_dirG_sizes[0];
                    c9_gb_dirG = c9_dirG_sizes[1];
                    for (c9_i618 = 0; c9_i618 < 9; c9_i618++) {
                      c9_dirG_data[c9_i618] = c9_cv60[c9_i618];
                    }

                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 68);
                    c9_cDir = 9.0;
                  } else {
                    guard16 = true;
                  }
                } else {
                  guard16 = true;
                }

                if (guard16 == true) {
                  CV_EML_MCDC(1, 1, 15, false);
                  CV_EML_IF(1, 1, 15, false);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 69);
                  guard17 = false;
                  if (CV_EML_COND(1, 1, 32, 118.0 < c9_dir)) {
                    if (CV_EML_COND(1, 1, 33, c9_dir <= 132.0)) {
                      CV_EML_MCDC(1, 1, 16, true);
                      CV_EML_IF(1, 1, 16, true);
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 70);
                      c9_dirG_sizes[0] = 1;
                      c9_dirG_sizes[1] = 8;
                      c9_hb_dirG = c9_dirG_sizes[0];
                      c9_ib_dirG = c9_dirG_sizes[1];
                      for (c9_i619 = 0; c9_i619 < 8; c9_i619++) {
                        c9_dirG_data[c9_i619] = c9_cv61[c9_i619];
                      }

                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 71);
                      c9_cDir = 8.0;
                    } else {
                      guard17 = true;
                    }
                  } else {
                    guard17 = true;
                  }

                  if (guard17 == true) {
                    CV_EML_MCDC(1, 1, 16, false);
                    CV_EML_IF(1, 1, 16, false);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 73);
                    for (c9_i620 = 0; c9_i620 < 9; c9_i620++) {
                      c9_u[c9_i620] = c9_cv62[c9_i620];
                    }

                    c9_y = NULL;
                    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U,
                      2, 1, 9), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c9_y);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 74);
                    c9_dirG_sizes[0] = 1;
                    c9_dirG_sizes[1] = 4;
                    c9_jb_dirG = c9_dirG_sizes[0];
                    c9_kb_dirG = c9_dirG_sizes[1];
                    for (c9_i621 = 0; c9_i621 < 4; c9_i621++) {
                      c9_dirG_data[c9_i621] = c9_cv57[c9_i621];
                    }

                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 75);
                    c9_cDir = 4.0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(1, 1, 0, true);
    CV_EML_IF(1, 1, 0, true);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 15);
    guard2 = false;
    if (CV_EML_COND(1, 1, 2, 0.0 < c9_dir)) {
      if (CV_EML_COND(1, 1, 3, c9_dir <= 31.0)) {
        CV_EML_MCDC(1, 1, 1, true);
        CV_EML_IF(1, 1, 1, true);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 16);
        c9_dirG_sizes[0] = 1;
        c9_dirG_sizes[1] = 7;
        c9_dirG = c9_dirG_sizes[0];
        c9_b_dirG = c9_dirG_sizes[1];
        for (c9_i603 = 0; c9_i603 < 7; c9_i603++) {
          c9_dirG_data[c9_i603] = c9_cv54[c9_i603];
        }

        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 17);
        c9_cDir = 7.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(1, 1, 1, false);
      CV_EML_IF(1, 1, 1, false);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 18);
      guard3 = false;
      if (CV_EML_COND(1, 1, 4, 31.0 < c9_dir)) {
        if (CV_EML_COND(1, 1, 5, c9_dir <= 37.0)) {
          CV_EML_MCDC(1, 1, 2, true);
          CV_EML_IF(1, 1, 2, true);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 19);
          c9_dirG_sizes[0] = 1;
          c9_dirG_sizes[1] = 4;
          c9_c_dirG = c9_dirG_sizes[0];
          c9_d_dirG = c9_dirG_sizes[1];
          for (c9_i604 = 0; c9_i604 < 4; c9_i604++) {
            c9_dirG_data[c9_i604] = c9_cv55[c9_i604];
          }

          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 20);
          c9_cDir = 4.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(1, 1, 2, false);
        CV_EML_IF(1, 1, 2, false);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 21);
        guard4 = false;
        if (CV_EML_COND(1, 1, 6, 37.0 < c9_dir)) {
          if (CV_EML_COND(1, 1, 7, c9_dir <= 68.0)) {
            CV_EML_MCDC(1, 1, 3, true);
            CV_EML_IF(1, 1, 3, true);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 22);
            c9_dirG_sizes[0] = 1;
            c9_dirG_sizes[1] = 5;
            c9_e_dirG = c9_dirG_sizes[0];
            c9_f_dirG = c9_dirG_sizes[1];
            for (c9_i605 = 0; c9_i605 < 5; c9_i605++) {
              c9_dirG_data[c9_i605] = c9_cv56[c9_i605];
            }

            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 23);
            c9_cDir = 5.0;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4 == true) {
          CV_EML_MCDC(1, 1, 3, false);
          CV_EML_IF(1, 1, 3, false);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 24);
          guard5 = false;
          if (CV_EML_COND(1, 1, 8, 68.0 < c9_dir)) {
            if (CV_EML_COND(1, 1, 9, c9_dir <= 99.0)) {
              CV_EML_MCDC(1, 1, 4, true);
              CV_EML_IF(1, 1, 4, true);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 25);
              c9_dirG_sizes[0] = 1;
              c9_dirG_sizes[1] = 4;
              c9_g_dirG = c9_dirG_sizes[0];
              c9_h_dirG = c9_dirG_sizes[1];
              for (c9_i606 = 0; c9_i606 < 4; c9_i606++) {
                c9_dirG_data[c9_i606] = c9_cv57[c9_i606];
              }

              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 26);
              c9_cDir = 4.0;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }

          if (guard5 == true) {
            CV_EML_MCDC(1, 1, 4, false);
            CV_EML_IF(1, 1, 4, false);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 28);
            guard6 = false;
            if (CV_EML_COND(1, 1, 10, 99.0 < c9_dir)) {
              if (CV_EML_COND(1, 1, 11, c9_dir <= 113.0)) {
                CV_EML_MCDC(1, 1, 5, true);
                CV_EML_IF(1, 1, 5, true);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 29);
                c9_dirG_sizes[0] = 1;
                c9_dirG_sizes[1] = 2;
                c9_i_dirG = c9_dirG_sizes[0];
                c9_j_dirG = c9_dirG_sizes[1];
                for (c9_i607 = 0; c9_i607 < 2; c9_i607++) {
                  c9_dirG_data[c9_i607] = c9_cv58[c9_i607];
                }

                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 30);
                c9_mag -= 2.0;
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 31);
                c9_cDir = 2.0;
              } else {
                guard6 = true;
              }
            } else {
              guard6 = true;
            }

            if (guard6 == true) {
              CV_EML_MCDC(1, 1, 5, false);
              CV_EML_IF(1, 1, 5, false);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 32);
              guard7 = false;
              if (CV_EML_COND(1, 1, 12, 113.0 < c9_dir)) {
                if (CV_EML_COND(1, 1, 13, c9_dir <= 127.0)) {
                  CV_EML_MCDC(1, 1, 6, true);
                  CV_EML_IF(1, 1, 6, true);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 33);
                  c9_dirG_sizes[0] = 1;
                  c9_dirG_sizes[1] = 6;
                  c9_k_dirG = c9_dirG_sizes[0];
                  c9_l_dirG = c9_dirG_sizes[1];
                  for (c9_i608 = 0; c9_i608 < 6; c9_i608++) {
                    c9_dirG_data[c9_i608] = c9_cv59[c9_i608];
                  }

                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 34);
                  c9_cDir = 6.0;
                } else {
                  guard7 = true;
                }
              } else {
                guard7 = true;
              }

              if (guard7 == true) {
                CV_EML_MCDC(1, 1, 6, false);
                CV_EML_IF(1, 1, 6, false);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 35);
                guard8 = false;
                if (CV_EML_COND(1, 1, 14, 127.0 < c9_dir)) {
                  if (CV_EML_COND(1, 1, 15, c9_dir <= 129.0)) {
                    CV_EML_MCDC(1, 1, 7, true);
                    CV_EML_IF(1, 1, 7, true);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 36);
                    c9_dirG_sizes[0] = 1;
                    c9_dirG_sizes[1] = 9;
                    c9_m_dirG = c9_dirG_sizes[0];
                    c9_n_dirG = c9_dirG_sizes[1];
                    for (c9_i609 = 0; c9_i609 < 9; c9_i609++) {
                      c9_dirG_data[c9_i609] = c9_cv60[c9_i609];
                    }

                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 37);
                    c9_cDir = 9.0;
                  } else {
                    guard8 = true;
                  }
                } else {
                  guard8 = true;
                }

                if (guard8 == true) {
                  CV_EML_MCDC(1, 1, 7, false);
                  CV_EML_IF(1, 1, 7, false);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 38);
                  guard9 = false;
                  if (CV_EML_COND(1, 1, 16, 129.0 < c9_dir)) {
                    if (CV_EML_COND(1, 1, 17, c9_dir <= 132.0)) {
                      CV_EML_MCDC(1, 1, 8, true);
                      CV_EML_IF(1, 1, 8, true);
                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 39);
                      c9_dirG_sizes[0] = 1;
                      c9_dirG_sizes[1] = 8;
                      c9_o_dirG = c9_dirG_sizes[0];
                      c9_p_dirG = c9_dirG_sizes[1];
                      for (c9_i610 = 0; c9_i610 < 8; c9_i610++) {
                        c9_dirG_data[c9_i610] = c9_cv61[c9_i610];
                      }

                      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 40);
                      c9_cDir = 8.0;
                    } else {
                      guard9 = true;
                    }
                  } else {
                    guard9 = true;
                  }

                  if (guard9 == true) {
                    CV_EML_MCDC(1, 1, 8, false);
                    CV_EML_IF(1, 1, 8, false);
                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 42);
                    c9_dirG_sizes[0] = 1;
                    c9_dirG_sizes[1] = 4;
                    c9_q_dirG = c9_dirG_sizes[0];
                    c9_r_dirG = c9_dirG_sizes[1];
                    for (c9_i611 = 0; c9_i611 < 4; c9_i611++) {
                      c9_dirG_data[c9_i611] = c9_cv57[c9_i611];
                    }

                    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 43);
                    c9_cDir = 4.0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 78);
  c9_c = c9_countDigits(chartInstance, c9_mag);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 80);
  c9_blanks(chartInstance, (125.0 + c9_c) + c9_cDir, c9_tmp_data, c9_tmp_sizes);
  c9_mystr_sizes[0] = 1;
  c9_mystr_sizes[1] = c9_tmp_sizes[1];
  c9_mystr = c9_mystr_sizes[0];
  c9_b_mystr = c9_mystr_sizes[1];
  c9_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i622 = 0; c9_i622 <= c9_loop_ub; c9_i622++) {
    c9_mystr_data[c9_i622] = c9_tmp_data[c9_i622];
  }

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 81);
  for (c9_i623 = 0; c9_i623 < 120; c9_i623++) {
    c9_b_u[c9_i623] = c9_cv63[c9_i623];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  c9_c_u = c9_mag;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = c9_dirG_sizes[1];
  c9_d_u = c9_u_sizes[0];
  c9_e_u = c9_u_sizes[1];
  c9_b_loop_ub = c9_dirG_sizes[0] * c9_dirG_sizes[1] - 1;
  for (c9_i624 = 0; c9_i624 <= c9_b_loop_ub; c9_i624++) {
    c9_u_data[c9_i624] = c9_dirG_data[c9_i624];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_u_data, 10, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  c9_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14,
                       c9_b_y, 14, c9_c_y, 14, c9_d_y), "sprintf", c9_b_tmp_data,
                      c9_b_tmp_sizes);
  c9_mystr_sizes[0] = 1;
  c9_mystr_sizes[1] = c9_b_tmp_sizes[1];
  c9_c_mystr = c9_mystr_sizes[0];
  c9_d_mystr = c9_mystr_sizes[1];
  c9_c_loop_ub = c9_b_tmp_sizes[0] * c9_b_tmp_sizes[1] - 1;
  for (c9_i625 = 0; c9_i625 <= c9_c_loop_ub; c9_i625++) {
    c9_mystr_data[c9_i625] = c9_b_tmp_data[c9_i625];
  }

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 82);
  c9_b_mystr_sizes[0] = 1;
  c9_b_mystr_sizes[1] = c9_mystr_sizes[1];
  c9_e_mystr = c9_b_mystr_sizes[0];
  c9_f_mystr = c9_b_mystr_sizes[1];
  c9_d_loop_ub = c9_mystr_sizes[0] * c9_mystr_sizes[1] - 1;
  for (c9_i626 = 0; c9_i626 <= c9_d_loop_ub; c9_i626++) {
    c9_b_mystr_data[c9_i626] = c9_mystr_data[c9_i626];
  }

  c9_ub_encStr2Arr(chartInstance, c9_b_mystr_data, c9_b_mystr_sizes, c9_dv91);
  for (c9_i627 = 0; c9_i627 < 256; c9_i627++) {
    c9_arrBML[c9_i627] = c9_dv91[c9_i627];
  }

  c9_updateDataWrittenToVector(chartInstance, 38U);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -82);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeOrigFunctionc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_dir, real_T
   c9_mag, real_T c9_arrBML[256])
{
  uint32_T c9_debug_family_var_map[9];
  int32_T c9_dirG_sizes[2];
  char_T c9_dirG_data[9];
  real_T c9_cDir;
  real_T c9_c;
  int32_T c9_mystr_sizes[2];
  char_T c9_mystr_data[138];
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  int32_T c9_dirG;
  int32_T c9_b_dirG;
  int32_T c9_i628;
  static char_T c9_cv64[2] = { 'U', 'P' };

  int32_T c9_c_dirG;
  int32_T c9_d_dirG;
  int32_T c9_i629;
  static char_T c9_cv65[4] = { 'D', 'O', 'W', 'N' };

  int32_T c9_e_dirG;
  int32_T c9_f_dirG;
  int32_T c9_i630;
  static char_T c9_cv66[5] = { 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_g_dirG;
  int32_T c9_h_dirG;
  int32_T c9_i631;
  static char_T c9_cv67[4] = { 'L', 'E', 'F', 'T' };

  int32_T c9_i_dirG;
  int32_T c9_j_dirG;
  int32_T c9_i632;
  static char_T c9_cv68[7] = { 'U', 'P', 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_k_dirG;
  int32_T c9_l_dirG;
  int32_T c9_i633;
  static char_T c9_cv69[6] = { 'U', 'P', 'L', 'E', 'F', 'T' };

  int32_T c9_m_dirG;
  int32_T c9_n_dirG;
  int32_T c9_i634;
  static char_T c9_cv70[9] = { 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T' };

  int32_T c9_o_dirG;
  int32_T c9_p_dirG;
  int32_T c9_i635;
  static char_T c9_cv71[8] = { 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T' };

  int32_T c9_q_dirG;
  int32_T c9_r_dirG;
  int32_T c9_i636;
  real_T c9_b_n;
  real_T c9_dv92[2];
  int32_T c9_iv1[2];
  int32_T c9_mystr;
  int32_T c9_b_mystr;
  int32_T c9_loop_ub;
  int32_T c9_i637;
  int32_T c9_i638;
  static char_T c9_cv72[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '%', 'd', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', '%', 's', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E',
    'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  char_T c9_u[120];
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  int32_T c9_u_sizes[2];
  int32_T c9_c_u;
  int32_T c9_d_u;
  int32_T c9_b_loop_ub;
  int32_T c9_i639;
  char_T c9_u_data[9];
  const mxArray *c9_c_y = NULL;
  int32_T c9_tmp_sizes[2];
  char_T c9_tmp_data[138];
  int32_T c9_c_mystr;
  int32_T c9_d_mystr;
  int32_T c9_c_loop_ub;
  int32_T c9_i640;
  int32_T c9_b_mystr_sizes[2];
  int32_T c9_e_mystr;
  int32_T c9_f_mystr;
  int32_T c9_d_loop_ub;
  int32_T c9_i641;
  char_T c9_b_mystr_data[138];
  real_T c9_dv93[256];
  int32_T c9_i642;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_kc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_dirG_data, (const int32_T *)
    &c9_dirG_sizes, NULL, 0, 0, (void *)c9_tc_sf_marshallOut, (void *)
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_cDir, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c9_mystr_data, (const int32_T *)
    &c9_mystr_sizes, NULL, 0, 3, (void *)c9_sc_sf_marshallOut, (void *)
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_dir, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_mag, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_arrBML, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 2);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 5);
  guard1 = false;
  if (CV_EML_COND(3, 1, 0, 0.0 < c9_dir)) {
    if (CV_EML_COND(3, 1, 1, c9_dir <= 24.0)) {
      CV_EML_MCDC(3, 1, 0, true);
      CV_EML_IF(3, 1, 0, true);
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 6);
      c9_dirG_sizes[0] = 1;
      c9_dirG_sizes[1] = 2;
      c9_dirG = c9_dirG_sizes[0];
      c9_b_dirG = c9_dirG_sizes[1];
      for (c9_i628 = 0; c9_i628 < 2; c9_i628++) {
        c9_dirG_data[c9_i628] = c9_cv64[c9_i628];
      }

      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 7);
      c9_cDir = 2.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(3, 1, 0, false);
    CV_EML_IF(3, 1, 0, false);
    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 8);
    guard2 = false;
    if (CV_EML_COND(3, 1, 2, 25.0 < c9_dir)) {
      if (CV_EML_COND(3, 1, 3, c9_dir <= 49.0)) {
        CV_EML_MCDC(3, 1, 1, true);
        CV_EML_IF(3, 1, 1, true);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 9);
        c9_dirG_sizes[0] = 1;
        c9_dirG_sizes[1] = 4;
        c9_c_dirG = c9_dirG_sizes[0];
        c9_d_dirG = c9_dirG_sizes[1];
        for (c9_i629 = 0; c9_i629 < 4; c9_i629++) {
          c9_dirG_data[c9_i629] = c9_cv65[c9_i629];
        }

        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 10);
        c9_cDir = 4.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(3, 1, 1, false);
      CV_EML_IF(3, 1, 1, false);
      _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 11);
      guard3 = false;
      if (CV_EML_COND(3, 1, 4, 50.0 < c9_dir)) {
        if (CV_EML_COND(3, 1, 5, c9_dir <= 74.0)) {
          CV_EML_MCDC(3, 1, 2, true);
          CV_EML_IF(3, 1, 2, true);
          _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 12);
          c9_dirG_sizes[0] = 1;
          c9_dirG_sizes[1] = 5;
          c9_e_dirG = c9_dirG_sizes[0];
          c9_f_dirG = c9_dirG_sizes[1];
          for (c9_i630 = 0; c9_i630 < 5; c9_i630++) {
            c9_dirG_data[c9_i630] = c9_cv66[c9_i630];
          }

          _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 13);
          c9_cDir = 5.0;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(3, 1, 2, false);
        CV_EML_IF(3, 1, 2, false);
        _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 14);
        guard4 = false;
        if (CV_EML_COND(3, 1, 6, 75.0 < c9_dir)) {
          if (CV_EML_COND(3, 1, 7, c9_dir <= 99.0)) {
            CV_EML_MCDC(3, 1, 3, true);
            CV_EML_IF(3, 1, 3, true);
            _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 15);
            c9_dirG_sizes[0] = 1;
            c9_dirG_sizes[1] = 4;
            c9_g_dirG = c9_dirG_sizes[0];
            c9_h_dirG = c9_dirG_sizes[1];
            for (c9_i631 = 0; c9_i631 < 4; c9_i631++) {
              c9_dirG_data[c9_i631] = c9_cv67[c9_i631];
            }

            _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 16);
            c9_cDir = 4.0;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4 == true) {
          CV_EML_MCDC(3, 1, 3, false);
          CV_EML_IF(3, 1, 3, false);
          _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 17);
          guard5 = false;
          if (CV_EML_COND(3, 1, 8, 100.0 < c9_dir)) {
            if (CV_EML_COND(3, 1, 9, c9_dir <= 107.0)) {
              CV_EML_MCDC(3, 1, 4, true);
              CV_EML_IF(3, 1, 4, true);
              _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 18);
              c9_dirG_sizes[0] = 1;
              c9_dirG_sizes[1] = 7;
              c9_i_dirG = c9_dirG_sizes[0];
              c9_j_dirG = c9_dirG_sizes[1];
              for (c9_i632 = 0; c9_i632 < 7; c9_i632++) {
                c9_dirG_data[c9_i632] = c9_cv68[c9_i632];
              }

              _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 19);
              c9_cDir = 7.0;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }

          if (guard5 == true) {
            CV_EML_MCDC(3, 1, 4, false);
            CV_EML_IF(3, 1, 4, false);
            _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 20);
            guard6 = false;
            if (CV_EML_COND(3, 1, 10, 108.0 < c9_dir)) {
              if (CV_EML_COND(3, 1, 11, c9_dir <= 115.0)) {
                CV_EML_MCDC(3, 1, 5, true);
                CV_EML_IF(3, 1, 5, true);
                _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 21);
                c9_dirG_sizes[0] = 1;
                c9_dirG_sizes[1] = 6;
                c9_k_dirG = c9_dirG_sizes[0];
                c9_l_dirG = c9_dirG_sizes[1];
                for (c9_i633 = 0; c9_i633 < 6; c9_i633++) {
                  c9_dirG_data[c9_i633] = c9_cv69[c9_i633];
                }

                _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 22);
                c9_cDir = 6.0;
              } else {
                guard6 = true;
              }
            } else {
              guard6 = true;
            }

            if (guard6 == true) {
              CV_EML_MCDC(3, 1, 5, false);
              CV_EML_IF(3, 1, 5, false);
              _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 23);
              guard7 = false;
              if (CV_EML_COND(3, 1, 12, 116.0 < c9_dir)) {
                if (CV_EML_COND(3, 1, 13, c9_dir <= 124.0)) {
                  CV_EML_MCDC(3, 1, 6, true);
                  CV_EML_IF(3, 1, 6, true);
                  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 24);
                  c9_dirG_sizes[0] = 1;
                  c9_dirG_sizes[1] = 9;
                  c9_m_dirG = c9_dirG_sizes[0];
                  c9_n_dirG = c9_dirG_sizes[1];
                  for (c9_i634 = 0; c9_i634 < 9; c9_i634++) {
                    c9_dirG_data[c9_i634] = c9_cv70[c9_i634];
                  }

                  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 25);
                  c9_cDir = 9.0;
                } else {
                  guard7 = true;
                }
              } else {
                guard7 = true;
              }

              if (guard7 == true) {
                CV_EML_MCDC(3, 1, 6, false);
                CV_EML_IF(3, 1, 6, false);
                _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 26);
                guard8 = false;
                if (CV_EML_COND(3, 1, 14, 125.0 < c9_dir)) {
                  if (CV_EML_COND(3, 1, 15, c9_dir <= 132.0)) {
                    CV_EML_MCDC(3, 1, 7, true);
                    CV_EML_IF(3, 1, 7, true);
                    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 27);
                    c9_dirG_sizes[0] = 1;
                    c9_dirG_sizes[1] = 8;
                    c9_o_dirG = c9_dirG_sizes[0];
                    c9_p_dirG = c9_dirG_sizes[1];
                    for (c9_i635 = 0; c9_i635 < 8; c9_i635++) {
                      c9_dirG_data[c9_i635] = c9_cv71[c9_i635];
                    }

                    _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 28);
                    c9_cDir = 8.0;
                  } else {
                    guard8 = true;
                  }
                } else {
                  guard8 = true;
                }

                if (guard8 == true) {
                  CV_EML_MCDC(3, 1, 7, false);
                  CV_EML_IF(3, 1, 7, false);
                  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 30);
                  c9_dirG_sizes[0] = 1;
                  c9_dirG_sizes[1] = 4;
                  c9_q_dirG = c9_dirG_sizes[0];
                  c9_r_dirG = c9_dirG_sizes[1];
                  for (c9_i636 = 0; c9_i636 < 4; c9_i636++) {
                    c9_dirG_data[c9_i636] = c9_cv67[c9_i636];
                  }

                  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 31);
                  c9_cDir = 4.0;
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 33);
  c9_c = c9_countDigits(chartInstance, c9_mag);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 35);
  c9_b_n = (125.0 + c9_c) + c9_cDir;
  c9_dv92[0] = 1.0;
  c9_dv92[1] = c9_b_n;
  c9_mystr_sizes[0] = 1;
  c9_iv1[0] = 1;
  c9_iv1[1] = (int32_T)c9_dv92[1];
  c9_mystr_sizes[1] = c9_iv1[1];
  c9_mystr = c9_mystr_sizes[0];
  c9_b_mystr = c9_mystr_sizes[1];
  c9_loop_ub = (int32_T)c9_dv92[1] - 1;
  for (c9_i637 = 0; c9_i637 <= c9_loop_ub; c9_i637++) {
    c9_mystr_data[c9_i637] = ' ';
  }

  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 36);
  for (c9_i638 = 0; c9_i638 < 120; c9_i638++) {
    c9_u[c9_i638] = c9_cv72[c9_i638];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  c9_b_u = c9_mag;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  c9_u_sizes[0] = 1;
  c9_u_sizes[1] = c9_dirG_sizes[1];
  c9_c_u = c9_u_sizes[0];
  c9_d_u = c9_u_sizes[1];
  c9_b_loop_ub = c9_dirG_sizes[0] * c9_dirG_sizes[1] - 1;
  for (c9_i639 = 0; c9_i639 <= c9_b_loop_ub; c9_i639++) {
    c9_u_data[c9_i639] = c9_dirG_data[c9_i639];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_u_data, 10, 0U, 1U, 0U, 2,
    c9_u_sizes[0], c9_u_sizes[1]), false);
  c9_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                      (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c9_y,
                       14, c9_b_y, 14, c9_c_y), "sprintf", c9_tmp_data,
                      c9_tmp_sizes);
  c9_mystr_sizes[0] = 1;
  c9_mystr_sizes[1] = c9_tmp_sizes[1];
  c9_c_mystr = c9_mystr_sizes[0];
  c9_d_mystr = c9_mystr_sizes[1];
  c9_c_loop_ub = c9_tmp_sizes[0] * c9_tmp_sizes[1] - 1;
  for (c9_i640 = 0; c9_i640 <= c9_c_loop_ub; c9_i640++) {
    c9_mystr_data[c9_i640] = c9_tmp_data[c9_i640];
  }

  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, 37);
  c9_b_mystr_sizes[0] = 1;
  c9_b_mystr_sizes[1] = c9_mystr_sizes[1];
  c9_e_mystr = c9_b_mystr_sizes[0];
  c9_f_mystr = c9_b_mystr_sizes[1];
  c9_d_loop_ub = c9_mystr_sizes[0] * c9_mystr_sizes[1] - 1;
  for (c9_i641 = 0; c9_i641 <= c9_d_loop_ub; c9_i641++) {
    c9_b_mystr_data[c9_i641] = c9_mystr_data[c9_i641];
  }

  c9_ub_encStr2Arr(chartInstance, c9_b_mystr_data, c9_b_mystr_sizes, c9_dv93);
  for (c9_i642 = 0; c9_i642 < 256; c9_i642++) {
    c9_arrBML[c9_i642] = c9_dv93[c9_i642];
  }

  c9_updateDataWrittenToVector(chartInstance, 39U);
  _SFD_EML_CALL(3U, chartInstance->c9_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_insertQueueLowc9_Demo_EP_IdleRand
  (SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T c9_bmls[1280],
   real_T c9_myBML[256], real_T c9_newBmls[1280])
{
  uint32_T c9_debug_family_var_map[8];
  real_T c9_full;
  real_T c9_t[256];
  real_T c9_i;
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i643;
  static real_T c9_varargin_2[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c9_i644;
  int32_T c9_i645;
  int32_T c9_i646;
  int32_T c9_i647;
  int32_T c9_i648;
  int32_T c9_b_i;
  int32_T c9_c_i;
  int32_T c9_i649;
  real_T c9_varargin_1[256];
  boolean_T c9_p;
  boolean_T c9_b_p;
  int32_T c9_k;
  real_T c9_b_k;
  real_T c9_x1;
  real_T c9_x2;
  boolean_T c9_c_p;
  int32_T c9_d_i;
  int32_T c9_i650;
  int32_T c9_i651;
  real_T c9_b_bmls[256];
  int32_T c9_i652;
  int32_T c9_i653;
  real_T c9_c_bmls[256];
  int32_T c9_i654;
  int32_T c9_i655;
  real_T c9_d_bmls[256];
  int32_T c9_i656;
  int32_T c9_i657;
  int32_T c9_i658;
  int32_T exitg1;
  boolean_T exitg2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_lc_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_full, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_t, 1U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_bmls, 5U, c9_vc_sf_marshallOut,
    c9_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myBML, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_newBmls, 7U, c9_vc_sf_marshallOut,
    c9_h_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 2);
  c9_full = 1.0;
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 3);
  for (c9_i643 = 0; c9_i643 < 256; c9_i643++) {
    c9_t[c9_i643] = c9_varargin_2[c9_i643];
  }

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 4);
  for (c9_i644 = 0; c9_i644 < 256; c9_i644++) {
    c9_newBmls[c9_i644] = c9_t[c9_i644];
  }

  for (c9_i645 = 0; c9_i645 < 256; c9_i645++) {
    c9_newBmls[c9_i645 + 256] = c9_t[c9_i645];
  }

  for (c9_i646 = 0; c9_i646 < 256; c9_i646++) {
    c9_newBmls[c9_i646 + 512] = c9_t[c9_i646];
  }

  for (c9_i647 = 0; c9_i647 < 256; c9_i647++) {
    c9_newBmls[c9_i647 + 768] = c9_t[c9_i647];
  }

  for (c9_i648 = 0; c9_i648 < 256; c9_i648++) {
    c9_newBmls[c9_i648 + 1024] = c9_t[c9_i648];
  }

  c9_updateDataWrittenToVector(chartInstance, 40U);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 5);
  c9_i = 1.0;
  c9_b_i = 0;
  do {
    exitg1 = 0;
    if (c9_b_i < 5) {
      c9_i = 1.0 + (real_T)c9_b_i;
      CV_EML_FOR(7, 1, 0, 1);
      _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 6);
      c9_c_i = (int32_T)c9_i - 1;
      for (c9_i649 = 0; c9_i649 < 256; c9_i649++) {
        c9_varargin_1[c9_i649] = c9_bmls[c9_i649 + (c9_c_i << 8)];
      }

      c9_p = false;
      c9_b_p = true;
      c9_k = 0;
      exitg2 = false;
      while ((exitg2 == false) && (c9_k < 256)) {
        c9_b_k = 1.0 + (real_T)c9_k;
        c9_x1 = c9_varargin_1[(int32_T)c9_b_k - 1];
        c9_x2 = c9_varargin_2[(int32_T)c9_b_k - 1];
        c9_c_p = (c9_x1 == c9_x2);
        if (!c9_c_p) {
          c9_b_p = false;
          exitg2 = true;
        } else {
          c9_k++;
        }
      }

      if (!c9_b_p) {
      } else {
        c9_p = true;
      }

      if (CV_EML_IF(7, 1, 0, c9_p)) {
        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 8);
        c9_d_i = (int32_T)c9_i - 1;
        for (c9_i650 = 0; c9_i650 < 256; c9_i650++) {
          c9_bmls[c9_i650 + (c9_d_i << 8)] = c9_myBML[c9_i650];
        }

        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 9);
        c9_full = 0.0;
        _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 10);
        exitg1 = 1;
      } else {
        c9_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(7, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 13);
  if (CV_EML_IF(7, 1, 1, c9_full != 0.0)) {
    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 15);
    for (c9_i651 = 0; c9_i651 < 256; c9_i651++) {
      c9_b_bmls[c9_i651] = c9_bmls[c9_i651 + 256];
    }

    for (c9_i652 = 0; c9_i652 < 256; c9_i652++) {
      c9_bmls[c9_i652] = c9_b_bmls[c9_i652];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 16);
    for (c9_i653 = 0; c9_i653 < 256; c9_i653++) {
      c9_c_bmls[c9_i653] = c9_bmls[c9_i653 + 512];
    }

    for (c9_i654 = 0; c9_i654 < 256; c9_i654++) {
      c9_bmls[c9_i654 + 256] = c9_c_bmls[c9_i654];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 17);
    for (c9_i655 = 0; c9_i655 < 256; c9_i655++) {
      c9_d_bmls[c9_i655] = c9_bmls[c9_i655 + 768];
    }

    for (c9_i656 = 0; c9_i656 < 256; c9_i656++) {
      c9_bmls[c9_i656 + 512] = c9_d_bmls[c9_i656];
    }

    _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 18);
    for (c9_i657 = 0; c9_i657 < 256; c9_i657++) {
      c9_bmls[c9_i657 + 1024] = c9_myBML[c9_i657];
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, 20);
  for (c9_i658 = 0; c9_i658 < 1280; c9_i658++) {
    c9_newBmls[c9_i658] = c9_bmls[c9_i658];
  }

  c9_updateDataWrittenToVector(chartInstance, 40U);
  _SFD_EML_CALL(7U, chartInstance->c9_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_blanks(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T
                      c9_b_n, char_T c9_b_data[], int32_T c9_b_sizes[2])
{
  real_T c9_dv94[2];
  int32_T c9_iv2[2];
  int32_T c9_b;
  int32_T c9_b_b;
  int32_T c9_loop_ub;
  int32_T c9_i659;
  (void)chartInstance;
  c9_dv94[0] = 1.0;
  c9_dv94[1] = c9_b_n;
  c9_b_sizes[0] = 1;
  c9_iv2[0] = 1;
  c9_iv2[1] = (int32_T)c9_dv94[1];
  c9_b_sizes[1] = c9_iv2[1];
  c9_b = c9_b_sizes[0];
  c9_b_b = c9_b_sizes[1];
  c9_loop_ub = (int32_T)c9_dv94[1] - 1;
  for (c9_i659 = 0; c9_i659 <= c9_loop_ub; c9_i659++) {
    c9_b_data[c9_i659] = ' ';
  }
}

void sf_exported_user_c9_Demo_EP_IdleRand_gazeFollowUserMove(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_gazeFollowUserMovec9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_gazeBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeFunction(SimStruct *c9_S,
  real_T c9_dir, real_T c9_mag, real_T c9_p, real_T c9_arrBML[256])
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeFunctionc9_Demo_EP_IdleRand(chartInstance, c9_dir, c9_mag, c9_p,
    c9_arrBML);
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeInterestedTable(SimStruct
  *c9_S, real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeInterestedTablec9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_gazeBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeOrigFunction(SimStruct *c9_S,
  real_T c9_dir, real_T c9_mag, real_T c9_arrBML[256])
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeOrigFunctionc9_Demo_EP_IdleRand(chartInstance, c9_dir, c9_mag,
    c9_arrBML);
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTable(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeTablec9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_gazeBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTableExtrovert(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeTableExtrovertc9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_gazeBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Demo_EP_IdleRand_idleGazeTableIntrovert(SimStruct *c9_S,
  real_T c9_bmlID, real_T *c9_p, real_T c9_gazeBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_idleGazeTableIntrovertc9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_gazeBML);
  *c9_p = c9_b_p;
}

void sf_exported_user_c9_Demo_EP_IdleRand_insertQueueLow(SimStruct *c9_S, real_T
  c9_bmls[1280], real_T c9_myBML[256], real_T c9_newBmls[1280])
{
  int32_T c9_i660;
  real_T c9_b_bmls[1280];
  int32_T c9_i661;
  real_T c9_b_myBML[256];
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  for (c9_i660 = 0; c9_i660 < 1280; c9_i660++) {
    c9_b_bmls[c9_i660] = c9_bmls[c9_i660];
  }

  for (c9_i661 = 0; c9_i661 < 256; c9_i661++) {
    c9_b_myBML[c9_i661] = c9_myBML[c9_i661];
  }

  c9_insertQueueLowc9_Demo_EP_IdleRand(chartInstance, c9_b_bmls, c9_b_myBML,
    c9_newBmls);
}

void sf_exported_user_c9_Demo_EP_IdleRand_setPersonalityFactor(SimStruct *c9_S,
  real_T c9_p, real_T *c9_m, real_T *c9_a, real_T *c9_h)
{
  real_T c9_b_h;
  real_T c9_b_a;
  real_T c9_b_m;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_setPersonalityFactorc9_Demo_EP_IdleRand(chartInstance, c9_p, &c9_b_m,
    &c9_b_a, &c9_b_h);
  *c9_m = c9_b_m;
  *c9_a = c9_b_a;
  *c9_h = c9_b_h;
}

void sf_exported_user_c9_Demo_EP_IdleRand_successTable(SimStruct *c9_S, real_T
  c9_bmlID, real_T *c9_p, real_T c9_poseBML[256])
{
  real_T c9_b_p;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo)->chartInstance;
  c9_successTablec9_Demo_EP_IdleRand(chartInstance, c9_bmlID, &c9_b_p,
    c9_poseBML);
  *c9_p = c9_b_p;
}

static const mxArray *c9_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int8_T c9_o_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int8_T c9_y;
  int8_T c9_i662;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i662, 1, 2, 0U, 0, 0U, 0);
  c9_y = c9_i662;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_secs;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int8_T c9_y;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_secs = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_secs), &c9_thisId);
  sf_mex_destroy(&c9_secs);
  *(int8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_p_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i663;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i663, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i663;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_q_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_stateGazeIde, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateGazeIde),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateGazeIde);
  return c9_y;
}

static uint8_T c9_r_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_tp_stateGazeIde;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_b_tp_stateGazeIde = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateGazeIde),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateGazeIde);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i664;
  real_T c9_b_inData[3];
  int32_T c9_i665;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i664 = 0; c9_i664 < 3; c9_i664++) {
    c9_b_inData[c9_i664] = (*(real_T (*)[3])c9_inData)[c9_i664];
  }

  for (c9_i665 = 0; c9_i665 < 3; c9_i665++) {
    c9_u[c9_i665] = c9_b_inData[c9_i665];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_s_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_mutContF, const char_T *c9_identifier,
  real_T c9_y[3])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_mutContF), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_b_mutContF);
}

static void c9_t_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3])
{
  real_T c9_dv95[3];
  int32_T c9_i666;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv95, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c9_i666 = 0; c9_i666 < 3; c9_i666++) {
    c9_y[c9_i666] = c9_dv95[c9_i666];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_mutContF;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i667;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_b_mutContF = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_mutContF), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_b_mutContF);
  for (c9_i667 = 0; c9_i667 < 3; c9_i667++) {
    (*(real_T (*)[3])c9_outData)[c9_i667] = c9_y[c9_i667];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i668;
  real_T c9_b_inData[4];
  int32_T c9_i669;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i668 = 0; c9_i668 < 4; c9_i668++) {
    c9_b_inData[c9_i668] = (*(real_T (*)[4])c9_inData)[c9_i668];
  }

  for (c9_i669 = 0; c9_i669 < 4; c9_i669++) {
    c9_u[c9_i669] = c9_b_inData[c9_i669];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_u_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_avertContF, const char_T *c9_identifier,
  real_T c9_y[4])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_avertContF), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_b_avertContF);
}

static void c9_v_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4])
{
  real_T c9_dv96[4];
  int32_T c9_i670;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv96, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c9_i670 = 0; c9_i670 < 4; c9_i670++) {
    c9_y[c9_i670] = c9_dv96[c9_i670];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_avertContF;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[4];
  int32_T c9_i671;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_b_avertContF = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_avertContF), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_b_avertContF);
  for (c9_i671 = 0; c9_i671 < 4; c9_i671++) {
    (*(real_T (*)[4])c9_outData)[c9_i671] = c9_y[c9_i671];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i672;
  real_T c9_b_inData[25];
  int32_T c9_i673;
  real_T c9_u[25];
  const mxArray *c9_y = NULL;
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i672 = 0; c9_i672 < 25; c9_i672++) {
    c9_b_inData[c9_i672] = (*(real_T (*)[25])c9_inData)[c9_i672];
  }

  for (c9_i673 = 0; c9_i673 < 25; c9_i673++) {
    c9_u[c9_i673] = c9_b_inData[c9_i673];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 25), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint32_T c9_w_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_method, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_method),
    &c9_thisId);
  sf_mex_destroy(&c9_b_method);
  return c9_y;
}

static uint32_T c9_x_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u1;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_method_not_empty = false;
  } else {
    chartInstance->c9_method_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u1, 1, 7, 0U, 0, 0U, 0);
    c9_y = c9_u1;
  }

  sf_mex_destroy(&c9_u);
  return c9_y;
}

static uint32_T c9_y_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state),
    &c9_thisId);
  sf_mex_destroy(&c9_d_state);
  return c9_y;
}

static uint32_T c9_ab_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u2;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_state_not_empty = false;
  } else {
    chartInstance->c9_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u2, 1, 7, 0U, 0, 0U, 0);
    c9_y = c9_u2;
  }

  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_bb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[625])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_cb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[625])
{
  uint32_T c9_uv8[625];
  int32_T c9_i674;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_c_state_not_empty = false;
  } else {
    chartInstance->c9_c_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv8, 1, 7, 0U, 1, 0U, 1, 625);
    for (c9_i674 = 0; c9_i674 < 625; c9_i674++) {
      c9_y[c9_i674] = c9_uv8[c9_i674];
    }
  }

  sf_mex_destroy(&c9_u);
}

static void c9_db_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
  uint32_T c9_y[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_eb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  uint32_T c9_y[2])
{
  uint32_T c9_uv9[2];
  int32_T c9_i675;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_b_state_not_empty = false;
  } else {
    chartInstance->c9_b_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv9, 1, 7, 0U, 1, 0U, 1, 2);
    for (c9_i675 = 0; c9_i675 < 2; c9_i675++) {
      c9_y[c9_i675] = c9_uv9[c9_i675];
    }
  }

  sf_mex_destroy(&c9_u);
}

static uint32_T c9_fb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_gb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_temporalCounter_i1), &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i1);
  return c9_y;
}

static uint32_T c9_gb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u3;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u3, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u3;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_hb_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_ib_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_ib_emlrt_marshallIn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  (void)c9_parentId;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_updateDataWrittenToVector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 40, 1, 0)] = true;
}

static void c9_errorIfDataNotWrittenToFcn(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 40, 1,
    0)]);
}

static void c9_b_twister_state_vector(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_mt[625], real_T c9_seed)
{
  uint32_T c9_r;
  int32_T c9_mti;
  real_T c9_b_mti;
  real_T c9_d6;
  uint32_T c9_u4;
  (void)chartInstance;
  (void)c9_seed;
  c9_r = 5489U;
  c9_mt[0] = 5489U;
  for (c9_mti = 0; c9_mti < 623; c9_mti++) {
    c9_b_mti = 2.0 + (real_T)c9_mti;
    c9_d6 = muDoubleScalarRound(c9_b_mti - 1.0);
    if (c9_d6 < 4.294967296E+9) {
      if (c9_d6 >= 0.0) {
        c9_u4 = (uint32_T)c9_d6;
      } else {
        c9_u4 = 0U;
      }
    } else if (c9_d6 >= 4.294967296E+9) {
      c9_u4 = MAX_uint32_T;
    } else {
      c9_u4 = 0U;
    }

    c9_r = (c9_r ^ c9_r >> 30U) * 1812433253U + c9_u4;
    c9_mt[(int32_T)c9_b_mti - 1] = c9_r;
  }

  c9_mt[624] = 624U;
}

static real_T c9_c_eml_rand_mt19937ar(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_d_state[625])
{
  int32_T c9_i676;
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
  boolean_T c9_b4;
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
    for (c9_i676 = 0; c9_i676 < 2; c9_i676++) {
      c9_u[c9_i676] = 0U;
    }

    for (c9_j = 0; c9_j < 2; c9_j++) {
      c9_b_j = 1.0 + (real_T)c9_j;
      c9_mti = c9_d_state[624] + 1U;
      if ((real_T)c9_mti >= 625.0) {
        for (c9_kk = 0; c9_kk < 227; c9_kk++) {
          c9_b_kk = 1.0 + (real_T)c9_kk;
          c9_y = (c9_d_state[(int32_T)c9_b_kk - 1] & 2147483648U) | (c9_d_state
            [(int32_T)(c9_b_kk + 1.0) - 1] & 2147483647U);
          c9_b_y = c9_y;
          c9_c_y = c9_b_y;
          if ((real_T)(c9_c_y & 1U) == 0.0) {
            c9_c_y >>= 1U;
          } else {
            c9_c_y = c9_c_y >> 1U ^ 2567483615U;
          }

          c9_d_state[(int32_T)c9_b_kk - 1] = c9_d_state[(int32_T)(c9_b_kk +
            397.0) - 1] ^ c9_c_y;
        }

        for (c9_c_kk = 0; c9_c_kk < 396; c9_c_kk++) {
          c9_b_kk = 228.0 + (real_T)c9_c_kk;
          c9_y = (c9_d_state[(int32_T)c9_b_kk - 1] & 2147483648U) | (c9_d_state
            [(int32_T)(c9_b_kk + 1.0) - 1] & 2147483647U);
          c9_d_y = c9_y;
          c9_e_y = c9_d_y;
          if ((real_T)(c9_e_y & 1U) == 0.0) {
            c9_e_y >>= 1U;
          } else {
            c9_e_y = c9_e_y >> 1U ^ 2567483615U;
          }

          c9_d_state[(int32_T)c9_b_kk - 1] = c9_d_state[(int32_T)((c9_b_kk + 1.0)
            - 228.0) - 1] ^ c9_e_y;
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
        (int32_T)c9_mti, 1, 625, 1, 0) - 1];
      c9_d_state[624] = c9_mti;
      c9_y ^= c9_y >> 11U;
      c9_y ^= c9_y << 7U & 2636928640U;
      c9_y ^= c9_y << 15U & 4022730752U;
      c9_y ^= c9_y >> 18U;
      c9_u[(int32_T)c9_b_j - 1] = c9_y;
    }

    c9_u[0] >>= 5U;
    c9_u[1] >>= 6U;
    c9_b_r = 1.1102230246251565E-16 * ((real_T)c9_u[0] * 6.7108864E+7 + (real_T)
      c9_u[1]);
    if (c9_b_r == 0.0) {
      guard1 = false;
      if ((real_T)c9_d_state[624] >= 1.0) {
        if ((real_T)c9_d_state[624] < 625.0) {
          c9_b4 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c9_b4 = false;
      }

      c9_isvalid = c9_b4;
      if (c9_isvalid) {
        c9_isvalid = false;
        c9_k = 0;
        exitg2 = false;
        while ((exitg2 == false) && (c9_k + 1 < 625)) {
          if ((real_T)c9_d_state[c9_k] == 0.0) {
            c9_a = c9_k + 1;
            c9_b_a = c9_a;
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

static void c9_b_log(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance, real_T *
                     c9_x)
{
  if (*c9_x < 0.0) {
    c9_b_eml_error(chartInstance);
  }

  *c9_x = muDoubleScalarLog(*c9_x);
}

static real_T c9_get_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1194) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_BML_address)[c9_b];
}

static void c9_set_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1194) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_BML_address)[c9_b] = c9_c;
}

static real_T *c9_access_BML(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#1194) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_BML_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static real_T c9_get_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1157) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_BOREDOM_THRESHOLD_address;
}

static void c9_set_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1157) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_BOREDOM_THRESHOLD_address = c9_c;
}

static real_T *c9_access_BOREDOM_THRESHOLD(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#1157) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_BOREDOM_THRESHOLD_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#1164) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_GUI_address;
}

static void c9_set_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#1164) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_GUI_address = c9_c;
}

static real_T *c9_access_GAZE_GUI(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#1164) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_GUI_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#1163) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_SOFTEYE_address;
}

static void c9_set_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#1163) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_SOFTEYE_address = c9_c;
}

static real_T *c9_access_GAZE_SOFTEYE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c9_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#1163) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_SOFTEYE_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#1165) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_USER_HAND_address;
}

static void c9_set_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#1165) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_USER_HAND_address = c9_c;
}

static real_T *c9_access_GAZE_USER_HAND(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#1165) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_USER_HAND_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1166) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_WIN_address;
}

static void c9_set_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1166) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_WIN_address = c9_c;
}

static real_T *c9_access_GAZE_WIN(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1166) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_WIN_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c9_c;
}

static real_T c9_get_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1188) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_P_address;
}

static void c9_set_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
                     uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1188) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_P_address = c9_c;
}

static real_T *c9_access_P(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c9_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#1188) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_P_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1171) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_BEFORE_address;
}

static void c9_set_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1171) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_BEFORE_address = c9_c;
}

static real_T *c9_access_STATE_BEFORE(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#1171) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_BEFORE_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1191) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_GO_address;
}

static void c9_set_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1191) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_GO_address = c9_c;
}

static real_T *c9_access_STATE_GO(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c9_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#1191) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_GO_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1172) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_OVER_address;
}

static void c9_set_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1172) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_OVER_address = c9_c;
}

static real_T *c9_access_STATE_OVER(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#1172) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_OVER_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1173) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_READY_address;
}

static void c9_set_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1173) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_READY_address = c9_c;
}

static real_T *c9_access_STATE_READY(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#1173) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_READY_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c9_c;
}

static real_T c9_get_avert(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1170) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_avert_address;
}

static void c9_set_avert(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1170) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_avert_address = c9_c;
}

static real_T *c9_access_avert(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1170) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_avert_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c9_c;
}

static real_T c9_get_avertH(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#1203) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_avertH_address;
}

static void c9_set_avertH(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#1203) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_avertH_address = c9_c;
}

static real_T *c9_access_avertH(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c9_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#1203) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_avertH_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c9_c;
}

static real_T c9_get_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c9_b);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1186) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c9_bmlsL_address)[c9_b];
}

static void c9_set_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c9_b);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1186) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c9_bmlsL_address)[c9_b] = c9_c;
}

static real_T *c9_access_bmlsL(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c9_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#1186) in the initialization routine of the chart.\n");
  }

  c9_c = *chartInstance->c9_bmlsL_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c9_c;
}

static real_T c9_get_boredom(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1156) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_boredom_address;
}

static void c9_set_boredom(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1156) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_boredom_address = c9_c;
}

static real_T *c9_access_boredom(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#1156) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_boredom_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c9_c;
}

static real_T c9_get_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c9_b);
  if (chartInstance->c9_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1192) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_changeFlag_address;
}

static void c9_set_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c9_b);
  if (chartInstance->c9_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1192) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_changeFlag_address = c9_c;
}

static real_T *c9_access_changeFlag(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c9_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#1192) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_changeFlag_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c9_c;
}

static real_T c9_get_fileID(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c9_b);
  if (chartInstance->c9_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1190) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_fileID_address;
}

static void c9_set_fileID(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c9_b);
  if (chartInstance->c9_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1190) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_fileID_address = c9_c;
}

static real_T *c9_access_fileID(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c9_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#1190) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_fileID_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c9_c;
}

static real_T c9_get_gazing(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1162) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_gazing_address;
}

static void c9_set_gazing(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1162) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_gazing_address = c9_c;
}

static real_T *c9_access_gazing(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1162) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_gazing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c9_c;
}

static real_T c9_get_interest(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1160) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_interest_address;
}

static void c9_set_interest(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1160) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_interest_address = c9_c;
}

static real_T *c9_access_interest(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#1160) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_interest_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c9_c;
}

static real_T c9_get_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c9_b);
  if (chartInstance->c9_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1187) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_pr_address;
}

static void c9_set_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
                      uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c9_b);
  if (chartInstance->c9_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1187) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_pr_address = c9_c;
}

static real_T *c9_access_pr(SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance,
  uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c9_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#1187) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_pr_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c9_c;
}

static real_T c9_get_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1158) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randAvertGazeChance_address;
}

static void c9_set_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1158) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randAvertGazeChance_address = c9_c;
}

static real_T *c9_access_randAvertGazeChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#1158) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randAvertGazeChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c9_c;
}

static real_T c9_get_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#1161) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randGazeDur_address;
}

static void c9_set_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#1161) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randGazeDur_address = c9_c;
}

static real_T *c9_access_randGazeDur(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#1161) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randGazeDur_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c9_c;
}

static real_T c9_get_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 22, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1159) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randPoseChance_address;
}

static void c9_set_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 22, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1159) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randPoseChance_address = c9_c;
}

static real_T *c9_access_randPoseChance(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 22, NULL);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#1159) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randPoseChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 22, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info(SFc9_Demo_EP_IdleRandInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c9_BML_address, &chartInstance->c9_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c9_BOREDOM_THRESHOLD_address,
    &chartInstance->c9_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_GUI", (void **)
    &chartInstance->c9_GAZE_GUI_address, &chartInstance->c9_GAZE_GUI_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_SOFTEYE", (void **)
    &chartInstance->c9_GAZE_SOFTEYE_address,
    &chartInstance->c9_GAZE_SOFTEYE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_USER_HAND", (void **)
    &chartInstance->c9_GAZE_USER_HAND_address,
    &chartInstance->c9_GAZE_USER_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c9_GAZE_WIN_address, &chartInstance->c9_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c9_P_address, &chartInstance->c9_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c9_STATE_BEFORE_address,
    &chartInstance->c9_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c9_STATE_GO_address, &chartInstance->c9_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c9_STATE_OVER_address, &chartInstance->c9_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c9_STATE_READY_address, &chartInstance->c9_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c9_avert_address, &chartInstance->c9_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avertH", (void **)
    &chartInstance->c9_avertH_address, &chartInstance->c9_avertH_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c9_bmlsL_address, &chartInstance->c9_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c9_boredom_address, &chartInstance->c9_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c9_changeFlag_address, &chartInstance->c9_changeFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c9_fileID_address, &chartInstance->c9_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c9_gazing_address, &chartInstance->c9_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c9_interest_address, &chartInstance->c9_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c9_pr_address, &chartInstance->c9_pr_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c9_randAvertGazeChance_address,
    &chartInstance->c9_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randGazeDur", (void **)
    &chartInstance->c9_randGazeDur_address, &chartInstance->c9_randGazeDur_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c9_randPoseChance_address,
    &chartInstance->c9_randPoseChance_index);
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

void sf_c9_Demo_EP_IdleRand_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(813752712U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3224161768U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1395315312U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(907642131U);
}

mxArray *sf_c9_Demo_EP_IdleRand_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0ZzzTjkjOlvsa9HSW7j8vB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(25);
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
      pr[1] = (double)(3);
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
      pr[1] = (double)(4);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
      pr[1] = (double)(5);
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
      pr[0] = (double)(256);
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

mxArray *sf_c9_Demo_EP_IdleRand_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_Demo_EP_IdleRand_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_Demo_EP_IdleRand(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[116],T\"gameState\",},{M[3],M[259],T\"BMLl\",},{M[3],M[211],T\"CHANCEA\",},{M[3],M[207],T\"CHANCEM\",},{M[3],M[291],T\"aF\",},{M[3],M[203],T\"avertContChance\",},{M[3],M[214],T\"avertContF\",},{M[3],M[209],T\"avertDur\",},{M[3],M[234],T\"chanceO\",},{M[3],M[210],T\"gazeDir\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[204],T\"gazeGUIChance\",},{M[3],M[215],T\"gazeUserHandChance\",},{M[3],M[290],T\"hF\",},{M[3],M[289],T\"mF\",},{M[3],M[212],T\"magnitude\",},{M[3],M[205],T\"mutContChance\",},{M[3],M[206],T\"mutContF\",},{M[3],M[285],T\"mutDur\",},{M[3],M[266],T\"n\",},{M[3],M[265],T\"newBmlsL\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[213],T\"randHeadChance\",},{M[3],M[114],T\"randHeadDur\",},{M[3],M[115],T\"randHeadDurOver\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c9_Demo_EP_IdleRand\",},{M[8],M[99],T\"is_active_stateGazeIde\",},{M[8],M[100],T\"is_active_stateGazeWin\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[8],M[101],T\"is_active_stateGazeSoft\",},{M[9],M[99],T\"is_stateGazeIde\",},{M[9],M[100],T\"is_stateGazeWin\",},{M[9],M[101],T\"is_stateGazeSoft\",},{M[11],M[23],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[83],M[1]}}},{M[11],M[23],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M1x2[92 90],M[1]}}},{M[11],M[23],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x9[318 272 14 328 329 304 15 61 78],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 37, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_Demo_EP_IdleRand_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_EP_IdleRandMachineNumber_,
           9,
           32,
           37,
           0,
           80,
           1,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_EP_IdleRandMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_EP_IdleRandMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_EP_IdleRandMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(3,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(4,11,0,0,"interest");
          _SFD_SET_DATA_PROPS(5,11,0,0,"randGazeDur");
          _SFD_SET_DATA_PROPS(6,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(7,11,0,0,"GAZE_SOFTEYE");
          _SFD_SET_DATA_PROPS(8,11,0,0,"GAZE_GUI");
          _SFD_SET_DATA_PROPS(9,11,0,0,"GAZE_USER_HAND");
          _SFD_SET_DATA_PROPS(10,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(11,0,0,0,"randHeadDur");
          _SFD_SET_DATA_PROPS(12,0,0,0,"randHeadDurOver");
          _SFD_SET_DATA_PROPS(13,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(14,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(15,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(16,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(17,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(18,0,0,0,"avertContChance");
          _SFD_SET_DATA_PROPS(19,0,0,0,"gazeGUIChance");
          _SFD_SET_DATA_PROPS(20,0,0,0,"mutContChance");
          _SFD_SET_DATA_PROPS(21,0,0,0,"mutContF");
          _SFD_SET_DATA_PROPS(22,0,0,0,"CHANCEM");
          _SFD_SET_DATA_PROPS(23,0,0,0,"avertDur");
          _SFD_SET_DATA_PROPS(24,0,0,0,"gazeDir");
          _SFD_SET_DATA_PROPS(25,0,0,0,"CHANCEA");
          _SFD_SET_DATA_PROPS(26,0,0,0,"magnitude");
          _SFD_SET_DATA_PROPS(27,0,0,0,"randHeadChance");
          _SFD_SET_DATA_PROPS(28,0,0,0,"avertContF");
          _SFD_SET_DATA_PROPS(29,0,0,0,"gazeUserHandChance");
          _SFD_SET_DATA_PROPS(30,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(31,11,0,0,"pr");
          _SFD_SET_DATA_PROPS(32,11,0,0,"P");
          _SFD_SET_DATA_PROPS(33,0,0,0,"chanceO");
          _SFD_SET_DATA_PROPS(34,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(35,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(36,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(37,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(38,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(39,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(40,0,0,0,"n");
          _SFD_SET_DATA_PROPS(41,1,1,0,"randArray");
          _SFD_SET_DATA_PROPS(42,0,0,0,"mutDur");
          _SFD_SET_DATA_PROPS(43,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(44,0,0,0,"mF");
          _SFD_SET_DATA_PROPS(45,0,0,0,"hF");
          _SFD_SET_DATA_PROPS(46,0,0,0,"aF");
          _SFD_SET_DATA_PROPS(47,11,0,0,"avertH");
          _SFD_SET_DATA_PROPS(48,8,0,0,"");
          _SFD_SET_DATA_PROPS(49,9,0,0,"");
          _SFD_SET_DATA_PROPS(50,9,0,0,"");
          _SFD_SET_DATA_PROPS(51,9,0,0,"");
          _SFD_SET_DATA_PROPS(52,9,0,0,"");
          _SFD_SET_DATA_PROPS(53,8,0,0,"");
          _SFD_SET_DATA_PROPS(54,9,0,0,"");
          _SFD_SET_DATA_PROPS(55,9,0,0,"");
          _SFD_SET_DATA_PROPS(56,8,0,0,"");
          _SFD_SET_DATA_PROPS(57,9,0,0,"");
          _SFD_SET_DATA_PROPS(58,9,0,0,"");
          _SFD_SET_DATA_PROPS(59,8,0,0,"");
          _SFD_SET_DATA_PROPS(60,9,0,0,"");
          _SFD_SET_DATA_PROPS(61,9,0,0,"");
          _SFD_SET_DATA_PROPS(62,8,0,0,"");
          _SFD_SET_DATA_PROPS(63,9,0,0,"");
          _SFD_SET_DATA_PROPS(64,9,0,0,"");
          _SFD_SET_DATA_PROPS(65,8,0,0,"");
          _SFD_SET_DATA_PROPS(66,9,0,0,"");
          _SFD_SET_DATA_PROPS(67,9,0,0,"");
          _SFD_SET_DATA_PROPS(68,8,0,0,"");
          _SFD_SET_DATA_PROPS(69,9,0,0,"");
          _SFD_SET_DATA_PROPS(70,8,0,0,"");
          _SFD_SET_DATA_PROPS(71,8,0,0,"");
          _SFD_SET_DATA_PROPS(72,9,0,0,"");
          _SFD_SET_DATA_PROPS(73,8,0,0,"");
          _SFD_SET_DATA_PROPS(74,8,0,0,"");
          _SFD_SET_DATA_PROPS(75,8,0,0,"");
          _SFD_SET_DATA_PROPS(76,9,0,0,"");
          _SFD_SET_DATA_PROPS(77,8,0,0,"");
          _SFD_SET_DATA_PROPS(78,8,0,0,"");
          _SFD_SET_DATA_PROPS(79,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(9,0,1);
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
          _SFD_STATE_INFO(23,0,1);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,1);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(31,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,9);
          _SFD_CH_SUBSTATE_INDEX(1,26);
          _SFD_CH_SUBSTATE_INDEX(2,23);
          _SFD_ST_SUBSTATE_COUNT(9,13);
          _SFD_ST_SUBSTATE_INDEX(9,0,10);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_INDEX(9,2,12);
          _SFD_ST_SUBSTATE_INDEX(9,3,13);
          _SFD_ST_SUBSTATE_INDEX(9,4,14);
          _SFD_ST_SUBSTATE_INDEX(9,5,15);
          _SFD_ST_SUBSTATE_INDEX(9,6,16);
          _SFD_ST_SUBSTATE_INDEX(9,7,17);
          _SFD_ST_SUBSTATE_INDEX(9,8,18);
          _SFD_ST_SUBSTATE_INDEX(9,9,19);
          _SFD_ST_SUBSTATE_INDEX(9,10,20);
          _SFD_ST_SUBSTATE_INDEX(9,11,21);
          _SFD_ST_SUBSTATE_INDEX(9,12,22);
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
          _SFD_ST_SUBSTATE_COUNT(26,4);
          _SFD_ST_SUBSTATE_INDEX(26,0,27);
          _SFD_ST_SUBSTATE_INDEX(26,1,28);
          _SFD_ST_SUBSTATE_INDEX(26,2,29);
          _SFD_ST_SUBSTATE_INDEX(26,3,30);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(23,2);
          _SFD_ST_SUBSTATE_INDEX(23,0,24);
          _SFD_ST_SUBSTATE_INDEX(23,1,25);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(9,13,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(23,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,4,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(8,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"setPersonalityFactorc9_Demo_EP_IdleRand",0,-1,
                             903);
        _SFD_CV_INIT_EML_IF(8,1,0,632,640,698,903);
        _SFD_CV_INIT_EML_IF(8,1,1,698,710,768,903);
        _SFD_CV_INIT_EML_IF(8,1,2,768,780,839,903);
        _SFD_CV_INIT_EML(4,1,25,23,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"idleGazeTablec9_Demo_EP_IdleRand",0,-1,3688);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",3688,-1,3883);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",3883,-1,4080);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",4080,-1,4271);
        _SFD_CV_INIT_EML_FCN(4,4,"aFcnTruthTableAction_4",4271,-1,4466);
        _SFD_CV_INIT_EML_FCN(4,5,"aFcnTruthTableAction_5",4466,-1,4665);
        _SFD_CV_INIT_EML_FCN(4,6,"aFcnTruthTableAction_6",4665,-1,4866);
        _SFD_CV_INIT_EML_FCN(4,7,"aFcnTruthTableAction_7",4866,-1,5069);
        _SFD_CV_INIT_EML_FCN(4,8,"aFcnTruthTableAction_8",5069,-1,5274);
        _SFD_CV_INIT_EML_FCN(4,9,"aFcnTruthTableAction_9",5274,-1,5499);
        _SFD_CV_INIT_EML_FCN(4,10,"aFcnTruthTableAction_10",5499,-1,5727);
        _SFD_CV_INIT_EML_FCN(4,11,"aFcnTruthTableAction_11",5727,-1,5945);
        _SFD_CV_INIT_EML_FCN(4,12,"aFcnTruthTableAction_12",5945,-1,6169);
        _SFD_CV_INIT_EML_FCN(4,13,"aFcnTruthTableAction_13",6169,-1,6391);
        _SFD_CV_INIT_EML_FCN(4,14,"aFcnTruthTableAction_14",6391,-1,6677);
        _SFD_CV_INIT_EML_FCN(4,15,"aFcnTruthTableAction_15",6677,-1,6897);
        _SFD_CV_INIT_EML_FCN(4,16,"aFcnTruthTableAction_16",6897,-1,7115);
        _SFD_CV_INIT_EML_FCN(4,17,"aFcnTruthTableAction_17",7115,-1,7316);
        _SFD_CV_INIT_EML_FCN(4,18,"aFcnTruthTableAction_18",7316,-1,7636);
        _SFD_CV_INIT_EML_FCN(4,19,"aFcnTruthTableAction_19",7636,-1,7863);
        _SFD_CV_INIT_EML_FCN(4,20,"aFcnTruthTableAction_20",7863,-1,8194);
        _SFD_CV_INIT_EML_FCN(4,21,"aFcnTruthTableAction_21",8194,-1,8415);
        _SFD_CV_INIT_EML_FCN(4,22,"aFcnTruthTableAction_22",8415,-1,8739);
        _SFD_CV_INIT_EML_FCN(4,23,"aFcnTruthTableAction_23",8739,-1,8966);
        _SFD_CV_INIT_EML_FCN(4,24,"aFcnTruthTableAction_24",8966,-1,9158);
        _SFD_CV_INIT_EML_IF(4,1,0,2119,2149,2180,3686);
        _SFD_CV_INIT_EML_IF(4,1,1,2180,2214,2245,3686);
        _SFD_CV_INIT_EML_IF(4,1,2,2245,2279,2310,3686);
        _SFD_CV_INIT_EML_IF(4,1,3,2310,2344,2375,3686);
        _SFD_CV_INIT_EML_IF(4,1,4,2375,2409,2440,3686);
        _SFD_CV_INIT_EML_IF(4,1,5,2440,2474,2505,3686);
        _SFD_CV_INIT_EML_IF(4,1,6,2505,2539,2570,3686);
        _SFD_CV_INIT_EML_IF(4,1,7,2570,2604,2635,3686);
        _SFD_CV_INIT_EML_IF(4,1,8,2635,2669,2700,3686);
        _SFD_CV_INIT_EML_IF(4,1,9,2700,2735,2767,3686);
        _SFD_CV_INIT_EML_IF(4,1,10,2767,2802,2834,3686);
        _SFD_CV_INIT_EML_IF(4,1,11,2834,2869,2901,3686);
        _SFD_CV_INIT_EML_IF(4,1,12,2901,2936,2968,3686);
        _SFD_CV_INIT_EML_IF(4,1,13,2968,3003,3035,3686);
        _SFD_CV_INIT_EML_IF(4,1,14,3035,3070,3102,3686);
        _SFD_CV_INIT_EML_IF(4,1,15,3102,3137,3169,3686);
        _SFD_CV_INIT_EML_IF(4,1,16,3169,3204,3236,3686);
        _SFD_CV_INIT_EML_IF(4,1,17,3236,3271,3303,3686);
        _SFD_CV_INIT_EML_IF(4,1,18,3303,3338,3370,3686);
        _SFD_CV_INIT_EML_IF(4,1,19,3370,3405,3437,3686);
        _SFD_CV_INIT_EML_IF(4,1,20,3437,3472,3504,3686);
        _SFD_CV_INIT_EML_IF(4,1,21,3504,3539,3571,3686);
        _SFD_CV_INIT_EML_IF(4,1,22,3571,3606,3638,3686);
        _SFD_CV_INIT_EML(5,1,13,12,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"idleGazeTableExtrovertc9_Demo_EP_IdleRand",0,
                             -1,1903);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",1903,-1,2097);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",2097,-1,2293);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",2293,-1,2483);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",2483,-1,2681);
        _SFD_CV_INIT_EML_FCN(5,5,"aFcnTruthTableAction_5",2681,-1,2881);
        _SFD_CV_INIT_EML_FCN(5,6,"aFcnTruthTableAction_6",2881,-1,3110);
        _SFD_CV_INIT_EML_FCN(5,7,"aFcnTruthTableAction_7",3110,-1,3337);
        _SFD_CV_INIT_EML_FCN(5,8,"aFcnTruthTableAction_8",3337,-1,3628);
        _SFD_CV_INIT_EML_FCN(5,9,"aFcnTruthTableAction_9",3628,-1,3853);
        _SFD_CV_INIT_EML_FCN(5,10,"aFcnTruthTableAction_10",3853,-1,4077);
        _SFD_CV_INIT_EML_FCN(5,11,"aFcnTruthTableAction_11",4077,-1,4260);
        _SFD_CV_INIT_EML_FCN(5,12,"aFcnTruthTableAction_12",4260,-1,4493);
        _SFD_CV_INIT_EML_IF(5,1,0,1071,1101,1132,1901);
        _SFD_CV_INIT_EML_IF(5,1,1,1132,1166,1197,1901);
        _SFD_CV_INIT_EML_IF(5,1,2,1197,1231,1262,1901);
        _SFD_CV_INIT_EML_IF(5,1,3,1262,1296,1327,1901);
        _SFD_CV_INIT_EML_IF(5,1,4,1327,1361,1392,1901);
        _SFD_CV_INIT_EML_IF(5,1,5,1392,1426,1457,1901);
        _SFD_CV_INIT_EML_IF(5,1,6,1457,1491,1522,1901);
        _SFD_CV_INIT_EML_IF(5,1,7,1522,1556,1587,1901);
        _SFD_CV_INIT_EML_IF(5,1,8,1587,1621,1652,1901);
        _SFD_CV_INIT_EML_IF(5,1,9,1652,1687,1719,1901);
        _SFD_CV_INIT_EML_IF(5,1,10,1719,1754,1786,1901);
        _SFD_CV_INIT_EML_IF(5,1,11,1786,1821,1853,1901);
        _SFD_CV_INIT_EML(6,1,14,13,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"idleGazeTableIntrovertc9_Demo_EP_IdleRand",0,
                             -1,2057);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",2057,-1,2251);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",2251,-1,2447);
        _SFD_CV_INIT_EML_FCN(6,3,"aFcnTruthTableAction_3",2447,-1,2641);
        _SFD_CV_INIT_EML_FCN(6,4,"aFcnTruthTableAction_4",2641,-1,2839);
        _SFD_CV_INIT_EML_FCN(6,5,"aFcnTruthTableAction_5",2839,-1,3039);
        _SFD_CV_INIT_EML_FCN(6,6,"aFcnTruthTableAction_6",3039,-1,3241);
        _SFD_CV_INIT_EML_FCN(6,7,"aFcnTruthTableAction_7",3241,-1,3445);
        _SFD_CV_INIT_EML_FCN(6,8,"aFcnTruthTableAction_8",3445,-1,3680);
        _SFD_CV_INIT_EML_FCN(6,9,"aFcnTruthTableAction_9",3680,-1,3917);
        _SFD_CV_INIT_EML_FCN(6,10,"aFcnTruthTableAction_10",3917,-1,4145);
        _SFD_CV_INIT_EML_FCN(6,11,"aFcnTruthTableAction_11",4145,-1,4375);
        _SFD_CV_INIT_EML_FCN(6,12,"aFcnTruthTableAction_12",4375,-1,4603);
        _SFD_CV_INIT_EML_FCN(6,13,"aFcnTruthTableAction_13",4603,-1,4836);
        _SFD_CV_INIT_EML_IF(6,1,0,1158,1188,1219,2055);
        _SFD_CV_INIT_EML_IF(6,1,1,1219,1253,1284,2055);
        _SFD_CV_INIT_EML_IF(6,1,2,1284,1318,1349,2055);
        _SFD_CV_INIT_EML_IF(6,1,3,1349,1383,1414,2055);
        _SFD_CV_INIT_EML_IF(6,1,4,1414,1448,1479,2055);
        _SFD_CV_INIT_EML_IF(6,1,5,1479,1513,1544,2055);
        _SFD_CV_INIT_EML_IF(6,1,6,1544,1578,1609,2055);
        _SFD_CV_INIT_EML_IF(6,1,7,1609,1643,1674,2055);
        _SFD_CV_INIT_EML_IF(6,1,8,1674,1708,1739,2055);
        _SFD_CV_INIT_EML_IF(6,1,9,1739,1774,1806,2055);
        _SFD_CV_INIT_EML_IF(6,1,10,1806,1841,1873,2055);
        _SFD_CV_INIT_EML_IF(6,1,11,1873,1908,1940,2055);
        _SFD_CV_INIT_EML_IF(6,1,12,1940,1975,2007,2055);
        _SFD_CV_INIT_EML(2,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"idleGazeInterestedTablec9_Demo_EP_IdleRand",0,
                             -1,1293);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",1293,-1,1479);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",1479,-1,1669);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1669,-1,1860);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1860,-1,2054);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",2054,-1,2250);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",2250,-1,2448);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",2448,-1,2648);
        _SFD_CV_INIT_EML_FCN(2,8,"aFcnTruthTableAction_8",2648,-1,2863);
        _SFD_CV_INIT_EML_IF(2,1,0,727,757,788,1291);
        _SFD_CV_INIT_EML_IF(2,1,1,788,822,853,1291);
        _SFD_CV_INIT_EML_IF(2,1,2,853,887,918,1291);
        _SFD_CV_INIT_EML_IF(2,1,3,918,952,983,1291);
        _SFD_CV_INIT_EML_IF(2,1,4,983,1017,1048,1291);
        _SFD_CV_INIT_EML_IF(2,1,5,1048,1082,1113,1291);
        _SFD_CV_INIT_EML_IF(2,1,6,1113,1147,1178,1291);
        _SFD_CV_INIT_EML_IF(2,1,7,1178,1212,1243,1291);
        _SFD_CV_INIT_EML(31,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(31,0,"successTablec9_Demo_EP_IdleRand",0,-1,570);
        _SFD_CV_INIT_EML_FCN(31,1,"aFcnTruthTableAction_1",570,-1,880);
        _SFD_CV_INIT_EML_FCN(31,2,"aFcnTruthTableAction_2",880,-1,1101);
        _SFD_CV_INIT_EML_FCN(31,3,"aFcnTruthTableAction_3",1101,-1,1359);
        _SFD_CV_INIT_EML_IF(31,1,0,329,359,390,568);
        _SFD_CV_INIT_EML_IF(31,1,1,390,424,455,568);
        _SFD_CV_INIT_EML_IF(31,1,2,455,489,520,568);
        _SFD_CV_INIT_EML(0,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"gazeFollowUserMovec9_Demo_EP_IdleRand",0,-1,
                             555);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",555,-1,780);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",780,-1,1004);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1004,-1,1170);
        _SFD_CV_INIT_EML_IF(0,1,0,314,344,375,553);
        _SFD_CV_INIT_EML_IF(0,1,1,375,409,440,553);
        _SFD_CV_INIT_EML_IF(0,1,2,440,474,505,553);
        _SFD_CV_INIT_EML(1,1,1,17,0,0,0,0,0,34,17);
        _SFD_CV_INIT_EML_FCN(1,0,"idleGazeFunctionc9_Demo_EP_IdleRand",0,-1,2378);
        _SFD_CV_INIT_EML_IF(1,1,0,775,791,1464,2103);
        _SFD_CV_INIT_EML_IF(1,1,1,868,889,950,1463);
        _SFD_CV_INIT_EML_IF(1,1,2,950,976,1009,1463);
        _SFD_CV_INIT_EML_IF(1,1,3,1009,1035,1069,1463);
        _SFD_CV_INIT_EML_IF(1,1,4,1069,1095,1154,1463);
        _SFD_CV_INIT_EML_IF(1,1,5,1154,1181,1228,1463);
        _SFD_CV_INIT_EML_IF(1,1,6,1228,1256,1292,1463);
        _SFD_CV_INIT_EML_IF(1,1,7,1292,1320,1358,1463);
        _SFD_CV_INIT_EML_IF(1,1,8,1358,1386,1423,1463);
        _SFD_CV_INIT_EML_IF(1,1,9,1504,1525,1558,2099);
        _SFD_CV_INIT_EML_IF(1,1,10,1558,1584,1631,2099);
        _SFD_CV_INIT_EML_IF(1,1,11,1631,1657,1691,2099);
        _SFD_CV_INIT_EML_IF(1,1,12,1691,1718,1776,2099);
        _SFD_CV_INIT_EML_IF(1,1,13,1776,1804,1840,2099);
        _SFD_CV_INIT_EML_IF(1,1,14,1840,1868,1904,2099);
        _SFD_CV_INIT_EML_IF(1,1,15,1904,1932,1970,2099);
        _SFD_CV_INIT_EML_IF(1,1,16,1970,1998,2035,2099);

        {
          static int condStart[] = { 778, 786 };

          static int condEnd[] = { 782, 790 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,1,0,778,790,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 872, 881 };

          static int condEnd[] = { 877, 888 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,1,871,889,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 958, 968 };

          static int condEnd[] = { 964, 975 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,2,957,976,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1017, 1027 };

          static int condEnd[] = { 1023, 1034 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,3,1016,1035,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1077, 1087 };

          static int condEnd[] = { 1083, 1094 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,4,1076,1095,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1162, 1172 };

          static int condEnd[] = { 1168, 1180 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,5,1161,1181,2,10,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1236, 1247 };

          static int condEnd[] = { 1243, 1255 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,6,1235,1256,2,12,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1300, 1311 };

          static int condEnd[] = { 1307, 1319 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,7,1299,1320,2,14,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1366, 1377 };

          static int condEnd[] = { 1373, 1385 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,8,1365,1386,2,16,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1508, 1517 };

          static int condEnd[] = { 1513, 1524 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,9,1507,1525,2,18,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1566, 1576 };

          static int condEnd[] = { 1572, 1583 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,10,1565,1584,2,20,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1639, 1649 };

          static int condEnd[] = { 1645, 1656 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,11,1638,1657,2,22,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1699, 1709 };

          static int condEnd[] = { 1705, 1717 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,12,1698,1718,2,24,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1784, 1795 };

          static int condEnd[] = { 1791, 1803 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,13,1783,1804,2,26,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1848, 1859 };

          static int condEnd[] = { 1855, 1867 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,14,1847,1868,2,28,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1912, 1923 };

          static int condEnd[] = { 1919, 1931 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,15,1911,1932,2,30,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1978, 1989 };

          static int condEnd[] = { 1985, 1997 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,1,16,1977,1998,2,32,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,1,1,8,0,0,0,0,0,16,8);
        _SFD_CV_INIT_EML_FCN(3,0,"idleGazeOrigFunctionc9_Demo_EP_IdleRand",0,-1,
                             973);
        _SFD_CV_INIT_EML_IF(3,1,0,169,190,221,698);
        _SFD_CV_INIT_EML_IF(3,1,1,221,247,280,698);
        _SFD_CV_INIT_EML_IF(3,1,2,280,306,340,698);
        _SFD_CV_INIT_EML_IF(3,1,3,340,366,399,698);
        _SFD_CV_INIT_EML_IF(3,1,4,399,427,463,698);
        _SFD_CV_INIT_EML_IF(3,1,5,463,491,527,698);
        _SFD_CV_INIT_EML_IF(3,1,6,527,555,593,698);
        _SFD_CV_INIT_EML_IF(3,1,7,593,621,658,698);

        {
          static int condStart[] = { 173, 182 };

          static int condEnd[] = { 178, 189 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,0,172,190,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 229, 239 };

          static int condEnd[] = { 235, 246 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,1,228,247,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 288, 298 };

          static int condEnd[] = { 294, 305 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,2,287,306,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 348, 358 };

          static int condEnd[] = { 354, 365 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,3,347,366,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 407, 418 };

          static int condEnd[] = { 414, 426 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,4,406,427,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 471, 482 };

          static int condEnd[] = { 478, 490 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,5,470,491,2,10,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 535, 546 };

          static int condEnd[] = { 542, 554 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,6,534,555,2,12,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 601, 612 };

          static int condEnd[] = { 608, 620 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,1,7,600,621,2,14,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(7,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"insertQueueLowc9_Demo_EP_IdleRand",0,-1,568);
        _SFD_CV_INIT_EML_IF(7,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(7,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(7,1,0,109,121,294);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_SCRIPT(1,1,4,0,0,0,0,0,6,3);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"countDigits",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(1,0,43,49,-1,94);
        _SFD_CV_INIT_SCRIPT_IF(1,1,103,120,152,175);
        _SFD_CV_INIT_SCRIPT_IF(1,2,152,175,207,263);
        _SFD_CV_INIT_SCRIPT_IF(1,3,207,232,-1,232);

        {
          static int condStart[] = { 107, 116 };

          static int condEnd[] = { 110, 119 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,106,120,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 160, 170 };

          static int condEnd[] = { 164, 174 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,1,159,175,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 215, 226 };

          static int condEnd[] = { 220, 231 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,2,214,232,2,4,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(13,0,0,1,67,1,48);

        {
          static int condStart[] = { 1, 17, 41 };

          static int condEnd[] = { 16, 40, 67 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(13,0,0,1,67,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(0,0,0,1,82,1,48);

        {
          static int condStart[] = { 1, 12, 32, 56 };

          static int condEnd[] = { 11, 31, 55, 82 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,0,1,82,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,53,1,48);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 52 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,53,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,42,1,42);

        {
          static int condStart[] = { 2, 23 };

          static int condEnd[] = { 20, 41 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(16,0,0,1,67,1,48);

        {
          static int condStart[] = { 1, 17, 41 };

          static int condEnd[] = { 16, 40, 67 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(16,0,0,1,67,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,0,25,0,25);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,0,25,0,25);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(20,0,0,1,103,1,48);

        {
          static int condStart[] = { 1, 12, 37, 53, 77 };

          static int condEnd[] = { 11, 36, 52, 76, 103 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(20,0,0,1,103,5,0,&(condStart[0]),&(condEnd[0]),9,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(14,0,0,1,91,1,48);

        {
          static int condStart[] = { 1, 25, 41, 65 };

          static int condEnd[] = { 24, 40, 64, 91 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(14,0,0,1,91,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,27,0,27);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(17,0,0,1,78,1,48);

        {
          static int condStart[] = { 1, 28, 52 };

          static int condEnd[] = { 27, 51, 78 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(17,0,0,1,78,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(19,0,0,1,77,1,48);

        {
          static int condStart[] = { 1, 27, 51 };

          static int condEnd[] = { 26, 50, 77 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(19,0,0,1,77,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(25,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(25,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(24,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(24,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(28,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(28,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(34,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(34,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,0,25,0,25);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(33,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(33,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,0,29,0,29);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(32,0,0,1,34,1,34);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 17, 34 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(32,0,0,1,34,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,39,1,39);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 23, 39 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,39,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_bd_sf_marshallOut,(MexInFcnForType)
            c9_l_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_cd_sf_marshallOut,(MexInFcnForType)
            c9_m_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_vc_sf_marshallOut,(MexInFcnForType)
            c9_h_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_vc_sf_marshallOut,(MexInFcnForType)
            c9_h_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)
            c9_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 25;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_dd_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_vc_sf_marshallOut,(MexInFcnForType)
            c9_h_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(79,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_vc_sf_marshallOut,(MexInFcnForType)
            c9_h_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(48,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(49,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(50,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(51,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(52,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(53,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(54,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(55,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(56,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(57,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(58,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(59,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(60,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(61,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(62,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(63,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(64,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(65,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(66,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(67,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(68,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(69,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(70,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(71,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(72,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(73,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(74,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(75,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(76,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(77,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(78,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(79,(void *)(NULL));

        {
          real_T *c9_gameState;
          real_T *c9_personality;
          real_T (*c9_randArray)[25];
          c9_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S,
            0);
          c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(1U,
            chartInstance->c9_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(2U,
            chartInstance->c9_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_interest_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_randGazeDur_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_GAZE_SOFTEYE_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c9_GAZE_GUI_address);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_GAZE_USER_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c9_randHeadDur);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c9_randHeadDurOver);
          _SFD_SET_DATA_VALUE_PTR(13U, c9_gameState);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c9_avert_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c9_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c9_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c9_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c9_avertContChance);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c9_gazeGUIChance);
          _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c9_mutContChance);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c9_mutContF);
          _SFD_SET_DATA_VALUE_PTR(22U, &chartInstance->c9_CHANCEM);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c9_avertDur);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c9_gazeDir);
          _SFD_SET_DATA_VALUE_PTR(25U, &chartInstance->c9_CHANCEA);
          _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance->c9_magnitude);
          _SFD_SET_DATA_VALUE_PTR(27U, &chartInstance->c9_randHeadChance);
          _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c9_avertContF);
          _SFD_SET_DATA_VALUE_PTR(29U, &chartInstance->c9_gazeUserHandChance);
          _SFD_SET_DATA_VALUE_PTR(30U, *chartInstance->c9_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c9_pr_address);
          _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c9_P_address);
          _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance->c9_chanceO);
          _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c9_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c9_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c9_changeFlag_address);
          _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c9_BMLl);
          _SFD_SET_DATA_VALUE_PTR(38U, *chartInstance->c9_BML_address);
          _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c9_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c9_n);
          _SFD_SET_DATA_VALUE_PTR(41U, *c9_randArray);
          _SFD_SET_DATA_VALUE_PTR(42U, &chartInstance->c9_mutDur);
          _SFD_SET_DATA_VALUE_PTR(43U, c9_personality);
          _SFD_SET_DATA_VALUE_PTR(44U, &chartInstance->c9_mF);
          _SFD_SET_DATA_VALUE_PTR(45U, &chartInstance->c9_hF);
          _SFD_SET_DATA_VALUE_PTR(46U, &chartInstance->c9_aF);
          _SFD_SET_DATA_VALUE_PTR(47U, chartInstance->c9_avertH_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_EP_IdleRandMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "vKpaTxm86KyV5ICvvyu1sG";
}

static void sf_opaque_initialize_c9_Demo_EP_IdleRand(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
  initialize_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_Demo_EP_IdleRand(void *chartInstanceVar)
{
  enable_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_Demo_EP_IdleRand(void *chartInstanceVar)
{
  disable_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_Demo_EP_IdleRand(void *chartInstanceVar)
{
  sf_gateway_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_Demo_EP_IdleRand(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_Demo_EP_IdleRand
    ((SFc9_Demo_EP_IdleRandInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_Demo_EP_IdleRand();/* state var info */
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

extern void sf_internal_set_sim_state_c9_Demo_EP_IdleRand(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_Demo_EP_IdleRand();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_Demo_EP_IdleRand(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c9_Demo_EP_IdleRand(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c9_Demo_EP_IdleRand(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_Demo_EP_IdleRandInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_EP_IdleRand_optimization_info();
    }

    finalize_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
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
  initSimStructsc9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_Demo_EP_IdleRand(SimStruct *S)
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
    initialize_params_c9_Demo_EP_IdleRand((SFc9_Demo_EP_IdleRandInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_Demo_EP_IdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_EP_IdleRand_optimization_info();
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1727213813U));
  ssSetChecksum1(S,(2935687061U));
  ssSetChecksum2(S,(2165095453U));
  ssSetChecksum3(S,(9449598U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_Demo_EP_IdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_Demo_EP_IdleRand(SimStruct *S)
{
  SFc9_Demo_EP_IdleRandInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_Demo_EP_IdleRandInstanceStruct *)utMalloc(sizeof
    (SFc9_Demo_EP_IdleRandInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_Demo_EP_IdleRandInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_Demo_EP_IdleRand;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_Demo_EP_IdleRand;
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

void c9_Demo_EP_IdleRand_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_Demo_EP_IdleRand(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_Demo_EP_IdleRand(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_Demo_EP_IdleRand(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_Demo_EP_IdleRand_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
