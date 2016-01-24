/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_EP_IdleRandMerg_sfun.h"
#include "c17_Demo_EP_IdleRandMerg.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_EP_IdleRandMerg_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c17_debug_family_names[28] = { "nargin", "nargout", "r1",
  "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "r13",
  "r14", "r15", "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23", "r24",
  "r25", "y" };

/* Function Declarations */
static void initialize_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initialize_params_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void enable_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void disable_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c17_update_debugger_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void set_sim_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c17_st);
static void finalize_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void sf_gateway_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c17_chartstep_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initSimStructsc17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier, real_T
  c17_b_y[25]);
static void c17_b_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[25]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_c_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_d_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_e_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Demo_EP_IdleRandMerg, const
  char_T *c17_identifier);
static uint8_T c17_f_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void init_dsm_address_info(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_Demo_EP_IdleRandMerg = 0U;
}

static void initialize_params_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[25];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_d_y)[25];
  c17_d_y = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  for (c17_i0 = 0; c17_i0 < 25; c17_i0++) {
    c17_u[c17_i0] = (*c17_d_y)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 1, 25),
                false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_hoistedGlobal = chartInstance->c17_is_active_c17_Demo_EP_IdleRandMerg;
  c17_b_u = c17_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[25];
  int32_T c17_i1;
  real_T (*c17_y)[25];
  c17_y = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)), "y",
                       c17_dv0);
  for (c17_i1 = 0; c17_i1 < 25; c17_i1++) {
    (*c17_y)[c17_i1] = c17_dv0[c17_i1];
  }

  chartInstance->c17_is_active_c17_Demo_EP_IdleRandMerg = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_Demo_EP_IdleRandMerg");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_Demo_EP_IdleRandMerg(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
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
  real_T (*c17_y)[25];
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
  c17_y = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_r1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c17_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c17_r1, 0U);
  chartInstance->c17_sfEvent = CALL_EVENT;
  c17_chartstep_c17_Demo_EP_IdleRandMerg(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_EP_IdleRandMergMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c17_i2 = 0; c17_i2 < 25; c17_i2++) {
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
}

static void c17_chartstep_c17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
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
  uint32_T c17_debug_family_var_map[28];
  real_T c17_nargin = 25.0;
  real_T c17_nargout = 1.0;
  real_T c17_y[25];
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
  real_T (*c17_b_y)[25];
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
  c17_b_y = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 1);
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
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 28U, c17_debug_family_names,
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
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_y, 27U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
  for (c17_i3 = 0; c17_i3 < 25; c17_i3++) {
    c17_y[c17_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  c17_x = c17_r1;
  c17_b_x = c17_x;
  c17_b_x = muDoubleScalarFloor(c17_b_x);
  c17_y[0] = c17_b_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  c17_c_x = c17_r2;
  c17_d_x = c17_c_x;
  c17_d_x = muDoubleScalarFloor(c17_d_x);
  c17_y[1] = c17_d_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 6);
  c17_e_x = c17_r3;
  c17_f_x = c17_e_x;
  c17_f_x = muDoubleScalarFloor(c17_f_x);
  c17_y[2] = c17_f_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 7);
  c17_g_x = c17_r4;
  c17_h_x = c17_g_x;
  c17_h_x = muDoubleScalarFloor(c17_h_x);
  c17_y[3] = c17_h_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 8);
  c17_i_x = c17_r5;
  c17_j_x = c17_i_x;
  c17_j_x = muDoubleScalarFloor(c17_j_x);
  c17_y[4] = c17_j_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  c17_k_x = c17_r6;
  c17_l_x = c17_k_x;
  c17_l_x = muDoubleScalarFloor(c17_l_x);
  c17_y[5] = c17_l_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
  c17_m_x = c17_r7;
  c17_n_x = c17_m_x;
  c17_n_x = muDoubleScalarFloor(c17_n_x);
  c17_y[6] = c17_n_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
  c17_o_x = c17_r8;
  c17_p_x = c17_o_x;
  c17_p_x = muDoubleScalarFloor(c17_p_x);
  c17_y[7] = c17_p_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 12);
  c17_q_x = c17_r9;
  c17_r_x = c17_q_x;
  c17_r_x = muDoubleScalarFloor(c17_r_x);
  c17_y[8] = c17_r_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 13);
  c17_s_x = c17_r10;
  c17_t_x = c17_s_x;
  c17_t_x = muDoubleScalarFloor(c17_t_x);
  c17_y[9] = c17_t_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_u_x = c17_r11;
  c17_v_x = c17_u_x;
  c17_v_x = muDoubleScalarFloor(c17_v_x);
  c17_y[10] = c17_v_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 15);
  c17_w_x = c17_r12;
  c17_x_x = c17_w_x;
  c17_x_x = muDoubleScalarFloor(c17_x_x);
  c17_y[11] = c17_x_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 16);
  c17_y_x = c17_r13;
  c17_ab_x = c17_y_x;
  c17_ab_x = muDoubleScalarFloor(c17_ab_x);
  c17_y[12] = c17_ab_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 17);
  c17_bb_x = c17_r14;
  c17_cb_x = c17_bb_x;
  c17_cb_x = muDoubleScalarFloor(c17_cb_x);
  c17_y[13] = c17_cb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 18);
  c17_db_x = c17_r15;
  c17_eb_x = c17_db_x;
  c17_eb_x = muDoubleScalarFloor(c17_eb_x);
  c17_y[14] = c17_eb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 19);
  c17_fb_x = c17_r16;
  c17_gb_x = c17_fb_x;
  c17_gb_x = muDoubleScalarFloor(c17_gb_x);
  c17_y[15] = c17_gb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 20);
  c17_hb_x = c17_r17;
  c17_ib_x = c17_hb_x;
  c17_ib_x = muDoubleScalarFloor(c17_ib_x);
  c17_y[16] = c17_ib_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 21);
  c17_jb_x = c17_r18;
  c17_kb_x = c17_jb_x;
  c17_kb_x = muDoubleScalarFloor(c17_kb_x);
  c17_y[17] = c17_kb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 22);
  c17_lb_x = c17_r19;
  c17_mb_x = c17_lb_x;
  c17_mb_x = muDoubleScalarFloor(c17_mb_x);
  c17_y[18] = c17_mb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 23);
  c17_nb_x = c17_r20;
  c17_ob_x = c17_nb_x;
  c17_ob_x = muDoubleScalarFloor(c17_ob_x);
  c17_y[19] = c17_ob_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 24);
  c17_pb_x = c17_r21;
  c17_qb_x = c17_pb_x;
  c17_qb_x = muDoubleScalarFloor(c17_qb_x);
  c17_y[20] = c17_qb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 25);
  c17_rb_x = c17_r22;
  c17_sb_x = c17_rb_x;
  c17_sb_x = muDoubleScalarFloor(c17_sb_x);
  c17_y[21] = c17_sb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 26);
  c17_tb_x = c17_r23;
  c17_ub_x = c17_tb_x;
  c17_ub_x = muDoubleScalarFloor(c17_ub_x);
  c17_y[22] = c17_ub_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 27);
  c17_vb_x = c17_r24;
  c17_wb_x = c17_vb_x;
  c17_wb_x = muDoubleScalarFloor(c17_wb_x);
  c17_y[23] = c17_wb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 28);
  c17_xb_x = c17_r25;
  c17_yb_x = c17_xb_x;
  c17_yb_x = muDoubleScalarFloor(c17_yb_x);
  c17_y[24] = c17_yb_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i4 = 0; c17_i4 < 25; c17_i4++) {
    (*c17_b_y)[c17_i4] = c17_y[c17_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c17_sfEvent);
}

static void initSimStructsc17_Demo_EP_IdleRandMerg
  (SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
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
  real_T c17_b_inData[25];
  int32_T c17_i6;
  real_T c17_u[25];
  const mxArray *c17_y = NULL;
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i5 = 0; c17_i5 < 25; c17_i5++) {
    c17_b_inData[c17_i5] = (*(real_T (*)[25])c17_inData)[c17_i5];
  }

  for (c17_i6 = 0; c17_i6 < 25; c17_i6++) {
    c17_u[c17_i6] = c17_b_inData[c17_i6];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 1, 25),
                false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_y, const char_T *c17_identifier, real_T
  c17_b_y[25])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
}

static void c17_b_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[25])
{
  real_T c17_dv1[25];
  int32_T c17_i7;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                25);
  for (c17_i7 = 0; c17_i7 < 25; c17_i7++) {
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
  real_T c17_b_y[25];
  int32_T c17_i8;
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c17_y = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
  for (c17_i8 = 0; c17_i8 < 25; c17_i8++) {
    (*(real_T (*)[25])c17_outData)[c17_i8] = c17_b_y[c17_i8];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_c_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
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
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
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

const mxArray *sf_c17_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void)
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

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_d_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
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
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
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

static uint8_T c17_e_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Demo_EP_IdleRandMerg, const
  char_T *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_Demo_EP_IdleRandMerg), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_Demo_EP_IdleRandMerg);
  return c17_y;
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_Demo_EP_IdleRandMergInstanceStruct
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

static void init_dsm_address_info(SFc17_Demo_EP_IdleRandMergInstanceStruct
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

void sf_c17_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4095725682U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3991474798U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2594714776U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3989615758U);
}

mxArray *sf_c17_Demo_EP_IdleRandMerg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("VpuJLrkkZFJktQtxLkPKvE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,25,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_Demo_EP_IdleRandMerg_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_Demo_EP_IdleRandMerg_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_Demo_EP_IdleRandMerg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c17_Demo_EP_IdleRandMerg\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_Demo_EP_IdleRandMerg_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_EP_IdleRandMergMachineNumber_,
           17,
           1,
           1,
           0,
           26,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_EP_IdleRandMergMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_EP_IdleRandMergMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_EP_IdleRandMergMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,709);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 25;
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
          real_T (*c17_y)[25];
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
          c17_y = (real_T (*)[25])ssGetOutputPortSignal(chartInstance->S, 1);
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
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_EP_IdleRandMergMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5eBYl8Ef1qpoEitlDh9wl";
}

static void sf_opaque_initialize_c17_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_Demo_EP_IdleRandMerg
    ((SFc17_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
  initialize_c17_Demo_EP_IdleRandMerg((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  enable_c17_Demo_EP_IdleRandMerg((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c17_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  disable_c17_Demo_EP_IdleRandMerg((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  sf_gateway_c17_Demo_EP_IdleRandMerg((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_Demo_EP_IdleRandMerg
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_Demo_EP_IdleRandMerg
    ((SFc17_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_Demo_EP_IdleRandMerg();/* state var info */
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

extern void sf_internal_set_sim_state_c17_Demo_EP_IdleRandMerg(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c17_Demo_EP_IdleRandMerg();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_Demo_EP_IdleRandMerg
    ((SFc17_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_Demo_EP_IdleRandMerg(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c17_Demo_EP_IdleRandMerg(S);
}

static void sf_opaque_set_sim_state_c17_Demo_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c17_Demo_EP_IdleRandMerg(S, st);
}

static void sf_opaque_terminate_c17_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_EP_IdleRandMerg_optimization_info();
    }

    finalize_c17_Demo_EP_IdleRandMerg((SFc17_Demo_EP_IdleRandMergInstanceStruct*)
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
  initSimStructsc17_Demo_EP_IdleRandMerg
    ((SFc17_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_Demo_EP_IdleRandMerg(SimStruct *S)
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
    initialize_params_c17_Demo_EP_IdleRandMerg
      ((SFc17_Demo_EP_IdleRandMergInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_EP_IdleRandMerg_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,25);
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
      for (inPortIdx=0; inPortIdx < 25; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1791135528U));
  ssSetChecksum1(S,(471279932U));
  ssSetChecksum2(S,(2854859400U));
  ssSetChecksum3(S,(1415329076U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_Demo_EP_IdleRandMerg(SimStruct *S)
{
  SFc17_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_Demo_EP_IdleRandMergInstanceStruct *)utMalloc(sizeof
    (SFc17_Demo_EP_IdleRandMergInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_Demo_EP_IdleRandMergInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_Demo_EP_IdleRandMerg;
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

void c17_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_Demo_EP_IdleRandMerg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_Demo_EP_IdleRandMerg_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
