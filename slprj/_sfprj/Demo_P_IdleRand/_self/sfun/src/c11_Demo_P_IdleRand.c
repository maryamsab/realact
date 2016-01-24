/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_P_IdleRand_sfun.h"
#include "c11_Demo_P_IdleRand.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_P_IdleRand_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c11_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_checkP                  ((uint8_T)1U)
#define c11_IN_gazeCamera              ((uint8_T)2U)
#define c11_IN_stateCheckSmile         ((uint8_T)3U)
#define c11_IN_stateInitial            ((uint8_T)4U)
#define c11_IN_wait                    ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[7] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "p", "poseBML" };

static const char * c11_d_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[9];

/* Function Declarations */
static void initialize_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void initialize_params_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void enable_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void disable_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void set_sim_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void finalize_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void sf_gateway_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void c11_enter_atomic_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_enter_internal_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void c11_exit_internal_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_initc11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);
static void initSimStructsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_gazeCamera(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_encStr2Arr(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  real_T c11_myarr256[256]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[1280]);
static void c11_b_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1280]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[256]);
static void c11_d_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_e_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier);
static real_T c11_f_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[256]);
static void c11_h_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_i_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_activate_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_deactivate_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_increment_counters_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_reset_counters_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance);
static void c11_insertQueuec11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, real_T c11_bmls[1280],
   real_T c11_myBML[256], real_T c11_newBmls[1280]);
static void c11_smileTablec11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, real_T c11_bmlID, real_T *
   c11_p, real_T c11_poseBML[256]);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_j_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_k_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_l_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_stateInitial, const char_T
  *c11_identifier);
static uint8_T c11_m_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint16_T c11_n_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_temporalCounter_i1, const char_T
  *c11_identifier);
static uint16_T c11_o_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *c11_p_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier);
static const mxArray *c11_q_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex);
static void c11_errorIfDataNotWrittenToFcn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex, uint32_T c11_dataNumber);
static real_T c11_get_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c);
static real_T *c11_access_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static real_T c11_get_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_avert(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_avert(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void c11_set_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static real_T c11_get_gazing(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b);
static void c11_set_gazing(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c);
static real_T *c11_access_gazing(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b);
static void init_dsm_address_info(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_Demo_P_IdleRand == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_gazeCamera) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_checkP) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i0;
  real_T c11_b_u[256];
  const mxArray *c11_c_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  int32_T c11_i1;
  real_T c11_d_u[256];
  const mxArray *c11_e_y = NULL;
  int32_T c11_i2;
  real_T c11_e_u[1280];
  const mxArray *c11_f_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  uint8_T c11_e_hoistedGlobal;
  uint8_T c11_h_u;
  const mxArray *c11_i_y = NULL;
  uint16_T c11_f_hoistedGlobal;
  uint16_T c11_i_u;
  const mxArray *c11_j_y = NULL;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(9, 1), false);
  c11_hoistedGlobal = *c11_gameState;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i0 = 0; c11_i0 < 256; c11_i0++) {
    c11_b_u[c11_i0] = chartInstance->c11_BMLM[c11_i0];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_b_hoistedGlobal = chartInstance->c11_fileID;
  c11_c_u = c11_b_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  for (c11_i1 = 0; c11_i1 < 256; c11_i1++) {
    c11_d_u[c11_i1] = chartInstance->c11_n[c11_i1];
  }

  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", c11_d_u, 0, 0U, 1U, 0U, 1, 256),
                false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  for (c11_i2 = 0; c11_i2 < 1280; c11_i2++) {
    c11_e_u[c11_i2] = chartInstance->c11_newBmlsM[c11_i2];
  }

  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", c11_e_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  c11_c_hoistedGlobal = chartInstance->c11_smileN;
  c11_f_u = c11_c_hoistedGlobal;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_active_c11_Demo_P_IdleRand;
  c11_g_u = c11_d_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  c11_e_hoistedGlobal = chartInstance->c11_is_c11_Demo_P_IdleRand;
  c11_h_u = c11_e_hoistedGlobal;
  c11_i_y = NULL;
  sf_mex_assign(&c11_i_y, sf_mex_create("y", &c11_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 7, c11_i_y);
  c11_f_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_i_u = c11_f_hoistedGlobal;
  c11_j_y = NULL;
  sf_mex_assign(&c11_j_y, sf_mex_create("y", &c11_i_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 8, c11_j_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[256];
  int32_T c11_i3;
  real_T c11_dv1[256];
  int32_T c11_i4;
  real_T c11_dv2[1280];
  int32_T c11_i5;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_gameState = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "gameState");
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "BMLM", c11_dv0);
  for (c11_i3 = 0; c11_i3 < 256; c11_i3++) {
    chartInstance->c11_BMLM[c11_i3] = c11_dv0[c11_i3];
  }

  chartInstance->c11_fileID = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 2)), "fileID");
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 3)),
    "n", c11_dv1);
  for (c11_i4 = 0; c11_i4 < 256; c11_i4++) {
    chartInstance->c11_n[c11_i4] = c11_dv1[c11_i4];
  }

  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 4)),
                       "newBmlsM", c11_dv2);
  for (c11_i5 = 0; c11_i5 < 1280; c11_i5++) {
    chartInstance->c11_newBmlsM[c11_i5] = c11_dv2[c11_i5];
  }

  chartInstance->c11_smileN = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 5)), "smileN");
  chartInstance->c11_is_active_c11_Demo_P_IdleRand = c11_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 6)),
     "is_active_c11_Demo_P_IdleRand");
  chartInstance->c11_is_c11_Demo_P_IdleRand = c11_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 7)),
     "is_c11_Demo_P_IdleRand");
  chartInstance->c11_temporalCounter_i1 = c11_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 8)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 9)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_Demo_P_IdleRand(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_checkP) {
      chartInstance->c11_tp_checkP = 1U;
    } else {
      chartInstance->c11_tp_checkP = 0U;
    }

    if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_gazeCamera) {
      chartInstance->c11_tp_gazeCamera = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_gazeCamera = 0U;
    }

    if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_stateCheckSmile) {
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      chartInstance->c11_tp_stateCheckSmile = 0U;
    }

    if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_stateInitial) {
      chartInstance->c11_tp_stateInitial = 1U;
    } else {
      chartInstance->c11_tp_stateInitial = 0U;
    }

    if (chartInstance->c11_is_c11_Demo_P_IdleRand == c11_IN_wait) {
      chartInstance->c11_tp_wait = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_wait = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  c11_set_sim_state_side_effects_c11_Demo_P_IdleRand(chartInstance);
}

static void c11_enter_atomic_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_Demo_P_IdleRand = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  uint32_T c11_b_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr;
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr;
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_myarr256[256];
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  real_T *c11_gameState;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_f_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  c11_set_avert(chartInstance, 0, 1.0);
  ssUpdateDataStoreLog(chartInstance->S, 6);
  *c11_gameState = c11_get_STATE_READY(chartInstance, 0);
  c11_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_gameState, 8U);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_b_debug_family_names,
    c11_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_arr, 1U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_mystr, 5U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  c11_mystr = ' ';
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_arr = 32.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i6 = 0; c11_i6 < 256; c11_i6++) {
    c11_tt[c11_i6] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_tt[0] = c11_arr;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i7 = 0; c11_i7 < 256; c11_i7++) {
    c11_myarr256[c11_i7] = c11_tt[c11_i7];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i8 = 0; c11_i8 < 256; c11_i8++) {
    chartInstance->c11_n[c11_i8] = c11_myarr256[c11_i8];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  for (c11_i9 = 0; c11_i9 < 256; c11_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_n[c11_i9], 16U);
  }

  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 16U);
  for (c11_i10 = 0; c11_i10 < 256; c11_i10++) {
    c11_set_bmlsM(chartInstance, c11_i10, chartInstance->c11_n[c11_i10]);
  }

  for (c11_i11 = 0; c11_i11 < 256; c11_i11++) {
    c11_set_bmlsM(chartInstance, c11_i11 + 256, chartInstance->c11_n[c11_i11]);
  }

  for (c11_i12 = 0; c11_i12 < 256; c11_i12++) {
    c11_set_bmlsM(chartInstance, c11_i12 + 512, chartInstance->c11_n[c11_i12]);
  }

  for (c11_i13 = 0; c11_i13 < 256; c11_i13++) {
    c11_set_bmlsM(chartInstance, c11_i13 + 768, chartInstance->c11_n[c11_i13]);
  }

  for (c11_i14 = 0; c11_i14 < 256; c11_i14++) {
    c11_set_bmlsM(chartInstance, c11_i14 + 1024, chartInstance->c11_n[c11_i14]);
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  ssUpdateDataStoreLog(chartInstance->S, 7);
  c11_errorIfDataNotWrittenToFcn(chartInstance, 5U, 16U);
  for (c11_i15 = 0; c11_i15 < 256; c11_i15++) {
    chartInstance->c11_newBmlsM[c11_i15] = chartInstance->c11_n[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 256; c11_i16++) {
    chartInstance->c11_newBmlsM[c11_i16 + 256] = chartInstance->c11_n[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 256; c11_i17++) {
    chartInstance->c11_newBmlsM[c11_i17 + 512] = chartInstance->c11_n[c11_i17];
  }

  for (c11_i18 = 0; c11_i18 < 256; c11_i18++) {
    chartInstance->c11_newBmlsM[c11_i18 + 768] = chartInstance->c11_n[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 256; c11_i19++) {
    chartInstance->c11_newBmlsM[c11_i19 + 1024] = chartInstance->c11_n[c11_i19];
  }

  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 5U);
  c11_updateDataWrittenToVector(chartInstance, 3U);
  for (c11_i20 = 0; c11_i20 < 1280; c11_i20++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i20], 13U);
  }

  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  real_T c11_b_BMLM[256];
  real_T c11_P;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  real_T c11_dv3[1280];
  int32_T c11_i24;
  real_T c11_dv4[256];
  real_T c11_dv5[1280];
  int32_T c11_i25;
  int32_T c11_i26;
  int32_T c11_i27;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_b_out;
  real_T *c11_gameState;
  real_T *c11_isSmiling;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  switch (chartInstance->c11_is_c11_Demo_P_IdleRand) {
   case c11_IN_checkP:
    CV_CHART_EVAL(7, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_checkP = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    chartInstance->c11_temporalCounter_i1 = 0U;
    chartInstance->c11_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_CHART_EVAL(7, 0, 2);
    c11_gazeCamera(chartInstance);
    break;

   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(7, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_k_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(4, 0, 0, *c11_isSmiling == 1.0)) {
      if (CV_EML_COND(4, 0, 1, *c11_gameState != c11_get_STATE_GO(chartInstance,
            0))) {
        if (CV_EML_COND(4, 0, 2, *c11_gameState != c11_get_STATE_READY
                        (chartInstance, 0))) {
          CV_EML_MCDC(4, 0, 0, true);
          CV_EML_IF(4, 0, 0, true);
          c11_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
        guard2 = true;
      }
    } else {
      c11_errorIfDataNotWrittenToFcn(chartInstance, 2U, 8U);
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(4, 0, 0, false);
      CV_EML_IF(4, 0, 0, false);
      c11_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_gazeCamera;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_temporalCounter_i1 = 0U;
      chartInstance->c11_tp_gazeCamera = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_g_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      c11_smileTablec11_Demo_P_IdleRand(chartInstance, 2.0, &c11_P, c11_b_BMLM);
      c11_set_P(chartInstance, 0, c11_P);
      ssUpdateDataStoreLog(chartInstance->S, 2);
      for (c11_i21 = 0; c11_i21 < 256; c11_i21++) {
        chartInstance->c11_BMLM[c11_i21] = c11_b_BMLM[c11_i21];
      }

      c11_updateDataWrittenToVector(chartInstance, 4U);
      for (c11_i22 = 0; c11_i22 < 256; c11_i22++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i22], 15U);
      }

      c11_set_avert(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 6);
      c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
      for (c11_i23 = 0; c11_i23 < 1280; c11_i23++) {
        c11_dv3[c11_i23] = c11_get_bmlsM(chartInstance, c11_i23);
      }

      for (c11_i24 = 0; c11_i24 < 256; c11_i24++) {
        c11_dv4[c11_i24] = chartInstance->c11_BMLM[c11_i24];
      }

      c11_insertQueuec11_Demo_P_IdleRand(chartInstance, c11_dv3, c11_dv4,
        c11_dv5);
      for (c11_i25 = 0; c11_i25 < 1280; c11_i25++) {
        chartInstance->c11_newBmlsM[c11_i25] = c11_dv5[c11_i25];
      }

      c11_updateDataWrittenToVector(chartInstance, 3U);
      for (c11_i26 = 0; c11_i26 < 1280; c11_i26++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i26], 13U);
      }

      c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
      for (c11_i27 = 0; c11_i27 < 1280; c11_i27++) {
        c11_set_bmlsM(chartInstance, c11_i27, chartInstance->
                      c11_newBmlsM[c11_i27]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 7);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(7, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_stateCheckSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateCheckSmile = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_CHART_EVAL(7, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_i_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    c11_b_out = CV_EML_IF(5, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs)
                          && (chartInstance->c11_temporalCounter_i1 >= 300));
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c11_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  switch (chartInstance->c11_is_c11_Demo_P_IdleRand) {
   case c11_IN_checkP:
    CV_CHART_EVAL(7, 0, 1);
    chartInstance->c11_tp_checkP = 0U;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_gazeCamera:
    CV_CHART_EVAL(7, 0, 2);
    chartInstance->c11_tp_gazeCamera = 0U;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(7, 0, 3);
    chartInstance->c11_tp_stateCheckSmile = 0U;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(7, 0, 4);
    chartInstance->c11_tp_stateInitial = 0U;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_wait:
    CV_CHART_EVAL(7, 0, 5);
    chartInstance->c11_tp_wait = 0U;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(7, 0, 0);
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_Demo_P_IdleRand(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_checkP = 0U;
  chartInstance->c11_tp_gazeCamera = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_tp_stateCheckSmile = 0U;
  chartInstance->c11_tp_stateInitial = 0U;
  chartInstance->c11_tp_wait = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_is_active_c11_Demo_P_IdleRand = 0U;
  chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_NO_ACTIVE_CHILD;
}

static void initSimStructsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_gazeCamera(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  real_T c11_b_BMLM[256];
  real_T c11_P;
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i30;
  real_T c11_dv6[1280];
  int32_T c11_i31;
  real_T c11_dv7[256];
  real_T c11_dv8[1280];
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_b_out;
  real_T *c11_isSmiling;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_l_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  guard2 = false;
  if (CV_EML_COND(3, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                  (chartInstance->c11_temporalCounter_i1 >= 1))) {
    if (CV_EML_COND(3, 0, 1, *c11_isSmiling == 1.0)) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c11_out = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(3, 0, 0, false);
    CV_EML_IF(3, 0, 0, false);
    c11_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c11_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_gazeCamera = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_checkP;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_checkP = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_h_debug_family_names,
      c11_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    c11_smileTablec11_Demo_P_IdleRand(chartInstance, 1.0, &c11_P, c11_b_BMLM);
    c11_set_P(chartInstance, 0, c11_P);
    ssUpdateDataStoreLog(chartInstance->S, 2);
    for (c11_i28 = 0; c11_i28 < 256; c11_i28++) {
      chartInstance->c11_BMLM[c11_i28] = c11_b_BMLM[c11_i28];
    }

    c11_updateDataWrittenToVector(chartInstance, 4U);
    for (c11_i29 = 0; c11_i29 < 256; c11_i29++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c11_BMLM[c11_i29], 15U);
    }

    c11_errorIfDataNotWrittenToFcn(chartInstance, 4U, 15U);
    for (c11_i30 = 0; c11_i30 < 1280; c11_i30++) {
      c11_dv6[c11_i30] = c11_get_bmlsM(chartInstance, c11_i30);
    }

    for (c11_i31 = 0; c11_i31 < 256; c11_i31++) {
      c11_dv7[c11_i31] = chartInstance->c11_BMLM[c11_i31];
    }

    c11_insertQueuec11_Demo_P_IdleRand(chartInstance, c11_dv6, c11_dv7, c11_dv8);
    for (c11_i32 = 0; c11_i32 < 1280; c11_i32++) {
      chartInstance->c11_newBmlsM[c11_i32] = c11_dv8[c11_i32];
    }

    c11_updateDataWrittenToVector(chartInstance, 3U);
    for (c11_i33 = 0; c11_i33 < 1280; c11_i33++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c11_newBmlsM[c11_i33], 13U);
    }

    c11_errorIfDataNotWrittenToFcn(chartInstance, 3U, 13U);
    for (c11_i34 = 0; c11_i34 < 1280; c11_i34++) {
      c11_set_bmlsM(chartInstance, c11_i34, chartInstance->c11_newBmlsM[c11_i34]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 7);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_j_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
      c11_c_sf_marshallOut, c11_c_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_f_sf_marshallOut,
      c11_e_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(7, 0, 0, (chartInstance->c11_sfEvent == c11_event_secs) &&
                    (chartInstance->c11_temporalCounter_i1 >= 1))) {
      if (CV_EML_COND(7, 0, 1, *c11_isSmiling != 1.0)) {
        CV_EML_MCDC(7, 0, 0, true);
        CV_EML_IF(7, 0, 0, true);
        c11_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c11_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_gazeCamera = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Demo_P_IdleRand = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c11_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
}

static void c11_encStr2Arr(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[230];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[230];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i35;
  static char_T c11_cv0[230] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '7', '0',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '0', '\"', ' ', 't', 'y', 'p',
    'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e',
    ' ', 'a', 'm', 'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a',
    'u', '=', '\"', '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T',
    'H', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't',
    'r', 'o', 'k', 'e', '=', '\"', '1', '0', '\"', ' ', 'r', 'e', 'l', 'a', 'x',
    '=', '\"', '7', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"', '1', '0', '0',
    '\"', ' ', 't', 'y', 'p', 'e', '=', '\"', 'f', 'a', 'c', 's', '\"', '/', '>',
    '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i36;
  static real_T c11_dv9[230] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 55.0, 48.0, 34.0, 32.0, 101.0,
    110.0, 100.0, 61.0, 34.0, 49.0, 48.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0,
    101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0,
    97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0,
    48.0, 46.0, 51.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0,
    115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0,
    114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 49.0, 48.0, 34.0, 32.0, 114.0, 101.0,
    108.0, 97.0, 120.0, 61.0, 34.0, 55.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0,
    61.0, 34.0, 49.0, 48.0, 48.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0,
    34.0, 102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0,
    108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i37;
  int32_T c11_i38;
  int32_T c11_i39;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i35 = 0; c11_i35 < 230; c11_i35++) {
    c11_mystr[c11_i35] = c11_cv0[c11_i35];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i36 = 0; c11_i36 < 230; c11_i36++) {
    c11_arr[c11_i36] = c11_dv9[c11_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 230.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i37 = 0; c11_i37 < 256; c11_i37++) {
    c11_tt[c11_i37] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i38 = 0; c11_i38 < 230; c11_i38++) {
    c11_tt[c11_i38] = c11_arr[c11_i38];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i39 = 0; c11_i39 < 256; c11_i39++) {
    c11_myarr256[c11_i39] = c11_tt[c11_i39];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\7-10-2015-Matlab-Demo\\encStr2Arr.m"));
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  real_T c11_b_inData[1280];
  int32_T c11_i43;
  int32_T c11_i44;
  int32_T c11_i45;
  real_T c11_u[1280];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i40 = 0;
  for (c11_i41 = 0; c11_i41 < 5; c11_i41++) {
    for (c11_i42 = 0; c11_i42 < 256; c11_i42++) {
      c11_b_inData[c11_i42 + c11_i40] = (*(real_T (*)[1280])c11_inData)[c11_i42
        + c11_i40];
    }

    c11_i40 += 256;
  }

  c11_i43 = 0;
  for (c11_i44 = 0; c11_i44 < 5; c11_i44++) {
    for (c11_i45 = 0; c11_i45 < 256; c11_i45++) {
      c11_u[c11_i45 + c11_i43] = c11_b_inData[c11_i45 + c11_i43];
    }

    c11_i43 += 256;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 5),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_newBmls, const char_T *c11_identifier,
  real_T c11_y[1280])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
}

static void c11_b_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[1280])
{
  real_T c11_dv10[1280];
  int32_T c11_i46;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv10, 1, 0, 0U, 1, 0U, 2,
                256, 5);
  for (c11_i46 = 0; c11_i46 < 1280; c11_i46++) {
    c11_y[c11_i46] = c11_dv10[c11_i46];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_newBmls;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[1280];
  int32_T c11_i47;
  int32_T c11_i48;
  int32_T c11_i49;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_newBmls = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_newBmls), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_newBmls);
  c11_i47 = 0;
  for (c11_i48 = 0; c11_i48 < 5; c11_i48++) {
    for (c11_i49 = 0; c11_i49 < 256; c11_i49++) {
      (*(real_T (*)[1280])c11_outData)[c11_i49 + c11_i47] = c11_y[c11_i49 +
        c11_i47];
    }

    c11_i47 += 256;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i50;
  real_T c11_b_inData[256];
  int32_T c11_i51;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i50 = 0; c11_i50 < 256; c11_i50++) {
    c11_b_inData[c11_i50] = (*(real_T (*)[256])c11_inData)[c11_i50];
  }

  for (c11_i51 = 0; c11_i51 < 256; c11_i51++) {
    c11_u[c11_i51] = c11_b_inData[c11_i51];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_myBML, const char_T *c11_identifier, real_T
  c11_y[256])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
}

static void c11_d_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv11[256];
  int32_T c11_i52;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv11, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c11_i52 = 0; c11_i52 < 256; c11_i52++) {
    c11_y[c11_i52] = c11_dv11[c11_i52];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myBML;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i53;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_myBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myBML), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myBML);
  for (c11_i53 = 0; c11_i53 < 256; c11_i53++) {
    (*(real_T (*)[256])c11_outData)[c11_i53] = c11_y[c11_i53];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_e_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_nargout, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  return c11_y;
}

static real_T c11_f_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i54;
  real_T c11_b_inData[256];
  int32_T c11_i55;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i54 = 0; c11_i54 < 256; c11_i54++) {
    c11_b_inData[c11_i54] = (*(real_T (*)[256])c11_inData)[c11_i54];
  }

  for (c11_i55 = 0; c11_i55 < 256; c11_i55++) {
    c11_u[c11_i55] = c11_b_inData[c11_i55];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_myarr256, const char_T *c11_identifier,
  real_T c11_y[256])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
}

static void c11_h_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[256])
{
  real_T c11_dv12[256];
  int32_T c11_i56;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv12, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c11_i56 = 0; c11_i56 < 256; c11_i56++) {
    c11_y[c11_i56] = c11_dv12[c11_i56];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_myarr256;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i57;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i57 = 0; c11_i57 < 256; c11_i57++) {
    (*(real_T (*)[256])c11_outData)[c11_i57] = c11_y[c11_i57];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  char_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(char_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_i_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b0, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_aVarTruthTableCondition_2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_aVarTruthTableCondition_2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_aVarTruthTableCondition_2), &c11_thisId);
  sf_mex_destroy(&c11_aVarTruthTableCondition_2);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i58;
  char_T c11_b_inData[230];
  int32_T c11_i59;
  char_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i58 = 0; c11_i58 < 230; c11_i58++) {
    c11_b_inData[c11_i58] = (*(char_T (*)[230])c11_inData)[c11_i58];
  }

  for (c11_i59 = 0; c11_i59 < 230; c11_i59++) {
    c11_u[c11_i59] = c11_b_inData[c11_i59];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 230),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i60;
  real_T c11_b_inData[230];
  int32_T c11_i61;
  real_T c11_u[230];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i60 = 0; c11_i60 < 230; c11_i60++) {
    c11_b_inData[c11_i60] = (*(real_T (*)[230])c11_inData)[c11_i60];
  }

  for (c11_i61 = 0; c11_i61 < 230; c11_i61++) {
    c11_u[c11_i61] = c11_b_inData[c11_i61];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 230), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i62;
  char_T c11_b_inData[109];
  int32_T c11_i63;
  char_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i62 = 0; c11_i62 < 109; c11_i62++) {
    c11_b_inData[c11_i62] = (*(char_T (*)[109])c11_inData)[c11_i62];
  }

  for (c11_i63 = 0; c11_i63 < 109; c11_i63++) {
    c11_u[c11_i63] = c11_b_inData[c11_i63];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 109),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i64;
  real_T c11_b_inData[109];
  int32_T c11_i65;
  real_T c11_u[109];
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i64 = 0; c11_i64 < 109; c11_i64++) {
    c11_b_inData[c11_i64] = (*(real_T (*)[109])c11_inData)[c11_i64];
  }

  for (c11_i65 = 0; c11_i65 < 109; c11_i65++) {
    c11_u[c11_i65] = c11_b_inData[c11_i65];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 109), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

const mxArray *sf_c11_Demo_P_IdleRand_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 5, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/7-10-2015-Matlab-Demo/encStr2Arr.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1435183461U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_activate_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  if (chartInstance->c11_temporalCounter_i1 < 511U) {
    chartInstance->c11_temporalCounter_i1 = (uint16_T)((uint32_T)
      chartInstance->c11_temporalCounter_i1 + 1U);
  }
}

static void c11_reset_counters_secsc11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c11_Demo_P_IdleRand_secs(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_activate_secsc11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c11_Demo_P_IdleRand_secs
  (SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_increment_counters_secsc11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c11_Demo_P_IdleRand_secs(SimStruct
  *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_reset_counters_secsc11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_deactivate_c11_Demo_P_IdleRand_secs(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_deactivate_secsc11_Demo_P_IdleRand(chartInstance);
}

boolean_T sf_exported_auto_isStablec11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  return chartInstance->c11_isStable;
}

void sf_exported_auto_duringc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_c11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_enterc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_enter_atomic_c11_Demo_P_IdleRand(chartInstance);
  c11_enter_internal_c11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_exitc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_Demo_P_IdleRand(chartInstance);
}

void sf_exported_auto_gatewayc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc11_Demo_P_IdleRand(SimStruct *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_initc11_Demo_P_IdleRand(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec11_Demo_P_IdleRand(SimStruct *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out, sf_internal_get_sim_state_c11_Demo_P_IdleRand(c11_S),
                false);
  return c11_out;
}

void sf_exported_auto_setSimstatec11_Demo_P_IdleRand(SimStruct *c11_S, const
  mxArray *c11_in)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c11_Demo_P_IdleRand(c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void sf_exported_auto_check_state_inconsistency_c11_Demo_P_IdleRand(SimStruct
  *c11_S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_P_IdleRandMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_insertQueuec11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, real_T c11_bmls[1280],
   real_T c11_myBML[256], real_T c11_newBmls[1280])
{
  uint32_T c11_debug_family_var_map[8];
  real_T c11_full;
  real_T c11_t[256];
  real_T c11_i;
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i66;
  static real_T c11_varargin_2[256] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c11_i67;
  int32_T c11_i68;
  int32_T c11_i69;
  int32_T c11_i70;
  int32_T c11_i71;
  int32_T c11_b_i;
  int32_T c11_c_i;
  int32_T c11_i72;
  real_T c11_varargin_1[256];
  boolean_T c11_p;
  boolean_T c11_b_p;
  int32_T c11_k;
  real_T c11_b_k;
  real_T c11_x1;
  real_T c11_x2;
  boolean_T c11_c_p;
  int32_T c11_d_i;
  int32_T c11_i73;
  int32_T c11_i74;
  real_T c11_b_bmls[256];
  int32_T c11_i75;
  int32_T c11_i76;
  real_T c11_c_bmls[256];
  int32_T c11_i77;
  int32_T c11_i78;
  real_T c11_d_bmls[256];
  int32_T c11_i79;
  int32_T c11_i80;
  int32_T c11_i81;
  int32_T exitg1;
  boolean_T exitg2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_full, 0U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_t, 1U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_bmls, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_newBmls, 7U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 2);
  c11_full = 1.0;
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 3);
  for (c11_i66 = 0; c11_i66 < 256; c11_i66++) {
    c11_t[c11_i66] = c11_varargin_2[c11_i66];
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 4);
  for (c11_i67 = 0; c11_i67 < 256; c11_i67++) {
    c11_newBmls[c11_i67] = c11_t[c11_i67];
  }

  for (c11_i68 = 0; c11_i68 < 256; c11_i68++) {
    c11_newBmls[c11_i68 + 256] = c11_t[c11_i68];
  }

  for (c11_i69 = 0; c11_i69 < 256; c11_i69++) {
    c11_newBmls[c11_i69 + 512] = c11_t[c11_i69];
  }

  for (c11_i70 = 0; c11_i70 < 256; c11_i70++) {
    c11_newBmls[c11_i70 + 768] = c11_t[c11_i70];
  }

  for (c11_i71 = 0; c11_i71 < 256; c11_i71++) {
    c11_newBmls[c11_i71 + 1024] = c11_t[c11_i71];
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 5);
  c11_i = 1.0;
  c11_b_i = 0;
  do {
    exitg1 = 0;
    if (c11_b_i < 5) {
      c11_i = 1.0 + (real_T)c11_b_i;
      CV_EML_FOR(2, 1, 0, 1);
      _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 6);
      c11_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)_SFD_INTEGER_CHECK(
        "i", c11_i), 1, 5, 2, 0) - 1;
      for (c11_i72 = 0; c11_i72 < 256; c11_i72++) {
        c11_varargin_1[c11_i72] = c11_bmls[c11_i72 + (c11_c_i << 8)];
      }

      c11_p = false;
      c11_b_p = true;
      c11_k = 0;
      exitg2 = false;
      while ((exitg2 == false) && (c11_k < 256)) {
        c11_b_k = 1.0 + (real_T)c11_k;
        c11_x1 = c11_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c11_b_k), 1, 256, 1, 0) - 1];
        c11_x2 = c11_varargin_2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c11_b_k), 1, 256, 1, 0) - 1];
        c11_c_p = (c11_x1 == c11_x2);
        if (!c11_c_p) {
          c11_b_p = false;
          exitg2 = true;
        } else {
          c11_k++;
        }
      }

      if (!c11_b_p) {
      } else {
        c11_p = true;
      }

      if (CV_EML_IF(2, 1, 0, c11_p)) {
        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 8);
        c11_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("bmls", (int32_T)
          _SFD_INTEGER_CHECK("i", c11_i), 1, 5, 2, 0) - 1;
        for (c11_i73 = 0; c11_i73 < 256; c11_i73++) {
          c11_bmls[c11_i73 + (c11_d_i << 8)] = c11_myBML[c11_i73];
        }

        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 9);
        c11_full = 0.0;
        _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 10);
        exitg1 = 1;
      } else {
        c11_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(2, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 13);
  if (CV_EML_IF(2, 1, 1, c11_full != 0.0)) {
    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 15);
    for (c11_i74 = 0; c11_i74 < 256; c11_i74++) {
      c11_b_bmls[c11_i74] = c11_bmls[c11_i74 + 256];
    }

    for (c11_i75 = 0; c11_i75 < 256; c11_i75++) {
      c11_bmls[c11_i75] = c11_b_bmls[c11_i75];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 16);
    for (c11_i76 = 0; c11_i76 < 256; c11_i76++) {
      c11_c_bmls[c11_i76] = c11_bmls[c11_i76 + 512];
    }

    for (c11_i77 = 0; c11_i77 < 256; c11_i77++) {
      c11_bmls[c11_i77 + 256] = c11_c_bmls[c11_i77];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 17);
    for (c11_i78 = 0; c11_i78 < 256; c11_i78++) {
      c11_d_bmls[c11_i78] = c11_bmls[c11_i78 + 768];
    }

    for (c11_i79 = 0; c11_i79 < 256; c11_i79++) {
      c11_bmls[c11_i79 + 512] = c11_d_bmls[c11_i79];
    }

    _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 18);
    for (c11_i80 = 0; c11_i80 < 256; c11_i80++) {
      c11_bmls[c11_i80 + 1024] = c11_myBML[c11_i80];
    }
  }

  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, 20);
  for (c11_i81 = 0; c11_i81 < 1280; c11_i81++) {
    c11_newBmls[c11_i81] = c11_bmls[c11_i81];
  }

  c11_updateDataWrittenToVector(chartInstance, 6U);
  _SFD_EML_CALL(2U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_smileTablec11_Demo_P_IdleRand
  (SFc11_Demo_P_IdleRandInstanceStruct *chartInstance, real_T c11_bmlID, real_T *
   c11_p, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[7];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 2.0;
  real_T c11_dv13[256];
  int32_T c11_i82;
  uint32_T c11_b_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[109];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[109];
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_myarr256[256];
  int32_T c11_i83;
  static char_T c11_cv1[109] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'g', 'a', 'z', 'e', 'T', 'a', 'r', 'g',
    'e', 't', '\"', ' ', 's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e',
    'n', 'd', '=', '\"', '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e',
    '-', 'h', 'i', 'n', 't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/',
    'b', 'm', 'l', '>', '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i84;
  static real_T c11_dv14[109] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 103.0, 97.0, 122.0, 101.0, 84.0, 97.0, 114.0,
    103.0, 101.0, 116.0, 34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0,
    34.0, 48.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 53.0, 34.0, 32.0,
    115.0, 98.0, 109.0, 58.0, 116.0, 105.0, 109.0, 101.0, 45.0, 104.0, 105.0,
    110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0, 34.0, 47.0, 62.0, 60.0, 47.0,
    98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0, 116.0, 62.0 };

  int32_T c11_i85;
  int32_T c11_i86;
  int32_T c11_i87;
  int32_T c11_i88;
  int32_T c11_i89;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_c_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_f_sf_marshallOut, c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 4U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p, 5U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  CV_EML_FCN(3, 0);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(3, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(3, 1);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
    c11_encStr2Arr(chartInstance, c11_dv13);
    for (c11_i82 = 0; c11_i82 < 256; c11_i82++) {
      c11_poseBML[c11_i82] = c11_dv13[c11_i82];
    }

    c11_updateDataWrittenToVector(chartInstance, 8U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
    *c11_p = 3.0;
    c11_updateDataWrittenToVector(chartInstance, 7U);
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(3, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(3, 2);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_e_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_j_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_c_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
        c11_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_i_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 6U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 7U,
        c11_c_sf_marshallOut, c11_c_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U,
        c11_d_sf_marshallOut, c11_d_sf_marshallIn);
      for (c11_i83 = 0; c11_i83 < 109; c11_i83++) {
        c11_mystr[c11_i83] = c11_cv1[c11_i83];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
      c11_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
      for (c11_i84 = 0; c11_i84 < 109; c11_i84++) {
        c11_arr[c11_i84] = c11_dv14[c11_i84];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
      c11_ss = 109.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
      c11_padsize = c11_maxarrsize - c11_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
      for (c11_i85 = 0; c11_i85 < 256; c11_i85++) {
        c11_tt[c11_i85] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
      for (c11_i86 = 0; c11_i86 < 109; c11_i86++) {
        c11_tt[c11_i86] = c11_arr[c11_i86];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
      for (c11_i87 = 0; c11_i87 < 256; c11_i87++) {
        c11_myarr256[c11_i87] = c11_tt[c11_i87];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c11_i88 = 0; c11_i88 < 256; c11_i88++) {
        c11_poseBML[c11_i88] = c11_myarr256[c11_i88];
      }

      c11_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 33);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(3, 1);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
      c11_encStr2Arr(chartInstance, c11_dv13);
      for (c11_i89 = 0; c11_i89 < 256; c11_i89++) {
        c11_poseBML[c11_i89] = c11_dv13[c11_i89];
      }

      c11_updateDataWrittenToVector(chartInstance, 8U);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, 27);
      *c11_p = 3.0;
      c11_updateDataWrittenToVector(chartInstance, 7U);
      _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(3U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

void sf_exported_user_c11_Demo_P_IdleRand_insertQueue(SimStruct *c11_S, real_T
  c11_bmls[1280], real_T c11_myBML[256], real_T c11_newBmls[1280])
{
  int32_T c11_i90;
  real_T c11_b_bmls[1280];
  int32_T c11_i91;
  real_T c11_b_myBML[256];
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  for (c11_i90 = 0; c11_i90 < 1280; c11_i90++) {
    c11_b_bmls[c11_i90] = c11_bmls[c11_i90];
  }

  for (c11_i91 = 0; c11_i91 < 256; c11_i91++) {
    c11_b_myBML[c11_i91] = c11_myBML[c11_i91];
  }

  c11_insertQueuec11_Demo_P_IdleRand(chartInstance, c11_b_bmls, c11_b_myBML,
    c11_newBmls);
}

void sf_exported_user_c11_Demo_P_IdleRand_smileTable(SimStruct *c11_S, real_T
  c11_bmlID, real_T *c11_p, real_T c11_poseBML[256])
{
  real_T c11_b_p;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c11_S))->instanceInfo)->chartInstance;
  c11_smileTablec11_Demo_P_IdleRand(chartInstance, c11_bmlID, &c11_b_p,
    c11_poseBML);
  *c11_p = c11_b_p;
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_j_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i92;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i92, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i92;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_secs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int8_T c11_y;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_k_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i93;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i93, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i93;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_l_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_tp_stateInitial, const char_T
  *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  return c11_y;
}

static uint8_T c11_m_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_stateInitial;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)chartInstanceVoid;
  c11_b_tp_stateInitial = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint16_T c11_n_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_temporalCounter_i1, const char_T
  *c11_identifier)
{
  uint16_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_temporalCounter_i1), &c11_thisId);
  sf_mex_destroy(&c11_b_temporalCounter_i1);
  return c11_y;
}

static uint16_T c11_o_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint16_T c11_y;
  uint16_T c11_u1;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u1, 1, 5, 0U, 0, 0U, 0);
  c11_y = c11_u1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static const mxArray *c11_p_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_q_emlrt_marshallIn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 8, 1, 0)] = true;
}

static void c11_errorIfDataNotWrittenToFcn(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_vectorIndex, uint32_T c11_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c11_dataNumber, c11_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c11_vectorIndex, 0, 8, 1,
    0)]);
}

static real_T c11_get_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#308) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_BML_address)[c11_b];
}

static void c11_set_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#308) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_BML_address)[c11_b] = c11_c;
}

static real_T *c11_access_BML(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_BML_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'BML\' (#308) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_BML_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#307) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_GAZE_WIN_address;
}

static void c11_set_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#307) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_GAZE_WIN_address = c11_c;
}

static real_T *c11_access_GAZE_WIN(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#307) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_GAZE_WIN_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#309) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_P_address;
}

static void c11_set_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
                      uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#309) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_P_address = c11_c;
}

static real_T *c11_access_P(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_P_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P\' (#309) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_P_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#314) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_BEFORE_address;
}

static void c11_set_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#314) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_BEFORE_address = c11_c;
}

static real_T *c11_access_STATE_BEFORE(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_STATE_BEFORE_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_BEFORE\' (#314) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_BEFORE_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#312) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_GO_address;
}

static void c11_set_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c11_b);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#312) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_GO_address = c11_c;
}

static real_T *c11_access_STATE_GO(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c11_STATE_GO_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_GO\' (#312) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_GO_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c11_c;
}

static real_T c11_get_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#313) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_STATE_READY_address;
}

static void c11_set_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 5, NULL, c11_b);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#313) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_STATE_READY_address = c11_c;
}

static real_T *c11_access_STATE_READY(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 5, NULL);
  if (chartInstance->c11_STATE_READY_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'STATE_READY\' (#313) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_STATE_READY_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 5, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#305) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_address;
}

static void c11_set_avert(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 6, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#305) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_address = c11_c;
}

static real_T *c11_access_avert(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 6, NULL);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#305) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 6, NULL);
  }

  return c11_c;
}

static real_T c11_get_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#317) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c11_bmlsM_address)[c11_b];
}

static void c11_set_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 7, NULL, c11_b);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#317) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c11_bmlsM_address)[c11_b] = c11_c;
}

static real_T *c11_access_bmlsM(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 7, NULL);
  if (chartInstance->c11_bmlsM_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsM\' (#317) in the initialization routine of the chart.\n");
  }

  c11_c = *chartInstance->c11_bmlsM_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 7, NULL);
  }

  return c11_c;
}

static real_T c11_get_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#315) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_changeFlag_address;
}

static void c11_set_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 8, NULL, c11_b);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#315) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_changeFlag_address = c11_c;
}

static real_T *c11_access_changeFlag(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 8, NULL);
  if (chartInstance->c11_changeFlag_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'changeFlag\' (#315) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_changeFlag_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 8, NULL);
  }

  return c11_c;
}

static real_T c11_get_gazing(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#306) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_gazing_address;
}

static void c11_set_gazing(SFc11_Demo_P_IdleRandInstanceStruct *chartInstance,
  uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 9, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#306) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_gazing_address = c11_c;
}

static real_T *c11_access_gazing(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 9, NULL);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#306) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_gazing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 9, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info(SFc11_Demo_P_IdleRandInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "BML", (void **)
    &chartInstance->c11_BML_address, &chartInstance->c11_BML_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c11_GAZE_WIN_address, &chartInstance->c11_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P", (void **)
    &chartInstance->c11_P_address, &chartInstance->c11_P_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_BEFORE", (void **)
    &chartInstance->c11_STATE_BEFORE_address,
    &chartInstance->c11_STATE_BEFORE_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_GO", (void **)
    &chartInstance->c11_STATE_GO_address, &chartInstance->c11_STATE_GO_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "STATE_READY", (void **)
    &chartInstance->c11_STATE_READY_address,
    &chartInstance->c11_STATE_READY_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c11_avert_address, &chartInstance->c11_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsM", (void **)
    &chartInstance->c11_bmlsM_address, &chartInstance->c11_bmlsM_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "changeFlag", (void **)
    &chartInstance->c11_changeFlag_address, &chartInstance->c11_changeFlag_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c11_gazing_address, &chartInstance->c11_gazing_index);
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

void sf_c11_Demo_P_IdleRand_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1376146544U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3667707537U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2294784209U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4127328833U);
}

mxArray *sf_c11_Demo_P_IdleRand_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IGsicNe0S9MF8OfOF6pNpF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Demo_P_IdleRand_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Demo_P_IdleRand_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_Demo_P_IdleRand(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[61],T\"gameState\",},{M[3],M[79],T\"BMLM\",},{M[3],M[55],T\"fileID\",},{M[3],M[80],T\"n\",},{M[3],M[77],T\"newBmlsM\",},{M[3],M[10],T\"smileN\",},{M[8],M[0],T\"is_active_c11_Demo_P_IdleRand\",},{M[9],M[0],T\"is_c11_Demo_P_IdleRand\",},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[81 67],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Demo_P_IdleRand_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_P_IdleRandMachineNumber_,
           11,
           7,
           8,
           0,
           24,
           1,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_P_IdleRandMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_P_IdleRandMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_P_IdleRandMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(1,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(2,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(3,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(4,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(5,11,0,0,"BML");
          _SFD_SET_DATA_PROPS(6,11,0,0,"P");
          _SFD_SET_DATA_PROPS(7,0,0,0,"fileID");
          _SFD_SET_DATA_PROPS(8,2,0,1,"gameState");
          _SFD_SET_DATA_PROPS(9,11,0,0,"STATE_GO");
          _SFD_SET_DATA_PROPS(10,11,0,0,"STATE_READY");
          _SFD_SET_DATA_PROPS(11,11,0,0,"STATE_BEFORE");
          _SFD_SET_DATA_PROPS(12,11,0,0,"changeFlag");
          _SFD_SET_DATA_PROPS(13,0,0,0,"newBmlsM");
          _SFD_SET_DATA_PROPS(14,11,0,0,"bmlsM");
          _SFD_SET_DATA_PROPS(15,0,0,0,"BMLM");
          _SFD_SET_DATA_PROPS(16,0,0,0,"n");
          _SFD_SET_DATA_PROPS(17,1,1,0,"personality");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,9,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,9,0,0,"");
          _SFD_SET_DATA_PROPS(23,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(2,0,2);
          _SFD_STATE_INFO(3,0,2);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,5);
          _SFD_CH_SUBSTATE_INDEX(4,6);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"insertQueuec11_Demo_P_IdleRand",0,-1,565);
        _SFD_CV_INIT_EML_IF(2,1,0,126,151,-1,-2);
        _SFD_CV_INIT_EML_IF(2,1,1,296,307,-1,546);
        _SFD_CV_INIT_EML_FOR(2,1,0,106,118,291);
        _SFD_CV_INIT_EML(3,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(3,0,"smileTablec11_Demo_P_IdleRand",0,-1,404);
        _SFD_CV_INIT_EML_FCN(3,1,"aFcnTruthTableAction_1",404,-1,707);
        _SFD_CV_INIT_EML_FCN(3,2,"aFcnTruthTableAction_2",707,-1,899);
        _SFD_CV_INIT_EML_FCN(3,3,"aFcnTruthTableAction_3",899,-1,1198);
        _SFD_CV_INIT_EML_IF(3,1,0,228,258,289,402);
        _SFD_CV_INIT_EML_IF(3,1,1,289,323,354,402);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,0,15,0,15);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,0,26,0,26);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,0,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,66,1,48);

        {
          static int condStart[] = { 1, 16, 40 };

          static int condEnd[] = { 15, 39, 66 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,66,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,0,26,0,26);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,0,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 256;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));

        {
          real_T *c11_isSmiling;
          real_T *c11_gameState;
          real_T *c11_personality;
          c11_personality = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_gameState = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c11_smileN);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_avert_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c11_BML_address);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c11_P_address);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c11_fileID);
          _SFD_SET_DATA_VALUE_PTR(8U, c11_gameState);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c11_STATE_GO_address);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c11_STATE_READY_address);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c11_STATE_BEFORE_address);
          _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c11_changeFlag_address);
          _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c11_newBmlsM);
          _SFD_SET_DATA_VALUE_PTR(14U, *chartInstance->c11_bmlsM_address);
          _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c11_BMLM);
          _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c11_n);
          _SFD_SET_DATA_VALUE_PTR(17U, c11_personality);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_P_IdleRandMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "VbrAtwmhWCQsyfAQ1yrNgE";
}

static void sf_opaque_initialize_c11_Demo_P_IdleRand(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
  initialize_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_Demo_P_IdleRand(void *chartInstanceVar)
{
  enable_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Demo_P_IdleRand(void *chartInstanceVar)
{
  disable_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Demo_P_IdleRand(void *chartInstanceVar)
{
  sf_gateway_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_Demo_P_IdleRand(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_Demo_P_IdleRand
    ((SFc11_Demo_P_IdleRandInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Demo_P_IdleRand();/* state var info */
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

extern void sf_internal_set_sim_state_c11_Demo_P_IdleRand(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_Demo_P_IdleRand();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_Demo_P_IdleRand(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c11_Demo_P_IdleRand(SimStruct* S, const
  mxArray *st)
{
}

static void sf_opaque_terminate_c11_Demo_P_IdleRand(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Demo_P_IdleRandInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_P_IdleRand_optimization_info();
    }

    finalize_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
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
  initSimStructsc11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Demo_P_IdleRand(SimStruct *S)
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
    initialize_params_c11_Demo_P_IdleRand((SFc11_Demo_P_IdleRandInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Demo_P_IdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_P_IdleRand_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2657594737U));
  ssSetChecksum1(S,(1027071414U));
  ssSetChecksum2(S,(69231537U));
  ssSetChecksum3(S,(1317257456U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Demo_P_IdleRand(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_Demo_P_IdleRand(SimStruct *S)
{
  SFc11_Demo_P_IdleRandInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_Demo_P_IdleRandInstanceStruct *)utMalloc(sizeof
    (SFc11_Demo_P_IdleRandInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Demo_P_IdleRandInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Demo_P_IdleRand;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Demo_P_IdleRand;
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

void c11_Demo_P_IdleRand_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Demo_P_IdleRand(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Demo_P_IdleRand(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Demo_P_IdleRand(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Demo_P_IdleRand_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
