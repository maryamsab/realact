/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_AU_VA1_sfun.h"
#include "c50_Demo_AU_VA1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Demo_AU_VA1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c50_event_secs                 (0)
#define CALL_EVENT                     (-1)
#define c50_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c50_IN_initial                 ((uint8_T)1U)
#define c50_IN_stateFacialExpression   ((uint8_T)2U)
#define c50_IN_wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c50_debug_family_names[9] = { "p", "a", "all_AUs", "c",
  "nargin", "nargout", "arousal", "valence", "eAmountFactor" };

static const char * c50_b_debug_family_names[8] = { "full", "t", "i", "nargin",
  "nargout", "bmls", "myBML", "newBmls" };

static const char * c50_c_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "mystr", "nargin", "nargout", "myarr256" };

static const char * c50_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c50_e_debug_family_names[9] = { "maxarrsize", "arr", "ss",
  "padsize", "tt", "nargin", "nargout", "mystr", "myarr256" };

static const char * c50_f_debug_family_names[14] = { "L", "str1", "all_AUs", "c",
  "AU", "eA", "temp", "temp2", "str2", "mystr", "nargin", "nargout", "eAmount",
  "arrBML" };

static const char * c50_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c50_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c50_dataWrittenToVector[5];

/* Function Declarations */
static void initialize_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void initialize_params_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void enable_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void disable_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_update_debugger_state_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void set_sim_state_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_st);
static void c50_set_sim_state_side_effects_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void finalize_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void sf_gateway_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_enter_atomic_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_enter_internal_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_exit_internal_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_initc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void initSimStructsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_cmdBML_AU_VA(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_eAmount[11], real_T c50_arrBML[1000]);
static void c50_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_formatSpec, real_T c50_varargin_1);
static real_T c50_b_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1, real_T c50_varargin_2);
static real_T c50_abs(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
                      c50_x);
static real_T c50_log10(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_x);
static real_T c50_ceil(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_x);
static void c50_eml_scalar_eg(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_b_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_c_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_d_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_e_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_f_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_g_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_h_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_i_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_encStr2Arr(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  char_T c50_mystr_data[], int32_T c50_mystr_sizes[2], real_T c50_myarr256[1000]);
static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber);
static real_T c50_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_feval, const char_T *c50_identifier);
static real_T c50_b_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_c_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_d_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_e_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_eAmountFactor, const char_T *c50_identifier,
  real_T c50_y[11]);
static void c50_f_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[11]);
static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_g_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_newBmls, const char_T *c50_identifier,
  real_T c50_y[5000]);
static void c50_h_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[5000]);
static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_i_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_myBML, const char_T *c50_identifier, real_T
  c50_y[1000]);
static void c50_j_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[1000]);
static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_k_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[1000]);
static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2]);
static void c50_l_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2]);
static void c50_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2]);
static const mxArray *c50_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c50_inData_data[], int32_T *c50_inData_sizes);
static void c50_m_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y_data[], int32_T *c50_y_sizes);
static void c50_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, real_T c50_outData_data[],
  int32_T *c50_outData_sizes);
static const mxArray *c50_i_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_n_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[103]);
static void c50_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_j_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_o_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[206]);
static void c50_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_k_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_p_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[306]);
static void c50_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_l_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_q_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[412]);
static void c50_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_m_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_r_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[515]);
static void c50_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_n_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_s_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[656]);
static void c50_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_o_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_t_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[759]);
static void c50_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_p_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_u_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[862]);
static void c50_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_q_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_v_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[965]);
static void c50_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_r_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static const mxArray *c50_s_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static void c50_w_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[9]);
static void c50_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_t_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static boolean_T c50_x_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static void c50_info_helper(const mxArray **c50_info);
static const mxArray *c50_emlrt_marshallOut(const char * c50_u);
static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u);
static void c50_b_info_helper(const mxArray **c50_info);
static void c50_activate_secsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_deactivate_secsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance);
static void c50_increment_counters_secsc50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_reset_counters_secsc50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_set_AU_Amountc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor[11]);
static void c50_insertQueueLowc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_bmls[5000], real_T c50_myBML[1000], real_T
  c50_newBmls[5000]);
static void c50_c_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_formatSpec, real_T c50_varargin_1);
static void c50_isequal(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static real_T c50_d_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1, real_T c50_varargin_2);
static void c50_validate_arguments(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_varargin_1, real_T c50_varargin_2);
static void c50_eml_switch_helper(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static void c50_check_type(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);
static boolean_T c50_b_isequal(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1[1000], real_T c50_varargin_2[1000]);
static const mxArray *c50_u_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int8_T c50_y_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_v_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static int32_T c50_ab_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_w_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData);
static uint8_T c50_bb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_b_tp_subFacial, const char_T
  *c50_identifier);
static uint8_T c50_cb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData);
static const mxArray *c50_db_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T *
  c50_identifier);
static const mxArray *c50_eb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId);
static void c50_updateDataWrittenToVector(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c50_vectorIndex);
static void c50_errorIfDataNotWrittenToFcn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c50_vectorIndex, uint32_T c50_dataNumber);
static void c50_b_log10(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  *c50_x);
static void c50_b_ceil(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  *c50_x);
static real_T c50_get_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b);
static void c50_set_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b, real_T c50_c);
static real_T *c50_access_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b);
static void init_dsm_address_info(SFc50_Demo_AU_VA1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initialize_params_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void disable_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_update_debugger_state_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c50_prevAniVal;
  c50_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c50_is_active_c50_Demo_AU_VA1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 12U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_active_subFacial == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_stateFacialExpression) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_initial) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
  }

  if (chartInstance->c50_is_subFacial == c50_IN_wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
  }

  _SFD_SET_ANIMATION(c50_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  const mxArray *c50_st;
  const mxArray *c50_y = NULL;
  int32_T c50_i0;
  real_T c50_u[11];
  const mxArray *c50_b_y = NULL;
  int32_T c50_i1;
  real_T c50_b_u[1000];
  const mxArray *c50_c_y = NULL;
  int32_T c50_i2;
  real_T c50_c_u[5000];
  const mxArray *c50_d_y = NULL;
  uint8_T c50_hoistedGlobal;
  uint8_T c50_d_u;
  const mxArray *c50_e_y = NULL;
  uint8_T c50_b_hoistedGlobal;
  uint8_T c50_e_u;
  const mxArray *c50_f_y = NULL;
  uint8_T c50_c_hoistedGlobal;
  uint8_T c50_f_u;
  const mxArray *c50_g_y = NULL;
  uint8_T c50_d_hoistedGlobal;
  uint8_T c50_g_u;
  const mxArray *c50_h_y = NULL;
  real_T (*c50_emotion_amount_factor)[11];
  c50_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_st = NULL;
  c50_st = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_createcellmatrix(7, 1), false);
  for (c50_i0 = 0; c50_i0 < 11; c50_i0++) {
    c50_u[c50_i0] = (*c50_emotion_amount_factor)[c50_i0];
  }

  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_setcell(c50_y, 0, c50_b_y);
  for (c50_i1 = 0; c50_i1 < 1000; c50_i1++) {
    c50_b_u[c50_i1] = chartInstance->c50_BMLl[c50_i1];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_b_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_setcell(c50_y, 1, c50_c_y);
  for (c50_i2 = 0; c50_i2 < 5000; c50_i2++) {
    c50_c_u[c50_i2] = chartInstance->c50_newBmlsL[c50_i2];
  }

  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", c50_c_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_setcell(c50_y, 2, c50_d_y);
  c50_hoistedGlobal = chartInstance->c50_is_active_c50_Demo_AU_VA1;
  c50_d_u = c50_hoistedGlobal;
  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", &c50_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 3, c50_e_y);
  c50_b_hoistedGlobal = chartInstance->c50_is_active_subFacial;
  c50_e_u = c50_b_hoistedGlobal;
  c50_f_y = NULL;
  sf_mex_assign(&c50_f_y, sf_mex_create("y", &c50_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 4, c50_f_y);
  c50_c_hoistedGlobal = chartInstance->c50_is_subFacial;
  c50_f_u = c50_c_hoistedGlobal;
  c50_g_y = NULL;
  sf_mex_assign(&c50_g_y, sf_mex_create("y", &c50_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 5, c50_g_y);
  c50_d_hoistedGlobal = chartInstance->c50_temporalCounter_i1;
  c50_g_u = c50_d_hoistedGlobal;
  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", &c50_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c50_y, 6, c50_h_y);
  sf_mex_assign(&c50_st, c50_y, false);
  return c50_st;
}

static void set_sim_state_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_st)
{
  const mxArray *c50_u;
  real_T c50_dv0[11];
  int32_T c50_i3;
  real_T c50_dv1[1000];
  int32_T c50_i4;
  real_T c50_dv2[5000];
  int32_T c50_i5;
  real_T (*c50_emotion_amount_factor)[11];
  c50_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_u = sf_mex_dup(c50_st);
  c50_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 0)),
    "emotion_amount_factor", c50_dv0);
  for (c50_i3 = 0; c50_i3 < 11; c50_i3++) {
    (*c50_emotion_amount_factor)[c50_i3] = c50_dv0[c50_i3];
  }

  c50_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 1)),
    "BMLl", c50_dv1);
  for (c50_i4 = 0; c50_i4 < 1000; c50_i4++) {
    chartInstance->c50_BMLl[c50_i4] = c50_dv1[c50_i4];
  }

  c50_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 2)),
    "newBmlsL", c50_dv2);
  for (c50_i5 = 0; c50_i5 < 5000; c50_i5++) {
    chartInstance->c50_newBmlsL[c50_i5] = c50_dv2[c50_i5];
  }

  chartInstance->c50_is_active_c50_Demo_AU_VA1 = c50_bb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c50_u, 3)),
     "is_active_c50_Demo_AU_VA1");
  chartInstance->c50_is_active_subFacial = c50_bb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 4)), "is_active_subFacial");
  chartInstance->c50_is_subFacial = c50_bb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 5)), "is_subFacial");
  chartInstance->c50_temporalCounter_i1 = c50_bb_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c50_u, 6)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c50_setSimStateSideEffectsInfo,
                c50_db_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
                  (c50_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c50_u);
  chartInstance->c50_doSetSimStateSideEffects = 1U;
  c50_update_debugger_state_c50_Demo_AU_VA1(chartInstance);
  sf_mex_destroy(&c50_st);
}

static void c50_set_sim_state_side_effects_c50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  if (chartInstance->c50_doSetSimStateSideEffects != 0) {
    if (chartInstance->c50_is_active_subFacial == 1U) {
      chartInstance->c50_tp_subFacial = 1U;
    } else {
      chartInstance->c50_tp_subFacial = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_initial) {
      chartInstance->c50_tp_initial = 1U;
    } else {
      chartInstance->c50_tp_initial = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_stateFacialExpression) {
      chartInstance->c50_tp_stateFacialExpression = 1U;
    } else {
      chartInstance->c50_tp_stateFacialExpression = 0U;
    }

    if (chartInstance->c50_is_subFacial == c50_IN_wait) {
      chartInstance->c50_tp_wait = 1U;
      if (sf_mex_sub(chartInstance->c50_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c50_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c50_tp_wait = 0U;
    }

    chartInstance->c50_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c50_setSimStateSideEffectsInfo);
}

static void sf_gateway_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  c50_set_sim_state_side_effects_c50_Demo_AU_VA1(chartInstance);
}

static void c50_enter_atomic_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
  chartInstance->c50_is_active_c50_Demo_AU_VA1 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
}

static void c50_enter_internal_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_active_subFacial = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_subFacial = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c50_sfEvent);
  chartInstance->c50_isStable = false;
  chartInstance->c50_is_subFacial = c50_IN_initial;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
  chartInstance->c50_tp_initial = 1U;
}

static void c50_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  uint32_T c50_debug_family_var_map[2];
  real_T c50_nargin = 0.0;
  real_T c50_nargout = 0.0;
  real_T c50_dv3[11];
  int32_T c50_i6;
  int32_T c50_i7;
  int32_T c50_i8;
  real_T c50_dv4[11];
  real_T c50_dv5[1000];
  int32_T c50_i9;
  int32_T c50_i10;
  int32_T c50_i11;
  static real_T c50_dv6[5000];
  int32_T c50_i12;
  real_T c50_dv7[1000];
  real_T c50_dv8[5000];
  int32_T c50_i13;
  int32_T c50_i14;
  int32_T c50_i15;
  uint32_T c50_b_debug_family_var_map[3];
  real_T c50_b_nargin = 0.0;
  real_T c50_b_nargout = 1.0;
  boolean_T c50_out;
  real_T c50_c_nargin = 0.0;
  real_T c50_c_nargout = 0.0;
  real_T c50_dv9[11];
  int32_T c50_i16;
  int32_T c50_i17;
  int32_T c50_i18;
  real_T c50_dv10[11];
  int32_T c50_i19;
  int32_T c50_i20;
  int32_T c50_i21;
  real_T c50_dv11[5000];
  int32_T c50_i22;
  real_T c50_dv12[1000];
  real_T c50_dv13[5000];
  int32_T c50_i23;
  int32_T c50_i24;
  int32_T c50_i25;
  real_T *c50_inA;
  real_T *c50_inV;
  real_T (*c50_emotion_amount_factor)[11];
  c50_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c50_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_isStable = true;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
  switch (chartInstance->c50_is_subFacial) {
   case c50_IN_initial:
    CV_STATE_EVAL(2, 0, 1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_initial = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
    chartInstance->c50_isStable = false;
    chartInstance->c50_is_subFacial = c50_IN_stateFacialExpression;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_stateFacialExpression = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_d_debug_family_names,
      c50_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 1U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    c50_set_AU_Amountc50_Demo_AU_VA1(chartInstance, *c50_inA, *c50_inV, c50_dv3);
    for (c50_i6 = 0; c50_i6 < 11; c50_i6++) {
      (*c50_emotion_amount_factor)[c50_i6] = c50_dv3[c50_i6];
    }

    c50_updateDataWrittenToVector(chartInstance, 2U);
    for (c50_i7 = 0; c50_i7 < 11; c50_i7++) {
      _SFD_DATA_RANGE_CHECK((*c50_emotion_amount_factor)[c50_i7], 5U);
    }

    c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U);
    for (c50_i8 = 0; c50_i8 < 11; c50_i8++) {
      c50_dv4[c50_i8] = (*c50_emotion_amount_factor)[c50_i8];
    }

    c50_cmdBML_AU_VA(chartInstance, c50_dv4, c50_dv5);
    for (c50_i9 = 0; c50_i9 < 1000; c50_i9++) {
      chartInstance->c50_BMLl[c50_i9] = c50_dv5[c50_i9];
    }

    c50_updateDataWrittenToVector(chartInstance, 0U);
    for (c50_i10 = 0; c50_i10 < 1000; c50_i10++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c50_BMLl[c50_i10], 1U);
    }

    c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
    for (c50_i11 = 0; c50_i11 < 5000; c50_i11++) {
      c50_dv6[c50_i11] = c50_get_bmlsL(chartInstance, c50_i11);
    }

    for (c50_i12 = 0; c50_i12 < 1000; c50_i12++) {
      c50_dv7[c50_i12] = chartInstance->c50_BMLl[c50_i12];
    }

    c50_insertQueueLowc50_Demo_AU_VA1(chartInstance, c50_dv6, c50_dv7, c50_dv8);
    for (c50_i13 = 0; c50_i13 < 5000; c50_i13++) {
      chartInstance->c50_newBmlsL[c50_i13] = c50_dv8[c50_i13];
    }

    c50_updateDataWrittenToVector(chartInstance, 1U);
    for (c50_i14 = 0; c50_i14 < 5000; c50_i14++) {
      _SFD_DATA_RANGE_CHECK(chartInstance->c50_newBmlsL[c50_i14], 2U);
    }

    c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
    for (c50_i15 = 0; c50_i15 < 5000; c50_i15++) {
      c50_set_bmlsL(chartInstance, c50_i15, chartInstance->c50_newBmlsL[c50_i15]);
    }

    ssUpdateDataStoreLog(chartInstance->S, 0);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(2, 0, 2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
    chartInstance->c50_tp_stateFacialExpression = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
    chartInstance->c50_isStable = false;
    chartInstance->c50_is_subFacial = c50_IN_wait;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
    chartInstance->c50_temporalCounter_i1 = 0U;
    chartInstance->c50_tp_wait = 1U;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait:
    CV_STATE_EVAL(2, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c50_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c50_g_debug_family_names,
      c50_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargin, 0U, c50_b_sf_marshallOut,
      c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_b_nargout, 1U,
      c50_b_sf_marshallOut, c50_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_out, 2U, c50_t_sf_marshallOut,
      c50_r_sf_marshallIn);
    c50_out = CV_EML_IF(3, 0, 0, (chartInstance->c50_sfEvent == c50_event_secs) &&
                        (chartInstance->c50_temporalCounter_i1 >= 7));
    _SFD_SYMBOL_SCOPE_POP();
    if (c50_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
      chartInstance->c50_isStable = false;
      chartInstance->c50_is_subFacial = c50_IN_stateFacialExpression;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
      chartInstance->c50_tp_stateFacialExpression = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c50_d_debug_family_names,
        c50_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c_nargin, 0U,
        c50_b_sf_marshallOut, c50_b_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c_nargout, 1U,
        c50_b_sf_marshallOut, c50_b_sf_marshallIn);
      c50_set_AU_Amountc50_Demo_AU_VA1(chartInstance, *c50_inA, *c50_inV,
        c50_dv9);
      for (c50_i16 = 0; c50_i16 < 11; c50_i16++) {
        (*c50_emotion_amount_factor)[c50_i16] = c50_dv9[c50_i16];
      }

      c50_updateDataWrittenToVector(chartInstance, 2U);
      for (c50_i17 = 0; c50_i17 < 11; c50_i17++) {
        _SFD_DATA_RANGE_CHECK((*c50_emotion_amount_factor)[c50_i17], 5U);
      }

      c50_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U);
      for (c50_i18 = 0; c50_i18 < 11; c50_i18++) {
        c50_dv10[c50_i18] = (*c50_emotion_amount_factor)[c50_i18];
      }

      c50_cmdBML_AU_VA(chartInstance, c50_dv10, c50_dv5);
      for (c50_i19 = 0; c50_i19 < 1000; c50_i19++) {
        chartInstance->c50_BMLl[c50_i19] = c50_dv5[c50_i19];
      }

      c50_updateDataWrittenToVector(chartInstance, 0U);
      for (c50_i20 = 0; c50_i20 < 1000; c50_i20++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c50_BMLl[c50_i20], 1U);
      }

      c50_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
      for (c50_i21 = 0; c50_i21 < 5000; c50_i21++) {
        c50_dv11[c50_i21] = c50_get_bmlsL(chartInstance, c50_i21);
      }

      for (c50_i22 = 0; c50_i22 < 1000; c50_i22++) {
        c50_dv12[c50_i22] = chartInstance->c50_BMLl[c50_i22];
      }

      c50_insertQueueLowc50_Demo_AU_VA1(chartInstance, c50_dv11, c50_dv12,
        c50_dv13);
      for (c50_i23 = 0; c50_i23 < 5000; c50_i23++) {
        chartInstance->c50_newBmlsL[c50_i23] = c50_dv13[c50_i23];
      }

      c50_updateDataWrittenToVector(chartInstance, 1U);
      for (c50_i24 = 0; c50_i24 < 5000; c50_i24++) {
        _SFD_DATA_RANGE_CHECK(chartInstance->c50_newBmlsL[c50_i24], 2U);
      }

      c50_errorIfDataNotWrittenToFcn(chartInstance, 1U, 2U);
      for (c50_i25 = 0; c50_i25 < 5000; c50_i25++) {
        c50_set_bmlsL(chartInstance, c50_i25, chartInstance->
                      c50_newBmlsL[c50_i25]);
      }

      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c50_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 0, 0);
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c50_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c50_sfEvent);
}

static void c50_exit_internal_c50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c50_is_subFacial) {
   case c50_IN_initial:
    CV_STATE_EVAL(2, 1, 1);
    chartInstance->c50_tp_initial = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_stateFacialExpression:
    CV_STATE_EVAL(2, 1, 2);
    chartInstance->c50_tp_stateFacialExpression = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c50_sfEvent);
    break;

   case c50_IN_wait:
    CV_STATE_EVAL(2, 1, 3);
    chartInstance->c50_tp_wait = 0U;
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c50_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 1, 0);
    chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c50_sfEvent);
    break;
  }

  chartInstance->c50_tp_subFacial = 0U;
  chartInstance->c50_is_active_subFacial = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c50_sfEvent);
}

static void c50_initc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c50_doSetSimStateSideEffects = 0U;
  chartInstance->c50_setSimStateSideEffectsInfo = NULL;
  chartInstance->c50_is_active_subFacial = 0U;
  chartInstance->c50_is_subFacial = c50_IN_NO_ACTIVE_CHILD;
  chartInstance->c50_tp_subFacial = 0U;
  chartInstance->c50_tp_initial = 0U;
  chartInstance->c50_tp_stateFacialExpression = 0U;
  chartInstance->c50_tp_wait = 0U;
  chartInstance->c50_temporalCounter_i1 = 0U;
  chartInstance->c50_is_active_c50_Demo_AU_VA1 = 0U;
}

static void initSimStructsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c50_cmdBML_AU_VA(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_eAmount[11], real_T c50_arrBML[1000])
{
  uint32_T c50_debug_family_var_map[14];
  real_T c50_L;
  const mxArray *c50_str1 = NULL;
  real_T c50_all_AUs[9];
  real_T c50_c;
  real_T c50_AU;
  real_T c50_eA;
  const mxArray *c50_temp = NULL;
  const mxArray *c50_temp2 = NULL;
  const mxArray *c50_str2 = NULL;
  char_T c50_mystr[965];
  char_T c50_b_mystr[862];
  char_T c50_c_mystr[759];
  char_T c50_d_mystr[656];
  char_T c50_e_mystr[515];
  char_T c50_f_mystr[412];
  char_T c50_g_mystr[306];
  char_T c50_h_mystr[206];
  char_T c50_i_mystr[103];
  int32_T c50_mystr_sizes[2];
  char_T c50_mystr_data[965];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i26;
  static char_T c50_cv0[34] = { '<', '?', 'x', 'm', 'l', ' ', 'v', 'e', 'r', 's',
    'i', 'o', 'n', '=', '\\', '\"', '1', '.', '0', '\\', '\"', ' ', '?', '>',
    '<', 'a', 'c', 't', '>', '<', 'b', 'm', 'l', '>' };

  char_T c50_u[34];
  const mxArray *c50_y = NULL;
  int32_T c50_i27;
  static real_T c50_dv14[9] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0 };

  int32_T c50_b_c;
  real_T c50_d0;
  real_T c50_varargin_1;
  real_T c50_varargin_2;
  real_T c50_x;
  real_T c50_b_x;
  real_T c50_xk;
  real_T c50_c_x;
  real_T c50_maxval;
  int32_T c50_i28;
  static char_T c50_cv1[124] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '1', 'd', '\\', '\"', ' ', ' ', 's', 't', 'a', 'r', 't',
    '=', '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\',
    '\"', '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"',
    '4', '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6',
    '\\', '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a',
    'm', 'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\',
    '\"', '/', '>' };

  char_T c50_b_u[124];
  const mxArray *c50_b_y = NULL;
  real_T c50_c_u;
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  int32_T c50_i29;
  static char_T c50_cv2[123] = { '<', 'f', 'a', 'c', 'e', ' ', 't', 'y', 'p',
    'e', '=', '\\', '\"', 'F', 'A', 'C', 'S', '\\', '\"', ' ', 's', 'i', 'd',
    'e', '=', '\\', '\"', 'B', 'O', 'T', 'H', '\\', '\"', ' ', 'a', 'u', '=',
    '\\', '\"', '%', '2', 'd', '\\', '\"', ' ', 's', 't', 'a', 'r', 't', '=',
    '\\', '\"', '0', '\\', '\"', ' ', 'r', 'e', 'a', 'd', 'y', '=', '\\', '\"',
    '2', '\\', '\"', ' ', 's', 't', 'r', 'o', 'k', 'e', '=', '\\', '\"', '4',
    '\\', '\"', ' ', ' ', 'r', 'e', 'l', 'a', 'x', '=', '\\', '\"', '6', '\\',
    '\"', ' ', 'e', 'n', 'd', '=', '\\', '\"', '8', '\\', '\"', ' ', 'a', 'm',
    'o', 'u', 'n', 't', '=', '\\', '\"', '%', '0', '.', '1', 'f', '\\', '\"',
    '/', '>' };

  char_T c50_e_u[123];
  const mxArray *c50_e_y = NULL;
  real_T c50_f_u;
  const mxArray *c50_f_y = NULL;
  real_T c50_g_u;
  const mxArray *c50_g_y = NULL;
  int32_T c50_i30;
  static char_T c50_cv3[12] = { '<', '/', 'b', 'm', 'l', '>', '<', '/', 'a', 'c',
    't', '>' };

  char_T c50_h_u[12];
  const mxArray *c50_h_y = NULL;
  int32_T c50_i31;
  int32_T c50_i32;
  int32_T c50_i33;
  int32_T c50_i34;
  int32_T c50_i35;
  int32_T c50_i36;
  int32_T c50_i37;
  int32_T c50_i38;
  int32_T c50_i39;
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[965];
  int32_T c50_j_mystr;
  int32_T c50_k_mystr;
  int32_T c50_loop_ub;
  int32_T c50_i40;
  int32_T c50_b_mystr_sizes[2];
  int32_T c50_l_mystr;
  int32_T c50_m_mystr;
  int32_T c50_b_loop_ub;
  int32_T c50_i41;
  char_T c50_b_mystr_data[965];
  real_T c50_dv15[1000];
  int32_T c50_i42;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 23U, c50_f_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_L, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str1, 1U, c50_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_all_AUs, 2U, c50_s_sf_marshallOut,
    c50_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_AU, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_eA, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp, 6U, c50_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_temp2, 7U, c50_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c50_str2, 8U, c50_r_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_mystr, MAX_uint32_T,
    c50_q_sf_marshallOut, c50_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_b_mystr, MAX_uint32_T,
    c50_p_sf_marshallOut, c50_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_c_mystr, MAX_uint32_T,
    c50_o_sf_marshallOut, c50_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_d_mystr, MAX_uint32_T,
    c50_n_sf_marshallOut, c50_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_e_mystr, MAX_uint32_T,
    c50_m_sf_marshallOut, c50_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_f_mystr, MAX_uint32_T,
    c50_l_sf_marshallOut, c50_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_g_mystr, MAX_uint32_T,
    c50_k_sf_marshallOut, c50_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_h_mystr, MAX_uint32_T,
    c50_j_sf_marshallOut, c50_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_i_mystr, MAX_uint32_T,
    c50_i_sf_marshallOut, c50_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    &c50_mystr_sizes, NULL, 0, -1, (void *)c50_g_sf_marshallOut, (void *)
    c50_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 10U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 11U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmount, 12U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_arrBML, 13U, c50_e_sf_marshallOut,
    c50_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 4);
  c50_L = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 6);
  for (c50_i26 = 0; c50_i26 < 34; c50_i26++) {
    c50_u[c50_i26] = c50_cv0[c50_i26];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  sf_mex_assign(&c50_str1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 7);
  for (c50_i27 = 0; c50_i27 < 9; c50_i27++) {
    c50_all_AUs[c50_i27] = c50_dv14[c50_i27];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 8);
  c50_c = 1.0;
  c50_b_c = 0;
  while (c50_b_c < 9) {
    c50_c = 1.0 + (real_T)c50_b_c;
    CV_SCRIPT_FOR(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 9);
    c50_AU = c50_all_AUs[(int32_T)c50_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 9);
    c50_eA = c50_eAmount[(int32_T)c50_c - 1];
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 10);
    if (CV_SCRIPT_IF(1, 0, c50_eA >= 0.1)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 11);
      c50_L++;
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 12);
      c50_fprintf(chartInstance, c50_AU, c50_eA);
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 13);
      c50_d0 = c50_abs(chartInstance, c50_AU);
      c50_b_log10(chartInstance, &c50_d0);
      c50_varargin_1 = c50_d0;
      c50_b_ceil(chartInstance, &c50_varargin_1);
      c50_varargin_2 = c50_varargin_1;
      c50_x = c50_varargin_2;
      c50_b_x = c50_x;
      c50_eml_scalar_eg(chartInstance);
      c50_xk = c50_b_x;
      c50_c_x = c50_xk;
      c50_eml_scalar_eg(chartInstance);
      c50_maxval = muDoubleScalarMax(c50_c_x, 1.0);
      if (CV_SCRIPT_IF(1, 1, c50_maxval == 1.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 14);
        for (c50_i28 = 0; c50_i28 < 124; c50_i28++) {
          c50_b_u[c50_i28] = c50_cv1[c50_i28];
        }

        c50_b_y = NULL;
        sf_mex_assign(&c50_b_y, sf_mex_create("y", c50_b_u, 10, 0U, 1U, 0U, 2, 1,
          124), false);
        c50_c_u = c50_AU;
        c50_c_y = NULL;
        sf_mex_assign(&c50_c_y, sf_mex_create("y", &c50_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        c50_d_u = c50_eA;
        c50_d_y = NULL;
        sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c50_b_y, 14, c50_c_y, 14, c50_d_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 15);
        sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 16);
        sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 18);
        for (c50_i29 = 0; c50_i29 < 123; c50_i29++) {
          c50_e_u[c50_i29] = c50_cv2[c50_i29];
        }

        c50_e_y = NULL;
        sf_mex_assign(&c50_e_y, sf_mex_create("y", c50_e_u, 10, 0U, 1U, 0U, 2, 1,
          123), false);
        c50_f_u = c50_AU;
        c50_f_y = NULL;
        sf_mex_assign(&c50_f_y, sf_mex_create("y", &c50_f_u, 0, 0U, 0U, 0U, 0),
                      false);
        c50_g_u = c50_eA;
        c50_g_y = NULL;
        sf_mex_assign(&c50_g_y, sf_mex_create("y", &c50_g_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_assign(&c50_temp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "sprintf", 1U, 3U, 14, c50_e_y, 14, c50_f_y, 14, c50_g_y), false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 19);
        sf_mex_assign(&c50_temp2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14, sf_mex_dup(c50_temp)),
                      false);
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 20);
        sf_mex_assign(&c50_str1, sf_mex_dup(c50_temp2), false);
      }
    }

    c50_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(1, 0, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 24);
  for (c50_i30 = 0; c50_i30 < 12; c50_i30++) {
    c50_h_u[c50_i30] = c50_cv3[c50_i30];
  }

  c50_h_y = NULL;
  sf_mex_assign(&c50_h_y, sf_mex_create("y", c50_h_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_assign(&c50_str2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "sprintf", 1U, 1U, 14, c50_h_y), false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 26);
  if (CV_SCRIPT_IF(1, 2, c50_L == 1.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 27);
    c50_blanks(chartInstance);
    for (c50_i31 = 0; c50_i31 < 103; c50_i31++) {
      c50_i_mystr[c50_i31] = ' ';
    }

    _SFD_SYMBOL_SWITCH(9U, 17U);
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 28);
    if (CV_SCRIPT_IF(1, 3, c50_L == 2.0)) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 29);
      c50_b_blanks(chartInstance);
      for (c50_i32 = 0; c50_i32 < 206; c50_i32++) {
        c50_h_mystr[c50_i32] = ' ';
      }

      _SFD_SYMBOL_SWITCH(9U, 16U);
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 30);
      if (CV_SCRIPT_IF(1, 4, c50_L == 3.0)) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 31);
        c50_c_blanks(chartInstance);
        for (c50_i33 = 0; c50_i33 < 306; c50_i33++) {
          c50_g_mystr[c50_i33] = ' ';
        }

        _SFD_SYMBOL_SWITCH(9U, 15U);
      } else {
        _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 32);
        if (CV_SCRIPT_IF(1, 5, c50_L == 4.0)) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 33);
          c50_d_blanks(chartInstance);
          for (c50_i34 = 0; c50_i34 < 412; c50_i34++) {
            c50_f_mystr[c50_i34] = ' ';
          }

          _SFD_SYMBOL_SWITCH(9U, 14U);
        } else {
          _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 34);
          if (CV_SCRIPT_IF(1, 6, c50_L == 5.0)) {
            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 35);
            c50_e_blanks(chartInstance);
            for (c50_i35 = 0; c50_i35 < 515; c50_i35++) {
              c50_e_mystr[c50_i35] = ' ';
            }

            _SFD_SYMBOL_SWITCH(9U, 13U);
          } else {
            _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 36);
            if (CV_SCRIPT_IF(1, 7, c50_L == 6.0)) {
              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 37);
              c50_f_blanks(chartInstance);
              for (c50_i36 = 0; c50_i36 < 656; c50_i36++) {
                c50_d_mystr[c50_i36] = ' ';
              }

              _SFD_SYMBOL_SWITCH(9U, 12U);
            } else {
              _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 38);
              if (CV_SCRIPT_IF(1, 8, c50_L == 7.0)) {
                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 39);
                c50_g_blanks(chartInstance);
                for (c50_i37 = 0; c50_i37 < 759; c50_i37++) {
                  c50_c_mystr[c50_i37] = ' ';
                }

                _SFD_SYMBOL_SWITCH(9U, 11U);
              } else {
                _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 40);
                if (CV_SCRIPT_IF(1, 9, c50_L == 8.0)) {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 41);
                  c50_h_blanks(chartInstance);
                  for (c50_i38 = 0; c50_i38 < 862; c50_i38++) {
                    c50_b_mystr[c50_i38] = ' ';
                  }

                  _SFD_SYMBOL_SWITCH(9U, 10U);
                } else {
                  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 42);
                  if (CV_SCRIPT_IF(1, 10, c50_L == 9.0)) {
                    _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 43);
                    c50_i_blanks(chartInstance);
                    for (c50_i39 = 0; c50_i39 < 965; c50_i39++) {
                      c50_mystr[c50_i39] = ' ';
                    }

                    _SFD_SYMBOL_SWITCH(9U, 9U);
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 45);
  c50_c_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "strcat", 1U, 2U, 14, sf_mex_dup(c50_str1), 14,
     sf_mex_dup(c50_str2)), "strcat", c50_tmp_data, c50_tmp_sizes);
  c50_mystr_sizes[0] = 1;
  c50_mystr_sizes[1] = c50_tmp_sizes[1];
  c50_j_mystr = c50_mystr_sizes[0];
  c50_k_mystr = c50_mystr_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i40 = 0; c50_i40 <= c50_loop_ub; c50_i40++) {
    c50_mystr_data[c50_i40] = c50_tmp_data[c50_i40];
  }

  _SFD_SYMBOL_SWITCH(9U, 18U);
  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, 46);
  c50_b_mystr_sizes[0] = 1;
  c50_b_mystr_sizes[1] = c50_mystr_sizes[1];
  c50_l_mystr = c50_b_mystr_sizes[0];
  c50_m_mystr = c50_b_mystr_sizes[1];
  c50_b_loop_ub = c50_mystr_sizes[0] * c50_mystr_sizes[1] - 1;
  for (c50_i41 = 0; c50_i41 <= c50_b_loop_ub; c50_i41++) {
    c50_b_mystr_data[c50_i41] = c50_mystr_data[c50_i41];
  }

  c50_encStr2Arr(chartInstance, c50_b_mystr_data, c50_b_mystr_sizes, c50_dv15);
  for (c50_i42 = 0; c50_i42 < 1000; c50_i42++) {
    c50_arrBML[c50_i42] = c50_dv15[c50_i42];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c50_sfEvent, -46);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c50_str1);
  sf_mex_destroy(&c50_temp);
  sf_mex_destroy(&c50_temp2);
  sf_mex_destroy(&c50_str2);
}

static void c50_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_formatSpec, real_T c50_varargin_1)
{
  c50_isequal(chartInstance);
  c50_b_fprintf(chartInstance, c50_formatSpec, c50_varargin_1);
}

static real_T c50_b_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1, real_T c50_varargin_2)
{
  real_T c50_nbytes;
  int32_T c50_i43;
  static char_T c50_cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c50_u[7];
  const mxArray *c50_y = NULL;
  real_T c50_b_u;
  const mxArray *c50_b_y = NULL;
  int32_T c50_i44;
  static char_T c50_formatSpec[22] = { 'A', 'U', ',', 'e', 'A', ':', ' ', '%',
    '0', '.', '0', 'f', ',', '%', '0', '.', '1', 'f', '\\', 'r', '\\', 'n' };

  char_T c50_c_u[22];
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  real_T c50_e_u;
  const mxArray *c50_e_y = NULL;
  const mxArray *c50_cfmt = NULL;
  const mxArray *c50_convs = NULL;
  c50_isequal(chartInstance);
  c50_validate_arguments(chartInstance, c50_varargin_1, c50_varargin_2);
  for (c50_i43 = 0; c50_i43 < 7; c50_i43++) {
    c50_u[c50_i43] = c50_cv4[c50_i43];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c50_b_u = 1.0;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c50_i44 = 0; c50_i44 < 22; c50_i44++) {
    c50_c_u[c50_i44] = c50_formatSpec[c50_i44];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1, 22),
                false);
  c50_d_u = c50_varargin_1;
  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0), false);
  c50_e_u = c50_varargin_2;
  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", &c50_e_u, 0, 0U, 0U, 0U, 0), false);
  c50_nbytes = c50_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 5U, 14, c50_y, 14, c50_b_y, 14,
     c50_c_y, 14, c50_d_y, 14, c50_e_y), "feval");
  sf_mex_destroy(&c50_cfmt);
  sf_mex_destroy(&c50_convs);
  return c50_nbytes;
}

static real_T c50_abs(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
                      c50_x)
{
  real_T c50_b_x;
  (void)chartInstance;
  c50_b_x = c50_x;
  return c50_b_x;
}

static real_T c50_log10(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_log10(chartInstance, &c50_b_x);
  return c50_b_x;
}

static real_T c50_ceil(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_x)
{
  real_T c50_b_x;
  c50_b_x = c50_x;
  c50_b_ceil(chartInstance, &c50_b_x);
  return c50_b_x;
}

static void c50_eml_scalar_eg(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_b_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_c_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_d_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_e_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_f_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_g_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_h_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_i_blanks(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_encStr2Arr(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  char_T c50_mystr_data[], int32_T c50_mystr_sizes[2], real_T c50_myarr256[1000])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_maxarrsize;
  int32_T c50_arr_sizes;
  real_T c50_arr_data[965];
  real_T c50_ss;
  real_T c50_padsize;
  real_T c50_tt[1000];
  real_T c50_nargin = 1.0;
  real_T c50_nargout = 1.0;
  int32_T c50_loop_ub;
  int32_T c50_i45;
  int32_T c50_i46;
  boolean_T c50_b0;
  boolean_T c50_b1;
  boolean_T c50_b2;
  int32_T c50_i47;
  int32_T c50_tmp_sizes;
  int32_T c50_b_loop_ub;
  int32_T c50_i48;
  int32_T c50_tmp_data[965];
  int32_T c50_iv0[1];
  int32_T c50_c_loop_ub;
  int32_T c50_i49;
  int32_T c50_i50;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_e_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_maxarrsize, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_arr_data, (const int32_T *)
    &c50_arr_sizes, NULL, 0, 1, (void *)c50_h_sf_marshallOut, (void *)
    c50_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_ss, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_padsize, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_tt, 4U, c50_e_sf_marshallOut,
    c50_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c50_mystr_data, (const int32_T *)
    c50_mystr_sizes, NULL, 1, 7, (void *)c50_g_sf_marshallOut, (void *)
    c50_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myarr256, 8U, c50_e_sf_marshallOut,
    c50_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 4);
  c50_maxarrsize = 1000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 6);
  c50_arr_sizes = c50_mystr_sizes[1];
  c50_loop_ub = c50_mystr_sizes[1] - 1;
  for (c50_i45 = 0; c50_i45 <= c50_loop_ub; c50_i45++) {
    c50_arr_data[c50_i45] = (real_T)c50_mystr_data[c50_mystr_sizes[0] * c50_i45];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 7);
  c50_ss = (real_T)c50_arr_sizes;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 8);
  c50_padsize = 1000.0 - c50_ss;
  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 9);
  for (c50_i46 = 0; c50_i46 < 1000; c50_i46++) {
    c50_tt[c50_i46] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 10);
  c50_b0 = (1.0 > c50_ss);
  c50_b1 = c50_b0;
  c50_b2 = c50_b1;
  if (c50_b2) {
    c50_i47 = 0;
  } else {
    c50_i47 = _SFD_EML_ARRAY_BOUNDS_CHECK("tt", (int32_T)c50_ss, 1, 1000, 0, 0);
  }

  c50_tmp_sizes = c50_i47;
  c50_b_loop_ub = c50_i47 - 1;
  for (c50_i48 = 0; c50_i48 <= c50_b_loop_ub; c50_i48++) {
    c50_tmp_data[c50_i48] = c50_i48;
  }

  c50_iv0[0] = c50_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c50_iv0, 1, *(int32_T (*)[1])&c50_arr_sizes, 1);
  c50_c_loop_ub = c50_arr_sizes - 1;
  for (c50_i49 = 0; c50_i49 <= c50_c_loop_ub; c50_i49++) {
    c50_tt[c50_tmp_data[c50_i49]] = c50_arr_data[c50_i49];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, 11);
  for (c50_i50 = 0; c50_i50 < 1000; c50_i50++) {
    c50_myarr256[c50_i50] = c50_tt[c50_i50];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c50_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c50_machineNumber, uint32_T
  c50_chartNumber, uint32_T c50_instanceNumber)
{
  (void)c50_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\14-12-2015-Matlab\\encStr2Arr.m"));
  _SFD_SCRIPT_TRANSLATION(c50_chartNumber, c50_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\root180\\Documents\\affective-project\\14-12-2015-Matlab\\cmdBML_AU_VA.m"));
}

static real_T c50_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_feval, const char_T *c50_identifier)
{
  real_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
  return c50_y;
}

static real_T c50_b_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  real_T c50_y;
  real_T c50_d1;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_d1, 1, 0, 0U, 0, 0U, 0);
  c50_y = c50_d1;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_c_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_strcat, const char_T *c50_identifier,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_strcat), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_strcat);
}

static void c50_d_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i51;
  uint32_T c50_uv0[2];
  int32_T c50_i52;
  static boolean_T c50_bv0[2] = { false, true };

  boolean_T c50_bv1[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[965];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i53;
  (void)chartInstance;
  for (c50_i51 = 0; c50_i51 < 2; c50_i51++) {
    c50_uv0[c50_i51] = 1U + 964U * (uint32_T)c50_i51;
  }

  for (c50_i52 = 0; c50_i52 < 2; c50_i52++) {
    c50_bv1[c50_i52] = c50_bv0[c50_i52];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 0, 10, 0U, 1,
                   0U, 2, c50_bv1, c50_uv0, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i53 = 0; c50_i53 <= c50_loop_ub; c50_i53++) {
    c50_y_data[c50_i53] = c50_tmp_data[c50_i53];
  }

  sf_mex_destroy(&c50_u);
}

static const mxArray *c50_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i54;
  real_T c50_b_inData[11];
  int32_T c50_i55;
  real_T c50_u[11];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i54 = 0; c50_i54 < 11; c50_i54++) {
    c50_b_inData[c50_i54] = (*(real_T (*)[11])c50_inData)[c50_i54];
  }

  for (c50_i55 = 0; c50_i55 < 11; c50_i55++) {
    c50_u[c50_i55] = c50_b_inData[c50_i55];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 11),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_e_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_eAmountFactor, const char_T *c50_identifier,
  real_T c50_y[11])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_eAmountFactor),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_eAmountFactor);
}

static void c50_f_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[11])
{
  real_T c50_dv16[11];
  int32_T c50_i56;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv16, 1, 0, 0U, 1, 0U, 2, 1,
                11);
  for (c50_i56 = 0; c50_i56 < 11; c50_i56++) {
    c50_y[c50_i56] = c50_dv16[c50_i56];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_eAmountFactor;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[11];
  int32_T c50_i57;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_eAmountFactor = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_eAmountFactor),
    &c50_thisId, c50_y);
  sf_mex_destroy(&c50_eAmountFactor);
  for (c50_i57 = 0; c50_i57 < 11; c50_i57++) {
    (*(real_T (*)[11])c50_outData)[c50_i57] = c50_y[c50_i57];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_b_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  real_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(real_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_feval;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_feval = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_feval),
    &c50_thisId);
  sf_mex_destroy(&c50_feval);
  *(real_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_c_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i58;
  int32_T c50_i59;
  int32_T c50_i60;
  real_T c50_b_inData[5000];
  int32_T c50_i61;
  int32_T c50_i62;
  int32_T c50_i63;
  real_T c50_u[5000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_i58 = 0;
  for (c50_i59 = 0; c50_i59 < 5; c50_i59++) {
    for (c50_i60 = 0; c50_i60 < 1000; c50_i60++) {
      c50_b_inData[c50_i60 + c50_i58] = (*(real_T (*)[5000])c50_inData)[c50_i60
        + c50_i58];
    }

    c50_i58 += 1000;
  }

  c50_i61 = 0;
  for (c50_i62 = 0; c50_i62 < 5; c50_i62++) {
    for (c50_i63 = 0; c50_i63 < 1000; c50_i63++) {
      c50_u[c50_i63 + c50_i61] = c50_b_inData[c50_i63 + c50_i61];
    }

    c50_i61 += 1000;
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1000, 5),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_g_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_newBmls, const char_T *c50_identifier,
  real_T c50_y[5000])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_newBmls), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_newBmls);
}

static void c50_h_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[5000])
{
  real_T c50_dv17[5000];
  int32_T c50_i64;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv17, 1, 0, 0U, 1, 0U, 2,
                1000, 5);
  for (c50_i64 = 0; c50_i64 < 5000; c50_i64++) {
    c50_y[c50_i64] = c50_dv17[c50_i64];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_newBmls;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[5000];
  int32_T c50_i65;
  int32_T c50_i66;
  int32_T c50_i67;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_newBmls = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_newBmls), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_newBmls);
  c50_i65 = 0;
  for (c50_i66 = 0; c50_i66 < 5; c50_i66++) {
    for (c50_i67 = 0; c50_i67 < 1000; c50_i67++) {
      (*(real_T (*)[5000])c50_outData)[c50_i67 + c50_i65] = c50_y[c50_i67 +
        c50_i65];
    }

    c50_i65 += 1000;
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_d_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i68;
  real_T c50_b_inData[1000];
  int32_T c50_i69;
  real_T c50_u[1000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i68 = 0; c50_i68 < 1000; c50_i68++) {
    c50_b_inData[c50_i68] = (*(real_T (*)[1000])c50_inData)[c50_i68];
  }

  for (c50_i69 = 0; c50_i69 < 1000; c50_i69++) {
    c50_u[c50_i69] = c50_b_inData[c50_i69];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1000, 1),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_i_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_myBML, const char_T *c50_identifier, real_T
  c50_y[1000])
{
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_myBML), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_myBML);
}

static void c50_j_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[1000])
{
  real_T c50_dv18[1000];
  int32_T c50_i70;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv18, 1, 0, 0U, 1, 0U, 2,
                1000, 1);
  for (c50_i70 = 0; c50_i70 < 1000; c50_i70++) {
    c50_y[c50_i70] = c50_dv18[c50_i70];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_myBML;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[1000];
  int32_T c50_i71;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_myBML = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_myBML), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_myBML);
  for (c50_i71 = 0; c50_i71 < 1000; c50_i71++) {
    (*(real_T (*)[1000])c50_outData)[c50_i71] = c50_y[c50_i71];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_e_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i72;
  real_T c50_b_inData[1000];
  int32_T c50_i73;
  real_T c50_u[1000];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i72 = 0; c50_i72 < 1000; c50_i72++) {
    c50_b_inData[c50_i72] = (*(real_T (*)[1000])c50_inData)[c50_i72];
  }

  for (c50_i73 = 0; c50_i73 < 1000; c50_i73++) {
    c50_u[c50_i73] = c50_b_inData[c50_i73];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 1, 1000), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_k_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[1000])
{
  real_T c50_dv19[1000];
  int32_T c50_i74;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv19, 1, 0, 0U, 1, 0U, 1,
                1000);
  for (c50_i74 = 0; c50_i74 < 1000; c50_i74++) {
    c50_y[c50_i74] = c50_dv19[c50_i74];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_myarr256;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[1000];
  int32_T c50_i75;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_myarr256 = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_myarr256), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_myarr256);
  for (c50_i75 = 0; c50_i75 < 1000; c50_i75++) {
    (*(real_T (*)[1000])c50_outData)[c50_i75] = c50_y[c50_i75];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_f_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  char_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(char_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_g_sf_marshallOut(void *chartInstanceVoid, char_T
  c50_inData_data[], int32_T c50_inData_sizes[2])
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes[2];
  int32_T c50_loop_ub;
  int32_T c50_i76;
  char_T c50_b_inData_data[965];
  int32_T c50_u_sizes[2];
  int32_T c50_b_loop_ub;
  int32_T c50_i77;
  char_T c50_u_data[965];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes[0] = 1;
  c50_b_inData_sizes[1] = c50_inData_sizes[1];
  c50_loop_ub = c50_inData_sizes[1] - 1;
  for (c50_i76 = 0; c50_i76 <= c50_loop_ub; c50_i76++) {
    c50_b_inData_data[c50_b_inData_sizes[0] * c50_i76] =
      c50_inData_data[c50_inData_sizes[0] * c50_i76];
  }

  c50_u_sizes[0] = 1;
  c50_u_sizes[1] = c50_b_inData_sizes[1];
  c50_b_loop_ub = c50_b_inData_sizes[1] - 1;
  for (c50_i77 = 0; c50_i77 <= c50_b_loop_ub; c50_i77++) {
    c50_u_data[c50_u_sizes[0] * c50_i77] = c50_b_inData_data[c50_b_inData_sizes
      [0] * c50_i77];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 10, 0U, 1U, 0U, 2,
    c50_u_sizes[0], c50_u_sizes[1]), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_l_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y_data[], int32_T c50_y_sizes[2])
{
  int32_T c50_i78;
  uint32_T c50_uv1[2];
  int32_T c50_i79;
  static boolean_T c50_bv2[2] = { false, true };

  boolean_T c50_bv3[2];
  int32_T c50_tmp_sizes[2];
  char_T c50_tmp_data[965];
  int32_T c50_y;
  int32_T c50_b_y;
  int32_T c50_loop_ub;
  int32_T c50_i80;
  (void)chartInstance;
  for (c50_i78 = 0; c50_i78 < 2; c50_i78++) {
    c50_uv1[c50_i78] = 1U + 964U * (uint32_T)c50_i78;
  }

  for (c50_i79 = 0; c50_i79 < 2; c50_i79++) {
    c50_bv3[c50_i79] = c50_bv2[c50_i79];
  }

  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c50_bv3, c50_uv1, c50_tmp_sizes);
  c50_y_sizes[0] = 1;
  c50_y_sizes[1] = c50_tmp_sizes[1];
  c50_y = c50_y_sizes[0];
  c50_b_y = c50_y_sizes[1];
  c50_loop_ub = c50_tmp_sizes[0] * c50_tmp_sizes[1] - 1;
  for (c50_i80 = 0; c50_i80 <= c50_loop_ub; c50_i80++) {
    c50_y_data[c50_i80] = c50_tmp_data[c50_i80];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, char_T c50_outData_data[],
  int32_T c50_outData_sizes[2])
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes[2];
  char_T c50_y_data[965];
  int32_T c50_loop_ub;
  int32_T c50_i81;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y_data, c50_y_sizes);
  sf_mex_destroy(&c50_mystr);
  c50_outData_sizes[0] = 1;
  c50_outData_sizes[1] = c50_y_sizes[1];
  c50_loop_ub = c50_y_sizes[1] - 1;
  for (c50_i81 = 0; c50_i81 <= c50_loop_ub; c50_i81++) {
    c50_outData_data[c50_outData_sizes[0] * c50_i81] = c50_y_data[c50_y_sizes[0]
      * c50_i81];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c50_inData_data[], int32_T *c50_inData_sizes)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_b_inData_sizes;
  int32_T c50_loop_ub;
  int32_T c50_i82;
  real_T c50_b_inData_data[965];
  int32_T c50_u_sizes;
  int32_T c50_b_loop_ub;
  int32_T c50_i83;
  real_T c50_u_data[965];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_b_inData_sizes = *c50_inData_sizes;
  c50_loop_ub = *c50_inData_sizes - 1;
  for (c50_i82 = 0; c50_i82 <= c50_loop_ub; c50_i82++) {
    c50_b_inData_data[c50_i82] = c50_inData_data[c50_i82];
  }

  c50_u_sizes = c50_b_inData_sizes;
  c50_b_loop_ub = c50_b_inData_sizes - 1;
  for (c50_i83 = 0; c50_i83 <= c50_b_loop_ub; c50_i83++) {
    c50_u_data[c50_i83] = c50_b_inData_data[c50_i83];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u_data, 0, 0U, 1U, 0U, 1,
    c50_u_sizes), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_m_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y_data[], int32_T *c50_y_sizes)
{
  static uint32_T c50_uv2[1] = { 965U };

  uint32_T c50_uv3[1];
  static boolean_T c50_bv4[1] = { true };

  boolean_T c50_bv5[1];
  int32_T c50_tmp_sizes;
  real_T c50_tmp_data[965];
  int32_T c50_loop_ub;
  int32_T c50_i84;
  (void)chartInstance;
  c50_uv3[0] = c50_uv2[0];
  c50_bv5[0] = c50_bv4[0];
  sf_mex_import_vs(c50_parentId, sf_mex_dup(c50_u), c50_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c50_bv5, c50_uv3, &c50_tmp_sizes);
  *c50_y_sizes = c50_tmp_sizes;
  c50_loop_ub = c50_tmp_sizes - 1;
  for (c50_i84 = 0; c50_i84 <= c50_loop_ub; c50_i84++) {
    c50_y_data[c50_i84] = c50_tmp_data[c50_i84];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, real_T c50_outData_data[],
  int32_T *c50_outData_sizes)
{
  const mxArray *c50_arr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y_sizes;
  real_T c50_y_data[965];
  int32_T c50_loop_ub;
  int32_T c50_i85;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_arr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_arr), &c50_thisId,
    c50_y_data, &c50_y_sizes);
  sf_mex_destroy(&c50_arr);
  *c50_outData_sizes = c50_y_sizes;
  c50_loop_ub = c50_y_sizes - 1;
  for (c50_i85 = 0; c50_i85 <= c50_loop_ub; c50_i85++) {
    c50_outData_data[c50_i85] = c50_y_data[c50_i85];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_i_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i86;
  char_T c50_b_inData[103];
  int32_T c50_i87;
  char_T c50_u[103];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i86 = 0; c50_i86 < 103; c50_i86++) {
    c50_b_inData[c50_i86] = (*(char_T (*)[103])c50_inData)[c50_i86];
  }

  for (c50_i87 = 0; c50_i87 < 103; c50_i87++) {
    c50_u[c50_i87] = c50_b_inData[c50_i87];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 103),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_n_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[103])
{
  char_T c50_cv5[103];
  int32_T c50_i88;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv5, 1, 10, 0U, 1, 0U, 2, 1,
                103);
  for (c50_i88 = 0; c50_i88 < 103; c50_i88++) {
    c50_y[c50_i88] = c50_cv5[c50_i88];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[103];
  int32_T c50_i89;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i89 = 0; c50_i89 < 103; c50_i89++) {
    (*(char_T (*)[103])c50_outData)[c50_i89] = c50_y[c50_i89];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_j_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i90;
  char_T c50_b_inData[206];
  int32_T c50_i91;
  char_T c50_u[206];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i90 = 0; c50_i90 < 206; c50_i90++) {
    c50_b_inData[c50_i90] = (*(char_T (*)[206])c50_inData)[c50_i90];
  }

  for (c50_i91 = 0; c50_i91 < 206; c50_i91++) {
    c50_u[c50_i91] = c50_b_inData[c50_i91];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 206),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_o_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[206])
{
  char_T c50_cv6[206];
  int32_T c50_i92;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv6, 1, 10, 0U, 1, 0U, 2, 1,
                206);
  for (c50_i92 = 0; c50_i92 < 206; c50_i92++) {
    c50_y[c50_i92] = c50_cv6[c50_i92];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[206];
  int32_T c50_i93;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i93 = 0; c50_i93 < 206; c50_i93++) {
    (*(char_T (*)[206])c50_outData)[c50_i93] = c50_y[c50_i93];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_k_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i94;
  char_T c50_b_inData[306];
  int32_T c50_i95;
  char_T c50_u[306];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i94 = 0; c50_i94 < 306; c50_i94++) {
    c50_b_inData[c50_i94] = (*(char_T (*)[306])c50_inData)[c50_i94];
  }

  for (c50_i95 = 0; c50_i95 < 306; c50_i95++) {
    c50_u[c50_i95] = c50_b_inData[c50_i95];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 306),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_p_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[306])
{
  char_T c50_cv7[306];
  int32_T c50_i96;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv7, 1, 10, 0U, 1, 0U, 2, 1,
                306);
  for (c50_i96 = 0; c50_i96 < 306; c50_i96++) {
    c50_y[c50_i96] = c50_cv7[c50_i96];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[306];
  int32_T c50_i97;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i97 = 0; c50_i97 < 306; c50_i97++) {
    (*(char_T (*)[306])c50_outData)[c50_i97] = c50_y[c50_i97];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_l_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i98;
  char_T c50_b_inData[412];
  int32_T c50_i99;
  char_T c50_u[412];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i98 = 0; c50_i98 < 412; c50_i98++) {
    c50_b_inData[c50_i98] = (*(char_T (*)[412])c50_inData)[c50_i98];
  }

  for (c50_i99 = 0; c50_i99 < 412; c50_i99++) {
    c50_u[c50_i99] = c50_b_inData[c50_i99];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 412),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_q_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[412])
{
  char_T c50_cv8[412];
  int32_T c50_i100;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv8, 1, 10, 0U, 1, 0U, 2, 1,
                412);
  for (c50_i100 = 0; c50_i100 < 412; c50_i100++) {
    c50_y[c50_i100] = c50_cv8[c50_i100];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[412];
  int32_T c50_i101;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i101 = 0; c50_i101 < 412; c50_i101++) {
    (*(char_T (*)[412])c50_outData)[c50_i101] = c50_y[c50_i101];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_m_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i102;
  char_T c50_b_inData[515];
  int32_T c50_i103;
  char_T c50_u[515];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i102 = 0; c50_i102 < 515; c50_i102++) {
    c50_b_inData[c50_i102] = (*(char_T (*)[515])c50_inData)[c50_i102];
  }

  for (c50_i103 = 0; c50_i103 < 515; c50_i103++) {
    c50_u[c50_i103] = c50_b_inData[c50_i103];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 515),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_r_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[515])
{
  char_T c50_cv9[515];
  int32_T c50_i104;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv9, 1, 10, 0U, 1, 0U, 2, 1,
                515);
  for (c50_i104 = 0; c50_i104 < 515; c50_i104++) {
    c50_y[c50_i104] = c50_cv9[c50_i104];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[515];
  int32_T c50_i105;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i105 = 0; c50_i105 < 515; c50_i105++) {
    (*(char_T (*)[515])c50_outData)[c50_i105] = c50_y[c50_i105];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_n_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i106;
  char_T c50_b_inData[656];
  int32_T c50_i107;
  char_T c50_u[656];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i106 = 0; c50_i106 < 656; c50_i106++) {
    c50_b_inData[c50_i106] = (*(char_T (*)[656])c50_inData)[c50_i106];
  }

  for (c50_i107 = 0; c50_i107 < 656; c50_i107++) {
    c50_u[c50_i107] = c50_b_inData[c50_i107];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 656),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_s_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[656])
{
  char_T c50_cv10[656];
  int32_T c50_i108;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv10, 1, 10, 0U, 1, 0U, 2,
                1, 656);
  for (c50_i108 = 0; c50_i108 < 656; c50_i108++) {
    c50_y[c50_i108] = c50_cv10[c50_i108];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[656];
  int32_T c50_i109;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i109 = 0; c50_i109 < 656; c50_i109++) {
    (*(char_T (*)[656])c50_outData)[c50_i109] = c50_y[c50_i109];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_o_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i110;
  char_T c50_b_inData[759];
  int32_T c50_i111;
  char_T c50_u[759];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i110 = 0; c50_i110 < 759; c50_i110++) {
    c50_b_inData[c50_i110] = (*(char_T (*)[759])c50_inData)[c50_i110];
  }

  for (c50_i111 = 0; c50_i111 < 759; c50_i111++) {
    c50_u[c50_i111] = c50_b_inData[c50_i111];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 759),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_t_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[759])
{
  char_T c50_cv11[759];
  int32_T c50_i112;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv11, 1, 10, 0U, 1, 0U, 2,
                1, 759);
  for (c50_i112 = 0; c50_i112 < 759; c50_i112++) {
    c50_y[c50_i112] = c50_cv11[c50_i112];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[759];
  int32_T c50_i113;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i113 = 0; c50_i113 < 759; c50_i113++) {
    (*(char_T (*)[759])c50_outData)[c50_i113] = c50_y[c50_i113];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_p_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i114;
  char_T c50_b_inData[862];
  int32_T c50_i115;
  char_T c50_u[862];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i114 = 0; c50_i114 < 862; c50_i114++) {
    c50_b_inData[c50_i114] = (*(char_T (*)[862])c50_inData)[c50_i114];
  }

  for (c50_i115 = 0; c50_i115 < 862; c50_i115++) {
    c50_u[c50_i115] = c50_b_inData[c50_i115];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 862),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_u_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[862])
{
  char_T c50_cv12[862];
  int32_T c50_i116;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv12, 1, 10, 0U, 1, 0U, 2,
                1, 862);
  for (c50_i116 = 0; c50_i116 < 862; c50_i116++) {
    c50_y[c50_i116] = c50_cv12[c50_i116];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[862];
  int32_T c50_i117;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i117 = 0; c50_i117 < 862; c50_i117++) {
    (*(char_T (*)[862])c50_outData)[c50_i117] = c50_y[c50_i117];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_q_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i118;
  char_T c50_b_inData[965];
  int32_T c50_i119;
  char_T c50_u[965];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i118 = 0; c50_i118 < 965; c50_i118++) {
    c50_b_inData[c50_i118] = (*(char_T (*)[965])c50_inData)[c50_i118];
  }

  for (c50_i119 = 0; c50_i119 < 965; c50_i119++) {
    c50_u[c50_i119] = c50_b_inData[c50_i119];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 965),
                false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_v_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  char_T c50_y[965])
{
  char_T c50_cv13[965];
  int32_T c50_i120;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_cv13, 1, 10, 0U, 1, 0U, 2,
                1, 965);
  for (c50_i120 = 0; c50_i120 < 965; c50_i120++) {
    c50_y[c50_i120] = c50_cv13[c50_i120];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_mystr;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  char_T c50_y[965];
  int32_T c50_i121;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mystr = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_mystr), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_mystr);
  for (c50_i121 = 0; c50_i121 < 965; c50_i121++) {
    (*(char_T (*)[965])c50_outData)[c50_i121] = c50_y[c50_i121];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_r_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  const mxArray *c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = sf_mex_dup(*(const mxArray **)c50_inData);
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static const mxArray *c50_s_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_i122;
  real_T c50_b_inData[9];
  int32_T c50_i123;
  real_T c50_u[9];
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  for (c50_i122 = 0; c50_i122 < 9; c50_i122++) {
    c50_b_inData[c50_i122] = (*(real_T (*)[9])c50_inData)[c50_i122];
  }

  for (c50_i123 = 0; c50_i123 < 9; c50_i123++) {
    c50_u[c50_i123] = c50_b_inData[c50_i123];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 0, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static void c50_w_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId,
  real_T c50_y[9])
{
  real_T c50_dv20[9];
  int32_T c50_i124;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), c50_dv20, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c50_i124 = 0; c50_i124 < 9; c50_i124++) {
    c50_y[c50_i124] = c50_dv20[c50_i124];
  }

  sf_mex_destroy(&c50_u);
}

static void c50_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_all_AUs;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  real_T c50_y[9];
  int32_T c50_i125;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_all_AUs = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_all_AUs), &c50_thisId,
    c50_y);
  sf_mex_destroy(&c50_all_AUs);
  for (c50_i125 = 0; c50_i125 < 9; c50_i125++) {
    (*(real_T (*)[9])c50_outData)[c50_i125] = c50_y[c50_i125];
  }

  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_t_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  boolean_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(boolean_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static boolean_T c50_x_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  boolean_T c50_y;
  boolean_T c50_b3;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_b3, 1, 11, 0U, 0, 0U, 0);
  c50_y = c50_b3;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_sf_internal_predicateOutput;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  boolean_T c50_y;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_sf_internal_predicateOutput = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_x_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_sf_internal_predicateOutput), &c50_thisId);
  sf_mex_destroy(&c50_sf_internal_predicateOutput);
  *(boolean_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

const mxArray *sf_c50_Demo_AU_VA1_get_eml_resolved_functions_info(void)
{
  const mxArray *c50_nameCaptureInfo = NULL;
  c50_nameCaptureInfo = NULL;
  sf_mex_assign(&c50_nameCaptureInfo, sf_mex_createstruct("structure", 2, 86, 1),
                false);
  c50_info_helper(&c50_nameCaptureInfo);
  c50_b_info_helper(&c50_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c50_nameCaptureInfo);
  return c50_nameCaptureInfo;
}

static void c50_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs0 = NULL;
  const mxArray *c50_lhs0 = NULL;
  const mxArray *c50_rhs1 = NULL;
  const mxArray *c50_lhs1 = NULL;
  const mxArray *c50_rhs2 = NULL;
  const mxArray *c50_lhs2 = NULL;
  const mxArray *c50_rhs3 = NULL;
  const mxArray *c50_lhs3 = NULL;
  const mxArray *c50_rhs4 = NULL;
  const mxArray *c50_lhs4 = NULL;
  const mxArray *c50_rhs5 = NULL;
  const mxArray *c50_lhs5 = NULL;
  const mxArray *c50_rhs6 = NULL;
  const mxArray *c50_lhs6 = NULL;
  const mxArray *c50_rhs7 = NULL;
  const mxArray *c50_lhs7 = NULL;
  const mxArray *c50_rhs8 = NULL;
  const mxArray *c50_lhs8 = NULL;
  const mxArray *c50_rhs9 = NULL;
  const mxArray *c50_lhs9 = NULL;
  const mxArray *c50_rhs10 = NULL;
  const mxArray *c50_lhs10 = NULL;
  const mxArray *c50_rhs11 = NULL;
  const mxArray *c50_lhs11 = NULL;
  const mxArray *c50_rhs12 = NULL;
  const mxArray *c50_lhs12 = NULL;
  const mxArray *c50_rhs13 = NULL;
  const mxArray *c50_lhs13 = NULL;
  const mxArray *c50_rhs14 = NULL;
  const mxArray *c50_lhs14 = NULL;
  const mxArray *c50_rhs15 = NULL;
  const mxArray *c50_lhs15 = NULL;
  const mxArray *c50_rhs16 = NULL;
  const mxArray *c50_lhs16 = NULL;
  const mxArray *c50_rhs17 = NULL;
  const mxArray *c50_lhs17 = NULL;
  const mxArray *c50_rhs18 = NULL;
  const mxArray *c50_lhs18 = NULL;
  const mxArray *c50_rhs19 = NULL;
  const mxArray *c50_lhs19 = NULL;
  const mxArray *c50_rhs20 = NULL;
  const mxArray *c50_lhs20 = NULL;
  const mxArray *c50_rhs21 = NULL;
  const mxArray *c50_lhs21 = NULL;
  const mxArray *c50_rhs22 = NULL;
  const mxArray *c50_lhs22 = NULL;
  const mxArray *c50_rhs23 = NULL;
  const mxArray *c50_lhs23 = NULL;
  const mxArray *c50_rhs24 = NULL;
  const mxArray *c50_lhs24 = NULL;
  const mxArray *c50_rhs25 = NULL;
  const mxArray *c50_lhs25 = NULL;
  const mxArray *c50_rhs26 = NULL;
  const mxArray *c50_lhs26 = NULL;
  const mxArray *c50_rhs27 = NULL;
  const mxArray *c50_lhs27 = NULL;
  const mxArray *c50_rhs28 = NULL;
  const mxArray *c50_lhs28 = NULL;
  const mxArray *c50_rhs29 = NULL;
  const mxArray *c50_lhs29 = NULL;
  const mxArray *c50_rhs30 = NULL;
  const mxArray *c50_lhs30 = NULL;
  const mxArray *c50_rhs31 = NULL;
  const mxArray *c50_lhs31 = NULL;
  const mxArray *c50_rhs32 = NULL;
  const mxArray *c50_lhs32 = NULL;
  const mxArray *c50_rhs33 = NULL;
  const mxArray *c50_lhs33 = NULL;
  const mxArray *c50_rhs34 = NULL;
  const mxArray *c50_lhs34 = NULL;
  const mxArray *c50_rhs35 = NULL;
  const mxArray *c50_lhs35 = NULL;
  const mxArray *c50_rhs36 = NULL;
  const mxArray *c50_lhs36 = NULL;
  const mxArray *c50_rhs37 = NULL;
  const mxArray *c50_lhs37 = NULL;
  const mxArray *c50_rhs38 = NULL;
  const mxArray *c50_lhs38 = NULL;
  const mxArray *c50_rhs39 = NULL;
  const mxArray *c50_lhs39 = NULL;
  const mxArray *c50_rhs40 = NULL;
  const mxArray *c50_lhs40 = NULL;
  const mxArray *c50_rhs41 = NULL;
  const mxArray *c50_lhs41 = NULL;
  const mxArray *c50_rhs42 = NULL;
  const mxArray *c50_lhs42 = NULL;
  const mxArray *c50_rhs43 = NULL;
  const mxArray *c50_lhs43 = NULL;
  const mxArray *c50_rhs44 = NULL;
  const mxArray *c50_lhs44 = NULL;
  const mxArray *c50_rhs45 = NULL;
  const mxArray *c50_lhs45 = NULL;
  const mxArray *c50_rhs46 = NULL;
  const mxArray *c50_lhs46 = NULL;
  const mxArray *c50_rhs47 = NULL;
  const mxArray *c50_lhs47 = NULL;
  const mxArray *c50_rhs48 = NULL;
  const mxArray *c50_lhs48 = NULL;
  const mxArray *c50_rhs49 = NULL;
  const mxArray *c50_lhs49 = NULL;
  const mxArray *c50_rhs50 = NULL;
  const mxArray *c50_lhs50 = NULL;
  const mxArray *c50_rhs51 = NULL;
  const mxArray *c50_lhs51 = NULL;
  const mxArray *c50_rhs52 = NULL;
  const mxArray *c50_lhs52 = NULL;
  const mxArray *c50_rhs53 = NULL;
  const mxArray *c50_lhs53 = NULL;
  const mxArray *c50_rhs54 = NULL;
  const mxArray *c50_lhs54 = NULL;
  const mxArray *c50_rhs55 = NULL;
  const mxArray *c50_lhs55 = NULL;
  const mxArray *c50_rhs56 = NULL;
  const mxArray *c50_lhs56 = NULL;
  const mxArray *c50_rhs57 = NULL;
  const mxArray *c50_lhs57 = NULL;
  const mxArray *c50_rhs58 = NULL;
  const mxArray *c50_lhs58 = NULL;
  const mxArray *c50_rhs59 = NULL;
  const mxArray *c50_lhs59 = NULL;
  const mxArray *c50_rhs60 = NULL;
  const mxArray *c50_lhs60 = NULL;
  const mxArray *c50_rhs61 = NULL;
  const mxArray *c50_lhs61 = NULL;
  const mxArray *c50_rhs62 = NULL;
  const mxArray *c50_lhs62 = NULL;
  const mxArray *c50_rhs63 = NULL;
  const mxArray *c50_lhs63 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c50_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c50_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c50_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isnan"), "name", "name", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c50_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c50_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c50_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c50_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c50_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c50_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c50_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c50_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c50_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c50_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c50_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c50_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("colon"), "name", "name", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c50_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c50_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c50_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("floor"), "name", "name", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c50_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c50_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c50_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c50_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c50_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c50_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmin"), "name", "name", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c50_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c50_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c50_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c50_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c50_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c50_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c50_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c50_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c50_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c50_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c50_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c50_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c50_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c50_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "name", "name", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c50_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fidCheck"), "name", "name",
                  39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c50_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("upper"), "name", "name", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c50_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c50_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!get_arg_info_struct"),
                  "context", "context", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851182U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c50_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c50_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!validate_arguments"),
                  "context", "context", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c50_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c50_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m!check_type"),
                  "context", "context", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c50_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c50_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c50_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("rdivide"), "name", "name",
                  49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742680U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c50_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c50_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851196U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c50_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_div"), "name", "name",
                  52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c50_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c50_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c50_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isequal"), "name", "name",
                  55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c50_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c50_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("isnan"), "name", "name", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c50_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c50_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "context", "context", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("cmdBML_AU_VA"), "name",
                  "name", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1450214020U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c50_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("fprintf"), "name", "name",
                  60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c50_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("abs"), "name", "name", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c50_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c50_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851112U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c50_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c50_rhs0);
  sf_mex_destroy(&c50_lhs0);
  sf_mex_destroy(&c50_rhs1);
  sf_mex_destroy(&c50_lhs1);
  sf_mex_destroy(&c50_rhs2);
  sf_mex_destroy(&c50_lhs2);
  sf_mex_destroy(&c50_rhs3);
  sf_mex_destroy(&c50_lhs3);
  sf_mex_destroy(&c50_rhs4);
  sf_mex_destroy(&c50_lhs4);
  sf_mex_destroy(&c50_rhs5);
  sf_mex_destroy(&c50_lhs5);
  sf_mex_destroy(&c50_rhs6);
  sf_mex_destroy(&c50_lhs6);
  sf_mex_destroy(&c50_rhs7);
  sf_mex_destroy(&c50_lhs7);
  sf_mex_destroy(&c50_rhs8);
  sf_mex_destroy(&c50_lhs8);
  sf_mex_destroy(&c50_rhs9);
  sf_mex_destroy(&c50_lhs9);
  sf_mex_destroy(&c50_rhs10);
  sf_mex_destroy(&c50_lhs10);
  sf_mex_destroy(&c50_rhs11);
  sf_mex_destroy(&c50_lhs11);
  sf_mex_destroy(&c50_rhs12);
  sf_mex_destroy(&c50_lhs12);
  sf_mex_destroy(&c50_rhs13);
  sf_mex_destroy(&c50_lhs13);
  sf_mex_destroy(&c50_rhs14);
  sf_mex_destroy(&c50_lhs14);
  sf_mex_destroy(&c50_rhs15);
  sf_mex_destroy(&c50_lhs15);
  sf_mex_destroy(&c50_rhs16);
  sf_mex_destroy(&c50_lhs16);
  sf_mex_destroy(&c50_rhs17);
  sf_mex_destroy(&c50_lhs17);
  sf_mex_destroy(&c50_rhs18);
  sf_mex_destroy(&c50_lhs18);
  sf_mex_destroy(&c50_rhs19);
  sf_mex_destroy(&c50_lhs19);
  sf_mex_destroy(&c50_rhs20);
  sf_mex_destroy(&c50_lhs20);
  sf_mex_destroy(&c50_rhs21);
  sf_mex_destroy(&c50_lhs21);
  sf_mex_destroy(&c50_rhs22);
  sf_mex_destroy(&c50_lhs22);
  sf_mex_destroy(&c50_rhs23);
  sf_mex_destroy(&c50_lhs23);
  sf_mex_destroy(&c50_rhs24);
  sf_mex_destroy(&c50_lhs24);
  sf_mex_destroy(&c50_rhs25);
  sf_mex_destroy(&c50_lhs25);
  sf_mex_destroy(&c50_rhs26);
  sf_mex_destroy(&c50_lhs26);
  sf_mex_destroy(&c50_rhs27);
  sf_mex_destroy(&c50_lhs27);
  sf_mex_destroy(&c50_rhs28);
  sf_mex_destroy(&c50_lhs28);
  sf_mex_destroy(&c50_rhs29);
  sf_mex_destroy(&c50_lhs29);
  sf_mex_destroy(&c50_rhs30);
  sf_mex_destroy(&c50_lhs30);
  sf_mex_destroy(&c50_rhs31);
  sf_mex_destroy(&c50_lhs31);
  sf_mex_destroy(&c50_rhs32);
  sf_mex_destroy(&c50_lhs32);
  sf_mex_destroy(&c50_rhs33);
  sf_mex_destroy(&c50_lhs33);
  sf_mex_destroy(&c50_rhs34);
  sf_mex_destroy(&c50_lhs34);
  sf_mex_destroy(&c50_rhs35);
  sf_mex_destroy(&c50_lhs35);
  sf_mex_destroy(&c50_rhs36);
  sf_mex_destroy(&c50_lhs36);
  sf_mex_destroy(&c50_rhs37);
  sf_mex_destroy(&c50_lhs37);
  sf_mex_destroy(&c50_rhs38);
  sf_mex_destroy(&c50_lhs38);
  sf_mex_destroy(&c50_rhs39);
  sf_mex_destroy(&c50_lhs39);
  sf_mex_destroy(&c50_rhs40);
  sf_mex_destroy(&c50_lhs40);
  sf_mex_destroy(&c50_rhs41);
  sf_mex_destroy(&c50_lhs41);
  sf_mex_destroy(&c50_rhs42);
  sf_mex_destroy(&c50_lhs42);
  sf_mex_destroy(&c50_rhs43);
  sf_mex_destroy(&c50_lhs43);
  sf_mex_destroy(&c50_rhs44);
  sf_mex_destroy(&c50_lhs44);
  sf_mex_destroy(&c50_rhs45);
  sf_mex_destroy(&c50_lhs45);
  sf_mex_destroy(&c50_rhs46);
  sf_mex_destroy(&c50_lhs46);
  sf_mex_destroy(&c50_rhs47);
  sf_mex_destroy(&c50_lhs47);
  sf_mex_destroy(&c50_rhs48);
  sf_mex_destroy(&c50_lhs48);
  sf_mex_destroy(&c50_rhs49);
  sf_mex_destroy(&c50_lhs49);
  sf_mex_destroy(&c50_rhs50);
  sf_mex_destroy(&c50_lhs50);
  sf_mex_destroy(&c50_rhs51);
  sf_mex_destroy(&c50_lhs51);
  sf_mex_destroy(&c50_rhs52);
  sf_mex_destroy(&c50_lhs52);
  sf_mex_destroy(&c50_rhs53);
  sf_mex_destroy(&c50_lhs53);
  sf_mex_destroy(&c50_rhs54);
  sf_mex_destroy(&c50_lhs54);
  sf_mex_destroy(&c50_rhs55);
  sf_mex_destroy(&c50_lhs55);
  sf_mex_destroy(&c50_rhs56);
  sf_mex_destroy(&c50_lhs56);
  sf_mex_destroy(&c50_rhs57);
  sf_mex_destroy(&c50_lhs57);
  sf_mex_destroy(&c50_rhs58);
  sf_mex_destroy(&c50_lhs58);
  sf_mex_destroy(&c50_rhs59);
  sf_mex_destroy(&c50_lhs59);
  sf_mex_destroy(&c50_rhs60);
  sf_mex_destroy(&c50_lhs60);
  sf_mex_destroy(&c50_rhs61);
  sf_mex_destroy(&c50_lhs61);
  sf_mex_destroy(&c50_rhs62);
  sf_mex_destroy(&c50_lhs62);
  sf_mex_destroy(&c50_rhs63);
  sf_mex_destroy(&c50_lhs63);
}

static const mxArray *c50_emlrt_marshallOut(const char * c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c50_u)), false);
  return c50_y;
}

static const mxArray *c50_b_emlrt_marshallOut(const uint32_T c50_u)
{
  const mxArray *c50_y = NULL;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 7, 0U, 0U, 0U, 0), false);
  return c50_y;
}

static void c50_b_info_helper(const mxArray **c50_info)
{
  const mxArray *c50_rhs64 = NULL;
  const mxArray *c50_lhs64 = NULL;
  const mxArray *c50_rhs65 = NULL;
  const mxArray *c50_lhs65 = NULL;
  const mxArray *c50_rhs66 = NULL;
  const mxArray *c50_lhs66 = NULL;
  const mxArray *c50_rhs67 = NULL;
  const mxArray *c50_lhs67 = NULL;
  const mxArray *c50_rhs68 = NULL;
  const mxArray *c50_lhs68 = NULL;
  const mxArray *c50_rhs69 = NULL;
  const mxArray *c50_lhs69 = NULL;
  const mxArray *c50_rhs70 = NULL;
  const mxArray *c50_lhs70 = NULL;
  const mxArray *c50_rhs71 = NULL;
  const mxArray *c50_lhs71 = NULL;
  const mxArray *c50_rhs72 = NULL;
  const mxArray *c50_lhs72 = NULL;
  const mxArray *c50_rhs73 = NULL;
  const mxArray *c50_lhs73 = NULL;
  const mxArray *c50_rhs74 = NULL;
  const mxArray *c50_lhs74 = NULL;
  const mxArray *c50_rhs75 = NULL;
  const mxArray *c50_lhs75 = NULL;
  const mxArray *c50_rhs76 = NULL;
  const mxArray *c50_lhs76 = NULL;
  const mxArray *c50_rhs77 = NULL;
  const mxArray *c50_lhs77 = NULL;
  const mxArray *c50_rhs78 = NULL;
  const mxArray *c50_lhs78 = NULL;
  const mxArray *c50_rhs79 = NULL;
  const mxArray *c50_lhs79 = NULL;
  const mxArray *c50_rhs80 = NULL;
  const mxArray *c50_lhs80 = NULL;
  const mxArray *c50_rhs81 = NULL;
  const mxArray *c50_lhs81 = NULL;
  const mxArray *c50_rhs82 = NULL;
  const mxArray *c50_lhs82 = NULL;
  const mxArray *c50_rhs83 = NULL;
  const mxArray *c50_lhs83 = NULL;
  const mxArray *c50_rhs84 = NULL;
  const mxArray *c50_lhs84 = NULL;
  const mxArray *c50_rhs85 = NULL;
  const mxArray *c50_lhs85 = NULL;
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("log10"), "name", "name", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862782U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c50_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_error"), "name", "name",
                  65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1343862758U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c50_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851128U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c50_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("realmax"), "name", "name",
                  67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1307683642U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c50_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c50_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1326760396U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c50_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("mrdivide"), "name", "name",
                  70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1388492496U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1370042286U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c50_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("ceil"), "name", "name", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742652U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c50_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c50_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/ceil.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_ceil"), "name",
                  "name", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_ceil.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1286851120U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c50_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("max"), "name", "name", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1311287716U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c50_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1378328384U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c50_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c50_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c50_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c50_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c50_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c50_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c50_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c50_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("blanks"), "name", "name", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363742678U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c50_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/blanks.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c50_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/cmdBML_AU_VA.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("encStr2Arr"), "name", "name",
                  85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c50_info, c50_emlrt_marshallOut(
    "[E]C:/Users/root180/Documents/affective-project/14-12-2015-Matlab/encStr2Arr.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(1445391012U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c50_info, c50_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c50_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c50_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c50_info, sf_mex_duplicatearraysafe(&c50_lhs85), "lhs", "lhs",
                  85);
  sf_mex_destroy(&c50_rhs64);
  sf_mex_destroy(&c50_lhs64);
  sf_mex_destroy(&c50_rhs65);
  sf_mex_destroy(&c50_lhs65);
  sf_mex_destroy(&c50_rhs66);
  sf_mex_destroy(&c50_lhs66);
  sf_mex_destroy(&c50_rhs67);
  sf_mex_destroy(&c50_lhs67);
  sf_mex_destroy(&c50_rhs68);
  sf_mex_destroy(&c50_lhs68);
  sf_mex_destroy(&c50_rhs69);
  sf_mex_destroy(&c50_lhs69);
  sf_mex_destroy(&c50_rhs70);
  sf_mex_destroy(&c50_lhs70);
  sf_mex_destroy(&c50_rhs71);
  sf_mex_destroy(&c50_lhs71);
  sf_mex_destroy(&c50_rhs72);
  sf_mex_destroy(&c50_lhs72);
  sf_mex_destroy(&c50_rhs73);
  sf_mex_destroy(&c50_lhs73);
  sf_mex_destroy(&c50_rhs74);
  sf_mex_destroy(&c50_lhs74);
  sf_mex_destroy(&c50_rhs75);
  sf_mex_destroy(&c50_lhs75);
  sf_mex_destroy(&c50_rhs76);
  sf_mex_destroy(&c50_lhs76);
  sf_mex_destroy(&c50_rhs77);
  sf_mex_destroy(&c50_lhs77);
  sf_mex_destroy(&c50_rhs78);
  sf_mex_destroy(&c50_lhs78);
  sf_mex_destroy(&c50_rhs79);
  sf_mex_destroy(&c50_lhs79);
  sf_mex_destroy(&c50_rhs80);
  sf_mex_destroy(&c50_lhs80);
  sf_mex_destroy(&c50_rhs81);
  sf_mex_destroy(&c50_lhs81);
  sf_mex_destroy(&c50_rhs82);
  sf_mex_destroy(&c50_lhs82);
  sf_mex_destroy(&c50_rhs83);
  sf_mex_destroy(&c50_lhs83);
  sf_mex_destroy(&c50_rhs84);
  sf_mex_destroy(&c50_lhs84);
  sf_mex_destroy(&c50_rhs85);
  sf_mex_destroy(&c50_lhs85);
}

static void c50_activate_secsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  chartInstance->c50_sfEvent = c50_event_secs;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c50_event_secs,
               chartInstance->c50_sfEvent);
}

static void c50_deactivate_secsc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance)
{
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c50_event_secs,
               chartInstance->c50_sfEvent);
}

static void c50_increment_counters_secsc50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  if (chartInstance->c50_temporalCounter_i1 < 15U) {
    chartInstance->c50_temporalCounter_i1++;
  }
}

static void c50_reset_counters_secsc50_Demo_AU_VA1
  (SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

void sf_exported_auto_activate_c50_Demo_AU_VA1_secs(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_activate_secsc50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_incrementTemporalCounter_c50_Demo_AU_VA1_secs(SimStruct
  *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_increment_counters_secsc50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_resetTemporalCounter_c50_Demo_AU_VA1_secs(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_reset_counters_secsc50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_deactivate_c50_Demo_AU_VA1_secs(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_deactivate_secsc50_Demo_AU_VA1(chartInstance);
}

boolean_T sf_exported_auto_isStablec50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  return chartInstance->c50_isStable;
}

void sf_exported_auto_duringc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_c50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_enterc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_enter_atomic_c50_Demo_AU_VA1(chartInstance);
  c50_enter_internal_c50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_exitc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
  c50_exit_internal_c50_Demo_AU_VA1(chartInstance);
}

void sf_exported_auto_gatewayc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_enablec50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_disablec50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _sfTime_ = sf_get_time(chartInstance->S);
}

void sf_exported_auto_stepBuffersc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initBuffersc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_activate_callc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  chartInstance->c50_sfEvent = CALL_EVENT;
}

void sf_exported_auto_increment_call_counterc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_reset_call_counterc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_deactivate_callc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
}

void sf_exported_auto_initc50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_initc50_Demo_AU_VA1(chartInstance);
}

const mxArray *sf_exported_auto_getSimstatec50_Demo_AU_VA1(SimStruct *c50_S)
{
  const mxArray *c50_out = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_out = NULL;
  sf_mex_assign(&c50_out, sf_internal_get_sim_state_c50_Demo_AU_VA1(c50_S),
                false);
  return c50_out;
}

void sf_exported_auto_setSimstatec50_Demo_AU_VA1(SimStruct *c50_S, const mxArray
  *c50_in)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  sf_internal_set_sim_state_c50_Demo_AU_VA1(c50_S, sf_mex_dup(c50_in));
  sf_mex_destroy(&c50_in);
}

void sf_exported_auto_check_state_inconsistency_c50_Demo_AU_VA1(SimStruct *c50_S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_AU_VA1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c50_set_AU_Amountc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_arousal, real_T c50_valence, real_T
  c50_eAmountFactor[11])
{
  uint32_T c50_debug_family_var_map[9];
  real_T c50_p;
  real_T c50_a;
  real_T c50_all_AUs[11];
  real_T c50_c;
  real_T c50_nargin = 2.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i126;
  static real_T c50_dv21[11] = { 1.0, 2.0, 4.0, 5.0, 6.0, 7.0, 12.0, 26.0, 45.0,
    10.0, 25.0 };

  int32_T c50_i127;
  int32_T c50_b_c;
  int32_T c50_i128;
  real_T c50_A[11];
  int32_T c50_i129;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c50_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_p, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_a, 1U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_all_AUs, 2U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_c, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 5U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_arousal, 6U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_valence, 7U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_eAmountFactor, 8U, c50_sf_marshallOut,
    c50_sf_marshallIn);
  CV_EML_FCN(1, 0);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 3);
  c50_c_fprintf(chartInstance, c50_arousal, c50_valence);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 8);
  c50_p = c50_valence;
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 8);
  c50_a = c50_arousal;
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 9);
  for (c50_i126 = 0; c50_i126 < 11; c50_i126++) {
    c50_all_AUs[c50_i126] = c50_dv21[c50_i126];
  }

  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 9);
  for (c50_i127 = 0; c50_i127 < 11; c50_i127++) {
    c50_eAmountFactor[c50_i127] = 0.0;
  }

  c50_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 10);
  c50_c = 1.0;
  c50_b_c = 0;
  while (c50_b_c < 9) {
    c50_c = 1.0 + (real_T)c50_b_c;
    CV_EML_FOR(1, 1, 0, 1);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 11);
    c50_eAmountFactor[0] = 0.003 * c50_p - 0.002 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 12);
    c50_eAmountFactor[1] = -0.002 * c50_p + 0.01 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 14);
    c50_eAmountFactor[7] = -0.002 * c50_p + 0.049 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 15);
    c50_eAmountFactor[4] = -0.008 * c50_p + 0.009 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 20);
    c50_eAmountFactor[9] = -0.053 * c50_p + 0.026 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 21);
    c50_eAmountFactor[3] = -0.003 * c50_p + 0.032 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 22);
    c50_eAmountFactor[8] = -0.021 * c50_p - 0.037 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 23);
    c50_eAmountFactor[2] = -0.036 * c50_p + 0.022 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 27);
    c50_eAmountFactor[10] = -0.023 * c50_p + 0.058 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 32);
    c50_eAmountFactor[5] = -0.005 * c50_p - 0.001 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 33);
    c50_eAmountFactor[6] = 0.057 * c50_p + 0.009 * c50_a;
    c50_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, 39);
    c50_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U);
    for (c50_i128 = 0; c50_i128 < 11; c50_i128++) {
      c50_A[c50_i128] = c50_eAmountFactor[c50_i128];
    }

    for (c50_i129 = 0; c50_i129 < 11; c50_i129++) {
      c50_eAmountFactor[c50_i129] = c50_A[c50_i129] / 6.0;
    }

    c50_updateDataWrittenToVector(chartInstance, 3U);
    c50_b_c++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(1, 1, 0, 0);
  _SFD_EML_CALL(1U, chartInstance->c50_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_insertQueueLowc50_Demo_AU_VA1(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_bmls[5000], real_T c50_myBML[1000], real_T
  c50_newBmls[5000])
{
  uint32_T c50_debug_family_var_map[8];
  real_T c50_full;
  real_T c50_t[1000];
  real_T c50_i;
  real_T c50_nargin = 2.0;
  real_T c50_nargout = 1.0;
  int32_T c50_i130;
  static real_T c50_dv22[1000] = { 32.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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

  int32_T c50_i131;
  int32_T c50_i132;
  int32_T c50_i133;
  int32_T c50_i134;
  int32_T c50_i135;
  int32_T c50_b_i;
  int32_T c50_c_i;
  int32_T c50_i136;
  real_T c50_b_bmls[1000];
  int32_T c50_i137;
  real_T c50_dv23[1000];
  int32_T c50_d_i;
  int32_T c50_i138;
  int32_T c50_i139;
  real_T c50_c_bmls[1000];
  int32_T c50_i140;
  int32_T c50_i141;
  real_T c50_d_bmls[1000];
  int32_T c50_i142;
  int32_T c50_i143;
  real_T c50_e_bmls[1000];
  int32_T c50_i144;
  int32_T c50_i145;
  int32_T c50_i146;
  int32_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c50_b_debug_family_names,
    c50_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_full, 0U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c50_t, 1U, c50_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_i, 2U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargin, 3U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c50_nargout, 4U, c50_b_sf_marshallOut,
    c50_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_bmls, 5U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_myBML, 6U, c50_d_sf_marshallOut,
    c50_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c50_newBmls, 7U, c50_c_sf_marshallOut,
    c50_c_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 2);
  c50_full = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 3);
  for (c50_i130 = 0; c50_i130 < 1000; c50_i130++) {
    c50_t[c50_i130] = c50_dv22[c50_i130];
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 4);
  for (c50_i131 = 0; c50_i131 < 1000; c50_i131++) {
    c50_newBmls[c50_i131] = c50_t[c50_i131];
  }

  for (c50_i132 = 0; c50_i132 < 1000; c50_i132++) {
    c50_newBmls[c50_i132 + 1000] = c50_t[c50_i132];
  }

  for (c50_i133 = 0; c50_i133 < 1000; c50_i133++) {
    c50_newBmls[c50_i133 + 2000] = c50_t[c50_i133];
  }

  for (c50_i134 = 0; c50_i134 < 1000; c50_i134++) {
    c50_newBmls[c50_i134 + 3000] = c50_t[c50_i134];
  }

  for (c50_i135 = 0; c50_i135 < 1000; c50_i135++) {
    c50_newBmls[c50_i135 + 4000] = c50_t[c50_i135];
  }

  c50_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 5);
  c50_i = 1.0;
  c50_b_i = 0;
  do {
    exitg1 = 0;
    if (c50_b_i < 5) {
      c50_i = 1.0 + (real_T)c50_b_i;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 6);
      c50_c_i = (int32_T)c50_i - 1;
      for (c50_i136 = 0; c50_i136 < 1000; c50_i136++) {
        c50_b_bmls[c50_i136] = c50_bmls[c50_i136 + 1000 * c50_c_i];
      }

      for (c50_i137 = 0; c50_i137 < 1000; c50_i137++) {
        c50_dv23[c50_i137] = c50_dv22[c50_i137];
      }

      if (CV_EML_IF(0, 1, 0, c50_b_isequal(chartInstance, c50_b_bmls, c50_dv23)))
      {
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 8);
        c50_d_i = (int32_T)c50_i - 1;
        for (c50_i138 = 0; c50_i138 < 1000; c50_i138++) {
          c50_bmls[c50_i138 + 1000 * c50_d_i] = c50_myBML[c50_i138];
        }

        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 9);
        c50_full = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 10);
        exitg1 = 1;
      } else {
        c50_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 13);
  if (CV_EML_IF(0, 1, 1, c50_full != 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 15);
    for (c50_i139 = 0; c50_i139 < 1000; c50_i139++) {
      c50_c_bmls[c50_i139] = c50_bmls[c50_i139 + 1000];
    }

    for (c50_i140 = 0; c50_i140 < 1000; c50_i140++) {
      c50_bmls[c50_i140] = c50_c_bmls[c50_i140];
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 16);
    for (c50_i141 = 0; c50_i141 < 1000; c50_i141++) {
      c50_d_bmls[c50_i141] = c50_bmls[c50_i141 + 2000];
    }

    for (c50_i142 = 0; c50_i142 < 1000; c50_i142++) {
      c50_bmls[c50_i142 + 1000] = c50_d_bmls[c50_i142];
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 17);
    for (c50_i143 = 0; c50_i143 < 1000; c50_i143++) {
      c50_e_bmls[c50_i143] = c50_bmls[c50_i143 + 3000];
    }

    for (c50_i144 = 0; c50_i144 < 1000; c50_i144++) {
      c50_bmls[c50_i144 + 2000] = c50_e_bmls[c50_i144];
    }

    _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 18);
    for (c50_i145 = 0; c50_i145 < 1000; c50_i145++) {
      c50_bmls[c50_i145 + 4000] = c50_myBML[c50_i145];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, 20);
  for (c50_i146 = 0; c50_i146 < 5000; c50_i146++) {
    c50_newBmls[c50_i146] = c50_bmls[c50_i146];
  }

  c50_updateDataWrittenToVector(chartInstance, 4U);
  _SFD_EML_CALL(0U, chartInstance->c50_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c50_c_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  c50_formatSpec, real_T c50_varargin_1)
{
  c50_isequal(chartInstance);
  c50_d_fprintf(chartInstance, c50_formatSpec, c50_varargin_1);
}

static void c50_isequal(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c50_d_fprintf(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1, real_T c50_varargin_2)
{
  real_T c50_nbytes;
  int32_T c50_i147;
  static char_T c50_cv14[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T c50_u[7];
  const mxArray *c50_y = NULL;
  real_T c50_b_u;
  const mxArray *c50_b_y = NULL;
  int32_T c50_i148;
  static char_T c50_formatSpec[19] = { 'V', 'A', ':', ' ', '%', '0', '.', '0',
    'f', ',', '%', '0', '.', '0', 'f', '\\', 'r', '\\', 'n' };

  char_T c50_c_u[19];
  const mxArray *c50_c_y = NULL;
  real_T c50_d_u;
  const mxArray *c50_d_y = NULL;
  real_T c50_e_u;
  const mxArray *c50_e_y = NULL;
  const mxArray *c50_cfmt = NULL;
  const mxArray *c50_convs = NULL;
  c50_isequal(chartInstance);
  c50_validate_arguments(chartInstance, c50_varargin_1, c50_varargin_2);
  for (c50_i147 = 0; c50_i147 < 7; c50_i147++) {
    c50_u[c50_i147] = c50_cv14[c50_i147];
  }

  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", c50_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c50_b_u = 1.0;
  c50_b_y = NULL;
  sf_mex_assign(&c50_b_y, sf_mex_create("y", &c50_b_u, 0, 0U, 0U, 0U, 0), false);
  for (c50_i148 = 0; c50_i148 < 19; c50_i148++) {
    c50_c_u[c50_i148] = c50_formatSpec[c50_i148];
  }

  c50_c_y = NULL;
  sf_mex_assign(&c50_c_y, sf_mex_create("y", c50_c_u, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c50_d_u = c50_varargin_1;
  c50_d_y = NULL;
  sf_mex_assign(&c50_d_y, sf_mex_create("y", &c50_d_u, 0, 0U, 0U, 0U, 0), false);
  c50_e_u = c50_varargin_2;
  c50_e_y = NULL;
  sf_mex_assign(&c50_e_y, sf_mex_create("y", &c50_e_u, 0, 0U, 0U, 0U, 0), false);
  c50_nbytes = c50_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 5U, 14, c50_y, 14, c50_b_y, 14,
     c50_c_y, 14, c50_d_y, 14, c50_e_y), "feval");
  sf_mex_destroy(&c50_cfmt);
  sf_mex_destroy(&c50_convs);
  return c50_nbytes;
}

static void c50_validate_arguments(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, real_T c50_varargin_1, real_T c50_varargin_2)
{
  (void)c50_varargin_1;
  (void)c50_varargin_2;
  c50_eml_switch_helper(chartInstance);
  c50_check_type(chartInstance);
  c50_eml_switch_helper(chartInstance);
  c50_check_type(chartInstance);
}

static void c50_eml_switch_helper(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c50_check_type(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c50_b_isequal(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  real_T c50_varargin_1[1000], real_T c50_varargin_2[1000])
{
  boolean_T c50_p;
  boolean_T c50_b_p;
  int32_T c50_k;
  real_T c50_b_k;
  real_T c50_x1;
  real_T c50_x2;
  boolean_T c50_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c50_p = false;
  c50_b_p = true;
  c50_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c50_k < 1000)) {
    c50_b_k = 1.0 + (real_T)c50_k;
    c50_x1 = c50_varargin_1[(int32_T)c50_b_k - 1];
    c50_x2 = c50_varargin_2[(int32_T)c50_b_k - 1];
    c50_c_p = (c50_x1 == c50_x2);
    if (!c50_c_p) {
      c50_b_p = false;
      exitg1 = true;
    } else {
      c50_k++;
    }
  }

  if (!c50_b_p) {
  } else {
    c50_p = true;
  }

  return c50_p;
}

void sf_exported_user_c50_Demo_AU_VA1_insertQueueLow(SimStruct *c50_S, real_T
  c50_bmls[5000], real_T c50_myBML[1000], real_T c50_newBmls[5000])
{
  int32_T c50_i149;
  real_T c50_b_bmls[5000];
  int32_T c50_i150;
  real_T c50_b_myBML[1000];
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  for (c50_i149 = 0; c50_i149 < 5000; c50_i149++) {
    c50_b_bmls[c50_i149] = c50_bmls[c50_i149];
  }

  for (c50_i150 = 0; c50_i150 < 1000; c50_i150++) {
    c50_b_myBML[c50_i150] = c50_myBML[c50_i150];
  }

  c50_insertQueueLowc50_Demo_AU_VA1(chartInstance, c50_b_bmls, c50_b_myBML,
    c50_newBmls);
}

void sf_exported_user_c50_Demo_AU_VA1_set_AU_Amount(SimStruct *c50_S, real_T
  c50_arousal, real_T c50_valence, real_T c50_eAmountFactor[11])
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)((ChartInfoStruct *)
    ((ChartRunTimeInfo *)ssGetUserData(c50_S))->instanceInfo)->chartInstance;
  c50_set_AU_Amountc50_Demo_AU_VA1(chartInstance, c50_arousal, c50_valence,
    c50_eAmountFactor);
}

static const mxArray *c50_u_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int8_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int8_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int8_T c50_y_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int8_T c50_y;
  int8_T c50_i151;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i151, 1, 2, 0U, 0, 0U, 0);
  c50_y = c50_i151;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_secs;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int8_T c50_y;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_secs = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_secs),
    &c50_thisId);
  sf_mex_destroy(&c50_secs);
  *(int8_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_v_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  int32_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(int32_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static int32_T c50_ab_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  int32_T c50_y;
  int32_T c50_i152;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_i152, 1, 6, 0U, 0, 0U, 0);
  c50_y = c50_i152;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_sfEvent;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  int32_T c50_y;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_b_sfEvent = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_sfEvent),
    &c50_thisId);
  sf_mex_destroy(&c50_b_sfEvent);
  *(int32_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_w_sf_marshallOut(void *chartInstanceVoid, void
  *c50_inData)
{
  const mxArray *c50_mxArrayOutData = NULL;
  uint8_T c50_u;
  const mxArray *c50_y = NULL;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_mxArrayOutData = NULL;
  c50_u = *(uint8_T *)c50_inData;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_create("y", &c50_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c50_mxArrayOutData, c50_y, false);
  return c50_mxArrayOutData;
}

static uint8_T c50_bb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_b_tp_subFacial, const char_T
  *c50_identifier)
{
  uint8_T c50_y;
  emlrtMsgIdentifier c50_thisId;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_tp_subFacial),
    &c50_thisId);
  sf_mex_destroy(&c50_b_tp_subFacial);
  return c50_y;
}

static uint8_T c50_cb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  uint8_T c50_y;
  uint8_T c50_u0;
  (void)chartInstance;
  sf_mex_import(c50_parentId, sf_mex_dup(c50_u), &c50_u0, 1, 3, 0U, 0, 0U, 0);
  c50_y = c50_u0;
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c50_mxArrayInData, const char_T *c50_varName, void *c50_outData)
{
  const mxArray *c50_b_tp_subFacial;
  const char_T *c50_identifier;
  emlrtMsgIdentifier c50_thisId;
  uint8_T c50_y;
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)chartInstanceVoid;
  c50_b_tp_subFacial = sf_mex_dup(c50_mxArrayInData);
  c50_identifier = c50_varName;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  c50_y = c50_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c50_b_tp_subFacial),
    &c50_thisId);
  sf_mex_destroy(&c50_b_tp_subFacial);
  *(uint8_T *)c50_outData = c50_y;
  sf_mex_destroy(&c50_mxArrayInData);
}

static const mxArray *c50_db_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_b_setSimStateSideEffectsInfo, const char_T *
  c50_identifier)
{
  const mxArray *c50_y = NULL;
  emlrtMsgIdentifier c50_thisId;
  c50_y = NULL;
  c50_thisId.fIdentifier = c50_identifier;
  c50_thisId.fParent = NULL;
  sf_mex_assign(&c50_y, c50_eb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c50_b_setSimStateSideEffectsInfo), &c50_thisId), false);
  sf_mex_destroy(&c50_b_setSimStateSideEffectsInfo);
  return c50_y;
}

static const mxArray *c50_eb_emlrt_marshallIn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, const mxArray *c50_u, const emlrtMsgIdentifier *c50_parentId)
{
  const mxArray *c50_y = NULL;
  (void)chartInstance;
  (void)c50_parentId;
  c50_y = NULL;
  sf_mex_assign(&c50_y, sf_mex_duplicatearraysafe(&c50_u), false);
  sf_mex_destroy(&c50_u);
  return c50_y;
}

static void c50_updateDataWrittenToVector(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c50_vectorIndex)
{
  (void)chartInstance;
  c50_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c50_vectorIndex, 0, 4, 1, 0)] = true;
}

static void c50_errorIfDataNotWrittenToFcn(SFc50_Demo_AU_VA1InstanceStruct
  *chartInstance, uint32_T c50_vectorIndex, uint32_T c50_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c50_dataNumber, c50_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c50_vectorIndex, 0, 4, 1,
    0)]);
}

static void c50_b_log10(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarLog10(*c50_x);
}

static void c50_b_ceil(SFc50_Demo_AU_VA1InstanceStruct *chartInstance, real_T
  *c50_x)
{
  (void)chartInstance;
  *c50_x = muDoubleScalarCeil(*c50_x);
}

static real_T c50_get_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c50_b);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2166) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c50_bmlsL_address)[c50_b];
}

static void c50_set_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b, real_T c50_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c50_b);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2166) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c50_bmlsL_address)[c50_b] = c50_c;
}

static real_T *c50_access_bmlsL(SFc50_Demo_AU_VA1InstanceStruct *chartInstance,
  uint32_T c50_b)
{
  real_T *c50_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c50_bmlsL_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'bmlsL\' (#2166) in the initialization routine of the chart.\n");
  }

  c50_c = *chartInstance->c50_bmlsL_address;
  if (c50_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c50_c;
}

static void init_dsm_address_info(SFc50_Demo_AU_VA1InstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "bmlsL", (void **)
    &chartInstance->c50_bmlsL_address, &chartInstance->c50_bmlsL_index);
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

void sf_c50_Demo_AU_VA1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3815812080U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3873046351U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2162405638U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(587436619U);
}

mxArray *sf_c50_Demo_AU_VA1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Jroy3d8zsPDMiRctPQ7cFE");
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
      pr[1] = (double)(11);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c50_Demo_AU_VA1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c50_Demo_AU_VA1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c50_Demo_AU_VA1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[199],T\"emotion_amount_factor\",},{M[3],M[175],T\"BMLl\",},{M[3],M[176],T\"newBmlsL\",},{M[8],M[0],T\"is_active_c50_Demo_AU_VA1\",},{M[8],M[116],T\"is_active_subFacial\",},{M[9],M[116],T\"is_subFacial\",},{M[11],M[39],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[197],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c50_Demo_AU_VA1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_AU_VA1MachineNumber_,
           50,
           6,
           4,
           0,
           12,
           1,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Demo_AU_VA1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Demo_AU_VA1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Demo_AU_VA1MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,11,0,0,"bmlsL");
          _SFD_SET_DATA_PROPS(1,0,0,0,"BMLl");
          _SFD_SET_DATA_PROPS(2,0,0,0,"newBmlsL");
          _SFD_SET_DATA_PROPS(3,1,1,0,"inA");
          _SFD_SET_DATA_PROPS(4,1,1,0,"inV");
          _SFD_SET_DATA_PROPS(5,2,0,1,"emotion_amount_factor");
          _SFD_SET_DATA_PROPS(6,9,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,8,0,0,"");
          _SFD_SET_DATA_PROPS(10,8,0,0,"");
          _SFD_SET_DATA_PROPS(11,9,0,0,"");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(2,0,1);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_ST_SUBSTATE_COUNT(2,3);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_INDEX(2,2,5);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(2,3,1,1,0,0,NULL,NULL);
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
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"set_AU_Amountc50_Demo_AU_VA1",0,-1,2062);
        _SFD_CV_INIT_EML_FOR(1,1,0,374,384,2062);
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"insertQueueLowc50_Demo_AU_VA1",0,-1,568);
        _SFD_CV_INIT_EML_IF(0,1,0,129,154,-1,-2);
        _SFD_CV_INIT_EML_IF(0,1,1,299,310,-1,549);
        _SFD_CV_INIT_EML_FOR(0,1,0,109,121,294);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"encStr2Arr",0,-1,440);
        _SFD_CV_INIT_SCRIPT(1,1,11,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"cmdBML_AU_VA",0,-1,1515);
        _SFD_CV_INIT_SCRIPT_IF(1,0,320,331,-1,993);
        _SFD_CV_INIT_SCRIPT_IF(1,1,419,453,721,981);
        _SFD_CV_INIT_SCRIPT_IF(1,2,1047,1055,1087,1099);
        _SFD_CV_INIT_SCRIPT_IF(1,3,1087,1099,1131,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,4,1131,1143,1175,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,5,1175,1187,1219,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,6,1219,1231,1263,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,7,1263,1275,1307,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,8,1307,1319,1351,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,9,1351,1363,1395,1442);
        _SFD_CV_INIT_SCRIPT_IF(1,10,1395,1407,-1,1407);
        _SFD_CV_INIT_SCRIPT_FOR(1,0,263,273,1001);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,13,0,13);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
            c50_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_d_sf_marshallOut,(MexInFcnForType)
            c50_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
            c50_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 11;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_sf_marshallOut,(MexInFcnForType)
            c50_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c50_b_sf_marshallOut,(MexInFcnForType)
          c50_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
            c50_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_d_sf_marshallOut,(MexInFcnForType)
            c50_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1000;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c50_c_sf_marshallOut,(MexInFcnForType)
            c50_c_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(11,(void *)(NULL));

        {
          real_T *c50_inA;
          real_T *c50_inV;
          real_T (*c50_emotion_amount_factor)[11];
          c50_emotion_amount_factor = (real_T (*)[11])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c50_inV = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c50_inA = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c50_bmlsL_address);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c50_BMLl);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c50_newBmlsL);
          _SFD_SET_DATA_VALUE_PTR(3U, c50_inA);
          _SFD_SET_DATA_VALUE_PTR(4U, c50_inV);
          _SFD_SET_DATA_VALUE_PTR(5U, *c50_emotion_amount_factor);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Demo_AU_VA1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3742eBK30kcvGQETEXq4UB";
}

static void sf_opaque_initialize_c50_Demo_AU_VA1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc50_Demo_AU_VA1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*)
    chartInstanceVar);
  initialize_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c50_Demo_AU_VA1(void *chartInstanceVar)
{
  enable_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c50_Demo_AU_VA1(void *chartInstanceVar)
{
  disable_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c50_Demo_AU_VA1(void *chartInstanceVar)
{
  sf_gateway_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c50_Demo_AU_VA1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c50_Demo_AU_VA1
    ((SFc50_Demo_AU_VA1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c50_Demo_AU_VA1();/* state var info */
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

extern void sf_internal_set_sim_state_c50_Demo_AU_VA1(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c50_Demo_AU_VA1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c50_Demo_AU_VA1(SimStruct* S)
{
  return NULL;
}

static void sf_opaque_set_sim_state_c50_Demo_AU_VA1(SimStruct* S, const mxArray *
  st)
{
}

static void sf_opaque_terminate_c50_Demo_AU_VA1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_AU_VA1_optimization_info();
    }

    finalize_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c50_Demo_AU_VA1(SimStruct *S)
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
    initialize_params_c50_Demo_AU_VA1((SFc50_Demo_AU_VA1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c50_Demo_AU_VA1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_AU_VA1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      50);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,50,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,50,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,50);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,50,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,50,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,50);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4258647114U));
  ssSetChecksum1(S,(1646318907U));
  ssSetChecksum2(S,(2384776341U));
  ssSetChecksum3(S,(1690361695U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c50_Demo_AU_VA1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c50_Demo_AU_VA1(SimStruct *S)
{
  SFc50_Demo_AU_VA1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc50_Demo_AU_VA1InstanceStruct *)utMalloc(sizeof
    (SFc50_Demo_AU_VA1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc50_Demo_AU_VA1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c50_Demo_AU_VA1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c50_Demo_AU_VA1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c50_Demo_AU_VA1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c50_Demo_AU_VA1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c50_Demo_AU_VA1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c50_Demo_AU_VA1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c50_Demo_AU_VA1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c50_Demo_AU_VA1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c50_Demo_AU_VA1;
  chartInstance->chartInfo.mdlStart = mdlStart_c50_Demo_AU_VA1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c50_Demo_AU_VA1;
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

void c50_Demo_AU_VA1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c50_Demo_AU_VA1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c50_Demo_AU_VA1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c50_Demo_AU_VA1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c50_Demo_AU_VA1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
