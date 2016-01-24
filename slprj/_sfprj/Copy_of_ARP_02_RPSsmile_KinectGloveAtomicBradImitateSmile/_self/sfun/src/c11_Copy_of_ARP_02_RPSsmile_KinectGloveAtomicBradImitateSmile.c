/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_sfun.h"
#include "c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c11_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_stateCheckSmile         ((uint8_T)1U)
#define c11_IN_stateHeadNeutral        ((uint8_T)2U)
#define c11_IN_stateImitateSmile       ((uint8_T)3U)
#define c11_IN_stateInitial            ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "bmlID", "poseBML" };

static const char * c11_b_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c11_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

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

static const char * c11_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[2];

/* Function Declarations */
static void
  initialize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  initialize_params_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void enable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  disable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_update_debugger_state_c11_Copy_of_ARP_02_RPSsmile_KinectGlov
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_Copy_of_ARP_02_RPSsmile_Kinec
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  finalize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  sf_gateway_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_enter_atomic_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_enter_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmil
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_exit_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicB
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_initc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitate
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void
  initSimStructsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_encStr2Arr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_myarr256[256]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
   real_T c11_y[256]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_b_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_bmlID, const char_T *c11_identifier);
static real_T c11_c_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_d_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
   real_T c11_y[256]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_activate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_deactivate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_increment_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGlo
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_reset_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAt
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_a[256]);
static void c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_bmlID, real_T c11_poseBML[256]);
static void c11_sendBML
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static void c11_b_sendBML
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int8_T c11_f_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_g_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_h_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_b_tp_stateInitial, const char_T
   *c11_identifier);
static uint8_T c11_i_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_j_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T
   *c11_identifier);
static const mxArray *c11_k_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_vectorIndex);
static real_T c11_get_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static void c11_set_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static real_T c11_get_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static void c11_set_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static real_T c11_get_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static void c11_set_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static real_T c11_get_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static void c11_set_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c);
static real_T *c11_access_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b);
static void init_dsm_address_info
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance);

/* Function Definitions */
static void
  initialize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void
  initialize_params_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void
  disable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c11_update_debugger_state_c11_Copy_of_ARP_02_RPSsmile_KinectGlov
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
      == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 8U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      == c11_IN_stateInitial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      == c11_IN_stateCheckSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      == c11_IN_stateHeadNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      == c11_IN_stateImitateSmile) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray
  *get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T c11_c_hoistedGlobal;
  uint8_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(3, 1), false);
  c11_hoistedGlobal = chartInstance->c11_smileN;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal =
    chartInstance->c11_is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_hoistedGlobal =
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS;
  c11_c_u = c11_c_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void
  set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  c11_u = sf_mex_dup(c11_st);
  chartInstance->c11_smileN = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 0)), "smileN");
  chartInstance->c11_is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
    = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile");
  chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
    = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_Copy_of_ARP_02_RPSsmile_KinectGlov(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_Copy_of_ARP_02_RPSsmile_Kinec
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        == c11_IN_stateCheckSmile) {
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      chartInstance->c11_tp_stateCheckSmile = 0U;
    }

    if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        == c11_IN_stateHeadNeutral) {
      chartInstance->c11_tp_stateHeadNeutral = 1U;
    } else {
      chartInstance->c11_tp_stateHeadNeutral = 0U;
    }

    if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        == c11_IN_stateImitateSmile) {
      chartInstance->c11_tp_stateImitateSmile = 1U;
    } else {
      chartInstance->c11_tp_stateImitateSmile = 0U;
    }

    if (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        == c11_IN_stateInitial) {
      chartInstance->c11_tp_stateInitial = 1U;
    } else {
      chartInstance->c11_tp_stateInitial = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void
  finalize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void
  sf_gateway_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  c11_set_sim_state_side_effects_c11_Copy_of_ARP_02_RPSsmile_Kinec(chartInstance);
}

static void c11_enter_atomic_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  chartInstance->c11_is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
    = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void c11_enter_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  chartInstance->c11_isStable = false;
  chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
    = c11_IN_stateInitial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
  chartInstance->c11_tp_stateInitial = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  c11_set_avert(chartInstance, 0, 0.0);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmil
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  uint32_T c11_debug_family_var_map[3];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 1.0;
  boolean_T c11_out;
  uint32_T c11_b_debug_family_var_map[2];
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 0.0;
  real_T c11_dv0[256];
  int32_T c11_i0;
  real_T c11_dv1[256];
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_b_out;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 0.0;
  int32_T c11_i1;
  real_T c11_dv2[256];
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_f_nargin = 0.0;
  real_T c11_f_nargout = 1.0;
  boolean_T c11_d_out;
  real_T c11_g_nargin = 0.0;
  real_T c11_g_nargout = 1.0;
  boolean_T c11_e_out;
  real_T c11_h_nargin = 0.0;
  real_T c11_h_nargout = 0.0;
  int32_T c11_i2;
  real_T c11_dv3[256];
  real_T *c11_isSmiling;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_isStable = true;
  switch
    (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS)
  {
   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_j_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    guard3 = false;
    guard4 = false;
    if (CV_EML_COND(2, 0, 0, *c11_isSmiling == 1.0)) {
      if (CV_EML_COND(2, 0, 1, c11_get_avert(chartInstance, 0) == 0.0)) {
        if (CV_EML_COND(2, 0, 2, c11_get_isPosing(chartInstance, 0) == 0.0)) {
          CV_EML_MCDC(2, 0, 0, true);
          CV_EML_IF(2, 0, 0, true);
          c11_out = true;
        } else {
          guard3 = true;
        }
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(2, 0, 0, false);
      CV_EML_IF(2, 0, 0, false);
      c11_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        = c11_IN_stateHeadNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateHeadNeutral = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_e_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
        (chartInstance, 2.0, c11_dv0);
      for (c11_i0 = 0; c11_i0 < 256; c11_i0++) {
        c11_dv1[c11_i0] = c11_dv0[c11_i0];
      }

      c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit
        (chartInstance, c11_dv1);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateHeadNeutral:
    CV_CHART_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_l_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(5, 0, 0, *c11_isSmiling == 1.0)) {
      if (CV_EML_COND(5, 0, 1, c11_get_isPosing(chartInstance, 0) == 0.0)) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c11_b_out = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(5, 0, 0, false);
      CV_EML_IF(5, 0, 0, false);
      c11_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c11_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateHeadNeutral = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        = c11_IN_stateImitateSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateImitateSmile = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_f_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
        (chartInstance, 1.0, c11_dv0);
      for (c11_i1 = 0; c11_i1 < 256; c11_i1++) {
        c11_dv2[c11_i1] = c11_dv0[c11_i1];
      }

      c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit
        (chartInstance, c11_dv2);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_i_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U, c11_c_sf_marshallOut,
        c11_c_sf_marshallIn);
      c11_c_out = CV_EML_IF(7, 0, 0, *c11_isSmiling == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateHeadNeutral = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
          = c11_IN_stateCheckSmile;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateCheckSmile = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateImitateSmile:
    CV_CHART_EVAL(8, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c11_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_h_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargin, 0U, c11_b_sf_marshallOut,
      c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargout, 1U,
      c11_b_sf_marshallOut, c11_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_c_sf_marshallOut,
      c11_c_sf_marshallIn);
    c11_d_out = CV_EML_IF(6, 0, 0, *c11_isSmiling == 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c11_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateImitateSmile = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
      chartInstance->c11_isStable = false;
      chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
        = c11_IN_stateCheckSmile;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
      chartInstance->c11_tp_stateCheckSmile = 1U;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_k_debug_family_names,
        c11_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargin, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_g_nargout, 1U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_out, 2U, c11_c_sf_marshallOut,
        c11_c_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(3, 0, 0, *c11_isSmiling == 1.0)) {
        if (CV_EML_COND(3, 0, 1, c11_get_avert(chartInstance, 0) == 0.0)) {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c11_e_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c11_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c11_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateImitateSmile = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
        chartInstance->c11_isStable = false;
        chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
          = c11_IN_stateHeadNeutral;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_stateHeadNeutral = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_e_debug_family_names,
          c11_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargin, 0U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_h_nargout, 1U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
          (chartInstance, 2.0, c11_dv0);
        for (c11_i2 = 0; c11_i2 < 256; c11_i2++) {
          c11_dv3[c11_i2] = c11_dv0[c11_i2];
        }

        c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit
          (chartInstance, c11_dv3);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c11_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(8, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateInitial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    chartInstance->c11_isStable = false;
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_stateCheckSmile;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_stateCheckSmile = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void c11_exit_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicB
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  switch
    (chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS)
  {
   case c11_IN_stateCheckSmile:
    CV_CHART_EVAL(8, 0, 1);
    chartInstance->c11_tp_stateCheckSmile = 0U;
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateHeadNeutral:
    CV_CHART_EVAL(8, 0, 2);
    chartInstance->c11_tp_stateHeadNeutral = 0U;
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateImitateSmile:
    CV_CHART_EVAL(8, 0, 3);
    chartInstance->c11_tp_stateImitateSmile = 0U;
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    break;

   case c11_IN_stateInitial:
    CV_CHART_EVAL(8, 0, 4);
    chartInstance->c11_tp_stateInitial = 0U;
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c11_sfEvent);
    break;

   default:
    CV_CHART_EVAL(8, 0, 0);
    chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
      = c11_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
    break;
  }
}

static void c11_initc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitate
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_stateCheckSmile = 0U;
  chartInstance->c11_tp_stateHeadNeutral = 0U;
  chartInstance->c11_tp_stateImitateSmile = 0U;
  chartInstance->c11_tp_stateInitial = 0U;
  chartInstance->c11_is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
    = 0U;
  chartInstance->c11_is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateS
    = c11_IN_NO_ACTIVE_CHILD;
}

static void
  initSimStructsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c11_encStr2Arr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_myarr256[256])
{
  uint32_T c11_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[222];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[222];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i3;
  static char_T c11_cv0[222] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', '?', '>', '<', 'a', 'c',
    't', '>', '<', 'b', 'm', 'l', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '1', '\"', ' ', 'a', 'u', '=', '\"', '1', '2',
    '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ', 's',
    't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e',
    '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '4', '\"',
    ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 't', 'y', 'p', 'e', '=', '\"',
    'f', 'a', 'c', 's', '\"', '/', '>', '<', 'f', 'a', 'c', 'e', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\"', '0', '.', '3', '\"', ' ', 'a', 'u', '=', '\"',
    '6', '\"', ' ', 's', 'i', 'd', 'e', '=', '\"', 'B', 'O', 'T', 'H', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 's', 't', 'r', 'o', 'k',
    'e', '=', '\"', '2', '\"', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\"', '4',
    '\"', ' ', 'e', 'n', 'd', '=', '\"', '6', '\"', ' ', 't', 'y', 'p', 'e', '=',
    '\"', 'f', 'a', 'c', 's', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>', '<',
    '/', 'a', 'c', 't', '>' };

  int32_T c11_i4;
  static real_T c11_dv4[222] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0, 62.0,
    60.0, 102.0, 97.0, 99.0, 101.0, 32.0, 97.0, 109.0, 111.0, 117.0, 110.0,
    116.0, 61.0, 34.0, 49.0, 34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 49.0, 50.0,
    34.0, 32.0, 115.0, 105.0, 100.0, 101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0,
    34.0, 32.0, 115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0,
    115.0, 116.0, 114.0, 111.0, 107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0,
    114.0, 101.0, 108.0, 97.0, 120.0, 61.0, 34.0, 52.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 54.0, 34.0, 32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0,
    102.0, 97.0, 99.0, 115.0, 34.0, 47.0, 62.0, 60.0, 102.0, 97.0, 99.0, 101.0,
    32.0, 97.0, 109.0, 111.0, 117.0, 110.0, 116.0, 61.0, 34.0, 48.0, 46.0, 51.0,
    34.0, 32.0, 97.0, 117.0, 61.0, 34.0, 54.0, 34.0, 32.0, 115.0, 105.0, 100.0,
    101.0, 61.0, 34.0, 66.0, 79.0, 84.0, 72.0, 34.0, 32.0, 115.0, 116.0, 97.0,
    114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 115.0, 116.0, 114.0, 111.0,
    107.0, 101.0, 61.0, 34.0, 50.0, 34.0, 32.0, 114.0, 101.0, 108.0, 97.0, 120.0,
    61.0, 34.0, 52.0, 34.0, 32.0, 101.0, 110.0, 100.0, 61.0, 34.0, 54.0, 34.0,
    32.0, 116.0, 121.0, 112.0, 101.0, 61.0, 34.0, 102.0, 97.0, 99.0, 115.0, 34.0,
    47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0, 99.0,
    116.0, 62.0 };

  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  for (c11_i3 = 0; c11_i3 < 222; c11_i3++) {
    c11_mystr[c11_i3] = c11_cv0[c11_i3];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_maxarrsize = 256.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i4 = 0; c11_i4 < 222; c11_i4++) {
    c11_arr[c11_i4] = c11_dv4[c11_i4];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_ss = 222.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_padsize = c11_maxarrsize - c11_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  for (c11_i5 = 0; c11_i5 < 256; c11_i5++) {
    c11_tt[c11_i5] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i6 = 0; c11_i6 < 222; c11_i6++) {
    c11_tt[c11_i6] = c11_arr[c11_i6];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i7 = 0; c11_i7 < 256; c11_i7++) {
    c11_myarr256[c11_i7] = c11_tt[c11_i7];
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
    "C:\\Users\\root180\\Documents\\affective-project\\4-6-2015-Matlab-M+M\\encStr2Arr.m"));
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i8;
  real_T c11_b_inData[256];
  int32_T c11_i9;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i8 = 0; c11_i8 < 256; c11_i8++) {
    c11_b_inData[c11_i8] = (*(real_T (*)[256])c11_inData)[c11_i8];
  }

  for (c11_i9 = 0; c11_i9 < 256; c11_i9++) {
    c11_u[c11_i9] = c11_b_inData[c11_i9];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 256, 1),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
   real_T c11_y[256])
{
  real_T c11_dv5[256];
  int32_T c11_i10;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv5, 1, 0, 0U, 1, 0U, 2,
                256, 1);
  for (c11_i10 = 0; c11_i10 < 256; c11_i10++) {
    c11_y[c11_i10] = c11_dv5[c11_i10];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_poseBML;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[256];
  int32_T c11_i11;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_poseBML = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_poseBML), &c11_thisId,
                       c11_y);
  sf_mex_destroy(&c11_poseBML);
  for (c11_i11 = 0; c11_i11 < 256; c11_i11++) {
    (*(real_T (*)[256])c11_outData)[c11_i11] = c11_y[c11_i11];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_b_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_bmlID, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_bmlID),
    &c11_thisId);
  sf_mex_destroy(&c11_bmlID);
  return c11_y;
}

static real_T c11_c_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
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

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_bmlID;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_bmlID = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_bmlID),
    &c11_thisId);
  sf_mex_destroy(&c11_bmlID);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_d_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
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

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_aVarTruthTableCondition_2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_aVarTruthTableCondition_2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_aVarTruthTableCondition_2), &c11_thisId);
  sf_mex_destroy(&c11_aVarTruthTableCondition_2);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i12;
  real_T c11_b_inData[256];
  int32_T c11_i13;
  real_T c11_u[256];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i12 = 0; c11_i12 < 256; c11_i12++) {
    c11_b_inData[c11_i12] = (*(real_T (*)[256])c11_inData)[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 256; c11_i13++) {
    c11_u[c11_i13] = c11_b_inData[c11_i13];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 256), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
   real_T c11_y[256])
{
  real_T c11_dv6[256];
  int32_T c11_i14;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv6, 1, 0, 0U, 1, 0U, 1,
                256);
  for (c11_i14 = 0; c11_i14 < 256; c11_i14++) {
    c11_y[c11_i14] = c11_dv6[c11_i14];
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
  int32_T c11_i15;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_myarr256 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_myarr256), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_myarr256);
  for (c11_i15 = 0; c11_i15 < 256; c11_i15++) {
    (*(real_T (*)[256])c11_outData)[c11_i15] = c11_y[c11_i15];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i16;
  char_T c11_b_inData[222];
  int32_T c11_i17;
  char_T c11_u[222];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i16 = 0; c11_i16 < 222; c11_i16++) {
    c11_b_inData[c11_i16] = (*(char_T (*)[222])c11_inData)[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 222; c11_i17++) {
    c11_u[c11_i17] = c11_b_inData[c11_i17];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 222),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i18;
  real_T c11_b_inData[222];
  int32_T c11_i19;
  real_T c11_u[222];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i18 = 0; c11_i18 < 222; c11_i18++) {
    c11_b_inData[c11_i18] = (*(real_T (*)[222])c11_inData)[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 222; c11_i19++) {
    c11_u[c11_i19] = c11_b_inData[c11_i19];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 222), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i20;
  char_T c11_b_inData[105];
  int32_T c11_i21;
  char_T c11_u[105];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i20 = 0; c11_i20 < 105; c11_i20++) {
    c11_b_inData[c11_i20] = (*(char_T (*)[105])c11_inData)[c11_i20];
  }

  for (c11_i21 = 0; c11_i21 < 105; c11_i21++) {
    c11_u[c11_i21] = c11_b_inData[c11_i21];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 105),
                false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i22;
  real_T c11_b_inData[105];
  int32_T c11_i23;
  real_T c11_u[105];
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i22 = 0; c11_i22 < 105; c11_i22++) {
    c11_b_inData[c11_i22] = (*(real_T (*)[105])c11_inData)[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 105; c11_i23++) {
    c11_u[c11_i23] = c11_b_inData[c11_i23];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 105), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

const mxArray
  *sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/4-6-2015-Matlab-M+M/encStr2Arr.m"),
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
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
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

static void c11_activate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  chartInstance->c11_sfEvent = c11_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_deactivate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c11_event_secs,
               chartInstance->c11_sfEvent);
}

static void c11_increment_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGlo
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c11_reset_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAt
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

void
  sf_exported_auto_activate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_activate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr(chartInstance);
}

void
  sf_exported_auto_incrementTemporalCounter_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_increment_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGlo(chartInstance);
}

void
  sf_exported_auto_resetTemporalCounter_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_reset_counters_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAt(chartInstance);
}

void
  sf_exported_auto_deactivate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_secs
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_deactivate_secsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic(chartInstance);
}

boolean_T
  sf_exported_auto_isStablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  return chartInstance->c11_isStable;
}

void
  sf_exported_auto_duringc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmil(chartInstance);
}

void
  sf_exported_auto_enterc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_sendBML(chartInstance);
  c11_enter_atomic_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBr(chartInstance);
  c11_enter_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomic(chartInstance);
}

void
  sf_exported_auto_exitc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_exit_internal_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicB(chartInstance);
  c11_b_sendBML(chartInstance);
}

void
  sf_exported_auto_gatewayc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void
  sf_exported_auto_enablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_sendBML(chartInstance);
}

void
  sf_exported_auto_disablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c11_b_sendBML(chartInstance);
}

void
  sf_exported_auto_stepBuffersc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
}

void
  sf_exported_auto_initBuffersc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
}

void
  sf_exported_auto_activate_callc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  chartInstance->c11_sfEvent = CALL_EVENT;
}

void
  sf_exported_auto_increment_call_counterc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
}

void
  sf_exported_auto_reset_call_counterc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
}

void
  sf_exported_auto_deactivate_callc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
}

void
  sf_exported_auto_initc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_initc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitate(chartInstance);
}

const mxArray
  *sf_exported_auto_getSimstatec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  const mxArray *c11_out = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_out = NULL;
  sf_mex_assign(&c11_out,
                sf_internal_get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
                (c11_S), false);
  return c11_out;
}

void
  sf_exported_auto_setSimstatec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S, const mxArray *c11_in)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    (c11_S, sf_mex_dup(c11_in));
  sf_mex_destroy(&c11_in);
}

void
  sf_exported_auto_check_state_inconsistency_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *c11_S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_a[256])
{
  int32_T c11_i24;
  int32_T c11_i25;
  int32_T c11_i26;
  real_T (*c11_b_a)[256];
  c11_b_a = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  for (c11_i24 = 0; c11_i24 < 256; c11_i24++) {
    _SFD_DATA_RANGE_CHECK(c11_a[c11_i24], 6U);
  }

  _SFD_SET_DATA_VALUE_PTR(6U, c11_a);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(1U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("a", c11_a, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
  for (c11_i25 = 0; c11_i25 < 256; c11_i25++) {
    (*c11_b_a)[c11_i25] = c11_a[c11_i25];
  }

  for (c11_i26 = 0; c11_i26 < 256; c11_i26++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_a)[c11_i26], 6U);
  }

  sf_call_output_fcn_call(chartInstance->S, 0, "sendBML", 0);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(6U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
}

static void c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, real_T c11_bmlID, real_T c11_poseBML[256])
{
  uint32_T c11_debug_family_var_map[6];
  boolean_T c11_aVarTruthTableCondition_1;
  boolean_T c11_aVarTruthTableCondition_2;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_dv7[256];
  int32_T c11_i27;
  uint32_T c11_b_debug_family_var_map[9];
  real_T c11_maxarrsize;
  real_T c11_arr[105];
  real_T c11_ss;
  real_T c11_padsize;
  real_T c11_tt[256];
  char_T c11_mystr[105];
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_myarr256[256];
  int32_T c11_i28;
  static char_T c11_cv1[105] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r',
    's', 'i', 'o', 'n', '=', '\"', '1', '.', '0', '\"', ' ', '?', '>', '<', 'a',
    'c', 't', '>', '<', 'b', 'm', 'l', '>', '<', 'g', 'a', 'z', 'e', ' ', 't',
    'a', 'r', 'g', 'e', 't', '=', '\"', 'c', 'a', 'm', 'e', 'r', 'a', '\"', ' ',
    's', 't', 'a', 'r', 't', '=', '\"', '0', '\"', ' ', 'e', 'n', 'd', '=', '\"',
    '5', '\"', ' ', 's', 'b', 'm', ':', 't', 'i', 'm', 'e', '-', 'h', 'i', 'n',
    't', '=', '\"', '1', '.', '5', '\"', '/', '>', '<', '/', 'b', 'm', 'l', '>',
    '<', '/', 'a', 'c', 't', '>' };

  int32_T c11_i29;
  static real_T c11_dv8[105] = { 60.0, 63.0, 120.0, 109.0, 108.0, 32.0, 118.0,
    101.0, 114.0, 115.0, 105.0, 111.0, 110.0, 61.0, 34.0, 49.0, 46.0, 48.0, 34.0,
    32.0, 63.0, 62.0, 60.0, 97.0, 99.0, 116.0, 62.0, 60.0, 98.0, 109.0, 108.0,
    62.0, 60.0, 103.0, 97.0, 122.0, 101.0, 32.0, 116.0, 97.0, 114.0, 103.0,
    101.0, 116.0, 61.0, 34.0, 99.0, 97.0, 109.0, 101.0, 114.0, 97.0, 34.0, 32.0,
    115.0, 116.0, 97.0, 114.0, 116.0, 61.0, 34.0, 48.0, 34.0, 32.0, 101.0, 110.0,
    100.0, 61.0, 34.0, 53.0, 34.0, 32.0, 115.0, 98.0, 109.0, 58.0, 116.0, 105.0,
    109.0, 101.0, 45.0, 104.0, 105.0, 110.0, 116.0, 61.0, 34.0, 49.0, 46.0, 53.0,
    34.0, 47.0, 62.0, 60.0, 47.0, 98.0, 109.0, 108.0, 62.0, 60.0, 47.0, 97.0,
    99.0, 116.0, 62.0 };

  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_1, 0U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_aVarTruthTableCondition_2, 1U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_bmlID, 4U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_poseBML, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 3);
  c11_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 4);
  c11_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 9);
  c11_aVarTruthTableCondition_1 = (c11_bmlID == 1.0);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 13);
  c11_aVarTruthTableCondition_2 = (c11_bmlID == 2.0);
  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 15);
  if (CV_EML_IF(1, 1, 0, c11_aVarTruthTableCondition_1)) {
    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 16);
    CV_EML_FCN(1, 1);
    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 27);
    c11_encStr2Arr(chartInstance, c11_dv7);
    for (c11_i27 = 0; c11_i27 < 256; c11_i27++) {
      c11_poseBML[c11_i27] = c11_dv7[c11_i27];
    }

    c11_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -27);
  } else {
    _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 17);
    if (CV_EML_IF(1, 1, 1, c11_aVarTruthTableCondition_2)) {
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 18);
      CV_EML_FCN(1, 2);
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 33);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c11_c_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_maxarrsize, 0U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_arr, 1U, c11_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c11_ss, 2U, c11_b_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_padsize, 3U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_tt, 4U, c11_d_sf_marshallOut,
        c11_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(c11_mystr, 5U, c11_g_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 6U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 7U,
        c11_b_sf_marshallOut, c11_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_myarr256, 8U,
        c11_d_sf_marshallOut, c11_d_sf_marshallIn);
      for (c11_i28 = 0; c11_i28 < 105; c11_i28++) {
        c11_mystr[c11_i28] = c11_cv1[c11_i28];
      }

      CV_SCRIPT_FCN(0, 0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 3);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
      c11_maxarrsize = 256.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
      for (c11_i29 = 0; c11_i29 < 105; c11_i29++) {
        c11_arr[c11_i29] = c11_dv8[c11_i29];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
      c11_ss = 105.0;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
      c11_padsize = c11_maxarrsize - c11_ss;
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
      for (c11_i30 = 0; c11_i30 < 256; c11_i30++) {
        c11_tt[c11_i30] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
      for (c11_i31 = 0; c11_i31 < 105; c11_i31++) {
        c11_tt[c11_i31] = c11_arr[c11_i31];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
      for (c11_i32 = 0; c11_i32 < 256; c11_i32++) {
        c11_myarr256[c11_i32] = c11_tt[c11_i32];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -11);
      _SFD_SYMBOL_SCOPE_POP();
      for (c11_i33 = 0; c11_i33 < 256; c11_i33++) {
        c11_poseBML[c11_i33] = c11_myarr256[c11_i33];
      }

      c11_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -33);
    } else {
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 20);
      CV_EML_FCN(1, 1);
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, 27);
      c11_encStr2Arr(chartInstance, c11_dv7);
      for (c11_i34 = 0; c11_i34 < 256; c11_i34++) {
        c11_poseBML[c11_i34] = c11_dv7[c11_i34];
      }

      c11_updateDataWrittenToVector(chartInstance, 1U);
      _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -27);
    }
  }

  _SFD_EML_CALL(1U, chartInstance->c11_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c11_sendBML
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_enable(chartInstance->S, 0, "sendBML", 0);
}

static void c11_b_sendBML
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  sf_call_output_fcn_disable(chartInstance->S, 0, "sendBML", 0);
}

void
  sf_exported_user_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_sendBML
  (SimStruct *c11_S, real_T c11_a[256])
{
  int32_T c11_i35;
  real_T c11_b_a[256];
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  for (c11_i35 = 0; c11_i35 < 256; c11_i35++) {
    c11_b_a[c11_i35] = c11_a[c11_i35];
  }

  c11_sendBMLc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImit(chartInstance,
    c11_b_a);
}

void
  sf_exported_user_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_smileTable
  (SimStruct *c11_S, real_T c11_bmlID, real_T c11_poseBML[256])
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)((ChartInfoStruct *)((ChartRunTimeInfo *)ssGetUserData(c11_S))
        ->instanceInfo)->chartInstance;
  c11_smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradI(chartInstance,
    c11_bmlID, c11_poseBML);
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int8_T c11_f_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int8_T c11_y;
  int8_T c11_i36;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i36, 1, 2, 0U, 0, 0U, 0);
  c11_y = c11_i36;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_secs;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int8_T c11_y;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_secs = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_secs),
    &c11_thisId);
  sf_mex_destroy(&c11_secs);
  *(int8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_g_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i37;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i37, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i37;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_h_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_b_tp_stateInitial, const char_T
   *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  return c11_y;
}

static uint8_T c11_i_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
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

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_stateInitial;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)chartInstanceVoid;
  c11_b_tp_stateInitial = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_stateInitial),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_stateInitial);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_j_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T
   *c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_k_emlrt_marshallIn
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
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

static void c11_updateDataWrittenToVector
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 1, 1, 0)] = true;
}

static real_T c11_get_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1565) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_GAZE_WIN_address;
}

static void c11_set_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c11_b);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1565) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_GAZE_WIN_address = c11_c;
}

static real_T *c11_access_GAZE_WIN
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c11_GAZE_WIN_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'GAZE_WIN\' (#1565) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_GAZE_WIN_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c11_c;
}

static real_T c11_get_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1563) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_avert_address;
}

static void c11_set_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c11_b);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1563) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_avert_address = c11_c;
}

static real_T *c11_access_avert
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c11_avert_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'avert\' (#1563) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_avert_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c11_c;
}

static real_T c11_get_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1564) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_gazing_address;
}

static void c11_set_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c11_b);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1564) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_gazing_address = c11_c;
}

static real_T *c11_access_gazing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c11_gazing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'gazing\' (#1564) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_gazing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c11_c;
}

static real_T c11_get_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1566) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c11_isPosing_address;
}

static void c11_set_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b, real_T c11_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c11_b);
  if (chartInstance->c11_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1566) in the initialization routine of the chart.\n");
  }

  *chartInstance->c11_isPosing_address = c11_c;
}

static real_T *c11_access_isPosing
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance, uint32_T c11_b)
{
  real_T *c11_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c11_isPosing_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'isPosing\' (#1566) in the initialization routine of the chart.\n");
  }

  c11_c = chartInstance->c11_isPosing_address;
  if (c11_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c11_c;
}

static void init_dsm_address_info
  (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
   *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "GAZE_WIN", (void **)
    &chartInstance->c11_GAZE_WIN_address, &chartInstance->c11_GAZE_WIN_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "avert", (void **)
    &chartInstance->c11_avert_address, &chartInstance->c11_avert_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "gazing", (void **)
    &chartInstance->c11_gazing_address, &chartInstance->c11_gazing_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "isPosing", (void **)
    &chartInstance->c11_isPosing_address, &chartInstance->c11_isPosing_index);
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

void
  sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_check_sum
  (mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2059311520U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(961303911U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3078108844U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3327425468U);
}

mxArray
  *sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("fQR6McJaf7aJFgTzB5I01G");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray
  *sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray
  *sf_get_sim_state_info_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[3],M[10],T\"smileN\",},{M[8],M[0],T\"is_active_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile\",},{M[9],M[0],T\"is_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_get_check_sum
    (&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
      *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance =
      (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
       *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
           11,
           6,
           9,
           0,
           9,
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
          (_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"smileN");
          _SFD_SET_DATA_PROPS(1,1,1,0,"isSmiling");
          _SFD_SET_DATA_PROPS(2,11,0,0,"avert");
          _SFD_SET_DATA_PROPS(3,11,0,0,"gazing");
          _SFD_SET_DATA_PROPS(4,11,0,0,"GAZE_WIN");
          _SFD_SET_DATA_PROPS(5,11,0,0,"isPosing");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,5);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

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
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,4,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,
                             "smileTablec11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile",
                             0,-1,400);
        _SFD_CV_INIT_EML_FCN(1,1,"aFcnTruthTableAction_1",400,-1,691);
        _SFD_CV_INIT_EML_FCN(1,2,"aFcnTruthTableAction_2",691,-1,875);
        _SFD_CV_INIT_EML_FCN(1,3,"aFcnTruthTableAction_3",875,-1,1170);
        _SFD_CV_INIT_EML_IF(1,1,0,224,254,285,398);
        _SFD_CV_INIT_EML_IF(1,1,1,285,319,350,398);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,436);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,39,1,39);

        {
          static int condStart[] = { 2, 24 };

          static int condEnd[] = { 20, 38 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,39,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,44,1,44);

        {
          static int condStart[] = { 1, 17, 30 };

          static int condEnd[] = { 15, 27, 43 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,44,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,30,1,30);

        {
          static int condStart[] = { 2, 19 };

          static int condEnd[] = { 16, 29 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,30,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,33,1,33);

        {
          static int condStart[] = { 2, 19 };

          static int condEnd[] = { 16, 32 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,33,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 256;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));

        {
          real_T *c11_isSmiling;
          c11_isSmiling = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c11_smileN);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_isSmiling);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c11_avert_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_gazing_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_GAZE_WIN_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c11_isPosing_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "E2GR3O1W4AP0NW0RhmU4eH";
}

static void
  sf_opaque_initialize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
  initialize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_enable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  enable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_disable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  disable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

static void
  sf_opaque_gateway_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  sf_gateway_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
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
    get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
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
  sf_internal_set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
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
    sf_get_sim_state_info_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct* S)
{
  return NULL;
}

static void
  sf_opaque_set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct* S, const mxArray *st)
{
}

static void
  sf_opaque_terminate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
       chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_optimization_info
        ();
    }

    finalize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
      ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
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
  initSimStructsc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
    ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
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
    initialize_params_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
      ((SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void
  mdlSetWorkWidths_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_optimization_info
      ();
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
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,11,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(506460996U));
  ssSetChecksum1(S,(2464733245U));
  ssSetChecksum2(S,(2127147208U));
  ssSetChecksum3(S,(2940059736U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void
  mdlStart_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
  (SimStruct *S)
{
  SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct *
    chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance =
    (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct
     *)utMalloc(sizeof
                (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile;
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

void
  c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
      (S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile
      (S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Copy_of_ARP_02_RPSsmile_KinectGloveAtomicBradImitateSmile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
