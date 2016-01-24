/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_sfun.h"
#include "c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c9_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_stateAvertGaze           ((uint8_T)1U)
#define c9_IN_stateAvertHead           ((uint8_T)2U)
#define c9_IN_stateGazingGUI           ((uint8_T)3U)
#define c9_IN_stateGazingUserHand      ((uint8_T)4U)
#define c9_IN_stateHeadNeutral         ((uint8_T)5U)
#define c9_IN_stateInit                ((uint8_T)6U)
#define c9_IN_stateRandGenerate        ((uint8_T)7U)
#define c9_IN_stateBrowUp              ((uint8_T)1U)
#define c9_b_IN_stateInit              ((uint8_T)2U)
#define c9_IN_stateNeckBack            ((uint8_T)3U)
#define c9_IN_stateWinSmile            ((uint8_T)4U)
#define c9_IN_stateGazeSoftEye         ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[27] = { "aVarTruthTableCondition_1",
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
  "nargout", "bmlID", "gazeBML" };

static const char * c9_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

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

static const char * c9_y_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c9_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

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

static const char * c9_ib_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c9_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_mb_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "gazeBML" };

static const char * c9_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c9_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_jc_debug_family_names[2] = { "nargin", "nargout" };

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

static boolean_T c9_dataWrittenToVector[7];

/* Function Declarations */
static void initialize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  initialize_params_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void enable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void disable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_update_debugger_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_ARP_02_RPSsmile_GAZEKinectGlove
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void finalize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void sf_gateway_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_enter_atomic_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_enter_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_exit_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_initc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  initSimStructsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_stateGazeIde
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_enter_atomic_stateRandGenerate
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_stateRandGenerate
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_stateGazeWin
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_b_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_c_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_d_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_e_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_f_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_g_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_h_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_i_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_j_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_k_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_l_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_m_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_n_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_o_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_p_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_q_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_r_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_s_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_t_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_u_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_v_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_w_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_x_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_y_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_ab_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_bb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_cb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_db_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_eb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_fb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_gb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_hb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static void c9_ib_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256]);
static real_T c9_rand
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static real_T c9_eml_rand
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625]);
static void c9_twister_state_vector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_mt[625], real_T c9_seed, uint32_T c9_b_mt[625]);
static void c9_b_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625], uint32_T c9_e_state[625], real_T
   *c9_r);
static void c9_eml_error
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static real_T c9_randi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   real_T c9_y[256]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_b_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_bmlID, const char_T *c9_identifier);
static real_T c9_c_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_d_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_activate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_deactivate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_increment_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_reset_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_sendBMLc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_arg[256]);
static void c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256]);
static void c9_idleGazeInterestedTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256]);
static void c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_poseBML[256]);
static void c9_gazeFollowUserMovec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBra
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256]);
static void c9_sendBML
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c9_b_sendBML
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static const mxArray *c9_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int8_T c9_f_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_g_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_tp_stateGazeIde, const char_T
   *c9_identifier);
static uint8_T c9_i_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint32_T c9_j_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_method, const char_T *c9_identifier);
static uint32_T c9_k_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static uint32_T c9_l_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier);
static uint32_T c9_m_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_n_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
   uint32_T c9_y[625]);
static void c9_o_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   uint32_T c9_y[625]);
static void c9_p_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
   uint32_T c9_y[2]);
static void c9_q_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   uint32_T c9_y[2]);
static uint32_T c9_r_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
   *c9_identifier);
static uint32_T c9_s_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_t_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T *
   c9_identifier);
static const mxArray *c9_u_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber);
static void c9_b_twister_state_vector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_mt[625], real_T c9_seed);
static real_T c9_c_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625]);
static real_T c9_get_BOREDOM_THRESHOLD
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_BOREDOM_THRESHOLD
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static real_T c9_get_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void c9_set_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c);
static real_T *c9_access_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b);
static void init_dsm_address_info
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void
  initialize_params_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void disable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_debugger_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitate
      == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeIde == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateRandGenerate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertGaze) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHead) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingGUI) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingUserHand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeWin == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_b_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateWinSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateNeckBack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeWin == c9_IN_stateBrowUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_active_stateGazeSoft == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeSoft == c9_b_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_stateGazeSoft == c9_IN_stateGazeSoftEye) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray
  *get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
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
  uint32_T c9_d_hoistedGlobal;
  uint32_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  uint32_T c9_e_hoistedGlobal;
  uint32_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  int32_T c9_i0;
  uint32_T c9_f_u[625];
  const mxArray *c9_g_y = NULL;
  int32_T c9_i1;
  uint32_T c9_g_u[2];
  const mxArray *c9_h_y = NULL;
  uint8_T c9_f_hoistedGlobal;
  uint8_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  uint8_T c9_g_hoistedGlobal;
  uint8_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  uint8_T c9_h_hoistedGlobal;
  uint8_T c9_j_u;
  const mxArray *c9_k_y = NULL;
  uint8_T c9_i_hoistedGlobal;
  uint8_T c9_k_u;
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
  uint8_T c9_m_hoistedGlobal;
  uint8_T c9_o_u;
  const mxArray *c9_p_y = NULL;
  uint8_T c9_n_hoistedGlobal;
  uint8_T c9_p_u;
  const mxArray *c9_q_y = NULL;
  uint32_T c9_o_hoistedGlobal;
  uint32_T c9_q_u;
  const mxArray *c9_r_y = NULL;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(17, 1), false);
  c9_hoistedGlobal = *c9_gameState;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = chartInstance->c9_randHeadDur;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = chartInstance->c9_randHeadDurOver;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = chartInstance->c9_method;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  if (!chartInstance->c9_method_not_empty) {
    sf_mex_assign(&c9_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = chartInstance->c9_state;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  if (!chartInstance->c9_state_not_empty) {
    sf_mex_assign(&c9_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c9_y, 4, c9_f_y);
  for (c9_i0 = 0; c9_i0 < 625; c9_i0++) {
    c9_f_u[c9_i0] = chartInstance->c9_c_state[c9_i0];
  }

  c9_g_y = NULL;
  if (!chartInstance->c9_c_state_not_empty) {
    sf_mex_assign(&c9_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_f_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c9_y, 5, c9_g_y);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_g_u[c9_i1] = chartInstance->c9_b_state[c9_i1];
  }

  c9_h_y = NULL;
  if (!chartInstance->c9_b_state_not_empty) {
    sf_mex_assign(&c9_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_g_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_f_hoistedGlobal =
    chartInstance->c9_is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitate;
  c9_h_u = c9_f_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_g_hoistedGlobal = chartInstance->c9_is_active_stateGazeIde;
  c9_i_u = c9_g_hoistedGlobal;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  c9_h_hoistedGlobal = chartInstance->c9_is_active_stateGazeWin;
  c9_j_u = c9_h_hoistedGlobal;
  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", &c9_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 9, c9_k_y);
  c9_i_hoistedGlobal = chartInstance->c9_is_active_stateGazeSoft;
  c9_k_u = c9_i_hoistedGlobal;
  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", &c9_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 10, c9_l_y);
  c9_j_hoistedGlobal = chartInstance->c9_is_stateGazeIde;
  c9_l_u = c9_j_hoistedGlobal;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 11, c9_m_y);
  c9_k_hoistedGlobal = chartInstance->c9_is_stateGazeWin;
  c9_m_u = c9_k_hoistedGlobal;
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 12, c9_n_y);
  c9_l_hoistedGlobal = chartInstance->c9_is_stateGazeSoft;
  c9_n_u = c9_l_hoistedGlobal;
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", &c9_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 13, c9_o_y);
  c9_m_hoistedGlobal = chartInstance->c9_temporalCounter_i3;
  c9_o_u = c9_m_hoistedGlobal;
  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_create("y", &c9_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 14, c9_p_y);
  c9_n_hoistedGlobal = chartInstance->c9_temporalCounter_i2;
  c9_p_u = c9_n_hoistedGlobal;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 15, c9_q_y);
  c9_o_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_q_u = c9_o_hoistedGlobal;
  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", &c9_q_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 16, c9_r_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void
  set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  uint32_T c9_uv0[625];
  int32_T c9_i2;
  uint32_T c9_uv1[2];
  int32_T c9_i3;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_gameState = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "gameState");
  chartInstance->c9_randHeadDur = c9_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 1)), "randHeadDur");
  chartInstance->c9_randHeadDurOver = c9_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 2)), "randHeadDurOver");
  chartInstance->c9_method = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 3)), "method");
  chartInstance->c9_state = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 4)), "state");
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 5)),
                        "state", c9_uv0);
  for (c9_i2 = 0; c9_i2 < 625; c9_i2++) {
    chartInstance->c9_c_state[c9_i2] = c9_uv0[c9_i2];
  }

  c9_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 6)),
                        "state", c9_uv1);
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    chartInstance->c9_b_state[c9_i3] = c9_uv1[c9_i3];
  }

  chartInstance->c9_is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitate
    = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 7)),
    "is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile");
  chartInstance->c9_is_active_stateGazeIde = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 8)), "is_active_stateGazeIde");
  chartInstance->c9_is_active_stateGazeWin = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 9)), "is_active_stateGazeWin");
  chartInstance->c9_is_active_stateGazeSoft = c9_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 10)),
     "is_active_stateGazeSoft");
  chartInstance->c9_is_stateGazeIde = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 11)), "is_stateGazeIde");
  chartInstance->c9_is_stateGazeWin = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 12)), "is_stateGazeWin");
  chartInstance->c9_is_stateGazeSoft = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 13)), "is_stateGazeSoft");
  chartInstance->c9_temporalCounter_i3 = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 14)), "temporalCounter_i3");
  chartInstance->c9_temporalCounter_i2 = c9_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 15)), "temporalCounter_i2");
  chartInstance->c9_temporalCounter_i1 = c9_r_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 16)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 17)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomi(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_ARP_02_RPSsmile_GAZEKinectGlove
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_active_stateGazeIde == 1U) {
      chartInstance->c9_tp_stateGazeIde = 1U;
    } else {
      chartInstance->c9_tp_stateGazeIde = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertGaze) {
      chartInstance->c9_tp_stateAvertGaze = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertGaze = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateAvertHead) {
      chartInstance->c9_tp_stateAvertHead = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateAvertHead = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingGUI) {
      chartInstance->c9_tp_stateGazingGUI = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGazingGUI = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateGazingUserHand) {
      chartInstance->c9_tp_stateGazingUserHand = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateGazingUserHand = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateHeadNeutral) {
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateInit) {
      chartInstance->c9_tp_stateInit = 1U;
    } else {
      chartInstance->c9_tp_stateInit = 0U;
    }

    if (chartInstance->c9_is_stateGazeIde == c9_IN_stateRandGenerate) {
      chartInstance->c9_tp_stateRandGenerate = 1U;
    } else {
      chartInstance->c9_tp_stateRandGenerate = 0U;
    }

    if (chartInstance->c9_is_active_stateGazeWin == 1U) {
      chartInstance->c9_tp_stateGazeWin = 1U;
    } else {
      chartInstance->c9_tp_stateGazeWin = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_IN_stateBrowUp) {
      chartInstance->c9_tp_stateBrowUp = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c9_temporalCounter_i2 = 0U;
      }
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
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        chartInstance->c9_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c9_tp_stateNeckBack = 0U;
    }

    if (chartInstance->c9_is_stateGazeWin == c9_IN_stateWinSmile) {
      chartInstance->c9_tp_stateWinSmile = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
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
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
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

static void finalize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  c9_set_sim_state_side_effects_c9_ARP_02_RPSsmile_GAZEKinectGlove(chartInstance);
}

static void c9_enter_atomic_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitate
    = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_enter_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T *c9_gameState;
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeIde = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeIde = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeIde = c9_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_qb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  *c9_gameState = 4.0;
  c9_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_gameState, 14U);
  c9_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  c9_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 5);
  c9_set_STATE_READY(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c9_set_GAZE_GUI(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  c9_set_GAZE_SHOFTEYE(chartInstance, 0, 2.0);
  ssUpdateDataStoreLog(chartInstance->S, 2);
  c9_set_GAZE_USER_HAND(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 3);
  c9_set_GAZE_WIN(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 4);
  c9_set_interest(chartInstance, 0, c9_get_BOREDOM_THRESHOLD(chartInstance, 0) -
                  c9_get_boredom(chartInstance, 0));
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c9_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 8);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeWin = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeWin = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeWin = c9_b_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
  chartInstance->c9_b_tp_stateInit = 1U;
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_active_stateGazeSoft = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  chartInstance->c9_tp_stateGazeSoft = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
  chartInstance->c9_isStable = false;
  chartInstance->c9_is_stateGazeSoft = c9_b_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
  chartInstance->c9_c_tp_stateInit = 1U;
}

static void c9_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  real_T c9_dv0[256];
  int32_T c9_i4;
  real_T c9_arg[256];
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_isStable = true;
  c9_stateGazeIde(chartInstance);
  c9_stateGazeWin(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeSoft) {
   case c9_IN_stateGazeSoftEye:
    CV_STATE_EVAL(12, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_vc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_out = CV_EML_IF(12, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                       (chartInstance->c9_temporalCounter_i3 >= 3));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateGazeSoftEye = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeSoft = c9_b_IN_stateInit;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_c_tp_stateInit = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(12, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_wc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(11, 0, 0, c9_get_gazing(chartInstance, 0) ==
                         c9_get_GAZE_SHOFTEYE(chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_c_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeSoft = c9_IN_stateGazeSoftEye;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i3 = 0U;
      chartInstance->c9_tp_stateGazeSoftEye = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_bc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 19.0, c9_dv0);
      for (c9_i4 = 0; c9_i4 < 256; c9_i4++) {
        c9_arg[c9_i4] = c9_dv0[c9_i4];
      }

      for (c9_i5 = 0; c9_i5 < 256; c9_i5++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i5], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i6 = 0; c9_i6 < 256; c9_i6++) {
        (*c9_b_arg)[c9_i6] = c9_arg[c9_i6];
      }

      for (c9_i7 = 0; c9_i7 < 256; c9_i7++) {
        _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i7], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 0, 0);
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c9_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
}

static void c9_exit_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  switch (chartInstance->c9_is_stateGazeSoft) {
   case c9_IN_stateGazeSoftEye:
    CV_STATE_EVAL(12, 1, 1);
    chartInstance->c9_tp_stateGazeSoftEye = 0U;
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(12, 1, 2);
    chartInstance->c9_c_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 1, 0);
    chartInstance->c9_is_stateGazeSoft = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeSoft = 0U;
  chartInstance->c9_is_active_stateGazeSoft = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeWin) {
   case c9_IN_stateBrowUp:
    CV_STATE_EVAL(15, 1, 1);
    chartInstance->c9_tp_stateBrowUp = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(15, 1, 2);
    chartInstance->c9_b_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNeckBack:
    CV_STATE_EVAL(15, 1, 3);
    chartInstance->c9_tp_stateNeckBack = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateWinSmile:
    CV_STATE_EVAL(15, 1, 4);
    chartInstance->c9_tp_stateWinSmile = 0U;
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(15, 1, 0);
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeWin = 0U;
  chartInstance->c9_is_active_stateGazeWin = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeIde) {
   case c9_IN_stateAvertGaze:
    CV_STATE_EVAL(4, 1, 1);
    chartInstance->c9_tp_stateAvertGaze = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHead:
    CV_STATE_EVAL(4, 1, 2);
    chartInstance->c9_tp_stateAvertHead = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingGUI:
    CV_STATE_EVAL(4, 1, 3);
    chartInstance->c9_tp_stateGazingGUI = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingUserHand:
    CV_STATE_EVAL(4, 1, 4);
    chartInstance->c9_tp_stateGazingUserHand = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateHeadNeutral:
    CV_STATE_EVAL(4, 1, 5);
    chartInstance->c9_tp_stateHeadNeutral = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInit:
    CV_STATE_EVAL(4, 1, 6);
    chartInstance->c9_tp_stateInit = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateRandGenerate:
    CV_STATE_EVAL(4, 1, 7);
    chartInstance->c9_tp_stateRandGenerate = 0U;
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 1, 0);
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    break;
  }

  chartInstance->c9_tp_stateGazeIde = 0U;
  chartInstance->c9_is_active_stateGazeIde = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
}

static void c9_initc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  chartInstance->c9_tp_stateAvertGaze = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateAvertHead = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateGazingGUI = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateGazingUserHand = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateHeadNeutral = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_stateInit = 0U;
  chartInstance->c9_tp_stateRandGenerate = 0U;
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
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_b_tp_stateInit = 0U;
  chartInstance->c9_tp_stateNeckBack = 0U;
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_tp_stateWinSmile = 0U;
  chartInstance->c9_temporalCounter_i2 = 0U;
  chartInstance->c9_is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitate
    = 0U;
}

static void
  initSimStructsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c9_stateGazeIde
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  boolean_T c9_temp;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_dv1[256];
  int32_T c9_i8;
  real_T c9_arg[256];
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_c_out;
  boolean_T c9_b_temp;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 1.0;
  boolean_T c9_e_out;
  boolean_T c9_c_temp;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 0.0;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 0.0;
  real_T c9_dv2[256];
  int32_T c9_i12;
  real_T c9_b_arg[256];
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 1.0;
  boolean_T c9_f_out;
  real_T c9_k_nargin = 0.0;
  real_T c9_k_nargout = 0.0;
  real_T c9_l_nargin = 0.0;
  real_T c9_l_nargout = 0.0;
  real_T c9_dv3[256];
  int32_T c9_i16;
  real_T c9_c_arg[256];
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  real_T c9_m_nargin = 0.0;
  real_T c9_m_nargout = 1.0;
  boolean_T c9_g_out;
  real_T c9_n_nargin = 0.0;
  real_T c9_n_nargout = 0.0;
  real_T c9_o_nargin = 0.0;
  real_T c9_o_nargout = 0.0;
  real_T c9_dv4[256];
  int32_T c9_i20;
  real_T c9_d_arg[256];
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  real_T c9_p_nargin = 0.0;
  real_T c9_p_nargout = 1.0;
  boolean_T c9_h_out;
  real_T *c9_gameState;
  real_T (*c9_e_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c9_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeIde) {
   case c9_IN_stateAvertGaze:
    CV_STATE_EVAL(4, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_kc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_temp = (chartInstance->c9_sfEvent == c9_event_secs);
    if (c9_temp) {
      c9_temp = (chartInstance->c9_temporalCounter_i1 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)c9_get_randGazeDur
                  (chartInstance, 0), 32U, 1U));
    }

    c9_out = CV_EML_IF(1, 0, 0, c9_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_jc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c9_tp_stateAvertGaze = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 17.0, c9_dv1);
      for (c9_i8 = 0; c9_i8 < 256; c9_i8++) {
        c9_arg[c9_i8] = c9_dv1[c9_i8];
      }

      for (c9_i9 = 0; c9_i9 < 256; c9_i9++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i9], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i10 = 0; c9_i10 < 256; c9_i10++) {
        (*c9_e_arg)[c9_i10] = c9_arg[c9_i10];
      }

      for (c9_i11 = 0; c9_i11 < 256; c9_i11++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i11], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateAvertHead:
    CV_STATE_EVAL(4, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_qc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 14U);
    c9_b_out = CV_EML_IF(22, 0, 0, *c9_gameState == c9_get_STATE_OVER
                         (chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_mc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 13U);
      c9_b_temp = (chartInstance->c9_sfEvent == c9_event_secs);
      if (c9_b_temp) {
        c9_b_temp = (chartInstance->c9_temporalCounter_i1 >=
                     _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
          chartInstance->c9_randHeadDurOver, 32U, 23U));
      }

      c9_c_out = CV_EML_IF(23, 0, 0, c9_b_temp);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c9_sfEvent);
        guard1 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_pc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_errorIfDataNotWrittenToFcn(chartInstance, 2U, 14U);
      c9_d_out = CV_EML_IF(21, 0, 0, *c9_gameState != c9_get_STATE_OVER
                           (chartInstance, 0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_lc_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        c9_errorIfDataNotWrittenToFcn(chartInstance, 0U, 12U);
        c9_c_temp = (chartInstance->c9_sfEvent == c9_event_secs);
        if (c9_c_temp) {
          c9_c_temp = (chartInstance->c9_temporalCounter_i1 >=
                       _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
            chartInstance->c9_randHeadDur, 32U, 24U));
        }

        c9_e_out = CV_EML_IF(24, 0, 0, c9_c_temp);
        _SFD_SYMBOL_SCOPE_POP();
        if (c9_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c9_sfEvent);
          guard1 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }

    if (guard2 == true) {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c9_sfEvent);
    }

    if (guard1 == true) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_jc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c9_tp_stateAvertHead = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 17.0, c9_dv2);
      for (c9_i12 = 0; c9_i12 < 256; c9_i12++) {
        c9_b_arg[c9_i12] = c9_dv2[c9_i12];
      }

      for (c9_i13 = 0; c9_i13 < 256; c9_i13++) {
        _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i13], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i14 = 0; c9_i14 < 256; c9_i14++) {
        (*c9_e_arg)[c9_i14] = c9_b_arg[c9_i14];
      }

      for (c9_i15 = 0; c9_i15 < 256; c9_i15++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i15], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingGUI:
    CV_STATE_EVAL(4, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_oc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_f_out = CV_EML_IF(7, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 3U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_jc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_k_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c9_tp_stateGazingGUI = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_l_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_l_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 17.0, c9_dv3);
      for (c9_i16 = 0; c9_i16 < 256; c9_i16++) {
        c9_c_arg[c9_i16] = c9_dv3[c9_i16];
      }

      for (c9_i17 = 0; c9_i17 < 256; c9_i17++) {
        _SFD_DATA_RANGE_CHECK(c9_c_arg[c9_i17], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_c_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_c_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i18 = 0; c9_i18 < 256; c9_i18++) {
        (*c9_e_arg)[c9_i18] = c9_c_arg[c9_i18];
      }

      for (c9_i19 = 0; c9_i19 < 256; c9_i19++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i19], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateGazingUserHand:
    CV_STATE_EVAL(4, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_nc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_m_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_m_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_g_out = CV_EML_IF(10, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 2U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_jc_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_n_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_n_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 8);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c9_tp_stateGazingUserHand = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_sb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_o_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_o_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 17.0, c9_dv4);
      for (c9_i20 = 0; c9_i20 < 256; c9_i20++) {
        c9_d_arg[c9_i20] = c9_dv4[c9_i20];
      }

      for (c9_i21 = 0; c9_i21 < 256; c9_i21++) {
        _SFD_DATA_RANGE_CHECK(c9_d_arg[c9_i21], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_d_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_d_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i22 = 0; c9_i22 < 256; c9_i22++) {
        (*c9_e_arg)[c9_i22] = c9_d_arg[c9_i22];
      }

      for (c9_i23 = 0; c9_i23 < 256; c9_i23++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i23], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateHeadNeutral:
    CV_STATE_EVAL(4, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_cc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_h_out = CV_EML_IF(0, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_h_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGenerate;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandGenerate = 1U;
      c9_enter_atomic_stateRandGenerate(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateInit:
    CV_STATE_EVAL(4, 0, 6);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateInit = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGenerate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateRandGenerate = 1U;
    c9_enter_atomic_stateRandGenerate(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateRandGenerate:
    CV_STATE_EVAL(4, 0, 7);
    c9_stateRandGenerate(chartInstance);
    break;

   default:
    CV_STATE_EVAL(4, 0, 0);
    chartInstance->c9_is_stateGazeIde = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
}

static void c9_enter_atomic_stateRandGenerate
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_b_r;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_hoistedGlobal;
  real_T c9_lowhigh[2];
  real_T c9_low;
  real_T c9_high;
  int32_T c9_i24;
  static char_T c9_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c9_u[26];
  const mxArray *c9_y = NULL;
  real_T c9_s;
  real_T c9_c_r;
  real_T c9_e_x;
  real_T c9_f_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_rb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  c9_r = c9_rand(chartInstance);
  c9_x = c9_r * 10.0;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarFloor(c9_b_x);
  c9_r = 1.0 + c9_b_x;
  c9_set_randAvertGazeChance(chartInstance, 0, c9_r);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c9_set_randGazeDur(chartInstance, 0, c9_randi(chartInstance));
  ssUpdateDataStoreLog(chartInstance->S, 14);
  chartInstance->c9_randHeadDur = c9_randi(chartInstance);
  c9_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_randHeadDur, 12U);
  c9_b_r = c9_rand(chartInstance);
  c9_c_x = c9_b_r * 3.0;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarFloor(c9_d_x);
  c9_b_r = 5.0 + c9_d_x;
  chartInstance->c9_randHeadDurOver = c9_b_r;
  c9_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_randHeadDurOver, 13U);
  c9_hoistedGlobal = c9_get_interest(chartInstance, 0);
  c9_lowhigh[0] = 1.0;
  c9_lowhigh[1] = c9_hoistedGlobal;
  c9_low = c9_lowhigh[0];
  c9_high = c9_lowhigh[1];
  if (c9_low <= c9_high) {
  } else {
    for (c9_i24 = 0; c9_i24 < 26; c9_i24++) {
      c9_u[c9_i24] = c9_cv0[c9_i24];
    }

    c9_y = NULL;
    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c9_y));
  }

  c9_s = (c9_high - c9_low) + 1.0;
  c9_c_r = c9_rand(chartInstance);
  c9_e_x = c9_c_r * c9_s;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarFloor(c9_f_x);
  c9_c_r = c9_low + c9_f_x;
  c9_set_randPoseChance(chartInstance, 0, c9_c_r);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_stateRandGenerate
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  boolean_T c9_out;
  uint32_T c9_b_debug_family_var_map[2];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 0.0;
  real_T c9_dv5[256];
  int32_T c9_i25;
  real_T c9_arg[256];
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 0.0;
  real_T c9_dv6[256];
  int32_T c9_i29;
  real_T c9_b_arg[256];
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_dv7[256];
  int32_T c9_i33;
  real_T c9_c_arg[256];
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  real_T c9_h_nargin = 0.0;
  real_T c9_h_nargout = 1.0;
  boolean_T c9_e_out;
  real_T c9_i_nargin = 0.0;
  real_T c9_i_nargout = 0.0;
  real_T c9_b_r;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_dv8[256];
  int32_T c9_i37;
  real_T c9_d_arg[256];
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  real_T c9_j_nargin = 0.0;
  real_T c9_j_nargout = 1.0;
  boolean_T c9_f_out;
  real_T (*c9_e_arg)[256];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  c9_e_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ec_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  guard5 = false;
  if (CV_EML_COND(8, 0, 0, c9_get_randGazeDur(chartInstance, 0) > 1.0)) {
    if (CV_EML_COND(8, 0, 1, c9_get_gazing(chartInstance, 0) == c9_get_GAZE_GUI
                    (chartInstance, 0))) {
      CV_EML_MCDC(8, 0, 0, true);
      CV_EML_IF(8, 0, 0, true);
      c9_out = true;
    } else {
      guard5 = true;
    }
  } else {
    guard5 = true;
  }

  if (guard5 == true) {
    CV_EML_MCDC(8, 0, 0, false);
    CV_EML_IF(8, 0, 0, false);
    c9_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_stateRandGenerate = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
    chartInstance->c9_isStable = false;
    chartInstance->c9_is_stateGazeIde = c9_IN_stateGazingGUI;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c9_sfEvent);
    chartInstance->c9_temporalCounter_i1 = 0U;
    chartInstance->c9_tp_stateGazingGUI = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_vb_debug_family_names,
      c9_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
      (chartInstance, 22.0, c9_dv5);
    for (c9_i25 = 0; c9_i25 < 256; c9_i25++) {
      c9_arg[c9_i25] = c9_dv5[c9_i25];
    }

    for (c9_i26 = 0; c9_i26 < 256; c9_i26++) {
      _SFD_DATA_RANGE_CHECK(c9_arg[c9_i26], 19U);
    }

    _SFD_SET_DATA_VALUE_PTR(19U, c9_arg);
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
    _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    for (c9_i27 = 0; c9_i27 < 256; c9_i27++) {
      (*c9_e_arg)[c9_i27] = c9_arg[c9_i27];
    }

    for (c9_i28 = 0; c9_i28 < 256; c9_i28++) {
      _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i28], 19U);
    }

    sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_UNSET_DATA_VALUE_PTR(19U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_dc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    guard4 = false;
    if (CV_EML_COND(9, 0, 0, c9_get_randAvertGazeChance(chartInstance, 0) > 2.0))
    {
      if (CV_EML_COND(9, 0, 1, c9_get_gazing(chartInstance, 0) ==
                      c9_get_GAZE_USER_HAND(chartInstance, 0))) {
        CV_EML_MCDC(9, 0, 0, true);
        CV_EML_IF(9, 0, 0, true);
        c9_b_out = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(9, 0, 0, false);
      CV_EML_IF(9, 0, 0, false);
      c9_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateRandGenerate = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeIde = c9_IN_stateGazingUserHand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_stateGazingUserHand = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_wb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
        (chartInstance, 23.0, c9_dv6);
      for (c9_i29 = 0; c9_i29 < 256; c9_i29++) {
        c9_b_arg[c9_i29] = c9_dv6[c9_i29];
      }

      for (c9_i30 = 0; c9_i30 < 256; c9_i30++) {
        _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i30], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i31 = 0; c9_i31 < 256; c9_i31++) {
        (*c9_e_arg)[c9_i31] = c9_b_arg[c9_i31];
      }

      for (c9_i32 = 0; c9_i32 < 256; c9_i32++) {
        _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i32], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_fc_debug_family_names,
        c9_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
        c9_c_sf_marshallIn);
      c9_c_out = CV_EML_IF(3, 0, 0, c9_get_isPosing(chartInstance, 0) != 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateRandGenerate = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
        chartInstance->c9_isStable = false;
        chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGenerate;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_stateRandGenerate = 1U;
        c9_enter_atomic_stateRandGenerate(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c9_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_ic_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
          c9_c_sf_marshallIn);
        guard3 = false;
        if (CV_EML_COND(6, 0, 0, c9_get_randAvertGazeChance(chartInstance, 0) >
                        5.0)) {
          if (CV_EML_COND(6, 0, 1, c9_get_isPosing(chartInstance, 0) == 0.0)) {
            CV_EML_MCDC(6, 0, 0, true);
            CV_EML_IF(6, 0, 0, true);
            c9_d_out = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }

        if (guard3 == true) {
          CV_EML_MCDC(6, 0, 0, false);
          CV_EML_IF(6, 0, 0, false);
          c9_d_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c9_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
          chartInstance->c9_tp_stateRandGenerate = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
          chartInstance->c9_isStable = false;
          chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertGaze;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
          chartInstance->c9_temporalCounter_i1 = 0U;
          chartInstance->c9_tp_stateAvertGaze = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_tb_debug_family_names,
            c9_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          c9_r = c9_rand(chartInstance);
          c9_x = c9_r * 8.0;
          c9_b_x = c9_x;
          c9_b_x = muDoubleScalarFloor(c9_b_x);
          c9_r = 1.0 + c9_b_x;
          c9_idleGazeInterestedTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtom
            (chartInstance, c9_r, c9_dv7);
          for (c9_i33 = 0; c9_i33 < 256; c9_i33++) {
            c9_c_arg[c9_i33] = c9_dv7[c9_i33];
          }

          for (c9_i34 = 0; c9_i34 < 256; c9_i34++) {
            _SFD_DATA_RANGE_CHECK(c9_c_arg[c9_i34], 19U);
          }

          _SFD_SET_DATA_VALUE_PTR(19U, c9_c_arg);
          _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
          _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_c_arg, c9_sf_marshallOut,
            c9_sf_marshallIn);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c9_sfEvent);
          for (c9_i35 = 0; c9_i35 < 256; c9_i35++) {
            (*c9_e_arg)[c9_i35] = c9_c_arg[c9_i35];
          }

          for (c9_i36 = 0; c9_i36 < 256; c9_i36++) {
            _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i36], 19U);
          }

          sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
          _SFD_SYMBOL_SCOPE_POP();
          _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
          _SFD_UNSET_DATA_VALUE_PTR(19U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                       chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_hc_debug_family_names,
            c9_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargin, 0U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_h_nargout, 1U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_out, 2U,
            c9_c_sf_marshallOut, c9_c_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(5, 0, 0, c9_get_randPoseChance(chartInstance, 0) ==
                          1.0)) {
            if (CV_EML_COND(5, 0, 1, c9_get_isPosing(chartInstance, 0) == 0.0))
            {
              CV_EML_MCDC(5, 0, 0, true);
              CV_EML_IF(5, 0, 0, true);
              c9_e_out = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(5, 0, 0, false);
            CV_EML_IF(5, 0, 0, false);
            c9_e_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c9_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_stateRandGenerate = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
            chartInstance->c9_isStable = false;
            chartInstance->c9_is_stateGazeIde = c9_IN_stateAvertHead;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c9_sfEvent);
            chartInstance->c9_temporalCounter_i1 = 0U;
            chartInstance->c9_tp_stateAvertHead = 1U;
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ub_debug_family_names,
              c9_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargin, 0U,
              c9_b_sf_marshallOut, c9_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_i_nargout, 1U,
              c9_b_sf_marshallOut, c9_b_sf_marshallIn);
            c9_set_avert(chartInstance, 0, 1.0);
            ssUpdateDataStoreLog(chartInstance->S, 8);
            c9_b_r = c9_rand(chartInstance);
            c9_c_x = c9_b_r * 8.0;
            c9_d_x = c9_c_x;
            c9_d_x = muDoubleScalarFloor(c9_d_x);
            c9_b_r = 9.0 + c9_d_x;
            c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
              (chartInstance, c9_b_r, c9_dv8);
            for (c9_i37 = 0; c9_i37 < 256; c9_i37++) {
              c9_d_arg[c9_i37] = c9_dv8[c9_i37];
            }

            for (c9_i38 = 0; c9_i38 < 256; c9_i38++) {
              _SFD_DATA_RANGE_CHECK(c9_d_arg[c9_i38], 19U);
            }

            _SFD_SET_DATA_VALUE_PTR(19U, c9_d_arg);
            _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
            _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_d_arg, c9_sf_marshallOut,
              c9_sf_marshallIn);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c9_sfEvent);
            for (c9_i39 = 0; c9_i39 < 256; c9_i39++) {
              (*c9_e_arg)[c9_i39] = c9_d_arg[c9_i39];
            }

            for (c9_i40 = 0; c9_i40 < 256; c9_i40++) {
              _SFD_DATA_RANGE_CHECK((*c9_e_arg)[c9_i40], 19U);
            }

            sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
            _SFD_SYMBOL_SCOPE_POP();
            _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
            _SFD_UNSET_DATA_VALUE_PTR(19U);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                         chartInstance->c9_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_gc_debug_family_names,
              c9_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargin, 0U,
              c9_b_sf_marshallOut, c9_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j_nargout, 1U,
              c9_b_sf_marshallOut, c9_b_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_out, 2U,
              c9_c_sf_marshallOut, c9_c_sf_marshallIn);
            guard1 = false;
            if (CV_EML_COND(4, 0, 0, 0.0 < c9_get_randAvertGazeChance
                            (chartInstance, 0))) {
              if (CV_EML_COND(4, 0, 1, c9_get_randAvertGazeChance(chartInstance,
                    0) < 4.0)) {
                CV_EML_MCDC(4, 0, 0, true);
                CV_EML_IF(4, 0, 0, true);
                c9_f_out = true;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1 == true) {
              CV_EML_MCDC(4, 0, 0, false);
              CV_EML_IF(4, 0, 0, false);
              c9_f_out = false;
            }

            _SFD_SYMBOL_SCOPE_POP();
            if (c9_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
              chartInstance->c9_tp_stateRandGenerate = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
              chartInstance->c9_isStable = false;
              chartInstance->c9_is_stateGazeIde = c9_IN_stateRandGenerate;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c9_sfEvent);
              chartInstance->c9_tp_stateRandGenerate = 1U;
              c9_enter_atomic_stateRandGenerate(chartInstance);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                           chartInstance->c9_sfEvent);
            }
          }
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c9_sfEvent);
}

static void c9_stateGazeWin
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  real_T c9_dv9[256];
  int32_T c9_i41;
  real_T c9_arg[256];
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  real_T c9_dv10[256];
  int32_T c9_i45;
  real_T c9_b_arg[256];
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_d_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  real_T c9_dv11[256];
  int32_T c9_i49;
  real_T c9_c_arg[256];
  int32_T c9_i50;
  int32_T c9_i51;
  int32_T c9_i52;
  real_T (*c9_d_arg)[256];
  c9_d_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
  switch (chartInstance->c9_is_stateGazeWin) {
   case c9_IN_stateBrowUp:
    CV_STATE_EVAL(15, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_rc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_out = CV_EML_IF(17, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                       (chartInstance->c9_temporalCounter_i2 >= 10));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateBrowUp = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_b_IN_stateInit;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_b_tp_stateInit = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c9_sfEvent);
    break;

   case c9_b_IN_stateInit:
    CV_STATE_EVAL(15, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_sc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_b_out = CV_EML_IF(16, 0, 0, c9_get_gazing(chartInstance, 0) ==
                         c9_get_GAZE_WIN(chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_b_tp_stateInit = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateWinSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_stateWinSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_xb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita
        (chartInstance, 1.0, c9_dv9);
      for (c9_i41 = 0; c9_i41 < 256; c9_i41++) {
        c9_arg[c9_i41] = c9_dv9[c9_i41];
      }

      for (c9_i42 = 0; c9_i42 < 256; c9_i42++) {
        _SFD_DATA_RANGE_CHECK(c9_arg[c9_i42], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i43 = 0; c9_i43 < 256; c9_i43++) {
        (*c9_d_arg)[c9_i43] = c9_arg[c9_i43];
      }

      for (c9_i44 = 0; c9_i44 < 256; c9_i44++) {
        _SFD_DATA_RANGE_CHECK((*c9_d_arg)[c9_i44], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateNeckBack:
    CV_STATE_EVAL(15, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_uc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_c_out = CV_EML_IF(13, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i2 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateNeckBack = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateBrowUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_stateBrowUp = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_ac_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita
        (chartInstance, 3.0, c9_dv10);
      for (c9_i45 = 0; c9_i45 < 256; c9_i45++) {
        c9_b_arg[c9_i45] = c9_dv10[c9_i45];
      }

      for (c9_i46 = 0; c9_i46 < 256; c9_i46++) {
        _SFD_DATA_RANGE_CHECK(c9_b_arg[c9_i46], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_b_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_b_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i47 = 0; c9_i47 < 256; c9_i47++) {
        (*c9_d_arg)[c9_i47] = c9_b_arg[c9_i47];
      }

      for (c9_i48 = 0; c9_i48 < 256; c9_i48++) {
        _SFD_DATA_RANGE_CHECK((*c9_d_arg)[c9_i48], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      c9_set_gazing(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 10);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_stateWinSmile:
    CV_STATE_EVAL(15, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c9_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_tc_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U, c9_b_sf_marshallOut,
      c9_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_out, 2U, c9_c_sf_marshallOut,
      c9_c_sf_marshallIn);
    c9_d_out = CV_EML_IF(14, 0, 0, (chartInstance->c9_sfEvent == c9_event_secs) &&
                         (chartInstance->c9_temporalCounter_i2 >= 1));
    _SFD_SYMBOL_SCOPE_POP();
    if (c9_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_stateWinSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c9_sfEvent);
      chartInstance->c9_isStable = false;
      chartInstance->c9_is_stateGazeWin = c9_IN_stateNeckBack;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i2 = 0U;
      chartInstance->c9_tp_stateNeckBack = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_yb_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita
        (chartInstance, 2.0, c9_dv11);
      for (c9_i49 = 0; c9_i49 < 256; c9_i49++) {
        c9_c_arg[c9_i49] = c9_dv11[c9_i49];
      }

      for (c9_i50 = 0; c9_i50 < 256; c9_i50++) {
        _SFD_DATA_RANGE_CHECK(c9_c_arg[c9_i50], 19U);
      }

      _SFD_SET_DATA_VALUE_PTR(19U, c9_c_arg);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
      _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_c_arg, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      for (c9_i51 = 0; c9_i51 < 256; c9_i51++) {
        (*c9_d_arg)[c9_i51] = c9_c_arg[c9_i51];
      }

      for (c9_i52 = 0; c9_i52 < 256; c9_i52++) {
        _SFD_DATA_RANGE_CHECK((*c9_d_arg)[c9_i52], 19U);
      }

      sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_UNSET_DATA_VALUE_PTR(19U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                   chartInstance->c9_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(15, 0, 0);
    chartInstance->c9_is_stateGazeWin = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c9_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c9_sfEvent);
}

static void c9_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i53;
  static char_T c9_cv1[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i54;
  static real_T c9_dv12[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
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
  for (c9_i53 = 0; c9_i53 < 118; c9_i53++) {
    c9_mystr[c9_i53] = c9_cv1[c9_i53];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i54 = 0; c9_i54 < 118; c9_i54++) {
    c9_arr[c9_i54] = c9_dv12[c9_i54];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i55 = 0; c9_i55 < 256; c9_i55++) {
    c9_tt[c9_i55] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i56 = 0; c9_i56 < 118; c9_i56++) {
    c9_tt[c9_i56] = c9_arr[c9_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i57 = 0; c9_i57 < 256; c9_i57++) {
    c9_myarr256[c9_i57] = c9_tt[c9_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_b_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i58;
  static char_T c9_cv2[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i59;
  static real_T c9_dv13[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_c_debug_family_names,
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
  for (c9_i58 = 0; c9_i58 < 119; c9_i58++) {
    c9_mystr[c9_i58] = c9_cv2[c9_i58];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i59 = 0; c9_i59 < 119; c9_i59++) {
    c9_arr[c9_i59] = c9_dv13[c9_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i60 = 0; c9_i60 < 256; c9_i60++) {
    c9_tt[c9_i60] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i61 = 0; c9_i61 < 119; c9_i61++) {
    c9_tt[c9_i61] = c9_arr[c9_i61];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i62 = 0; c9_i62 < 256; c9_i62++) {
    c9_myarr256[c9_i62] = c9_tt[c9_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_c_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[116];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[116];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i63;
  static char_T c9_cv3[116] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i64;
  static real_T c9_dv14[116] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i65;
  int32_T c9_i66;
  int32_T c9_i67;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_d_debug_family_names,
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
  for (c9_i63 = 0; c9_i63 < 116; c9_i63++) {
    c9_mystr[c9_i63] = c9_cv3[c9_i63];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i64 = 0; c9_i64 < 116; c9_i64++) {
    c9_arr[c9_i64] = c9_dv14[c9_i64];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 116.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i65 = 0; c9_i65 < 256; c9_i65++) {
    c9_tt[c9_i65] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i66 = 0; c9_i66 < 116; c9_i66++) {
    c9_tt[c9_i66] = c9_arr[c9_i66];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i67 = 0; c9_i67 < 256; c9_i67++) {
    c9_myarr256[c9_i67] = c9_tt[c9_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_d_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i68;
  static char_T c9_cv4[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i69;
  static real_T c9_dv15[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i70;
  int32_T c9_i71;
  int32_T c9_i72;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_e_debug_family_names,
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
  for (c9_i68 = 0; c9_i68 < 118; c9_i68++) {
    c9_mystr[c9_i68] = c9_cv4[c9_i68];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i69 = 0; c9_i69 < 118; c9_i69++) {
    c9_arr[c9_i69] = c9_dv15[c9_i69];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i70 = 0; c9_i70 < 256; c9_i70++) {
    c9_tt[c9_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i71 = 0; c9_i71 < 118; c9_i71++) {
    c9_tt[c9_i71] = c9_arr[c9_i71];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i72 = 0; c9_i72 < 256; c9_i72++) {
    c9_myarr256[c9_i72] = c9_tt[c9_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_e_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i73;
  static char_T c9_cv5[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i74;
  static real_T c9_dv16[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i75;
  int32_T c9_i76;
  int32_T c9_i77;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_f_debug_family_names,
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
  for (c9_i73 = 0; c9_i73 < 120; c9_i73++) {
    c9_mystr[c9_i73] = c9_cv5[c9_i73];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i74 = 0; c9_i74 < 120; c9_i74++) {
    c9_arr[c9_i74] = c9_dv16[c9_i74];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i75 = 0; c9_i75 < 256; c9_i75++) {
    c9_tt[c9_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i76 = 0; c9_i76 < 120; c9_i76++) {
    c9_tt[c9_i76] = c9_arr[c9_i76];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i77 = 0; c9_i77 < 256; c9_i77++) {
    c9_myarr256[c9_i77] = c9_tt[c9_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_f_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i78;
  static char_T c9_cv6[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i79;
  static real_T c9_dv17[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i80;
  int32_T c9_i81;
  int32_T c9_i82;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_g_debug_family_names,
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
  for (c9_i78 = 0; c9_i78 < 121; c9_i78++) {
    c9_mystr[c9_i78] = c9_cv6[c9_i78];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i79 = 0; c9_i79 < 121; c9_i79++) {
    c9_arr[c9_i79] = c9_dv17[c9_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i80 = 0; c9_i80 < 256; c9_i80++) {
    c9_tt[c9_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i81 = 0; c9_i81 < 121; c9_i81++) {
    c9_tt[c9_i81] = c9_arr[c9_i81];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i82 = 0; c9_i82 < 256; c9_i82++) {
    c9_myarr256[c9_i82] = c9_tt[c9_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_g_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i83;
  static char_T c9_cv7[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i84;
  static real_T c9_dv18[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i85;
  int32_T c9_i86;
  int32_T c9_i87;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_h_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i83 = 0; c9_i83 < 122; c9_i83++) {
    c9_mystr[c9_i83] = c9_cv7[c9_i83];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i84 = 0; c9_i84 < 122; c9_i84++) {
    c9_arr[c9_i84] = c9_dv18[c9_i84];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i85 = 0; c9_i85 < 256; c9_i85++) {
    c9_tt[c9_i85] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i86 = 0; c9_i86 < 122; c9_i86++) {
    c9_tt[c9_i86] = c9_arr[c9_i86];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i87 = 0; c9_i87 < 256; c9_i87++) {
    c9_myarr256[c9_i87] = c9_tt[c9_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_h_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i88;
  static char_T c9_cv8[123] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i89;
  static real_T c9_dv19[123] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i90;
  int32_T c9_i91;
  int32_T c9_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_i_debug_family_names,
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
  for (c9_i88 = 0; c9_i88 < 123; c9_i88++) {
    c9_mystr[c9_i88] = c9_cv8[c9_i88];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i89 = 0; c9_i89 < 123; c9_i89++) {
    c9_arr[c9_i89] = c9_dv19[c9_i89];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 123.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i90 = 0; c9_i90 < 256; c9_i90++) {
    c9_tt[c9_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i91 = 0; c9_i91 < 123; c9_i91++) {
    c9_tt[c9_i91] = c9_arr[c9_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i92 = 0; c9_i92 < 256; c9_i92++) {
    c9_myarr256[c9_i92] = c9_tt[c9_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_i_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[132];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[132];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i93;
  static char_T c9_cv9[132] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd', 'i',
    'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i94;
  static real_T c9_dv20[132] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i95;
  int32_T c9_i96;
  int32_T c9_i97;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_j_debug_family_names,
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
  for (c9_i93 = 0; c9_i93 < 132; c9_i93++) {
    c9_mystr[c9_i93] = c9_cv9[c9_i93];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i94 = 0; c9_i94 < 132; c9_i94++) {
    c9_arr[c9_i94] = c9_dv20[c9_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 132.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i95 = 0; c9_i95 < 256; c9_i95++) {
    c9_tt[c9_i95] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i96 = 0; c9_i96 < 132; c9_i96++) {
    c9_tt[c9_i96] = c9_arr[c9_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i97 = 0; c9_i97 < 256; c9_i97++) {
    c9_myarr256[c9_i97] = c9_tt[c9_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_j_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[136];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[136];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i98;
  static char_T c9_cv10[136] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L',
    'E', 'F', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-',
    'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C',
    'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i99;
  static real_T c9_dv21[136] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0,
    69.0, 70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0,
    61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i100;
  int32_T c9_i101;
  int32_T c9_i102;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_k_debug_family_names,
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
  for (c9_i98 = 0; c9_i98 < 136; c9_i98++) {
    c9_mystr[c9_i98] = c9_cv10[c9_i98];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i99 = 0; c9_i99 < 136; c9_i99++) {
    c9_arr[c9_i99] = c9_dv21[c9_i99];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 136.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i100 = 0; c9_i100 < 256; c9_i100++) {
    c9_tt[c9_i100] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i101 = 0; c9_i101 < 136; c9_i101++) {
    c9_tt[c9_i101] = c9_arr[c9_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i102 = 0; c9_i102 < 256; c9_i102++) {
    c9_myarr256[c9_i102] = c9_tt[c9_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_k_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[137];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[137];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i103;
  static char_T c9_cv11[137] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R',
    'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't',
    '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E',
    'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i',
    'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i104;
  static real_T c9_dv22[137] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c9_i105;
  int32_T c9_i106;
  int32_T c9_i107;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_l_debug_family_names,
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
  for (c9_i103 = 0; c9_i103 < 137; c9_i103++) {
    c9_mystr[c9_i103] = c9_cv11[c9_i103];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i104 = 0; c9_i104 < 137; c9_i104++) {
    c9_arr[c9_i104] = c9_dv22[c9_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 137.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i105 = 0; c9_i105 < 256; c9_i105++) {
    c9_tt[c9_i105] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i106 = 0; c9_i106 < 137; c9_i106++) {
    c9_tt[c9_i106] = c9_arr[c9_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i107 = 0; c9_i107 < 256; c9_i107++) {
    c9_myarr256[c9_i107] = c9_tt[c9_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_l_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[133];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[133];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i108;
  static char_T c9_cv12[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G',
    'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r',
    'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K',
    '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't',
    '=', '\"', '1', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i109;
  static real_T c9_dv23[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 82.0, 73.0, 71.0,
    72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i110;
  int32_T c9_i111;
  int32_T c9_i112;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_m_debug_family_names,
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
  for (c9_i108 = 0; c9_i108 < 133; c9_i108++) {
    c9_mystr[c9_i108] = c9_cv12[c9_i108];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i109 = 0; c9_i109 < 133; c9_i109++) {
    c9_arr[c9_i109] = c9_dv23[c9_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i110 = 0; c9_i110 < 256; c9_i110++) {
    c9_tt[c9_i110] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i111 = 0; c9_i111 < 133; c9_i111++) {
    c9_tt[c9_i111] = c9_arr[c9_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i112 = 0; c9_i112 < 256; c9_i112++) {
    c9_myarr256[c9_i112] = c9_tt[c9_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_m_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[132];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[132];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i113;
  static char_T c9_cv13[132] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"',
    ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=',
    '\"', '1', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i114;
  static real_T c9_dv24[132] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0,
    97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i115;
  int32_T c9_i116;
  int32_T c9_i117;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_n_debug_family_names,
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
  for (c9_i113 = 0; c9_i113 < 132; c9_i113++) {
    c9_mystr[c9_i113] = c9_cv13[c9_i113];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i114 = 0; c9_i114 < 132; c9_i114++) {
    c9_arr[c9_i114] = c9_dv24[c9_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 132.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i115 = 0; c9_i115 < 256; c9_i115++) {
    c9_tt[c9_i115] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i116 = 0; c9_i116 < 132; c9_i116++) {
    c9_tt[c9_i116] = c9_arr[c9_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i117 = 0; c9_i117 < 256; c9_i117++) {
    c9_myarr256[c9_i117] = c9_tt[c9_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_n_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[128];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[128];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i118;
  static char_T c9_cv14[128] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b', 'm',
    ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i119;
  static real_T c9_dv25[128] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0, 69.0,
    67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0,
    97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i120;
  int32_T c9_i121;
  int32_T c9_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_o_debug_family_names,
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
  for (c9_i118 = 0; c9_i118 < 128; c9_i118++) {
    c9_mystr[c9_i118] = c9_cv14[c9_i118];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i119 = 0; c9_i119 < 128; c9_i119++) {
    c9_arr[c9_i119] = c9_dv25[c9_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 128.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i120 = 0; c9_i120 < 256; c9_i120++) {
    c9_tt[c9_i120] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i121 = 0; c9_i121 < 128; c9_i121++) {
    c9_tt[c9_i121] = c9_arr[c9_i121];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i122 = 0; c9_i122 < 256; c9_i122++) {
    c9_myarr256[c9_i122] = c9_tt[c9_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_o_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[133];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[133];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i123;
  static char_T c9_cv15[133] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i124;
  static real_T c9_dv26[133] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0,
    34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0,
    45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0,
    32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i125;
  int32_T c9_i126;
  int32_T c9_i127;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_p_debug_family_names,
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
  for (c9_i123 = 0; c9_i123 < 133; c9_i123++) {
    c9_mystr[c9_i123] = c9_cv15[c9_i123];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i124 = 0; c9_i124 < 133; c9_i124++) {
    c9_arr[c9_i124] = c9_dv26[c9_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 133.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i125 = 0; c9_i125 < 256; c9_i125++) {
    c9_tt[c9_i125] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i126 = 0; c9_i126 < 133; c9_i126++) {
    c9_tt[c9_i126] = c9_arr[c9_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i127 = 0; c9_i127 < 256; c9_i127++) {
    c9_myarr256[c9_i127] = c9_tt[c9_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_p_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[132];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[132];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i128;
  static char_T c9_cv16[132] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'd',
    'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1',
    '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i129;
  static real_T c9_dv27[132] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 100.0, 105.0, 114.0, 101.0,
    99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0,
    32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0,
    114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i130;
  int32_T c9_i131;
  int32_T c9_i132;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_q_debug_family_names,
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
  for (c9_i128 = 0; c9_i128 < 132; c9_i128++) {
    c9_mystr[c9_i128] = c9_cv16[c9_i128];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i129 = 0; c9_i129 < 132; c9_i129++) {
    c9_arr[c9_i129] = c9_dv27[c9_i129];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 132.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i130 = 0; c9_i130 < 256; c9_i130++) {
    c9_tt[c9_i130] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i131 = 0; c9_i131 < 132; c9_i131++) {
    c9_tt[c9_i131] = c9_arr[c9_i131];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i132 = 0; c9_i132 < 256; c9_i132++) {
    c9_myarr256[c9_i132] = c9_tt[c9_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_q_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i133;
  static char_T c9_cv17[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i134;
  static real_T c9_dv28[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 32.0, 78.0,
    69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i135;
  int32_T c9_i136;
  int32_T c9_i137;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_r_debug_family_names,
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
  for (c9_i133 = 0; c9_i133 < 115; c9_i133++) {
    c9_mystr[c9_i133] = c9_cv17[c9_i133];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i134 = 0; c9_i134 < 115; c9_i134++) {
    c9_arr[c9_i134] = c9_dv28[c9_i134];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i135 = 0; c9_i135 < 256; c9_i135++) {
    c9_tt[c9_i135] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i136 = 0; c9_i136 < 115; c9_i136++) {
    c9_tt[c9_i136] = c9_arr[c9_i136];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i137 = 0; c9_i137 < 256; c9_i137++) {
    c9_myarr256[c9_i137] = c9_tt[c9_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_r_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[238];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[238];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i138;
  static char_T c9_cv18[238] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '0', '.', '2', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"',
    '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n',
    't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '3', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i139;
  static real_T c9_dv29[238] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 53.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 50.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0,
    105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i140;
  int32_T c9_i141;
  int32_T c9_i142;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_s_debug_family_names,
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
  for (c9_i138 = 0; c9_i138 < 238; c9_i138++) {
    c9_mystr[c9_i138] = c9_cv18[c9_i138];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i139 = 0; c9_i139 < 238; c9_i139++) {
    c9_arr[c9_i139] = c9_dv29[c9_i139];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 238.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i140 = 0; c9_i140 < 256; c9_i140++) {
    c9_tt[c9_i140] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i141 = 0; c9_i141 < 238; c9_i141++) {
    c9_tt[c9_i141] = c9_arr[c9_i141];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i142 = 0; c9_i142 < 256; c9_i142++) {
    c9_myarr256[c9_i142] = c9_tt[c9_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_s_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i143;
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

  int32_T c9_i144;
  static real_T c9_dv30[151] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i145;
  int32_T c9_i146;
  int32_T c9_i147;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_t_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ib_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_hb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i143 = 0; c9_i143 < 151; c9_i143++) {
    c9_mystr[c9_i143] = c9_cv19[c9_i143];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i144 = 0; c9_i144 < 151; c9_i144++) {
    c9_arr[c9_i144] = c9_dv30[c9_i144];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 151.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i145 = 0; c9_i145 < 256; c9_i145++) {
    c9_tt[c9_i145] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i146 = 0; c9_i146 < 151; c9_i146++) {
    c9_tt[c9_i146] = c9_arr[c9_i146];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i147 = 0; c9_i147 < 256; c9_i147++) {
    c9_myarr256[c9_i147] = c9_tt[c9_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_t_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i148;
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

  int32_T c9_i149;
  static real_T c9_dv31[251] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i150;
  int32_T c9_i151;
  int32_T c9_i152;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_u_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i148 = 0; c9_i148 < 251; c9_i148++) {
    c9_mystr[c9_i148] = c9_cv20[c9_i148];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i149 = 0; c9_i149 < 251; c9_i149++) {
    c9_arr[c9_i149] = c9_dv31[c9_i149];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 251.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i150 = 0; c9_i150 < 256; c9_i150++) {
    c9_tt[c9_i150] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i151 = 0; c9_i151 < 251; c9_i151++) {
    c9_tt[c9_i151] = c9_arr[c9_i151];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i152 = 0; c9_i152 < 256; c9_i152++) {
    c9_myarr256[c9_i152] = c9_tt[c9_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_u_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i153;
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

  int32_T c9_i154;
  static real_T c9_dv32[140] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i155;
  int32_T c9_i156;
  int32_T c9_i157;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_v_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i153 = 0; c9_i153 < 140; c9_i153++) {
    c9_mystr[c9_i153] = c9_cv21[c9_i153];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i154 = 0; c9_i154 < 140; c9_i154++) {
    c9_arr[c9_i154] = c9_dv32[c9_i154];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i155 = 0; c9_i155 < 256; c9_i155++) {
    c9_tt[c9_i155] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i156 = 0; c9_i156 < 140; c9_i156++) {
    c9_tt[c9_i156] = c9_arr[c9_i156];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i157 = 0; c9_i157 < 256; c9_i157++) {
    c9_myarr256[c9_i157] = c9_tt[c9_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_v_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[238];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[238];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i158;
  static char_T c9_cv22[238] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n', 'g', 'l', 'e', '=', '\"',
    '1', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n', '=', '\"',
    'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n',
    't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '0', '.', '3', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i159;
  static real_T c9_dv33[238] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0,
    116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0,
    97.0, 110.0, 103.0, 108.0, 101.0, 61.0, 34.0, 49.0, 53.0, 34.0, 32.0, 100.0,
    105.0, 114.0, 101.0, 99.0, 116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 82.0,
    73.0, 71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0,
    105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0,
    78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0,
    109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i160;
  int32_T c9_i161;
  int32_T c9_i162;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_w_debug_family_names,
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
  for (c9_i158 = 0; c9_i158 < 238; c9_i158++) {
    c9_mystr[c9_i158] = c9_cv22[c9_i158];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i159 = 0; c9_i159 < 238; c9_i159++) {
    c9_arr[c9_i159] = c9_dv33[c9_i159];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 238.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i160 = 0; c9_i160 < 256; c9_i160++) {
    c9_tt[c9_i160] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i161 = 0; c9_i161 < 238; c9_i161++) {
    c9_tt[c9_i161] = c9_arr[c9_i161];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i162 = 0; c9_i162 < 256; c9_i162++) {
    c9_myarr256[c9_i162] = c9_tt[c9_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_w_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[138];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[138];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i163;
  static char_T c9_cv23[138] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h',
    'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g', 'e',
    't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i164;
  static real_T c9_dv34[138] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0, 83.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c9_i165;
  int32_T c9_i166;
  int32_T c9_i167;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_x_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i163 = 0; c9_i163 < 138; c9_i163++) {
    c9_mystr[c9_i163] = c9_cv23[c9_i163];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i164 = 0; c9_i164 < 138; c9_i164++) {
    c9_arr[c9_i164] = c9_dv34[c9_i164];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 138.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i165 = 0; c9_i165 < 256; c9_i165++) {
    c9_tt[c9_i165] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i166 = 0; c9_i166 < 138; c9_i166++) {
    c9_tt[c9_i166] = c9_arr[c9_i166];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i167 = 0; c9_i167 < 256; c9_i167++) {
    c9_myarr256[c9_i167] = c9_tt[c9_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_x_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i168;
  static char_T c9_cv24[115] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r',
    'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c9_i169;
  static real_T c9_dv35[115] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i170;
  int32_T c9_i171;
  int32_T c9_i172;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ab_debug_family_names,
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
  for (c9_i168 = 0; c9_i168 < 115; c9_i168++) {
    c9_mystr[c9_i168] = c9_cv24[c9_i168];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i169 = 0; c9_i169 < 115; c9_i169++) {
    c9_arr[c9_i169] = c9_dv35[c9_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 115.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i170 = 0; c9_i170 < 256; c9_i170++) {
    c9_tt[c9_i170] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i171 = 0; c9_i171 < 115; c9_i171++) {
    c9_tt[c9_i171] = c9_arr[c9_i171];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i172 = 0; c9_i172 < 256; c9_i172++) {
    c9_myarr256[c9_i172] = c9_tt[c9_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_y_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i173;
  static char_T c9_cv25[117] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '5', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E', 'Y',
    'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm',
    'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c9_i174;
  static real_T c9_dv36[117] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i175;
  int32_T c9_i176;
  int32_T c9_i177;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_bb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i173 = 0; c9_i173 < 117; c9_i173++) {
    c9_mystr[c9_i173] = c9_cv25[c9_i173];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i174 = 0; c9_i174 < 117; c9_i174++) {
    c9_arr[c9_i174] = c9_dv36[c9_i174];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 117.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i175 = 0; c9_i175 < 256; c9_i175++) {
    c9_tt[c9_i175] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i176 = 0; c9_i176 < 117; c9_i176++) {
    c9_tt[c9_i176] = c9_arr[c9_i176];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i177 = 0; c9_i177 < 256; c9_i177++) {
    c9_myarr256[c9_i177] = c9_tt[c9_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ab_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i178;
  static char_T c9_cv26[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'E',
    'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a',
    'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c9_i179;
  static real_T c9_dv37[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i180;
  int32_T c9_i181;
  int32_T c9_i182;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_cb_debug_family_names,
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
  for (c9_i178 = 0; c9_i178 < 118; c9_i178++) {
    c9_mystr[c9_i178] = c9_cv26[c9_i178];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i179 = 0; c9_i179 < 118; c9_i179++) {
    c9_arr[c9_i179] = c9_dv37[c9_i179];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i180 = 0; c9_i180 < 256; c9_i180++) {
    c9_tt[c9_i180] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i181 = 0; c9_i181 < 118; c9_i181++) {
    c9_tt[c9_i181] = c9_arr[c9_i181];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i182 = 0; c9_i182 < 256; c9_i182++) {
    c9_myarr256[c9_i182] = c9_tt[c9_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_bb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i183;
  static char_T c9_cv27[119] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c',
    'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c9_i184;
  static real_T c9_dv38[119] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i185;
  int32_T c9_i186;
  int32_T c9_i187;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_db_debug_family_names,
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
  for (c9_i183 = 0; c9_i183 < 119; c9_i183++) {
    c9_mystr[c9_i183] = c9_cv27[c9_i183];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i184 = 0; c9_i184 < 119; c9_i184++) {
    c9_arr[c9_i184] = c9_dv38[c9_i184];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 119.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i185 = 0; c9_i185 < 256; c9_i185++) {
    c9_tt[c9_i185] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i186 = 0; c9_i186 < 119; c9_i186++) {
    c9_tt[c9_i186] = c9_arr[c9_i186];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i187 = 0; c9_i187 < 256; c9_i187++) {
    c9_myarr256[c9_i187] = c9_tt[c9_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_cb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i188;
  static char_T c9_cv28[120] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's',
    'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=',
    '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"',
    'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i189;
  static real_T c9_dv39[120] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i190;
  int32_T c9_i191;
  int32_T c9_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_eb_debug_family_names,
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
  for (c9_i188 = 0; c9_i188 < 120; c9_i188++) {
    c9_mystr[c9_i188] = c9_cv28[c9_i188];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i189 = 0; c9_i189 < 120; c9_i189++) {
    c9_arr[c9_i189] = c9_dv39[c9_i189];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i190 = 0; c9_i190 < 256; c9_i190++) {
    c9_tt[c9_i190] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i191 = 0; c9_i191 < 120; c9_i191++) {
    c9_tt[c9_i191] = c9_arr[c9_i191];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i192 = 0; c9_i192 < 256; c9_i192++) {
    c9_myarr256[c9_i192] = c9_tt[c9_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_db_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i193;
  static char_T c9_cv29[121] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=',
    '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i194;
  static real_T c9_dv40[121] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i195;
  int32_T c9_i196;
  int32_T c9_i197;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_fb_debug_family_names,
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
  for (c9_i193 = 0; c9_i193 < 121; c9_i193++) {
    c9_mystr[c9_i193] = c9_cv29[c9_i193];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i194 = 0; c9_i194 < 121; c9_i194++) {
    c9_arr[c9_i194] = c9_dv40[c9_i194];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 121.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i195 = 0; c9_i195 < 256; c9_i195++) {
    c9_tt[c9_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i196 = 0; c9_i196 < 121; c9_i196++) {
    c9_tt[c9_i196] = c9_arr[c9_i196];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i197 = 0; c9_i197 < 256; c9_i197++) {
    c9_myarr256[c9_i197] = c9_tt[c9_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_eb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i198;
  static char_T c9_cv30[122] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't',
    '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i199;
  static real_T c9_dv41[122] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i200;
  int32_T c9_i201;
  int32_T c9_i202;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_gb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i198 = 0; c9_i198 < 122; c9_i198++) {
    c9_mystr[c9_i198] = c9_cv30[c9_i198];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i199 = 0; c9_i199 < 122; c9_i199++) {
    c9_arr[c9_i199] = c9_dv41[c9_i199];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 122.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i200 = 0; c9_i200 < 256; c9_i200++) {
    c9_tt[c9_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i201 = 0; c9_i201 < 122; c9_i201++) {
    c9_tt[c9_i201] = c9_arr[c9_i201];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i202 = 0; c9_i202 < 256; c9_i202++) {
    c9_myarr256[c9_i202] = c9_tt[c9_i202];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_fb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
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
  int32_T c9_i203;
  static char_T c9_cv31[237] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c9_i204;
  static real_T c9_dv42[237] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i205;
  int32_T c9_i206;
  int32_T c9_i207;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_jb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_ub_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_tb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i203 = 0; c9_i203 < 237; c9_i203++) {
    c9_mystr[c9_i203] = c9_cv31[c9_i203];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i204 = 0; c9_i204 < 237; c9_i204++) {
    c9_arr[c9_i204] = c9_dv42[c9_i204];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 237.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i205 = 0; c9_i205 < 256; c9_i205++) {
    c9_tt[c9_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i206 = 0; c9_i206 < 237; c9_i206++) {
    c9_tt[c9_i206] = c9_arr[c9_i206];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i207 = 0; c9_i207 < 256; c9_i207++) {
    c9_myarr256[c9_i207] = c9_tt[c9_i207];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_gb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  int32_T c9_i208;
  static char_T c9_cv32[142] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j',
    'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A',
    'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i209;
  static real_T c9_dv43[142] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i210;
  int32_T c9_i211;
  int32_T c9_i212;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_kb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_wb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_vb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i208 = 0; c9_i208 < 142; c9_i208++) {
    c9_mystr[c9_i208] = c9_cv32[c9_i208];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i209 = 0; c9_i209 < 142; c9_i209++) {
    c9_arr[c9_i209] = c9_dv43[c9_i209];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 142.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i210 = 0; c9_i210 < 256; c9_i210++) {
    c9_tt[c9_i210] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i211 = 0; c9_i211 < 142; c9_i211++) {
    c9_tt[c9_i211] = c9_arr[c9_i211];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i212 = 0; c9_i212 < 256; c9_i212++) {
    c9_myarr256[c9_i212] = c9_tt[c9_i212];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_hb_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_myarr256[256])
{
  uint32_T c9_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[143];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[143];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  int32_T c9_i213;
  static char_T c9_cv33[143] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '7', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'R', 'I', 'G', 'H', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H',
    'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i214;
  static real_T c9_dv44[143] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 55.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 82.0, 73.0, 71.0, 72.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0,
    65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i215;
  int32_T c9_i216;
  int32_T c9_i217;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_nb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_bc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_ac_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i213 = 0; c9_i213 < 143; c9_i213++) {
    c9_mystr[c9_i213] = c9_cv33[c9_i213];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i214 = 0; c9_i214 < 143; c9_i214++) {
    c9_arr[c9_i214] = c9_dv44[c9_i214];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 143.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i215 = 0; c9_i215 < 256; c9_i215++) {
    c9_tt[c9_i215] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i216 = 0; c9_i216 < 143; c9_i216++) {
    c9_tt[c9_i216] = c9_arr[c9_i216];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i217 = 0; c9_i217 < 256; c9_i217++) {
    c9_myarr256[c9_i217] = c9_tt[c9_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ib_encStr2Arr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  int32_T c9_i218;
  static char_T c9_cv34[87] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.',
    '5', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e',
    'r', 'a', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c9_i219;
  static real_T c9_dv45[87] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0,
    105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0,
    46.0, 53.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i220;
  int32_T c9_i221;
  int32_T c9_i222;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_pb_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_dc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_cc_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  for (c9_i218 = 0; c9_i218 < 87; c9_i218++) {
    c9_mystr[c9_i218] = c9_cv34[c9_i218];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  for (c9_i219 = 0; c9_i219 < 87; c9_i219++) {
    c9_arr[c9_i219] = c9_dv45[c9_i219];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_ss = 87.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_padsize = c9_maxarrsize - c9_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  for (c9_i220 = 0; c9_i220 < 256; c9_i220++) {
    c9_tt[c9_i220] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  for (c9_i221 = 0; c9_i221 < 87; c9_i221++) {
    c9_tt[c9_i221] = c9_arr[c9_i221];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i222 = 0; c9_i222 < 256; c9_i222++) {
    c9_myarr256[c9_i222] = c9_tt[c9_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c9_rand
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  return c9_eml_rand(chartInstance);
}

static real_T c9_eml_rand
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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
  int32_T c9_i223;
  uint32_T c9_icng;
  uint32_T c9_jsr;
  uint32_T c9_u1;
  uint32_T c9_u2;
  uint32_T c9_ui;
  uint32_T c9_b_ui;
  real_T c9_c_r;
  real_T c9_d1;
  uint32_T c9_uv2[625];
  int32_T c9_i224;
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
      for (c9_i223 = 0; c9_i223 < 2; c9_i223++) {
        chartInstance->c9_b_state[c9_i223] = 362436069U + 158852560U * (uint32_T)
          c9_i223;
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
      for (c9_i224 = 0; c9_i224 < 625; c9_i224++) {
        chartInstance->c9_c_state[c9_i224] = c9_uv2[c9_i224];
      }

      chartInstance->c9_c_state_not_empty = true;
    }

    c9_d2 = c9_c_eml_rand_mt19937ar(chartInstance, chartInstance->c9_c_state);
    c9_r = c9_d2;
  }

  return c9_r;
}

static void c9_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625])
{
  real_T c9_d3;
  int32_T c9_i225;
  c9_d3 = 5489.0;
  for (c9_i225 = 0; c9_i225 < 625; c9_i225++) {
    c9_d_state[c9_i225] = 0U;
  }

  c9_b_twister_state_vector(chartInstance, c9_d_state, c9_d3);
}

static void c9_twister_state_vector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_mt[625], real_T c9_seed, uint32_T c9_b_mt[625])
{
  int32_T c9_i226;
  for (c9_i226 = 0; c9_i226 < 625; c9_i226++) {
    c9_b_mt[c9_i226] = c9_mt[c9_i226];
  }

  c9_b_twister_state_vector(chartInstance, c9_b_mt, c9_seed);
}

static void c9_b_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625], uint32_T c9_e_state[625], real_T
   *c9_r)
{
  int32_T c9_i227;
  for (c9_i227 = 0; c9_i227 < 625; c9_i227++) {
    c9_e_state[c9_i227] = c9_d_state[c9_i227];
  }

  *c9_r = c9_c_eml_rand_mt19937ar(chartInstance, c9_e_state);
}

static void c9_eml_error
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  int32_T c9_i228;
  static char_T c9_cv35[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c9_u[37];
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  for (c9_i228 = 0; c9_i228 < 37; c9_i228++) {
    c9_u[c9_i228] = c9_cv35[c9_i228];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 37), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c9_y));
}

static real_T c9_randi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  real_T c9_r;
  real_T c9_x;
  real_T c9_b_x;
  c9_r = c9_rand(chartInstance);
  c9_x = c9_r * 4.0;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarFloor(c9_b_x);
  return 2.0 + c9_b_x;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\30-6-2015-v2-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i229;
  real_T c9_b_inData[256];
  int32_T c9_i230;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i229 = 0; c9_i229 < 256; c9_i229++) {
    c9_b_inData[c9_i229] = (*(real_T (*)[256])c9_inData)[c9_i229];
  }

  for (c9_i230 = 0; c9_i230 < 256; c9_i230++) {
    c9_u[c9_i230] = c9_b_inData[c9_i230];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   real_T c9_y[256])
{
  real_T c9_dv46[256];
  int32_T c9_i231;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv46, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c9_i231 = 0; c9_i231 < 256; c9_i231++) {
    c9_y[c9_i231] = c9_dv46[c9_i231];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_gazeBML;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[256];
  int32_T c9_i232;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_gazeBML = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_gazeBML), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_gazeBML);
  for (c9_i232 = 0; c9_i232 < 256; c9_i232++) {
    (*(real_T (*)[256])c9_outData)[c9_i232] = c9_y[c9_i232];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_b_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_bmlID, const char_T *c9_identifier)
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
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
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
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_d_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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
  const mxArray *c9_aVarTruthTableCondition_23;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_aVarTruthTableCondition_23 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_aVarTruthTableCondition_23), &c9_thisId);
  sf_mex_destroy(&c9_aVarTruthTableCondition_23);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i233;
  real_T c9_b_inData[256];
  int32_T c9_i234;
  real_T c9_u[256];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i233 = 0; c9_i233 < 256; c9_i233++) {
    c9_b_inData[c9_i233] = (*(real_T (*)[256])c9_inData)[c9_i233];
  }

  for (c9_i234 = 0; c9_i234 < 256; c9_i234++) {
    c9_u[c9_i234] = c9_b_inData[c9_i234];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   real_T c9_y[256])
{
  real_T c9_dv47[256];
  int32_T c9_i235;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv47, 1, 0, 0U, 1, 0U, 1, 256);
  for (c9_i235 = 0; c9_i235 < 256; c9_i235++) {
    c9_y[c9_i235] = c9_dv47[c9_i235];
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
  int32_T c9_i236;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_myarr256 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_myarr256), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_myarr256);
  for (c9_i236 = 0; c9_i236 < 256; c9_i236++) {
    (*(real_T (*)[256])c9_outData)[c9_i236] = c9_y[c9_i236];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i237;
  char_T c9_b_inData[118];
  int32_T c9_i238;
  char_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i237 = 0; c9_i237 < 118; c9_i237++) {
    c9_b_inData[c9_i237] = (*(char_T (*)[118])c9_inData)[c9_i237];
  }

  for (c9_i238 = 0; c9_i238 < 118; c9_i238++) {
    c9_u[c9_i238] = c9_b_inData[c9_i238];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i239;
  real_T c9_b_inData[118];
  int32_T c9_i240;
  real_T c9_u[118];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i239 = 0; c9_i239 < 118; c9_i239++) {
    c9_b_inData[c9_i239] = (*(real_T (*)[118])c9_inData)[c9_i239];
  }

  for (c9_i240 = 0; c9_i240 < 118; c9_i240++) {
    c9_u[c9_i240] = c9_b_inData[c9_i240];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i241;
  char_T c9_b_inData[119];
  int32_T c9_i242;
  char_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i241 = 0; c9_i241 < 119; c9_i241++) {
    c9_b_inData[c9_i241] = (*(char_T (*)[119])c9_inData)[c9_i241];
  }

  for (c9_i242 = 0; c9_i242 < 119; c9_i242++) {
    c9_u[c9_i242] = c9_b_inData[c9_i242];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i243;
  real_T c9_b_inData[119];
  int32_T c9_i244;
  real_T c9_u[119];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i243 = 0; c9_i243 < 119; c9_i243++) {
    c9_b_inData[c9_i243] = (*(real_T (*)[119])c9_inData)[c9_i243];
  }

  for (c9_i244 = 0; c9_i244 < 119; c9_i244++) {
    c9_u[c9_i244] = c9_b_inData[c9_i244];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i245;
  char_T c9_b_inData[116];
  int32_T c9_i246;
  char_T c9_u[116];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i245 = 0; c9_i245 < 116; c9_i245++) {
    c9_b_inData[c9_i245] = (*(char_T (*)[116])c9_inData)[c9_i245];
  }

  for (c9_i246 = 0; c9_i246 < 116; c9_i246++) {
    c9_u[c9_i246] = c9_b_inData[c9_i246];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i247;
  real_T c9_b_inData[116];
  int32_T c9_i248;
  real_T c9_u[116];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i247 = 0; c9_i247 < 116; c9_i247++) {
    c9_b_inData[c9_i247] = (*(real_T (*)[116])c9_inData)[c9_i247];
  }

  for (c9_i248 = 0; c9_i248 < 116; c9_i248++) {
    c9_u[c9_i248] = c9_b_inData[c9_i248];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i249;
  char_T c9_b_inData[120];
  int32_T c9_i250;
  char_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i249 = 0; c9_i249 < 120; c9_i249++) {
    c9_b_inData[c9_i249] = (*(char_T (*)[120])c9_inData)[c9_i249];
  }

  for (c9_i250 = 0; c9_i250 < 120; c9_i250++) {
    c9_u[c9_i250] = c9_b_inData[c9_i250];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i251;
  real_T c9_b_inData[120];
  int32_T c9_i252;
  real_T c9_u[120];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i251 = 0; c9_i251 < 120; c9_i251++) {
    c9_b_inData[c9_i251] = (*(real_T (*)[120])c9_inData)[c9_i251];
  }

  for (c9_i252 = 0; c9_i252 < 120; c9_i252++) {
    c9_u[c9_i252] = c9_b_inData[c9_i252];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i253;
  char_T c9_b_inData[121];
  int32_T c9_i254;
  char_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i253 = 0; c9_i253 < 121; c9_i253++) {
    c9_b_inData[c9_i253] = (*(char_T (*)[121])c9_inData)[c9_i253];
  }

  for (c9_i254 = 0; c9_i254 < 121; c9_i254++) {
    c9_u[c9_i254] = c9_b_inData[c9_i254];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i255;
  real_T c9_b_inData[121];
  int32_T c9_i256;
  real_T c9_u[121];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i255 = 0; c9_i255 < 121; c9_i255++) {
    c9_b_inData[c9_i255] = (*(real_T (*)[121])c9_inData)[c9_i255];
  }

  for (c9_i256 = 0; c9_i256 < 121; c9_i256++) {
    c9_u[c9_i256] = c9_b_inData[c9_i256];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_o_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i257;
  char_T c9_b_inData[122];
  int32_T c9_i258;
  char_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i257 = 0; c9_i257 < 122; c9_i257++) {
    c9_b_inData[c9_i257] = (*(char_T (*)[122])c9_inData)[c9_i257];
  }

  for (c9_i258 = 0; c9_i258 < 122; c9_i258++) {
    c9_u[c9_i258] = c9_b_inData[c9_i258];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_p_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i259;
  real_T c9_b_inData[122];
  int32_T c9_i260;
  real_T c9_u[122];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i259 = 0; c9_i259 < 122; c9_i259++) {
    c9_b_inData[c9_i259] = (*(real_T (*)[122])c9_inData)[c9_i259];
  }

  for (c9_i260 = 0; c9_i260 < 122; c9_i260++) {
    c9_u[c9_i260] = c9_b_inData[c9_i260];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_q_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i261;
  char_T c9_b_inData[123];
  int32_T c9_i262;
  char_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i261 = 0; c9_i261 < 123; c9_i261++) {
    c9_b_inData[c9_i261] = (*(char_T (*)[123])c9_inData)[c9_i261];
  }

  for (c9_i262 = 0; c9_i262 < 123; c9_i262++) {
    c9_u[c9_i262] = c9_b_inData[c9_i262];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_r_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i263;
  real_T c9_b_inData[123];
  int32_T c9_i264;
  real_T c9_u[123];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i263 = 0; c9_i263 < 123; c9_i263++) {
    c9_b_inData[c9_i263] = (*(real_T (*)[123])c9_inData)[c9_i263];
  }

  for (c9_i264 = 0; c9_i264 < 123; c9_i264++) {
    c9_u[c9_i264] = c9_b_inData[c9_i264];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_s_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i265;
  char_T c9_b_inData[132];
  int32_T c9_i266;
  char_T c9_u[132];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i265 = 0; c9_i265 < 132; c9_i265++) {
    c9_b_inData[c9_i265] = (*(char_T (*)[132])c9_inData)[c9_i265];
  }

  for (c9_i266 = 0; c9_i266 < 132; c9_i266++) {
    c9_u[c9_i266] = c9_b_inData[c9_i266];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 132),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_t_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i267;
  real_T c9_b_inData[132];
  int32_T c9_i268;
  real_T c9_u[132];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i267 = 0; c9_i267 < 132; c9_i267++) {
    c9_b_inData[c9_i267] = (*(real_T (*)[132])c9_inData)[c9_i267];
  }

  for (c9_i268 = 0; c9_i268 < 132; c9_i268++) {
    c9_u[c9_i268] = c9_b_inData[c9_i268];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 132), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_u_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i269;
  char_T c9_b_inData[136];
  int32_T c9_i270;
  char_T c9_u[136];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i269 = 0; c9_i269 < 136; c9_i269++) {
    c9_b_inData[c9_i269] = (*(char_T (*)[136])c9_inData)[c9_i269];
  }

  for (c9_i270 = 0; c9_i270 < 136; c9_i270++) {
    c9_u[c9_i270] = c9_b_inData[c9_i270];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_v_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i271;
  real_T c9_b_inData[136];
  int32_T c9_i272;
  real_T c9_u[136];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i271 = 0; c9_i271 < 136; c9_i271++) {
    c9_b_inData[c9_i271] = (*(real_T (*)[136])c9_inData)[c9_i271];
  }

  for (c9_i272 = 0; c9_i272 < 136; c9_i272++) {
    c9_u[c9_i272] = c9_b_inData[c9_i272];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_w_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i273;
  char_T c9_b_inData[137];
  int32_T c9_i274;
  char_T c9_u[137];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i273 = 0; c9_i273 < 137; c9_i273++) {
    c9_b_inData[c9_i273] = (*(char_T (*)[137])c9_inData)[c9_i273];
  }

  for (c9_i274 = 0; c9_i274 < 137; c9_i274++) {
    c9_u[c9_i274] = c9_b_inData[c9_i274];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_x_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i275;
  real_T c9_b_inData[137];
  int32_T c9_i276;
  real_T c9_u[137];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i275 = 0; c9_i275 < 137; c9_i275++) {
    c9_b_inData[c9_i275] = (*(real_T (*)[137])c9_inData)[c9_i275];
  }

  for (c9_i276 = 0; c9_i276 < 137; c9_i276++) {
    c9_u[c9_i276] = c9_b_inData[c9_i276];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_y_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i277;
  char_T c9_b_inData[133];
  int32_T c9_i278;
  char_T c9_u[133];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i277 = 0; c9_i277 < 133; c9_i277++) {
    c9_b_inData[c9_i277] = (*(char_T (*)[133])c9_inData)[c9_i277];
  }

  for (c9_i278 = 0; c9_i278 < 133; c9_i278++) {
    c9_u[c9_i278] = c9_b_inData[c9_i278];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i279;
  real_T c9_b_inData[133];
  int32_T c9_i280;
  real_T c9_u[133];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i279 = 0; c9_i279 < 133; c9_i279++) {
    c9_b_inData[c9_i279] = (*(real_T (*)[133])c9_inData)[c9_i279];
  }

  for (c9_i280 = 0; c9_i280 < 133; c9_i280++) {
    c9_u[c9_i280] = c9_b_inData[c9_i280];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i281;
  char_T c9_b_inData[128];
  int32_T c9_i282;
  char_T c9_u[128];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i281 = 0; c9_i281 < 128; c9_i281++) {
    c9_b_inData[c9_i281] = (*(char_T (*)[128])c9_inData)[c9_i281];
  }

  for (c9_i282 = 0; c9_i282 < 128; c9_i282++) {
    c9_u[c9_i282] = c9_b_inData[c9_i282];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 128),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i283;
  real_T c9_b_inData[128];
  int32_T c9_i284;
  real_T c9_u[128];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i283 = 0; c9_i283 < 128; c9_i283++) {
    c9_b_inData[c9_i283] = (*(real_T (*)[128])c9_inData)[c9_i283];
  }

  for (c9_i284 = 0; c9_i284 < 128; c9_i284++) {
    c9_u[c9_i284] = c9_b_inData[c9_i284];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 128), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_db_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i285;
  char_T c9_b_inData[115];
  int32_T c9_i286;
  char_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i285 = 0; c9_i285 < 115; c9_i285++) {
    c9_b_inData[c9_i285] = (*(char_T (*)[115])c9_inData)[c9_i285];
  }

  for (c9_i286 = 0; c9_i286 < 115; c9_i286++) {
    c9_u[c9_i286] = c9_b_inData[c9_i286];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i287;
  real_T c9_b_inData[115];
  int32_T c9_i288;
  real_T c9_u[115];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i287 = 0; c9_i287 < 115; c9_i287++) {
    c9_b_inData[c9_i287] = (*(real_T (*)[115])c9_inData)[c9_i287];
  }

  for (c9_i288 = 0; c9_i288 < 115; c9_i288++) {
    c9_u[c9_i288] = c9_b_inData[c9_i288];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i289;
  char_T c9_b_inData[238];
  int32_T c9_i290;
  char_T c9_u[238];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i289 = 0; c9_i289 < 238; c9_i289++) {
    c9_b_inData[c9_i289] = (*(char_T (*)[238])c9_inData)[c9_i289];
  }

  for (c9_i290 = 0; c9_i290 < 238; c9_i290++) {
    c9_u[c9_i290] = c9_b_inData[c9_i290];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 238),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i291;
  real_T c9_b_inData[238];
  int32_T c9_i292;
  real_T c9_u[238];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i291 = 0; c9_i291 < 238; c9_i291++) {
    c9_b_inData[c9_i291] = (*(real_T (*)[238])c9_inData)[c9_i291];
  }

  for (c9_i292 = 0; c9_i292 < 238; c9_i292++) {
    c9_u[c9_i292] = c9_b_inData[c9_i292];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 238), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i293;
  char_T c9_b_inData[151];
  int32_T c9_i294;
  char_T c9_u[151];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i293 = 0; c9_i293 < 151; c9_i293++) {
    c9_b_inData[c9_i293] = (*(char_T (*)[151])c9_inData)[c9_i293];
  }

  for (c9_i294 = 0; c9_i294 < 151; c9_i294++) {
    c9_u[c9_i294] = c9_b_inData[c9_i294];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 151),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i295;
  real_T c9_b_inData[151];
  int32_T c9_i296;
  real_T c9_u[151];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i295 = 0; c9_i295 < 151; c9_i295++) {
    c9_b_inData[c9_i295] = (*(real_T (*)[151])c9_inData)[c9_i295];
  }

  for (c9_i296 = 0; c9_i296 < 151; c9_i296++) {
    c9_u[c9_i296] = c9_b_inData[c9_i296];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 151), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i297;
  char_T c9_b_inData[251];
  int32_T c9_i298;
  char_T c9_u[251];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i297 = 0; c9_i297 < 251; c9_i297++) {
    c9_b_inData[c9_i297] = (*(char_T (*)[251])c9_inData)[c9_i297];
  }

  for (c9_i298 = 0; c9_i298 < 251; c9_i298++) {
    c9_u[c9_i298] = c9_b_inData[c9_i298];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 251),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i299;
  real_T c9_b_inData[251];
  int32_T c9_i300;
  real_T c9_u[251];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i299 = 0; c9_i299 < 251; c9_i299++) {
    c9_b_inData[c9_i299] = (*(real_T (*)[251])c9_inData)[c9_i299];
  }

  for (c9_i300 = 0; c9_i300 < 251; c9_i300++) {
    c9_u[c9_i300] = c9_b_inData[c9_i300];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 251), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i301;
  char_T c9_b_inData[140];
  int32_T c9_i302;
  char_T c9_u[140];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i301 = 0; c9_i301 < 140; c9_i301++) {
    c9_b_inData[c9_i301] = (*(char_T (*)[140])c9_inData)[c9_i301];
  }

  for (c9_i302 = 0; c9_i302 < 140; c9_i302++) {
    c9_u[c9_i302] = c9_b_inData[c9_i302];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 140),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i303;
  real_T c9_b_inData[140];
  int32_T c9_i304;
  real_T c9_u[140];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i303 = 0; c9_i303 < 140; c9_i303++) {
    c9_b_inData[c9_i303] = (*(real_T (*)[140])c9_inData)[c9_i303];
  }

  for (c9_i304 = 0; c9_i304 < 140; c9_i304++) {
    c9_u[c9_i304] = c9_b_inData[c9_i304];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 140), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i305;
  char_T c9_b_inData[138];
  int32_T c9_i306;
  char_T c9_u[138];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i305 = 0; c9_i305 < 138; c9_i305++) {
    c9_b_inData[c9_i305] = (*(char_T (*)[138])c9_inData)[c9_i305];
  }

  for (c9_i306 = 0; c9_i306 < 138; c9_i306++) {
    c9_u[c9_i306] = c9_b_inData[c9_i306];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i307;
  real_T c9_b_inData[138];
  int32_T c9_i308;
  real_T c9_u[138];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i307 = 0; c9_i307 < 138; c9_i307++) {
    c9_b_inData[c9_i307] = (*(real_T (*)[138])c9_inData)[c9_i307];
  }

  for (c9_i308 = 0; c9_i308 < 138; c9_i308++) {
    c9_u[c9_i308] = c9_b_inData[c9_i308];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i309;
  char_T c9_b_inData[117];
  int32_T c9_i310;
  char_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i309 = 0; c9_i309 < 117; c9_i309++) {
    c9_b_inData[c9_i309] = (*(char_T (*)[117])c9_inData)[c9_i309];
  }

  for (c9_i310 = 0; c9_i310 < 117; c9_i310++) {
    c9_u[c9_i310] = c9_b_inData[c9_i310];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 117),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i311;
  real_T c9_b_inData[117];
  int32_T c9_i312;
  real_T c9_u[117];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i311 = 0; c9_i311 < 117; c9_i311++) {
    c9_b_inData[c9_i311] = (*(real_T (*)[117])c9_inData)[c9_i311];
  }

  for (c9_i312 = 0; c9_i312 < 117; c9_i312++) {
    c9_u[c9_i312] = c9_b_inData[c9_i312];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 117), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i313;
  char_T c9_b_inData[139];
  int32_T c9_i314;
  char_T c9_u[139];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i313 = 0; c9_i313 < 139; c9_i313++) {
    c9_b_inData[c9_i313] = (*(char_T (*)[139])c9_inData)[c9_i313];
  }

  for (c9_i314 = 0; c9_i314 < 139; c9_i314++) {
    c9_u[c9_i314] = c9_b_inData[c9_i314];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 139),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i315;
  real_T c9_b_inData[139];
  int32_T c9_i316;
  real_T c9_u[139];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i315 = 0; c9_i315 < 139; c9_i315++) {
    c9_b_inData[c9_i315] = (*(real_T (*)[139])c9_inData)[c9_i315];
  }

  for (c9_i316 = 0; c9_i316 < 139; c9_i316++) {
    c9_u[c9_i316] = c9_b_inData[c9_i316];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 139), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i317;
  char_T c9_b_inData[237];
  int32_T c9_i318;
  char_T c9_u[237];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i317 = 0; c9_i317 < 237; c9_i317++) {
    c9_b_inData[c9_i317] = (*(char_T (*)[237])c9_inData)[c9_i317];
  }

  for (c9_i318 = 0; c9_i318 < 237; c9_i318++) {
    c9_u[c9_i318] = c9_b_inData[c9_i318];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 237),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i319;
  real_T c9_b_inData[237];
  int32_T c9_i320;
  real_T c9_u[237];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i319 = 0; c9_i319 < 237; c9_i319++) {
    c9_b_inData[c9_i319] = (*(real_T (*)[237])c9_inData)[c9_i319];
  }

  for (c9_i320 = 0; c9_i320 < 237; c9_i320++) {
    c9_u[c9_i320] = c9_b_inData[c9_i320];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 237), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i321;
  char_T c9_b_inData[142];
  int32_T c9_i322;
  char_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i321 = 0; c9_i321 < 142; c9_i321++) {
    c9_b_inData[c9_i321] = (*(char_T (*)[142])c9_inData)[c9_i321];
  }

  for (c9_i322 = 0; c9_i322 < 142; c9_i322++) {
    c9_u[c9_i322] = c9_b_inData[c9_i322];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i323;
  real_T c9_b_inData[142];
  int32_T c9_i324;
  real_T c9_u[142];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i323 = 0; c9_i323 < 142; c9_i323++) {
    c9_b_inData[c9_i323] = (*(real_T (*)[142])c9_inData)[c9_i323];
  }

  for (c9_i324 = 0; c9_i324 < 142; c9_i324++) {
    c9_u[c9_i324] = c9_b_inData[c9_i324];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i325;
  char_T c9_b_inData[185];
  int32_T c9_i326;
  char_T c9_u[185];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i325 = 0; c9_i325 < 185; c9_i325++) {
    c9_b_inData[c9_i325] = (*(char_T (*)[185])c9_inData)[c9_i325];
  }

  for (c9_i326 = 0; c9_i326 < 185; c9_i326++) {
    c9_u[c9_i326] = c9_b_inData[c9_i326];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 185),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i327;
  real_T c9_b_inData[185];
  int32_T c9_i328;
  real_T c9_u[185];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i327 = 0; c9_i327 < 185; c9_i327++) {
    c9_b_inData[c9_i327] = (*(real_T (*)[185])c9_inData)[c9_i327];
  }

  for (c9_i328 = 0; c9_i328 < 185; c9_i328++) {
    c9_u[c9_i328] = c9_b_inData[c9_i328];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 185), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i329;
  char_T c9_b_inData[143];
  int32_T c9_i330;
  char_T c9_u[143];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i329 = 0; c9_i329 < 143; c9_i329++) {
    c9_b_inData[c9_i329] = (*(char_T (*)[143])c9_inData)[c9_i329];
  }

  for (c9_i330 = 0; c9_i330 < 143; c9_i330++) {
    c9_u[c9_i330] = c9_b_inData[c9_i330];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 143),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i331;
  real_T c9_b_inData[143];
  int32_T c9_i332;
  real_T c9_u[143];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i331 = 0; c9_i331 < 143; c9_i331++) {
    c9_b_inData[c9_i331] = (*(real_T (*)[143])c9_inData)[c9_i331];
  }

  for (c9_i332 = 0; c9_i332 < 143; c9_i332++) {
    c9_u[c9_i332] = c9_b_inData[c9_i332];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 143), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i333;
  char_T c9_b_inData[87];
  int32_T c9_i334;
  char_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i333 = 0; c9_i333 < 87; c9_i333++) {
    c9_b_inData[c9_i333] = (*(char_T (*)[87])c9_inData)[c9_i333];
  }

  for (c9_i334 = 0; c9_i334 < 87; c9_i334++) {
    c9_u[c9_i334] = c9_b_inData[c9_i334];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i335;
  real_T c9_b_inData[87];
  int32_T c9_i336;
  real_T c9_u[87];
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i335 = 0; c9_i335 < 87; c9_i335++) {
    c9_b_inData[c9_i335] = (*(real_T (*)[87])c9_inData)[c9_i335];
  }

  for (c9_i336 = 0; c9_i336 < 87; c9_i336++) {
    c9_u[c9_i336] = c9_b_inData[c9_i336];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray
  *sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 31, 1),
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/30-6-2015-v2-Matlab-M+M/encStr2Arr.m"),
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

static void c9_activate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  chartInstance->c9_sfEvent = c9_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_deactivate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c9_event_secs,
               chartInstance->c9_sfEvent);
}

static void c9_increment_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c9_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c9_temporalCounter_i1++;
  }

  if (chartInstance->c9_temporalCounter_i2 < 15U) {
    chartInstance->c9_temporalCounter_i2 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i2 + 1);
  }

  if (chartInstance->c9_temporalCounter_i3 < 7U) {
    chartInstance->c9_temporalCounter_i3 = (uint8_T)(int16_T)
      (chartInstance->c9_temporalCounter_i3 + 1);
  }
}

static void c9_reset_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBr
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

void
  sf_exported_auto_activate_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_activate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_increment_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtom(chartInstance);
}

void
  sf_exported_auto_resetTemporalCounter_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_reset_counters_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBr(chartInstance);
}

void
  sf_exported_auto_deactivate_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_deactivate_secsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm(chartInstance);
}

boolean_T
  sf_exported_auto_isStablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  return chartInstance->c9_isStable;
}

void
  sf_exported_auto_duringc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile(chartInstance);
}

void
  sf_exported_auto_enterc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendBML(chartInstance);
  c9_enter_atomic_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit(chartInstance);
  c9_enter_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradIm(chartInstance);
}

void
  sf_exported_auto_exitc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_exit_internal_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImi(chartInstance);
  c9_b_sendBML(chartInstance);
}

void
  sf_exported_auto_gatewayc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void
  sf_exported_auto_enablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_sendBML(chartInstance);
}

void
  sf_exported_auto_disablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_b_sendBML(chartInstance);
}

void
  sf_exported_auto_stepBuffersc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_initBuffersc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_activate_callc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  chartInstance->c9_sfEvent = CALL_EVENT;
}

void
  sf_exported_auto_increment_call_counterc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_reset_call_counterc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_deactivate_callc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
}

void
  sf_exported_auto_initc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_initc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile(chartInstance);
}

const mxArray
  *sf_exported_auto_getSimstatec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  const mxArray *c9_out = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_out = NULL;
  sf_mex_assign(&c9_out,
                sf_internal_get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
                (c9_S), false);
  return c9_out;
}

void
  sf_exported_auto_setSimstatec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S, const mxArray *c9_in)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  sf_internal_set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    (c9_S, sf_mex_dup(c9_in));
  sf_mex_destroy(&c9_in);
}

void
  sf_exported_auto_check_state_inconsistency_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *c9_S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_sendBMLc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmi
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_arg[256])
{
  int32_T c9_i337;
  int32_T c9_i338;
  int32_T c9_i339;
  real_T (*c9_b_arg)[256];
  c9_b_arg = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 2);
  for (c9_i337 = 0; c9_i337 < 256; c9_i337++) {
    _SFD_DATA_RANGE_CHECK(c9_arg[c9_i337], 19U);
  }

  _SFD_SET_DATA_VALUE_PTR(19U, c9_arg);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("arg", c9_arg, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
  for (c9_i338 = 0; c9_i338 < 256; c9_i338++) {
    (*c9_b_arg)[c9_i338] = c9_arg[c9_i338];
  }

  for (c9_i339 = 0; c9_i339 < 256; c9_i339++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_arg)[c9_i339], 19U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(19U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
}

static void c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[27];
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
  real_T c9_nargout = 1.0;
  real_T c9_dv48[256];
  int32_T c9_i340;
  int32_T c9_i341;
  int32_T c9_i342;
  int32_T c9_i343;
  int32_T c9_i344;
  int32_T c9_i345;
  int32_T c9_i346;
  int32_T c9_i347;
  int32_T c9_i348;
  int32_T c9_i349;
  int32_T c9_i350;
  int32_T c9_i351;
  int32_T c9_i352;
  int32_T c9_i353;
  int32_T c9_i354;
  int32_T c9_i355;
  int32_T c9_i356;
  int32_T c9_i357;
  int32_T c9_i358;
  int32_T c9_i359;
  int32_T c9_i360;
  int32_T c9_i361;
  int32_T c9_i362;
  int32_T c9_i363;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c9_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 23U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 24U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 25U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 26U, c9_sf_marshallOut,
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
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 21);
  c9_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 22);
  c9_aVarTruthTableCondition_20 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 23);
  c9_aVarTruthTableCondition_21 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 24);
  c9_aVarTruthTableCondition_22 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 25);
  c9_aVarTruthTableCondition_23 = false;
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 29);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 32);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 35);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 38);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 41);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 44);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 47);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 50);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 53);
  c9_aVarTruthTableCondition_9 = (c9_bmlID == 9.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 56);
  c9_aVarTruthTableCondition_10 = (c9_bmlID == 10.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 59);
  c9_aVarTruthTableCondition_11 = (c9_bmlID == 11.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 62);
  c9_aVarTruthTableCondition_12 = (c9_bmlID == 12.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 65);
  c9_aVarTruthTableCondition_13 = (c9_bmlID == 13.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 68);
  c9_aVarTruthTableCondition_14 = (c9_bmlID == 14.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 71);
  c9_aVarTruthTableCondition_15 = (c9_bmlID == 15.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 74);
  c9_aVarTruthTableCondition_16 = (c9_bmlID == 16.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 78);
  c9_aVarTruthTableCondition_17 = (c9_bmlID == 17.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 82);
  c9_aVarTruthTableCondition_18 = (c9_bmlID == 18.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 86);
  c9_aVarTruthTableCondition_19 = (c9_bmlID == 19.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 90);
  c9_aVarTruthTableCondition_20 = (c9_bmlID == 20.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 94);
  c9_aVarTruthTableCondition_21 = (c9_bmlID == 21.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 98);
  c9_aVarTruthTableCondition_22 = (c9_bmlID == 22.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 102);
  c9_aVarTruthTableCondition_23 = (c9_bmlID == 23.0);
  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 104);
  if (CV_EML_IF(2, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 105);
    CV_EML_FCN(2, 1);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 158U);
    c9_encStr2Arr(chartInstance, c9_dv48);
    for (c9_i340 = 0; c9_i340 < 256; c9_i340++) {
      c9_gazeBML[c9_i340] = c9_dv48[c9_i340];
    }

    c9_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -158);
  } else {
    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 106);
    if (CV_EML_IF(2, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 107);
      CV_EML_FCN(2, 2);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 164U);
      c9_b_encStr2Arr(chartInstance, c9_dv48);
      for (c9_i341 = 0; c9_i341 < 256; c9_i341++) {
        c9_gazeBML[c9_i341] = c9_dv48[c9_i341];
      }

      c9_updateDataWrittenToVector(chartInstance, 3U);
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -164);
    } else {
      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 108);
      if (CV_EML_IF(2, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 109);
        CV_EML_FCN(2, 3);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 170U);
        c9_c_encStr2Arr(chartInstance, c9_dv48);
        for (c9_i342 = 0; c9_i342 < 256; c9_i342++) {
          c9_gazeBML[c9_i342] = c9_dv48[c9_i342];
        }

        c9_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -170);
      } else {
        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 110);
        if (CV_EML_IF(2, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 111);
          CV_EML_FCN(2, 4);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 176U);
          c9_d_encStr2Arr(chartInstance, c9_dv48);
          for (c9_i343 = 0; c9_i343 < 256; c9_i343++) {
            c9_gazeBML[c9_i343] = c9_dv48[c9_i343];
          }

          c9_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -176);
        } else {
          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 112);
          if (CV_EML_IF(2, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 113);
            CV_EML_FCN(2, 5);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 182U);
            c9_e_encStr2Arr(chartInstance, c9_dv48);
            for (c9_i344 = 0; c9_i344 < 256; c9_i344++) {
              c9_gazeBML[c9_i344] = c9_dv48[c9_i344];
            }

            c9_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -182);
          } else {
            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 114);
            if (CV_EML_IF(2, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 115);
              CV_EML_FCN(2, 6);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 188U);
              c9_f_encStr2Arr(chartInstance, c9_dv48);
              for (c9_i345 = 0; c9_i345 < 256; c9_i345++) {
                c9_gazeBML[c9_i345] = c9_dv48[c9_i345];
              }

              c9_updateDataWrittenToVector(chartInstance, 3U);
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -188);
            } else {
              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 116);
              if (CV_EML_IF(2, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 117);
                CV_EML_FCN(2, 7);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 194U);
                c9_g_encStr2Arr(chartInstance, c9_dv48);
                for (c9_i346 = 0; c9_i346 < 256; c9_i346++) {
                  c9_gazeBML[c9_i346] = c9_dv48[c9_i346];
                }

                c9_updateDataWrittenToVector(chartInstance, 3U);
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -194);
              } else {
                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 118);
                if (CV_EML_IF(2, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 119);
                  CV_EML_FCN(2, 8);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 200U);
                  c9_h_encStr2Arr(chartInstance, c9_dv48);
                  for (c9_i347 = 0; c9_i347 < 256; c9_i347++) {
                    c9_gazeBML[c9_i347] = c9_dv48[c9_i347];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 3U);
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -200);
                } else {
                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 120);
                  if (CV_EML_IF(2, 1, 8, c9_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 121);
                    CV_EML_FCN(2, 11);
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 218U);
                    c9_i_encStr2Arr(chartInstance, c9_dv48);
                    for (c9_i348 = 0; c9_i348 < 256; c9_i348++) {
                      c9_gazeBML[c9_i348] = c9_dv48[c9_i348];
                    }

                    c9_updateDataWrittenToVector(chartInstance, 3U);
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -218);
                  } else {
                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 122);
                    if (CV_EML_IF(2, 1, 9, c9_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 123);
                      CV_EML_FCN(2, 9);
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 206U);
                      c9_j_encStr2Arr(chartInstance, c9_dv48);
                      for (c9_i349 = 0; c9_i349 < 256; c9_i349++) {
                        c9_gazeBML[c9_i349] = c9_dv48[c9_i349];
                      }

                      c9_updateDataWrittenToVector(chartInstance, 3U);
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -206);
                    } else {
                      _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 124);
                      if (CV_EML_IF(2, 1, 10, c9_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 125);
                        CV_EML_FCN(2, 10);
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 212U);
                        c9_k_encStr2Arr(chartInstance, c9_dv48);
                        for (c9_i350 = 0; c9_i350 < 256; c9_i350++) {
                          c9_gazeBML[c9_i350] = c9_dv48[c9_i350];
                        }

                        c9_updateDataWrittenToVector(chartInstance, 3U);
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -212);
                      } else {
                        _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 126);
                        if (CV_EML_IF(2, 1, 11, c9_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                        MAX_int8_T);
                          CV_EML_FCN(2, 12);
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 224U);
                          c9_l_encStr2Arr(chartInstance, c9_dv48);
                          for (c9_i351 = 0; c9_i351 < 256; c9_i351++) {
                            c9_gazeBML[c9_i351] = c9_dv48[c9_i351];
                          }

                          c9_updateDataWrittenToVector(chartInstance, 3U);
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -224);
                        } else {
                          _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 128U);
                          if (CV_EML_IF(2, 1, 12, c9_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 129U);
                            CV_EML_FCN(2, 13);
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 230U);
                            c9_m_encStr2Arr(chartInstance, c9_dv48);
                            for (c9_i352 = 0; c9_i352 < 256; c9_i352++) {
                              c9_gazeBML[c9_i352] = c9_dv48[c9_i352];
                            }

                            c9_updateDataWrittenToVector(chartInstance, 3U);
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -230);
                          } else {
                            _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 130U);
                            if (CV_EML_IF(2, 1, 13,
                                          c9_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 131U);
                              CV_EML_FCN(2, 14);
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 236U);
                              c9_n_encStr2Arr(chartInstance, c9_dv48);
                              for (c9_i353 = 0; c9_i353 < 256; c9_i353++) {
                                c9_gazeBML[c9_i353] = c9_dv48[c9_i353];
                              }

                              c9_updateDataWrittenToVector(chartInstance, 3U);
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -236);
                            } else {
                              _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, 132U);
                              if (CV_EML_IF(2, 1, 14,
                                            c9_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              133U);
                                CV_EML_FCN(2, 15);
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              242U);
                                c9_o_encStr2Arr(chartInstance, c9_dv48);
                                for (c9_i354 = 0; c9_i354 < 256; c9_i354++) {
                                  c9_gazeBML[c9_i354] = c9_dv48[c9_i354];
                                }

                                c9_updateDataWrittenToVector(chartInstance, 3U);
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              -242);
                              } else {
                                _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                              134U);
                                if (CV_EML_IF(2, 1, 15,
                                              c9_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                135U);
                                  CV_EML_FCN(2, 16);
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                248U);
                                  c9_p_encStr2Arr(chartInstance, c9_dv48);
                                  for (c9_i355 = 0; c9_i355 < 256; c9_i355++) {
                                    c9_gazeBML[c9_i355] = c9_dv48[c9_i355];
                                  }

                                  c9_updateDataWrittenToVector(chartInstance, 3U);
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                -248);
                                } else {
                                  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                136U);
                                  if (CV_EML_IF(2, 1, 16,
                                                c9_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  137U);
                                    CV_EML_FCN(2, 17);
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  254U);
                                    c9_q_encStr2Arr(chartInstance, c9_dv48);
                                    for (c9_i356 = 0; c9_i356 < 256; c9_i356++)
                                    {
                                      c9_gazeBML[c9_i356] = c9_dv48[c9_i356];
                                    }

                                    c9_updateDataWrittenToVector(chartInstance,
                                      3U);
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  -254);
                                  } else {
                                    _SFD_EML_CALL(2U, chartInstance->c9_sfEvent,
                                                  138U);
                                    if (CV_EML_IF(2, 1, 17,
                                                  c9_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    139U);
                                      CV_EML_FCN(2, 18);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    260);
                                      c9_r_encStr2Arr(chartInstance, c9_dv48);
                                      for (c9_i357 = 0; c9_i357 < 256; c9_i357++)
                                      {
                                        c9_gazeBML[c9_i357] = c9_dv48[c9_i357];
                                      }

                                      c9_updateDataWrittenToVector(chartInstance,
                                        3U);
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    -260);
                                    } else {
                                      _SFD_EML_CALL(2U,
                                                    chartInstance->c9_sfEvent,
                                                    140U);
                                      if (CV_EML_IF(2, 1, 18,
                                                    c9_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(2U,
                                                      chartInstance->c9_sfEvent,
                                                      141U);
                                        CV_EML_FCN(2, 19);
                                        _SFD_EML_CALL(2U,
                                                      chartInstance->c9_sfEvent,
                                                      266);
                                        c9_s_encStr2Arr(chartInstance, c9_dv48);
                                        for (c9_i358 = 0; c9_i358 < 256; c9_i358
                                             ++) {
                                          c9_gazeBML[c9_i358] = c9_dv48[c9_i358];
                                        }

                                        c9_updateDataWrittenToVector
                                          (chartInstance, 3U);
                                        _SFD_EML_CALL(2U,
                                                      chartInstance->c9_sfEvent,
                                                      -266);
                                      } else {
                                        _SFD_EML_CALL(2U,
                                                      chartInstance->c9_sfEvent,
                                                      142U);
                                        if (CV_EML_IF(2, 1, 19,
                                                      c9_aVarTruthTableCondition_20))
                                        {
                                          _SFD_EML_CALL(2U,
                                                        chartInstance->c9_sfEvent,
                                                        143U);
                                          CV_EML_FCN(2, 20);
                                          _SFD_EML_CALL(2U,
                                                        chartInstance->c9_sfEvent,
                                                        272);
                                          c9_t_encStr2Arr(chartInstance, c9_dv48);
                                          for (c9_i359 = 0; c9_i359 < 256;
                                               c9_i359++) {
                                            c9_gazeBML[c9_i359] =
                                              c9_dv48[c9_i359];
                                          }

                                          c9_updateDataWrittenToVector
                                            (chartInstance, 3U);
                                          _SFD_EML_CALL(2U,
                                                        chartInstance->c9_sfEvent,
                                                        -272);
                                        } else {
                                          _SFD_EML_CALL(2U,
                                                        chartInstance->c9_sfEvent,
                                                        144U);
                                          if (CV_EML_IF(2, 1, 20,
                                                        c9_aVarTruthTableCondition_21))
                                          {
                                            _SFD_EML_CALL(2U,
                                                          chartInstance->c9_sfEvent,
                                                          145U);
                                            CV_EML_FCN(2, 21);
                                            _SFD_EML_CALL(2U,
                                                          chartInstance->c9_sfEvent,
                                                          278);
                                            c9_u_encStr2Arr(chartInstance,
                                                            c9_dv48);
                                            for (c9_i360 = 0; c9_i360 < 256;
                                                 c9_i360++) {
                                              c9_gazeBML[c9_i360] =
                                                c9_dv48[c9_i360];
                                            }

                                            c9_updateDataWrittenToVector
                                              (chartInstance, 3U);
                                            _SFD_EML_CALL(2U,
                                                          chartInstance->c9_sfEvent,
                                                          -278);
                                          } else {
                                            _SFD_EML_CALL(2U,
                                                          chartInstance->c9_sfEvent,
                                                          146U);
                                            if (CV_EML_IF(2, 1, 21,
                                                          c9_aVarTruthTableCondition_22))
                                            {
                                              _SFD_EML_CALL(2U,
                                                            chartInstance->c9_sfEvent,
                                                            147U);
                                              CV_EML_FCN(2, 22);
                                              _SFD_EML_CALL(2U,
                                                            chartInstance->c9_sfEvent,
                                                            284);
                                              c9_v_encStr2Arr(chartInstance,
                                                c9_dv48);
                                              for (c9_i361 = 0; c9_i361 < 256;
                                                   c9_i361++) {
                                                c9_gazeBML[c9_i361] =
                                                  c9_dv48[c9_i361];
                                              }

                                              c9_updateDataWrittenToVector
                                                (chartInstance, 3U);
                                              _SFD_EML_CALL(2U,
                                                            chartInstance->c9_sfEvent,
                                                            -284);
                                            } else {
                                              _SFD_EML_CALL(2U,
                                                            chartInstance->c9_sfEvent,
                                                            148U);
                                              if (CV_EML_IF(2, 1, 22,
                                                            c9_aVarTruthTableCondition_23))
                                              {
                                                _SFD_EML_CALL(2U,
                                                  chartInstance->c9_sfEvent,
                                                  149U);
                                                CV_EML_FCN(2, 23);
                                                _SFD_EML_CALL(2U,
                                                  chartInstance->c9_sfEvent, 290);
                                                c9_w_encStr2Arr(chartInstance,
                                                  c9_dv48);
                                                for (c9_i362 = 0; c9_i362 < 256;
                                                     c9_i362++) {
                                                  c9_gazeBML[c9_i362] =
                                                    c9_dv48[c9_i362];
                                                }

                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 3U);
                                                _SFD_EML_CALL(2U,
                                                  chartInstance->c9_sfEvent,
                                                  -290);
                                              } else {
                                                _SFD_EML_CALL(2U,
                                                  chartInstance->c9_sfEvent,
                                                  151U);
                                                CV_EML_FCN(2, 1);
                                                _SFD_EML_CALL(2U,
                                                  chartInstance->c9_sfEvent,
                                                  158U);
                                                c9_encStr2Arr(chartInstance,
                                                  c9_dv48);
                                                for (c9_i363 = 0; c9_i363 < 256;
                                                     c9_i363++) {
                                                  c9_gazeBML[c9_i363] =
                                                    c9_dv48[c9_i363];
                                                }

                                                c9_updateDataWrittenToVector
                                                  (chartInstance, 3U);
                                                _SFD_EML_CALL(2U,
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

  _SFD_EML_CALL(2U, chartInstance->c9_sfEvent, -151);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_idleGazeInterestedTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[12];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  boolean_T c9_aVarTruthTableCondition_4;
  boolean_T c9_aVarTruthTableCondition_5;
  boolean_T c9_aVarTruthTableCondition_6;
  boolean_T c9_aVarTruthTableCondition_7;
  boolean_T c9_aVarTruthTableCondition_8;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv49[256];
  int32_T c9_i364;
  int32_T c9_i365;
  int32_T c9_i366;
  int32_T c9_i367;
  int32_T c9_i368;
  int32_T c9_i369;
  int32_T c9_i370;
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
  int32_T c9_i371;
  static char_T c9_cv36[139] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'P', 'O', 'L', 'A', 'R', '\"', ' ', 's', 'b',
    'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"',
    'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-',
    'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i372;
  static real_T c9_dv50[139] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i373;
  int32_T c9_i374;
  int32_T c9_i375;
  int32_T c9_i376;
  int32_T c9_i377;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c9_y_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_bmlID, 10U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 11U, c9_sf_marshallOut,
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
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 7);
  c9_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 8);
  c9_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 9);
  c9_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 17);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 20);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 23);
  c9_aVarTruthTableCondition_4 = (c9_bmlID == 4.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 26);
  c9_aVarTruthTableCondition_5 = (c9_bmlID == 5.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 29);
  c9_aVarTruthTableCondition_6 = (c9_bmlID == 6.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 32);
  c9_aVarTruthTableCondition_7 = (c9_bmlID == 7.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 35);
  c9_aVarTruthTableCondition_8 = (c9_bmlID == 8.0);
  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 37);
  if (CV_EML_IF(1, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 38);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 61);
    c9_x_encStr2Arr(chartInstance, c9_dv49);
    for (c9_i364 = 0; c9_i364 < 256; c9_i364++) {
      c9_gazeBML[c9_i364] = c9_dv49[c9_i364];
    }

    c9_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -61);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 39);
    if (CV_EML_IF(1, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 40);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 67);
      c9_y_encStr2Arr(chartInstance, c9_dv49);
      for (c9_i365 = 0; c9_i365 < 256; c9_i365++) {
        c9_gazeBML[c9_i365] = c9_dv49[c9_i365];
      }

      c9_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -67);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 41);
      if (CV_EML_IF(1, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 42);
        CV_EML_FCN(1, 3);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 73);
        c9_ab_encStr2Arr(chartInstance, c9_dv49);
        for (c9_i366 = 0; c9_i366 < 256; c9_i366++) {
          c9_gazeBML[c9_i366] = c9_dv49[c9_i366];
        }

        c9_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -73);
      } else {
        _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 43);
        if (CV_EML_IF(1, 1, 3, c9_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 44);
          CV_EML_FCN(1, 4);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 79);
          c9_bb_encStr2Arr(chartInstance, c9_dv49);
          for (c9_i367 = 0; c9_i367 < 256; c9_i367++) {
            c9_gazeBML[c9_i367] = c9_dv49[c9_i367];
          }

          c9_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -79);
        } else {
          _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 45);
          if (CV_EML_IF(1, 1, 4, c9_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 46);
            CV_EML_FCN(1, 5);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 85);
            c9_cb_encStr2Arr(chartInstance, c9_dv49);
            for (c9_i368 = 0; c9_i368 < 256; c9_i368++) {
              c9_gazeBML[c9_i368] = c9_dv49[c9_i368];
            }

            c9_updateDataWrittenToVector(chartInstance, 4U);
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -85);
          } else {
            _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 47);
            if (CV_EML_IF(1, 1, 5, c9_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 48);
              CV_EML_FCN(1, 6);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 91);
              c9_db_encStr2Arr(chartInstance, c9_dv49);
              for (c9_i369 = 0; c9_i369 < 256; c9_i369++) {
                c9_gazeBML[c9_i369] = c9_dv49[c9_i369];
              }

              c9_updateDataWrittenToVector(chartInstance, 4U);
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -91);
            } else {
              _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 49);
              if (CV_EML_IF(1, 1, 6, c9_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 50);
                CV_EML_FCN(1, 7);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 97);
                c9_eb_encStr2Arr(chartInstance, c9_dv49);
                for (c9_i370 = 0; c9_i370 < 256; c9_i370++) {
                  c9_gazeBML[c9_i370] = c9_dv49[c9_i370];
                }

                c9_updateDataWrittenToVector(chartInstance, 4U);
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -97);
              } else {
                _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 51);
                if (CV_EML_IF(1, 1, 7, c9_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 52);
                  CV_EML_FCN(1, 8);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 103);
                  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U,
                    c9_hb_debug_family_names, c9_b_debug_family_var_map);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
                    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_sb_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
                    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U,
                    c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_rb_sf_marshallOut);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
                    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
                    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
                  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
                    c9_d_sf_marshallOut, c9_d_sf_marshallIn);
                  for (c9_i371 = 0; c9_i371 < 139; c9_i371++) {
                    c9_mystr[c9_i371] = c9_cv36[c9_i371];
                  }

                  CV_SCRIPT_FCN(0, 0);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
                  c9_maxarrsize = 256.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
                  for (c9_i372 = 0; c9_i372 < 139; c9_i372++) {
                    c9_arr[c9_i372] = c9_dv50[c9_i372];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
                  c9_ss = 139.0;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
                  c9_padsize = c9_maxarrsize - c9_ss;
                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
                  for (c9_i373 = 0; c9_i373 < 256; c9_i373++) {
                    c9_tt[c9_i373] = 0.0;
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
                  for (c9_i374 = 0; c9_i374 < 139; c9_i374++) {
                    c9_tt[c9_i374] = c9_arr[c9_i374];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
                  for (c9_i375 = 0; c9_i375 < 256; c9_i375++) {
                    c9_myarr256[c9_i375] = c9_tt[c9_i375];
                  }

                  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
                  _SFD_SYMBOL_SCOPE_POP();
                  for (c9_i376 = 0; c9_i376 < 256; c9_i376++) {
                    c9_gazeBML[c9_i376] = c9_myarr256[c9_i376];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 4U);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -103);
                } else {
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 54);
                  CV_EML_FCN(1, 1);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, 61);
                  c9_x_encStr2Arr(chartInstance, c9_dv49);
                  for (c9_i377 = 0; c9_i377 < 256; c9_i377++) {
                    c9_gazeBML[c9_i377] = c9_dv49[c9_i377];
                  }

                  c9_updateDataWrittenToVector(chartInstance, 4U);
                  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -61);
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c9_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_poseBML[256])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv51[256];
  int32_T c9_i378;
  int32_T c9_i379;
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
  int32_T c9_i380;
  static char_T c9_cv37[185] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
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

  int32_T c9_i381;
  static real_T c9_dv52[185] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
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

  int32_T c9_i382;
  int32_T c9_i383;
  int32_T c9_i384;
  int32_T c9_i385;
  int32_T c9_i386;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_ib_debug_family_names,
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
  CV_EML_FCN(20, 0);
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 3);
  c9_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 4);
  c9_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 5);
  c9_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 10);
  c9_aVarTruthTableCondition_1 = (c9_bmlID == 1.0);
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 14);
  c9_aVarTruthTableCondition_2 = (c9_bmlID == 2.0);
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 18);
  c9_aVarTruthTableCondition_3 = (c9_bmlID == 3.0);
  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 20);
  if (CV_EML_IF(20, 1, 0, c9_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 21);
    CV_EML_FCN(20, 1);
    _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 34);
    c9_fb_encStr2Arr(chartInstance, c9_dv51);
    for (c9_i378 = 0; c9_i378 < 256; c9_i378++) {
      c9_poseBML[c9_i378] = c9_dv51[c9_i378];
    }

    c9_updateDataWrittenToVector(chartInstance, 5U);
    _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, -34);
  } else {
    _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 22);
    if (CV_EML_IF(20, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 23);
      CV_EML_FCN(20, 2);
      _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 40);
      c9_gb_encStr2Arr(chartInstance, c9_dv51);
      for (c9_i379 = 0; c9_i379 < 256; c9_i379++) {
        c9_poseBML[c9_i379] = c9_dv51[c9_i379];
      }

      c9_updateDataWrittenToVector(chartInstance, 5U);
      _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, -40);
    } else {
      _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 24);
      if (CV_EML_IF(20, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 25);
        CV_EML_FCN(20, 3);
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 46);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_lb_debug_family_names,
          c9_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_yb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
          c9_d_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_xb_sf_marshallOut);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
          c9_b_sf_marshallOut, c9_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U,
          c9_d_sf_marshallOut, c9_d_sf_marshallIn);
        for (c9_i380 = 0; c9_i380 < 185; c9_i380++) {
          c9_mystr[c9_i380] = c9_cv37[c9_i380];
        }

        CV_SCRIPT_FCN(0, 0);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
        c9_maxarrsize = 256.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
        for (c9_i381 = 0; c9_i381 < 185; c9_i381++) {
          c9_arr[c9_i381] = c9_dv52[c9_i381];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
        c9_ss = 185.0;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
        c9_padsize = c9_maxarrsize - c9_ss;
        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
        for (c9_i382 = 0; c9_i382 < 256; c9_i382++) {
          c9_tt[c9_i382] = 0.0;
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
        for (c9_i383 = 0; c9_i383 < 185; c9_i383++) {
          c9_tt[c9_i383] = c9_arr[c9_i383];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
        for (c9_i384 = 0; c9_i384 < 256; c9_i384++) {
          c9_myarr256[c9_i384] = c9_tt[c9_i384];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
        _SFD_SYMBOL_SCOPE_POP();
        for (c9_i385 = 0; c9_i385 < 256; c9_i385++) {
          c9_poseBML[c9_i385] = c9_myarr256[c9_i385];
        }

        c9_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, -46);
      } else {
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 27);
        CV_EML_FCN(20, 1);
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, 34);
        c9_fb_encStr2Arr(chartInstance, c9_dv51);
        for (c9_i386 = 0; c9_i386 < 256; c9_i386++) {
          c9_poseBML[c9_i386] = c9_dv51[c9_i386];
        }

        c9_updateDataWrittenToVector(chartInstance, 5U);
        _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, -34);
      }
    }
  }

  _SFD_EML_CALL(20U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_gazeFollowUserMovec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBra
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  uint32_T c9_debug_family_var_map[7];
  boolean_T c9_aVarTruthTableCondition_1;
  boolean_T c9_aVarTruthTableCondition_2;
  boolean_T c9_aVarTruthTableCondition_3;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_dv53[256];
  int32_T c9_i387;
  uint32_T c9_b_debug_family_var_map[9];
  real_T c9_maxarrsize;
  real_T c9_arr[143];
  real_T c9_ss;
  real_T c9_padsize;
  real_T c9_tt[256];
  char_T c9_mystr[143];
  real_T c9_b_nargin = 1.0;
  real_T c9_b_nargout = 1.0;
  real_T c9_myarr256[256];
  int32_T c9_i388;
  static char_T c9_cv38[143] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '2', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'L', 'E', 'F', 'T', '\"', ' ', 's', 'b', 'm',
    ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H',
    'E', 'A', 'D', ' ', 'B', 'A', 'C', 'K', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', ' ',
    't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c9_i389;
  static real_T c9_dv54[143] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 50.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 76.0, 69.0, 70.0, 84.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0,
    97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 66.0,
    65.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0,
    32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0,
    101.0, 114.0, 97.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c9_i390;
  int32_T c9_i391;
  int32_T c9_i392;
  int32_T c9_i393;
  int32_T c9_i394;
  int32_T c9_i395;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_mb_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_gazeBML, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
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
    c9_hb_encStr2Arr(chartInstance, c9_dv53);
    for (c9_i387 = 0; c9_i387 < 256; c9_i387++) {
      c9_gazeBML[c9_i387] = c9_dv53[c9_i387];
    }

    c9_updateDataWrittenToVector(chartInstance, 6U);
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -34);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
    if (CV_EML_IF(0, 1, 1, c9_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
      CV_EML_FCN(0, 2);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 40);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_ob_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_maxarrsize, 0U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_arr, 1U, c9_bc_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c9_ss, 2U, c9_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_padsize, 3U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_tt, 4U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c9_mystr, 5U, c9_ac_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 6U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 7U,
        c9_b_sf_marshallOut, c9_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_myarr256, 8U, c9_d_sf_marshallOut,
        c9_d_sf_marshallIn);
      for (c9_i388 = 0; c9_i388 < 143; c9_i388++) {
        c9_mystr[c9_i388] = c9_cv38[c9_i388];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
      c9_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
      for (c9_i389 = 0; c9_i389 < 143; c9_i389++) {
        c9_arr[c9_i389] = c9_dv54[c9_i389];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 7);
      c9_ss = 143.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
      c9_padsize = c9_maxarrsize - c9_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
      for (c9_i390 = 0; c9_i390 < 256; c9_i390++) {
        c9_tt[c9_i390] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
      for (c9_i391 = 0; c9_i391 < 143; c9_i391++) {
        c9_tt[c9_i391] = c9_arr[c9_i391];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
      for (c9_i392 = 0; c9_i392 < 256; c9_i392++) {
        c9_myarr256[c9_i392] = c9_tt[c9_i392];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c9_i393 = 0; c9_i393 < 256; c9_i393++) {
        c9_gazeBML[c9_i393] = c9_myarr256[c9_i393];
      }

      c9_updateDataWrittenToVector(chartInstance, 6U);
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -40);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
      if (CV_EML_IF(0, 1, 2, c9_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        c9_ib_encStr2Arr(chartInstance, c9_dv53);
        for (c9_i394 = 0; c9_i394 < 256; c9_i394++) {
          c9_gazeBML[c9_i394] = c9_dv53[c9_i394];
        }

        c9_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -46);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
        CV_EML_FCN(0, 3);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 46);
        c9_ib_encStr2Arr(chartInstance, c9_dv53);
        for (c9_i395 = 0; c9_i395 < 256; c9_i395++) {
          c9_gazeBML[c9_i395] = c9_dv53[c9_i395];
        }

        c9_updateDataWrittenToVector(chartInstance, 6U);
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -46);
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_sendBML
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c9_b_sendBML
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void
  sf_exported_user_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_gazeFollowUserMove
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_gazeFollowUserMovec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBra(chartInstance,
    c9_bmlID, c9_gazeBML);
}

void
  sf_exported_user_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_idleGazeInterestedTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_idleGazeInterestedTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtom(chartInstance,
    c9_bmlID, c9_gazeBML);
}

void
  sf_exported_user_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_idleGazeTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_gazeBML[256])
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImit(chartInstance,
    c9_bmlID, c9_gazeBML);
}

void
  sf_exported_user_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_sendBML
  (SimStruct *c9_S, real_T c9_arg[256])
{
  int32_T c9_i396;
  real_T c9_b_arg[256];
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  for (c9_i396 = 0; c9_i396 < 256; c9_i396++) {
    c9_b_arg[c9_i396] = c9_arg[c9_i396];
  }

  c9_sendBMLc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmi(chartInstance,
    c9_b_arg);
}

void
  sf_exported_user_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_successTable
  (SimStruct *c9_S, real_T c9_bmlID, real_T c9_poseBML[256])
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    ((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c9_S))->instanceInfo
    )->chartInstance;
  c9_successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImita(chartInstance,
    c9_bmlID, c9_poseBML);
}

static const mxArray *c9_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int8_T c9_f_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int8_T c9_y;
  int8_T c9_i397;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i397, 1, 2, 0U, 0, 0U, 0);
  c9_y = c9_i397;
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
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
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

static const mxArray *c9_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_g_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i398;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i398, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i398;
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
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
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

static const mxArray *c9_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_tp_stateGazeIde, const char_T
   *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateGazeIde),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateGazeIde);
  return c9_y;
}

static uint8_T c9_i_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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
  const mxArray *c9_b_tp_stateGazeIde;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    chartInstanceVoid;
  c9_b_tp_stateGazeIde = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_stateGazeIde),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_stateGazeIde);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint32_T c9_j_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_method, const char_T *c9_identifier)
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
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier)
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
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
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

static void c9_n_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
   uint32_T c9_y[625])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_o_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   uint32_T c9_y[625])
{
  uint32_T c9_uv3[625];
  int32_T c9_i399;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_c_state_not_empty = false;
  } else {
    chartInstance->c9_c_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c9_i399 = 0; c9_i399 < 625; c9_i399++) {
      c9_y[c9_i399] = c9_uv3[c9_i399];
    }
  }

  sf_mex_destroy(&c9_u);
}

static void c9_p_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_d_state, const char_T *c9_identifier,
   uint32_T c9_y[2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_d_state), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_d_state);
}

static void c9_q_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
   uint32_T c9_y[2])
{
  uint32_T c9_uv4[2];
  int32_T c9_i400;
  if (mxIsEmpty(c9_u)) {
    chartInstance->c9_b_state_not_empty = false;
  } else {
    chartInstance->c9_b_state_not_empty = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c9_i400 = 0; c9_i400 < 2; c9_i400++) {
      c9_y[c9_i400] = c9_uv4[c9_i400];
    }
  }

  sf_mex_destroy(&c9_u);
}

static uint32_T c9_r_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
   *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_temporalCounter_i1),
    &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i1);
  return c9_y;
}

static uint32_T c9_s_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u6;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u6, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u6;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_t_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T *
   c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_u_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_u_emlrt_marshallIn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
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

static void c9_updateDataWrittenToVector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 6, 1, 0)] = true;
}

static void c9_errorIfDataNotWrittenToFcn
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 6, 1,
    0)]);
}

static void c9_b_twister_state_vector
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_mt[625], real_T c9_seed)
{
  real_T c9_d5;
  uint32_T c9_u7;
  uint32_T c9_r;
  int32_T c9_mti;
  real_T c9_b_mti;
  real_T c9_d6;
  uint32_T c9_u8;
  (void)chartInstance;
  c9_d5 = c9_seed;
  if (c9_d5 < 4.294967296E+9) {
    if (c9_d5 >= 0.0) {
      c9_u7 = (uint32_T)c9_d5;
    } else {
      c9_u7 = 0U;
    }
  } else if (c9_d5 >= 4.294967296E+9) {
    c9_u7 = MAX_uint32_T;
  } else {
    c9_u7 = 0U;
  }

  c9_r = c9_u7;
  c9_mt[0] = c9_r;
  for (c9_mti = 0; c9_mti < 623; c9_mti++) {
    c9_b_mti = 2.0 + (real_T)c9_mti;
    c9_d6 = muDoubleScalarRound(c9_b_mti - 1.0);
    if (c9_d6 < 4.294967296E+9) {
      if (c9_d6 >= 0.0) {
        c9_u8 = (uint32_T)c9_d6;
      } else {
        c9_u8 = 0U;
      }
    } else if (c9_d6 >= 4.294967296E+9) {
      c9_u8 = MAX_uint32_T;
    } else {
      c9_u8 = 0U;
    }

    c9_r = (c9_r ^ c9_r >> 30U) * 1812433253U + c9_u8;
    c9_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c9_b_mti), 1, 625, 1, 0) - 1] = c9_r;
  }

  c9_mt[624] = 624U;
}

static real_T c9_c_eml_rand_mt19937ar
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_d_state[625])
{
  int32_T c9_i401;
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
    for (c9_i401 = 0; c9_i401 < 2; c9_i401++) {
      c9_u[c9_i401] = 0U;
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
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#385) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_BOREDOM_THRESHOLD_address;
}

static void c9_set_BOREDOM_THRESHOLD
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c9_b);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#385) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_BOREDOM_THRESHOLD_address = c9_c;
}

static real_T *c9_access_BOREDOM_THRESHOLD
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c9_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#385) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_BOREDOM_THRESHOLD_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#393) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_GUI_address;
}

static void c9_set_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c9_b);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#393) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_GUI_address = c9_c;
}

static real_T *c9_access_GAZE_GUI
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c9_GAZE_GUI_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_GUI\' (#393) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_GUI_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#392) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_SHOFTEYE_address;
}

static void c9_set_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c9_b);
  if (chartInstance->c9_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#392) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_SHOFTEYE_address = c9_c;
}

static real_T *c9_access_GAZE_SHOFTEYE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c9_GAZE_SHOFTEYE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_SHOFTEYE\' (#392) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_SHOFTEYE_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#394) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_USER_HAND_address;
}

static void c9_set_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c9_b);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#394) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_USER_HAND_address = c9_c;
}

static real_T *c9_access_GAZE_USER_HAND
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c9_GAZE_USER_HAND_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_USER_HAND\' (#394) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_USER_HAND_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c9_c;
}

static real_T c9_get_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#395) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_GAZE_WIN_address;
}

static void c9_set_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c9_b);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#395) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_GAZE_WIN_address = c9_c;
}

static real_T *c9_access_GAZE_WIN
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c9_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#395) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_GAZE_WIN_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#400) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_BEFORE_address;
}

static void c9_set_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c9_b);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#400) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_BEFORE_address = c9_c;
}

static real_T *c9_access_STATE_BEFORE
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c9_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#400) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_BEFORE_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#401) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_OVER_address;
}

static void c9_set_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c9_b);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#401) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_OVER_address = c9_c;
}

static real_T *c9_access_STATE_OVER
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c9_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#401) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_OVER_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c9_c;
}

static real_T c9_get_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#402) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_STATE_READY_address;
}

static void c9_set_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c9_b);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#402) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_STATE_READY_address = c9_c;
}

static real_T *c9_access_STATE_READY
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c9_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#402) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_STATE_READY_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c9_c;
}

static real_T c9_get_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#399) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_avert_address;
}

static void c9_set_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c9_b);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#399) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_avert_address = c9_c;
}

static real_T *c9_access_avert
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c9_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#399) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_avert_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c9_c;
}

static real_T c9_get_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#384) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_boredom_address;
}

static void c9_set_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c9_b);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#384) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_boredom_address = c9_c;
}

static real_T *c9_access_boredom
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c9_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#384) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_boredom_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c9_c;
}

static real_T c9_get_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#391) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_gazing_address;
}

static void c9_set_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c9_b);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#391) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_gazing_address = c9_c;
}

static real_T *c9_access_gazing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c9_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#391) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_gazing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c9_c;
}

static real_T c9_get_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#389) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_interest_address;
}

static void c9_set_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c9_b);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#389) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_interest_address = c9_c;
}

static real_T *c9_access_interest
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c9_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#389) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_interest_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c9_c;
}

static real_T c9_get_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#388) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_isPosing_address;
}

static void c9_set_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c9_b);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#388) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_isPosing_address = c9_c;
}

static real_T *c9_access_isPosing
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c9_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#388) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_isPosing_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c9_c;
}

static real_T c9_get_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#386) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randAvertGazeChance_address;
}

static void c9_set_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c9_b);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#386) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randAvertGazeChance_address = c9_c;
}

static real_T *c9_access_randAvertGazeChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c9_randAvertGazeChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randAvertGazeChance\' (#386) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randAvertGazeChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c9_c;
}

static real_T c9_get_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#390) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randGazeDur_address;
}

static void c9_set_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c9_b);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#390) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randGazeDur_address = c9_c;
}

static real_T *c9_access_randGazeDur
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c9_randGazeDur_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randGazeDur\' (#390) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randGazeDur_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c9_c;
}

static real_T c9_get_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#387) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c9_randPoseChance_address;
}

static void c9_set_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b, real_T c9_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c9_b);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#387) in the initialization routine of the chart.\n");
  }

  *chartInstance->c9_randPoseChance_address = c9_c;
}

static real_T *c9_access_randPoseChance
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c9_b)
{
  real_T *c9_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c9_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#387) in the initialization routine of the chart.\n");
  }

  c9_c = chartInstance->c9_randPoseChance_address;
  if (c9_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c9_c;
}

static void init_dsm_address_info
  (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c9_BOREDOM_THRESHOLD_address,
    &chartInstance->c9_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_GUI", (void **)
    &chartInstance->c9_GAZE_GUI_address, &chartInstance->c9_GAZE_GUI_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_SHOFTEYE", (void **)
    &chartInstance->c9_GAZE_SHOFTEYE_address,
    &chartInstance->c9_GAZE_SHOFTEYE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_USER_HAND", (void **)
    &chartInstance->c9_GAZE_USER_HAND_address,
    &chartInstance->c9_GAZE_USER_HAND_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c9_GAZE_WIN_address, &chartInstance->c9_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c9_STATE_BEFORE_address,
    &chartInstance->c9_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c9_STATE_OVER_address, &chartInstance->c9_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c9_STATE_READY_address, &chartInstance->c9_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c9_avert_address, &chartInstance->c9_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c9_boredom_address, &chartInstance->c9_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c9_gazing_address, &chartInstance->c9_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c9_interest_address, &chartInstance->c9_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c9_isPosing_address, &chartInstance->c9_isPosing_index);
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

void sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_get_check_sum
  (mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3828496226U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3121904652U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1564644187U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(509244727U);
}

mxArray
  *sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KS0oSfXa6CJ75CxyNoKlTD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray
  *sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[116],T\"gameState\",},{M[3],M[114],T\"randHeadDur\",},{M[3],M[115],T\"randHeadDurOver\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile\",},{M[8],M[99],T\"is_active_stateGazeIde\",},{M[8],M[100],T\"is_active_stateGazeWin\",}}",
    "100 S1x7'type','srcId','name','auxInfo'{{M[8],M[101],T\"is_active_stateGazeSoft\",},{M[9],M[99],T\"is_stateGazeIde\",},{M[9],M[100],T\"is_stateGazeWin\",},{M[9],M[101],T\"is_stateGazeSoft\",},{M[11],M[23],T\"temporalCounter_i3\",S'et','os','ct'{{T\"ev\",M[83],M[1]}}},{M[11],M[23],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M1x3[91 92 90],M[1]}}},{M[11],M[23],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x5[13 14 15 78 61],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 17, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_get_check_sum
    (&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
      *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance =
      (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
           9,
           21,
           27,
           0,
           28,
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
          (_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randAvertGazeChance");
          _SFD_SET_DATA_PROPS(3,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(4,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(5,11,0,0,"interest");
          _SFD_SET_DATA_PROPS(6,11,0,0,"randGazeDur");
          _SFD_SET_DATA_PROPS(7,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(8,11,0,0,"GAZE_SHOFTEYE");
          _SFD_SET_DATA_PROPS(9,11,0,0,"GAZE_GUI");
          _SFD_SET_DATA_PROPS(10,11,0,0,"GAZE_USER_HAND");
          _SFD_SET_DATA_PROPS(11,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(12,0,0,0,"randHeadDur");
          _SFD_SET_DATA_PROPS(13,0,0,0,"randHeadDurOver");
          _SFD_SET_DATA_PROPS(14,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(15,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(16,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(17,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(18,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
          _SFD_SET_DATA_PROPS(26,8,0,0,"");
          _SFD_SET_DATA_PROPS(27,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(4,0,1);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,1);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,1);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(20,0,2);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,4);
          _SFD_CH_SUBSTATE_INDEX(1,15);
          _SFD_CH_SUBSTATE_INDEX(2,12);
          _SFD_ST_SUBSTATE_COUNT(4,7);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_INDEX(4,2,7);
          _SFD_ST_SUBSTATE_INDEX(4,3,8);
          _SFD_ST_SUBSTATE_INDEX(4,4,9);
          _SFD_ST_SUBSTATE_INDEX(4,5,10);
          _SFD_ST_SUBSTATE_INDEX(4,6,11);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(15,4);
          _SFD_ST_SUBSTATE_INDEX(15,0,16);
          _SFD_ST_SUBSTATE_INDEX(15,1,17);
          _SFD_ST_SUBSTATE_INDEX(15,2,18);
          _SFD_ST_SUBSTATE_INDEX(15,3,19);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(12,2);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,14);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

        {
          _SFD_CV_INIT_STATE(4,7,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,4,1,1,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,25,23,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,
                             "idleGazeTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile",
                             0,-1,3684);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",3684,-1,3871);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",3871,-1,4060);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",4060,-1,4243);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",4243,-1,4430);
        _SFD_CV_INIT_EML_FCN(2,5,"aFcnTruthTableAction_5",4430,-1,4621);
        _SFD_CV_INIT_EML_FCN(2,6,"aFcnTruthTableAction_6",4621,-1,4814);
        _SFD_CV_INIT_EML_FCN(2,7,"aFcnTruthTableAction_7",4814,-1,5009);
        _SFD_CV_INIT_EML_FCN(2,8,"aFcnTruthTableAction_8",5009,-1,5206);
        _SFD_CV_INIT_EML_FCN(2,9,"aFcnTruthTableAction_9",5206,-1,5414);
        _SFD_CV_INIT_EML_FCN(2,10,"aFcnTruthTableAction_10",5414,-1,5625);
        _SFD_CV_INIT_EML_FCN(2,11,"aFcnTruthTableAction_11",5625,-1,5826);
        _SFD_CV_INIT_EML_FCN(2,12,"aFcnTruthTableAction_12",5826,-1,6031);
        _SFD_CV_INIT_EML_FCN(2,13,"aFcnTruthTableAction_13",6031,-1,6234);
        _SFD_CV_INIT_EML_FCN(2,14,"aFcnTruthTableAction_14",6234,-1,6429);
        _SFD_CV_INIT_EML_FCN(2,15,"aFcnTruthTableAction_15",6429,-1,6632);
        _SFD_CV_INIT_EML_FCN(2,16,"aFcnTruthTableAction_16",6632,-1,6833);
        _SFD_CV_INIT_EML_FCN(2,17,"aFcnTruthTableAction_17",6833,-1,7028);
        _SFD_CV_INIT_EML_FCN(2,18,"aFcnTruthTableAction_18",7028,-1,7340);
        _SFD_CV_INIT_EML_FCN(2,19,"aFcnTruthTableAction_19",7340,-1,7563);
        _SFD_CV_INIT_EML_FCN(2,20,"aFcnTruthTableAction_20",7563,-1,7890);
        _SFD_CV_INIT_EML_FCN(2,21,"aFcnTruthTableAction_21",7890,-1,8107);
        _SFD_CV_INIT_EML_FCN(2,22,"aFcnTruthTableAction_22",8107,-1,8423);
        _SFD_CV_INIT_EML_FCN(2,23,"aFcnTruthTableAction_23",8423,-1,8642);
        _SFD_CV_INIT_EML_FCN(2,24,"aFcnTruthTableAction_24",8642,-1,8830);
        _SFD_CV_INIT_EML_IF(2,1,0,2115,2145,2176,3682);
        _SFD_CV_INIT_EML_IF(2,1,1,2176,2210,2241,3682);
        _SFD_CV_INIT_EML_IF(2,1,2,2241,2275,2306,3682);
        _SFD_CV_INIT_EML_IF(2,1,3,2306,2340,2371,3682);
        _SFD_CV_INIT_EML_IF(2,1,4,2371,2405,2436,3682);
        _SFD_CV_INIT_EML_IF(2,1,5,2436,2470,2501,3682);
        _SFD_CV_INIT_EML_IF(2,1,6,2501,2535,2566,3682);
        _SFD_CV_INIT_EML_IF(2,1,7,2566,2600,2631,3682);
        _SFD_CV_INIT_EML_IF(2,1,8,2631,2665,2697,3682);
        _SFD_CV_INIT_EML_IF(2,1,9,2697,2732,2763,3682);
        _SFD_CV_INIT_EML_IF(2,1,10,2763,2798,2830,3682);
        _SFD_CV_INIT_EML_IF(2,1,11,2830,2865,2897,3682);
        _SFD_CV_INIT_EML_IF(2,1,12,2897,2932,2964,3682);
        _SFD_CV_INIT_EML_IF(2,1,13,2964,2999,3031,3682);
        _SFD_CV_INIT_EML_IF(2,1,14,3031,3066,3098,3682);
        _SFD_CV_INIT_EML_IF(2,1,15,3098,3133,3165,3682);
        _SFD_CV_INIT_EML_IF(2,1,16,3165,3200,3232,3682);
        _SFD_CV_INIT_EML_IF(2,1,17,3232,3267,3299,3682);
        _SFD_CV_INIT_EML_IF(2,1,18,3299,3334,3366,3682);
        _SFD_CV_INIT_EML_IF(2,1,19,3366,3401,3433,3682);
        _SFD_CV_INIT_EML_IF(2,1,20,3433,3468,3500,3682);
        _SFD_CV_INIT_EML_IF(2,1,21,3500,3535,3567,3682);
        _SFD_CV_INIT_EML_IF(2,1,22,3567,3602,3634,3682);
        _SFD_CV_INIT_EML(1,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,
                             "idleGazeInterestedTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile",
                             0,-1,1289);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1289,-1,1471);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1471,-1,1657);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1657,-1,1844);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1844,-1,2034);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",2034,-1,2226);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2226,-1,2420);
        _SFD_CV_INIT_EML_FCN(1,7,"aFcnTruthTableAction_7",2420,-1,2616);
        _SFD_CV_INIT_EML_FCN(1,8,"aFcnTruthTableAction_8",2616,-1,2827);
        _SFD_CV_INIT_EML_IF(1,1,0,723,753,784,1287);
        _SFD_CV_INIT_EML_IF(1,1,1,784,818,849,1287);
        _SFD_CV_INIT_EML_IF(1,1,2,849,883,914,1287);
        _SFD_CV_INIT_EML_IF(1,1,3,914,948,979,1287);
        _SFD_CV_INIT_EML_IF(1,1,4,979,1013,1044,1287);
        _SFD_CV_INIT_EML_IF(1,1,5,1044,1078,1109,1287);
        _SFD_CV_INIT_EML_IF(1,1,6,1109,1143,1174,1287);
        _SFD_CV_INIT_EML_IF(1,1,7,1174,1208,1239,1287);
        _SFD_CV_INIT_EML(20,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(20,0,
                             "successTablec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile",
                             0,-1,566);
        _SFD_CV_INIT_EML_FCN(20,1,"aFcnTruthTableAction_1",566,-1,872);
        _SFD_CV_INIT_EML_FCN(20,2,"aFcnTruthTableAction_2",872,-1,1089);
        _SFD_CV_INIT_EML_FCN(20,3,"aFcnTruthTableAction_3",1089,-1,1343);
        _SFD_CV_INIT_EML_IF(20,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(20,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(20,1,2,451,485,516,564);
        _SFD_CV_INIT_EML(0,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,
                             "gazeFollowUserMovec9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile",
                             0,-1,551);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",551,-1,768);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",768,-1,984);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",984,-1,1142);
        _SFD_CV_INIT_EML_IF(0,1,0,310,340,371,549);
        _SFD_CV_INIT_EML_IF(0,1,1,371,405,436,549);
        _SFD_CV_INIT_EML_IF(0,1,2,436,470,501,549);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,53,1,48);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 52 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,53,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,39,1,39);

        {
          static int condStart[] = { 2, 20 };

          static int condEnd[] = { 17, 38 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,39,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,12,1,12);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,52,1,48);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 51 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,52,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,38,1,38);

        {
          static int condStart[] = { 2, 24 };

          static int condEnd[] = { 21, 37 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,38,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,42,1,42);

        {
          static int condStart[] = { 2, 28 };

          static int condEnd[] = { 25, 41 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(19,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,0,23,0,23);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(24,0,0,0,23,0,23);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,0,27,0,27);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,22,1,22);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(16,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(16,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,22,1,22);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
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
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
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

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

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

        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(26,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(27,(void *)(NULL));

        {
          real_T *c9_gameState;
          c9_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(1U,
            chartInstance->c9_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(2U,
            chartInstance->c9_randAvertGazeChance_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_isPosing_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c9_interest_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_randGazeDur_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c9_GAZE_SHOFTEYE_address);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c9_GAZE_GUI_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_GAZE_USER_HAND_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c9_randHeadDur);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c9_randHeadDurOver);
          _SFD_SET_DATA_VALUE_PTR(14U, c9_gameState);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c9_avert_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c9_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c9_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c9_STATE_READY_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "riLDbwowSpOlrT5Awj9HwH";
}

static void
  sf_opaque_initialize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
  initialize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_enable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile(void
  *chartInstanceVar)
{
  enable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_disable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  disable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_gateway_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  sf_gateway_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
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
    get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ();                                /* state var info */
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
  sf_internal_set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
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
    sf_get_sim_state_info_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct* S)
{
  return NULL;
}

static void
  sf_opaque_set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct* S, const mxArray *st)
{
}

static void
  sf_opaque_terminate_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
       chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_optimization_info
        ();
    }

    finalize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
      ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
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
  initSimStructsc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
    ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
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
    initialize_params_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
      ((SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void
  mdlSetWorkWidths_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_optimization_info
      ();
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
      (),infoStruct,9,1);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
    }

    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(166428497U));
  ssSetChecksum1(S,(983166204U));
  ssSetChecksum2(S,(3308073826U));
  ssSetChecksum3(S,(247238487U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct
    *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance =
    (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct *)
    utMalloc(sizeof
             (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile;
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

void c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile
      (S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_ARP_02_RPSsmile_GAZEKinectGloveAtomicBradImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
