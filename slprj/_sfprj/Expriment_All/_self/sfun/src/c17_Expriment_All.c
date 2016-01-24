/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Expriment_All_sfun.h"
#include "c17_Expriment_All.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Expriment_All_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c17_debug_family_names[43] = { "nargin", "nargout", "r1",
  "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "r13",
  "r14", "r15", "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23", "r24",
  "r25", "r26", "r27", "r28", "r29", "r30", "r31", "r32", "r33", "r34", "r35",
  "r36", "r37", "r38", "r39", "r40", "y" };

/* Function Declarations */
static void initialize_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void initialize_params_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance);
static void enable_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void disable_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance);
static void set_sim_state_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_st);
static void finalize_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void sf_gateway_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void c17_chartstep_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void initSimStructsc17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier, real_T
  c17_b_y[40]);
static void c17_b_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[40]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_c_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static real_T c17_floor(SFc17_Expriment_AllInstanceStruct *chartInstance, real_T
  c17_x);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_d_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_e_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Expriment_All, const char_T
  *c17_identifier);
static uint8_T c17_f_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_floor(SFc17_Expriment_AllInstanceStruct *chartInstance, real_T
  *c17_x);
static void init_dsm_address_info(SFc17_Expriment_AllInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_Expriment_All = 0U;
}

static void initialize_params_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_Expriment_All
  (SFc17_Expriment_AllInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[40];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_d_y)[40];
  c17_d_y = (real_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  for (c17_i0 = 0; c17_i0 < 40; c17_i0++) {
    c17_u[c17_i0] = (*c17_d_y)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 1, 40),
                false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_hoistedGlobal = chartInstance->c17_is_active_c17_Expriment_All;
  c17_b_u = c17_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[40];
  int32_T c17_i1;
  real_T (*c17_y)[40];
  c17_y = (real_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)), "y",
                       c17_dv0);
  for (c17_i1 = 0; c17_i1 < 40; c17_i1++) {
    (*c17_y)[c17_i1] = c17_dv0[c17_i1];
  }

  chartInstance->c17_is_active_c17_Expriment_All = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_Expriment_All");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_Expriment_All(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  int32_T c17_i2;
  real_T *c17_r1;
  real_T *c17_r2;
  real_T *c17_r3;
  real_T *c17_r4;
  real_T *c17_r5;
  real_T *c17_r6;
  real_T *c17_r7;
  real_T *c17_r8;
  real_T *c17_r9;
  real_T *c17_r10;
  real_T *c17_r11;
  real_T *c17_r12;
  real_T *c17_r13;
  real_T *c17_r14;
  real_T *c17_r15;
  real_T *c17_r16;
  real_T *c17_r17;
  real_T *c17_r18;
  real_T *c17_r19;
  real_T *c17_r20;
  real_T *c17_r21;
  real_T *c17_r22;
  real_T *c17_r23;
  real_T *c17_r24;
  real_T *c17_r25;
  real_T *c17_r26;
  real_T *c17_r27;
  real_T *c17_r28;
  real_T *c17_r29;
  real_T *c17_r30;
  real_T *c17_r31;
  real_T *c17_r32;
  real_T *c17_r33;
  real_T *c17_r34;
  real_T *c17_r35;
  real_T *c17_r36;
  real_T *c17_r37;
  real_T *c17_r38;
  real_T *c17_r39;
  real_T *c17_r40;
  real_T (*c17_y)[40];
  c17_r40 = (real_T *)ssGetInputPortSignal(chartInstance->S, 39);
  c17_r39 = (real_T *)ssGetInputPortSignal(chartInstance->S, 38);
  c17_r38 = (real_T *)ssGetInputPortSignal(chartInstance->S, 37);
  c17_r37 = (real_T *)ssGetInputPortSignal(chartInstance->S, 36);
  c17_r36 = (real_T *)ssGetInputPortSignal(chartInstance->S, 35);
  c17_r35 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
  c17_r34 = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
  c17_r33 = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
  c17_r32 = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
  c17_r31 = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
  c17_r30 = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
  c17_r29 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c17_r28 = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c17_r27 = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c17_r26 = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c17_r25 = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c17_r24 = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c17_r23 = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c17_r22 = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c17_r21 = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c17_r20 = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c17_r19 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c17_r18 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c17_r17 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c17_r16 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c17_r15 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c17_r14 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c17_r13 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c17_r12 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c17_r11 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c17_r10 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c17_r9 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c17_r8 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c17_r7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c17_r6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c17_r5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c17_r4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c17_r3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c17_r2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c17_y = (real_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c17_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c17_r1, 0U);
  chartInstance->c17_sfEvent = CALL_EVENT;
  c17_chartstep_c17_Expriment_All(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Expriment_AllMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c17_i2 = 0; c17_i2 < 40; c17_i2++) {
    _SFD_DATA_RANGE_CHECK((*c17_y)[c17_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c17_r2, 2U);
  _SFD_DATA_RANGE_CHECK(*c17_r3, 3U);
  _SFD_DATA_RANGE_CHECK(*c17_r4, 4U);
  _SFD_DATA_RANGE_CHECK(*c17_r5, 5U);
  _SFD_DATA_RANGE_CHECK(*c17_r6, 6U);
  _SFD_DATA_RANGE_CHECK(*c17_r7, 7U);
  _SFD_DATA_RANGE_CHECK(*c17_r8, 8U);
  _SFD_DATA_RANGE_CHECK(*c17_r9, 9U);
  _SFD_DATA_RANGE_CHECK(*c17_r10, 10U);
  _SFD_DATA_RANGE_CHECK(*c17_r11, 11U);
  _SFD_DATA_RANGE_CHECK(*c17_r12, 12U);
  _SFD_DATA_RANGE_CHECK(*c17_r13, 13U);
  _SFD_DATA_RANGE_CHECK(*c17_r14, 14U);
  _SFD_DATA_RANGE_CHECK(*c17_r15, 15U);
  _SFD_DATA_RANGE_CHECK(*c17_r16, 16U);
  _SFD_DATA_RANGE_CHECK(*c17_r17, 17U);
  _SFD_DATA_RANGE_CHECK(*c17_r18, 18U);
  _SFD_DATA_RANGE_CHECK(*c17_r19, 19U);
  _SFD_DATA_RANGE_CHECK(*c17_r20, 20U);
  _SFD_DATA_RANGE_CHECK(*c17_r21, 21U);
  _SFD_DATA_RANGE_CHECK(*c17_r22, 22U);
  _SFD_DATA_RANGE_CHECK(*c17_r23, 23U);
  _SFD_DATA_RANGE_CHECK(*c17_r24, 24U);
  _SFD_DATA_RANGE_CHECK(*c17_r25, 25U);
  _SFD_DATA_RANGE_CHECK(*c17_r26, 26U);
  _SFD_DATA_RANGE_CHECK(*c17_r27, 27U);
  _SFD_DATA_RANGE_CHECK(*c17_r28, 28U);
  _SFD_DATA_RANGE_CHECK(*c17_r29, 29U);
  _SFD_DATA_RANGE_CHECK(*c17_r30, 30U);
  _SFD_DATA_RANGE_CHECK(*c17_r31, 31U);
  _SFD_DATA_RANGE_CHECK(*c17_r32, 32U);
  _SFD_DATA_RANGE_CHECK(*c17_r33, 33U);
  _SFD_DATA_RANGE_CHECK(*c17_r34, 34U);
  _SFD_DATA_RANGE_CHECK(*c17_r35, 35U);
  _SFD_DATA_RANGE_CHECK(*c17_r36, 36U);
  _SFD_DATA_RANGE_CHECK(*c17_r37, 37U);
  _SFD_DATA_RANGE_CHECK(*c17_r38, 38U);
  _SFD_DATA_RANGE_CHECK(*c17_r39, 39U);
  _SFD_DATA_RANGE_CHECK(*c17_r40, 40U);
}

static void c17_chartstep_c17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  real_T c17_hoistedGlobal;
  real_T c17_b_hoistedGlobal;
  real_T c17_c_hoistedGlobal;
  real_T c17_d_hoistedGlobal;
  real_T c17_e_hoistedGlobal;
  real_T c17_f_hoistedGlobal;
  real_T c17_g_hoistedGlobal;
  real_T c17_h_hoistedGlobal;
  real_T c17_i_hoistedGlobal;
  real_T c17_j_hoistedGlobal;
  real_T c17_k_hoistedGlobal;
  real_T c17_l_hoistedGlobal;
  real_T c17_m_hoistedGlobal;
  real_T c17_n_hoistedGlobal;
  real_T c17_o_hoistedGlobal;
  real_T c17_p_hoistedGlobal;
  real_T c17_q_hoistedGlobal;
  real_T c17_r_hoistedGlobal;
  real_T c17_s_hoistedGlobal;
  real_T c17_t_hoistedGlobal;
  real_T c17_u_hoistedGlobal;
  real_T c17_v_hoistedGlobal;
  real_T c17_w_hoistedGlobal;
  real_T c17_x_hoistedGlobal;
  real_T c17_y_hoistedGlobal;
  real_T c17_ab_hoistedGlobal;
  real_T c17_bb_hoistedGlobal;
  real_T c17_cb_hoistedGlobal;
  real_T c17_db_hoistedGlobal;
  real_T c17_eb_hoistedGlobal;
  real_T c17_fb_hoistedGlobal;
  real_T c17_gb_hoistedGlobal;
  real_T c17_hb_hoistedGlobal;
  real_T c17_ib_hoistedGlobal;
  real_T c17_jb_hoistedGlobal;
  real_T c17_kb_hoistedGlobal;
  real_T c17_lb_hoistedGlobal;
  real_T c17_mb_hoistedGlobal;
  real_T c17_nb_hoistedGlobal;
  real_T c17_ob_hoistedGlobal;
  real_T c17_r1;
  real_T c17_r2;
  real_T c17_r3;
  real_T c17_r4;
  real_T c17_r5;
  real_T c17_r6;
  real_T c17_r7;
  real_T c17_r8;
  real_T c17_r9;
  real_T c17_r10;
  real_T c17_r11;
  real_T c17_r12;
  real_T c17_r13;
  real_T c17_r14;
  real_T c17_r15;
  real_T c17_r16;
  real_T c17_r17;
  real_T c17_r18;
  real_T c17_r19;
  real_T c17_r20;
  real_T c17_r21;
  real_T c17_r22;
  real_T c17_r23;
  real_T c17_r24;
  real_T c17_r25;
  real_T c17_r26;
  real_T c17_r27;
  real_T c17_r28;
  real_T c17_r29;
  real_T c17_r30;
  real_T c17_r31;
  real_T c17_r32;
  real_T c17_r33;
  real_T c17_r34;
  real_T c17_r35;
  real_T c17_r36;
  real_T c17_r37;
  real_T c17_r38;
  real_T c17_r39;
  real_T c17_r40;
  uint32_T c17_debug_family_var_map[43];
  real_T c17_nargin = 40.0;
  real_T c17_nargout = 1.0;
  real_T c17_y[40];
  int32_T c17_i3;
  real_T c17_x;
  real_T c17_b_x;
  real_T c17_c_x;
  real_T c17_d_x;
  real_T c17_e_x;
  real_T c17_f_x;
  real_T c17_g_x;
  real_T c17_h_x;
  real_T c17_i_x;
  real_T c17_j_x;
  real_T c17_k_x;
  real_T c17_l_x;
  real_T c17_m_x;
  real_T c17_n_x;
  real_T c17_o_x;
  real_T c17_p_x;
  real_T c17_q_x;
  real_T c17_r_x;
  real_T c17_s_x;
  real_T c17_t_x;
  real_T c17_u_x;
  real_T c17_v_x;
  real_T c17_w_x;
  real_T c17_x_x;
  real_T c17_y_x;
  real_T c17_ab_x;
  real_T c17_bb_x;
  real_T c17_cb_x;
  real_T c17_db_x;
  real_T c17_eb_x;
  real_T c17_fb_x;
  real_T c17_gb_x;
  real_T c17_hb_x;
  real_T c17_ib_x;
  real_T c17_jb_x;
  real_T c17_kb_x;
  real_T c17_lb_x;
  real_T c17_mb_x;
  real_T c17_nb_x;
  real_T c17_ob_x;
  real_T c17_pb_x;
  real_T c17_qb_x;
  real_T c17_rb_x;
  real_T c17_sb_x;
  real_T c17_tb_x;
  real_T c17_ub_x;
  real_T c17_vb_x;
  real_T c17_wb_x;
  real_T c17_xb_x;
  real_T c17_yb_x;
  real_T c17_ac_x;
  real_T c17_bc_x;
  real_T c17_cc_x;
  real_T c17_dc_x;
  real_T c17_ec_x;
  real_T c17_fc_x;
  real_T c17_gc_x;
  real_T c17_hc_x;
  real_T c17_ic_x;
  real_T c17_jc_x;
  real_T c17_kc_x;
  real_T c17_lc_x;
  real_T c17_mc_x;
  real_T c17_nc_x;
  real_T c17_oc_x;
  real_T c17_pc_x;
  real_T c17_qc_x;
  real_T c17_rc_x;
  real_T c17_sc_x;
  real_T c17_tc_x;
  real_T c17_uc_x;
  real_T c17_vc_x;
  real_T c17_wc_x;
  real_T c17_xc_x;
  real_T c17_yc_x;
  real_T c17_ad_x;
  int32_T c17_i4;
  real_T *c17_b_r1;
  real_T *c17_b_r2;
  real_T *c17_b_r3;
  real_T *c17_b_r4;
  real_T *c17_b_r5;
  real_T *c17_b_r6;
  real_T *c17_b_r7;
  real_T *c17_b_r8;
  real_T *c17_b_r9;
  real_T *c17_b_r10;
  real_T *c17_b_r11;
  real_T *c17_b_r12;
  real_T *c17_b_r13;
  real_T *c17_b_r14;
  real_T *c17_b_r15;
  real_T *c17_b_r16;
  real_T *c17_b_r17;
  real_T *c17_b_r18;
  real_T *c17_b_r19;
  real_T *c17_b_r20;
  real_T *c17_b_r21;
  real_T *c17_b_r22;
  real_T *c17_b_r23;
  real_T *c17_b_r24;
  real_T *c17_b_r25;
  real_T *c17_b_r26;
  real_T *c17_b_r27;
  real_T *c17_b_r28;
  real_T *c17_b_r29;
  real_T *c17_b_r30;
  real_T *c17_b_r31;
  real_T *c17_b_r32;
  real_T *c17_b_r33;
  real_T *c17_b_r34;
  real_T *c17_b_r35;
  real_T *c17_b_r36;
  real_T *c17_b_r37;
  real_T *c17_b_r38;
  real_T *c17_b_r39;
  real_T *c17_b_r40;
  real_T (*c17_b_y)[40];
  c17_b_r40 = (real_T *)ssGetInputPortSignal(chartInstance->S, 39);
  c17_b_r39 = (real_T *)ssGetInputPortSignal(chartInstance->S, 38);
  c17_b_r38 = (real_T *)ssGetInputPortSignal(chartInstance->S, 37);
  c17_b_r37 = (real_T *)ssGetInputPortSignal(chartInstance->S, 36);
  c17_b_r36 = (real_T *)ssGetInputPortSignal(chartInstance->S, 35);
  c17_b_r35 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
  c17_b_r34 = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
  c17_b_r33 = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
  c17_b_r32 = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
  c17_b_r31 = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
  c17_b_r30 = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
  c17_b_r29 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
  c17_b_r28 = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
  c17_b_r27 = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
  c17_b_r26 = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
  c17_b_r25 = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
  c17_b_r24 = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
  c17_b_r23 = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
  c17_b_r22 = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
  c17_b_r21 = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
  c17_b_r20 = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c17_b_r19 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c17_b_r18 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c17_b_r17 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c17_b_r16 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c17_b_r15 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c17_b_r14 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c17_b_r13 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c17_b_r12 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c17_b_r11 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c17_b_r10 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c17_b_r9 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c17_b_r8 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c17_b_r7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c17_b_r6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c17_b_r5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c17_b_r4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c17_b_r3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c17_b_r2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c17_b_y = (real_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_b_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c17_sfEvent);
  c17_hoistedGlobal = *c17_b_r1;
  c17_b_hoistedGlobal = *c17_b_r2;
  c17_c_hoistedGlobal = *c17_b_r3;
  c17_d_hoistedGlobal = *c17_b_r4;
  c17_e_hoistedGlobal = *c17_b_r5;
  c17_f_hoistedGlobal = *c17_b_r6;
  c17_g_hoistedGlobal = *c17_b_r7;
  c17_h_hoistedGlobal = *c17_b_r8;
  c17_i_hoistedGlobal = *c17_b_r9;
  c17_j_hoistedGlobal = *c17_b_r10;
  c17_k_hoistedGlobal = *c17_b_r11;
  c17_l_hoistedGlobal = *c17_b_r12;
  c17_m_hoistedGlobal = *c17_b_r13;
  c17_n_hoistedGlobal = *c17_b_r14;
  c17_o_hoistedGlobal = *c17_b_r15;
  c17_p_hoistedGlobal = *c17_b_r16;
  c17_q_hoistedGlobal = *c17_b_r17;
  c17_r_hoistedGlobal = *c17_b_r18;
  c17_s_hoistedGlobal = *c17_b_r19;
  c17_t_hoistedGlobal = *c17_b_r20;
  c17_u_hoistedGlobal = *c17_b_r21;
  c17_v_hoistedGlobal = *c17_b_r22;
  c17_w_hoistedGlobal = *c17_b_r23;
  c17_x_hoistedGlobal = *c17_b_r24;
  c17_y_hoistedGlobal = *c17_b_r25;
  c17_ab_hoistedGlobal = *c17_b_r26;
  c17_bb_hoistedGlobal = *c17_b_r27;
  c17_cb_hoistedGlobal = *c17_b_r28;
  c17_db_hoistedGlobal = *c17_b_r29;
  c17_eb_hoistedGlobal = *c17_b_r30;
  c17_fb_hoistedGlobal = *c17_b_r31;
  c17_gb_hoistedGlobal = *c17_b_r32;
  c17_hb_hoistedGlobal = *c17_b_r33;
  c17_ib_hoistedGlobal = *c17_b_r34;
  c17_jb_hoistedGlobal = *c17_b_r35;
  c17_kb_hoistedGlobal = *c17_b_r36;
  c17_lb_hoistedGlobal = *c17_b_r37;
  c17_mb_hoistedGlobal = *c17_b_r38;
  c17_nb_hoistedGlobal = *c17_b_r39;
  c17_ob_hoistedGlobal = *c17_b_r40;
  c17_r1 = c17_hoistedGlobal;
  c17_r2 = c17_b_hoistedGlobal;
  c17_r3 = c17_c_hoistedGlobal;
  c17_r4 = c17_d_hoistedGlobal;
  c17_r5 = c17_e_hoistedGlobal;
  c17_r6 = c17_f_hoistedGlobal;
  c17_r7 = c17_g_hoistedGlobal;
  c17_r8 = c17_h_hoistedGlobal;
  c17_r9 = c17_i_hoistedGlobal;
  c17_r10 = c17_j_hoistedGlobal;
  c17_r11 = c17_k_hoistedGlobal;
  c17_r12 = c17_l_hoistedGlobal;
  c17_r13 = c17_m_hoistedGlobal;
  c17_r14 = c17_n_hoistedGlobal;
  c17_r15 = c17_o_hoistedGlobal;
  c17_r16 = c17_p_hoistedGlobal;
  c17_r17 = c17_q_hoistedGlobal;
  c17_r18 = c17_r_hoistedGlobal;
  c17_r19 = c17_s_hoistedGlobal;
  c17_r20 = c17_t_hoistedGlobal;
  c17_r21 = c17_u_hoistedGlobal;
  c17_r22 = c17_v_hoistedGlobal;
  c17_r23 = c17_w_hoistedGlobal;
  c17_r24 = c17_x_hoistedGlobal;
  c17_r25 = c17_y_hoistedGlobal;
  c17_r26 = c17_ab_hoistedGlobal;
  c17_r27 = c17_bb_hoistedGlobal;
  c17_r28 = c17_cb_hoistedGlobal;
  c17_r29 = c17_db_hoistedGlobal;
  c17_r30 = c17_eb_hoistedGlobal;
  c17_r31 = c17_fb_hoistedGlobal;
  c17_r32 = c17_gb_hoistedGlobal;
  c17_r33 = c17_hb_hoistedGlobal;
  c17_r34 = c17_ib_hoistedGlobal;
  c17_r35 = c17_jb_hoistedGlobal;
  c17_r36 = c17_kb_hoistedGlobal;
  c17_r37 = c17_lb_hoistedGlobal;
  c17_r38 = c17_mb_hoistedGlobal;
  c17_r39 = c17_nb_hoistedGlobal;
  c17_r40 = c17_ob_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 43U, 43U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 0U, c17_b_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 1U, c17_b_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r1, 2U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r2, 3U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r3, 4U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r4, 5U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r5, 6U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r6, 7U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r7, 8U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r8, 9U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r9, 10U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r10, 11U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r11, 12U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r12, 13U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r13, 14U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r14, 15U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r15, 16U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r16, 17U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r17, 18U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r18, 19U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r19, 20U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r20, 21U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r21, 22U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r22, 23U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r23, 24U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r24, 25U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r25, 26U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r26, 27U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r27, 28U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r28, 29U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r29, 30U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r30, 31U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r31, 32U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r32, 33U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r33, 34U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r34, 35U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r35, 36U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r36, 37U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r37, 38U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r38, 39U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r39, 40U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_r40, 41U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_y, 42U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
  for (c17_i3 = 0; c17_i3 < 40; c17_i3++) {
    c17_y[c17_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  c17_y[0] = c17_r1;
  c17_b_floor(chartInstance, &c17_y[0]);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  c17_y[1] = c17_r2;
  c17_b_floor(chartInstance, &c17_y[1]);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 6);
  c17_x = c17_r3;
  c17_b_x = c17_x;
  c17_b_x = muDoubleScalarFloor(c17_b_x);
  c17_y[2] = c17_b_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 7);
  c17_c_x = c17_r4;
  c17_d_x = c17_c_x;
  c17_d_x = muDoubleScalarFloor(c17_d_x);
  c17_y[3] = c17_d_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 8);
  c17_e_x = c17_r5;
  c17_f_x = c17_e_x;
  c17_f_x = muDoubleScalarFloor(c17_f_x);
  c17_y[4] = c17_f_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  c17_g_x = c17_r6;
  c17_h_x = c17_g_x;
  c17_h_x = muDoubleScalarFloor(c17_h_x);
  c17_y[5] = c17_h_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
  c17_i_x = c17_r7;
  c17_j_x = c17_i_x;
  c17_j_x = muDoubleScalarFloor(c17_j_x);
  c17_y[6] = c17_j_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
  c17_k_x = c17_r8;
  c17_l_x = c17_k_x;
  c17_l_x = muDoubleScalarFloor(c17_l_x);
  c17_y[7] = c17_l_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 12);
  c17_m_x = c17_r9;
  c17_n_x = c17_m_x;
  c17_n_x = muDoubleScalarFloor(c17_n_x);
  c17_y[8] = c17_n_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 13);
  c17_o_x = c17_r10;
  c17_p_x = c17_o_x;
  c17_p_x = muDoubleScalarFloor(c17_p_x);
  c17_y[9] = c17_p_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_q_x = c17_r11;
  c17_r_x = c17_q_x;
  c17_r_x = muDoubleScalarFloor(c17_r_x);
  c17_y[10] = c17_r_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 15);
  c17_s_x = c17_r12;
  c17_t_x = c17_s_x;
  c17_t_x = muDoubleScalarFloor(c17_t_x);
  c17_y[11] = c17_t_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 16);
  c17_u_x = c17_r13;
  c17_v_x = c17_u_x;
  c17_v_x = muDoubleScalarFloor(c17_v_x);
  c17_y[12] = c17_v_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 17);
  c17_w_x = c17_r14;
  c17_x_x = c17_w_x;
  c17_x_x = muDoubleScalarFloor(c17_x_x);
  c17_y[13] = c17_x_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 18);
  c17_y_x = c17_r15;
  c17_ab_x = c17_y_x;
  c17_ab_x = muDoubleScalarFloor(c17_ab_x);
  c17_y[14] = c17_ab_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 19);
  c17_bb_x = c17_r16;
  c17_cb_x = c17_bb_x;
  c17_cb_x = muDoubleScalarFloor(c17_cb_x);
  c17_y[15] = c17_cb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 20);
  c17_db_x = c17_r17;
  c17_eb_x = c17_db_x;
  c17_eb_x = muDoubleScalarFloor(c17_eb_x);
  c17_y[16] = c17_eb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 21);
  c17_fb_x = c17_r18;
  c17_gb_x = c17_fb_x;
  c17_gb_x = muDoubleScalarFloor(c17_gb_x);
  c17_y[17] = c17_gb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 22);
  c17_hb_x = c17_r19;
  c17_ib_x = c17_hb_x;
  c17_ib_x = muDoubleScalarFloor(c17_ib_x);
  c17_y[18] = c17_ib_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 23);
  c17_jb_x = c17_r20;
  c17_kb_x = c17_jb_x;
  c17_kb_x = muDoubleScalarFloor(c17_kb_x);
  c17_y[19] = c17_kb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 24);
  c17_lb_x = c17_r21;
  c17_mb_x = c17_lb_x;
  c17_mb_x = muDoubleScalarFloor(c17_mb_x);
  c17_y[20] = c17_mb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 25);
  c17_nb_x = c17_r22;
  c17_ob_x = c17_nb_x;
  c17_ob_x = muDoubleScalarFloor(c17_ob_x);
  c17_y[21] = c17_ob_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 26);
  c17_pb_x = c17_r23;
  c17_qb_x = c17_pb_x;
  c17_qb_x = muDoubleScalarFloor(c17_qb_x);
  c17_y[22] = c17_qb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 27);
  c17_rb_x = c17_r24;
  c17_sb_x = c17_rb_x;
  c17_sb_x = muDoubleScalarFloor(c17_sb_x);
  c17_y[23] = c17_sb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 28);
  c17_tb_x = c17_r25;
  c17_ub_x = c17_tb_x;
  c17_ub_x = muDoubleScalarFloor(c17_ub_x);
  c17_y[24] = c17_ub_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 29);
  c17_vb_x = c17_r26;
  c17_wb_x = c17_vb_x;
  c17_wb_x = muDoubleScalarFloor(c17_wb_x);
  c17_y[25] = c17_wb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 30);
  c17_xb_x = c17_r27;
  c17_yb_x = c17_xb_x;
  c17_yb_x = muDoubleScalarFloor(c17_yb_x);
  c17_y[26] = c17_yb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 31);
  c17_ac_x = c17_r28;
  c17_bc_x = c17_ac_x;
  c17_bc_x = muDoubleScalarFloor(c17_bc_x);
  c17_y[27] = c17_bc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 32);
  c17_cc_x = c17_r29;
  c17_dc_x = c17_cc_x;
  c17_dc_x = muDoubleScalarFloor(c17_dc_x);
  c17_y[28] = c17_dc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 33);
  c17_ec_x = c17_r30;
  c17_fc_x = c17_ec_x;
  c17_fc_x = muDoubleScalarFloor(c17_fc_x);
  c17_y[29] = c17_fc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 34);
  c17_gc_x = c17_r31;
  c17_hc_x = c17_gc_x;
  c17_hc_x = muDoubleScalarFloor(c17_hc_x);
  c17_y[30] = c17_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 35);
  c17_ic_x = c17_r32;
  c17_jc_x = c17_ic_x;
  c17_jc_x = muDoubleScalarFloor(c17_jc_x);
  c17_y[31] = c17_jc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 36);
  c17_kc_x = c17_r33;
  c17_lc_x = c17_kc_x;
  c17_lc_x = muDoubleScalarFloor(c17_lc_x);
  c17_y[32] = c17_lc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 37);
  c17_mc_x = c17_r34;
  c17_nc_x = c17_mc_x;
  c17_nc_x = muDoubleScalarFloor(c17_nc_x);
  c17_y[33] = c17_nc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 38);
  c17_oc_x = c17_r35;
  c17_pc_x = c17_oc_x;
  c17_pc_x = muDoubleScalarFloor(c17_pc_x);
  c17_y[34] = c17_pc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 39);
  c17_qc_x = c17_r36;
  c17_rc_x = c17_qc_x;
  c17_rc_x = muDoubleScalarFloor(c17_rc_x);
  c17_y[35] = c17_rc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 40);
  c17_sc_x = c17_r37;
  c17_tc_x = c17_sc_x;
  c17_tc_x = muDoubleScalarFloor(c17_tc_x);
  c17_y[36] = c17_tc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 41);
  c17_uc_x = c17_r37;
  c17_vc_x = c17_uc_x;
  c17_vc_x = muDoubleScalarFloor(c17_vc_x);
  c17_y[37] = c17_vc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 42);
  c17_wc_x = c17_r39;
  c17_xc_x = c17_wc_x;
  c17_xc_x = muDoubleScalarFloor(c17_xc_x);
  c17_y[38] = c17_xc_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 43);
  c17_yc_x = c17_r40;
  c17_ad_x = c17_yc_x;
  c17_ad_x = muDoubleScalarFloor(c17_ad_x);
  c17_y[39] = c17_ad_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i4 = 0; c17_i4 < 40; c17_i4++) {
    (*c17_b_y)[c17_i4] = c17_y[c17_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c17_sfEvent);
}

static void initSimStructsc17_Expriment_All(SFc17_Expriment_AllInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  (void)c17_chartNumber;
  (void)c17_instanceNumber;
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i5;
  real_T c17_b_inData[40];
  int32_T c17_i6;
  real_T c17_u[40];
  const mxArray *c17_y = NULL;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i5 = 0; c17_i5 < 40; c17_i5++) {
    c17_b_inData[c17_i5] = (*(real_T (*)[40])c17_inData)[c17_i5];
  }

  for (c17_i6 = 0; c17_i6 < 40; c17_i6++) {
    c17_u[c17_i6] = c17_b_inData[c17_i6];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 1, 40),
                false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier, real_T
  c17_b_y[40])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
}

static void c17_b_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[40])
{
  real_T c17_dv1[40];
  int32_T c17_i7;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                40);
  for (c17_i7 = 0; c17_i7 < 40; c17_i7++) {
    c17_y[c17_i7] = c17_dv1[c17_i7];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_y;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_b_y[40];
  int32_T c17_i8;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_y = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
  for (c17_i8 = 0; c17_i8 < 40; c17_i8++) {
    (*(real_T (*)[40])c17_outData)[c17_i8] = c17_b_y[c17_i8];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_c_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_Expriment_All_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("floor"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static real_T c17_floor(SFc17_Expriment_AllInstanceStruct *chartInstance, real_T
  c17_x)
{
  real_T c17_b_x;
  c17_b_x = c17_x;
  c17_b_floor(chartInstance, &c17_b_x);
  return c17_b_x;
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_d_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i9;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i9, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i9;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_e_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Expriment_All, const char_T
  *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_Expriment_All), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_Expriment_All);
  return c17_y;
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_Expriment_AllInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_floor(SFc17_Expriment_AllInstanceStruct *chartInstance, real_T
  *c17_x)
{
  (void)chartInstance;
  *c17_x = muDoubleScalarFloor(*c17_x);
}

static void init_dsm_address_info(SFc17_Expriment_AllInstanceStruct
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

void sf_c17_Expriment_All_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2603526584U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1814441676U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(87608777U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3522372936U);
}

mxArray *sf_c17_Expriment_All_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MWzcAy1yDJPv0UVIgNtsuH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,40,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,24,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,25,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,26,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,27,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,28,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,29,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,30,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,31,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,32,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,34,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,34,"type",mxType);
    }

    mxSetField(mxData,34,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,35,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,35,"type",mxType);
    }

    mxSetField(mxData,35,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,36,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,36,"type",mxType);
    }

    mxSetField(mxData,36,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,37,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,37,"type",mxType);
    }

    mxSetField(mxData,37,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,38,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,38,"type",mxType);
    }

    mxSetField(mxData,38,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,39,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,39,"type",mxType);
    }

    mxSetField(mxData,39,"complexity",mxCreateDoubleScalar(0));
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
      pr[1] = (double)(40);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_Expriment_All_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_Expriment_All_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_Expriment_All(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c17_Expriment_All\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_Expriment_All_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_Expriment_AllInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_Expriment_AllInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Expriment_AllMachineNumber_,
           17,
           1,
           1,
           0,
           41,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Expriment_AllMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Expriment_AllMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Expriment_AllMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"r1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"r2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"r3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"r4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"r5");
          _SFD_SET_DATA_PROPS(6,1,1,0,"r6");
          _SFD_SET_DATA_PROPS(7,1,1,0,"r7");
          _SFD_SET_DATA_PROPS(8,1,1,0,"r8");
          _SFD_SET_DATA_PROPS(9,1,1,0,"r9");
          _SFD_SET_DATA_PROPS(10,1,1,0,"r10");
          _SFD_SET_DATA_PROPS(11,1,1,0,"r11");
          _SFD_SET_DATA_PROPS(12,1,1,0,"r12");
          _SFD_SET_DATA_PROPS(13,1,1,0,"r13");
          _SFD_SET_DATA_PROPS(14,1,1,0,"r14");
          _SFD_SET_DATA_PROPS(15,1,1,0,"r15");
          _SFD_SET_DATA_PROPS(16,1,1,0,"r16");
          _SFD_SET_DATA_PROPS(17,1,1,0,"r17");
          _SFD_SET_DATA_PROPS(18,1,1,0,"r18");
          _SFD_SET_DATA_PROPS(19,1,1,0,"r19");
          _SFD_SET_DATA_PROPS(20,1,1,0,"r20");
          _SFD_SET_DATA_PROPS(21,1,1,0,"r21");
          _SFD_SET_DATA_PROPS(22,1,1,0,"r22");
          _SFD_SET_DATA_PROPS(23,1,1,0,"r23");
          _SFD_SET_DATA_PROPS(24,1,1,0,"r24");
          _SFD_SET_DATA_PROPS(25,1,1,0,"r25");
          _SFD_SET_DATA_PROPS(26,1,1,0,"r26");
          _SFD_SET_DATA_PROPS(27,1,1,0,"r27");
          _SFD_SET_DATA_PROPS(28,1,1,0,"r28");
          _SFD_SET_DATA_PROPS(29,1,1,0,"r29");
          _SFD_SET_DATA_PROPS(30,1,1,0,"r30");
          _SFD_SET_DATA_PROPS(31,1,1,0,"r31");
          _SFD_SET_DATA_PROPS(32,1,1,0,"r32");
          _SFD_SET_DATA_PROPS(33,1,1,0,"r33");
          _SFD_SET_DATA_PROPS(34,1,1,0,"r34");
          _SFD_SET_DATA_PROPS(35,1,1,0,"r35");
          _SFD_SET_DATA_PROPS(36,1,1,0,"r36");
          _SFD_SET_DATA_PROPS(37,1,1,0,"r37");
          _SFD_SET_DATA_PROPS(38,1,1,0,"r38");
          _SFD_SET_DATA_PROPS(39,1,1,0,"r39");
          _SFD_SET_DATA_PROPS(40,1,1,0,"r40");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1134);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 40;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)
            c17_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c17_r1;
          real_T *c17_r2;
          real_T *c17_r3;
          real_T *c17_r4;
          real_T *c17_r5;
          real_T *c17_r6;
          real_T *c17_r7;
          real_T *c17_r8;
          real_T *c17_r9;
          real_T *c17_r10;
          real_T *c17_r11;
          real_T *c17_r12;
          real_T *c17_r13;
          real_T *c17_r14;
          real_T *c17_r15;
          real_T *c17_r16;
          real_T *c17_r17;
          real_T *c17_r18;
          real_T *c17_r19;
          real_T *c17_r20;
          real_T *c17_r21;
          real_T *c17_r22;
          real_T *c17_r23;
          real_T *c17_r24;
          real_T *c17_r25;
          real_T *c17_r26;
          real_T *c17_r27;
          real_T *c17_r28;
          real_T *c17_r29;
          real_T *c17_r30;
          real_T *c17_r31;
          real_T *c17_r32;
          real_T *c17_r33;
          real_T *c17_r34;
          real_T *c17_r35;
          real_T *c17_r36;
          real_T *c17_r37;
          real_T *c17_r38;
          real_T *c17_r39;
          real_T *c17_r40;
          real_T (*c17_y)[40];
          c17_r40 = (real_T *)ssGetInputPortSignal(chartInstance->S, 39);
          c17_r39 = (real_T *)ssGetInputPortSignal(chartInstance->S, 38);
          c17_r38 = (real_T *)ssGetInputPortSignal(chartInstance->S, 37);
          c17_r37 = (real_T *)ssGetInputPortSignal(chartInstance->S, 36);
          c17_r36 = (real_T *)ssGetInputPortSignal(chartInstance->S, 35);
          c17_r35 = (real_T *)ssGetInputPortSignal(chartInstance->S, 34);
          c17_r34 = (real_T *)ssGetInputPortSignal(chartInstance->S, 33);
          c17_r33 = (real_T *)ssGetInputPortSignal(chartInstance->S, 32);
          c17_r32 = (real_T *)ssGetInputPortSignal(chartInstance->S, 31);
          c17_r31 = (real_T *)ssGetInputPortSignal(chartInstance->S, 30);
          c17_r30 = (real_T *)ssGetInputPortSignal(chartInstance->S, 29);
          c17_r29 = (real_T *)ssGetInputPortSignal(chartInstance->S, 28);
          c17_r28 = (real_T *)ssGetInputPortSignal(chartInstance->S, 27);
          c17_r27 = (real_T *)ssGetInputPortSignal(chartInstance->S, 26);
          c17_r26 = (real_T *)ssGetInputPortSignal(chartInstance->S, 25);
          c17_r25 = (real_T *)ssGetInputPortSignal(chartInstance->S, 24);
          c17_r24 = (real_T *)ssGetInputPortSignal(chartInstance->S, 23);
          c17_r23 = (real_T *)ssGetInputPortSignal(chartInstance->S, 22);
          c17_r22 = (real_T *)ssGetInputPortSignal(chartInstance->S, 21);
          c17_r21 = (real_T *)ssGetInputPortSignal(chartInstance->S, 20);
          c17_r20 = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
          c17_r19 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
          c17_r18 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
          c17_r17 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
          c17_r16 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c17_r15 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c17_r14 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c17_r13 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c17_r12 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c17_r11 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c17_r10 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c17_r9 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c17_r8 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c17_r7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c17_r6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c17_r5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c17_r4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c17_r3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c17_r2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c17_y = (real_T (*)[40])ssGetOutputPortSignal(chartInstance->S, 1);
          c17_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c17_r1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c17_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c17_r2);
          _SFD_SET_DATA_VALUE_PTR(3U, c17_r3);
          _SFD_SET_DATA_VALUE_PTR(4U, c17_r4);
          _SFD_SET_DATA_VALUE_PTR(5U, c17_r5);
          _SFD_SET_DATA_VALUE_PTR(6U, c17_r6);
          _SFD_SET_DATA_VALUE_PTR(7U, c17_r7);
          _SFD_SET_DATA_VALUE_PTR(8U, c17_r8);
          _SFD_SET_DATA_VALUE_PTR(9U, c17_r9);
          _SFD_SET_DATA_VALUE_PTR(10U, c17_r10);
          _SFD_SET_DATA_VALUE_PTR(11U, c17_r11);
          _SFD_SET_DATA_VALUE_PTR(12U, c17_r12);
          _SFD_SET_DATA_VALUE_PTR(13U, c17_r13);
          _SFD_SET_DATA_VALUE_PTR(14U, c17_r14);
          _SFD_SET_DATA_VALUE_PTR(15U, c17_r15);
          _SFD_SET_DATA_VALUE_PTR(16U, c17_r16);
          _SFD_SET_DATA_VALUE_PTR(17U, c17_r17);
          _SFD_SET_DATA_VALUE_PTR(18U, c17_r18);
          _SFD_SET_DATA_VALUE_PTR(19U, c17_r19);
          _SFD_SET_DATA_VALUE_PTR(20U, c17_r20);
          _SFD_SET_DATA_VALUE_PTR(21U, c17_r21);
          _SFD_SET_DATA_VALUE_PTR(22U, c17_r22);
          _SFD_SET_DATA_VALUE_PTR(23U, c17_r23);
          _SFD_SET_DATA_VALUE_PTR(24U, c17_r24);
          _SFD_SET_DATA_VALUE_PTR(25U, c17_r25);
          _SFD_SET_DATA_VALUE_PTR(26U, c17_r26);
          _SFD_SET_DATA_VALUE_PTR(27U, c17_r27);
          _SFD_SET_DATA_VALUE_PTR(28U, c17_r28);
          _SFD_SET_DATA_VALUE_PTR(29U, c17_r29);
          _SFD_SET_DATA_VALUE_PTR(30U, c17_r30);
          _SFD_SET_DATA_VALUE_PTR(31U, c17_r31);
          _SFD_SET_DATA_VALUE_PTR(32U, c17_r32);
          _SFD_SET_DATA_VALUE_PTR(33U, c17_r33);
          _SFD_SET_DATA_VALUE_PTR(34U, c17_r34);
          _SFD_SET_DATA_VALUE_PTR(35U, c17_r35);
          _SFD_SET_DATA_VALUE_PTR(36U, c17_r36);
          _SFD_SET_DATA_VALUE_PTR(37U, c17_r37);
          _SFD_SET_DATA_VALUE_PTR(38U, c17_r38);
          _SFD_SET_DATA_VALUE_PTR(39U, c17_r39);
          _SFD_SET_DATA_VALUE_PTR(40U, c17_r40);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Expriment_AllMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5HqB6tv2x8LAhpkoKTWGxB";
}

static void sf_opaque_initialize_c17_Expriment_All(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar);
  initialize_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_Expriment_All(void *chartInstanceVar)
{
  enable_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_Expriment_All(void *chartInstanceVar)
{
  disable_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_Expriment_All(void *chartInstanceVar)
{
  sf_gateway_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_Expriment_All(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_Expriment_All
    ((SFc17_Expriment_AllInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_Expriment_All();/* state var info */
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

extern void sf_internal_set_sim_state_c17_Expriment_All(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c17_Expriment_All();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_Expriment_All(SimStruct* S)
{
  return sf_internal_get_sim_state_c17_Expriment_All(S);
}

static void sf_opaque_set_sim_state_c17_Expriment_All(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c17_Expriment_All(S, st);
}

static void sf_opaque_terminate_c17_Expriment_All(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_Expriment_AllInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Expriment_All_optimization_info();
    }

    finalize_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
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
  initSimStructsc17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_Expriment_All(SimStruct *S)
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
    initialize_params_c17_Expriment_All((SFc17_Expriment_AllInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Expriment_All_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 23, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 24, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 25, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 26, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 27, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 28, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 29, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 30, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 31, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 32, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 33, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 34, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 35, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 36, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 37, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 38, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 39, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,40);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 40; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(944149834U));
  ssSetChecksum1(S,(978276028U));
  ssSetChecksum2(S,(1308718065U));
  ssSetChecksum3(S,(4283136584U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_Expriment_All(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_Expriment_All(SimStruct *S)
{
  SFc17_Expriment_AllInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_Expriment_AllInstanceStruct *)utMalloc(sizeof
    (SFc17_Expriment_AllInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_Expriment_AllInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_Expriment_All;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_Expriment_All;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_Expriment_All;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_Expriment_All;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_Expriment_All;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_Expriment_All;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_Expriment_All;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_Expriment_All;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_Expriment_All;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_Expriment_All;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_Expriment_All;
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

void c17_Expriment_All_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_Expriment_All(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_Expriment_All(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_Expriment_All(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_Expriment_All_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
