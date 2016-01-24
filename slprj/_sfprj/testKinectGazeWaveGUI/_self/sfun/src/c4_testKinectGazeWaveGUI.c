/* Include files */

#include <stddef.h>
#include "blas.h"
#include "testKinectGazeWaveGUI_sfun.h"
#include "c4_testKinectGazeWaveGUI.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testKinectGazeWaveGUI_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_idle                     ((uint8_T)1U)
#define c4_IN_initalize                ((uint8_T)2U)
#define c4_IN_initializeWalkE          ((uint8_T)3U)
#define c4_IN_state2beat               ((uint8_T)4U)
#define c4_IN_stateAvert               ((uint8_T)5U)
#define c4_IN_stateBeat                ((uint8_T)6U)
#define c4_IN_stateCheckUser           ((uint8_T)7U)
#define c4_IN_stateCheckUser2          ((uint8_T)8U)
#define c4_IN_stateExtravert           ((uint8_T)9U)
#define c4_IN_stateExtravetPose        ((uint8_T)10U)
#define c4_IN_stateGazeI               ((uint8_T)11U)
#define c4_IN_stateInitalizeGazeE      ((uint8_T)12U)
#define c4_IN_stateInitializeIntrovert ((uint8_T)13U)
#define c4_IN_stateInitializeSmileI    ((uint8_T)14U)
#define c4_IN_stateIntrovertPose       ((uint8_T)15U)
#define c4_IN_stateSmile               ((uint8_T)16U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_y_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c4_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_gb_debug_family_names[19] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15", "gazeBML",
  "nargin", "nargout", "bmlID" };

static const char * c4_hb_debug_family_names[19] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15", "nargin",
  "nargout", "bmlID", "gazeBML" };

static const char * c4_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_sb_debug_family_names[21] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17", "nargin",
  "nargout", "bmlID", "poseBML" };

static const char * c4_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_vb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_yb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_nc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_uc_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c4_gd_debug_family_names[2] = { "nargin", "nargout" };

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

static const char * c4_se_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_te_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ue_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_ve_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_we_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_xe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c4_dataWrittenToVector[21];

/* Function Declarations */
static void initialize_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void initialize_params_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void enable_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void disable_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void set_sim_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void finalize_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void sf_gateway_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_chartstep_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void initSimStructsc4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_initalize(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_stateInitalizeGazeE(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_stateCheckUser(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_enter_atomic_stateGazeI(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance);
static void c4_stateInitializeIntrovert(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_stateExtravert(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_initializeWalkE(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_idle(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_enter_atomic_stateExtravetPose
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_stateExtravetPose(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_stateCheckUser2(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_enter_atomic_stateAvert(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance);
static void c4_stateAvert(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_enter_atomic_stateBeat(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_stateBeat(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_enter_atomic_state2beat(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance);
static void c4_state2beat(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_b_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_c_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_d_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_e_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_f_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_g_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_h_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static real_T c4_rand(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static real_T c4_eml_rand(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);
static void c4_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625]);
static void c4_twister_state_vector(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625]);
static void c4_b_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
  *c4_r);
static void c4_eml_error(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_i_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_j_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_k_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_l_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_m_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_n_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static real_T c4_randi(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance);
static void c4_o_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_p_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_q_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_r_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_s_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_t_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_u_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_v_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_w_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_x_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_y_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_ab_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_bb_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void c4_cb_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256]);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_nargout, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_myarr256, const char_T *c4_identifier,
  real_T c4_y[256]);
static void c4_d_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
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
static boolean_T c4_e_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
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
static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_sendBML(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance,
  real_T c4_arg[256]);
static void c4_gazeAvert(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance,
  real_T c4_bmlID);
static void c4_introvertIdlePose(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256]);
static const mxArray *c4_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_g_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_initalize, const char_T *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_i_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256]);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint32_T c4_j_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier);
static uint32_T c4_k_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint32_T c4_l_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier);
static uint32_T c4_m_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_n_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[625]);
static void c4_o_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[625]);
static void c4_p_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[2]);
static void c4_q_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[2]);
static const mxArray *c4_r_emlrt_marshallIn
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier);
static const mxArray *c4_s_emlrt_marshallIn
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c4_u,
   const emlrtMsgIdentifier *c4_parentId);
static void c4_updateDataWrittenToVector
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex);
static void c4_errorIfDataNotWrittenToFcn
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex, uint32_T c4_dataNumber);
static void c4_b_twister_state_vector(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed);
static real_T c4_c_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625]);
static void init_dsm_address_info(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_idle = 0U;
  chartInstance->c4_tp_initalize = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_initializeWalkE = 0U;
  chartInstance->c4_tp_state2beat = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateAvert = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateBeat = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateCheckUser = 0U;
  chartInstance->c4_tp_stateCheckUser2 = 0U;
  chartInstance->c4_tp_stateExtravert = 0U;
  chartInstance->c4_tp_stateExtravetPose = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateGazeI = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateInitalizeGazeE = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateInitializeIntrovert = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateInitializeSmileI = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateIntrovertPose = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateSmile = 0U;
  chartInstance->c4_is_active_c4_testKinectGazeWaveGUI = 0U;
  chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void disable_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

static void c4_update_debugger_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_testKinectGazeWaveGUI == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_initalize) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
      c4_IN_stateInitializeSmileI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateInitalizeGazeE)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateCheckUser) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateGazeI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
      c4_IN_stateInitializeIntrovert) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateExtravert) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_initializeWalkE) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateExtravetPose)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateCheckUser2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateAvert) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateIntrovertPose)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateBeat) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_state2beat) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
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
  int32_T c4_i0;
  real_T c4_g_u[256];
  const mxArray *c4_h_y = NULL;
  int32_T c4_i1;
  real_T c4_h_u[256];
  const mxArray *c4_i_y = NULL;
  int32_T c4_i2;
  real_T c4_i_u[256];
  const mxArray *c4_j_y = NULL;
  int32_T c4_i3;
  real_T c4_j_u[256];
  const mxArray *c4_k_y = NULL;
  int32_T c4_i4;
  real_T c4_k_u[256];
  const mxArray *c4_l_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_l_u;
  const mxArray *c4_m_y = NULL;
  int32_T c4_i5;
  real_T c4_m_u[256];
  const mxArray *c4_n_y = NULL;
  int32_T c4_i6;
  real_T c4_n_u[256];
  const mxArray *c4_o_y = NULL;
  int32_T c4_i7;
  real_T c4_o_u[256];
  const mxArray *c4_p_y = NULL;
  int32_T c4_i8;
  real_T c4_p_u[256];
  const mxArray *c4_q_y = NULL;
  uint32_T c4_h_hoistedGlobal;
  uint32_T c4_q_u;
  const mxArray *c4_r_y = NULL;
  uint32_T c4_i_hoistedGlobal;
  uint32_T c4_r_u;
  const mxArray *c4_s_y = NULL;
  int32_T c4_i9;
  uint32_T c4_s_u[625];
  const mxArray *c4_t_y = NULL;
  int32_T c4_i10;
  uint32_T c4_t_u[2];
  const mxArray *c4_u_y = NULL;
  uint8_T c4_j_hoistedGlobal;
  uint8_T c4_u_u;
  const mxArray *c4_v_y = NULL;
  uint8_T c4_k_hoistedGlobal;
  uint8_T c4_v_u;
  const mxArray *c4_w_y = NULL;
  uint8_T c4_l_hoistedGlobal;
  uint8_T c4_w_u;
  const mxArray *c4_x_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(23, 1), false);
  c4_hoistedGlobal = chartInstance->c4_beat;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_beat2;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_count;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_gaze;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_m;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = chartInstance->c4_n;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  for (c4_i0 = 0; c4_i0 < 256; c4_i0++) {
    c4_g_u[c4_i0] = chartInstance->c4_txtAvert[c4_i0];
  }

  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  for (c4_i1 = 0; c4_i1 < 256; c4_i1++) {
    c4_h_u[c4_i1] = chartInstance->c4_txtBeat[c4_i1];
  }

  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_h_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  for (c4_i2 = 0; c4_i2 < 256; c4_i2++) {
    c4_i_u[c4_i2] = chartInstance->c4_txtBeat2[c4_i2];
  }

  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_i_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  for (c4_i3 = 0; c4_i3 < 256; c4_i3++) {
    c4_j_u[c4_i3] = chartInstance->c4_txtEyeTarget[c4_i3];
  }

  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_j_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 9, c4_k_y);
  for (c4_i4 = 0; c4_i4 < 256; c4_i4++) {
    c4_k_u[c4_i4] = chartInstance->c4_txtGaze[c4_i4];
  }

  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_k_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  c4_g_hoistedGlobal = chartInstance->c4_txtGaze2;
  c4_l_u = c4_g_hoistedGlobal;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 11, c4_m_y);
  for (c4_i5 = 0; c4_i5 < 256; c4_i5++) {
    c4_m_u[c4_i5] = chartInstance->c4_txtNoSmile[c4_i5];
  }

  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_m_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 12, c4_n_y);
  for (c4_i6 = 0; c4_i6 < 256; c4_i6++) {
    c4_n_u[c4_i6] = chartInstance->c4_txtSmile[c4_i6];
  }

  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_n_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 13, c4_o_y);
  for (c4_i7 = 0; c4_i7 < 256; c4_i7++) {
    c4_o_u[c4_i7] = chartInstance->c4_txtWalkFw[c4_i7];
  }

  c4_p_y = NULL;
  sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_o_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 14, c4_p_y);
  for (c4_i8 = 0; c4_i8 < 256; c4_i8++) {
    c4_p_u[c4_i8] = chartInstance->c4_txtWalkToNeutral[c4_i8];
  }

  c4_q_y = NULL;
  sf_mex_assign(&c4_q_y, sf_mex_create("y", c4_p_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c4_y, 15, c4_q_y);
  c4_h_hoistedGlobal = chartInstance->c4_method;
  c4_q_u = c4_h_hoistedGlobal;
  c4_r_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_r_y, sf_mex_create("y", &c4_q_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 16, c4_r_y);
  c4_i_hoistedGlobal = chartInstance->c4_state;
  c4_r_u = c4_i_hoistedGlobal;
  c4_s_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_s_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_s_y, sf_mex_create("y", &c4_r_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 17, c4_s_y);
  for (c4_i9 = 0; c4_i9 < 625; c4_i9++) {
    c4_s_u[c4_i9] = chartInstance->c4_c_state[c4_i9];
  }

  c4_t_y = NULL;
  if (!chartInstance->c4_c_state_not_empty) {
    sf_mex_assign(&c4_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_t_y, sf_mex_create("y", c4_s_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c4_y, 18, c4_t_y);
  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    c4_t_u[c4_i10] = chartInstance->c4_b_state[c4_i10];
  }

  c4_u_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_u_y, sf_mex_create("y", c4_t_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c4_y, 19, c4_u_y);
  c4_j_hoistedGlobal = chartInstance->c4_is_active_c4_testKinectGazeWaveGUI;
  c4_u_u = c4_j_hoistedGlobal;
  c4_v_y = NULL;
  sf_mex_assign(&c4_v_y, sf_mex_create("y", &c4_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 20, c4_v_y);
  c4_k_hoistedGlobal = chartInstance->c4_is_c4_testKinectGazeWaveGUI;
  c4_v_u = c4_k_hoistedGlobal;
  c4_w_y = NULL;
  sf_mex_assign(&c4_w_y, sf_mex_create("y", &c4_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 21, c4_w_y);
  c4_l_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_w_u = c4_l_hoistedGlobal;
  c4_x_y = NULL;
  sf_mex_assign(&c4_x_y, sf_mex_create("y", &c4_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 22, c4_x_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[256];
  int32_T c4_i11;
  real_T c4_dv1[256];
  int32_T c4_i12;
  real_T c4_dv2[256];
  int32_T c4_i13;
  real_T c4_dv3[256];
  int32_T c4_i14;
  real_T c4_dv4[256];
  int32_T c4_i15;
  real_T c4_dv5[256];
  int32_T c4_i16;
  real_T c4_dv6[256];
  int32_T c4_i17;
  real_T c4_dv7[256];
  int32_T c4_i18;
  real_T c4_dv8[256];
  int32_T c4_i19;
  uint32_T c4_uv0[625];
  int32_T c4_i20;
  uint32_T c4_uv1[2];
  int32_T c4_i21;
  c4_u = sf_mex_dup(c4_st);
  chartInstance->c4_beat = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "beat");
  chartInstance->c4_beat2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "beat2");
  chartInstance->c4_count = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "count");
  chartInstance->c4_gaze = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "gaze");
  chartInstance->c4_m = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "m");
  chartInstance->c4_n = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "n");
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
                        "txtAvert", c4_dv0);
  for (c4_i11 = 0; c4_i11 < 256; c4_i11++) {
    chartInstance->c4_txtAvert[c4_i11] = c4_dv0[c4_i11];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
                        "txtBeat", c4_dv1);
  for (c4_i12 = 0; c4_i12 < 256; c4_i12++) {
    chartInstance->c4_txtBeat[c4_i12] = c4_dv1[c4_i12];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
                        "txtBeat2", c4_dv2);
  for (c4_i13 = 0; c4_i13 < 256; c4_i13++) {
    chartInstance->c4_txtBeat2[c4_i13] = c4_dv2[c4_i13];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 9)),
                        "txtEyeTarget", c4_dv3);
  for (c4_i14 = 0; c4_i14 < 256; c4_i14++) {
    chartInstance->c4_txtEyeTarget[c4_i14] = c4_dv3[c4_i14];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 10)),
                        "txtGaze", c4_dv4);
  for (c4_i15 = 0; c4_i15 < 256; c4_i15++) {
    chartInstance->c4_txtGaze[c4_i15] = c4_dv4[c4_i15];
  }

  chartInstance->c4_txtGaze2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 11)), "txtGaze2");
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 12)),
                        "txtNoSmile", c4_dv5);
  for (c4_i16 = 0; c4_i16 < 256; c4_i16++) {
    chartInstance->c4_txtNoSmile[c4_i16] = c4_dv5[c4_i16];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 13)),
                        "txtSmile", c4_dv6);
  for (c4_i17 = 0; c4_i17 < 256; c4_i17++) {
    chartInstance->c4_txtSmile[c4_i17] = c4_dv6[c4_i17];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 14)),
                        "txtWalkFw", c4_dv7);
  for (c4_i18 = 0; c4_i18 < 256; c4_i18++) {
    chartInstance->c4_txtWalkFw[c4_i18] = c4_dv7[c4_i18];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 15)),
                        "txtWalkToNeutral", c4_dv8);
  for (c4_i19 = 0; c4_i19 < 256; c4_i19++) {
    chartInstance->c4_txtWalkToNeutral[c4_i19] = c4_dv8[c4_i19];
  }

  chartInstance->c4_method = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 16)), "method");
  chartInstance->c4_state = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 17)), "state");
  c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 18)),
                        "state", c4_uv0);
  for (c4_i20 = 0; c4_i20 < 625; c4_i20++) {
    chartInstance->c4_c_state[c4_i20] = c4_uv0[c4_i20];
  }

  c4_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 19)),
                        "state", c4_uv1);
  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    chartInstance->c4_b_state[c4_i21] = c4_uv1[c4_i21];
  }

  chartInstance->c4_is_active_c4_testKinectGazeWaveGUI = c4_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 20)),
     "is_active_c4_testKinectGazeWaveGUI");
  chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 21)),
     "is_c4_testKinectGazeWaveGUI");
  chartInstance->c4_temporalCounter_i1 = c4_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 22)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 23)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_testKinectGazeWaveGUI(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_idle) {
      chartInstance->c4_tp_idle = 1U;
    } else {
      chartInstance->c4_tp_idle = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_initalize) {
      chartInstance->c4_tp_initalize = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_initalize = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_initializeWalkE)
    {
      chartInstance->c4_tp_initializeWalkE = 1U;
    } else {
      chartInstance->c4_tp_initializeWalkE = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_state2beat) {
      chartInstance->c4_tp_state2beat = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_state2beat = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateAvert) {
      chartInstance->c4_tp_stateAvert = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateAvert = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateBeat) {
      chartInstance->c4_tp_stateBeat = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateBeat = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateCheckUser) {
      chartInstance->c4_tp_stateCheckUser = 1U;
    } else {
      chartInstance->c4_tp_stateCheckUser = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateCheckUser2)
    {
      chartInstance->c4_tp_stateCheckUser2 = 1U;
    } else {
      chartInstance->c4_tp_stateCheckUser2 = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateExtravert) {
      chartInstance->c4_tp_stateExtravert = 1U;
    } else {
      chartInstance->c4_tp_stateExtravert = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateExtravetPose)
    {
      chartInstance->c4_tp_stateExtravetPose = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateExtravetPose = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateGazeI) {
      chartInstance->c4_tp_stateGazeI = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateGazeI = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
        c4_IN_stateInitalizeGazeE) {
      chartInstance->c4_tp_stateInitalizeGazeE = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateInitalizeGazeE = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
        c4_IN_stateInitializeIntrovert) {
      chartInstance->c4_tp_stateInitializeIntrovert = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateInitializeIntrovert = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
        c4_IN_stateInitializeSmileI) {
      chartInstance->c4_tp_stateInitializeSmileI = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateInitializeSmileI = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI ==
        c4_IN_stateIntrovertPose) {
      chartInstance->c4_tp_stateIntrovertPose = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_stateIntrovertPose = 0U;
    }

    if (chartInstance->c4_is_c4_testKinectGazeWaveGUI == c4_IN_stateSmile) {
      chartInstance->c4_tp_stateSmile = 1U;
    } else {
      chartInstance->c4_tp_stateSmile = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i30;
  real_T *c4_handLup;
  real_T *c4_extraversionW;
  real_T *c4_handRup;
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_set_sim_state_side_effects_c4_testKinectGazeWaveGUI(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c4_temporalCounter_i1 < 31U) {
    chartInstance->c4_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_handLup, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_extraversionW, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
  for (c4_i22 = 0; c4_i22 < 256; c4_i22++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtBeat[c4_i22], 4U);
  }

  for (c4_i23 = 0; c4_i23 < 256; c4_i23++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtNoSmile[c4_i23], 5U);
  }

  for (c4_i24 = 0; c4_i24 < 256; c4_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtSmile[c4_i24], 6U);
  }

  for (c4_i25 = 0; c4_i25 < 256; c4_i25++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtAvert[c4_i25], 7U);
  }

  for (c4_i26 = 0; c4_i26 < 256; c4_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtEyeTarget[c4_i26], 8U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtGaze2, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_gaze, 10U);
  for (c4_i27 = 0; c4_i27 < 256; c4_i27++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtGaze[c4_i27], 11U);
  }

  for (c4_i28 = 0; c4_i28 < 256; c4_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtWalkToNeutral[c4_i28], 12U);
  }

  for (c4_i29 = 0; c4_i29 < 256; c4_i29++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtWalkFw[c4_i29], 13U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_n, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_m, 15U);
  _SFD_DATA_RANGE_CHECK(*c4_handRup, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat2, 17U);
  for (c4_i30 = 0; c4_i30 < 256; c4_i30++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtBeat2[c4_i30], 18U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_testKinectGazeWaveGUI(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_testKinectGazeWaveGUIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv9[256];
  int32_T c4_i31;
  int32_T c4_i32;
  real_T c4_dv10[256];
  int32_T c4_i33;
  int32_T c4_i34;
  real_T c4_dv11[256];
  int32_T c4_i35;
  int32_T c4_i36;
  real_T c4_dv12[256];
  int32_T c4_i37;
  int32_T c4_i38;
  real_T c4_dv13[256];
  int32_T c4_i39;
  int32_T c4_i40;
  real_T c4_dv14[256];
  int32_T c4_i41;
  int32_T c4_i42;
  real_T c4_dv15[256];
  int32_T c4_i43;
  int32_T c4_i44;
  real_T c4_dv16[256];
  int32_T c4_i45;
  int32_T c4_i46;
  uint32_T c4_b_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[103];
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_myarr256[256];
  int32_T c4_i47;
  static char_T c4_cv0[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', '0', ' ', '0',
    ' ', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i48;
  static real_T c4_dv17[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 32.0, 32.0, 48.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i49;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  uint32_T c4_c_debug_family_var_map[3];
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  int32_T c4_i54;
  real_T c4_arg[256];
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_d_out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_i_nargin = 0.0;
  real_T c4_i_nargout = 1.0;
  boolean_T c4_f_out;
  real_T c4_j_nargin = 0.0;
  real_T c4_j_nargout = 0.0;
  real_T *c4_extraversionW;
  real_T *c4_handRup;
  real_T *c4_handLup;
  real_T (*c4_b_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  if (chartInstance->c4_is_active_c4_testKinectGazeWaveGUI == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_active_c4_testKinectGazeWaveGUI = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_initalize;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_initalize = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    chartInstance->c4_beat = 0.0;
    c4_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat, 0U);
    chartInstance->c4_gaze = 0.0;
    c4_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_gaze, 10U);
    chartInstance->c4_beat2 = 0.0;
    c4_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat2, 17U);
    chartInstance->c4_count = 0.0;
    c4_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
    c4_encStr2Arr(chartInstance, c4_dv9);
    for (c4_i31 = 0; c4_i31 < 256; c4_i31++) {
      chartInstance->c4_txtEyeTarget[c4_i31] = c4_dv9[c4_i31];
    }

    c4_updateDataWrittenToVector(chartInstance, 6U);
    for (c4_i32 = 0; c4_i32 < 256; c4_i32++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtEyeTarget[c4_i32], 8U);
    }

    c4_b_encStr2Arr(chartInstance, c4_dv10);
    for (c4_i33 = 0; c4_i33 < 256; c4_i33++) {
      chartInstance->c4_txtSmile[c4_i33] = c4_dv10[c4_i33];
    }

    c4_updateDataWrittenToVector(chartInstance, 4U);
    for (c4_i34 = 0; c4_i34 < 256; c4_i34++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtSmile[c4_i34], 6U);
    }

    c4_c_encStr2Arr(chartInstance, c4_dv11);
    for (c4_i35 = 0; c4_i35 < 256; c4_i35++) {
      chartInstance->c4_txtNoSmile[c4_i35] = c4_dv11[c4_i35];
    }

    c4_updateDataWrittenToVector(chartInstance, 3U);
    for (c4_i36 = 0; c4_i36 < 256; c4_i36++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtNoSmile[c4_i36], 5U);
    }

    c4_d_encStr2Arr(chartInstance, c4_dv12);
    for (c4_i37 = 0; c4_i37 < 256; c4_i37++) {
      chartInstance->c4_txtBeat[c4_i37] = c4_dv12[c4_i37];
    }

    c4_updateDataWrittenToVector(chartInstance, 2U);
    for (c4_i38 = 0; c4_i38 < 256; c4_i38++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtBeat[c4_i38], 4U);
    }

    c4_e_encStr2Arr(chartInstance, c4_dv13);
    for (c4_i39 = 0; c4_i39 < 256; c4_i39++) {
      chartInstance->c4_txtBeat2[c4_i39] = c4_dv13[c4_i39];
    }

    c4_updateDataWrittenToVector(chartInstance, 15U);
    for (c4_i40 = 0; c4_i40 < 256; c4_i40++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtBeat2[c4_i40], 18U);
    }

    c4_f_encStr2Arr(chartInstance, c4_dv14);
    for (c4_i41 = 0; c4_i41 < 256; c4_i41++) {
      chartInstance->c4_txtAvert[c4_i41] = c4_dv14[c4_i41];
    }

    c4_updateDataWrittenToVector(chartInstance, 5U);
    for (c4_i42 = 0; c4_i42 < 256; c4_i42++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtAvert[c4_i42], 7U);
    }

    c4_g_encStr2Arr(chartInstance, c4_dv15);
    for (c4_i43 = 0; c4_i43 < 256; c4_i43++) {
      chartInstance->c4_txtGaze[c4_i43] = c4_dv15[c4_i43];
    }

    c4_updateDataWrittenToVector(chartInstance, 9U);
    for (c4_i44 = 0; c4_i44 < 256; c4_i44++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtGaze[c4_i44], 11U);
    }

    c4_h_encStr2Arr(chartInstance, c4_dv16);
    for (c4_i45 = 0; c4_i45 < 256; c4_i45++) {
      chartInstance->c4_txtWalkFw[c4_i45] = c4_dv16[c4_i45];
    }

    c4_updateDataWrittenToVector(chartInstance, 11U);
    for (c4_i46 = 0; c4_i46 < 256; c4_i46++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtWalkFw[c4_i46], 13U);
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_j_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_r_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_q_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    for (c4_i47 = 0; c4_i47 < 103; c4_i47++) {
      c4_mystr[c4_i47] = c4_cv0[c4_i47];
    }

    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
    c4_maxarrsize = 256.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
    for (c4_i48 = 0; c4_i48 < 103; c4_i48++) {
      c4_arr[c4_i48] = c4_dv17[c4_i48];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
    c4_ss = 103.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
    c4_padsize = c4_maxarrsize - c4_ss;
    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
    for (c4_i49 = 0; c4_i49 < 256; c4_i49++) {
      c4_tt[c4_i49] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
    for (c4_i50 = 0; c4_i50 < 103; c4_i50++) {
      c4_tt[c4_i50] = c4_arr[c4_i50];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
    for (c4_i51 = 0; c4_i51 < 256; c4_i51++) {
      c4_myarr256[c4_i51] = c4_tt[c4_i51];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
    _SFD_SYMBOL_SCOPE_POP();
    for (c4_i52 = 0; c4_i52 < 256; c4_i52++) {
      chartInstance->c4_txtWalkToNeutral[c4_i52] = c4_myarr256[c4_i52];
    }

    c4_updateDataWrittenToVector(chartInstance, 10U);
    for (c4_i53 = 0; c4_i53 < 256; c4_i53++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_txtWalkToNeutral[c4_i53], 12U);
    }

    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c4_is_c4_testKinectGazeWaveGUI) {
     case c4_IN_idle:
      CV_CHART_EVAL(0, 0, 1);
      c4_idle(chartInstance);
      break;

     case c4_IN_initalize:
      CV_CHART_EVAL(0, 0, 2);
      c4_initalize(chartInstance);
      break;

     case c4_IN_initializeWalkE:
      CV_CHART_EVAL(0, 0, 3);
      c4_initializeWalkE(chartInstance);
      break;

     case c4_IN_state2beat:
      CV_CHART_EVAL(0, 0, 4);
      c4_state2beat(chartInstance);
      break;

     case c4_IN_stateAvert:
      CV_CHART_EVAL(0, 0, 5);
      c4_stateAvert(chartInstance);
      break;

     case c4_IN_stateBeat:
      CV_CHART_EVAL(0, 0, 6);
      c4_stateBeat(chartInstance);
      break;

     case c4_IN_stateCheckUser:
      CV_CHART_EVAL(0, 0, 7);
      c4_stateCheckUser(chartInstance);
      break;

     case c4_IN_stateCheckUser2:
      CV_CHART_EVAL(0, 0, 8);
      c4_stateCheckUser2(chartInstance);
      break;

     case c4_IN_stateExtravert:
      CV_CHART_EVAL(0, 0, 9);
      c4_stateExtravert(chartInstance);
      break;

     case c4_IN_stateExtravetPose:
      CV_CHART_EVAL(0, 0, 10);
      c4_stateExtravetPose(chartInstance);
      break;

     case c4_IN_stateGazeI:
      CV_CHART_EVAL(0, 0, 11);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_gc_debug_family_names,
        c4_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_out = CV_EML_IF(19, 0, 0, chartInstance->c4_temporalCounter_i1 >= 10);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateGazeI = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateCheckUser;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCheckUser = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c4_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c4_sfEvent);
      break;

     case c4_IN_stateInitalizeGazeE:
      CV_CHART_EVAL(0, 0, 12);
      c4_stateInitalizeGazeE(chartInstance);
      break;

     case c4_IN_stateInitializeIntrovert:
      CV_CHART_EVAL(0, 0, 13);
      c4_stateInitializeIntrovert(chartInstance);
      break;

     case c4_IN_stateInitializeSmileI:
      CV_CHART_EVAL(0, 0, 14);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_yb_debug_family_names,
        c4_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_b_out = CV_EML_IF(28, 0, 0, chartInstance->c4_temporalCounter_i1 >= 5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateInitializeSmileI = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI =
          c4_IN_stateInitializeIntrovert;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateInitializeIntrovert = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_o_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        c4_errorIfDataNotWrittenToFcn(chartInstance, 10U, 12U);
        for (c4_i54 = 0; c4_i54 < 256; c4_i54++) {
          c4_arg[c4_i54] = chartInstance->c4_txtWalkToNeutral[c4_i54];
        }

        for (c4_i55 = 0; c4_i55 < 256; c4_i55++) {
          _SFD_DATA_RANGE_CHECK(c4_arg[c4_i55], 29U);
        }

        _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
        _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
        _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
          c4_f_sf_marshallIn);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c4_sfEvent);
        for (c4_i56 = 0; c4_i56 < 256; c4_i56++) {
          (*c4_b_arg)[c4_i56] = c4_arg[c4_i56];
        }

        for (c4_i57 = 0; c4_i57 < 256; c4_i57++) {
          _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i57], 29U);
        }

        sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
        _SFD_UNSET_DATA_VALUE_PTR(29U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                     chartInstance->c4_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c4_sfEvent);
      break;

     case c4_IN_stateIntrovertPose:
      CV_CHART_EVAL(0, 0, 15);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ed_debug_family_names,
        c4_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_c_out = CV_EML_IF(18, 0, 0, *c4_extraversionW > 5.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateIntrovertPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_idle = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kc_debug_family_names,
          c4_c_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_db_sf_marshallOut,
          c4_c_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(21, 0, 0, *c4_handRup == 1.0)) {
          if (CV_EML_COND(21, 0, 1, chartInstance->c4_gaze == 0.0)) {
            CV_EML_MCDC(21, 0, 0, true);
            CV_EML_IF(21, 0, 0, true);
            c4_d_out = true;
          } else {
            guard2 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(21, 0, 0, false);
          CV_EML_IF(21, 0, 0, false);
          c4_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c4_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateIntrovertPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
          chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
          chartInstance->c4_temporalCounter_i1 = 0U;
          chartInstance->c4_tp_stateGazeI = 1U;
          c4_enter_atomic_stateGazeI(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                       chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_lc_debug_family_names,
            c4_c_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U,
            c4_db_sf_marshallOut, c4_c_sf_marshallIn);
          guard1 = false;
          if (CV_EML_COND(38, 0, 0, *c4_handLup == 1.0)) {
            if (CV_EML_COND(38, 0, 1, chartInstance->c4_gaze == 0.0)) {
              CV_EML_MCDC(38, 0, 0, true);
              CV_EML_IF(38, 0, 0, true);
              c4_e_out = true;
            } else {
              guard1 = true;
            }
          } else {
            c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
            guard1 = true;
          }

          if (guard1 == true) {
            CV_EML_MCDC(38, 0, 0, false);
            CV_EML_IF(38, 0, 0, false);
            c4_e_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c4_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c4_sfEvent);
            chartInstance->c4_tp_stateIntrovertPose = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
            chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
            chartInstance->c4_temporalCounter_i1 = 0U;
            chartInstance->c4_tp_stateGazeI = 1U;
            c4_enter_atomic_stateGazeI(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                         chartInstance->c4_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hc_debug_family_names,
              c4_c_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U,
              c4_sf_marshallOut, c4_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
              c4_sf_marshallOut, c4_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U,
              c4_db_sf_marshallOut, c4_c_sf_marshallIn);
            c4_f_out = CV_EML_IF(3, 0, 0, chartInstance->c4_temporalCounter_i1 >=
                                 30);
            _SFD_SYMBOL_SCOPE_POP();
            if (c4_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
              chartInstance->c4_tp_stateIntrovertPose = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
              chartInstance->c4_is_c4_testKinectGazeWaveGUI =
                c4_IN_stateCheckUser;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
              chartInstance->c4_tp_stateCheckUser = 1U;
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                           chartInstance->c4_sfEvent);
            }
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c4_sfEvent);
      break;

     case c4_IN_stateSmile:
      CV_CHART_EVAL(0, 0, 16);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravert;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtravert = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_p_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
      chartInstance->c4_count++;
      c4_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c4_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_testKinectGazeWaveGUI
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_initalize(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_vb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(5, 0, 0, chartInstance->c4_temporalCounter_i1 >= 1);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_initalize = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c4_sfEvent);
}

static void c4_stateInitalizeGazeE(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  int32_T c4_i58;
  real_T c4_arg[256];
  int32_T c4_i59;
  int32_T c4_i60;
  int32_T c4_i61;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_cc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(27, 0, 0, chartInstance->c4_temporalCounter_i1 >= 1);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateInitalizeGazeE = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_initializeWalkE;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_initializeWalkE = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_q_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 11U, 13U);
    for (c4_i58 = 0; c4_i58 < 256; c4_i58++) {
      c4_arg[c4_i58] = chartInstance->c4_txtWalkFw[c4_i58];
    }

    for (c4_i59 = 0; c4_i59 < 256; c4_i59++) {
      _SFD_DATA_RANGE_CHECK(c4_arg[c4_i59], 29U);
    }

    _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
      c4_f_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
    for (c4_i60 = 0; c4_i60 < 256; c4_i60++) {
      (*c4_b_arg)[c4_i60] = c4_arg[c4_i60];
    }

    for (c4_i61 = 0; c4_i61 < 256; c4_i61++) {
      _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i61], 29U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(29U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c4_sfEvent);
}

static void c4_stateCheckUser(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_d_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_f_out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 0.0;
  real_T c4_i_nargin = 0.0;
  real_T c4_i_nargout = 1.0;
  boolean_T c4_g_out;
  real_T *c4_extraversionW;
  real_T *c4_handRup;
  real_T *c4_handLup;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ec_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(15, 0, 0, *c4_extraversionW > 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateCheckUser = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ac_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard4 = false;
    if (CV_EML_COND(40, 0, 0, *c4_handRup == 1.0)) {
      if (CV_EML_COND(40, 0, 1, chartInstance->c4_gaze == 0.0)) {
        CV_EML_MCDC(40, 0, 0, true);
        CV_EML_IF(40, 0, 0, true);
        c4_b_out = true;
      } else {
        guard4 = true;
      }
    } else {
      c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(40, 0, 0, false);
      CV_EML_IF(40, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCheckUser = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateGazeI = 1U;
      c4_enter_atomic_stateGazeI(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_dc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard3 = false;
      if (CV_EML_COND(17, 0, 0, *c4_handLup == 1.0)) {
        if (CV_EML_COND(17, 0, 1, chartInstance->c4_gaze == 0.0)) {
          CV_EML_MCDC(17, 0, 0, true);
          CV_EML_IF(17, 0, 0, true);
          c4_c_out = true;
        } else {
          guard3 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(17, 0, 0, false);
        CV_EML_IF(17, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCheckUser = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateGazeI = 1U;
        c4_enter_atomic_stateGazeI(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_oc_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_db_sf_marshallOut,
          c4_c_sf_marshallIn);
        c4_d_out = CV_EML_IF(13, 0, 0, *c4_handRup == 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c4_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_pc_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          chartInstance->c4_gaze = 0.0;
          c4_updateDataWrittenToVector(chartInstance, 8U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_gaze, 10U);
          _SFD_SYMBOL_SCOPE_POP();
          chartInstance->c4_tp_stateCheckUser = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
          chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateAvert;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
          chartInstance->c4_temporalCounter_i1 = 0U;
          chartInstance->c4_tp_stateAvert = 1U;
          c4_enter_atomic_stateAvert(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                       chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_qc_debug_family_names,
            c4_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U,
            c4_db_sf_marshallOut, c4_c_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(20, 0, 0, *c4_handRup == 1.0)) {
            if (CV_EML_COND(20, 0, 1, chartInstance->c4_gaze == 1.0)) {
              CV_EML_MCDC(20, 0, 0, true);
              CV_EML_IF(20, 0, 0, true);
              c4_e_out = true;
            } else {
              guard2 = true;
            }
          } else {
            c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(20, 0, 0, false);
            CV_EML_IF(20, 0, 0, false);
            c4_e_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c4_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
            chartInstance->c4_tp_stateCheckUser = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
            chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateAvert;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
            chartInstance->c4_temporalCounter_i1 = 0U;
            chartInstance->c4_tp_stateAvert = 1U;
            c4_enter_atomic_stateAvert(chartInstance);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                         chartInstance->c4_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_mc_debug_family_names,
              c4_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U,
              c4_sf_marshallOut, c4_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U,
              c4_sf_marshallOut, c4_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U,
              c4_db_sf_marshallOut, c4_c_sf_marshallIn);
            c4_f_out = CV_EML_IF(41, 0, 0, *c4_handLup == 0.0);
            _SFD_SYMBOL_SCOPE_POP();
            if (c4_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c4_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_nc_debug_family_names,
                c4_b_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U,
                c4_sf_marshallOut, c4_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
                c4_sf_marshallOut, c4_sf_marshallIn);
              chartInstance->c4_gaze = 0.0;
              c4_updateDataWrittenToVector(chartInstance, 8U);
              _SFD_DATA_RANGE_CHECK(chartInstance->c4_gaze, 10U);
              _SFD_SYMBOL_SCOPE_POP();
              chartInstance->c4_tp_stateCheckUser = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
              chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateAvert;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
              chartInstance->c4_temporalCounter_i1 = 0U;
              chartInstance->c4_tp_stateAvert = 1U;
              c4_enter_atomic_stateAvert(chartInstance);
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                           chartInstance->c4_sfEvent);
              _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_rc_debug_family_names,
                c4_debug_family_var_map);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U,
                c4_sf_marshallOut, c4_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
                c4_sf_marshallOut, c4_sf_marshallIn);
              _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_out, 2U,
                c4_db_sf_marshallOut, c4_c_sf_marshallIn);
              guard1 = false;
              if (CV_EML_COND(42, 0, 0, *c4_handLup == 1.0)) {
                if (CV_EML_COND(42, 0, 1, chartInstance->c4_gaze == 1.0)) {
                  CV_EML_MCDC(42, 0, 0, true);
                  CV_EML_IF(42, 0, 0, true);
                  c4_g_out = true;
                } else {
                  guard1 = true;
                }
              } else {
                c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
                guard1 = true;
              }

              if (guard1 == true) {
                CV_EML_MCDC(42, 0, 0, false);
                CV_EML_IF(42, 0, 0, false);
                c4_g_out = false;
              }

              _SFD_SYMBOL_SCOPE_POP();
              if (c4_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U,
                             chartInstance->c4_sfEvent);
                chartInstance->c4_tp_stateCheckUser = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
                chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateAvert;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
                chartInstance->c4_temporalCounter_i1 = 0U;
                chartInstance->c4_tp_stateAvert = 1U;
                c4_enter_atomic_stateAvert(chartInstance);
              } else {
                _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                             chartInstance->c4_sfEvent);
              }
            }
          }
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateGazeI(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  int32_T c4_i62;
  real_T c4_arg[256];
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_n_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 9U, 11U);
  for (c4_i62 = 0; c4_i62 < 256; c4_i62++) {
    c4_arg[c4_i62] = chartInstance->c4_txtGaze[c4_i62];
  }

  for (c4_i63 = 0; c4_i63 < 256; c4_i63++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i63], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i64 = 0; c4_i64 < 256; c4_i64++) {
    (*c4_b_arg)[c4_i64] = c4_arg[c4_i64];
  }

  for (c4_i65 = 0; c4_i65 < 256; c4_i65++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i65], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  chartInstance->c4_gaze = 1.0;
  c4_updateDataWrittenToVector(chartInstance, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_gaze, 10U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateInitializeIntrovert(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T *c4_extraversionW;
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_sc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(14, 0, 0, *c4_extraversionW > 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateInitializeIntrovert = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_bc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(12, 0, 0, chartInstance->c4_temporalCounter_i1 >= 5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateInitializeIntrovert = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateCheckUser;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCheckUser = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c4_sfEvent);
}

static void c4_stateExtravert(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i66;
  real_T c4_arg[256];
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T *c4_extraversionW;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_vc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(25, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateExtravert = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
    c4_b_out = CV_EML_IF(1, 0, 0, chartInstance->c4_count == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtravert = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_m_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 6U);
      for (c4_i66 = 0; c4_i66 < 256; c4_i66++) {
        c4_arg[c4_i66] = chartInstance->c4_txtSmile[c4_i66];
      }

      for (c4_i67 = 0; c4_i67 < 256; c4_i67++) {
        _SFD_DATA_RANGE_CHECK(c4_arg[c4_i67], 29U);
      }

      _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
        c4_f_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c4_sfEvent);
      for (c4_i68 = 0; c4_i68 < 256; c4_i68++) {
        (*c4_b_arg)[c4_i68] = c4_arg[c4_i68];
      }

      for (c4_i69 = 0; c4_i69 < 256; c4_i69++) {
        _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i69], 29U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(29U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_tc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
      c4_c_out = CV_EML_IF(7, 0, 0, chartInstance->c4_count == 15.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_uc_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        chartInstance->c4_count = 0.0;
        c4_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c4_tp_stateExtravert = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateCheckUser2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCheckUser2 = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateExtravert = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateCheckUser2;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCheckUser2 = 1U;
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c4_sfEvent);
}

static void c4_initializeWalkE(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_initializeWalkE = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravert;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateExtravert = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_p_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
  chartInstance->c4_count++;
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c4_sfEvent);
}

static void c4_idle(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  int32_T c4_i70;
  real_T c4_arg[256];
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  int32_T c4_i74;
  real_T c4_b_arg[256];
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  real_T *c4_extraversionW;
  real_T (*c4_c_arg)[256];
  c4_c_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_wb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(2, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateInitializeSmileI;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_stateInitializeSmileI = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_k_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 3U, 5U);
    for (c4_i70 = 0; c4_i70 < 256; c4_i70++) {
      c4_arg[c4_i70] = chartInstance->c4_txtNoSmile[c4_i70];
    }

    for (c4_i71 = 0; c4_i71 < 256; c4_i71++) {
      _SFD_DATA_RANGE_CHECK(c4_arg[c4_i71], 29U);
    }

    _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
      c4_f_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
    for (c4_i72 = 0; c4_i72 < 256; c4_i72++) {
      (*c4_c_arg)[c4_i72] = c4_arg[c4_i72];
    }

    for (c4_i73 = 0; c4_i73 < 256; c4_i73++) {
      _SFD_DATA_RANGE_CHECK((*c4_c_arg)[c4_i73], 29U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(29U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_xb_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(0, 0, 0, *c4_extraversionW > 5.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_idle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateInitalizeGazeE;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateInitalizeGazeE = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_l_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 9U, 11U);
      for (c4_i74 = 0; c4_i74 < 256; c4_i74++) {
        c4_b_arg[c4_i74] = chartInstance->c4_txtGaze[c4_i74];
      }

      for (c4_i75 = 0; c4_i75 < 256; c4_i75++) {
        _SFD_DATA_RANGE_CHECK(c4_b_arg[c4_i75], 29U);
      }

      _SFD_SET_DATA_VALUE_PTR(29U, c4_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_b_arg, c4_bc_sf_marshallOut,
        c4_f_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c4_sfEvent);
      for (c4_i76 = 0; c4_i76 < 256; c4_i76++) {
        (*c4_c_arg)[c4_i76] = c4_b_arg[c4_i76];
      }

      for (c4_i77 = 0; c4_i77 < 256; c4_i77++) {
        _SFD_DATA_RANGE_CHECK((*c4_c_arg)[c4_i77], 29U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(29U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateExtravetPose
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_hoistedGlobal;
  real_T c4_bmlID;
  uint32_T c4_b_debug_family_var_map[10];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  boolean_T c4_aVarTruthTableCondition_5;
  boolean_T c4_aVarTruthTableCondition_6;
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_poseBML[256];
  real_T c4_dv18[256];
  int32_T c4_i78;
  int32_T c4_i79;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  real_T c4_dv19[256];
  int32_T c4_i80;
  int32_T c4_i81;
  real_T c4_b_u[256];
  const mxArray *c4_b_y = NULL;
  real_T c4_dv20[256];
  int32_T c4_i82;
  int32_T c4_i83;
  real_T c4_c_u[256];
  const mxArray *c4_c_y = NULL;
  real_T c4_dv21[256];
  int32_T c4_i84;
  int32_T c4_i85;
  real_T c4_d_u[256];
  const mxArray *c4_d_y = NULL;
  real_T c4_dv22[256];
  int32_T c4_i86;
  int32_T c4_i87;
  real_T c4_e_u[256];
  const mxArray *c4_e_y = NULL;
  real_T c4_dv23[256];
  int32_T c4_i88;
  int32_T c4_i89;
  real_T c4_f_u[256];
  const mxArray *c4_f_y = NULL;
  real_T c4_dv24[256];
  int32_T c4_i90;
  int32_T c4_i91;
  real_T c4_g_u[256];
  const mxArray *c4_g_y = NULL;
  int32_T c4_i92;
  real_T c4_arg[256];
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_r_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 6.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  c4_r = 1.0 + c4_b_x;
  chartInstance->c4_m = c4_r;
  c4_updateDataWrittenToVector(chartInstance, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_m, 15U);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 13U, 15U);
  c4_hoistedGlobal = chartInstance->c4_m;
  c4_bmlID = c4_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c4_y_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_5, 4U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_6, 5U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 9U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
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
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 24);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 27);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 29);
  if (CV_EML_IF(2, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 30);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 49);
    c4_i_encStr2Arr(chartInstance, c4_dv18);
    for (c4_i78 = 0; c4_i78 < 256; c4_i78++) {
      c4_poseBML[c4_i78] = c4_dv18[c4_i78];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c4_i79 = 0; c4_i79 < 256; c4_i79++) {
      c4_u[c4_i79] = c4_poseBML[c4_i79];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -49);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 31);
    if (CV_EML_IF(2, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 32);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 55);
      c4_j_encStr2Arr(chartInstance, c4_dv19);
      for (c4_i80 = 0; c4_i80 < 256; c4_i80++) {
        c4_poseBML[c4_i80] = c4_dv19[c4_i80];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c4_i81 = 0; c4_i81 < 256; c4_i81++) {
        c4_b_u[c4_i81] = c4_poseBML[c4_i81];
      }

      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_b_y);
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -55);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 33);
      if (CV_EML_IF(2, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 34);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 61);
        c4_k_encStr2Arr(chartInstance, c4_dv20);
        for (c4_i82 = 0; c4_i82 < 256; c4_i82++) {
          c4_poseBML[c4_i82] = c4_dv20[c4_i82];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c4_i83 = 0; c4_i83 < 256; c4_i83++) {
          c4_c_u[c4_i83] = c4_poseBML[c4_i83];
        }

        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_c_y);
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -61);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 35);
        if (CV_EML_IF(2, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 36);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 67);
          c4_l_encStr2Arr(chartInstance, c4_dv21);
          for (c4_i84 = 0; c4_i84 < 256; c4_i84++) {
            c4_poseBML[c4_i84] = c4_dv21[c4_i84];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c4_i85 = 0; c4_i85 < 256; c4_i85++) {
            c4_d_u[c4_i85] = c4_poseBML[c4_i85];
          }

          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c4_d_y);
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -67);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 37);
          if (CV_EML_IF(2, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 38);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 73);
            c4_m_encStr2Arr(chartInstance, c4_dv22);
            for (c4_i86 = 0; c4_i86 < 256; c4_i86++) {
              c4_poseBML[c4_i86] = c4_dv22[c4_i86];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c4_i87 = 0; c4_i87 < 256; c4_i87++) {
              c4_e_u[c4_i87] = c4_poseBML[c4_i87];
            }

            c4_e_y = NULL;
            sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c4_e_y);
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -73);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 39);
            if (CV_EML_IF(2, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 40);
              CV_EML_FCN(2, 6);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 79);
              c4_n_encStr2Arr(chartInstance, c4_dv23);
              for (c4_i88 = 0; c4_i88 < 256; c4_i88++) {
                c4_poseBML[c4_i88] = c4_dv23[c4_i88];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c4_i89 = 0; c4_i89 < 256; c4_i89++) {
                c4_f_u[c4_i89] = c4_poseBML[c4_i89];
              }

              c4_f_y = NULL;
              sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c4_f_y);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -79);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 42);
              CV_EML_FCN(2, 3);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, 61);
              c4_k_encStr2Arr(chartInstance, c4_dv24);
              for (c4_i90 = 0; c4_i90 < 256; c4_i90++) {
                c4_poseBML[c4_i90] = c4_dv24[c4_i90];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c4_i91 = 0; c4_i91 < 256; c4_i91++) {
                c4_g_u[c4_i91] = c4_poseBML[c4_i91];
              }

              c4_g_y = NULL;
              sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c4_g_y);
              _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -61);
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c4_sfEvent, -42);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i92 = 0; c4_i92 < 256; c4_i92++) {
    c4_arg[c4_i92] = c4_poseBML[c4_i92];
  }

  for (c4_i93 = 0; c4_i93 < 256; c4_i93++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i93], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i94 = 0; c4_i94 < 256; c4_i94++) {
    (*c4_b_arg)[c4_i94] = c4_arg[c4_i94];
  }

  for (c4_i95 = 0; c4_i95 < 256; c4_i95++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i95], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateExtravetPose(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_d_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T *c4_extraversionW;
  real_T *c4_handLup;
  real_T *c4_handRup;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_dd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(31, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateExtravetPose = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard3 = false;
    guard4 = false;
    if (CV_EML_COND(30, 0, 0, *c4_handLup == 0.0)) {
      if (CV_EML_COND(30, 0, 1, *c4_handRup == 1.0)) {
        if (CV_EML_COND(30, 0, 2, chartInstance->c4_beat == 0.0)) {
          CV_EML_MCDC(30, 0, 0, true);
          CV_EML_IF(30, 0, 0, true);
          c4_b_out = true;
        } else {
          guard3 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(30, 0, 0, false);
      CV_EML_IF(30, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtravetPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateBeat;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateBeat = 1U;
      c4_enter_atomic_stateBeat(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jd_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard1 = false;
      guard2 = false;
      if (*c4_handLup == 1.0) {
        if (*c4_handRup == 1.0) {
          if (chartInstance->c4_beat2 == 0.0) {
            CV_EML_IF(37, 0, 0, true);
            c4_c_out = true;
          } else {
            guard1 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 14U, 17U);
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_IF(37, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateExtravetPose = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_state2beat;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_state2beat = 1U;
        c4_enter_atomic_state2beat(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_wc_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_db_sf_marshallOut,
          c4_c_sf_marshallIn);
        c4_d_out = CV_EML_IF(32, 0, 0, chartInstance->c4_temporalCounter_i1 >=
                             30);
        _SFD_SYMBOL_SCOPE_POP();
        if (c4_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateExtravetPose = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
          chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravert;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateExtravert = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_p_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
          chartInstance->c4_count++;
          c4_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                       chartInstance->c4_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c4_sfEvent);
}

static void c4_stateCheckUser2(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T *c4_extraversionW;
  real_T *c4_handLup;
  real_T *c4_handRup;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ad_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(29, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateCheckUser2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_id_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard3 = false;
    guard4 = false;
    if (CV_EML_COND(9, 0, 0, *c4_handLup == 0.0)) {
      if (CV_EML_COND(9, 0, 1, *c4_handRup == 1.0)) {
        if (CV_EML_COND(9, 0, 2, chartInstance->c4_beat == 0.0)) {
          CV_EML_MCDC(9, 0, 0, true);
          CV_EML_IF(9, 0, 0, true);
          c4_b_out = true;
        } else {
          guard3 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(9, 0, 0, false);
      CV_EML_IF(9, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateCheckUser2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateBeat;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateBeat = 1U;
      c4_enter_atomic_stateBeat(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hd_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard1 = false;
      guard2 = false;
      if (CV_EML_COND(34, 0, 0, *c4_handLup == 1.0)) {
        if (CV_EML_COND(34, 0, 1, *c4_handRup == 1.0)) {
          if (CV_EML_COND(34, 0, 2, chartInstance->c4_beat2 == 0.0)) {
            CV_EML_MCDC(34, 0, 0, true);
            CV_EML_IF(34, 0, 0, true);
            c4_c_out = true;
          } else {
            guard1 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 14U, 17U);
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(34, 0, 0, false);
        CV_EML_IF(34, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateCheckUser2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_state2beat;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_state2beat = 1U;
        c4_enter_atomic_state2beat(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_gd_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        chartInstance->c4_beat = 0.0;
        c4_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat, 0U);
        chartInstance->c4_beat2 = 0.0;
        c4_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat2, 17U);
        _SFD_SYMBOL_SCOPE_POP();
        chartInstance->c4_tp_stateCheckUser2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravetPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateExtravetPose = 1U;
        c4_enter_atomic_stateExtravetPose(chartInstance);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateAvert(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_bmlID;
  uint32_T c4_b_debug_family_var_map[19];
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
  real_T c4_b_nargin = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_gazeBML[256];
  real_T c4_dv25[256];
  int32_T c4_i96;
  int32_T c4_i97;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  real_T c4_dv26[256];
  int32_T c4_i98;
  int32_T c4_i99;
  real_T c4_b_u[256];
  const mxArray *c4_b_y = NULL;
  real_T c4_dv27[256];
  int32_T c4_i100;
  int32_T c4_i101;
  real_T c4_c_u[256];
  const mxArray *c4_c_y = NULL;
  real_T c4_dv28[256];
  int32_T c4_i102;
  int32_T c4_i103;
  real_T c4_d_u[256];
  const mxArray *c4_d_y = NULL;
  real_T c4_dv29[256];
  int32_T c4_i104;
  int32_T c4_i105;
  real_T c4_e_u[256];
  const mxArray *c4_e_y = NULL;
  real_T c4_dv30[256];
  int32_T c4_i106;
  int32_T c4_i107;
  real_T c4_f_u[256];
  const mxArray *c4_f_y = NULL;
  real_T c4_dv31[256];
  int32_T c4_i108;
  int32_T c4_i109;
  real_T c4_g_u[256];
  const mxArray *c4_g_y = NULL;
  real_T c4_dv32[256];
  int32_T c4_i110;
  int32_T c4_i111;
  real_T c4_h_u[256];
  const mxArray *c4_h_y = NULL;
  real_T c4_dv33[256];
  int32_T c4_i112;
  int32_T c4_i113;
  real_T c4_i_u[256];
  const mxArray *c4_i_y = NULL;
  real_T c4_dv34[256];
  int32_T c4_i114;
  int32_T c4_i115;
  real_T c4_j_u[256];
  const mxArray *c4_j_y = NULL;
  real_T c4_dv35[256];
  int32_T c4_i116;
  int32_T c4_i117;
  real_T c4_k_u[256];
  const mxArray *c4_k_y = NULL;
  real_T c4_dv36[256];
  int32_T c4_i118;
  int32_T c4_i119;
  real_T c4_l_u[256];
  const mxArray *c4_l_y = NULL;
  real_T c4_dv37[256];
  int32_T c4_i120;
  int32_T c4_i121;
  real_T c4_m_u[256];
  const mxArray *c4_m_y = NULL;
  real_T c4_dv38[256];
  int32_T c4_i122;
  int32_T c4_i123;
  real_T c4_n_u[256];
  const mxArray *c4_n_y = NULL;
  real_T c4_dv39[256];
  int32_T c4_i124;
  int32_T c4_i125;
  real_T c4_o_u[256];
  const mxArray *c4_o_y = NULL;
  real_T c4_dv40[256];
  int32_T c4_i126;
  int32_T c4_i127;
  real_T c4_p_u[256];
  const mxArray *c4_p_y = NULL;
  int32_T c4_i128;
  real_T c4_b_gazeBML[256];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ab_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_gazeAvert(chartInstance, c4_randi(chartInstance));
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 15.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  c4_r = 1.0 + c4_b_x;
  c4_bmlID = c4_r;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c4_hb_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_5, 4U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_6, 5U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_7, 6U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_8, 7U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_9, 8U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_10, 9U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_11, 10U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_12, 11U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_13, 12U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_14, 13U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_15, 14U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_gazeBML, 18U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 24);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 27);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 30);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 33);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 36);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 39);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 42);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 45);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 48);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 51);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 54);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 57);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 60);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 63);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 65);
  if (CV_EML_IF(3, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 66);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
    c4_o_encStr2Arr(chartInstance, c4_dv25);
    for (c4_i96 = 0; c4_i96 < 256; c4_i96++) {
      c4_gazeBML[c4_i96] = c4_dv25[c4_i96];
    }

    sf_mex_printf("%s =\\n", "gazeBML");
    for (c4_i97 = 0; c4_i97 < 256; c4_i97++) {
      c4_u[c4_i97] = c4_gazeBML[c4_i97];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 67);
    if (CV_EML_IF(3, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 68);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
      c4_p_encStr2Arr(chartInstance, c4_dv26);
      for (c4_i98 = 0; c4_i98 < 256; c4_i98++) {
        c4_gazeBML[c4_i98] = c4_dv26[c4_i98];
      }

      sf_mex_printf("%s =\\n", "gazeBML");
      for (c4_i99 = 0; c4_i99 < 256; c4_i99++) {
        c4_b_u[c4_i99] = c4_gazeBML[c4_i99];
      }

      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_b_y);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 69);
      if (CV_EML_IF(3, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 70);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
        c4_q_encStr2Arr(chartInstance, c4_dv27);
        for (c4_i100 = 0; c4_i100 < 256; c4_i100++) {
          c4_gazeBML[c4_i100] = c4_dv27[c4_i100];
        }

        sf_mex_printf("%s =\\n", "gazeBML");
        for (c4_i101 = 0; c4_i101 < 256; c4_i101++) {
          c4_c_u[c4_i101] = c4_gazeBML[c4_i101];
        }

        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_c_y);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 71);
        if (CV_EML_IF(3, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 72);
          CV_EML_FCN(3, 2);
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
          c4_p_encStr2Arr(chartInstance, c4_dv28);
          for (c4_i102 = 0; c4_i102 < 256; c4_i102++) {
            c4_gazeBML[c4_i102] = c4_dv28[c4_i102];
          }

          sf_mex_printf("%s =\\n", "gazeBML");
          for (c4_i103 = 0; c4_i103 < 256; c4_i103++) {
            c4_d_u[c4_i103] = c4_gazeBML[c4_i103];
          }

          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c4_d_y);
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 73);
          if (CV_EML_IF(3, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 74);
            CV_EML_FCN(3, 4);
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 121);
            c4_r_encStr2Arr(chartInstance, c4_dv29);
            for (c4_i104 = 0; c4_i104 < 256; c4_i104++) {
              c4_gazeBML[c4_i104] = c4_dv29[c4_i104];
            }

            sf_mex_printf("%s =\\n", "gazeBML");
            for (c4_i105 = 0; c4_i105 < 256; c4_i105++) {
              c4_e_u[c4_i105] = c4_gazeBML[c4_i105];
            }

            c4_e_y = NULL;
            sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c4_e_y);
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -121);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 75);
            if (CV_EML_IF(3, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 76);
              CV_EML_FCN(3, 2);
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
              c4_p_encStr2Arr(chartInstance, c4_dv30);
              for (c4_i106 = 0; c4_i106 < 256; c4_i106++) {
                c4_gazeBML[c4_i106] = c4_dv30[c4_i106];
              }

              sf_mex_printf("%s =\\n", "gazeBML");
              for (c4_i107 = 0; c4_i107 < 256; c4_i107++) {
                c4_f_u[c4_i107] = c4_gazeBML[c4_i107];
              }

              c4_f_y = NULL;
              sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c4_f_y);
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 77);
              if (CV_EML_IF(3, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 78);
                CV_EML_FCN(3, 4);
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 121);
                c4_r_encStr2Arr(chartInstance, c4_dv31);
                for (c4_i108 = 0; c4_i108 < 256; c4_i108++) {
                  c4_gazeBML[c4_i108] = c4_dv31[c4_i108];
                }

                sf_mex_printf("%s =\\n", "gazeBML");
                for (c4_i109 = 0; c4_i109 < 256; c4_i109++) {
                  c4_g_u[c4_i109] = c4_gazeBML[c4_i109];
                }

                c4_g_y = NULL;
                sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c4_g_y);
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -121);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 79);
                if (CV_EML_IF(3, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 80);
                  CV_EML_FCN(3, 5);
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, MAX_int8_T);
                  c4_s_encStr2Arr(chartInstance, c4_dv32);
                  for (c4_i110 = 0; c4_i110 < 256; c4_i110++) {
                    c4_gazeBML[c4_i110] = c4_dv32[c4_i110];
                  }

                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c4_i111 = 0; c4_i111 < 256; c4_i111++) {
                    c4_h_u[c4_i111] = c4_gazeBML[c4_i111];
                  }

                  c4_h_y = NULL;
                  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c4_h_y);
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -127);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 81);
                  if (CV_EML_IF(3, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 82);
                    CV_EML_FCN(3, 2);
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
                    c4_p_encStr2Arr(chartInstance, c4_dv33);
                    for (c4_i112 = 0; c4_i112 < 256; c4_i112++) {
                      c4_gazeBML[c4_i112] = c4_dv33[c4_i112];
                    }

                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c4_i113 = 0; c4_i113 < 256; c4_i113++) {
                      c4_i_u[c4_i113] = c4_gazeBML[c4_i113];
                    }

                    c4_i_y = NULL;
                    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c4_i_y);
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 83);
                    if (CV_EML_IF(3, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 84);
                      CV_EML_FCN(3, 1);
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                      c4_o_encStr2Arr(chartInstance, c4_dv34);
                      for (c4_i114 = 0; c4_i114 < 256; c4_i114++) {
                        c4_gazeBML[c4_i114] = c4_dv34[c4_i114];
                      }

                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c4_i115 = 0; c4_i115 < 256; c4_i115++) {
                        c4_j_u[c4_i115] = c4_gazeBML[c4_i115];
                      }

                      c4_j_y = NULL;
                      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c4_j_y);
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 85);
                      if (CV_EML_IF(3, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 86);
                        CV_EML_FCN(3, 1);
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                        c4_o_encStr2Arr(chartInstance, c4_dv35);
                        for (c4_i116 = 0; c4_i116 < 256; c4_i116++) {
                          c4_gazeBML[c4_i116] = c4_dv35[c4_i116];
                        }

                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c4_i117 = 0; c4_i117 < 256; c4_i117++) {
                          c4_k_u[c4_i117] = c4_gazeBML[c4_i117];
                        }

                        c4_k_y = NULL;
                        sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c4_k_y);
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                      } else {
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 87);
                        if (CV_EML_IF(3, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 88);
                          CV_EML_FCN(3, 1);
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                          c4_o_encStr2Arr(chartInstance, c4_dv36);
                          for (c4_i118 = 0; c4_i118 < 256; c4_i118++) {
                            c4_gazeBML[c4_i118] = c4_dv36[c4_i118];
                          }

                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c4_i119 = 0; c4_i119 < 256; c4_i119++) {
                            c4_l_u[c4_i119] = c4_gazeBML[c4_i119];
                          }

                          c4_l_y = NULL;
                          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c4_l_y);
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                        } else {
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 89);
                          if (CV_EML_IF(3, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 90);
                            CV_EML_FCN(3, 3);
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                            c4_q_encStr2Arr(chartInstance, c4_dv37);
                            for (c4_i120 = 0; c4_i120 < 256; c4_i120++) {
                              c4_gazeBML[c4_i120] = c4_dv37[c4_i120];
                            }

                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c4_i121 = 0; c4_i121 < 256; c4_i121++) {
                              c4_m_u[c4_i121] = c4_gazeBML[c4_i121];
                            }

                            c4_m_y = NULL;
                            sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c4_m_y);
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
                          } else {
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 91);
                            if (CV_EML_IF(3, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 92);
                              CV_EML_FCN(3, 3);
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                              c4_q_encStr2Arr(chartInstance, c4_dv38);
                              for (c4_i122 = 0; c4_i122 < 256; c4_i122++) {
                                c4_gazeBML[c4_i122] = c4_dv38[c4_i122];
                              }

                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c4_i123 = 0; c4_i123 < 256; c4_i123++) {
                                c4_n_u[c4_i123] = c4_gazeBML[c4_i123];
                              }

                              c4_n_y = NULL;
                              sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c4_n_y);
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
                            } else {
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 93);
                              if (CV_EML_IF(3, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 94);
                                CV_EML_FCN(3, 3);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                                c4_q_encStr2Arr(chartInstance, c4_dv39);
                                for (c4_i124 = 0; c4_i124 < 256; c4_i124++) {
                                  c4_gazeBML[c4_i124] = c4_dv39[c4_i124];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c4_i125 = 0; c4_i125 < 256; c4_i125++) {
                                  c4_o_u[c4_i125] = c4_gazeBML[c4_i125];
                                }

                                c4_o_y = NULL;
                                sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c4_o_y);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent,
                                              -115);
                              } else {
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 96);
                                CV_EML_FCN(3, 3);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                                c4_q_encStr2Arr(chartInstance, c4_dv40);
                                for (c4_i126 = 0; c4_i126 < 256; c4_i126++) {
                                  c4_gazeBML[c4_i126] = c4_dv40[c4_i126];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c4_i127 = 0; c4_i127 < 256; c4_i127++) {
                                  c4_p_u[c4_i127] = c4_gazeBML[c4_i127];
                                }

                                c4_p_y = NULL;
                                sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_p_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c4_p_y);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent,
                                              -115);
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

  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -96);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i128 = 0; c4_i128 < 256; c4_i128++) {
    c4_b_gazeBML[c4_i128] = c4_gazeBML[c4_i128];
  }

  c4_sendBML(chartInstance, c4_b_gazeBML);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateAvert(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 1.0;
  boolean_T c4_b_out;
  real_T c4_c_nargin = 0.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  boolean_T c4_d_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_hoistedGlobal;
  real_T c4_dv41[256];
  int32_T c4_i129;
  real_T c4_arg[256];
  int32_T c4_i130;
  int32_T c4_i131;
  int32_T c4_i132;
  real_T *c4_extraversionW;
  real_T *c4_handRup;
  real_T *c4_handLup;
  real_T (*c4_b_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(23, 0, 0, *c4_extraversionW > 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateAvert = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(22, 0, 0, *c4_handRup == 1.0)) {
      if (CV_EML_COND(22, 0, 1, chartInstance->c4_gaze == 0.0)) {
        CV_EML_MCDC(22, 0, 0, true);
        CV_EML_IF(22, 0, 0, true);
        c4_b_out = true;
      } else {
        guard2 = true;
      }
    } else {
      c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(22, 0, 0, false);
      CV_EML_IF(22, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateAvert = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_stateGazeI = 1U;
      c4_enter_atomic_stateGazeI(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ic_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_db_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(39, 0, 0, *c4_handLup == 1.0)) {
        if (CV_EML_COND(39, 0, 1, chartInstance->c4_gaze == 0.0)) {
          CV_EML_MCDC(39, 0, 0, true);
          CV_EML_IF(39, 0, 0, true);
          c4_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 8U, 10U);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(39, 0, 0, false);
        CV_EML_IF(39, 0, 0, false);
        c4_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateAvert = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
        chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateGazeI;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
        chartInstance->c4_temporalCounter_i1 = 0U;
        chartInstance->c4_tp_stateGazeI = 1U;
        c4_enter_atomic_stateGazeI(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ld_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_db_sf_marshallOut,
          c4_c_sf_marshallIn);
        c4_d_out = CV_EML_IF(16, 0, 0, chartInstance->c4_temporalCounter_i1 >= 5);
        _SFD_SYMBOL_SCOPE_POP();
        if (c4_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateAvert = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
          chartInstance->c4_is_c4_testKinectGazeWaveGUI =
            c4_IN_stateIntrovertPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
          chartInstance->c4_temporalCounter_i1 = 0U;
          chartInstance->c4_tp_stateIntrovertPose = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ib_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
            c4_sf_marshallOut, c4_sf_marshallIn);
          c4_r = c4_rand(chartInstance);
          c4_x = c4_r * 18.0;
          c4_b_x = c4_x;
          c4_b_x = muDoubleScalarFloor(c4_b_x);
          c4_r = 1.0 + c4_b_x;
          chartInstance->c4_n = c4_r;
          c4_updateDataWrittenToVector(chartInstance, 12U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_n, 14U);
          c4_errorIfDataNotWrittenToFcn(chartInstance, 12U, 14U);
          c4_hoistedGlobal = chartInstance->c4_n;
          c4_introvertIdlePose(chartInstance, c4_hoistedGlobal, c4_dv41);
          for (c4_i129 = 0; c4_i129 < 256; c4_i129++) {
            c4_arg[c4_i129] = c4_dv41[c4_i129];
          }

          for (c4_i130 = 0; c4_i130 < 256; c4_i130++) {
            _SFD_DATA_RANGE_CHECK(c4_arg[c4_i130], 29U);
          }

          _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
          _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
          _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
            c4_f_sf_marshallIn);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                       chartInstance->c4_sfEvent);
          for (c4_i131 = 0; c4_i131 < 256; c4_i131++) {
            (*c4_b_arg)[c4_i131] = c4_arg[c4_i131];
          }

          for (c4_i132 = 0; c4_i132 < 256; c4_i132++) {
            _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i132], 29U);
          }

          sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
          _SFD_SYMBOL_SCOPE_POP();
          _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
          _SFD_UNSET_DATA_VALUE_PTR(29U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                       chartInstance->c4_sfEvent);
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_stateBeat(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  int32_T c4_i133;
  real_T c4_arg[256];
  int32_T c4_i134;
  int32_T c4_i135;
  int32_T c4_i136;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_tb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
  chartInstance->c4_count++;
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 2U, 4U);
  for (c4_i133 = 0; c4_i133 < 256; c4_i133++) {
    c4_arg[c4_i133] = chartInstance->c4_txtBeat[c4_i133];
  }

  for (c4_i134 = 0; c4_i134 < 256; c4_i134++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i134], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i135 = 0; c4_i135 < 256; c4_i135++) {
    (*c4_b_arg)[c4_i135] = c4_arg[c4_i135];
  }

  for (c4_i136 = 0; c4_i136 < 256; c4_i136++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i136], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  chartInstance->c4_beat = 1.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat, 0U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateBeat(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
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
  real_T *c4_extraversionW;
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_bd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(26, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateBeat = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_yc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(6, 0, 0, chartInstance->c4_temporalCounter_i1 >= 15);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateBeat = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravert;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtravert = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_p_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
      chartInstance->c4_count++;
      c4_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_state2beat(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  int32_T c4_i137;
  real_T c4_arg[256];
  int32_T c4_i138;
  int32_T c4_i139;
  int32_T c4_i140;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ub_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
  chartInstance->c4_count++;
  c4_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 18U);
  for (c4_i137 = 0; c4_i137 < 256; c4_i137++) {
    c4_arg[c4_i137] = chartInstance->c4_txtBeat2[c4_i137];
  }

  for (c4_i138 = 0; c4_i138 < 256; c4_i138++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i138], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i139 = 0; c4_i139 < 256; c4_i139++) {
    (*c4_b_arg)[c4_i139] = c4_arg[c4_i139];
  }

  for (c4_i140 = 0; c4_i140 < 256; c4_i140++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i140], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  chartInstance->c4_beat2 = 1.0;
  c4_updateDataWrittenToVector(chartInstance, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_beat2, 17U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_state2beat(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  real_T *c4_extraversionW;
  c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_cd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_db_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(35, 0, 0, *c4_extraversionW <= 5.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_state2beat = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_idle = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_xc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_db_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_b_out = CV_EML_IF(36, 0, 0, chartInstance->c4_temporalCounter_i1 >= 15);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_state2beat = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_testKinectGazeWaveGUI = c4_IN_stateExtravert;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtravert = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_p_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 3U);
      chartInstance->c4_count++;
      c4_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_count, 3U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c4_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
}

static void c4_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[99];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[99];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i141;
  static char_T c4_cv1[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i142;
  static real_T c4_dv42[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 66.0, 65.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i143;
  int32_T c4_i144;
  int32_T c4_i145;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i141 = 0; c4_i141 < 99; c4_i141++) {
    c4_mystr[c4_i141] = c4_cv1[c4_i141];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i142 = 0; c4_i142 < 99; c4_i142++) {
    c4_arr[c4_i142] = c4_dv42[c4_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 99.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i143 = 0; c4_i143 < 256; c4_i143++) {
    c4_tt[c4_i143] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i144 = 0; c4_i144 < 99; c4_i144++) {
    c4_tt[c4_i144] = c4_arr[c4_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i145 = 0; c4_i145 < 256; c4_i145++) {
    c4_myarr256[c4_i145] = c4_tt[c4_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_b_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[240];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[240];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i146;
  static char_T c4_cv2[240] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '6', '\"', ' ',
    ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=',
    '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.',
    '3', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't',
    'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<',
    'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a',
    'u', '=', '\"', 'w', 'i', 'd', 'e', '\"', ' ', ' ', 'a', 'm', 'o', 'u', 'n',
    't', '=', '\"', '0', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i147;
  static real_T c4_dv43[240] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0,
    111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0, 34.0, 47.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0,
    66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0,
    111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0,
    67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0,
    84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 119.0, 105.0, 100.0, 101.0,
    34.0, 32.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i148;
  int32_T c4_i149;
  int32_T c4_i150;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_c_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i146 = 0; c4_i146 < 240; c4_i146++) {
    c4_mystr[c4_i146] = c4_cv2[c4_i146];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i147 = 0; c4_i147 < 240; c4_i147++) {
    c4_arr[c4_i147] = c4_dv43[c4_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 240.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i148 = 0; c4_i148 < 256; c4_i148++) {
    c4_tt[c4_i148] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i149 = 0; c4_i149 < 240; c4_i149++) {
    c4_tt[c4_i149] = c4_arr[c4_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i150 = 0; c4_i150 < 256; c4_i150++) {
    c4_myarr256[c4_i150] = c4_tt[c4_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[236];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[236];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i151;
  static char_T c4_cv3[236] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '6', '\"', ' ',
    ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=',
    '\"', '3', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0',
    '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't', 'a',
    'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '3', '5',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '\"', '/', '>', '<',
    'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a',
    'u', '=', '\"', 'w', 'i', 'd', 'e', '\"', ' ', ' ', 'a', 'm', 'o', 'u', 'n',
    't', '=', '\"', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i152;
  static real_T c4_dv44[236] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 51.0, 53.0, 34.0, 32.0, 97.0, 109.0,
    111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0,
    67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0,
    84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 51.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 119.0, 105.0, 100.0, 101.0, 34.0, 32.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i153;
  int32_T c4_i154;
  int32_T c4_i155;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_d_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i151 = 0; c4_i151 < 236; c4_i151++) {
    c4_mystr[c4_i151] = c4_cv3[c4_i151];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i152 = 0; c4_i152 < 236; c4_i152++) {
    c4_arr[c4_i152] = c4_dv44[c4_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 236.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i153 = 0; c4_i153 < 256; c4_i153++) {
    c4_tt[c4_i153] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i154 = 0; c4_i154 < 236; c4_i154++) {
    c4_tt[c4_i154] = c4_arr[c4_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i155 = 0; c4_i155 < 256; c4_i155++) {
    c4_myarr256[c4_i155] = c4_tt[c4_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_d_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[91];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[91];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i156;
  static char_T c4_cv4[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H', 'i',
    'g', 'h', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i157;
  static real_T c4_dv45[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i158;
  int32_T c4_i159;
  int32_T c4_i160;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_e_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i156 = 0; c4_i156 < 91; c4_i156++) {
    c4_mystr[c4_i156] = c4_cv4[c4_i156];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i157 = 0; c4_i157 < 91; c4_i157++) {
    c4_arr[c4_i157] = c4_dv45[c4_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i158 = 0; c4_i158 < 256; c4_i158++) {
    c4_tt[c4_i158] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i159 = 0; c4_i159 < 91; c4_i159++) {
    c4_tt[c4_i159] = c4_arr[c4_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i160 = 0; c4_i160 < 256; c4_i160++) {
    c4_myarr256[c4_i160] = c4_tt[c4_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_e_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[91];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[91];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i161;
  static char_T c4_cv5[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'H', 'i',
    'g', 'h', 'B', 't', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i162;
  static real_T c4_dv46[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 72.0, 105.0, 103.0, 104.0, 66.0, 116.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i163;
  int32_T c4_i164;
  int32_T c4_i165;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_f_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i161 = 0; c4_i161 < 91; c4_i161++) {
    c4_mystr[c4_i161] = c4_cv5[c4_i161];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i162 = 0; c4_i162 < 91; c4_i162++) {
    c4_arr[c4_i162] = c4_dv46[c4_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i163 = 0; c4_i163 < 256; c4_i163++) {
    c4_tt[c4_i163] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i164 = 0; c4_i164 < 91; c4_i164++) {
    c4_tt[c4_i164] = c4_arr[c4_i164];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i165 = 0; c4_i165 < 256; c4_i165++) {
    c4_myarr256[c4_i165] = c4_tt[c4_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_f_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[61];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[61];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i166;
  static char_T c4_cv6[61] = { 's', 'c', 'e', 'n', 'e', '.', 'g', 'e', 't', 'P',
    'a', 'w', 'n', '(', '\\', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\\', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 'i', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'V', 'e', 'c', '(', '0', '.', '2', ',', '1', '.', '2',
    ',', '0', '.', '3', ')', ')' };

  int32_T c4_i167;
  static real_T c4_dv47[61] = { 115.0, 99.0, 101.0, 110.0, 101.0, 46.0, 103.0,
    101.0, 116.0, 80.0, 97.0, 119.0, 110.0, 40.0, 92.0, 34.0, 103.0, 97.0, 122.0,
    101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 92.0, 34.0, 41.0, 46.0, 115.0,
    101.0, 116.0, 80.0, 111.0, 115.0, 105.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 86.0, 101.0, 99.0, 40.0, 48.0, 46.0, 50.0, 44.0, 49.0, 46.0,
    50.0, 44.0, 48.0, 46.0, 51.0, 41.0, 41.0 };

  int32_T c4_i168;
  int32_T c4_i169;
  int32_T c4_i170;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_g_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i166 = 0; c4_i166 < 61; c4_i166++) {
    c4_mystr[c4_i166] = c4_cv6[c4_i166];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i167 = 0; c4_i167 < 61; c4_i167++) {
    c4_arr[c4_i167] = c4_dv47[c4_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 61.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i168 = 0; c4_i168 < 256; c4_i168++) {
    c4_tt[c4_i168] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i169 = 0; c4_i169 < 61; c4_i169++) {
    c4_tt[c4_i169] = c4_arr[c4_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i170 = 0; c4_i170 < 256; c4_i170++) {
    c4_myarr256[c4_i170] = c4_tt[c4_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_g_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i171;
  static char_T c4_cv7[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i172;
  static real_T c4_dv48[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0,
    111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0,
    34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i173;
  int32_T c4_i174;
  int32_T c4_i175;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_h_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i171 = 0; c4_i171 < 95; c4_i171++) {
    c4_mystr[c4_i171] = c4_cv7[c4_i171];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i172 = 0; c4_i172 < 95; c4_i172++) {
    c4_arr[c4_i172] = c4_dv48[c4_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i173 = 0; c4_i173 < 256; c4_i173++) {
    c4_tt[c4_i173] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i174 = 0; c4_i174 < 95; c4_i174++) {
    c4_tt[c4_i174] = c4_arr[c4_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i175 = 0; c4_i175 < 256; c4_i175++) {
    c4_myarr256[c4_i175] = c4_tt[c4_i175];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_h_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[102];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[102];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i176;
  static char_T c4_cv8[102] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o', 't',
    'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a', 'l',
    'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', '0', ' ', '0',
    ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c4_i177;
  static real_T c4_dv49[102] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 32.0, 48.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i178;
  int32_T c4_i179;
  int32_T c4_i180;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_i_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i176 = 0; c4_i176 < 102; c4_i176++) {
    c4_mystr[c4_i176] = c4_cv8[c4_i176];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i177 = 0; c4_i177 < 102; c4_i177++) {
    c4_arr[c4_i177] = c4_dv49[c4_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 102.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i178 = 0; c4_i178 < 256; c4_i178++) {
    c4_tt[c4_i178] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i179 = 0; c4_i179 < 102; c4_i179++) {
    c4_tt[c4_i179] = c4_arr[c4_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i180 = 0; c4_i180 < 256; c4_i180++) {
    c4_myarr256[c4_i180] = c4_tt[c4_i180];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_rand(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  return c4_eml_rand(chartInstance);
}

static real_T c4_eml_rand(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i181;
  uint32_T c4_icng;
  uint32_T c4_jsr;
  uint32_T c4_u1;
  uint32_T c4_u2;
  uint32_T c4_ui;
  uint32_T c4_b_ui;
  real_T c4_c_r;
  real_T c4_d1;
  uint32_T c4_uv2[625];
  int32_T c4_i182;
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
      for (c4_i181 = 0; c4_i181 < 2; c4_i181++) {
        chartInstance->c4_b_state[c4_i181] = 362436069U + 158852560U * (uint32_T)
          c4_i181;
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
      for (c4_i182 = 0; c4_i182 < 625; c4_i182++) {
        chartInstance->c4_c_state[c4_i182] = c4_uv2[c4_i182];
      }

      chartInstance->c4_c_state_not_empty = true;
    }

    c4_d2 = c4_c_eml_rand_mt19937ar(chartInstance, chartInstance->c4_c_state);
    c4_r = c4_d2;
  }

  return c4_r;
}

static void c4_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625])
{
  real_T c4_d3;
  int32_T c4_i183;
  c4_d3 = 5489.0;
  for (c4_i183 = 0; c4_i183 < 625; c4_i183++) {
    c4_d_state[c4_i183] = 0U;
  }

  c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d3);
}

static void c4_twister_state_vector(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625])
{
  int32_T c4_i184;
  for (c4_i184 = 0; c4_i184 < 625; c4_i184++) {
    c4_b_mt[c4_i184] = c4_mt[c4_i184];
  }

  c4_b_twister_state_vector(chartInstance, c4_b_mt, c4_seed);
}

static void c4_b_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
  *c4_r)
{
  int32_T c4_i185;
  for (c4_i185 = 0; c4_i185 < 625; c4_i185++) {
    c4_e_state[c4_i185] = c4_d_state[c4_i185];
  }

  *c4_r = c4_c_eml_rand_mt19937ar(chartInstance, c4_e_state);
}

static void c4_eml_error(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  int32_T c4_i186;
  static char_T c4_cv9[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c4_u[37];
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  for (c4_i186 = 0; c4_i186 < 37; c4_i186++) {
    c4_u[c4_i186] = c4_cv9[c4_i186];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c4_y));
}

static void c4_i_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[248];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[248];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i187;
  static char_T c4_cv10[248] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '2', '\"', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r',
    'm', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', 'f',
    'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u',
    '=', '\"', '6', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u',
    'n', 't', '=', '\"', '1', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i188;
  static real_T c4_dv50[248] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 50.0, 34.0, 32.0, 110.0, 97.0, 109.0, 101.0, 61.0,
    34.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 64.0, 73.0, 100.0, 108.0,
    101.0, 48.0, 49.0, 95.0, 65.0, 114.0, 109.0, 83.0, 116.0, 114.0, 101.0,
    116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 32.0, 115.0, 116.0,
    97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0,
    34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0,
    121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0,
    117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i189;
  int32_T c4_i190;
  int32_T c4_i191;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_s_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i187 = 0; c4_i187 < 248; c4_i187++) {
    c4_mystr[c4_i187] = c4_cv10[c4_i187];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i188 = 0; c4_i188 < 248; c4_i188++) {
    c4_arr[c4_i188] = c4_dv50[c4_i188];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 248.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i189 = 0; c4_i189 < 256; c4_i189++) {
    c4_tt[c4_i189] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i190 = 0; c4_i190 < 248; c4_i190++) {
    c4_tt[c4_i190] = c4_arr[c4_i190];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i191 = 0; c4_i191 < 256; c4_i191++) {
    c4_myarr256[c4_i191] = c4_tt[c4_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_j_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[248];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[248];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i192;
  static char_T c4_cv11[248] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '3', '\"', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r',
    'm', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', 'f',
    'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u',
    '=', '\"', '6', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u',
    'n', 't', '=', '\"', '1', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't',
    'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e',
    '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i193;
  static real_T c4_dv51[248] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 51.0, 34.0, 32.0, 110.0, 97.0, 109.0, 101.0, 61.0,
    34.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 64.0, 73.0, 100.0, 108.0,
    101.0, 48.0, 49.0, 95.0, 65.0, 114.0, 109.0, 83.0, 116.0, 114.0, 101.0,
    116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0,
    101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 32.0, 115.0, 116.0,
    97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0,
    34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0,
    121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0,
    105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0,
    117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i194;
  int32_T c4_i195;
  int32_T c4_i196;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_t_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i192 = 0; c4_i192 < 248; c4_i192++) {
    c4_mystr[c4_i192] = c4_cv11[c4_i192];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i193 = 0; c4_i193 < 248; c4_i193++) {
    c4_arr[c4_i193] = c4_dv51[c4_i193];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 248.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i194 = 0; c4_i194 < 256; c4_i194++) {
    c4_tt[c4_i194] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i195 = 0; c4_i195 < 248; c4_i195++) {
    c4_tt[c4_i195] = c4_arr[c4_i195];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i196 = 0; c4_i196 < 256; c4_i196++) {
    c4_myarr256[c4_i196] = c4_tt[c4_i196];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_k_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[244];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[244];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i197;
  static char_T c4_cv12[244] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '2', '\"', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o',
    'I', 'd', 'l', 'e', '0', '3', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ',
    't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '6',
    '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"',
    '1', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O',
    'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't',
    'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5',
    '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i198;
  static real_T c4_dv52[244] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 50.0, 34.0, 32.0, 110.0, 97.0, 109.0, 101.0, 61.0,
    34.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 64.0, 73.0, 100.0, 108.0,
    101.0, 48.0, 49.0, 95.0, 84.0, 111.0, 73.0, 100.0, 108.0, 101.0, 48.0, 51.0,
    34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0,
    34.0, 54.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0,
    48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0,
    97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0,
    66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0,
    111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i199;
  int32_T c4_i200;
  int32_T c4_i201;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_u_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i197 = 0; c4_i197 < 244; c4_i197++) {
    c4_mystr[c4_i197] = c4_cv12[c4_i197];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i198 = 0; c4_i198 < 244; c4_i198++) {
    c4_arr[c4_i198] = c4_dv52[c4_i198];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 244.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i199 = 0; c4_i199 < 256; c4_i199++) {
    c4_tt[c4_i199] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i200 = 0; c4_i200 < 244; c4_i200++) {
    c4_tt[c4_i200] = c4_arr[c4_i200];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i201 = 0; c4_i201 < 256; c4_i201++) {
    c4_myarr256[c4_i201] = c4_tt[c4_i201];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_l_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[226];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[226];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i202;
  static char_T c4_cv13[226] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l',
    'e', '0', '3', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"',
    'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '6', '\"', ' ', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2',
    '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>',
    '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C',
    'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    'a', 'u', '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=',
    '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i203;
  static real_T c4_dv53[226] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0,
    99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0,
    83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0,
    72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 32.0, 115.0,
    116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0,
    61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0,
    116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0,
    115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0,
    97.0, 117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0,
    50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i204;
  int32_T c4_i205;
  int32_T c4_i206;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_v_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i202 = 0; c4_i202 < 226; c4_i202++) {
    c4_mystr[c4_i202] = c4_cv13[c4_i202];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i203 = 0; c4_i203 < 226; c4_i203++) {
    c4_arr[c4_i203] = c4_dv53[c4_i203];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 226.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i204 = 0; c4_i204 < 256; c4_i204++) {
    c4_tt[c4_i204] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i205 = 0; c4_i205 < 226; c4_i205++) {
    c4_tt[c4_i205] = c4_arr[c4_i205];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i206 = 0; c4_i206 < 256; c4_i206++) {
    c4_myarr256[c4_i206] = c4_tt[c4_i206];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_m_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[235];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[235];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i207;
  static char_T c4_cv14[235] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', '/', '>',
    '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C',
    'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    'a', 'u', '=', '\"', '6', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"',
    '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o',
    'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ',
    't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n',
    'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i208;
  static real_T c4_dv54[235] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0,
    32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0,
    32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0,
    50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0,
    112.0, 101.0, 61.0, 34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0,
    100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0,
    61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0,
    61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0,
    34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i209;
  int32_T c4_i210;
  int32_T c4_i211;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_w_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i207 = 0; c4_i207 < 235; c4_i207++) {
    c4_mystr[c4_i207] = c4_cv14[c4_i207];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i208 = 0; c4_i208 < 235; c4_i208++) {
    c4_arr[c4_i208] = c4_dv54[c4_i208];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 235.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i209 = 0; c4_i209 < 256; c4_i209++) {
    c4_tt[c4_i209] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i210 = 0; c4_i210 < 235; c4_i210++) {
    c4_tt[c4_i210] = c4_arr[c4_i210];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i211 = 0; c4_i211 < 256; c4_i211++) {
    c4_myarr256[c4_i211] = c4_tt[c4_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_n_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[253];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[253];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i212;
  static char_T c4_cv15[253] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '1', '\"', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h',
    'o', 'u', 'l', 'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1',
    '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 'a', 'u', '=', '\"', '6', '\"', ' ', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '1', '\"', '/', '>', '<', 'f',
    'a', 'c', 'e', ' ', 't', 'y', 'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"',
    ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u',
    '=', '\"', '1', '2', '\"', ' ', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '5', '\"', ' ', 'a', 'm', 'o', 'u',
    'n', 't', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i213;
  static real_T c4_dv55[253] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 49.0, 34.0, 32.0, 110.0, 97.0, 109.0, 101.0, 61.0,
    34.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 64.0, 73.0, 100.0, 108.0,
    101.0, 48.0, 49.0, 95.0, 83.0, 104.0, 111.0, 117.0, 108.0, 100.0, 101.0,
    114.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0,
    34.0, 32.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0,
    32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0,
    111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 70.0, 65.0,
    67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0,
    84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 50.0, 53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i214;
  int32_T c4_i215;
  int32_T c4_i216;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_x_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i212 = 0; c4_i212 < 253; c4_i212++) {
    c4_mystr[c4_i212] = c4_cv15[c4_i212];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i213 = 0; c4_i213 < 253; c4_i213++) {
    c4_arr[c4_i213] = c4_dv55[c4_i213];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 253.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i214 = 0; c4_i214 < 256; c4_i214++) {
    c4_tt[c4_i214] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i215 = 0; c4_i215 < 253; c4_i215++) {
    c4_tt[c4_i215] = c4_arr[c4_i215];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i216 = 0; c4_i216 < 256; c4_i216++) {
    c4_myarr256[c4_i216] = c4_tt[c4_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_randi(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance)
{
  real_T c4_r;
  real_T c4_x;
  real_T c4_b_x;
  c4_r = c4_rand(chartInstance);
  c4_x = c4_r * 18.0;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarFloor(c4_b_x);
  return 1.0 + c4_b_x;
}

static void c4_o_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[112];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[112];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i217;
  static char_T c4_cv16[112] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i218;
  static real_T c4_dv56[112] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i219;
  int32_T c4_i220;
  int32_T c4_i221;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_bb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i217 = 0; c4_i217 < 112; c4_i217++) {
    c4_mystr[c4_i217] = c4_cv16[c4_i217];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i218 = 0; c4_i218 < 112; c4_i218++) {
    c4_arr[c4_i218] = c4_dv56[c4_i218];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 112.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i219 = 0; c4_i219 < 256; c4_i219++) {
    c4_tt[c4_i219] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i220 = 0; c4_i220 < 112; c4_i220++) {
    c4_tt[c4_i220] = c4_arr[c4_i220];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i221 = 0; c4_i221 < 256; c4_i221++) {
    c4_myarr256[c4_i221] = c4_tt[c4_i221];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_p_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[116];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[116];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i222;
  static char_T c4_cv17[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c4_i223;
  static real_T c4_dv57[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i224;
  int32_T c4_i225;
  int32_T c4_i226;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_cb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i222 = 0; c4_i222 < 116; c4_i222++) {
    c4_mystr[c4_i222] = c4_cv17[c4_i222];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i223 = 0; c4_i223 < 116; c4_i223++) {
    c4_arr[c4_i223] = c4_dv57[c4_i223];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i224 = 0; c4_i224 < 256; c4_i224++) {
    c4_tt[c4_i224] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i225 = 0; c4_i225 < 116; c4_i225++) {
    c4_tt[c4_i225] = c4_arr[c4_i225];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i226 = 0; c4_i226 < 256; c4_i226++) {
    c4_myarr256[c4_i226] = c4_tt[c4_i226];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_q_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[117];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[117];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i227;
  static char_T c4_cv18[117] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i228;
  static real_T c4_dv58[117] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0,
    114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i229;
  int32_T c4_i230;
  int32_T c4_i231;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_db_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i227 = 0; c4_i227 < 117; c4_i227++) {
    c4_mystr[c4_i227] = c4_cv18[c4_i227];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i228 = 0; c4_i228 < 117; c4_i228++) {
    c4_arr[c4_i228] = c4_dv58[c4_i228];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i229 = 0; c4_i229 < 256; c4_i229++) {
    c4_tt[c4_i229] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i230 = 0; c4_i230 < 117; c4_i230++) {
    c4_tt[c4_i230] = c4_arr[c4_i230];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i231 = 0; c4_i231 < 256; c4_i231++) {
    c4_myarr256[c4_i231] = c4_tt[c4_i231];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_r_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[113];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[113];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i232;
  static char_T c4_cv19[113] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i233;
  static real_T c4_dv59[113] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0,
    116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i234;
  int32_T c4_i235;
  int32_T c4_i236;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_eb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i232 = 0; c4_i232 < 113; c4_i232++) {
    c4_mystr[c4_i232] = c4_cv19[c4_i232];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i233 = 0; c4_i233 < 113; c4_i233++) {
    c4_arr[c4_i233] = c4_dv59[c4_i233];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 113.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i234 = 0; c4_i234 < 256; c4_i234++) {
    c4_tt[c4_i234] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i235 = 0; c4_i235 < 113; c4_i235++) {
    c4_tt[c4_i235] = c4_arr[c4_i235];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i236 = 0; c4_i236 < 256; c4_i236++) {
    c4_myarr256[c4_i236] = c4_tt[c4_i236];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_s_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[112];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[112];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i237;
  static char_T c4_cv20[112] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i238;
  static real_T c4_dv60[112] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i239;
  int32_T c4_i240;
  int32_T c4_i241;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_fb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i237 = 0; c4_i237 < 112; c4_i237++) {
    c4_mystr[c4_i237] = c4_cv20[c4_i237];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i238 = 0; c4_i238 < 112; c4_i238++) {
    c4_arr[c4_i238] = c4_dv60[c4_i238];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 112.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i239 = 0; c4_i239 < 256; c4_i239++) {
    c4_tt[c4_i239] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i240 = 0; c4_i240 < 112; c4_i240++) {
    c4_tt[c4_i240] = c4_arr[c4_i240];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i241 = 0; c4_i241 < 256; c4_i241++) {
    c4_myarr256[c4_i241] = c4_tt[c4_i241];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_t_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[92];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[92];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i242;
  static char_T c4_cv21[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i243;
  static real_T c4_dv61[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i244;
  int32_T c4_i245;
  int32_T c4_i246;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_jb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i242 = 0; c4_i242 < 92; c4_i242++) {
    c4_mystr[c4_i242] = c4_cv21[c4_i242];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i243 = 0; c4_i243 < 92; c4_i243++) {
    c4_arr[c4_i243] = c4_dv61[c4_i243];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i244 = 0; c4_i244 < 256; c4_i244++) {
    c4_tt[c4_i244] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i245 = 0; c4_i245 < 92; c4_i245++) {
    c4_tt[c4_i245] = c4_arr[c4_i245];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i246 = 0; c4_i246 < 256; c4_i246++) {
    c4_myarr256[c4_i246] = c4_tt[c4_i246];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_u_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[92];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[92];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i247;
  static char_T c4_cv22[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i248;
  static real_T c4_dv62[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i249;
  int32_T c4_i250;
  int32_T c4_i251;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_kb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i247 = 0; c4_i247 < 92; c4_i247++) {
    c4_mystr[c4_i247] = c4_cv22[c4_i247];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i248 = 0; c4_i248 < 92; c4_i248++) {
    c4_arr[c4_i248] = c4_dv62[c4_i248];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i249 = 0; c4_i249 < 256; c4_i249++) {
    c4_tt[c4_i249] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i250 = 0; c4_i250 < 92; c4_i250++) {
    c4_tt[c4_i250] = c4_arr[c4_i250];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i251 = 0; c4_i251 < 256; c4_i251++) {
    c4_myarr256[c4_i251] = c4_tt[c4_i251];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_v_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i252;
  static char_T c4_cv23[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i253;
  static real_T c4_dv63[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i254;
  int32_T c4_i255;
  int32_T c4_i256;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_lb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i252 = 0; c4_i252 < 93; c4_i252++) {
    c4_mystr[c4_i252] = c4_cv23[c4_i252];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i253 = 0; c4_i253 < 93; c4_i253++) {
    c4_arr[c4_i253] = c4_dv63[c4_i253];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i254 = 0; c4_i254 < 256; c4_i254++) {
    c4_tt[c4_i254] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i255 = 0; c4_i255 < 93; c4_i255++) {
    c4_tt[c4_i255] = c4_arr[c4_i255];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i256 = 0; c4_i256 < 256; c4_i256++) {
    c4_myarr256[c4_i256] = c4_tt[c4_i256];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_w_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[96];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[96];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i257;
  static char_T c4_cv24[96] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i258;
  static real_T c4_dv64[96] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i259;
  int32_T c4_i260;
  int32_T c4_i261;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_mb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_rb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i257 = 0; c4_i257 < 96; c4_i257++) {
    c4_mystr[c4_i257] = c4_cv24[c4_i257];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i258 = 0; c4_i258 < 96; c4_i258++) {
    c4_arr[c4_i258] = c4_dv64[c4_i258];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 96.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i259 = 0; c4_i259 < 256; c4_i259++) {
    c4_tt[c4_i259] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i260 = 0; c4_i260 < 96; c4_i260++) {
    c4_tt[c4_i260] = c4_arr[c4_i260];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i261 = 0; c4_i261 < 256; c4_i261++) {
    c4_myarr256[c4_i261] = c4_tt[c4_i261];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_x_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i262;
  static char_T c4_cv25[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'h', 'i', 'n', 'k', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i263;
  static real_T c4_dv65[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 104.0,
    105.0, 110.0, 107.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i264;
  int32_T c4_i265;
  int32_T c4_i266;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_nb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i262 = 0; c4_i262 < 86; c4_i262++) {
    c4_mystr[c4_i262] = c4_cv25[c4_i262];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i263 = 0; c4_i263 < 86; c4_i263++) {
    c4_arr[c4_i263] = c4_dv65[c4_i263];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i264 = 0; c4_i264 < 256; c4_i264++) {
    c4_tt[c4_i264] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i265 = 0; c4_i265 < 86; c4_i265++) {
    c4_tt[c4_i265] = c4_arr[c4_i265];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i266 = 0; c4_i266 < 256; c4_i266++) {
    c4_myarr256[c4_i266] = c4_tt[c4_i266];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_y_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[91];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[91];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i267;
  static char_T c4_cv26[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i268;
  static real_T c4_dv66[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i269;
  int32_T c4_i270;
  int32_T c4_i271;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ob_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i267 = 0; c4_i267 < 91; c4_i267++) {
    c4_mystr[c4_i267] = c4_cv26[c4_i267];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i268 = 0; c4_i268 < 91; c4_i268++) {
    c4_arr[c4_i268] = c4_dv66[c4_i268];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i269 = 0; c4_i269 < 256; c4_i269++) {
    c4_tt[c4_i269] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i270 = 0; c4_i270 < 91; c4_i270++) {
    c4_tt[c4_i270] = c4_arr[c4_i270];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i271 = 0; c4_i271 < 256; c4_i271++) {
    c4_myarr256[c4_i271] = c4_tt[c4_i271];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_ab_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
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
  int32_T c4_i272;
  static char_T c4_cv27[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i273;
  static real_T c4_dv67[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i274;
  int32_T c4_i275;
  int32_T c4_i276;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_pb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i272 = 0; c4_i272 < 94; c4_i272++) {
    c4_mystr[c4_i272] = c4_cv27[c4_i272];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i273 = 0; c4_i273 < 94; c4_i273++) {
    c4_arr[c4_i273] = c4_dv67[c4_i273];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i274 = 0; c4_i274 < 256; c4_i274++) {
    c4_tt[c4_i274] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i275 = 0; c4_i275 < 94; c4_i275++) {
    c4_tt[c4_i275] = c4_arr[c4_i275];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i276 = 0; c4_i276 < 256; c4_i276++) {
    c4_myarr256[c4_i276] = c4_tt[c4_i276];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_bb_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[111];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[111];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i277;
  static char_T c4_cv28[111] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '1', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '1', '0', '\"', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C',
    'h', 'r', 'B', 'r', 'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S',
    'q', 'u', 'e', 'e', 'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i278;
  static real_T c4_dv68[111] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 64.0, 73.0, 100.0,
    108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0, 117.0, 101.0, 101.0, 122.0,
    101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i279;
  int32_T c4_i280;
  int32_T c4_i281;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_qb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_xb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i277 = 0; c4_i277 < 111; c4_i277++) {
    c4_mystr[c4_i277] = c4_cv28[c4_i277];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i278 = 0; c4_i278 < 111; c4_i278++) {
    c4_arr[c4_i278] = c4_dv68[c4_i278];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 111.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i279 = 0; c4_i279 < 256; c4_i279++) {
    c4_tt[c4_i279] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i280 = 0; c4_i280 < 111; c4_i280++) {
    c4_tt[c4_i280] = c4_arr[c4_i280];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i281 = 0; c4_i281 < 256; c4_i281++) {
    c4_myarr256[c4_i281] = c4_tt[c4_i281];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_cb_encStr2Arr(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_myarr256[256])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[92];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[256];
  char_T c4_mystr[92];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i282;
  static char_T c4_cv29[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i283;
  static real_T c4_dv69[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c4_i284;
  int32_T c4_i285;
  int32_T c4_i286;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_rb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  for (c4_i282 = 0; c4_i282 < 92; c4_i282++) {
    c4_mystr[c4_i282] = c4_cv29[c4_i282];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i283 = 0; c4_i283 < 92; c4_i283++) {
    c4_arr[c4_i283] = c4_dv69[c4_i283];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i284 = 0; c4_i284 < 256; c4_i284++) {
    c4_tt[c4_i284] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i285 = 0; c4_i285 < 92; c4_i285++) {
    c4_tt[c4_i285] = c4_arr[c4_i285];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i286 = 0; c4_i286 < 256; c4_i286++) {
    c4_myarr256[c4_i286] = c4_tt[c4_i286];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c4_chartNumber, c4_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_nargout, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i287;
  real_T c4_b_inData[256];
  int32_T c4_i288;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i287 = 0; c4_i287 < 256; c4_i287++) {
    c4_b_inData[c4_i287] = (*(real_T (*)[256])c4_inData)[c4_i287];
  }

  for (c4_i288 = 0; c4_i288 < 256; c4_i288++) {
    c4_u[c4_i288] = c4_b_inData[c4_i288];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_myarr256, const char_T *c4_identifier,
  real_T c4_y[256])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
}

static void c4_d_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256])
{
  real_T c4_dv70[256];
  int32_T c4_i289;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv70, 1, 0, 0U, 1, 0U, 1, 256);
  for (c4_i289 = 0; c4_i289 < 256; c4_i289++) {
    c4_y[c4_i289] = c4_dv70[c4_i289];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_myarr256;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i290;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_myarr256 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
  for (c4_i290 = 0; c4_i290 < 256; c4_i290++) {
    (*(real_T (*)[256])c4_outData)[c4_i290] = c4_y[c4_i290];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i291;
  char_T c4_b_inData[99];
  int32_T c4_i292;
  char_T c4_u[99];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i291 = 0; c4_i291 < 99; c4_i291++) {
    c4_b_inData[c4_i291] = (*(char_T (*)[99])c4_inData)[c4_i291];
  }

  for (c4_i292 = 0; c4_i292 < 99; c4_i292++) {
    c4_u[c4_i292] = c4_b_inData[c4_i292];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i293;
  real_T c4_b_inData[99];
  int32_T c4_i294;
  real_T c4_u[99];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i293 = 0; c4_i293 < 99; c4_i293++) {
    c4_b_inData[c4_i293] = (*(real_T (*)[99])c4_inData)[c4_i293];
  }

  for (c4_i294 = 0; c4_i294 < 99; c4_i294++) {
    c4_u[c4_i294] = c4_b_inData[c4_i294];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i295;
  char_T c4_b_inData[240];
  int32_T c4_i296;
  char_T c4_u[240];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i295 = 0; c4_i295 < 240; c4_i295++) {
    c4_b_inData[c4_i295] = (*(char_T (*)[240])c4_inData)[c4_i295];
  }

  for (c4_i296 = 0; c4_i296 < 240; c4_i296++) {
    c4_u[c4_i296] = c4_b_inData[c4_i296];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 240),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i297;
  real_T c4_b_inData[240];
  int32_T c4_i298;
  real_T c4_u[240];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i297 = 0; c4_i297 < 240; c4_i297++) {
    c4_b_inData[c4_i297] = (*(real_T (*)[240])c4_inData)[c4_i297];
  }

  for (c4_i298 = 0; c4_i298 < 240; c4_i298++) {
    c4_u[c4_i298] = c4_b_inData[c4_i298];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 240), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i299;
  char_T c4_b_inData[236];
  int32_T c4_i300;
  char_T c4_u[236];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i299 = 0; c4_i299 < 236; c4_i299++) {
    c4_b_inData[c4_i299] = (*(char_T (*)[236])c4_inData)[c4_i299];
  }

  for (c4_i300 = 0; c4_i300 < 236; c4_i300++) {
    c4_u[c4_i300] = c4_b_inData[c4_i300];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 236),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i301;
  real_T c4_b_inData[236];
  int32_T c4_i302;
  real_T c4_u[236];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i301 = 0; c4_i301 < 236; c4_i301++) {
    c4_b_inData[c4_i301] = (*(real_T (*)[236])c4_inData)[c4_i301];
  }

  for (c4_i302 = 0; c4_i302 < 236; c4_i302++) {
    c4_u[c4_i302] = c4_b_inData[c4_i302];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 236), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i303;
  char_T c4_b_inData[91];
  int32_T c4_i304;
  char_T c4_u[91];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i303 = 0; c4_i303 < 91; c4_i303++) {
    c4_b_inData[c4_i303] = (*(char_T (*)[91])c4_inData)[c4_i303];
  }

  for (c4_i304 = 0; c4_i304 < 91; c4_i304++) {
    c4_u[c4_i304] = c4_b_inData[c4_i304];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i305;
  real_T c4_b_inData[91];
  int32_T c4_i306;
  real_T c4_u[91];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i305 = 0; c4_i305 < 91; c4_i305++) {
    c4_b_inData[c4_i305] = (*(real_T (*)[91])c4_inData)[c4_i305];
  }

  for (c4_i306 = 0; c4_i306 < 91; c4_i306++) {
    c4_u[c4_i306] = c4_b_inData[c4_i306];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_k_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i307;
  char_T c4_b_inData[61];
  int32_T c4_i308;
  char_T c4_u[61];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i307 = 0; c4_i307 < 61; c4_i307++) {
    c4_b_inData[c4_i307] = (*(char_T (*)[61])c4_inData)[c4_i307];
  }

  for (c4_i308 = 0; c4_i308 < 61; c4_i308++) {
    c4_u[c4_i308] = c4_b_inData[c4_i308];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 61), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_l_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i309;
  real_T c4_b_inData[61];
  int32_T c4_i310;
  real_T c4_u[61];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i309 = 0; c4_i309 < 61; c4_i309++) {
    c4_b_inData[c4_i309] = (*(real_T (*)[61])c4_inData)[c4_i309];
  }

  for (c4_i310 = 0; c4_i310 < 61; c4_i310++) {
    c4_u[c4_i310] = c4_b_inData[c4_i310];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 61), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_m_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i311;
  char_T c4_b_inData[95];
  int32_T c4_i312;
  char_T c4_u[95];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i311 = 0; c4_i311 < 95; c4_i311++) {
    c4_b_inData[c4_i311] = (*(char_T (*)[95])c4_inData)[c4_i311];
  }

  for (c4_i312 = 0; c4_i312 < 95; c4_i312++) {
    c4_u[c4_i312] = c4_b_inData[c4_i312];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_n_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i313;
  real_T c4_b_inData[95];
  int32_T c4_i314;
  real_T c4_u[95];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i313 = 0; c4_i313 < 95; c4_i313++) {
    c4_b_inData[c4_i313] = (*(real_T (*)[95])c4_inData)[c4_i313];
  }

  for (c4_i314 = 0; c4_i314 < 95; c4_i314++) {
    c4_u[c4_i314] = c4_b_inData[c4_i314];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_o_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i315;
  char_T c4_b_inData[102];
  int32_T c4_i316;
  char_T c4_u[102];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i315 = 0; c4_i315 < 102; c4_i315++) {
    c4_b_inData[c4_i315] = (*(char_T (*)[102])c4_inData)[c4_i315];
  }

  for (c4_i316 = 0; c4_i316 < 102; c4_i316++) {
    c4_u[c4_i316] = c4_b_inData[c4_i316];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 102),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_p_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i317;
  real_T c4_b_inData[102];
  int32_T c4_i318;
  real_T c4_u[102];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i317 = 0; c4_i317 < 102; c4_i317++) {
    c4_b_inData[c4_i317] = (*(real_T (*)[102])c4_inData)[c4_i317];
  }

  for (c4_i318 = 0; c4_i318 < 102; c4_i318++) {
    c4_u[c4_i318] = c4_b_inData[c4_i318];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 102), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_q_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i319;
  char_T c4_b_inData[103];
  int32_T c4_i320;
  char_T c4_u[103];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i319 = 0; c4_i319 < 103; c4_i319++) {
    c4_b_inData[c4_i319] = (*(char_T (*)[103])c4_inData)[c4_i319];
  }

  for (c4_i320 = 0; c4_i320 < 103; c4_i320++) {
    c4_u[c4_i320] = c4_b_inData[c4_i320];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_r_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i321;
  real_T c4_b_inData[103];
  int32_T c4_i322;
  real_T c4_u[103];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i321 = 0; c4_i321 < 103; c4_i321++) {
    c4_b_inData[c4_i321] = (*(real_T (*)[103])c4_inData)[c4_i321];
  }

  for (c4_i322 = 0; c4_i322 < 103; c4_i322++) {
    c4_u[c4_i322] = c4_b_inData[c4_i322];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_s_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i323;
  char_T c4_b_inData[248];
  int32_T c4_i324;
  char_T c4_u[248];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i323 = 0; c4_i323 < 248; c4_i323++) {
    c4_b_inData[c4_i323] = (*(char_T (*)[248])c4_inData)[c4_i323];
  }

  for (c4_i324 = 0; c4_i324 < 248; c4_i324++) {
    c4_u[c4_i324] = c4_b_inData[c4_i324];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 248),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_t_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i325;
  real_T c4_b_inData[248];
  int32_T c4_i326;
  real_T c4_u[248];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i325 = 0; c4_i325 < 248; c4_i325++) {
    c4_b_inData[c4_i325] = (*(real_T (*)[248])c4_inData)[c4_i325];
  }

  for (c4_i326 = 0; c4_i326 < 248; c4_i326++) {
    c4_u[c4_i326] = c4_b_inData[c4_i326];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 248), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_u_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i327;
  char_T c4_b_inData[244];
  int32_T c4_i328;
  char_T c4_u[244];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i327 = 0; c4_i327 < 244; c4_i327++) {
    c4_b_inData[c4_i327] = (*(char_T (*)[244])c4_inData)[c4_i327];
  }

  for (c4_i328 = 0; c4_i328 < 244; c4_i328++) {
    c4_u[c4_i328] = c4_b_inData[c4_i328];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 244),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_v_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i329;
  real_T c4_b_inData[244];
  int32_T c4_i330;
  real_T c4_u[244];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i329 = 0; c4_i329 < 244; c4_i329++) {
    c4_b_inData[c4_i329] = (*(real_T (*)[244])c4_inData)[c4_i329];
  }

  for (c4_i330 = 0; c4_i330 < 244; c4_i330++) {
    c4_u[c4_i330] = c4_b_inData[c4_i330];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 244), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_w_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i331;
  char_T c4_b_inData[226];
  int32_T c4_i332;
  char_T c4_u[226];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i331 = 0; c4_i331 < 226; c4_i331++) {
    c4_b_inData[c4_i331] = (*(char_T (*)[226])c4_inData)[c4_i331];
  }

  for (c4_i332 = 0; c4_i332 < 226; c4_i332++) {
    c4_u[c4_i332] = c4_b_inData[c4_i332];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 226),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_x_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i333;
  real_T c4_b_inData[226];
  int32_T c4_i334;
  real_T c4_u[226];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i333 = 0; c4_i333 < 226; c4_i333++) {
    c4_b_inData[c4_i333] = (*(real_T (*)[226])c4_inData)[c4_i333];
  }

  for (c4_i334 = 0; c4_i334 < 226; c4_i334++) {
    c4_u[c4_i334] = c4_b_inData[c4_i334];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 226), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_y_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i335;
  char_T c4_b_inData[235];
  int32_T c4_i336;
  char_T c4_u[235];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i335 = 0; c4_i335 < 235; c4_i335++) {
    c4_b_inData[c4_i335] = (*(char_T (*)[235])c4_inData)[c4_i335];
  }

  for (c4_i336 = 0; c4_i336 < 235; c4_i336++) {
    c4_u[c4_i336] = c4_b_inData[c4_i336];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 235),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i337;
  real_T c4_b_inData[235];
  int32_T c4_i338;
  real_T c4_u[235];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i337 = 0; c4_i337 < 235; c4_i337++) {
    c4_b_inData[c4_i337] = (*(real_T (*)[235])c4_inData)[c4_i337];
  }

  for (c4_i338 = 0; c4_i338 < 235; c4_i338++) {
    c4_u[c4_i338] = c4_b_inData[c4_i338];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 235), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i339;
  char_T c4_b_inData[253];
  int32_T c4_i340;
  char_T c4_u[253];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i339 = 0; c4_i339 < 253; c4_i339++) {
    c4_b_inData[c4_i339] = (*(char_T (*)[253])c4_inData)[c4_i339];
  }

  for (c4_i340 = 0; c4_i340 < 253; c4_i340++) {
    c4_u[c4_i340] = c4_b_inData[c4_i340];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 253),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i341;
  real_T c4_b_inData[253];
  int32_T c4_i342;
  real_T c4_u[253];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i341 = 0; c4_i341 < 253; c4_i341++) {
    c4_b_inData[c4_i341] = (*(real_T (*)[253])c4_inData)[c4_i341];
  }

  for (c4_i342 = 0; c4_i342 < 253; c4_i342++) {
    c4_u[c4_i342] = c4_b_inData[c4_i342];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 253), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_db_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_e_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct *
  chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
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
  const mxArray *c4_aVarTruthTableCondition_6;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_aVarTruthTableCondition_6 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_aVarTruthTableCondition_6), &c4_thisId);
  sf_mex_destroy(&c4_aVarTruthTableCondition_6);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i343;
  char_T c4_b_inData[112];
  int32_T c4_i344;
  char_T c4_u[112];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i343 = 0; c4_i343 < 112; c4_i343++) {
    c4_b_inData[c4_i343] = (*(char_T (*)[112])c4_inData)[c4_i343];
  }

  for (c4_i344 = 0; c4_i344 < 112; c4_i344++) {
    c4_u[c4_i344] = c4_b_inData[c4_i344];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 112),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i345;
  real_T c4_b_inData[112];
  int32_T c4_i346;
  real_T c4_u[112];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i345 = 0; c4_i345 < 112; c4_i345++) {
    c4_b_inData[c4_i345] = (*(real_T (*)[112])c4_inData)[c4_i345];
  }

  for (c4_i346 = 0; c4_i346 < 112; c4_i346++) {
    c4_u[c4_i346] = c4_b_inData[c4_i346];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 112), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i347;
  char_T c4_b_inData[116];
  int32_T c4_i348;
  char_T c4_u[116];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i347 = 0; c4_i347 < 116; c4_i347++) {
    c4_b_inData[c4_i347] = (*(char_T (*)[116])c4_inData)[c4_i347];
  }

  for (c4_i348 = 0; c4_i348 < 116; c4_i348++) {
    c4_u[c4_i348] = c4_b_inData[c4_i348];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i349;
  real_T c4_b_inData[116];
  int32_T c4_i350;
  real_T c4_u[116];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i349 = 0; c4_i349 < 116; c4_i349++) {
    c4_b_inData[c4_i349] = (*(real_T (*)[116])c4_inData)[c4_i349];
  }

  for (c4_i350 = 0; c4_i350 < 116; c4_i350++) {
    c4_u[c4_i350] = c4_b_inData[c4_i350];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i351;
  char_T c4_b_inData[117];
  int32_T c4_i352;
  char_T c4_u[117];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i351 = 0; c4_i351 < 117; c4_i351++) {
    c4_b_inData[c4_i351] = (*(char_T (*)[117])c4_inData)[c4_i351];
  }

  for (c4_i352 = 0; c4_i352 < 117; c4_i352++) {
    c4_u[c4_i352] = c4_b_inData[c4_i352];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 117),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i353;
  real_T c4_b_inData[117];
  int32_T c4_i354;
  real_T c4_u[117];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i353 = 0; c4_i353 < 117; c4_i353++) {
    c4_b_inData[c4_i353] = (*(real_T (*)[117])c4_inData)[c4_i353];
  }

  for (c4_i354 = 0; c4_i354 < 117; c4_i354++) {
    c4_u[c4_i354] = c4_b_inData[c4_i354];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 117), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i355;
  char_T c4_b_inData[113];
  int32_T c4_i356;
  char_T c4_u[113];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i355 = 0; c4_i355 < 113; c4_i355++) {
    c4_b_inData[c4_i355] = (*(char_T (*)[113])c4_inData)[c4_i355];
  }

  for (c4_i356 = 0; c4_i356 < 113; c4_i356++) {
    c4_u[c4_i356] = c4_b_inData[c4_i356];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 113),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i357;
  real_T c4_b_inData[113];
  int32_T c4_i358;
  real_T c4_u[113];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i357 = 0; c4_i357 < 113; c4_i357++) {
    c4_b_inData[c4_i357] = (*(real_T (*)[113])c4_inData)[c4_i357];
  }

  for (c4_i358 = 0; c4_i358 < 113; c4_i358++) {
    c4_u[c4_i358] = c4_b_inData[c4_i358];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 113), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i359;
  char_T c4_b_inData[92];
  int32_T c4_i360;
  char_T c4_u[92];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i359 = 0; c4_i359 < 92; c4_i359++) {
    c4_b_inData[c4_i359] = (*(char_T (*)[92])c4_inData)[c4_i359];
  }

  for (c4_i360 = 0; c4_i360 < 92; c4_i360++) {
    c4_u[c4_i360] = c4_b_inData[c4_i360];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i361;
  real_T c4_b_inData[92];
  int32_T c4_i362;
  real_T c4_u[92];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i361 = 0; c4_i361 < 92; c4_i361++) {
    c4_b_inData[c4_i361] = (*(real_T (*)[92])c4_inData)[c4_i361];
  }

  for (c4_i362 = 0; c4_i362 < 92; c4_i362++) {
    c4_u[c4_i362] = c4_b_inData[c4_i362];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i363;
  char_T c4_b_inData[93];
  int32_T c4_i364;
  char_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i363 = 0; c4_i363 < 93; c4_i363++) {
    c4_b_inData[c4_i363] = (*(char_T (*)[93])c4_inData)[c4_i363];
  }

  for (c4_i364 = 0; c4_i364 < 93; c4_i364++) {
    c4_u[c4_i364] = c4_b_inData[c4_i364];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i365;
  real_T c4_b_inData[93];
  int32_T c4_i366;
  real_T c4_u[93];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i365 = 0; c4_i365 < 93; c4_i365++) {
    c4_b_inData[c4_i365] = (*(real_T (*)[93])c4_inData)[c4_i365];
  }

  for (c4_i366 = 0; c4_i366 < 93; c4_i366++) {
    c4_u[c4_i366] = c4_b_inData[c4_i366];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i367;
  char_T c4_b_inData[96];
  int32_T c4_i368;
  char_T c4_u[96];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i367 = 0; c4_i367 < 96; c4_i367++) {
    c4_b_inData[c4_i367] = (*(char_T (*)[96])c4_inData)[c4_i367];
  }

  for (c4_i368 = 0; c4_i368 < 96; c4_i368++) {
    c4_u[c4_i368] = c4_b_inData[c4_i368];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 96), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i369;
  real_T c4_b_inData[96];
  int32_T c4_i370;
  real_T c4_u[96];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i369 = 0; c4_i369 < 96; c4_i369++) {
    c4_b_inData[c4_i369] = (*(real_T (*)[96])c4_inData)[c4_i369];
  }

  for (c4_i370 = 0; c4_i370 < 96; c4_i370++) {
    c4_u[c4_i370] = c4_b_inData[c4_i370];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 96), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i371;
  char_T c4_b_inData[86];
  int32_T c4_i372;
  char_T c4_u[86];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i371 = 0; c4_i371 < 86; c4_i371++) {
    c4_b_inData[c4_i371] = (*(char_T (*)[86])c4_inData)[c4_i371];
  }

  for (c4_i372 = 0; c4_i372 < 86; c4_i372++) {
    c4_u[c4_i372] = c4_b_inData[c4_i372];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i373;
  real_T c4_b_inData[86];
  int32_T c4_i374;
  real_T c4_u[86];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i373 = 0; c4_i373 < 86; c4_i373++) {
    c4_b_inData[c4_i373] = (*(real_T (*)[86])c4_inData)[c4_i373];
  }

  for (c4_i374 = 0; c4_i374 < 86; c4_i374++) {
    c4_u[c4_i374] = c4_b_inData[c4_i374];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i375;
  char_T c4_b_inData[94];
  int32_T c4_i376;
  char_T c4_u[94];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i375 = 0; c4_i375 < 94; c4_i375++) {
    c4_b_inData[c4_i375] = (*(char_T (*)[94])c4_inData)[c4_i375];
  }

  for (c4_i376 = 0; c4_i376 < 94; c4_i376++) {
    c4_u[c4_i376] = c4_b_inData[c4_i376];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i377;
  real_T c4_b_inData[94];
  int32_T c4_i378;
  real_T c4_u[94];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i377 = 0; c4_i377 < 94; c4_i377++) {
    c4_b_inData[c4_i377] = (*(real_T (*)[94])c4_inData)[c4_i377];
  }

  for (c4_i378 = 0; c4_i378 < 94; c4_i378++) {
    c4_u[c4_i378] = c4_b_inData[c4_i378];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i379;
  char_T c4_b_inData[111];
  int32_T c4_i380;
  char_T c4_u[111];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i379 = 0; c4_i379 < 111; c4_i379++) {
    c4_b_inData[c4_i379] = (*(char_T (*)[111])c4_inData)[c4_i379];
  }

  for (c4_i380 = 0; c4_i380 < 111; c4_i380++) {
    c4_u[c4_i380] = c4_b_inData[c4_i380];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i381;
  real_T c4_b_inData[111];
  int32_T c4_i382;
  real_T c4_u[111];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i381 = 0; c4_i381 < 111; c4_i381++) {
    c4_b_inData[c4_i381] = (*(real_T (*)[111])c4_inData)[c4_i381];
  }

  for (c4_i382 = 0; c4_i382 < 111; c4_i382++) {
    c4_u[c4_i382] = c4_b_inData[c4_i382];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_testKinectGazeWaveGUI_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
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

static void c4_sendBML(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance,
  real_T c4_arg[256])
{
  int32_T c4_i383;
  int32_T c4_i384;
  int32_T c4_i385;
  real_T (*c4_b_arg)[256];
  c4_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c4_i383 = 0; c4_i383 < 256; c4_i383++) {
    _SFD_DATA_RANGE_CHECK(c4_arg[c4_i383], 29U);
  }

  _SFD_SET_DATA_VALUE_PTR(29U, c4_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c4_arg, c4_bc_sf_marshallOut,
    c4_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
  for (c4_i384 = 0; c4_i384 < 256; c4_i384++) {
    (*c4_b_arg)[c4_i384] = c4_arg[c4_i384];
  }

  for (c4_i385 = 0; c4_i385 < 256; c4_i385++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_arg)[c4_i385], 29U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(29U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
}

static void c4_gazeAvert(SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance,
  real_T c4_bmlID)
{
  uint32_T c4_debug_family_var_map[19];
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
  real_T c4_gazeBML[256];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv71[256];
  int32_T c4_i386;
  int32_T c4_i387;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  real_T c4_dv72[256];
  int32_T c4_i388;
  int32_T c4_i389;
  real_T c4_b_u[256];
  const mxArray *c4_b_y = NULL;
  real_T c4_dv73[256];
  int32_T c4_i390;
  int32_T c4_i391;
  real_T c4_c_u[256];
  const mxArray *c4_c_y = NULL;
  real_T c4_dv74[256];
  int32_T c4_i392;
  int32_T c4_i393;
  real_T c4_d_u[256];
  const mxArray *c4_d_y = NULL;
  real_T c4_dv75[256];
  int32_T c4_i394;
  int32_T c4_i395;
  real_T c4_e_u[256];
  const mxArray *c4_e_y = NULL;
  real_T c4_dv76[256];
  int32_T c4_i396;
  int32_T c4_i397;
  real_T c4_f_u[256];
  const mxArray *c4_f_y = NULL;
  real_T c4_dv77[256];
  int32_T c4_i398;
  int32_T c4_i399;
  real_T c4_g_u[256];
  const mxArray *c4_g_y = NULL;
  real_T c4_dv78[256];
  int32_T c4_i400;
  int32_T c4_i401;
  real_T c4_h_u[256];
  const mxArray *c4_h_y = NULL;
  real_T c4_dv79[256];
  int32_T c4_i402;
  int32_T c4_i403;
  real_T c4_i_u[256];
  const mxArray *c4_i_y = NULL;
  real_T c4_dv80[256];
  int32_T c4_i404;
  int32_T c4_i405;
  real_T c4_j_u[256];
  const mxArray *c4_j_y = NULL;
  real_T c4_dv81[256];
  int32_T c4_i406;
  int32_T c4_i407;
  real_T c4_k_u[256];
  const mxArray *c4_k_y = NULL;
  real_T c4_dv82[256];
  int32_T c4_i408;
  int32_T c4_i409;
  real_T c4_l_u[256];
  const mxArray *c4_l_y = NULL;
  real_T c4_dv83[256];
  int32_T c4_i410;
  int32_T c4_i411;
  real_T c4_m_u[256];
  const mxArray *c4_m_y = NULL;
  real_T c4_dv84[256];
  int32_T c4_i412;
  int32_T c4_i413;
  real_T c4_n_u[256];
  const mxArray *c4_n_y = NULL;
  real_T c4_dv85[256];
  int32_T c4_i414;
  int32_T c4_i415;
  real_T c4_o_u[256];
  const mxArray *c4_o_y = NULL;
  real_T c4_dv86[256];
  int32_T c4_i416;
  int32_T c4_i417;
  real_T c4_p_u[256];
  const mxArray *c4_p_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c4_gb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_5, 4U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_6, 5U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_7, 6U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_8, 7U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_9, 8U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_10, 9U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_11, 10U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_12, 11U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_13, 12U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_14, 13U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_15, 14U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_gazeBML, 15U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 16U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 24);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 27);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 30);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 33);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 36);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 39);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 42);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 45);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 48);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 51);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 54);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 57);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 60);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 63);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 65);
  if (CV_EML_IF(3, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 66);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
    c4_o_encStr2Arr(chartInstance, c4_dv71);
    for (c4_i386 = 0; c4_i386 < 256; c4_i386++) {
      c4_gazeBML[c4_i386] = c4_dv71[c4_i386];
    }

    sf_mex_printf("%s =\\n", "gazeBML");
    for (c4_i387 = 0; c4_i387 < 256; c4_i387++) {
      c4_u[c4_i387] = c4_gazeBML[c4_i387];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 67);
    if (CV_EML_IF(3, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 68);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
      c4_p_encStr2Arr(chartInstance, c4_dv72);
      for (c4_i388 = 0; c4_i388 < 256; c4_i388++) {
        c4_gazeBML[c4_i388] = c4_dv72[c4_i388];
      }

      sf_mex_printf("%s =\\n", "gazeBML");
      for (c4_i389 = 0; c4_i389 < 256; c4_i389++) {
        c4_b_u[c4_i389] = c4_gazeBML[c4_i389];
      }

      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_b_y);
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 69);
      if (CV_EML_IF(3, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 70);
        CV_EML_FCN(3, 3);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
        c4_q_encStr2Arr(chartInstance, c4_dv73);
        for (c4_i390 = 0; c4_i390 < 256; c4_i390++) {
          c4_gazeBML[c4_i390] = c4_dv73[c4_i390];
        }

        sf_mex_printf("%s =\\n", "gazeBML");
        for (c4_i391 = 0; c4_i391 < 256; c4_i391++) {
          c4_c_u[c4_i391] = c4_gazeBML[c4_i391];
        }

        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_c_y);
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
      } else {
        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 71);
        if (CV_EML_IF(3, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 72);
          CV_EML_FCN(3, 2);
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
          c4_p_encStr2Arr(chartInstance, c4_dv74);
          for (c4_i392 = 0; c4_i392 < 256; c4_i392++) {
            c4_gazeBML[c4_i392] = c4_dv74[c4_i392];
          }

          sf_mex_printf("%s =\\n", "gazeBML");
          for (c4_i393 = 0; c4_i393 < 256; c4_i393++) {
            c4_d_u[c4_i393] = c4_gazeBML[c4_i393];
          }

          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c4_d_y);
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
        } else {
          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 73);
          if (CV_EML_IF(3, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 74);
            CV_EML_FCN(3, 4);
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 121);
            c4_r_encStr2Arr(chartInstance, c4_dv75);
            for (c4_i394 = 0; c4_i394 < 256; c4_i394++) {
              c4_gazeBML[c4_i394] = c4_dv75[c4_i394];
            }

            sf_mex_printf("%s =\\n", "gazeBML");
            for (c4_i395 = 0; c4_i395 < 256; c4_i395++) {
              c4_e_u[c4_i395] = c4_gazeBML[c4_i395];
            }

            c4_e_y = NULL;
            sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c4_e_y);
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -121);
          } else {
            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 75);
            if (CV_EML_IF(3, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 76);
              CV_EML_FCN(3, 2);
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
              c4_p_encStr2Arr(chartInstance, c4_dv76);
              for (c4_i396 = 0; c4_i396 < 256; c4_i396++) {
                c4_gazeBML[c4_i396] = c4_dv76[c4_i396];
              }

              sf_mex_printf("%s =\\n", "gazeBML");
              for (c4_i397 = 0; c4_i397 < 256; c4_i397++) {
                c4_f_u[c4_i397] = c4_gazeBML[c4_i397];
              }

              c4_f_y = NULL;
              sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c4_f_y);
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
            } else {
              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 77);
              if (CV_EML_IF(3, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 78);
                CV_EML_FCN(3, 4);
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 121);
                c4_r_encStr2Arr(chartInstance, c4_dv77);
                for (c4_i398 = 0; c4_i398 < 256; c4_i398++) {
                  c4_gazeBML[c4_i398] = c4_dv77[c4_i398];
                }

                sf_mex_printf("%s =\\n", "gazeBML");
                for (c4_i399 = 0; c4_i399 < 256; c4_i399++) {
                  c4_g_u[c4_i399] = c4_gazeBML[c4_i399];
                }

                c4_g_y = NULL;
                sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c4_g_y);
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -121);
              } else {
                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 79);
                if (CV_EML_IF(3, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 80);
                  CV_EML_FCN(3, 5);
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, MAX_int8_T);
                  c4_s_encStr2Arr(chartInstance, c4_dv78);
                  for (c4_i400 = 0; c4_i400 < 256; c4_i400++) {
                    c4_gazeBML[c4_i400] = c4_dv78[c4_i400];
                  }

                  sf_mex_printf("%s =\\n", "gazeBML");
                  for (c4_i401 = 0; c4_i401 < 256; c4_i401++) {
                    c4_h_u[c4_i401] = c4_gazeBML[c4_i401];
                  }

                  c4_h_y = NULL;
                  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c4_h_y);
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -127);
                } else {
                  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 81);
                  if (CV_EML_IF(3, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 82);
                    CV_EML_FCN(3, 2);
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 109);
                    c4_p_encStr2Arr(chartInstance, c4_dv79);
                    for (c4_i402 = 0; c4_i402 < 256; c4_i402++) {
                      c4_gazeBML[c4_i402] = c4_dv79[c4_i402];
                    }

                    sf_mex_printf("%s =\\n", "gazeBML");
                    for (c4_i403 = 0; c4_i403 < 256; c4_i403++) {
                      c4_i_u[c4_i403] = c4_gazeBML[c4_i403];
                    }

                    c4_i_y = NULL;
                    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c4_i_y);
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -109);
                  } else {
                    _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 83);
                    if (CV_EML_IF(3, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 84);
                      CV_EML_FCN(3, 1);
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                      c4_o_encStr2Arr(chartInstance, c4_dv80);
                      for (c4_i404 = 0; c4_i404 < 256; c4_i404++) {
                        c4_gazeBML[c4_i404] = c4_dv80[c4_i404];
                      }

                      sf_mex_printf("%s =\\n", "gazeBML");
                      for (c4_i405 = 0; c4_i405 < 256; c4_i405++) {
                        c4_j_u[c4_i405] = c4_gazeBML[c4_i405];
                      }

                      c4_j_y = NULL;
                      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c4_j_y);
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                    } else {
                      _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 85);
                      if (CV_EML_IF(3, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 86);
                        CV_EML_FCN(3, 1);
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                        c4_o_encStr2Arr(chartInstance, c4_dv81);
                        for (c4_i406 = 0; c4_i406 < 256; c4_i406++) {
                          c4_gazeBML[c4_i406] = c4_dv81[c4_i406];
                        }

                        sf_mex_printf("%s =\\n", "gazeBML");
                        for (c4_i407 = 0; c4_i407 < 256; c4_i407++) {
                          c4_k_u[c4_i407] = c4_gazeBML[c4_i407];
                        }

                        c4_k_y = NULL;
                        sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c4_k_y);
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                      } else {
                        _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 87);
                        if (CV_EML_IF(3, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 88);
                          CV_EML_FCN(3, 1);
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 103);
                          c4_o_encStr2Arr(chartInstance, c4_dv82);
                          for (c4_i408 = 0; c4_i408 < 256; c4_i408++) {
                            c4_gazeBML[c4_i408] = c4_dv82[c4_i408];
                          }

                          sf_mex_printf("%s =\\n", "gazeBML");
                          for (c4_i409 = 0; c4_i409 < 256; c4_i409++) {
                            c4_l_u[c4_i409] = c4_gazeBML[c4_i409];
                          }

                          c4_l_y = NULL;
                          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c4_l_y);
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -103);
                        } else {
                          _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 89);
                          if (CV_EML_IF(3, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 90);
                            CV_EML_FCN(3, 3);
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                            c4_q_encStr2Arr(chartInstance, c4_dv83);
                            for (c4_i410 = 0; c4_i410 < 256; c4_i410++) {
                              c4_gazeBML[c4_i410] = c4_dv83[c4_i410];
                            }

                            sf_mex_printf("%s =\\n", "gazeBML");
                            for (c4_i411 = 0; c4_i411 < 256; c4_i411++) {
                              c4_m_u[c4_i411] = c4_gazeBML[c4_i411];
                            }

                            c4_m_y = NULL;
                            sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c4_m_y);
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
                          } else {
                            _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 91);
                            if (CV_EML_IF(3, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 92);
                              CV_EML_FCN(3, 3);
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                              c4_q_encStr2Arr(chartInstance, c4_dv84);
                              for (c4_i412 = 0; c4_i412 < 256; c4_i412++) {
                                c4_gazeBML[c4_i412] = c4_dv84[c4_i412];
                              }

                              sf_mex_printf("%s =\\n", "gazeBML");
                              for (c4_i413 = 0; c4_i413 < 256; c4_i413++) {
                                c4_n_u[c4_i413] = c4_gazeBML[c4_i413];
                              }

                              c4_n_y = NULL;
                              sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c4_n_y);
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -115);
                            } else {
                              _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 93);
                              if (CV_EML_IF(3, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 94);
                                CV_EML_FCN(3, 3);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                                c4_q_encStr2Arr(chartInstance, c4_dv85);
                                for (c4_i414 = 0; c4_i414 < 256; c4_i414++) {
                                  c4_gazeBML[c4_i414] = c4_dv85[c4_i414];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c4_i415 = 0; c4_i415 < 256; c4_i415++) {
                                  c4_o_u[c4_i415] = c4_gazeBML[c4_i415];
                                }

                                c4_o_y = NULL;
                                sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c4_o_y);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent,
                                              -115);
                              } else {
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 96);
                                CV_EML_FCN(3, 3);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, 115);
                                c4_q_encStr2Arr(chartInstance, c4_dv86);
                                for (c4_i416 = 0; c4_i416 < 256; c4_i416++) {
                                  c4_gazeBML[c4_i416] = c4_dv86[c4_i416];
                                }

                                sf_mex_printf("%s =\\n", "gazeBML");
                                for (c4_i417 = 0; c4_i417 < 256; c4_i417++) {
                                  c4_p_u[c4_i417] = c4_gazeBML[c4_i417];
                                }

                                c4_p_y = NULL;
                                sf_mex_assign(&c4_p_y, sf_mex_create("y", c4_p_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c4_p_y);
                                _SFD_EML_CALL(3U, chartInstance->c4_sfEvent,
                                              -115);
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

  _SFD_EML_CALL(3U, chartInstance->c4_sfEvent, -96);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_introvertIdlePose(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, real_T c4_bmlID, real_T c4_poseBML[256])
{
  uint32_T c4_debug_family_var_map[21];
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
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  real_T c4_dv87[256];
  int32_T c4_i418;
  int32_T c4_i419;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  real_T c4_dv88[256];
  int32_T c4_i420;
  int32_T c4_i421;
  real_T c4_b_u[256];
  const mxArray *c4_b_y = NULL;
  real_T c4_dv89[256];
  int32_T c4_i422;
  int32_T c4_i423;
  real_T c4_c_u[256];
  const mxArray *c4_c_y = NULL;
  real_T c4_dv90[256];
  int32_T c4_i424;
  int32_T c4_i425;
  real_T c4_d_u[256];
  const mxArray *c4_d_y = NULL;
  real_T c4_dv91[256];
  int32_T c4_i426;
  int32_T c4_i427;
  real_T c4_e_u[256];
  const mxArray *c4_e_y = NULL;
  real_T c4_dv92[256];
  int32_T c4_i428;
  int32_T c4_i429;
  real_T c4_f_u[256];
  const mxArray *c4_f_y = NULL;
  real_T c4_dv93[256];
  int32_T c4_i430;
  int32_T c4_i431;
  real_T c4_g_u[256];
  const mxArray *c4_g_y = NULL;
  real_T c4_dv94[256];
  int32_T c4_i432;
  int32_T c4_i433;
  real_T c4_h_u[256];
  const mxArray *c4_h_y = NULL;
  real_T c4_dv95[256];
  int32_T c4_i434;
  int32_T c4_i435;
  real_T c4_i_u[256];
  const mxArray *c4_i_y = NULL;
  real_T c4_dv96[256];
  int32_T c4_i436;
  int32_T c4_i437;
  real_T c4_j_u[256];
  const mxArray *c4_j_y = NULL;
  real_T c4_dv97[256];
  int32_T c4_i438;
  int32_T c4_i439;
  real_T c4_k_u[256];
  const mxArray *c4_k_y = NULL;
  real_T c4_dv98[256];
  int32_T c4_i440;
  int32_T c4_i441;
  real_T c4_l_u[256];
  const mxArray *c4_l_y = NULL;
  real_T c4_dv99[256];
  int32_T c4_i442;
  int32_T c4_i443;
  real_T c4_m_u[256];
  const mxArray *c4_m_y = NULL;
  real_T c4_dv100[256];
  int32_T c4_i444;
  int32_T c4_i445;
  real_T c4_n_u[256];
  const mxArray *c4_n_y = NULL;
  real_T c4_dv101[256];
  int32_T c4_i446;
  int32_T c4_i447;
  real_T c4_o_u[256];
  const mxArray *c4_o_y = NULL;
  real_T c4_dv102[256];
  int32_T c4_i448;
  int32_T c4_i449;
  real_T c4_p_u[256];
  const mxArray *c4_p_y = NULL;
  real_T c4_dv103[256];
  int32_T c4_i450;
  int32_T c4_i451;
  real_T c4_q_u[256];
  const mxArray *c4_q_y = NULL;
  real_T c4_dv104[256];
  int32_T c4_i452;
  int32_T c4_i453;
  real_T c4_r_u[256];
  const mxArray *c4_r_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c4_sb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_1, 0U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_2, 1U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_3, 2U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_4, 3U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_5, 4U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_6, 5U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_7, 6U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_8, 7U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_9, 8U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_10, 9U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_11, 10U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_12, 11U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_13, 12U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_14, 13U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_15, 14U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_16, 15U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_17, 16U,
    c4_db_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 18U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 19U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 20U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 23);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 26);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 29);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 32);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 35);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 38);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 41);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 44);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 47);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 50);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 53);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 56);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 59);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 62);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 65);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 68);
  c4_aVarTruthTableCondition_16 = (c4_bmlID == 16.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 71);
  c4_aVarTruthTableCondition_17 = (c4_bmlID == 17.0);
  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 73);
  if (CV_EML_IF(7, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 74);
    CV_EML_FCN(7, 1);
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 115);
    c4_t_encStr2Arr(chartInstance, c4_dv87);
    for (c4_i418 = 0; c4_i418 < 256; c4_i418++) {
      c4_poseBML[c4_i418] = c4_dv87[c4_i418];
    }

    sf_mex_printf("%s =\\n", "poseBML");
    for (c4_i419 = 0; c4_i419 < 256; c4_i419++) {
      c4_u[c4_i419] = c4_poseBML[c4_i419];
    }

    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 256), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_y);
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -115);
  } else {
    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 75);
    if (CV_EML_IF(7, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 76);
      CV_EML_FCN(7, 2);
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 121);
      c4_u_encStr2Arr(chartInstance, c4_dv88);
      for (c4_i420 = 0; c4_i420 < 256; c4_i420++) {
        c4_poseBML[c4_i420] = c4_dv88[c4_i420];
      }

      sf_mex_printf("%s =\\n", "poseBML");
      for (c4_i421 = 0; c4_i421 < 256; c4_i421++) {
        c4_b_u[c4_i421] = c4_poseBML[c4_i421];
      }

      c4_b_y = NULL;
      sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 256),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c4_b_y);
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -121);
    } else {
      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 77);
      if (CV_EML_IF(7, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 78);
        CV_EML_FCN(7, 3);
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, MAX_int8_T);
        c4_v_encStr2Arr(chartInstance, c4_dv89);
        for (c4_i422 = 0; c4_i422 < 256; c4_i422++) {
          c4_poseBML[c4_i422] = c4_dv89[c4_i422];
        }

        sf_mex_printf("%s =\\n", "poseBML");
        for (c4_i423 = 0; c4_i423 < 256; c4_i423++) {
          c4_c_u[c4_i423] = c4_poseBML[c4_i423];
        }

        c4_c_y = NULL;
        sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 256),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c4_c_y);
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -127);
      } else {
        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 79);
        if (CV_EML_IF(7, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 80);
          CV_EML_FCN(7, 4);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 133U);
          c4_w_encStr2Arr(chartInstance, c4_dv90);
          for (c4_i424 = 0; c4_i424 < 256; c4_i424++) {
            c4_poseBML[c4_i424] = c4_dv90[c4_i424];
          }

          sf_mex_printf("%s =\\n", "poseBML");
          for (c4_i425 = 0; c4_i425 < 256; c4_i425++) {
            c4_d_u[c4_i425] = c4_poseBML[c4_i425];
          }

          c4_d_y = NULL;
          sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1,
            256), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c4_d_y);
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -133);
        } else {
          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 81);
          if (CV_EML_IF(7, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 82);
            CV_EML_FCN(7, 5);
            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 139U);
            c4_x_encStr2Arr(chartInstance, c4_dv91);
            for (c4_i426 = 0; c4_i426 < 256; c4_i426++) {
              c4_poseBML[c4_i426] = c4_dv91[c4_i426];
            }

            sf_mex_printf("%s =\\n", "poseBML");
            for (c4_i427 = 0; c4_i427 < 256; c4_i427++) {
              c4_e_u[c4_i427] = c4_poseBML[c4_i427];
            }

            c4_e_y = NULL;
            sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1,
              256), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c4_e_y);
            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -139);
          } else {
            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 83);
            if (CV_EML_IF(7, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 84);
              CV_EML_FCN(7, 6);
              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 145U);
              c4_y_encStr2Arr(chartInstance, c4_dv92);
              for (c4_i428 = 0; c4_i428 < 256; c4_i428++) {
                c4_poseBML[c4_i428] = c4_dv92[c4_i428];
              }

              sf_mex_printf("%s =\\n", "poseBML");
              for (c4_i429 = 0; c4_i429 < 256; c4_i429++) {
                c4_f_u[c4_i429] = c4_poseBML[c4_i429];
              }

              c4_f_y = NULL;
              sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1,
                256), false);
              sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                                c4_f_y);
              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -145);
            } else {
              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 85);
              if (CV_EML_IF(7, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 86);
                CV_EML_FCN(7, 8);
                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 157U);
                c4_ab_encStr2Arr(chartInstance, c4_dv93);
                for (c4_i430 = 0; c4_i430 < 256; c4_i430++) {
                  c4_poseBML[c4_i430] = c4_dv93[c4_i430];
                }

                sf_mex_printf("%s =\\n", "poseBML");
                for (c4_i431 = 0; c4_i431 < 256; c4_i431++) {
                  c4_g_u[c4_i431] = c4_poseBML[c4_i431];
                }

                c4_g_y = NULL;
                sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U,
                  1, 256), false);
                sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                  14, c4_g_y);
                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -157);
              } else {
                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 87);
                if (CV_EML_IF(7, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 88);
                  CV_EML_FCN(7, 3);
                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, MAX_int8_T);
                  c4_v_encStr2Arr(chartInstance, c4_dv94);
                  for (c4_i432 = 0; c4_i432 < 256; c4_i432++) {
                    c4_poseBML[c4_i432] = c4_dv94[c4_i432];
                  }

                  sf_mex_printf("%s =\\n", "poseBML");
                  for (c4_i433 = 0; c4_i433 < 256; c4_i433++) {
                    c4_h_u[c4_i433] = c4_poseBML[c4_i433];
                  }

                  c4_h_y = NULL;
                  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_h_u, 0, 0U, 1U,
                    0U, 1, 256), false);
                  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U,
                                    14, c4_h_y);
                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -127);
                } else {
                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 89);
                  if (CV_EML_IF(7, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 90);
                    CV_EML_FCN(7, 5);
                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 139U);
                    c4_x_encStr2Arr(chartInstance, c4_dv95);
                    for (c4_i434 = 0; c4_i434 < 256; c4_i434++) {
                      c4_poseBML[c4_i434] = c4_dv95[c4_i434];
                    }

                    sf_mex_printf("%s =\\n", "poseBML");
                    for (c4_i435 = 0; c4_i435 < 256; c4_i435++) {
                      c4_i_u[c4_i435] = c4_poseBML[c4_i435];
                    }

                    c4_i_y = NULL;
                    sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_i_u, 0, 0U, 1U,
                      0U, 1, 256), false);
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                      1U, 14, c4_i_y);
                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -139);
                  } else {
                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 91);
                    if (CV_EML_IF(7, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 92);
                      CV_EML_FCN(7, 6);
                      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 145U);
                      c4_y_encStr2Arr(chartInstance, c4_dv96);
                      for (c4_i436 = 0; c4_i436 < 256; c4_i436++) {
                        c4_poseBML[c4_i436] = c4_dv96[c4_i436];
                      }

                      sf_mex_printf("%s =\\n", "poseBML");
                      for (c4_i437 = 0; c4_i437 < 256; c4_i437++) {
                        c4_j_u[c4_i437] = c4_poseBML[c4_i437];
                      }

                      c4_j_y = NULL;
                      sf_mex_assign(&c4_j_y, sf_mex_create("y", c4_j_u, 0, 0U,
                        1U, 0U, 1, 256), false);
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U,
                                        1U, 14, c4_j_y);
                      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -145);
                    } else {
                      _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 93);
                      if (CV_EML_IF(7, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 94);
                        CV_EML_FCN(7, 3);
                        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, MAX_int8_T);
                        c4_v_encStr2Arr(chartInstance, c4_dv97);
                        for (c4_i438 = 0; c4_i438 < 256; c4_i438++) {
                          c4_poseBML[c4_i438] = c4_dv97[c4_i438];
                        }

                        sf_mex_printf("%s =\\n", "poseBML");
                        for (c4_i439 = 0; c4_i439 < 256; c4_i439++) {
                          c4_k_u[c4_i439] = c4_poseBML[c4_i439];
                        }

                        c4_k_y = NULL;
                        sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_k_u, 0, 0U,
                          1U, 0U, 1, 256), false);
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                          0U, 1U, 14, c4_k_y);
                        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -127);
                      } else {
                        _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 95);
                        if (CV_EML_IF(7, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 96);
                          CV_EML_FCN(7, 5);
                          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 139U);
                          c4_x_encStr2Arr(chartInstance, c4_dv98);
                          for (c4_i440 = 0; c4_i440 < 256; c4_i440++) {
                            c4_poseBML[c4_i440] = c4_dv98[c4_i440];
                          }

                          sf_mex_printf("%s =\\n", "poseBML");
                          for (c4_i441 = 0; c4_i441 < 256; c4_i441++) {
                            c4_l_u[c4_i441] = c4_poseBML[c4_i441];
                          }

                          c4_l_y = NULL;
                          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_l_u, 0,
                            0U, 1U, 0U, 1, 256), false);
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp",
                                            0U, 1U, 14, c4_l_y);
                          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -139);
                        } else {
                          _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 97);
                          if (CV_EML_IF(7, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 98);
                            CV_EML_FCN(7, 7);
                            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 151U);
                            c4_bb_encStr2Arr(chartInstance, c4_dv99);
                            for (c4_i442 = 0; c4_i442 < 256; c4_i442++) {
                              c4_poseBML[c4_i442] = c4_dv99[c4_i442];
                            }

                            sf_mex_printf("%s =\\n", "poseBML");
                            for (c4_i443 = 0; c4_i443 < 256; c4_i443++) {
                              c4_m_u[c4_i443] = c4_poseBML[c4_i443];
                            }

                            c4_m_y = NULL;
                            sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_m_u, 0,
                              0U, 1U, 0U, 1, 256), false);
                            sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                              "disp", 0U, 1U, 14, c4_m_y);
                            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -151);
                          } else {
                            _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 99);
                            if (CV_EML_IF(7, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 100);
                              CV_EML_FCN(7, 1);
                              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 115);
                              c4_t_encStr2Arr(chartInstance, c4_dv100);
                              for (c4_i444 = 0; c4_i444 < 256; c4_i444++) {
                                c4_poseBML[c4_i444] = c4_dv100[c4_i444];
                              }

                              sf_mex_printf("%s =\\n", "poseBML");
                              for (c4_i445 = 0; c4_i445 < 256; c4_i445++) {
                                c4_n_u[c4_i445] = c4_poseBML[c4_i445];
                              }

                              c4_n_y = NULL;
                              sf_mex_assign(&c4_n_y, sf_mex_create("y", c4_n_u,
                                0, 0U, 1U, 0U, 1, 256), false);
                              sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                "disp", 0U, 1U, 14, c4_n_y);
                              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -115);
                            } else {
                              _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 101);
                              if (CV_EML_IF(7, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 102);
                                CV_EML_FCN(7, 5);
                                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                              139U);
                                c4_x_encStr2Arr(chartInstance, c4_dv101);
                                for (c4_i446 = 0; c4_i446 < 256; c4_i446++) {
                                  c4_poseBML[c4_i446] = c4_dv101[c4_i446];
                                }

                                sf_mex_printf("%s =\\n", "poseBML");
                                for (c4_i447 = 0; c4_i447 < 256; c4_i447++) {
                                  c4_o_u[c4_i447] = c4_poseBML[c4_i447];
                                }

                                c4_o_y = NULL;
                                sf_mex_assign(&c4_o_y, sf_mex_create("y", c4_o_u,
                                  0, 0U, 1U, 0U, 1, 256), false);
                                sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                  "disp", 0U, 1U, 14, c4_o_y);
                                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                              -139);
                              } else {
                                _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, 103);
                                if (CV_EML_IF(7, 1, 15,
                                              c4_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                104);
                                  CV_EML_FCN(7, 6);
                                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                145U);
                                  c4_y_encStr2Arr(chartInstance, c4_dv102);
                                  for (c4_i448 = 0; c4_i448 < 256; c4_i448++) {
                                    c4_poseBML[c4_i448] = c4_dv102[c4_i448];
                                  }

                                  sf_mex_printf("%s =\\n", "poseBML");
                                  for (c4_i449 = 0; c4_i449 < 256; c4_i449++) {
                                    c4_p_u[c4_i449] = c4_poseBML[c4_i449];
                                  }

                                  c4_p_y = NULL;
                                  sf_mex_assign(&c4_p_y, sf_mex_create("y",
                                    c4_p_u, 0, 0U, 1U, 0U, 1, 256), false);
                                  sf_mex_call_debug(sfGlobalDebugInstanceStruct,
                                                    "disp", 0U, 1U, 14, c4_p_y);
                                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                105);
                                  if (CV_EML_IF(7, 1, 16,
                                                c4_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  106);
                                    CV_EML_FCN(7, 9);
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  163U);
                                    c4_cb_encStr2Arr(chartInstance, c4_dv103);
                                    for (c4_i450 = 0; c4_i450 < 256; c4_i450++)
                                    {
                                      c4_poseBML[c4_i450] = c4_dv103[c4_i450];
                                    }

                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c4_i451 = 0; c4_i451 < 256; c4_i451++)
                                    {
                                      c4_q_u[c4_i451] = c4_poseBML[c4_i451];
                                    }

                                    c4_q_y = NULL;
                                    sf_mex_assign(&c4_q_y, sf_mex_create("y",
                                      c4_q_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c4_q_y);
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  108);
                                    CV_EML_FCN(7, 7);
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  151U);
                                    c4_bb_encStr2Arr(chartInstance, c4_dv104);
                                    for (c4_i452 = 0; c4_i452 < 256; c4_i452++)
                                    {
                                      c4_poseBML[c4_i452] = c4_dv104[c4_i452];
                                    }

                                    sf_mex_printf("%s =\\n", "poseBML");
                                    for (c4_i453 = 0; c4_i453 < 256; c4_i453++)
                                    {
                                      c4_r_u[c4_i453] = c4_poseBML[c4_i453];
                                    }

                                    c4_r_y = NULL;
                                    sf_mex_assign(&c4_r_y, sf_mex_create("y",
                                      c4_r_u, 0, 0U, 1U, 0U, 1, 256), false);
                                    sf_mex_call_debug
                                      (sfGlobalDebugInstanceStruct, "disp", 0U,
                                       1U, 14, c4_r_y);
                                    _SFD_EML_CALL(7U, chartInstance->c4_sfEvent,
                                                  -151);
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

  _SFD_EML_CALL(7U, chartInstance->c4_sfEvent, -108);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c4_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i454;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i454, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i454;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_initalize, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_initalize),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_initalize);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_initalize;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_b_tp_initalize = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_initalize),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_initalize);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i455;
  real_T c4_b_inData[256];
  int32_T c4_i456;
  real_T c4_u[256];
  const mxArray *c4_y = NULL;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i455 = 0; c4_i455 < 256; c4_i455++) {
    c4_b_inData[c4_i455] = (*(real_T (*)[256])c4_inData)[c4_i455];
  }

  for (c4_i456 = 0; c4_i456 < 256; c4_i456++) {
    c4_u[c4_i456] = c4_b_inData[c4_i456];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_i_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[256])
{
  real_T c4_dv105[256];
  int32_T c4_i457;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv105, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c4_i457 = 0; c4_i457 < 256; c4_i457++) {
    c4_y[c4_i457] = c4_dv105[c4_i457];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_arg;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[256];
  int32_T c4_i458;
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)chartInstanceVoid;
  c4_arg = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_arg), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_arg);
  for (c4_i458 = 0; c4_i458 < 256; c4_i458++) {
    (*(real_T (*)[256])c4_outData)[c4_i458] = c4_y[c4_i458];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static uint32_T c4_j_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static uint32_T c4_k_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static uint32_T c4_l_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static uint32_T c4_m_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static void c4_n_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_o_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[625])
{
  uint32_T c4_uv3[625];
  int32_T c4_i459;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_c_state_not_empty = false;
  } else {
    chartInstance->c4_c_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c4_i459 = 0; c4_i459 < 625; c4_i459++) {
      c4_y[c4_i459] = c4_uv3[c4_i459];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_p_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_q_emlrt_marshallIn(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[2])
{
  uint32_T c4_uv4[2];
  int32_T c4_i460;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_b_state_not_empty = false;
  } else {
    chartInstance->c4_b_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i460 = 0; c4_i460 < 2; c4_i460++) {
      c4_y[c4_i460] = c4_uv4[c4_i460];
    }
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_r_emlrt_marshallIn
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray
   *c4_b_setSimStateSideEffectsInfo, const char_T *c4_identifier)
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
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, const mxArray *c4_u,
   const emlrtMsgIdentifier *c4_parentId)
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
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex)
{
  (void)chartInstance;
  c4_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c4_vectorIndex, 0, 20, 1, 0)] = true;
}

static void c4_errorIfDataNotWrittenToFcn
  (SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance, uint32_T
   c4_vectorIndex, uint32_T c4_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c4_dataNumber, c4_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c4_vectorIndex, 0, 20, 1,
    0)]);
}

static void c4_b_twister_state_vector(SFc4_testKinectGazeWaveGUIInstanceStruct
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

static real_T c4_c_eml_rand_mt19937ar(SFc4_testKinectGazeWaveGUIInstanceStruct
  *chartInstance, uint32_T c4_d_state[625])
{
  int32_T c4_i461;
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
    for (c4_i461 = 0; c4_i461 < 2; c4_i461++) {
      c4_u[c4_i461] = 0U;
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

static void init_dsm_address_info(SFc4_testKinectGazeWaveGUIInstanceStruct
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

void sf_c4_testKinectGazeWaveGUI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2930378133U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3227323497U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(593110288U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4155754884U);
}

mxArray *sf_c4_testKinectGazeWaveGUI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xODRPw1LzXvKwXRNwx7G0C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
      pr[0] = (double)(256);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_testKinectGazeWaveGUI_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_testKinectGazeWaveGUI_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_testKinectGazeWaveGUI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[372],T\"beat\",},{M[3],M[517],T\"beat2\",},{M[3],M[421],T\"count\",},{M[3],M[477],T\"gaze\",},{M[3],M[503],T\"m\",},{M[3],M[502],T\"n\",},{M[3],M[441],T\"txtAvert\",},{M[3],M[431],T\"txtBeat\",},{M[3],M[518],T\"txtBeat2\",},{M[3],M[475],T\"txtEyeTarget\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[478],T\"txtGaze\",},{M[3],M[476],T\"txtGaze2\",},{M[3],M[432],T\"txtNoSmile\",},{M[3],M[434],T\"txtSmile\",},{M[3],M[489],T\"txtWalkFw\",},{M[3],M[488],T\"txtWalkToNeutral\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c4_testKinectGazeWaveGUI\",},{M[9],M[0],T\"is_c4_testKinectGazeWaveGUI\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x10[394 492 428 481 448 390 398 505 21 445],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 23, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_testKinectGazeWaveGUI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _testKinectGazeWaveGUIMachineNumber_,
           4,
           22,
           43,
           0,
           30,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_testKinectGazeWaveGUIMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_testKinectGazeWaveGUIMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _testKinectGazeWaveGUIMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"beat");
          _SFD_SET_DATA_PROPS(1,1,1,0,"handLup");
          _SFD_SET_DATA_PROPS(2,1,1,0,"extraversionW");
          _SFD_SET_DATA_PROPS(3,0,0,0,"count");
          _SFD_SET_DATA_PROPS(4,0,0,0,"txtBeat");
          _SFD_SET_DATA_PROPS(5,0,0,0,"txtNoSmile");
          _SFD_SET_DATA_PROPS(6,0,0,0,"txtSmile");
          _SFD_SET_DATA_PROPS(7,0,0,0,"txtAvert");
          _SFD_SET_DATA_PROPS(8,0,0,0,"txtEyeTarget");
          _SFD_SET_DATA_PROPS(9,0,0,0,"txtGaze2");
          _SFD_SET_DATA_PROPS(10,0,0,0,"gaze");
          _SFD_SET_DATA_PROPS(11,0,0,0,"txtGaze");
          _SFD_SET_DATA_PROPS(12,0,0,0,"txtWalkToNeutral");
          _SFD_SET_DATA_PROPS(13,0,0,0,"txtWalkFw");
          _SFD_SET_DATA_PROPS(14,0,0,0,"n");
          _SFD_SET_DATA_PROPS(15,0,0,0,"m");
          _SFD_SET_DATA_PROPS(16,1,1,0,"handRup");
          _SFD_SET_DATA_PROPS(17,0,0,0,"beat2");
          _SFD_SET_DATA_PROPS(18,0,0,0,"txtBeat2");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,9,0,0,"");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,9,0,0,"");
          _SFD_SET_DATA_PROPS(27,8,0,0,"");
          _SFD_SET_DATA_PROPS(28,9,0,0,"");
          _SFD_SET_DATA_PROPS(29,8,0,0,"");
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
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
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_CH_SUBSTATE_COUNT(16);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,4);
          _SFD_CH_SUBSTATE_INDEX(1,5);
          _SFD_CH_SUBSTATE_INDEX(2,6);
          _SFD_CH_SUBSTATE_INDEX(3,9);
          _SFD_CH_SUBSTATE_INDEX(4,10);
          _SFD_CH_SUBSTATE_INDEX(5,11);
          _SFD_CH_SUBSTATE_INDEX(6,12);
          _SFD_CH_SUBSTATE_INDEX(7,13);
          _SFD_CH_SUBSTATE_INDEX(8,14);
          _SFD_CH_SUBSTATE_INDEX(9,15);
          _SFD_CH_SUBSTATE_INDEX(10,16);
          _SFD_CH_SUBSTATE_INDEX(11,17);
          _SFD_CH_SUBSTATE_INDEX(12,18);
          _SFD_CH_SUBSTATE_INDEX(13,19);
          _SFD_CH_SUBSTATE_INDEX(14,20);
          _SFD_CH_SUBSTATE_INDEX(15,21);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
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
        }

        _SFD_CV_INIT_CHART(16,1,0,0);

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
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"extravertIdlePose",0,-1,985);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",985,-1,1310);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",1310,-1,1631);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1631,-1,1953);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1953,-1,2258);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",2258,-1,2571);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",2571,-1,2902);
        _SFD_CV_INIT_EML_IF(2,1,0,549,579,610,983);
        _SFD_CV_INIT_EML_IF(2,1,1,610,644,675,983);
        _SFD_CV_INIT_EML_IF(2,1,2,675,709,740,983);
        _SFD_CV_INIT_EML_IF(2,1,3,740,774,805,983);
        _SFD_CV_INIT_EML_IF(2,1,4,805,839,870,983);
        _SFD_CV_INIT_EML_IF(2,1,5,870,904,935,983);
        _SFD_CV_INIT_EML(7,1,10,17,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"introvertIdlePose",0,-1,2656);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",2656,-1,2823);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",2823,-1,2989);
        _SFD_CV_INIT_EML_FCN(7,3,"aFcnTruthTableAction_3",2989,-1,3157);
        _SFD_CV_INIT_EML_FCN(7,4,"aFcnTruthTableAction_4",3157,-1,3329);
        _SFD_CV_INIT_EML_FCN(7,5,"aFcnTruthTableAction_5",3329,-1,3500);
        _SFD_CV_INIT_EML_FCN(7,6,"aFcnTruthTableAction_6",3500,-1,3681);
        _SFD_CV_INIT_EML_FCN(7,7,"aFcnTruthTableAction_7",3681,-1,3883);
        _SFD_CV_INIT_EML_FCN(7,8,"aFcnTruthTableAction_8",3883,-1,4051);
        _SFD_CV_INIT_EML_FCN(7,9,"aFcnTruthTableAction_9",4051,-1,4233);
        _SFD_CV_INIT_EML_IF(7,1,0,1497,1527,1558,2654);
        _SFD_CV_INIT_EML_IF(7,1,1,1558,1592,1623,2654);
        _SFD_CV_INIT_EML_IF(7,1,2,1623,1657,1688,2654);
        _SFD_CV_INIT_EML_IF(7,1,3,1688,1722,1753,2654);
        _SFD_CV_INIT_EML_IF(7,1,4,1753,1787,1818,2654);
        _SFD_CV_INIT_EML_IF(7,1,5,1818,1852,1883,2654);
        _SFD_CV_INIT_EML_IF(7,1,6,1883,1917,1948,2654);
        _SFD_CV_INIT_EML_IF(7,1,7,1948,1982,2013,2654);
        _SFD_CV_INIT_EML_IF(7,1,8,2013,2047,2078,2654);
        _SFD_CV_INIT_EML_IF(7,1,9,2078,2113,2144,2654);
        _SFD_CV_INIT_EML_IF(7,1,10,2144,2179,2210,2654);
        _SFD_CV_INIT_EML_IF(7,1,11,2210,2245,2276,2654);
        _SFD_CV_INIT_EML_IF(7,1,12,2276,2311,2342,2654);
        _SFD_CV_INIT_EML_IF(7,1,13,2342,2377,2408,2654);
        _SFD_CV_INIT_EML_IF(7,1,14,2408,2443,2474,2654);
        _SFD_CV_INIT_EML_IF(7,1,15,2474,2509,2540,2654);
        _SFD_CV_INIT_EML_IF(7,1,16,2540,2575,2606,2654);
        _SFD_CV_INIT_EML(1,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"copingInvaded",0,-1,686);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",686,-1,944);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",944,-1,1202);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1202,-1,1387);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1387,-1,1707);
        _SFD_CV_INIT_EML_IF(1,1,0,380,410,441,684);
        _SFD_CV_INIT_EML_IF(1,1,1,441,475,506,684);
        _SFD_CV_INIT_EML_IF(1,1,2,506,540,571,684);
        _SFD_CV_INIT_EML_IF(1,1,3,571,605,636,684);
        _SFD_CV_INIT_EML(0,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredPoseS",0,-1,1276);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1276,-1,1458);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1458,-1,1623);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1623,-1,1790);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1790,-1,1959);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",1959,-1,2128);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",2128,-1,2302);
        _SFD_CV_INIT_EML_IF(0,1,0,710,740,771,1274);
        _SFD_CV_INIT_EML_IF(0,1,1,771,805,836,1274);
        _SFD_CV_INIT_EML_IF(0,1,2,836,870,901,1274);
        _SFD_CV_INIT_EML_IF(0,1,3,901,935,966,1274);
        _SFD_CV_INIT_EML_IF(0,1,4,966,1000,1031,1274);
        _SFD_CV_INIT_EML_IF(0,1,5,1031,1065,1096,1274);
        _SFD_CV_INIT_EML_IF(0,1,6,1096,1130,1161,1274);
        _SFD_CV_INIT_EML_IF(0,1,7,1161,1195,1226,1274);
        _SFD_CV_INIT_EML(3,1,6,15,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"gazeAvert",0,-1,2342);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",2342,-1,2521);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",2521,-1,2708);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",2708,-1,2897);
        _SFD_CV_INIT_EML_FCN(3,4,"aFcnTruthTableAction_4",2897,-1,3078);
        _SFD_CV_INIT_EML_FCN(3,5,"aFcnTruthTableAction_5",3078,-1,3256);
        _SFD_CV_INIT_EML_IF(3,1,0,1315,1345,1376,2340);
        _SFD_CV_INIT_EML_IF(3,1,1,1376,1410,1441,2340);
        _SFD_CV_INIT_EML_IF(3,1,2,1441,1475,1506,2340);
        _SFD_CV_INIT_EML_IF(3,1,3,1506,1540,1571,2340);
        _SFD_CV_INIT_EML_IF(3,1,4,1571,1605,1636,2340);
        _SFD_CV_INIT_EML_IF(3,1,5,1636,1670,1701,2340);
        _SFD_CV_INIT_EML_IF(3,1,6,1701,1735,1766,2340);
        _SFD_CV_INIT_EML_IF(3,1,7,1766,1800,1831,2340);
        _SFD_CV_INIT_EML_IF(3,1,8,1831,1865,1896,2340);
        _SFD_CV_INIT_EML_IF(3,1,9,1896,1931,1962,2340);
        _SFD_CV_INIT_EML_IF(3,1,10,1962,1997,2028,2340);
        _SFD_CV_INIT_EML_IF(3,1,11,2028,2063,2094,2340);
        _SFD_CV_INIT_EML_IF(3,1,12,2094,2129,2160,2340);
        _SFD_CV_INIT_EML_IF(3,1,13,2160,2195,2226,2340);
        _SFD_CV_INIT_EML_IF(3,1,14,2226,2261,2292,2340);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(40,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(40,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(17,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(17,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(39,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(39,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(22,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(22,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(21,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(21,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(38,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(38,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(20,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(20,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(42,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(42,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(42,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,10,1,10);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(32,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(32,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(36,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(36,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(35,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(10,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(34,0,0,1,37,1,37);

        {
          static int condStart[] = { 1, 15, 29 };

          static int condEnd[] = { 11, 25, 37 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(34,0,0,1,37,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,36,1,36);

        {
          static int condStart[] = { 1, 15, 29 };

          static int condEnd[] = { 11, 25, 36 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,36,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,39,1,39);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(30,0,0,1,36,1,36);

        {
          static int condStart[] = { 1, 15, 29 };

          static int condEnd[] = { 11, 25, 36 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(30,0,0,1,36,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,0,12,0,12);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_bc_sf_marshallOut,(MexInFcnForType)
            c4_f_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(28,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(29,(void *)(NULL));

        {
          real_T *c4_handLup;
          real_T *c4_extraversionW;
          real_T *c4_handRup;
          c4_handRup = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_extraversionW = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_handLup = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c4_beat);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_handLup);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_extraversionW);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c4_count);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c4_txtBeat);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_txtNoSmile);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_txtSmile);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_txtAvert);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c4_txtEyeTarget);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c4_txtGaze2);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c4_gaze);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c4_txtGaze);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c4_txtWalkToNeutral);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c4_txtWalkFw);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c4_n);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c4_m);
          _SFD_SET_DATA_VALUE_PTR(16U, c4_handRup);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c4_beat2);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c4_txtBeat2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _testKinectGazeWaveGUIMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "0vxVfz2Ky6THxT11gdQGhF";
}

static void sf_opaque_initialize_c4_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_testKinectGazeWaveGUI
    ((SFc4_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar);
  initialize_c4_testKinectGazeWaveGUI((SFc4_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  enable_c4_testKinectGazeWaveGUI((SFc4_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  disable_c4_testKinectGazeWaveGUI((SFc4_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  sf_gateway_c4_testKinectGazeWaveGUI((SFc4_testKinectGazeWaveGUIInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_testKinectGazeWaveGUI
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_testKinectGazeWaveGUI
    ((SFc4_testKinectGazeWaveGUIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_testKinectGazeWaveGUI();/* state var info */
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

extern void sf_internal_set_sim_state_c4_testKinectGazeWaveGUI(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_testKinectGazeWaveGUI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_testKinectGazeWaveGUI
    ((SFc4_testKinectGazeWaveGUIInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_testKinectGazeWaveGUI(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_testKinectGazeWaveGUI(S);
}

static void sf_opaque_set_sim_state_c4_testKinectGazeWaveGUI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_testKinectGazeWaveGUI(S, st);
}

static void sf_opaque_terminate_c4_testKinectGazeWaveGUI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_testKinectGazeWaveGUI_optimization_info();
    }

    finalize_c4_testKinectGazeWaveGUI((SFc4_testKinectGazeWaveGUIInstanceStruct*)
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
  initSimStructsc4_testKinectGazeWaveGUI
    ((SFc4_testKinectGazeWaveGUIInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_testKinectGazeWaveGUI(SimStruct *S)
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
    initialize_params_c4_testKinectGazeWaveGUI
      ((SFc4_testKinectGazeWaveGUIInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_testKinectGazeWaveGUI(SimStruct *S)
{
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_testKinectGazeWaveGUI_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,4,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2103906784U));
  ssSetChecksum1(S,(3998665342U));
  ssSetChecksum2(S,(2892595852U));
  ssSetChecksum3(S,(1479318780U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_testKinectGazeWaveGUI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_testKinectGazeWaveGUI(SimStruct *S)
{
  SFc4_testKinectGazeWaveGUIInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_testKinectGazeWaveGUIInstanceStruct *)utMalloc(sizeof
    (SFc4_testKinectGazeWaveGUIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_testKinectGazeWaveGUIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_testKinectGazeWaveGUI;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_testKinectGazeWaveGUI;
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

void c4_testKinectGazeWaveGUI_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_testKinectGazeWaveGUI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_testKinectGazeWaveGUI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_testKinectGazeWaveGUI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_testKinectGazeWaveGUI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
