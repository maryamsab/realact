/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Demo_EP_IdleRandMerg_sfun.h"
#include "c47_Demo_EP_IdleRandMerg.h"
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
static const char * c47_debug_family_names[7] = { "currentTime", "A", "fileID",
  "nargin", "nargout", "v", "a" };

/* Function Declarations */
static void initialize_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initialize_params_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void enable_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void disable_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void c47_update_debugger_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void set_sim_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c47_st);
static void finalize_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void sf_gateway_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void initSimStructsc47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber);
static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static void c47_info_helper(const mxArray **c47_info);
static const mxArray *c47_emlrt_marshallOut(const char * c47_u);
static const mxArray *c47_b_emlrt_marshallOut(const uint32_T c47_u);
static real_T c47_fopen(SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance);
static real_T c47_fileManager(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);
static void c47_fclose(SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c47_fileID);
static int32_T c47_b_fileManager(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c47_varargin_1);
static real_T c47_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_feval, const char_T *c47_identifier);
static real_T c47_b_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static boolean_T c47_c_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_failp, const char_T *c47_identifier);
static boolean_T c47_d_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static int32_T c47_e_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static uint8_T c47_f_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_b_is_active_c47_Demo_EP_IdleRandMerg, const
  char_T *c47_identifier);
static uint8_T c47_g_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void init_dsm_address_info(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  chartInstance->c47_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c47_is_active_c47_Demo_EP_IdleRandMerg = 0U;
}

static void initialize_params_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c47_update_debugger_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  const mxArray *c47_st;
  const mxArray *c47_y = NULL;
  uint8_T c47_hoistedGlobal;
  uint8_T c47_u;
  const mxArray *c47_b_y = NULL;
  c47_st = NULL;
  c47_st = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_createcellmatrix(1, 1), false);
  c47_hoistedGlobal = chartInstance->c47_is_active_c47_Demo_EP_IdleRandMerg;
  c47_u = c47_hoistedGlobal;
  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", &c47_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 0, c47_b_y);
  sf_mex_assign(&c47_st, c47_y, false);
  return c47_st;
}

static void set_sim_state_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance, const mxArray
   *c47_st)
{
  const mxArray *c47_u;
  chartInstance->c47_doneDoubleBufferReInit = true;
  c47_u = sf_mex_dup(c47_st);
  chartInstance->c47_is_active_c47_Demo_EP_IdleRandMerg = c47_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 0)),
     "is_active_c47_Demo_EP_IdleRandMerg");
  sf_mex_destroy(&c47_u);
  c47_update_debugger_state_c47_Demo_EP_IdleRandMerg(chartInstance);
  sf_mex_destroy(&c47_st);
}

static void finalize_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  real_T c47_hoistedGlobal;
  real_T c47_b_hoistedGlobal;
  real_T c47_v;
  real_T c47_a;
  uint32_T c47_debug_family_var_map[7];
  const mxArray *c47_currentTime = NULL;
  const mxArray *c47_A = NULL;
  real_T c47_fileID;
  real_T c47_nargin = 2.0;
  real_T c47_nargout = 0.0;
  int32_T c47_i0;
  static char_T c47_cv0[20] = { 'D', 'e', 'm', 'o', '_', 'E', 'P', '_', 'I', 'd',
    'l', 'e', 'R', 'a', 'n', 'd', 'M', 'e', 'r', 'g' };

  char_T c47_u[20];
  const mxArray *c47_y = NULL;
  int32_T c47_i1;
  static char_T c47_cv1[14] = { 'S', 'i', 'm', 'u', 'l', 'a', 't', 'i', 'o', 'n',
    'T', 'i', 'm', 'e' };

  char_T c47_b_u[14];
  const mxArray *c47_b_y = NULL;
  real_T c47_c_u;
  const mxArray *c47_c_y = NULL;
  real_T c47_d_u;
  const mxArray *c47_d_y = NULL;
  real_T c47_e_u;
  const mxArray *c47_e_y = NULL;
  int32_T c47_i2;
  static char_T c47_cv2[21] = { '%', '0', '.', '1', 'f', ',', '%', '0', '.', '1',
    'f', ',', '%', '0', '.', '1', 'f', '\\', 'r', '\\', 'n' };

  char_T c47_f_u[21];
  const mxArray *c47_f_y = NULL;
  real_T *c47_b_v;
  real_T *c47_b_a;
  c47_b_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c47_b_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, chartInstance->c47_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c47_b_v, 0U);
  _SFD_DATA_RANGE_CHECK(*c47_b_a, 1U);
  chartInstance->c47_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, chartInstance->c47_sfEvent);
  c47_hoistedGlobal = *c47_b_v;
  c47_b_hoistedGlobal = *c47_b_a;
  c47_v = c47_hoistedGlobal;
  c47_a = c47_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c47_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c47_currentTime, 0U, c47_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c47_A, 1U, c47_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_fileID, 2U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 3U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 4U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c47_v, 5U, c47_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c47_a, 6U, c47_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 7);
  for (c47_i0 = 0; c47_i0 < 20; c47_i0++) {
    c47_u[c47_i0] = c47_cv0[c47_i0];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 10, 0U, 1U, 0U, 2, 1, 20),
                false);
  for (c47_i1 = 0; c47_i1 < 14; c47_i1++) {
    c47_b_u[c47_i1] = c47_cv1[c47_i1];
  }

  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", c47_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_assign(&c47_currentTime, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "get_param", 1U, 2U, 14, c47_y, 14, c47_b_y), false);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 9);
  c47_c_u = c47_v;
  c47_c_y = NULL;
  sf_mex_assign(&c47_c_y, sf_mex_create("y", &c47_c_u, 0, 0U, 0U, 0U, 0), false);
  c47_d_u = c47_a;
  c47_d_y = NULL;
  sf_mex_assign(&c47_d_y, sf_mex_create("y", &c47_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_A, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "vertcat",
    1U, 3U, 14, c47_c_y, 14, c47_d_y, 14, sf_mex_dup(c47_currentTime)), false);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 11);
  c47_fileID = c47_fopen(chartInstance);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 12);
  c47_e_u = c47_fileID;
  c47_e_y = NULL;
  sf_mex_assign(&c47_e_y, sf_mex_create("y", &c47_e_u, 0, 0U, 0U, 0U, 0), false);
  for (c47_i2 = 0; c47_i2 < 21; c47_i2++) {
    c47_f_u[c47_i2] = c47_cv2[c47_i2];
  }

  c47_f_y = NULL;
  sf_mex_assign(&c47_f_y, sf_mex_create("y", c47_f_u, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "fprintf", 0U, 3U, 14, c47_e_y,
                    14, c47_f_y, 14, sf_mex_dup(c47_A));
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, 13);
  c47_fclose(chartInstance, c47_fileID);
  _SFD_EML_CALL(0U, chartInstance->c47_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c47_currentTime);
  sf_mex_destroy(&c47_A);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c47_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Demo_EP_IdleRandMergMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc47_Demo_EP_IdleRandMerg
  (SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber)
{
  (void)c47_machineNumber;
  (void)c47_chartNumber;
  (void)c47_instanceNumber;
}

static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  real_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(real_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_feval;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y;
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c47_feval = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_feval),
    &c47_thisId);
  sf_mex_destroy(&c47_feval);
  *(real_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  const mxArray *c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = sf_mex_dup(*(const mxArray **)c47_inData);
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_duplicatearraysafe(&c47_u), false);
  sf_mex_destroy(&c47_u);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

const mxArray *sf_c47_Demo_EP_IdleRandMerg_get_eml_resolved_functions_info(void)
{
  const mxArray *c47_nameCaptureInfo = NULL;
  c47_nameCaptureInfo = NULL;
  sf_mex_assign(&c47_nameCaptureInfo, sf_mex_createstruct("structure", 2, 45, 1),
                false);
  c47_info_helper(&c47_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c47_nameCaptureInfo);
  return c47_nameCaptureInfo;
}

static void c47_info_helper(const mxArray **c47_info)
{
  const mxArray *c47_rhs0 = NULL;
  const mxArray *c47_lhs0 = NULL;
  const mxArray *c47_rhs1 = NULL;
  const mxArray *c47_lhs1 = NULL;
  const mxArray *c47_rhs2 = NULL;
  const mxArray *c47_lhs2 = NULL;
  const mxArray *c47_rhs3 = NULL;
  const mxArray *c47_lhs3 = NULL;
  const mxArray *c47_rhs4 = NULL;
  const mxArray *c47_lhs4 = NULL;
  const mxArray *c47_rhs5 = NULL;
  const mxArray *c47_lhs5 = NULL;
  const mxArray *c47_rhs6 = NULL;
  const mxArray *c47_lhs6 = NULL;
  const mxArray *c47_rhs7 = NULL;
  const mxArray *c47_lhs7 = NULL;
  const mxArray *c47_rhs8 = NULL;
  const mxArray *c47_lhs8 = NULL;
  const mxArray *c47_rhs9 = NULL;
  const mxArray *c47_lhs9 = NULL;
  const mxArray *c47_rhs10 = NULL;
  const mxArray *c47_lhs10 = NULL;
  const mxArray *c47_rhs11 = NULL;
  const mxArray *c47_lhs11 = NULL;
  const mxArray *c47_rhs12 = NULL;
  const mxArray *c47_lhs12 = NULL;
  const mxArray *c47_rhs13 = NULL;
  const mxArray *c47_lhs13 = NULL;
  const mxArray *c47_rhs14 = NULL;
  const mxArray *c47_lhs14 = NULL;
  const mxArray *c47_rhs15 = NULL;
  const mxArray *c47_lhs15 = NULL;
  const mxArray *c47_rhs16 = NULL;
  const mxArray *c47_lhs16 = NULL;
  const mxArray *c47_rhs17 = NULL;
  const mxArray *c47_lhs17 = NULL;
  const mxArray *c47_rhs18 = NULL;
  const mxArray *c47_lhs18 = NULL;
  const mxArray *c47_rhs19 = NULL;
  const mxArray *c47_lhs19 = NULL;
  const mxArray *c47_rhs20 = NULL;
  const mxArray *c47_lhs20 = NULL;
  const mxArray *c47_rhs21 = NULL;
  const mxArray *c47_lhs21 = NULL;
  const mxArray *c47_rhs22 = NULL;
  const mxArray *c47_lhs22 = NULL;
  const mxArray *c47_rhs23 = NULL;
  const mxArray *c47_lhs23 = NULL;
  const mxArray *c47_rhs24 = NULL;
  const mxArray *c47_lhs24 = NULL;
  const mxArray *c47_rhs25 = NULL;
  const mxArray *c47_lhs25 = NULL;
  const mxArray *c47_rhs26 = NULL;
  const mxArray *c47_lhs26 = NULL;
  const mxArray *c47_rhs27 = NULL;
  const mxArray *c47_lhs27 = NULL;
  const mxArray *c47_rhs28 = NULL;
  const mxArray *c47_lhs28 = NULL;
  const mxArray *c47_rhs29 = NULL;
  const mxArray *c47_lhs29 = NULL;
  const mxArray *c47_rhs30 = NULL;
  const mxArray *c47_lhs30 = NULL;
  const mxArray *c47_rhs31 = NULL;
  const mxArray *c47_lhs31 = NULL;
  const mxArray *c47_rhs32 = NULL;
  const mxArray *c47_lhs32 = NULL;
  const mxArray *c47_rhs33 = NULL;
  const mxArray *c47_lhs33 = NULL;
  const mxArray *c47_rhs34 = NULL;
  const mxArray *c47_lhs34 = NULL;
  const mxArray *c47_rhs35 = NULL;
  const mxArray *c47_lhs35 = NULL;
  const mxArray *c47_rhs36 = NULL;
  const mxArray *c47_lhs36 = NULL;
  const mxArray *c47_rhs37 = NULL;
  const mxArray *c47_lhs37 = NULL;
  const mxArray *c47_rhs38 = NULL;
  const mxArray *c47_lhs38 = NULL;
  const mxArray *c47_rhs39 = NULL;
  const mxArray *c47_lhs39 = NULL;
  const mxArray *c47_rhs40 = NULL;
  const mxArray *c47_lhs40 = NULL;
  const mxArray *c47_rhs41 = NULL;
  const mxArray *c47_lhs41 = NULL;
  const mxArray *c47_rhs42 = NULL;
  const mxArray *c47_lhs42 = NULL;
  const mxArray *c47_rhs43 = NULL;
  const mxArray *c47_lhs43 = NULL;
  const mxArray *c47_rhs44 = NULL;
  const mxArray *c47_lhs44 = NULL;
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fopen"), "name", "name", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c47_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fopen.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fileManager"), "name",
                  "name", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c47_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.errorIf"),
                  "name", "name", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/errorIf.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1334104338U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c47_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c47_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m!STANDALONE"),
                  "context", "context", 4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("isequal"), "name", "name", 4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286851158U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c47_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286851186U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c47_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363742658U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c47_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c47_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fprintf"), "name", "name", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fprintf.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c47_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fclose"), "name", "name", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c47_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fidCheck"), "name", "name",
                  10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c47_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("upper"), "name", "name", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c47_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/upper.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_string_transform"),
                  "name", "name", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c47_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c47_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c47_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c47_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c47_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1327451510U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c47_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("colon"), "name", "name", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c47_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("colon"), "name", "name", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1378328388U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c47_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c47_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c47_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("floor"), "name", "name", 22);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363742654U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c47_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c47_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 24);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286851126U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c47_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 25);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmin"), "name", "name", 25);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c47_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 26);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c47_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 27);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 27);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c47_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 28);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmin"), "name", "name", 28);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c47_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 29);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 29);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c47_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 30);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 30);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c47_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 31);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1389340320U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c47_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 32);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 32);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c47_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 33);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1389340322U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c47_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 34);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 34);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882700U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c47_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 35);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1323202978U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c47_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 36);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 36);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c47_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 37);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 37);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c47_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 38);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 38);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1372614816U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c47_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 39);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1372615560U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c47_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 40);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 40);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1376013088U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c47_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 41);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("intmax"), "name", "name", 41);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1362294282U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c47_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "name", "name", 42);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1319762368U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c47_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fidCheck.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 43);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363743356U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c47_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/iofun/fclose.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("fileManager"), "name",
                  "name", 44);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/iofun/private/fileManager.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1381882702U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c47_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs44), "lhs", "lhs",
                  44);
  sf_mex_destroy(&c47_rhs0);
  sf_mex_destroy(&c47_lhs0);
  sf_mex_destroy(&c47_rhs1);
  sf_mex_destroy(&c47_lhs1);
  sf_mex_destroy(&c47_rhs2);
  sf_mex_destroy(&c47_lhs2);
  sf_mex_destroy(&c47_rhs3);
  sf_mex_destroy(&c47_lhs3);
  sf_mex_destroy(&c47_rhs4);
  sf_mex_destroy(&c47_lhs4);
  sf_mex_destroy(&c47_rhs5);
  sf_mex_destroy(&c47_lhs5);
  sf_mex_destroy(&c47_rhs6);
  sf_mex_destroy(&c47_lhs6);
  sf_mex_destroy(&c47_rhs7);
  sf_mex_destroy(&c47_lhs7);
  sf_mex_destroy(&c47_rhs8);
  sf_mex_destroy(&c47_lhs8);
  sf_mex_destroy(&c47_rhs9);
  sf_mex_destroy(&c47_lhs9);
  sf_mex_destroy(&c47_rhs10);
  sf_mex_destroy(&c47_lhs10);
  sf_mex_destroy(&c47_rhs11);
  sf_mex_destroy(&c47_lhs11);
  sf_mex_destroy(&c47_rhs12);
  sf_mex_destroy(&c47_lhs12);
  sf_mex_destroy(&c47_rhs13);
  sf_mex_destroy(&c47_lhs13);
  sf_mex_destroy(&c47_rhs14);
  sf_mex_destroy(&c47_lhs14);
  sf_mex_destroy(&c47_rhs15);
  sf_mex_destroy(&c47_lhs15);
  sf_mex_destroy(&c47_rhs16);
  sf_mex_destroy(&c47_lhs16);
  sf_mex_destroy(&c47_rhs17);
  sf_mex_destroy(&c47_lhs17);
  sf_mex_destroy(&c47_rhs18);
  sf_mex_destroy(&c47_lhs18);
  sf_mex_destroy(&c47_rhs19);
  sf_mex_destroy(&c47_lhs19);
  sf_mex_destroy(&c47_rhs20);
  sf_mex_destroy(&c47_lhs20);
  sf_mex_destroy(&c47_rhs21);
  sf_mex_destroy(&c47_lhs21);
  sf_mex_destroy(&c47_rhs22);
  sf_mex_destroy(&c47_lhs22);
  sf_mex_destroy(&c47_rhs23);
  sf_mex_destroy(&c47_lhs23);
  sf_mex_destroy(&c47_rhs24);
  sf_mex_destroy(&c47_lhs24);
  sf_mex_destroy(&c47_rhs25);
  sf_mex_destroy(&c47_lhs25);
  sf_mex_destroy(&c47_rhs26);
  sf_mex_destroy(&c47_lhs26);
  sf_mex_destroy(&c47_rhs27);
  sf_mex_destroy(&c47_lhs27);
  sf_mex_destroy(&c47_rhs28);
  sf_mex_destroy(&c47_lhs28);
  sf_mex_destroy(&c47_rhs29);
  sf_mex_destroy(&c47_lhs29);
  sf_mex_destroy(&c47_rhs30);
  sf_mex_destroy(&c47_lhs30);
  sf_mex_destroy(&c47_rhs31);
  sf_mex_destroy(&c47_lhs31);
  sf_mex_destroy(&c47_rhs32);
  sf_mex_destroy(&c47_lhs32);
  sf_mex_destroy(&c47_rhs33);
  sf_mex_destroy(&c47_lhs33);
  sf_mex_destroy(&c47_rhs34);
  sf_mex_destroy(&c47_lhs34);
  sf_mex_destroy(&c47_rhs35);
  sf_mex_destroy(&c47_lhs35);
  sf_mex_destroy(&c47_rhs36);
  sf_mex_destroy(&c47_lhs36);
  sf_mex_destroy(&c47_rhs37);
  sf_mex_destroy(&c47_lhs37);
  sf_mex_destroy(&c47_rhs38);
  sf_mex_destroy(&c47_lhs38);
  sf_mex_destroy(&c47_rhs39);
  sf_mex_destroy(&c47_lhs39);
  sf_mex_destroy(&c47_rhs40);
  sf_mex_destroy(&c47_lhs40);
  sf_mex_destroy(&c47_rhs41);
  sf_mex_destroy(&c47_lhs41);
  sf_mex_destroy(&c47_rhs42);
  sf_mex_destroy(&c47_lhs42);
  sf_mex_destroy(&c47_rhs43);
  sf_mex_destroy(&c47_lhs43);
  sf_mex_destroy(&c47_rhs44);
  sf_mex_destroy(&c47_lhs44);
}

static const mxArray *c47_emlrt_marshallOut(const char * c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c47_u)), false);
  return c47_y;
}

static const mxArray *c47_b_emlrt_marshallOut(const uint32_T c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 7, 0U, 0U, 0U, 0), false);
  return c47_y;
}

static real_T c47_fopen(SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance)
{
  return c47_fileManager(chartInstance);
}

static real_T c47_fileManager(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance)
{
  int32_T c47_i3;
  static char_T c47_cv3[5] = { 'f', 'o', 'p', 'e', 'n' };

  char_T c47_u[5];
  const mxArray *c47_y = NULL;
  int32_T c47_i4;
  static char_T c47_filename[17] = { 'L', 'E', 'H', 'N', '_', 'V', 'A', '_', 't',
    'a', 'b', 'l', 'e', '.', 't', 'x', 't' };

  char_T c47_b_u[17];
  const mxArray *c47_b_y = NULL;
  char_T c47_c_u;
  const mxArray *c47_c_y = NULL;
  for (c47_i3 = 0; c47_i3 < 5; c47_i3++) {
    c47_u[c47_i3] = c47_cv3[c47_i3];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  for (c47_i4 = 0; c47_i4 < 17; c47_i4++) {
    c47_b_u[c47_i4] = c47_filename[c47_i4];
  }

  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", c47_b_u, 10, 0U, 1U, 0U, 2, 1, 17),
                false);
  c47_c_u = 'a';
  c47_c_y = NULL;
  sf_mex_assign(&c47_c_y, sf_mex_create("y", &c47_c_u, 10, 0U, 0U, 0U, 0), false);
  return c47_emlrt_marshallIn(chartInstance, sf_mex_call_debug
    (sfGlobalDebugInstanceStruct, "feval", 1U, 3U, 14, c47_y, 14, c47_b_y, 14,
     c47_c_y), "feval");
}

static void c47_fclose(SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance,
  real_T c47_fileID)
{
  c47_b_fileManager(chartInstance, c47_fileID);
}

static int32_T c47_b_fileManager(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, real_T c47_varargin_1)
{
  int32_T c47_f;
  real_T c47_fid;
  int32_T c47_i5;
  static char_T c47_cv4[6] = { 'f', 'c', 'l', 'o', 's', 'e' };

  char_T c47_u[6];
  const mxArray *c47_y = NULL;
  real_T c47_b_u;
  const mxArray *c47_b_y = NULL;
  const mxArray *c47_failp = NULL;
  c47_fid = c47_varargin_1;
  for (c47_i5 = 0; c47_i5 < 6; c47_i5++) {
    c47_u[c47_i5] = c47_cv4[c47_i5];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 10, 0U, 1U, 0U, 2, 1, 6),
                false);
  c47_b_u = c47_fid;
  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", &c47_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_failp, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "logical", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "feval", 1U, 2U, 14, c47_y, 14, c47_b_y)), false);
  if (c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_failp), "failp")) {
    c47_f = -1;
  } else {
    c47_f = 0;
  }

  sf_mex_destroy(&c47_failp);
  return c47_f;
}

static real_T c47_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_feval, const char_T *c47_identifier)
{
  real_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_feval),
    &c47_thisId);
  sf_mex_destroy(&c47_feval);
  return c47_y;
}

static real_T c47_b_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  real_T c47_y;
  real_T c47_d0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_d0, 1, 0, 0U, 0, 0U, 0);
  c47_y = c47_d0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static boolean_T c47_c_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_failp, const char_T *c47_identifier)
{
  boolean_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_failp),
    &c47_thisId);
  sf_mex_destroy(&c47_failp);
  return c47_y;
}

static boolean_T c47_d_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  boolean_T c47_y;
  boolean_T c47_b0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_b0, 1, 11, 0U, 0, 0U, 0);
  c47_y = c47_b0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(int32_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static int32_T c47_e_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  int32_T c47_y;
  int32_T c47_i6;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_i6, 1, 6, 0U, 0, 0U, 0);
  c47_y = c47_i6;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_sfEvent;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  int32_T c47_y;
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)chartInstanceVoid;
  c47_b_sfEvent = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_sfEvent),
    &c47_thisId);
  sf_mex_destroy(&c47_b_sfEvent);
  *(int32_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static uint8_T c47_f_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_b_is_active_c47_Demo_EP_IdleRandMerg, const
  char_T *c47_identifier)
{
  uint8_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_is_active_c47_Demo_EP_IdleRandMerg), &c47_thisId);
  sf_mex_destroy(&c47_b_is_active_c47_Demo_EP_IdleRandMerg);
  return c47_y;
}

static uint8_T c47_g_emlrt_marshallIn(SFc47_Demo_EP_IdleRandMergInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint8_T c47_y;
  uint8_T c47_u0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u0, 1, 3, 0U, 0, 0U, 0);
  c47_y = c47_u0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void init_dsm_address_info(SFc47_Demo_EP_IdleRandMergInstanceStruct
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

void sf_c47_Demo_EP_IdleRandMerg_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(791578562U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1196032255U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1166744914U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4168030773U);
}

mxArray *sf_c47_Demo_EP_IdleRandMerg_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("b2Y91KTB3TvHOkJtt5jhFD");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c47_Demo_EP_IdleRandMerg_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c47_Demo_EP_IdleRandMerg_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c47_Demo_EP_IdleRandMerg(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c47_Demo_EP_IdleRandMerg\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c47_Demo_EP_IdleRandMerg_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Demo_EP_IdleRandMergMachineNumber_,
           47,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v");
          _SFD_SET_DATA_PROPS(1,1,1,0,"a");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1122);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c47_v;
          real_T *c47_a;
          c47_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c47_v = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c47_v);
          _SFD_SET_DATA_VALUE_PTR(1U, c47_a);
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
  return "PaA98thoaIzT5nBolaJkr";
}

static void sf_opaque_initialize_c47_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c47_Demo_EP_IdleRandMerg
    ((SFc47_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
  initialize_c47_Demo_EP_IdleRandMerg((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c47_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  enable_c47_Demo_EP_IdleRandMerg((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c47_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  disable_c47_Demo_EP_IdleRandMerg((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c47_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  sf_gateway_c47_Demo_EP_IdleRandMerg((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c47_Demo_EP_IdleRandMerg
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c47_Demo_EP_IdleRandMerg
    ((SFc47_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c47_Demo_EP_IdleRandMerg();/* state var info */
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

extern void sf_internal_set_sim_state_c47_Demo_EP_IdleRandMerg(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c47_Demo_EP_IdleRandMerg();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c47_Demo_EP_IdleRandMerg
    ((SFc47_Demo_EP_IdleRandMergInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c47_Demo_EP_IdleRandMerg(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c47_Demo_EP_IdleRandMerg(S);
}

static void sf_opaque_set_sim_state_c47_Demo_EP_IdleRandMerg(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c47_Demo_EP_IdleRandMerg(S, st);
}

static void sf_opaque_terminate_c47_Demo_EP_IdleRandMerg(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc47_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Demo_EP_IdleRandMerg_optimization_info();
    }

    finalize_c47_Demo_EP_IdleRandMerg((SFc47_Demo_EP_IdleRandMergInstanceStruct*)
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
  initSimStructsc47_Demo_EP_IdleRandMerg
    ((SFc47_Demo_EP_IdleRandMergInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c47_Demo_EP_IdleRandMerg(SimStruct *S)
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
    initialize_params_c47_Demo_EP_IdleRandMerg
      ((SFc47_Demo_EP_IdleRandMergInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c47_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Demo_EP_IdleRandMerg_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      47);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,47,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,47,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,47);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,47,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,47);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2754413306U));
  ssSetChecksum1(S,(2941942775U));
  ssSetChecksum2(S,(2287457094U));
  ssSetChecksum3(S,(2041822740U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c47_Demo_EP_IdleRandMerg(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c47_Demo_EP_IdleRandMerg(SimStruct *S)
{
  SFc47_Demo_EP_IdleRandMergInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc47_Demo_EP_IdleRandMergInstanceStruct *)utMalloc(sizeof
    (SFc47_Demo_EP_IdleRandMergInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc47_Demo_EP_IdleRandMergInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlStart = mdlStart_c47_Demo_EP_IdleRandMerg;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c47_Demo_EP_IdleRandMerg;
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

void c47_Demo_EP_IdleRandMerg_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c47_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c47_Demo_EP_IdleRandMerg(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c47_Demo_EP_IdleRandMerg(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c47_Demo_EP_IdleRandMerg_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
