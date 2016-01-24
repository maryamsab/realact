/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_01_lib_TruthTables_sfun.h"
#include "c3_ARP_01_lib_TruthTables.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_01_lib_TruthTables_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_d_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_f_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_g_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_h_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_i_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_j_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_k_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_l_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c3_m_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_n_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_o_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_p_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_q_debug_family_names[8] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c3_r_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_s_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_t_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_u_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_v_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_w_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_x_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_y_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_ab_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_bb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_cb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_db_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_eb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_fb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_gb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_hb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ib_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_jb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_kb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_lb_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_mb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_nb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ob_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_pb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_qb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_rb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_sb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_tb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ub_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_vb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_wb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_xb_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c3_yb_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ac_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_bc_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "bmlID", "poseBML" };

static const char * c3_cc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_dc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ec_debug_family_names[21] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17", "nargin",
  "nargout", "bmlID", "gazeBML" };

static const char * c3_fc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_gc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_hc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ic_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_jc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_kc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_lc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_mc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_nc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_oc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_pc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_qc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_rc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_sc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_tc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_uc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_vc_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_wc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_xc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_yc_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_ad_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_bd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_cd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_dd_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_ed_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_fd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_gd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_hd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_id_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_jd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_kd_debug_family_names[10] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "nargin", "nargout", "sbmID", "poseSBM" };

static const char * c3_ld_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_md_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_nd_debug_family_names[12] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c3_od_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_pd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_qd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_rd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_sd_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c3_td_debug_family_names[22] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3",
  "aVarTruthTableCondition_4", "aVarTruthTableCondition_5",
  "aVarTruthTableCondition_6", "aVarTruthTableCondition_7",
  "aVarTruthTableCondition_8", "aVarTruthTableCondition_9",
  "aVarTruthTableCondition_10", "aVarTruthTableCondition_11",
  "aVarTruthTableCondition_12", "aVarTruthTableCondition_13",
  "aVarTruthTableCondition_14", "aVarTruthTableCondition_15",
  "aVarTruthTableCondition_16", "aVarTruthTableCondition_17",
  "aVarTruthTableCondition_18", "nargin", "nargout", "bmlID", "gazeBML" };

static const char * c3_ud_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

/* Function Declarations */
static void initialize_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void initialize_params_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void enable_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void disable_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void set_sim_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void c3_set_sim_state_side_effects_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void finalize_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void sf_gateway_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void initSimStructsc3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_b_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_db_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_gd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_hd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_id_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_jd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_kd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ld_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_md_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_nd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_od_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_pd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_qd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_rd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_sd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_td_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ud_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_vd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_wd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_xd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_yd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ae_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_be_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ce_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_de_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_ee_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_fe_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_ge_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ARP_01_lib_TruthTables, const
  char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_c3_ARP_01_lib_TruthTables = 0U;
}

static void initialize_params_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(1, 1), false);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ARP_01_lib_TruthTables;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_is_active_c3_ARP_01_lib_TruthTables = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
     "is_active_c3_ARP_01_lib_TruthTables");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ARP_01_lib_TruthTables(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  c3_set_sim_state_side_effects_c3_ARP_01_lib_TruthTables(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_01_lib_TruthTablesMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_ARP_01_lib_TruthTables
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Maryam\\Documents\\maryam-research\\code\\Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i0;
  real_T c3_b_inData[256];
  int32_T c3_i1;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i0 = 0; c3_i0 < 256; c3_i0++) {
    c3_b_inData[c3_i0] = (*(real_T (*)[256])c3_inData)[c3_i0];
  }

  for (c3_i1 = 0; c3_i1 < 256; c3_i1++) {
    c3_u[c3_i1] = c3_b_inData[c3_i1];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 256, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv0[256];
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 2, 256,
                1);
  for (c3_i2 = 0; c3_i2 < 256; c3_i2++) {
    c3_y[c3_i2] = c3_dv0[c3_i2];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_poseBML;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i3;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_poseBML = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_poseBML), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_poseBML);
  for (c3_i3 = 0; c3_i3 < 256; c3_i3++) {
    (*(real_T (*)[256])c3_outData)[c3_i3] = c3_y[c3_i3];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_b_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_bmlID;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_bmlID = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_bmlID), &c3_thisId);
  sf_mex_destroy(&c3_bmlID);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_aVarTruthTableCondition_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_aVarTruthTableCondition_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_2), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_2);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i4;
  real_T c3_b_inData[256];
  int32_T c3_i5;
  real_T c3_u[256];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i4 = 0; c3_i4 < 256; c3_i4++) {
    c3_b_inData[c3_i4] = (*(real_T (*)[256])c3_inData)[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 256; c3_i5++) {
    c3_u[c3_i5] = c3_b_inData[c3_i5];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[256])
{
  real_T c3_dv1[256];
  int32_T c3_i6;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 256);
  for (c3_i6 = 0; c3_i6 < 256; c3_i6++) {
    c3_y[c3_i6] = c3_dv1[c3_i6];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_myarr256;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[256];
  int32_T c3_i7;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_myarr256 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_myarr256), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_myarr256);
  for (c3_i7 = 0; c3_i7 < 256; c3_i7++) {
    (*(real_T (*)[256])c3_outData)[c3_i7] = c3_y[c3_i7];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i8;
  char_T c3_b_inData[94];
  int32_T c3_i9;
  char_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i8 = 0; c3_i8 < 94; c3_i8++) {
    c3_b_inData[c3_i8] = (*(char_T (*)[94])c3_inData)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 94; c3_i9++) {
    c3_u[c3_i9] = c3_b_inData[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i10;
  real_T c3_b_inData[94];
  int32_T c3_i11;
  real_T c3_u[94];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i10 = 0; c3_i10 < 94; c3_i10++) {
    c3_b_inData[c3_i10] = (*(real_T (*)[94])c3_inData)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 94; c3_i11++) {
    c3_u[c3_i11] = c3_b_inData[c3_i11];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 94), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i12;
  char_T c3_b_inData[88];
  int32_T c3_i13;
  char_T c3_u[88];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i12 = 0; c3_i12 < 88; c3_i12++) {
    c3_b_inData[c3_i12] = (*(char_T (*)[88])c3_inData)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 88; c3_i13++) {
    c3_u[c3_i13] = c3_b_inData[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 88), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i14;
  real_T c3_b_inData[88];
  int32_T c3_i15;
  real_T c3_u[88];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 88; c3_i14++) {
    c3_b_inData[c3_i14] = (*(real_T (*)[88])c3_inData)[c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 88; c3_i15++) {
    c3_u[c3_i15] = c3_b_inData[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 88), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i16;
  char_T c3_b_inData[86];
  int32_T c3_i17;
  char_T c3_u[86];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i16 = 0; c3_i16 < 86; c3_i16++) {
    c3_b_inData[c3_i16] = (*(char_T (*)[86])c3_inData)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 86; c3_i17++) {
    c3_u[c3_i17] = c3_b_inData[c3_i17];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 86), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i18;
  real_T c3_b_inData[86];
  int32_T c3_i19;
  real_T c3_u[86];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i18 = 0; c3_i18 < 86; c3_i18++) {
    c3_b_inData[c3_i18] = (*(real_T (*)[86])c3_inData)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 86; c3_i19++) {
    c3_u[c3_i19] = c3_b_inData[c3_i19];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 86), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i20;
  char_T c3_b_inData[98];
  int32_T c3_i21;
  char_T c3_u[98];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i20 = 0; c3_i20 < 98; c3_i20++) {
    c3_b_inData[c3_i20] = (*(char_T (*)[98])c3_inData)[c3_i20];
  }

  for (c3_i21 = 0; c3_i21 < 98; c3_i21++) {
    c3_u[c3_i21] = c3_b_inData[c3_i21];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 98), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i22;
  real_T c3_b_inData[98];
  int32_T c3_i23;
  real_T c3_u[98];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i22 = 0; c3_i22 < 98; c3_i22++) {
    c3_b_inData[c3_i22] = (*(real_T (*)[98])c3_inData)[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 98; c3_i23++) {
    c3_u[c3_i23] = c3_b_inData[c3_i23];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 98), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i24;
  char_T c3_b_inData[96];
  int32_T c3_i25;
  char_T c3_u[96];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i24 = 0; c3_i24 < 96; c3_i24++) {
    c3_b_inData[c3_i24] = (*(char_T (*)[96])c3_inData)[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 96; c3_i25++) {
    c3_u[c3_i25] = c3_b_inData[c3_i25];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 96), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i26;
  real_T c3_b_inData[96];
  int32_T c3_i27;
  real_T c3_u[96];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i26 = 0; c3_i26 < 96; c3_i26++) {
    c3_b_inData[c3_i26] = (*(real_T (*)[96])c3_inData)[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 96; c3_i27++) {
    c3_u[c3_i27] = c3_b_inData[c3_i27];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 96), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_o_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i28;
  char_T c3_b_inData[161];
  int32_T c3_i29;
  char_T c3_u[161];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i28 = 0; c3_i28 < 161; c3_i28++) {
    c3_b_inData[c3_i28] = (*(char_T (*)[161])c3_inData)[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 161; c3_i29++) {
    c3_u[c3_i29] = c3_b_inData[c3_i29];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 161),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_p_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i30;
  real_T c3_b_inData[161];
  int32_T c3_i31;
  real_T c3_u[161];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i30 = 0; c3_i30 < 161; c3_i30++) {
    c3_b_inData[c3_i30] = (*(real_T (*)[161])c3_inData)[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 161; c3_i31++) {
    c3_u[c3_i31] = c3_b_inData[c3_i31];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 161), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_q_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i32;
  char_T c3_b_inData[157];
  int32_T c3_i33;
  char_T c3_u[157];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i32 = 0; c3_i32 < 157; c3_i32++) {
    c3_b_inData[c3_i32] = (*(char_T (*)[157])c3_inData)[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 157; c3_i33++) {
    c3_u[c3_i33] = c3_b_inData[c3_i33];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 157),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_r_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i34;
  real_T c3_b_inData[157];
  int32_T c3_i35;
  real_T c3_u[157];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i34 = 0; c3_i34 < 157; c3_i34++) {
    c3_b_inData[c3_i34] = (*(real_T (*)[157])c3_inData)[c3_i34];
  }

  for (c3_i35 = 0; c3_i35 < 157; c3_i35++) {
    c3_u[c3_i35] = c3_b_inData[c3_i35];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 157), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_s_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i36;
  char_T c3_b_inData[92];
  int32_T c3_i37;
  char_T c3_u[92];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i36 = 0; c3_i36 < 92; c3_i36++) {
    c3_b_inData[c3_i36] = (*(char_T (*)[92])c3_inData)[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 92; c3_i37++) {
    c3_u[c3_i37] = c3_b_inData[c3_i37];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 92), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_t_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i38;
  real_T c3_b_inData[92];
  int32_T c3_i39;
  real_T c3_u[92];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i38 = 0; c3_i38 < 92; c3_i38++) {
    c3_b_inData[c3_i38] = (*(real_T (*)[92])c3_inData)[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 92; c3_i39++) {
    c3_u[c3_i39] = c3_b_inData[c3_i39];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 92), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_u_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i40;
  char_T c3_b_inData[89];
  int32_T c3_i41;
  char_T c3_u[89];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i40 = 0; c3_i40 < 89; c3_i40++) {
    c3_b_inData[c3_i40] = (*(char_T (*)[89])c3_inData)[c3_i40];
  }

  for (c3_i41 = 0; c3_i41 < 89; c3_i41++) {
    c3_u[c3_i41] = c3_b_inData[c3_i41];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 89), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_v_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i42;
  real_T c3_b_inData[89];
  int32_T c3_i43;
  real_T c3_u[89];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i42 = 0; c3_i42 < 89; c3_i42++) {
    c3_b_inData[c3_i42] = (*(real_T (*)[89])c3_inData)[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 89; c3_i43++) {
    c3_u[c3_i43] = c3_b_inData[c3_i43];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 89), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_w_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i44;
  char_T c3_b_inData[165];
  int32_T c3_i45;
  char_T c3_u[165];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i44 = 0; c3_i44 < 165; c3_i44++) {
    c3_b_inData[c3_i44] = (*(char_T (*)[165])c3_inData)[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 165; c3_i45++) {
    c3_u[c3_i45] = c3_b_inData[c3_i45];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 165),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_x_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i46;
  real_T c3_b_inData[165];
  int32_T c3_i47;
  real_T c3_u[165];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i46 = 0; c3_i46 < 165; c3_i46++) {
    c3_b_inData[c3_i46] = (*(real_T (*)[165])c3_inData)[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 165; c3_i47++) {
    c3_u[c3_i47] = c3_b_inData[c3_i47];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 165), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_y_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i48;
  char_T c3_b_inData[91];
  int32_T c3_i49;
  char_T c3_u[91];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i48 = 0; c3_i48 < 91; c3_i48++) {
    c3_b_inData[c3_i48] = (*(char_T (*)[91])c3_inData)[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 91; c3_i49++) {
    c3_u[c3_i49] = c3_b_inData[c3_i49];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 91), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ab_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i50;
  real_T c3_b_inData[91];
  int32_T c3_i51;
  real_T c3_u[91];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i50 = 0; c3_i50 < 91; c3_i50++) {
    c3_b_inData[c3_i50] = (*(real_T (*)[91])c3_inData)[c3_i50];
  }

  for (c3_i51 = 0; c3_i51 < 91; c3_i51++) {
    c3_u[c3_i51] = c3_b_inData[c3_i51];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 91), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_bb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i52;
  char_T c3_b_inData[223];
  int32_T c3_i53;
  char_T c3_u[223];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i52 = 0; c3_i52 < 223; c3_i52++) {
    c3_b_inData[c3_i52] = (*(char_T (*)[223])c3_inData)[c3_i52];
  }

  for (c3_i53 = 0; c3_i53 < 223; c3_i53++) {
    c3_u[c3_i53] = c3_b_inData[c3_i53];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 223),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_cb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i54;
  real_T c3_b_inData[223];
  int32_T c3_i55;
  real_T c3_u[223];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i54 = 0; c3_i54 < 223; c3_i54++) {
    c3_b_inData[c3_i54] = (*(real_T (*)[223])c3_inData)[c3_i54];
  }

  for (c3_i55 = 0; c3_i55 < 223; c3_i55++) {
    c3_u[c3_i55] = c3_b_inData[c3_i55];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 223), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_db_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i56;
  char_T c3_b_inData[87];
  int32_T c3_i57;
  char_T c3_u[87];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i56 = 0; c3_i56 < 87; c3_i56++) {
    c3_b_inData[c3_i56] = (*(char_T (*)[87])c3_inData)[c3_i56];
  }

  for (c3_i57 = 0; c3_i57 < 87; c3_i57++) {
    c3_u[c3_i57] = c3_b_inData[c3_i57];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 87), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_eb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i58;
  real_T c3_b_inData[87];
  int32_T c3_i59;
  real_T c3_u[87];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i58 = 0; c3_i58 < 87; c3_i58++) {
    c3_b_inData[c3_i58] = (*(real_T (*)[87])c3_inData)[c3_i58];
  }

  for (c3_i59 = 0; c3_i59 < 87; c3_i59++) {
    c3_u[c3_i59] = c3_b_inData[c3_i59];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 87), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_fb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i60;
  char_T c3_b_inData[93];
  int32_T c3_i61;
  char_T c3_u[93];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i60 = 0; c3_i60 < 93; c3_i60++) {
    c3_b_inData[c3_i60] = (*(char_T (*)[93])c3_inData)[c3_i60];
  }

  for (c3_i61 = 0; c3_i61 < 93; c3_i61++) {
    c3_u[c3_i61] = c3_b_inData[c3_i61];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 93), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_gb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i62;
  real_T c3_b_inData[93];
  int32_T c3_i63;
  real_T c3_u[93];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i62 = 0; c3_i62 < 93; c3_i62++) {
    c3_b_inData[c3_i62] = (*(real_T (*)[93])c3_inData)[c3_i62];
  }

  for (c3_i63 = 0; c3_i63 < 93; c3_i63++) {
    c3_u[c3_i63] = c3_b_inData[c3_i63];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 93), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_hb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i64;
  char_T c3_b_inData[95];
  int32_T c3_i65;
  char_T c3_u[95];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i64 = 0; c3_i64 < 95; c3_i64++) {
    c3_b_inData[c3_i64] = (*(char_T (*)[95])c3_inData)[c3_i64];
  }

  for (c3_i65 = 0; c3_i65 < 95; c3_i65++) {
    c3_u[c3_i65] = c3_b_inData[c3_i65];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 95), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ib_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i66;
  real_T c3_b_inData[95];
  int32_T c3_i67;
  real_T c3_u[95];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i66 = 0; c3_i66 < 95; c3_i66++) {
    c3_b_inData[c3_i66] = (*(real_T (*)[95])c3_inData)[c3_i66];
  }

  for (c3_i67 = 0; c3_i67 < 95; c3_i67++) {
    c3_u[c3_i67] = c3_b_inData[c3_i67];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 95), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_jb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i68;
  char_T c3_b_inData[97];
  int32_T c3_i69;
  char_T c3_u[97];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i68 = 0; c3_i68 < 97; c3_i68++) {
    c3_b_inData[c3_i68] = (*(char_T (*)[97])c3_inData)[c3_i68];
  }

  for (c3_i69 = 0; c3_i69 < 97; c3_i69++) {
    c3_u[c3_i69] = c3_b_inData[c3_i69];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 97), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_kb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i70;
  real_T c3_b_inData[97];
  int32_T c3_i71;
  real_T c3_u[97];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i70 = 0; c3_i70 < 97; c3_i70++) {
    c3_b_inData[c3_i70] = (*(real_T (*)[97])c3_inData)[c3_i70];
  }

  for (c3_i71 = 0; c3_i71 < 97; c3_i71++) {
    c3_u[c3_i71] = c3_b_inData[c3_i71];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 97), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_lb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i72;
  char_T c3_b_inData[101];
  int32_T c3_i73;
  char_T c3_u[101];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i72 = 0; c3_i72 < 101; c3_i72++) {
    c3_b_inData[c3_i72] = (*(char_T (*)[101])c3_inData)[c3_i72];
  }

  for (c3_i73 = 0; c3_i73 < 101; c3_i73++) {
    c3_u[c3_i73] = c3_b_inData[c3_i73];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 101),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_mb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i74;
  real_T c3_b_inData[101];
  int32_T c3_i75;
  real_T c3_u[101];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i74 = 0; c3_i74 < 101; c3_i74++) {
    c3_b_inData[c3_i74] = (*(real_T (*)[101])c3_inData)[c3_i74];
  }

  for (c3_i75 = 0; c3_i75 < 101; c3_i75++) {
    c3_u[c3_i75] = c3_b_inData[c3_i75];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 101), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_nb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i76;
  char_T c3_b_inData[103];
  int32_T c3_i77;
  char_T c3_u[103];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i76 = 0; c3_i76 < 103; c3_i76++) {
    c3_b_inData[c3_i76] = (*(char_T (*)[103])c3_inData)[c3_i76];
  }

  for (c3_i77 = 0; c3_i77 < 103; c3_i77++) {
    c3_u[c3_i77] = c3_b_inData[c3_i77];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ob_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i78;
  real_T c3_b_inData[103];
  int32_T c3_i79;
  real_T c3_u[103];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i78 = 0; c3_i78 < 103; c3_i78++) {
    c3_b_inData[c3_i78] = (*(real_T (*)[103])c3_inData)[c3_i78];
  }

  for (c3_i79 = 0; c3_i79 < 103; c3_i79++) {
    c3_u[c3_i79] = c3_b_inData[c3_i79];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 103), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_pb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i80;
  char_T c3_b_inData[104];
  int32_T c3_i81;
  char_T c3_u[104];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i80 = 0; c3_i80 < 104; c3_i80++) {
    c3_b_inData[c3_i80] = (*(char_T (*)[104])c3_inData)[c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 104; c3_i81++) {
    c3_u[c3_i81] = c3_b_inData[c3_i81];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 104),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_qb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i82;
  real_T c3_b_inData[104];
  int32_T c3_i83;
  real_T c3_u[104];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i82 = 0; c3_i82 < 104; c3_i82++) {
    c3_b_inData[c3_i82] = (*(real_T (*)[104])c3_inData)[c3_i82];
  }

  for (c3_i83 = 0; c3_i83 < 104; c3_i83++) {
    c3_u[c3_i83] = c3_b_inData[c3_i83];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 104), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_rb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i84;
  char_T c3_b_inData[105];
  int32_T c3_i85;
  char_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i84 = 0; c3_i84 < 105; c3_i84++) {
    c3_b_inData[c3_i84] = (*(char_T (*)[105])c3_inData)[c3_i84];
  }

  for (c3_i85 = 0; c3_i85 < 105; c3_i85++) {
    c3_u[c3_i85] = c3_b_inData[c3_i85];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_sb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i86;
  real_T c3_b_inData[105];
  int32_T c3_i87;
  real_T c3_u[105];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i86 = 0; c3_i86 < 105; c3_i86++) {
    c3_b_inData[c3_i86] = (*(real_T (*)[105])c3_inData)[c3_i86];
  }

  for (c3_i87 = 0; c3_i87 < 105; c3_i87++) {
    c3_u[c3_i87] = c3_b_inData[c3_i87];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_tb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i88;
  char_T c3_b_inData[107];
  int32_T c3_i89;
  char_T c3_u[107];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i88 = 0; c3_i88 < 107; c3_i88++) {
    c3_b_inData[c3_i88] = (*(char_T (*)[107])c3_inData)[c3_i88];
  }

  for (c3_i89 = 0; c3_i89 < 107; c3_i89++) {
    c3_u[c3_i89] = c3_b_inData[c3_i89];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 107),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ub_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i90;
  real_T c3_b_inData[107];
  int32_T c3_i91;
  real_T c3_u[107];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i90 = 0; c3_i90 < 107; c3_i90++) {
    c3_b_inData[c3_i90] = (*(real_T (*)[107])c3_inData)[c3_i90];
  }

  for (c3_i91 = 0; c3_i91 < 107; c3_i91++) {
    c3_u[c3_i91] = c3_b_inData[c3_i91];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 107), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_vb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i92;
  char_T c3_b_inData[102];
  int32_T c3_i93;
  char_T c3_u[102];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i92 = 0; c3_i92 < 102; c3_i92++) {
    c3_b_inData[c3_i92] = (*(char_T (*)[102])c3_inData)[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 102; c3_i93++) {
    c3_u[c3_i93] = c3_b_inData[c3_i93];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 102),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_wb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i94;
  real_T c3_b_inData[102];
  int32_T c3_i95;
  real_T c3_u[102];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i94 = 0; c3_i94 < 102; c3_i94++) {
    c3_b_inData[c3_i94] = (*(real_T (*)[102])c3_inData)[c3_i94];
  }

  for (c3_i95 = 0; c3_i95 < 102; c3_i95++) {
    c3_u[c3_i95] = c3_b_inData[c3_i95];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 102), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_xb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i96;
  char_T c3_b_inData[68];
  int32_T c3_i97;
  char_T c3_u[68];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i96 = 0; c3_i96 < 68; c3_i96++) {
    c3_b_inData[c3_i96] = (*(char_T (*)[68])c3_inData)[c3_i96];
  }

  for (c3_i97 = 0; c3_i97 < 68; c3_i97++) {
    c3_u[c3_i97] = c3_b_inData[c3_i97];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 68), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_yb_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i98;
  real_T c3_b_inData[68];
  int32_T c3_i99;
  real_T c3_u[68];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i98 = 0; c3_i98 < 68; c3_i98++) {
    c3_b_inData[c3_i98] = (*(real_T (*)[68])c3_inData)[c3_i98];
  }

  for (c3_i99 = 0; c3_i99 < 68; c3_i99++) {
    c3_u[c3_i99] = c3_b_inData[c3_i99];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 68), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ac_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i100;
  char_T c3_b_inData[142];
  int32_T c3_i101;
  char_T c3_u[142];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i100 = 0; c3_i100 < 142; c3_i100++) {
    c3_b_inData[c3_i100] = (*(char_T (*)[142])c3_inData)[c3_i100];
  }

  for (c3_i101 = 0; c3_i101 < 142; c3_i101++) {
    c3_u[c3_i101] = c3_b_inData[c3_i101];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 142),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_bc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i102;
  real_T c3_b_inData[142];
  int32_T c3_i103;
  real_T c3_u[142];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i102 = 0; c3_i102 < 142; c3_i102++) {
    c3_b_inData[c3_i102] = (*(real_T (*)[142])c3_inData)[c3_i102];
  }

  for (c3_i103 = 0; c3_i103 < 142; c3_i103++) {
    c3_u[c3_i103] = c3_b_inData[c3_i103];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 142), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_cc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i104;
  char_T c3_b_inData[183];
  int32_T c3_i105;
  char_T c3_u[183];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i104 = 0; c3_i104 < 183; c3_i104++) {
    c3_b_inData[c3_i104] = (*(char_T (*)[183])c3_inData)[c3_i104];
  }

  for (c3_i105 = 0; c3_i105 < 183; c3_i105++) {
    c3_u[c3_i105] = c3_b_inData[c3_i105];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 183),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_dc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i106;
  real_T c3_b_inData[183];
  int32_T c3_i107;
  real_T c3_u[183];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i106 = 0; c3_i106 < 183; c3_i106++) {
    c3_b_inData[c3_i106] = (*(real_T (*)[183])c3_inData)[c3_i106];
  }

  for (c3_i107 = 0; c3_i107 < 183; c3_i107++) {
    c3_u[c3_i107] = c3_b_inData[c3_i107];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 183), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ec_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i108;
  char_T c3_b_inData[118];
  int32_T c3_i109;
  char_T c3_u[118];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i108 = 0; c3_i108 < 118; c3_i108++) {
    c3_b_inData[c3_i108] = (*(char_T (*)[118])c3_inData)[c3_i108];
  }

  for (c3_i109 = 0; c3_i109 < 118; c3_i109++) {
    c3_u[c3_i109] = c3_b_inData[c3_i109];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 118),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_fc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i110;
  real_T c3_b_inData[118];
  int32_T c3_i111;
  real_T c3_u[118];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i110 = 0; c3_i110 < 118; c3_i110++) {
    c3_b_inData[c3_i110] = (*(real_T (*)[118])c3_inData)[c3_i110];
  }

  for (c3_i111 = 0; c3_i111 < 118; c3_i111++) {
    c3_u[c3_i111] = c3_b_inData[c3_i111];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 118), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_gc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i112;
  char_T c3_b_inData[119];
  int32_T c3_i113;
  char_T c3_u[119];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i112 = 0; c3_i112 < 119; c3_i112++) {
    c3_b_inData[c3_i112] = (*(char_T (*)[119])c3_inData)[c3_i112];
  }

  for (c3_i113 = 0; c3_i113 < 119; c3_i113++) {
    c3_u[c3_i113] = c3_b_inData[c3_i113];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 119),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_hc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i114;
  real_T c3_b_inData[119];
  int32_T c3_i115;
  real_T c3_u[119];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i114 = 0; c3_i114 < 119; c3_i114++) {
    c3_b_inData[c3_i114] = (*(real_T (*)[119])c3_inData)[c3_i114];
  }

  for (c3_i115 = 0; c3_i115 < 119; c3_i115++) {
    c3_u[c3_i115] = c3_b_inData[c3_i115];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 119), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ic_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i116;
  char_T c3_b_inData[116];
  int32_T c3_i117;
  char_T c3_u[116];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i116 = 0; c3_i116 < 116; c3_i116++) {
    c3_b_inData[c3_i116] = (*(char_T (*)[116])c3_inData)[c3_i116];
  }

  for (c3_i117 = 0; c3_i117 < 116; c3_i117++) {
    c3_u[c3_i117] = c3_b_inData[c3_i117];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 116),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_jc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i118;
  real_T c3_b_inData[116];
  int32_T c3_i119;
  real_T c3_u[116];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i118 = 0; c3_i118 < 116; c3_i118++) {
    c3_b_inData[c3_i118] = (*(real_T (*)[116])c3_inData)[c3_i118];
  }

  for (c3_i119 = 0; c3_i119 < 116; c3_i119++) {
    c3_u[c3_i119] = c3_b_inData[c3_i119];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 116), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_kc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i120;
  char_T c3_b_inData[120];
  int32_T c3_i121;
  char_T c3_u[120];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i120 = 0; c3_i120 < 120; c3_i120++) {
    c3_b_inData[c3_i120] = (*(char_T (*)[120])c3_inData)[c3_i120];
  }

  for (c3_i121 = 0; c3_i121 < 120; c3_i121++) {
    c3_u[c3_i121] = c3_b_inData[c3_i121];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 120),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_lc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i122;
  real_T c3_b_inData[120];
  int32_T c3_i123;
  real_T c3_u[120];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i122 = 0; c3_i122 < 120; c3_i122++) {
    c3_b_inData[c3_i122] = (*(real_T (*)[120])c3_inData)[c3_i122];
  }

  for (c3_i123 = 0; c3_i123 < 120; c3_i123++) {
    c3_u[c3_i123] = c3_b_inData[c3_i123];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 120), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_mc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i124;
  char_T c3_b_inData[121];
  int32_T c3_i125;
  char_T c3_u[121];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i124 = 0; c3_i124 < 121; c3_i124++) {
    c3_b_inData[c3_i124] = (*(char_T (*)[121])c3_inData)[c3_i124];
  }

  for (c3_i125 = 0; c3_i125 < 121; c3_i125++) {
    c3_u[c3_i125] = c3_b_inData[c3_i125];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 121),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_nc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i126;
  real_T c3_b_inData[121];
  int32_T c3_i127;
  real_T c3_u[121];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i126 = 0; c3_i126 < 121; c3_i126++) {
    c3_b_inData[c3_i126] = (*(real_T (*)[121])c3_inData)[c3_i126];
  }

  for (c3_i127 = 0; c3_i127 < 121; c3_i127++) {
    c3_u[c3_i127] = c3_b_inData[c3_i127];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 121), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_oc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i128;
  char_T c3_b_inData[122];
  int32_T c3_i129;
  char_T c3_u[122];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i128 = 0; c3_i128 < 122; c3_i128++) {
    c3_b_inData[c3_i128] = (*(char_T (*)[122])c3_inData)[c3_i128];
  }

  for (c3_i129 = 0; c3_i129 < 122; c3_i129++) {
    c3_u[c3_i129] = c3_b_inData[c3_i129];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 122),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_pc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i130;
  real_T c3_b_inData[122];
  int32_T c3_i131;
  real_T c3_u[122];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i130 = 0; c3_i130 < 122; c3_i130++) {
    c3_b_inData[c3_i130] = (*(real_T (*)[122])c3_inData)[c3_i130];
  }

  for (c3_i131 = 0; c3_i131 < 122; c3_i131++) {
    c3_u[c3_i131] = c3_b_inData[c3_i131];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 122), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_qc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i132;
  char_T c3_b_inData[123];
  int32_T c3_i133;
  char_T c3_u[123];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i132 = 0; c3_i132 < 123; c3_i132++) {
    c3_b_inData[c3_i132] = (*(char_T (*)[123])c3_inData)[c3_i132];
  }

  for (c3_i133 = 0; c3_i133 < 123; c3_i133++) {
    c3_u[c3_i133] = c3_b_inData[c3_i133];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 123),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_rc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i134;
  real_T c3_b_inData[123];
  int32_T c3_i135;
  real_T c3_u[123];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i134 = 0; c3_i134 < 123; c3_i134++) {
    c3_b_inData[c3_i134] = (*(real_T (*)[123])c3_inData)[c3_i134];
  }

  for (c3_i135 = 0; c3_i135 < 123; c3_i135++) {
    c3_u[c3_i135] = c3_b_inData[c3_i135];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 123), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_sc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i136;
  char_T c3_b_inData[133];
  int32_T c3_i137;
  char_T c3_u[133];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i136 = 0; c3_i136 < 133; c3_i136++) {
    c3_b_inData[c3_i136] = (*(char_T (*)[133])c3_inData)[c3_i136];
  }

  for (c3_i137 = 0; c3_i137 < 133; c3_i137++) {
    c3_u[c3_i137] = c3_b_inData[c3_i137];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 133),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_tc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i138;
  real_T c3_b_inData[133];
  int32_T c3_i139;
  real_T c3_u[133];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i138 = 0; c3_i138 < 133; c3_i138++) {
    c3_b_inData[c3_i138] = (*(real_T (*)[133])c3_inData)[c3_i138];
  }

  for (c3_i139 = 0; c3_i139 < 133; c3_i139++) {
    c3_u[c3_i139] = c3_b_inData[c3_i139];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 133), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_uc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i140;
  char_T c3_b_inData[137];
  int32_T c3_i141;
  char_T c3_u[137];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i140 = 0; c3_i140 < 137; c3_i140++) {
    c3_b_inData[c3_i140] = (*(char_T (*)[137])c3_inData)[c3_i140];
  }

  for (c3_i141 = 0; c3_i141 < 137; c3_i141++) {
    c3_u[c3_i141] = c3_b_inData[c3_i141];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 137),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_vc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i142;
  real_T c3_b_inData[137];
  int32_T c3_i143;
  real_T c3_u[137];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i142 = 0; c3_i142 < 137; c3_i142++) {
    c3_b_inData[c3_i142] = (*(real_T (*)[137])c3_inData)[c3_i142];
  }

  for (c3_i143 = 0; c3_i143 < 137; c3_i143++) {
    c3_u[c3_i143] = c3_b_inData[c3_i143];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 137), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_wc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i144;
  char_T c3_b_inData[138];
  int32_T c3_i145;
  char_T c3_u[138];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i144 = 0; c3_i144 < 138; c3_i144++) {
    c3_b_inData[c3_i144] = (*(char_T (*)[138])c3_inData)[c3_i144];
  }

  for (c3_i145 = 0; c3_i145 < 138; c3_i145++) {
    c3_u[c3_i145] = c3_b_inData[c3_i145];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 138),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_xc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i146;
  real_T c3_b_inData[138];
  int32_T c3_i147;
  real_T c3_u[138];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i146 = 0; c3_i146 < 138; c3_i146++) {
    c3_b_inData[c3_i146] = (*(real_T (*)[138])c3_inData)[c3_i146];
  }

  for (c3_i147 = 0; c3_i147 < 138; c3_i147++) {
    c3_u[c3_i147] = c3_b_inData[c3_i147];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 138), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_yc_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i148;
  char_T c3_b_inData[136];
  int32_T c3_i149;
  char_T c3_u[136];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i148 = 0; c3_i148 < 136; c3_i148++) {
    c3_b_inData[c3_i148] = (*(char_T (*)[136])c3_inData)[c3_i148];
  }

  for (c3_i149 = 0; c3_i149 < 136; c3_i149++) {
    c3_u[c3_i149] = c3_b_inData[c3_i149];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 136),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ad_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i150;
  real_T c3_b_inData[136];
  int32_T c3_i151;
  real_T c3_u[136];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i150 = 0; c3_i150 < 136; c3_i150++) {
    c3_b_inData[c3_i150] = (*(real_T (*)[136])c3_inData)[c3_i150];
  }

  for (c3_i151 = 0; c3_i151 < 136; c3_i151++) {
    c3_u[c3_i151] = c3_b_inData[c3_i151];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 136), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_bd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i152;
  char_T c3_b_inData[135];
  int32_T c3_i153;
  char_T c3_u[135];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i152 = 0; c3_i152 < 135; c3_i152++) {
    c3_b_inData[c3_i152] = (*(char_T (*)[135])c3_inData)[c3_i152];
  }

  for (c3_i153 = 0; c3_i153 < 135; c3_i153++) {
    c3_u[c3_i153] = c3_b_inData[c3_i153];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 135),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_cd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i154;
  real_T c3_b_inData[135];
  int32_T c3_i155;
  real_T c3_u[135];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i154 = 0; c3_i154 < 135; c3_i154++) {
    c3_b_inData[c3_i154] = (*(real_T (*)[135])c3_inData)[c3_i154];
  }

  for (c3_i155 = 0; c3_i155 < 135; c3_i155++) {
    c3_u[c3_i155] = c3_b_inData[c3_i155];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 135), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_dd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i156;
  char_T c3_b_inData[131];
  int32_T c3_i157;
  char_T c3_u[131];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i156 = 0; c3_i156 < 131; c3_i156++) {
    c3_b_inData[c3_i156] = (*(char_T (*)[131])c3_inData)[c3_i156];
  }

  for (c3_i157 = 0; c3_i157 < 131; c3_i157++) {
    c3_u[c3_i157] = c3_b_inData[c3_i157];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 131),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ed_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i158;
  real_T c3_b_inData[131];
  int32_T c3_i159;
  real_T c3_u[131];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i158 = 0; c3_i158 < 131; c3_i158++) {
    c3_b_inData[c3_i158] = (*(real_T (*)[131])c3_inData)[c3_i158];
  }

  for (c3_i159 = 0; c3_i159 < 131; c3_i159++) {
    c3_u[c3_i159] = c3_b_inData[c3_i159];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 131), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_fd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i160;
  char_T c3_b_inData[134];
  int32_T c3_i161;
  char_T c3_u[134];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i160 = 0; c3_i160 < 134; c3_i160++) {
    c3_b_inData[c3_i160] = (*(char_T (*)[134])c3_inData)[c3_i160];
  }

  for (c3_i161 = 0; c3_i161 < 134; c3_i161++) {
    c3_u[c3_i161] = c3_b_inData[c3_i161];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 134),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_gd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i162;
  real_T c3_b_inData[134];
  int32_T c3_i163;
  real_T c3_u[134];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i162 = 0; c3_i162 < 134; c3_i162++) {
    c3_b_inData[c3_i162] = (*(real_T (*)[134])c3_inData)[c3_i162];
  }

  for (c3_i163 = 0; c3_i163 < 134; c3_i163++) {
    c3_u[c3_i163] = c3_b_inData[c3_i163];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 134), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_hd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i164;
  char_T c3_b_inData[109];
  int32_T c3_i165;
  char_T c3_u[109];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i164 = 0; c3_i164 < 109; c3_i164++) {
    c3_b_inData[c3_i164] = (*(char_T (*)[109])c3_inData)[c3_i164];
  }

  for (c3_i165 = 0; c3_i165 < 109; c3_i165++) {
    c3_u[c3_i165] = c3_b_inData[c3_i165];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_id_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i166;
  real_T c3_b_inData[109];
  int32_T c3_i167;
  real_T c3_u[109];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i166 = 0; c3_i166 < 109; c3_i166++) {
    c3_b_inData[c3_i166] = (*(real_T (*)[109])c3_inData)[c3_i166];
  }

  for (c3_i167 = 0; c3_i167 < 109; c3_i167++) {
    c3_u[c3_i167] = c3_b_inData[c3_i167];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_jd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i168;
  char_T c3_b_inData[110];
  int32_T c3_i169;
  char_T c3_u[110];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i168 = 0; c3_i168 < 110; c3_i168++) {
    c3_b_inData[c3_i168] = (*(char_T (*)[110])c3_inData)[c3_i168];
  }

  for (c3_i169 = 0; c3_i169 < 110; c3_i169++) {
    c3_u[c3_i169] = c3_b_inData[c3_i169];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 110),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_kd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i170;
  real_T c3_b_inData[110];
  int32_T c3_i171;
  real_T c3_u[110];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i170 = 0; c3_i170 < 110; c3_i170++) {
    c3_b_inData[c3_i170] = (*(real_T (*)[110])c3_inData)[c3_i170];
  }

  for (c3_i171 = 0; c3_i171 < 110; c3_i171++) {
    c3_u[c3_i171] = c3_b_inData[c3_i171];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 110), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ld_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i172;
  char_T c3_b_inData[111];
  int32_T c3_i173;
  char_T c3_u[111];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i172 = 0; c3_i172 < 111; c3_i172++) {
    c3_b_inData[c3_i172] = (*(char_T (*)[111])c3_inData)[c3_i172];
  }

  for (c3_i173 = 0; c3_i173 < 111; c3_i173++) {
    c3_u[c3_i173] = c3_b_inData[c3_i173];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 111),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_md_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i174;
  real_T c3_b_inData[111];
  int32_T c3_i175;
  real_T c3_u[111];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i174 = 0; c3_i174 < 111; c3_i174++) {
    c3_b_inData[c3_i174] = (*(real_T (*)[111])c3_inData)[c3_i174];
  }

  for (c3_i175 = 0; c3_i175 < 111; c3_i175++) {
    c3_u[c3_i175] = c3_b_inData[c3_i175];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 111), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_nd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i176;
  char_T c3_b_inData[112];
  int32_T c3_i177;
  char_T c3_u[112];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i176 = 0; c3_i176 < 112; c3_i176++) {
    c3_b_inData[c3_i176] = (*(char_T (*)[112])c3_inData)[c3_i176];
  }

  for (c3_i177 = 0; c3_i177 < 112; c3_i177++) {
    c3_u[c3_i177] = c3_b_inData[c3_i177];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 112),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_od_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i178;
  real_T c3_b_inData[112];
  int32_T c3_i179;
  real_T c3_u[112];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i178 = 0; c3_i178 < 112; c3_i178++) {
    c3_b_inData[c3_i178] = (*(real_T (*)[112])c3_inData)[c3_i178];
  }

  for (c3_i179 = 0; c3_i179 < 112; c3_i179++) {
    c3_u[c3_i179] = c3_b_inData[c3_i179];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 112), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_pd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i180;
  char_T c3_b_inData[114];
  int32_T c3_i181;
  char_T c3_u[114];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i180 = 0; c3_i180 < 114; c3_i180++) {
    c3_b_inData[c3_i180] = (*(char_T (*)[114])c3_inData)[c3_i180];
  }

  for (c3_i181 = 0; c3_i181 < 114; c3_i181++) {
    c3_u[c3_i181] = c3_b_inData[c3_i181];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 114),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_qd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i182;
  real_T c3_b_inData[114];
  int32_T c3_i183;
  real_T c3_u[114];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i182 = 0; c3_i182 < 114; c3_i182++) {
    c3_b_inData[c3_i182] = (*(real_T (*)[114])c3_inData)[c3_i182];
  }

  for (c3_i183 = 0; c3_i183 < 114; c3_i183++) {
    c3_u[c3_i183] = c3_b_inData[c3_i183];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 114), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_rd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i184;
  char_T c3_b_inData[115];
  int32_T c3_i185;
  char_T c3_u[115];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i184 = 0; c3_i184 < 115; c3_i184++) {
    c3_b_inData[c3_i184] = (*(char_T (*)[115])c3_inData)[c3_i184];
  }

  for (c3_i185 = 0; c3_i185 < 115; c3_i185++) {
    c3_u[c3_i185] = c3_b_inData[c3_i185];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 115),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_sd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i186;
  real_T c3_b_inData[115];
  int32_T c3_i187;
  real_T c3_u[115];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i186 = 0; c3_i186 < 115; c3_i186++) {
    c3_b_inData[c3_i186] = (*(real_T (*)[115])c3_inData)[c3_i186];
  }

  for (c3_i187 = 0; c3_i187 < 115; c3_i187++) {
    c3_u[c3_i187] = c3_b_inData[c3_i187];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 115), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_td_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i188;
  char_T c3_b_inData[124];
  int32_T c3_i189;
  char_T c3_u[124];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i188 = 0; c3_i188 < 124; c3_i188++) {
    c3_b_inData[c3_i188] = (*(char_T (*)[124])c3_inData)[c3_i188];
  }

  for (c3_i189 = 0; c3_i189 < 124; c3_i189++) {
    c3_u[c3_i189] = c3_b_inData[c3_i189];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 124),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ud_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i190;
  real_T c3_b_inData[124];
  int32_T c3_i191;
  real_T c3_u[124];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i190 = 0; c3_i190 < 124; c3_i190++) {
    c3_b_inData[c3_i190] = (*(real_T (*)[124])c3_inData)[c3_i190];
  }

  for (c3_i191 = 0; c3_i191 < 124; c3_i191++) {
    c3_u[c3_i191] = c3_b_inData[c3_i191];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 124), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_vd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i192;
  char_T c3_b_inData[81];
  int32_T c3_i193;
  char_T c3_u[81];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i192 = 0; c3_i192 < 81; c3_i192++) {
    c3_b_inData[c3_i192] = (*(char_T (*)[81])c3_inData)[c3_i192];
  }

  for (c3_i193 = 0; c3_i193 < 81; c3_i193++) {
    c3_u[c3_i193] = c3_b_inData[c3_i193];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 81), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_wd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i194;
  real_T c3_b_inData[81];
  int32_T c3_i195;
  real_T c3_u[81];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i194 = 0; c3_i194 < 81; c3_i194++) {
    c3_b_inData[c3_i194] = (*(real_T (*)[81])c3_inData)[c3_i194];
  }

  for (c3_i195 = 0; c3_i195 < 81; c3_i195++) {
    c3_u[c3_i195] = c3_b_inData[c3_i195];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 81), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_xd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i196;
  char_T c3_b_inData[78];
  int32_T c3_i197;
  char_T c3_u[78];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i196 = 0; c3_i196 < 78; c3_i196++) {
    c3_b_inData[c3_i196] = (*(char_T (*)[78])c3_inData)[c3_i196];
  }

  for (c3_i197 = 0; c3_i197 < 78; c3_i197++) {
    c3_u[c3_i197] = c3_b_inData[c3_i197];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 78), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_yd_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i198;
  real_T c3_b_inData[78];
  int32_T c3_i199;
  real_T c3_u[78];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i198 = 0; c3_i198 < 78; c3_i198++) {
    c3_b_inData[c3_i198] = (*(real_T (*)[78])c3_inData)[c3_i198];
  }

  for (c3_i199 = 0; c3_i199 < 78; c3_i199++) {
    c3_u[c3_i199] = c3_b_inData[c3_i199];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 78), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ae_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i200;
  char_T c3_b_inData[147];
  int32_T c3_i201;
  char_T c3_u[147];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i200 = 0; c3_i200 < 147; c3_i200++) {
    c3_b_inData[c3_i200] = (*(char_T (*)[147])c3_inData)[c3_i200];
  }

  for (c3_i201 = 0; c3_i201 < 147; c3_i201++) {
    c3_u[c3_i201] = c3_b_inData[c3_i201];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 147),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_be_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i202;
  real_T c3_b_inData[147];
  int32_T c3_i203;
  real_T c3_u[147];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i202 = 0; c3_i202 < 147; c3_i202++) {
    c3_b_inData[c3_i202] = (*(real_T (*)[147])c3_inData)[c3_i202];
  }

  for (c3_i203 = 0; c3_i203 < 147; c3_i203++) {
    c3_u[c3_i203] = c3_b_inData[c3_i203];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 147), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ce_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i204;
  char_T c3_b_inData[164];
  int32_T c3_i205;
  char_T c3_u[164];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i204 = 0; c3_i204 < 164; c3_i204++) {
    c3_b_inData[c3_i204] = (*(char_T (*)[164])c3_inData)[c3_i204];
  }

  for (c3_i205 = 0; c3_i205 < 164; c3_i205++) {
    c3_u[c3_i205] = c3_b_inData[c3_i205];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 164),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_de_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i206;
  real_T c3_b_inData[164];
  int32_T c3_i207;
  real_T c3_u[164];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i206 = 0; c3_i206 < 164; c3_i206++) {
    c3_b_inData[c3_i206] = (*(real_T (*)[164])c3_inData)[c3_i206];
  }

  for (c3_i207 = 0; c3_i207 < 164; c3_i207++) {
    c3_u[c3_i207] = c3_b_inData[c3_i207];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 164), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_ee_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i208;
  char_T c3_b_inData[225];
  int32_T c3_i209;
  char_T c3_u[225];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i208 = 0; c3_i208 < 225; c3_i208++) {
    c3_b_inData[c3_i208] = (*(char_T (*)[225])c3_inData)[c3_i208];
  }

  for (c3_i209 = 0; c3_i209 < 225; c3_i209++) {
    c3_u[c3_i209] = c3_b_inData[c3_i209];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 225),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_fe_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i210;
  real_T c3_b_inData[225];
  int32_T c3_i211;
  real_T c3_u[225];
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i210 = 0; c3_i210 < 225; c3_i210++) {
    c3_b_inData[c3_i210] = (*(real_T (*)[225])c3_inData)[c3_i210];
  }

  for (c3_i211 = 0; c3_i211 < 225; c3_i211++) {
    c3_u[c3_i211] = c3_b_inData[c3_i211];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 225), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_ARP_01_lib_TruthTables_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/Maryam/Documents/maryam-research/code/Matlab-M+M/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1403737746U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_ge_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i212;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i212, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i212;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ARP_01_lib_TruthTables, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_ARP_01_lib_TruthTables), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_ARP_01_lib_TruthTables);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_ARP_01_lib_TruthTablesInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_ARP_01_lib_TruthTablesInstanceStruct
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

void sf_c3_ARP_01_lib_TruthTables_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1499575435U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3492746488U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3368815911U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(494505689U);
}

mxArray *sf_c3_ARP_01_lib_TruthTables_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Un8ryONr9tUefRJPWSEqjF");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ARP_01_lib_TruthTables_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ARP_01_lib_TruthTables_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_ARP_01_lib_TruthTables(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c3_ARP_01_lib_TruthTables\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ARP_01_lib_TruthTables_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_01_lib_TruthTablesMachineNumber_,
           3,
           18,
           0,
           0,
           36,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_ARP_01_lib_TruthTablesMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ARP_01_lib_TruthTablesMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_01_lib_TruthTablesMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,8,0,0,"");
          _SFD_SET_DATA_PROPS(1,9,0,0,"");
          _SFD_SET_DATA_PROPS(2,8,0,0,"");
          _SFD_SET_DATA_PROPS(3,9,0,0,"");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_SET_DATA_PROPS(5,9,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,9,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,9,0,0,"");
          _SFD_SET_DATA_PROPS(10,8,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_SET_DATA_PROPS(12,8,0,0,"");
          _SFD_SET_DATA_PROPS(13,9,0,0,"");
          _SFD_SET_DATA_PROPS(14,8,0,0,"");
          _SFD_SET_DATA_PROPS(15,9,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,9,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,9,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,9,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
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
          _SFD_STATE_INFO(11,0,2);
          _SFD_STATE_INFO(12,0,2);
          _SFD_STATE_INFO(13,0,2);
          _SFD_STATE_INFO(14,0,2);
          _SFD_STATE_INFO(15,0,2);
          _SFD_STATE_INFO(16,0,2);
          _SFD_STATE_INFO(17,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

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

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(13,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(13,0,"rockPoseTable",0,-1,401);
        _SFD_CV_INIT_EML_FCN(13,1,"aFcnTruthTableAction_1",401,-1,562);
        _SFD_CV_INIT_EML_FCN(13,2,"aFcnTruthTableAction_2",562,-1,723);
        _SFD_CV_INIT_EML_IF(13,1,0,225,255,286,399);
        _SFD_CV_INIT_EML_IF(13,1,1,286,320,351,399);
        _SFD_CV_INIT_EML(11,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(11,0,"paperPoseBradTable",0,-1,409);
        _SFD_CV_INIT_EML_FCN(11,1,"aFcnTruthTableAction_1",409,-1,565);
        _SFD_CV_INIT_EML_FCN(11,2,"aFcnTruthTableAction_2",565,-1,719);
        _SFD_CV_INIT_EML_IF(11,1,0,233,263,294,407);
        _SFD_CV_INIT_EML_IF(11,1,1,294,328,359,407);
        _SFD_CV_INIT_EML(12,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(12,0,"paperPoseRachelTable",0,-1,411);
        _SFD_CV_INIT_EML_FCN(12,1,"aFcnTruthTableAction_1",411,-1,577);
        _SFD_CV_INIT_EML_FCN(12,2,"aFcnTruthTableAction_2",577,-1,741);
        _SFD_CV_INIT_EML_IF(12,1,0,235,265,296,409);
        _SFD_CV_INIT_EML_IF(12,1,1,296,330,361,409);
        _SFD_CV_INIT_EML(14,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(14,0,"scissorsPoseBradTable",0,-1,418);
        _SFD_CV_INIT_EML_FCN(14,1,"aFcnTruthTableAction_1",418,-1,575);
        _SFD_CV_INIT_EML_FCN(14,2,"aFcnTruthTableAction_2",575,-1,734);
        _SFD_CV_INIT_EML_IF(14,1,0,242,272,303,416);
        _SFD_CV_INIT_EML_IF(14,1,1,303,337,368,416);
        _SFD_CV_INIT_EML(15,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(15,0,"scissorsPoseRachelTable",0,-1,420);
        _SFD_CV_INIT_EML_FCN(15,1,"aFcnTruthTableAction_1",420,-1,587);
        _SFD_CV_INIT_EML_FCN(15,2,"aFcnTruthTableAction_2",587,-1,756);
        _SFD_CV_INIT_EML_IF(15,1,0,244,274,305,418);
        _SFD_CV_INIT_EML_IF(15,1,1,305,339,370,418);
        _SFD_CV_INIT_EML(3,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"handPoseSBTable",0,-1,759);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",759,-1,995);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",995,-1,1229);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",1229,-1,1401);
        _SFD_CV_INIT_EML_FCN(3,4,"aFcnTruthTableAction_4",1401,-1,1569);
        _SFD_CV_INIT_EML_IF(3,1,0,453,483,514,757);
        _SFD_CV_INIT_EML_IF(3,1,1,514,548,579,757);
        _SFD_CV_INIT_EML_IF(3,1,2,579,613,644,757);
        _SFD_CV_INIT_EML_IF(3,1,3,644,678,709,757);
        _SFD_CV_INIT_EML(2,1,5,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"handPoseSBRachelTable",0,-1,765);
        _SFD_CV_INIT_EML_FCN(2,1,"aFcnTruthTableAction_1",765,-1,1005);
        _SFD_CV_INIT_EML_FCN(2,2,"aFcnTruthTableAction_2",1005,-1,1243);
        _SFD_CV_INIT_EML_FCN(2,3,"aFcnTruthTableAction_3",1243,-1,1417);
        _SFD_CV_INIT_EML_FCN(2,4,"aFcnTruthTableAction_4",1417,-1,1587);
        _SFD_CV_INIT_EML_IF(2,1,0,459,489,520,763);
        _SFD_CV_INIT_EML_IF(2,1,1,520,554,585,763);
        _SFD_CV_INIT_EML_IF(2,1,2,585,619,650,763);
        _SFD_CV_INIT_EML_IF(2,1,3,650,684,715,763);
        _SFD_CV_INIT_EML(16,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(16,0,"smileTable",0,-1,410);
        _SFD_CV_INIT_EML_FCN(16,1,"aFcnTruthTableAction_1",410,-1,701);
        _SFD_CV_INIT_EML_FCN(16,2,"aFcnTruthTableAction_2",701,-1,865);
        _SFD_CV_INIT_EML_IF(16,1,0,234,264,295,408);
        _SFD_CV_INIT_EML_IF(16,1,1,295,329,360,408);
        _SFD_CV_INIT_EML(6,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(6,0,"idlePoseBradTable",0,-1,2812);
        _SFD_CV_INIT_EML_FCN(6,1,"aFcnTruthTableAction_1",2812,-1,2983);
        _SFD_CV_INIT_EML_FCN(6,2,"aFcnTruthTableAction_2",2983,-1,3145);
        _SFD_CV_INIT_EML_FCN(6,3,"aFcnTruthTableAction_3",3145,-1,3312);
        _SFD_CV_INIT_EML_FCN(6,4,"aFcnTruthTableAction_4",3312,-1,3481);
        _SFD_CV_INIT_EML_FCN(6,5,"aFcnTruthTableAction_5",3481,-1,3650);
        _SFD_CV_INIT_EML_FCN(6,6,"aFcnTruthTableAction_6",3650,-1,3831);
        _SFD_CV_INIT_EML_FCN(6,7,"aFcnTruthTableAction_7",3831,-1,4010);
        _SFD_CV_INIT_EML_FCN(6,8,"aFcnTruthTableAction_8",4010,-1,4179);
        _SFD_CV_INIT_EML_FCN(6,9,"aFcnTruthTableAction_9",4179,-1,4346);
        _SFD_CV_INIT_EML_FCN(6,10,"aFcnTruthTableAction_10",4346,-1,4515);
        _SFD_CV_INIT_EML_FCN(6,11,"aFcnTruthTableAction_11",4515,-1,4681);
        _SFD_CV_INIT_EML_IF(6,1,0,1584,1614,1645,2810);
        _SFD_CV_INIT_EML_IF(6,1,1,1645,1679,1710,2810);
        _SFD_CV_INIT_EML_IF(6,1,2,1710,1744,1775,2810);
        _SFD_CV_INIT_EML_IF(6,1,3,1775,1809,1840,2810);
        _SFD_CV_INIT_EML_IF(6,1,4,1840,1874,1905,2810);
        _SFD_CV_INIT_EML_IF(6,1,5,1905,1939,1971,2810);
        _SFD_CV_INIT_EML_IF(6,1,6,1971,2005,2036,2810);
        _SFD_CV_INIT_EML_IF(6,1,7,2036,2070,2101,2810);
        _SFD_CV_INIT_EML_IF(6,1,8,2101,2135,2166,2810);
        _SFD_CV_INIT_EML_IF(6,1,9,2166,2201,2233,2810);
        _SFD_CV_INIT_EML_IF(6,1,10,2233,2268,2300,2810);
        _SFD_CV_INIT_EML_IF(6,1,11,2300,2335,2366,2810);
        _SFD_CV_INIT_EML_IF(6,1,12,2366,2401,2432,2810);
        _SFD_CV_INIT_EML_IF(6,1,13,2432,2467,2498,2810);
        _SFD_CV_INIT_EML_IF(6,1,14,2498,2533,2564,2810);
        _SFD_CV_INIT_EML_IF(6,1,15,2564,2599,2630,2810);
        _SFD_CV_INIT_EML_IF(6,1,16,2630,2665,2696,2810);
        _SFD_CV_INIT_EML_IF(6,1,17,2696,2731,2762,2810);
        _SFD_CV_INIT_EML(9,1,12,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(9,0,"idlePoseRachelTable",0,-1,2814);
        _SFD_CV_INIT_EML_FCN(9,1,"aFcnTruthTableAction_1",2814,-1,2995);
        _SFD_CV_INIT_EML_FCN(9,2,"aFcnTruthTableAction_2",2995,-1,3167);
        _SFD_CV_INIT_EML_FCN(9,3,"aFcnTruthTableAction_3",3167,-1,3344);
        _SFD_CV_INIT_EML_FCN(9,4,"aFcnTruthTableAction_4",3344,-1,3523);
        _SFD_CV_INIT_EML_FCN(9,5,"aFcnTruthTableAction_5",3523,-1,3702);
        _SFD_CV_INIT_EML_FCN(9,6,"aFcnTruthTableAction_6",3702,-1,3893);
        _SFD_CV_INIT_EML_FCN(9,7,"aFcnTruthTableAction_7",3893,-1,4082);
        _SFD_CV_INIT_EML_FCN(9,8,"aFcnTruthTableAction_8",4082,-1,4261);
        _SFD_CV_INIT_EML_FCN(9,9,"aFcnTruthTableAction_9",4261,-1,4438);
        _SFD_CV_INIT_EML_FCN(9,10,"aFcnTruthTableAction_10",4438,-1,4617);
        _SFD_CV_INIT_EML_FCN(9,11,"aFcnTruthTableAction_11",4617,-1,4793);
        _SFD_CV_INIT_EML_IF(9,1,0,1586,1616,1647,2812);
        _SFD_CV_INIT_EML_IF(9,1,1,1647,1681,1712,2812);
        _SFD_CV_INIT_EML_IF(9,1,2,1712,1746,1777,2812);
        _SFD_CV_INIT_EML_IF(9,1,3,1777,1811,1842,2812);
        _SFD_CV_INIT_EML_IF(9,1,4,1842,1876,1907,2812);
        _SFD_CV_INIT_EML_IF(9,1,5,1907,1941,1973,2812);
        _SFD_CV_INIT_EML_IF(9,1,6,1973,2007,2038,2812);
        _SFD_CV_INIT_EML_IF(9,1,7,2038,2072,2103,2812);
        _SFD_CV_INIT_EML_IF(9,1,8,2103,2137,2168,2812);
        _SFD_CV_INIT_EML_IF(9,1,9,2168,2203,2235,2812);
        _SFD_CV_INIT_EML_IF(9,1,10,2235,2270,2302,2812);
        _SFD_CV_INIT_EML_IF(9,1,11,2302,2337,2368,2812);
        _SFD_CV_INIT_EML_IF(9,1,12,2368,2403,2434,2812);
        _SFD_CV_INIT_EML_IF(9,1,13,2434,2469,2500,2812);
        _SFD_CV_INIT_EML_IF(9,1,14,2500,2535,2566,2812);
        _SFD_CV_INIT_EML_IF(9,1,15,2566,2601,2632,2812);
        _SFD_CV_INIT_EML_IF(9,1,16,2632,2667,2698,2812);
        _SFD_CV_INIT_EML_IF(9,1,17,2698,2733,2764,2812);
        _SFD_CV_INIT_EML(10,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(10,0,"initialPoseTable",0,-1,537);
        _SFD_CV_INIT_EML_FCN(10,1,"aFcnTruthTableAction_1",537,-1,681);
        _SFD_CV_INIT_EML_FCN(10,2,"aFcnTruthTableAction_2",681,-1,846);
        _SFD_CV_INIT_EML_FCN(10,3,"aFcnTruthTableAction_3",846,-1,1010);
        _SFD_CV_INIT_EML_IF(10,1,0,296,326,357,535);
        _SFD_CV_INIT_EML_IF(10,1,1,357,391,422,535);
        _SFD_CV_INIT_EML_IF(10,1,2,422,456,487,535);
        _SFD_CV_INIT_EML(17,1,4,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(17,0,"successTable",0,-1,566);
        _SFD_CV_INIT_EML_FCN(17,1,"aFcnTruthTableAction_1",566,-1,857);
        _SFD_CV_INIT_EML_FCN(17,2,"aFcnTruthTableAction_2",857,-1,1073);
        _SFD_CV_INIT_EML_FCN(17,3,"aFcnTruthTableAction_3",1073,-1,1324);
        _SFD_CV_INIT_EML_IF(17,1,0,325,355,386,564);
        _SFD_CV_INIT_EML_IF(17,1,1,386,420,451,564);
        _SFD_CV_INIT_EML_IF(17,1,2,451,485,516,564);
        _SFD_CV_INIT_EML(4,1,18,17,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"idleGazeTable",0,-1,2660);
        _SFD_CV_INIT_EML_FCN(4,1,"aFcnTruthTableAction_1",2660,-1,2846);
        _SFD_CV_INIT_EML_FCN(4,2,"aFcnTruthTableAction_2",2846,-1,3034);
        _SFD_CV_INIT_EML_FCN(4,3,"aFcnTruthTableAction_3",3034,-1,3216);
        _SFD_CV_INIT_EML_FCN(4,4,"aFcnTruthTableAction_4",3216,-1,3402);
        _SFD_CV_INIT_EML_FCN(4,5,"aFcnTruthTableAction_5",3402,-1,3592);
        _SFD_CV_INIT_EML_FCN(4,6,"aFcnTruthTableAction_6",3592,-1,3784);
        _SFD_CV_INIT_EML_FCN(4,7,"aFcnTruthTableAction_7",3784,-1,3978);
        _SFD_CV_INIT_EML_FCN(4,8,"aFcnTruthTableAction_8",3978,-1,4174);
        _SFD_CV_INIT_EML_FCN(4,9,"aFcnTruthTableAction_9",4174,-1,4374);
        _SFD_CV_INIT_EML_FCN(4,10,"aFcnTruthTableAction_10",4374,-1,4583);
        _SFD_CV_INIT_EML_FCN(4,11,"aFcnTruthTableAction_11",4583,-1,4794);
        _SFD_CV_INIT_EML_FCN(4,12,"aFcnTruthTableAction_12",4794,-1,5001);
        _SFD_CV_INIT_EML_FCN(4,13,"aFcnTruthTableAction_13",5001,-1,5206);
        _SFD_CV_INIT_EML_FCN(4,14,"aFcnTruthTableAction_14",5206,-1,5403);
        _SFD_CV_INIT_EML_FCN(4,15,"aFcnTruthTableAction_15",5403,-1,5606);
        _SFD_CV_INIT_EML_FCN(4,16,"aFcnTruthTableAction_16",5606,-1,5807);
        _SFD_CV_INIT_EML_FCN(4,17,"aFcnTruthTableAction_17",5807,-1,5972);
        _SFD_CV_INIT_EML_IF(4,1,0,1493,1523,1554,2658);
        _SFD_CV_INIT_EML_IF(4,1,1,1554,1588,1619,2658);
        _SFD_CV_INIT_EML_IF(4,1,2,1619,1653,1684,2658);
        _SFD_CV_INIT_EML_IF(4,1,3,1684,1718,1749,2658);
        _SFD_CV_INIT_EML_IF(4,1,4,1749,1783,1814,2658);
        _SFD_CV_INIT_EML_IF(4,1,5,1814,1848,1879,2658);
        _SFD_CV_INIT_EML_IF(4,1,6,1879,1913,1944,2658);
        _SFD_CV_INIT_EML_IF(4,1,7,1944,1978,2009,2658);
        _SFD_CV_INIT_EML_IF(4,1,8,2009,2043,2074,2658);
        _SFD_CV_INIT_EML_IF(4,1,9,2074,2109,2141,2658);
        _SFD_CV_INIT_EML_IF(4,1,10,2141,2176,2208,2658);
        _SFD_CV_INIT_EML_IF(4,1,11,2208,2243,2275,2658);
        _SFD_CV_INIT_EML_IF(4,1,12,2275,2310,2342,2658);
        _SFD_CV_INIT_EML_IF(4,1,13,2342,2377,2409,2658);
        _SFD_CV_INIT_EML_IF(4,1,14,2409,2444,2476,2658);
        _SFD_CV_INIT_EML_IF(4,1,15,2476,2511,2543,2658);
        _SFD_CV_INIT_EML_IF(4,1,16,2543,2578,2610,2658);
        _SFD_CV_INIT_EML(5,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"idlePoseBradSTable",0,-1,1284);
        _SFD_CV_INIT_EML_FCN(5,1,"aFcnTruthTableAction_1",1284,-1,1466);
        _SFD_CV_INIT_EML_FCN(5,2,"aFcnTruthTableAction_2",1466,-1,1649);
        _SFD_CV_INIT_EML_FCN(5,3,"aFcnTruthTableAction_3",1649,-1,1833);
        _SFD_CV_INIT_EML_FCN(5,4,"aFcnTruthTableAction_4",1833,-1,2019);
        _SFD_CV_INIT_EML_FCN(5,5,"aFcnTruthTableAction_5",2019,-1,2205);
        _SFD_CV_INIT_EML_FCN(5,6,"aFcnTruthTableAction_6",2205,-1,2396);
        _SFD_CV_INIT_EML_IF(5,1,0,718,748,779,1282);
        _SFD_CV_INIT_EML_IF(5,1,1,779,813,844,1282);
        _SFD_CV_INIT_EML_IF(5,1,2,844,878,909,1282);
        _SFD_CV_INIT_EML_IF(5,1,3,909,943,974,1282);
        _SFD_CV_INIT_EML_IF(5,1,4,974,1008,1039,1282);
        _SFD_CV_INIT_EML_IF(5,1,5,1039,1073,1104,1282);
        _SFD_CV_INIT_EML_IF(5,1,6,1104,1138,1169,1282);
        _SFD_CV_INIT_EML_IF(5,1,7,1169,1203,1234,1282);
        _SFD_CV_INIT_EML(8,1,7,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(8,0,"idlePoseRachelSTable",0,-1,1286);
        _SFD_CV_INIT_EML_FCN(8,1,"aFcnTruthTableAction_1",1286,-1,1478);
        _SFD_CV_INIT_EML_FCN(8,2,"aFcnTruthTableAction_2",1478,-1,1671);
        _SFD_CV_INIT_EML_FCN(8,3,"aFcnTruthTableAction_3",1671,-1,1865);
        _SFD_CV_INIT_EML_FCN(8,4,"aFcnTruthTableAction_4",1865,-1,2061);
        _SFD_CV_INIT_EML_FCN(8,5,"aFcnTruthTableAction_5",2061,-1,2257);
        _SFD_CV_INIT_EML_FCN(8,6,"aFcnTruthTableAction_6",2257,-1,2458);
        _SFD_CV_INIT_EML_IF(8,1,0,720,750,781,1284);
        _SFD_CV_INIT_EML_IF(8,1,1,781,815,846,1284);
        _SFD_CV_INIT_EML_IF(8,1,2,846,880,911,1284);
        _SFD_CV_INIT_EML_IF(8,1,3,911,945,976,1284);
        _SFD_CV_INIT_EML_IF(8,1,4,976,1010,1041,1284);
        _SFD_CV_INIT_EML_IF(8,1,5,1041,1075,1106,1284);
        _SFD_CV_INIT_EML_IF(8,1,6,1106,1140,1171,1284);
        _SFD_CV_INIT_EML_IF(8,1,7,1171,1205,1236,1284);
        _SFD_CV_INIT_EML(1,1,7,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"handPoseSBCompleteTable",0,-1,1096);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",1096,-1,1332);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",1332,-1,1566);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",1566,-1,1738);
        _SFD_CV_INIT_EML_FCN(1,4,"aFcnTruthTableAction_4",1738,-1,1907);
        _SFD_CV_INIT_EML_FCN(1,5,"aFcnTruthTableAction_5",1907,-1,2063);
        _SFD_CV_INIT_EML_FCN(1,6,"aFcnTruthTableAction_6",2063,-1,2216);
        _SFD_CV_INIT_EML_IF(1,1,0,660,690,721,1094);
        _SFD_CV_INIT_EML_IF(1,1,1,721,755,786,1094);
        _SFD_CV_INIT_EML_IF(1,1,2,786,820,851,1094);
        _SFD_CV_INIT_EML_IF(1,1,3,851,885,916,1094);
        _SFD_CV_INIT_EML_IF(1,1,4,916,950,981,1094);
        _SFD_CV_INIT_EML_IF(1,1,5,981,1015,1046,1094);
        _SFD_CV_INIT_EML(7,1,9,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"idlePoseCompleteTable",0,-1,1366);
        _SFD_CV_INIT_EML_FCN(7,1,"aFcnTruthTableAction_1",1366,-1,1582);
        _SFD_CV_INIT_EML_FCN(7,2,"aFcnTruthTableAction_2",1582,-1,1813);
        _SFD_CV_INIT_EML_FCN(7,3,"aFcnTruthTableAction_3",1813,-1,1948);
        _SFD_CV_INIT_EML_FCN(7,4,"aFcnTruthTableAction_4",1948,-1,2239);
        _SFD_CV_INIT_EML_FCN(7,5,"aFcnTruthTableAction_5",2239,-1,2531);
        _SFD_CV_INIT_EML_FCN(7,6,"aFcnTruthTableAction_6",2531,-1,2825);
        _SFD_CV_INIT_EML_FCN(7,7,"aFcnTruthTableAction_7",2825,-1,3120);
        _SFD_CV_INIT_EML_FCN(7,8,"aFcnTruthTableAction_8",3120,-1,3284);
        _SFD_CV_INIT_EML_IF(7,1,0,800,830,861,1364);
        _SFD_CV_INIT_EML_IF(7,1,1,861,895,926,1364);
        _SFD_CV_INIT_EML_IF(7,1,2,926,960,991,1364);
        _SFD_CV_INIT_EML_IF(7,1,3,991,1025,1056,1364);
        _SFD_CV_INIT_EML_IF(7,1,4,1056,1090,1121,1364);
        _SFD_CV_INIT_EML_IF(7,1,5,1121,1155,1186,1364);
        _SFD_CV_INIT_EML_IF(7,1,6,1186,1220,1251,1364);
        _SFD_CV_INIT_EML_IF(7,1,7,1251,1285,1316,1364);
        _SFD_CV_INIT_EML(0,1,27,18,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"boredGazeCompleteTable",0,-1,2823);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",2823,-1,3009);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",3009,-1,3197);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",3197,-1,3379);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",3379,-1,3565);
        _SFD_CV_INIT_EML_FCN(0,5,"aFcnTruthTableAction_5",3565,-1,3755);
        _SFD_CV_INIT_EML_FCN(0,6,"aFcnTruthTableAction_6",3755,-1,3947);
        _SFD_CV_INIT_EML_FCN(0,7,"aFcnTruthTableAction_7",3947,-1,4141);
        _SFD_CV_INIT_EML_FCN(0,8,"aFcnTruthTableAction_8",4141,-1,4337);
        _SFD_CV_INIT_EML_FCN(0,9,"aFcnTruthTableAction_9",4337,-1,4537);
        _SFD_CV_INIT_EML_FCN(0,10,"aFcnTruthTableAction_10",4537,-1,4746);
        _SFD_CV_INIT_EML_FCN(0,11,"aFcnTruthTableAction_11",4746,-1,4957);
        _SFD_CV_INIT_EML_FCN(0,12,"aFcnTruthTableAction_12",4957,-1,5164);
        _SFD_CV_INIT_EML_FCN(0,13,"aFcnTruthTableAction_13",5164,-1,5369);
        _SFD_CV_INIT_EML_FCN(0,14,"aFcnTruthTableAction_14",5369,-1,5566);
        _SFD_CV_INIT_EML_FCN(0,15,"aFcnTruthTableAction_15",5566,-1,5769);
        _SFD_CV_INIT_EML_FCN(0,16,"aFcnTruthTableAction_16",5769,-1,5970);
        _SFD_CV_INIT_EML_FCN(0,17,"aFcnTruthTableAction_17",5970,-1,6183);
        _SFD_CV_INIT_EML_FCN(0,18,"aFcnTruthTableAction_18",6183,-1,6398);
        _SFD_CV_INIT_EML_FCN(0,19,"aFcnTruthTableAction_19",6398,-1,6612);
        _SFD_CV_INIT_EML_FCN(0,20,"aFcnTruthTableAction_20",6612,-1,6825);
        _SFD_CV_INIT_EML_FCN(0,21,"aFcnTruthTableAction_21",6825,-1,7042);
        _SFD_CV_INIT_EML_FCN(0,22,"aFcnTruthTableAction_22",7042,-1,7261);
        _SFD_CV_INIT_EML_FCN(0,23,"aFcnTruthTableAction_23",7261,-1,7482);
        _SFD_CV_INIT_EML_FCN(0,24,"aFcnTruthTableAction_24",7482,-1,7705);
        _SFD_CV_INIT_EML_FCN(0,25,"aFcnTruthTableAction_25",7705,-1,7871);
        _SFD_CV_INIT_EML_FCN(0,26,"aFcnTruthTableAction_26",7871,-1,8168);
        _SFD_CV_INIT_EML_IF(0,1,0,1589,1619,1650,2821);
        _SFD_CV_INIT_EML_IF(0,1,1,1650,1684,1715,2821);
        _SFD_CV_INIT_EML_IF(0,1,2,1715,1749,1780,2821);
        _SFD_CV_INIT_EML_IF(0,1,3,1780,1814,1845,2821);
        _SFD_CV_INIT_EML_IF(0,1,4,1845,1879,1910,2821);
        _SFD_CV_INIT_EML_IF(0,1,5,1910,1944,1975,2821);
        _SFD_CV_INIT_EML_IF(0,1,6,1975,2009,2040,2821);
        _SFD_CV_INIT_EML_IF(0,1,7,2040,2074,2105,2821);
        _SFD_CV_INIT_EML_IF(0,1,8,2105,2139,2170,2821);
        _SFD_CV_INIT_EML_IF(0,1,9,2170,2205,2237,2821);
        _SFD_CV_INIT_EML_IF(0,1,10,2237,2272,2304,2821);
        _SFD_CV_INIT_EML_IF(0,1,11,2304,2339,2371,2821);
        _SFD_CV_INIT_EML_IF(0,1,12,2371,2406,2438,2821);
        _SFD_CV_INIT_EML_IF(0,1,13,2438,2473,2505,2821);
        _SFD_CV_INIT_EML_IF(0,1,14,2505,2540,2572,2821);
        _SFD_CV_INIT_EML_IF(0,1,15,2572,2607,2639,2821);
        _SFD_CV_INIT_EML_IF(0,1,16,2639,2674,2706,2821);
        _SFD_CV_INIT_EML_IF(0,1,17,2706,2741,2773,2821);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(1,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(2,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(3,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(13,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
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
        _SFD_SET_DATA_VALUE_PTR(30,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(31,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(32,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(33,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(34,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(35,(void *)(NULL));
        (void)chartInstance;
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_01_lib_TruthTablesMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "k4SIIUrgLBPB97TXtASgZE";
}

static void sf_opaque_initialize_c3_ARP_01_lib_TruthTables(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*) chartInstanceVar);
  initialize_c3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ARP_01_lib_TruthTables(void *chartInstanceVar)
{
  enable_c3_ARP_01_lib_TruthTables((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_ARP_01_lib_TruthTables(void *chartInstanceVar)
{
  disable_c3_ARP_01_lib_TruthTables((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_ARP_01_lib_TruthTables(void *chartInstanceVar)
{
  sf_gateway_c3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_ARP_01_lib_TruthTables
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ARP_01_lib_TruthTables();/* state var info */
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

extern void sf_internal_set_sim_state_c3_ARP_01_lib_TruthTables(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_ARP_01_lib_TruthTables();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_ARP_01_lib_TruthTables
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_ARP_01_lib_TruthTables(S);
}

static void sf_opaque_set_sim_state_c3_ARP_01_lib_TruthTables(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_ARP_01_lib_TruthTables(S, st);
}

static void sf_opaque_terminate_c3_ARP_01_lib_TruthTables(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_01_lib_TruthTables_optimization_info();
    }

    finalize_c3_ARP_01_lib_TruthTables
      ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ARP_01_lib_TruthTables
    ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ARP_01_lib_TruthTables(SimStruct *S)
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
    initialize_params_c3_ARP_01_lib_TruthTables
      ((SFc3_ARP_01_lib_TruthTablesInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ARP_01_lib_TruthTables(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_01_lib_TruthTables_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3331292908U));
  ssSetChecksum1(S,(2858171399U));
  ssSetChecksum2(S,(1857137805U));
  ssSetChecksum3(S,(1437507049U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ARP_01_lib_TruthTables(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ARP_01_lib_TruthTables(SimStruct *S)
{
  SFc3_ARP_01_lib_TruthTablesInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_ARP_01_lib_TruthTablesInstanceStruct *)utMalloc(sizeof
    (SFc3_ARP_01_lib_TruthTablesInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ARP_01_lib_TruthTablesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ARP_01_lib_TruthTables;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_ARP_01_lib_TruthTables;
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

void c3_ARP_01_lib_TruthTables_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ARP_01_lib_TruthTables(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ARP_01_lib_TruthTables(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ARP_01_lib_TruthTables(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ARP_01_lib_TruthTables_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
