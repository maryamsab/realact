/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Gaze_sfun.h"
#include "c5_Expriment_Gaze.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Gaze_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c5_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c5_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c5_IN_checkGameOver            ((uint8_T)1U)
#define c5_IN_gameOver                 ((uint8_T)2U)
#define c5_IN_gazeCamera               ((uint8_T)3U)
#define c5_IN_saccadeFinish            ((uint8_T)4U)
#define c5_IN_stateBradWin             ((uint8_T)5U)
#define c5_IN_stateCompare             ((uint8_T)6U)
#define c5_IN_stateGo                  ((uint8_T)7U)
#define c5_IN_stateInit                ((uint8_T)8U)
#define c5_IN_stateNoWin               ((uint8_T)9U)
#define c5_IN_statePoseReady           ((uint8_T)10U)
#define c5_IN_stateReadUserHand        ((uint8_T)11U)
#define c5_IN_stateReady               ((uint8_T)12U)
#define c5_IN_stateShowHands           ((uint8_T)13U)
#define c5_IN_stateShowResult          ((uint8_T)14U)
#define c5_IN_stateSt1                 ((uint8_T)15U)
#define c5_IN_stateStart               ((uint8_T)16U)
#define c5_IN_stateUserWin             ((uint8_T)17U)
#define c5_IN_statePosePaper           ((uint8_T)1U)
#define c5_IN_statePoseRock            ((uint8_T)2U)
#define c5_IN_statePoseScissors        ((uint8_T)3U)
#define c5_IN_stateRandomeHand         ((uint8_T)4U)
#define c5_IN_wait                     ((uint8_T)5U)
#define c5_IN_stateAgentNotWin         ((uint8_T)1U)
#define c5_IN_stateAgentWin            ((uint8_T)2U)
#define c5_IN_stateBoredom             ((uint8_T)3U)
#define c5_b_IN_stateInit              ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[8] = { "full", "tempp", "i", "nargin",
  "nargout", "bmls", "mBML", "newBmls" };

static const char * c5_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_c_debug_family_names[8] = { "full", "tempp", "i",
  "nargin", "nargout", "bmls", "myBML", "newBmls" };

static const char * c5_d_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "p", "poseBML" };

static const char * c5_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_g_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_h_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "p", "poseBML" };

static const char * c5_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_j_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_l_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "p", "poseBML" };

static const char * c5_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_o_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c5_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_q_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_t_debug_family_names[23] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c5_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_v_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_gb_debug_family_names[9] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c5_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c5_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_fc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_rc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_jd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c5_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c5_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c5_dataWrittenToVector[22];

/* Function Declarations */
static void initialize_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void initialize_params_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void enable_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void disable_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void set_sim_state_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void c5_set_sim_state_side_effects_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void finalize_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void sf_gateway_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_enter_atomic_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance);
static void c5_enter_internal_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_exit_internal_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_initc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void initSimStructsc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_stateGame(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateSt1(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_enter_atomic_stateStart(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_stateStart(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_enter_atomic_saccadeFinish(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_stateInit(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_enter_atomic_gazeCamera(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_enter_atomic_stateReady(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_stateReady(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_statePoseReady(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateGo(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateReadUserHand(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_stateShowHands(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateUserWin(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateNoWin(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_stateShowResult(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_statePlayHand(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_enter_atomic_statePoseRock(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_enter_atomic_statePosePaper(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_enter_atomic_statePoseScissors(SFc5_Expriment_GazeInstanceStruct *
  chartInstance);
static void c5_enter_atomic_stateAgentNotWin(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);
static void c5_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_b_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_c_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_d_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_e_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_f_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_g_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_h_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_i_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_j_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_k_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_l_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_m_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_n_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_o_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_p_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_q_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_r_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_s_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_t_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_u_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_v_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_w_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_x_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_y_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_ab_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_bb_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void c5_cb_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000]);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  const mxArray *c5_newBmls, const char_T *c5_identifier, real_T c5_y[5000]);
static void c5_b_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[5000]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[1000]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_d_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_nargout, const char_T *c5_identifier);
static real_T c5_e_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[1000]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static boolean_T c5_g_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_w_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_x_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_y_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_db_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static void c5_activate_secsc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance);
static void c5_deactivate_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_increment_counters_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_reset_counters_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_insertQueuec5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_bmls[5000], real_T c5_mBML[1000], real_T c5_newBmls
  [5000]);
static void c5_insertQueueLowc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_bmls[5000], real_T c5_myBML[1000], real_T
  c5_newBmls[5000]);
static void c5_sendSBMc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_arg[256]);
static void c5_rockPoseTablec5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000]);
static void c5_paperPoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000]);
static void c5_scissorsPoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000]);
static void c5_handPoseSBTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_sbmID, real_T
   c5_poseSBM[1000]);
static void c5_idlePoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000]);
static void c5_initialPoseTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000]);
static void c5_sendSBM(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static void c5_b_sendSBM(SFc5_Expriment_GazeInstanceStruct *chartInstance);
static boolean_T c5_isequal(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_varargin_1[1000], real_T c5_varargin_2[1000]);
static const mxArray *c5_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int8_T c5_h_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_i_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static uint8_T c5_j_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_stateGame, const char_T *c5_identifier);
static uint8_T c5_k_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_l_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256]);
static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint32_T c5_m_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_temporalCounter_i3, const char_T
  *c5_identifier);
static uint32_T c5_n_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static const mxArray *c5_o_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier);
static const mxArray *c5_p_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_updateDataWrittenToVector(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_vectorIndex);
static void c5_errorIfDataNotWrittenToFcn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_vectorIndex, uint32_T c5_dataNumber);
static real_T c5_get_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_CONTEMPT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_CONTEMPT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_CONTEMPT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_P(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_P(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c);
static real_T *c5_access_P(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_GO(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_STATE_GO(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_GO(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_HAND(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_STATE_HAND(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_OVER(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_STATE_OVER(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_OVER(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_READY(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_STATE_READY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_READY(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_boredom(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_boredom(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_boredom(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_n(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_n(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c);
static real_T *c5_access_n(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                      c5_b, real_T c5_c);
static real_T *c5_access_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                      c5_b, real_T c5_c);
static real_T *c5_access_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_r(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_r(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c);
static real_T *c5_access_r(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static void c5_set_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c);
static real_T *c5_access_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_randSmile(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_randSmile(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_randSmile(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b);
static real_T c5_get_s(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_s(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c);
static real_T *c5_access_s(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_t(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_t(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c);
static real_T *c5_access_t(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static real_T c5_get_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void c5_set_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c);
static real_T *c5_access_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b);
static void init_dsm_address_info(SFc5_Expriment_GazeInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_debugger_state_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_prevAniVal;
  c5_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c5_is_active_c5_Expriment_Gaze == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_active_stateGame == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateSt1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateStart) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_saccadeFinish) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_gameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_checkGameOver) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_statePoseReady) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateGo) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateReadUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateShowHands) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateCompare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateUserWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateBradWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateNoWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGame == c5_IN_stateShowResult) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_active_statePlayHand == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_statePlayHand == c5_IN_stateRandomeHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_statePlayHand == c5_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_statePlayHand == c5_IN_statePoseRock) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_statePlayHand == c5_IN_statePosePaper) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_statePlayHand == c5_IN_statePoseScissors) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_active_stateGameOver == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGameOver == c5_b_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGameOver == c5_IN_stateAgentNotWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGameOver == c5_IN_stateAgentWin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
  }

  if (chartInstance->c5_is_stateGameOver == c5_IN_stateBoredom) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
  }

  _SFD_SET_ANIMATION(c5_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_e_hoistedGlobal;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_f_hoistedGlobal;
  real_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_g_hoistedGlobal;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i0;
  real_T c5_h_u[5000];
  const mxArray *c5_i_y = NULL;
  int32_T c5_i1;
  real_T c5_i_u[5000];
  const mxArray *c5_j_y = NULL;
  uint8_T c5_h_hoistedGlobal;
  uint8_T c5_j_u;
  const mxArray *c5_k_y = NULL;
  uint8_T c5_i_hoistedGlobal;
  uint8_T c5_k_u;
  const mxArray *c5_l_y = NULL;
  uint8_T c5_j_hoistedGlobal;
  uint8_T c5_l_u;
  const mxArray *c5_m_y = NULL;
  uint8_T c5_k_hoistedGlobal;
  uint8_T c5_m_u;
  const mxArray *c5_n_y = NULL;
  uint8_T c5_l_hoistedGlobal;
  uint8_T c5_n_u;
  const mxArray *c5_o_y = NULL;
  uint8_T c5_m_hoistedGlobal;
  uint8_T c5_o_u;
  const mxArray *c5_p_y = NULL;
  uint8_T c5_n_hoistedGlobal;
  uint8_T c5_p_u;
  const mxArray *c5_q_y = NULL;
  uint32_T c5_o_hoistedGlobal;
  uint32_T c5_q_u;
  const mxArray *c5_r_y = NULL;
  uint32_T c5_p_hoistedGlobal;
  uint32_T c5_r_u;
  const mxArray *c5_s_y = NULL;
  uint32_T c5_q_hoistedGlobal;
  uint32_T c5_s_u;
  const mxArray *c5_t_y = NULL;
  real_T *c5_bWinT;
  real_T *c5_bradHand;
  real_T *c5_gameState;
  real_T *c5_round;
  real_T *c5_uWinT;
  real_T *c5_userHand;
  real_T *c5_win;
  c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(19, 1), false);
  c5_hoistedGlobal = *c5_bWinT;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_bradHand;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_gameState;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_round;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = *c5_uWinT;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_f_hoistedGlobal = *c5_userHand;
  c5_f_u = c5_f_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 5, c5_g_y);
  c5_g_hoistedGlobal = *c5_win;
  c5_g_u = c5_g_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 6, c5_h_y);
  for (c5_i0 = 0; c5_i0 < 5000; c5_i0++) {
    c5_h_u[c5_i0] = chartInstance->c5_newBmlsH[c5_i0];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_h_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c5_y, 7, c5_i_y);
  for (c5_i1 = 0; c5_i1 < 5000; c5_i1++) {
    c5_i_u[c5_i1] = chartInstance->c5_newBmlsL[c5_i1];
  }

  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_i_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c5_y, 8, c5_j_y);
  c5_h_hoistedGlobal = chartInstance->c5_is_active_c5_Expriment_Gaze;
  c5_j_u = c5_h_hoistedGlobal;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 9, c5_k_y);
  c5_i_hoistedGlobal = chartInstance->c5_is_active_stateGame;
  c5_k_u = c5_i_hoistedGlobal;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 10, c5_l_y);
  c5_j_hoistedGlobal = chartInstance->c5_is_active_statePlayHand;
  c5_l_u = c5_j_hoistedGlobal;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 11, c5_m_y);
  c5_k_hoistedGlobal = chartInstance->c5_is_active_stateGameOver;
  c5_m_u = c5_k_hoistedGlobal;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 12, c5_n_y);
  c5_l_hoistedGlobal = chartInstance->c5_is_stateGame;
  c5_n_u = c5_l_hoistedGlobal;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 13, c5_o_y);
  c5_m_hoistedGlobal = chartInstance->c5_is_statePlayHand;
  c5_o_u = c5_m_hoistedGlobal;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 14, c5_p_y);
  c5_n_hoistedGlobal = chartInstance->c5_is_stateGameOver;
  c5_p_u = c5_n_hoistedGlobal;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 15, c5_q_y);
  c5_o_hoistedGlobal = chartInstance->c5_temporalCounter_i3;
  c5_q_u = c5_o_hoistedGlobal;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_q_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 16, c5_r_y);
  c5_p_hoistedGlobal = chartInstance->c5_temporalCounter_i2;
  c5_r_u = c5_p_hoistedGlobal;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_r_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 17, c5_s_y);
  c5_q_hoistedGlobal = chartInstance->c5_temporalCounter_i1;
  c5_s_u = c5_q_hoistedGlobal;
  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", &c5_s_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 18, c5_t_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[5000];
  int32_T c5_i2;
  real_T c5_dv1[5000];
  int32_T c5_i3;
  real_T *c5_bWinT;
  real_T *c5_bradHand;
  real_T *c5_gameState;
  real_T *c5_round;
  real_T *c5_uWinT;
  real_T *c5_userHand;
  real_T *c5_win;
  c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_u = sf_mex_dup(c5_st);
  *c5_bWinT = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 0)), "bWinT");
  *c5_bradHand = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 1)), "bradHand");
  *c5_gameState = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 2)), "gameState");
  *c5_round = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 3)), "round");
  *c5_uWinT = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 4)), "uWinT");
  *c5_userHand = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 5)), "userHand");
  *c5_win = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    6)), "win");
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 7)),
                      "newBmlsH", c5_dv0);
  for (c5_i2 = 0; c5_i2 < 5000; c5_i2++) {
    chartInstance->c5_newBmlsH[c5_i2] = c5_dv0[c5_i2];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 8)),
                      "newBmlsL", c5_dv1);
  for (c5_i3 = 0; c5_i3 < 5000; c5_i3++) {
    chartInstance->c5_newBmlsL[c5_i3] = c5_dv1[c5_i3];
  }

  chartInstance->c5_is_active_c5_Expriment_Gaze = c5_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 9)),
     "is_active_c5_Expriment_Gaze");
  chartInstance->c5_is_active_stateGame = c5_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 10)), "is_active_stateGame");
  chartInstance->c5_is_active_statePlayHand = c5_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 11)),
     "is_active_statePlayHand");
  chartInstance->c5_is_active_stateGameOver = c5_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 12)),
     "is_active_stateGameOver");
  chartInstance->c5_is_stateGame = c5_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 13)), "is_stateGame");
  chartInstance->c5_is_statePlayHand = c5_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 14)), "is_statePlayHand");
  chartInstance->c5_is_stateGameOver = c5_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 15)), "is_stateGameOver");
  chartInstance->c5_temporalCounter_i3 = c5_m_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 16)), "temporalCounter_i3");
  chartInstance->c5_temporalCounter_i2 = c5_m_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 17)), "temporalCounter_i2");
  chartInstance->c5_temporalCounter_i1 = c5_m_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 18)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c5_setSimStateSideEffectsInfo,
                c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 19)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c5_u);
  chartInstance->c5_doSetSimStateSideEffects = 1U;
  c5_update_debugger_state_c5_Expriment_Gaze(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void c5_set_sim_state_side_effects_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  if (chartInstance->c5_doSetSimStateSideEffects != 0) {
    if (chartInstance->c5_is_active_stateGame == 1U) {
      chartInstance->c5_tp_stateGame = 1U;
    } else {
      chartInstance->c5_tp_stateGame = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_checkGameOver) {
      chartInstance->c5_tp_checkGameOver = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_checkGameOver = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_gameOver) {
      chartInstance->c5_tp_gameOver = 1U;
    } else {
      chartInstance->c5_tp_gameOver = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_gazeCamera) {
      chartInstance->c5_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_gazeCamera = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_saccadeFinish) {
      chartInstance->c5_tp_saccadeFinish = 1U;
    } else {
      chartInstance->c5_tp_saccadeFinish = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateBradWin) {
      chartInstance->c5_tp_stateBradWin = 1U;
    } else {
      chartInstance->c5_tp_stateBradWin = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateCompare) {
      chartInstance->c5_tp_stateCompare = 1U;
    } else {
      chartInstance->c5_tp_stateCompare = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateGo) {
      chartInstance->c5_tp_stateGo = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateGo = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateInit) {
      chartInstance->c5_tp_stateInit = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateInit = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateNoWin) {
      chartInstance->c5_tp_stateNoWin = 1U;
    } else {
      chartInstance->c5_tp_stateNoWin = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_statePoseReady) {
      chartInstance->c5_tp_statePoseReady = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_statePoseReady = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateReadUserHand) {
      chartInstance->c5_tp_stateReadUserHand = 1U;
    } else {
      chartInstance->c5_tp_stateReadUserHand = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateReady) {
      chartInstance->c5_tp_stateReady = 1U;
    } else {
      chartInstance->c5_tp_stateReady = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateShowHands) {
      chartInstance->c5_tp_stateShowHands = 1U;
    } else {
      chartInstance->c5_tp_stateShowHands = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateShowResult) {
      chartInstance->c5_tp_stateShowResult = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateShowResult = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateSt1) {
      chartInstance->c5_tp_stateSt1 = 1U;
    } else {
      chartInstance->c5_tp_stateSt1 = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateStart) {
      chartInstance->c5_tp_stateStart = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 18) == 0.0) {
        chartInstance->c5_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateStart = 0U;
    }

    if (chartInstance->c5_is_stateGame == c5_IN_stateUserWin) {
      chartInstance->c5_tp_stateUserWin = 1U;
    } else {
      chartInstance->c5_tp_stateUserWin = 0U;
    }

    if (chartInstance->c5_is_active_statePlayHand == 1U) {
      chartInstance->c5_tp_statePlayHand = 1U;
    } else {
      chartInstance->c5_tp_statePlayHand = 0U;
    }

    if (chartInstance->c5_is_statePlayHand == c5_IN_statePosePaper) {
      chartInstance->c5_tp_statePosePaper = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c5_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c5_tp_statePosePaper = 0U;
    }

    if (chartInstance->c5_is_statePlayHand == c5_IN_statePoseRock) {
      chartInstance->c5_tp_statePoseRock = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 22) == 0.0) {
        chartInstance->c5_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c5_tp_statePoseRock = 0U;
    }

    if (chartInstance->c5_is_statePlayHand == c5_IN_statePoseScissors) {
      chartInstance->c5_tp_statePoseScissors = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 23) == 0.0) {
        chartInstance->c5_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c5_tp_statePoseScissors = 0U;
    }

    if (chartInstance->c5_is_statePlayHand == c5_IN_stateRandomeHand) {
      chartInstance->c5_tp_stateRandomeHand = 1U;
    } else {
      chartInstance->c5_tp_stateRandomeHand = 0U;
    }

    if (chartInstance->c5_is_statePlayHand == c5_IN_wait) {
      chartInstance->c5_tp_wait = 1U;
    } else {
      chartInstance->c5_tp_wait = 0U;
    }

    if (chartInstance->c5_is_active_stateGameOver == 1U) {
      chartInstance->c5_tp_stateGameOver = 1U;
    } else {
      chartInstance->c5_tp_stateGameOver = 0U;
    }

    if (chartInstance->c5_is_stateGameOver == c5_IN_stateAgentNotWin) {
      chartInstance->c5_tp_stateAgentNotWin = 1U;
    } else {
      chartInstance->c5_tp_stateAgentNotWin = 0U;
    }

    if (chartInstance->c5_is_stateGameOver == c5_IN_stateAgentWin) {
      chartInstance->c5_tp_stateAgentWin = 1U;
    } else {
      chartInstance->c5_tp_stateAgentWin = 0U;
    }

    if (chartInstance->c5_is_stateGameOver == c5_IN_stateBoredom) {
      chartInstance->c5_tp_stateBoredom = 1U;
      if (sf_mex_sub(chartInstance->c5_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 29) == 0.0) {
        chartInstance->c5_temporalCounter_i3 = 0U;
      }
    } else {
      chartInstance->c5_tp_stateBoredom = 0U;
    }

    if (chartInstance->c5_is_stateGameOver == c5_b_IN_stateInit) {
      chartInstance->c5_b_tp_stateInit = 1U;
    } else {
      chartInstance->c5_b_tp_stateInit = 0U;
    }

    chartInstance->c5_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c5_setSimStateSideEffectsInfo);
}

static void sf_gateway_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  c5_set_sim_state_side_effects_c5_Expriment_Gaze(chartInstance);
}

static void c5_enter_atomic_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  chartInstance->c5_is_active_c5_Expriment_Gaze = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
}

static void c5_enter_internal_c5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T *c5_gameState;
  real_T *c5_round;
  real_T *c5_userHand;
  real_T *c5_bradHand;
  real_T *c5_win;
  real_T *c5_uWinT;
  real_T *c5_bWinT;
  c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_active_stateGame = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateGame = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGame = c5_IN_stateSt1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateSt1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_lb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_STATE_READY(chartInstance, 0, 7.0);
  ssUpdateDataStoreLog(chartInstance->S, 20);
  c5_set_STATE_GO(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 17);
  c5_set_STATE_HAND(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 18);
  c5_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 19);
  c5_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 16);
  c5_set_STATE_RESULT(chartInstance, 0, 5.0);
  ssUpdateDataStoreLog(chartInstance->S, 21);
  c5_set_STATE_WAIT(chartInstance, 0, 6.0);
  ssUpdateDataStoreLog(chartInstance->S, 22);
  *c5_gameState = 14.0;
  c5_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
  c5_set_BORED(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c5_set_SAD(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c5_set_FRUST(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c5_set_FEAR(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c5_set_CONTEMPT(chartInstance, 0, 5.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c5_set_IDLE(chartInstance, 0, 6.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c5_set_HAPPY(chartInstance, 0, 7.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  c5_set_EXCITE(chartInstance, 0, 8.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  *c5_round = 0.0;
  c5_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_round, 43U);
  c5_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 23);
  c5_set_gazing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 31);
  c5_set_uHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 42);
  c5_set_bHand(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 25);
  c5_set_randSmile(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 38);
  *c5_userHand = 3.0;
  c5_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_userHand, 3U);
  *c5_bradHand = 3.0;
  c5_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_bradHand, 2U);
  *c5_win = 0.0;
  c5_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
  *c5_uWinT = 0.0;
  c5_updateDataWrittenToVector(chartInstance, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_uWinT, 10U);
  *c5_bWinT = 0.0;
  c5_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_bWinT, 9U);
  c5_set_BOREDOM_THRESHOLD(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c5_set_boredom(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 28);
  c5_set_t(chartInstance, 0, 10.0);
  ssUpdateDataStoreLog(chartInstance->S, 40);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_active_statePlayHand = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_statePlayHand = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_statePlayHand = c5_IN_stateRandomeHand;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateRandomeHand = 1U;
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_active_stateGameOver = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateGameOver = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGameOver = c5_b_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
  chartInstance->c5_b_tp_stateInit = 1U;
}

static void c5_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 1.0;
  boolean_T c5_b_out;
  real_T c5_d_nargin = 0.0;
  real_T c5_d_nargout = 1.0;
  boolean_T c5_c_out;
  real_T c5_e_nargin = 0.0;
  real_T c5_e_nargout = 1.0;
  boolean_T c5_d_out;
  real_T c5_f_nargin = 0.0;
  real_T c5_f_nargout = 0.0;
  real_T *c5_gameState;
  real_T *c5_uWinT;
  real_T *c5_bWinT;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_isStable = true;
  c5_stateGame(chartInstance);
  c5_statePlayHand(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c5_sfEvent);
  switch (chartInstance->c5_is_stateGameOver) {
   case c5_IN_stateAgentNotWin:
    CV_STATE_EVAL(27, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateAgentNotWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGameOver = c5_IN_stateBoredom;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i3 = 0U;
    chartInstance->c5_tp_stateBoredom = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateAgentWin:
    CV_STATE_EVAL(27, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateAgentWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGameOver = c5_IN_stateBoredom;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i3 = 0U;
    chartInstance->c5_tp_stateBoredom = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateBoredom:
    CV_STATE_EVAL(27, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_id_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
    if (c5_temp) {
      c5_temp = (chartInstance->c5_temporalCounter_i3 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(5.0 * c5_get_t
        (chartInstance, 0)), 32U, 34U));
    }

    guard2 = false;
    if (CV_EML_COND(34, 0, 0, c5_temp)) {
      if (CV_EML_COND(34, 0, 1, c5_get_boredom(chartInstance, 0) <
                      c5_get_BOREDOM_THRESHOLD(chartInstance, 0) - 2.0)) {
        CV_EML_MCDC(34, 0, 0, true);
        CV_EML_IF(34, 0, 0, true);
        c5_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(34, 0, 0, false);
      CV_EML_IF(34, 0, 0, false);
      c5_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c5_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_jd_debug_family_names,
        c5_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      c5_set_boredom(chartInstance, 0, c5_get_boredom(chartInstance, 0) + 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 28);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c5_tp_stateBoredom = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGameOver = c5_IN_stateBoredom;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i3 = 0U;
      chartInstance->c5_tp_stateBoredom = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c5_sfEvent);
    break;

   case c5_b_IN_stateInit:
    CV_STATE_EVAL(27, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_fd_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    c5_b_out = CV_EML_IF(29, 0, 0, *c5_gameState == c5_get_STATE_OVER
                         (chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c5_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                   chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_hd_debug_family_names,
        c5_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_out, 2U, c5_f_sf_marshallOut,
        c5_e_sf_marshallIn);
      c5_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
      c5_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
      c5_c_out = CV_EML_IF(31, 0, 0, *c5_uWinT >= *c5_bWinT);
      _SFD_SYMBOL_SCOPE_POP();
      if (c5_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
        chartInstance->c5_b_tp_stateInit = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
        chartInstance->c5_isStable = false;
        chartInstance->c5_is_stateGameOver = c5_IN_stateAgentNotWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_stateAgentNotWin = 1U;
        c5_enter_atomic_stateAgentNotWin(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                     chartInstance->c5_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_gd_debug_family_names,
          c5_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargin, 0U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargout, 1U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_out, 2U, c5_f_sf_marshallOut,
          c5_e_sf_marshallIn);
        c5_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
        c5_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
        c5_d_out = CV_EML_IF(30, 0, 0, *c5_uWinT < *c5_bWinT);
        _SFD_SYMBOL_SCOPE_POP();
        if (c5_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
          chartInstance->c5_b_tp_stateInit = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
          chartInstance->c5_isStable = false;
          chartInstance->c5_is_stateGameOver = c5_IN_stateAgentWin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_stateAgentWin = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_fc_debug_family_names,
            c5_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargin, 0U,
            c5_c_sf_marshallOut, c5_c_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargout, 1U,
            c5_c_sf_marshallOut, c5_c_sf_marshallIn);
          c5_set_gazing(chartInstance, 0, c5_get_GAZE_WIN(chartInstance, 0));
          ssUpdateDataStoreLog(chartInstance->S, 31);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 0, 0);
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c5_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
}

static void c5_exit_internal_c5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c5_is_stateGameOver) {
   case c5_IN_stateAgentNotWin:
    CV_STATE_EVAL(27, 1, 1);
    chartInstance->c5_tp_stateAgentNotWin = 0U;
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateAgentWin:
    CV_STATE_EVAL(27, 1, 2);
    chartInstance->c5_tp_stateAgentWin = 0U;
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateBoredom:
    CV_STATE_EVAL(27, 1, 3);
    chartInstance->c5_tp_stateBoredom = 0U;
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c5_sfEvent);
    break;

   case c5_b_IN_stateInit:
    CV_STATE_EVAL(27, 1, 4);
    chartInstance->c5_b_tp_stateInit = 0U;
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 1, 0);
    chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c5_sfEvent);
    break;
  }

  chartInstance->c5_tp_stateGameOver = 0U;
  chartInstance->c5_is_active_stateGameOver = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
  switch (chartInstance->c5_is_statePlayHand) {
   case c5_IN_statePosePaper:
    CV_STATE_EVAL(32, 1, 1);
    chartInstance->c5_tp_statePosePaper = 0U;
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_statePoseRock:
    CV_STATE_EVAL(32, 1, 2);
    chartInstance->c5_tp_statePoseRock = 0U;
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_statePoseScissors:
    CV_STATE_EVAL(32, 1, 3);
    chartInstance->c5_tp_statePoseScissors = 0U;
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateRandomeHand:
    CV_STATE_EVAL(32, 1, 4);
    chartInstance->c5_tp_stateRandomeHand = 0U;
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_wait:
    CV_STATE_EVAL(32, 1, 5);
    chartInstance->c5_tp_wait = 0U;
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(32, 1, 0);
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
    break;
  }

  chartInstance->c5_tp_statePlayHand = 0U;
  chartInstance->c5_is_active_statePlayHand = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, chartInstance->c5_sfEvent);
  switch (chartInstance->c5_is_stateGame) {
   case c5_IN_checkGameOver:
    CV_STATE_EVAL(9, 1, 1);
    chartInstance->c5_tp_checkGameOver = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_gameOver:
    CV_STATE_EVAL(9, 1, 2);
    chartInstance->c5_tp_gameOver = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_gazeCamera:
    CV_STATE_EVAL(9, 1, 3);
    chartInstance->c5_tp_gazeCamera = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_saccadeFinish:
    CV_STATE_EVAL(9, 1, 4);
    chartInstance->c5_tp_saccadeFinish = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateBradWin:
    CV_STATE_EVAL(9, 1, 5);
    chartInstance->c5_tp_stateBradWin = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateCompare:
    CV_STATE_EVAL(9, 1, 6);
    chartInstance->c5_tp_stateCompare = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateGo:
    CV_STATE_EVAL(9, 1, 7);
    chartInstance->c5_tp_stateGo = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateInit:
    CV_STATE_EVAL(9, 1, 8);
    chartInstance->c5_tp_stateInit = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateNoWin:
    CV_STATE_EVAL(9, 1, 9);
    chartInstance->c5_tp_stateNoWin = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_statePoseReady:
    CV_STATE_EVAL(9, 1, 10);
    chartInstance->c5_tp_statePoseReady = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateReadUserHand:
    CV_STATE_EVAL(9, 1, 11);
    chartInstance->c5_tp_stateReadUserHand = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateReady:
    CV_STATE_EVAL(9, 1, 12);
    chartInstance->c5_tp_stateReady = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateShowHands:
    CV_STATE_EVAL(9, 1, 13);
    chartInstance->c5_tp_stateShowHands = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateShowResult:
    CV_STATE_EVAL(9, 1, 14);
    chartInstance->c5_tp_stateShowResult = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateSt1:
    CV_STATE_EVAL(9, 1, 15);
    chartInstance->c5_tp_stateSt1 = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateStart:
    CV_STATE_EVAL(9, 1, 16);
    chartInstance->c5_tp_stateStart = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateUserWin:
    CV_STATE_EVAL(9, 1, 17);
    chartInstance->c5_tp_stateUserWin = 0U;
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 1, 0);
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
    break;
  }

  chartInstance->c5_tp_stateGame = 0U;
  chartInstance->c5_is_active_stateGame = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
}

static void c5_initc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_doSetSimStateSideEffects = 0U;
  chartInstance->c5_setSimStateSideEffectsInfo = NULL;
  chartInstance->c5_is_active_stateGame = 0U;
  chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
  chartInstance->c5_tp_stateGame = 0U;
  chartInstance->c5_tp_checkGameOver = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_gameOver = 0U;
  chartInstance->c5_tp_gazeCamera = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_saccadeFinish = 0U;
  chartInstance->c5_tp_stateBradWin = 0U;
  chartInstance->c5_tp_stateCompare = 0U;
  chartInstance->c5_tp_stateGo = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateInit = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateNoWin = 0U;
  chartInstance->c5_tp_statePoseReady = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateReadUserHand = 0U;
  chartInstance->c5_tp_stateReady = 0U;
  chartInstance->c5_tp_stateShowHands = 0U;
  chartInstance->c5_tp_stateShowResult = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateSt1 = 0U;
  chartInstance->c5_tp_stateStart = 0U;
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateUserWin = 0U;
  chartInstance->c5_is_active_stateGameOver = 0U;
  chartInstance->c5_is_stateGameOver = c5_IN_NO_ACTIVE_CHILD;
  chartInstance->c5_tp_stateGameOver = 0U;
  chartInstance->c5_tp_stateAgentNotWin = 0U;
  chartInstance->c5_tp_stateAgentWin = 0U;
  chartInstance->c5_tp_stateBoredom = 0U;
  chartInstance->c5_temporalCounter_i3 = 0U;
  chartInstance->c5_b_tp_stateInit = 0U;
  chartInstance->c5_is_active_statePlayHand = 0U;
  chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
  chartInstance->c5_tp_statePlayHand = 0U;
  chartInstance->c5_tp_statePosePaper = 0U;
  chartInstance->c5_temporalCounter_i2 = 0U;
  chartInstance->c5_tp_statePoseRock = 0U;
  chartInstance->c5_temporalCounter_i2 = 0U;
  chartInstance->c5_tp_statePoseScissors = 0U;
  chartInstance->c5_temporalCounter_i2 = 0U;
  chartInstance->c5_tp_stateRandomeHand = 0U;
  chartInstance->c5_tp_wait = 0U;
  chartInstance->c5_is_active_c5_Expriment_Gaze = 0U;
}

static void initSimStructsc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_stateGame(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 1.0;
  boolean_T c5_b_out;
  boolean_T c5_temp;
  real_T c5_d_nargin = 0.0;
  real_T c5_d_nargout = 0.0;
  real_T c5_e_nargin = 0.0;
  real_T c5_e_nargout = 1.0;
  boolean_T c5_c_out;
  real_T c5_f_nargin = 0.0;
  real_T c5_f_nargout = 1.0;
  boolean_T c5_d_out;
  real_T c5_g_nargin = 0.0;
  real_T c5_g_nargout = 0.0;
  real_T c5_h_nargin = 0.0;
  real_T c5_h_nargout = 1.0;
  boolean_T c5_e_out;
  real_T c5_i_nargin = 0.0;
  real_T c5_i_nargout = 0.0;
  int32_T c5_i4;
  static char_T c5_cv0[7] = { 'b', 'r', 'a', 'd', 'W', 'o', 'n' };

  char_T c5_u[7];
  const mxArray *c5_y = NULL;
  real_T c5_j_nargin = 0.0;
  real_T c5_j_nargout = 1.0;
  boolean_T c5_f_out;
  real_T c5_k_nargin = 0.0;
  real_T c5_k_nargout = 0.0;
  int32_T c5_i5;
  static char_T c5_cv1[7] = { 'u', 's', 'e', 'r', 'W', 'o', 'n' };

  char_T c5_b_u[7];
  const mxArray *c5_b_y = NULL;
  real_T c5_l_nargin = 0.0;
  real_T c5_l_nargout = 1.0;
  boolean_T c5_g_out;
  real_T c5_m_nargin = 0.0;
  real_T c5_m_nargout = 0.0;
  int32_T c5_i6;
  static char_T c5_cv2[7] = { 'n', 'o', 'n', 'e', 'W', 'o', 'n' };

  char_T c5_c_u[7];
  const mxArray *c5_c_y = NULL;
  real_T *c5_round;
  real_T *c5_gameState;
  real_T *c5_win;
  real_T *c5_uWinT;
  real_T *c5_bWinT;
  boolean_T guard1 = false;
  c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c5_sfEvent);
  switch (chartInstance->c5_is_stateGame) {
   case c5_IN_checkGameOver:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_ic_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_errorIfDataNotWrittenToFcn(chartInstance, 6U, 43U);
    c5_out = CV_EML_IF(1, 0, 0, *c5_round == 5.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_checkGameOver = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_gameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_gameOver = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ob_debug_family_names,
        c5_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      *c5_gameState = c5_get_STATE_OVER(chartInstance, 0);
      c5_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
      c5_set_boredom(chartInstance, 0, c5_get_boredom(chartInstance, 0) - 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 28);
      c5_set_gazing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 31);
      *c5_win = 0.0;
      c5_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                   chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_jc_debug_family_names,
        c5_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 2U, c5_f_sf_marshallOut,
        c5_e_sf_marshallIn);
      c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
      if (c5_temp) {
        c5_temp = (chartInstance->c5_temporalCounter_i1 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c5_get_t
                    (chartInstance, 0), 32U, 41U));
      }

      c5_b_out = CV_EML_IF(41, 0, 0, c5_temp);
      _SFD_SYMBOL_SCOPE_POP();
      if (c5_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_checkGameOver = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
        chartInstance->c5_isStable = false;
        chartInstance->c5_is_stateGame = c5_IN_stateInit;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
        chartInstance->c5_temporalCounter_i1 = 0U;
        chartInstance->c5_tp_stateInit = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_pb_debug_family_names,
          c5_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargin, 0U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargout, 1U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        *c5_gameState = c5_get_STATE_READY(chartInstance, 0);
        c5_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                     chartInstance->c5_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_gameOver:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c5_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_gazeCamera:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_mc_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_c_out = CV_EML_IF(38, 0, 0, (chartInstance->c5_sfEvent == c5_event_secs) &&
                         (chartInstance->c5_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_gazeCamera = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateReady = 1U;
      c5_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_saccadeFinish:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_hc_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    c5_d_out = CV_EML_IF(40, 0, 0, *c5_gameState == 25.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_saccadeFinish = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_checkGameOver;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i1 = 0U;
      chartInstance->c5_tp_checkGameOver = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateBradWin:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateBradWin = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_stateShowResult;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_stateShowResult = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ac_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_set_gazing(chartInstance, 0, c5_get_GAZE_GUI(chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 31);
    *c5_gameState = c5_get_STATE_WAIT(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateCompare:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_vc_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_h_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_h_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_e_out = CV_EML_IF(11, 0, 0, c5_get_diff(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateCompare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_stateBradWin;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateBradWin = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_xb_debug_family_names,
        c5_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      *c5_win = 2.0;
      c5_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
      for (c5_i4 = 0; c5_i4 < 7; c5_i4++) {
        c5_u[c5_i4] = c5_cv0[c5_i4];
      }

      c5_y = NULL;
      sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 7),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c5_y);
      c5_errorIfDataNotWrittenToFcn(chartInstance, 4U, 9U);
      (*c5_bWinT)++;
      c5_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(*c5_bWinT, 9U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_uc_debug_family_names,
        c5_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_out, 2U, c5_f_sf_marshallOut,
        c5_e_sf_marshallIn);
      c5_f_out = CV_EML_IF(10, 0, 0, c5_get_diff(chartInstance, 0) == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c5_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_stateCompare = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
        chartInstance->c5_isStable = false;
        chartInstance->c5_is_stateGame = c5_IN_stateUserWin;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_stateUserWin = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_wb_debug_family_names,
          c5_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_k_nargin, 0U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_k_nargout, 1U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        *c5_win = 1.0;
        c5_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
        for (c5_i5 = 0; c5_i5 < 7; c5_i5++) {
          c5_b_u[c5_i5] = c5_cv1[c5_i5];
        }

        c5_b_y = NULL;
        sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1,
          7), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c5_b_y);
        c5_errorIfDataNotWrittenToFcn(chartInstance, 5U, 10U);
        (*c5_uWinT)++;
        c5_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_DATA_RANGE_CHECK(*c5_uWinT, 10U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     chartInstance->c5_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_wc_debug_family_names,
          c5_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_l_nargin, 0U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_l_nargout, 1U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_out, 2U, c5_f_sf_marshallOut,
          c5_e_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(12, 0, 0, c5_get_diff(chartInstance, 0) != 1.0)) {
          if (CV_EML_COND(12, 0, 1, c5_get_diff(chartInstance, 0) != 2.0)) {
            CV_EML_MCDC(12, 0, 0, true);
            CV_EML_IF(12, 0, 0, true);
            c5_g_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(12, 0, 0, false);
          CV_EML_IF(12, 0, 0, false);
          c5_g_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c5_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_stateCompare = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
          chartInstance->c5_isStable = false;
          chartInstance->c5_is_stateGame = c5_IN_stateNoWin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_stateNoWin = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_yb_debug_family_names,
            c5_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_m_nargin, 0U,
            c5_c_sf_marshallOut, c5_c_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_m_nargout, 1U,
            c5_c_sf_marshallOut, c5_c_sf_marshallIn);
          for (c5_i6 = 0; c5_i6 < 7; c5_i6++) {
            c5_c_u[c5_i6] = c5_cv2[c5_i6];
          }

          c5_c_y = NULL;
          sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1,
            7), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c5_c_y);
          *c5_win = 0.0;
          c5_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                       chartInstance->c5_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateGo:
    CV_STATE_EVAL(9, 0, 7);
    c5_stateGo(chartInstance);
    break;

   case c5_IN_stateInit:
    CV_STATE_EVAL(9, 0, 8);
    c5_stateInit(chartInstance);
    break;

   case c5_IN_stateNoWin:
    CV_STATE_EVAL(9, 0, 9);
    c5_stateNoWin(chartInstance);
    break;

   case c5_IN_statePoseReady:
    CV_STATE_EVAL(9, 0, 10);
    c5_statePoseReady(chartInstance);
    break;

   case c5_IN_stateReadUserHand:
    CV_STATE_EVAL(9, 0, 11);
    c5_stateReadUserHand(chartInstance);
    break;

   case c5_IN_stateReady:
    CV_STATE_EVAL(9, 0, 12);
    c5_stateReady(chartInstance);
    break;

   case c5_IN_stateShowHands:
    CV_STATE_EVAL(9, 0, 13);
    c5_stateShowHands(chartInstance);
    break;

   case c5_IN_stateShowResult:
    CV_STATE_EVAL(9, 0, 14);
    c5_stateShowResult(chartInstance);
    break;

   case c5_IN_stateSt1:
    CV_STATE_EVAL(9, 0, 15);
    c5_stateSt1(chartInstance);
    break;

   case c5_IN_stateStart:
    CV_STATE_EVAL(9, 0, 16);
    c5_stateStart(chartInstance);
    break;

   case c5_IN_stateUserWin:
    CV_STATE_EVAL(9, 0, 17);
    c5_stateUserWin(chartInstance);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    chartInstance->c5_is_stateGame = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c5_sfEvent);
}

static void c5_stateSt1(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateSt1 = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGame = c5_IN_stateStart;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateStart = 1U;
  c5_enter_atomic_stateStart(chartInstance);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c5_sfEvent);
}

static void c5_enter_atomic_stateStart(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML[1000];
  real_T c5_P;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  real_T c5_dv2[5000];
  int32_T c5_i16;
  real_T c5_dv3[1000];
  real_T c5_dv4[5000];
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_mb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_randPoseChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 37);
  c5_set_randAvertGazeChance(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 36);
  c5_set_GAZE_GUI(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  c5_set_GAZE_SOFTEYE(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  c5_set_GAZE_USER_HAND(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 10);
  c5_set_GAZE_WIN(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c5_set_P(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c5_initialPoseTablec5_Expriment_Gaze(chartInstance, 4.0, &c5_P, c5_BML);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i7 = 0; c5_i7 < 1000; c5_i7++) {
    c5_set_BML(chartInstance, c5_i7, c5_BML[c5_i7]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  c5_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 23);
  c5_set_avertH(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 24);
  c5_encStr2Arr(chartInstance, c5_BML);
  for (c5_i8 = 0; c5_i8 < 1000; c5_i8++) {
    c5_set_n(chartInstance, c5_i8, c5_BML[c5_i8]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 32);
  for (c5_i9 = 0; c5_i9 < 1000; c5_i9++) {
    chartInstance->c5_newBmlsH[c5_i9] = c5_get_n(chartInstance, c5_i9);
  }

  for (c5_i10 = 0; c5_i10 < 1000; c5_i10++) {
    chartInstance->c5_newBmlsH[c5_i10 + 1000] = c5_get_n(chartInstance, c5_i10);
  }

  for (c5_i11 = 0; c5_i11 < 1000; c5_i11++) {
    chartInstance->c5_newBmlsH[c5_i11 + 2000] = c5_get_n(chartInstance, c5_i11);
  }

  for (c5_i12 = 0; c5_i12 < 1000; c5_i12++) {
    chartInstance->c5_newBmlsH[c5_i12 + 3000] = c5_get_n(chartInstance, c5_i12);
  }

  for (c5_i13 = 0; c5_i13 < 1000; c5_i13++) {
    chartInstance->c5_newBmlsH[c5_i13 + 4000] = c5_get_n(chartInstance, c5_i13);
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i14 = 0; c5_i14 < 5000; c5_i14++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i14], 48U);
  }

  for (c5_i15 = 0; c5_i15 < 5000; c5_i15++) {
    c5_dv2[c5_i15] = c5_get_bmlsH(chartInstance, c5_i15);
  }

  for (c5_i16 = 0; c5_i16 < 1000; c5_i16++) {
    c5_dv3[c5_i16] = c5_get_BML2(chartInstance, c5_i16);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv2, c5_dv3, c5_dv4);
  for (c5_i17 = 0; c5_i17 < 5000; c5_i17++) {
    chartInstance->c5_newBmlsH[c5_i17] = c5_dv4[c5_i17];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i18 = 0; c5_i18 < 5000; c5_i18++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i18], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i19 = 0; c5_i19 < 5000; c5_i19++) {
    c5_set_bmlsH(chartInstance, c5_i19, chartInstance->c5_newBmlsH[c5_i19]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_stateStart(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_gc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
  if (c5_temp) {
    c5_temp = (chartInstance->c5_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c5_get_t(chartInstance, 0),
                32U, 39U));
  }

  c5_out = CV_EML_IF(39, 0, 0, c5_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateStart = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_saccadeFinish;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_saccadeFinish = 1U;
    c5_enter_atomic_saccadeFinish(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c5_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c5_sfEvent);
}

static void c5_enter_atomic_saccadeFinish(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML2[1000];
  real_T c5_P;
  int32_T c5_i20;
  int32_T c5_i21;
  real_T c5_dv5[5000];
  int32_T c5_i22;
  real_T c5_dv6[1000];
  real_T c5_dv7[5000];
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_nb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_initialPoseTablec5_Expriment_Gaze(chartInstance, 1.0, &c5_P, c5_BML2);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i20 = 0; c5_i20 < 1000; c5_i20++) {
    c5_set_BML2(chartInstance, c5_i20, c5_BML2[c5_i20]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c5_i21 = 0; c5_i21 < 5000; c5_i21++) {
    c5_dv5[c5_i21] = c5_get_bmlsH(chartInstance, c5_i21);
  }

  for (c5_i22 = 0; c5_i22 < 1000; c5_i22++) {
    c5_dv6[c5_i22] = c5_get_BML2(chartInstance, c5_i22);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv5, c5_dv6, c5_dv7);
  for (c5_i23 = 0; c5_i23 < 5000; c5_i23++) {
    chartInstance->c5_newBmlsH[c5_i23] = c5_dv7[c5_i23];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i24 = 0; c5_i24 < 5000; c5_i24++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i24], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i25 = 0; c5_i25 < 5000; c5_i25++) {
    c5_set_bmlsH(chartInstance, c5_i25, chartInstance->c5_newBmlsH[c5_i25]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_stateInit(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_kc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
  if (c5_temp) {
    c5_temp = (chartInstance->c5_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(2.0 * c5_get_t
      (chartInstance, 0)), 32U, 37U));
  }

  c5_out = CV_EML_IF(37, 0, 0, c5_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateInit = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_gazeCamera;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_gazeCamera = 1U;
    c5_enter_atomic_gazeCamera(chartInstance);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c5_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c5_sfEvent);
}

static void c5_enter_atomic_gazeCamera(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML2[1000];
  real_T c5_P;
  int32_T c5_i26;
  int32_T c5_i27;
  real_T c5_dv8[5000];
  int32_T c5_i28;
  real_T c5_dv9[1000];
  real_T c5_dv10[5000];
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_qb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_initialPoseTablec5_Expriment_Gaze(chartInstance, 2.0, &c5_P, c5_BML2);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i26 = 0; c5_i26 < 1000; c5_i26++) {
    c5_set_BML2(chartInstance, c5_i26, c5_BML2[c5_i26]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  c5_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 23);
  for (c5_i27 = 0; c5_i27 < 5000; c5_i27++) {
    c5_dv8[c5_i27] = c5_get_bmlsH(chartInstance, c5_i27);
  }

  for (c5_i28 = 0; c5_i28 < 1000; c5_i28++) {
    c5_dv9[c5_i28] = c5_get_BML2(chartInstance, c5_i28);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv8, c5_dv9, c5_dv10);
  for (c5_i29 = 0; c5_i29 < 5000; c5_i29++) {
    chartInstance->c5_newBmlsH[c5_i29] = c5_dv10[c5_i29];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i30 = 0; c5_i30 < 5000; c5_i30++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i30], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i31 = 0; c5_i31 < 5000; c5_i31++) {
    c5_set_bmlsH(chartInstance, c5_i31, chartInstance->c5_newBmlsH[c5_i31]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_enter_atomic_stateReady(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T *c5_round;
  real_T *c5_bradHand;
  real_T *c5_userHand;
  real_T *c5_win;
  c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_rb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_errorIfDataNotWrittenToFcn(chartInstance, 6U, 43U);
  (*c5_round)++;
  c5_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_round, 43U);
  *c5_bradHand = 3.0;
  c5_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_bradHand, 2U);
  *c5_userHand = 3.0;
  c5_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_userHand, 3U);
  *c5_win = 0.0;
  c5_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_win, 4U);
  c5_set_gazing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 31);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_stateReady(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 1.0;
  boolean_T c5_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_oc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_out = CV_EML_IF(4, 0, 0, c5_get_boredom(chartInstance, 0) <
                     c5_get_BOREDOM_THRESHOLD(chartInstance, 0) - 4.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_pc_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_set_boredom(chartInstance, 0, c5_get_boredom(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 28);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c5_tp_stateReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_statePoseReady;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_statePoseReady = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_nc_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_b_out = CV_EML_IF(0, 0, 0, c5_get_uHand(chartInstance, 0) == 3.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_stateReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateReady = 1U;
      c5_enter_atomic_stateReady(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateReady = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_stateGame = c5_IN_statePoseReady;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i1 = 0U;
      chartInstance->c5_tp_statePoseReady = 1U;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c5_sfEvent);
}

static void c5_statePoseReady(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 0.0;
  real_T *c5_gameState;
  real_T (*c5_randArray)[25];
  c5_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 1);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_qc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
  if (c5_temp) {
    c5_temp = (chartInstance->c5_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c5_get_t(chartInstance, 0),
                32U, 5U));
  }

  c5_out = CV_EML_IF(5, 0, 0, c5_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_rc_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_set_bHand(chartInstance, 0, (*c5_randArray)[14]);
    ssUpdateDataStoreLog(chartInstance->S, 25);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c5_tp_statePoseReady = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_stateGo;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_stateGo = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_sb_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    *c5_gameState = c5_get_STATE_GO(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c5_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c5_sfEvent);
}

static void c5_stateGo(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T *c5_inputUser;
  real_T *c5_gameState;
  c5_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_sc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
  if (c5_temp) {
    c5_temp = (chartInstance->c5_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(2.0 * c5_get_t
      (chartInstance, 0)), 32U, 6U));
  }

  c5_out = CV_EML_IF(6, 0, 0, c5_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateGo = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_tb_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_set_uHand(chartInstance, 0, *c5_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 42);
    c5_set_gazing(chartInstance, 0, c5_get_GAZE_USER_HAND(chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 31);
    *c5_gameState = c5_get_STATE_HAND(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c5_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c5_sfEvent);
}

static void c5_stateReadUserHand(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  uint32_T c5_b_debug_family_var_map[2];
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 0.0;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 0.0;
  real_T *c5_bradHand;
  real_T *c5_userHand;
  real_T *c5_inputUser;
  real_T *c5_gameState;
  c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_tc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_out = CV_EML_IF(7, 0, 0, c5_get_uHand(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_stateReadUserHand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateReadUserHand = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_tb_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    c5_set_uHand(chartInstance, 0, *c5_inputUser);
    ssUpdateDataStoreLog(chartInstance->S, 42);
    c5_set_gazing(chartInstance, 0, c5_get_GAZE_USER_HAND(chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 31);
    *c5_gameState = c5_get_STATE_HAND(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateReadUserHand = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_stateShowHands;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateShowHands = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ub_debug_family_names,
      c5_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    *c5_bradHand = c5_get_bHand(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c5_bradHand, 2U);
    *c5_userHand = c5_get_uHand(chartInstance, 0);
    c5_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c5_userHand, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c5_sfEvent);
}

static void c5_stateShowHands(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T *c5_gameState;
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateShowHands = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGame = c5_IN_stateCompare;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateCompare = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_vb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_temp(chartInstance, 0, c5_get_uHand(chartInstance, 0) - c5_get_bHand
              (chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 41);
  c5_hoistedGlobal = c5_get_temp(chartInstance, 0);
  c5_b_hoistedGlobal = c5_get_temp(chartInstance, 0);
  c5_A = c5_b_hoistedGlobal;
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_y = c5_c_x / 3.0;
  c5_d_x = c5_y;
  c5_e_x = c5_d_x;
  c5_e_x = muDoubleScalarFloor(c5_e_x);
  c5_set_diff(chartInstance, 0, c5_hoistedGlobal - 3.0 * c5_e_x);
  ssUpdateDataStoreLog(chartInstance->S, 29);
  c5_set_gazing(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 31);
  *c5_gameState = c5_get_STATE_RESULT(chartInstance, 0);
  c5_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c5_sfEvent);
}

static void c5_stateUserWin(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T *c5_gameState;
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateUserWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGame = c5_IN_stateShowResult;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateShowResult = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ac_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_gazing(chartInstance, 0, c5_get_GAZE_GUI(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 31);
  *c5_gameState = c5_get_STATE_WAIT(chartInstance, 0);
  c5_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c5_sfEvent);
}

static void c5_stateNoWin(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T *c5_gameState;
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
  chartInstance->c5_tp_stateNoWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
  chartInstance->c5_isStable = false;
  chartInstance->c5_is_stateGame = c5_IN_stateShowResult;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
  chartInstance->c5_temporalCounter_i1 = 0U;
  chartInstance->c5_tp_stateShowResult = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ac_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_gazing(chartInstance, 0, c5_get_GAZE_GUI(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 31);
  *c5_gameState = c5_get_STATE_WAIT(chartInstance, 0);
  c5_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_gameState, 0U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c5_sfEvent);
}

static void c5_stateShowResult(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c5_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_lc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
  if (c5_temp) {
    c5_temp = (chartInstance->c5_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(4.0 * c5_get_t
      (chartInstance, 0)), 32U, 2U));
  }

  c5_out = CV_EML_IF(2, 0, 0, c5_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c5_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c5_sfEvent);
    chartInstance->c5_tp_stateShowResult = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
    chartInstance->c5_isStable = false;
    chartInstance->c5_is_stateGame = c5_IN_checkGameOver;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c5_sfEvent);
    chartInstance->c5_temporalCounter_i1 = 0U;
    chartInstance->c5_tp_checkGameOver = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c5_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c5_sfEvent);
}

static void c5_statePlayHand(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[3];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_out;
  boolean_T c5_temp;
  real_T c5_b_nargin = 0.0;
  real_T c5_b_nargout = 1.0;
  boolean_T c5_b_out;
  boolean_T c5_b_temp;
  real_T c5_c_nargin = 0.0;
  real_T c5_c_nargout = 1.0;
  boolean_T c5_c_out;
  boolean_T c5_c_temp;
  real_T c5_d_nargin = 0.0;
  real_T c5_d_nargout = 1.0;
  boolean_T c5_d_out;
  real_T c5_e_nargin = 0.0;
  real_T c5_e_nargout = 1.0;
  boolean_T c5_e_out;
  real_T c5_f_nargin = 0.0;
  real_T c5_f_nargout = 1.0;
  boolean_T c5_f_out;
  real_T c5_g_nargin = 0.0;
  real_T c5_g_nargout = 1.0;
  boolean_T c5_g_out;
  real_T *c5_gameState;
  c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c5_sfEvent);
  switch (chartInstance->c5_is_statePlayHand) {
   case c5_IN_statePosePaper:
    CV_STATE_EVAL(32, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_dd_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_temp = (chartInstance->c5_sfEvent == c5_event_secs);
    if (c5_temp) {
      c5_temp = (chartInstance->c5_temporalCounter_i2 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(2.0 * c5_get_t
        (chartInstance, 0)), 32U, 26U));
    }

    c5_out = CV_EML_IF(26, 0, 0, c5_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_statePosePaper = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_statePlayHand = c5_IN_stateRandomeHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomeHand = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_statePoseRock:
    CV_STATE_EVAL(32, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_cd_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_b_temp = (chartInstance->c5_sfEvent == c5_event_secs);
    if (c5_b_temp) {
      c5_b_temp = (chartInstance->c5_temporalCounter_i2 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(2.0 * c5_get_t
        (chartInstance, 0)), 32U, 25U));
    }

    c5_b_out = CV_EML_IF(25, 0, 0, c5_b_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_statePoseRock = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_statePlayHand = c5_IN_stateRandomeHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomeHand = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_statePoseScissors:
    CV_STATE_EVAL(32, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_ed_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_c_temp = (chartInstance->c5_sfEvent == c5_event_secs);
    if (c5_c_temp) {
      c5_c_temp = (chartInstance->c5_temporalCounter_i2 >=
                   _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)(2.0 * c5_get_t
        (chartInstance, 0)), 32U, 27U));
    }

    c5_c_out = CV_EML_IF(27, 0, 0, c5_c_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c5_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_statePoseScissors = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_statePlayHand = c5_IN_stateRandomeHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomeHand = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_stateRandomeHand:
    CV_STATE_EVAL(32, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_xc_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    c5_d_out = CV_EML_IF(19, 0, 0, *c5_gameState == c5_get_STATE_GO
                         (chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_stateRandomeHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_statePlayHand = c5_IN_wait;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_wait = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U,
                   chartInstance->c5_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, chartInstance->c5_sfEvent);
    break;

   case c5_IN_wait:
    CV_STATE_EVAL(32, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c5_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c5_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_bd_debug_family_names,
      c5_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargin, 0U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargout, 1U, c5_c_sf_marshallOut,
      c5_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_out, 2U, c5_f_sf_marshallOut,
      c5_e_sf_marshallIn);
    c5_e_out = CV_EML_IF(23, 0, 0, c5_get_bHand(chartInstance, 0) == 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c5_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c5_sfEvent);
      chartInstance->c5_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
      chartInstance->c5_isStable = false;
      chartInstance->c5_is_statePlayHand = c5_IN_statePosePaper;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
      chartInstance->c5_temporalCounter_i2 = 0U;
      chartInstance->c5_tp_statePosePaper = 1U;
      c5_enter_atomic_statePosePaper(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                   chartInstance->c5_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_ad_debug_family_names,
        c5_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargin, 0U, c5_c_sf_marshallOut,
        c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargout, 1U,
        c5_c_sf_marshallOut, c5_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_out, 2U, c5_f_sf_marshallOut,
        c5_e_sf_marshallIn);
      c5_f_out = CV_EML_IF(21, 0, 0, c5_get_bHand(chartInstance, 0) == 2.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c5_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c5_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c5_sfEvent);
        chartInstance->c5_tp_wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
        chartInstance->c5_isStable = false;
        chartInstance->c5_is_statePlayHand = c5_IN_statePoseRock;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, chartInstance->c5_sfEvent);
        chartInstance->c5_temporalCounter_i2 = 0U;
        chartInstance->c5_tp_statePoseRock = 1U;
        c5_enter_atomic_statePoseRock(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                     chartInstance->c5_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c5_yc_debug_family_names,
          c5_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_nargin, 0U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_nargout, 1U,
          c5_c_sf_marshallOut, c5_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_out, 2U, c5_f_sf_marshallOut,
          c5_e_sf_marshallIn);
        c5_g_out = CV_EML_IF(20, 0, 0, c5_get_bHand(chartInstance, 0) == 0.0);
        _SFD_SYMBOL_SCOPE_POP();
        if (c5_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c5_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c5_sfEvent);
          chartInstance->c5_tp_wait = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, chartInstance->c5_sfEvent);
          chartInstance->c5_isStable = false;
          chartInstance->c5_is_statePlayHand = c5_IN_statePoseScissors;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, chartInstance->c5_sfEvent);
          chartInstance->c5_temporalCounter_i2 = 0U;
          chartInstance->c5_tp_statePoseScissors = 1U;
          c5_enter_atomic_statePoseScissors(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U,
                       chartInstance->c5_sfEvent);
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, chartInstance->c5_sfEvent);
    break;

   default:
    CV_STATE_EVAL(32, 0, 0);
    chartInstance->c5_is_statePlayHand = c5_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, chartInstance->c5_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c5_sfEvent);
}

static void c5_enter_atomic_statePoseRock(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML2[1000];
  real_T c5_P;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_dv11[5000];
  int32_T c5_i34;
  real_T c5_dv12[1000];
  real_T c5_dv13[5000];
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_bc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_r(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 35);
  c5_rockPoseTablec5_Expriment_Gaze(chartInstance, c5_get_r(chartInstance, 0),
    &c5_P, c5_BML2);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i32 = 0; c5_i32 < 1000; c5_i32++) {
    c5_set_BML2(chartInstance, c5_i32, c5_BML2[c5_i32]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c5_i33 = 0; c5_i33 < 5000; c5_i33++) {
    c5_dv11[c5_i33] = c5_get_bmlsH(chartInstance, c5_i33);
  }

  for (c5_i34 = 0; c5_i34 < 1000; c5_i34++) {
    c5_dv12[c5_i34] = c5_get_BML2(chartInstance, c5_i34);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv11, c5_dv12, c5_dv13);
  for (c5_i35 = 0; c5_i35 < 5000; c5_i35++) {
    chartInstance->c5_newBmlsH[c5_i35] = c5_dv13[c5_i35];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i36 = 0; c5_i36 < 5000; c5_i36++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i36], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i37 = 0; c5_i37 < 5000; c5_i37++) {
    c5_set_bmlsH(chartInstance, c5_i37, chartInstance->c5_newBmlsH[c5_i37]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_enter_atomic_statePosePaper(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML2[1000];
  real_T c5_P;
  int32_T c5_i38;
  int32_T c5_i39;
  real_T c5_dv14[5000];
  int32_T c5_i40;
  real_T c5_dv15[1000];
  real_T c5_dv16[5000];
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_cc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_pa(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 33);
  c5_paperPoseBradTablec5_Expriment_Gaze(chartInstance, c5_get_pa(chartInstance,
    0), &c5_P, c5_BML2);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i38 = 0; c5_i38 < 1000; c5_i38++) {
    c5_set_BML2(chartInstance, c5_i38, c5_BML2[c5_i38]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c5_i39 = 0; c5_i39 < 5000; c5_i39++) {
    c5_dv14[c5_i39] = c5_get_bmlsH(chartInstance, c5_i39);
  }

  for (c5_i40 = 0; c5_i40 < 1000; c5_i40++) {
    c5_dv15[c5_i40] = c5_get_BML2(chartInstance, c5_i40);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv14, c5_dv15, c5_dv16);
  for (c5_i41 = 0; c5_i41 < 5000; c5_i41++) {
    chartInstance->c5_newBmlsH[c5_i41] = c5_dv16[c5_i41];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i42 = 0; c5_i42 < 5000; c5_i42++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i42], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i43 = 0; c5_i43 < 5000; c5_i43++) {
    c5_set_bmlsH(chartInstance, c5_i43, chartInstance->c5_newBmlsH[c5_i43]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_enter_atomic_statePoseScissors(SFc5_Expriment_GazeInstanceStruct *
  chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML2[1000];
  real_T c5_P;
  int32_T c5_i44;
  int32_T c5_i45;
  real_T c5_dv17[5000];
  int32_T c5_i46;
  real_T c5_dv18[1000];
  real_T c5_dv19[5000];
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_dc_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_set_s(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 39);
  c5_scissorsPoseBradTablec5_Expriment_Gaze(chartInstance, c5_get_s
    (chartInstance, 0), &c5_P, c5_BML2);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i44 = 0; c5_i44 < 1000; c5_i44++) {
    c5_set_BML2(chartInstance, c5_i44, c5_BML2[c5_i44]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  for (c5_i45 = 0; c5_i45 < 5000; c5_i45++) {
    c5_dv17[c5_i45] = c5_get_bmlsH(chartInstance, c5_i45);
  }

  for (c5_i46 = 0; c5_i46 < 1000; c5_i46++) {
    c5_dv18[c5_i46] = c5_get_BML2(chartInstance, c5_i46);
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_dv17, c5_dv18, c5_dv19);
  for (c5_i47 = 0; c5_i47 < 5000; c5_i47++) {
    chartInstance->c5_newBmlsH[c5_i47] = c5_dv19[c5_i47];
  }

  c5_updateDataWrittenToVector(chartInstance, 7U);
  for (c5_i48 = 0; c5_i48 < 5000; c5_i48++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsH[c5_i48], 48U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 7U, 48U);
  for (c5_i49 = 0; c5_i49 < 5000; c5_i49++) {
    c5_set_bmlsH(chartInstance, c5_i49, chartInstance->c5_newBmlsH[c5_i49]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 26);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_enter_atomic_stateAgentNotWin(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  uint32_T c5_debug_family_var_map[2];
  real_T c5_nargin = 0.0;
  real_T c5_nargout = 0.0;
  real_T c5_BML[1000];
  real_T c5_P;
  int32_T c5_i50;
  int32_T c5_i51;
  real_T c5_dv20[5000];
  int32_T c5_i52;
  real_T c5_dv21[1000];
  real_T c5_dv22[5000];
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  real_T (*c5_randArray)[25];
  c5_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c5_ec_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  c5_idlePoseBradTablec5_Expriment_Gaze(chartInstance, (*c5_randArray)[15],
    &c5_P, c5_BML);
  c5_set_P(chartInstance, 0, c5_P);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  for (c5_i50 = 0; c5_i50 < 1000; c5_i50++) {
    c5_set_BML(chartInstance, c5_i50, c5_BML[c5_i50]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  for (c5_i51 = 0; c5_i51 < 5000; c5_i51++) {
    c5_dv20[c5_i51] = c5_get_bmlsL(chartInstance, c5_i51);
  }

  for (c5_i52 = 0; c5_i52 < 1000; c5_i52++) {
    c5_dv21[c5_i52] = c5_get_BML(chartInstance, c5_i52);
  }

  c5_insertQueueLowc5_Expriment_Gaze(chartInstance, c5_dv20, c5_dv21, c5_dv22);
  for (c5_i53 = 0; c5_i53 < 5000; c5_i53++) {
    chartInstance->c5_newBmlsL[c5_i53] = c5_dv22[c5_i53];
  }

  c5_updateDataWrittenToVector(chartInstance, 8U);
  for (c5_i54 = 0; c5_i54 < 5000; c5_i54++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_newBmlsL[c5_i54], 51U);
  }

  c5_errorIfDataNotWrittenToFcn(chartInstance, 8U, 51U);
  for (c5_i55 = 0; c5_i55 < 5000; c5_i55++) {
    c5_set_bmlsL(chartInstance, c5_i55, chartInstance->c5_newBmlsL[c5_i55]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr;
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i56;
  int32_T c5_i57;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_arr, 1U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_mystr, 5U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  c5_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i56 = 0; c5_i56 < 1000; c5_i56++) {
    c5_tt[c5_i56] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_tt[0] = c5_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i57 = 0; c5_i57 < 1000; c5_i57++) {
    c5_myarr256[c5_i57] = c5_tt[c5_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_b_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[144];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[144];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i58;
  static char_T c5_cv3[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '2', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\"', '1',
    '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e',
    'l', 'a', 'x', '=', '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4',
    '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c5_i59;
  static real_T c5_dv23[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 50.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0,
    34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_e_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i58 = 0; c5_i58 < 144; c5_i58++) {
    c5_mystr[c5_i58] = c5_cv3[c5_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i59 = 0; c5_i59 < 144; c5_i59++) {
    c5_arr[c5_i59] = c5_dv23[c5_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i60 = 0; c5_i60 < 1000; c5_i60++) {
    c5_tt[c5_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i61 = 0; c5_i61 < 144; c5_i61++) {
    c5_tt[c5_i61] = c5_arr[c5_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i62 = 0; c5_i62 < 1000; c5_i62++) {
    c5_myarr256[c5_i62] = c5_tt[c5_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_c_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[144];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[144];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i63;
  static char_T c5_cv4[144] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'B', 'e', 'a', 't', 'F', 'i',
    's', 't', 'M', 'i', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 't', 'a', 'r',
    't', '=', '\"', '0', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\"', '1',
    '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e',
    'l', 'a', 'x', '=', '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4',
    '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c5_i64;
  static real_T c5_dv24[144] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 66.0, 101.0,
    97.0, 116.0, 70.0, 105.0, 115.0, 116.0, 77.0, 105.0, 100.0, 76.0, 102.0,
    48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0,
    34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 52.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_f_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i63 = 0; c5_i63 < 144; c5_i63++) {
    c5_mystr[c5_i63] = c5_cv4[c5_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i64 = 0; c5_i64 < 144; c5_i64++) {
    c5_arr[c5_i64] = c5_dv24[c5_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 144.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i65 = 0; c5_i65 < 1000; c5_i65++) {
    c5_tt[c5_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i66 = 0; c5_i66 < 144; c5_i66++) {
    c5_tt[c5_i66] = c5_arr[c5_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i67 = 0; c5_i67 < 1000; c5_i67++) {
    c5_myarr256[c5_i67] = c5_tt[c5_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_d_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i68;
  static char_T c5_cv5[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't',
    'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_',
    'R', 'P', 'S', '_', 'P', 'r', 'e', 'p', '.', 's', 'k', 'm', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i69;
  static real_T c5_dv25[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 82.0, 80.0, 83.0, 95.0, 80.0, 114.0, 101.0, 112.0,
    46.0, 115.0, 107.0, 109.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_g_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i68 = 0; c5_i68 < 97; c5_i68++) {
    c5_mystr[c5_i68] = c5_cv5[c5_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i69 = 0; c5_i69 < 97; c5_i69++) {
    c5_arr[c5_i69] = c5_dv25[c5_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i70 = 0; c5_i70 < 1000; c5_i70++) {
    c5_tt[c5_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i71 = 0; c5_i71 < 97; c5_i71++) {
    c5_tt[c5_i71] = c5_arr[c5_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i72 = 0; c5_i72 < 1000; c5_i72++) {
    c5_myarr256[c5_i72] = c5_tt[c5_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_e_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[127];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[127];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i73;
  static char_T c5_cv6[127] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'O', 'f', 'f', 'e', 'r', 'L',
    'f', '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    's', 't', 'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a',
    'x', '=', '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i74;
  static real_T c5_dv26[127] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 79.0, 102.0,
    102.0, 101.0, 114.0, 76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 51.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 52.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_i_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_l_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i73 = 0; c5_i73 < 127; c5_i73++) {
    c5_mystr[c5_i73] = c5_cv6[c5_i73];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i74 = 0; c5_i74 < 127; c5_i74++) {
    c5_arr[c5_i74] = c5_dv26[c5_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 127.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i75 = 0; c5_i75 < 1000; c5_i75++) {
    c5_tt[c5_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i76 = 0; c5_i76 < 127; c5_i76++) {
    c5_tt[c5_i76] = c5_arr[c5_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i77 = 0; c5_i77 < 1000; c5_i77++) {
    c5_myarr256[c5_i77] = c5_tt[c5_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_f_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[125];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[125];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i78;
  static char_T c5_cv7[125] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=',
    '\"', '3', '\"', ' ', 'e', 'n', 'd', '=', '\"', '4', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i79;
  static real_T c5_dv27[125] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0,
    61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0,
    34.0, 50.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 51.0,
    34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 52.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_j_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_n_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i78 = 0; c5_i78 < 125; c5_i78++) {
    c5_mystr[c5_i78] = c5_cv7[c5_i78];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i79 = 0; c5_i79 < 125; c5_i79++) {
    c5_arr[c5_i79] = c5_dv27[c5_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 125.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i80 = 0; c5_i80 < 1000; c5_i80++) {
    c5_tt[c5_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i81 = 0; c5_i81 < 125; c5_i81++) {
    c5_tt[c5_i81] = c5_arr[c5_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i82 = 0; c5_i82 < 1000; c5_i82++) {
    c5_myarr256[c5_i82] = c5_tt[c5_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_g_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[99];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[99];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i83;
  static char_T c5_cv8[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't',
    'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_',
    'U', 's', 'e', '_', 'P', 'a', 'p', 'e', 'r', '.', 's', 'k', 'm', '\"', ' ',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i84;
  static real_T c5_dv28[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 85.0, 115.0, 101.0, 95.0, 80.0, 97.0, 112.0,
    101.0, 114.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_k_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i83 = 0; c5_i83 < 99; c5_i83++) {
    c5_mystr[c5_i83] = c5_cv8[c5_i83];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i84 = 0; c5_i84 < 99; c5_i84++) {
    c5_arr[c5_i84] = c5_dv28[c5_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 99.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i85 = 0; c5_i85 < 1000; c5_i85++) {
    c5_tt[c5_i85] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i86 = 0; c5_i86 < 99; c5_i86++) {
    c5_tt[c5_i86] = c5_arr[c5_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i87 = 0; c5_i87 < 1000; c5_i87++) {
    c5_myarr256[c5_i87] = c5_tt[c5_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_h_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[86];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[86];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i88;
  static char_T c5_cv9[86] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'Y', 'o', 'u', 'L', 'f', '0',
    '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c5_i89;
  static real_T c5_dv29[86] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 89.0, 111.0,
    117.0, 76.0, 102.0, 48.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_m_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_q_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i88 = 0; c5_i88 < 86; c5_i88++) {
    c5_mystr[c5_i88] = c5_cv9[c5_i88];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i89 = 0; c5_i89 < 86; c5_i89++) {
    c5_arr[c5_i89] = c5_dv29[c5_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 86.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i90 = 0; c5_i90 < 1000; c5_i90++) {
    c5_tt[c5_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i91 = 0; c5_i91 < 86; c5_i91++) {
    c5_tt[c5_i91] = c5_arr[c5_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i92 = 0; c5_i92 < 1000; c5_i92++) {
    c5_myarr256[c5_i92] = c5_tt[c5_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_i_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[102];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[102];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i93;
  static char_T c5_cv10[102] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'U', 's', 'e', '_', 'S', 'c', 'i', 's', 's', 'o', 'r', 's', '.', 's',
    'k', 'm', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c5_i94;
  static real_T c5_dv30[102] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 85.0, 115.0, 101.0, 95.0, 83.0, 99.0, 105.0,
    115.0, 115.0, 111.0, 114.0, 115.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_n_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_t_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_s_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i93 = 0; c5_i93 < 102; c5_i93++) {
    c5_mystr[c5_i93] = c5_cv10[c5_i93];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i94 = 0; c5_i94 < 102; c5_i94++) {
    c5_arr[c5_i94] = c5_dv30[c5_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 102.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i95 = 0; c5_i95 < 1000; c5_i95++) {
    c5_tt[c5_i95] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i96 = 0; c5_i96 < 102; c5_i96++) {
    c5_tt[c5_i96] = c5_arr[c5_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i97 = 0; c5_i97 < 1000; c5_i97++) {
    c5_myarr256[c5_i97] = c5_tt[c5_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_j_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[160];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[160];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i98;
  static char_T c5_cv11[160] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S',
    'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o',
    'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p', 'i',
    'n', 'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r',
    'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(',
    '1', ',', '0', ',', '0', ',', '0', '.', '5', ')', ')', ';', 'b', 'r', 'a',
    'd', '.', 'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')',
    '.', 'g', 'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e',
    '(', '\"', 'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')', '.', 's', 'e', 't',
    'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r',
    'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',', '0', '.', '5', ')',
    ')' };

  int32_T c5_i99;
  static real_T c5_dv31[160] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0, 110.0,
    107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 53.0, 41.0, 41.0, 59.0, 98.0, 114.0, 97.0, 100.0, 46.0,
    103.0, 101.0, 116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0,
    40.0, 41.0, 46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0,
    66.0, 121.0, 78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 114.0, 105.0,
    110.0, 103.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 46.0, 53.0, 41.0, 41.0 };

  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_p_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_v_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_u_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i98 = 0; c5_i98 < 160; c5_i98++) {
    c5_mystr[c5_i98] = c5_cv11[c5_i98];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i99 = 0; c5_i99 < 160; c5_i99++) {
    c5_arr[c5_i99] = c5_dv31[c5_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 160.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i100 = 0; c5_i100 < 1000; c5_i100++) {
    c5_tt[c5_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i101 = 0; c5_i101 < 160; c5_i101++) {
    c5_tt[c5_i101] = c5_arr[c5_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i102 = 0; c5_i102 < 1000; c5_i102++) {
    c5_myarr256[c5_i102] = c5_tt[c5_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_k_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[156];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[156];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i103;
  static char_T c5_cv12[156] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S',
    'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o',
    'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 'p', 'i',
    'n', 'k', 'y', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r',
    'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(',
    '1', ',', '0', ',', '0', ',', '0', ')', ')', ';', 'b', 'r', 'a', 'd', '.',
    'g', 'e', 't', 'S', 'k', 'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g',
    'e', 't', 'J', 'o', 'i', 'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"',
    'l', '_', 'r', 'i', 'n', 'g', '1', '\"', ')', '.', 's', 'e', 't', 'P', 'o',
    's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', '(', 'S', 'r', 'Q', 'u',
    'a', 't', '(', '1', ',', '0', ',', '0', ',', '0', ')', ')' };

  int32_T c5_i104;
  static real_T c5_dv32[156] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 112.0, 105.0, 110.0,
    107.0, 121.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0,
    115.0, 116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0,
    83.0, 114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0,
    44.0, 48.0, 41.0, 41.0, 59.0, 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 114.0, 105.0, 110.0,
    103.0, 49.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0 };

  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_q_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_x_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_w_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i103 = 0; c5_i103 < 156; c5_i103++) {
    c5_mystr[c5_i103] = c5_cv12[c5_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i104 = 0; c5_i104 < 156; c5_i104++) {
    c5_arr[c5_i104] = c5_dv32[c5_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 156.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i105 = 0; c5_i105 < 1000; c5_i105++) {
    c5_tt[c5_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i106 = 0; c5_i106 < 156; c5_i106++) {
    c5_tt[c5_i106] = c5_arr[c5_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i107 = 0; c5_i107 < 1000; c5_i107++) {
    c5_myarr256[c5_i107] = c5_tt[c5_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_l_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[91];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[91];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i108;
  static char_T c5_cv13[91] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', '.', '0', '5', ')', ')' };

  int32_T c5_i109;
  static real_T c5_dv33[91] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 46.0, 48.0, 53.0, 41.0, 41.0 };

  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_r_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i108 = 0; c5_i108 < 91; c5_i108++) {
    c5_mystr[c5_i108] = c5_cv13[c5_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i109 = 0; c5_i109 < 91; c5_i109++) {
    c5_arr[c5_i109] = c5_dv33[c5_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i110 = 0; c5_i110 < 1000; c5_i110++) {
    c5_tt[c5_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i111 = 0; c5_i111 < 91; c5_i111++) {
    c5_tt[c5_i111] = c5_arr[c5_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i112 = 0; c5_i112 < 1000; c5_i112++) {
    c5_myarr256[c5_i112] = c5_tt[c5_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_m_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[88];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[88];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i113;
  static char_T c5_cv14[88] = { 'b', 'r', 'a', 'd', '.', 'g', 'e', 't', 'S', 'k',
    'e', 'l', 'e', 't', 'o', 'n', '(', ')', '.', 'g', 'e', 't', 'J', 'o', 'i',
    'n', 't', 'B', 'y', 'N', 'a', 'm', 'e', '(', '\"', 'l', '_', 's', 't', 'e',
    'r', 'n', 'o', 'c', 'l', 'a', 'v', 'i', 'c', 'u', 'l', 'a', 'r', '\"', ')',
    '.', 's', 'e', 't', 'P', 'o', 's', 't', 'r', 'o', 't', 'a', 't', 'i', 'o',
    'n', '(', 'S', 'r', 'Q', 'u', 'a', 't', '(', '1', ',', '0', ',', '0', ',',
    '0', ')', ')' };

  int32_T c5_i114;
  static real_T c5_dv34[88] = { 98.0, 114.0, 97.0, 100.0, 46.0, 103.0, 101.0,
    116.0, 83.0, 107.0, 101.0, 108.0, 101.0, 116.0, 111.0, 110.0, 40.0, 41.0,
    46.0, 103.0, 101.0, 116.0, 74.0, 111.0, 105.0, 110.0, 116.0, 66.0, 121.0,
    78.0, 97.0, 109.0, 101.0, 40.0, 34.0, 108.0, 95.0, 115.0, 116.0, 101.0,
    114.0, 110.0, 111.0, 99.0, 108.0, 97.0, 118.0, 105.0, 99.0, 117.0, 108.0,
    97.0, 114.0, 34.0, 41.0, 46.0, 115.0, 101.0, 116.0, 80.0, 111.0, 115.0,
    116.0, 114.0, 111.0, 116.0, 97.0, 116.0, 105.0, 111.0, 110.0, 40.0, 83.0,
    114.0, 81.0, 117.0, 97.0, 116.0, 40.0, 49.0, 44.0, 48.0, 44.0, 48.0, 44.0,
    48.0, 41.0, 41.0 };

  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_s_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i113 = 0; c5_i113 < 88; c5_i113++) {
    c5_mystr[c5_i113] = c5_cv14[c5_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i114 = 0; c5_i114 < 88; c5_i114++) {
    c5_arr[c5_i114] = c5_dv34[c5_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i115 = 0; c5_i115 < 1000; c5_i115++) {
    c5_tt[c5_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i116 = 0; c5_i116 < 88; c5_i116++) {
    c5_tt[c5_i116] = c5_arr[c5_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i117 = 0; c5_i117 < 1000; c5_i117++) {
    c5_myarr256[c5_i117] = c5_tt[c5_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_n_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[91];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[91];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i118;
  static char_T c5_cv15[91] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't', 'r',
    'e', 't', 'c', 'h', '0', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i119;
  static real_T c5_dv35[91] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_u_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_ab_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_y_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i118 = 0; c5_i118 < 91; c5_i118++) {
    c5_mystr[c5_i118] = c5_cv15[c5_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i119 = 0; c5_i119 < 91; c5_i119++) {
    c5_arr[c5_i119] = c5_dv35[c5_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 91.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i120 = 0; c5_i120 < 1000; c5_i120++) {
    c5_tt[c5_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i121 = 0; c5_i121 < 91; c5_i121++) {
    c5_tt[c5_i121] = c5_arr[c5_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i122 = 0; c5_i122 < 1000; c5_i122++) {
    c5_myarr256[c5_i122] = c5_tt[c5_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_o_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[87];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[87];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i123;
  static char_T c5_cv16[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '3', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c5_i124;
  static real_T c5_dv36[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_v_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i123 = 0; c5_i123 < 87; c5_i123++) {
    c5_mystr[c5_i123] = c5_cv16[c5_i123];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i124 = 0; c5_i124 < 87; c5_i124++) {
    c5_arr[c5_i124] = c5_dv36[c5_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i125 = 0; c5_i125 < 1000; c5_i125++) {
    c5_tt[c5_i125] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i126 = 0; c5_i126 < 87; c5_i126++) {
    c5_tt[c5_i126] = c5_arr[c5_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i127 = 0; c5_i127 < 1000; c5_i127++) {
    c5_myarr256[c5_i127] = c5_tt[c5_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_p_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i128;
  static char_T c5_cv17[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i129;
  static real_T c5_dv37[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i130;
  int32_T c5_i131;
  int32_T c5_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_w_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i128 = 0; c5_i128 < 93; c5_i128++) {
    c5_mystr[c5_i128] = c5_cv17[c5_i128];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i129 = 0; c5_i129 < 93; c5_i129++) {
    c5_arr[c5_i129] = c5_dv37[c5_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i130 = 0; c5_i130 < 1000; c5_i130++) {
    c5_tt[c5_i130] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i131 = 0; c5_i131 < 93; c5_i131++) {
    c5_tt[c5_i131] = c5_arr[c5_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i132 = 0; c5_i132 < 1000; c5_i132++) {
    c5_myarr256[c5_i132] = c5_tt[c5_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_q_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[94];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[94];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i133;
  static char_T c5_cv18[94] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i134;
  static real_T c5_dv38[94] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i135;
  int32_T c5_i136;
  int32_T c5_i137;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_x_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i133 = 0; c5_i133 < 94; c5_i133++) {
    c5_mystr[c5_i133] = c5_cv18[c5_i133];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i134 = 0; c5_i134 < 94; c5_i134++) {
    c5_arr[c5_i134] = c5_dv38[c5_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 94.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i135 = 0; c5_i135 < 1000; c5_i135++) {
    c5_tt[c5_i135] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i136 = 0; c5_i136 < 94; c5_i136++) {
    c5_tt[c5_i136] = c5_arr[c5_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i137 = 0; c5_i137 < 1000; c5_i137++) {
    c5_myarr256[c5_i137] = c5_tt[c5_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_r_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[95];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[95];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i138;
  static char_T c5_cv19[95] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i139;
  static real_T c5_dv39[95] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i140;
  int32_T c5_i141;
  int32_T c5_i142;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_y_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i138 = 0; c5_i138 < 95; c5_i138++) {
    c5_mystr[c5_i138] = c5_cv19[c5_i138];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i139 = 0; c5_i139 < 95; c5_i139++) {
    c5_arr[c5_i139] = c5_dv39[c5_i139];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 95.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i140 = 0; c5_i140 < 1000; c5_i140++) {
    c5_tt[c5_i140] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i141 = 0; c5_i141 < 95; c5_i141++) {
    c5_tt[c5_i141] = c5_arr[c5_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i142 = 0; c5_i142 < 1000; c5_i142++) {
    c5_myarr256[c5_i142] = c5_tt[c5_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_s_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[88];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[88];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i143;
  static char_T c5_cv20[88] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c5_i144;
  static real_T c5_dv40[88] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i145;
  int32_T c5_i146;
  int32_T c5_i147;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_ab_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_cb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_bb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i143 = 0; c5_i143 < 88; c5_i143++) {
    c5_mystr[c5_i143] = c5_cv20[c5_i143];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i144 = 0; c5_i144 < 88; c5_i144++) {
    c5_arr[c5_i144] = c5_dv40[c5_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 88.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i145 = 0; c5_i145 < 1000; c5_i145++) {
    c5_tt[c5_i145] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i146 = 0; c5_i146 < 88; c5_i146++) {
    c5_tt[c5_i146] = c5_arr[c5_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i147 = 0; c5_i147 < 1000; c5_i147++) {
    c5_myarr256[c5_i147] = c5_tt[c5_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_t_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i148;
  static char_T c5_cv21[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i149;
  static real_T c5_dv41[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i150;
  int32_T c5_i151;
  int32_T c5_i152;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_bb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i148 = 0; c5_i148 < 93; c5_i148++) {
    c5_mystr[c5_i148] = c5_cv21[c5_i148];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i149 = 0; c5_i149 < 93; c5_i149++) {
    c5_arr[c5_i149] = c5_dv41[c5_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i150 = 0; c5_i150 < 1000; c5_i150++) {
    c5_tt[c5_i150] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i151 = 0; c5_i151 < 93; c5_i151++) {
    c5_tt[c5_i151] = c5_arr[c5_i151];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i152 = 0; c5_i152 < 1000; c5_i152++) {
    c5_myarr256[c5_i152] = c5_tt[c5_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_u_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[93];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[93];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i153;
  static char_T c5_cv22[93] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i154;
  static real_T c5_dv42[93] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i155;
  int32_T c5_i156;
  int32_T c5_i157;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_cb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_gb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_fb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i153 = 0; c5_i153 < 93; c5_i153++) {
    c5_mystr[c5_i153] = c5_cv22[c5_i153];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i154 = 0; c5_i154 < 93; c5_i154++) {
    c5_arr[c5_i154] = c5_dv42[c5_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 93.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i155 = 0; c5_i155 < 1000; c5_i155++) {
    c5_tt[c5_i155] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i156 = 0; c5_i156 < 93; c5_i156++) {
    c5_tt[c5_i156] = c5_arr[c5_i156];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i157 = 0; c5_i157 < 1000; c5_i157++) {
    c5_myarr256[c5_i157] = c5_tt[c5_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_v_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i158;
  static char_T c5_cv23[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i159;
  static real_T c5_dv43[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i160;
  int32_T c5_i161;
  int32_T c5_i162;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_db_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i158 = 0; c5_i158 < 97; c5_i158++) {
    c5_mystr[c5_i158] = c5_cv23[c5_i158];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i159 = 0; c5_i159 < 97; c5_i159++) {
    c5_arr[c5_i159] = c5_dv43[c5_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i160 = 0; c5_i160 < 1000; c5_i160++) {
    c5_tt[c5_i160] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i161 = 0; c5_i161 < 97; c5_i161++) {
    c5_tt[c5_i161] = c5_arr[c5_i161];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i162 = 0; c5_i162 < 1000; c5_i162++) {
    c5_myarr256[c5_i162] = c5_tt[c5_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_w_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i163;
  static char_T c5_cv24[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i164;
  static real_T c5_dv44[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i165;
  int32_T c5_i166;
  int32_T c5_i167;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_eb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i163 = 0; c5_i163 < 97; c5_i163++) {
    c5_mystr[c5_i163] = c5_cv24[c5_i163];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i164 = 0; c5_i164 < 97; c5_i164++) {
    c5_arr[c5_i164] = c5_dv44[c5_i164];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i165 = 0; c5_i165 < 1000; c5_i165++) {
    c5_tt[c5_i165] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i166 = 0; c5_i166 < 97; c5_i166++) {
    c5_tt[c5_i166] = c5_arr[c5_i166];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i167 = 0; c5_i167 < 1000; c5_i167++) {
    c5_myarr256[c5_i167] = c5_tt[c5_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_x_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[92];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[92];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i168;
  static char_T c5_cv25[92] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h', 'H',
    'a', 'n', 'd', 's', '0', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i169;
  static real_T c5_dv45[92] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c5_i170;
  int32_T c5_i171;
  int32_T c5_i172;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_fb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i168 = 0; c5_i168 < 92; c5_i168++) {
    c5_mystr[c5_i168] = c5_cv25[c5_i168];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i169 = 0; c5_i169 < 92; c5_i169++) {
    c5_arr[c5_i169] = c5_dv45[c5_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 92.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i170 = 0; c5_i170 < 1000; c5_i170++) {
    c5_tt[c5_i170] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i171 = 0; c5_i171 < 92; c5_i171++) {
    c5_tt[c5_i171] = c5_arr[c5_i171];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i172 = 0; c5_i172 < 1000; c5_i172++) {
    c5_myarr256[c5_i172] = c5_tt[c5_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_y_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[68];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[68];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i173;
  static char_T c5_cv26[68] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 's', 'a', 'c', 'c', 'a', 'd', 'e',
    ' ', 'f', 'i', 'n', 'i', 's', 'h', '=', '\"', 't', 'r', 'u', 'e', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i174;
  static real_T c5_dv46[68] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 115.0, 97.0, 99.0, 99.0, 97.0, 100.0, 101.0, 32.0, 102.0, 105.0,
    110.0, 105.0, 115.0, 104.0, 61.0, 34.0, 116.0, 114.0, 117.0, 101.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c5_i175;
  int32_T c5_i176;
  int32_T c5_i177;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_hb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i173 = 0; c5_i173 < 68; c5_i173++) {
    c5_mystr[c5_i173] = c5_cv26[c5_i173];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i174 = 0; c5_i174 < 68; c5_i174++) {
    c5_arr[c5_i174] = c5_dv46[c5_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 68.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i175 = 0; c5_i175 < 1000; c5_i175++) {
    c5_tt[c5_i175] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i176 = 0; c5_i176 < 68; c5_i176++) {
    c5_tt[c5_i176] = c5_arr[c5_i176];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i177 = 0; c5_i177 < 1000; c5_i177++) {
    c5_myarr256[c5_i177] = c5_tt[c5_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_ab_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[87];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[87];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i178;
  static char_T c5_cv27[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0',
    '.', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c5_i179;
  static real_T c5_dv47[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i180;
  int32_T c5_i181;
  int32_T c5_i182;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_ib_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i178 = 0; c5_i178 < 87; c5_i178++) {
    c5_mystr[c5_i178] = c5_cv27[c5_i178];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i179 = 0; c5_i179 < 87; c5_i179++) {
    c5_arr[c5_i179] = c5_dv47[c5_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i180 = 0; c5_i180 < 1000; c5_i180++) {
    c5_tt[c5_i180] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i181 = 0; c5_i181 < 87; c5_i181++) {
    c5_tt[c5_i181] = c5_arr[c5_i181];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i182 = 0; c5_i182 < 1000; c5_i182++) {
    c5_myarr256[c5_i182] = c5_tt[c5_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_bb_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[97];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[97];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i183;
  static char_T c5_cv28[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 't', 'y',
    'p', 'e', '=', '\"', 'F', 'A', 'C', 'S', '\"', ' ', 's', 'i', 'd', 'e', '=',
    '\"', 'B', 'O', 'T', 'H', '\"', ' ', 'a', 'u', '=', '\"', '4', '5', '\"',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '5', '\"', ' ', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i184;
  static real_T c5_dv48[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 70.0, 65.0, 67.0, 83.0, 34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0,
    34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 52.0,
    53.0, 34.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0,
    46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i185;
  int32_T c5_i186;
  int32_T c5_i187;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_jb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i183 = 0; c5_i183 < 97; c5_i183++) {
    c5_mystr[c5_i183] = c5_cv28[c5_i183];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i184 = 0; c5_i184 < 97; c5_i184++) {
    c5_arr[c5_i184] = c5_dv48[c5_i184];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i185 = 0; c5_i185 < 1000; c5_i185++) {
    c5_tt[c5_i185] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i186 = 0; c5_i186 < 97; c5_i186++) {
    c5_tt[c5_i186] = c5_arr[c5_i186];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i187 = 0; c5_i187 < 1000; c5_i187++) {
    c5_myarr256[c5_i187] = c5_tt[c5_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_cb_encStr2Arr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_myarr256[1000])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_maxarrsize;
  real_T c5_arr[137];
  real_T c5_ss;
  real_T c5_padsize;
  real_T c5_tt[1000];
  char_T c5_mystr[137];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i188;
  static char_T c5_cv29[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'l', 'o', 'c', 'o', 'm', 'o',
    't', 'i', 'o', 'n', ' ', 'm', 'a', 'n', 'n', 'e', 'r', '=', '\"', 'w', 'a',
    'l', 'k', '\"', ' ', 'f', 'a', 'c', 'i', 'n', 'g', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', ' ', ' ', 's', 'b', 'm', ':', 'a', 'c', 'c', 'e', 'l',
    '=', '\"', '0', '.', '5', '\"', ' ', 's', 'b', 'm', ':', 's', 'c', 'o', 'o',
    't', 'a', 'c', 'c', 'e', 'l', '=', '\"', '5', '0', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', '0', ' ', '0', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c5_i189;
  static real_T c5_dv49[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 108.0, 111.0, 99.0, 111.0, 109.0, 111.0, 116.0, 105.0, 111.0,
    110.0, 32.0, 109.0, 97.0, 110.0, 110.0, 101.0, 114.0, 61.0, 34.0, 119.0,
    97.0, 108.0, 107.0, 34.0, 32.0, 102.0, 97.0, 99.0, 105.0, 110.0, 103.0, 61.0,
    34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0, 32.0, 115.0, 98.0,
    109.0, 58.0, 97.0, 99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 115.0, 99.0, 111.0, 111.0, 116.0, 97.0,
    99.0, 99.0, 101.0, 108.0, 61.0, 34.0, 53.0, 48.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 48.0, 32.0, 48.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c5_i190;
  int32_T c5_i191;
  int32_T c5_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_kb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_maxarrsize, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_arr, 1U, c5_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ss, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_padsize, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tt, 4U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_mystr, 5U, c5_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myarr256, 8U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  for (c5_i188 = 0; c5_i188 < 137; c5_i188++) {
    c5_mystr[c5_i188] = c5_cv29[c5_i188];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 6);
  for (c5_i189 = 0; c5_i189 < 137; c5_i189++) {
    c5_arr[c5_i189] = c5_dv49[c5_i189];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_padsize = c5_maxarrsize - c5_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  for (c5_i190 = 0; c5_i190 < 1000; c5_i190++) {
    c5_tt[c5_i190] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i191 = 0; c5_i191 < 137; c5_i191++) {
    c5_tt[c5_i191] = c5_arr[c5_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i192 = 0; c5_i192 < 1000; c5_i192++) {
    c5_myarr256[c5_i192] = c5_tt[c5_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\24-12-2015-Matlab\\encStr2Arr.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i193;
  int32_T c5_i194;
  int32_T c5_i195;
  real_T c5_b_inData[5000];
  int32_T c5_i196;
  int32_T c5_i197;
  int32_T c5_i198;
  real_T c5_u[5000];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i193 = 0;
  for (c5_i194 = 0; c5_i194 < 5; c5_i194++) {
    for (c5_i195 = 0; c5_i195 < 1000; c5_i195++) {
      c5_b_inData[c5_i195 + c5_i193] = (*(real_T (*)[5000])c5_inData)[c5_i195 +
        c5_i193];
    }

    c5_i193 += 1000;
  }

  c5_i196 = 0;
  for (c5_i197 = 0; c5_i197 < 5; c5_i197++) {
    for (c5_i198 = 0; c5_i198 < 1000; c5_i198++) {
      c5_u[c5_i198 + c5_i196] = c5_b_inData[c5_i198 + c5_i196];
    }

    c5_i196 += 1000;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  const mxArray *c5_newBmls, const char_T *c5_identifier, real_T c5_y[5000])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_newBmls), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_newBmls);
}

static void c5_b_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[5000])
{
  real_T c5_dv50[5000];
  int32_T c5_i199;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv50, 1, 0, 0U, 1, 0U, 2, 1000,
                5);
  for (c5_i199 = 0; c5_i199 < 5000; c5_i199++) {
    c5_y[c5_i199] = c5_dv50[c5_i199];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_newBmls;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[5000];
  int32_T c5_i200;
  int32_T c5_i201;
  int32_T c5_i202;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_newBmls = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_newBmls), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_newBmls);
  c5_i200 = 0;
  for (c5_i201 = 0; c5_i201 < 5; c5_i201++) {
    for (c5_i202 = 0; c5_i202 < 1000; c5_i202++) {
      (*(real_T (*)[5000])c5_outData)[c5_i202 + c5_i200] = c5_y[c5_i202 +
        c5_i200];
    }

    c5_i200 += 1000;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i203;
  real_T c5_b_inData[1000];
  int32_T c5_i204;
  real_T c5_u[1000];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i203 = 0; c5_i203 < 1000; c5_i203++) {
    c5_b_inData[c5_i203] = (*(real_T (*)[1000])c5_inData)[c5_i203];
  }

  for (c5_i204 = 0; c5_i204 < 1000; c5_i204++) {
    c5_u[c5_i204] = c5_b_inData[c5_i204];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[1000])
{
  real_T c5_dv51[1000];
  int32_T c5_i205;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv51, 1, 0, 0U, 1, 0U, 2, 1000,
                1);
  for (c5_i205 = 0; c5_i205 < 1000; c5_i205++) {
    c5_y[c5_i205] = c5_dv51[c5_i205];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_mBML;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[1000];
  int32_T c5_i206;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mBML = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_mBML), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_mBML);
  for (c5_i206 = 0; c5_i206 < 1000; c5_i206++) {
    (*(real_T (*)[1000])c5_outData)[c5_i206] = c5_y[c5_i206];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_d_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_nargout, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  return c5_y;
}

static real_T c5_e_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i207;
  real_T c5_b_inData[1000];
  int32_T c5_i208;
  real_T c5_u[1000];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i207 = 0; c5_i207 < 1000; c5_i207++) {
    c5_b_inData[c5_i207] = (*(real_T (*)[1000])c5_inData)[c5_i207];
  }

  for (c5_i208 = 0; c5_i208 < 1000; c5_i208++) {
    c5_u[c5_i208] = c5_b_inData[c5_i208];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[1000])
{
  real_T c5_dv52[1000];
  int32_T c5_i209;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv52, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c5_i209 = 0; c5_i209 < 1000; c5_i209++) {
    c5_y[c5_i209] = c5_dv52[c5_i209];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_myarr256;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[1000];
  int32_T c5_i210;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_myarr256 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_myarr256), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_myarr256);
  for (c5_i210 = 0; c5_i210 < 1000; c5_i210++) {
    (*(real_T (*)[1000])c5_outData)[c5_i210] = c5_y[c5_i210];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  char_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(char_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static boolean_T c5_g_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_y;
  boolean_T c5_b0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b0, 1, 11, 0U, 0, 0U, 0);
  c5_y = c5_b0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_aVarTruthTableCondition_3;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_y;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_aVarTruthTableCondition_3 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_aVarTruthTableCondition_3), &c5_thisId);
  sf_mex_destroy(&c5_aVarTruthTableCondition_3);
  *(boolean_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i211;
  char_T c5_b_inData[144];
  int32_T c5_i212;
  char_T c5_u[144];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i211 = 0; c5_i211 < 144; c5_i211++) {
    c5_b_inData[c5_i211] = (*(char_T (*)[144])c5_inData)[c5_i211];
  }

  for (c5_i212 = 0; c5_i212 < 144; c5_i212++) {
    c5_u[c5_i212] = c5_b_inData[c5_i212];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 144),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i213;
  real_T c5_b_inData[144];
  int32_T c5_i214;
  real_T c5_u[144];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i213 = 0; c5_i213 < 144; c5_i213++) {
    c5_b_inData[c5_i213] = (*(real_T (*)[144])c5_inData)[c5_i213];
  }

  for (c5_i214 = 0; c5_i214 < 144; c5_i214++) {
    c5_u[c5_i214] = c5_b_inData[c5_i214];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 144), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i215;
  char_T c5_b_inData[97];
  int32_T c5_i216;
  char_T c5_u[97];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i215 = 0; c5_i215 < 97; c5_i215++) {
    c5_b_inData[c5_i215] = (*(char_T (*)[97])c5_inData)[c5_i215];
  }

  for (c5_i216 = 0; c5_i216 < 97; c5_i216++) {
    c5_u[c5_i216] = c5_b_inData[c5_i216];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i217;
  real_T c5_b_inData[97];
  int32_T c5_i218;
  real_T c5_u[97];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i217 = 0; c5_i217 < 97; c5_i217++) {
    c5_b_inData[c5_i217] = (*(real_T (*)[97])c5_inData)[c5_i217];
  }

  for (c5_i218 = 0; c5_i218 < 97; c5_i218++) {
    c5_u[c5_i218] = c5_b_inData[c5_i218];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i219;
  char_T c5_b_inData[127];
  int32_T c5_i220;
  char_T c5_u[127];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i219 = 0; c5_i219 < 127; c5_i219++) {
    c5_b_inData[c5_i219] = (*(char_T (*)[127])c5_inData)[c5_i219];
  }

  for (c5_i220 = 0; c5_i220 < 127; c5_i220++) {
    c5_u[c5_i220] = c5_b_inData[c5_i220];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 127),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i221;
  real_T c5_b_inData[127];
  int32_T c5_i222;
  real_T c5_u[127];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i221 = 0; c5_i221 < 127; c5_i221++) {
    c5_b_inData[c5_i221] = (*(real_T (*)[127])c5_inData)[c5_i221];
  }

  for (c5_i222 = 0; c5_i222 < 127; c5_i222++) {
    c5_u[c5_i222] = c5_b_inData[c5_i222];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 127), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i223;
  char_T c5_b_inData[125];
  int32_T c5_i224;
  char_T c5_u[125];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i223 = 0; c5_i223 < 125; c5_i223++) {
    c5_b_inData[c5_i223] = (*(char_T (*)[125])c5_inData)[c5_i223];
  }

  for (c5_i224 = 0; c5_i224 < 125; c5_i224++) {
    c5_u[c5_i224] = c5_b_inData[c5_i224];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 125),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i225;
  real_T c5_b_inData[125];
  int32_T c5_i226;
  real_T c5_u[125];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i225 = 0; c5_i225 < 125; c5_i225++) {
    c5_b_inData[c5_i225] = (*(real_T (*)[125])c5_inData)[c5_i225];
  }

  for (c5_i226 = 0; c5_i226 < 125; c5_i226++) {
    c5_u[c5_i226] = c5_b_inData[c5_i226];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 125), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i227;
  char_T c5_b_inData[99];
  int32_T c5_i228;
  char_T c5_u[99];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i227 = 0; c5_i227 < 99; c5_i227++) {
    c5_b_inData[c5_i227] = (*(char_T (*)[99])c5_inData)[c5_i227];
  }

  for (c5_i228 = 0; c5_i228 < 99; c5_i228++) {
    c5_u[c5_i228] = c5_b_inData[c5_i228];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i229;
  real_T c5_b_inData[99];
  int32_T c5_i230;
  real_T c5_u[99];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i229 = 0; c5_i229 < 99; c5_i229++) {
    c5_b_inData[c5_i229] = (*(real_T (*)[99])c5_inData)[c5_i229];
  }

  for (c5_i230 = 0; c5_i230 < 99; c5_i230++) {
    c5_u[c5_i230] = c5_b_inData[c5_i230];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i231;
  char_T c5_b_inData[86];
  int32_T c5_i232;
  char_T c5_u[86];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i231 = 0; c5_i231 < 86; c5_i231++) {
    c5_b_inData[c5_i231] = (*(char_T (*)[86])c5_inData)[c5_i231];
  }

  for (c5_i232 = 0; c5_i232 < 86; c5_i232++) {
    c5_u[c5_i232] = c5_b_inData[c5_i232];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i233;
  real_T c5_b_inData[86];
  int32_T c5_i234;
  real_T c5_u[86];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i233 = 0; c5_i233 < 86; c5_i233++) {
    c5_b_inData[c5_i233] = (*(real_T (*)[86])c5_inData)[c5_i233];
  }

  for (c5_i234 = 0; c5_i234 < 86; c5_i234++) {
    c5_u[c5_i234] = c5_b_inData[c5_i234];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i235;
  char_T c5_b_inData[102];
  int32_T c5_i236;
  char_T c5_u[102];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i235 = 0; c5_i235 < 102; c5_i235++) {
    c5_b_inData[c5_i235] = (*(char_T (*)[102])c5_inData)[c5_i235];
  }

  for (c5_i236 = 0; c5_i236 < 102; c5_i236++) {
    c5_u[c5_i236] = c5_b_inData[c5_i236];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 102),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i237;
  real_T c5_b_inData[102];
  int32_T c5_i238;
  real_T c5_u[102];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i237 = 0; c5_i237 < 102; c5_i237++) {
    c5_b_inData[c5_i237] = (*(real_T (*)[102])c5_inData)[c5_i237];
  }

  for (c5_i238 = 0; c5_i238 < 102; c5_i238++) {
    c5_u[c5_i238] = c5_b_inData[c5_i238];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 102), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i239;
  char_T c5_b_inData[160];
  int32_T c5_i240;
  char_T c5_u[160];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i239 = 0; c5_i239 < 160; c5_i239++) {
    c5_b_inData[c5_i239] = (*(char_T (*)[160])c5_inData)[c5_i239];
  }

  for (c5_i240 = 0; c5_i240 < 160; c5_i240++) {
    c5_u[c5_i240] = c5_b_inData[c5_i240];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 160),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i241;
  real_T c5_b_inData[160];
  int32_T c5_i242;
  real_T c5_u[160];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i241 = 0; c5_i241 < 160; c5_i241++) {
    c5_b_inData[c5_i241] = (*(real_T (*)[160])c5_inData)[c5_i241];
  }

  for (c5_i242 = 0; c5_i242 < 160; c5_i242++) {
    c5_u[c5_i242] = c5_b_inData[c5_i242];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 160), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_w_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i243;
  char_T c5_b_inData[156];
  int32_T c5_i244;
  char_T c5_u[156];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i243 = 0; c5_i243 < 156; c5_i243++) {
    c5_b_inData[c5_i243] = (*(char_T (*)[156])c5_inData)[c5_i243];
  }

  for (c5_i244 = 0; c5_i244 < 156; c5_i244++) {
    c5_u[c5_i244] = c5_b_inData[c5_i244];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 156),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_x_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i245;
  real_T c5_b_inData[156];
  int32_T c5_i246;
  real_T c5_u[156];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i245 = 0; c5_i245 < 156; c5_i245++) {
    c5_b_inData[c5_i245] = (*(real_T (*)[156])c5_inData)[c5_i245];
  }

  for (c5_i246 = 0; c5_i246 < 156; c5_i246++) {
    c5_u[c5_i246] = c5_b_inData[c5_i246];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 156), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_y_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i247;
  char_T c5_b_inData[91];
  int32_T c5_i248;
  char_T c5_u[91];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i247 = 0; c5_i247 < 91; c5_i247++) {
    c5_b_inData[c5_i247] = (*(char_T (*)[91])c5_inData)[c5_i247];
  }

  for (c5_i248 = 0; c5_i248 < 91; c5_i248++) {
    c5_u[c5_i248] = c5_b_inData[c5_i248];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i249;
  real_T c5_b_inData[91];
  int32_T c5_i250;
  real_T c5_u[91];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i249 = 0; c5_i249 < 91; c5_i249++) {
    c5_b_inData[c5_i249] = (*(real_T (*)[91])c5_inData)[c5_i249];
  }

  for (c5_i250 = 0; c5_i250 < 91; c5_i250++) {
    c5_u[c5_i250] = c5_b_inData[c5_i250];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i251;
  char_T c5_b_inData[88];
  int32_T c5_i252;
  char_T c5_u[88];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i251 = 0; c5_i251 < 88; c5_i251++) {
    c5_b_inData[c5_i251] = (*(char_T (*)[88])c5_inData)[c5_i251];
  }

  for (c5_i252 = 0; c5_i252 < 88; c5_i252++) {
    c5_u[c5_i252] = c5_b_inData[c5_i252];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i253;
  real_T c5_b_inData[88];
  int32_T c5_i254;
  real_T c5_u[88];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i253 = 0; c5_i253 < 88; c5_i253++) {
    c5_b_inData[c5_i253] = (*(real_T (*)[88])c5_inData)[c5_i253];
  }

  for (c5_i254 = 0; c5_i254 < 88; c5_i254++) {
    c5_u[c5_i254] = c5_b_inData[c5_i254];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_db_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i255;
  char_T c5_b_inData[87];
  int32_T c5_i256;
  char_T c5_u[87];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i255 = 0; c5_i255 < 87; c5_i255++) {
    c5_b_inData[c5_i255] = (*(char_T (*)[87])c5_inData)[c5_i255];
  }

  for (c5_i256 = 0; c5_i256 < 87; c5_i256++) {
    c5_u[c5_i256] = c5_b_inData[c5_i256];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i257;
  real_T c5_b_inData[87];
  int32_T c5_i258;
  real_T c5_u[87];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i257 = 0; c5_i257 < 87; c5_i257++) {
    c5_b_inData[c5_i257] = (*(real_T (*)[87])c5_inData)[c5_i257];
  }

  for (c5_i258 = 0; c5_i258 < 87; c5_i258++) {
    c5_u[c5_i258] = c5_b_inData[c5_i258];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i259;
  char_T c5_b_inData[93];
  int32_T c5_i260;
  char_T c5_u[93];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i259 = 0; c5_i259 < 93; c5_i259++) {
    c5_b_inData[c5_i259] = (*(char_T (*)[93])c5_inData)[c5_i259];
  }

  for (c5_i260 = 0; c5_i260 < 93; c5_i260++) {
    c5_u[c5_i260] = c5_b_inData[c5_i260];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i261;
  real_T c5_b_inData[93];
  int32_T c5_i262;
  real_T c5_u[93];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i261 = 0; c5_i261 < 93; c5_i261++) {
    c5_b_inData[c5_i261] = (*(real_T (*)[93])c5_inData)[c5_i261];
  }

  for (c5_i262 = 0; c5_i262 < 93; c5_i262++) {
    c5_u[c5_i262] = c5_b_inData[c5_i262];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i263;
  char_T c5_b_inData[94];
  int32_T c5_i264;
  char_T c5_u[94];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i263 = 0; c5_i263 < 94; c5_i263++) {
    c5_b_inData[c5_i263] = (*(char_T (*)[94])c5_inData)[c5_i263];
  }

  for (c5_i264 = 0; c5_i264 < 94; c5_i264++) {
    c5_u[c5_i264] = c5_b_inData[c5_i264];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i265;
  real_T c5_b_inData[94];
  int32_T c5_i266;
  real_T c5_u[94];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i265 = 0; c5_i265 < 94; c5_i265++) {
    c5_b_inData[c5_i265] = (*(real_T (*)[94])c5_inData)[c5_i265];
  }

  for (c5_i266 = 0; c5_i266 < 94; c5_i266++) {
    c5_u[c5_i266] = c5_b_inData[c5_i266];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i267;
  char_T c5_b_inData[95];
  int32_T c5_i268;
  char_T c5_u[95];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i267 = 0; c5_i267 < 95; c5_i267++) {
    c5_b_inData[c5_i267] = (*(char_T (*)[95])c5_inData)[c5_i267];
  }

  for (c5_i268 = 0; c5_i268 < 95; c5_i268++) {
    c5_u[c5_i268] = c5_b_inData[c5_i268];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i269;
  real_T c5_b_inData[95];
  int32_T c5_i270;
  real_T c5_u[95];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i269 = 0; c5_i269 < 95; c5_i269++) {
    c5_b_inData[c5_i269] = (*(real_T (*)[95])c5_inData)[c5_i269];
  }

  for (c5_i270 = 0; c5_i270 < 95; c5_i270++) {
    c5_u[c5_i270] = c5_b_inData[c5_i270];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i271;
  char_T c5_b_inData[92];
  int32_T c5_i272;
  char_T c5_u[92];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i271 = 0; c5_i271 < 92; c5_i271++) {
    c5_b_inData[c5_i271] = (*(char_T (*)[92])c5_inData)[c5_i271];
  }

  for (c5_i272 = 0; c5_i272 < 92; c5_i272++) {
    c5_u[c5_i272] = c5_b_inData[c5_i272];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i273;
  real_T c5_b_inData[92];
  int32_T c5_i274;
  real_T c5_u[92];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i273 = 0; c5_i273 < 92; c5_i273++) {
    c5_b_inData[c5_i273] = (*(real_T (*)[92])c5_inData)[c5_i273];
  }

  for (c5_i274 = 0; c5_i274 < 92; c5_i274++) {
    c5_u[c5_i274] = c5_b_inData[c5_i274];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i275;
  char_T c5_b_inData[68];
  int32_T c5_i276;
  char_T c5_u[68];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i275 = 0; c5_i275 < 68; c5_i275++) {
    c5_b_inData[c5_i275] = (*(char_T (*)[68])c5_inData)[c5_i275];
  }

  for (c5_i276 = 0; c5_i276 < 68; c5_i276++) {
    c5_u[c5_i276] = c5_b_inData[c5_i276];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i277;
  real_T c5_b_inData[68];
  int32_T c5_i278;
  real_T c5_u[68];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i277 = 0; c5_i277 < 68; c5_i277++) {
    c5_b_inData[c5_i277] = (*(real_T (*)[68])c5_inData)[c5_i277];
  }

  for (c5_i278 = 0; c5_i278 < 68; c5_i278++) {
    c5_u[c5_i278] = c5_b_inData[c5_i278];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i279;
  char_T c5_b_inData[137];
  int32_T c5_i280;
  char_T c5_u[137];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i279 = 0; c5_i279 < 137; c5_i279++) {
    c5_b_inData[c5_i279] = (*(char_T (*)[137])c5_inData)[c5_i279];
  }

  for (c5_i280 = 0; c5_i280 < 137; c5_i280++) {
    c5_u[c5_i280] = c5_b_inData[c5_i280];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i281;
  real_T c5_b_inData[137];
  int32_T c5_i282;
  real_T c5_u[137];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i281 = 0; c5_i281 < 137; c5_i281++) {
    c5_b_inData[c5_i281] = (*(real_T (*)[137])c5_inData)[c5_i281];
  }

  for (c5_i282 = 0; c5_i282 < 137; c5_i282++) {
    c5_u[c5_i282] = c5_b_inData[c5_i282];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_Expriment_Gaze_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 16, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/24-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("disp"), "name", "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static void c5_activate_secsc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance)
{
  chartInstance->c5_sfEvent = c5_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c5_event_secs,
               chartInstance->c5_sfEvent);
}

static void c5_deactivate_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c5_event_secs,
               chartInstance->c5_sfEvent);
}

static void c5_increment_counters_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  if (chartInstance->c5_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c5_temporalCounter_i1++;
  }

  if (chartInstance->c5_temporalCounter_i2 < MAX_uint32_T) {
    chartInstance->c5_temporalCounter_i2++;
  }

  if (chartInstance->c5_temporalCounter_i3 < MAX_uint32_T) {
    chartInstance->c5_temporalCounter_i3++;
  }
}

static void c5_reset_counters_secsc5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c5_Expriment_Gaze_secs(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_activate_secsc5_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c5_Expriment_Gaze_secs(SimStruct *
  c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_increment_counters_secsc5_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c5_Expriment_Gaze_secs(SimStruct
  *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_reset_counters_secsc5_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_deactivate_c5_Expriment_Gaze_secs(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_deactivate_secsc5_Expriment_Gaze(chartInstance);
}

boolean_T sf_exported_auto_isStablec5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  return chartInstance->c5_isStable;
}

void sf_exported_auto_duringc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_c5_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_enterc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_sendSBM(chartInstance);
  c5_enter_atomic_c5_Expriment_Gaze(chartInstance);
  c5_enter_internal_c5_Expriment_Gaze(chartInstance);
}

void sf_exported_auto_exitc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_exit_internal_c5_Expriment_Gaze(chartInstance);
  c5_b_sendSBM(chartInstance);
}

void sf_exported_auto_gatewayc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_sendSBM(chartInstance);
}

void sf_exported_auto_disablec5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c5_b_sendSBM(chartInstance);
}

void sf_exported_auto_stepBuffersc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  chartInstance->c5_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc5_Expriment_Gaze(SimStruct *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_initc5_Expriment_Gaze(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec5_Expriment_Gaze(SimStruct *c5_S)
{
  const mxArray *c5_out = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_out = NULL;
  sf_mex_assign(&c5_out, sf_internal_get_sim_state_c5_Expriment_Gaze(c5_S),
                false);
  return c5_out;
}

void sf_exported_auto_setSimstatec5_Expriment_Gaze(SimStruct *c5_S, const
  mxArray *c5_in)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c5_Expriment_Gaze(c5_S, sf_mex_dup(c5_in));
  sf_mex_destroy(&c5_in);
}

void sf_exported_auto_check_state_inconsistency_c5_Expriment_Gaze(SimStruct
  *c5_S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_GazeMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_insertQueuec5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_bmls[5000], real_T c5_mBML[1000], real_T c5_newBmls
  [5000])
{
  uint32_T c5_debug_family_var_map[8];
  real_T c5_full;
  real_T c5_tempp[1000];
  real_T c5_i;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i283;
  static real_T c5_dv53[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  int32_T c5_i284;
  int32_T c5_i285;
  int32_T c5_i286;
  int32_T c5_i287;
  int32_T c5_i288;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_i289;
  real_T c5_b_bmls[1000];
  int32_T c5_i290;
  real_T c5_dv54[1000];
  int32_T c5_d_i;
  int32_T c5_i291;
  int32_T c5_i292;
  real_T c5_c_bmls[1000];
  int32_T c5_i293;
  int32_T c5_i294;
  real_T c5_d_bmls[1000];
  int32_T c5_i295;
  int32_T c5_i296;
  real_T c5_e_bmls[1000];
  int32_T c5_i297;
  int32_T c5_i298;
  int32_T c5_i299;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_full, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_tempp, 1U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 2U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_bmls, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_mBML, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_newBmls, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 2);
  c5_full = 1.0;
  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 3);
  for (c5_i283 = 0; c5_i283 < 1000; c5_i283++) {
    c5_tempp[c5_i283] = c5_dv53[c5_i283];
  }

  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 4);
  for (c5_i284 = 0; c5_i284 < 1000; c5_i284++) {
    c5_newBmls[c5_i284] = c5_tempp[c5_i284];
  }

  for (c5_i285 = 0; c5_i285 < 1000; c5_i285++) {
    c5_newBmls[c5_i285 + 1000] = c5_tempp[c5_i285];
  }

  for (c5_i286 = 0; c5_i286 < 1000; c5_i286++) {
    c5_newBmls[c5_i286 + 2000] = c5_tempp[c5_i286];
  }

  for (c5_i287 = 0; c5_i287 < 1000; c5_i287++) {
    c5_newBmls[c5_i287 + 3000] = c5_tempp[c5_i287];
  }

  for (c5_i288 = 0; c5_i288 < 1000; c5_i288++) {
    c5_newBmls[c5_i288 + 4000] = c5_tempp[c5_i288];
  }

  c5_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 5);
  c5_i = 1.0;
  c5_b_i = 0;
  do {
    exitg1 = 0;
    if (c5_b_i < 5) {
      c5_i = 1.0 + (real_T)c5_b_i;
      CV_EML_FOR(3, 1, 0, 1);
      _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 6);
      c5_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c5_i), 1, 5, 2, 0) - 1;
      for (c5_i289 = 0; c5_i289 < 1000; c5_i289++) {
        c5_b_bmls[c5_i289] = c5_bmls[c5_i289 + 1000 * c5_c_i];
      }

      for (c5_i290 = 0; c5_i290 < 1000; c5_i290++) {
        c5_dv54[c5_i290] = c5_dv53[c5_i290];
      }

      if (CV_EML_IF(3, 1, 0, c5_isequal(chartInstance, c5_b_bmls, c5_dv54))) {
        _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 8);
        c5_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK
          ("i", c5_i), 1, 5, 2, 0) - 1;
        for (c5_i291 = 0; c5_i291 < 1000; c5_i291++) {
          c5_bmls[c5_i291 + 1000 * c5_d_i] = c5_mBML[c5_i291];
        }

        _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 9);
        c5_full = 0.0;
        _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 10);
        exitg1 = 1;
      } else {
        c5_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(3, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 13);
  if (CV_EML_IF(3, 1, 1, c5_full != 0.0)) {
    _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 15);
    for (c5_i292 = 0; c5_i292 < 1000; c5_i292++) {
      c5_c_bmls[c5_i292] = c5_bmls[c5_i292 + 1000];
    }

    for (c5_i293 = 0; c5_i293 < 1000; c5_i293++) {
      c5_bmls[c5_i293] = c5_c_bmls[c5_i293];
    }

    _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 16);
    for (c5_i294 = 0; c5_i294 < 1000; c5_i294++) {
      c5_d_bmls[c5_i294] = c5_bmls[c5_i294 + 2000];
    }

    for (c5_i295 = 0; c5_i295 < 1000; c5_i295++) {
      c5_bmls[c5_i295 + 1000] = c5_d_bmls[c5_i295];
    }

    _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 17);
    for (c5_i296 = 0; c5_i296 < 1000; c5_i296++) {
      c5_e_bmls[c5_i296] = c5_bmls[c5_i296 + 3000];
    }

    for (c5_i297 = 0; c5_i297 < 1000; c5_i297++) {
      c5_bmls[c5_i297 + 2000] = c5_e_bmls[c5_i297];
    }

    _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 18);
    for (c5_i298 = 0; c5_i298 < 1000; c5_i298++) {
      c5_bmls[c5_i298 + 4000] = c5_mBML[c5_i298];
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, 20);
  for (c5_i299 = 0; c5_i299 < 5000; c5_i299++) {
    c5_newBmls[c5_i299] = c5_bmls[c5_i299];
  }

  c5_updateDataWrittenToVector(chartInstance, 9U);
  _SFD_EML_CALL(3U, chartInstance->c5_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_insertQueueLowc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_bmls[5000], real_T c5_myBML[1000], real_T
  c5_newBmls[5000])
{
  uint32_T c5_debug_family_var_map[8];
  real_T c5_full;
  real_T c5_tempp[1000];
  real_T c5_i;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i300;
  static real_T c5_dv55[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  int32_T c5_i301;
  int32_T c5_i302;
  int32_T c5_i303;
  int32_T c5_i304;
  int32_T c5_i305;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_i306;
  real_T c5_b_bmls[1000];
  int32_T c5_i307;
  real_T c5_dv56[1000];
  int32_T c5_d_i;
  int32_T c5_i308;
  int32_T c5_i309;
  real_T c5_c_bmls[1000];
  int32_T c5_i310;
  int32_T c5_i311;
  real_T c5_d_bmls[1000];
  int32_T c5_i312;
  int32_T c5_i313;
  real_T c5_e_bmls[1000];
  int32_T c5_i314;
  int32_T c5_i315;
  int32_T c5_i316;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_c_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_full, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_tempp, 1U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 2U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_bmls, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_myBML, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_newBmls, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 2);
  c5_full = 1.0;
  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 3);
  for (c5_i300 = 0; c5_i300 < 1000; c5_i300++) {
    c5_tempp[c5_i300] = c5_dv55[c5_i300];
  }

  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 4);
  for (c5_i301 = 0; c5_i301 < 1000; c5_i301++) {
    c5_newBmls[c5_i301] = c5_tempp[c5_i301];
  }

  for (c5_i302 = 0; c5_i302 < 1000; c5_i302++) {
    c5_newBmls[c5_i302 + 1000] = c5_tempp[c5_i302];
  }

  for (c5_i303 = 0; c5_i303 < 1000; c5_i303++) {
    c5_newBmls[c5_i303 + 2000] = c5_tempp[c5_i303];
  }

  for (c5_i304 = 0; c5_i304 < 1000; c5_i304++) {
    c5_newBmls[c5_i304 + 3000] = c5_tempp[c5_i304];
  }

  for (c5_i305 = 0; c5_i305 < 1000; c5_i305++) {
    c5_newBmls[c5_i305 + 4000] = c5_tempp[c5_i305];
  }

  c5_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 5);
  c5_i = 1.0;
  c5_b_i = 0;
  do {
    exitg1 = 0;
    if (c5_b_i < 5) {
      c5_i = 1.0 + (real_T)c5_b_i;
      CV_EML_FOR(4, 1, 0, 1);
      _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 6);
      c5_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c5_i), 1, 5, 2, 0) - 1;
      for (c5_i306 = 0; c5_i306 < 1000; c5_i306++) {
        c5_b_bmls[c5_i306] = c5_bmls[c5_i306 + 1000 * c5_c_i];
      }

      for (c5_i307 = 0; c5_i307 < 1000; c5_i307++) {
        c5_dv56[c5_i307] = c5_dv55[c5_i307];
      }

      if (CV_EML_IF(4, 1, 0, c5_isequal(chartInstance, c5_b_bmls, c5_dv56))) {
        _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 8);
        c5_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK
          ("i", c5_i), 1, 5, 2, 0) - 1;
        for (c5_i308 = 0; c5_i308 < 1000; c5_i308++) {
          c5_bmls[c5_i308 + 1000 * c5_d_i] = c5_myBML[c5_i308];
        }

        _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 9);
        c5_full = 0.0;
        _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 10);
        exitg1 = 1;
      } else {
        c5_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(4, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 13);
  if (CV_EML_IF(4, 1, 1, c5_full != 0.0)) {
    _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 15);
    for (c5_i309 = 0; c5_i309 < 1000; c5_i309++) {
      c5_c_bmls[c5_i309] = c5_bmls[c5_i309 + 1000];
    }

    for (c5_i310 = 0; c5_i310 < 1000; c5_i310++) {
      c5_bmls[c5_i310] = c5_c_bmls[c5_i310];
    }

    _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 16);
    for (c5_i311 = 0; c5_i311 < 1000; c5_i311++) {
      c5_d_bmls[c5_i311] = c5_bmls[c5_i311 + 2000];
    }

    for (c5_i312 = 0; c5_i312 < 1000; c5_i312++) {
      c5_bmls[c5_i312 + 1000] = c5_d_bmls[c5_i312];
    }

    _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 17);
    for (c5_i313 = 0; c5_i313 < 1000; c5_i313++) {
      c5_e_bmls[c5_i313] = c5_bmls[c5_i313 + 3000];
    }

    for (c5_i314 = 0; c5_i314 < 1000; c5_i314++) {
      c5_bmls[c5_i314 + 2000] = c5_e_bmls[c5_i314];
    }

    _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 18);
    for (c5_i315 = 0; c5_i315 < 1000; c5_i315++) {
      c5_bmls[c5_i315 + 4000] = c5_myBML[c5_i315];
    }
  }

  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, 21);
  for (c5_i316 = 0; c5_i316 < 5000; c5_i316++) {
    c5_newBmls[c5_i316] = c5_bmls[c5_i316];
  }

  c5_updateDataWrittenToVector(chartInstance, 10U);
  _SFD_EML_CALL(4U, chartInstance->c5_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_sendSBMc5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, real_T c5_arg[256])
{
  int32_T c5_i317;
  int32_T c5_i318;
  int32_T c5_i319;
  real_T (*c5_b_arg)[256];
  c5_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 8);
  for (c5_i317 = 0; c5_i317 < 256; c5_i317++) {
    _SFD_DATA_RANGE_CHECK(c5_arg[c5_i317], 61U);
  }

  _SFD_SET_DATA_VALUE_PTR(61U, c5_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c5_arg, c5_vb_sf_marshallOut,
    c5_i_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c5_sfEvent);
  for (c5_i318 = 0; c5_i318 < 256; c5_i318++) {
    (*c5_b_arg)[c5_i318] = c5_arg[c5_i318];
  }

  for (c5_i319 = 0; c5_i319 < 256; c5_i319++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_arg)[c5_i319], 61U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendSBM", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 8U, chartInstance->c5_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(61U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c5_sfEvent);
}

static void c5_rockPoseTablec5_Expriment_Gaze(SFc5_Expriment_GazeInstanceStruct *
  chartInstance, real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  uint32_T c5_debug_family_var_map[8];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 2.0;
  real_T c5_dv57[1000];
  int32_T c5_i320;
  int32_T c5_i321;
  int32_T c5_i322;
  int32_T c5_i323;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_d_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_p, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(6, 0);
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 14);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 18);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 20);
  if (CV_EML_IF(6, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 21);
    CV_EML_FCN(6, 1);
    _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 34);
    c5_b_encStr2Arr(chartInstance, c5_dv57);
    for (c5_i320 = 0; c5_i320 < 1000; c5_i320++) {
      c5_poseBML[c5_i320] = c5_dv57[c5_i320];
    }

    c5_updateDataWrittenToVector(chartInstance, 12U);
    _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 34);
    *c5_p = 2.0;
    c5_updateDataWrittenToVector(chartInstance, 11U);
    _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, -34);
  } else {
    _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 22);
    if (CV_EML_IF(6, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 23);
      CV_EML_FCN(6, 2);
      _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 40);
      c5_c_encStr2Arr(chartInstance, c5_dv57);
      for (c5_i321 = 0; c5_i321 < 1000; c5_i321++) {
        c5_poseBML[c5_i321] = c5_dv57[c5_i321];
      }

      c5_updateDataWrittenToVector(chartInstance, 12U);
      _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 40);
      *c5_p = 2.0;
      c5_updateDataWrittenToVector(chartInstance, 11U);
      _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, -40);
    } else {
      _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 24);
      if (CV_EML_IF(6, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 25);
        CV_EML_FCN(6, 4);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 52);
        c5_d_encStr2Arr(chartInstance, c5_dv57);
        for (c5_i322 = 0; c5_i322 < 1000; c5_i322++) {
          c5_poseBML[c5_i322] = c5_dv57[c5_i322];
        }

        c5_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 52);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, -52);
      } else {
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 27);
        CV_EML_FCN(6, 1);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 34);
        c5_b_encStr2Arr(chartInstance, c5_dv57);
        for (c5_i323 = 0; c5_i323 < 1000; c5_i323++) {
          c5_poseBML[c5_i323] = c5_dv57[c5_i323];
        }

        c5_updateDataWrittenToVector(chartInstance, 12U);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, 34);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 11U);
        _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(6U, chartInstance->c5_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_paperPoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000])
{
  uint32_T c5_debug_family_var_map[8];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 2.0;
  real_T c5_dv58[1000];
  int32_T c5_i324;
  int32_T c5_i325;
  int32_T c5_i326;
  int32_T c5_i327;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_h_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_p, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 14);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 18);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 20);
  if (CV_EML_IF(5, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 21);
    CV_EML_FCN(5, 1);
    _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 34);
    c5_e_encStr2Arr(chartInstance, c5_dv58);
    for (c5_i324 = 0; c5_i324 < 1000; c5_i324++) {
      c5_poseBML[c5_i324] = c5_dv58[c5_i324];
    }

    c5_updateDataWrittenToVector(chartInstance, 14U);
    _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 34);
    *c5_p = 2.0;
    c5_updateDataWrittenToVector(chartInstance, 13U);
    _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, -34);
  } else {
    _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 22);
    if (CV_EML_IF(5, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 23);
      CV_EML_FCN(5, 2);
      _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 40);
      c5_f_encStr2Arr(chartInstance, c5_dv58);
      for (c5_i325 = 0; c5_i325 < 1000; c5_i325++) {
        c5_poseBML[c5_i325] = c5_dv58[c5_i325];
      }

      c5_updateDataWrittenToVector(chartInstance, 14U);
      _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 40);
      *c5_p = 2.0;
      c5_updateDataWrittenToVector(chartInstance, 13U);
      _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, -40);
    } else {
      _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 24);
      if (CV_EML_IF(5, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 25);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 46);
        c5_g_encStr2Arr(chartInstance, c5_dv58);
        for (c5_i326 = 0; c5_i326 < 1000; c5_i326++) {
          c5_poseBML[c5_i326] = c5_dv58[c5_i326];
        }

        c5_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 46);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, -46);
      } else {
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 27);
        CV_EML_FCN(5, 3);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 46);
        c5_g_encStr2Arr(chartInstance, c5_dv58);
        for (c5_i327 = 0; c5_i327 < 1000; c5_i327++) {
          c5_poseBML[c5_i327] = c5_dv58[c5_i327];
        }

        c5_updateDataWrittenToVector(chartInstance, 14U);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, 46);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 13U);
        _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, -46);
      }
    }
  }

  _SFD_EML_CALL(5U, chartInstance->c5_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_scissorsPoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000])
{
  uint32_T c5_debug_family_var_map[8];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 2.0;
  real_T c5_dv59[1000];
  int32_T c5_i328;
  int32_T c5_i329;
  int32_T c5_i330;
  int32_T c5_i331;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_l_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_p, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 14);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 18);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 20);
  if (CV_EML_IF(7, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 21);
    CV_EML_FCN(7, 1);
    _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 34);
    c5_h_encStr2Arr(chartInstance, c5_dv59);
    for (c5_i328 = 0; c5_i328 < 1000; c5_i328++) {
      c5_poseBML[c5_i328] = c5_dv59[c5_i328];
    }

    c5_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 34);
    *c5_p = 2.0;
    c5_updateDataWrittenToVector(chartInstance, 15U);
    _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, -34);
  } else {
    _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 22);
    if (CV_EML_IF(7, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 23);
      CV_EML_FCN(7, 3);
      _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 46);
      c5_i_encStr2Arr(chartInstance, c5_dv59);
      for (c5_i329 = 0; c5_i329 < 1000; c5_i329++) {
        c5_poseBML[c5_i329] = c5_dv59[c5_i329];
      }

      c5_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 46);
      *c5_p = 2.0;
      c5_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, -46);
    } else {
      _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 24);
      if (CV_EML_IF(7, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 25);
        CV_EML_FCN(7, 3);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 46);
        c5_i_encStr2Arr(chartInstance, c5_dv59);
        for (c5_i330 = 0; c5_i330 < 1000; c5_i330++) {
          c5_poseBML[c5_i330] = c5_dv59[c5_i330];
        }

        c5_updateDataWrittenToVector(chartInstance, 16U);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 46);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, -46);
      } else {
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 27);
        CV_EML_FCN(7, 1);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 34);
        c5_h_encStr2Arr(chartInstance, c5_dv59);
        for (c5_i331 = 0; c5_i331 < 1000; c5_i331++) {
          c5_poseBML[c5_i331] = c5_dv59[c5_i331];
        }

        c5_updateDataWrittenToVector(chartInstance, 16U);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, 34);
        *c5_p = 2.0;
        c5_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(7U, chartInstance->c5_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_handPoseSBTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_sbmID, real_T
   c5_poseSBM[1000])
{
  uint32_T c5_debug_family_var_map[8];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  boolean_T c5_aVarTruthTableCondition_4;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  real_T c5_dv60[1000];
  int32_T c5_i332;
  int32_T c5_i333;
  int32_T c5_i334;
  int32_T c5_i335;
  int32_T c5_i336;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_o_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_4, 3U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_sbmID, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseSBM, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_aVarTruthTableCondition_1 = (c5_sbmID == 1.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_aVarTruthTableCondition_2 = (c5_sbmID == 2.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_aVarTruthTableCondition_3 = (c5_sbmID == 3.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_aVarTruthTableCondition_4 = (c5_sbmID == 4.0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
  if (CV_EML_IF(0, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 41);
    c5_j_encStr2Arr(chartInstance, c5_dv60);
    for (c5_i332 = 0; c5_i332 < 1000; c5_i332++) {
      c5_poseSBM[c5_i332] = c5_dv60[c5_i332];
    }

    c5_updateDataWrittenToVector(chartInstance, 17U);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -41);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
    if (CV_EML_IF(0, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 47);
      c5_k_encStr2Arr(chartInstance, c5_dv60);
      for (c5_i333 = 0; c5_i333 < 1000; c5_i333++) {
        c5_poseSBM[c5_i333] = c5_dv60[c5_i333];
      }

      c5_updateDataWrittenToVector(chartInstance, 17U);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -47);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
      if (CV_EML_IF(0, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 53);
        c5_l_encStr2Arr(chartInstance, c5_dv60);
        for (c5_i334 = 0; c5_i334 < 1000; c5_i334++) {
          c5_poseSBM[c5_i334] = c5_dv60[c5_i334];
        }

        c5_updateDataWrittenToVector(chartInstance, 17U);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -53);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
        if (CV_EML_IF(0, 1, 3, c5_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 59);
          c5_m_encStr2Arr(chartInstance, c5_dv60);
          for (c5_i335 = 0; c5_i335 < 1000; c5_i335++) {
            c5_poseSBM[c5_i335] = c5_dv60[c5_i335];
          }

          c5_updateDataWrittenToVector(chartInstance, 17U);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -59);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
          CV_EML_FCN(0, 1);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 41);
          c5_j_encStr2Arr(chartInstance, c5_dv60);
          for (c5_i336 = 0; c5_i336 < 1000; c5_i336++) {
            c5_poseSBM[c5_i336] = c5_dv60[c5_i336];
          }

          c5_updateDataWrittenToVector(chartInstance, 17U);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -41);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_idlePoseBradTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000])
{
  uint32_T c5_debug_family_var_map[23];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  boolean_T c5_aVarTruthTableCondition_4;
  boolean_T c5_aVarTruthTableCondition_5;
  boolean_T c5_aVarTruthTableCondition_6;
  boolean_T c5_aVarTruthTableCondition_7;
  boolean_T c5_aVarTruthTableCondition_8;
  boolean_T c5_aVarTruthTableCondition_9;
  boolean_T c5_aVarTruthTableCondition_10;
  boolean_T c5_aVarTruthTableCondition_11;
  boolean_T c5_aVarTruthTableCondition_12;
  boolean_T c5_aVarTruthTableCondition_13;
  boolean_T c5_aVarTruthTableCondition_14;
  boolean_T c5_aVarTruthTableCondition_15;
  boolean_T c5_aVarTruthTableCondition_16;
  boolean_T c5_aVarTruthTableCondition_17;
  boolean_T c5_aVarTruthTableCondition_18;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 2.0;
  real_T c5_dv61[1000];
  int32_T c5_i337;
  int32_T c5_i338;
  int32_T c5_i339;
  int32_T c5_i340;
  int32_T c5_i341;
  int32_T c5_i342;
  int32_T c5_i343;
  int32_T c5_i344;
  int32_T c5_i345;
  int32_T c5_i346;
  int32_T c5_i347;
  int32_T c5_i348;
  int32_T c5_i349;
  int32_T c5_i350;
  int32_T c5_i351;
  int32_T c5_i352;
  int32_T c5_i353;
  int32_T c5_i354;
  int32_T c5_i355;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c5_t_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_4, 3U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_5, 4U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_6, 5U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_7, 6U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_8, 7U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_9, 8U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_10, 9U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_11, 10U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_12, 11U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_13, 12U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_14, 13U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_15, 14U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_16, 15U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_17, 16U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_18, 17U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 18U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 19U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 20U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_p, 21U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 6);
  c5_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 7);
  c5_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 8);
  c5_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 9);
  c5_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 11);
  c5_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 12);
  c5_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 13);
  c5_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 14);
  c5_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 15);
  c5_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 16);
  c5_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 17);
  c5_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 18);
  c5_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 19);
  c5_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 20);
  c5_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 24);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 27);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 30);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 33);
  c5_aVarTruthTableCondition_4 = (c5_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 36);
  c5_aVarTruthTableCondition_5 = (c5_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 39);
  c5_aVarTruthTableCondition_6 = (c5_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 42);
  c5_aVarTruthTableCondition_7 = (c5_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 45);
  c5_aVarTruthTableCondition_8 = (c5_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 48);
  c5_aVarTruthTableCondition_9 = (c5_bmlID == 9.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 51);
  c5_aVarTruthTableCondition_10 = (c5_bmlID == 10.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 54);
  c5_aVarTruthTableCondition_11 = (c5_bmlID == 11.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 57);
  c5_aVarTruthTableCondition_12 = (c5_bmlID == 12.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 60);
  c5_aVarTruthTableCondition_13 = (c5_bmlID == 13.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 63);
  c5_aVarTruthTableCondition_14 = (c5_bmlID == 14.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 66);
  c5_aVarTruthTableCondition_15 = (c5_bmlID == 15.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 69);
  c5_aVarTruthTableCondition_16 = (c5_bmlID == 16.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 72);
  c5_aVarTruthTableCondition_17 = (c5_bmlID == 17.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 75);
  c5_aVarTruthTableCondition_18 = (c5_bmlID == 18.0);
  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 77);
  if (CV_EML_IF(1, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 78);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 121);
    c5_n_encStr2Arr(chartInstance, c5_dv61);
    for (c5_i337 = 0; c5_i337 < 1000; c5_i337++) {
      c5_poseBML[c5_i337] = c5_dv61[c5_i337];
    }

    c5_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 121);
    *c5_p = 3.0;
    c5_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -121);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 79);
    if (CV_EML_IF(1, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 80);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, MAX_int8_T);
      c5_o_encStr2Arr(chartInstance, c5_dv61);
      for (c5_i338 = 0; c5_i338 < 1000; c5_i338++) {
        c5_poseBML[c5_i338] = c5_dv61[c5_i338];
      }

      c5_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, MAX_int8_T);
      *c5_p = 3.0;
      c5_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -127);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 81);
      if (CV_EML_IF(1, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 82);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
        c5_p_encStr2Arr(chartInstance, c5_dv61);
        for (c5_i339 = 0; c5_i339 < 1000; c5_i339++) {
          c5_poseBML[c5_i339] = c5_dv61[c5_i339];
        }

        c5_updateDataWrittenToVector(chartInstance, 19U);
        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
        *c5_p = 3.0;
        c5_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -133);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 83);
        if (CV_EML_IF(1, 1, 3, c5_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 84);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 139U);
          c5_q_encStr2Arr(chartInstance, c5_dv61);
          for (c5_i340 = 0; c5_i340 < 1000; c5_i340++) {
            c5_poseBML[c5_i340] = c5_dv61[c5_i340];
          }

          c5_updateDataWrittenToVector(chartInstance, 19U);
          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 139U);
          *c5_p = 3.0;
          c5_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -139);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 85);
          if (CV_EML_IF(1, 1, 4, c5_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 86);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 145U);
            c5_r_encStr2Arr(chartInstance, c5_dv61);
            for (c5_i341 = 0; c5_i341 < 1000; c5_i341++) {
              c5_poseBML[c5_i341] = c5_dv61[c5_i341];
            }

            c5_updateDataWrittenToVector(chartInstance, 19U);
            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 145U);
            *c5_p = 3.0;
            c5_updateDataWrittenToVector(chartInstance, 18U);
            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -145);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 87);
            if (CV_EML_IF(1, 1, 5, c5_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 88);
              CV_EML_FCN(1, 11);
              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 181U);
              c5_s_encStr2Arr(chartInstance, c5_dv61);
              for (c5_i342 = 0; c5_i342 < 1000; c5_i342++) {
                c5_poseBML[c5_i342] = c5_dv61[c5_i342];
              }

              c5_updateDataWrittenToVector(chartInstance, 19U);
              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 181U);
              *c5_p = 3.0;
              c5_updateDataWrittenToVector(chartInstance, 18U);
              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -181);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 89);
              if (CV_EML_IF(1, 1, 6, c5_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 90);
                CV_EML_FCN(1, 3);
                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
                c5_p_encStr2Arr(chartInstance, c5_dv61);
                for (c5_i343 = 0; c5_i343 < 1000; c5_i343++) {
                  c5_poseBML[c5_i343] = c5_dv61[c5_i343];
                }

                c5_updateDataWrittenToVector(chartInstance, 19U);
                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
                *c5_p = 3.0;
                c5_updateDataWrittenToVector(chartInstance, 18U);
                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -133);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 91);
                if (CV_EML_IF(1, 1, 7, c5_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 92);
                  CV_EML_FCN(1, 5);
                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 145U);
                  c5_r_encStr2Arr(chartInstance, c5_dv61);
                  for (c5_i344 = 0; c5_i344 < 1000; c5_i344++) {
                    c5_poseBML[c5_i344] = c5_dv61[c5_i344];
                  }

                  c5_updateDataWrittenToVector(chartInstance, 19U);
                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 145U);
                  *c5_p = 3.0;
                  c5_updateDataWrittenToVector(chartInstance, 18U);
                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -145);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 93);
                  if (CV_EML_IF(1, 1, 8, c5_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 94);
                    CV_EML_FCN(1, 3);
                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
                    c5_p_encStr2Arr(chartInstance, c5_dv61);
                    for (c5_i345 = 0; c5_i345 < 1000; c5_i345++) {
                      c5_poseBML[c5_i345] = c5_dv61[c5_i345];
                    }

                    c5_updateDataWrittenToVector(chartInstance, 19U);
                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 133U);
                    *c5_p = 3.0;
                    c5_updateDataWrittenToVector(chartInstance, 18U);
                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -133);
                  } else {
                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 95);
                    if (CV_EML_IF(1, 1, 9, c5_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 96);
                      CV_EML_FCN(1, 10);
                      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 175U);
                      c5_t_encStr2Arr(chartInstance, c5_dv61);
                      for (c5_i346 = 0; c5_i346 < 1000; c5_i346++) {
                        c5_poseBML[c5_i346] = c5_dv61[c5_i346];
                      }

                      c5_updateDataWrittenToVector(chartInstance, 19U);
                      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 175U);
                      *c5_p = 3.0;
                      c5_updateDataWrittenToVector(chartInstance, 18U);
                      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -175);
                    } else {
                      _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 97);
                      if (CV_EML_IF(1, 1, 10, c5_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 98);
                        CV_EML_FCN(1, 11);
                        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 181U);
                        c5_s_encStr2Arr(chartInstance, c5_dv61);
                        for (c5_i347 = 0; c5_i347 < 1000; c5_i347++) {
                          c5_poseBML[c5_i347] = c5_dv61[c5_i347];
                        }

                        c5_updateDataWrittenToVector(chartInstance, 19U);
                        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 181U);
                        *c5_p = 3.0;
                        c5_updateDataWrittenToVector(chartInstance, 18U);
                        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -181);
                      } else {
                        _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 99);
                        if (CV_EML_IF(1, 1, 11, c5_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 100);
                          CV_EML_FCN(1, 8);
                          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 163U);
                          c5_u_encStr2Arr(chartInstance, c5_dv61);
                          for (c5_i348 = 0; c5_i348 < 1000; c5_i348++) {
                            c5_poseBML[c5_i348] = c5_dv61[c5_i348];
                          }

                          c5_updateDataWrittenToVector(chartInstance, 19U);
                          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 163U);
                          *c5_p = 3.0;
                          c5_updateDataWrittenToVector(chartInstance, 18U);
                          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -163);
                        } else {
                          _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 101);
                          if (CV_EML_IF(1, 1, 12, c5_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 102);
                            CV_EML_FCN(1, 8);
                            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 163U);
                            c5_u_encStr2Arr(chartInstance, c5_dv61);
                            for (c5_i349 = 0; c5_i349 < 1000; c5_i349++) {
                              c5_poseBML[c5_i349] = c5_dv61[c5_i349];
                            }

                            c5_updateDataWrittenToVector(chartInstance, 19U);
                            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 163U);
                            *c5_p = 3.0;
                            c5_updateDataWrittenToVector(chartInstance, 18U);
                            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 103);
                            if (CV_EML_IF(1, 1, 13,
                                          c5_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 104);
                              CV_EML_FCN(1, 7);
                              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 157U);
                              c5_v_encStr2Arr(chartInstance, c5_dv61);
                              for (c5_i350 = 0; c5_i350 < 1000; c5_i350++) {
                                c5_poseBML[c5_i350] = c5_dv61[c5_i350];
                              }

                              c5_updateDataWrittenToVector(chartInstance, 19U);
                              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 157U);
                              *c5_p = 3.0;
                              c5_updateDataWrittenToVector(chartInstance, 18U);
                              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -157);
                            } else {
                              _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 105);
                              if (CV_EML_IF(1, 1, 14,
                                            c5_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 106);
                                CV_EML_FCN(1, 6);
                                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                              151U);
                                c5_w_encStr2Arr(chartInstance, c5_dv61);
                                for (c5_i351 = 0; c5_i351 < 1000; c5_i351++) {
                                  c5_poseBML[c5_i351] = c5_dv61[c5_i351];
                                }

                                c5_updateDataWrittenToVector(chartInstance, 19U);
                                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                              151U);
                                *c5_p = 3.0;
                                c5_updateDataWrittenToVector(chartInstance, 18U);
                                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                              -151);
                              } else {
                                _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, 107);
                                if (CV_EML_IF(1, 1, 15,
                                              c5_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                108);
                                  CV_EML_FCN(1, 5);
                                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                145U);
                                  c5_r_encStr2Arr(chartInstance, c5_dv61);
                                  for (c5_i352 = 0; c5_i352 < 1000; c5_i352++) {
                                    c5_poseBML[c5_i352] = c5_dv61[c5_i352];
                                  }

                                  c5_updateDataWrittenToVector(chartInstance,
                                    19U);
                                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                145U);
                                  *c5_p = 3.0;
                                  c5_updateDataWrittenToVector(chartInstance,
                                    18U);
                                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                -145);
                                } else {
                                  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                109);
                                  if (CV_EML_IF(1, 1, 16,
                                                c5_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                  110);
                                    CV_EML_FCN(1, 8);
                                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                  163U);
                                    c5_u_encStr2Arr(chartInstance, c5_dv61);
                                    for (c5_i353 = 0; c5_i353 < 1000; c5_i353++)
                                    {
                                      c5_poseBML[c5_i353] = c5_dv61[c5_i353];
                                    }

                                    c5_updateDataWrittenToVector(chartInstance,
                                      19U);
                                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                  163U);
                                    *c5_p = 3.0;
                                    c5_updateDataWrittenToVector(chartInstance,
                                      18U);
                                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                  -163);
                                  } else {
                                    _SFD_EML_CALL(1U, chartInstance->c5_sfEvent,
                                                  111);
                                    if (CV_EML_IF(1, 1, 17,
                                                  c5_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    112);
                                      CV_EML_FCN(1, 9);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    169U);
                                      c5_x_encStr2Arr(chartInstance, c5_dv61);
                                      for (c5_i354 = 0; c5_i354 < 1000; c5_i354
                                           ++) {
                                        c5_poseBML[c5_i354] = c5_dv61[c5_i354];
                                      }

                                      c5_updateDataWrittenToVector(chartInstance,
                                        19U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    169U);
                                      *c5_p = 3.0;
                                      c5_updateDataWrittenToVector(chartInstance,
                                        18U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    -169);
                                    } else {
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    114);
                                      CV_EML_FCN(1, 3);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    133U);
                                      c5_p_encStr2Arr(chartInstance, c5_dv61);
                                      for (c5_i355 = 0; c5_i355 < 1000; c5_i355
                                           ++) {
                                        c5_poseBML[c5_i355] = c5_dv61[c5_i355];
                                      }

                                      c5_updateDataWrittenToVector(chartInstance,
                                        19U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
                                                    133U);
                                      *c5_p = 3.0;
                                      c5_updateDataWrittenToVector(chartInstance,
                                        18U);
                                      _SFD_EML_CALL(1U,
                                                    chartInstance->c5_sfEvent,
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

  _SFD_EML_CALL(1U, chartInstance->c5_sfEvent, -114);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_initialPoseTablec5_Expriment_Gaze
  (SFc5_Expriment_GazeInstanceStruct *chartInstance, real_T c5_bmlID, real_T
   *c5_p, real_T c5_poseBML[1000])
{
  uint32_T c5_debug_family_var_map[9];
  boolean_T c5_aVarTruthTableCondition_1;
  boolean_T c5_aVarTruthTableCondition_2;
  boolean_T c5_aVarTruthTableCondition_3;
  boolean_T c5_aVarTruthTableCondition_4;
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 2.0;
  real_T c5_dv62[1000];
  int32_T c5_i356;
  int32_T c5_i357;
  int32_T c5_i358;
  int32_T c5_i359;
  int32_T c5_i360;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_gb_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_1, 0U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_2, 1U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_3, 2U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_aVarTruthTableCondition_4, 3U,
    c5_f_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_bmlID, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_p, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poseBML, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 3);
  c5_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 4);
  c5_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 5);
  c5_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 6);
  c5_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 10);
  c5_aVarTruthTableCondition_1 = (c5_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 13);
  c5_aVarTruthTableCondition_2 = (c5_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 16);
  c5_aVarTruthTableCondition_3 = (c5_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 19);
  c5_aVarTruthTableCondition_4 = (c5_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 21);
  if (CV_EML_IF(2, 1, 0, c5_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 22);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 37);
    c5_y_encStr2Arr(chartInstance, c5_dv62);
    for (c5_i356 = 0; c5_i356 < 1000; c5_i356++) {
      c5_poseBML[c5_i356] = c5_dv62[c5_i356];
    }

    c5_updateDataWrittenToVector(chartInstance, 21U);
    _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 37);
    *c5_p = 3.0;
    c5_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -37);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 23);
    if (CV_EML_IF(2, 1, 1, c5_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 24);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 43);
      c5_ab_encStr2Arr(chartInstance, c5_dv62);
      for (c5_i357 = 0; c5_i357 < 1000; c5_i357++) {
        c5_poseBML[c5_i357] = c5_dv62[c5_i357];
      }

      c5_updateDataWrittenToVector(chartInstance, 21U);
      _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 43);
      *c5_p = 3.0;
      c5_updateDataWrittenToVector(chartInstance, 20U);
      _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -43);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 25);
      if (CV_EML_IF(2, 1, 2, c5_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 26);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 49);
        c5_bb_encStr2Arr(chartInstance, c5_dv62);
        for (c5_i358 = 0; c5_i358 < 1000; c5_i358++) {
          c5_poseBML[c5_i358] = c5_dv62[c5_i358];
        }

        c5_updateDataWrittenToVector(chartInstance, 21U);
        _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 49);
        *c5_p = 3.0;
        c5_updateDataWrittenToVector(chartInstance, 20U);
        _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -49);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 27);
        if (CV_EML_IF(2, 1, 3, c5_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 28);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 55);
          c5_cb_encStr2Arr(chartInstance, c5_dv62);
          for (c5_i359 = 0; c5_i359 < 1000; c5_i359++) {
            c5_poseBML[c5_i359] = c5_dv62[c5_i359];
          }

          c5_updateDataWrittenToVector(chartInstance, 21U);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 55);
          *c5_p = 3.0;
          c5_updateDataWrittenToVector(chartInstance, 20U);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -55);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 30);
          CV_EML_FCN(2, 1);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 37);
          c5_y_encStr2Arr(chartInstance, c5_dv62);
          for (c5_i360 = 0; c5_i360 < 1000; c5_i360++) {
            c5_poseBML[c5_i360] = c5_dv62[c5_i360];
          }

          c5_updateDataWrittenToVector(chartInstance, 21U);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, 37);
          *c5_p = 3.0;
          c5_updateDataWrittenToVector(chartInstance, 20U);
          _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -37);
        }
      }
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c5_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_sendSBM(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendSBM", 0);
}

static void c5_b_sendSBM(SFc5_Expriment_GazeInstanceStruct *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendSBM", 0);
}

static boolean_T c5_isequal(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  real_T c5_varargin_1[1000], real_T c5_varargin_2[1000])
{
  boolean_T c5_p;
  boolean_T c5_b_p;
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_x1;
  real_T c5_x2;
  boolean_T c5_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c5_p = false;
  c5_b_p = true;
  c5_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c5_k < 1000)) {
    c5_b_k = 1.0 + (real_T)c5_k;
    c5_x1 = c5_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c5_b_k), 1, 1000, 1, 0) - 1];
    c5_x2 = c5_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c5_b_k), 1, 1000, 1, 0) - 1];
    c5_c_p = (c5_x1 == c5_x2);
    if (!c5_c_p) {
      c5_b_p = false;
      exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (!c5_b_p) {
  } else {
    c5_p = true;
  }

  return c5_p;
}

void sf_exported_user_c5_Expriment_Gaze_handPoseSBTable(SimStruct *c5_S, real_T
  c5_sbmID, real_T c5_poseSBM[1000])
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_handPoseSBTablec5_Expriment_Gaze(chartInstance, c5_sbmID, c5_poseSBM);
}

void sf_exported_user_c5_Expriment_Gaze_idlePoseBradTable(SimStruct *c5_S,
  real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  real_T c5_b_p;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_idlePoseBradTablec5_Expriment_Gaze(chartInstance, c5_bmlID, &c5_b_p,
    c5_poseBML);
  *c5_p = c5_b_p;
}

void sf_exported_user_c5_Expriment_Gaze_initialPoseTable(SimStruct *c5_S, real_T
  c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  real_T c5_b_p;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_initialPoseTablec5_Expriment_Gaze(chartInstance, c5_bmlID, &c5_b_p,
    c5_poseBML);
  *c5_p = c5_b_p;
}

void sf_exported_user_c5_Expriment_Gaze_insertQueue(SimStruct *c5_S, real_T
  c5_bmls[5000], real_T c5_mBML[1000], real_T c5_newBmls[5000])
{
  int32_T c5_i361;
  real_T c5_b_bmls[5000];
  int32_T c5_i362;
  real_T c5_b_mBML[1000];
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  for (c5_i361 = 0; c5_i361 < 5000; c5_i361++) {
    c5_b_bmls[c5_i361] = c5_bmls[c5_i361];
  }

  for (c5_i362 = 0; c5_i362 < 1000; c5_i362++) {
    c5_b_mBML[c5_i362] = c5_mBML[c5_i362];
  }

  c5_insertQueuec5_Expriment_Gaze(chartInstance, c5_b_bmls, c5_b_mBML,
    c5_newBmls);
}

void sf_exported_user_c5_Expriment_Gaze_insertQueueLow(SimStruct *c5_S, real_T
  c5_bmls[5000], real_T c5_myBML[1000], real_T c5_newBmls[5000])
{
  int32_T c5_i363;
  real_T c5_b_bmls[5000];
  int32_T c5_i364;
  real_T c5_b_myBML[1000];
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  for (c5_i363 = 0; c5_i363 < 5000; c5_i363++) {
    c5_b_bmls[c5_i363] = c5_bmls[c5_i363];
  }

  for (c5_i364 = 0; c5_i364 < 1000; c5_i364++) {
    c5_b_myBML[c5_i364] = c5_myBML[c5_i364];
  }

  c5_insertQueueLowc5_Expriment_Gaze(chartInstance, c5_b_bmls, c5_b_myBML,
    c5_newBmls);
}

void sf_exported_user_c5_Expriment_Gaze_paperPoseBradTable(SimStruct *c5_S,
  real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  real_T c5_b_p;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_paperPoseBradTablec5_Expriment_Gaze(chartInstance, c5_bmlID, &c5_b_p,
    c5_poseBML);
  *c5_p = c5_b_p;
}

void sf_exported_user_c5_Expriment_Gaze_rockPoseTable(SimStruct *c5_S, real_T
  c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  real_T c5_b_p;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_rockPoseTablec5_Expriment_Gaze(chartInstance, c5_bmlID, &c5_b_p, c5_poseBML);
  *c5_p = c5_b_p;
}

void sf_exported_user_c5_Expriment_Gaze_scissorsPoseBradTable(SimStruct *c5_S,
  real_T c5_bmlID, real_T *c5_p, real_T c5_poseBML[1000])
{
  real_T c5_b_p;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  c5_scissorsPoseBradTablec5_Expriment_Gaze(chartInstance, c5_bmlID, &c5_b_p,
    c5_poseBML);
  *c5_p = c5_b_p;
}

void sf_exported_user_c5_Expriment_Gaze_sendSBM(SimStruct *c5_S, real_T c5_arg
  [256])
{
  int32_T c5_i365;
  real_T c5_b_arg[256];
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c5_S))->instanceInfo)->chartInstance;
  for (c5_i365 = 0; c5_i365 < 256; c5_i365++) {
    c5_b_arg[c5_i365] = c5_arg[c5_i365];
  }

  c5_sendSBMc5_Expriment_Gaze(chartInstance, c5_b_arg);
}

static const mxArray *c5_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int8_T c5_h_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int8_T c5_y;
  int8_T c5_i366;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i366, 1, 2, 0U, 0, 0U, 0);
  c5_y = c5_i366;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_secs;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int8_T c5_y;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_secs = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_secs), &c5_thisId);
  sf_mex_destroy(&c5_secs);
  *(int8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_i_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i367;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i367, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i367;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint8_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint8_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static uint8_T c5_j_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_tp_stateGame, const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateGame),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateGame);
  return c5_y;
}

static uint8_T c5_k_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_tp_stateGame;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_b_tp_stateGame = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_tp_stateGame),
    &c5_thisId);
  sf_mex_destroy(&c5_b_tp_stateGame);
  *(uint8_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i368;
  real_T c5_b_inData[25];
  int32_T c5_i369;
  real_T c5_u[25];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i368 = 0; c5_i368 < 25; c5_i368++) {
    c5_b_inData[c5_i368] = (*(real_T (*)[25])c5_inData)[c5_i368];
  }

  for (c5_i369 = 0; c5_i369 < 25; c5_i369++) {
    c5_u[c5_i369] = c5_b_inData[c5_i369];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 25), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i370;
  real_T c5_b_inData[256];
  int32_T c5_i371;
  real_T c5_u[256];
  const mxArray *c5_y = NULL;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i370 = 0; c5_i370 < 256; c5_i370++) {
    c5_b_inData[c5_i370] = (*(real_T (*)[256])c5_inData)[c5_i370];
  }

  for (c5_i371 = 0; c5_i371 < 256; c5_i371++) {
    c5_u[c5_i371] = c5_b_inData[c5_i371];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_l_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[256])
{
  real_T c5_dv63[256];
  int32_T c5_i372;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv63, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c5_i372 = 0; c5_i372 < 256; c5_i372++) {
    c5_y[c5_i372] = c5_dv63[c5_i372];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_arg;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[256];
  int32_T c5_i373;
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)chartInstanceVoid;
  c5_arg = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_arg), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_arg);
  for (c5_i373 = 0; c5_i373 < 256; c5_i373++) {
    (*(real_T (*)[256])c5_outData)[c5_i373] = c5_y[c5_i373];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static uint32_T c5_m_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_temporalCounter_i3, const char_T
  *c5_identifier)
{
  uint32_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_temporalCounter_i3),
    &c5_thisId);
  sf_mex_destroy(&c5_b_temporalCounter_i3);
  return c5_y;
}

static uint32_T c5_n_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u1;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u1, 1, 7, 0U, 0, 0U, 0);
  c5_y = c5_u1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static const mxArray *c5_o_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_b_setSimStateSideEffectsInfo, const char_T
  *c5_identifier)
{
  const mxArray *c5_y = NULL;
  emlrtMsgIdentifier c5_thisId;
  c5_y = NULL;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  sf_mex_assign(&c5_y, c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_setSimStateSideEffectsInfo), &c5_thisId), false);
  sf_mex_destroy(&c5_b_setSimStateSideEffectsInfo);
  return c5_y;
}

static const mxArray *c5_p_emlrt_marshallIn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  const mxArray *c5_y = NULL;
  (void)chartInstance;
  (void)c5_parentId;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_duplicatearraysafe(&c5_u), false);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_updateDataWrittenToVector(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_vectorIndex)
{
  (void)chartInstance;
  c5_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c5_vectorIndex, 0, 21, 1, 0)] = true;
}

static void c5_errorIfDataNotWrittenToFcn(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_vectorIndex, uint32_T c5_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c5_dataNumber, c5_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c5_vectorIndex, 0, 21, 1,
    0)]);
}

static real_T c5_get_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c5_b);
  if (chartInstance->c5_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#715) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c5_BML_address)[c5_b];
}

static void c5_set_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c5_b);
  if (chartInstance->c5_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#715) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c5_BML_address)[c5_b] = c5_c;
}

static real_T *c5_access_BML(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c5_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#715) in the initialization routine of the chart.\n");
  }

  c5_c = *chartInstance->c5_BML_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c5_c;
}

static real_T c5_get_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c5_b);
  if (chartInstance->c5_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#719) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c5_BML2_address)[c5_b];
}

static void c5_set_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c5_b);
  if (chartInstance->c5_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#719) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c5_BML2_address)[c5_b] = c5_c;
}

static real_T *c5_access_BML2(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c5_BML2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML2\' (#719) in the initialization routine of the chart.\n");
  }

  c5_c = *chartInstance->c5_BML2_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c5_c;
}

static real_T c5_get_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c5_b);
  if (chartInstance->c5_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#710) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_BORED_address;
}

static void c5_set_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c5_b);
  if (chartInstance->c5_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#710) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_BORED_address = c5_c;
}

static real_T *c5_access_BORED(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c5_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#710) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_BORED_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c5_c;
}

static real_T c5_get_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c5_b);
  if (chartInstance->c5_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#687) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_BOREDOM_THRESHOLD_address;
}

static void c5_set_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c5_b);
  if (chartInstance->c5_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#687) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_BOREDOM_THRESHOLD_address = c5_c;
}

static real_T *c5_access_BOREDOM_THRESHOLD(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c5_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#687) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_BOREDOM_THRESHOLD_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c5_c;
}

static real_T c5_get_CONTEMPT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c5_b);
  if (chartInstance->c5_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#709) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_CONTEMPT_address;
}

static void c5_set_CONTEMPT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c5_b);
  if (chartInstance->c5_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#709) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_CONTEMPT_address = c5_c;
}

static real_T *c5_access_CONTEMPT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c5_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#709) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_CONTEMPT_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c5_c;
}

static real_T c5_get_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c5_b);
  if (chartInstance->c5_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#714) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_EXCITE_address;
}

static void c5_set_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c5_b);
  if (chartInstance->c5_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#714) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_EXCITE_address = c5_c;
}

static real_T *c5_access_EXCITE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c5_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#714) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_EXCITE_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c5_c;
}

static real_T c5_get_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c5_b);
  if (chartInstance->c5_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#712) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_FEAR_address;
}

static void c5_set_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c5_b);
  if (chartInstance->c5_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#712) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_FEAR_address = c5_c;
}

static real_T *c5_access_FEAR(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c5_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#712) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_FEAR_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c5_c;
}

static real_T c5_get_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c5_b);
  if (chartInstance->c5_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#711) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_FRUST_address;
}

static void c5_set_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c5_b);
  if (chartInstance->c5_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#711) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_FRUST_address = c5_c;
}

static real_T *c5_access_FRUST(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c5_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#711) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_FRUST_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c5_c;
}

static real_T c5_get_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c5_b);
  if (chartInstance->c5_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#695) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_GAZE_GUI_address;
}

static void c5_set_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c5_b);
  if (chartInstance->c5_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#695) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_GAZE_GUI_address = c5_c;
}

static real_T *c5_access_GAZE_GUI(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c5_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#695) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_GAZE_GUI_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c5_c;
}

static real_T c5_get_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c5_b);
  if (chartInstance->c5_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#696) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_GAZE_SOFTEYE_address;
}

static void c5_set_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c5_b);
  if (chartInstance->c5_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#696) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_GAZE_SOFTEYE_address = c5_c;
}

static real_T *c5_access_GAZE_SOFTEYE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c5_GAZE_SOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SOFTEYE\' (#696) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_GAZE_SOFTEYE_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c5_c;
}

static real_T c5_get_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c5_b);
  if (chartInstance->c5_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#697) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_GAZE_USER_HAND_address;
}

static void c5_set_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c5_b);
  if (chartInstance->c5_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#697) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_GAZE_USER_HAND_address = c5_c;
}

static real_T *c5_access_GAZE_USER_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c5_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#697) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_GAZE_USER_HAND_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c5_c;
}

static real_T c5_get_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c5_b);
  if (chartInstance->c5_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#703) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_GAZE_WIN_address;
}

static void c5_set_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c5_b);
  if (chartInstance->c5_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#703) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_GAZE_WIN_address = c5_c;
}

static real_T *c5_access_GAZE_WIN(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c5_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#703) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_GAZE_WIN_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c5_c;
}

static real_T c5_get_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c5_b);
  if (chartInstance->c5_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#707) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_HAPPY_address;
}

static void c5_set_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c5_b);
  if (chartInstance->c5_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#707) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_HAPPY_address = c5_c;
}

static real_T *c5_access_HAPPY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c5_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#707) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_HAPPY_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c5_c;
}

static real_T c5_get_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c5_b);
  if (chartInstance->c5_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#713) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_IDLE_address;
}

static void c5_set_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c5_b);
  if (chartInstance->c5_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#713) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_IDLE_address = c5_c;
}

static real_T *c5_access_IDLE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c5_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#713) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_IDLE_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c5_c;
}

static real_T c5_get_P(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c5_b);
  if (chartInstance->c5_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#693) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_P_address;
}

static void c5_set_P(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c5_b);
  if (chartInstance->c5_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#693) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_P_address = c5_c;
}

static real_T *c5_access_P(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c5_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#693) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_P_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c5_c;
}

static real_T c5_get_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c5_b);
  if (chartInstance->c5_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#708) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_SAD_address;
}

static void c5_set_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c5_b);
  if (chartInstance->c5_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#708) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_SAD_address = c5_c;
}

static real_T *c5_access_SAD(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c5_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#708) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_SAD_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c5_b);
  if (chartInstance->c5_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#704) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_BEFORE_address;
}

static void c5_set_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c5_b);
  if (chartInstance->c5_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#704) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_BEFORE_address = c5_c;
}

static real_T *c5_access_STATE_BEFORE(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c5_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#704) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_BEFORE_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_GO(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c5_b);
  if (chartInstance->c5_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#699) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_GO_address;
}

static void c5_set_STATE_GO(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c5_b);
  if (chartInstance->c5_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#699) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_GO_address = c5_c;
}

static real_T *c5_access_STATE_GO(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c5_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#699) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_GO_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_HAND(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c5_b);
  if (chartInstance->c5_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#700) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_HAND_address;
}

static void c5_set_STATE_HAND(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c5_b);
  if (chartInstance->c5_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#700) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_HAND_address = c5_c;
}

static real_T *c5_access_STATE_HAND(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c5_STATE_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_HAND\' (#700) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_HAND_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_OVER(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c5_b);
  if (chartInstance->c5_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#701) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_OVER_address;
}

static void c5_set_STATE_OVER(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c5_b);
  if (chartInstance->c5_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#701) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_OVER_address = c5_c;
}

static real_T *c5_access_STATE_OVER(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c5_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#701) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_OVER_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_READY(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c5_b);
  if (chartInstance->c5_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#698) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_READY_address;
}

static void c5_set_STATE_READY(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c5_b);
  if (chartInstance->c5_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#698) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_READY_address = c5_c;
}

static real_T *c5_access_STATE_READY(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c5_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#698) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_READY_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c5_b);
  if (chartInstance->c5_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#705) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_RESULT_address;
}

static void c5_set_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c5_b);
  if (chartInstance->c5_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#705) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_RESULT_address = c5_c;
}

static real_T *c5_access_STATE_RESULT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c5_STATE_RESULT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_RESULT\' (#705) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_RESULT_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c5_c;
}

static real_T c5_get_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 22, NULL, c5_b);
  if (chartInstance->c5_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#706) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_STATE_WAIT_address;
}

static void c5_set_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 22, NULL, c5_b);
  if (chartInstance->c5_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#706) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_STATE_WAIT_address = c5_c;
}

static real_T *c5_access_STATE_WAIT(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 22, NULL);
  if (chartInstance->c5_STATE_WAIT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_WAIT\' (#706) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_STATE_WAIT_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 22, NULL);
  }

  return c5_c;
}

static real_T c5_get_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 23, NULL, c5_b);
  if (chartInstance->c5_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#694) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_avert_address;
}

static void c5_set_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 23, NULL, c5_b);
  if (chartInstance->c5_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#694) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_avert_address = c5_c;
}

static real_T *c5_access_avert(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 23, NULL);
  if (chartInstance->c5_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#694) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_avert_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 23, NULL);
  }

  return c5_c;
}

static real_T c5_get_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 24, NULL, c5_b);
  if (chartInstance->c5_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#728) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_avertH_address;
}

static void c5_set_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 24, NULL, c5_b);
  if (chartInstance->c5_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#728) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_avertH_address = c5_c;
}

static real_T *c5_access_avertH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 24, NULL);
  if (chartInstance->c5_avertH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avertH\' (#728) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_avertH_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 24, NULL);
  }

  return c5_c;
}

static real_T c5_get_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 25, NULL, c5_b);
  if (chartInstance->c5_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#682) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_bHand_address;
}

static void c5_set_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 25, NULL, c5_b);
  if (chartInstance->c5_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#682) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_bHand_address = c5_c;
}

static real_T *c5_access_bHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 25, NULL);
  if (chartInstance->c5_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#682) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_bHand_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 25, NULL);
  }

  return c5_c;
}

static real_T c5_get_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 26, NULL, c5_b);
  if (chartInstance->c5_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#721) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c5_bmlsH_address)[c5_b];
}

static void c5_set_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 26, NULL, c5_b);
  if (chartInstance->c5_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#721) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c5_bmlsH_address)[c5_b] = c5_c;
}

static real_T *c5_access_bmlsH(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 26, NULL);
  if (chartInstance->c5_bmlsH_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsH\' (#721) in the initialization routine of the chart.\n");
  }

  c5_c = *chartInstance->c5_bmlsH_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 26, NULL);
  }

  return c5_c;
}

static real_T c5_get_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 27, NULL, c5_b);
  if (chartInstance->c5_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#724) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c5_bmlsL_address)[c5_b];
}

static void c5_set_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 27, NULL, c5_b);
  if (chartInstance->c5_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#724) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c5_bmlsL_address)[c5_b] = c5_c;
}

static real_T *c5_access_bmlsL(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 27, NULL);
  if (chartInstance->c5_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#724) in the initialization routine of the chart.\n");
  }

  c5_c = *chartInstance->c5_bmlsL_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 27, NULL);
  }

  return c5_c;
}

static real_T c5_get_boredom(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 28, NULL, c5_b);
  if (chartInstance->c5_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#686) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_boredom_address;
}

static void c5_set_boredom(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 28, NULL, c5_b);
  if (chartInstance->c5_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#686) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_boredom_address = c5_c;
}

static real_T *c5_access_boredom(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 28, NULL);
  if (chartInstance->c5_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#686) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_boredom_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 28, NULL);
  }

  return c5_c;
}

static real_T c5_get_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 29, NULL, c5_b);
  if (chartInstance->c5_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#680) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_diff_address;
}

static void c5_set_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 29, NULL, c5_b);
  if (chartInstance->c5_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#680) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_diff_address = c5_c;
}

static real_T *c5_access_diff(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 29, NULL);
  if (chartInstance->c5_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#680) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_diff_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 29, NULL);
  }

  return c5_c;
}

static real_T c5_get_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 30, NULL, c5_b);
  if (chartInstance->c5_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#718) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_fileID_address;
}

static void c5_set_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 30, NULL, c5_b);
  if (chartInstance->c5_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#718) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_fileID_address = c5_c;
}

static real_T *c5_access_fileID(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 30, NULL);
  if (chartInstance->c5_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#718) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_fileID_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 30, NULL);
  }

  return c5_c;
}

static real_T c5_get_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 31, NULL, c5_b);
  if (chartInstance->c5_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#702) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_gazing_address;
}

static void c5_set_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 31, NULL, c5_b);
  if (chartInstance->c5_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#702) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_gazing_address = c5_c;
}

static real_T *c5_access_gazing(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 31, NULL);
  if (chartInstance->c5_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#702) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_gazing_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 31, NULL);
  }

  return c5_c;
}

static real_T c5_get_n(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 32, NULL, c5_b);
  if (chartInstance->c5_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#723) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c5_n_address)[c5_b];
}

static void c5_set_n(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 32, NULL, c5_b);
  if (chartInstance->c5_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#723) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c5_n_address)[c5_b] = c5_c;
}

static real_T *c5_access_n(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 32, NULL);
  if (chartInstance->c5_n_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'n\' (#723) in the initialization routine of the chart.\n");
  }

  c5_c = *chartInstance->c5_n_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 32, NULL);
  }

  return c5_c;
}

static real_T c5_get_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 33, NULL, c5_b);
  if (chartInstance->c5_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#691) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_pa_address;
}

static void c5_set_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                      c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 33, NULL, c5_b);
  if (chartInstance->c5_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#691) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_pa_address = c5_c;
}

static real_T *c5_access_pa(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 33, NULL);
  if (chartInstance->c5_pa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pa\' (#691) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_pa_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 33, NULL);
  }

  return c5_c;
}

static real_T c5_get_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 34, NULL, c5_b);
  if (chartInstance->c5_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#716) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_pr_address;
}

static void c5_set_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                      c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 34, NULL, c5_b);
  if (chartInstance->c5_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#716) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_pr_address = c5_c;
}

static real_T *c5_access_pr(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 34, NULL);
  if (chartInstance->c5_pr_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pr\' (#716) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_pr_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 34, NULL);
  }

  return c5_c;
}

static real_T c5_get_r(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 35, NULL, c5_b);
  if (chartInstance->c5_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#690) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_r_address;
}

static void c5_set_r(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 35, NULL, c5_b);
  if (chartInstance->c5_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#690) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_r_address = c5_c;
}

static real_T *c5_access_r(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 35, NULL);
  if (chartInstance->c5_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#690) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_r_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 35, NULL);
  }

  return c5_c;
}

static real_T c5_get_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 36, NULL, c5_b);
  if (chartInstance->c5_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#688) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_randAvertGazeChance_address;
}

static void c5_set_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 36, NULL, c5_b);
  if (chartInstance->c5_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#688) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_randAvertGazeChance_address = c5_c;
}

static real_T *c5_access_randAvertGazeChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 36, NULL);
  if (chartInstance->c5_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#688) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_randAvertGazeChance_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 36, NULL);
  }

  return c5_c;
}

static real_T c5_get_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 37, NULL, c5_b);
  if (chartInstance->c5_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#689) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_randPoseChance_address;
}

static void c5_set_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 37, NULL, c5_b);
  if (chartInstance->c5_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#689) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_randPoseChance_address = c5_c;
}

static real_T *c5_access_randPoseChance(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 37, NULL);
  if (chartInstance->c5_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#689) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_randPoseChance_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 37, NULL);
  }

  return c5_c;
}

static real_T c5_get_randSmile(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 38, NULL, c5_b);
  if (chartInstance->c5_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#685) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_randSmile_address;
}

static void c5_set_randSmile(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 38, NULL, c5_b);
  if (chartInstance->c5_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#685) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_randSmile_address = c5_c;
}

static real_T *c5_access_randSmile(SFc5_Expriment_GazeInstanceStruct
  *chartInstance, uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 38, NULL);
  if (chartInstance->c5_randSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSmile\' (#685) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_randSmile_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 38, NULL);
  }

  return c5_c;
}

static real_T c5_get_s(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 39, NULL, c5_b);
  if (chartInstance->c5_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#692) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_s_address;
}

static void c5_set_s(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 39, NULL, c5_b);
  if (chartInstance->c5_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#692) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_s_address = c5_c;
}

static real_T *c5_access_s(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 39, NULL);
  if (chartInstance->c5_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#692) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_s_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 39, NULL);
  }

  return c5_c;
}

static real_T c5_get_t(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 40, NULL, c5_b);
  if (chartInstance->c5_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#720) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_t_address;
}

static void c5_set_t(SFc5_Expriment_GazeInstanceStruct *chartInstance, uint32_T
                     c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 40, NULL, c5_b);
  if (chartInstance->c5_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#720) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_t_address = c5_c;
}

static real_T *c5_access_t(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 40, NULL);
  if (chartInstance->c5_t_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'t\' (#720) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_t_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 40, NULL);
  }

  return c5_c;
}

static real_T c5_get_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 41, NULL, c5_b);
  if (chartInstance->c5_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#679) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_temp_address;
}

static void c5_set_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 41, NULL, c5_b);
  if (chartInstance->c5_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#679) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_temp_address = c5_c;
}

static real_T *c5_access_temp(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 41, NULL);
  if (chartInstance->c5_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#679) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_temp_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 41, NULL);
  }

  return c5_c;
}

static real_T c5_get_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 42, NULL, c5_b);
  if (chartInstance->c5_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#681) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c5_uHand_address;
}

static void c5_set_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b, real_T c5_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 42, NULL, c5_b);
  if (chartInstance->c5_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#681) in the initialization routine of the chart.\n");
  }

  *chartInstance->c5_uHand_address = c5_c;
}

static real_T *c5_access_uHand(SFc5_Expriment_GazeInstanceStruct *chartInstance,
  uint32_T c5_b)
{
  real_T *c5_c;
  ssReadFromDataStore(chartInstance->S, 42, NULL);
  if (chartInstance->c5_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#681) in the initialization routine of the chart.\n");
  }

  c5_c = chartInstance->c5_uHand_address;
  if (c5_b == 0) {
    ssWriteToDataStore(chartInstance->S, 42, NULL);
  }

  return c5_c;
}

static void init_dsm_address_info(SFc5_Expriment_GazeInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c5_BML_address, &chartInstance->c5_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML2", (void **)
    &chartInstance->c5_BML2_address, &chartInstance->c5_BML2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BORED", (void **)
    &chartInstance->c5_BORED_address, &chartInstance->c5_BORED_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c5_BOREDOM_THRESHOLD_address,
    &chartInstance->c5_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "CONTEMPT", (void **)
    &chartInstance->c5_CONTEMPT_address, &chartInstance->c5_CONTEMPT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "EXCITE", (void **)
    &chartInstance->c5_EXCITE_address, &chartInstance->c5_EXCITE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FEAR", (void **)
    &chartInstance->c5_FEAR_address, &chartInstance->c5_FEAR_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FRUST", (void **)
    &chartInstance->c5_FRUST_address, &chartInstance->c5_FRUST_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_GUI", (void **)
    &chartInstance->c5_GAZE_GUI_address, &chartInstance->c5_GAZE_GUI_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_SOFTEYE", (void **)
    &chartInstance->c5_GAZE_SOFTEYE_address,
    &chartInstance->c5_GAZE_SOFTEYE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_USER_HAND", (void **)
    &chartInstance->c5_GAZE_USER_HAND_address,
    &chartInstance->c5_GAZE_USER_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c5_GAZE_WIN_address, &chartInstance->c5_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "HAPPY", (void **)
    &chartInstance->c5_HAPPY_address, &chartInstance->c5_HAPPY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "IDLE", (void **)
    &chartInstance->c5_IDLE_address, &chartInstance->c5_IDLE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c5_P_address, &chartInstance->c5_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "SAD", (void **)
    &chartInstance->c5_SAD_address, &chartInstance->c5_SAD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c5_STATE_BEFORE_address,
    &chartInstance->c5_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c5_STATE_GO_address, &chartInstance->c5_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_HAND", (void **)
    &chartInstance->c5_STATE_HAND_address, &chartInstance->c5_STATE_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c5_STATE_OVER_address, &chartInstance->c5_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c5_STATE_READY_address, &chartInstance->c5_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_RESULT", (void **)
    &chartInstance->c5_STATE_RESULT_address,
    &chartInstance->c5_STATE_RESULT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_WAIT", (void **)
    &chartInstance->c5_STATE_WAIT_address, &chartInstance->c5_STATE_WAIT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c5_avert_address, &chartInstance->c5_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avertH", (void **)
    &chartInstance->c5_avertH_address, &chartInstance->c5_avertH_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c5_bHand_address, &chartInstance->c5_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsH", (void **)
    &chartInstance->c5_bmlsH_address, &chartInstance->c5_bmlsH_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c5_bmlsL_address, &chartInstance->c5_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c5_boredom_address, &chartInstance->c5_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c5_diff_address, &chartInstance->c5_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c5_fileID_address, &chartInstance->c5_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c5_gazing_address, &chartInstance->c5_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "n", (void **)
    &chartInstance->c5_n_address, &chartInstance->c5_n_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pa", (void **)
    &chartInstance->c5_pa_address, &chartInstance->c5_pa_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pr", (void **)
    &chartInstance->c5_pr_address, &chartInstance->c5_pr_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c5_r_address, &chartInstance->c5_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randAvertGazeChance", (void **)
    &chartInstance->c5_randAvertGazeChance_address,
    &chartInstance->c5_randAvertGazeChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c5_randPoseChance_address,
    &chartInstance->c5_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSmile", (void **)
    &chartInstance->c5_randSmile_address, &chartInstance->c5_randSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c5_s_address, &chartInstance->c5_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "t", (void **)
    &chartInstance->c5_t_address, &chartInstance->c5_t_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c5_temp_address, &chartInstance->c5_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c5_uHand_address, &chartInstance->c5_uHand_index);
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

void sf_c5_Expriment_Gaze_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3609980694U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(602400227U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(543283212U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1377734385U);
}

mxArray *sf_c5_Expriment_Gaze_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WdToWhQ1o1aRqVKbPAqsMH");
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
      pr[1] = (double)(25);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_Expriment_Gaze_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_Expriment_Gaze_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_Expriment_Gaze(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[114],T\"bWinT\",},{M[1],M[107],T\"bradHand\",},{M[1],M[105],T\"gameState\",},{M[1],M[148],T\"round\",},{M[1],M[115],T\"uWinT\",},{M[1],M[108],T\"userHand\",},{M[1],M[109],T\"win\",},{M[3],M[177],T\"newBmlsH\",},{M[3],M[180],T\"newBmlsL\",},{M[8],M[0],T\"is_active_c5_Expriment_Gaze\",}}",
    "100 S1x9'type','srcId','name','auxInfo'{{M[8],M[2],T\"is_active_stateGame\",},{M[8],M[43],T\"is_active_statePlayHand\",},{M[8],M[65],T\"is_active_stateGameOver\",},{M[9],M[2],T\"is_stateGame\",},{M[9],M[43],T\"is_statePlayHand\",},{M[9],M[65],T\"is_stateGameOver\",},{M[11],M[149],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[79],M[1]}}},{M[11],M[149],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M1x3[63 61 64],M[1]}}},{M[11],M[149],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x7[28 186 29 42 168 32 33],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 19, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Expriment_Gaze_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Expriment_GazeInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_Expriment_GazeInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_GazeMachineNumber_,
           5,
           38,
           44,
           0,
           79,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_GazeMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_GazeMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_GazeMachineNumber_,
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
          _SFD_SET_DATA_PROPS(16,11,0,0,"r");
          _SFD_SET_DATA_PROPS(17,11,0,0,"pa");
          _SFD_SET_DATA_PROPS(18,11,0,0,"s");
          _SFD_SET_DATA_PROPS(19,11,0,0,"P");
          _SFD_SET_DATA_PROPS(20,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(21,11,0,0,"GAZE_GUI");
          _SFD_SET_DATA_PROPS(22,11,0,0,"GAZE_SOFTEYE");
          _SFD_SET_DATA_PROPS(23,11,0,0,"GAZE_USER_HAND");
          _SFD_SET_DATA_PROPS(24,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(25,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(26,11,0,0,"STATE_HAND");
          _SFD_SET_DATA_PROPS(27,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(28,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(29,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(30,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(31,11,0,0,"STATE_RESULT");
          _SFD_SET_DATA_PROPS(32,11,0,0,"STATE_WAIT");
          _SFD_SET_DATA_PROPS(33,11,0,0,"HAPPY");
          _SFD_SET_DATA_PROPS(34,11,0,0,"SAD");
          _SFD_SET_DATA_PROPS(35,11,0,0,"CONTEMPT");
          _SFD_SET_DATA_PROPS(36,11,0,0,"BORED");
          _SFD_SET_DATA_PROPS(37,11,0,0,"FRUST");
          _SFD_SET_DATA_PROPS(38,11,0,0,"FEAR");
          _SFD_SET_DATA_PROPS(39,11,0,0,"IDLE");
          _SFD_SET_DATA_PROPS(40,11,0,0,"EXCITE");
          _SFD_SET_DATA_PROPS(41,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(42,11,0,0,"pr");
          _SFD_SET_DATA_PROPS(43,2,0,1,"round");
          _SFD_SET_DATA_PROPS(44,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(45,11,0,0,"BML2");
          _SFD_SET_DATA_PROPS(46,11,0,0,"t");
          _SFD_SET_DATA_PROPS(47,11,0,0,"bmlsH");
          _SFD_SET_DATA_PROPS(48,0,0,0,"newBmlsH");
          _SFD_SET_DATA_PROPS(49,11,0,0,"n");
          _SFD_SET_DATA_PROPS(50,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(51,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(52,1,1,0,"randArray");
          _SFD_SET_DATA_PROPS(53,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(54,11,0,0,"avertH");
          _SFD_SET_DATA_PROPS(55,8,0,0,"");
          _SFD_SET_DATA_PROPS(56,8,0,0,"");
          _SFD_SET_DATA_PROPS(57,9,0,0,"");
          _SFD_SET_DATA_PROPS(58,8,0,0,"");
          _SFD_SET_DATA_PROPS(59,8,0,0,"");
          _SFD_SET_DATA_PROPS(60,9,0,0,"");
          _SFD_SET_DATA_PROPS(61,8,0,0,"");
          _SFD_SET_DATA_PROPS(62,9,0,0,"");
          _SFD_SET_DATA_PROPS(63,8,0,0,"");
          _SFD_SET_DATA_PROPS(64,9,0,0,"");
          _SFD_SET_DATA_PROPS(65,9,0,0,"");
          _SFD_SET_DATA_PROPS(66,8,0,0,"");
          _SFD_SET_DATA_PROPS(67,9,0,0,"");
          _SFD_SET_DATA_PROPS(68,9,0,0,"");
          _SFD_SET_DATA_PROPS(69,8,0,0,"");
          _SFD_SET_DATA_PROPS(70,9,0,0,"");
          _SFD_SET_DATA_PROPS(71,8,0,0,"");
          _SFD_SET_DATA_PROPS(72,9,0,0,"");
          _SFD_SET_DATA_PROPS(73,9,0,0,"");
          _SFD_SET_DATA_PROPS(74,8,0,0,"");
          _SFD_SET_DATA_PROPS(75,9,0,0,"");
          _SFD_SET_DATA_PROPS(76,9,0,0,"");
          _SFD_SET_DATA_PROPS(77,8,0,0,"");
          _SFD_SET_DATA_PROPS(78,9,0,0,"");
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
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,1);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,0,1);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(6,0,2);
          _SFD_STATE_INFO(7,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,9);
          _SFD_CH_SUBSTATE_INDEX(1,32);
          _SFD_CH_SUBSTATE_INDEX(2,27);
          _SFD_ST_SUBSTATE_COUNT(9,17);
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
          _SFD_ST_SUBSTATE_INDEX(9,13,23);
          _SFD_ST_SUBSTATE_INDEX(9,14,24);
          _SFD_ST_SUBSTATE_INDEX(9,15,25);
          _SFD_ST_SUBSTATE_INDEX(9,16,26);
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
          _SFD_ST_SUBSTATE_COUNT(32,5);
          _SFD_ST_SUBSTATE_INDEX(32,0,33);
          _SFD_ST_SUBSTATE_INDEX(32,1,34);
          _SFD_ST_SUBSTATE_INDEX(32,2,35);
          _SFD_ST_SUBSTATE_INDEX(32,3,36);
          _SFD_ST_SUBSTATE_INDEX(32,4,37);
          _SFD_ST_SUBSTATE_COUNT(33,0);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(27,4);
          _SFD_ST_SUBSTATE_INDEX(27,0,28);
          _SFD_ST_SUBSTATE_INDEX(27,1,29);
          _SFD_ST_SUBSTATE_INDEX(27,2,30);
          _SFD_ST_SUBSTATE_INDEX(27,3,31);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(31,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(9,17,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(27,4,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(32,5,1,1,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
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
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"insertQueuec5_Expriment_Gaze",0,-1,590);
        _SFD_CV_INIT_EML_IF(3,1,0,149,178,-1,-2);
        _SFD_CV_INIT_EML_IF(3,1,1,322,333,-1,571);
        _SFD_CV_INIT_EML_FOR(3,1,0,129,141,317);
        _SFD_CV_INIT_EML(4,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"insertQueueLowc5_Expriment_Gaze",0,-1,597);
        _SFD_CV_INIT_EML_IF(4,1,0,153,182,-1,-2);
        _SFD_CV_INIT_EML_IF(4,1,1,327,338,-1,578);
        _SFD_CV_INIT_EML_FOR(4,1,0,133,145,322);
        _SFD_CV_INIT_EML(6,1,5,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"rockPoseTablec5_Expriment_Gaze",0,-1,562);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",562,-1,779);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",779,-1,997);
        _SFD_CV_INIT_EML_FCN(6,3,"aFcnTruthTableAction_3",997,-1,1169);
        _SFD_CV_INIT_EML_FCN(6,4,"aFcnTruthTableAction_4",1169,-1,1338);
        _SFD_CV_INIT_EML_IF(6,1,0,321,351,382,560);
        _SFD_CV_INIT_EML_IF(6,1,1,382,416,447,560);
        _SFD_CV_INIT_EML_IF(6,1,2,447,481,512,560);
        _SFD_CV_INIT_EML(5,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"paperPoseBradTablec5_Expriment_Gaze",0,-1,571);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",571,-1,771);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",771,-1,970);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",970,-1,1146);
        _SFD_CV_INIT_EML_IF(5,1,0,330,360,391,569);
        _SFD_CV_INIT_EML_IF(5,1,1,391,425,456,569);
        _SFD_CV_INIT_EML_IF(5,1,2,456,490,521,569);
        _SFD_CV_INIT_EML(7,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"scissorsPoseBradTablec5_Expriment_Gaze",0,-1,
                             583);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",583,-1,745);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",745,-1,910);
        _SFD_CV_INIT_EML_FCN(7,3,"aFcnTruthTableAction_3",910,-1,1092);
        _SFD_CV_INIT_EML_IF(7,1,0,342,372,403,581);
        _SFD_CV_INIT_EML_IF(7,1,1,403,437,468,581);
        _SFD_CV_INIT_EML_IF(7,1,2,468,502,533,581);
        _SFD_CV_INIT_EML(0,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"handPoseSBTablec5_Expriment_Gaze",0,-1,759);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",759,-1,995);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",995,-1,1229);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1229,-1,1401);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1401,-1,1569);
        _SFD_CV_INIT_EML_IF(0,1,0,453,483,514,757);
        _SFD_CV_INIT_EML_IF(0,1,1,514,548,579,757);
        _SFD_CV_INIT_EML_IF(0,1,2,579,613,644,757);
        _SFD_CV_INIT_EML_IF(0,1,3,644,678,709,757);
        _SFD_CV_INIT_EML(1,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"idlePoseBradTablec5_Expriment_Gaze",0,-1,2816);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",2816,-1,2992);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",2992,-1,3159);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",3159,-1,3331);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",3331,-1,3505);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",3505,-1,3679);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",3679,-1,3865);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",3865,-1,4049);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",4049,-1,4223);
        _SFD_CV_INIT_EML_FCN(1,9,"aFcnTruthTableAction_9",4223,-1,4395);
        _SFD_CV_INIT_EML_FCN(1,10,"aFcnTruthTableAction_10",4395,-1,4569);
        _SFD_CV_INIT_EML_FCN(1,11,"aFcnTruthTableAction_11",4569,-1,4740);
        _SFD_CV_INIT_EML_IF(1,1,0,1588,1618,1649,2814);
        _SFD_CV_INIT_EML_IF(1,1,1,1649,1683,1714,2814);
        _SFD_CV_INIT_EML_IF(1,1,2,1714,1748,1779,2814);
        _SFD_CV_INIT_EML_IF(1,1,3,1779,1813,1844,2814);
        _SFD_CV_INIT_EML_IF(1,1,4,1844,1878,1909,2814);
        _SFD_CV_INIT_EML_IF(1,1,5,1909,1943,1975,2814);
        _SFD_CV_INIT_EML_IF(1,1,6,1975,2009,2040,2814);
        _SFD_CV_INIT_EML_IF(1,1,7,2040,2074,2105,2814);
        _SFD_CV_INIT_EML_IF(1,1,8,2105,2139,2170,2814);
        _SFD_CV_INIT_EML_IF(1,1,9,2170,2205,2237,2814);
        _SFD_CV_INIT_EML_IF(1,1,10,2237,2272,2304,2814);
        _SFD_CV_INIT_EML_IF(1,1,11,2304,2339,2370,2814);
        _SFD_CV_INIT_EML_IF(1,1,12,2370,2405,2436,2814);
        _SFD_CV_INIT_EML_IF(1,1,13,2436,2471,2502,2814);
        _SFD_CV_INIT_EML_IF(1,1,14,2502,2537,2568,2814);
        _SFD_CV_INIT_EML_IF(1,1,15,2568,2603,2634,2814);
        _SFD_CV_INIT_EML_IF(1,1,16,2634,2669,2700,2814);
        _SFD_CV_INIT_EML_IF(1,1,17,2700,2735,2766,2814);
        _SFD_CV_INIT_EML(2,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"initialPoseTablec5_Expriment_Gaze",0,-1,690);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",690,-1,839);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",839,-1,1009);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1009,-1,1179);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1179,-1,1391);
        _SFD_CV_INIT_EML_IF(2,1,0,384,414,445,688);
        _SFD_CV_INIT_EML_IF(2,1,1,445,479,510,688);
        _SFD_CV_INIT_EML_IF(2,1,2,510,544,575,688);
        _SFD_CV_INIT_EML_IF(2,1,3,575,609,640,688);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(20,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(39,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(40,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(40,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(41,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(41,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(37,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(38,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,8,1,8);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(12,0,0,1,19,1,19);

        {
          static int condStart[] = { 1, 12 };

          static int condEnd[] = { 8, 19 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,1,19,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,20,1,20);
        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,9,1,9);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(29,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(30,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(34,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(34,0,0,0,43,0,43);

        {
          static int condStart[] = { 0, 16 };

          static int condEnd[] = { 15, 43 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(34,0,0,0,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 25;
          _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_ub_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_vb_sf_marshallOut,(MexInFcnForType)
            c5_i_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

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

        {
          real_T *c5_gameState;
          real_T *c5_inputUser;
          real_T *c5_bradHand;
          real_T *c5_userHand;
          real_T *c5_win;
          real_T *c5_bWinT;
          real_T *c5_uWinT;
          real_T *c5_round;
          real_T *c5_personality;
          real_T (*c5_randArray)[25];
          c5_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_randArray = (real_T (*)[25])ssGetInputPortSignal(chartInstance->S,
            1);
          c5_round = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c5_uWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c5_bWinT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c5_win = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c5_userHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_bradHand = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_inputUser = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_gameState);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_inputUser);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_bradHand);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_userHand);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_win);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c5_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c5_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c5_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c5_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c5_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c5_randSmile_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c5_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(13U,
            chartInstance->c5_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(14U,
            chartInstance->c5_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c5_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c5_r_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c5_pa_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c5_s_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c5_P_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c5_avert_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c5_GAZE_GUI_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c5_GAZE_SOFTEYE_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c5_GAZE_USER_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c5_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c5_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c5_STATE_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c5_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c5_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c5_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c5_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c5_STATE_RESULT_address);
          _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c5_STATE_WAIT_address);
          _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c5_HAPPY_address);
          _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c5_SAD_address);
          _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c5_CONTEMPT_address);
          _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c5_BORED_address);
          _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c5_FRUST_address);
          _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c5_FEAR_address);
          _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c5_IDLE_address);
          _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c5_EXCITE_address);
          _SFD_SET_DATA_VALUE_PTR(41U, *chartInstance->c5_BML_address);
          _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c5_pr_address);
          _SFD_SET_DATA_VALUE_PTR(43U, c5_round);
          _SFD_SET_DATA_VALUE_PTR(44U, chartInstance->c5_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(45U, *chartInstance->c5_BML2_address);
          _SFD_SET_DATA_VALUE_PTR(46U, chartInstance->c5_t_address);
          _SFD_SET_DATA_VALUE_PTR(47U, *chartInstance->c5_bmlsH_address);
          _SFD_SET_DATA_VALUE_PTR(48U, chartInstance->c5_newBmlsH);
          _SFD_SET_DATA_VALUE_PTR(49U, *chartInstance->c5_n_address);
          _SFD_SET_DATA_VALUE_PTR(50U, *chartInstance->c5_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(51U, chartInstance->c5_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(52U, *c5_randArray);
          _SFD_SET_DATA_VALUE_PTR(53U, c5_personality);
          _SFD_SET_DATA_VALUE_PTR(54U, chartInstance->c5_avertH_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_GazeMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "9r6dOo1C7vSvBUqRkGsLYG";
}

static void sf_opaque_initialize_c5_Expriment_Gaze(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
  initialize_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_Expriment_Gaze(void *chartInstanceVar)
{
  enable_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_Expriment_Gaze(void *chartInstanceVar)
{
  disable_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_Expriment_Gaze(void *chartInstanceVar)
{
  sf_gateway_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Expriment_Gaze(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Expriment_Gaze
    ((SFc5_Expriment_GazeInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Expriment_Gaze();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_Expriment_Gaze();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Expriment_Gaze(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c5_Expriment_Gaze(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c5_Expriment_Gaze(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Expriment_GazeInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Gaze_optimization_info();
    }

    finalize_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
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
  initSimStructsc5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Expriment_Gaze(SimStruct *S)
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
    initialize_params_c5_Expriment_Gaze((SFc5_Expriment_GazeInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Gaze_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,5,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,8);
    }

    ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(224397803U));
  ssSetChecksum1(S,(3727700987U));
  ssSetChecksum2(S,(2395587348U));
  ssSetChecksum3(S,(321101559U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Expriment_Gaze(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c5_Expriment_Gaze(SimStruct *S)
{
  SFc5_Expriment_GazeInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_Expriment_GazeInstanceStruct *)utMalloc(sizeof
    (SFc5_Expriment_GazeInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Expriment_GazeInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Expriment_Gaze;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_Expriment_Gaze;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_Expriment_Gaze;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Expriment_Gaze;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Expriment_Gaze;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Expriment_Gaze;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Expriment_Gaze;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Expriment_Gaze;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Expriment_Gaze;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Expriment_Gaze;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Expriment_Gaze;
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

void c5_Expriment_Gaze_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Expriment_Gaze(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Expriment_Gaze(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Expriment_Gaze_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
