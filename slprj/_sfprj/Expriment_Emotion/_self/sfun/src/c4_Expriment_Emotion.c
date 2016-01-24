/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_Emotion_sfun.h"
#include "c4_Expriment_Emotion.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_Emotion_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c4_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_avoidRepeatedPose        ((uint8_T)1U)
#define c4_IN_avoidRepeatedPose1       ((uint8_T)2U)
#define c4_IN_leanChange               ((uint8_T)3U)
#define c4_IN_poseCategoryChance       ((uint8_T)4U)
#define c4_IN_poseCategoryChance1      ((uint8_T)5U)
#define c4_IN_poseCategoryChance2      ((uint8_T)6U)
#define c4_IN_selfAdaptorPoseCategory  ((uint8_T)7U)
#define c4_IN_selfAdaptorPoseCategory1 ((uint8_T)8U)
#define c4_IN_stateExtrovertPoseChance ((uint8_T)9U)
#define c4_IN_stateInit                ((uint8_T)10U)
#define c4_IN_stateRandomPose          ((uint8_T)11U)
#define c4_IN_weightshiftPoseCategory  ((uint8_T)12U)
#define c4_IN_weightshiftPoseCategory1 ((uint8_T)13U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[25] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "aVarTruthTableCondition_19",
  "aVarTruthTableCondition_20", "nargin", "nargout", "bmlID", "pr", "poseBML" };

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

static const char * c4_k_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_l_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

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

static const char * c4_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_v_debug_family_names[24] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "aVarTruthTableCondition_19", "nargin",
  "nargout", "bmlID", "pr", "poseBML" };

static const char * c4_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_y_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

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

static const char * c4_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_lb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_nb_debug_family_names[18] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13", "nargin",
  "nargout", "bmlID", "pr", "poseBML" };

static const char * c4_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_sb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_tb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ub_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_vb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_wb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_xb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_yb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_bc_debug_family_names[9] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "poseSpeed", "spacious",
  "shiftType" };

static const char * c4_cc_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5", "nargin", "nargout",
  "poseSpeed", "poseTwitch", "poseType" };

static const char * c4_dc_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c4_ec_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c4_fc_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c4_gc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_hc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_jc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_kc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_lc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_mc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_nc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_oc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_qc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_rc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_sc_debug_family_names[2] = { "nargin", "nargout" };

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

static boolean_T c4_dataWrittenToVector[28];

/* Function Declarations */
static void initialize_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void initialize_params_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void enable_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void disable_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void set_sim_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void finalize_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void sf_gateway_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_enter_atomic_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_enter_internal_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_exit_internal_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_initc4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void initSimStructsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_idlePoseGenerate(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_enter_atomic_leanChange(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_stateRandomPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_stateExtrovertPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_poseCategoryChance1(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_poseCategoryChance2(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_weightshiftPoseCategory(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_enter_atomic_selfAdaptorPoseCategory1
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_enter_atomic_weightshiftPoseCategory1
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_weightshiftPoseCategory1(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);
static void c4_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_b_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_c_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_d_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_e_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_f_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_g_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_h_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_i_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_j_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_k_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_l_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_m_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_n_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_o_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_p_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_q_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_r_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_s_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_t_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_u_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_v_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_w_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_x_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_y_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_ab_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_bb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_cb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_db_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_eb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_fb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_gb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_hb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_ib_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_jb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_kb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_lb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_mb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_nb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_ob_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_pb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_qb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_rb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_sb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_tb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_ub_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_vb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_wb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static void c4_xb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000]);
static real_T c4_rand(SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static real_T c4_eml_rand(SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625]);
static void c4_twister_state_vector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625]);
static void c4_b_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
  *c4_r);
static void c4_eml_error(SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_poseBML, const char_T *c4_identifier, real_T
  c4_y[1000]);
static void c4_b_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[1000]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_pr, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_e_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_f_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_myarr256, const char_T *c4_identifier,
  real_T c4_y[1000]);
static void c4_g_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[1000]);
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
static void c4_h_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_newBmls, const char_T *c4_identifier, real_T
  c4_y[5000]);
static void c4_i_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5000]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static void c4_activate_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_deactivate_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_increment_counters_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_reset_counters_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance);
static void c4_selfAdaptorTableBillyc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000]);
static void c4_selfAdaptor_TwitchTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000]);
static void c4_weightshift_SpaceTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000]);
static real_T c4_weightShiftTypeTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_poseSpeed,
   real_T c4_spacious);
static real_T c4_selfAdaptorTypeTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_poseSpeed,
   real_T c4_poseTwitch);
static void c4_insertQueueLowc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmls[5000],
   real_T c4_myBML[1000], real_T c4_newBmls[5000]);
static void c4_insertQueuec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmls[5000],
   real_T c4_myBML[1000], real_T c4_newBmls[5000]);
static boolean_T c4_isequal(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_varargin_1[1000], real_T c4_varargin_2[1000]);
static const mxArray *c4_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int8_T c4_j_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_k_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_l_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_idlePoseGenerate, const char_T
  *c4_identifier);
static uint8_T c4_m_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint32_T c4_n_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier);
static uint32_T c4_o_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static uint32_T c4_p_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier);
static uint32_T c4_q_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_r_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[625]);
static void c4_s_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[625]);
static void c4_t_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[2]);
static void c4_u_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[2]);
static uint32_T c4_v_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_temporalCounter_i1, const char_T
  *c4_identifier);
static uint32_T c4_w_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *c4_x_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_y_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_updateDataWrittenToVector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex);
static void c4_errorIfDataNotWrittenToFcn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber);
static void c4_b_twister_state_vector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed);
static real_T c4_c_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625]);
static real_T c4_get_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_BORED(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_BORED(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_BORED(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct *
  chartInstance, uint32_T c4_b);
static real_T c4_get_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_EXCITE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_EXCITE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_EXCITE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_FEAR(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_FEAR(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_FEAR(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_FRUST(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_FRUST(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_FRUST(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_HAPPY(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_HAPPY(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_HAPPY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_IDLE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_IDLE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_IDLE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
                     uint32_T c4_b, real_T c4_c);
static real_T *c4_access_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static real_T c4_get_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_STATE_GO(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_STATE_GO(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_GO(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_bmlsL(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_bmlsL(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_bmlsL(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_bmlsM(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_bmlsM(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_bmlsM(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_boredom(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_boredom(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_boredom(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_fileID(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b);
static void c4_set_fileID(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_fileID(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_interest(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_interest(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_interest(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_frequency_factor(SFc4_Expriment_EmotionInstanceStruct *
  chartInstance, uint32_T c4_b);
static void c4_set_pose_frequency_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_frequency_factor
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_lean(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_lean(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_lean(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static real_T c4_get_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void c4_set_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c);
static real_T *c4_access_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b);
static void init_dsm_address_info(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_debugger_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_Expriment_Emotion == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_active_idlePoseGenerate == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateInit) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_leanChange) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateRandomPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateExtrovertPoseChance) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_selfAdaptorPoseCategory) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_weightshiftPoseCategory) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_selfAdaptorPoseCategory1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_weightshiftPoseCategory1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_avoidRepeatedPose) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_idlePoseGenerate == c4_IN_avoidRepeatedPose1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  int32_T c4_i0;
  real_T c4_b_u[1000];
  const mxArray *c4_c_y = NULL;
  int32_T c4_i1;
  real_T c4_c_u[1000];
  const mxArray *c4_d_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  int32_T c4_i2;
  real_T c4_f_u[1000];
  const mxArray *c4_g_y = NULL;
  int32_T c4_i3;
  real_T c4_g_u[5000];
  const mxArray *c4_h_y = NULL;
  int32_T c4_i4;
  real_T c4_h_u[5000];
  const mxArray *c4_i_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_j_u;
  const mxArray *c4_k_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_k_u;
  const mxArray *c4_l_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_l_u;
  const mxArray *c4_m_y = NULL;
  real_T c4_h_hoistedGlobal;
  real_T c4_m_u;
  const mxArray *c4_n_y = NULL;
  real_T c4_i_hoistedGlobal;
  real_T c4_n_u;
  const mxArray *c4_o_y = NULL;
  real_T c4_j_hoistedGlobal;
  real_T c4_o_u;
  const mxArray *c4_p_y = NULL;
  real_T c4_k_hoistedGlobal;
  real_T c4_p_u;
  const mxArray *c4_q_y = NULL;
  real_T c4_l_hoistedGlobal;
  real_T c4_q_u;
  const mxArray *c4_r_y = NULL;
  real_T c4_m_hoistedGlobal;
  real_T c4_r_u;
  const mxArray *c4_s_y = NULL;
  uint32_T c4_n_hoistedGlobal;
  uint32_T c4_s_u;
  const mxArray *c4_t_y = NULL;
  uint32_T c4_o_hoistedGlobal;
  uint32_T c4_t_u;
  const mxArray *c4_u_y = NULL;
  int32_T c4_i5;
  uint32_T c4_u_u[625];
  const mxArray *c4_v_y = NULL;
  int32_T c4_i6;
  uint32_T c4_v_u[2];
  const mxArray *c4_w_y = NULL;
  uint8_T c4_p_hoistedGlobal;
  uint8_T c4_w_u;
  const mxArray *c4_x_y = NULL;
  uint8_T c4_q_hoistedGlobal;
  uint8_T c4_x_u;
  const mxArray *c4_y_y = NULL;
  uint8_T c4_r_hoistedGlobal;
  uint8_T c4_y_u;
  const mxArray *c4_ab_y = NULL;
  uint32_T c4_s_hoistedGlobal;
  uint32_T c4_ab_u;
  const mxArray *c4_bb_y = NULL;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(26, 1), false);
  c4_hoistedGlobal = *c4_gameState;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i0 = 0; c4_i0 < 1000; c4_i0++) {
    c4_b_u[c4_i0] = chartInstance->c4_BMLM[c4_i0];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  for (c4_i1 = 0; c4_i1 < 1000; c4_i1++) {
    c4_c_u[c4_i1] = chartInstance->c4_BMLl[c4_i1];
  }

  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_b_hoistedGlobal = chartInstance->c4_catChance;
  c4_d_u = c4_b_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_c_hoistedGlobal = chartInstance->c4_leanPose;
  c4_e_u = c4_c_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  for (c4_i2 = 0; c4_i2 < 1000; c4_i2++) {
    c4_f_u[c4_i2] = chartInstance->c4_n[c4_i2];
  }

  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1, 1000),
                false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  for (c4_i3 = 0; c4_i3 < 5000; c4_i3++) {
    c4_g_u[c4_i3] = chartInstance->c4_newBmlsL[c4_i3];
  }

  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_g_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  for (c4_i4 = 0; c4_i4 < 5000; c4_i4++) {
    c4_h_u[c4_i4] = chartInstance->c4_newBmlsM[c4_i4];
  }

  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", c4_h_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_d_hoistedGlobal = chartInstance->c4_oldPose;
  c4_i_u = c4_d_hoistedGlobal;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  c4_e_hoistedGlobal = chartInstance->c4_pCatChance;
  c4_j_u = c4_e_hoistedGlobal;
  c4_k_y = NULL;
  sf_mex_assign(&c4_k_y, sf_mex_create("y", &c4_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 9, c4_k_y);
  c4_f_hoistedGlobal = chartInstance->c4_pChangeFlag;
  c4_k_u = c4_f_hoistedGlobal;
  c4_l_y = NULL;
  sf_mex_assign(&c4_l_y, sf_mex_create("y", &c4_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 10, c4_l_y);
  c4_g_hoistedGlobal = chartInstance->c4_pPoseChance;
  c4_l_u = c4_g_hoistedGlobal;
  c4_m_y = NULL;
  sf_mex_assign(&c4_m_y, sf_mex_create("y", &c4_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 11, c4_m_y);
  c4_h_hoistedGlobal = chartInstance->c4_pPoseChanceP;
  c4_m_u = c4_h_hoistedGlobal;
  c4_n_y = NULL;
  sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 12, c4_n_y);
  c4_i_hoistedGlobal = chartInstance->c4_poseFreq;
  c4_n_u = c4_i_hoistedGlobal;
  c4_o_y = NULL;
  sf_mex_assign(&c4_o_y, sf_mex_create("y", &c4_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 13, c4_o_y);
  c4_j_hoistedGlobal = chartInstance->c4_poseFreqP;
  c4_o_u = c4_j_hoistedGlobal;
  c4_p_y = NULL;
  sf_mex_assign(&c4_p_y, sf_mex_create("y", &c4_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 14, c4_p_y);
  c4_k_hoistedGlobal = chartInstance->c4_poseNum;
  c4_p_u = c4_k_hoistedGlobal;
  c4_q_y = NULL;
  sf_mex_assign(&c4_q_y, sf_mex_create("y", &c4_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 15, c4_q_y);
  c4_l_hoistedGlobal = chartInstance->c4_pose_type;
  c4_q_u = c4_l_hoistedGlobal;
  c4_r_y = NULL;
  sf_mex_assign(&c4_r_y, sf_mex_create("y", &c4_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 16, c4_r_y);
  c4_m_hoistedGlobal = chartInstance->c4_randPR;
  c4_r_u = c4_m_hoistedGlobal;
  c4_s_y = NULL;
  sf_mex_assign(&c4_s_y, sf_mex_create("y", &c4_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 17, c4_s_y);
  c4_n_hoistedGlobal = chartInstance->c4_method;
  c4_s_u = c4_n_hoistedGlobal;
  c4_t_y = NULL;
  if (!chartInstance->c4_method_not_empty) {
    sf_mex_assign(&c4_t_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_t_y, sf_mex_create("y", &c4_s_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 18, c4_t_y);
  c4_o_hoistedGlobal = chartInstance->c4_state;
  c4_t_u = c4_o_hoistedGlobal;
  c4_u_y = NULL;
  if (!chartInstance->c4_state_not_empty) {
    sf_mex_assign(&c4_u_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_u_y, sf_mex_create("y", &c4_t_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 19, c4_u_y);
  for (c4_i5 = 0; c4_i5 < 625; c4_i5++) {
    c4_u_u[c4_i5] = chartInstance->c4_c_state[c4_i5];
  }

  c4_v_y = NULL;
  if (!chartInstance->c4_c_state_not_empty) {
    sf_mex_assign(&c4_v_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_v_y, sf_mex_create("y", c4_u_u, 7, 0U, 1U, 0U, 1, 625),
                  false);
  }

  sf_mex_setcell(c4_y, 20, c4_v_y);
  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_v_u[c4_i6] = chartInstance->c4_b_state[c4_i6];
  }

  c4_w_y = NULL;
  if (!chartInstance->c4_b_state_not_empty) {
    sf_mex_assign(&c4_w_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_w_y, sf_mex_create("y", c4_v_u, 7, 0U, 1U, 0U, 1, 2),
                  false);
  }

  sf_mex_setcell(c4_y, 21, c4_w_y);
  c4_p_hoistedGlobal = chartInstance->c4_is_active_c4_Expriment_Emotion;
  c4_w_u = c4_p_hoistedGlobal;
  c4_x_y = NULL;
  sf_mex_assign(&c4_x_y, sf_mex_create("y", &c4_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 22, c4_x_y);
  c4_q_hoistedGlobal = chartInstance->c4_is_active_idlePoseGenerate;
  c4_x_u = c4_q_hoistedGlobal;
  c4_y_y = NULL;
  sf_mex_assign(&c4_y_y, sf_mex_create("y", &c4_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 23, c4_y_y);
  c4_r_hoistedGlobal = chartInstance->c4_is_idlePoseGenerate;
  c4_y_u = c4_r_hoistedGlobal;
  c4_ab_y = NULL;
  sf_mex_assign(&c4_ab_y, sf_mex_create("y", &c4_y_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 24, c4_ab_y);
  c4_s_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_ab_u = c4_s_hoistedGlobal;
  c4_bb_y = NULL;
  sf_mex_assign(&c4_bb_y, sf_mex_create("y", &c4_ab_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 25, c4_bb_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[1000];
  int32_T c4_i7;
  real_T c4_dv1[1000];
  int32_T c4_i8;
  real_T c4_dv2[1000];
  int32_T c4_i9;
  real_T c4_dv3[5000];
  int32_T c4_i10;
  real_T c4_dv4[5000];
  int32_T c4_i11;
  uint32_T c4_uv0[625];
  int32_T c4_i12;
  uint32_T c4_uv1[2];
  int32_T c4_i13;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_gameState = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "gameState");
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "BMLM",
                      c4_dv0);
  for (c4_i7 = 0; c4_i7 < 1000; c4_i7++) {
    chartInstance->c4_BMLM[c4_i7] = c4_dv0[c4_i7];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)), "BMLl",
                      c4_dv1);
  for (c4_i8 = 0; c4_i8 < 1000; c4_i8++) {
    chartInstance->c4_BMLl[c4_i8] = c4_dv1[c4_i8];
  }

  chartInstance->c4_catChance = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "catChance");
  chartInstance->c4_leanPose = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "leanPose");
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)), "n",
                        c4_dv2);
  for (c4_i9 = 0; c4_i9 < 1000; c4_i9++) {
    chartInstance->c4_n[c4_i9] = c4_dv2[c4_i9];
  }

  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
                        "newBmlsL", c4_dv3);
  for (c4_i10 = 0; c4_i10 < 5000; c4_i10++) {
    chartInstance->c4_newBmlsL[c4_i10] = c4_dv3[c4_i10];
  }

  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
                        "newBmlsM", c4_dv4);
  for (c4_i11 = 0; c4_i11 < 5000; c4_i11++) {
    chartInstance->c4_newBmlsM[c4_i11] = c4_dv4[c4_i11];
  }

  chartInstance->c4_oldPose = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 8)), "oldPose");
  chartInstance->c4_pCatChance = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 9)), "pCatChance");
  chartInstance->c4_pChangeFlag = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 10)), "pChangeFlag");
  chartInstance->c4_pPoseChance = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 11)), "pPoseChance");
  chartInstance->c4_pPoseChanceP = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 12)), "pPoseChanceP");
  chartInstance->c4_poseFreq = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 13)), "poseFreq");
  chartInstance->c4_poseFreqP = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 14)), "poseFreqP");
  chartInstance->c4_poseNum = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 15)), "poseNum");
  chartInstance->c4_pose_type = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 16)), "pose_type");
  chartInstance->c4_randPR = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 17)), "randPR");
  chartInstance->c4_method = c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 18)), "method");
  chartInstance->c4_state = c4_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 19)), "state");
  c4_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 20)),
                        "state", c4_uv0);
  for (c4_i12 = 0; c4_i12 < 625; c4_i12++) {
    chartInstance->c4_c_state[c4_i12] = c4_uv0[c4_i12];
  }

  c4_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 21)),
                        "state", c4_uv1);
  for (c4_i13 = 0; c4_i13 < 2; c4_i13++) {
    chartInstance->c4_b_state[c4_i13] = c4_uv1[c4_i13];
  }

  chartInstance->c4_is_active_c4_Expriment_Emotion = c4_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 22)),
     "is_active_c4_Expriment_Emotion");
  chartInstance->c4_is_active_idlePoseGenerate = c4_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 23)),
     "is_active_idlePoseGenerate");
  chartInstance->c4_is_idlePoseGenerate = c4_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 24)), "is_idlePoseGenerate");
  chartInstance->c4_temporalCounter_i1 = c4_v_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 25)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 26)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_Expriment_Emotion(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_active_idlePoseGenerate == 1U) {
      chartInstance->c4_tp_idlePoseGenerate = 1U;
    } else {
      chartInstance->c4_tp_idlePoseGenerate = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_avoidRepeatedPose) {
      chartInstance->c4_tp_avoidRepeatedPose = 1U;
    } else {
      chartInstance->c4_tp_avoidRepeatedPose = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_avoidRepeatedPose1) {
      chartInstance->c4_tp_avoidRepeatedPose1 = 1U;
    } else {
      chartInstance->c4_tp_avoidRepeatedPose1 = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_leanChange) {
      chartInstance->c4_tp_leanChange = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_leanChange = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance) {
      chartInstance->c4_tp_poseCategoryChance = 1U;
    } else {
      chartInstance->c4_tp_poseCategoryChance = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance1) {
      chartInstance->c4_tp_poseCategoryChance1 = 1U;
    } else {
      chartInstance->c4_tp_poseCategoryChance1 = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_poseCategoryChance2) {
      chartInstance->c4_tp_poseCategoryChance2 = 1U;
    } else {
      chartInstance->c4_tp_poseCategoryChance2 = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_selfAdaptorPoseCategory)
    {
      chartInstance->c4_tp_selfAdaptorPoseCategory = 1U;
    } else {
      chartInstance->c4_tp_selfAdaptorPoseCategory = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_selfAdaptorPoseCategory1)
    {
      chartInstance->c4_tp_selfAdaptorPoseCategory1 = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_selfAdaptorPoseCategory1 = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateExtrovertPoseChance)
    {
      chartInstance->c4_tp_stateExtrovertPoseChance = 1U;
    } else {
      chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateInit) {
      chartInstance->c4_tp_stateInit = 1U;
    } else {
      chartInstance->c4_tp_stateInit = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_stateRandomPose) {
      chartInstance->c4_tp_stateRandomPose = 1U;
    } else {
      chartInstance->c4_tp_stateRandomPose = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_weightshiftPoseCategory)
    {
      chartInstance->c4_tp_weightshiftPoseCategory = 1U;
    } else {
      chartInstance->c4_tp_weightshiftPoseCategory = 0U;
    }

    if (chartInstance->c4_is_idlePoseGenerate == c4_IN_weightshiftPoseCategory1)
    {
      chartInstance->c4_tp_weightshiftPoseCategory1 = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_weightshiftPoseCategory1 = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  c4_set_sim_state_side_effects_c4_Expriment_Emotion(chartInstance);
}

static void c4_enter_atomic_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_active_c4_Expriment_Emotion = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void c4_enter_internal_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_dv5[1000];
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  real_T *c4_gameState;
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_active_idlePoseGenerate = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_idlePoseGenerate = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_idlePoseGenerate = c4_IN_stateInit;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_stateInit = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_gc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_STATE_OVER(chartInstance, 0, 3.0);
  ssUpdateDataStoreLog(chartInstance->S, 13);
  c4_set_STATE_BEFORE(chartInstance, 0, 4.0);
  ssUpdateDataStoreLog(chartInstance->S, 11);
  c4_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 27);
  c4_set_STATE_READY(chartInstance, 0, 7.0);
  ssUpdateDataStoreLog(chartInstance->S, 14);
  c4_set_STATE_GO(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 12);
  *c4_gameState = 14.0;
  c4_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_gameState, 4U);
  c4_xb_encStr2Arr(chartInstance, c4_dv5);
  for (c4_i14 = 0; c4_i14 < 1000; c4_i14++) {
    chartInstance->c4_n[c4_i14] = c4_dv5[c4_i14];
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  for (c4_i15 = 0; c4_i15 < 1000; c4_i15++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_n[c4_i15], 27U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 3U, 27U);
  for (c4_i16 = 0; c4_i16 < 1000; c4_i16++) {
    c4_set_bmlsL(chartInstance, c4_i16, chartInstance->c4_n[c4_i16]);
  }

  for (c4_i17 = 0; c4_i17 < 1000; c4_i17++) {
    c4_set_bmlsL(chartInstance, c4_i17 + 1000, chartInstance->c4_n[c4_i17]);
  }

  for (c4_i18 = 0; c4_i18 < 1000; c4_i18++) {
    c4_set_bmlsL(chartInstance, c4_i18 + 2000, chartInstance->c4_n[c4_i18]);
  }

  for (c4_i19 = 0; c4_i19 < 1000; c4_i19++) {
    c4_set_bmlsL(chartInstance, c4_i19 + 3000, chartInstance->c4_n[c4_i19]);
  }

  for (c4_i20 = 0; c4_i20 < 1000; c4_i20++) {
    c4_set_bmlsL(chartInstance, c4_i20 + 4000, chartInstance->c4_n[c4_i20]);
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  ssUpdateDataStoreLog(chartInstance->S, 15);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 3U, 27U);
  for (c4_i21 = 0; c4_i21 < 1000; c4_i21++) {
    chartInstance->c4_newBmlsL[c4_i21] = chartInstance->c4_n[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 1000; c4_i22++) {
    chartInstance->c4_newBmlsL[c4_i22 + 1000] = chartInstance->c4_n[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 1000; c4_i23++) {
    chartInstance->c4_newBmlsL[c4_i23 + 2000] = chartInstance->c4_n[c4_i23];
  }

  for (c4_i24 = 0; c4_i24 < 1000; c4_i24++) {
    chartInstance->c4_newBmlsL[c4_i24 + 3000] = chartInstance->c4_n[c4_i24];
  }

  for (c4_i25 = 0; c4_i25 < 1000; c4_i25++) {
    chartInstance->c4_newBmlsL[c4_i25 + 4000] = chartInstance->c4_n[c4_i25];
  }

  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 3U);
  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i26 = 0; c4_i26 < 5000; c4_i26++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i26], 25U);
  }

  c4_set_pose_frequency_factor(chartInstance, 0, 20.0);
  ssUpdateDataStoreLog(chartInstance->S, 25);
  c4_set_pose_chance_factor(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 23);
  c4_set_pose_cat_chance(chartInstance, 0, 70.0);
  ssUpdateDataStoreLog(chartInstance->S, 22);
  c4_set_pose_lean(chartInstance, 0, 12.0);
  ssUpdateDataStoreLog(chartInstance->S, 26);
  c4_set_pose_speed(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 29);
  c4_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 27);
  c4_set_pose_twitch(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 30);
  c4_set_pose_space(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 28);
  chartInstance->c4_poseNum = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
  chartInstance->c4_oldPose = 0.0;
  c4_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_oldPose, 57U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_isStable = true;
  c4_idlePoseGenerate(chartInstance);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void c4_exit_internal_c4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  switch (chartInstance->c4_is_idlePoseGenerate) {
   case c4_IN_avoidRepeatedPose:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c4_tp_avoidRepeatedPose = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_avoidRepeatedPose1:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c4_tp_avoidRepeatedPose1 = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_leanChange:
    CV_STATE_EVAL(0, 1, 3);
    chartInstance->c4_tp_leanChange = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_poseCategoryChance:
    CV_STATE_EVAL(0, 1, 4);
    chartInstance->c4_tp_poseCategoryChance = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_poseCategoryChance1:
    CV_STATE_EVAL(0, 1, 5);
    chartInstance->c4_tp_poseCategoryChance1 = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_poseCategoryChance2:
    CV_STATE_EVAL(0, 1, 6);
    chartInstance->c4_tp_poseCategoryChance2 = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_selfAdaptorPoseCategory:
    CV_STATE_EVAL(0, 1, 7);
    chartInstance->c4_tp_selfAdaptorPoseCategory = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_selfAdaptorPoseCategory1:
    CV_STATE_EVAL(0, 1, 8);
    chartInstance->c4_tp_selfAdaptorPoseCategory1 = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateExtrovertPoseChance:
    CV_STATE_EVAL(0, 1, 9);
    chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateInit:
    CV_STATE_EVAL(0, 1, 10);
    chartInstance->c4_tp_stateInit = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandomPose:
    CV_STATE_EVAL(0, 1, 11);
    chartInstance->c4_tp_stateRandomPose = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_weightshiftPoseCategory:
    CV_STATE_EVAL(0, 1, 12);
    chartInstance->c4_tp_weightshiftPoseCategory = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_weightshiftPoseCategory1:
    CV_STATE_EVAL(0, 1, 13);
    chartInstance->c4_tp_weightshiftPoseCategory1 = 0U;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    break;
  }

  chartInstance->c4_tp_idlePoseGenerate = 0U;
  chartInstance->c4_is_active_idlePoseGenerate = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
}

static void c4_initc4_Expriment_Emotion(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_method_not_empty = false;
  chartInstance->c4_state_not_empty = false;
  chartInstance->c4_b_state_not_empty = false;
  chartInstance->c4_c_state_not_empty = false;
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_is_active_idlePoseGenerate = 0U;
  chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
  chartInstance->c4_tp_idlePoseGenerate = 0U;
  chartInstance->c4_tp_avoidRepeatedPose = 0U;
  chartInstance->c4_tp_avoidRepeatedPose1 = 0U;
  chartInstance->c4_tp_leanChange = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_poseCategoryChance = 0U;
  chartInstance->c4_tp_poseCategoryChance1 = 0U;
  chartInstance->c4_tp_poseCategoryChance2 = 0U;
  chartInstance->c4_tp_selfAdaptorPoseCategory = 0U;
  chartInstance->c4_tp_selfAdaptorPoseCategory1 = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
  chartInstance->c4_tp_stateInit = 0U;
  chartInstance->c4_tp_stateRandomPose = 0U;
  chartInstance->c4_tp_weightshiftPoseCategory = 0U;
  chartInstance->c4_tp_weightshiftPoseCategory1 = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_is_active_c4_Expriment_Emotion = 0U;
}

static void initSimStructsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_idlePoseGenerate(SFc4_Expriment_EmotionInstanceStruct
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
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_d_out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_i_nargin = 0.0;
  real_T c4_i_nargout = 0.0;
  real_T c4_j_nargin = 0.0;
  real_T c4_j_nargout = 1.0;
  boolean_T c4_f_out;
  real_T c4_k_nargin = 0.0;
  real_T c4_k_nargout = 0.0;
  real_T c4_l_nargin = 0.0;
  real_T c4_l_nargout = 0.0;
  real_T c4_m_nargin = 0.0;
  real_T c4_m_nargout = 0.0;
  real_T c4_n_nargin = 0.0;
  real_T c4_n_nargout = 1.0;
  boolean_T c4_g_out;
  boolean_T c4_temp;
  real_T c4_o_nargin = 0.0;
  real_T c4_o_nargout = 0.0;
  real_T c4_p_nargin = 0.0;
  real_T c4_p_nargout = 0.0;
  real_T (*c4_randArray)[40];
  boolean_T guard1 = false;
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  switch (chartInstance->c4_is_idlePoseGenerate) {
   case c4_IN_avoidRepeatedPose:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_nd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 16U, 56U);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 17U, 57U);
    c4_out = CV_EML_IF(31, 0, 0, chartInstance->c4_poseNum ==
                       chartInstance->c4_oldPose);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_avoidRepeatedPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_rc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
      chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
        _SFD_EML_ARRAY_BOUNDS_CHECK(
        "State avoidRepeatedPose #1502 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n  "
        "                                                                                                   ^^^^^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "State avoidRepeatedPose #1502 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n  "
        "                                                                                                               ^^^^^^^^^",
        chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
      c4_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_selfAdaptorPoseCategory1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_selfAdaptorPoseCategory1 = 1U;
      c4_enter_atomic_selfAdaptorPoseCategory1(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_avoidRepeatedPose1:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_od_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 16U, 56U);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 17U, 57U);
    c4_b_out = CV_EML_IF(33, 0, 0, chartInstance->c4_poseNum ==
                         chartInstance->c4_oldPose);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_avoidRepeatedPose1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_sc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
      chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
        _SFD_EML_ARRAY_BOUNDS_CHECK(
        "State avoidRepeatedPose1 #1518 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n "
        "                                                                                                     ^^^^^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "State avoidRepeatedPose1 #1518 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n "
        "                                                                                                                 ^^^^^^^^^",
        chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
      c4_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_avoidRepeatedPose1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_weightshiftPoseCategory1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_weightshiftPoseCategory1 = 1U;
      c4_enter_atomic_weightshiftPoseCategory1(chartInstance);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_leanChange:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_tc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_c_out = CV_EML_IF(18, 0, 0, (chartInstance->c4_sfEvent == c4_event_secs) &&
                         (chartInstance->c4_temporalCounter_i1 >= 1U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_leanChange = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
      ssUpdateDataStoreLog(chartInstance->S, 32);
      c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance,
        0) - c4_get_boredom(chartInstance, 0));
      ssUpdateDataStoreLog(chartInstance->S, 21);
      c4_set_interest(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 21);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_poseCategoryChance:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_gd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_d_out = CV_EML_IF(19, 0, 0, c4_get_bodyBusyFlag(chartInstance, 0) != 1.0);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    if (c4_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_hd_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
      c4_e_out = CV_EML_IF(14, 0, 0, chartInstance->c4_randPR <=
                           c4_get_pose_cat_chance(chartInstance, 0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_poseCategoryChance = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_idlePoseGenerate = c4_IN_weightshiftPoseCategory;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_weightshiftPoseCategory = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_oc_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        chartInstance->c4_pose_type =
          c4_weightShiftTypeTablec4_Expriment_Emotion(chartInstance,
          c4_get_pose_speed(chartInstance, 0), c4_get_pose_space(chartInstance,
          0));
        c4_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
        c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
        chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
          _SFD_EML_ARRAY_BOUNDS_CHECK(
          "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
          "                                                                                              ^^^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
          "                                                                                                          ^^^^^^^^^",
          chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
        c4_updateDataWrittenToVector(chartInstance, 16U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ld_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
        c4_f_out = CV_EML_IF(9, 0, 0, chartInstance->c4_randPR >
                             c4_get_pose_cat_chance(chartInstance, 0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c4_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_poseCategoryChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_idlePoseGenerate = c4_IN_selfAdaptorPoseCategory;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_selfAdaptorPoseCategory = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_nc_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargin, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargout, 1U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          chartInstance->c4_pose_type =
            c4_selfAdaptorTypeTablec4_Expriment_Emotion(chartInstance,
            c4_get_pose_speed(chartInstance, 0), c4_get_pose_twitch
            (chartInstance, 0));
          c4_updateDataWrittenToVector(chartInstance, 15U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
          c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
          chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK
            (28U, _SFD_EML_ARRAY_BOUNDS_CHECK(
              "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
              "                                                                                               ^^^^^^^^^",
              (int32_T)_SFD_INTEGER_CHECK(
               "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
               "                                                                                                           ^^^^^^^^^",
               chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
          c4_updateDataWrittenToVector(chartInstance, 16U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_poseCategoryChance = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_poseCategoryChance = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_mc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      chartInstance->c4_randPR = (*c4_randArray)[19];
      c4_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_poseCategoryChance1:
    CV_STATE_EVAL(0, 0, 5);
    c4_poseCategoryChance1(chartInstance);
    break;

   case c4_IN_poseCategoryChance2:
    CV_STATE_EVAL(0, 0, 6);
    c4_poseCategoryChance2(chartInstance);
    break;

   case c4_IN_selfAdaptorPoseCategory:
    CV_STATE_EVAL(0, 0, 7);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_selfAdaptorPoseCategory = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_avoidRepeatedPose;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_avoidRepeatedPose = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_rc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_m_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_m_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
    chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
      _SFD_EML_ARRAY_BOUNDS_CHECK(
      "State avoidRepeatedPose #1502 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n  "
      "                                                                                                   ^^^^^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "State avoidRepeatedPose #1502 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n  "
      "                                                                                                               ^^^^^^^^^",
      chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
    c4_updateDataWrittenToVector(chartInstance, 16U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_selfAdaptorPoseCategory1:
    CV_STATE_EVAL(0, 0, 8);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_wc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_n_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_n_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_temp = (chartInstance->c4_sfEvent == c4_event_secs);
    if (c4_temp) {
      c4_temp = (chartInstance->c4_temporalCounter_i1 >=
                 _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
                  c4_get_pose_frequency_factor(chartInstance, 0), 32U, 2U));
    }

    c4_g_out = CV_EML_IF(2, 0, 0, c4_temp);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_selfAdaptorPoseCategory1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_o_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_o_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
      ssUpdateDataStoreLog(chartInstance->S, 32);
      c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance,
        0) - c4_get_boredom(chartInstance, 0));
      ssUpdateDataStoreLog(chartInstance->S, 21);
      c4_set_interest(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 21);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateExtrovertPoseChance:
    CV_STATE_EVAL(0, 0, 9);
    c4_stateExtrovertPoseChance(chartInstance);
    break;

   case c4_IN_stateInit:
    CV_STATE_EVAL(0, 0, 10);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateInit = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomPose = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_p_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_p_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
    ssUpdateDataStoreLog(chartInstance->S, 32);
    c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance, 0)
                    - c4_get_boredom(chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 21);
    c4_set_interest(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 21);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_stateRandomPose:
    CV_STATE_EVAL(0, 0, 11);
    c4_stateRandomPose(chartInstance);
    break;

   case c4_IN_weightshiftPoseCategory:
    CV_STATE_EVAL(0, 0, 12);
    c4_weightshiftPoseCategory(chartInstance);
    break;

   case c4_IN_weightshiftPoseCategory1:
    CV_STATE_EVAL(0, 0, 13);
    c4_weightshiftPoseCategory1(chartInstance);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c4_is_idlePoseGenerate = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_leanChange(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_b_BMLM[1000];
  real_T c4_P;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  real_T c4_dv6[5000];
  int32_T c4_i30;
  real_T c4_dv7[1000];
  real_T c4_dv8[5000];
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_hc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_set_pose_lean_flag(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 27);
  c4_weightshift_SpaceTablec4_Expriment_Emotion(chartInstance, c4_get_pose_lean
    (chartInstance, 0), &c4_P, c4_b_BMLM);
  c4_set_P(chartInstance, 0, c4_P);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  for (c4_i27 = 0; c4_i27 < 1000; c4_i27++) {
    chartInstance->c4_BMLM[c4_i27] = c4_b_BMLM[c4_i27];
  }

  c4_updateDataWrittenToVector(chartInstance, 1U);
  for (c4_i28 = 0; c4_i28 < 1000; c4_i28++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_BMLM[c4_i28], 24U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 1U, 24U);
  for (c4_i29 = 0; c4_i29 < 5000; c4_i29++) {
    c4_dv6[c4_i29] = c4_get_bmlsM(chartInstance, c4_i29);
  }

  for (c4_i30 = 0; c4_i30 < 1000; c4_i30++) {
    c4_dv7[c4_i30] = chartInstance->c4_BMLM[c4_i30];
  }

  c4_insertQueuec4_Expriment_Emotion(chartInstance, c4_dv6, c4_dv7, c4_dv8);
  for (c4_i31 = 0; c4_i31 < 5000; c4_i31++) {
    chartInstance->c4_newBmlsM[c4_i31] = c4_dv8[c4_i31];
  }

  c4_updateDataWrittenToVector(chartInstance, 13U);
  for (c4_i32 = 0; c4_i32 < 5000; c4_i32++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsM[c4_i32], 42U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 13U, 42U);
  for (c4_i33 = 0; c4_i33 < 5000; c4_i33++) {
    c4_set_bmlsM(chartInstance, c4_i33, chartInstance->c4_newBmlsM[c4_i33]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 16);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_stateRandomPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d_y;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_lowhigh[2];
  real_T c4_low;
  real_T c4_high;
  int32_T c4_i34;
  static char_T c4_cv0[26] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'a', 'n',
    'd', 'i', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'L', 'i', 'm', 'i', 't',
    's' };

  char_T c4_u[26];
  const mxArray *c4_e_y = NULL;
  real_T c4_s;
  real_T c4_r;
  real_T c4_f_x;
  real_T c4_g_x;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_uc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(17, 0, 0, c4_get_pose_lean_flag(chartInstance, 0) == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomPose = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_leanChange;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_leanChange = 1U;
    c4_enter_atomic_leanChange(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomPose = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_stateExtrovertPoseChance;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateExtrovertPoseChance = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_jc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_hoistedGlobal = c4_get_interest(chartInstance, 0);
    c4_b_hoistedGlobal = c4_get_randSlowPose(chartInstance, 0);
    c4_c_hoistedGlobal = c4_get_pose_chance_factor(chartInstance, 0);
    c4_A = c4_hoistedGlobal * c4_b_hoistedGlobal;
    c4_B = c4_c_hoistedGlobal;
    c4_x = c4_A;
    c4_y = c4_B;
    c4_b_x = c4_x;
    c4_b_y = c4_y;
    c4_c_x = c4_b_x;
    c4_c_y = c4_b_y;
    c4_d_y = c4_c_x / c4_c_y;
    c4_d_x = c4_d_y;
    c4_e_x = c4_d_x;
    c4_e_x = muDoubleScalarRound(c4_e_x);
    c4_lowhigh[0] = 0.0;
    c4_lowhigh[1] = c4_e_x;
    c4_low = c4_lowhigh[0];
    c4_high = c4_lowhigh[1];
    if (c4_low <= c4_high) {
    } else {
      for (c4_i34 = 0; c4_i34 < 26; c4_i34++) {
        c4_u[c4_i34] = c4_cv0[c4_i34];
      }

      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 26),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
        1U, 1U, 14, c4_e_y));
    }

    c4_s = (c4_high - c4_low) + 1.0;
    c4_r = c4_rand(chartInstance);
    c4_f_x = c4_r * c4_s;
    c4_g_x = c4_f_x;
    c4_g_x = muDoubleScalarFloor(c4_g_x);
    c4_r = c4_low + c4_g_x;
    c4_set_randPoseChance(chartInstance, 0, c4_r);
    ssUpdateDataStoreLog(chartInstance->S, 31);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c4_sfEvent);
}

static void c4_stateExtrovertPoseChance(SFc4_Expriment_EmotionInstanceStruct
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
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 1.0;
  boolean_T c4_d_out;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 0.0;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 0.0;
  real_T c4_i_nargin = 0.0;
  real_T c4_i_nargout = 1.0;
  boolean_T c4_e_out;
  real_T c4_j_nargin = 0.0;
  real_T c4_j_nargout = 1.0;
  boolean_T c4_f_out;
  real_T c4_k_nargin = 0.0;
  real_T c4_k_nargout = 0.0;
  real_T c4_l_nargin = 0.0;
  real_T c4_l_nargout = 0.0;
  real_T *c4_gameState;
  real_T (*c4_randArray)[40];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ad_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(5, 0, 0, c4_get_pose_speed(chartInstance, 0) == 3.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_dd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    guard5 = false;
    guard6 = false;
    if (CV_EML_COND(6, 0, 0, c4_get_randPoseChance(chartInstance, 0) == 1.0)) {
      if (CV_EML_COND(6, 0, 1, *c4_gameState != c4_get_STATE_GO(chartInstance, 0)))
      {
        if (CV_EML_COND(6, 0, 2, *c4_gameState != c4_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(6, 0, 0, true);
          CV_EML_IF(6, 0, 0, true);
          c4_b_out = true;
        } else {
          guard5 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
        guard6 = true;
      }
    } else {
      c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
      guard6 = true;
    }

    if (guard6 == true) {
      guard5 = true;
    }

    if (guard5 == true) {
      CV_EML_MCDC(6, 0, 0, false);
      CV_EML_IF(6, 0, 0, false);
      c4_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_poseCategoryChance = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_mc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      chartInstance->c4_randPR = (*c4_randArray)[19];
      c4_updateDataWrittenToVector(chartInstance, 4U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_stateRandomPose = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
      ssUpdateDataStoreLog(chartInstance->S, 32);
      c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance,
        0) - c4_get_boredom(chartInstance, 0));
      ssUpdateDataStoreLog(chartInstance->S, 21);
      c4_set_interest(chartInstance, 0, 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 21);
      _SFD_SYMBOL_SCOPE_POP();
    }
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_xc_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_c_out = CV_EML_IF(3, 0, 0, c4_get_pose_speed(chartInstance, 0) == 2.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_cd_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(1, 0, 0, c4_get_randPoseChance(chartInstance, 0) == 1.0))
      {
        if (CV_EML_COND(1, 0, 1, *c4_gameState != c4_get_STATE_GO(chartInstance,
              0))) {
          if (CV_EML_COND(1, 0, 2, *c4_gameState != c4_get_STATE_READY
                          (chartInstance, 0))) {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c4_d_out = true;
          } else {
            guard3 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
          guard4 = true;
        }
      } else {
        c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
        guard4 = true;
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c4_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c4_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_poseCategoryChance1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_kc_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        chartInstance->c4_randPR = (*c4_randArray)[19];
        c4_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_stateRandomPose = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
        ssUpdateDataStoreLog(chartInstance->S, 32);
        c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance,
          0) - c4_get_boredom(chartInstance, 0));
        ssUpdateDataStoreLog(chartInstance->S, 21);
        c4_set_interest(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 21);
        _SFD_SYMBOL_SCOPE_POP();
      }
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_yc_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_e_out = CV_EML_IF(23, 0, 0, c4_get_pose_speed(chartInstance, 0) == 1.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                     chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_bd_debug_family_names,
          c4_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_out, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        guard1 = false;
        guard2 = false;
        if (CV_EML_COND(24, 0, 0, c4_get_randPoseChance(chartInstance, 0) == 1.0))
        {
          if (CV_EML_COND(24, 0, 1, *c4_gameState != c4_get_STATE_GO
                          (chartInstance, 0))) {
            if (CV_EML_COND(24, 0, 2, *c4_gameState != c4_get_STATE_READY
                            (chartInstance, 0))) {
              CV_EML_MCDC(24, 0, 0, true);
              CV_EML_IF(24, 0, 0, true);
              c4_f_out = true;
            } else {
              guard1 = true;
            }
          } else {
            c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
            guard2 = true;
          }
        } else {
          c4_errorIfDataNotWrittenToFcn(chartInstance, 0U, 4U);
          guard2 = true;
        }

        if (guard2 == true) {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(24, 0, 0, false);
          CV_EML_IF(24, 0, 0, false);
          c4_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c4_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_poseCategoryChance2 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_lc_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargin, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_k_nargout, 1U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          chartInstance->c4_randPR = (*c4_randArray)[19];
          c4_updateDataWrittenToVector(chartInstance, 4U);
          _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateExtrovertPoseChance = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c4_sfEvent);
          chartInstance->c4_isStable = false;
          chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
          chartInstance->c4_tp_stateRandomPose = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
            c4_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargin, 0U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_l_nargout, 1U,
            c4_b_sf_marshallOut, c4_b_sf_marshallIn);
          c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
          ssUpdateDataStoreLog(chartInstance->S, 32);
          c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD
                          (chartInstance, 0) - c4_get_boredom(chartInstance, 0));
          ssUpdateDataStoreLog(chartInstance->S, 21);
          c4_set_interest(chartInstance, 0, 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 21);
          _SFD_SYMBOL_SCOPE_POP();
        }
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c4_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c4_sfEvent);
}

static void c4_poseCategoryChance1(SFc4_Expriment_EmotionInstanceStruct
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
  real_T c4_d_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T (*c4_randArray)[40];
  boolean_T guard1 = false;
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_ed_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(21, 0, 0, c4_get_bodyBusyFlag(chartInstance, 0) != 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_kd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
    c4_b_out = CV_EML_IF(13, 0, 0, chartInstance->c4_randPR <=
                         c4_get_pose_cat_chance(chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_poseCategoryChance1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_selfAdaptorPoseCategory;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_selfAdaptorPoseCategory = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_nc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      chartInstance->c4_pose_type = c4_selfAdaptorTypeTablec4_Expriment_Emotion
        (chartInstance, c4_get_pose_speed(chartInstance, 0), c4_get_pose_twitch
         (chartInstance, 0));
      c4_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
      chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
        _SFD_EML_ARRAY_BOUNDS_CHECK(
        "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
        "                                                                                               ^^^^^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
        "                                                                                                           ^^^^^^^^^",
        chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
      c4_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_md_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
      c4_c_out = CV_EML_IF(12, 0, 0, chartInstance->c4_randPR >
                           c4_get_pose_cat_chance(chartInstance, 0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_poseCategoryChance1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_idlePoseGenerate = c4_IN_weightshiftPoseCategory;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_weightshiftPoseCategory = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_oc_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        chartInstance->c4_pose_type =
          c4_weightShiftTypeTablec4_Expriment_Emotion(chartInstance,
          c4_get_pose_speed(chartInstance, 0), c4_get_pose_space(chartInstance,
          0));
        c4_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
        c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
        chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
          _SFD_EML_ARRAY_BOUNDS_CHECK(
          "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
          "                                                                                              ^^^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
          "                                                                                                          ^^^^^^^^^",
          chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
        c4_updateDataWrittenToVector(chartInstance, 16U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_poseCategoryChance1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_poseCategoryChance1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_kc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    chartInstance->c4_randPR = (*c4_randArray)[19];
    c4_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c4_sfEvent);
}

static void c4_poseCategoryChance2(SFc4_Expriment_EmotionInstanceStruct
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
  real_T c4_d_nargout = 1.0;
  boolean_T c4_c_out;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T (*c4_randArray)[40];
  boolean_T guard1 = false;
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_fd_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_out = CV_EML_IF(26, 0, 0, c4_get_bodyBusyFlag(chartInstance, 0) != 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_jd_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_c_sf_marshallOut,
      c4_c_sf_marshallIn);
    c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
    c4_b_out = CV_EML_IF(28, 0, 0, chartInstance->c4_randPR <=
                         c4_get_pose_cat_chance(chartInstance, 0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_poseCategoryChance2 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      chartInstance->c4_isStable = false;
      chartInstance->c4_is_idlePoseGenerate = c4_IN_weightshiftPoseCategory;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_weightshiftPoseCategory = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_oc_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      chartInstance->c4_pose_type = c4_weightShiftTypeTablec4_Expriment_Emotion
        (chartInstance, c4_get_pose_speed(chartInstance, 0), c4_get_pose_space
         (chartInstance, 0));
      c4_updateDataWrittenToVector(chartInstance, 15U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
      chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
        _SFD_EML_ARRAY_BOUNDS_CHECK(
        "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
        "                                                                                              ^^^^^^^^^",
        (int32_T)_SFD_INTEGER_CHECK(
        "State weightshiftPoseCategory #222 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type);\n     "
        "                                                                                                          ^^^^^^^^^",
        chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
      c4_updateDataWrittenToVector(chartInstance, 16U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_id_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U,
        c4_b_sf_marshallOut, c4_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_c_sf_marshallOut,
        c4_c_sf_marshallIn);
      c4_errorIfDataNotWrittenToFcn(chartInstance, 4U, 30U);
      c4_c_out = CV_EML_IF(27, 0, 0, chartInstance->c4_randPR >
                           c4_get_pose_cat_chance(chartInstance, 0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_poseCategoryChance2 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
        chartInstance->c4_isStable = false;
        chartInstance->c4_is_idlePoseGenerate = c4_IN_selfAdaptorPoseCategory;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
        chartInstance->c4_tp_selfAdaptorPoseCategory = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_nc_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U,
          c4_b_sf_marshallOut, c4_b_sf_marshallIn);
        chartInstance->c4_pose_type =
          c4_selfAdaptorTypeTablec4_Expriment_Emotion(chartInstance,
          c4_get_pose_speed(chartInstance, 0), c4_get_pose_twitch(chartInstance,
          0));
        c4_updateDataWrittenToVector(chartInstance, 15U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_pose_type, 53U);
        c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
        chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
          _SFD_EML_ARRAY_BOUNDS_CHECK(
          "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
          "                                                                                               ^^^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "State selfAdaptorPoseCategory #221 in Chart \'CharacterControl/idlePose_Controller\' (#198): poseNum=randArray(:,pose_type) ;\n    "
          "                                                                                                           ^^^^^^^^^",
          chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
        c4_updateDataWrittenToVector(chartInstance, 16U);
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_poseCategoryChance2 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_poseCategoryChance2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_poseCategoryChance2 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_lc_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    chartInstance->c4_randPR = (*c4_randArray)[19];
    c4_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_randPR, 30U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c4_sfEvent);
}

static void c4_weightshiftPoseCategory(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T (*c4_randArray)[40];
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_weightshiftPoseCategory = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c4_sfEvent);
  chartInstance->c4_isStable = false;
  chartInstance->c4_is_idlePoseGenerate = c4_IN_avoidRepeatedPose1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_avoidRepeatedPose1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_sc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 15U, 53U);
  chartInstance->c4_poseNum = (*c4_randArray)[_SFD_ARRAY_BOUNDS_CHECK(28U,
    _SFD_EML_ARRAY_BOUNDS_CHECK(
    "State avoidRepeatedPose1 #1518 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n "
    "                                                                                                     ^^^^^^^^^",
    (int32_T)_SFD_INTEGER_CHECK(
    "State avoidRepeatedPose1 #1518 in Chart \'CharacterControl/idlePose_Controller\' (#198): entry: poseNum=randArray(:,pose_type) ;\n "
    "                                                                                                                 ^^^^^^^^^",
    chartInstance->c4_pose_type), 1, 40, 2, 0) - 1, 0, 39, 2, 0)];
  c4_updateDataWrittenToVector(chartInstance, 16U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_poseNum, 56U);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c4_sfEvent);
}

static void c4_enter_atomic_selfAdaptorPoseCategory1
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_b_BMLl[1000];
  real_T c4_P;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  real_T c4_dv9[5000];
  int32_T c4_i38;
  real_T c4_dv10[1000];
  real_T c4_dv11[5000];
  int32_T c4_i39;
  int32_T c4_i40;
  int32_T c4_i41;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_pc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 16U, 56U);
  chartInstance->c4_oldPose = chartInstance->c4_poseNum;
  c4_updateDataWrittenToVector(chartInstance, 17U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_oldPose, 57U);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 16U, 56U);
  c4_selfAdaptor_TwitchTablec4_Expriment_Emotion(chartInstance,
    chartInstance->c4_poseNum, &c4_P, c4_b_BMLl);
  c4_set_P(chartInstance, 0, c4_P);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  for (c4_i35 = 0; c4_i35 < 1000; c4_i35++) {
    chartInstance->c4_BMLl[c4_i35] = c4_b_BMLl[c4_i35];
  }

  c4_updateDataWrittenToVector(chartInstance, 12U);
  for (c4_i36 = 0; c4_i36 < 1000; c4_i36++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_BMLl[c4_i36], 41U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 12U, 41U);
  for (c4_i37 = 0; c4_i37 < 5000; c4_i37++) {
    c4_dv9[c4_i37] = c4_get_bmlsL(chartInstance, c4_i37);
  }

  for (c4_i38 = 0; c4_i38 < 1000; c4_i38++) {
    c4_dv10[c4_i38] = chartInstance->c4_BMLl[c4_i38];
  }

  c4_insertQueueLowc4_Expriment_Emotion(chartInstance, c4_dv9, c4_dv10, c4_dv11);
  for (c4_i39 = 0; c4_i39 < 5000; c4_i39++) {
    chartInstance->c4_newBmlsL[c4_i39] = c4_dv11[c4_i39];
  }

  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i40 = 0; c4_i40 < 5000; c4_i40++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i40], 25U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 2U, 25U);
  for (c4_i41 = 0; c4_i41 < 5000; c4_i41++) {
    c4_set_bmlsL(chartInstance, c4_i41, chartInstance->c4_newBmlsL[c4_i41]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_enter_atomic_weightshiftPoseCategory1
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[2];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 0.0;
  real_T c4_b_BMLl[1000];
  real_T c4_P;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  real_T c4_dv12[5000];
  int32_T c4_i45;
  real_T c4_dv13[1000];
  real_T c4_dv14[5000];
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_qc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  c4_errorIfDataNotWrittenToFcn(chartInstance, 16U, 56U);
  c4_weightshift_SpaceTablec4_Expriment_Emotion(chartInstance,
    chartInstance->c4_poseNum, &c4_P, c4_b_BMLl);
  c4_set_P(chartInstance, 0, c4_P);
  ssUpdateDataStoreLog(chartInstance->S, 9);
  for (c4_i42 = 0; c4_i42 < 1000; c4_i42++) {
    chartInstance->c4_BMLl[c4_i42] = c4_b_BMLl[c4_i42];
  }

  c4_updateDataWrittenToVector(chartInstance, 12U);
  for (c4_i43 = 0; c4_i43 < 1000; c4_i43++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_BMLl[c4_i43], 41U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 12U, 41U);
  for (c4_i44 = 0; c4_i44 < 5000; c4_i44++) {
    c4_dv12[c4_i44] = c4_get_bmlsL(chartInstance, c4_i44);
  }

  for (c4_i45 = 0; c4_i45 < 1000; c4_i45++) {
    c4_dv13[c4_i45] = chartInstance->c4_BMLl[c4_i45];
  }

  c4_insertQueueLowc4_Expriment_Emotion(chartInstance, c4_dv12, c4_dv13, c4_dv14);
  for (c4_i46 = 0; c4_i46 < 5000; c4_i46++) {
    chartInstance->c4_newBmlsL[c4_i46] = c4_dv14[c4_i46];
  }

  c4_updateDataWrittenToVector(chartInstance, 2U);
  for (c4_i47 = 0; c4_i47 < 5000; c4_i47++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_newBmlsL[c4_i47], 25U);
  }

  c4_errorIfDataNotWrittenToFcn(chartInstance, 2U, 25U);
  for (c4_i48 = 0; c4_i48 < 5000; c4_i48++) {
    c4_set_bmlsL(chartInstance, c4_i48, chartInstance->c4_newBmlsL[c4_i48]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 15);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_weightshiftPoseCategory1(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_out;
  boolean_T c4_temp;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T (*c4_randArray)[40];
  c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S, 2);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_vc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  c4_temp = (chartInstance->c4_sfEvent == c4_event_secs);
  if (c4_temp) {
    c4_temp = (chartInstance->c4_temporalCounter_i1 >=
               _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
                c4_get_pose_frequency_factor(chartInstance, 0), 32U, 15U));
  }

  c4_out = CV_EML_IF(15, 0, 0, c4_temp);
  _SFD_SYMBOL_SCOPE_POP();
  if (c4_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_weightshiftPoseCategory1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c4_sfEvent);
    chartInstance->c4_isStable = false;
    chartInstance->c4_is_idlePoseGenerate = c4_IN_stateRandomPose;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c4_sfEvent);
    chartInstance->c4_tp_stateRandomPose = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_ic_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_set_randSlowPose(chartInstance, 0, (*c4_randArray)[10]);
    ssUpdateDataStoreLog(chartInstance->S, 32);
    c4_set_interest(chartInstance, 0, c4_get_BOREDOM_THRESHOLD(chartInstance, 0)
                    - c4_get_boredom(chartInstance, 0));
    ssUpdateDataStoreLog(chartInstance->S, 21);
    c4_set_interest(chartInstance, 0, 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 21);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c4_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c4_sfEvent);
}

static void c4_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i49;
  static char_T c4_cv1[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i50;
  static real_T c4_dv15[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
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
  for (c4_i49 = 0; c4_i49 < 103; c4_i49++) {
    c4_mystr[c4_i49] = c4_cv1[c4_i49];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i50 = 0; c4_i50 < 103; c4_i50++) {
    c4_arr[c4_i50] = c4_dv15[c4_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i51 = 0; c4_i51 < 1000; c4_i51++) {
    c4_tt[c4_i51] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i52 = 0; c4_i52 < 103; c4_i52++) {
    c4_tt[c4_i52] = c4_arr[c4_i52];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i53 = 0; c4_i53 < 1000; c4_i53++) {
    c4_myarr256[c4_i53] = c4_tt[c4_i53];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_b_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[102];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[102];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i54;
  static char_T c4_cv2[102] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h', 't',
    'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  int32_T c4_i55;
  static real_T c4_dv16[102] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_c_debug_family_names,
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
  for (c4_i54 = 0; c4_i54 < 102; c4_i54++) {
    c4_mystr[c4_i54] = c4_cv2[c4_i54];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i55 = 0; c4_i55 < 102; c4_i55++) {
    c4_arr[c4_i55] = c4_dv16[c4_i55];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 102.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i56 = 0; c4_i56 < 1000; c4_i56++) {
    c4_tt[c4_i56] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i57 = 0; c4_i57 < 102; c4_i57++) {
    c4_tt[c4_i57] = c4_arr[c4_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i58 = 0; c4_i58 < 1000; c4_i58++) {
    c4_myarr256[c4_i58] = c4_tt[c4_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_c_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i59;
  static char_T c4_cv3[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l', 'd',
    'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's', 'p',
    'e', 'e', 'd', '=', '\"', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i60;
  static real_T c4_dv17[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_d_debug_family_names,
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
  for (c4_i59 = 0; c4_i59 < 106; c4_i59++) {
    c4_mystr[c4_i59] = c4_cv3[c4_i59];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i60 = 0; c4_i60 < 106; c4_i60++) {
    c4_arr[c4_i60] = c4_dv17[c4_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i61 = 0; c4_i61 < 1000; c4_i61++) {
    c4_tt[c4_i61] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i62 = 0; c4_i62 < 106; c4_i62++) {
    c4_tt[c4_i62] = c4_arr[c4_i62];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i63 = 0; c4_i63 < 1000; c4_i63++) {
    c4_myarr256[c4_i63] = c4_tt[c4_i63];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_d_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[104];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[104];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i64;
  static char_T c4_cv4[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i65;
  static real_T c4_dv18[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_e_debug_family_names,
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
  for (c4_i64 = 0; c4_i64 < 104; c4_i64++) {
    c4_mystr[c4_i64] = c4_cv4[c4_i64];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i65 = 0; c4_i65 < 104; c4_i65++) {
    c4_arr[c4_i65] = c4_dv18[c4_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i66 = 0; c4_i66 < 1000; c4_i66++) {
    c4_tt[c4_i66] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i67 = 0; c4_i67 < 104; c4_i67++) {
    c4_tt[c4_i67] = c4_arr[c4_i67];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i68 = 0; c4_i68 < 1000; c4_i68++) {
    c4_myarr256[c4_i68] = c4_tt[c4_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_e_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i69;
  static char_T c4_cv5[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's', 'p',
    'e', 'e', 'd', '=', '\"', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i70;
  static real_T c4_dv19[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_f_debug_family_names,
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
  for (c4_i69 = 0; c4_i69 < 106; c4_i69++) {
    c4_mystr[c4_i69] = c4_cv5[c4_i69];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i70 = 0; c4_i70 < 106; c4_i70++) {
    c4_arr[c4_i70] = c4_dv19[c4_i70];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i71 = 0; c4_i71 < 1000; c4_i71++) {
    c4_tt[c4_i71] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i72 = 0; c4_i72 < 106; c4_i72++) {
    c4_tt[c4_i72] = c4_arr[c4_i72];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i73 = 0; c4_i73 < 1000; c4_i73++) {
    c4_myarr256[c4_i73] = c4_tt[c4_i73];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_f_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i74;
  static char_T c4_cv6[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't', 'c',
    'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '2', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i75;
  static real_T c4_dv20[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i78;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_g_debug_family_names,
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
  for (c4_i74 = 0; c4_i74 < 103; c4_i74++) {
    c4_mystr[c4_i74] = c4_cv6[c4_i74];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i75 = 0; c4_i75 < 103; c4_i75++) {
    c4_arr[c4_i75] = c4_dv20[c4_i75];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i76 = 0; c4_i76 < 1000; c4_i76++) {
    c4_tt[c4_i76] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i77 = 0; c4_i77 < 103; c4_i77++) {
    c4_tt[c4_i77] = c4_arr[c4_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i78 = 0; c4_i78 < 1000; c4_i78++) {
    c4_myarr256[c4_i78] = c4_tt[c4_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_g_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i79;
  static char_T c4_cv7[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e', 'z',
    'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i80;
  static real_T c4_dv21[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i81;
  int32_T c4_i82;
  int32_T c4_i83;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_h_debug_family_names,
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
  for (c4_i79 = 0; c4_i79 < 103; c4_i79++) {
    c4_mystr[c4_i79] = c4_cv7[c4_i79];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i80 = 0; c4_i80 < 103; c4_i80++) {
    c4_arr[c4_i80] = c4_dv21[c4_i80];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i81 = 0; c4_i81 < 1000; c4_i81++) {
    c4_tt[c4_i81] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i82 = 0; c4_i82 < 103; c4_i82++) {
    c4_tt[c4_i82] = c4_arr[c4_i82];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i83 = 0; c4_i83 < 1000; c4_i83++) {
    c4_myarr256[c4_i83] = c4_tt[c4_i83];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_h_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[321];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[321];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i84;
  static char_T c4_cv8[321] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's', 'b',
    'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"',
    ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a',
    'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"', ' ',
    's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e',
    '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'n', 'a',
    'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/', 'C', 'h', 'r',
    'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd', 'l', 'e', '_',
    'b', 'r', 'u', 's', 'h', '_', 'c', 'e', 'n', 't', 'e', 'r', '.', 's', 'k',
    'm', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '2', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i85;
  static real_T c4_dv22[321] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0,
    61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 98.0, 114.0, 117.0, 115.0, 104.0, 95.0,
    99.0, 101.0, 110.0, 116.0, 101.0, 114.0, 46.0, 115.0, 107.0, 109.0, 34.0,
    32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_i_debug_family_names,
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
  for (c4_i84 = 0; c4_i84 < 321; c4_i84++) {
    c4_mystr[c4_i84] = c4_cv8[c4_i84];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i85 = 0; c4_i85 < 321; c4_i85++) {
    c4_arr[c4_i85] = c4_dv22[c4_i85];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 321.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i86 = 0; c4_i86 < 1000; c4_i86++) {
    c4_tt[c4_i86] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i87 = 0; c4_i87 < 321; c4_i87++) {
    c4_tt[c4_i87] = c4_arr[c4_i87];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i88 = 0; c4_i88 < 1000; c4_i88++) {
    c4_myarr256[c4_i88] = c4_tt[c4_i88];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_i_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[320];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[320];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i89;
  static char_T c4_cv9[320] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a', 'n',
    'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T',
    'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n', ' ',
    'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/', 'C',
    'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd', 'l',
    'e', '_', 'h', 'a', 'n', 'd', '_', 'l', 'o', 'o', 'k', '.', 's', 'k', 'm',
    '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '2', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i90;
  static real_T c4_dv23[320] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 104.0, 97.0, 110.0, 100.0, 95.0, 108.0,
    111.0, 111.0, 107.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_j_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i89 = 0; c4_i89 < 320; c4_i89++) {
    c4_mystr[c4_i89] = c4_cv9[c4_i89];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i90 = 0; c4_i90 < 320; c4_i90++) {
    c4_arr[c4_i90] = c4_dv23[c4_i90];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 320.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i91 = 0; c4_i91 < 1000; c4_i91++) {
    c4_tt[c4_i91] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i92 = 0; c4_i92 < 320; c4_i92++) {
    c4_tt[c4_i92] = c4_arr[c4_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i93 = 0; c4_i93 < 1000; c4_i93++) {
    c4_myarr256[c4_i93] = c4_tt[c4_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_j_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[104];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[104];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i94;
  static char_T c4_cv10[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h',
    'H', 'a', 'n', 'd', 's', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '0', '.', '8', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i95;
  static real_T c4_dv24[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 56.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_k_debug_family_names,
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
  for (c4_i94 = 0; c4_i94 < 104; c4_i94++) {
    c4_mystr[c4_i94] = c4_cv10[c4_i94];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i95 = 0; c4_i95 < 104; c4_i95++) {
    c4_arr[c4_i95] = c4_dv24[c4_i95];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i96 = 0; c4_i96 < 1000; c4_i96++) {
    c4_tt[c4_i96] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i97 = 0; c4_i97 < 104; c4_i97++) {
    c4_tt[c4_i97] = c4_arr[c4_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i98 = 0; c4_i98 < 1000; c4_i98++) {
    c4_myarr256[c4_i98] = c4_tt[c4_i98];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_k_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i99;
  static char_T c4_cv11[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i100;
  static real_T c4_dv25[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_l_debug_family_names,
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
  for (c4_i99 = 0; c4_i99 < 103; c4_i99++) {
    c4_mystr[c4_i99] = c4_cv11[c4_i99];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i100 = 0; c4_i100 < 103; c4_i100++) {
    c4_arr[c4_i100] = c4_dv25[c4_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i101 = 0; c4_i101 < 1000; c4_i101++) {
    c4_tt[c4_i101] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i102 = 0; c4_i102 < 103; c4_i102++) {
    c4_tt[c4_i102] = c4_arr[c4_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i103 = 0; c4_i103 < 1000; c4_i103++) {
    c4_myarr256[c4_i103] = c4_tt[c4_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_l_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i104;
  static char_T c4_cv12[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h',
    't', 'S', 'h', 'i', 'f', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i105;
  static real_T c4_dv26[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_m_debug_family_names,
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
  for (c4_i104 = 0; c4_i104 < 103; c4_i104++) {
    c4_mystr[c4_i104] = c4_cv12[c4_i104];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i105 = 0; c4_i105 < 103; c4_i105++) {
    c4_arr[c4_i105] = c4_dv26[c4_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i106 = 0; c4_i106 < 1000; c4_i106++) {
    c4_tt[c4_i106] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i107 = 0; c4_i107 < 103; c4_i107++) {
    c4_tt[c4_i107] = c4_arr[c4_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i108 = 0; c4_i108 < 1000; c4_i108++) {
    c4_myarr256[c4_i108] = c4_tt[c4_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_m_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[107];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[107];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i109;
  static char_T c4_cv13[107] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm',
    'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i110;
  static real_T c4_dv27[107] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i111;
  int32_T c4_i112;
  int32_T c4_i113;
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
  for (c4_i109 = 0; c4_i109 < 107; c4_i109++) {
    c4_mystr[c4_i109] = c4_cv13[c4_i109];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i110 = 0; c4_i110 < 107; c4_i110++) {
    c4_arr[c4_i110] = c4_dv27[c4_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 107.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i111 = 0; c4_i111 < 1000; c4_i111++) {
    c4_tt[c4_i111] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i112 = 0; c4_i112 < 107; c4_i112++) {
    c4_tt[c4_i112] = c4_arr[c4_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i113 = 0; c4_i113 < 1000; c4_i113++) {
    c4_myarr256[c4_i113] = c4_tt[c4_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_n_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i114;
  static char_T c4_cv14[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i115;
  static real_T c4_dv28[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i116;
  int32_T c4_i117;
  int32_T c4_i118;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_o_debug_family_names,
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
  for (c4_i114 = 0; c4_i114 < 103; c4_i114++) {
    c4_mystr[c4_i114] = c4_cv14[c4_i114];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i115 = 0; c4_i115 < 103; c4_i115++) {
    c4_arr[c4_i115] = c4_dv28[c4_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i116 = 0; c4_i116 < 1000; c4_i116++) {
    c4_tt[c4_i116] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i117 = 0; c4_i117 < 103; c4_i117++) {
    c4_tt[c4_i117] = c4_arr[c4_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i118 = 0; c4_i118 < 1000; c4_i118++) {
    c4_myarr256[c4_i118] = c4_tt[c4_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_o_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i119;
  static char_T c4_cv15[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '7', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i120;
  static real_T c4_dv29[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 55.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i121;
  int32_T c4_i122;
  int32_T c4_i123;
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
  for (c4_i119 = 0; c4_i119 < 105; c4_i119++) {
    c4_mystr[c4_i119] = c4_cv15[c4_i119];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i120 = 0; c4_i120 < 105; c4_i120++) {
    c4_arr[c4_i120] = c4_dv29[c4_i120];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i121 = 0; c4_i121 < 1000; c4_i121++) {
    c4_tt[c4_i121] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i122 = 0; c4_i122 < 105; c4_i122++) {
    c4_tt[c4_i122] = c4_arr[c4_i122];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i123 = 0; c4_i123 < 1000; c4_i123++) {
    c4_myarr256[c4_i123] = c4_tt[c4_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_p_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i124;
  static char_T c4_cv16[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i125;
  static real_T c4_dv30[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i126;
  int32_T c4_i127;
  int32_T c4_i128;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_q_debug_family_names,
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
  for (c4_i124 = 0; c4_i124 < 106; c4_i124++) {
    c4_mystr[c4_i124] = c4_cv16[c4_i124];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i125 = 0; c4_i125 < 106; c4_i125++) {
    c4_arr[c4_i125] = c4_dv30[c4_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i126 = 0; c4_i126 < 1000; c4_i126++) {
    c4_tt[c4_i126] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i127 = 0; c4_i127 < 106; c4_i127++) {
    c4_tt[c4_i127] = c4_arr[c4_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i128 = 0; c4_i128 < 1000; c4_i128++) {
    c4_myarr256[c4_i128] = c4_tt[c4_i128];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_q_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[102];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[102];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i129;
  static char_T c4_cv17[102] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'W', 'e', 'i', 'g', 'h',
    't', 'S', 'h', 'i', 'f', 't', '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i130;
  static real_T c4_dv31[102] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 87.0, 101.0,
    105.0, 103.0, 104.0, 116.0, 83.0, 104.0, 105.0, 102.0, 116.0, 48.0, 50.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i131;
  int32_T c4_i132;
  int32_T c4_i133;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_r_debug_family_names,
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
  for (c4_i129 = 0; c4_i129 < 102; c4_i129++) {
    c4_mystr[c4_i129] = c4_cv17[c4_i129];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i130 = 0; c4_i130 < 102; c4_i130++) {
    c4_arr[c4_i130] = c4_dv31[c4_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 102.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i131 = 0; c4_i131 < 1000; c4_i131++) {
    c4_tt[c4_i131] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i132 = 0; c4_i132 < 102; c4_i132++) {
    c4_tt[c4_i132] = c4_arr[c4_i132];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i133 = 0; c4_i133 < 1000; c4_i133++) {
    c4_myarr256[c4_i133] = c4_tt[c4_i133];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_r_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[314];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[314];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i134;
  static char_T c4_cv18[314] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T',
    'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't',
    '\"', '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'n',
    'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd', 'l', 'e',
    '_', 'b', 'r', 'u', 's', 'h', '.', 's', 'k', 'm', '\"', ' ', 's', 'p', 'e',
    'e', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i135;
  static real_T c4_dv32[314] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0,
    61.0, 34.0, 51.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 98.0, 114.0, 117.0, 115.0, 104.0, 46.0,
    115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i136;
  int32_T c4_i137;
  int32_T c4_i138;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_s_debug_family_names,
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
  for (c4_i134 = 0; c4_i134 < 314; c4_i134++) {
    c4_mystr[c4_i134] = c4_cv18[c4_i134];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i135 = 0; c4_i135 < 314; c4_i135++) {
    c4_arr[c4_i135] = c4_dv32[c4_i135];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 314.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i136 = 0; c4_i136 < 1000; c4_i136++) {
    c4_tt[c4_i136] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i137 = 0; c4_i137 < 314; c4_i137++) {
    c4_tt[c4_i137] = c4_arr[c4_i137];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i138 = 0; c4_i138 < 1000; c4_i138++) {
    c4_myarr256[c4_i138] = c4_tt[c4_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_s_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[321];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[321];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i139;
  static char_T c4_cv19[321] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ', 's',
    'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1',
    '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T',
    'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'L', 'E', 'F', 'T', '\"',
    ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g',
    'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':', 't', 'i',
    'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't', 'a', 'r',
    'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't',
    '\"', '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'n',
    'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/', 'C', 'h',
    'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd', 'l', 'e',
    '_', 'b', 'r', 'u', 's', 'h', '_', 'c', 'e', 'n', 't', 'e', 'r', '.', 's',
    'k', 'm', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '1', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i140;
  static real_T c4_dv33[321] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0,
    70.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0,
    116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0,
    49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0,
    97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0,
    60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0, 101.0,
    61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 76.0, 69.0, 70.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0,
    116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0, 69.0,
    83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 98.0, 114.0, 117.0, 115.0, 104.0, 95.0,
    99.0, 101.0, 110.0, 116.0, 101.0, 114.0, 46.0, 115.0, 107.0, 109.0, 34.0,
    32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i141;
  int32_T c4_i142;
  int32_T c4_i143;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_t_debug_family_names,
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
  for (c4_i139 = 0; c4_i139 < 321; c4_i139++) {
    c4_mystr[c4_i139] = c4_cv19[c4_i139];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i140 = 0; c4_i140 < 321; c4_i140++) {
    c4_arr[c4_i140] = c4_dv33[c4_i140];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 321.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i141 = 0; c4_i141 < 1000; c4_i141++) {
    c4_tt[c4_i141] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i142 = 0; c4_i142 < 321; c4_i142++) {
    c4_tt[c4_i142] = c4_arr[c4_i142];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i143 = 0; c4_i143 < 1000; c4_i143++) {
    c4_myarr256[c4_i143] = c4_tt[c4_i143];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_t_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[320];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[320];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i144;
  static char_T c4_cv20[320] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '1', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ',
    'a', 'n', 'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e',
    'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '1', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n',
    ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/',
    'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd',
    'l', 'e', '_', 'h', 'a', 'n', 'd', '_', 'l', 'o', 'o', 'k', '.', 's', 'k',
    'm', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '1', '\"', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i145;
  static real_T c4_dv34[320] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 49.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 104.0, 97.0, 110.0, 100.0, 95.0, 108.0,
    111.0, 111.0, 107.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i146;
  int32_T c4_i147;
  int32_T c4_i148;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_u_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_p_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_o_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i144 = 0; c4_i144 < 320; c4_i144++) {
    c4_mystr[c4_i144] = c4_cv20[c4_i144];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i145 = 0; c4_i145 < 320; c4_i145++) {
    c4_arr[c4_i145] = c4_dv34[c4_i145];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 320.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i146 = 0; c4_i146 < 1000; c4_i146++) {
    c4_tt[c4_i146] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i147 = 0; c4_i147 < 320; c4_i147++) {
    c4_tt[c4_i147] = c4_arr[c4_i147];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i148 = 0; c4_i148 < 1000; c4_i148++) {
    c4_myarr256[c4_i148] = c4_tt[c4_i148];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_u_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[104];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[104];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i149;
  static char_T c4_cv21[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e',
    'e', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i150;
  static real_T c4_dv35[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i151;
  int32_T c4_i152;
  int32_T c4_i153;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_w_debug_family_names,
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
  for (c4_i149 = 0; c4_i149 < 104; c4_i149++) {
    c4_mystr[c4_i149] = c4_cv21[c4_i149];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i150 = 0; c4_i150 < 104; c4_i150++) {
    c4_arr[c4_i150] = c4_dv35[c4_i150];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i151 = 0; c4_i151 < 1000; c4_i151++) {
    c4_tt[c4_i151] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i152 = 0; c4_i152 < 104; c4_i152++) {
    c4_tt[c4_i152] = c4_arr[c4_i152];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i153 = 0; c4_i153 < 1000; c4_i153++) {
    c4_myarr256[c4_i153] = c4_tt[c4_i153];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_v_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i154;
  static char_T c4_cv22[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i155;
  static real_T c4_dv36[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i156;
  int32_T c4_i157;
  int32_T c4_i158;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_x_debug_family_names,
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
  for (c4_i154 = 0; c4_i154 < 106; c4_i154++) {
    c4_mystr[c4_i154] = c4_cv22[c4_i154];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i155 = 0; c4_i155 < 106; c4_i155++) {
    c4_arr[c4_i155] = c4_dv36[c4_i155];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i156 = 0; c4_i156 < 1000; c4_i156++) {
    c4_tt[c4_i156] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i157 = 0; c4_i157 < 106; c4_i157++) {
    c4_tt[c4_i157] = c4_arr[c4_i157];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i158 = 0; c4_i158 < 1000; c4_i158++) {
    c4_myarr256[c4_i158] = c4_tt[c4_i158];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_w_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[102];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[102];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i159;
  static char_T c4_cv23[102] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h',
    'H', 'a', 'n', 'd', 's', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '1', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a',
    'c', 't', '>' };

  int32_T c4_i160;
  static real_T c4_dv37[102] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 32.0, 47.0, 62.0,
    60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i161;
  int32_T c4_i162;
  int32_T c4_i163;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_y_debug_family_names,
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
  for (c4_i159 = 0; c4_i159 < 102; c4_i159++) {
    c4_mystr[c4_i159] = c4_cv23[c4_i159];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i160 = 0; c4_i160 < 102; c4_i160++) {
    c4_arr[c4_i160] = c4_dv37[c4_i160];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 102.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i161 = 0; c4_i161 < 1000; c4_i161++) {
    c4_tt[c4_i161] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i162 = 0; c4_i162 < 102; c4_i162++) {
    c4_tt[c4_i162] = c4_arr[c4_i162];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i163 = 0; c4_i163 < 1000; c4_i163++) {
    c4_myarr256[c4_i163] = c4_tt[c4_i163];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_x_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i164;
  static char_T c4_cv24[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '1', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i165;
  static real_T c4_dv38[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i166;
  int32_T c4_i167;
  int32_T c4_i168;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ab_debug_family_names,
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
  for (c4_i164 = 0; c4_i164 < 103; c4_i164++) {
    c4_mystr[c4_i164] = c4_cv24[c4_i164];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i165 = 0; c4_i165 < 103; c4_i165++) {
    c4_arr[c4_i165] = c4_dv38[c4_i165];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i166 = 0; c4_i166 < 1000; c4_i166++) {
    c4_tt[c4_i166] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i167 = 0; c4_i167 < 103; c4_i167++) {
    c4_tt[c4_i167] = c4_arr[c4_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i168 = 0; c4_i168 < 1000; c4_i168++) {
    c4_myarr256[c4_i168] = c4_tt[c4_i168];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_y_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[104];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[104];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i169;
  static char_T c4_cv25[104] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'u', 'c', 'h',
    'H', 'a', 'n', 'd', 's', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '1', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c4_i170;
  static real_T c4_dv39[104] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    117.0, 99.0, 104.0, 72.0, 97.0, 110.0, 100.0, 115.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 32.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c4_i171;
  int32_T c4_i172;
  int32_T c4_i173;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_bb_debug_family_names,
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
  for (c4_i169 = 0; c4_i169 < 104; c4_i169++) {
    c4_mystr[c4_i169] = c4_cv25[c4_i169];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i170 = 0; c4_i170 < 104; c4_i170++) {
    c4_arr[c4_i170] = c4_dv39[c4_i170];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 104.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i171 = 0; c4_i171 < 1000; c4_i171++) {
    c4_tt[c4_i171] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i172 = 0; c4_i172 < 104; c4_i172++) {
    c4_tt[c4_i172] = c4_arr[c4_i172];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i173 = 0; c4_i173 < 1000; c4_i173++) {
    c4_myarr256[c4_i173] = c4_tt[c4_i173];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_ab_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i174;
  static char_T c4_cv26[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i175;
  static real_T c4_dv40[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0,
    53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i176;
  int32_T c4_i177;
  int32_T c4_i178;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_cb_debug_family_names,
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
  for (c4_i174 = 0; c4_i174 < 105; c4_i174++) {
    c4_mystr[c4_i174] = c4_cv26[c4_i174];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i175 = 0; c4_i175 < 105; c4_i175++) {
    c4_arr[c4_i175] = c4_dv40[c4_i175];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i176 = 0; c4_i176 < 1000; c4_i176++) {
    c4_tt[c4_i176] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i177 = 0; c4_i177 < 105; c4_i177++) {
    c4_tt[c4_i177] = c4_arr[c4_i177];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i178 = 0; c4_i178 < 1000; c4_i178++) {
    c4_myarr256[c4_i178] = c4_tt[c4_i178];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_bb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[109];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[109];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i179;
  static char_T c4_cv27[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '1', '.', '5', '\"', ' ', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i180;
  static real_T c4_dv41[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 46.0, 53.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i181;
  int32_T c4_i182;
  int32_T c4_i183;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_db_debug_family_names,
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
  for (c4_i179 = 0; c4_i179 < 109; c4_i179++) {
    c4_mystr[c4_i179] = c4_cv27[c4_i179];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i180 = 0; c4_i180 < 109; c4_i180++) {
    c4_arr[c4_i180] = c4_dv41[c4_i180];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 109.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i181 = 0; c4_i181 < 1000; c4_i181++) {
    c4_tt[c4_i181] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i182 = 0; c4_i182 < 109; c4_i182++) {
    c4_tt[c4_i182] = c4_arr[c4_i182];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i183 = 0; c4_i183 < 1000; c4_i183++) {
    c4_myarr256[c4_i183] = c4_tt[c4_i183];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_cb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i184;
  static char_T c4_cv28[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '1', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i185;
  static real_T c4_dv42[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i186;
  int32_T c4_i187;
  int32_T c4_i188;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_eb_debug_family_names,
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
  for (c4_i184 = 0; c4_i184 < 105; c4_i184++) {
    c4_mystr[c4_i184] = c4_cv28[c4_i184];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i185 = 0; c4_i185 < 105; c4_i185++) {
    c4_arr[c4_i185] = c4_dv42[c4_i185];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i186 = 0; c4_i186 < 1000; c4_i186++) {
    c4_tt[c4_i186] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i187 = 0; c4_i187 < 105; c4_i187++) {
    c4_tt[c4_i187] = c4_arr[c4_i187];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i188 = 0; c4_i188 < 1000; c4_i188++) {
    c4_myarr256[c4_i188] = c4_tt[c4_i188];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_db_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i189;
  static char_T c4_cv29[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '1', '.', '2', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i190;
  static real_T c4_dv43[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 50.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i191;
  int32_T c4_i192;
  int32_T c4_i193;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_fb_debug_family_names,
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
  for (c4_i189 = 0; c4_i189 < 105; c4_i189++) {
    c4_mystr[c4_i189] = c4_cv29[c4_i189];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i190 = 0; c4_i190 < 105; c4_i190++) {
    c4_arr[c4_i190] = c4_dv43[c4_i190];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i191 = 0; c4_i191 < 1000; c4_i191++) {
    c4_tt[c4_i191] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i192 = 0; c4_i192 < 105; c4_i192++) {
    c4_tt[c4_i192] = c4_arr[c4_i192];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i193 = 0; c4_i193 < 1000; c4_i193++) {
    c4_myarr256[c4_i193] = c4_tt[c4_i193];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_eb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i194;
  static char_T c4_cv30[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e',
    'e', 'd', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i195;
  static real_T c4_dv44[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0,
    53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i196;
  int32_T c4_i197;
  int32_T c4_i198;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_gb_debug_family_names,
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
  for (c4_i194 = 0; c4_i194 < 106; c4_i194++) {
    c4_mystr[c4_i194] = c4_cv30[c4_i194];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i195 = 0; c4_i195 < 106; c4_i195++) {
    c4_arr[c4_i195] = c4_dv44[c4_i195];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i196 = 0; c4_i196 < 1000; c4_i196++) {
    c4_tt[c4_i196] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i197 = 0; c4_i197 < 106; c4_i197++) {
    c4_tt[c4_i197] = c4_arr[c4_i197];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i198 = 0; c4_i198 < 1000; c4_i198++) {
    c4_myarr256[c4_i198] = c4_tt[c4_i198];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_fb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i199;
  static char_T c4_cv31[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '4', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i200;
  static real_T c4_dv45[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 52.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0,
    47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i201;
  int32_T c4_i202;
  int32_T c4_i203;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_hb_debug_family_names,
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
  for (c4_i199 = 0; c4_i199 < 106; c4_i199++) {
    c4_mystr[c4_i199] = c4_cv31[c4_i199];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i200 = 0; c4_i200 < 106; c4_i200++) {
    c4_arr[c4_i200] = c4_dv45[c4_i200];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i201 = 0; c4_i201 < 1000; c4_i201++) {
    c4_tt[c4_i201] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i202 = 0; c4_i202 < 106; c4_i202++) {
    c4_tt[c4_i202] = c4_arr[c4_i202];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i203 = 0; c4_i203 < 1000; c4_i203++) {
    c4_myarr256[c4_i203] = c4_tt[c4_i203];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_gb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i204;
  static char_T c4_cv32[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd',
    '=', '\"', '0', '.', '5', '\"', ' ', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i205;
  static real_T c4_dv46[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 53.0,
    34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i206;
  int32_T c4_i207;
  int32_T c4_i208;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ib_debug_family_names,
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
  for (c4_i204 = 0; c4_i204 < 105; c4_i204++) {
    c4_mystr[c4_i204] = c4_cv32[c4_i204];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i205 = 0; c4_i205 < 105; c4_i205++) {
    c4_arr[c4_i205] = c4_dv46[c4_i205];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i206 = 0; c4_i206 < 1000; c4_i206++) {
    c4_tt[c4_i206] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i207 = 0; c4_i207 < 105; c4_i207++) {
    c4_tt[c4_i207] = c4_arr[c4_i207];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i208 = 0; c4_i208 < 1000; c4_i208++) {
    c4_myarr256[c4_i208] = c4_tt[c4_i208];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_hb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[106];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[106];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i209;
  static char_T c4_cv33[106] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'H', 'e', 'a', 'd', 'L', 'f', '0', '1', '\"', ' ', 's', 'p', 'e',
    'e', 'd', '=', '\"', '0', '.', '6', '\"', '/', '>', '<', '/', 'b', 'm', 'l',
    '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i210;
  static real_T c4_dv47[106] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 72.0, 101.0, 97.0, 100.0, 76.0, 102.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i211;
  int32_T c4_i212;
  int32_T c4_i213;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_jb_debug_family_names,
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
  for (c4_i209 = 0; c4_i209 < 106; c4_i209++) {
    c4_mystr[c4_i209] = c4_cv33[c4_i209];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i210 = 0; c4_i210 < 106; c4_i210++) {
    c4_arr[c4_i210] = c4_dv47[c4_i210];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 106.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i211 = 0; c4_i211 < 1000; c4_i211++) {
    c4_tt[c4_i211] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i212 = 0; c4_i212 < 106; c4_i212++) {
    c4_tt[c4_i212] = c4_arr[c4_i212];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i213 = 0; c4_i213 < 1000; c4_i213++) {
    c4_myarr256[c4_i213] = c4_tt[c4_i213];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_ib_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i214;
  static char_T c4_cv34[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'T', 'e', 'm', 'p', 'l', 'e', 'L', 'f', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '0', '.', '6', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i215;
  static real_T c4_dv48[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 84.0, 101.0, 109.0, 112.0, 108.0, 101.0,
    76.0, 102.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i216;
  int32_T c4_i217;
  int32_T c4_i218;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_kb_debug_family_names,
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
  for (c4_i214 = 0; c4_i214 < 108; c4_i214++) {
    c4_mystr[c4_i214] = c4_cv34[c4_i214];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i215 = 0; c4_i215 < 108; c4_i215++) {
    c4_arr[c4_i215] = c4_dv48[c4_i215];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i216 = 0; c4_i216 < 1000; c4_i216++) {
    c4_tt[c4_i216] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i217 = 0; c4_i217 < 108; c4_i217++) {
    c4_tt[c4_i217] = c4_arr[c4_i217];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i218 = 0; c4_i218 < 1000; c4_i218++) {
    c4_myarr256[c4_i218] = c4_tt[c4_i218];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_jb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i219;
  static char_T c4_cv35[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'c', 'r', 'a', 't',
    'c', 'h', 'C', 'h', 'e', 's', 't', '0', '1', '\"', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '0', '.', '6', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i220;
  static real_T c4_dv49[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 99.0,
    114.0, 97.0, 116.0, 99.0, 104.0, 67.0, 104.0, 101.0, 115.0, 116.0, 48.0,
    49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i221;
  int32_T c4_i222;
  int32_T c4_i223;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_lb_debug_family_names,
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
  for (c4_i219 = 0; c4_i219 < 105; c4_i219++) {
    c4_mystr[c4_i219] = c4_cv35[c4_i219];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i220 = 0; c4_i220 < 105; c4_i220++) {
    c4_arr[c4_i220] = c4_dv49[c4_i220];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i221 = 0; c4_i221 < 1000; c4_i221++) {
    c4_tt[c4_i221] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i222 = 0; c4_i222 < 105; c4_i222++) {
    c4_tt[c4_i222] = c4_arr[c4_i222];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i223 = 0; c4_i223 < 1000; c4_i223++) {
    c4_myarr256[c4_i223] = c4_tt[c4_i223];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_kb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[105];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[105];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i224;
  static char_T c4_cv36[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'q', 'u', 'e', 'e',
    'z', 'e', 'H', 'a', 'n', 'd', '0', '1', '\"', ' ', ' ', 's', 'p', 'e', 'e',
    'd', '=', '\"', '0', '.', '6', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i225;
  static real_T c4_dv50[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 113.0,
    117.0, 101.0, 101.0, 122.0, 101.0, 72.0, 97.0, 110.0, 100.0, 48.0, 49.0,
    34.0, 32.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 48.0, 46.0,
    54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i226;
  int32_T c4_i227;
  int32_T c4_i228;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_mb_debug_family_names,
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
  for (c4_i224 = 0; c4_i224 < 105; c4_i224++) {
    c4_mystr[c4_i224] = c4_cv36[c4_i224];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i225 = 0; c4_i225 < 105; c4_i225++) {
    c4_arr[c4_i225] = c4_dv50[c4_i225];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 105.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i226 = 0; c4_i226 < 1000; c4_i226++) {
    c4_tt[c4_i226] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i227 = 0; c4_i227 < 105; c4_i227++) {
    c4_tt[c4_i227] = c4_arr[c4_i227];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i228 = 0; c4_i228 < 1000; c4_i228++) {
    c4_myarr256[c4_i228] = c4_tt[c4_i228];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_lb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[118];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[118];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i229;
  static char_T c4_cv37[118] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a',
    't', 'a', '/', 'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't',
    '_', 'i', 'd', 'l', 'e', '_', 'b', 'r', 'u', 's', 'h', '_', 'c', 'e', 'n',
    't', 'e', 'r', '.', 's', 'k', 'm', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i230;
  static real_T c4_dv51[118] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0,
    116.0, 97.0, 47.0, 67.0, 104.0, 114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0,
    101.0, 115.0, 116.0, 95.0, 105.0, 100.0, 108.0, 101.0, 95.0, 98.0, 114.0,
    117.0, 115.0, 104.0, 95.0, 99.0, 101.0, 110.0, 116.0, 101.0, 114.0, 46.0,
    115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i231;
  int32_T c4_i232;
  int32_T c4_i233;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ob_debug_family_names,
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
  for (c4_i229 = 0; c4_i229 < 118; c4_i229++) {
    c4_mystr[c4_i229] = c4_cv37[c4_i229];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i230 = 0; c4_i230 < 118; c4_i230++) {
    c4_arr[c4_i230] = c4_dv51[c4_i230];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 118.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i231 = 0; c4_i231 < 1000; c4_i231++) {
    c4_tt[c4_i231] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i232 = 0; c4_i232 < 118; c4_i232++) {
    c4_tt[c4_i232] = c4_arr[c4_i232];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i233 = 0; c4_i233 < 1000; c4_i233++) {
    c4_myarr256[c4_i233] = c4_tt[c4_i233];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_mb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[322];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[322];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i234;
  static char_T c4_cv38[322] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '1', '0', '\"', ' ', 'd', 'i', 'r', 'e', 'c',
    't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H', 'T',
    '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n',
    'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', ' ', 'N', 'E', 'C', 'K', '\"', ' ',
    's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"',
    '2', '\"', ' ', 't', 'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e',
    'T', 'a', 'r', 'g', 'e', 't', '\"', '/', '>', '<', 'g', 'a', 'z', 'e', ' ',
    'a', 'n', 'g', 'l', 'e', '=', '\"', '2', '0', '\"', ' ', 'd', 'i', 'r', 'e',
    'c', 't', 'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', 'R', 'I', 'G', 'H',
    'T', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o', 'i', 'n', 't', '-', 'r', 'a',
    'n', 'g', 'e', '=', '\"', 'E', 'Y', 'E', 'S', '\"', ' ', 's', 'b', 'm', ':',
    't', 'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', '/', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i', 'o', 'n',
    ' ', 'n', 'a', 'm', 'e', '=', '\"', '.', '.', '/', 'd', 'a', 't', 'a', '/',
    'C', 'h', 'r', 'B', 'r', 'a', 'd', '/', 't', 'e', 's', 't', '_', 'i', 'd',
    'l', 'e', '_', 'h', 'a', 'n', 'd', '_', 'l', 'o', 'o', 'k', '.', 's', 'k',
    'm', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '1', '.', '5', '\"', '/',
    '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i235;
  static real_T c4_dv52[322] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 32.0, 78.0, 69.0, 67.0, 75.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0,
    34.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0,
    103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0,
    47.0, 62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0,
    116.0, 105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 82.0, 73.0,
    71.0, 72.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 106.0, 111.0, 105.0,
    110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0, 101.0, 61.0, 34.0, 69.0, 89.0,
    69.0, 83.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0,
    45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 97.0, 110.0, 105.0,
    109.0, 97.0, 116.0, 105.0, 111.0, 110.0, 32.0, 110.0, 97.0, 109.0, 101.0,
    61.0, 34.0, 46.0, 46.0, 47.0, 100.0, 97.0, 116.0, 97.0, 47.0, 67.0, 104.0,
    114.0, 66.0, 114.0, 97.0, 100.0, 47.0, 116.0, 101.0, 115.0, 116.0, 95.0,
    105.0, 100.0, 108.0, 101.0, 95.0, 104.0, 97.0, 110.0, 100.0, 95.0, 108.0,
    111.0, 111.0, 107.0, 46.0, 115.0, 107.0, 109.0, 34.0, 32.0, 115.0, 112.0,
    101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0,
    47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i236;
  int32_T c4_i237;
  int32_T c4_i238;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_pb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_eb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_db_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i234 = 0; c4_i234 < 322; c4_i234++) {
    c4_mystr[c4_i234] = c4_cv38[c4_i234];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i235 = 0; c4_i235 < 322; c4_i235++) {
    c4_arr[c4_i235] = c4_dv52[c4_i235];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 322.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i236 = 0; c4_i236 < 1000; c4_i236++) {
    c4_tt[c4_i236] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i237 = 0; c4_i237 < 322; c4_i237++) {
    c4_tt[c4_i237] = c4_arr[c4_i237];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i238 = 0; c4_i238 < 1000; c4_i238++) {
    c4_myarr256[c4_i238] = c4_tt[c4_i238];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_nb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[153];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[153];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i239;
  static char_T c4_cv39[153] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l',
    'e', '0', '3', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ',
    'r', 'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 's', 't', 'r', 'o', 'k',
    'e', '=', '\"', '2', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '_', 'e', 'n',
    'd', '=', '\"', '3', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '1', '8',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '0', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i240;
  static real_T c4_dv53[153] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 51.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0,
    34.0, 49.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0,
    50.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 95.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 51.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 49.0, 56.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 50.0,
    48.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0,
    97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i241;
  int32_T c4_i242;
  int32_T c4_i243;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_qb_debug_family_names,
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
  for (c4_i239 = 0; c4_i239 < 153; c4_i239++) {
    c4_mystr[c4_i239] = c4_cv39[c4_i239];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i240 = 0; c4_i240 < 153; c4_i240++) {
    c4_arr[c4_i240] = c4_dv53[c4_i240];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 153.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i241 = 0; c4_i241 < 1000; c4_i241++) {
    c4_tt[c4_i241] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i242 = 0; c4_i242 < 153; c4_i242++) {
    c4_tt[c4_i242] = c4_arr[c4_i242];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i243 = 0; c4_i243 < 1000; c4_i243++) {
    c4_myarr256[c4_i243] = c4_tt[c4_i243];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_ob_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[155];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[155];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i244;
  static char_T c4_cv40[155] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'h', 'i', 'n', 'k',
    '0', '1', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'r',
    'e', 'a', 'd', 'y', '=', '\"', '1', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '4', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '_', 'e', 'n', 'd',
    '=', '\"', '2', '0', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '2',
    '1', '\"', ' ', 'e', 'n', 'd', '=', '\"', '2', '2', '\"', ' ', '/', '>', '<',
    '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i245;
  static real_T c4_dv54[155] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 104.0,
    105.0, 110.0, 107.0, 48.0, 49.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0,
    116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 114.0, 101.0, 97.0, 100.0, 121.0, 61.0,
    34.0, 49.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0,
    52.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 95.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 50.0, 48.0, 34.0, 32.0, 32.0, 114.0, 101.0, 108.0,
    97.0, 120.0, 61.0, 34.0, 50.0, 49.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0,
    34.0, 50.0, 50.0, 34.0, 32.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i246;
  int32_T c4_i247;
  int32_T c4_i248;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_rb_debug_family_names,
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
  for (c4_i244 = 0; c4_i244 < 155; c4_i244++) {
    c4_mystr[c4_i244] = c4_cv40[c4_i244];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i245 = 0; c4_i245 < 155; c4_i245++) {
    c4_arr[c4_i245] = c4_dv54[c4_i245];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 155.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i246 = 0; c4_i246 < 1000; c4_i246++) {
    c4_tt[c4_i246] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i247 = 0; c4_i247 < 155; c4_i247++) {
    c4_tt[c4_i247] = c4_arr[c4_i247];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i248 = 0; c4_i248 < 1000; c4_i248++) {
    c4_myarr256[c4_i248] = c4_tt[c4_i248];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_pb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[97];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[97];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i249;
  static char_T c4_cv41[97] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '1', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i250;
  static real_T c4_dv55[97] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 115.0, 112.0, 101.0,
    101.0, 100.0, 61.0, 34.0, 49.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i251;
  int32_T c4_i252;
  int32_T c4_i253;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_sb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_kb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_jb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i249 = 0; c4_i249 < 97; c4_i249++) {
    c4_mystr[c4_i249] = c4_cv41[c4_i249];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i250 = 0; c4_i250 < 97; c4_i250++) {
    c4_arr[c4_i250] = c4_dv55[c4_i250];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 97.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i251 = 0; c4_i251 < 1000; c4_i251++) {
    c4_tt[c4_i251] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i252 = 0; c4_i252 < 97; c4_i252++) {
    c4_tt[c4_i252] = c4_arr[c4_i252];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i253 = 0; c4_i253 < 1000; c4_i253++) {
    c4_myarr256[c4_i253] = c4_tt[c4_i253];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_qb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i254;
  static char_T c4_cv42[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '1', '.', '2', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i255;
  static real_T c4_dv56[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 49.0, 46.0, 50.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i256;
  int32_T c4_i257;
  int32_T c4_i258;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_tb_debug_family_names,
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
  for (c4_i254 = 0; c4_i254 < 108; c4_i254++) {
    c4_mystr[c4_i254] = c4_cv42[c4_i254];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i255 = 0; c4_i255 < 108; c4_i255++) {
    c4_arr[c4_i255] = c4_dv56[c4_i255];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i256 = 0; c4_i256 < 1000; c4_i256++) {
    c4_tt[c4_i256] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i257 = 0; c4_i257 < 108; c4_i257++) {
    c4_tt[c4_i257] = c4_arr[c4_i257];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i258 = 0; c4_i258 < 1000; c4_i258++) {
    c4_myarr256[c4_i258] = c4_tt[c4_i258];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_rb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[99];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[99];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i259;
  static char_T c4_cv43[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '1', '.', '5', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i260;
  static real_T c4_dv57[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 115.0, 112.0, 101.0,
    101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i261;
  int32_T c4_i262;
  int32_T c4_i263;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ub_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i259 = 0; c4_i259 < 99; c4_i259++) {
    c4_mystr[c4_i259] = c4_cv43[c4_i259];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i260 = 0; c4_i260 < 99; c4_i260++) {
    c4_arr[c4_i260] = c4_dv57[c4_i260];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 99.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i261 = 0; c4_i261 < 1000; c4_i261++) {
    c4_tt[c4_i261] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i262 = 0; c4_i262 < 99; c4_i262++) {
    c4_tt[c4_i262] = c4_arr[c4_i262];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i263 = 0; c4_i263 < 1000; c4_i263++) {
    c4_myarr256[c4_i263] = c4_tt[c4_i263];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_sb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[103];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[103];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i264;
  static char_T c4_cv44[103] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'A', 'r', 'm', 'S', 't',
    'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=',
    '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/',
    'a', 'c', 't', '>' };

  int32_T c4_i265;
  static real_T c4_dv58[103] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 65.0, 114.0,
    109.0, 83.0, 116.0, 114.0, 101.0, 116.0, 99.0, 104.0, 48.0, 49.0, 34.0, 32.0,
    115.0, 112.0, 101.0, 101.0, 100.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0,
    62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0,
    62.0 };

  int32_T c4_i266;
  int32_T c4_i267;
  int32_T c4_i268;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_vb_debug_family_names,
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
  for (c4_i264 = 0; c4_i264 < 103; c4_i264++) {
    c4_mystr[c4_i264] = c4_cv44[c4_i264];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i265 = 0; c4_i265 < 103; c4_i265++) {
    c4_arr[c4_i265] = c4_dv58[c4_i265];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 103.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i266 = 0; c4_i266 < 1000; c4_i266++) {
    c4_tt[c4_i266] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i267 = 0; c4_i267 < 103; c4_i267++) {
    c4_tt[c4_i267] = c4_arr[c4_i267];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i268 = 0; c4_i268 < 1000; c4_i268++) {
    c4_myarr256[c4_i268] = c4_tt[c4_i268];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_tb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[99];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[99];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i269;
  static char_T c4_cv45[99] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't', 'i',
    'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r', 'a',
    'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'T', 'o', 'I', 'd', 'l', 'e',
    '0', '2', '\"', ' ', 's', 'p', 'e', 'e', 'd', '=', '\"', '0', '.', '6', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i270;
  static real_T c4_dv59[99] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 84.0, 111.0,
    73.0, 100.0, 108.0, 101.0, 48.0, 50.0, 34.0, 32.0, 115.0, 112.0, 101.0,
    101.0, 100.0, 61.0, 34.0, 48.0, 46.0, 54.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i271;
  int32_T c4_i272;
  int32_T c4_i273;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_wb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_mb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_lb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i269 = 0; c4_i269 < 99; c4_i269++) {
    c4_mystr[c4_i269] = c4_cv45[c4_i269];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i270 = 0; c4_i270 < 99; c4_i270++) {
    c4_arr[c4_i270] = c4_dv59[c4_i270];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 99.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i271 = 0; c4_i271 < 1000; c4_i271++) {
    c4_tt[c4_i271] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i272 = 0; c4_i272 < 99; c4_i272++) {
    c4_tt[c4_i272] = c4_arr[c4_i272];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i273 = 0; c4_i273 < 1000; c4_i273++) {
    c4_myarr256[c4_i273] = c4_tt[c4_i273];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_ub_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[108];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[108];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i274;
  static char_T c4_cv46[108] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'a', 'n', 'i', 'm', 'a', 't',
    'i', 'o', 'n', ' ', 'n', 'a', 'm', 'e', '=', '\"', 'C', 'h', 'r', 'B', 'r',
    'a', 'd', '@', 'I', 'd', 'l', 'e', '0', '1', '_', 'S', 'h', 'o', 'u', 'l',
    'd', 'e', 'r', 'S', 't', 'r', 'e', 't', 'c', 'h', '0', '1', '\"', ' ', 's',
    'p', 'e', 'e', 'd', '=', '\"', '0', '.', '6', '\"', '/', '>', '<', '/', 'b',
    'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i275;
  static real_T c4_dv60[108] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 97.0, 110.0, 105.0, 109.0, 97.0, 116.0, 105.0, 111.0, 110.0,
    32.0, 110.0, 97.0, 109.0, 101.0, 61.0, 34.0, 67.0, 104.0, 114.0, 66.0, 114.0,
    97.0, 100.0, 64.0, 73.0, 100.0, 108.0, 101.0, 48.0, 49.0, 95.0, 83.0, 104.0,
    111.0, 117.0, 108.0, 100.0, 101.0, 114.0, 83.0, 116.0, 114.0, 101.0, 116.0,
    99.0, 104.0, 48.0, 49.0, 34.0, 32.0, 115.0, 112.0, 101.0, 101.0, 100.0, 61.0,
    34.0, 48.0, 46.0, 54.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i276;
  int32_T c4_i277;
  int32_T c4_i278;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_xb_debug_family_names,
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
  for (c4_i274 = 0; c4_i274 < 108; c4_i274++) {
    c4_mystr[c4_i274] = c4_cv46[c4_i274];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i275 = 0; c4_i275 < 108; c4_i275++) {
    c4_arr[c4_i275] = c4_dv60[c4_i275];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 108.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i276 = 0; c4_i276 < 1000; c4_i276++) {
    c4_tt[c4_i276] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i277 = 0; c4_i277 < 108; c4_i277++) {
    c4_tt[c4_i277] = c4_arr[c4_i277];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i278 = 0; c4_i278 < 1000; c4_i278++) {
    c4_myarr256[c4_i278] = c4_tt[c4_i278];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_vb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[143];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[143];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i279;
  static char_T c4_cv47[143] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'U', 'P', '\"', ' ', 's', 'b', 'm', ':', 'j', 'o',
    'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E', 'A', 'D',
    ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm',
    'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't', 'a', 'r', 'g',
    'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e', 't', '\"',
    '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c4_i280;
  static real_T c4_dv61[143] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 85.0, 80.0, 34.0, 32.0, 115.0, 98.0, 109.0,
    58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0, 110.0, 103.0,
    101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 67.0, 72.0, 69.0, 83.0,
    84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0,
    104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0,
    114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i281;
  int32_T c4_i282;
  int32_T c4_i283;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_yb_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_ob_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_nb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i279 = 0; c4_i279 < 143; c4_i279++) {
    c4_mystr[c4_i279] = c4_cv47[c4_i279];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i280 = 0; c4_i280 < 143; c4_i280++) {
    c4_arr[c4_i280] = c4_dv61[c4_i280];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 143.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i281 = 0; c4_i281 < 1000; c4_i281++) {
    c4_tt[c4_i281] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i282 = 0; c4_i282 < 143; c4_i282++) {
    c4_tt[c4_i282] = c4_arr[c4_i282];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i283 = 0; c4_i283 < 1000; c4_i283++) {
    c4_myarr256[c4_i283] = c4_tt[c4_i283];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_wb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr[145];
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr[145];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i284;
  static char_T c4_cv48[145] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 'a',
    'n', 'g', 'l', 'e', '=', '\"', '3', '\"', ' ', 'd', 'i', 'r', 'e', 'c', 't',
    'i', 'o', 'n', '=', '\"', 'D', 'O', 'W', 'N', '\"', ' ', 's', 'b', 'm', ':',
    'j', 'o', 'i', 'n', 't', '-', 'r', 'a', 'n', 'g', 'e', '=', '\"', 'H', 'E',
    'A', 'D', ' ', 'C', 'H', 'E', 'S', 'T', '\"', ' ', 's', 'b', 'm', ':', 't',
    'i', 'm', 'e', '-', 'h', 'i', 'n', 't', '=', '\"', '2', '\"', ' ', 't', 'a',
    'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g', 'e',
    't', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't',
    '>' };

  int32_T c4_i285;
  static real_T c4_dv62[145] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 97.0, 110.0, 103.0, 108.0,
    101.0, 61.0, 34.0, 51.0, 34.0, 32.0, 100.0, 105.0, 114.0, 101.0, 99.0, 116.0,
    105.0, 111.0, 110.0, 61.0, 34.0, 68.0, 79.0, 87.0, 78.0, 34.0, 32.0, 115.0,
    98.0, 109.0, 58.0, 106.0, 111.0, 105.0, 110.0, 116.0, 45.0, 114.0, 97.0,
    110.0, 103.0, 101.0, 61.0, 34.0, 72.0, 69.0, 65.0, 68.0, 32.0, 67.0, 72.0,
    69.0, 83.0, 84.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0,
    101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 50.0, 34.0, 32.0, 116.0,
    97.0, 114.0, 103.0, 101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0,
    84.0, 97.0, 114.0, 103.0, 101.0, 116.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0,
    109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c4_i286;
  int32_T c4_i287;
  int32_T c4_i288;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ac_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_arr, 1U, c4_qb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_mystr, 5U, c4_pb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  for (c4_i284 = 0; c4_i284 < 145; c4_i284++) {
    c4_mystr[c4_i284] = c4_cv48[c4_i284];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i285 = 0; c4_i285 < 145; c4_i285++) {
    c4_arr[c4_i285] = c4_dv62[c4_i285];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 145.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i286 = 0; c4_i286 < 1000; c4_i286++) {
    c4_tt[c4_i286] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  for (c4_i287 = 0; c4_i287 < 145; c4_i287++) {
    c4_tt[c4_i287] = c4_arr[c4_i287];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i288 = 0; c4_i288 < 1000; c4_i288++) {
    c4_myarr256[c4_i288] = c4_tt[c4_i288];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_xb_encStr2Arr(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_myarr256[1000])
{
  uint32_T c4_debug_family_var_map[9];
  real_T c4_maxarrsize;
  real_T c4_arr;
  real_T c4_ss;
  real_T c4_padsize;
  real_T c4_tt[1000];
  char_T c4_mystr;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i289;
  int32_T c4_i290;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_ec_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_maxarrsize, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_arr, 1U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ss, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_padsize, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_tt, 4U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_mystr, 5U, c4_sb_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myarr256, 8U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  c4_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_padsize = c4_maxarrsize - c4_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i289 = 0; c4_i289 < 1000; c4_i289++) {
    c4_tt[c4_i289] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_tt[0] = c4_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, 11);
  for (c4_i290 = 0; c4_i290 < 1000; c4_i290++) {
    c4_myarr256[c4_i290] = c4_tt[c4_i290];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c4_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_rand(SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  return c4_eml_rand(chartInstance);
}

static real_T c4_eml_rand(SFc4_Expriment_EmotionInstanceStruct *chartInstance)
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
  int32_T c4_i291;
  uint32_T c4_icng;
  uint32_T c4_jsr;
  uint32_T c4_u1;
  uint32_T c4_u2;
  uint32_T c4_ui;
  uint32_T c4_b_ui;
  real_T c4_c_r;
  real_T c4_d1;
  uint32_T c4_uv2[625];
  int32_T c4_i292;
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
      for (c4_i291 = 0; c4_i291 < 2; c4_i291++) {
        chartInstance->c4_b_state[c4_i291] = 362436069U + 158852560U * (uint32_T)
          c4_i291;
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
      for (c4_i292 = 0; c4_i292 < 625; c4_i292++) {
        chartInstance->c4_c_state[c4_i292] = c4_uv2[c4_i292];
      }

      chartInstance->c4_c_state_not_empty = true;
    }

    c4_d2 = c4_c_eml_rand_mt19937ar(chartInstance, chartInstance->c4_c_state);
    c4_r = c4_d2;
  }

  return c4_r;
}

static void c4_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625])
{
  real_T c4_d3;
  int32_T c4_i293;
  c4_d3 = 5489.0;
  for (c4_i293 = 0; c4_i293 < 625; c4_i293++) {
    c4_d_state[c4_i293] = 0U;
  }

  c4_b_twister_state_vector(chartInstance, c4_d_state, c4_d3);
}

static void c4_twister_state_vector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed, uint32_T c4_b_mt[625])
{
  int32_T c4_i294;
  for (c4_i294 = 0; c4_i294 < 625; c4_i294++) {
    c4_b_mt[c4_i294] = c4_mt[c4_i294];
  }

  c4_b_twister_state_vector(chartInstance, c4_b_mt, c4_seed);
}

static void c4_b_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625], uint32_T c4_e_state[625], real_T
  *c4_r)
{
  int32_T c4_i295;
  for (c4_i295 = 0; c4_i295 < 625; c4_i295++) {
    c4_e_state[c4_i295] = c4_d_state[c4_i295];
  }

  *c4_r = c4_c_eml_rand_mt19937ar(chartInstance, c4_e_state);
}

static void c4_eml_error(SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  int32_T c4_i296;
  static char_T c4_cv49[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c4_u[37];
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  for (c4_i296 = 0; c4_i296 < 37; c4_i296++) {
    c4_u[c4_i296] = c4_cv49[c4_i296];
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
    "C:\\Users\\root180\\Documents\\affective-project\\28-12-2015-Matlab\\encStr2Arr.m"));
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i297;
  real_T c4_b_inData[1000];
  int32_T c4_i298;
  real_T c4_u[1000];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i297 = 0; c4_i297 < 1000; c4_i297++) {
    c4_b_inData[c4_i297] = (*(real_T (*)[1000])c4_inData)[c4_i297];
  }

  for (c4_i298 = 0; c4_i298 < 1000; c4_i298++) {
    c4_u[c4_i298] = c4_b_inData[c4_i298];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_poseBML, const char_T *c4_identifier, real_T
  c4_y[1000])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
}

static void c4_b_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[1000])
{
  real_T c4_dv63[1000];
  int32_T c4_i299;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv63, 1, 0, 0U, 1, 0U, 2, 1000,
                1);
  for (c4_i299 = 0; c4_i299 < 1000; c4_i299++) {
    c4_y[c4_i299] = c4_dv63[c4_i299];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_poseBML;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[1000];
  int32_T c4_i300;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_poseBML = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_poseBML), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_poseBML);
  for (c4_i300 = 0; c4_i300 < 1000; c4_i300++) {
    (*(real_T (*)[1000])c4_outData)[c4_i300] = c4_y[c4_i300];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_pr, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_pr), &c4_thisId);
  sf_mex_destroy(&c4_pr);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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
  const mxArray *c4_pr;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_pr = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_pr), &c4_thisId);
  sf_mex_destroy(&c4_pr);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_e_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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
  const mxArray *c4_aVarTruthTableCondition_20;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_aVarTruthTableCondition_20 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_aVarTruthTableCondition_20), &c4_thisId);
  sf_mex_destroy(&c4_aVarTruthTableCondition_20);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i301;
  real_T c4_b_inData[1000];
  int32_T c4_i302;
  real_T c4_u[1000];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i301 = 0; c4_i301 < 1000; c4_i301++) {
    c4_b_inData[c4_i301] = (*(real_T (*)[1000])c4_inData)[c4_i301];
  }

  for (c4_i302 = 0; c4_i302 < 1000; c4_i302++) {
    c4_u[c4_i302] = c4_b_inData[c4_i302];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_f_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_myarr256, const char_T *c4_identifier,
  real_T c4_y[1000])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
}

static void c4_g_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[1000])
{
  real_T c4_dv64[1000];
  int32_T c4_i303;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv64, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c4_i303 = 0; c4_i303 < 1000; c4_i303++) {
    c4_y[c4_i303] = c4_dv64[c4_i303];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_myarr256;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[1000];
  int32_T c4_i304;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_myarr256 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_myarr256), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_myarr256);
  for (c4_i304 = 0; c4_i304 < 1000; c4_i304++) {
    (*(real_T (*)[1000])c4_outData)[c4_i304] = c4_y[c4_i304];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i305;
  char_T c4_b_inData[103];
  int32_T c4_i306;
  char_T c4_u[103];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i305 = 0; c4_i305 < 103; c4_i305++) {
    c4_b_inData[c4_i305] = (*(char_T (*)[103])c4_inData)[c4_i305];
  }

  for (c4_i306 = 0; c4_i306 < 103; c4_i306++) {
    c4_u[c4_i306] = c4_b_inData[c4_i306];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i307;
  real_T c4_b_inData[103];
  int32_T c4_i308;
  real_T c4_u[103];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i307 = 0; c4_i307 < 103; c4_i307++) {
    c4_b_inData[c4_i307] = (*(real_T (*)[103])c4_inData)[c4_i307];
  }

  for (c4_i308 = 0; c4_i308 < 103; c4_i308++) {
    c4_u[c4_i308] = c4_b_inData[c4_i308];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i309;
  char_T c4_b_inData[102];
  int32_T c4_i310;
  char_T c4_u[102];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i309 = 0; c4_i309 < 102; c4_i309++) {
    c4_b_inData[c4_i309] = (*(char_T (*)[102])c4_inData)[c4_i309];
  }

  for (c4_i310 = 0; c4_i310 < 102; c4_i310++) {
    c4_u[c4_i310] = c4_b_inData[c4_i310];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 102),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i311;
  real_T c4_b_inData[102];
  int32_T c4_i312;
  real_T c4_u[102];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i311 = 0; c4_i311 < 102; c4_i311++) {
    c4_b_inData[c4_i311] = (*(real_T (*)[102])c4_inData)[c4_i311];
  }

  for (c4_i312 = 0; c4_i312 < 102; c4_i312++) {
    c4_u[c4_i312] = c4_b_inData[c4_i312];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 102), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_i_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i313;
  char_T c4_b_inData[106];
  int32_T c4_i314;
  char_T c4_u[106];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i313 = 0; c4_i313 < 106; c4_i313++) {
    c4_b_inData[c4_i313] = (*(char_T (*)[106])c4_inData)[c4_i313];
  }

  for (c4_i314 = 0; c4_i314 < 106; c4_i314++) {
    c4_u[c4_i314] = c4_b_inData[c4_i314];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 106),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_j_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i315;
  real_T c4_b_inData[106];
  int32_T c4_i316;
  real_T c4_u[106];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i315 = 0; c4_i315 < 106; c4_i315++) {
    c4_b_inData[c4_i315] = (*(real_T (*)[106])c4_inData)[c4_i315];
  }

  for (c4_i316 = 0; c4_i316 < 106; c4_i316++) {
    c4_u[c4_i316] = c4_b_inData[c4_i316];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 106), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_k_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i317;
  char_T c4_b_inData[104];
  int32_T c4_i318;
  char_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i317 = 0; c4_i317 < 104; c4_i317++) {
    c4_b_inData[c4_i317] = (*(char_T (*)[104])c4_inData)[c4_i317];
  }

  for (c4_i318 = 0; c4_i318 < 104; c4_i318++) {
    c4_u[c4_i318] = c4_b_inData[c4_i318];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_l_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i319;
  real_T c4_b_inData[104];
  int32_T c4_i320;
  real_T c4_u[104];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i319 = 0; c4_i319 < 104; c4_i319++) {
    c4_b_inData[c4_i319] = (*(real_T (*)[104])c4_inData)[c4_i319];
  }

  for (c4_i320 = 0; c4_i320 < 104; c4_i320++) {
    c4_u[c4_i320] = c4_b_inData[c4_i320];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_m_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i321;
  char_T c4_b_inData[321];
  int32_T c4_i322;
  char_T c4_u[321];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i321 = 0; c4_i321 < 321; c4_i321++) {
    c4_b_inData[c4_i321] = (*(char_T (*)[321])c4_inData)[c4_i321];
  }

  for (c4_i322 = 0; c4_i322 < 321; c4_i322++) {
    c4_u[c4_i322] = c4_b_inData[c4_i322];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 321),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_n_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i323;
  real_T c4_b_inData[321];
  int32_T c4_i324;
  real_T c4_u[321];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i323 = 0; c4_i323 < 321; c4_i323++) {
    c4_b_inData[c4_i323] = (*(real_T (*)[321])c4_inData)[c4_i323];
  }

  for (c4_i324 = 0; c4_i324 < 321; c4_i324++) {
    c4_u[c4_i324] = c4_b_inData[c4_i324];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 321), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_o_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i325;
  char_T c4_b_inData[320];
  int32_T c4_i326;
  char_T c4_u[320];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i325 = 0; c4_i325 < 320; c4_i325++) {
    c4_b_inData[c4_i325] = (*(char_T (*)[320])c4_inData)[c4_i325];
  }

  for (c4_i326 = 0; c4_i326 < 320; c4_i326++) {
    c4_u[c4_i326] = c4_b_inData[c4_i326];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 320),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_p_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i327;
  real_T c4_b_inData[320];
  int32_T c4_i328;
  real_T c4_u[320];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i327 = 0; c4_i327 < 320; c4_i327++) {
    c4_b_inData[c4_i327] = (*(real_T (*)[320])c4_inData)[c4_i327];
  }

  for (c4_i328 = 0; c4_i328 < 320; c4_i328++) {
    c4_u[c4_i328] = c4_b_inData[c4_i328];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 320), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_q_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i329;
  char_T c4_b_inData[107];
  int32_T c4_i330;
  char_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i329 = 0; c4_i329 < 107; c4_i329++) {
    c4_b_inData[c4_i329] = (*(char_T (*)[107])c4_inData)[c4_i329];
  }

  for (c4_i330 = 0; c4_i330 < 107; c4_i330++) {
    c4_u[c4_i330] = c4_b_inData[c4_i330];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 107),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_r_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i331;
  real_T c4_b_inData[107];
  int32_T c4_i332;
  real_T c4_u[107];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i331 = 0; c4_i331 < 107; c4_i331++) {
    c4_b_inData[c4_i331] = (*(real_T (*)[107])c4_inData)[c4_i331];
  }

  for (c4_i332 = 0; c4_i332 < 107; c4_i332++) {
    c4_u[c4_i332] = c4_b_inData[c4_i332];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 107), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_s_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i333;
  char_T c4_b_inData[105];
  int32_T c4_i334;
  char_T c4_u[105];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i333 = 0; c4_i333 < 105; c4_i333++) {
    c4_b_inData[c4_i333] = (*(char_T (*)[105])c4_inData)[c4_i333];
  }

  for (c4_i334 = 0; c4_i334 < 105; c4_i334++) {
    c4_u[c4_i334] = c4_b_inData[c4_i334];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_t_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i335;
  real_T c4_b_inData[105];
  int32_T c4_i336;
  real_T c4_u[105];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i335 = 0; c4_i335 < 105; c4_i335++) {
    c4_b_inData[c4_i335] = (*(real_T (*)[105])c4_inData)[c4_i335];
  }

  for (c4_i336 = 0; c4_i336 < 105; c4_i336++) {
    c4_u[c4_i336] = c4_b_inData[c4_i336];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_u_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i337;
  char_T c4_b_inData[314];
  int32_T c4_i338;
  char_T c4_u[314];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i337 = 0; c4_i337 < 314; c4_i337++) {
    c4_b_inData[c4_i337] = (*(char_T (*)[314])c4_inData)[c4_i337];
  }

  for (c4_i338 = 0; c4_i338 < 314; c4_i338++) {
    c4_u[c4_i338] = c4_b_inData[c4_i338];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 314),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_v_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i339;
  real_T c4_b_inData[314];
  int32_T c4_i340;
  real_T c4_u[314];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i339 = 0; c4_i339 < 314; c4_i339++) {
    c4_b_inData[c4_i339] = (*(real_T (*)[314])c4_inData)[c4_i339];
  }

  for (c4_i340 = 0; c4_i340 < 314; c4_i340++) {
    c4_u[c4_i340] = c4_b_inData[c4_i340];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 314), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_w_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i341;
  char_T c4_b_inData[109];
  int32_T c4_i342;
  char_T c4_u[109];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i341 = 0; c4_i341 < 109; c4_i341++) {
    c4_b_inData[c4_i341] = (*(char_T (*)[109])c4_inData)[c4_i341];
  }

  for (c4_i342 = 0; c4_i342 < 109; c4_i342++) {
    c4_u[c4_i342] = c4_b_inData[c4_i342];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_x_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i343;
  real_T c4_b_inData[109];
  int32_T c4_i344;
  real_T c4_u[109];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i343 = 0; c4_i343 < 109; c4_i343++) {
    c4_b_inData[c4_i343] = (*(real_T (*)[109])c4_inData)[c4_i343];
  }

  for (c4_i344 = 0; c4_i344 < 109; c4_i344++) {
    c4_u[c4_i344] = c4_b_inData[c4_i344];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_y_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i345;
  char_T c4_b_inData[108];
  int32_T c4_i346;
  char_T c4_u[108];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i345 = 0; c4_i345 < 108; c4_i345++) {
    c4_b_inData[c4_i345] = (*(char_T (*)[108])c4_inData)[c4_i345];
  }

  for (c4_i346 = 0; c4_i346 < 108; c4_i346++) {
    c4_u[c4_i346] = c4_b_inData[c4_i346];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 108),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i347;
  real_T c4_b_inData[108];
  int32_T c4_i348;
  real_T c4_u[108];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i347 = 0; c4_i347 < 108; c4_i347++) {
    c4_b_inData[c4_i347] = (*(real_T (*)[108])c4_inData)[c4_i347];
  }

  for (c4_i348 = 0; c4_i348 < 108; c4_i348++) {
    c4_u[c4_i348] = c4_b_inData[c4_i348];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 108), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i349;
  char_T c4_b_inData[118];
  int32_T c4_i350;
  char_T c4_u[118];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i349 = 0; c4_i349 < 118; c4_i349++) {
    c4_b_inData[c4_i349] = (*(char_T (*)[118])c4_inData)[c4_i349];
  }

  for (c4_i350 = 0; c4_i350 < 118; c4_i350++) {
    c4_u[c4_i350] = c4_b_inData[c4_i350];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i351;
  real_T c4_b_inData[118];
  int32_T c4_i352;
  real_T c4_u[118];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i351 = 0; c4_i351 < 118; c4_i351++) {
    c4_b_inData[c4_i351] = (*(real_T (*)[118])c4_inData)[c4_i351];
  }

  for (c4_i352 = 0; c4_i352 < 118; c4_i352++) {
    c4_u[c4_i352] = c4_b_inData[c4_i352];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_db_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i353;
  char_T c4_b_inData[322];
  int32_T c4_i354;
  char_T c4_u[322];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i353 = 0; c4_i353 < 322; c4_i353++) {
    c4_b_inData[c4_i353] = (*(char_T (*)[322])c4_inData)[c4_i353];
  }

  for (c4_i354 = 0; c4_i354 < 322; c4_i354++) {
    c4_u[c4_i354] = c4_b_inData[c4_i354];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 322),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i355;
  real_T c4_b_inData[322];
  int32_T c4_i356;
  real_T c4_u[322];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i355 = 0; c4_i355 < 322; c4_i355++) {
    c4_b_inData[c4_i355] = (*(real_T (*)[322])c4_inData)[c4_i355];
  }

  for (c4_i356 = 0; c4_i356 < 322; c4_i356++) {
    c4_u[c4_i356] = c4_b_inData[c4_i356];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 322), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i357;
  char_T c4_b_inData[153];
  int32_T c4_i358;
  char_T c4_u[153];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i357 = 0; c4_i357 < 153; c4_i357++) {
    c4_b_inData[c4_i357] = (*(char_T (*)[153])c4_inData)[c4_i357];
  }

  for (c4_i358 = 0; c4_i358 < 153; c4_i358++) {
    c4_u[c4_i358] = c4_b_inData[c4_i358];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 153),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i359;
  real_T c4_b_inData[153];
  int32_T c4_i360;
  real_T c4_u[153];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i359 = 0; c4_i359 < 153; c4_i359++) {
    c4_b_inData[c4_i359] = (*(real_T (*)[153])c4_inData)[c4_i359];
  }

  for (c4_i360 = 0; c4_i360 < 153; c4_i360++) {
    c4_u[c4_i360] = c4_b_inData[c4_i360];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 153), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i361;
  char_T c4_b_inData[155];
  int32_T c4_i362;
  char_T c4_u[155];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i361 = 0; c4_i361 < 155; c4_i361++) {
    c4_b_inData[c4_i361] = (*(char_T (*)[155])c4_inData)[c4_i361];
  }

  for (c4_i362 = 0; c4_i362 < 155; c4_i362++) {
    c4_u[c4_i362] = c4_b_inData[c4_i362];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 155),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i363;
  real_T c4_b_inData[155];
  int32_T c4_i364;
  real_T c4_u[155];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i363 = 0; c4_i363 < 155; c4_i363++) {
    c4_b_inData[c4_i363] = (*(real_T (*)[155])c4_inData)[c4_i363];
  }

  for (c4_i364 = 0; c4_i364 < 155; c4_i364++) {
    c4_u[c4_i364] = c4_b_inData[c4_i364];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 155), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i365;
  char_T c4_b_inData[97];
  int32_T c4_i366;
  char_T c4_u[97];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i365 = 0; c4_i365 < 97; c4_i365++) {
    c4_b_inData[c4_i365] = (*(char_T (*)[97])c4_inData)[c4_i365];
  }

  for (c4_i366 = 0; c4_i366 < 97; c4_i366++) {
    c4_u[c4_i366] = c4_b_inData[c4_i366];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i367;
  real_T c4_b_inData[97];
  int32_T c4_i368;
  real_T c4_u[97];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i367 = 0; c4_i367 < 97; c4_i367++) {
    c4_b_inData[c4_i367] = (*(real_T (*)[97])c4_inData)[c4_i367];
  }

  for (c4_i368 = 0; c4_i368 < 97; c4_i368++) {
    c4_u[c4_i368] = c4_b_inData[c4_i368];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i369;
  char_T c4_b_inData[99];
  int32_T c4_i370;
  char_T c4_u[99];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i369 = 0; c4_i369 < 99; c4_i369++) {
    c4_b_inData[c4_i369] = (*(char_T (*)[99])c4_inData)[c4_i369];
  }

  for (c4_i370 = 0; c4_i370 < 99; c4_i370++) {
    c4_u[c4_i370] = c4_b_inData[c4_i370];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 99), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i371;
  real_T c4_b_inData[99];
  int32_T c4_i372;
  real_T c4_u[99];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i371 = 0; c4_i371 < 99; c4_i371++) {
    c4_b_inData[c4_i371] = (*(real_T (*)[99])c4_inData)[c4_i371];
  }

  for (c4_i372 = 0; c4_i372 < 99; c4_i372++) {
    c4_u[c4_i372] = c4_b_inData[c4_i372];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 99), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i373;
  char_T c4_b_inData[143];
  int32_T c4_i374;
  char_T c4_u[143];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i373 = 0; c4_i373 < 143; c4_i373++) {
    c4_b_inData[c4_i373] = (*(char_T (*)[143])c4_inData)[c4_i373];
  }

  for (c4_i374 = 0; c4_i374 < 143; c4_i374++) {
    c4_u[c4_i374] = c4_b_inData[c4_i374];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 143),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i375;
  real_T c4_b_inData[143];
  int32_T c4_i376;
  real_T c4_u[143];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i375 = 0; c4_i375 < 143; c4_i375++) {
    c4_b_inData[c4_i375] = (*(real_T (*)[143])c4_inData)[c4_i375];
  }

  for (c4_i376 = 0; c4_i376 < 143; c4_i376++) {
    c4_u[c4_i376] = c4_b_inData[c4_i376];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 143), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i377;
  char_T c4_b_inData[145];
  int32_T c4_i378;
  char_T c4_u[145];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i377 = 0; c4_i377 < 145; c4_i377++) {
    c4_b_inData[c4_i377] = (*(char_T (*)[145])c4_inData)[c4_i377];
  }

  for (c4_i378 = 0; c4_i378 < 145; c4_i378++) {
    c4_u[c4_i378] = c4_b_inData[c4_i378];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 145),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i379;
  real_T c4_b_inData[145];
  int32_T c4_i380;
  real_T c4_u[145];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i379 = 0; c4_i379 < 145; c4_i379++) {
    c4_b_inData[c4_i379] = (*(real_T (*)[145])c4_inData)[c4_i379];
  }

  for (c4_i380 = 0; c4_i380 < 145; c4_i380++) {
    c4_u[c4_i380] = c4_b_inData[c4_i380];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 145), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i381;
  int32_T c4_i382;
  int32_T c4_i383;
  real_T c4_b_inData[5000];
  int32_T c4_i384;
  int32_T c4_i385;
  int32_T c4_i386;
  real_T c4_u[5000];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i381 = 0;
  for (c4_i382 = 0; c4_i382 < 5; c4_i382++) {
    for (c4_i383 = 0; c4_i383 < 1000; c4_i383++) {
      c4_b_inData[c4_i383 + c4_i381] = (*(real_T (*)[5000])c4_inData)[c4_i383 +
        c4_i381];
    }

    c4_i381 += 1000;
  }

  c4_i384 = 0;
  for (c4_i385 = 0; c4_i385 < 5; c4_i385++) {
    for (c4_i386 = 0; c4_i386 < 1000; c4_i386++) {
      c4_u[c4_i386 + c4_i384] = c4_b_inData[c4_i386 + c4_i384];
    }

    c4_i384 += 1000;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_h_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_newBmls, const char_T *c4_identifier, real_T
  c4_y[5000])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_newBmls), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_newBmls);
}

static void c4_i_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5000])
{
  real_T c4_dv65[5000];
  int32_T c4_i387;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv65, 1, 0, 0U, 1, 0U, 2, 1000,
                5);
  for (c4_i387 = 0; c4_i387 < 5000; c4_i387++) {
    c4_y[c4_i387] = c4_dv65[c4_i387];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_newBmls;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[5000];
  int32_T c4_i388;
  int32_T c4_i389;
  int32_T c4_i390;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_newBmls = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_newBmls), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_newBmls);
  c4_i388 = 0;
  for (c4_i389 = 0; c4_i389 < 5; c4_i389++) {
    for (c4_i390 = 0; c4_i390 < 1000; c4_i390++) {
      (*(real_T (*)[5000])c4_outData)[c4_i390 + c4_i388] = c4_y[c4_i390 +
        c4_i388];
    }

    c4_i388 += 1000;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  char_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(char_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_Expriment_Emotion_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 42, 1),
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
  const mxArray *c4_rhs39 = NULL;
  const mxArray *c4_lhs39 = NULL;
  const mxArray *c4_rhs40 = NULL;
  const mxArray *c4_lhs40 = NULL;
  const mxArray *c4_rhs41 = NULL;
  const mxArray *c4_lhs41 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/28-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("round"), "name", "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1307683638U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("randi"), "name", "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215430U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rand"), "name", "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1383909690U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_is_rand_extrinsic"),
                  "name", "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215432U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand"), "name", "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_str2id"), "name",
                  "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380222U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807_stateful"),
                  "name", "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mcg16807"), "name",
                  "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong_stateful"),
                  "name", "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_shr3cong"), "name",
                  "name", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1313380220U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar_stateful"),
                  "name", "name", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1366194644U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_rand_mt19937ar"), "name",
                  "name", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1368215434U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eps"), "name", "name", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_eps"), "name", "name", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("isequal"), "name", "name", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state"),
                  "context", "context", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu"),
                  "context", "context", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randi.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c4_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c4_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c4_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs41), "lhs", "lhs",
                  41);
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
  sf_mex_destroy(&c4_rhs39);
  sf_mex_destroy(&c4_lhs39);
  sf_mex_destroy(&c4_rhs40);
  sf_mex_destroy(&c4_lhs40);
  sf_mex_destroy(&c4_rhs41);
  sf_mex_destroy(&c4_lhs41);
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

static void c4_activate_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = c4_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_deactivate_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c4_event_secs,
               chartInstance->c4_sfEvent);
}

static void c4_increment_counters_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  if (chartInstance->c4_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c4_temporalCounter_i1++;
  }
}

static void c4_reset_counters_secsc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c4_Expriment_Emotion_secs(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_activate_secsc4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c4_Expriment_Emotion_secs
  (SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_increment_counters_secsc4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c4_Expriment_Emotion_secs(SimStruct
  *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_reset_counters_secsc4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_deactivate_c4_Expriment_Emotion_secs(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_deactivate_secsc4_Expriment_Emotion(chartInstance);
}

boolean_T sf_exported_auto_isStablec4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  return chartInstance->c4_isStable;
}

void sf_exported_auto_duringc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_c4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_enterc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_enter_atomic_c4_Expriment_Emotion(chartInstance);
  c4_enter_internal_c4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_exitc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c4_exit_internal_c4_Expriment_Emotion(chartInstance);
}

void sf_exported_auto_gatewayc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  chartInstance->c4_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc4_Expriment_Emotion(SimStruct *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_initc4_Expriment_Emotion(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec4_Expriment_Emotion(SimStruct *c4_S)
{
  const mxArray *c4_out = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_out = NULL;
  sf_mex_assign(&c4_out, sf_internal_get_sim_state_c4_Expriment_Emotion(c4_S),
                false);
  return c4_out;
}

void sf_exported_auto_setSimstatec4_Expriment_Emotion(SimStruct *c4_S, const
  mxArray *c4_in)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c4_Expriment_Emotion(c4_S, sf_mex_dup(c4_in));
  sf_mex_destroy(&c4_in);
}

void sf_exported_auto_check_state_inconsistency_c4_Expriment_Emotion(SimStruct
  *c4_S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_EmotionMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_selfAdaptorTableBillyc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000])
{
  uint32_T c4_debug_family_var_map[25];
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
  boolean_T c4_aVarTruthTableCondition_19;
  boolean_T c4_aVarTruthTableCondition_20;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_dv66[1000];
  int32_T c4_i391;
  int32_T c4_i392;
  int32_T c4_i393;
  int32_T c4_i394;
  int32_T c4_i395;
  int32_T c4_i396;
  int32_T c4_i397;
  int32_T c4_i398;
  int32_T c4_i399;
  int32_T c4_i400;
  int32_T c4_i401;
  int32_T c4_i402;
  int32_T c4_i403;
  int32_T c4_i404;
  int32_T c4_i405;
  int32_T c4_i406;
  int32_T c4_i407;
  int32_T c4_i408;
  int32_T c4_i409;
  int32_T c4_i410;
  int32_T c4_i411;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 25U, c4_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_19, 18U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_20, 19U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 20U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 21U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 22U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_pr, 23U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 24U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(16, 0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 20);
  c4_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 22);
  c4_aVarTruthTableCondition_20 = false;
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 26);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 29);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 32);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 35);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 38);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 41);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 44);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 47);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 50);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 53);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 56);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 59);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 62);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 65);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 68);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 71);
  c4_aVarTruthTableCondition_16 = (c4_bmlID == 16.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 74);
  c4_aVarTruthTableCondition_17 = (c4_bmlID == 17.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 77);
  c4_aVarTruthTableCondition_18 = (c4_bmlID == 18.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 80);
  c4_aVarTruthTableCondition_19 = (c4_bmlID == 19.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 83);
  c4_aVarTruthTableCondition_20 = (c4_bmlID == 20.0);
  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 85);
  if (CV_EML_IF(16, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 86);
    CV_EML_FCN(16, 1);
    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 133U);
    c4_encStr2Arr(chartInstance, c4_dv66);
    for (c4_i391 = 0; c4_i391 < 1000; c4_i391++) {
      c4_poseBML[c4_i391] = c4_dv66[c4_i391];
    }

    c4_updateDataWrittenToVector(chartInstance, 19U);
    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 133U);
    *c4_pr = 3.0;
    c4_updateDataWrittenToVector(chartInstance, 18U);
    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -133);
  } else {
    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 87);
    if (CV_EML_IF(16, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 88);
      CV_EML_FCN(16, 2);
      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 139U);
      c4_b_encStr2Arr(chartInstance, c4_dv66);
      for (c4_i392 = 0; c4_i392 < 1000; c4_i392++) {
        c4_poseBML[c4_i392] = c4_dv66[c4_i392];
      }

      c4_updateDataWrittenToVector(chartInstance, 19U);
      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 139U);
      *c4_pr = 3.0;
      c4_updateDataWrittenToVector(chartInstance, 18U);
      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -139);
    } else {
      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 89);
      if (CV_EML_IF(16, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 90);
        CV_EML_FCN(16, 3);
        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 145U);
        c4_c_encStr2Arr(chartInstance, c4_dv66);
        for (c4_i393 = 0; c4_i393 < 1000; c4_i393++) {
          c4_poseBML[c4_i393] = c4_dv66[c4_i393];
        }

        c4_updateDataWrittenToVector(chartInstance, 19U);
        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 145U);
        *c4_pr = 3.0;
        c4_updateDataWrittenToVector(chartInstance, 18U);
        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -145);
      } else {
        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 91);
        if (CV_EML_IF(16, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 92);
          CV_EML_FCN(16, 4);
          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 151U);
          c4_d_encStr2Arr(chartInstance, c4_dv66);
          for (c4_i394 = 0; c4_i394 < 1000; c4_i394++) {
            c4_poseBML[c4_i394] = c4_dv66[c4_i394];
          }

          c4_updateDataWrittenToVector(chartInstance, 19U);
          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 151U);
          *c4_pr = 3.0;
          c4_updateDataWrittenToVector(chartInstance, 18U);
          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -151);
        } else {
          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 93);
          if (CV_EML_IF(16, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 94);
            CV_EML_FCN(16, 5);
            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 157U);
            c4_e_encStr2Arr(chartInstance, c4_dv66);
            for (c4_i395 = 0; c4_i395 < 1000; c4_i395++) {
              c4_poseBML[c4_i395] = c4_dv66[c4_i395];
            }

            c4_updateDataWrittenToVector(chartInstance, 19U);
            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 157U);
            *c4_pr = 3.0;
            c4_updateDataWrittenToVector(chartInstance, 18U);
            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -157);
          } else {
            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 95);
            if (CV_EML_IF(16, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 96);
              CV_EML_FCN(16, 6);
              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 163U);
              c4_f_encStr2Arr(chartInstance, c4_dv66);
              for (c4_i396 = 0; c4_i396 < 1000; c4_i396++) {
                c4_poseBML[c4_i396] = c4_dv66[c4_i396];
              }

              c4_updateDataWrittenToVector(chartInstance, 19U);
              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 163U);
              *c4_pr = 3.0;
              c4_updateDataWrittenToVector(chartInstance, 18U);
              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -163);
            } else {
              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 97);
              if (CV_EML_IF(16, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 98);
                CV_EML_FCN(16, 7);
                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 169U);
                c4_g_encStr2Arr(chartInstance, c4_dv66);
                for (c4_i397 = 0; c4_i397 < 1000; c4_i397++) {
                  c4_poseBML[c4_i397] = c4_dv66[c4_i397];
                }

                c4_updateDataWrittenToVector(chartInstance, 19U);
                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 169U);
                *c4_pr = 3.0;
                c4_updateDataWrittenToVector(chartInstance, 18U);
                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -169);
              } else {
                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 99);
                if (CV_EML_IF(16, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 100);
                  CV_EML_FCN(16, 8);
                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 175U);
                  c4_h_encStr2Arr(chartInstance, c4_dv66);
                  for (c4_i398 = 0; c4_i398 < 1000; c4_i398++) {
                    c4_poseBML[c4_i398] = c4_dv66[c4_i398];
                  }

                  c4_updateDataWrittenToVector(chartInstance, 19U);
                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 175U);
                  *c4_pr = 3.0;
                  c4_updateDataWrittenToVector(chartInstance, 18U);
                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -175);
                } else {
                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 101);
                  if (CV_EML_IF(16, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 102);
                    CV_EML_FCN(16, 9);
                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 181U);
                    c4_i_encStr2Arr(chartInstance, c4_dv66);
                    for (c4_i399 = 0; c4_i399 < 1000; c4_i399++) {
                      c4_poseBML[c4_i399] = c4_dv66[c4_i399];
                    }

                    c4_updateDataWrittenToVector(chartInstance, 19U);
                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 181U);
                    *c4_pr = 3.0;
                    c4_updateDataWrittenToVector(chartInstance, 18U);
                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -181);
                  } else {
                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 103);
                    if (CV_EML_IF(16, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 104);
                      CV_EML_FCN(16, 10);
                      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 187U);
                      c4_j_encStr2Arr(chartInstance, c4_dv66);
                      for (c4_i400 = 0; c4_i400 < 1000; c4_i400++) {
                        c4_poseBML[c4_i400] = c4_dv66[c4_i400];
                      }

                      c4_updateDataWrittenToVector(chartInstance, 19U);
                      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 187U);
                      *c4_pr = 3.0;
                      c4_updateDataWrittenToVector(chartInstance, 18U);
                      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -187);
                    } else {
                      _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 105);
                      if (CV_EML_IF(16, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 106);
                        CV_EML_FCN(16, 11);
                        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 193U);
                        c4_k_encStr2Arr(chartInstance, c4_dv66);
                        for (c4_i401 = 0; c4_i401 < 1000; c4_i401++) {
                          c4_poseBML[c4_i401] = c4_dv66[c4_i401];
                        }

                        c4_updateDataWrittenToVector(chartInstance, 19U);
                        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 193U);
                        *c4_pr = 3.0;
                        c4_updateDataWrittenToVector(chartInstance, 18U);
                        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -193);
                      } else {
                        _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 107);
                        if (CV_EML_IF(16, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 108);
                          CV_EML_FCN(16, 12);
                          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 199U);
                          c4_l_encStr2Arr(chartInstance, c4_dv66);
                          for (c4_i402 = 0; c4_i402 < 1000; c4_i402++) {
                            c4_poseBML[c4_i402] = c4_dv66[c4_i402];
                          }

                          c4_updateDataWrittenToVector(chartInstance, 19U);
                          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 199U);
                          *c4_pr = 3.0;
                          c4_updateDataWrittenToVector(chartInstance, 18U);
                          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -199);
                        } else {
                          _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 109);
                          if (CV_EML_IF(16, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 110);
                            CV_EML_FCN(16, 13);
                            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 205U);
                            c4_m_encStr2Arr(chartInstance, c4_dv66);
                            for (c4_i403 = 0; c4_i403 < 1000; c4_i403++) {
                              c4_poseBML[c4_i403] = c4_dv66[c4_i403];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 19U);
                            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 205U);
                            *c4_pr = 3.0;
                            c4_updateDataWrittenToVector(chartInstance, 18U);
                            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -205);
                          } else {
                            _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 111);
                            if (CV_EML_IF(16, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 112);
                              CV_EML_FCN(16, 14);
                              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 211U);
                              c4_n_encStr2Arr(chartInstance, c4_dv66);
                              for (c4_i404 = 0; c4_i404 < 1000; c4_i404++) {
                                c4_poseBML[c4_i404] = c4_dv66[c4_i404];
                              }

                              c4_updateDataWrittenToVector(chartInstance, 19U);
                              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 211U);
                              *c4_pr = 3.0;
                              c4_updateDataWrittenToVector(chartInstance, 18U);
                              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -211);
                            } else {
                              _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, 113);
                              if (CV_EML_IF(16, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                              114);
                                CV_EML_FCN(16, 15);
                                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                              217U);
                                c4_o_encStr2Arr(chartInstance, c4_dv66);
                                for (c4_i405 = 0; c4_i405 < 1000; c4_i405++) {
                                  c4_poseBML[c4_i405] = c4_dv66[c4_i405];
                                }

                                c4_updateDataWrittenToVector(chartInstance, 19U);
                                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                              217U);
                                *c4_pr = 3.0;
                                c4_updateDataWrittenToVector(chartInstance, 18U);
                                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                              -217);
                              } else {
                                _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                              115);
                                if (CV_EML_IF(16, 1, 15,
                                              c4_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                116);
                                  CV_EML_FCN(16, 16);
                                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                223U);
                                  c4_p_encStr2Arr(chartInstance, c4_dv66);
                                  for (c4_i406 = 0; c4_i406 < 1000; c4_i406++) {
                                    c4_poseBML[c4_i406] = c4_dv66[c4_i406];
                                  }

                                  c4_updateDataWrittenToVector(chartInstance,
                                    19U);
                                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                223U);
                                  *c4_pr = 3.0;
                                  c4_updateDataWrittenToVector(chartInstance,
                                    18U);
                                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                -223);
                                } else {
                                  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                117);
                                  if (CV_EML_IF(16, 1, 16,
                                                c4_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                  118);
                                    CV_EML_FCN(16, 17);
                                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                  229U);
                                    c4_q_encStr2Arr(chartInstance, c4_dv66);
                                    for (c4_i407 = 0; c4_i407 < 1000; c4_i407++)
                                    {
                                      c4_poseBML[c4_i407] = c4_dv66[c4_i407];
                                    }

                                    c4_updateDataWrittenToVector(chartInstance,
                                      19U);
                                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                  229U);
                                    *c4_pr = 3.0;
                                    c4_updateDataWrittenToVector(chartInstance,
                                      18U);
                                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                  -229);
                                  } else {
                                    _SFD_EML_CALL(16U, chartInstance->c4_sfEvent,
                                                  119);
                                    if (CV_EML_IF(16, 1, 17,
                                                  c4_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(16U,
                                                    chartInstance->c4_sfEvent,
                                                    120);
                                      CV_EML_FCN(16, 18);
                                      _SFD_EML_CALL(16U,
                                                    chartInstance->c4_sfEvent,
                                                    235U);
                                      c4_r_encStr2Arr(chartInstance, c4_dv66);
                                      for (c4_i408 = 0; c4_i408 < 1000; c4_i408
                                           ++) {
                                        c4_poseBML[c4_i408] = c4_dv66[c4_i408];
                                      }

                                      c4_updateDataWrittenToVector(chartInstance,
                                        19U);
                                      _SFD_EML_CALL(16U,
                                                    chartInstance->c4_sfEvent,
                                                    235U);
                                      *c4_pr = 3.0;
                                      c4_updateDataWrittenToVector(chartInstance,
                                        18U);
                                      _SFD_EML_CALL(16U,
                                                    chartInstance->c4_sfEvent,
                                                    -235);
                                    } else {
                                      _SFD_EML_CALL(16U,
                                                    chartInstance->c4_sfEvent,
                                                    121);
                                      if (CV_EML_IF(16, 1, 18,
                                                    c4_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(16U,
                                                      chartInstance->c4_sfEvent,
                                                      122);
                                        CV_EML_FCN(16, 19);
                                        _SFD_EML_CALL(16U,
                                                      chartInstance->c4_sfEvent,
                                                      241U);
                                        c4_s_encStr2Arr(chartInstance, c4_dv66);
                                        for (c4_i409 = 0; c4_i409 < 1000;
                                             c4_i409++) {
                                          c4_poseBML[c4_i409] = c4_dv66[c4_i409];
                                        }

                                        c4_updateDataWrittenToVector
                                          (chartInstance, 19U);
                                        _SFD_EML_CALL(16U,
                                                      chartInstance->c4_sfEvent,
                                                      241U);
                                        *c4_pr = 3.0;
                                        c4_updateDataWrittenToVector
                                          (chartInstance, 18U);
                                        _SFD_EML_CALL(16U,
                                                      chartInstance->c4_sfEvent,
                                                      -241);
                                      } else {
                                        _SFD_EML_CALL(16U,
                                                      chartInstance->c4_sfEvent,
                                                      123);
                                        if (CV_EML_IF(16, 1, 19,
                                                      c4_aVarTruthTableCondition_20))
                                        {
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        124);
                                          CV_EML_FCN(16, 20);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        247U);
                                          c4_t_encStr2Arr(chartInstance, c4_dv66);
                                          for (c4_i410 = 0; c4_i410 < 1000;
                                               c4_i410++) {
                                            c4_poseBML[c4_i410] =
                                              c4_dv66[c4_i410];
                                          }

                                          c4_updateDataWrittenToVector
                                            (chartInstance, 19U);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        247U);
                                          *c4_pr = 3.0;
                                          c4_updateDataWrittenToVector
                                            (chartInstance, 18U);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        -247);
                                        } else {
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        126);
                                          CV_EML_FCN(16, 1);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        133U);
                                          c4_encStr2Arr(chartInstance, c4_dv66);
                                          for (c4_i411 = 0; c4_i411 < 1000;
                                               c4_i411++) {
                                            c4_poseBML[c4_i411] =
                                              c4_dv66[c4_i411];
                                          }

                                          c4_updateDataWrittenToVector
                                            (chartInstance, 19U);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
                                                        133U);
                                          *c4_pr = 3.0;
                                          c4_updateDataWrittenToVector
                                            (chartInstance, 18U);
                                          _SFD_EML_CALL(16U,
                                                        chartInstance->c4_sfEvent,
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
    }
  }

  _SFD_EML_CALL(16U, chartInstance->c4_sfEvent, -126);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_selfAdaptor_TwitchTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000])
{
  uint32_T c4_debug_family_var_map[24];
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
  boolean_T c4_aVarTruthTableCondition_19;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_dv67[1000];
  int32_T c4_i412;
  int32_T c4_i413;
  int32_T c4_i414;
  int32_T c4_i415;
  int32_T c4_i416;
  int32_T c4_i417;
  int32_T c4_i418;
  int32_T c4_i419;
  int32_T c4_i420;
  int32_T c4_i421;
  int32_T c4_i422;
  int32_T c4_i423;
  int32_T c4_i424;
  int32_T c4_i425;
  int32_T c4_i426;
  int32_T c4_i427;
  int32_T c4_i428;
  int32_T c4_i429;
  int32_T c4_i430;
  int32_T c4_i431;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c4_v_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_aVarTruthTableCondition_19, 18U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 19U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 20U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 21U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_pr, 22U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 23U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(18, 0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 16);
  c4_aVarTruthTableCondition_14 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 17);
  c4_aVarTruthTableCondition_15 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 18);
  c4_aVarTruthTableCondition_16 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_17 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 20);
  c4_aVarTruthTableCondition_18 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 21);
  c4_aVarTruthTableCondition_19 = false;
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 25);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 28);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 31);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 34);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 37);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 40);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 43);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 46);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 49);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 52);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 55);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 58);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 61);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 64);
  c4_aVarTruthTableCondition_14 = (c4_bmlID == 14.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 67);
  c4_aVarTruthTableCondition_15 = (c4_bmlID == 15.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 70);
  c4_aVarTruthTableCondition_16 = (c4_bmlID == 16.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 73);
  c4_aVarTruthTableCondition_17 = (c4_bmlID == 17.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 76);
  c4_aVarTruthTableCondition_18 = (c4_bmlID == 18.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 79);
  c4_aVarTruthTableCondition_19 = (c4_bmlID == 19.0);
  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 81);
  if (CV_EML_IF(18, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 82);
    CV_EML_FCN(18, 1);
    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, MAX_int8_T);
    c4_u_encStr2Arr(chartInstance, c4_dv67);
    for (c4_i412 = 0; c4_i412 < 1000; c4_i412++) {
      c4_poseBML[c4_i412] = c4_dv67[c4_i412];
    }

    c4_updateDataWrittenToVector(chartInstance, 21U);
    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, MAX_int8_T);
    *c4_pr = 3.0;
    c4_updateDataWrittenToVector(chartInstance, 20U);
    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -127);
  } else {
    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 83);
    if (CV_EML_IF(18, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 84);
      CV_EML_FCN(18, 2);
      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 133U);
      c4_v_encStr2Arr(chartInstance, c4_dv67);
      for (c4_i413 = 0; c4_i413 < 1000; c4_i413++) {
        c4_poseBML[c4_i413] = c4_dv67[c4_i413];
      }

      c4_updateDataWrittenToVector(chartInstance, 21U);
      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 133U);
      *c4_pr = 3.0;
      c4_updateDataWrittenToVector(chartInstance, 20U);
      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -133);
    } else {
      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 85);
      if (CV_EML_IF(18, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 86);
        CV_EML_FCN(18, 3);
        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 139U);
        c4_k_encStr2Arr(chartInstance, c4_dv67);
        for (c4_i414 = 0; c4_i414 < 1000; c4_i414++) {
          c4_poseBML[c4_i414] = c4_dv67[c4_i414];
        }

        c4_updateDataWrittenToVector(chartInstance, 21U);
        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 139U);
        *c4_pr = 3.0;
        c4_updateDataWrittenToVector(chartInstance, 20U);
        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -139);
      } else {
        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 87);
        if (CV_EML_IF(18, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 88);
          CV_EML_FCN(18, 4);
          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 145U);
          c4_w_encStr2Arr(chartInstance, c4_dv67);
          for (c4_i415 = 0; c4_i415 < 1000; c4_i415++) {
            c4_poseBML[c4_i415] = c4_dv67[c4_i415];
          }

          c4_updateDataWrittenToVector(chartInstance, 21U);
          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 145U);
          *c4_pr = 3.0;
          c4_updateDataWrittenToVector(chartInstance, 20U);
          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -145);
        } else {
          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 89);
          if (CV_EML_IF(18, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 90);
            CV_EML_FCN(18, 5);
            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 151U);
            c4_x_encStr2Arr(chartInstance, c4_dv67);
            for (c4_i416 = 0; c4_i416 < 1000; c4_i416++) {
              c4_poseBML[c4_i416] = c4_dv67[c4_i416];
            }

            c4_updateDataWrittenToVector(chartInstance, 21U);
            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 151U);
            *c4_pr = 3.0;
            c4_updateDataWrittenToVector(chartInstance, 20U);
            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -151);
          } else {
            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 91);
            if (CV_EML_IF(18, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 92);
              CV_EML_FCN(18, 6);
              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 157U);
              c4_y_encStr2Arr(chartInstance, c4_dv67);
              for (c4_i417 = 0; c4_i417 < 1000; c4_i417++) {
                c4_poseBML[c4_i417] = c4_dv67[c4_i417];
              }

              c4_updateDataWrittenToVector(chartInstance, 21U);
              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 157U);
              *c4_pr = 3.0;
              c4_updateDataWrittenToVector(chartInstance, 20U);
              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -157);
            } else {
              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 93);
              if (CV_EML_IF(18, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 94);
                CV_EML_FCN(18, 7);
                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 163U);
                c4_ab_encStr2Arr(chartInstance, c4_dv67);
                for (c4_i418 = 0; c4_i418 < 1000; c4_i418++) {
                  c4_poseBML[c4_i418] = c4_dv67[c4_i418];
                }

                c4_updateDataWrittenToVector(chartInstance, 21U);
                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 163U);
                *c4_pr = 3.0;
                c4_updateDataWrittenToVector(chartInstance, 20U);
                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -163);
              } else {
                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 95);
                if (CV_EML_IF(18, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 96);
                  CV_EML_FCN(18, 8);
                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 169U);
                  c4_bb_encStr2Arr(chartInstance, c4_dv67);
                  for (c4_i419 = 0; c4_i419 < 1000; c4_i419++) {
                    c4_poseBML[c4_i419] = c4_dv67[c4_i419];
                  }

                  c4_updateDataWrittenToVector(chartInstance, 21U);
                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 169U);
                  *c4_pr = 3.0;
                  c4_updateDataWrittenToVector(chartInstance, 20U);
                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -169);
                } else {
                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 97);
                  if (CV_EML_IF(18, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 98);
                    CV_EML_FCN(18, 9);
                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 175U);
                    c4_cb_encStr2Arr(chartInstance, c4_dv67);
                    for (c4_i420 = 0; c4_i420 < 1000; c4_i420++) {
                      c4_poseBML[c4_i420] = c4_dv67[c4_i420];
                    }

                    c4_updateDataWrittenToVector(chartInstance, 21U);
                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 175U);
                    *c4_pr = 3.0;
                    c4_updateDataWrittenToVector(chartInstance, 20U);
                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -175);
                  } else {
                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 99);
                    if (CV_EML_IF(18, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 100);
                      CV_EML_FCN(18, 10);
                      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 181U);
                      c4_db_encStr2Arr(chartInstance, c4_dv67);
                      for (c4_i421 = 0; c4_i421 < 1000; c4_i421++) {
                        c4_poseBML[c4_i421] = c4_dv67[c4_i421];
                      }

                      c4_updateDataWrittenToVector(chartInstance, 21U);
                      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 181U);
                      *c4_pr = 3.0;
                      c4_updateDataWrittenToVector(chartInstance, 20U);
                      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -181);
                    } else {
                      _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 101);
                      if (CV_EML_IF(18, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 102);
                        CV_EML_FCN(18, 11);
                        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 187U);
                        c4_eb_encStr2Arr(chartInstance, c4_dv67);
                        for (c4_i422 = 0; c4_i422 < 1000; c4_i422++) {
                          c4_poseBML[c4_i422] = c4_dv67[c4_i422];
                        }

                        c4_updateDataWrittenToVector(chartInstance, 21U);
                        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 187U);
                        *c4_pr = 3.0;
                        c4_updateDataWrittenToVector(chartInstance, 20U);
                        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -187);
                      } else {
                        _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 103);
                        if (CV_EML_IF(18, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 104);
                          CV_EML_FCN(18, 12);
                          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 193U);
                          c4_fb_encStr2Arr(chartInstance, c4_dv67);
                          for (c4_i423 = 0; c4_i423 < 1000; c4_i423++) {
                            c4_poseBML[c4_i423] = c4_dv67[c4_i423];
                          }

                          c4_updateDataWrittenToVector(chartInstance, 21U);
                          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 193U);
                          *c4_pr = 3.0;
                          c4_updateDataWrittenToVector(chartInstance, 20U);
                          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -193);
                        } else {
                          _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 105);
                          if (CV_EML_IF(18, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 106);
                            CV_EML_FCN(18, 13);
                            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 199U);
                            c4_gb_encStr2Arr(chartInstance, c4_dv67);
                            for (c4_i424 = 0; c4_i424 < 1000; c4_i424++) {
                              c4_poseBML[c4_i424] = c4_dv67[c4_i424];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 21U);
                            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 199U);
                            *c4_pr = 3.0;
                            c4_updateDataWrittenToVector(chartInstance, 20U);
                            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -199);
                          } else {
                            _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 107);
                            if (CV_EML_IF(18, 1, 13,
                                          c4_aVarTruthTableCondition_14)) {
                              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 108);
                              CV_EML_FCN(18, 14);
                              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 205U);
                              c4_hb_encStr2Arr(chartInstance, c4_dv67);
                              for (c4_i425 = 0; c4_i425 < 1000; c4_i425++) {
                                c4_poseBML[c4_i425] = c4_dv67[c4_i425];
                              }

                              c4_updateDataWrittenToVector(chartInstance, 21U);
                              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 205U);
                              *c4_pr = 3.0;
                              c4_updateDataWrittenToVector(chartInstance, 20U);
                              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -205);
                            } else {
                              _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, 109);
                              if (CV_EML_IF(18, 1, 14,
                                            c4_aVarTruthTableCondition_15)) {
                                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                              110);
                                CV_EML_FCN(18, 15);
                                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                              211U);
                                c4_ib_encStr2Arr(chartInstance, c4_dv67);
                                for (c4_i426 = 0; c4_i426 < 1000; c4_i426++) {
                                  c4_poseBML[c4_i426] = c4_dv67[c4_i426];
                                }

                                c4_updateDataWrittenToVector(chartInstance, 21U);
                                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                              211U);
                                *c4_pr = 3.0;
                                c4_updateDataWrittenToVector(chartInstance, 20U);
                                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                              -211);
                              } else {
                                _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                              111);
                                if (CV_EML_IF(18, 1, 15,
                                              c4_aVarTruthTableCondition_16)) {
                                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                112);
                                  CV_EML_FCN(18, 16);
                                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                217U);
                                  c4_jb_encStr2Arr(chartInstance, c4_dv67);
                                  for (c4_i427 = 0; c4_i427 < 1000; c4_i427++) {
                                    c4_poseBML[c4_i427] = c4_dv67[c4_i427];
                                  }

                                  c4_updateDataWrittenToVector(chartInstance,
                                    21U);
                                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                217U);
                                  *c4_pr = 3.0;
                                  c4_updateDataWrittenToVector(chartInstance,
                                    20U);
                                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                -217);
                                } else {
                                  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                113);
                                  if (CV_EML_IF(18, 1, 16,
                                                c4_aVarTruthTableCondition_17))
                                  {
                                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                  114);
                                    CV_EML_FCN(18, 17);
                                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                  223U);
                                    c4_j_encStr2Arr(chartInstance, c4_dv67);
                                    for (c4_i428 = 0; c4_i428 < 1000; c4_i428++)
                                    {
                                      c4_poseBML[c4_i428] = c4_dv67[c4_i428];
                                    }

                                    c4_updateDataWrittenToVector(chartInstance,
                                      21U);
                                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                  223U);
                                    *c4_pr = 3.0;
                                    c4_updateDataWrittenToVector(chartInstance,
                                      20U);
                                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                  -223);
                                  } else {
                                    _SFD_EML_CALL(18U, chartInstance->c4_sfEvent,
                                                  115);
                                    if (CV_EML_IF(18, 1, 17,
                                                  c4_aVarTruthTableCondition_18))
                                    {
                                      _SFD_EML_CALL(18U,
                                                    chartInstance->c4_sfEvent,
                                                    116);
                                      CV_EML_FCN(18, 18);
                                      _SFD_EML_CALL(18U,
                                                    chartInstance->c4_sfEvent,
                                                    229U);
                                      c4_kb_encStr2Arr(chartInstance, c4_dv67);
                                      for (c4_i429 = 0; c4_i429 < 1000; c4_i429
                                           ++) {
                                        c4_poseBML[c4_i429] = c4_dv67[c4_i429];
                                      }

                                      c4_updateDataWrittenToVector(chartInstance,
                                        21U);
                                      _SFD_EML_CALL(18U,
                                                    chartInstance->c4_sfEvent,
                                                    229U);
                                      *c4_pr = 3.0;
                                      c4_updateDataWrittenToVector(chartInstance,
                                        20U);
                                      _SFD_EML_CALL(18U,
                                                    chartInstance->c4_sfEvent,
                                                    -229);
                                    } else {
                                      _SFD_EML_CALL(18U,
                                                    chartInstance->c4_sfEvent,
                                                    117);
                                      if (CV_EML_IF(18, 1, 18,
                                                    c4_aVarTruthTableCondition_19))
                                      {
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      118);
                                        CV_EML_FCN(18, 19);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      235U);
                                        c4_c_encStr2Arr(chartInstance, c4_dv67);
                                        for (c4_i430 = 0; c4_i430 < 1000;
                                             c4_i430++) {
                                          c4_poseBML[c4_i430] = c4_dv67[c4_i430];
                                        }

                                        c4_updateDataWrittenToVector
                                          (chartInstance, 21U);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      235U);
                                        *c4_pr = 3.0;
                                        c4_updateDataWrittenToVector
                                          (chartInstance, 20U);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      -235);
                                      } else {
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      120);
                                        CV_EML_FCN(18, 1);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      MAX_int8_T);
                                        c4_u_encStr2Arr(chartInstance, c4_dv67);
                                        for (c4_i431 = 0; c4_i431 < 1000;
                                             c4_i431++) {
                                          c4_poseBML[c4_i431] = c4_dv67[c4_i431];
                                        }

                                        c4_updateDataWrittenToVector
                                          (chartInstance, 21U);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      MAX_int8_T);
                                        *c4_pr = 3.0;
                                        c4_updateDataWrittenToVector
                                          (chartInstance, 20U);
                                        _SFD_EML_CALL(18U,
                                                      chartInstance->c4_sfEvent,
                                                      -127);
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

  _SFD_EML_CALL(18U, chartInstance->c4_sfEvent, -120);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_weightshift_SpaceTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmlID, real_T *
   c4_pr, real_T c4_poseBML[1000])
{
  uint32_T c4_debug_family_var_map[18];
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
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_dv68[1000];
  int32_T c4_i432;
  int32_T c4_i433;
  int32_T c4_i434;
  int32_T c4_i435;
  int32_T c4_i436;
  int32_T c4_i437;
  int32_T c4_i438;
  int32_T c4_i439;
  int32_T c4_i440;
  int32_T c4_i441;
  int32_T c4_i442;
  int32_T c4_i443;
  int32_T c4_i444;
  int32_T c4_i445;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_nb_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 13U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 14U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_bmlID, 15U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_pr, 16U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_poseBML, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(20, 0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 8);
  c4_aVarTruthTableCondition_6 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 9);
  c4_aVarTruthTableCondition_7 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 10);
  c4_aVarTruthTableCondition_8 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 11);
  c4_aVarTruthTableCondition_9 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 12);
  c4_aVarTruthTableCondition_10 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 13);
  c4_aVarTruthTableCondition_11 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 14);
  c4_aVarTruthTableCondition_12 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 15);
  c4_aVarTruthTableCondition_13 = false;
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_1 = (c4_bmlID == 1.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 22);
  c4_aVarTruthTableCondition_2 = (c4_bmlID == 2.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 25);
  c4_aVarTruthTableCondition_3 = (c4_bmlID == 3.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 28);
  c4_aVarTruthTableCondition_4 = (c4_bmlID == 4.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 31);
  c4_aVarTruthTableCondition_5 = (c4_bmlID == 5.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 34);
  c4_aVarTruthTableCondition_6 = (c4_bmlID == 6.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 37);
  c4_aVarTruthTableCondition_7 = (c4_bmlID == 7.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 40);
  c4_aVarTruthTableCondition_8 = (c4_bmlID == 8.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 43);
  c4_aVarTruthTableCondition_9 = (c4_bmlID == 9.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 46);
  c4_aVarTruthTableCondition_10 = (c4_bmlID == 10.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 49);
  c4_aVarTruthTableCondition_11 = (c4_bmlID == 11.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 52);
  c4_aVarTruthTableCondition_12 = (c4_bmlID == 12.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 55);
  c4_aVarTruthTableCondition_13 = (c4_bmlID == 13.0);
  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 57);
  if (CV_EML_IF(20, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 58);
    CV_EML_FCN(20, 1);
    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 91);
    c4_lb_encStr2Arr(chartInstance, c4_dv68);
    for (c4_i432 = 0; c4_i432 < 1000; c4_i432++) {
      c4_poseBML[c4_i432] = c4_dv68[c4_i432];
    }

    c4_updateDataWrittenToVector(chartInstance, 23U);
    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 91);
    *c4_pr = 3.0;
    c4_updateDataWrittenToVector(chartInstance, 22U);
    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -91);
  } else {
    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 59);
    if (CV_EML_IF(20, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 60);
      CV_EML_FCN(20, 2);
      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 97);
      c4_mb_encStr2Arr(chartInstance, c4_dv68);
      for (c4_i433 = 0; c4_i433 < 1000; c4_i433++) {
        c4_poseBML[c4_i433] = c4_dv68[c4_i433];
      }

      c4_updateDataWrittenToVector(chartInstance, 23U);
      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 97);
      *c4_pr = 3.0;
      c4_updateDataWrittenToVector(chartInstance, 22U);
      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -97);
    } else {
      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 61);
      if (CV_EML_IF(20, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 62);
        CV_EML_FCN(20, 3);
        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 103);
        c4_nb_encStr2Arr(chartInstance, c4_dv68);
        for (c4_i434 = 0; c4_i434 < 1000; c4_i434++) {
          c4_poseBML[c4_i434] = c4_dv68[c4_i434];
        }

        c4_updateDataWrittenToVector(chartInstance, 23U);
        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 103);
        *c4_pr = 4.0;
        c4_updateDataWrittenToVector(chartInstance, 22U);
        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -103);
      } else {
        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 63);
        if (CV_EML_IF(20, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 64);
          CV_EML_FCN(20, 4);
          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 109);
          c4_ob_encStr2Arr(chartInstance, c4_dv68);
          for (c4_i435 = 0; c4_i435 < 1000; c4_i435++) {
            c4_poseBML[c4_i435] = c4_dv68[c4_i435];
          }

          c4_updateDataWrittenToVector(chartInstance, 23U);
          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 109);
          *c4_pr = 4.0;
          c4_updateDataWrittenToVector(chartInstance, 22U);
          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -109);
        } else {
          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 65);
          if (CV_EML_IF(20, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 66);
            CV_EML_FCN(20, 8);
            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 133U);
            c4_p_encStr2Arr(chartInstance, c4_dv68);
            for (c4_i436 = 0; c4_i436 < 1000; c4_i436++) {
              c4_poseBML[c4_i436] = c4_dv68[c4_i436];
            }

            c4_updateDataWrittenToVector(chartInstance, 23U);
            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 133U);
            *c4_pr = 3.0;
            c4_updateDataWrittenToVector(chartInstance, 22U);
            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -133);
          } else {
            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 67);
            if (CV_EML_IF(20, 1, 5, c4_aVarTruthTableCondition_6)) {
              _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 68);
              CV_EML_FCN(20, 9);
              _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 139U);
              c4_pb_encStr2Arr(chartInstance, c4_dv68);
              for (c4_i437 = 0; c4_i437 < 1000; c4_i437++) {
                c4_poseBML[c4_i437] = c4_dv68[c4_i437];
              }

              c4_updateDataWrittenToVector(chartInstance, 23U);
              _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 139U);
              *c4_pr = 4.0;
              c4_updateDataWrittenToVector(chartInstance, 22U);
              _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -139);
            } else {
              _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 69);
              if (CV_EML_IF(20, 1, 6, c4_aVarTruthTableCondition_7)) {
                _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 70);
                CV_EML_FCN(20, 7);
                _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, MAX_int8_T);
                c4_qb_encStr2Arr(chartInstance, c4_dv68);
                for (c4_i438 = 0; c4_i438 < 1000; c4_i438++) {
                  c4_poseBML[c4_i438] = c4_dv68[c4_i438];
                }

                c4_updateDataWrittenToVector(chartInstance, 23U);
                _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, MAX_int8_T);
                *c4_pr = 3.0;
                c4_updateDataWrittenToVector(chartInstance, 22U);
                _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -127);
              } else {
                _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 71);
                if (CV_EML_IF(20, 1, 7, c4_aVarTruthTableCondition_8)) {
                  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 72);
                  CV_EML_FCN(20, 5);
                  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 115);
                  c4_rb_encStr2Arr(chartInstance, c4_dv68);
                  for (c4_i439 = 0; c4_i439 < 1000; c4_i439++) {
                    c4_poseBML[c4_i439] = c4_dv68[c4_i439];
                  }

                  c4_updateDataWrittenToVector(chartInstance, 23U);
                  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 115);
                  *c4_pr = 4.0;
                  c4_updateDataWrittenToVector(chartInstance, 22U);
                  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -115);
                } else {
                  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 73);
                  if (CV_EML_IF(20, 1, 8, c4_aVarTruthTableCondition_9)) {
                    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 74);
                    CV_EML_FCN(20, 6);
                    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 121);
                    c4_sb_encStr2Arr(chartInstance, c4_dv68);
                    for (c4_i440 = 0; c4_i440 < 1000; c4_i440++) {
                      c4_poseBML[c4_i440] = c4_dv68[c4_i440];
                    }

                    c4_updateDataWrittenToVector(chartInstance, 23U);
                    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 121);
                    *c4_pr = 3.0;
                    c4_updateDataWrittenToVector(chartInstance, 22U);
                    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -121);
                  } else {
                    _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 75);
                    if (CV_EML_IF(20, 1, 9, c4_aVarTruthTableCondition_10)) {
                      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 76);
                      CV_EML_FCN(20, 10);
                      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 145U);
                      c4_tb_encStr2Arr(chartInstance, c4_dv68);
                      for (c4_i441 = 0; c4_i441 < 1000; c4_i441++) {
                        c4_poseBML[c4_i441] = c4_dv68[c4_i441];
                      }

                      c4_updateDataWrittenToVector(chartInstance, 23U);
                      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 145U);
                      *c4_pr = 4.0;
                      c4_updateDataWrittenToVector(chartInstance, 22U);
                      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -145);
                    } else {
                      _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 77);
                      if (CV_EML_IF(20, 1, 10, c4_aVarTruthTableCondition_11)) {
                        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 78);
                        CV_EML_FCN(20, 11);
                        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 151U);
                        c4_ub_encStr2Arr(chartInstance, c4_dv68);
                        for (c4_i442 = 0; c4_i442 < 1000; c4_i442++) {
                          c4_poseBML[c4_i442] = c4_dv68[c4_i442];
                        }

                        c4_updateDataWrittenToVector(chartInstance, 23U);
                        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 151U);
                        *c4_pr = 3.0;
                        c4_updateDataWrittenToVector(chartInstance, 22U);
                        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -151);
                      } else {
                        _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 79);
                        if (CV_EML_IF(20, 1, 11, c4_aVarTruthTableCondition_12))
                        {
                          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 80);
                          CV_EML_FCN(20, 12);
                          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 157U);
                          c4_vb_encStr2Arr(chartInstance, c4_dv68);
                          for (c4_i443 = 0; c4_i443 < 1000; c4_i443++) {
                            c4_poseBML[c4_i443] = c4_dv68[c4_i443];
                          }

                          c4_updateDataWrittenToVector(chartInstance, 23U);
                          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 157U);
                          *c4_pr = 3.0;
                          c4_updateDataWrittenToVector(chartInstance, 22U);
                          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -157);
                        } else {
                          _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 81);
                          if (CV_EML_IF(20, 1, 12, c4_aVarTruthTableCondition_13))
                          {
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 82);
                            CV_EML_FCN(20, 13);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 163U);
                            c4_wb_encStr2Arr(chartInstance, c4_dv68);
                            for (c4_i444 = 0; c4_i444 < 1000; c4_i444++) {
                              c4_poseBML[c4_i444] = c4_dv68[c4_i444];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 23U);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 163U);
                            *c4_pr = 3.0;
                            c4_updateDataWrittenToVector(chartInstance, 22U);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -163);
                          } else {
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 84);
                            CV_EML_FCN(20, 8);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 133U);
                            c4_p_encStr2Arr(chartInstance, c4_dv68);
                            for (c4_i445 = 0; c4_i445 < 1000; c4_i445++) {
                              c4_poseBML[c4_i445] = c4_dv68[c4_i445];
                            }

                            c4_updateDataWrittenToVector(chartInstance, 23U);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, 133U);
                            *c4_pr = 3.0;
                            c4_updateDataWrittenToVector(chartInstance, 22U);
                            _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -133);
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

  _SFD_EML_CALL(20U, chartInstance->c4_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c4_weightShiftTypeTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_poseSpeed,
   real_T c4_spacious)
{
  real_T c4_shiftType;
  uint32_T c4_debug_family_var_map[9];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_bc_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_poseSpeed, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_spacious, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_shiftType, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  CV_EML_FCN(19, 0);
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 11);
  guard2 = false;
  if (c4_poseSpeed == 2.0) {
    if (c4_spacious == 0.0) {
      c4_b1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c4_b1 = false;
  }

  c4_aVarTruthTableCondition_1 = c4_b1;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 15);
  guard1 = false;
  if (c4_poseSpeed == 2.0) {
    if (c4_spacious == 1.0) {
      c4_b2 = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    c4_b2 = false;
  }

  c4_aVarTruthTableCondition_2 = c4_b2;
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 19);
  c4_aVarTruthTableCondition_3 = (c4_poseSpeed == 3.0);
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 23);
  c4_aVarTruthTableCondition_4 = (c4_poseSpeed == 1.0);
  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 25);
  if (CV_EML_IF(19, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 26);
    CV_EML_FCN(19, 1);
    _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 41);
    c4_shiftType = 21.0;
    c4_updateDataWrittenToVector(chartInstance, 24U);
    _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -41);
  } else {
    _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 27);
    if (CV_EML_IF(19, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 28);
      CV_EML_FCN(19, 3);
      _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 53);
      c4_shiftType = 22.0;
      c4_updateDataWrittenToVector(chartInstance, 24U);
      _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -53);
    } else {
      _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 29);
      if (CV_EML_IF(19, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 30);
        CV_EML_FCN(19, 2);
        _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 47);
        c4_shiftType = 26.0;
        c4_updateDataWrittenToVector(chartInstance, 24U);
        _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -47);
      } else {
        _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 31);
        if (CV_EML_IF(19, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 32);
          CV_EML_FCN(19, 4);
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 59);
          c4_shiftType = 16.0;
          c4_updateDataWrittenToVector(chartInstance, 24U);
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -59);
        } else {
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 34);
          CV_EML_FCN(19, 4);
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, 59);
          c4_shiftType = 16.0;
          c4_updateDataWrittenToVector(chartInstance, 24U);
          _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -59);
        }
      }
    }
  }

  _SFD_EML_CALL(19U, chartInstance->c4_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  return c4_shiftType;
}

static real_T c4_selfAdaptorTypeTablec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_poseSpeed,
   real_T c4_poseTwitch)
{
  real_T c4_poseType;
  uint32_T c4_debug_family_var_map[10];
  boolean_T c4_aVarTruthTableCondition_1;
  boolean_T c4_aVarTruthTableCondition_2;
  boolean_T c4_aVarTruthTableCondition_3;
  boolean_T c4_aVarTruthTableCondition_4;
  boolean_T c4_aVarTruthTableCondition_5;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  boolean_T c4_b3;
  boolean_T c4_b4;
  boolean_T c4_b5;
  boolean_T c4_b6;
  boolean_T c4_b7;
  boolean_T c4_b8;
  boolean_T c4_b9;
  boolean_T c4_b10;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c4_cc_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 5U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 6U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_poseSpeed, 7U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_poseTwitch, 8U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_poseType, 9U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  CV_EML_FCN(17, 0);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 3);
  c4_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 4);
  c4_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 5);
  c4_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 6);
  c4_aVarTruthTableCondition_4 = false;
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 7);
  c4_aVarTruthTableCondition_5 = false;
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 12);
  c4_b3 = (c4_poseSpeed == 2.0);
  c4_b4 = (c4_poseTwitch == 1.0);
  c4_aVarTruthTableCondition_1 = (c4_b3 && c4_b4);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 16);
  c4_b5 = (c4_poseSpeed == 3.0);
  c4_b6 = (c4_poseTwitch == 1.0);
  c4_aVarTruthTableCondition_2 = (c4_b5 && c4_b6);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 20);
  c4_b7 = (c4_poseSpeed == 2.0);
  c4_b8 = (c4_poseTwitch == 0.0);
  c4_aVarTruthTableCondition_3 = (c4_b7 && c4_b8);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 24);
  c4_b9 = (c4_poseSpeed == 3.0);
  c4_b10 = (c4_poseTwitch == 0.0);
  c4_aVarTruthTableCondition_4 = (c4_b9 && c4_b10);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 28);
  c4_aVarTruthTableCondition_5 = (c4_poseSpeed == 1.0);
  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 30);
  if (CV_EML_IF(17, 1, 0, c4_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 31);
    CV_EML_FCN(17, 1);
    _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 48);
    c4_poseType = 13.0;
    c4_updateDataWrittenToVector(chartInstance, 25U);
    _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -48);
  } else {
    _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 32);
    if (CV_EML_IF(17, 1, 1, c4_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 33);
      CV_EML_FCN(17, 2);
      _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 54);
      c4_poseType = 14.0;
      c4_updateDataWrittenToVector(chartInstance, 25U);
      _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -54);
    } else {
      _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 34);
      if (CV_EML_IF(17, 1, 2, c4_aVarTruthTableCondition_3)) {
        _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 35);
        CV_EML_FCN(17, 3);
        _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 60);
        c4_poseType = 23.0;
        c4_updateDataWrittenToVector(chartInstance, 25U);
        _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -60);
      } else {
        _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 36);
        if (CV_EML_IF(17, 1, 3, c4_aVarTruthTableCondition_4)) {
          _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 37);
          CV_EML_FCN(17, 4);
          _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 66);
          c4_poseType = 24.0;
          c4_updateDataWrittenToVector(chartInstance, 25U);
          _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -66);
        } else {
          _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 38);
          if (CV_EML_IF(17, 1, 4, c4_aVarTruthTableCondition_5)) {
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 39);
            CV_EML_FCN(17, 5);
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 72);
            c4_poseType = 16.0;
            c4_updateDataWrittenToVector(chartInstance, 25U);
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -72);
          } else {
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 41);
            CV_EML_FCN(17, 5);
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, 72);
            c4_poseType = 16.0;
            c4_updateDataWrittenToVector(chartInstance, 25U);
            _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -72);
          }
        }
      }
    }
  }

  _SFD_EML_CALL(17U, chartInstance->c4_sfEvent, -41);
  _SFD_SYMBOL_SCOPE_POP();
  return c4_poseType;
}

static void c4_insertQueueLowc4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmls[5000],
   real_T c4_myBML[1000], real_T c4_newBmls[5000])
{
  uint32_T c4_debug_family_var_map[8];
  real_T c4_full;
  real_T c4_t[1000];
  real_T c4_i;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i446;
  static real_T c4_dv69[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c4_i447;
  int32_T c4_i448;
  int32_T c4_i449;
  int32_T c4_i450;
  int32_T c4_i451;
  int32_T c4_b_i;
  int32_T c4_c_i;
  int32_T c4_i452;
  real_T c4_b_bmls[1000];
  int32_T c4_i453;
  real_T c4_dv70[1000];
  int32_T c4_d_i;
  int32_T c4_i454;
  int32_T c4_i455;
  real_T c4_c_bmls[1000];
  int32_T c4_i456;
  int32_T c4_i457;
  real_T c4_d_bmls[1000];
  int32_T c4_i458;
  int32_T c4_i459;
  real_T c4_e_bmls[1000];
  int32_T c4_i460;
  int32_T c4_i461;
  int32_T c4_i462;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_dc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_full, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_t, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_bmls, 5U, c4_rb_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_newBmls, 7U, c4_rb_sf_marshallOut,
    c4_e_sf_marshallIn);
  CV_EML_FCN(15, 0);
  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 2);
  c4_full = 1.0;
  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 3);
  for (c4_i446 = 0; c4_i446 < 1000; c4_i446++) {
    c4_t[c4_i446] = c4_dv69[c4_i446];
  }

  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 4);
  for (c4_i447 = 0; c4_i447 < 1000; c4_i447++) {
    c4_newBmls[c4_i447] = c4_t[c4_i447];
  }

  for (c4_i448 = 0; c4_i448 < 1000; c4_i448++) {
    c4_newBmls[c4_i448 + 1000] = c4_t[c4_i448];
  }

  for (c4_i449 = 0; c4_i449 < 1000; c4_i449++) {
    c4_newBmls[c4_i449 + 2000] = c4_t[c4_i449];
  }

  for (c4_i450 = 0; c4_i450 < 1000; c4_i450++) {
    c4_newBmls[c4_i450 + 3000] = c4_t[c4_i450];
  }

  for (c4_i451 = 0; c4_i451 < 1000; c4_i451++) {
    c4_newBmls[c4_i451 + 4000] = c4_t[c4_i451];
  }

  c4_updateDataWrittenToVector(chartInstance, 26U);
  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 5);
  c4_i = 1.0;
  c4_b_i = 0;
  do {
    exitg1 = 0;
    if (c4_b_i < 5) {
      c4_i = 1.0 + (real_T)c4_b_i;
      CV_EML_FOR(15, 1, 0, 1);
      _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 6);
      c4_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c4_i), 1, 5, 2, 0) - 1;
      for (c4_i452 = 0; c4_i452 < 1000; c4_i452++) {
        c4_b_bmls[c4_i452] = c4_bmls[c4_i452 + 1000 * c4_c_i];
      }

      for (c4_i453 = 0; c4_i453 < 1000; c4_i453++) {
        c4_dv70[c4_i453] = c4_dv69[c4_i453];
      }

      if (CV_EML_IF(15, 1, 0, c4_isequal(chartInstance, c4_b_bmls, c4_dv70))) {
        _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 8);
        c4_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK
          ("i", c4_i), 1, 5, 2, 0) - 1;
        for (c4_i454 = 0; c4_i454 < 1000; c4_i454++) {
          c4_bmls[c4_i454 + 1000 * c4_d_i] = c4_myBML[c4_i454];
        }

        _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 9);
        c4_full = 0.0;
        _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 10);
        exitg1 = 1;
      } else {
        c4_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(15, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 13);
  if (CV_EML_IF(15, 1, 1, c4_full != 0.0)) {
    _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 15);
    for (c4_i455 = 0; c4_i455 < 1000; c4_i455++) {
      c4_c_bmls[c4_i455] = c4_bmls[c4_i455 + 1000];
    }

    for (c4_i456 = 0; c4_i456 < 1000; c4_i456++) {
      c4_bmls[c4_i456] = c4_c_bmls[c4_i456];
    }

    _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 16);
    for (c4_i457 = 0; c4_i457 < 1000; c4_i457++) {
      c4_d_bmls[c4_i457] = c4_bmls[c4_i457 + 2000];
    }

    for (c4_i458 = 0; c4_i458 < 1000; c4_i458++) {
      c4_bmls[c4_i458 + 1000] = c4_d_bmls[c4_i458];
    }

    _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 17);
    for (c4_i459 = 0; c4_i459 < 1000; c4_i459++) {
      c4_e_bmls[c4_i459] = c4_bmls[c4_i459 + 3000];
    }

    for (c4_i460 = 0; c4_i460 < 1000; c4_i460++) {
      c4_bmls[c4_i460 + 2000] = c4_e_bmls[c4_i460];
    }

    _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 18);
    for (c4_i461 = 0; c4_i461 < 1000; c4_i461++) {
      c4_bmls[c4_i461 + 4000] = c4_myBML[c4_i461];
    }
  }

  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, 20);
  for (c4_i462 = 0; c4_i462 < 5000; c4_i462++) {
    c4_newBmls[c4_i462] = c4_bmls[c4_i462];
  }

  c4_updateDataWrittenToVector(chartInstance, 26U);
  _SFD_EML_CALL(15U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c4_insertQueuec4_Expriment_Emotion
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, real_T c4_bmls[5000],
   real_T c4_myBML[1000], real_T c4_newBmls[5000])
{
  uint32_T c4_debug_family_var_map[8];
  real_T c4_full;
  real_T c4_t[1000];
  real_T c4_i;
  real_T c4_nargin = 2.0;
  real_T c4_nargout = 1.0;
  int32_T c4_i463;
  static real_T c4_dv71[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c4_i464;
  int32_T c4_i465;
  int32_T c4_i466;
  int32_T c4_i467;
  int32_T c4_i468;
  int32_T c4_b_i;
  int32_T c4_c_i;
  int32_T c4_i469;
  real_T c4_b_bmls[1000];
  int32_T c4_i470;
  real_T c4_dv72[1000];
  int32_T c4_d_i;
  int32_T c4_i471;
  int32_T c4_i472;
  real_T c4_c_bmls[1000];
  int32_T c4_i473;
  int32_T c4_i474;
  real_T c4_d_bmls[1000];
  int32_T c4_i475;
  int32_T c4_i476;
  real_T c4_e_bmls[1000];
  int32_T c4_i477;
  int32_T c4_i478;
  int32_T c4_i479;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c4_fc_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_full, 0U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_t, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i, 2U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_bmls, 5U, c4_rb_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_myBML, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_newBmls, 7U, c4_rb_sf_marshallOut,
    c4_e_sf_marshallIn);
  CV_EML_FCN(14, 0);
  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 2);
  c4_full = 1.0;
  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 3);
  for (c4_i463 = 0; c4_i463 < 1000; c4_i463++) {
    c4_t[c4_i463] = c4_dv71[c4_i463];
  }

  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 4);
  for (c4_i464 = 0; c4_i464 < 1000; c4_i464++) {
    c4_newBmls[c4_i464] = c4_t[c4_i464];
  }

  for (c4_i465 = 0; c4_i465 < 1000; c4_i465++) {
    c4_newBmls[c4_i465 + 1000] = c4_t[c4_i465];
  }

  for (c4_i466 = 0; c4_i466 < 1000; c4_i466++) {
    c4_newBmls[c4_i466 + 2000] = c4_t[c4_i466];
  }

  for (c4_i467 = 0; c4_i467 < 1000; c4_i467++) {
    c4_newBmls[c4_i467 + 3000] = c4_t[c4_i467];
  }

  for (c4_i468 = 0; c4_i468 < 1000; c4_i468++) {
    c4_newBmls[c4_i468 + 4000] = c4_t[c4_i468];
  }

  c4_updateDataWrittenToVector(chartInstance, 27U);
  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 5);
  c4_i = 1.0;
  c4_b_i = 0;
  do {
    exitg1 = 0;
    if (c4_b_i < 5) {
      c4_i = 1.0 + (real_T)c4_b_i;
      CV_EML_FOR(14, 1, 0, 1);
      _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 6);
      c4_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c4_i), 1, 5, 2, 0) - 1;
      for (c4_i469 = 0; c4_i469 < 1000; c4_i469++) {
        c4_b_bmls[c4_i469] = c4_bmls[c4_i469 + 1000 * c4_c_i];
      }

      for (c4_i470 = 0; c4_i470 < 1000; c4_i470++) {
        c4_dv72[c4_i470] = c4_dv71[c4_i470];
      }

      if (CV_EML_IF(14, 1, 0, c4_isequal(chartInstance, c4_b_bmls, c4_dv72))) {
        _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 8);
        c4_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK
          ("i", c4_i), 1, 5, 2, 0) - 1;
        for (c4_i471 = 0; c4_i471 < 1000; c4_i471++) {
          c4_bmls[c4_i471 + 1000 * c4_d_i] = c4_myBML[c4_i471];
        }

        _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 9);
        c4_full = 0.0;
        _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 10);
        exitg1 = 1;
      } else {
        c4_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(14, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 13);
  if (CV_EML_IF(14, 1, 1, c4_full != 0.0)) {
    _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 15);
    for (c4_i472 = 0; c4_i472 < 1000; c4_i472++) {
      c4_c_bmls[c4_i472] = c4_bmls[c4_i472 + 1000];
    }

    for (c4_i473 = 0; c4_i473 < 1000; c4_i473++) {
      c4_bmls[c4_i473] = c4_c_bmls[c4_i473];
    }

    _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 16);
    for (c4_i474 = 0; c4_i474 < 1000; c4_i474++) {
      c4_d_bmls[c4_i474] = c4_bmls[c4_i474 + 2000];
    }

    for (c4_i475 = 0; c4_i475 < 1000; c4_i475++) {
      c4_bmls[c4_i475 + 1000] = c4_d_bmls[c4_i475];
    }

    _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 17);
    for (c4_i476 = 0; c4_i476 < 1000; c4_i476++) {
      c4_e_bmls[c4_i476] = c4_bmls[c4_i476 + 3000];
    }

    for (c4_i477 = 0; c4_i477 < 1000; c4_i477++) {
      c4_bmls[c4_i477 + 2000] = c4_e_bmls[c4_i477];
    }

    _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 18);
    for (c4_i478 = 0; c4_i478 < 1000; c4_i478++) {
      c4_bmls[c4_i478 + 4000] = c4_myBML[c4_i478];
    }
  }

  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, 20);
  for (c4_i479 = 0; c4_i479 < 5000; c4_i479++) {
    c4_newBmls[c4_i479] = c4_bmls[c4_i479];
  }

  c4_updateDataWrittenToVector(chartInstance, 27U);
  _SFD_EML_CALL(14U, chartInstance->c4_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static boolean_T c4_isequal(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  real_T c4_varargin_1[1000], real_T c4_varargin_2[1000])
{
  boolean_T c4_p;
  boolean_T c4_b_p;
  int32_T c4_k;
  real_T c4_b_k;
  real_T c4_x1;
  real_T c4_x2;
  boolean_T c4_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c4_p = false;
  c4_b_p = true;
  c4_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c4_k < 1000)) {
    c4_b_k = 1.0 + (real_T)c4_k;
    c4_x1 = c4_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c4_b_k), 1, 1000, 1, 0) - 1];
    c4_x2 = c4_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c4_b_k), 1, 1000, 1, 0) - 1];
    c4_c_p = (c4_x1 == c4_x2);
    if (!c4_c_p) {
      c4_b_p = false;
      exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (!c4_b_p) {
  } else {
    c4_p = true;
  }

  return c4_p;
}

void sf_exported_user_c4_Expriment_Emotion_insertQueue(SimStruct *c4_S, real_T
  c4_bmls[5000], real_T c4_myBML[1000], real_T c4_newBmls[5000])
{
  int32_T c4_i480;
  real_T c4_b_bmls[5000];
  int32_T c4_i481;
  real_T c4_b_myBML[1000];
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  for (c4_i480 = 0; c4_i480 < 5000; c4_i480++) {
    c4_b_bmls[c4_i480] = c4_bmls[c4_i480];
  }

  for (c4_i481 = 0; c4_i481 < 1000; c4_i481++) {
    c4_b_myBML[c4_i481] = c4_myBML[c4_i481];
  }

  c4_insertQueuec4_Expriment_Emotion(chartInstance, c4_b_bmls, c4_b_myBML,
    c4_newBmls);
}

void sf_exported_user_c4_Expriment_Emotion_insertQueueLow(SimStruct *c4_S,
  real_T c4_bmls[5000], real_T c4_myBML[1000], real_T c4_newBmls[5000])
{
  int32_T c4_i482;
  real_T c4_b_bmls[5000];
  int32_T c4_i483;
  real_T c4_b_myBML[1000];
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  for (c4_i482 = 0; c4_i482 < 5000; c4_i482++) {
    c4_b_bmls[c4_i482] = c4_bmls[c4_i482];
  }

  for (c4_i483 = 0; c4_i483 < 1000; c4_i483++) {
    c4_b_myBML[c4_i483] = c4_myBML[c4_i483];
  }

  c4_insertQueueLowc4_Expriment_Emotion(chartInstance, c4_b_bmls, c4_b_myBML,
    c4_newBmls);
}

void sf_exported_user_c4_Expriment_Emotion_selfAdaptorTableBilly(SimStruct *c4_S,
  real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000])
{
  real_T c4_b_pr;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_selfAdaptorTableBillyc4_Expriment_Emotion(chartInstance, c4_bmlID, &c4_b_pr,
    c4_poseBML);
  *c4_pr = c4_b_pr;
}

real_T sf_exported_user_c4_Expriment_Emotion_selfAdaptorTypeTable(SimStruct
  *c4_S, real_T c4_poseSpeed, real_T c4_poseTwitch)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  return c4_selfAdaptorTypeTablec4_Expriment_Emotion(chartInstance, c4_poseSpeed,
    c4_poseTwitch);
}

void sf_exported_user_c4_Expriment_Emotion_selfAdaptor_TwitchTable(SimStruct
  *c4_S, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000])
{
  real_T c4_b_pr;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_selfAdaptor_TwitchTablec4_Expriment_Emotion(chartInstance, c4_bmlID,
    &c4_b_pr, c4_poseBML);
  *c4_pr = c4_b_pr;
}

real_T sf_exported_user_c4_Expriment_Emotion_weightShiftTypeTable(SimStruct
  *c4_S, real_T c4_poseSpeed, real_T c4_spacious)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  return c4_weightShiftTypeTablec4_Expriment_Emotion(chartInstance, c4_poseSpeed,
    c4_spacious);
}

void sf_exported_user_c4_Expriment_Emotion_weightshift_SpaceTable(SimStruct
  *c4_S, real_T c4_bmlID, real_T *c4_pr, real_T c4_poseBML[1000])
{
  real_T c4_b_pr;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c4_S))->instanceInfo)->chartInstance;
  c4_weightshift_SpaceTablec4_Expriment_Emotion(chartInstance, c4_bmlID,
    &c4_b_pr, c4_poseBML);
  *c4_pr = c4_b_pr;
}

static const mxArray *c4_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int8_T c4_j_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int8_T c4_y;
  int8_T c4_i484;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i484, 1, 2, 0U, 0, 0U, 0);
  c4_y = c4_i484;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_secs;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int8_T c4_y;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_secs = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_secs), &c4_thisId);
  sf_mex_destroy(&c4_secs);
  *(int8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_k_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i485;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i485, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i485;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_l_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_tp_idlePoseGenerate, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_tp_idlePoseGenerate), &c4_thisId);
  sf_mex_destroy(&c4_b_tp_idlePoseGenerate);
  return c4_y;
}

static uint8_T c4_m_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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

static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_idlePoseGenerate;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_b_tp_idlePoseGenerate = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_tp_idlePoseGenerate), &c4_thisId);
  sf_mex_destroy(&c4_b_tp_idlePoseGenerate);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i486;
  real_T c4_b_inData[40];
  int32_T c4_i487;
  real_T c4_u[40];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i486 = 0; c4_i486 < 40; c4_i486++) {
    c4_b_inData[c4_i486] = (*(real_T (*)[40])c4_inData)[c4_i486];
  }

  for (c4_i487 = 0; c4_i487 < 40; c4_i487++) {
    c4_u[c4_i487] = c4_b_inData[c4_i487];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 40), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i488;
  real_T c4_b_inData[6];
  int32_T c4_i489;
  real_T c4_u[6];
  const mxArray *c4_y = NULL;
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i488 = 0; c4_i488 < 6; c4_i488++) {
    c4_b_inData[c4_i488] = (*(real_T (*)[6])c4_inData)[c4_i488];
  }

  for (c4_i489 = 0; c4_i489 < 6; c4_i489++) {
    c4_u[c4_i489] = c4_b_inData[c4_i489];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 6), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint32_T c4_n_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_method, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_method),
    &c4_thisId);
  sf_mex_destroy(&c4_b_method);
  return c4_y;
}

static uint32_T c4_o_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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

static uint32_T c4_p_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId);
  sf_mex_destroy(&c4_d_state);
  return c4_y;
}

static uint32_T c4_q_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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

static void c4_r_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[625])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_s_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[625])
{
  uint32_T c4_uv3[625];
  int32_T c4_i490;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_c_state_not_empty = false;
  } else {
    chartInstance->c4_c_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c4_i490 = 0; c4_i490 < 625; c4_i490++) {
      c4_y[c4_i490] = c4_uv3[c4_i490];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_t_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_d_state, const char_T *c4_identifier,
  uint32_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_d_state), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_d_state);
}

static void c4_u_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  uint32_T c4_y[2])
{
  uint32_T c4_uv4[2];
  int32_T c4_i491;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_b_state_not_empty = false;
  } else {
    chartInstance->c4_b_state_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c4_i491 = 0; c4_i491 < 2; c4_i491++) {
      c4_y[c4_i491] = c4_uv4[c4_i491];
    }
  }

  sf_mex_destroy(&c4_u);
}

static uint32_T c4_v_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_temporalCounter_i1, const char_T
  *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_temporalCounter_i1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_temporalCounter_i1);
  return c4_y;
}

static uint32_T c4_w_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u6;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u6, 1, 7, 0U, 0, 0U, 0);
  c4_y = c4_u6;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *c4_x_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  sf_mex_assign(&c4_y, c4_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_y_emlrt_marshallIn(SFc4_Expriment_EmotionInstanceStruct
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

static void c4_updateDataWrittenToVector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex)
{
  (void)chartInstance;
  c4_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c4_vectorIndex, 0, 27, 1, 0)] = true;
}

static void c4_errorIfDataNotWrittenToFcn(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_vectorIndex, uint32_T c4_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c4_dataNumber, c4_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c4_vectorIndex, 0, 27, 1,
    0)]);
}

static void c4_b_twister_state_vector(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_mt[625], real_T c4_seed)
{
  real_T c4_d5;
  uint32_T c4_u7;
  uint32_T c4_r;
  int32_T c4_mti;
  real_T c4_b_mti;
  real_T c4_d6;
  uint32_T c4_u8;
  (void)chartInstance;
  c4_d5 = c4_seed;
  if (c4_d5 < 4.294967296E+9) {
    if (c4_d5 >= 0.0) {
      c4_u7 = (uint32_T)c4_d5;
    } else {
      c4_u7 = 0U;
    }
  } else if (c4_d5 >= 4.294967296E+9) {
    c4_u7 = MAX_uint32_T;
  } else {
    c4_u7 = 0U;
  }

  c4_r = c4_u7;
  c4_mt[0] = c4_r;
  for (c4_mti = 0; c4_mti < 623; c4_mti++) {
    c4_b_mti = 2.0 + (real_T)c4_mti;
    c4_d6 = muDoubleScalarRound(c4_b_mti - 1.0);
    if (c4_d6 < 4.294967296E+9) {
      if (c4_d6 >= 0.0) {
        c4_u8 = (uint32_T)c4_d6;
      } else {
        c4_u8 = 0U;
      }
    } else if (c4_d6 >= 4.294967296E+9) {
      c4_u8 = MAX_uint32_T;
    } else {
      c4_u8 = 0U;
    }

    c4_r = (c4_r ^ c4_r >> 30U) * 1812433253U + c4_u8;
    c4_mt[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c4_b_mti), 1, 625, 1, 0) - 1] = c4_r;
  }

  c4_mt[624] = 624U;
}

static real_T c4_c_eml_rand_mt19937ar(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_d_state[625])
{
  int32_T c4_i492;
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
  boolean_T c4_b11;
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
    for (c4_i492 = 0; c4_i492 < 2; c4_i492++) {
      c4_u[c4_i492] = 0U;
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
          c4_b11 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        c4_b11 = false;
      }

      c4_isvalid = c4_b11;
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

static real_T c4_get_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#311) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_BML_address)[c4_b];
}

static void c4_set_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c4_b);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#311) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_BML_address)[c4_b] = c4_c;
}

static real_T *c4_access_BML(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c4_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#311) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_BML_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c4_c;
}

static real_T c4_get_BORED(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#306) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_BORED_address;
}

static void c4_set_BORED(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c4_b);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#306) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_BORED_address = c4_c;
}

static real_T *c4_access_BORED(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c4_BORED_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BORED\' (#306) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_BORED_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c4_c;
}

static real_T c4_get_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#293) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_BOREDOM_THRESHOLD_address;
}

static void c4_set_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c4_b);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#293) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_BOREDOM_THRESHOLD_address = c4_c;
}

static real_T *c4_access_BOREDOM_THRESHOLD(SFc4_Expriment_EmotionInstanceStruct *
  chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c4_BOREDOM_THRESHOLD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOM_THRESHOLD\' (#293) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_BOREDOM_THRESHOLD_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c4_c;
}

static real_T c4_get_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#305) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_CONTEMPT_address;
}

static void c4_set_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c4_b);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#305) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_CONTEMPT_address = c4_c;
}

static real_T *c4_access_CONTEMPT(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c4_CONTEMPT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'CONTEMPT\' (#305) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_CONTEMPT_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c4_c;
}

static real_T c4_get_EXCITE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#310) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_EXCITE_address;
}

static void c4_set_EXCITE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c4_b);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#310) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_EXCITE_address = c4_c;
}

static real_T *c4_access_EXCITE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c4_EXCITE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'EXCITE\' (#310) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_EXCITE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c4_c;
}

static real_T c4_get_FEAR(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#308) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_FEAR_address;
}

static void c4_set_FEAR(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c4_b);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#308) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_FEAR_address = c4_c;
}

static real_T *c4_access_FEAR(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c4_FEAR_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FEAR\' (#308) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_FEAR_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c4_c;
}

static real_T c4_get_FRUST(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#307) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_FRUST_address;
}

static void c4_set_FRUST(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c4_b);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#307) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_FRUST_address = c4_c;
}

static real_T *c4_access_FRUST(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c4_FRUST_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'FRUST\' (#307) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_FRUST_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c4_c;
}

static real_T c4_get_HAPPY(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#303) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_HAPPY_address;
}

static void c4_set_HAPPY(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c4_b);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#303) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_HAPPY_address = c4_c;
}

static real_T *c4_access_HAPPY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c4_HAPPY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'HAPPY\' (#303) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_HAPPY_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c4_c;
}

static real_T c4_get_IDLE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#309) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_IDLE_address;
}

static void c4_set_IDLE(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c4_b);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#309) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_IDLE_address = c4_c;
}

static real_T *c4_access_IDLE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c4_IDLE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'IDLE\' (#309) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_IDLE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c4_c;
}

static real_T c4_get_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#312) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_P_address;
}

static void c4_set_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
                     uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c4_b);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#312) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_P_address = c4_c;
}

static real_T *c4_access_P(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c4_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#312) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_P_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c4_c;
}

static real_T c4_get_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#304) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_SAD_address;
}

static void c4_set_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c4_b);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#304) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_SAD_address = c4_c;
}

static real_T *c4_access_SAD(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c4_SAD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'SAD\' (#304) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_SAD_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#299) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_BEFORE_address;
}

static void c4_set_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c4_b);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#299) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_BEFORE_address = c4_c;
}

static real_T *c4_access_STATE_BEFORE(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c4_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#299) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_BEFORE_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_GO(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#314) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_GO_address;
}

static void c4_set_STATE_GO(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c4_b);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#314) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_GO_address = c4_c;
}

static real_T *c4_access_STATE_GO(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c4_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#314) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_GO_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#298) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_OVER_address;
}

static void c4_set_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c4_b);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#298) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_OVER_address = c4_c;
}

static real_T *c4_access_STATE_OVER(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c4_STATE_OVER_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_OVER\' (#298) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_OVER_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c4_c;
}

static real_T c4_get_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#300) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_STATE_READY_address;
}

static void c4_set_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c4_b);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#300) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_STATE_READY_address = c4_c;
}

static real_T *c4_access_STATE_READY(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c4_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#300) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_STATE_READY_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c4_c;
}

static real_T c4_get_bmlsL(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#318) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_bmlsL_address)[c4_b];
}

static void c4_set_bmlsL(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c4_b);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#318) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_bmlsL_address)[c4_b] = c4_c;
}

static real_T *c4_access_bmlsL(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c4_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#318) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_bmlsL_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c4_c;
}

static real_T c4_get_bmlsM(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#332) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c4_bmlsM_address)[c4_b];
}

static void c4_set_bmlsM(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c4_b);
  if (chartInstance->c4_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#332) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c4_bmlsM_address)[c4_b] = c4_c;
}

static real_T *c4_access_bmlsM(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c4_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#332) in the initialization routine of the chart.\n");
  }

  c4_c = *chartInstance->c4_bmlsM_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c4_c;
}

static real_T c4_get_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c4_b);
  if (chartInstance->c4_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#315) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_bodyBusyFlag_address;
}

static void c4_set_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c4_b);
  if (chartInstance->c4_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#315) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_bodyBusyFlag_address = c4_c;
}

static real_T *c4_access_bodyBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c4_bodyBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bodyBusyFlag\' (#315) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_bodyBusyFlag_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c4_c;
}

static real_T c4_get_boredom(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#292) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_boredom_address;
}

static void c4_set_boredom(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c4_b);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#292) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_boredom_address = c4_c;
}

static real_T *c4_access_boredom(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c4_boredom_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'boredom\' (#292) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_boredom_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c4_c;
}

static real_T c4_get_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 19, NULL, c4_b);
  if (chartInstance->c4_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#336) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_faceBusyFlag_address;
}

static void c4_set_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 19, NULL, c4_b);
  if (chartInstance->c4_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#336) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_faceBusyFlag_address = c4_c;
}

static real_T *c4_access_faceBusyFlag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 19, NULL);
  if (chartInstance->c4_faceBusyFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'faceBusyFlag\' (#336) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_faceBusyFlag_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 19, NULL);
  }

  return c4_c;
}

static real_T c4_get_fileID(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 20, NULL, c4_b);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#313) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_fileID_address;
}

static void c4_set_fileID(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 20, NULL, c4_b);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#313) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_fileID_address = c4_c;
}

static real_T *c4_access_fileID(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 20, NULL);
  if (chartInstance->c4_fileID_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'fileID\' (#313) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_fileID_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 20, NULL);
  }

  return c4_c;
}

static real_T c4_get_interest(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 21, NULL, c4_b);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#295) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_interest_address;
}

static void c4_set_interest(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 21, NULL, c4_b);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#295) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_interest_address = c4_c;
}

static real_T *c4_access_interest(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 21, NULL);
  if (chartInstance->c4_interest_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'interest\' (#295) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_interest_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 21, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 22, NULL, c4_b);
  if (chartInstance->c4_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#343) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_cat_chance_address;
}

static void c4_set_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 22, NULL, c4_b);
  if (chartInstance->c4_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#343) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_cat_chance_address = c4_c;
}

static real_T *c4_access_pose_cat_chance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 22, NULL);
  if (chartInstance->c4_pose_cat_chance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_cat_chance\' (#343) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_cat_chance_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 22, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 23, NULL, c4_b);
  if (chartInstance->c4_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#342) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_chance_factor_address;
}

static void c4_set_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 23, NULL, c4_b);
  if (chartInstance->c4_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#342) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_chance_factor_address = c4_c;
}

static real_T *c4_access_pose_chance_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 23, NULL);
  if (chartInstance->c4_pose_chance_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_chance_factor\' (#342) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_chance_factor_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 23, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 24, NULL, c4_b);
  if (chartInstance->c4_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#344) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_change_flag_address;
}

static void c4_set_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 24, NULL, c4_b);
  if (chartInstance->c4_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#344) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_change_flag_address = c4_c;
}

static real_T *c4_access_pose_change_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 24, NULL);
  if (chartInstance->c4_pose_change_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_change_flag\' (#344) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_change_flag_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 24, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_frequency_factor(SFc4_Expriment_EmotionInstanceStruct *
  chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 25, NULL, c4_b);
  if (chartInstance->c4_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#341) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_frequency_factor_address;
}

static void c4_set_pose_frequency_factor(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 25, NULL, c4_b);
  if (chartInstance->c4_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#341) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_frequency_factor_address = c4_c;
}

static real_T *c4_access_pose_frequency_factor
  (SFc4_Expriment_EmotionInstanceStruct *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 25, NULL);
  if (chartInstance->c4_pose_frequency_factor_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_frequency_factor\' (#341) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_frequency_factor_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 25, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_lean(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 26, NULL, c4_b);
  if (chartInstance->c4_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#340) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_lean_address;
}

static void c4_set_pose_lean(SFc4_Expriment_EmotionInstanceStruct *chartInstance,
  uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 26, NULL, c4_b);
  if (chartInstance->c4_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#340) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_lean_address = c4_c;
}

static real_T *c4_access_pose_lean(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 26, NULL);
  if (chartInstance->c4_pose_lean_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean\' (#340) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_lean_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 26, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 27, NULL, c4_b);
  if (chartInstance->c4_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#339) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_lean_flag_address;
}

static void c4_set_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 27, NULL, c4_b);
  if (chartInstance->c4_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#339) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_lean_flag_address = c4_c;
}

static real_T *c4_access_pose_lean_flag(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 27, NULL);
  if (chartInstance->c4_pose_lean_flag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_lean_flag\' (#339) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_lean_flag_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 27, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 28, NULL, c4_b);
  if (chartInstance->c4_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#1487) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_space_address;
}

static void c4_set_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 28, NULL, c4_b);
  if (chartInstance->c4_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#1487) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_space_address = c4_c;
}

static real_T *c4_access_pose_space(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 28, NULL);
  if (chartInstance->c4_pose_space_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_space\' (#1487) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_space_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 28, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 29, NULL, c4_b);
  if (chartInstance->c4_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#338) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_speed_address;
}

static void c4_set_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 29, NULL, c4_b);
  if (chartInstance->c4_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#338) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_speed_address = c4_c;
}

static real_T *c4_access_pose_speed(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 29, NULL);
  if (chartInstance->c4_pose_speed_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_speed\' (#338) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_speed_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 29, NULL);
  }

  return c4_c;
}

static real_T c4_get_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 30, NULL, c4_b);
  if (chartInstance->c4_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#346) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_pose_twitch_address;
}

static void c4_set_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 30, NULL, c4_b);
  if (chartInstance->c4_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#346) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_pose_twitch_address = c4_c;
}

static real_T *c4_access_pose_twitch(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 30, NULL);
  if (chartInstance->c4_pose_twitch_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose_twitch\' (#346) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_pose_twitch_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 30, NULL);
  }

  return c4_c;
}

static real_T c4_get_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 31, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#297) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randPoseChance_address;
}

static void c4_set_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 31, NULL, c4_b);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#297) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randPoseChance_address = c4_c;
}

static real_T *c4_access_randPoseChance(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 31, NULL);
  if (chartInstance->c4_randPoseChance_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randPoseChance\' (#297) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randPoseChance_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 31, NULL);
  }

  return c4_c;
}

static real_T c4_get_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 32, NULL, c4_b);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#294) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c4_randSlowPose_address;
}

static void c4_set_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b, real_T c4_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 32, NULL, c4_b);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#294) in the initialization routine of the chart.\n");
  }

  *chartInstance->c4_randSlowPose_address = c4_c;
}

static real_T *c4_access_randSlowPose(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance, uint32_T c4_b)
{
  real_T *c4_c;
  ssReadFromDataStore(chartInstance->S, 32, NULL);
  if (chartInstance->c4_randSlowPose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randSlowPose\' (#294) in the initialization routine of the chart.\n");
  }

  c4_c = chartInstance->c4_randSlowPose_address;
  if (c4_b == 0) {
    ssWriteToDataStore(chartInstance->S, 32, NULL);
  }

  return c4_c;
}

static void init_dsm_address_info(SFc4_Expriment_EmotionInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c4_BML_address, &chartInstance->c4_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BORED", (void **)
    &chartInstance->c4_BORED_address, &chartInstance->c4_BORED_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOM_THRESHOLD", (void **)
    &chartInstance->c4_BOREDOM_THRESHOLD_address,
    &chartInstance->c4_BOREDOM_THRESHOLD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "CONTEMPT", (void **)
    &chartInstance->c4_CONTEMPT_address, &chartInstance->c4_CONTEMPT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "EXCITE", (void **)
    &chartInstance->c4_EXCITE_address, &chartInstance->c4_EXCITE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FEAR", (void **)
    &chartInstance->c4_FEAR_address, &chartInstance->c4_FEAR_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "FRUST", (void **)
    &chartInstance->c4_FRUST_address, &chartInstance->c4_FRUST_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "HAPPY", (void **)
    &chartInstance->c4_HAPPY_address, &chartInstance->c4_HAPPY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "IDLE", (void **)
    &chartInstance->c4_IDLE_address, &chartInstance->c4_IDLE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c4_P_address, &chartInstance->c4_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "SAD", (void **)
    &chartInstance->c4_SAD_address, &chartInstance->c4_SAD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c4_STATE_BEFORE_address,
    &chartInstance->c4_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c4_STATE_GO_address, &chartInstance->c4_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_OVER", (void **)
    &chartInstance->c4_STATE_OVER_address, &chartInstance->c4_STATE_OVER_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c4_STATE_READY_address, &chartInstance->c4_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c4_bmlsL_address, &chartInstance->c4_bmlsL_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c4_bmlsM_address, &chartInstance->c4_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bodyBusyFlag", (void **)
    &chartInstance->c4_bodyBusyFlag_address,
    &chartInstance->c4_bodyBusyFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "boredom", (void **)
    &chartInstance->c4_boredom_address, &chartInstance->c4_boredom_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "faceBusyFlag", (void **)
    &chartInstance->c4_faceBusyFlag_address,
    &chartInstance->c4_faceBusyFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "fileID", (void **)
    &chartInstance->c4_fileID_address, &chartInstance->c4_fileID_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "interest", (void **)
    &chartInstance->c4_interest_address, &chartInstance->c4_interest_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_cat_chance", (void **)
    &chartInstance->c4_pose_cat_chance_address,
    &chartInstance->c4_pose_cat_chance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_chance_factor", (void **)
    &chartInstance->c4_pose_chance_factor_address,
    &chartInstance->c4_pose_chance_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_change_flag", (void **)
    &chartInstance->c4_pose_change_flag_address,
    &chartInstance->c4_pose_change_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_frequency_factor", (void
    **)&chartInstance->c4_pose_frequency_factor_address,
    &chartInstance->c4_pose_frequency_factor_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean", (void **)
    &chartInstance->c4_pose_lean_address, &chartInstance->c4_pose_lean_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_lean_flag", (void **)
    &chartInstance->c4_pose_lean_flag_address,
    &chartInstance->c4_pose_lean_flag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_space", (void **)
    &chartInstance->c4_pose_space_address, &chartInstance->c4_pose_space_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_speed", (void **)
    &chartInstance->c4_pose_speed_address, &chartInstance->c4_pose_speed_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose_twitch", (void **)
    &chartInstance->c4_pose_twitch_address, &chartInstance->c4_pose_twitch_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randPoseChance", (void **)
    &chartInstance->c4_randPoseChance_address,
    &chartInstance->c4_randPoseChance_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randSlowPose", (void **)
    &chartInstance->c4_randSlowPose_address,
    &chartInstance->c4_randSlowPose_index);
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

void sf_c4_Expriment_Emotion_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(317020653U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2580291345U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(164750699U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1904129422U);
}

mxArray *sf_c4_Expriment_Emotion_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WPqCXfQrnIQxBvW9VXIH5E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[1] = (double)(40);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
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

    mxArray *mxData = mxCreateStructMatrix(1,17,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
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
      pr[0] = (double)(1000);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_Expriment_Emotion_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_Expriment_Emotion_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_Expriment_Emotion(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[40],T\"gameState\",},{M[3],M[141],T\"BMLM\",},{M[3],M[307],T\"BMLl\",},{M[3],M[283],T\"catChance\",},{M[3],M[261],T\"leanPose\",},{M[3],M[144],T\"n\",},{M[3],M[142],T\"newBmlsL\",},{M[3],M[308],T\"newBmlsM\",},{M[3],M[490],T\"oldPose\",},{M[3],M[282],T\"pCatChance\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[325],T\"pChangeFlag\",},{M[3],M[259],T\"pPoseChance\",},{M[3],M[274],T\"pPoseChanceP\",},{M[3],M[260],T\"poseFreq\",},{M[3],M[275],T\"poseFreqP\",},{M[3],M[489],T\"poseNum\",},{M[3],M[463],T\"pose_type\",},{M[3],M[223],T\"randPR\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mcg16807_stateful.m\"}}}}",
    "100 S1x6'type','srcId','name','auxInfo'{{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"C:\\MATLAB\\R2014a32\\toolbox\\eml\\lib\\matlab\\randfun\\eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c4_Expriment_Emotion\",},{M[8],M[318],T\"is_active_idlePoseGenerate\",},{M[9],M[318],T\"is_idlePoseGenerate\",},{M[11],M[16],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[286 476 475],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 26, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Expriment_Emotion_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Expriment_EmotionInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_EmotionMachineNumber_,
           4,
           21,
           36,
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
        init_script_number_translation(_Expriment_EmotionMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_EmotionMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_EmotionMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"boredom");
          _SFD_SET_DATA_PROPS(1,11,0,0,"BOREDOM_THRESHOLD");
          _SFD_SET_DATA_PROPS(2,11,0,0,"randSlowPose");
          _SFD_SET_DATA_PROPS(3,11,0,0,"interest");
          _SFD_SET_DATA_PROPS(4,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(5,11,0,0,"randPoseChance");
          _SFD_SET_DATA_PROPS(6,11,0,0,"STATE_OVER");
          _SFD_SET_DATA_PROPS(7,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(8,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(9,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(10,1,1,0,"inE");
          _SFD_SET_DATA_PROPS(11,11,0,0,"HAPPY");
          _SFD_SET_DATA_PROPS(12,11,0,0,"SAD");
          _SFD_SET_DATA_PROPS(13,11,0,0,"CONTEMPT");
          _SFD_SET_DATA_PROPS(14,11,0,0,"BORED");
          _SFD_SET_DATA_PROPS(15,11,0,0,"FRUST");
          _SFD_SET_DATA_PROPS(16,11,0,0,"FEAR");
          _SFD_SET_DATA_PROPS(17,11,0,0,"IDLE");
          _SFD_SET_DATA_PROPS(18,11,0,0,"EXCITE");
          _SFD_SET_DATA_PROPS(19,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(20,11,0,0,"P");
          _SFD_SET_DATA_PROPS(21,11,0,0,"fileID");
          _SFD_SET_DATA_PROPS(22,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(23,11,0,0,"bodyBusyFlag");
          _SFD_SET_DATA_PROPS(24,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(25,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(26,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(27,0,0,0,"n");
          _SFD_SET_DATA_PROPS(28,1,1,0,"randArray");
          _SFD_SET_DATA_PROPS(29,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(30,0,0,0,"randPR");
          _SFD_SET_DATA_PROPS(31,0,0,0,"pPoseChance");
          _SFD_SET_DATA_PROPS(32,0,0,0,"poseFreq");
          _SFD_SET_DATA_PROPS(33,0,0,0,"leanPose");
          _SFD_SET_DATA_PROPS(34,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(35,0,0,0,"pPoseChanceP");
          _SFD_SET_DATA_PROPS(36,0,0,0,"poseFreqP");
          _SFD_SET_DATA_PROPS(37,0,0,0,"pCatChance");
          _SFD_SET_DATA_PROPS(38,0,0,0,"catChance");
          _SFD_SET_DATA_PROPS(39,1,1,0,"personalityChange");
          _SFD_SET_DATA_PROPS(40,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(41,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(42,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(43,0,0,0,"pChangeFlag");
          _SFD_SET_DATA_PROPS(44,11,0,0,"faceBusyFlag");
          _SFD_SET_DATA_PROPS(45,1,1,0,"poseArray");
          _SFD_SET_DATA_PROPS(46,11,0,0,"pose_speed");
          _SFD_SET_DATA_PROPS(47,11,0,0,"pose_lean_flag");
          _SFD_SET_DATA_PROPS(48,11,0,0,"pose_lean");
          _SFD_SET_DATA_PROPS(49,11,0,0,"pose_frequency_factor");
          _SFD_SET_DATA_PROPS(50,11,0,0,"pose_chance_factor");
          _SFD_SET_DATA_PROPS(51,11,0,0,"pose_cat_chance");
          _SFD_SET_DATA_PROPS(52,11,0,0,"pose_change_flag");
          _SFD_SET_DATA_PROPS(53,0,0,0,"pose_type");
          _SFD_SET_DATA_PROPS(54,11,0,0,"pose_twitch");
          _SFD_SET_DATA_PROPS(55,11,0,0,"pose_space");
          _SFD_SET_DATA_PROPS(56,0,0,0,"poseNum");
          _SFD_SET_DATA_PROPS(57,0,0,0,"oldPose");
          _SFD_SET_DATA_PROPS(58,8,0,0,"");
          _SFD_SET_DATA_PROPS(59,9,0,0,"");
          _SFD_SET_DATA_PROPS(60,9,0,0,"");
          _SFD_SET_DATA_PROPS(61,8,0,0,"");
          _SFD_SET_DATA_PROPS(62,9,0,0,"");
          _SFD_SET_DATA_PROPS(63,9,0,0,"");
          _SFD_SET_DATA_PROPS(64,9,0,0,"");
          _SFD_SET_DATA_PROPS(65,8,0,0,"");
          _SFD_SET_DATA_PROPS(66,9,0,0,"");
          _SFD_SET_DATA_PROPS(67,8,0,0,"");
          _SFD_SET_DATA_PROPS(68,9,0,0,"");
          _SFD_SET_DATA_PROPS(69,8,0,0,"");
          _SFD_SET_DATA_PROPS(70,8,0,0,"");
          _SFD_SET_DATA_PROPS(71,8,0,0,"");
          _SFD_SET_DATA_PROPS(72,9,0,0,"");
          _SFD_SET_DATA_PROPS(73,8,0,0,"");
          _SFD_SET_DATA_PROPS(74,8,0,0,"");
          _SFD_SET_DATA_PROPS(75,9,0,0,"");
          _SFD_SET_DATA_PROPS(76,8,0,0,"");
          _SFD_SET_DATA_PROPS(77,8,0,0,"");
          _SFD_SET_DATA_PROPS(78,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,2);
          _SFD_STATE_INFO(15,0,2);
          _SFD_STATE_INFO(16,0,2);
          _SFD_STATE_INFO(17,0,2);
          _SFD_STATE_INFO(18,0,2);
          _SFD_STATE_INFO(19,0,2);
          _SFD_STATE_INFO(20,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,13);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_INDEX(0,4,5);
          _SFD_ST_SUBSTATE_INDEX(0,5,6);
          _SFD_ST_SUBSTATE_INDEX(0,6,7);
          _SFD_ST_SUBSTATE_INDEX(0,7,8);
          _SFD_ST_SUBSTATE_INDEX(0,8,9);
          _SFD_ST_SUBSTATE_INDEX(0,9,10);
          _SFD_ST_SUBSTATE_INDEX(0,10,11);
          _SFD_ST_SUBSTATE_INDEX(0,11,12);
          _SFD_ST_SUBSTATE_INDEX(0,12,13);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,13,1,1,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(16,1,21,20,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(16,0,"selfAdaptorTableBillyc4_Expriment_Emotion",0,
                             -1,3135);
        _SFD_CV_INIT_EML_FCN(16,1,"aFcnTruthTableAction_1",3135,-1,3322);
        _SFD_CV_INIT_EML_FCN(16,2,"aFcnTruthTableAction_2",3322,-1,3507);
        _SFD_CV_INIT_EML_FCN(16,3,"aFcnTruthTableAction_3",3507,-1,3704);
        _SFD_CV_INIT_EML_FCN(16,4,"aFcnTruthTableAction_4",3704,-1,3890);
        _SFD_CV_INIT_EML_FCN(16,5,"aFcnTruthTableAction_5",3890,-1,4086);
        _SFD_CV_INIT_EML_FCN(16,6,"aFcnTruthTableAction_6",4086,-1,4271);
        _SFD_CV_INIT_EML_FCN(16,7,"aFcnTruthTableAction_7",4271,-1,4457);
        _SFD_CV_INIT_EML_FCN(16,8,"aFcnTruthTableAction_8",4457,-1,4860);
        _SFD_CV_INIT_EML_FCN(16,9,"aFcnTruthTableAction_9",4860,-1,5259);
        _SFD_CV_INIT_EML_FCN(16,10,"aFcnTruthTableAction_10",5259,-1,5459);
        _SFD_CV_INIT_EML_FCN(16,11,"aFcnTruthTableAction_11",5459,-1,5648);
        _SFD_CV_INIT_EML_FCN(16,12,"aFcnTruthTableAction_12",5648,-1,5836);
        _SFD_CV_INIT_EML_FCN(16,13,"aFcnTruthTableAction_13",5836,-1,6030);
        _SFD_CV_INIT_EML_FCN(16,14,"aFcnTruthTableAction_14",6030,-1,6218);
        _SFD_CV_INIT_EML_FCN(16,15,"aFcnTruthTableAction_15",6218,-1,6411);
        _SFD_CV_INIT_EML_FCN(16,16,"aFcnTruthTableAction_16",6411,-1,6612);
        _SFD_CV_INIT_EML_FCN(16,17,"aFcnTruthTableAction_17",6612,-1,6801);
        _SFD_CV_INIT_EML_FCN(16,18,"aFcnTruthTableAction_18",6801,-1,7195);
        _SFD_CV_INIT_EML_FCN(16,19,"aFcnTruthTableAction_19",7195,-1,7598);
        _SFD_CV_INIT_EML_FCN(16,20,"aFcnTruthTableAction_20",7598,-1,7999);
        _SFD_CV_INIT_EML_IF(16,1,0,1767,1797,1828,3133);
        _SFD_CV_INIT_EML_IF(16,1,1,1828,1862,1893,3133);
        _SFD_CV_INIT_EML_IF(16,1,2,1893,1927,1958,3133);
        _SFD_CV_INIT_EML_IF(16,1,3,1958,1992,2023,3133);
        _SFD_CV_INIT_EML_IF(16,1,4,2023,2057,2088,3133);
        _SFD_CV_INIT_EML_IF(16,1,5,2088,2122,2153,3133);
        _SFD_CV_INIT_EML_IF(16,1,6,2153,2187,2218,3133);
        _SFD_CV_INIT_EML_IF(16,1,7,2218,2252,2283,3133);
        _SFD_CV_INIT_EML_IF(16,1,8,2283,2317,2348,3133);
        _SFD_CV_INIT_EML_IF(16,1,9,2348,2383,2415,3133);
        _SFD_CV_INIT_EML_IF(16,1,10,2415,2450,2482,3133);
        _SFD_CV_INIT_EML_IF(16,1,11,2482,2517,2549,3133);
        _SFD_CV_INIT_EML_IF(16,1,12,2549,2584,2616,3133);
        _SFD_CV_INIT_EML_IF(16,1,13,2616,2651,2683,3133);
        _SFD_CV_INIT_EML_IF(16,1,14,2683,2718,2750,3133);
        _SFD_CV_INIT_EML_IF(16,1,15,2750,2785,2817,3133);
        _SFD_CV_INIT_EML_IF(16,1,16,2817,2852,2884,3133);
        _SFD_CV_INIT_EML_IF(16,1,17,2884,2919,2951,3133);
        _SFD_CV_INIT_EML_IF(16,1,18,2951,2986,3018,3133);
        _SFD_CV_INIT_EML_IF(16,1,19,3018,3053,3085,3133);
        _SFD_CV_INIT_EML(18,1,20,19,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(18,0,"selfAdaptor_TwitchTablec4_Expriment_Emotion",
                             0,-1,2983);
        _SFD_CV_INIT_EML_FCN(18,1,"aFcnTruthTableAction_1",2983,-1,3174);
        _SFD_CV_INIT_EML_FCN(18,2,"aFcnTruthTableAction_2",3174,-1,3375);
        _SFD_CV_INIT_EML_FCN(18,3,"aFcnTruthTableAction_3",3375,-1,3565);
        _SFD_CV_INIT_EML_FCN(18,4,"aFcnTruthTableAction_4",3565,-1,3752);
        _SFD_CV_INIT_EML_FCN(18,5,"aFcnTruthTableAction_5",3752,-1,3941);
        _SFD_CV_INIT_EML_FCN(18,6,"aFcnTruthTableAction_6",3941,-1,4127);
        _SFD_CV_INIT_EML_FCN(18,7,"aFcnTruthTableAction_7",4127,-1,4314);
        _SFD_CV_INIT_EML_FCN(18,8,"aFcnTruthTableAction_8",4314,-1,4506);
        _SFD_CV_INIT_EML_FCN(18,9,"aFcnTruthTableAction_9",4506,-1,4692);
        _SFD_CV_INIT_EML_FCN(18,10,"aFcnTruthTableAction_10",4692,-1,4880);
        _SFD_CV_INIT_EML_FCN(18,11,"aFcnTruthTableAction_11",4880,-1,5069);
        _SFD_CV_INIT_EML_FCN(18,12,"aFcnTruthTableAction_12",5069,-1,5255);
        _SFD_CV_INIT_EML_FCN(18,13,"aFcnTruthTableAction_13",5255,-1,5443);
        _SFD_CV_INIT_EML_FCN(18,14,"aFcnTruthTableAction_14",5443,-1,5632);
        _SFD_CV_INIT_EML_FCN(18,15,"aFcnTruthTableAction_15",5632,-1,5831);
        _SFD_CV_INIT_EML_FCN(18,16,"aFcnTruthTableAction_16",5831,-1,6019);
        _SFD_CV_INIT_EML_FCN(18,17,"aFcnTruthTableAction_17",6019,-1,6206);
        _SFD_CV_INIT_EML_FCN(18,18,"aFcnTruthTableAction_18",6206,-1,6395);
        _SFD_CV_INIT_EML_FCN(18,19,"aFcnTruthTableAction_19",6395,-1,6577);
        _SFD_CV_INIT_EML_IF(18,1,0,1682,1712,1743,2981);
        _SFD_CV_INIT_EML_IF(18,1,1,1743,1777,1808,2981);
        _SFD_CV_INIT_EML_IF(18,1,2,1808,1842,1873,2981);
        _SFD_CV_INIT_EML_IF(18,1,3,1873,1907,1938,2981);
        _SFD_CV_INIT_EML_IF(18,1,4,1938,1972,2003,2981);
        _SFD_CV_INIT_EML_IF(18,1,5,2003,2037,2068,2981);
        _SFD_CV_INIT_EML_IF(18,1,6,2068,2102,2133,2981);
        _SFD_CV_INIT_EML_IF(18,1,7,2133,2167,2198,2981);
        _SFD_CV_INIT_EML_IF(18,1,8,2198,2232,2263,2981);
        _SFD_CV_INIT_EML_IF(18,1,9,2263,2298,2330,2981);
        _SFD_CV_INIT_EML_IF(18,1,10,2330,2365,2397,2981);
        _SFD_CV_INIT_EML_IF(18,1,11,2397,2432,2464,2981);
        _SFD_CV_INIT_EML_IF(18,1,12,2464,2499,2531,2981);
        _SFD_CV_INIT_EML_IF(18,1,13,2531,2566,2598,2981);
        _SFD_CV_INIT_EML_IF(18,1,14,2598,2633,2665,2981);
        _SFD_CV_INIT_EML_IF(18,1,15,2665,2700,2732,2981);
        _SFD_CV_INIT_EML_IF(18,1,16,2732,2767,2799,2981);
        _SFD_CV_INIT_EML_IF(18,1,17,2799,2834,2866,2981);
        _SFD_CV_INIT_EML_IF(18,1,18,2866,2901,2933,2981);
        _SFD_CV_INIT_EML(20,1,14,13,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(20,0,"weightshift_SpaceTablec4_Expriment_Emotion",0,
                             -1,2058);
        _SFD_CV_INIT_EML_FCN(20,1,"aFcnTruthTableAction_1",2058,-1,2267);
        _SFD_CV_INIT_EML_FCN(20,2,"aFcnTruthTableAction_2",2267,-1,2679);
        _SFD_CV_INIT_EML_FCN(20,3,"aFcnTruthTableAction_3",2679,-1,2926);
        _SFD_CV_INIT_EML_FCN(20,4,"aFcnTruthTableAction_4",2926,-1,3175);
        _SFD_CV_INIT_EML_FCN(20,5,"aFcnTruthTableAction_5",3175,-1,3362);
        _SFD_CV_INIT_EML_FCN(20,6,"aFcnTruthTableAction_6",3362,-1,3548);
        _SFD_CV_INIT_EML_FCN(20,7,"aFcnTruthTableAction_7",3548,-1,3750);
        _SFD_CV_INIT_EML_FCN(20,8,"aFcnTruthTableAction_8",3750,-1,3952);
        _SFD_CV_INIT_EML_FCN(20,9,"aFcnTruthTableAction_9",3952,-1,4139);
        _SFD_CV_INIT_EML_FCN(20,10,"aFcnTruthTableAction_10",4139,-1,4327);
        _SFD_CV_INIT_EML_FCN(20,11,"aFcnTruthTableAction_11",4327,-1,4530);
        _SFD_CV_INIT_EML_FCN(20,12,"aFcnTruthTableAction_12",4530,-1,4762);
        _SFD_CV_INIT_EML_FCN(20,13,"aFcnTruthTableAction_13",4762,-1,4993);
        _SFD_CV_INIT_EML_IF(20,1,0,1159,1189,1220,2056);
        _SFD_CV_INIT_EML_IF(20,1,1,1220,1254,1285,2056);
        _SFD_CV_INIT_EML_IF(20,1,2,1285,1319,1350,2056);
        _SFD_CV_INIT_EML_IF(20,1,3,1350,1384,1415,2056);
        _SFD_CV_INIT_EML_IF(20,1,4,1415,1449,1480,2056);
        _SFD_CV_INIT_EML_IF(20,1,5,1480,1514,1545,2056);
        _SFD_CV_INIT_EML_IF(20,1,6,1545,1579,1610,2056);
        _SFD_CV_INIT_EML_IF(20,1,7,1610,1644,1675,2056);
        _SFD_CV_INIT_EML_IF(20,1,8,1675,1709,1740,2056);
        _SFD_CV_INIT_EML_IF(20,1,9,1740,1775,1807,2056);
        _SFD_CV_INIT_EML_IF(20,1,10,1807,1842,1874,2056);
        _SFD_CV_INIT_EML_IF(20,1,11,1874,1909,1941,2056);
        _SFD_CV_INIT_EML_IF(20,1,12,1941,1976,2008,2056);
        _SFD_CV_INIT_EML(19,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(19,0,"weightShiftTypeTablec4_Expriment_Emotion",0,
                             -1,814);
        _SFD_CV_INIT_EML_FCN(19,1,"aFcnTruthTableAction_1",814,-1,879);
        _SFD_CV_INIT_EML_FCN(19,2,"aFcnTruthTableAction_2",879,-1,942);
        _SFD_CV_INIT_EML_FCN(19,3,"aFcnTruthTableAction_3",942,-1,1002);
        _SFD_CV_INIT_EML_FCN(19,4,"aFcnTruthTableAction_4",1002,-1,1063);
        _SFD_CV_INIT_EML_IF(19,1,0,508,538,569,812);
        _SFD_CV_INIT_EML_IF(19,1,1,569,603,634,812);
        _SFD_CV_INIT_EML_IF(19,1,2,634,668,699,812);
        _SFD_CV_INIT_EML_IF(19,1,3,699,733,764,812);
        _SFD_CV_INIT_EML(17,1,6,5,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(17,0,"selfAdaptorTypeTablec4_Expriment_Emotion",0,
                             -1,1029);
        _SFD_CV_INIT_EML_FCN(17,1,"aFcnTruthTableAction_1",1029,-1,1092);
        _SFD_CV_INIT_EML_FCN(17,2,"aFcnTruthTableAction_2",1092,-1,1155);
        _SFD_CV_INIT_EML_FCN(17,3,"aFcnTruthTableAction_3",1155,-1,1220);
        _SFD_CV_INIT_EML_FCN(17,4,"aFcnTruthTableAction_4",1220,-1,1285);
        _SFD_CV_INIT_EML_FCN(17,5,"aFcnTruthTableAction_5",1285,-1,1343);
        _SFD_CV_INIT_EML_IF(17,1,0,658,688,719,1027);
        _SFD_CV_INIT_EML_IF(17,1,1,719,753,784,1027);
        _SFD_CV_INIT_EML_IF(17,1,2,784,818,849,1027);
        _SFD_CV_INIT_EML_IF(17,1,3,849,883,914,1027);
        _SFD_CV_INIT_EML_IF(17,1,4,914,948,979,1027);
        _SFD_CV_INIT_EML(15,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(15,0,"insertQueueLowc4_Expriment_Emotion",0,-1,568);
        _SFD_CV_INIT_EML_IF(15,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(15,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(15,1,0,109,121,294);
        _SFD_CV_INIT_EML(14,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(14,0,"insertQueuec4_Expriment_Emotion",0,-1,565);
        _SFD_CV_INIT_EML_IF(14,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(14,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(14,1,0,106,118,291);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,13,0,13);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,0,33,0,33);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,33,0,33);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(23,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(24,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(24,0,0,1,71,1,48);

        {
          static int condStart[] = { 1, 21, 45 };

          static int condEnd[] = { 20, 44, 71 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(24,0,0,1,71,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,71,1,48);

        {
          static int condStart[] = { 1, 21, 45 };

          static int condEnd[] = { 20, 44, 71 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,71,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,71,1,48);

        {
          static int condStart[] = { 1, 21, 45 };

          static int condEnd[] = { 20, 44, 71 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,71,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(26,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(14,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(27,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(27,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(28,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,24,1,24);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(31,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(32,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(33,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(34,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
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
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
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

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1000;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 40;
          _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_wb_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_xb_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_rb_sf_marshallOut,(MexInFcnForType)
            c4_e_sf_marshallIn);
        }

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
          real_T *c4_gameState;
          real_T *c4_inA;
          real_T *c4_inE;
          real_T *c4_personality;
          real_T *c4_inV;
          boolean_T *c4_personalityChange;
          real_T (*c4_randArray)[40];
          real_T (*c4_poseArray)[6];
          c4_poseArray = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 6);
          c4_personalityChange = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 5);
          c4_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_randArray = (real_T (*)[40])ssGetInputPortSignal(chartInstance->S,
            2);
          c4_inE = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c4_boredom_address);
          _SFD_SET_DATA_VALUE_PTR(1U,
            chartInstance->c4_BOREDOM_THRESHOLD_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c4_randSlowPose_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c4_interest_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_gameState);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c4_randPoseChance_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c4_STATE_OVER_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c4_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c4_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_inA);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_inE);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c4_HAPPY_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c4_SAD_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c4_CONTEMPT_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c4_BORED_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c4_FRUST_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c4_FEAR_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c4_IDLE_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c4_EXCITE_address);
          _SFD_SET_DATA_VALUE_PTR(19U, *chartInstance->c4_BML_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c4_P_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c4_fileID_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c4_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c4_bodyBusyFlag_address);
          _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c4_BMLM);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c4_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(26U, *chartInstance->c4_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c4_n);
          _SFD_SET_DATA_VALUE_PTR(28U, *c4_randArray);
          _SFD_SET_DATA_VALUE_PTR(29U, c4_personality);
          _SFD_SET_DATA_VALUE_PTR(30U, &chartInstance->c4_randPR);
          _SFD_SET_DATA_VALUE_PTR(31U, &chartInstance->c4_pPoseChance);
          _SFD_SET_DATA_VALUE_PTR(32U, &chartInstance->c4_poseFreq);
          _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance->c4_leanPose);
          _SFD_SET_DATA_VALUE_PTR(34U, c4_inV);
          _SFD_SET_DATA_VALUE_PTR(35U, &chartInstance->c4_pPoseChanceP);
          _SFD_SET_DATA_VALUE_PTR(36U, &chartInstance->c4_poseFreqP);
          _SFD_SET_DATA_VALUE_PTR(37U, &chartInstance->c4_pCatChance);
          _SFD_SET_DATA_VALUE_PTR(38U, &chartInstance->c4_catChance);
          _SFD_SET_DATA_VALUE_PTR(39U, c4_personalityChange);
          _SFD_SET_DATA_VALUE_PTR(40U, *chartInstance->c4_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(41U, chartInstance->c4_BMLl);
          _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c4_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(43U, &chartInstance->c4_pChangeFlag);
          _SFD_SET_DATA_VALUE_PTR(44U, chartInstance->c4_faceBusyFlag_address);
          _SFD_SET_DATA_VALUE_PTR(45U, *c4_poseArray);
          _SFD_SET_DATA_VALUE_PTR(46U, chartInstance->c4_pose_speed_address);
          _SFD_SET_DATA_VALUE_PTR(47U, chartInstance->c4_pose_lean_flag_address);
          _SFD_SET_DATA_VALUE_PTR(48U, chartInstance->c4_pose_lean_address);
          _SFD_SET_DATA_VALUE_PTR(49U,
            chartInstance->c4_pose_frequency_factor_address);
          _SFD_SET_DATA_VALUE_PTR(50U,
            chartInstance->c4_pose_chance_factor_address);
          _SFD_SET_DATA_VALUE_PTR(51U, chartInstance->c4_pose_cat_chance_address);
          _SFD_SET_DATA_VALUE_PTR(52U,
            chartInstance->c4_pose_change_flag_address);
          _SFD_SET_DATA_VALUE_PTR(53U, &chartInstance->c4_pose_type);
          _SFD_SET_DATA_VALUE_PTR(54U, chartInstance->c4_pose_twitch_address);
          _SFD_SET_DATA_VALUE_PTR(55U, chartInstance->c4_pose_space_address);
          _SFD_SET_DATA_VALUE_PTR(56U, &chartInstance->c4_poseNum);
          _SFD_SET_DATA_VALUE_PTR(57U, &chartInstance->c4_oldPose);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_EmotionMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "OU4GZdtszysYcng69VlbC";
}

static void sf_opaque_initialize_c4_Expriment_Emotion(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_Expriment_Emotion(void *chartInstanceVar)
{
  enable_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_Expriment_Emotion(void *chartInstanceVar)
{
  disable_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_Expriment_Emotion(void *chartInstanceVar)
{
  sf_gateway_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Expriment_Emotion(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Expriment_Emotion
    ((SFc4_Expriment_EmotionInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Expriment_Emotion();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Expriment_Emotion(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_Expriment_Emotion();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Expriment_Emotion(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c4_Expriment_Emotion(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c4_Expriment_Emotion(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Expriment_EmotionInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_Emotion_optimization_info();
    }

    finalize_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
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
  initSimStructsc4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Expriment_Emotion(SimStruct *S)
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
    initialize_params_c4_Expriment_Emotion((SFc4_Expriment_EmotionInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Expriment_Emotion(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_Emotion_optimization_info();
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2681952004U));
  ssSetChecksum1(S,(268944582U));
  ssSetChecksum2(S,(526995628U));
  ssSetChecksum3(S,(900612015U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Expriment_Emotion(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_Expriment_Emotion(SimStruct *S)
{
  SFc4_Expriment_EmotionInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_Expriment_EmotionInstanceStruct *)utMalloc(sizeof
    (SFc4_Expriment_EmotionInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Expriment_EmotionInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Expriment_Emotion;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Expriment_Emotion;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Expriment_Emotion;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Expriment_Emotion;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Expriment_Emotion;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Expriment_Emotion;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Expriment_Emotion;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Expriment_Emotion;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Expriment_Emotion;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Expriment_Emotion;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Expriment_Emotion;
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

void c4_Expriment_Emotion_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Expriment_Emotion(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Expriment_Emotion(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Expriment_Emotion(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Expriment_Emotion_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
