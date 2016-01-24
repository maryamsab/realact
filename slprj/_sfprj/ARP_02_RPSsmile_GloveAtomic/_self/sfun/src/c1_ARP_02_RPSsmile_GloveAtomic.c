/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ARP_02_RPSsmile_GloveAtomic_sfun.h"
#include "c1_ARP_02_RPSsmile_GloveAtomic.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ARP_02_RPSsmile_GloveAtomic_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_secs                  (0)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const mxArray *c1_subchartSimStateInfo;
static const mxArray *c1_b_subchartSimStateInfo;
static const mxArray *c1_c_subchartSimStateInfo;
static const mxArray *c1_d_subchartSimStateInfo;
static boolean_T c1_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initialize_params_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void enable_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void disable_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_st);
static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void finalize_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void sf_gateway_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void initSimStructsc1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int8_T c1_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_c_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_b_tp_RPSGameBrad, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_gameState, const char_T *c1_identifier);
static real_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_b_randomH, const char_T *c1_identifier,
  real_T c1_y[2]);
static void c1_h_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_e_subchartSimStateInfo, const char_T *c1_identifier);
static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId);
static real_T c1_get_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b);
static real_T c1_get_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static void c1_set_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b);
static real_T c1_get_wristRotate(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b);
static void c1_set_wristRotate(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c);
static real_T *c1_access_wristRotate
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T c1_b);
static void init_dsm_address_info(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  real_T *c1_gameState;
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
  c1_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  sf_exported_auto_initc7_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_initc6_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_initc5_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_initc4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct);
  _sfTime_ = sf_get_time(chartInstance->S);
  c1_subchartSimStateInfo = NULL;
  c1_b_subchartSimStateInfo = NULL;
  c1_c_subchartSimStateInfo = NULL;
  c1_d_subchartSimStateInfo = NULL;
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_RPSGameBrad = 0U;
  chartInstance->c1_tp_RPSGameBrad = 0U;
  chartInstance->c1_is_active_idleGazeBrad = 0U;
  chartInstance->c1_tp_idleGazeBrad = 0U;
  chartInstance->c1_is_active_idlePoseBrad = 0U;
  chartInstance->c1_tp_idlePoseBrad = 0U;
  chartInstance->c1_is_active_timeBasedSmileBrad = 0U;
  chartInstance->c1_tp_timeBasedSmileBrad = 0U;
  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic = 0U;
  c1_set_temp(chartInstance, 0, 0.0);
  c1_set_diff(chartInstance, 0, 0.0);
  c1_set_uHand(chartInstance, 0, 0.0);
  c1_set_bHand(chartInstance, 0, 0.0);
  c1_set_smileYN(chartInstance, 0, 0.0);
  c1_set_bored(chartInstance, 0, 0.0);
  c1_set_BOREDOMT(chartInstance, 0, 0.0);
  c1_set_randomG(chartInstance, 0, 0.0);
  c1_set_randomP(chartInstance, 0, 0.0);
  c1_set_pose(chartInstance, 0, 0.0);
  c1_set_b(chartInstance, 0, 0.0);
  c1_set_r(chartInstance, 0, 0.0);
  c1_set_p(chartInstance, 0, 0.0);
  c1_set_s(chartInstance, 0, 0.0);
  c1_set_randomD(chartInstance, 0, 0.0);
  c1_set_wristRotate(chartInstance, 0, 0.0);
  c1_set_smileN(chartInstance, 0, 0.0);
  c1_set_pSmile(chartInstance, 0, 0.0);
  c1_set_avert(chartInstance, 0, 0.0);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c1_gameState = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c1_bradHand = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *c1_userHand = 3.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *c1_win = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *c1_bWinT = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *c1_uWinT = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    *c1_round = 0.0;
  }
}

static void initialize_params_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_is_active_RPSGameBrad == 1U) {
    sf_exported_auto_enablec7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idleGazeBrad == 1U) {
    sf_exported_auto_enablec6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_enablec5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_timeBasedSmileBrad == 1U) {
    sf_exported_auto_enablec4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
  }
}

static void disable_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c1_is_active_RPSGameBrad == 1U) {
    sf_exported_auto_disablec7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idleGazeBrad == 1U) {
    sf_exported_auto_disablec6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_disablec5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_timeBasedSmileBrad == 1U) {
    sf_exported_auto_disablec4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
  }
}

static void c1_update_debugger_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_RPSGameBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_idleGazeBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_timeBasedSmileBrad == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
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
  int32_T c1_i0;
  real_T c1_t_u[2];
  const mxArray *c1_u_y = NULL;
  real_T c1_t_hoistedGlobal;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_u_hoistedGlobal;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_v_hoistedGlobal;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_w_hoistedGlobal;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_x_hoistedGlobal;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_y_hoistedGlobal;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T c1_ab_hoistedGlobal;
  real_T c1_bb_u;
  const mxArray *c1_cb_y = NULL;
  uint8_T c1_bb_hoistedGlobal;
  uint8_T c1_cb_u;
  const mxArray *c1_db_y = NULL;
  uint8_T c1_cb_hoistedGlobal;
  uint8_T c1_db_u;
  const mxArray *c1_eb_y = NULL;
  uint8_T c1_db_hoistedGlobal;
  uint8_T c1_eb_u;
  const mxArray *c1_fb_y = NULL;
  uint8_T c1_eb_hoistedGlobal;
  uint8_T c1_fb_u;
  const mxArray *c1_gb_y = NULL;
  uint8_T c1_fb_hoistedGlobal;
  uint8_T c1_gb_u;
  const mxArray *c1_hb_y = NULL;
  const mxArray *c1_hb_u;
  const mxArray *c1_ib_y = NULL;
  const mxArray *c1_ib_u;
  const mxArray *c1_jb_y = NULL;
  const mxArray *c1_jb_u;
  const mxArray *c1_kb_y = NULL;
  const mxArray *c1_kb_u;
  const mxArray *c1_lb_y = NULL;
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
                sf_exported_auto_getSimstatec7_ARP_02_RPSsmile_GloveAtomic
                (chartInstance->c1_subchartSimstruct), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo,
                sf_exported_auto_getSimstatec6_ARP_02_RPSsmile_GloveAtomic
                (chartInstance->c1_b_subchartSimstruct), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo,
                sf_exported_auto_getSimstatec5_ARP_02_RPSsmile_GloveAtomic
                (chartInstance->c1_c_subchartSimstruct), true);
  sf_mex_assign(&c1_d_subchartSimStateInfo,
                sf_exported_auto_getSimstatec4_ARP_02_RPSsmile_GloveAtomic
                (chartInstance->c1_d_subchartSimstruct), true);
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(36, 1), false);
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
  c1_i_hoistedGlobal = c1_get_avert(chartInstance, 0);
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = c1_get_b(chartInstance, 0);
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = c1_get_bHand(chartInstance, 0);
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = c1_get_bored(chartInstance, 0);
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = c1_get_diff(chartInstance, 0);
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = c1_get_p(chartInstance, 0);
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = c1_get_pSmile(chartInstance, 0);
  c1_o_u = c1_o_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  c1_p_hoistedGlobal = c1_get_pose(chartInstance, 0);
  c1_p_u = c1_p_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 15, c1_q_y);
  c1_q_hoistedGlobal = c1_get_r(chartInstance, 0);
  c1_q_u = c1_q_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 16, c1_r_y);
  c1_r_hoistedGlobal = c1_get_randomD(chartInstance, 0);
  c1_r_u = c1_r_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 17, c1_s_y);
  c1_s_hoistedGlobal = c1_get_randomG(chartInstance, 0);
  c1_s_u = c1_s_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 18, c1_t_y);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_t_u[c1_i0] = chartInstance->c1_randomH[c1_i0];
  }

  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", c1_t_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 19, c1_u_y);
  c1_t_hoistedGlobal = c1_get_randomP(chartInstance, 0);
  c1_u_u = c1_t_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 20, c1_v_y);
  c1_u_hoistedGlobal = c1_get_s(chartInstance, 0);
  c1_v_u = c1_u_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 21, c1_w_y);
  c1_v_hoistedGlobal = c1_get_smileN(chartInstance, 0);
  c1_w_u = c1_v_hoistedGlobal;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 22, c1_x_y);
  c1_w_hoistedGlobal = c1_get_smileYN(chartInstance, 0);
  c1_x_u = c1_w_hoistedGlobal;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 23, c1_y_y);
  c1_x_hoistedGlobal = c1_get_temp(chartInstance, 0);
  c1_y_u = c1_x_hoistedGlobal;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 24, c1_ab_y);
  c1_y_hoistedGlobal = c1_get_uHand(chartInstance, 0);
  c1_ab_u = c1_y_hoistedGlobal;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 25, c1_bb_y);
  c1_ab_hoistedGlobal = c1_get_wristRotate(chartInstance, 0);
  c1_bb_u = c1_ab_hoistedGlobal;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 26, c1_cb_y);
  c1_bb_hoistedGlobal =
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic;
  c1_cb_u = c1_bb_hoistedGlobal;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", &c1_cb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 27, c1_db_y);
  c1_cb_hoistedGlobal = chartInstance->c1_is_active_timeBasedSmileBrad;
  c1_db_u = c1_cb_hoistedGlobal;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_db_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 28, c1_eb_y);
  c1_db_hoistedGlobal = chartInstance->c1_is_active_idlePoseBrad;
  c1_eb_u = c1_db_hoistedGlobal;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_eb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 29, c1_fb_y);
  c1_eb_hoistedGlobal = chartInstance->c1_is_active_idleGazeBrad;
  c1_fb_u = c1_eb_hoistedGlobal;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_fb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 30, c1_gb_y);
  c1_fb_hoistedGlobal = chartInstance->c1_is_active_RPSGameBrad;
  c1_gb_u = c1_fb_hoistedGlobal;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_gb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 31, c1_hb_y);
  c1_hb_u = sf_mex_dup(c1_d_subchartSimStateInfo);
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_duplicatearraysafe(&c1_hb_u), false);
  sf_mex_destroy(&c1_hb_u);
  sf_mex_setcell(c1_y, 32, c1_ib_y);
  c1_ib_u = sf_mex_dup(c1_c_subchartSimStateInfo);
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_duplicatearraysafe(&c1_ib_u), false);
  sf_mex_destroy(&c1_ib_u);
  sf_mex_setcell(c1_y, 33, c1_jb_y);
  c1_jb_u = sf_mex_dup(c1_b_subchartSimStateInfo);
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_duplicatearraysafe(&c1_jb_u), false);
  sf_mex_destroy(&c1_jb_u);
  sf_mex_setcell(c1_y, 34, c1_kb_y);
  c1_kb_u = sf_mex_dup(c1_subchartSimStateInfo);
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_duplicatearraysafe(&c1_kb_u), false);
  sf_mex_destroy(&c1_kb_u);
  sf_mex_setcell(c1_y, 35, c1_lb_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[2];
  int32_T c1_i1;
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
  *c1_bWinT = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "bWinT");
  *c1_bradHand = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "bradHand");
  *c1_gameState = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "gameState");
  *c1_round = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "round");
  *c1_uWinT = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "uWinT");
  *c1_userHand = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "userHand");
  *c1_win = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    6)), "win");
  c1_set_BOREDOMT(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 7)), "BOREDOMT"));
  c1_set_avert(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
                (sf_mex_getcell(c1_u, 8)), "avert"));
  c1_set_b(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 9)), "b"));
  c1_set_bHand(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
                (sf_mex_getcell(c1_u, 10)), "bHand"));
  c1_set_bored(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
                (sf_mex_getcell(c1_u, 11)), "bored"));
  c1_set_diff(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 12)), "diff"));
  c1_set_p(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 13)), "p"));
  c1_set_pSmile(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 14)), "pSmile"));
  c1_set_pose(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 15)), "pose"));
  c1_set_r(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 16)), "r"));
  c1_set_randomD(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 17)), "randomD"));
  c1_set_randomG(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 18)), "randomG"));
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 19)),
                        "randomH", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    chartInstance->c1_randomH[c1_i1] = c1_dv0[c1_i1];
  }

  c1_set_randomP(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 20)), "randomP"));
  c1_set_s(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
            (sf_mex_getcell(c1_u, 21)), "s"));
  c1_set_smileN(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 22)), "smileN"));
  c1_set_smileYN(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 23)), "smileYN"));
  c1_set_temp(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 24)), "temp"));
  c1_set_uHand(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
                (sf_mex_getcell(c1_u, 25)), "uHand"));
  c1_set_wristRotate(chartInstance, 0, c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 26)), "wristRotate"));
  chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic =
    c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 27)),
    "is_active_c1_ARP_02_RPSsmile_GloveAtomic");
  chartInstance->c1_is_active_timeBasedSmileBrad = c1_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 28)),
     "is_active_timeBasedSmileBrad");
  chartInstance->c1_is_active_idlePoseBrad = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 29)), "is_active_idlePoseBrad");
  chartInstance->c1_is_active_idleGazeBrad = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 30)), "is_active_idleGazeBrad");
  chartInstance->c1_is_active_RPSGameBrad = c1_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 31)), "is_active_RPSGameBrad");
  sf_mex_assign(&c1_d_subchartSimStateInfo, c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 32)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_c_subchartSimStateInfo, c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 33)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_b_subchartSimStateInfo, c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 34)), "subchartSimStateInfo"), true);
  sf_mex_assign(&c1_subchartSimStateInfo, c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 35)), "subchartSimStateInfo"), true);
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 36)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  sf_exported_auto_setSimstatec7_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_subchartSimstruct, sf_mex_dup(c1_subchartSimStateInfo));
  sf_exported_auto_setSimstatec6_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_b_subchartSimstruct, sf_mex_dup(c1_b_subchartSimStateInfo));
  sf_exported_auto_setSimstatec5_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_c_subchartSimstruct, sf_mex_dup(c1_c_subchartSimStateInfo));
  sf_exported_auto_setSimstatec4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct, sf_mex_dup(c1_d_subchartSimStateInfo));
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_RPSGameBrad == 1U) {
      chartInstance->c1_tp_RPSGameBrad = 1U;
    } else {
      chartInstance->c1_tp_RPSGameBrad = 0U;
    }

    if (chartInstance->c1_is_active_idleGazeBrad == 1U) {
      chartInstance->c1_tp_idleGazeBrad = 1U;
    } else {
      chartInstance->c1_tp_idleGazeBrad = 0U;
    }

    if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
      chartInstance->c1_tp_idlePoseBrad = 1U;
    } else {
      chartInstance->c1_tp_idlePoseBrad = 0U;
    }

    if (chartInstance->c1_is_active_timeBasedSmileBrad == 1U) {
      chartInstance->c1_tp_timeBasedSmileBrad = 1U;
    } else {
      chartInstance->c1_tp_timeBasedSmileBrad = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c1_subchartSimStateInfo);
  sf_mex_destroy(&c1_b_subchartSimStateInfo);
  sf_mex_destroy(&c1_c_subchartSimStateInfo);
  sf_mex_destroy(&c1_d_subchartSimStateInfo);
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  int32_T c1_i2;
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
  c1_set_sim_state_side_effects_c1_ARP_02_RPSsmile_GloveAtomic(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_exported_auto_gatewayc7_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_gatewayc6_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_gatewayc5_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_gatewayc4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_gameState, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_inputUser, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_bradHand, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_userHand, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_win, 4U);
  _SFD_DATA_RANGE_CHECK(c1_get_temp(chartInstance, 0), 5U);
  _SFD_DATA_RANGE_CHECK(c1_get_diff(chartInstance, 0), 6U);
  _SFD_DATA_RANGE_CHECK(c1_get_uHand(chartInstance, 0), 7U);
  _SFD_DATA_RANGE_CHECK(c1_get_bHand(chartInstance, 0), 8U);
  _SFD_DATA_RANGE_CHECK(*c1_bWinT, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_uWinT, 10U);
  _SFD_DATA_RANGE_CHECK(c1_get_smileYN(chartInstance, 0), 11U);
  _SFD_DATA_RANGE_CHECK(c1_get_bored(chartInstance, 0), 12U);
  _SFD_DATA_RANGE_CHECK(c1_get_BOREDOMT(chartInstance, 0), 13U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomG(chartInstance, 0), 14U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomP(chartInstance, 0), 15U);
  _SFD_DATA_RANGE_CHECK(c1_get_pose(chartInstance, 0), 16U);
  _SFD_DATA_RANGE_CHECK(c1_get_b(chartInstance, 0), 17U);
  _SFD_DATA_RANGE_CHECK(c1_get_r(chartInstance, 0), 18U);
  _SFD_DATA_RANGE_CHECK(c1_get_p(chartInstance, 0), 19U);
  _SFD_DATA_RANGE_CHECK(c1_get_s(chartInstance, 0), 20U);
  _SFD_DATA_RANGE_CHECK(c1_get_randomD(chartInstance, 0), 21U);
  _SFD_DATA_RANGE_CHECK(c1_get_wristRotate(chartInstance, 0), 22U);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_randomH[c1_i2], 23U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_round, 24U);
  _SFD_DATA_RANGE_CHECK(c1_get_smileN(chartInstance, 0), 25U);
  _SFD_DATA_RANGE_CHECK(c1_get_pSmile(chartInstance, 0), 26U);
  _SFD_DATA_RANGE_CHECK(c1_get_avert(chartInstance, 0), 27U);
  sf_exported_auto_activate_c7_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_activate_c6_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_activate_c5_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_activate_callc4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c7_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c6_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_incrementTemporalCounter_c5_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_c_subchartSimstruct);
  chartInstance->c1_sfEvent = c1_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_stepBuffersc7_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_stepBuffersc6_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_stepBuffersc5_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_stepBuffersc4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic == 0U) {
    sf_exported_auto_initBuffersc7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
    sf_exported_auto_initBuffersc6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
    sf_exported_auto_initBuffersc5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
    sf_exported_auto_initBuffersc4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_ARP_02_RPSsmile_GloveAtomic = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_RPSGameBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_RPSGameBrad = 1U;
    sf_exported_auto_enterc7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
    chartInstance->c1_is_active_idleGazeBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_idleGazeBrad = 1U;
    sf_exported_auto_enterc6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
    chartInstance->c1_is_active_idlePoseBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_idlePoseBrad = 1U;
    sf_exported_auto_enterc5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
    chartInstance->c1_is_active_timeBasedSmileBrad = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_timeBasedSmileBrad = 1U;
    sf_exported_auto_enterc4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
    sf_exported_auto_duringc4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_secs,
               chartInstance->c1_sfEvent);
  sf_exported_auto_resetTemporalCounter_c7_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c6_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_resetTemporalCounter_c5_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_deactivate_c7_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_subchartSimstruct);
  sf_exported_auto_deactivate_c6_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_b_subchartSimstruct);
  sf_exported_auto_deactivate_c5_ARP_02_RPSsmile_GloveAtomic_secs
    (chartInstance->c1_c_subchartSimstruct);
  sf_exported_auto_deactivate_callc4_ARP_02_RPSsmile_GloveAtomic
    (chartInstance->c1_d_subchartSimstruct);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ARP_02_RPSsmile_GloveAtomicMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  if (chartInstance->c1_is_active_RPSGameBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c7_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idleGazeBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c6_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_b_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_idlePoseBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c5_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_c_subchartSimstruct);
  }

  if (chartInstance->c1_is_active_timeBasedSmileBrad == 1U) {
    sf_exported_auto_check_state_inconsistency_c4_ARP_02_RPSsmile_GloveAtomic
      (chartInstance->c1_d_subchartSimstruct);
  }
}

static void initSimStructsc1_ARP_02_RPSsmile_GloveAtomic
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance)
{
  chartInstance->c1_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "RPSGameBrad");
  chartInstance->c1_b_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "idleGazeBrad");
  chartInstance->c1_c_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "idlePoseBrad");
  chartInstance->c1_d_subchartSimstruct = sf_get_subchart_simstruct
    (chartInstance->S, "timeBasedSmileBrad");
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

const mxArray *sf_c1_ARP_02_RPSsmile_GloveAtomic_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i3;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i3, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i3;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_secs;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_secs = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_secs), &c1_thisId);
  sf_mex_destroy(&c1_secs);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_b_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i4;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i4, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i4;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_c_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_b_tp_RPSGameBrad, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_RPSGameBrad),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPSGameBrad);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_RPSGameBrad;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_RPSGameBrad = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_RPSGameBrad),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_RPSGameBrad);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_gameState, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_gameState),
    &c1_thisId);
  sf_mex_destroy(&c1_gameState);
  return c1_y;
}

static real_T c1_f_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_gameState;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_gameState = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_gameState),
    &c1_thisId);
  sf_mex_destroy(&c1_gameState);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i5;
  real_T c1_b_inData[2];
  int32_T c1_i6;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_b_inData[c1_i5] = (*(real_T (*)[2])c1_inData)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_u[c1_i6] = c1_b_inData[c1_i6];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_b_randomH, const char_T *c1_identifier,
  real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_randomH), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_randomH);
}

static void c1_h_emlrt_marshallIn(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv1[2];
  int32_T c1_i7;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_y[c1_i7] = c1_dv1[c1_i7];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_randomH;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i8;
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
    chartInstanceVoid;
  c1_b_randomH = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_randomH), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_randomH);
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    (*(real_T (*)[2])c1_outData)[c1_i8] = c1_y[c1_i8];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_e_subchartSimStateInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_e_subchartSimStateInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_e_subchartSimStateInfo);
  return c1_y;
}

static const mxArray *c1_j_emlrt_marshallIn
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, const mxArray *
   c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static real_T c1_get_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#623) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_BOREDOMT_address;
}

static void c1_set_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#623) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_BOREDOMT_address = c1_c;
}

static real_T *c1_access_BOREDOMT(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_BOREDOMT_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BOREDOMT\' (#623) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_BOREDOMT_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static real_T c1_get_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#637) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_avert_address;
}

static void c1_set_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#637) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_avert_address = c1_c;
}

static real_T *c1_access_avert(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#637) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_avert_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static real_T c1_get_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#627) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_b_address;
}

static void c1_set_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#627) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_b_address = c1_c;
}

static real_T *c1_access_b(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c1_b_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'b\' (#627) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_b_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c1_c;
}

static real_T c1_get_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#618) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bHand_address;
}

static void c1_set_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#618) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bHand_address = c1_c;
}

static real_T *c1_access_bHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c1_bHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bHand\' (#618) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c1_c;
}

static real_T c1_get_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#622) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_bored_address;
}

static void c1_set_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#622) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_bored_address = c1_c;
}

static real_T *c1_access_bored(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c1_bored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bored\' (#622) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_bored_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c1_c;
}

static real_T c1_get_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#616) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_diff_address;
}

static void c1_set_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c1_b);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#616) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_diff_address = c1_c;
}

static real_T *c1_access_diff(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c1_diff_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'diff\' (#616) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_diff_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c1_c;
}

static real_T c1_get_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#629) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_p_address;
}

static void c1_set_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c1_b);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#629) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_p_address = c1_c;
}

static real_T *c1_access_p(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c1_p_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'p\' (#629) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_p_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c1_c;
}

static real_T c1_get_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#636) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pSmile_address;
}

static void c1_set_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c1_b);
  if (chartInstance->c1_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#636) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pSmile_address = c1_c;
}

static real_T *c1_access_pSmile(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c1_pSmile_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pSmile\' (#636) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pSmile_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c1_c;
}

static real_T c1_get_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#626) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_pose_address;
}

static void c1_set_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c1_b);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#626) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_pose_address = c1_c;
}

static real_T *c1_access_pose(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c1_pose_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'pose\' (#626) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_pose_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c1_c;
}

static real_T c1_get_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#628) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_r_address;
}

static void c1_set_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c1_b);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#628) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_r_address = c1_c;
}

static real_T *c1_access_r(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c1_r_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'r\' (#628) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_r_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#631) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomD_address;
}

static void c1_set_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 10, NULL, c1_b);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#631) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomD_address = c1_c;
}

static real_T *c1_access_randomD(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 10, NULL);
  if (chartInstance->c1_randomD_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomD\' (#631) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomD_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 10, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#624) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomG_address;
}

static void c1_set_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 11, NULL, c1_b);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#624) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomG_address = c1_c;
}

static real_T *c1_access_randomG(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 11, NULL);
  if (chartInstance->c1_randomG_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomG\' (#624) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomG_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 11, NULL);
  }

  return c1_c;
}

static real_T c1_get_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#625) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_randomP_address;
}

static void c1_set_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 12, NULL, c1_b);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#625) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_randomP_address = c1_c;
}

static real_T *c1_access_randomP(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 12, NULL);
  if (chartInstance->c1_randomP_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'randomP\' (#625) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_randomP_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 12, NULL);
  }

  return c1_c;
}

static real_T c1_get_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#630) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_s_address;
}

static void c1_set_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
                     *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 13, NULL, c1_b);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#630) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_s_address = c1_c;
}

static real_T *c1_access_s(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 13, NULL);
  if (chartInstance->c1_s_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'s\' (#630) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_s_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 13, NULL);
  }

  return c1_c;
}

static real_T c1_get_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#635) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_smileN_address;
}

static void c1_set_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 14, NULL, c1_b);
  if (chartInstance->c1_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#635) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_smileN_address = c1_c;
}

static real_T *c1_access_smileN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 14, NULL);
  if (chartInstance->c1_smileN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileN\' (#635) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_smileN_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 14, NULL);
  }

  return c1_c;
}

static real_T c1_get_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#621) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_smileYN_address;
}

static void c1_set_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 15, NULL, c1_b);
  if (chartInstance->c1_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#621) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_smileYN_address = c1_c;
}

static real_T *c1_access_smileYN(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 15, NULL);
  if (chartInstance->c1_smileYN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'smileYN\' (#621) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_smileYN_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 15, NULL);
  }

  return c1_c;
}

static real_T c1_get_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#615) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_temp_address;
}

static void c1_set_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 16, NULL, c1_b);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#615) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_temp_address = c1_c;
}

static real_T *c1_access_temp(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 16, NULL);
  if (chartInstance->c1_temp_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'temp\' (#615) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_temp_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 16, NULL);
  }

  return c1_c;
}

static real_T c1_get_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#617) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_uHand_address;
}

static void c1_set_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 17, NULL, c1_b);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#617) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_uHand_address = c1_c;
}

static real_T *c1_access_uHand(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 17, NULL);
  if (chartInstance->c1_uHand_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'uHand\' (#617) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_uHand_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 17, NULL);
  }

  return c1_c;
}

static real_T c1_get_wristRotate(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *
  chartInstance, uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#632) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_wristRotate_address;
}

static void c1_set_wristRotate(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance, uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 18, NULL, c1_b);
  if (chartInstance->c1_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#632) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_wristRotate_address = c1_c;
}

static real_T *c1_access_wristRotate
  (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance, uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 18, NULL);
  if (chartInstance->c1_wristRotate_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'wristRotate\' (#632) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_wristRotate_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 18, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BOREDOMT", (void **)
    &chartInstance->c1_BOREDOMT_address, &chartInstance->c1_BOREDOMT_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c1_avert_address, &chartInstance->c1_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "b", (void **)
    &chartInstance->c1_b_address, &chartInstance->c1_b_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bHand", (void **)
    &chartInstance->c1_bHand_address, &chartInstance->c1_bHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bored", (void **)
    &chartInstance->c1_bored_address, &chartInstance->c1_bored_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "diff", (void **)
    &chartInstance->c1_diff_address, &chartInstance->c1_diff_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "p", (void **)
    &chartInstance->c1_p_address, &chartInstance->c1_p_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pSmile", (void **)
    &chartInstance->c1_pSmile_address, &chartInstance->c1_pSmile_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "pose", (void **)
    &chartInstance->c1_pose_address, &chartInstance->c1_pose_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "r", (void **)
    &chartInstance->c1_r_address, &chartInstance->c1_r_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomD", (void **)
    &chartInstance->c1_randomD_address, &chartInstance->c1_randomD_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomG", (void **)
    &chartInstance->c1_randomG_address, &chartInstance->c1_randomG_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "randomP", (void **)
    &chartInstance->c1_randomP_address, &chartInstance->c1_randomP_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "s", (void **)
    &chartInstance->c1_s_address, &chartInstance->c1_s_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileN", (void **)
    &chartInstance->c1_smileN_address, &chartInstance->c1_smileN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "smileYN", (void **)
    &chartInstance->c1_smileYN_address, &chartInstance->c1_smileYN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "temp", (void **)
    &chartInstance->c1_temp_address, &chartInstance->c1_temp_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "uHand", (void **)
    &chartInstance->c1_uHand_address, &chartInstance->c1_uHand_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "wristRotate", (void **)
    &chartInstance->c1_wristRotate_address, &chartInstance->c1_wristRotate_index);
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

void sf_c1_ARP_02_RPSsmile_GloveAtomic_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2570243210U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3379186368U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2552709319U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(82637333U);
}

mxArray *sf_c1_ARP_02_RPSsmile_GloveAtomic_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xgMQXwlHdJRfCTTlAXthQD");
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

    mxArray *mxData = mxCreateStructMatrix(1,20,3,dataFields);

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
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ARP_02_RPSsmile_GloveAtomic_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_ARP_02_RPSsmile_GloveAtomic_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_ARP_02_RPSsmile_GloveAtomic(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[469],T\"bWinT\",},{M[1],M[390],T\"bradHand\",},{M[1],M[464],T\"gameState\",},{M[1],M[713],T\"round\",},{M[1],M[470],T\"uWinT\",},{M[1],M[461],T\"userHand\",},{M[1],M[459],T\"win\",},{M[3],M[568],T\"BOREDOMT\",},{M[3],M[756],T\"avert\",},{M[3],M[641],T\"b\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[468],T\"bHand\",},{M[3],M[567],T\"bored\",},{M[3],M[462],T\"diff\",},{M[3],M[660],T\"p\",},{M[3],M[755],T\"pSmile\",},{M[3],M[636],T\"pose\",},{M[3],M[659],T\"r\",},{M[3],M[688],T\"randomD\",},{M[3],M[596],T\"randomG\",},{M[3],M[701],T\"randomH\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[635],T\"randomP\",},{M[3],M[661],T\"s\",},{M[3],M[754],T\"smileN\",},{M[3],M[566],T\"smileYN\",},{M[3],M[460],T\"temp\",},{M[3],M[467],T\"uHand\",},{M[3],M[689],T\"wristRotate\",},{M[8],M[0],T\"is_active_c1_ARP_02_RPSsmile_GloveAtomic\",},{M[8],M[750],T\"is_active_timeBasedSmileBrad\",},{M[8],M[751],T\"is_active_idlePoseBrad\",}}",
    "100 S1x6'type','srcId','name','auxInfo'{{M[8],M[752],T\"is_active_idleGazeBrad\",},{M[8],M[753],T\"is_active_RPSGameBrad\",},{M[14],M[750],T\"subchartSimStateInfo\",},{M[14],M[751],T\"subchartSimStateInfo\",},{M[14],M[752],T\"subchartSimStateInfo\",},{M[14],M[753],T\"subchartSimStateInfo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 36, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ARP_02_RPSsmile_GloveAtomic_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
           1,
           4,
           0,
           0,
           28,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation
          (_ARP_02_RPSsmile_GloveAtomicMachineNumber_,chartInstance->chartNumber,
           chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ARP_02_RPSsmile_GloveAtomicMachineNumber_,
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
          _SFD_SET_DATA_PROPS(11,0,0,0,"smileYN");
          _SFD_SET_DATA_PROPS(12,0,0,0,"bored");
          _SFD_SET_DATA_PROPS(13,0,0,0,"BOREDOMT");
          _SFD_SET_DATA_PROPS(14,0,0,0,"randomG");
          _SFD_SET_DATA_PROPS(15,0,0,0,"randomP");
          _SFD_SET_DATA_PROPS(16,0,0,0,"pose");
          _SFD_SET_DATA_PROPS(17,0,0,0,"b");
          _SFD_SET_DATA_PROPS(18,0,0,0,"r");
          _SFD_SET_DATA_PROPS(19,0,0,0,"p");
          _SFD_SET_DATA_PROPS(20,0,0,0,"s");
          _SFD_SET_DATA_PROPS(21,0,0,0,"randomD");
          _SFD_SET_DATA_PROPS(22,0,0,0,"wristRotate");
          _SFD_SET_DATA_PROPS(23,0,0,0,"randomH");
          _SFD_SET_DATA_PROPS(24,2,0,1,"round");
          _SFD_SET_DATA_PROPS(25,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(26,0,0,0,"pSmile");
          _SFD_SET_DATA_PROPS(27,0,0,0,"avert");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,1);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,0,0,0);

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

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);

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
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_temp_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_diff_address);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c1_uHand_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c1_bHand_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_bWinT);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_uWinT);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c1_smileYN_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c1_bored_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c1_BOREDOMT_address);
          _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c1_randomG_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c1_randomP_address);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c1_pose_address);
          _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c1_b_address);
          _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c1_r_address);
          _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c1_p_address);
          _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c1_s_address);
          _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c1_randomD_address);
          _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c1_wristRotate_address);
          _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c1_randomH);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_round);
          _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c1_smileN_address);
          _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c1_pSmile_address);
          _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c1_avert_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ARP_02_RPSsmile_GloveAtomicMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bdUKCAnkKFUGRI6ZQt0JnC";
}

static void sf_opaque_initialize_c1_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
  initialize_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  enable_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  disable_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  sf_gateway_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_RPSsmile_GloveAtomic();/* state var info */
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

extern void sf_internal_set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct*
  S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_ARP_02_RPSsmile_GloveAtomic();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic(S);
}

static void sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic(S, st);
}

static void sf_opaque_terminate_c1_ARP_02_RPSsmile_GloveAtomic(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ARP_02_RPSsmile_GloveAtomic_optimization_info();
    }

    finalize_c1_ARP_02_RPSsmile_GloveAtomic
      ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ARP_02_RPSsmile_GloveAtomic
    ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
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
    initialize_params_c1_ARP_02_RPSsmile_GloveAtomic
      ((SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ARP_02_RPSsmile_GloveAtomic_optimization_info();
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
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,7);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
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
  ssSetChecksum0(S,(1011036713U));
  ssSetChecksum1(S,(2560039644U));
  ssSetChecksum2(S,(2441143324U));
  ssSetChecksum3(S,(1775378309U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_ARP_02_RPSsmile_GloveAtomic(SimStruct *S)
{
  SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct *)utMalloc
    (sizeof(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ARP_02_RPSsmile_GloveAtomicInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ARP_02_RPSsmile_GloveAtomic;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_GloveAtomic;
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

void c1_ARP_02_RPSsmile_GloveAtomic_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ARP_02_RPSsmile_GloveAtomic(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ARP_02_RPSsmile_GloveAtomic_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
